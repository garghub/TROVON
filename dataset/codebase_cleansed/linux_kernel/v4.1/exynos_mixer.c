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
bool enable)
{
struct mixer_resources *res = &ctx->mixer_res;
u32 val = enable ? ~0 : 0;
switch (win) {
case 0:
mixer_reg_writemask(res, MXR_CFG, val, MXR_CFG_GRP0_ENABLE);
break;
case 1:
mixer_reg_writemask(res, MXR_CFG, val, MXR_CFG_GRP1_ENABLE);
break;
case 2:
if (ctx->vp_enabled) {
vp_reg_writemask(res, VP_ENABLE, val, VP_ENABLE_ON);
mixer_reg_writemask(res, MXR_CFG, val,
MXR_CFG_VP_ENABLE);
mixer_reg_writemask(res, MXR_GRAPHIC_CFG(0), val,
MXR_GRP_CFG_BLEND_PRE_MUL |
MXR_GRP_CFG_PIXEL_BLEND_EN);
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
static void vp_video_buffer(struct mixer_context *ctx, unsigned int win)
{
struct mixer_resources *res = &ctx->mixer_res;
unsigned long flags;
struct exynos_drm_plane *plane;
dma_addr_t luma_addr[2], chroma_addr[2];
bool tiled_mode = false;
bool crcb_mode = false;
u32 val;
plane = &ctx->planes[win];
switch (plane->pixel_format) {
case DRM_FORMAT_NV12:
crcb_mode = false;
break;
case DRM_FORMAT_NV21:
crcb_mode = true;
break;
default:
DRM_ERROR("pixel format for vp is wrong [%d].\n",
plane->pixel_format);
return;
}
luma_addr[0] = plane->dma_addr[0];
chroma_addr[0] = plane->dma_addr[1];
if (plane->scan_flag & DRM_MODE_FLAG_INTERLACE) {
ctx->interlace = true;
if (tiled_mode) {
luma_addr[1] = luma_addr[0] + 0x40;
chroma_addr[1] = chroma_addr[0] + 0x40;
} else {
luma_addr[1] = luma_addr[0] + plane->pitch;
chroma_addr[1] = chroma_addr[0] + plane->pitch;
}
} else {
ctx->interlace = false;
luma_addr[1] = 0;
chroma_addr[1] = 0;
}
spin_lock_irqsave(&res->reg_slock, flags);
mixer_vsync_set_update(ctx, false);
val = (ctx->interlace ? ~0 : 0);
vp_reg_writemask(res, VP_MODE, val, VP_MODE_LINE_SKIP);
val = (crcb_mode ? VP_MODE_NV21 : VP_MODE_NV12);
val |= (tiled_mode ? VP_MODE_MEM_TILED : VP_MODE_MEM_LINEAR);
vp_reg_writemask(res, VP_MODE, val, VP_MODE_FMT_MASK);
vp_reg_write(res, VP_IMG_SIZE_Y, VP_IMG_HSIZE(plane->pitch) |
VP_IMG_VSIZE(plane->fb_height));
vp_reg_write(res, VP_IMG_SIZE_C, VP_IMG_HSIZE(plane->pitch) |
VP_IMG_VSIZE(plane->fb_height / 2));
vp_reg_write(res, VP_SRC_WIDTH, plane->src_width);
vp_reg_write(res, VP_SRC_HEIGHT, plane->src_height);
vp_reg_write(res, VP_SRC_H_POSITION,
VP_SRC_H_POSITION_VAL(plane->src_x));
vp_reg_write(res, VP_SRC_V_POSITION, plane->src_y);
vp_reg_write(res, VP_DST_WIDTH, plane->crtc_width);
vp_reg_write(res, VP_DST_H_POSITION, plane->crtc_x);
if (ctx->interlace) {
vp_reg_write(res, VP_DST_HEIGHT, plane->crtc_height / 2);
vp_reg_write(res, VP_DST_V_POSITION, plane->crtc_y / 2);
} else {
vp_reg_write(res, VP_DST_HEIGHT, plane->crtc_height);
vp_reg_write(res, VP_DST_V_POSITION, plane->crtc_y);
}
vp_reg_write(res, VP_H_RATIO, plane->h_ratio);
vp_reg_write(res, VP_V_RATIO, plane->v_ratio);
vp_reg_write(res, VP_ENDIAN_MODE, VP_ENDIAN_MODE_LITTLE);
vp_reg_write(res, VP_TOP_Y_PTR, luma_addr[0]);
vp_reg_write(res, VP_BOT_Y_PTR, luma_addr[1]);
vp_reg_write(res, VP_TOP_C_PTR, chroma_addr[0]);
vp_reg_write(res, VP_BOT_C_PTR, chroma_addr[1]);
mixer_cfg_scan(ctx, plane->mode_height);
mixer_cfg_rgb_fmt(ctx, plane->mode_height);
mixer_cfg_layer(ctx, win, true);
mixer_run(ctx);
mixer_vsync_set_update(ctx, true);
spin_unlock_irqrestore(&res->reg_slock, flags);
mixer_regs_dump(ctx);
vp_regs_dump(ctx);
}
static void mixer_layer_update(struct mixer_context *ctx)
{
struct mixer_resources *res = &ctx->mixer_res;
mixer_reg_writemask(res, MXR_CFG, ~0, MXR_CFG_LAYER_UPDATE);
}
static int mixer_setup_scale(const struct exynos_drm_plane *plane,
unsigned int *x_ratio, unsigned int *y_ratio)
{
if (plane->crtc_width != plane->src_width) {
if (plane->crtc_width == 2 * plane->src_width)
*x_ratio = 1;
else
goto fail;
}
if (plane->crtc_height != plane->src_height) {
if (plane->crtc_height == 2 * plane->src_height)
*y_ratio = 1;
else
goto fail;
}
return 0;
fail:
DRM_DEBUG_KMS("only 2x width/height scaling of plane supported\n");
return -ENOTSUPP;
}
static void mixer_graph_buffer(struct mixer_context *ctx, unsigned int win)
{
struct mixer_resources *res = &ctx->mixer_res;
unsigned long flags;
struct exynos_drm_plane *plane;
unsigned int x_ratio = 0, y_ratio = 0;
unsigned int src_x_offset, src_y_offset, dst_x_offset, dst_y_offset;
dma_addr_t dma_addr;
unsigned int fmt;
u32 val;
plane = &ctx->planes[win];
switch (plane->pixel_format) {
case DRM_FORMAT_XRGB4444:
fmt = MXR_FORMAT_ARGB4444;
break;
case DRM_FORMAT_XRGB1555:
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
if (mixer_setup_scale(plane, &x_ratio, &y_ratio))
return;
dst_x_offset = plane->crtc_x;
dst_y_offset = plane->crtc_y;
dma_addr = plane->dma_addr[0]
+ (plane->src_x * plane->bpp >> 3)
+ (plane->src_y * plane->pitch);
src_x_offset = 0;
src_y_offset = 0;
if (plane->scan_flag & DRM_MODE_FLAG_INTERLACE)
ctx->interlace = true;
else
ctx->interlace = false;
spin_lock_irqsave(&res->reg_slock, flags);
mixer_vsync_set_update(ctx, false);
mixer_reg_writemask(res, MXR_GRAPHIC_CFG(win),
MXR_GRP_CFG_FORMAT_VAL(fmt), MXR_GRP_CFG_FORMAT_MASK);
mixer_reg_write(res, MXR_GRAPHIC_SPAN(win),
plane->pitch / (plane->bpp >> 3));
if (ctx->mxr_ver == MXR_VER_128_0_0_184 &&
win == MIXER_DEFAULT_WIN) {
val = MXR_MXR_RES_HEIGHT(plane->mode_height);
val |= MXR_MXR_RES_WIDTH(plane->mode_width);
mixer_reg_write(res, MXR_RESOLUTION, val);
}
val = MXR_GRP_WH_WIDTH(plane->src_width);
val |= MXR_GRP_WH_HEIGHT(plane->src_height);
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
mixer_cfg_scan(ctx, plane->mode_height);
mixer_cfg_rgb_fmt(ctx, plane->mode_height);
mixer_cfg_layer(ctx, win, true);
if (ctx->mxr_ver == MXR_VER_16_0_33_0 ||
ctx->mxr_ver == MXR_VER_128_0_0_184)
mixer_layer_update(ctx);
mixer_run(ctx);
mixer_vsync_set_update(ctx, true);
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
usleep_range(10000, 12000);
}
WARN(tries == 0, "failed to reset Video Processor\n");
}
static void mixer_win_reset(struct mixer_context *ctx)
{
struct mixer_resources *res = &ctx->mixer_res;
unsigned long flags;
u32 val;
spin_lock_irqsave(&res->reg_slock, flags);
mixer_vsync_set_update(ctx, false);
mixer_reg_writemask(res, MXR_CFG, MXR_CFG_DST_HDMI, MXR_CFG_DST_MASK);
mixer_reg_writemask(res, MXR_CFG, MXR_CFG_OUT_RGB888, MXR_CFG_OUT_MASK);
mixer_reg_writemask(res, MXR_STATUS, MXR_STATUS_16_BURST,
MXR_STATUS_BURST_MASK);
val = MXR_LAYER_CFG_GRP1_VAL(3);
val |= MXR_LAYER_CFG_GRP0_VAL(2);
if (ctx->vp_enabled)
val |= MXR_LAYER_CFG_VP_VAL(1);
mixer_reg_write(res, MXR_LAYER_CFG, val);
mixer_reg_write(res, MXR_BG_COLOR0, 0x008080);
mixer_reg_write(res, MXR_BG_COLOR1, 0x008080);
mixer_reg_write(res, MXR_BG_COLOR2, 0x008080);
val = MXR_GRP_CFG_COLOR_KEY_DISABLE;
val |= MXR_GRP_CFG_WIN_BLEND_EN;
val |= MXR_GRP_CFG_ALPHA_VAL(0xff);
mixer_reg_write(res, MXR_GRAPHIC_CFG(0), val);
val |= MXR_GRP_CFG_BLEND_PRE_MUL;
val |= MXR_GRP_CFG_PIXEL_BLEND_EN;
mixer_reg_write(res, MXR_GRAPHIC_CFG(1), val);
val = MXR_GRP_CFG_ALPHA_VAL(0);
mixer_reg_write(res, MXR_VIDEO_CFG, val);
if (ctx->vp_enabled) {
vp_win_reset(ctx);
vp_default_filter(res);
}
mixer_reg_writemask(res, MXR_CFG, 0, MXR_CFG_GRP0_ENABLE);
mixer_reg_writemask(res, MXR_CFG, 0, MXR_CFG_GRP1_ENABLE);
if (ctx->vp_enabled)
mixer_reg_writemask(res, MXR_CFG, 0, MXR_CFG_VP_ENABLE);
mixer_vsync_set_update(ctx, true);
spin_unlock_irqrestore(&res->reg_slock, flags);
}
static irqreturn_t mixer_irq_handler(int irq, void *arg)
{
struct mixer_context *ctx = arg;
struct mixer_resources *res = &ctx->mixer_res;
u32 val, base, shadow;
spin_lock(&res->reg_slock);
val = mixer_reg_read(res, MXR_INT_STATUS);
if (val & MXR_INT_STATUS_VSYNC) {
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
drm_handle_vblank(ctx->drm_dev, ctx->pipe);
exynos_drm_crtc_finish_pageflip(ctx->drm_dev, ctx->pipe);
if (atomic_read(&ctx->wait_vsync_event)) {
atomic_set(&ctx->wait_vsync_event, 0);
wake_up(&ctx->wait_vsync_queue);
}
}
out:
if (~val & MXR_INT_EN_VSYNC) {
val &= ~MXR_INT_EN_VSYNC;
val |= MXR_INT_CLEAR_VSYNC;
}
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
if (!is_drm_iommu_supported(mixer_ctx->drm_dev))
return 0;
return drm_iommu_attach_device(mixer_ctx->drm_dev, mixer_ctx->dev);
}
static void mixer_ctx_remove(struct mixer_context *mixer_ctx)
{
if (is_drm_iommu_supported(mixer_ctx->drm_dev))
drm_iommu_detach_device(mixer_ctx->drm_dev, mixer_ctx->dev);
}
static int mixer_enable_vblank(struct exynos_drm_crtc *crtc)
{
struct mixer_context *mixer_ctx = crtc->ctx;
struct mixer_resources *res = &mixer_ctx->mixer_res;
if (!mixer_ctx->powered) {
mixer_ctx->int_en |= MXR_INT_EN_VSYNC;
return 0;
}
mixer_reg_writemask(res, MXR_INT_EN, MXR_INT_EN_VSYNC,
MXR_INT_EN_VSYNC);
return 0;
}
static void mixer_disable_vblank(struct exynos_drm_crtc *crtc)
{
struct mixer_context *mixer_ctx = crtc->ctx;
struct mixer_resources *res = &mixer_ctx->mixer_res;
mixer_reg_writemask(res, MXR_INT_EN, 0, MXR_INT_EN_VSYNC);
}
static void mixer_win_commit(struct exynos_drm_crtc *crtc, unsigned int win)
{
struct mixer_context *mixer_ctx = crtc->ctx;
DRM_DEBUG_KMS("win: %d\n", win);
mutex_lock(&mixer_ctx->mixer_mutex);
if (!mixer_ctx->powered) {
mutex_unlock(&mixer_ctx->mixer_mutex);
return;
}
mutex_unlock(&mixer_ctx->mixer_mutex);
if (win > 1 && mixer_ctx->vp_enabled)
vp_video_buffer(mixer_ctx, win);
else
mixer_graph_buffer(mixer_ctx, win);
mixer_ctx->planes[win].enabled = true;
}
static void mixer_win_disable(struct exynos_drm_crtc *crtc, unsigned int win)
{
struct mixer_context *mixer_ctx = crtc->ctx;
struct mixer_resources *res = &mixer_ctx->mixer_res;
unsigned long flags;
DRM_DEBUG_KMS("win: %d\n", win);
mutex_lock(&mixer_ctx->mixer_mutex);
if (!mixer_ctx->powered) {
mutex_unlock(&mixer_ctx->mixer_mutex);
mixer_ctx->planes[win].resume = false;
return;
}
mutex_unlock(&mixer_ctx->mixer_mutex);
spin_lock_irqsave(&res->reg_slock, flags);
mixer_vsync_set_update(mixer_ctx, false);
mixer_cfg_layer(mixer_ctx, win, false);
mixer_vsync_set_update(mixer_ctx, true);
spin_unlock_irqrestore(&res->reg_slock, flags);
mixer_ctx->planes[win].enabled = false;
}
static void mixer_wait_for_vblank(struct exynos_drm_crtc *crtc)
{
struct mixer_context *mixer_ctx = crtc->ctx;
int err;
mutex_lock(&mixer_ctx->mixer_mutex);
if (!mixer_ctx->powered) {
mutex_unlock(&mixer_ctx->mixer_mutex);
return;
}
mutex_unlock(&mixer_ctx->mixer_mutex);
err = drm_vblank_get(mixer_ctx->drm_dev, mixer_ctx->pipe);
if (err < 0) {
DRM_DEBUG_KMS("failed to acquire vblank counter\n");
return;
}
atomic_set(&mixer_ctx->wait_vsync_event, 1);
if (!wait_event_timeout(mixer_ctx->wait_vsync_queue,
!atomic_read(&mixer_ctx->wait_vsync_event),
HZ/20))
DRM_DEBUG_KMS("vblank wait timed out.\n");
drm_vblank_put(mixer_ctx->drm_dev, mixer_ctx->pipe);
}
static void mixer_window_suspend(struct mixer_context *ctx)
{
struct exynos_drm_plane *plane;
int i;
for (i = 0; i < MIXER_WIN_NR; i++) {
plane = &ctx->planes[i];
plane->resume = plane->enabled;
mixer_win_disable(ctx->crtc, i);
}
mixer_wait_for_vblank(ctx->crtc);
}
static void mixer_window_resume(struct mixer_context *ctx)
{
struct exynos_drm_plane *plane;
int i;
for (i = 0; i < MIXER_WIN_NR; i++) {
plane = &ctx->planes[i];
plane->enabled = plane->resume;
plane->resume = false;
if (plane->enabled)
mixer_win_commit(ctx->crtc, i);
}
}
static void mixer_poweron(struct mixer_context *ctx)
{
struct mixer_resources *res = &ctx->mixer_res;
mutex_lock(&ctx->mixer_mutex);
if (ctx->powered) {
mutex_unlock(&ctx->mixer_mutex);
return;
}
mutex_unlock(&ctx->mixer_mutex);
pm_runtime_get_sync(ctx->dev);
clk_prepare_enable(res->mixer);
clk_prepare_enable(res->hdmi);
if (ctx->vp_enabled) {
clk_prepare_enable(res->vp);
if (ctx->has_sclk)
clk_prepare_enable(res->sclk_mixer);
}
mutex_lock(&ctx->mixer_mutex);
ctx->powered = true;
mutex_unlock(&ctx->mixer_mutex);
mixer_reg_writemask(res, MXR_STATUS, ~0, MXR_STATUS_SOFT_RESET);
mixer_reg_write(res, MXR_INT_EN, ctx->int_en);
mixer_win_reset(ctx);
mixer_window_resume(ctx);
}
static void mixer_poweroff(struct mixer_context *ctx)
{
struct mixer_resources *res = &ctx->mixer_res;
mutex_lock(&ctx->mixer_mutex);
if (!ctx->powered) {
mutex_unlock(&ctx->mixer_mutex);
return;
}
mutex_unlock(&ctx->mixer_mutex);
mixer_stop(ctx);
mixer_regs_dump(ctx);
mixer_window_suspend(ctx);
ctx->int_en = mixer_reg_read(res, MXR_INT_EN);
mutex_lock(&ctx->mixer_mutex);
ctx->powered = false;
mutex_unlock(&ctx->mixer_mutex);
clk_disable_unprepare(res->hdmi);
clk_disable_unprepare(res->mixer);
if (ctx->vp_enabled) {
clk_disable_unprepare(res->vp);
if (ctx->has_sclk)
clk_disable_unprepare(res->sclk_mixer);
}
pm_runtime_put_sync(ctx->dev);
}
static void mixer_dpms(struct exynos_drm_crtc *crtc, int mode)
{
switch (mode) {
case DRM_MODE_DPMS_ON:
mixer_poweron(crtc->ctx);
break;
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
case DRM_MODE_DPMS_OFF:
mixer_poweroff(crtc->ctx);
break;
default:
DRM_DEBUG_KMS("unknown dpms mode: %d\n", mode);
break;
}
}
int mixer_check_mode(struct drm_display_mode *mode)
{
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
enum drm_plane_type type;
unsigned int zpos;
int ret;
ret = mixer_initialize(ctx, drm_dev);
if (ret)
return ret;
for (zpos = 0; zpos < MIXER_WIN_NR; zpos++) {
type = (zpos == MIXER_DEFAULT_WIN) ? DRM_PLANE_TYPE_PRIMARY :
DRM_PLANE_TYPE_OVERLAY;
ret = exynos_plane_init(drm_dev, &ctx->planes[zpos],
1 << ctx->pipe, type, zpos);
if (ret)
return ret;
}
exynos_plane = &ctx->planes[MIXER_DEFAULT_WIN];
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
struct mixer_drv_data *drv;
struct mixer_context *ctx;
int ret;
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx) {
DRM_ERROR("failed to alloc mixer context.\n");
return -ENOMEM;
}
mutex_init(&ctx->mixer_mutex);
if (dev->of_node) {
const struct of_device_id *match;
match = of_match_node(mixer_match_types, dev->of_node);
drv = (struct mixer_drv_data *)match->data;
} else {
drv = (struct mixer_drv_data *)
platform_get_device_id(pdev)->driver_data;
}
ctx->pdev = pdev;
ctx->dev = dev;
ctx->vp_enabled = drv->is_vp_enabled;
ctx->has_sclk = drv->has_sclk;
ctx->mxr_ver = drv->version;
init_waitqueue_head(&ctx->wait_vsync_queue);
atomic_set(&ctx->wait_vsync_event, 0);
platform_set_drvdata(pdev, ctx);
ret = exynos_drm_component_add(&pdev->dev, EXYNOS_DEVICE_TYPE_CRTC,
EXYNOS_DISPLAY_TYPE_HDMI);
if (ret)
return ret;
ret = component_add(&pdev->dev, &mixer_component_ops);
if (ret) {
exynos_drm_component_del(&pdev->dev, EXYNOS_DEVICE_TYPE_CRTC);
return ret;
}
pm_runtime_enable(dev);
return ret;
}
static int mixer_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
component_del(&pdev->dev, &mixer_component_ops);
exynos_drm_component_del(&pdev->dev, EXYNOS_DEVICE_TYPE_CRTC);
return 0;
}
