import jp.co.cmcc.event.Applet;
import jp.co.cmcc.event.Event;

import java.net.http.HttpURLConnection;
import java.net.http.URL;
import java.io.IOException;
import java.io.InputStream;

import iot.oem.gpio.Gpio;
import iot.oem.comm.CommConnectionImpl;

public class GPSSensor extends Applet
{
    private static final String REPORT_SERVER_FORMAT = "http://42.121.18.62:8080/dthing/ParmInfo.action?saveDataInfo&saveType=log&parmInfo=";
    private static boolean allowLogPrint = true;
    private static boolean allowRunning = true;

    private static long totalMemory = 0;
    private static long gcMemory = 0;

    private static final int DefaultGPSPort = 0;
    private static final int DefaultBaudrate = 9600;
    private static final int DefaultGPSBuffer = 512;
    private static final int DefaultGCPercentage = 50;
    private static int totalReadLength = 0;
    private static CommConnectionImpl gpsComm = null;

    public void cleanup() {
        allowRunning = false;
    }

    public void processEvent(Event paramEvent) {
    }

    public void startup() {

        new Thread() {
            public void run() {
                byte[] buf = null;
                int readSize = 0;
                InputStream is = null;
                totalMemory = Runtime.getRuntime().totalMemory();
                gcMemory = totalMemory * DefaultGCPercentage/ 100;
                Gpio ldo = null;
                boolean isLDOEnabled = false;

                while(allowRunning) {
                    try {
                        if (ldo == null) {
                            ldo = new Gpio(60); //60 for board, 7 for shoe
                        }

                        if ((ldo != null) && !isLDOEnabled) {
                            ldo.setCurrentMode(Gpio.READ_MODE);
                            isLDOEnabled = ldo.read();

                            if (!isLDOEnabled) {
                                ldo.setCurrentMode(Gpio.WRITE_MODE);
                                ldo.write(true);
                            }

                            ldo.setCurrentMode(Gpio.READ_MODE);
                            isLDOEnabled = ldo.read();
                            String res = isLDOEnabled? "Success" : "Failure";
                            reportTestInfo("GPSCOM", "pull GPIO 60 to high:" + res);

                            if (!isLDOEnabled) {
                                continue;
                            }
                        }

                        if (gpsComm == null) {
                            gpsComm = CommConnectionImpl.getComInstance(DefaultGPSPort, DefaultBaudrate);

                            if (gpsComm != null) {
                                buf = new byte[DefaultGPSBuffer];
                                reportTestInfo("GPSCOM", "Comm instance is created");
                            } else {
                                continue;
                            }
                        }

                        if (is == null) {
                            is = gpsComm.openInputStream();
                            if (is != null) {
                                reportTestInfo("GPSCOM", "Comm input stream is opened");
                                Thread.sleep(10000L);
                            } else {
                                continue;
                            }
                        }

                        readSize = is.read(buf, 0, DefaultGPSBuffer);

                        if (readSize < 0)
                        {
                            reportTestInfo("GPSCOM", "exit when readSize is less than 0");
                            break;
                        }

                        String readString = new String(buf);

                        reportTestInfo("GPSCOM", "read["+readSize+"]:" + convertEscapedChar(readString.substring(0, 50)));
                        MemoryCheck();
                        Thread.sleep(2000);
                    } catch (IllegalArgumentException e) {
                        reportTestInfo("GPSCOM", "IllegalArgumentException:" + e);
                    } catch (InterruptedException e) {
                        reportTestInfo("GPSCOM", "InterruptedException:" + e);
                    } catch (IOException e) {
                        reportTestInfo("GPSCOM", "IOException:" + e);
                    }
                }

                try {
                   if (ldo != null) {
                       ldo.setCurrentMode(Gpio.WRITE_MODE);
                       ldo.write(false);
                       isLDOEnabled = false;
                   }
                   gpsComm.close();
                   reportTestInfo("GPSCOM", "GPS comm is closed");
                } catch (IOException e1) {
                   reportTestInfo("GPSCOM", "IOException:" + e1);
                }
                notifyDestroyed();
            }

            private String convertEscapedChar(String original)
            {
                String escaped = "";
                char[] ctest = original.toCharArray();
                for (int i = 0; i < ctest.length; i++)
                {
                    if ((ctest[i] != '\r') && (ctest[i] != '\n'))
                    {
                        escaped = escaped + ctest[i];
                    }
                    else
                    {
                        escaped = escaped + '.';
                    }
                }
                return escaped;
            }

            private void reportTestInfo(String name, String msg) {
                String content = name + ":" + msg.replace(' ', '.');
                String reportInfo = REPORT_SERVER_FORMAT + content;

                if (allowLogPrint)
                {
                    System.out.println("[" + name + "]" + content + "\r\n");
                    //return;
                }

                try {
                    URL url = new URL(reportInfo);
                    HttpURLConnection httpConn = (HttpURLConnection)url.openConnection();
                    httpConn.setRequestMethod(HttpURLConnection.POST);
                    InputStream dis = httpConn.getInputStream();
                    dis.close();
                    httpConn.disconnect();
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                }
            }

            public void MemoryCheck() {
                long free =  Runtime.getRuntime().freeMemory();

                if (free < gcMemory) {
                    Runtime.getRuntime().gc();
                    reportTestInfo("GPSCOM", "gc when left " + free + "/" + gcMemory);
                }
            }
        }.start();
    }
}