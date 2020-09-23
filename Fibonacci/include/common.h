#ifndef __COMMON_H__
#define __COMMON_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "type.h"
#include "log.h"

#define BYTE0(x) (0xFF&(x>>0))

#define BYTE1(x) (0xFF&(x>>8))

#define BYTE2(x) (0xFF&(x>>16))

#define BYTE3(x) (0xFF&(x>>24))

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif

