/*******************************************************************************
 * Copyright (c) 2012, 2013 IBM Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution. 
 *
 * The Eclipse Public License is available at 
 *   http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at 
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    Ian Craggs - initial contribution
 *    Ian Craggs - change delimiter option from char to string
 *    Al Stockdill-Mander - Version using the embedded C client
 *******************************************************************************/

/*
 
 stdout subscriber
 
 compulsory parameters:
 
  topic to subscribe to
 
 defaulted parameters:
 
	--host localhost
	--port 1883
	--qos 2
	--delimiter \n
	--clientid stdout_subscriber
	
	--userid none
	--password none

 for example:

    stdoutsub topic/of/interest --host iot.eclipse.org

*/
#include "MQTTClient.h"
#include "sci_types.h"


volatile int toStop = 0;


void usage()
{
	SCI_TRACE_LOW("MQTT stdout subscriber\n");
	SCI_TRACE_LOW("Usage: stdoutsub topicname <options>, where options are:\n");
	SCI_TRACE_LOW("  --host <hostname> (default is localhost)\n");
	SCI_TRACE_LOW("  --port <port> (default is 1883)\n");
	SCI_TRACE_LOW("  --qos <qos> (default is 2)\n");
	SCI_TRACE_LOW("  --delimiter <delim> (default is \\n)\n");
	SCI_TRACE_LOW("  --clientid <clientid> (default is hostname+timestamp)\n");
	SCI_TRACE_LOW("  --username none\n");
	SCI_TRACE_LOW("  --password none\n");
	SCI_TRACE_LOW("  --showtopics <on or off> (default is on if the topic has a wildcard, else off)\n");
	exit(-1);
}


void cfinish(int sig)
{
	//signal(SIGINT, NULL);
	toStop = 1;
}


struct opts_struct
{
	char* clientid;
	int nodelimiter;
	char* delimiter;
	enum QoS qos;
	char* username;
	char* password;
	char* host;
	int port;
	int showtopics;
} opts =
{
	(char*)"spreadtrum-stdout-subscriber", 0, (char*)"\n", QOS2, NULL, NULL, (char*)"localhost", 1883, 0
};




void getopts(int argc, char** argv)
{
	int count = 2;
	
	while (count < argc)
	{
		if (strcmp(argv[count], "--qos") == 0)
		{
			if (++count < argc)
			{
				if (strcmp(argv[count], "0") == 0)
					opts.qos = QOS0;
				else if (strcmp(argv[count], "1") == 0)
					opts.qos = QOS1;
				else if (strcmp(argv[count], "2") == 0)
					opts.qos = QOS2;
				else
					usage();
			}
			else
				usage();
		}
		else if (strcmp(argv[count], "--host") == 0)
		{
			if (++count < argc)
				opts.host = argv[count];
			else
				usage();
		}
		else if (strcmp(argv[count], "--port") == 0)
		{
			if (++count < argc)
				opts.port = atoi(argv[count]);
			else
				usage();
		}
		else if (strcmp(argv[count], "--clientid") == 0)
		{
			if (++count < argc)
				opts.clientid = argv[count];
			else
				usage();
		}
		else if (strcmp(argv[count], "--username") == 0)
		{
			if (++count < argc)
				opts.username = argv[count];
			else
				usage();
		}
		else if (strcmp(argv[count], "--password") == 0)
		{
			if (++count < argc)
				opts.password = argv[count];
			else
				usage();
		}
		else if (strcmp(argv[count], "--delimiter") == 0)
		{
			if (++count < argc)
				opts.delimiter = argv[count];
			else
				opts.nodelimiter = 1;
		}
		else if (strcmp(argv[count], "--showtopics") == 0)
		{
			if (++count < argc)
			{
				if (strcmp(argv[count], "on") == 0)
					opts.showtopics = 1;
				else if (strcmp(argv[count], "off") == 0)
					opts.showtopics = 0;
				else
					usage();
			}
			else
				usage();
		}
		count++;
	}
	
}


void messageArrived(MessageData* md)
{
	MQTTMessage* message = md->message;

	if (opts.showtopics)
		SCI_TRACE_LOW("%.*s\t", md->topicName->lenstring.len, md->topicName->lenstring.data);
	if (opts.nodelimiter)
		SCI_TRACE_LOW("%.*s", (int)message->payloadlen, (char*)message->payload);
	else
		SCI_TRACE_LOW("%.*s%s", (int)message->payloadlen, (char*)message->payload, opts.delimiter);
	//fflush(stdout);
}


int MQTTTest_main(int argc, char** argv)
{
	int rc = 0;
	unsigned char sendbuf[100];
	unsigned char readbuf[100];
	Network n;
	MQTTClient c;
	MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
	char* topic;

	if (argc < 2)
		usage();
	
	topic = argv[1];

	if (strchr(topic, '#') || strchr(topic, '+'))
		opts.showtopics = 1;
	if (opts.showtopics)
		SCI_TRACE_LOW("topic is %s\n", topic);

	getopts(argc, argv);	
	
	//signal(SIGINT, cfinish);
	//signal(SIGTERM, cfinish);

	NetworkInit(&n);
	NetworkConnect(&n, opts.host, opts.port);
	MQTTClientInit(&c, &n, 3000, sendbuf, sizeof(sendbuf), readbuf, sizeof(readbuf));	
 
	       
	data.willFlag = 0;
	data.MQTTVersion = 3;
	data.clientID.cstring = opts.clientid;
	data.username.cstring = opts.username;
	data.password.cstring = opts.password;

	data.keepAliveInterval = 10;
	data.cleansession = 1;
	SCI_TRACE_LOW("Connecting to %s %d\n", opts.host, opts.port);
	
	rc = MQTTConnect(&c, &data);
	SCI_TRACE_LOW("Connected %d\n", rc);
    
    SCI_TRACE_LOW("Subscribing to %s\n", topic);
	rc = MQTTSubscribe(&c, topic, opts.qos, messageArrived);
	SCI_TRACE_LOW("Subscribed %d\n", rc);

	while (!toStop)
	{
		MQTTYield(&c, 1000);
	}
	
	SCI_TRACE_LOW("Stopping\n");

	MQTTDisconnect(&c);
	NetworkDisconnect(&n);

	return 0;
}


