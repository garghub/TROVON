static inline bool is_alpha_format(unsigned int pixel_format)
{
switch (pixel_format) {
case DRM_FORMAT_ARGB8888:
case DRM_FORMAT_ARGB1555:
case DRM_FORMAT_ARGB4444:
return true;
default:
return false;
}
}
static inline u32 vp_reg_read(struct mixer_resources *res, u32 reg_id)
{
return readl(res->vp_regs + reg_id);
}
static inline void vp_reg_write(struct mixer_resources *res, u32 reg_id,
u32 val)
{
writel(val, res->vp_regs + reg_id);
}
static inline void vp_reg_writemask(struct mixer_resources *res, u32 reg_id,
u32 val, u32 mask)
{
u32 old = vp_reg_read(res, reg_id);
val = (val & mask) | (old & ~mask);
writel(val, res->vp_regs + reg_id);
}
static inline u32 mixer_reg_read(struct mixer_resources *res, u32 reg_id)
{
return readl(res->mixer_regs + reg_id);
}
static inline void mixer_reg_write(struct mixer_resources *res, u32 reg_id,
u32 val)
{
writel(val, res->mixer_regs + reg_id);
}
static inline void mixer_reg_writemask(struct mixer_resources *res,
u32 reg_id, u32 val, u32 mask)
{
u32 old = mixer_reg_read(res, reg_id);
val = (val & mask) | (old & ~mask);
writel(val, res->mixer_regs + reg_id);
}
static void mixer_regs_dump(struct mixer_context *ctx)
{
#define DUMPREG(reg_id) \
do { \
DRM_DEBUG_KMS(#reg_id " = %08x\n", \
(u32)readl(ctx->mixer_res.mixer_regs + reg_id)); \
} while (0)
DUMPREG(MXR_STATUS);
DUMPREG(MXR_CFG);
DUMPREG(MXR_INT_EN);
DUMPREG(MXR_INT_STATUS);
DUMPREG(MXR_LAYER_CFG);
DUMPREG(MXR_VIDEO_CFG);
DUMPREG(MXR_GRAPHIC0_CFG);
DUMPREG(MXR_GRAPHIC0_BASE);
DUMPREG(MXR_GRAPHIC0_SPAN);
DUMPREG(MXR_GRAPHIC0_WH);
DUMPREG(MXR_GRAPHIC0_SXY);
DUMPREG(MXR_GRAPHIC0_DXY);
DUMPREG(MXR_GRAPHIC1_CFG);
DUMPREG(MXR_GRAPHIC1_BASE);
DUMPREG(MXR_GRAPHIC1_SPAN);
DUMPREG(MXR_GRAPHIC1_WH);
DUMPREG(MXR_GRAPHIC1_SXY);
DUMPREG(MXR_GRAPHIC1_DXY);
#undef DUMPREG
}
static void vp_regs_dump(struct mixer_context *ctx)
{
#define DUMPREG(reg_id) \
do { \
DRM_DEBUG_KMS(#reg_id " = %08x\n", \
(u32) readl(ctx->mixer_res.vp_regs + reg_id)); \
} while (0)
DUMPREG(VP_ENABLE);
DUMPREG(VP_SRESET);
DUMPREG(VP_SHADOW_UPDATE);
DUMPREG(VP_FIELD_ID);
DUMPREG(VP_MODE);
DUMPREG(VP_IMG_SIZE_Y);
DUMPREG(VP_IMG_SIZE_C);
DUMPREG(VP_PER_RATE_CTRL);
DUMPREG(VP_TOP_Y_PTR);
DUMPREG(VP_BOT_Y_PTR);
DUMPREG(VP_TOP_C_PTR);
DUMPREG(VP_BOT_C_PTR);
DUMPREG(VP_ENDIAN_MODE);
DUMPREG(VP_SRC_H_POSITION);
DUMPREG(VP_SRC_V_POSITION);
DUMPREG(VP_SRC_WIDTH);
DUMPREG(VP_SRC_HEIGHT);
DUMPREG(VP_DST_H_POSITION);
DUMPREG(VP_DST_V_POSITION);
DUMPREG(VP_DST_WIDTH);
DUMPREG(VP_DST_HEIGHT);
DUMPREG(VP_H_RATIO);
DUMPREG(VP_V_RATIO);
#undef DUMPREG
}
static inline void vp_filter_set(struct mixer_resources *res,
int reg_id, const u8 *data, unsigned int size)
{
BUG_ON(size & 3);
for (; size; size -= 4, reg_id += 4, data += 4) {
u32 val = (data[0] << 24) | (data[1] << 16) |
(data[2] << 8) | data[3];
vp_reg_write(res, reg_id, val);
}
}
static void vp_default_filter(struct mixer_resources *res)
{
vp_filter_set(res, VP_POLY8_Y0_LL,
filter_y_horiz_tap8, sizeof(filter_y_horiz_tap8));
vp_filter_set(res, VP_POLY4_Y0_LL,
filter_y_vert_tap4, sizeof(filter_y_vert_tap4));
vp_filter_set(res, VP_POLY4_C0_LL,
filter_cr_horiz_tap4, sizeof(filter_cr_horiz_tap4));
}
static void mixer_cfg_gfx_blend(struct mixer_context *ctx, unsigned int win,
bool alpha)
{
struct mixer_resources *res = &ctx->mixer_res;
u32 val;
val = MXR_GRP_CFG_COLOR_KEY_DISABLE;
if (alpha) {
val |= MXR_GRP_CFG_BLEND_PRE_MUL;
val |= MXR_GRP_CFG_PIXEL_BLEND_EN;
}
mixer_reg_writemask(res, MXR_GRAPHIC_CFG(win),
val, MXR_GRP_CFG_MISC_MASK);
}
static void mixer_cfg_vp_blend(struct mixer_context *ctx)
{
struct mixer_resources *res = &ctx->mixer_res;
u32 val;
val = 0;
mixer_reg_write(res, MXR_VIDEO_CFG, val);
}
static void mixer_vsync_set_update(struct mixer_context *ctx, bool enable)
{
struct mixer_resources *res = &ctx->mixer_res;
mixer_reg_writemask(res, MXR_STATUS, enable ?
MXR_STATUS_SYNC_ENABLE : 0, MXR_STATUS_SYNC_ENABLE);
if (ctx->vp_enabled)
vp_reg_write(res, VP_SHADOW_UPDATE, enable ?
VP_SHADOW_UPDATE_ENABLE : 0);
}
static void mixer_cfg_scan(struct mixer_context *ctx, unsigned int height)
{
struct mixer_resources *res = &ctx->mixer_res;
u32 val;
val = (ctx->interlace ? MXR_CFG_SCAN_INTERLACE :
MXR_CFG_SCAN_PROGRESSIVE);
if (ctx->mxr_ver != MXR_VER_128_0_0_184) {
if (height <= 480)
val |= MXR_CFG_SCAN_NTSC | MXR_CFG_SCAN_SD;
else if (height <= 576)
val |= MXR_CFG_SCAN_PAL | MXR_CFG_SCAN_SD;
else if (height <= 720)
val |= MXR_CFG_SCAN_HD_720 | MXR_CFG_SCAN_HD;
else if (height <= 1080)
val |= MXR_CFG_SCAN_HD_1080 | MXR_CFG_SCAN_HD;
else
val |= MXR_CFG_SCAN_HD_720 | MXR_CFG_SCAN_HD;
}
mixer_reg_writemask(res, MXR_CFG, val, MXR_CFG_SCAN_MASK);
}
static void mixer_cfg_rgb_fmt(struct mixer_context *ctx, unsigned int height)
{
struct mixer_resources *res = &ctx->mixer_res;
u32 val;
if (height == 480) {
val = MXR_CFG_RGB601_0_255;
} else if (height == 576) {
val = MXR_CFG_RGB601_0_255;
} else if (height == 720) {
val = MXR_CFG_RGB709_16_235;
mixer_reg_write(res, MXR_CM_COEFF_Y,
(1 << 30) | (94 << 20) | (314 << 10) |
(32 << 0));
mixer_reg_write(res, MXR_CM_COEFF_CB,
(972 << 20) | (851 << 10) | (225 << 0));
mixer_reg_write(res, MXR_CM_COEFF_CR,
(225 << 20) | (820 << 10) | (1004 << 0));
} else if (height == 1080) {
val = MXR_CFG_RGB709_16_235;
mixer_reg_write(res, MXR_CM_COEFF_Y,
(1 << 30) | (94 << 20) | (314 << 10) |
(32 << 0));
mixer_reg_write(res, MXR_CM_COEFF_CB,
(972 << 20) | (851 << 10) | (225 << 0));
mixer_reg_write(res, MXR_CM_COEFF_CR,
(225 << 20) | (820 << 10) | (1004 << 0));
} else {
val = MXR_CFG_RGB709_16_235;
mixer_reg_write(res, MXR_CM_COEFF_Y,
(1 << 30) | (94 << 20) | (314 << 10) |
(32 << 0));
mixer_reg_write(res, MXR_CM_COEFF_CB,
(972 << 20) | (851 << 10) | (225 << 0));
mixer_reg_write(res, MXR_CM_COEFF_CR,
(225 << 20) | (820 << 10) | (1004 << 0));
}
mixer_reg_writemask(res, MXR_CFG, val, MXR_CFG_RGB_FMT_MASK);
}
static void mixer_cfg_layer(struct mixer_context *ctx, unsigned int win,
unsigned int priority, bool enable)
{
struct mixer_resources *res = &ctx->mixer_res;
u32 val = enable ? ~0 : 0;
switch (win) {
case 0:
mixer_reg_writemask(res, MXR_CFG, val, MXR_CFG_GRP0_ENABLE);
mixer_reg_writemask(res, MXR_LAYER_CFG,
MXR_LAYER_CFG_GRP0_VAL(priority),
MXR_LAYER_CFG_GRP0_MASK);
break;
case 1:
mixer_reg_writemask(res, MXR_CFG, val, MXR_CFG_GRP1_ENABLE);
mixer_reg_writemask(res, MXR_LAYER_CFG,
MXR_LAYER_CFG_GRP1_VAL(priority),
MXR_LAYER_CFG_GRP1_MASK);
break;
case VP_DEFAULT_WIN:
if (ctx->vp_enabled) {
vp_reg_writemask(res, VP_ENABLE, val, VP_ENABLE_ON);
mixer_reg_writemask(res, MXR_CFG, val,
MXR_CFG_VP_ENABLE);
mixer_reg_writemask(res, MXR_LAYER_CFG,
MXR_LAYER_CFG_VP_VAL(priority),
MXR_LAYER_CFG_VP_MASK);
}
break;
}
}
static void mixer_run(struct mixer_context *ctx)
{
struct mixer_resources *res = &ctx->mixer_res;
mixer_reg_writemask(res, MXR_STATUS, ~0, MXR_STATUS_REG_RUN);
}
static void mixer_stop(struct mixer_context *ctx)
{
struct mixer_resources *res = &ctx->mixer_res;
int timeout = 20;
mixer_reg_writemask(res, MXR_STATUS, 0, MXR_STATUS_REG_RUN);
while (!(mixer_reg_read(res, MXR_STATUS) & MXR_STATUS_REG_IDLE) &&
--timeout)
usleep_range(10000, 12000);
}
static void vp_video_buffer(struct mixer_context *ctx,
struct exynos_drm_plane *plane)
{
struct exynos_drm_plane_state *state =
to_exynos_plane_state(plane->base.state);
struct drm_display_mode *mode = &state->base.crtc->state->adjusted_mode;
struct mixer_resources *res = &ctx->mixer_res;
struct drm_framebuffer *fb = state->base.fb;
unsigned int priority = state->base.normalized_zpos + 1;
unsigned long flags;
dma_addr_t luma_addr[2], chroma_addr[2];
bool tiled_mode = false;
bool crcb_mode = false;
u32 val;
switch (fb->pixel_format) {
case DRM_FORMAT_NV12:
crcb_mode = false;
break;
case DRM_FORMAT_NV21:
crcb_mode = true;
break;
default:
DRM_ERROR("pixel format for vp is wrong [%d].\n",
fb->pixel_format);
return;
}
luma_addr[0] = exynos_drm_fb_dma_addr(fb, 0);
chroma_addr[0] = exynos_drm_fb_dma_addr(fb, 1);
if (mode->flags & DRM_MODE_FLAG_INTERLACE) {
ctx->interlace = true;
if (tiled_mode) {
luma_addr[1] = luma_addr[0] + 0x40;
chroma_addr[1] = chroma_addr[0] + 0x40;
} else {
luma_addr[1] = luma_addr[0] + fb->pitches[0];
chroma_addr[1] = chroma_addr[0] + fb->pitches[0];
}
} else {
ctx->interlace = false;
luma_addr[1] = 0;
chroma_addr[1] = 0;
}
spin_lock_irqsave(&res->reg_slock, flags);
val = (ctx->interlace ? ~0 : 0);
vp_reg_writemask(res, VP_MODE, val, VP_MODE_LINE_SKIP);
val = (crcb_mode ? VP_MODE_NV21 : VP_MODE_NV12);
val |= (tiled_mode ? VP_MODE_MEM_TILED : VP_MODE_MEM_LINEAR);
vp_reg_writemask(res, VP_MODE, val, VP_MODE_FMT_MASK);
vp_reg_write(res, VP_IMG_SIZE_Y, VP_IMG_HSIZE(fb->pitches[0]) |
VP_IMG_VSIZE(fb->height));
vp_reg_write(res, VP_IMG_SIZE_C, VP_IMG_HSIZE(fb->pitches[0]) |
VP_IMG_VSIZE(fb->height / 2));
vp_reg_write(res, VP_SRC_WIDTH, state->src.w);
vp_reg_write(res, VP_SRC_HEIGHT, state->src.h);
vp_reg_write(res, VP_SRC_H_POSITION,
VP_SRC_H_POSITION_VAL(state->src.x));
vp_reg_write(res, VP_SRC_V_POSITION, state->src.y);
vp_reg_write(res, VP_DST_WIDTH, state->crtc.w);
vp_reg_write(res, VP_DST_H_POSITION, state->crtc.x);
if (ctx->interlace) {
vp_reg_write(res, VP_DST_HEIGHT, state->crtc.h / 2);
vp_reg_write(res, VP_DST_V_POSITION, state->crtc.y / 2);
} else {
vp_reg_write(res, VP_DST_HEIGHT, state->crtc.h);
vp_reg_write(res, VP_DST_V_POSITION, state->crtc.y);
}
vp_reg_write(res, VP_H_RATIO, state->h_ratio);
vp_reg_write(res, VP_V_RATIO, state->v_ratio);
vp_reg_write(res, VP_ENDIAN_MODE, VP_ENDIAN_MODE_LITTLE);
vp_reg_write(res, VP_TOP_Y_PTR, luma_addr[0]);
vp_reg_write(res, VP_BOT_Y_PTR, luma_addr[1]);
vp_reg_write(res, VP_TOP_C_PTR, chroma_addr[0]);
vp_reg_write(res, VP_BOT_C_PTR, chroma_addr[1]);
mixer_cfg_scan(ctx, mode->vdisplay);
mixer_cfg_rgb_fmt(ctx, mode->vdisplay);
mixer_cfg_layer(ctx, plane->index, priority, true);
mixer_cfg_vp_blend(ctx);
mixer_run(ctx);
spin_unlock_irqrestore(&res->reg_slock, flags);
mixer_regs_dump(ctx);
vp_regs_dump(ctx);
}
static void mixer_layer_update(struct mixer_context *ctx)
{
struct mixer_resources *res = &ctx->mixer_res;
mixer_reg_writemask(res, MXR_CFG, ~0, MXR_CFG_LAYER_UPDATE);
}
static void mixer_graph_buffer(struct mixer_context *ctx,
struct exynos_drm_plane *plane)
{
struct exynos_drm_plane_state *state =
to_exynos_plane_state(plane->base.state);
struct drm_display_mode *mode = &state->base.crtc->state->adjusted_mode;
struct mixer_resources *res = &ctx->mixer_res;
struct drm_framebuffer *fb = state->base.fb;
unsigned int priority = state->base.normalized_zpos + 1;
unsigned long flags;
unsigned int win = plane->index;
unsigned int x_ratio = 0, y_ratio = 0;
unsigned int src_x_offset, src_y_offset, dst_x_offset, dst_y_offset;
dma_addr_t dma_addr;
unsigned int fmt;
u32 val;
switch (fb->pixel_format) {
case DRM_FORMAT_XRGB4444:
case DRM_FORMAT_ARGB4444:
fmt = MXR_FORMAT_ARGB4444;
break;
case DRM_FORMAT_XRGB1555:
case DRM_FORMAT_ARGB1555:
fmt = MXR_FORMAT_ARGB1555;
break;
case DRM_FORMAT_RGB565:
fmt = MXR_FORMAT_RGB565;
break;
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_ARGB8888:
fmt = MXR_FORMAT_ARGB8888;
break;
default:
DRM_DEBUG_KMS("pixelformat unsupported by mixer\n");
return;
}
x_ratio = state->h_ratio == (1 << 15);
y_ratio = state->v_ratio == (1 << 15);
dst_x_offset = state->crtc.x;
dst_y_offset = state->crtc.y;
dma_addr = exynos_drm_fb_dma_addr(fb, 0)
+ (state->src.x * fb->bits_per_pixel >> 3)
+ (state->src.y * fb->pitches[0]);
src_x_offset = 0;
src_y_offset = 0;
if (mode->flags & DRM_MODE_FLAG_INTERLACE)
ctx->interlace = true;
else
ctx->interlace = false;
spin_lock_irqsave(&res->reg_slock, flags);
mixer_reg_writemask(res, MXR_GRAPHIC_CFG(win),
MXR_GRP_CFG_FORMAT_VAL(fmt), MXR_GRP_CFG_FORMAT_MASK);
mixer_reg_write(res, MXR_GRAPHIC_SPAN(win),
fb->pitches[0] / (fb->bits_per_pixel >> 3));
if (ctx->mxr_ver == MXR_VER_128_0_0_184 &&
win == DEFAULT_WIN) {
val = MXR_MXR_RES_HEIGHT(mode->vdisplay);
val |= MXR_MXR_RES_WIDTH(mode->hdisplay);
mixer_reg_write(res, MXR_RESOLUTION, val);
}
val = MXR_GRP_WH_WIDTH(state->src.w);
val |= MXR_GRP_WH_HEIGHT(state->src.h);
val |= MXR_GRP_WH_H_SCALE(x_ratio);
val |= MXR_GRP_WH_V_SCALE(y_ratio);
mixer_reg_write(res, MXR_GRAPHIC_WH(win), val);
val = MXR_GRP_SXY_SX(src_x_offset);
val |= MXR_GRP_SXY_SY(src_y_offset);
mixer_reg_write(res, MXR_GRAPHIC_SXY(win), val);
val = MXR_GRP_DXY_DX(dst_x_offset);
val |= MXR_GRP_DXY_DY(dst_y_offset);
mixer_reg_write(res, MXR_GRAPHIC_DXY(win), val);
mixer_reg_write(res, MXR_GRAPHIC_BASE(win), dma_addr);
mixer_cfg_scan(ctx, mode->vdisplay);
mixer_cfg_rgb_fmt(ctx, mode->vdisplay);
mixer_cfg_layer(ctx, win, priority, true);
mixer_cfg_gfx_blend(ctx, win, is_alpha_format(fb->pixel_format));
if (ctx->mxr_ver == MXR_VER_16_0_33_0 ||
ctx->mxr_ver == MXR_VER_128_0_0_184)
mixer_layer_update(ctx);
mixer_run(ctx);
spin_unlock_irqrestore(&res->reg_slock, flags);
mixer_regs_dump(ctx);
}
static void vp_win_reset(struct mixer_context *ctx)
{
struct mixer_resources *res = &ctx->mixer_res;
int tries = 100;
vp_reg_write(res, VP_SRESET, VP_SRESET_PROCESSING);
for (tries = 100; tries; --tries) {
if (~vp_reg_read(res, VP_SRESET) & VP_SRESET_PROCESSING)
break;
mdelay(10);
}
WARN(tries == 0, "failed to reset Video Processor\n");
}
static void mixer_win_reset(struct mixer_context *ctx)
{
struct mixer_resources *res = &ctx->mixer_res;
unsigned long flags;
spin_lock_irqsave(&res->reg_slock, flags);
mixer_reg_writemask(res, MXR_CFG, MXR_CFG_DST_HDMI, MXR_CFG_DST_MASK);
mixer_reg_writemask(res, MXR_CFG, MXR_CFG_OUT_RGB888, MXR_CFG_OUT_MASK);
mixer_reg_writemask(res, MXR_STATUS, MXR_STATUS_16_BURST,
MXR_STATUS_BURST_MASK);
mixer_reg_write(res, MXR_LAYER_CFG, 0);
mixer_reg_write(res, MXR_BG_COLOR0, 0x008080);
mixer_reg_write(res, MXR_BG_COLOR1, 0x008080);
mixer_reg_write(res, MXR_BG_COLOR2, 0x008080);
if (ctx->vp_enabled) {
vp_win_reset(ctx);
vp_default_filter(res);
}
mixer_reg_writemask(res, MXR_CFG, 0, MXR_CFG_GRP0_ENABLE);
mixer_reg_writemask(res, MXR_CFG, 0, MXR_CFG_GRP1_ENABLE);
if (ctx->vp_enabled)
mixer_reg_writemask(res, MXR_CFG, 0, MXR_CFG_VP_ENABLE);
spin_unlock_irqrestore(&res->reg_slock, flags);
}
static irqreturn_t mixer_irq_handler(int irq, void *arg)
{
struct mixer_context *ctx = arg;
struct mixer_resources *res = &ctx->mixer_res;
u32 val, base, shadow;
int win;
spin_lock(&res->reg_slock);
val = mixer_reg_read(res, MXR_INT_STATUS);
if (val & MXR_INT_STATUS_VSYNC) {
val |= MXR_INT_CLEAR_VSYNC;
val &= ~MXR_INT_STATUS_VSYNC;
if (ctx->interlace) {
base = mixer_reg_read(res, MXR_GRAPHIC_BASE(0));
shadow = mixer_reg_read(res, MXR_GRAPHIC_BASE_S(0));
if (base != shadow)
goto out;
base = mixer_reg_read(res, MXR_GRAPHIC_BASE(1));
shadow = mixer_reg_read(res, MXR_GRAPHIC_BASE_S(1));
if (base != shadow)
goto out;
}
drm_crtc_handle_vblank(&ctx->crtc->base);
for (win = 0 ; win < MIXER_WIN_NR ; win++) {
struct exynos_drm_plane *plane = &ctx->planes[win];
if (!plane->pending_fb)
continue;
exynos_drm_crtc_finish_update(ctx->crtc, plane);
}
}
out:
mixer_reg_write(res, MXR_INT_STATUS, val);
spin_unlock(&res->reg_slock);
return IRQ_HANDLED;
}
static int mixer_resources_init(struct mixer_context *mixer_ctx)
{
struct device *dev = &mixer_ctx->pdev->dev;
struct mixer_resources *mixer_res = &mixer_ctx->mixer_res;
struct resource *res;
int ret;
spin_lock_init(&mixer_res->reg_slock);
mixer_res->mixer = devm_clk_get(dev, "mixer");
if (IS_ERR(mixer_res->mixer)) {
dev_err(dev, "failed to get clock 'mixer'\n");
return -ENODEV;
}
mixer_res->hdmi = devm_clk_get(dev, "hdmi");
if (IS_ERR(mixer_res->hdmi)) {
dev_err(dev, "failed to get clock 'hdmi'\n");
return PTR_ERR(mixer_res->hdmi);
}
mixer_res->sclk_hdmi = devm_clk_get(dev, "sclk_hdmi");
if (IS_ERR(mixer_res->sclk_hdmi)) {
dev_err(dev, "failed to get clock 'sclk_hdmi'\n");
return -ENODEV;
}
res = platform_get_resource(mixer_ctx->pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(dev, "get memory resource failed.\n");
return -ENXIO;
}
mixer_res->mixer_regs = devm_ioremap(dev, res->start,
resource_size(res));
if (mixer_res->mixer_regs == NULL) {
dev_err(dev, "register mapping failed.\n");
return -ENXIO;
}
res = platform_get_resource(mixer_ctx->pdev, IORESOURCE_IRQ, 0);
if (res == NULL) {
dev_err(dev, "get interrupt resource failed.\n");
return -ENXIO;
}
ret = devm_request_irq(dev, res->start, mixer_irq_handler,
0, "drm_mixer", mixer_ctx);
if (ret) {
dev_err(dev, "request interrupt failed.\n");
return ret;
}
mixer_res->irq = res->start;
return 0;
}
static int vp_resources_init(struct mixer_context *mixer_ctx)
{
struct device *dev = &mixer_ctx->pdev->dev;
struct mixer_resources *mixer_res = &mixer_ctx->mixer_res;
struct resource *res;
mixer_res->vp = devm_clk_get(dev, "vp");
if (IS_ERR(mixer_res->vp)) {
dev_err(dev, "failed to get clock 'vp'\n");
return -ENODEV;
}
if (mixer_ctx->has_sclk) {
mixer_res->sclk_mixer = devm_clk_get(dev, "sclk_mixer");
if (IS_ERR(mixer_res->sclk_mixer)) {
dev_err(dev, "failed to get clock 'sclk_mixer'\n");
return -ENODEV;
}
mixer_res->mout_mixer = devm_clk_get(dev, "mout_mixer");
if (IS_ERR(mixer_res->mout_mixer)) {
dev_err(dev, "failed to get clock 'mout_mixer'\n");
return -ENODEV;
}
if (mixer_res->sclk_hdmi && mixer_res->mout_mixer)
clk_set_parent(mixer_res->mout_mixer,
mixer_res->sclk_hdmi);
}
res = platform_get_resource(mixer_ctx->pdev, IORESOURCE_MEM, 1);
if (res == NULL) {
dev_err(dev, "get memory resource failed.\n");
return -ENXIO;
}
mixer_res->vp_regs = devm_ioremap(dev, res->start,
resource_size(res));
if (mixer_res->vp_regs == NULL) {
dev_err(dev, "register mapping failed.\n");
return -ENXIO;
}
return 0;
}
static int mixer_initialize(struct mixer_context *mixer_ctx,
struct drm_device *drm_dev)
{
int ret;
struct exynos_drm_private *priv;
priv = drm_dev->dev_private;
mixer_ctx->drm_dev = drm_dev;
mixer_ctx->pipe = priv->pipe++;
ret = mixer_resources_init(mixer_ctx);
if (ret) {
DRM_ERROR("mixer_resources_init failed ret=%d\n", ret);
return ret;
}
if (mixer_ctx->vp_enabled) {
ret = vp_resources_init(mixer_ctx);
if (ret) {
DRM_ERROR("vp_resources_init failed ret=%d\n", ret);
return ret;
}
}
ret = drm_iommu_attach_device(drm_dev, mixer_ctx->dev);
if (ret)
priv->pipe--;
return ret;
}
static void mixer_ctx_remove(struct mixer_context *mixer_ctx)
{
drm_iommu_detach_device(mixer_ctx->drm_dev, mixer_ctx->dev);
}
static int mixer_enable_vblank(struct exynos_drm_crtc *crtc)
{
struct mixer_context *mixer_ctx = crtc->ctx;
struct mixer_resources *res = &mixer_ctx->mixer_res;
__set_bit(MXR_BIT_VSYNC, &mixer_ctx->flags);
if (!test_bit(MXR_BIT_POWERED, &mixer_ctx->flags))
return 0;
mixer_reg_writemask(res, MXR_INT_STATUS, ~0, MXR_INT_CLEAR_VSYNC);
mixer_reg_writemask(res, MXR_INT_EN, ~0, MXR_INT_EN_VSYNC);
return 0;
}
static void mixer_disable_vblank(struct exynos_drm_crtc *crtc)
{
struct mixer_context *mixer_ctx = crtc->ctx;
struct mixer_resources *res = &mixer_ctx->mixer_res;
__clear_bit(MXR_BIT_VSYNC, &mixer_ctx->flags);
if (!test_bit(MXR_BIT_POWERED, &mixer_ctx->flags))
return;
mixer_reg_writemask(res, MXR_INT_STATUS, ~0, MXR_INT_CLEAR_VSYNC);
mixer_reg_writemask(res, MXR_INT_EN, 0, MXR_INT_EN_VSYNC);
}
static void mixer_atomic_begin(struct exynos_drm_crtc *crtc)
{
struct mixer_context *mixer_ctx = crtc->ctx;
if (!test_bit(MXR_BIT_POWERED, &mixer_ctx->flags))
return;
mixer_vsync_set_update(mixer_ctx, false);
}
static void mixer_update_plane(struct exynos_drm_crtc *crtc,
struct exynos_drm_plane *plane)
{
struct mixer_context *mixer_ctx = crtc->ctx;
DRM_DEBUG_KMS("win: %d\n", plane->index);
if (!test_bit(MXR_BIT_POWERED, &mixer_ctx->flags))
return;
if (plane->index == VP_DEFAULT_WIN)
vp_video_buffer(mixer_ctx, plane);
else
mixer_graph_buffer(mixer_ctx, plane);
}
static void mixer_disable_plane(struct exynos_drm_crtc *crtc,
struct exynos_drm_plane *plane)
{
struct mixer_context *mixer_ctx = crtc->ctx;
struct mixer_resources *res = &mixer_ctx->mixer_res;
unsigned long flags;
DRM_DEBUG_KMS("win: %d\n", plane->index);
if (!test_bit(MXR_BIT_POWERED, &mixer_ctx->flags))
return;
spin_lock_irqsave(&res->reg_slock, flags);
mixer_cfg_layer(mixer_ctx, plane->index, 0, false);
spin_unlock_irqrestore(&res->reg_slock, flags);
}
static void mixer_atomic_flush(struct exynos_drm_crtc *crtc)
{
struct mixer_context *mixer_ctx = crtc->ctx;
if (!test_bit(MXR_BIT_POWERED, &mixer_ctx->flags))
return;
mixer_vsync_set_update(mixer_ctx, true);
}
static void mixer_enable(struct exynos_drm_crtc *crtc)
{
struct mixer_context *ctx = crtc->ctx;
struct mixer_resources *res = &ctx->mixer_res;
if (test_bit(MXR_BIT_POWERED, &ctx->flags))
return;
pm_runtime_get_sync(ctx->dev);
exynos_drm_pipe_clk_enable(crtc, true);
mixer_vsync_set_update(ctx, false);
mixer_reg_writemask(res, MXR_STATUS, ~0, MXR_STATUS_SOFT_RESET);
if (test_bit(MXR_BIT_VSYNC, &ctx->flags)) {
mixer_reg_writemask(res, MXR_INT_STATUS, ~0, MXR_INT_CLEAR_VSYNC);
mixer_reg_writemask(res, MXR_INT_EN, ~0, MXR_INT_EN_VSYNC);
}
mixer_win_reset(ctx);
mixer_vsync_set_update(ctx, true);
set_bit(MXR_BIT_POWERED, &ctx->flags);
}
static void mixer_disable(struct exynos_drm_crtc *crtc)
{
struct mixer_context *ctx = crtc->ctx;
int i;
if (!test_bit(MXR_BIT_POWERED, &ctx->flags))
return;
mixer_stop(ctx);
mixer_regs_dump(ctx);
for (i = 0; i < MIXER_WIN_NR; i++)
mixer_disable_plane(crtc, &ctx->planes[i]);
exynos_drm_pipe_clk_enable(crtc, false);
pm_runtime_put(ctx->dev);
clear_bit(MXR_BIT_POWERED, &ctx->flags);
}
static int mixer_atomic_check(struct exynos_drm_crtc *crtc,
struct drm_crtc_state *state)
{
struct drm_display_mode *mode = &state->adjusted_mode;
u32 w, h;
w = mode->hdisplay;
h = mode->vdisplay;
DRM_DEBUG_KMS("xres=%d, yres=%d, refresh=%d, intl=%d\n",
mode->hdisplay, mode->vdisplay, mode->vrefresh,
(mode->flags & DRM_MODE_FLAG_INTERLACE) ? 1 : 0);
if ((w >= 464 && w <= 720 && h >= 261 && h <= 576) ||
(w >= 1024 && w <= 1280 && h >= 576 && h <= 720) ||
(w >= 1664 && w <= 1920 && h >= 936 && h <= 1080))
return 0;
return -EINVAL;
}
static int mixer_bind(struct device *dev, struct device *manager, void *data)
{
struct mixer_context *ctx = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
struct exynos_drm_plane *exynos_plane;
unsigned int i;
int ret;
ret = mixer_initialize(ctx, drm_dev);
if (ret)
return ret;
for (i = 0; i < MIXER_WIN_NR; i++) {
if (i == VP_DEFAULT_WIN && !ctx->vp_enabled)
continue;
ret = exynos_plane_init(drm_dev, &ctx->planes[i], i,
1 << ctx->pipe, &plane_configs[i]);
if (ret)
return ret;
}
exynos_plane = &ctx->planes[DEFAULT_WIN];
ctx->crtc = exynos_drm_crtc_create(drm_dev, &exynos_plane->base,
ctx->pipe, EXYNOS_DISPLAY_TYPE_HDMI,
&mixer_crtc_ops, ctx);
if (IS_ERR(ctx->crtc)) {
mixer_ctx_remove(ctx);
ret = PTR_ERR(ctx->crtc);
goto free_ctx;
}
return 0;
free_ctx:
devm_kfree(dev, ctx);
return ret;
}
static void mixer_unbind(struct device *dev, struct device *master, void *data)
{
struct mixer_context *ctx = dev_get_drvdata(dev);
mixer_ctx_remove(ctx);
}
static int mixer_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct mixer_drv_data *drv;
struct mixer_context *ctx;
int ret;
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx) {
DRM_ERROR("failed to alloc mixer context.\n");
return -ENOMEM;
}
drv = of_device_get_match_data(dev);
ctx->pdev = pdev;
ctx->dev = dev;
ctx->vp_enabled = drv->is_vp_enabled;
ctx->has_sclk = drv->has_sclk;
ctx->mxr_ver = drv->version;
platform_set_drvdata(pdev, ctx);
ret = component_add(&pdev->dev, &mixer_component_ops);
if (!ret)
pm_runtime_enable(dev);
return ret;
}
static int mixer_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
component_del(&pdev->dev, &mixer_component_ops);
return 0;
}
static int __maybe_unused exynos_mixer_suspend(struct device *dev)
{
struct mixer_context *ctx = dev_get_drvdata(dev);
struct mixer_resources *res = &ctx->mixer_res;
clk_disable_unprepare(res->hdmi);
clk_disable_unprepare(res->mixer);
if (ctx->vp_enabled) {
clk_disable_unprepare(res->vp);
if (ctx->has_sclk)
clk_disable_unprepare(res->sclk_mixer);
}
return 0;
}
static int __maybe_unused exynos_mixer_resume(struct device *dev)
{
struct mixer_context *ctx = dev_get_drvdata(dev);
struct mixer_resources *res = &ctx->mixer_res;
int ret;
ret = clk_prepare_enable(res->mixer);
if (ret < 0) {
DRM_ERROR("Failed to prepare_enable the mixer clk [%d]\n", ret);
return ret;
}
ret = clk_prepare_enable(res->hdmi);
if (ret < 0) {
DRM_ERROR("Failed to prepare_enable the hdmi clk [%d]\n", ret);
return ret;
}
if (ctx->vp_enabled) {
ret = clk_prepare_enable(res->vp);
if (ret < 0) {
DRM_ERROR("Failed to prepare_enable the vp clk [%d]\n",
ret);
return ret;
}
if (ctx->has_sclk) {
ret = clk_prepare_enable(res->sclk_mixer);
if (ret < 0) {
DRM_ERROR("Failed to prepare_enable the " \
"sclk_mixer clk [%d]\n",
ret);
return ret;
}
}
}
return 0;
}
