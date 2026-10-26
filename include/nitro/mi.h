#ifndef _NITRO_MI_H
#define _NITRO_MI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "nitro/types.h"

#define MI_DMA_MAX_NUM 3

void MI_DmaFill32(u32 dma, void *ptr, u8 value, u32 size);
void MI_DmaCopy16(u32 dma, const void *src, void *dst, u32 size);
void MI_DmaCopy32(u32 dma, const void *src, void *dst, u32 size);
void MI_func_0002(u32 dma, void *src, void *dst, u32 size, u32, u32);
void MI_func_0003(u32 dma);
BOOL MI_IsDmaBusy(u32 dma);
void MI_WaitDma(u32 dma);

void MI_CpuFill8(void *ptr, u8 value, u32 size);
void MI_CpuCopy8(const void *src, void *dst, u32 size);
void MIi_CpuCopy16(const void *src, void *dst, u32 size);
void MIi_CpuCopy32(const void *src, void *dst, u32 size);
void MI_CpuFill16(u16 value, void *dst, u32 size);
void MIi_CpuCopyFast(const void *src, void *dst, u32 size);
void MIi_CpuClearFast(u32 value, void *ptr, u32 size);
void MIi_CpuClear16(u32 value, void *ptr, u32 size);
void MIi_CpuClear32(u32 value, void *ptr, u32 size);

void MI_Copy32B(const void *src, void *dst);

void MI_Swap(u32 *a, u32 *b);

void MIi_UncompressBackward(void *addr);

void MI_func_0008(s32 dmaChannel, void *param2, u32 param3, s32 param4);
void MI_func_0009(void);
s32 MI_func_0010(s32 dmaChannel, void *param2, u32 param3, u32 param4, u32 param5);

inline void MI_CpuClearFast(void *ptr, u32 size) {
    MIi_CpuClearFast(0, ptr, size);
}

inline void MI_CpuFillFast(void *ptr, u8 value, u32 size) {
    MIi_CpuClearFast(value, ptr, size);
}

inline void MI_CpuCopyFast(void *src, void *dst, u32 size) {
    MIi_CpuCopyFast(src, dst, size);
}

inline void MI_CpuFill32(u32 value, void *ptr, u32 size) {
    MIi_CpuClear32(value, ptr, size);
}

#ifdef __cplusplus
} // extern "C"
#endif

#endif
