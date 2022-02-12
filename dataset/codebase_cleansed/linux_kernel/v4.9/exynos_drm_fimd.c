static int fimd_enable_vblank(struct exynos_drm_crtc *crtc)
{
struct fimd_context *ctx = crtc->ctx;
u32 val;
if (ctx->suspended)
return -EPERM;
if (!test_and_set_bit(0, &ctx->irq_flags)) {
val = readl(ctx->regs + VIDINTCON0);
val |= VIDINTCON0_INT_ENABLE;
if (ctx->i80_if) {
val |= VIDINTCON0_INT_I80IFDONE;
val |= VIDINTCON0_INT_SYSMAINCON;
val &= ~VIDINTCON0_INT_SYSSUBCON;
} else {
val |= VIDINTCON0_INT_FRAME;
val &= ~VIDINTCON0_FRAMESEL0_MASK;
val |= VIDINTCON0_FRAMESEL0_VSYNC;
val &= ~VIDINTCON0_FRAMESEL1_MASK;
val |= VIDINTCON0_FRAMESEL1_NONE;
}
writel(val, ctx->regs + VIDINTCON0);
}
return 0;
}
static void fimd_disable_vblank(struct exynos_drm_crtc *crtc)
{
struct fimd_context *ctx = crtc->ctx;
u32 val;
if (ctx->suspended)
return;
if (test_and_clear_bit(0, &ctx->irq_flags)) {
val = readl(ctx->regs + VIDINTCON0);
val &= ~VIDINTCON0_INT_ENABLE;
if (ctx->i80_if) {
val &= ~VIDINTCON0_INT_I80IFDONE;
val &= ~VIDINTCON0_INT_SYSMAINCON;
val &= ~VIDINTCON0_INT_SYSSUBCON;
} else
val &= ~VIDINTCON0_INT_FRAME;
writel(val, ctx->regs + VIDINTCON0);
}
}
static void fimd_wait_for_vblank(struct exynos_drm_crtc *crtc)
{
struct fimd_context *ctx = crtc->ctx;
if (ctx->suspended)
return;
atomic_set(&ctx->wait_vsync_event, 1);
if (!wait_event_timeout(ctx->wait_vsync_queue,
!atomic_read(&ctx->wait_vsync_event),
HZ/20))
DRM_DEBUG_KMS("vblank wait timed out.\n");
}
static void fimd_enable_video_output(struct fimd_context *ctx, unsigned int win,
bool enable)
{
u32 val = readl(ctx->regs + WINCON(win));
if (enable)
val |= WINCONx_ENWIN;
else
val &= ~WINCONx_ENWIN;
writel(val, ctx->regs + WINCON(win));
}
static void fimd_enable_shadow_channel_path(struct fimd_context *ctx,
unsigned int win,
bool enable)
{
u32 val = readl(ctx->regs + SHADOWCON);
if (enable)
val |= SHADOWCON_CHx_ENABLE(win);
else
val &= ~SHADOWCON_CHx_ENABLE(win);
writel(val, ctx->regs + SHADOWCON);
}
static void fimd_clear_channels(struct exynos_drm_crtc *crtc)
{
struct fimd_context *ctx = crtc->ctx;
unsigned int win, ch_enabled = 0;
DRM_DEBUG_KMS("%s\n", __FILE__);
pm_runtime_get_sync(ctx->dev);
clk_prepare_enable(ctx->bus_clk);
clk_prepare_enable(ctx->lcd_clk);
for (win = 0; win < WINDOWS_NR; win++) {
u32 val = readl(ctx->regs + WINCON(win));
if (val & WINCONx_ENWIN) {
fimd_enable_video_output(ctx, win, false);
if (ctx->driver_data->has_shadowcon)
fimd_enable_shadow_channel_path(ctx, win,
false);
ch_enabled = 1;
}
}
if (ch_enabled) {
int pipe = ctx->pipe;
ctx->suspended = false;
ctx->pipe = -1;
fimd_enable_vblank(ctx->crtc);
fimd_wait_for_vblank(ctx->crtc);
fimd_disable_vblank(ctx->crtc);
ctx->suspended = true;
ctx->pipe = pipe;
}
clk_disable_unprepare(ctx->lcd_clk);
clk_disable_unprepare(ctx->bus_clk);
pm_runtime_put(ctx->dev);
}
static int fimd_atomic_check(struct exynos_drm_crtc *crtc,
struct drm_crtc_state *state)
{
struct drm_display_mode *mode = &state->adjusted_mode;
struct fimd_context *ctx = crtc->ctx;
unsigned long ideal_clk, lcd_rate;
u32 clkdiv;
if (mode->clock == 0) {
DRM_INFO("Mode has zero clock value.\n");
return -EINVAL;
}
ideal_clk = mode->clock * 1000;
if (ctx->i80_if) {
ideal_clk *= 2;
}
lcd_rate = clk_get_rate(ctx->lcd_clk);
if (2 * lcd_rate < ideal_clk) {
DRM_INFO("sclk_fimd clock too low(%lu) for requested pixel clock(%lu)\n",
lcd_rate, ideal_clk);
return -EINVAL;
}
clkdiv = DIV_ROUND_CLOSEST(lcd_rate, ideal_clk);
if (clkdiv >= 0x200) {
DRM_INFO("requested pixel clock(%lu) too low\n", ideal_clk);
return -EINVAL;
}
ctx->clkdiv = (clkdiv < 0x100) ? clkdiv : 0xff;
return 0;
}
static void fimd_setup_trigger(struct fimd_context *ctx)
{
void __iomem *timing_base = ctx->regs + ctx->driver_data->timing_base;
u32 trg_type = ctx->driver_data->trg_type;
u32 val = readl(timing_base + TRIGCON);
val &= ~(TRGMODE_ENABLE);
if (trg_type == I80_HW_TRG) {
if (ctx->driver_data->has_hw_trigger)
val |= HWTRGEN_ENABLE | HWTRGMASK_ENABLE;
if (ctx->driver_data->has_trigger_per_te)
val |= HWTRIGEN_PER_ENABLE;
} else {
val |= TRGMODE_ENABLE;
}
writel(val, timing_base + TRIGCON);
}
static void fimd_commit(struct exynos_drm_crtc *crtc)
{
struct fimd_context *ctx = crtc->ctx;
struct drm_display_mode *mode = &crtc->base.state->adjusted_mode;
const struct fimd_driver_data *driver_data = ctx->driver_data;
void *timing_base = ctx->regs + driver_data->timing_base;
u32 val;
if (ctx->suspended)
return;
if (mode->htotal == 0 || mode->vtotal == 0)
return;
if (ctx->i80_if) {
val = ctx->i80ifcon | I80IFEN_ENABLE;
writel(val, timing_base + I80IFCONFAx(0));
writel(0, timing_base + I80IFCONFBx(0));
if (driver_data->has_vtsel && ctx->sysreg &&
regmap_update_bits(ctx->sysreg,
driver_data->lcdblk_offset,
0x3 << driver_data->lcdblk_vt_shift,
0x1 << driver_data->lcdblk_vt_shift)) {
DRM_ERROR("Failed to update sysreg for I80 i/f.\n");
return;
}
} else {
int vsync_len, vbpd, vfpd, hsync_len, hbpd, hfpd;
u32 vidcon1;
vidcon1 = ctx->vidcon1;
if (mode->flags & DRM_MODE_FLAG_NVSYNC)
vidcon1 |= VIDCON1_INV_VSYNC;
if (mode->flags & DRM_MODE_FLAG_NHSYNC)
vidcon1 |= VIDCON1_INV_HSYNC;
writel(vidcon1, ctx->regs + driver_data->timing_base + VIDCON1);
vsync_len = mode->crtc_vsync_end - mode->crtc_vsync_start;
vbpd = mode->crtc_vtotal - mode->crtc_vsync_end;
vfpd = mode->crtc_vsync_start - mode->crtc_vdisplay;
val = VIDTCON0_VBPD(vbpd - 1) |
VIDTCON0_VFPD(vfpd - 1) |
VIDTCON0_VSPW(vsync_len - 1);
writel(val, ctx->regs + driver_data->timing_base + VIDTCON0);
hsync_len = mode->crtc_hsync_end - mode->crtc_hsync_start;
hbpd = mode->crtc_htotal - mode->crtc_hsync_end;
hfpd = mode->crtc_hsync_start - mode->crtc_hdisplay;
val = VIDTCON1_HBPD(hbpd - 1) |
VIDTCON1_HFPD(hfpd - 1) |
VIDTCON1_HSPW(hsync_len - 1);
writel(val, ctx->regs + driver_data->timing_base + VIDTCON1);
}
if (driver_data->has_vidoutcon)
writel(ctx->vidout_con, timing_base + VIDOUT_CON);
if (ctx->sysreg && regmap_update_bits(ctx->sysreg,
driver_data->lcdblk_offset,
0x1 << driver_data->lcdblk_bypass_shift,
0x1 << driver_data->lcdblk_bypass_shift)) {
DRM_ERROR("Failed to update sysreg for bypass setting.\n");
return;
}
if (driver_data->has_mic_bypass && ctx->sysreg &&
regmap_update_bits(ctx->sysreg,
driver_data->lcdblk_offset,
0x1 << driver_data->lcdblk_mic_bypass_shift,
0x1 << driver_data->lcdblk_mic_bypass_shift)) {
DRM_ERROR("Failed to update sysreg for bypass mic.\n");
return;
}
val = VIDTCON2_LINEVAL(mode->vdisplay - 1) |
VIDTCON2_HOZVAL(mode->hdisplay - 1) |
VIDTCON2_LINEVAL_E(mode->vdisplay - 1) |
VIDTCON2_HOZVAL_E(mode->hdisplay - 1);
writel(val, ctx->regs + driver_data->timing_base + VIDTCON2);
fimd_setup_trigger(ctx);
val = ctx->vidcon0;
val |= VIDCON0_ENVID | VIDCON0_ENVID_F;
if (ctx->driver_data->has_clksel)
val |= VIDCON0_CLKSEL_LCD;
if (ctx->clkdiv > 1)
val |= VIDCON0_CLKVAL_F(ctx->clkdiv - 1) | VIDCON0_CLKDIR;
writel(val, ctx->regs + VIDCON0);
}
static void fimd_win_set_pixfmt(struct fimd_context *ctx, unsigned int win,
uint32_t pixel_format, int width)
{
unsigned long val;
val = WINCONx_ENWIN;
if (ctx->driver_data->has_limited_fmt && !win) {
if (pixel_format == DRM_FORMAT_ARGB8888)
pixel_format = DRM_FORMAT_XRGB8888;
}
switch (pixel_format) {
case DRM_FORMAT_C8:
val |= WINCON0_BPPMODE_8BPP_PALETTE;
val |= WINCONx_BURSTLEN_8WORD;
val |= WINCONx_BYTSWP;
break;
case DRM_FORMAT_XRGB1555:
val |= WINCON0_BPPMODE_16BPP_1555;
val |= WINCONx_HAWSWP;
val |= WINCONx_BURSTLEN_16WORD;
break;
case DRM_FORMAT_RGB565:
val |= WINCON0_BPPMODE_16BPP_565;
val |= WINCONx_HAWSWP;
val |= WINCONx_BURSTLEN_16WORD;
break;
case DRM_FORMAT_XRGB8888:
val |= WINCON0_BPPMODE_24BPP_888;
val |= WINCONx_WSWP;
val |= WINCONx_BURSTLEN_16WORD;
break;
case DRM_FORMAT_ARGB8888:
val |= WINCON1_BPPMODE_25BPP_A1888
| WINCON1_BLD_PIX | WINCON1_ALPHA_SEL;
val |= WINCONx_WSWP;
val |= WINCONx_BURSTLEN_16WORD;
break;
default:
DRM_DEBUG_KMS("invalid pixel size so using unpacked 24bpp.\n");
val |= WINCON0_BPPMODE_24BPP_888;
val |= WINCONx_WSWP;
val |= WINCONx_BURSTLEN_16WORD;
break;
}
if (width < MIN_FB_WIDTH_FOR_16WORD_BURST) {
val &= ~WINCONx_BURSTLEN_MASK;
val |= WINCONx_BURSTLEN_4WORD;
}
writel(val, ctx->regs + WINCON(win));
if (win != 0) {
val = VIDISD14C_ALPHA0_R(0xf) |
VIDISD14C_ALPHA0_G(0xf) |
VIDISD14C_ALPHA0_B(0xf) |
VIDISD14C_ALPHA1_R(0xf) |
VIDISD14C_ALPHA1_G(0xf) |
VIDISD14C_ALPHA1_B(0xf);
writel(val, ctx->regs + VIDOSD_C(win));
val = VIDW_ALPHA_R(0xf) | VIDW_ALPHA_G(0xf) |
VIDW_ALPHA_G(0xf);
writel(val, ctx->regs + VIDWnALPHA0(win));
writel(val, ctx->regs + VIDWnALPHA1(win));
}
}
static void fimd_win_set_colkey(struct fimd_context *ctx, unsigned int win)
{
unsigned int keycon0 = 0, keycon1 = 0;
keycon0 = ~(WxKEYCON0_KEYBL_EN | WxKEYCON0_KEYEN_F |
WxKEYCON0_DIRCON) | WxKEYCON0_COMPKEY(0);
keycon1 = WxKEYCON1_COLVAL(0xffffffff);
writel(keycon0, ctx->regs + WKEYCON0_BASE(win));
writel(keycon1, ctx->regs + WKEYCON1_BASE(win));
}
static void fimd_shadow_protect_win(struct fimd_context *ctx,
unsigned int win, bool protect)
{
u32 reg, bits, val;
if (ctx->driver_data->has_shadowcon) {
reg = SHADOWCON;
bits = SHADOWCON_WINx_PROTECT(win);
} else {
reg = PRTCON;
bits = PRTCON_PROTECT;
}
val = readl(ctx->regs + reg);
if (protect)
val |= bits;
else
val &= ~bits;
writel(val, ctx->regs + reg);
}
static void fimd_atomic_begin(struct exynos_drm_crtc *crtc)
{
struct fimd_context *ctx = crtc->ctx;
int i;
if (ctx->suspended)
return;
for (i = 0; i < WINDOWS_NR; i++)
fimd_shadow_protect_win(ctx, i, true);
}
static void fimd_atomic_flush(struct exynos_drm_crtc *crtc)
{
struct fimd_context *ctx = crtc->ctx;
int i;
if (ctx->suspended)
return;
for (i = 0; i < WINDOWS_NR; i++)
fimd_shadow_protect_win(ctx, i, false);
}
static void fimd_update_plane(struct exynos_drm_crtc *crtc,
struct exynos_drm_plane *plane)
{
struct exynos_drm_plane_state *state =
to_exynos_plane_state(plane->base.state);
struct fimd_context *ctx = crtc->ctx;
struct drm_framebuffer *fb = state->base.fb;
dma_addr_t dma_addr;
unsigned long val, size, offset;
unsigned int last_x, last_y, buf_offsize, line_size;
unsigned int win = plane->index;
unsigned int bpp = fb->bits_per_pixel >> 3;
unsigned int pitch = fb->pitches[0];
if (ctx->suspended)
return;
offset = state->src.x * bpp;
offset += state->src.y * pitch;
dma_addr = exynos_drm_fb_dma_addr(fb, 0) + offset;
val = (unsigned long)dma_addr;
writel(val, ctx->regs + VIDWx_BUF_START(win, 0));
size = pitch * state->crtc.h;
val = (unsigned long)(dma_addr + size);
writel(val, ctx->regs + VIDWx_BUF_END(win, 0));
DRM_DEBUG_KMS("start addr = 0x%lx, end addr = 0x%lx, size = 0x%lx\n",
(unsigned long)dma_addr, val, size);
DRM_DEBUG_KMS("ovl_width = %d, ovl_height = %d\n",
state->crtc.w, state->crtc.h);
buf_offsize = pitch - (state->crtc.w * bpp);
line_size = state->crtc.w * bpp;
val = VIDW_BUF_SIZE_OFFSET(buf_offsize) |
VIDW_BUF_SIZE_PAGEWIDTH(line_size) |
VIDW_BUF_SIZE_OFFSET_E(buf_offsize) |
VIDW_BUF_SIZE_PAGEWIDTH_E(line_size);
writel(val, ctx->regs + VIDWx_BUF_SIZE(win, 0));
val = VIDOSDxA_TOPLEFT_X(state->crtc.x) |
VIDOSDxA_TOPLEFT_Y(state->crtc.y) |
VIDOSDxA_TOPLEFT_X_E(state->crtc.x) |
VIDOSDxA_TOPLEFT_Y_E(state->crtc.y);
writel(val, ctx->regs + VIDOSD_A(win));
last_x = state->crtc.x + state->crtc.w;
if (last_x)
last_x--;
last_y = state->crtc.y + state->crtc.h;
if (last_y)
last_y--;
val = VIDOSDxB_BOTRIGHT_X(last_x) | VIDOSDxB_BOTRIGHT_Y(last_y) |
VIDOSDxB_BOTRIGHT_X_E(last_x) | VIDOSDxB_BOTRIGHT_Y_E(last_y);
writel(val, ctx->regs + VIDOSD_B(win));
DRM_DEBUG_KMS("osd pos: tx = %d, ty = %d, bx = %d, by = %d\n",
state->crtc.x, state->crtc.y, last_x, last_y);
if (win != 3 && win != 4) {
u32 offset = VIDOSD_D(win);
if (win == 0)
offset = VIDOSD_C(win);
val = state->crtc.w * state->crtc.h;
writel(val, ctx->regs + offset);
DRM_DEBUG_KMS("osd size = 0x%x\n", (unsigned int)val);
}
fimd_win_set_pixfmt(ctx, win, fb->pixel_format, state->src.w);
if (win != 0)
fimd_win_set_colkey(ctx, win);
fimd_enable_video_output(ctx, win, true);
if (ctx->driver_data->has_shadowcon)
fimd_enable_shadow_channel_path(ctx, win, true);
if (ctx->i80_if)
atomic_set(&ctx->win_updated, 1);
}
static void fimd_disable_plane(struct exynos_drm_crtc *crtc,
struct exynos_drm_plane *plane)
{
struct fimd_context *ctx = crtc->ctx;
unsigned int win = plane->index;
if (ctx->suspended)
return;
fimd_enable_video_output(ctx, win, false);
if (ctx->driver_data->has_shadowcon)
fimd_enable_shadow_channel_path(ctx, win, false);
}
static void fimd_enable(struct exynos_drm_crtc *crtc)
{
struct fimd_context *ctx = crtc->ctx;
if (!ctx->suspended)
return;
ctx->suspended = false;
pm_runtime_get_sync(ctx->dev);
if (test_and_clear_bit(0, &ctx->irq_flags))
fimd_enable_vblank(ctx->crtc);
fimd_commit(ctx->crtc);
}
static void fimd_disable(struct exynos_drm_crtc *crtc)
{
struct fimd_context *ctx = crtc->ctx;
int i;
if (ctx->suspended)
return;
for (i = 0; i < WINDOWS_NR; i++)
fimd_disable_plane(crtc, &ctx->planes[i]);
fimd_enable_vblank(crtc);
fimd_wait_for_vblank(crtc);
fimd_disable_vblank(crtc);
writel(0, ctx->regs + VIDCON0);
pm_runtime_put_sync(ctx->dev);
ctx->suspended = true;
}
static void fimd_trigger(struct device *dev)
{
struct fimd_context *ctx = dev_get_drvdata(dev);
const struct fimd_driver_data *driver_data = ctx->driver_data;
void *timing_base = ctx->regs + driver_data->timing_base;
u32 reg;
if (atomic_read(&ctx->triggering))
return;
atomic_set(&ctx->triggering, 1);
reg = readl(timing_base + TRIGCON);
reg |= (TRGMODE_ENABLE | SWTRGCMD_ENABLE);
writel(reg, timing_base + TRIGCON);
if (!test_bit(0, &ctx->irq_flags))
atomic_set(&ctx->triggering, 0);
}
static void fimd_te_handler(struct exynos_drm_crtc *crtc)
{
struct fimd_context *ctx = crtc->ctx;
u32 trg_type = ctx->driver_data->trg_type;
if (ctx->pipe < 0 || !ctx->drm_dev)
return;
if (trg_type == I80_HW_TRG)
goto out;
if (atomic_add_unless(&ctx->win_updated, -1, 0))
fimd_trigger(ctx->dev);
out:
if (atomic_read(&ctx->wait_vsync_event)) {
atomic_set(&ctx->wait_vsync_event, 0);
wake_up(&ctx->wait_vsync_queue);
}
if (test_bit(0, &ctx->irq_flags))
drm_crtc_handle_vblank(&ctx->crtc->base);
}
static void fimd_dp_clock_enable(struct exynos_drm_clk *clk, bool enable)
{
struct fimd_context *ctx = container_of(clk, struct fimd_context,
dp_clk);
u32 val = enable ? DP_MIE_CLK_DP_ENABLE : DP_MIE_CLK_DISABLE;
writel(val, ctx->regs + DP_MIE_CLKCON);
}
static irqreturn_t fimd_irq_handler(int irq, void *dev_id)
{
struct fimd_context *ctx = (struct fimd_context *)dev_id;
u32 val, clear_bit;
val = readl(ctx->regs + VIDINTCON1);
clear_bit = ctx->i80_if ? VIDINTCON1_INT_I80 : VIDINTCON1_INT_FRAME;
if (val & clear_bit)
writel(clear_bit, ctx->regs + VIDINTCON1);
if (ctx->pipe < 0 || !ctx->drm_dev)
goto out;
if (!ctx->i80_if)
drm_crtc_handle_vblank(&ctx->crtc->base);
if (ctx->i80_if) {
atomic_set(&ctx->triggering, 0);
} else {
if (atomic_read(&ctx->wait_vsync_event)) {
atomic_set(&ctx->wait_vsync_event, 0);
wake_up(&ctx->wait_vsync_queue);
}
}
out:
return IRQ_HANDLED;
}
static int fimd_bind(struct device *dev, struct device *master, void *data)
{
struct fimd_context *ctx = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
struct exynos_drm_private *priv = drm_dev->dev_private;
struct exynos_drm_plane *exynos_plane;
unsigned int i;
int ret;
ctx->drm_dev = drm_dev;
ctx->pipe = priv->pipe++;
for (i = 0; i < WINDOWS_NR; i++) {
ctx->configs[i].pixel_formats = fimd_formats;
ctx->configs[i].num_pixel_formats = ARRAY_SIZE(fimd_formats);
ctx->configs[i].zpos = i;
ctx->configs[i].type = fimd_win_types[i];
ret = exynos_plane_init(drm_dev, &ctx->planes[i], i,
1 << ctx->pipe, &ctx->configs[i]);
if (ret)
return ret;
}
exynos_plane = &ctx->planes[DEFAULT_WIN];
ctx->crtc = exynos_drm_crtc_create(drm_dev, &exynos_plane->base,
ctx->pipe, EXYNOS_DISPLAY_TYPE_LCD,
&fimd_crtc_ops, ctx);
if (IS_ERR(ctx->crtc))
return PTR_ERR(ctx->crtc);
if (ctx->driver_data->has_dp_clk) {
ctx->dp_clk.enable = fimd_dp_clock_enable;
ctx->crtc->pipe_clk = &ctx->dp_clk;
}
if (ctx->encoder)
exynos_dpi_bind(drm_dev, ctx->encoder);
if (is_drm_iommu_supported(drm_dev))
fimd_clear_channels(ctx->crtc);
ret = drm_iommu_attach_device(drm_dev, dev);
if (ret)
priv->pipe--;
return ret;
}
static void fimd_unbind(struct device *dev, struct device *master,
void *data)
{
struct fimd_context *ctx = dev_get_drvdata(dev);
fimd_disable(ctx->crtc);
drm_iommu_detach_device(ctx->drm_dev, ctx->dev);
if (ctx->encoder)
exynos_dpi_remove(ctx->encoder);
}
static int fimd_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct fimd_context *ctx;
struct device_node *i80_if_timings;
struct resource *res;
int ret;
if (!dev->of_node)
return -ENODEV;
ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->dev = dev;
ctx->suspended = true;
ctx->driver_data = of_device_get_match_data(dev);
if (of_property_read_bool(dev->of_node, "samsung,invert-vden"))
ctx->vidcon1 |= VIDCON1_INV_VDEN;
if (of_property_read_bool(dev->of_node, "samsung,invert-vclk"))
ctx->vidcon1 |= VIDCON1_INV_VCLK;
i80_if_timings = of_get_child_by_name(dev->of_node, "i80-if-timings");
if (i80_if_timings) {
u32 val;
ctx->i80_if = true;
if (ctx->driver_data->has_vidoutcon)
ctx->vidout_con |= VIDOUT_CON_F_I80_LDI0;
else
ctx->vidcon0 |= VIDCON0_VIDOUT_I80_LDI0;
ctx->vidcon0 |= VIDCON0_DSI_EN;
if (of_property_read_u32(i80_if_timings, "cs-setup", &val))
val = 0;
ctx->i80ifcon = LCD_CS_SETUP(val);
if (of_property_read_u32(i80_if_timings, "wr-setup", &val))
val = 0;
ctx->i80ifcon |= LCD_WR_SETUP(val);
if (of_property_read_u32(i80_if_timings, "wr-active", &val))
val = 1;
ctx->i80ifcon |= LCD_WR_ACTIVE(val);
if (of_property_read_u32(i80_if_timings, "wr-hold", &val))
val = 0;
ctx->i80ifcon |= LCD_WR_HOLD(val);
}
of_node_put(i80_if_timings);
ctx->sysreg = syscon_regmap_lookup_by_phandle(dev->of_node,
"samsung,sysreg");
if (IS_ERR(ctx->sysreg)) {
dev_warn(dev, "failed to get system register.\n");
ctx->sysreg = NULL;
}
ctx->bus_clk = devm_clk_get(dev, "fimd");
if (IS_ERR(ctx->bus_clk)) {
dev_err(dev, "failed to get bus clock\n");
return PTR_ERR(ctx->bus_clk);
}
ctx->lcd_clk = devm_clk_get(dev, "sclk_fimd");
if (IS_ERR(ctx->lcd_clk)) {
dev_err(dev, "failed to get lcd clock\n");
return PTR_ERR(ctx->lcd_clk);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ctx->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(ctx->regs))
return PTR_ERR(ctx->regs);
res = platform_get_resource_byname(pdev, IORESOURCE_IRQ,
ctx->i80_if ? "lcd_sys" : "vsync");
if (!res) {
dev_err(dev, "irq request failed.\n");
return -ENXIO;
}
ret = devm_request_irq(dev, res->start, fimd_irq_handler,
0, "drm_fimd", ctx);
if (ret) {
dev_err(dev, "irq request failed.\n");
return ret;
}
init_waitqueue_head(&ctx->wait_vsync_queue);
atomic_set(&ctx->wait_vsync_event, 0);
platform_set_drvdata(pdev, ctx);
ctx->encoder = exynos_dpi_probe(dev);
if (IS_ERR(ctx->encoder))
return PTR_ERR(ctx->encoder);
pm_runtime_enable(dev);
ret = component_add(dev, &fimd_component_ops);
if (ret)
goto err_disable_pm_runtime;
return ret;
err_disable_pm_runtime:
pm_runtime_disable(dev);
return ret;
}
static int fimd_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
component_del(&pdev->dev, &fimd_component_ops);
return 0;
}
static int exynos_fimd_suspend(struct device *dev)
{
struct fimd_context *ctx = dev_get_drvdata(dev);
clk_disable_unprepare(ctx->lcd_clk);
clk_disable_unprepare(ctx->bus_clk);
return 0;
}
static int exynos_fimd_resume(struct device *dev)
{
struct fimd_context *ctx = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(ctx->bus_clk);
if (ret < 0) {
DRM_ERROR("Failed to prepare_enable the bus clk [%d]\n", ret);
return ret;
}
ret = clk_prepare_enable(ctx->lcd_clk);
if (ret < 0) {
DRM_ERROR("Failed to prepare_enable the lcd clk [%d]\n", ret);
return ret;
}
return 0;
}
