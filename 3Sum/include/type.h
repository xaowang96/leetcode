#ifndef __TYPE_H__
#define __TYPE_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#define AMCK(flag, log, next)           \
if(flag)\
{   \
    log; \
    next; \
}


#ifndef false
#define false               0
#endif

#ifndef true
#define true                1
#endif




#ifndef bool
typedef int                     bool;
#endif

#ifndef U8
typedef unsigned char           U8;
#endif

#ifndef S8
typedef char                    S8;
#endif

#ifndef U32
typedef unsigned int            U32;
#endif

#ifndef S32
typedef int                     S32;
#endif

#ifndef U64
typedef unsigned long long int  U64;
#endif

#ifndef S64
typedef long long int           S64;
#endif

#ifndef uint8
typedef unsigned char           uint8;
#endif

#ifndef int8
typedef char                    int8;
#endif

#ifndef uint16
typedef unsigned short          uint16;
#endif

#ifndef int16
typedef short                   int16;
#endif

#ifndef uint32
typedef unsigned int            uint32;
#endif

#ifndef int32
typedef int                     int32;
#endif

#ifndef RFAIL
#define RFAIL       -1
#endif

#ifndef RSUCCESS
#define RSUCCESS    0
#endif

#ifndef FAILURE
#define FAILURE -1
#endif

#ifndef  DWORD
#define  DWORD         uint32
#endif
#ifndef  WORD
#define  WORD          uint16
#endif
#ifndef  BYTE
#define  BYTE          uint8
#endif
#ifndef  BOOL
#define  BOOL          uint32
#endif

#ifndef TRUE
#define TRUE    1
#endif

#ifndef FALSE
#define FALSE   0
#endif


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif
