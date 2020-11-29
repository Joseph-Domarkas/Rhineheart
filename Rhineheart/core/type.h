#ifndef __TYPES_H__
#define __TYPES_H__

#define INT_MAX 0xFFFFFFFF

#ifndef __ASSEMBLER__

#define TRUE 1
#define FALSE 0
#define PRIVATE static
#define PACKED __attribute__ ((packed))
#define SQUELCH_UNUSED __attribute__((unused))
#define ALIGNED(x) __attribute__((aligned (x)))

typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;

typedef signed char sint8, s8;
typedef signed short int sint16, s16;
typedef signed long int sint32, s32;
typedef signed long long int sint64, s64;

#ifndef _SIZE_T
typedef int size_t;
#define _SIZE_T 1
#endif

typedef signed char bool;

typedef unsigned long uint;
typedef signed long sint;

typedef uint8 uint8_t, u8;
typedef uint16 uint16_t, u16, __le16;
typedef uint32 uint32_t, u32, __le32, __be32, dma_addr_t, frame_t, framenum_t, phys_addr_t;
typedef uint64 uint64_t, u64, __le64;

typedef void *addr_t;

#endif // [#ifndef __ASSEMBLER__]

#endif
