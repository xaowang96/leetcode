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

/**@brife:定义数据大小*/
#define DATA_SIZE_8B (8)
#define DATA_SIZE_32B (32)
#define DATA_SIZE_64B (64)
#define DATA_SIZE_128B (128)
#define DATA_SIZE_256B (256)
#define DATA_SIZE_512B (512)
#define DATA_SIZE_1024B (1024)
#define DATA_SIZE_2048B (2048)

#define BYTE0(x) (0xFF&(x>>0))

#define BYTE1(x) (0xFF&(x>>8))

#define BYTE2(x) (0xFF&(x>>16))

#define BYTE3(x) (0xFF&(x>>24))

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif

