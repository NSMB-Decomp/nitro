#ifndef _NITRO_GX_H
#define _NITRO_GX_H

#ifdef __cplusplus
extern "C" {
#endif

#include "nitro/gx/g3.h"
#include "nitro/gx/gx_bank.h"
#include "nitro/gx/gx_bg.h"
#include "nitro/gx/gx_blend.h"
#include "nitro/gx/gx_fifo.h"
#include "nitro/gx/gx_init.h"
#include "nitro/gx/gx_load.h"
#include "nitro/gx/gx_obj.h"
#include "nitro/gx/gx_state.h"
#include "nitro/gx/gx_vram.h"
#include "nitro/reg.h"
#include "nitro/types.h"

#define GX_POWER_ALL 0x20e

#define GX_DISP_SELECT_MAIN_SUB 0x8000
#define GX_DISP_SELECT_SUB_MAIN 0
#define GX_DISPMODE_GRAPHICS 1
#define GX_DISPMODE_VRAM_C 0xa
#define GX_DISPMODE_VRAM_D 0xe

#define GX_PLANEMASK_NONE 0
#define GX_PLANEMASK_BG0 0x1
#define GX_PLANEMASK_BG1 0x2
#define GX_PLANEMASK_BG2 0x4
#define GX_PLANEMASK_BG3 0x8
#define GX_PLANEMASK_OBJ 0x10

#define GX_RGB(r, g, b) ((r) | ((g) << 0x5) | ((b) << 0xa))

inline void GXS_DispOff(void) {
    REG_DISPCNT_SUB &= ~0x10000;
}

inline void GXS_DispOn(void) {
    REG_DISPCNT_SUB |= 0x10000;
}

inline void GX_SetPower(u32 value) {
    REG_POWER_CNT = (REG_POWER_CNT & 0xFFFFFDF1) | (value);
}

inline void GX_SetDispSelect(u32 value) {
    REG_POWER_CNT = (REG_POWER_CNT & ~0x8000) | value;
}

inline u16 GX_GetVCount(void) {
    return REG_VCOUNT;
}

inline void GX_SetVisiblePlane(s32 plane) {
    REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | (plane << 8);
}

inline void GXS_SetVisiblePlane(s32 plane) {
    REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | (plane << 8);
}

inline void GX_SetVisibleWindows(s32 windows) {
    REG_DISPCNT = (REG_DISPCNT & ~0xE000) | (windows << 13);
}

inline void GXS_SetVisibleWindows(s32 windows) {
    REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0xE000) | (windows << 13);
}

#ifdef __cplusplus
} // extern "C"
#endif

#endif
