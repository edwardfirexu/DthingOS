/* DO NOT EDIT THIS FILE - it is machine generated */
#include <kni.h>

/* Header for native method signature information. */

#ifndef __NATIVE_METHODS_H__
#define __NATIVE_METHODS_H__
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    const char* name;
    const char* signature;
    KniFunc fnPtr;
} KniNativeMethodInfo;

typedef struct {
    const char* classpath;
    KniNativeMethodInfo* methods;
    int methodCount;
} KniClassNativeMethodInfo;

#define NATIVE_CLASSES_COUNT 34

/* com.yarlungsoft.ams.Scheduler native APIs */
KniNativeMethodInfo gJava_com_yarlungsoft_ams_Scheduler[2] = {
    {"reportState",         "(I)V",                  (KniFunc)Java_com_yarlungsoft_ams_Scheduler_reportState},
    {"reportRunningObject", "(Ljava/lang/Object;)V", (KniFunc)Java_com_yarlungsoft_ams_Scheduler_reportRunningObject},
};

/* com.yarlungsoft.util.SystemInputStream native APIs */
KniNativeMethodInfo gJava_com_yarlungsoft_util_SystemInputStream[1] = {
    {"readN", "([BII)I", (KniFunc)Java_com_yarlungsoft_util_SystemInputStream_readN},
};

/* com.yarlungsoft.util.SystemPrintStream native APIs */
KniNativeMethodInfo gJava_com_yarlungsoft_util_SystemPrintStream[2] = {
    {"flush", "()V",  (KniFunc)Java_com_yarlungsoft_util_SystemPrintStream_flush},
    {"write", "(I)V", (KniFunc)Java_com_yarlungsoft_util_SystemPrintStream_write},
};

/* iot.oem.adc.ADCManager native APIs */
KniNativeMethodInfo gJava_iot_oem_adc_ADCManager[3] = {
    {"init0",    "()I",  (KniFunc)Java_iot_oem_adc_ADCManager_init0},
    {"read0",    "(I)I", (KniFunc)Java_iot_oem_adc_ADCManager_read0},
    {"destroy0", "()I",  (KniFunc)Java_iot_oem_adc_ADCManager_destroy0},
};

/* iot.oem.battery.BatteryManager native APIs */
KniNativeMethodInfo gJava_iot_oem_battery_BatteryManager[2] = {
    {"getStatus0",      "()I", (KniFunc)Java_iot_oem_battery_BatteryManager_getStatus0},
    {"getTemperature0", "()I", (KniFunc)Java_iot_oem_battery_BatteryManager_getTemperature0},
};

/* iot.oem.ear.EarManager native APIs */
KniNativeMethodInfo gJava_iot_oem_ear_EarManager[4] = {
    {"init0",      "()I",  (KniFunc)Java_iot_oem_ear_EarManager_init0},
    {"getStatus0", "()I",  (KniFunc)Java_iot_oem_ear_EarManager_getStatus0},
    {"setStatus0", "(Z)I", (KniFunc)Java_iot_oem_ear_EarManager_setStatus0},
    {"close0",     "()I",  (KniFunc)Java_iot_oem_ear_EarManager_close0},
};

/* iot.oem.gpio.Gpio native APIs */
KniNativeMethodInfo gJava_iot_oem_gpio_Gpio[8] = {
    {"open0",           "(I)I",  (KniFunc)Java_iot_oem_gpio_Gpio_open0},
    {"setCurrentMode0", "(II)I", (KniFunc)Java_iot_oem_gpio_Gpio_setCurrentMode0},
    {"getCurrentMode0", "(I)I",  (KniFunc)Java_iot_oem_gpio_Gpio_getCurrentMode0},
    {"read0",           "(I)I",  (KniFunc)Java_iot_oem_gpio_Gpio_read0},
    {"write0",          "(IZ)I", (KniFunc)Java_iot_oem_gpio_Gpio_write0},
    {"registerInt0",    "(II)I", (KniFunc)Java_iot_oem_gpio_Gpio_registerInt0},
    {"unregisterInt0",  "(I)I",  (KniFunc)Java_iot_oem_gpio_Gpio_unregisterInt0},
    {"close0",          "(I)I",  (KniFunc)Java_iot_oem_gpio_Gpio_close0},
};

/* iot.oem.i2c.I2CManager native APIs */
KniNativeMethodInfo gJava_iot_oem_i2c_I2CManager[6] = {
    {"open0",    "(II)I",     (KniFunc)Java_iot_oem_i2c_I2CManager_open0},
    {"getRate0", "(I)I",      (KniFunc)Java_iot_oem_i2c_I2CManager_getRate0},
    {"setRate0", "(II)I",     (KniFunc)Java_iot_oem_i2c_I2CManager_setRate0},
    {"close0",   "(I)I",      (KniFunc)Java_iot_oem_i2c_I2CManager_close0},
    {"read0",    "(III[BI)I", (KniFunc)Java_iot_oem_i2c_I2CManager_read0},
    {"write0",   "(III[BI)I", (KniFunc)Java_iot_oem_i2c_I2CManager_write0},
};

/* iot.oem.lcd.LCD native APIs */
KniNativeMethodInfo gJava_iot_oem_lcd_LCD[6] = {
    {"setBackgroundStatus0", "(Z)I",                    (KniFunc)Java_iot_oem_lcd_LCD_setBackgroundStatus0},
    {"getBackgroundStatus0", "()I",                     (KniFunc)Java_iot_oem_lcd_LCD_getBackgroundStatus0},
    {"getHeight0",           "()I",                     (KniFunc)Java_iot_oem_lcd_LCD_getHeight0},
    {"getWidth0",            "()I",                     (KniFunc)Java_iot_oem_lcd_LCD_getWidth0},
    {"drawString0",          "(IILjava/lang/String;)I", (KniFunc)Java_iot_oem_lcd_LCD_drawString0},
    {"clean0",               "()I",                     (KniFunc)Java_iot_oem_lcd_LCD_clean0},
};

/* iot.oem.micophone.Micophone native APIs */
KniNativeMethodInfo gJava_iot_oem_micophone_Micophone[8] = {
    {"open0",      "()I",  (KniFunc)Java_iot_oem_micophone_Micophone_open0},
    {"getStatus0", "()I",  (KniFunc)Java_iot_oem_micophone_Micophone_getStatus0},
    {"setStatus0", "(Z)I", (KniFunc)Java_iot_oem_micophone_Micophone_setStatus0},
    {"getInPath0", "()I",  (KniFunc)Java_iot_oem_micophone_Micophone_getInPath0},
    {"setInPath0", "(I)I", (KniFunc)Java_iot_oem_micophone_Micophone_setInPath0},
    {"getGain0",   "()I",  (KniFunc)Java_iot_oem_micophone_Micophone_getGain0},
    {"setGain0",   "(I)I", (KniFunc)Java_iot_oem_micophone_Micophone_setGain0},
    {"close0",     "()I",  (KniFunc)Java_iot_oem_micophone_Micophone_close0},
};

/* iot.oem.pcmchannel.PCMChannel native APIs */
KniNativeMethodInfo gJava_iot_oem_pcmchannel_PCMChannel[8] = {
    {"open0",         "()I",  (KniFunc)Java_iot_oem_pcmchannel_PCMChannel_open0},
    {"getStatus0",    "()I",  (KniFunc)Java_iot_oem_pcmchannel_PCMChannel_getStatus0},
    {"setStatus0",    "(Z)I", (KniFunc)Java_iot_oem_pcmchannel_PCMChannel_setStatus0},
    {"getFrequency0", "()I",  (KniFunc)Java_iot_oem_pcmchannel_PCMChannel_getFrequency0},
    {"setFrequency0", "(I)I", (KniFunc)Java_iot_oem_pcmchannel_PCMChannel_setFrequency0},
    {"getMode0",      "()I",  (KniFunc)Java_iot_oem_pcmchannel_PCMChannel_getMode0},
    {"setMode0",      "(I)I", (KniFunc)Java_iot_oem_pcmchannel_PCMChannel_setMode0},
    {"close0",        "()I",  (KniFunc)Java_iot_oem_pcmchannel_PCMChannel_close0},
};

/* iot.oem.pwm.PWMManager native APIs */
KniNativeMethodInfo gJava_iot_oem_pwm_PWMManager[2] = {
    {"config0",  "(III)I", (KniFunc)Java_iot_oem_pwm_PWMManager_config0},
    {"command0", "(III)I", (KniFunc)Java_iot_oem_pwm_PWMManager_command0},
};

/* iot.oem.sim.SimManager native APIs */
KniNativeMethodInfo gJava_iot_oem_sim_SimManager[5] = {
    {"close0",          "()I",                                     (KniFunc)Java_iot_oem_sim_SimManager_close0},
    {"enablePinLock0",  "(Ljava/lang/String;)I",                   (KniFunc)Java_iot_oem_sim_SimManager_enablePinLock0},
    {"disablePinLock0", "(Ljava/lang/String;)I",                   (KniFunc)Java_iot_oem_sim_SimManager_disablePinLock0},
    {"unlockPin0",      "(Ljava/lang/String;)I",                   (KniFunc)Java_iot_oem_sim_SimManager_unlockPin0},
    {"changePin0",      "(Ljava/lang/String;Ljava/lang/String;)I", (KniFunc)Java_iot_oem_sim_SimManager_changePin0},
};

/* iot.oem.spi.SPIManager native APIs */
KniNativeMethodInfo gJava_iot_oem_spi_SPIManager[6] = {
    {"open0",    "(II)I",    (KniFunc)Java_iot_oem_spi_SPIManager_open0},
    {"getRate0", "(I)I",     (KniFunc)Java_iot_oem_spi_SPIManager_getRate0},
    {"setRate0", "(II)I",    (KniFunc)Java_iot_oem_spi_SPIManager_setRate0},
    {"close0",   "(I)I",     (KniFunc)Java_iot_oem_spi_SPIManager_close0},
    {"read0",    "(II[BI)I", (KniFunc)Java_iot_oem_spi_SPIManager_read0},
    {"write0",   "(II[BI)I", (KniFunc)Java_iot_oem_spi_SPIManager_write0},
};

/* iot.oem.spk.SpeakerManager native APIs */
KniNativeMethodInfo gJava_iot_oem_spk_SpeakerManager[4] = {
    {"init0",      "()I",  (KniFunc)Java_iot_oem_spk_SpeakerManager_init0},
    {"getStatus0", "()I",  (KniFunc)Java_iot_oem_spk_SpeakerManager_getStatus0},
    {"setStatus0", "(Z)I", (KniFunc)Java_iot_oem_spk_SpeakerManager_setStatus0},
    {"close0",     "()I",  (KniFunc)Java_iot_oem_spk_SpeakerManager_close0},
};

/* iot.oem.usb.USBConnection native APIs */
KniNativeMethodInfo gJava_iot_oem_usb_USBConnection[2] = {
    {"open0",  "(Ljava/lang/String;)I", (KniFunc)Java_iot_oem_usb_USBConnection_open0},
    {"close0", "(I)I",                  (KniFunc)Java_iot_oem_usb_USBConnection_close0},
};

/* java.io.File native APIs */
KniNativeMethodInfo gJava_java_io_File[8] = {
    {"createFile0",   "(Ljava/lang/String;)Z",                   (KniFunc)Java_java_io_File_createFile0},
    {"delete0",       "(Ljava/lang/String;)Z",                   (KniFunc)Java_java_io_File_delete0},
    {"exists0",       "(Ljava/lang/String;)Z",                   (KniFunc)Java_java_io_File_exists0},
    {"isDirectory0",  "(Ljava/lang/String;)Z",                   (KniFunc)Java_java_io_File_isDirectory0},
    {"isFile0",       "(Ljava/lang/String;)Z",                   (KniFunc)Java_java_io_File_isFile0},
    {"lastModified0", "(Ljava/lang/String;)J",                   (KniFunc)Java_java_io_File_lastModified0},
    {"length0",       "(Ljava/lang/String;)J",                   (KniFunc)Java_java_io_File_length0},
    {"list0",         "(Ljava/lang/String;)[Ljava/lang/String;", (KniFunc)Java_java_io_File_list0},
};

/* java.lang.AsyncIO native APIs */
KniNativeMethodInfo gJava_java_lang_AsyncIO[3] = {
    {"getCurNotifierState", "()I",  (KniFunc)Java_java_lang_AsyncIO_getCurNotifierState},
    {"setCurNotifierState", "(I)I", (KniFunc)Java_java_lang_AsyncIO_setCurNotifierState},
    {"waitSignalOrTimeOut", "()V",  (KniFunc)Java_java_lang_AsyncIO_waitSignalOrTimeOut},
};

/* java.lang.Class native APIs */
KniNativeMethodInfo gJava_java_lang_Class[7] = {
    {"forName",          "(Ljava/lang/String;)Ljava/lang/Class;", (KniFunc)Java_java_lang_Class_forName},
    {"isInstance",       "(Ljava/lang/Object;)Z",                 (KniFunc)Java_java_lang_Class_isInstance},
    {"isAssignableFrom", "(Ljava/lang/Class;)Z",                  (KniFunc)Java_java_lang_Class_isAssignableFrom},
    {"isInterface",      "()Z",                                   (KniFunc)Java_java_lang_Class_isInterface},
    {"isArray",          "()Z",                                   (KniFunc)Java_java_lang_Class_isArray},
    {"newInstance0",     "()Ljava/lang/Object;",                  (KniFunc)Java_java_lang_Class_newInstance0},
    {"getName",          "()Ljava/lang/String;",                  (KniFunc)Java_java_lang_Class_getName},
};

/* java.lang.DThread native APIs */
KniNativeMethodInfo gJava_java_lang_DThread[5] = {
    {"start0",         "()V",                   (KniFunc)Java_java_lang_Thread_start},
    {"sleep0",         "(J)V",                  (KniFunc)Java_java_lang_Thread_sleep},
    {"activeCount0",   "()I",                   (KniFunc)Java_java_lang_Thread_activeCount},
    {"currentThread0", "()Ljava/lang/DThread;", (KniFunc)Java_java_lang_Thread_currentThread},
    {"isAlive0",       "()Z",                   (KniFunc)Java_java_lang_Thread_isAlive},
};

/* java.lang.Double native APIs */
KniNativeMethodInfo gJava_java_lang_Double[3] = {
    {"doubleToLongBits",    "(D)J", (KniFunc)Java_java_lang_Double_doubleToLongBits},
    {"doubleToRawLongBits", "(D)J", (KniFunc)Java_java_lang_Double_doubleToRawLongBits},
    {"longBitsToDouble",    "(J)D", (KniFunc)Java_java_lang_Double_longBitsToDouble},
};

/* java.lang.Float native APIs */
KniNativeMethodInfo gJava_java_lang_Float[3] = {
    {"floatToIntBits",    "(F)I", (KniFunc)Java_java_lang_Float_floatToIntBits},
    {"floatToRawIntBits", "(F)I", (KniFunc)Java_java_lang_Float_floatToRawIntBits},
    {"intBitsToFloat",    "(I)F", (KniFunc)Java_java_lang_Float_intBitsToFloat},
};

/* java.lang.Math native APIs */
KniNativeMethodInfo gJava_java_lang_Math[4] = {
    {"cos",  "(D)D", (KniFunc)Java_java_lang_Math_cos},
    {"sin",  "(D)D", (KniFunc)Java_java_lang_Math_sin},
    {"sqrt", "(D)D", (KniFunc)Java_java_lang_Math_sqrt},
    {"tan",  "(D)D", (KniFunc)Java_java_lang_Math_tan},
};

/* java.lang.Object native APIs */
KniNativeMethodInfo gJava_java_lang_Object[6] = {
    {"internalClone", "(Ljava/lang/Cloneable;)Ljava/lang/Object;", (KniFunc)Java_java_lang_Object_internalClone},
    {"getClass",      "()Ljava/lang/Class;",                       (KniFunc)Java_java_lang_Object_getClass},
    {"hashCode",      "()I",                                       (KniFunc)Java_java_lang_Object_hashCode},
    {"notify",        "()V",                                       (KniFunc)Java_java_lang_Object_notify},
    {"notifyAll",     "()V",                                       (KniFunc)Java_java_lang_Object_notifyAll},
    {"wait",          "(JI)V",                                     (KniFunc)Java_java_lang_Object_wait},
};

/* java.lang.Runtime native APIs */
KniNativeMethodInfo gJava_java_lang_Runtime[3] = {
    {"freeMemory",  "()J", (KniFunc)Java_java_lang_Runtime_freeMemory},
    {"totalMemory", "()J", (KniFunc)Java_java_lang_Runtime_totalMemory},
    {"gc",          "()V", (KniFunc)Java_java_lang_Runtime_gc},
};

/* java.lang.String native APIs */
KniNativeMethodInfo gJava_java_lang_String[1] = {
    {"intern", "()Ljava/lang/String;", (KniFunc)Java_java_lang_String_intern},
};

/* java.lang.System native APIs */
KniNativeMethodInfo gJava_java_lang_System[4] = {
    {"arraycopy",         "(Ljava/lang/Object;ILjava/lang/Object;II)V",               (KniFunc)Java_java_lang_System_arraycopy},
    {"currentTimeMillis", "()J",                                                      (KniFunc)Java_java_lang_System_currentTimeMillis},
    {"getProperty",       "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", (KniFunc)Java_java_lang_System_getProperty},
    {"identityHashCode",  "(Ljava/lang/Object;)I",                                    (KniFunc)Java_java_lang_System_identityHashCode},
};

/* java.lang.Thread native APIs */
KniNativeMethodInfo gJava_java_lang_Thread[11] = {
    {"activeCount",   "()I",                   (KniFunc)Java_java_lang_Thread_activeCount},
    {"currentThread", "()Ljava/lang/Thread;",  (KniFunc)Java_java_lang_Thread_currentThread},
    {"interrupt",     "()V",                   (KniFunc)Java_java_lang_Thread_interrupt},
    {"interrupted",   "()Z",                   (KniFunc)Java_java_lang_Thread_interrupted},
    {"isAlive",       "()Z",                   (KniFunc)Java_java_lang_Thread_isAlive},
    {"isInterrupted", "()Z",                   (KniFunc)Java_java_lang_Thread_isInterrupted},
    {"setPriority",   "(I)V",                  (KniFunc)Java_java_lang_Thread_setPriority},
    {"sleep",         "(JI)V",                 (KniFunc)Java_java_lang_Thread_sleep},
    {"start",         "()V",                   (KniFunc)Java_java_lang_Thread_start},
    {"yield",         "()V",                   (KniFunc)Java_java_lang_Thread_yield},
    {"holdsLock",     "(Ljava/lang/Object;)Z", (KniFunc)Java_java_lang_Thread_holdsLock},
};

/* java.lang.Throwable native APIs */
KniNativeMethodInfo gJava_java_lang_Throwable[1] = {
    {"printStackTrace0", "(Ljava/lang/Object;)V", (KniFunc)Java_java_lang_Throwable_printStackTrace0},
};

/* java.net.NetNativeBridge native APIs */
KniNativeMethodInfo gJava_java_net_NetNativeBridge[9] = {
    {"isNetworkInited", "()Z",          (KniFunc)Java_java_net_NetNativeBridge_isNetworkInited},
    {"startUpNetwork",  "([B)I",        (KniFunc)Java_java_net_NetNativeBridge_startUpNetwork},
    {"socket0",         "(Z)I",         (KniFunc)Java_java_net_NetNativeBridge_socket0},
    {"connect0",        "(IIII)I",      (KniFunc)Java_java_net_NetNativeBridge_connect0},
    {"recv0",           "(I[BII)I",     (KniFunc)Java_java_net_NetNativeBridge_recv0},
    {"send0",           "(I[BII)I",     (KniFunc)Java_java_net_NetNativeBridge_send0},
    {"recvfrom0",       "(I[BIIIIII)I", (KniFunc)Java_java_net_NetNativeBridge_recvfrom0},
    {"sendto0",         "(I[BIIIII)I",  (KniFunc)Java_java_net_NetNativeBridge_sendto0},
    {"closeSocket0",    "(I)I",         (KniFunc)Java_java_net_NetNativeBridge_closeSocket0},
};

/* java.util.TimeZone native APIs */
KniNativeMethodInfo gJava_java_util_TimeZone[1] = {
    {"getDefaultId", "()Ljava/lang/String;", (KniFunc)Java_java_util_TimeZone_getDefaultId},
};

/* jp.co.cmcc.atcommand.ATCommandConnection native APIs */
KniNativeMethodInfo gJava_jp_co_cmcc_atcommand_ATCommandConnection[5] = {
    {"open0",     "()I",                                    (KniFunc)Java_jp_co_cmcc_atcommand_ATCommandConnection_open0},
    {"send0",     "(Ljava/lang/String;)Ljava/lang/String;", (KniFunc)Java_jp_co_cmcc_atcommand_ATCommandConnection_send0},
    {"sendAsyn0", "(Ljava/lang/String;)I",                  (KniFunc)Java_jp_co_cmcc_atcommand_ATCommandConnection_sendAsyn0},
    {"get0",      "()Ljava/lang/String;",                   (KniFunc)Java_jp_co_cmcc_atcommand_ATCommandConnection_get0},
    {"close0",    "()I",                                    (KniFunc)Java_jp_co_cmcc_atcommand_ATCommandConnection_close0},
};

/* jp.co.cmcc.message.sms.MyMessageSender native APIs */
KniNativeMethodInfo gJava_jp_co_cmcc_message_sms_MyMessageSender[1] = {
    {"nSend", "(Ljava/lang/String;III[BI)Z", (KniFunc)Java_jp_co_cmcc_message_sms_MyMessageSender_nSend},
};

/* jp.co.cmcc.message.sms.MySmsConnectionThread native APIs */
KniNativeMethodInfo gJava_jp_co_cmcc_message_sms_MySmsConnectionThread[4] = {
    {"nReadMessage",   "()Z", (KniFunc)Java_jp_co_cmcc_message_sms_MySmsConnectionThread_nReadMessage},
    {"nDeleteMessage", "()V", (KniFunc)Java_jp_co_cmcc_message_sms_MySmsConnectionThread_nDeleteMessage},
    {"nRegister",      "()Z", (KniFunc)Java_jp_co_cmcc_message_sms_MySmsConnectionThread_nRegister},
    {"nUnregister",    "()V", (KniFunc)Java_jp_co_cmcc_message_sms_MySmsConnectionThread_nUnregister},
};

KniClassNativeMethodInfo gNativeMthTab[NATIVE_CLASSES_COUNT] = {
    {"Lcom/yarlungsoft/ams/Scheduler;",                gJava_com_yarlungsoft_ams_Scheduler,                2},
    {"Lcom/yarlungsoft/util/SystemInputStream;",       gJava_com_yarlungsoft_util_SystemInputStream,       1},
    {"Lcom/yarlungsoft/util/SystemPrintStream;",       gJava_com_yarlungsoft_util_SystemPrintStream,       2},
    {"Liot/oem/adc/ADCManager;",                       gJava_iot_oem_adc_ADCManager,                       3},
    {"Liot/oem/battery/BatteryManager;",               gJava_iot_oem_battery_BatteryManager,               2},
    {"Liot/oem/ear/EarManager;",                       gJava_iot_oem_ear_EarManager,                       4},
    {"Liot/oem/gpio/Gpio;",                            gJava_iot_oem_gpio_Gpio,                            8},
    {"Liot/oem/i2c/I2CManager;",                       gJava_iot_oem_i2c_I2CManager,                       6},
    {"Liot/oem/lcd/LCD;",                              gJava_iot_oem_lcd_LCD,                              6},
    {"Liot/oem/micophone/Micophone;",                  gJava_iot_oem_micophone_Micophone,                  8},
    {"Liot/oem/pcmchannel/PCMChannel;",                gJava_iot_oem_pcmchannel_PCMChannel,                8},
    {"Liot/oem/pwm/PWMManager;",                       gJava_iot_oem_pwm_PWMManager,                       2},
    {"Liot/oem/sim/SimManager;",                       gJava_iot_oem_sim_SimManager,                       5},
    {"Liot/oem/spi/SPIManager;",                       gJava_iot_oem_spi_SPIManager,                       6},
    {"Liot/oem/spk/SpeakerManager;",                   gJava_iot_oem_spk_SpeakerManager,                   4},
    {"Liot/oem/usb/USBConnection;",                    gJava_iot_oem_usb_USBConnection,                    2},
    {"Ljava/io/File;",                                 gJava_java_io_File,                                 8},
    {"Ljava/lang/AsyncIO;",                            gJava_java_lang_AsyncIO,                            3},
    {"Ljava/lang/Class;",                              gJava_java_lang_Class,                              7},
    {"Ljava/lang/DThread;",                            gJava_java_lang_DThread,                            5},
    {"Ljava/lang/Double;",                             gJava_java_lang_Double,                             3},
    {"Ljava/lang/Float;",                              gJava_java_lang_Float,                              3},
    {"Ljava/lang/Math;",                               gJava_java_lang_Math,                               4},
    {"Ljava/lang/Object;",                             gJava_java_lang_Object,                             6},
    {"Ljava/lang/Runtime;",                            gJava_java_lang_Runtime,                            3},
    {"Ljava/lang/String;",                             gJava_java_lang_String,                             1},
    {"Ljava/lang/System;",                             gJava_java_lang_System,                             4},
    {"Ljava/lang/Thread;",                             gJava_java_lang_Thread,                             11},
    {"Ljava/lang/Throwable;",                          gJava_java_lang_Throwable,                          1},
    {"Ljava/net/NetNativeBridge;",                     gJava_java_net_NetNativeBridge,                     9},
    {"Ljava/util/TimeZone;",                           gJava_java_util_TimeZone,                           1},
    {"Ljp/co/cmcc/atcommand/ATCommandConnection;",     gJava_jp_co_cmcc_atcommand_ATCommandConnection,     5},
    {"Ljp/co/cmcc/message/sms/MyMessageSender;",       gJava_jp_co_cmcc_message_sms_MyMessageSender,       1},
    {"Ljp/co/cmcc/message/sms/MySmsConnectionThread;", gJava_jp_co_cmcc_message_sms_MySmsConnectionThread, 4},
};

#ifdef __cplusplus
}
#endif
#endif // __NATIVE_METHODS_H__
