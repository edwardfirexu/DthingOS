#ifndef __VM_COMMON_H__
#define __VM_COMMON_H__

//#pragma comment(lib,"../loader/Debug/loader.lib")

#define ARCH_X86
#define INLINE

#define _TEST_ED_    //test edward code of classloader


#ifdef ARCH_X86
	#pragma comment(lib, "Winmm.lib")
	#include <Windows.h>
	#include <Mmsystem.h>
#endif

#include <stdint.h>
#include <crtl.h>
#include <stdio.h>
#include <assert.h>


typedef uint8_t		u1 ;
typedef uint16_t	u2 ;
typedef uint32_t	u4 ;
typedef uint64_t	u8 ;
typedef  int8_t		s1 ;
typedef  int16_t	s2 ;
typedef  int32_t	s4 ;
typedef  int64_t	s8 ;
typedef  int   vbool;



#define DVM_MALLOC		CRTL_malloc
#define DVM_MEMSET		CRTL_memset
#define DVM_FREE		CRTL_free
#define DVM_STRCMP      CRTL_strcmp
#define DVM_ASSERT		assert

#define false (0)
#define true  (1)


/* flags for dvmMalloc*/
enum {
    ALLOC_DEFAULT = 0x00,
    ALLOC_DONT_TRACK = 0x01,  // don't add to internal tracking list 
    ALLOC_NON_MOVING = 0x02,
};


#define __MAY_ERROR__ 1


#endif