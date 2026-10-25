#ifdef __cplusplus
extern "C" {
#endif

#include "nitro/reg.h"
#include "nitro/types.h"

#define GX_BLEND_PLANEMASK_NONE 0
#define GX_BLEND_PLANEMASK_BG0 0x1
#define GX_BLEND_PLANEMASK_BG1 0x2
#define GX_BLEND_PLANEMASK_BG2 0x4
#define GX_BLEND_PLANEMASK_BG3 0x8
#define GX_BLEND_PLANEMASK_OBJ 0x10
#define GX_BLEND_PLANEMASK_BD 0x20

void G2x_SetBlendBrightness_(REGBlend *blend, s32 cnt, s32 brightness);
void G2x_ChangeBlendBrightness_(REGBlend *blend, s32 brightness);
void _G2_SetBlend(u32 *reg, u32 srcPlane, u32 dstPlane, u32 srcAlpha, u32 dstAlpha);

inline void G2_BlendNone() {
    REG_BLDCNT = 0;
}

inline void G2S_BlendNone() {
    REG_BLDCNT_SUB = 0;
}

inline void G2_SetBlendAlpha(u32 srcPlane, u32 dstPlane, u32 srcAlpha, u32 dstAlpha) {
    _G2_SetBlend((u32 *) &REG_BLDCNT, srcPlane, dstPlane, srcAlpha, dstAlpha);
}

inline void G2S_SetBlendAlpha(u32 srcPlane, u32 dstPlane, u32 srcAlpha, u32 dstAlpha) {
    _G2_SetBlend((u32 *) &REG_BLDCNT_SUB, srcPlane, dstPlane, srcAlpha, dstAlpha);
}

inline void G2_ChangeBlendAlpha(u32 param1, u32 param2) {
    REG_BLDALPHA = param1 | (param2 << 8);
}

inline void G2S_ChangeBlendAlpha(u32 param1, u32 param2) {
    REG_BLDALPHA_SUB = param1 | (param2 << 8);
}

#ifdef __cplusplus
}
#endif
