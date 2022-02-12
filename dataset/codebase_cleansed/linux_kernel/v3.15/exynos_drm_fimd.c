static inline struct fimd_driver_data *drm_fimd_get_driver_data(
struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(fimd_driver_dt_match, &pdev->dev);
return (struct fimd_driver_data *)of_id->data;
}
static int fimd_mgr_initialize(struct exynos_drm_manager *mgr,
struct drm_device *drm_dev, int pipe)
{
struct fimd_context *ctx = mgr->ctx;
ctx->drm_dev = drm_dev;
ctx->pipe = pipe;
drm_dev->irq_enabled = true;
drm_dev->vblank_disable_allowed = true;
if (is_drm_iommu_supported(ctx->drm_dev))
drm_iommu_attach_device(ctx->drm_dev, ctx->dev);
return 0;
}
static void fimd_mgr_remove(struct exynos_drm_manager *mgr)
{
struct fimd_context *ctx = mgr->ctx;
if (is_drm_iommu_supported(ctx->drm_dev))
drm_iommu_detach_device(ctx->drm_dev, ctx->dev);
}
static u32 fimd_calc_clkdiv(struct fimd_context *ctx,
const struct drm_display_mode *mode)
{
unsigned long ideal_clk = mode->htotal * mode->vtotal * mode->vrefresh;
u32 clkdiv;
clkdiv = DIV_ROUND_UP(clk_get_rate(ctx->lcd_clk), ideal_clk);
return (clkdiv < 0x100) ? clkdiv : 0xff;
}
static bool fimd_mode_fixup(struct exynos_drm_manager *mgr,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
if (adjusted_mode->vrefresh == 0)
adjusted_mode->vrefresh = FIMD_DEFAULT_FRAMERATE;
return true;
}
static void fimd_mode_set(struct exynos_drm_manager *mgr,
const struct drm_display_mode *in_mode)
{
struct fimd_context *ctx = mgr->ctx;
drm_mode_copy(&ctx->mode, in_mode);
}
static void fimd_commit(struct exynos_drm_manager *mgr)
{
struct fimd_context *ctx = mgr->ctx;
struct drm_display_mode *mode = &ctx->mode;
struct fimd_driver_data *driver_data;
u32 val, clkdiv, vidcon1;
int vsync_len, vbpd, vfpd, hsync_len, hbpd, hfpd;
driver_data = ctx->driver_data;
if (ctx->suspended)
return;
if (mode->htotal == 0 || mode->vtotal == 0)
return;
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
val = VIDTCON2_LINEVAL(mode->vdisplay - 1) |
VIDTCON2_HOZVAL(mode->hdisplay - 1) |
VIDTCON2_LINEVAL_E(mode->vdisplay - 1) |
VIDTCON2_HOZVAL_E(mode->hdisplay - 1);
writel(val, ctx->regs + driver_data->timing_base + VIDTCON2);
val = VIDCON0_ENVID | VIDCON0_ENVID_F;
if (ctx->driver_data->has_clksel)
val |= VIDCON0_CLKSEL_LCD;
clkdiv = fimd_calc_clkdiv(ctx, mode);
if (clkdiv > 1)
val |= VIDCON0_CLKVAL_F(clkdiv - 1) | VIDCON0_CLKDIR;
writel(val, ctx->regs + VIDCON0);
}
static int fimd_enable_vblank(struct exynos_drm_manager *mgr)
{
struct fimd_context *ctx = mgr->ctx;
u32 val;
if (ctx->suspended)
return -EPERM;
if (!test_and_set_bit(0, &ctx->irq_flags)) {
val = readl(ctx->regs + VIDINTCON0);
val |= VIDINTCON0_INT_ENABLE;
val |= VIDINTCON0_INT_FRAME;
val &= ~VIDINTCON0_FRAMESEL0_MASK;
val |= VIDINTCON0_FRAMESEL0_VSYNC;
val &= ~VIDINTCON0_FRAMESEL1_MASK;
val |= VIDINTCON0_FRAMESEL1_NONE;
writel(val, ctx->regs + VIDINTCON0);
}
return 0;
}
static void fimd_disable_vblank(struct exynos_drm_manager *mgr)
{
struct fimd_context *ctx = mgr->ctx;
u32 val;
if (ctx->suspended)
return;
if (test_and_clear_bit(0, &ctx->irq_flags)) {
val = readl(ctx->regs + VIDINTCON0);
val &= ~VIDINTCON0_INT_FRAME;
val &= ~VIDINTCON0_INT_ENABLE;
writel(val, ctx->regs + VIDINTCON0);
}
}
static void fimd_wait_for_vblank(struct exynos_drm_manager *mgr)
{
struct fimd_context *ctx = mgr->ctx;
if (ctx->suspended)
return;
atomic_set(&ctx->wait_vsync_event, 1);
if (!wait_event_timeout(ctx->wait_vsync_queue,
!atomic_read(&ctx->wait_vsync_event),
HZ/20))
DRM_DEBUG_KMS("vblank wait timed out.\n");
}
static void fimd_win_mode_set(struct exynos_drm_manager *mgr,
struct exynos_drm_overlay *overlay)
{
struct fimd_context *ctx = mgr->ctx;
struct fimd_win_data *win_data;
int win;
unsigned long offset;
if (!overlay) {
DRM_ERROR("overlay is NULL\n");
return;
}
win = overlay->zpos;
if (win == DEFAULT_ZPOS)
win = ctx->default_win;
if (win < 0 || win >= WINDOWS_NR)
return;
offset = overlay->fb_x * (overlay->bpp >> 3);
offset += overlay->fb_y * overlay->pitch;
DRM_DEBUG_KMS("offset = 0x%lx, pitch = %x\n", offset, overlay->pitch);
win_data = &ctx->win_data[win];
win_data->offset_x = overlay->crtc_x;
win_data->offset_y = overlay->crtc_y;
win_data->ovl_width = overlay->crtc_width;
win_data->ovl_height = overlay->crtc_height;
win_data->fb_width = overlay->fb_width;
win_data->fb_height = overlay->fb_height;
win_data->dma_addr = overlay->dma_addr[0] + offset;
win_data->bpp = overlay->bpp;
win_data->pixel_format = overlay->pixel_format;
win_data->buf_offsize = (overlay->fb_width - overlay->crtc_width) *
(overlay->bpp >> 3);
win_data->line_size = overlay->crtc_width * (overlay->bpp >> 3);
DRM_DEBUG_KMS("offset_x = %d, offset_y = %d\n",
win_data->offset_x, win_data->offset_y);
DRM_DEBUG_KMS("ovl_width = %d, ovl_height = %d\n",
win_data->ovl_width, win_data->ovl_height);
DRM_DEBUG_KMS("paddr = 0x%lx\n", (unsigned long)win_data->dma_addr);
DRM_DEBUG_KMS("fb_width = %d, crtc_width = %d\n",
overlay->fb_width, overlay->crtc_width);
}
static void fimd_win_set_pixfmt(struct fimd_context *ctx, unsigned int win)
{
struct fimd_win_data *win_data = &ctx->win_data[win];
unsigned long val;
val = WINCONx_ENWIN;
if (ctx->driver_data->has_limited_fmt && !win) {
if (win_data->pixel_format == DRM_FORMAT_ARGB8888)
win_data->pixel_format = DRM_FORMAT_XRGB8888;
}
switch (win_data->pixel_format) {
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
DRM_DEBUG_KMS("bpp = %d\n", win_data->bpp);
writel(val, ctx->regs + WINCON(win));
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
int win, bool protect)
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
static void fimd_win_commit(struct exynos_drm_manager *mgr, int zpos)
{
struct fimd_context *ctx = mgr->ctx;
struct fimd_win_data *win_data;
int win = zpos;
unsigned long val, alpha, size;
unsigned int last_x;
unsigned int last_y;
if (ctx->suspended)
return;
if (win == DEFAULT_ZPOS)
win = ctx->default_win;
if (win < 0 || win >= WINDOWS_NR)
return;
win_data = &ctx->win_data[win];
if (ctx->suspended) {
win_data->resume = true;
return;
}
fimd_shadow_protect_win(ctx, win, true);
val = (unsigned long)win_data->dma_addr;
writel(val, ctx->regs + VIDWx_BUF_START(win, 0));
size = win_data->fb_width * win_data->ovl_height * (win_data->bpp >> 3);
val = (unsigned long)(win_data->dma_addr + size);
writel(val, ctx->regs + VIDWx_BUF_END(win, 0));
DRM_DEBUG_KMS("start addr = 0x%lx, end addr = 0x%lx, size = 0x%lx\n",
(unsigned long)win_data->dma_addr, val, size);
DRM_DEBUG_KMS("ovl_width = %d, ovl_height = %d\n",
win_data->ovl_width, win_data->ovl_height);
val = VIDW_BUF_SIZE_OFFSET(win_data->buf_offsize) |
VIDW_BUF_SIZE_PAGEWIDTH(win_data->line_size) |
VIDW_BUF_SIZE_OFFSET_E(win_data->buf_offsize) |
VIDW_BUF_SIZE_PAGEWIDTH_E(win_data->line_size);
writel(val, ctx->regs + VIDWx_BUF_SIZE(win, 0));
val = VIDOSDxA_TOPLEFT_X(win_data->offset_x) |
VIDOSDxA_TOPLEFT_Y(win_data->offset_y) |
VIDOSDxA_TOPLEFT_X_E(win_data->offset_x) |
VIDOSDxA_TOPLEFT_Y_E(win_data->offset_y);
writel(val, ctx->regs + VIDOSD_A(win));
last_x = win_data->offset_x + win_data->ovl_width;
if (last_x)
last_x--;
last_y = win_data->offset_y + win_data->ovl_height;
if (last_y)
last_y--;
val = VIDOSDxB_BOTRIGHT_X(last_x) | VIDOSDxB_BOTRIGHT_Y(last_y) |
VIDOSDxB_BOTRIGHT_X_E(last_x) | VIDOSDxB_BOTRIGHT_Y_E(last_y);
writel(val, ctx->regs + VIDOSD_B(win));
DRM_DEBUG_KMS("osd pos: tx = %d, ty = %d, bx = %d, by = %d\n",
win_data->offset_x, win_data->offset_y, last_x, last_y);
if (win != 0) {
alpha = VIDISD14C_ALPHA1_R(0xf) |
VIDISD14C_ALPHA1_G(0xf) |
VIDISD14C_ALPHA1_B(0xf);
writel(alpha, ctx->regs + VIDOSD_C(win));
}
if (win != 3 && win != 4) {
u32 offset = VIDOSD_D(win);
if (win == 0)
offset = VIDOSD_C(win);
val = win_data->ovl_width * win_data->ovl_height;
writel(val, ctx->regs + offset);
DRM_DEBUG_KMS("osd size = 0x%x\n", (unsigned int)val);
}
fimd_win_set_pixfmt(ctx, win);
if (win != 0)
fimd_win_set_colkey(ctx, win);
val = readl(ctx->regs + WINCON(win));
val |= WINCONx_ENWIN;
writel(val, ctx->regs + WINCON(win));
fimd_shadow_protect_win(ctx, win, false);
if (ctx->driver_data->has_shadowcon) {
val = readl(ctx->regs + SHADOWCON);
val |= SHADOWCON_CHx_ENABLE(win);
writel(val, ctx->regs + SHADOWCON);
}
win_data->enabled = true;
}
static void fimd_win_disable(struct exynos_drm_manager *mgr, int zpos)
{
struct fimd_context *ctx = mgr->ctx;
struct fimd_win_data *win_data;
int win = zpos;
u32 val;
if (win == DEFAULT_ZPOS)
win = ctx->default_win;
if (win < 0 || win >= WINDOWS_NR)
return;
win_data = &ctx->win_data[win];
if (ctx->suspended) {
win_data->resume = false;
return;
}
fimd_shadow_protect_win(ctx, win, true);
val = readl(ctx->regs + WINCON(win));
val &= ~WINCONx_ENWIN;
writel(val, ctx->regs + WINCON(win));
if (ctx->driver_data->has_shadowcon) {
val = readl(ctx->regs + SHADOWCON);
val &= ~SHADOWCON_CHx_ENABLE(win);
writel(val, ctx->regs + SHADOWCON);
}
fimd_shadow_protect_win(ctx, win, false);
win_data->enabled = false;
}
static void fimd_clear_win(struct fimd_context *ctx, int win)
{
writel(0, ctx->regs + WINCON(win));
writel(0, ctx->regs + VIDOSD_A(win));
writel(0, ctx->regs + VIDOSD_B(win));
writel(0, ctx->regs + VIDOSD_C(win));
if (win == 1 || win == 2)
writel(0, ctx->regs + VIDOSD_D(win));
fimd_shadow_protect_win(ctx, win, false);
}
static void fimd_window_suspend(struct exynos_drm_manager *mgr)
{
struct fimd_context *ctx = mgr->ctx;
struct fimd_win_data *win_data;
int i;
for (i = 0; i < WINDOWS_NR; i++) {
win_data = &ctx->win_data[i];
win_data->resume = win_data->enabled;
if (win_data->enabled)
fimd_win_disable(mgr, i);
}
fimd_wait_for_vblank(mgr);
}
static void fimd_window_resume(struct exynos_drm_manager *mgr)
{
struct fimd_context *ctx = mgr->ctx;
struct fimd_win_data *win_data;
int i;
for (i = 0; i < WINDOWS_NR; i++) {
win_data = &ctx->win_data[i];
win_data->enabled = win_data->resume;
win_data->resume = false;
}
}
static void fimd_apply(struct exynos_drm_manager *mgr)
{
struct fimd_context *ctx = mgr->ctx;
struct fimd_win_data *win_data;
int i;
for (i = 0; i < WINDOWS_NR; i++) {
win_data = &ctx->win_data[i];
if (win_data->enabled)
fimd_win_commit(mgr, i);
}
fimd_commit(mgr);
}
static int fimd_poweron(struct exynos_drm_manager *mgr)
{
struct fimd_context *ctx = mgr->ctx;
int ret;
if (!ctx->suspended)
return 0;
ctx->suspended = false;
pm_runtime_get_sync(ctx->dev);
ret = clk_prepare_enable(ctx->bus_clk);
if (ret < 0) {
DRM_ERROR("Failed to prepare_enable the bus clk [%d]\n", ret);
goto bus_clk_err;
}
ret = clk_prepare_enable(ctx->lcd_clk);
if (ret < 0) {
DRM_ERROR("Failed to prepare_enable the lcd clk [%d]\n", ret);
goto lcd_clk_err;
}
if (test_and_clear_bit(0, &ctx->irq_flags)) {
ret = fimd_enable_vblank(mgr);
if (ret) {
DRM_ERROR("Failed to re-enable vblank [%d]\n", ret);
goto enable_vblank_err;
}
}
fimd_window_resume(mgr);
fimd_apply(mgr);
return 0;
enable_vblank_err:
clk_disable_unprepare(ctx->lcd_clk);
lcd_clk_err:
clk_disable_unprepare(ctx->bus_clk);
bus_clk_err:
ctx->suspended = true;
return ret;
}
static int fimd_poweroff(struct exynos_drm_manager *mgr)
{
struct fimd_context *ctx = mgr->ctx;
if (ctx->suspended)
return 0;
fimd_window_suspend(mgr);
clk_disable_unprepare(ctx->lcd_clk);
clk_disable_unprepare(ctx->bus_clk);
pm_runtime_put_sync(ctx->dev);
ctx->suspended = true;
return 0;
}
static void fimd_dpms(struct exynos_drm_manager *mgr, int mode)
{
DRM_DEBUG_KMS("%s, %d\n", __FILE__, mode);
switch (mode) {
case DRM_MODE_DPMS_ON:
fimd_poweron(mgr);
break;
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
case DRM_MODE_DPMS_OFF:
fimd_poweroff(mgr);
break;
default:
DRM_DEBUG_KMS("unspecified mode %d\n", mode);
break;
}
}
static irqreturn_t fimd_irq_handler(int irq, void *dev_id)
{
struct fimd_context *ctx = (struct fimd_context *)dev_id;
u32 val;
val = readl(ctx->regs + VIDINTCON1);
if (val & VIDINTCON1_INT_FRAME)
writel(VIDINTCON1_INT_FRAME, ctx->regs + VIDINTCON1);
if (ctx->pipe < 0 || !ctx->drm_dev)
goto out;
drm_handle_vblank(ctx->drm_dev, ctx->pipe);
exynos_drm_crtc_finish_pageflip(ctx->drm_dev, ctx->pipe);
if (atomic_read(&ctx->wait_vsync_event)) {
atomic_set(&ctx->wait_vsync_event, 0);
wake_up(&ctx->wait_vsync_queue);
}
out:
return IRQ_HANDLED;
}
static int fimd_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct fimd_context *ctx;
struct resource *res;
int win;
int ret = -EINVAL;
if (!dev->of_node)
return -ENODEV;
ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->dev = dev;
ctx->suspended = true;
if (of_property_read_bool(dev->of_node, "samsung,invert-vden"))
ctx->vidcon1 |= VIDCON1_INV_VDEN;
if (of_property_read_bool(dev->of_node, "samsung,invert-vclk"))
ctx->vidcon1 |= VIDCON1_INV_VCLK;
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
res = platform_get_resource_byname(pdev, IORESOURCE_IRQ, "vsync");
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
ctx->driver_data = drm_fimd_get_driver_data(pdev);
init_waitqueue_head(&ctx->wait_vsync_queue);
atomic_set(&ctx->wait_vsync_event, 0);
platform_set_drvdata(pdev, &fimd_manager);
fimd_manager.ctx = ctx;
exynos_drm_manager_register(&fimd_manager);
exynos_dpi_probe(ctx->dev);
pm_runtime_enable(dev);
for (win = 0; win < WINDOWS_NR; win++)
fimd_clear_win(ctx, win);
return 0;
}
static int fimd_remove(struct platform_device *pdev)
{
struct exynos_drm_manager *mgr = platform_get_drvdata(pdev);
exynos_dpi_remove(&pdev->dev);
exynos_drm_manager_unregister(&fimd_manager);
fimd_dpms(mgr, DRM_MODE_DPMS_OFF);
pm_runtime_disable(&pdev->dev);
return 0;
}
