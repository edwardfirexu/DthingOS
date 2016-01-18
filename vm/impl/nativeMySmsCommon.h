/* DO NOT EDIT THIS FILE - it is machine generated */
#include <dthing.h>
#include <kni.h>
#if defined(ARCH_ARM_SPD)
#include <Mn_api.h>
#include <mn_events.h>
#include <caf.h>
#endif

/* Header for class jp.co.cmcc.message.sms */

#ifndef __NATIVE_MYSMSCOMMON_H__
#define __NATIVE_MYSMSCOMMON_H__

#ifdef __cplusplus
extern "C" {
#endif

#if defined(ARCH_ARM_SPD)

#define JAVA_ENC_GSM_7BIT   0
#define JAVA_ENC_8BIT_BIN   1
#define JAVA_ENC_UCS_2      2
#define JAVA_ENC_ASCII      3

#define     JAVASMS_HEAD_8BIT_LENGTH               5   // the length of SMS head

#define     JAVASMS_HEAD_IEI_POS         0     // the pos of SMS indicate
#define     JAVASMS_HEAD_IEL_POS         1     // the pos of SMS indicate length
#define     JAVASMS_HEAD_REF_NUM_POS      2     // the pos of reference number
#define     JAVASMS_HEAD_8BIT_MAX_NUM_POS      3     // the pos of max number
#define     JAVASMS_HEAD_8BIT_SEQ_NUM_POS        4     // the pos sequence number
#define     JAVASMS_HEAD_16BIT_MAX_NUM_POS        4
#define     JAVASMS_HEAD_16BIT_SEQ_NUM_POS        5

#define     JAVASMS_HEAD_LENGTH_FOR_PORT            6     // the length of SMS head
#define     JAVASMS_HEAD_IEI_FOR_PORT             0x05  // the indicate of SMS
#define     JAVASMS_HEAD_IEL_FOR_PORT             0x04  // the length of SMS indicate
#define     JAVASMS_HEAD_IEI_POS_FOR_PORT         0     // the pos of SMS indicate
#define     JAVASMS_HEAD_IEL_POS_FOR_PORT         1     // the pos of SMS indicate length
#define     JAVASMS_HEAD_SRC_PORTH_POS   2     // the pos of src port(high 8bit)
#define     JAVASMS_HEAD_SRC_PORTL_POS      3     // the pos of srct port(low 8bit)
#define     JAVASMS_HEAD_DST_PORTH_POS   4     // the pos of dest port(high 8bit)
#define     JAVASMS_HEAD_DST_PORTL_POS      5     // the pos of dest port(low 8bit)
#define     JAVASMS_VCARD_PORT_NUM       0x23F4

#define        MMISMS_MAX_DEF_SPLIT_LEN    153   // the length of default split-SMS

#define MSISDN_LEN_MAX        32

#define MMISMS_JAVA_MAX_UCS2_BYTE_LEN        134
#define MMISMS_JAVA_MAX_UCS2_SPLIT_LEN        128

#define MMISMS_JAVA_MAX_DEF_BYTE_LEN        154
#define MMISMS_JAVA_MAX_DEF_SPLIT_LEN        147

#define MMISMS_JAVA_MAX_8BIT_BYTE_LEN        134
#define MMISMS_JAVA_MAX_8BIT_SPLIT_LEN        128

#define  JAVASMS_MT_OFFSERT_YEAR    2000

#define    MMISMS_DEFAULT_WORD_NUM            5
#define MMISMS_VALID_DATA_LEN_DIV        2

//支持最大的群发号码个数（范围：30-100）
#define JAVASMS_DEST_ADDR_MAX_NUM     100

#define JAVASMS_NUMBER_MAX_LEN   40     //baokun change 20 to 40

#define JAVA_PHONE_NUM_MAX_SIZE       (32)      /** phone number length */
#define JAVA_MAX_LONG_SMS_NUM         (30)
#define JAVA_SMS_CONTENT_MAX_LEN      (MMISMS_MAX_DEF_SPLIT_LEN*MMISMS_SPLIT_MAX_NUM)
#define JAVA_SMS_INVAILD_INDEX        0xFFFF

#define MMISMS_RECIEVER_NUM_MAX             20
#define MMISMS_SPLIT_MAX_NUM          6

typedef enum _JAVA_SMS_ERROR_ID_E
{
  JAVA_SMS_ERROR_NO = 0,    //no error.
  JAVA_SMS_ERROR_REPEAT,    //receive repeated sms.
  JAVA_SMS_ERROR_ALLOC,   //alloc memory fail.
}JAVA_SMS_ERROR_ID_E;

typedef struct _JAVA_SMS_USER_DATA_T
{
    MN_SMS_USER_DATA_HEAD_T  user_data_head_t;     // the head structure
    MN_SMS_USER_VALID_DATA_T user_valid_data_t;    // the used valid data structure
} JAVA_SMS_USER_DATA_T;

/** SMS data structure */
typedef struct SCISmsMessage_s
{
  uint8  addr[JAVA_PHONE_NUM_MAX_SIZE]; /*** If this is an incoming Short Message: the source address  * If this is an outgoing Short Message: the destination address  */
  uint16 srcPort;       /** The source port number. Unused for CBS */
  uint16 dstPort;       /** The destination port number for Sms or Message ID for CBS*/
  uint8 encoding;      /** The message encoding :  * 0 = 7-bit alphabet   * 1 = 8-bit alphabet     * 2 = 8-bit binary   * 3 = 16-bit alphabet   */
  uint64 timestamp;      /** Timestamp (ms since 1970). Unused for CBS */
  int32 seq_id;         /**   * Sequence id of received message or -1 for non-fragmented message.   * In case the target APIs already defragment, behave as non-fragmented.    *   */
  int32 seq_idx;         /**   * Index in sequence of received message for SMS or inc page number for CBS. 1-based.   *  1 for non-fragmented messages.   * In case the target APIs already defragment, behave as non-fragmented.   *   */
  int32 seq_len;        /** * Sequence length of received message for SMS or number of pages for CBS.    * 1 for non-fragmented messages.    * In case the target APIs already defragment, behave as non-fragmented.    *    */
  uint16 length;         /** The length of the payload (data) only */
  uint8 * data;         /* more allocated as required */
}SCISmsMessage;

typedef struct
{
  SCISmsMessage    myriad_sms[JAVA_MAX_LONG_SMS_NUM];
}JAVA_LONG_SMS_T;

typedef struct _JAVA_SMS_CONTENT_T
{
  uint16 length;                             // the length of data
  uint8 data[JAVA_SMS_CONTENT_MAX_LEN+1];    // the data of user inputting
}JAVA_SMS_CONTENT_T;

typedef struct _JAVA_PARTY_NUMBER_T
{
    MN_NUMBER_TYPE_E  number_type;
    uint16            num_len;
    uint8             bcd_num[MN_MAX_ADDR_BCD_LEN];
} JAVA_PARTY_NUMBER_T;

typedef struct
{
    uint8   mday;       // day of the month - [1,31]
    uint8   mon;        // months  - [1,12]
    uint16  year;       // years [2000,2049]
    uint8   wday;       // days since Sunday - [0,6], (Sunday : 0, Monday : 1)
}SCI_DATE_T;

typedef struct
{
    uint8   sec;        // secondsafter the minute - [0,59]
    uint8   min;        // minutesafter the hour - [0,59]
    uint8   hour;       // hours since midnight - [0,23]
}SCI_TIME_T;

typedef struct
{
    uint8   number;             // the number of dest addr
    uint8   dest_addr_id;        // the index of dest_addr
    uint8   dest_addr[ JAVASMS_DEST_ADDR_MAX_NUM ][JAVASMS_NUMBER_MAX_LEN+1]; // the destination address
}MMISMS_NUMBER_LIST_T;

//读取短信内容
typedef struct
{
    CAF_STRING_T time_string;   //时间
    CAF_STRING_T name_string;    //来自
    CAF_STRING_T content_string;     //内容
}MMISMS_READMSG_CONTENT_T;

typedef struct
{
    uint16                    failed_count;
    MMISMS_NUMBER_LIST_T    dest_list;
    uint8                    update_dest_addr[JAVASMS_NUMBER_MAX_LEN+2];
}MMISMS_DEST_ADDR_INFO_T;

#endif  //ARCH_ARM_SPD

#ifdef __cplusplus
}
#endif
#endif // __NATIVE_MYSMSCOMMON_H__
