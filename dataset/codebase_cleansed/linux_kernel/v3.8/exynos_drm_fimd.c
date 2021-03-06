static inline struct fimd_driver_data *drm_fimd_get_driver_data(
struct platform_device *pdev)
{
#ifdef CONFIG_OF
const struct of_device_id *of_id =
of_match_device(fimd_driver_dt_match, &pdev->dev);
if (of_id)
return (struct fimd_driver_data *)of_id->data;
#endif
return (struct fimd_driver_data *)
platform_get_device_id(pdev)->driver_data;
}
static bool fimd_display_is_connected(struct device *dev)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
return true;
}
static void *fimd_get_panel(struct device *dev)
{
struct fimd_context *ctx = get_fimd_context(dev);
DRM_DEBUG_KMS("%s\n", __FILE__);
return ctx->panel;
}
static int fimd_check_timing(struct device *dev, void *timing)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
return 0;
}
static int fimd_display_power_on(struct device *dev, int mode)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
return 0;
}
static void fimd_dpms(struct device *subdrv_dev, int mode)
{
struct fimd_context *ctx = get_fimd_context(subdrv_dev);
DRM_DEBUG_KMS("%s, %d\n", __FILE__, mode);
mutex_lock(&ctx->lock);
switch (mode) {
case DRM_MODE_DPMS_ON:
if (ctx->suspended)
pm_runtime_get_sync(subdrv_dev);
break;
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
case DRM_MODE_DPMS_OFF:
if (!ctx->suspended)
pm_runtime_put_sync(subdrv_dev);
break;
default:
DRM_DEBUG_KMS("unspecified mode %d\n", mode);
break;
}
mutex_unlock(&ctx->lock);
}
static void fimd_apply(struct device *subdrv_dev)
{
struct fimd_context *ctx = get_fimd_context(subdrv_dev);
struct exynos_drm_manager *mgr = ctx->subdrv.manager;
struct exynos_drm_manager_ops *mgr_ops = mgr->ops;
struct exynos_drm_overlay_ops *ovl_ops = mgr->overlay_ops;
struct fimd_win_data *win_data;
int i;
DRM_DEBUG_KMS("%s\n", __FILE__);
for (i = 0; i < WINDOWS_NR; i++) {
win_data = &ctx->win_data[i];
if (win_data->enabled && (ovl_ops && ovl_ops->commit))
ovl_ops->commit(subdrv_dev, i);
}
if (mgr_ops && mgr_ops->commit)
mgr_ops->commit(subdrv_dev);
}
static void fimd_commit(struct device *dev)
{
struct fimd_context *ctx = get_fimd_context(dev);
struct exynos_drm_panel_info *panel = ctx->panel;
struct fb_videomode *timing = &panel->timing;
struct fimd_driver_data *driver_data;
struct platform_device *pdev = to_platform_device(dev);
u32 val;
driver_data = drm_fimd_get_driver_data(pdev);
if (ctx->suspended)
return;
DRM_DEBUG_KMS("%s\n", __FILE__);
writel(ctx->vidcon1, ctx->regs + driver_data->timing_base + VIDCON1);
val = VIDTCON0_VBPD(timing->upper_margin - 1) |
VIDTCON0_VFPD(timing->lower_margin - 1) |
VIDTCON0_VSPW(timing->vsync_len - 1);
writel(val, ctx->regs + driver_data->timing_base + VIDTCON0);
val = VIDTCON1_HBPD(timing->left_margin - 1) |
VIDTCON1_HFPD(timing->right_margin - 1) |
VIDTCON1_HSPW(timing->hsync_len - 1);
writel(val, ctx->regs + driver_data->timing_base + VIDTCON1);
val = VIDTCON2_LINEVAL(timing->yres - 1) |
VIDTCON2_HOZVAL(timing->xres - 1) |
VIDTCON2_LINEVAL_E(timing->yres - 1) |
VIDTCON2_HOZVAL_E(timing->xres - 1);
writel(val, ctx->regs + driver_data->timing_base + VIDTCON2);
val = ctx->vidcon0;
val &= ~(VIDCON0_CLKVAL_F_MASK | VIDCON0_CLKDIR);
if (ctx->clkdiv > 1)
val |= VIDCON0_CLKVAL_F(ctx->clkdiv - 1) | VIDCON0_CLKDIR;
else
val &= ~VIDCON0_CLKDIR;
val |= VIDCON0_ENVID | VIDCON0_ENVID_F;
writel(val, ctx->regs + VIDCON0);
}
static int fimd_enable_vblank(struct device *dev)
{
struct fimd_context *ctx = get_fimd_context(dev);
u32 val;
DRM_DEBUG_KMS("%s\n", __FILE__);
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
static void fimd_disable_vblank(struct device *dev)
{
struct fimd_context *ctx = get_fimd_context(dev);
u32 val;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (ctx->suspended)
return;
if (test_and_clear_bit(0, &ctx->irq_flags)) {
val = readl(ctx->regs + VIDINTCON0);
val &= ~VIDINTCON0_INT_FRAME;
val &= ~VIDINTCON0_INT_ENABLE;
writel(val, ctx->regs + VIDINTCON0);
}
}
static void fimd_wait_for_vblank(struct device *dev)
{
struct fimd_context *ctx = get_fimd_context(dev);
if (ctx->suspended)
return;
atomic_set(&ctx->wait_vsync_event, 1);
if (!wait_event_timeout(ctx->wait_vsync_queue,
!atomic_read(&ctx->wait_vsync_event),
DRM_HZ/20))
DRM_DEBUG_KMS("vblank wait timed out.\n");
}
static void fimd_win_mode_set(struct device *dev,
struct exynos_drm_overlay *overlay)
{
struct fimd_context *ctx = get_fimd_context(dev);
struct fimd_win_data *win_data;
int win;
unsigned long offset;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (!overlay) {
dev_err(dev, "overlay is NULL\n");
return;
}
win = overlay->zpos;
if (win == DEFAULT_ZPOS)
win = ctx->default_win;
if (win < 0 || win > WINDOWS_NR)
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
static void fimd_win_set_pixfmt(struct device *dev, unsigned int win)
{
struct fimd_context *ctx = get_fimd_context(dev);
struct fimd_win_data *win_data = &ctx->win_data[win];
unsigned long val;
DRM_DEBUG_KMS("%s\n", __FILE__);
val = WINCONx_ENWIN;
switch (win_data->bpp) {
case 1:
val |= WINCON0_BPPMODE_1BPP;
val |= WINCONx_BITSWP;
val |= WINCONx_BURSTLEN_4WORD;
break;
case 2:
val |= WINCON0_BPPMODE_2BPP;
val |= WINCONx_BITSWP;
val |= WINCONx_BURSTLEN_8WORD;
break;
case 4:
val |= WINCON0_BPPMODE_4BPP;
val |= WINCONx_BITSWP;
val |= WINCONx_BURSTLEN_8WORD;
break;
case 8:
val |= WINCON0_BPPMODE_8BPP_PALETTE;
val |= WINCONx_BURSTLEN_8WORD;
val |= WINCONx_BYTSWP;
break;
case 16:
val |= WINCON0_BPPMODE_16BPP_565;
val |= WINCONx_HAWSWP;
val |= WINCONx_BURSTLEN_16WORD;
break;
case 24:
val |= WINCON0_BPPMODE_24BPP_888;
val |= WINCONx_WSWP;
val |= WINCONx_BURSTLEN_16WORD;
break;
case 32:
val |= WINCON1_BPPMODE_28BPP_A4888
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
static void fimd_win_set_colkey(struct device *dev, unsigned int win)
{
struct fimd_context *ctx = get_fimd_context(dev);
unsigned int keycon0 = 0, keycon1 = 0;
DRM_DEBUG_KMS("%s\n", __FILE__);
keycon0 = ~(WxKEYCON0_KEYBL_EN | WxKEYCON0_KEYEN_F |
WxKEYCON0_DIRCON) | WxKEYCON0_COMPKEY(0);
keycon1 = WxKEYCON1_COLVAL(0xffffffff);
writel(keycon0, ctx->regs + WKEYCON0_BASE(win));
writel(keycon1, ctx->regs + WKEYCON1_BASE(win));
}
static void fimd_win_commit(struct device *dev, int zpos)
{
struct fimd_context *ctx = get_fimd_context(dev);
struct fimd_win_data *win_data;
int win = zpos;
unsigned long val, alpha, size;
unsigned int last_x;
unsigned int last_y;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (ctx->suspended)
return;
if (win == DEFAULT_ZPOS)
win = ctx->default_win;
if (win < 0 || win > WINDOWS_NR)
return;
win_data = &ctx->win_data[win];
val = readl(ctx->regs + SHADOWCON);
val |= SHADOWCON_WINx_PROTECT(win);
writel(val, ctx->regs + SHADOWCON);
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
offset = VIDOSD_C_SIZE_W0;
val = win_data->ovl_width * win_data->ovl_height;
writel(val, ctx->regs + offset);
DRM_DEBUG_KMS("osd size = 0x%x\n", (unsigned int)val);
}
fimd_win_set_pixfmt(dev, win);
if (win != 0)
fimd_win_set_colkey(dev, win);
val = readl(ctx->regs + WINCON(win));
val |= WINCONx_ENWIN;
writel(val, ctx->regs + WINCON(win));
val = readl(ctx->regs + SHADOWCON);
val |= SHADOWCON_CHx_ENABLE(win);
val &= ~SHADOWCON_WINx_PROTECT(win);
writel(val, ctx->regs + SHADOWCON);
win_data->enabled = true;
}
static void fimd_win_disable(struct device *dev, int zpos)
{
struct fimd_context *ctx = get_fimd_context(dev);
struct fimd_win_data *win_data;
int win = zpos;
u32 val;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (win == DEFAULT_ZPOS)
win = ctx->default_win;
if (win < 0 || win > WINDOWS_NR)
return;
win_data = &ctx->win_data[win];
if (ctx->suspended) {
win_data->resume = false;
return;
}
val = readl(ctx->regs + SHADOWCON);
val |= SHADOWCON_WINx_PROTECT(win);
writel(val, ctx->regs + SHADOWCON);
val = readl(ctx->regs + WINCON(win));
val &= ~WINCONx_ENWIN;
writel(val, ctx->regs + WINCON(win));
val = readl(ctx->regs + SHADOWCON);
val &= ~SHADOWCON_CHx_ENABLE(win);
val &= ~SHADOWCON_WINx_PROTECT(win);
writel(val, ctx->regs + SHADOWCON);
win_data->enabled = false;
}
static irqreturn_t fimd_irq_handler(int irq, void *dev_id)
{
struct fimd_context *ctx = (struct fimd_context *)dev_id;
struct exynos_drm_subdrv *subdrv = &ctx->subdrv;
struct drm_device *drm_dev = subdrv->drm_dev;
struct exynos_drm_manager *manager = subdrv->manager;
u32 val;
val = readl(ctx->regs + VIDINTCON1);
if (val & VIDINTCON1_INT_FRAME)
writel(VIDINTCON1_INT_FRAME, ctx->regs + VIDINTCON1);
if (manager->pipe < 0)
goto out;
drm_handle_vblank(drm_dev, manager->pipe);
exynos_drm_crtc_finish_pageflip(drm_dev, manager->pipe);
if (atomic_read(&ctx->wait_vsync_event)) {
atomic_set(&ctx->wait_vsync_event, 0);
DRM_WAKEUP(&ctx->wait_vsync_queue);
}
out:
return IRQ_HANDLED;
}
static int fimd_subdrv_probe(struct drm_device *drm_dev, struct device *dev)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
drm_dev->irq_enabled = 1;
drm_dev->vblank_disable_allowed = 1;
if (is_drm_iommu_supported(drm_dev))
drm_iommu_attach_device(drm_dev, dev);
return 0;
}
static void fimd_subdrv_remove(struct drm_device *drm_dev, struct device *dev)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
if (is_drm_iommu_supported(drm_dev))
drm_iommu_detach_device(drm_dev, dev);
}
static int fimd_calc_clkdiv(struct fimd_context *ctx,
struct fb_videomode *timing)
{
unsigned long clk = clk_get_rate(ctx->lcd_clk);
u32 retrace;
u32 clkdiv;
u32 best_framerate = 0;
u32 framerate;
DRM_DEBUG_KMS("%s\n", __FILE__);
retrace = timing->left_margin + timing->hsync_len +
timing->right_margin + timing->xres;
retrace *= timing->upper_margin + timing->vsync_len +
timing->lower_margin + timing->yres;
if (!timing->refresh)
timing->refresh = 60;
clk /= retrace;
for (clkdiv = 1; clkdiv < 0x100; clkdiv++) {
int tmp;
framerate = clk / clkdiv;
tmp = timing->refresh - framerate;
if (tmp < 0) {
best_framerate = framerate;
continue;
} else {
if (!best_framerate)
best_framerate = framerate;
else if (tmp < (best_framerate - framerate))
best_framerate = framerate;
break;
}
}
return clkdiv;
}
static void fimd_clear_win(struct fimd_context *ctx, int win)
{
u32 val;
DRM_DEBUG_KMS("%s\n", __FILE__);
writel(0, ctx->regs + WINCON(win));
writel(0, ctx->regs + VIDOSD_A(win));
writel(0, ctx->regs + VIDOSD_B(win));
writel(0, ctx->regs + VIDOSD_C(win));
if (win == 1 || win == 2)
writel(0, ctx->regs + VIDOSD_D(win));
val = readl(ctx->regs + SHADOWCON);
val &= ~SHADOWCON_WINx_PROTECT(win);
writel(val, ctx->regs + SHADOWCON);
}
static int fimd_clock(struct fimd_context *ctx, bool enable)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
if (enable) {
int ret;
ret = clk_enable(ctx->bus_clk);
if (ret < 0)
return ret;
ret = clk_enable(ctx->lcd_clk);
if (ret < 0) {
clk_disable(ctx->bus_clk);
return ret;
}
} else {
clk_disable(ctx->lcd_clk);
clk_disable(ctx->bus_clk);
}
return 0;
}
static void fimd_window_suspend(struct device *dev)
{
struct fimd_context *ctx = get_fimd_context(dev);
struct fimd_win_data *win_data;
int i;
for (i = 0; i < WINDOWS_NR; i++) {
win_data = &ctx->win_data[i];
win_data->resume = win_data->enabled;
fimd_win_disable(dev, i);
}
fimd_wait_for_vblank(dev);
}
static void fimd_window_resume(struct device *dev)
{
struct fimd_context *ctx = get_fimd_context(dev);
struct fimd_win_data *win_data;
int i;
for (i = 0; i < WINDOWS_NR; i++) {
win_data = &ctx->win_data[i];
win_data->enabled = win_data->resume;
win_data->resume = false;
}
}
static int fimd_activate(struct fimd_context *ctx, bool enable)
{
struct device *dev = ctx->subdrv.dev;
if (enable) {
int ret;
ret = fimd_clock(ctx, true);
if (ret < 0)
return ret;
ctx->suspended = false;
if (test_and_clear_bit(0, &ctx->irq_flags))
fimd_enable_vblank(dev);
fimd_window_resume(dev);
} else {
fimd_window_suspend(dev);
fimd_clock(ctx, false);
ctx->suspended = true;
}
return 0;
}
static int fimd_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct fimd_context *ctx;
struct exynos_drm_subdrv *subdrv;
struct exynos_drm_fimd_pdata *pdata;
struct exynos_drm_panel_info *panel;
struct resource *res;
int win;
int ret = -EINVAL;
DRM_DEBUG_KMS("%s\n", __FILE__);
pdata = pdev->dev.platform_data;
if (!pdata) {
dev_err(dev, "no platform data specified\n");
return -EINVAL;
}
panel = &pdata->panel;
if (!panel) {
dev_err(dev, "panel is null.\n");
return -EINVAL;
}
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
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
ctx->regs = devm_request_and_ioremap(&pdev->dev, res);
if (!ctx->regs) {
dev_err(dev, "failed to map registers\n");
return -ENXIO;
}
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_err(dev, "irq request failed.\n");
return -ENXIO;
}
ctx->irq = res->start;
ret = devm_request_irq(&pdev->dev, ctx->irq, fimd_irq_handler,
0, "drm_fimd", ctx);
if (ret) {
dev_err(dev, "irq request failed.\n");
return ret;
}
ctx->vidcon0 = pdata->vidcon0;
ctx->vidcon1 = pdata->vidcon1;
ctx->default_win = pdata->default_win;
ctx->panel = panel;
DRM_INIT_WAITQUEUE(&ctx->wait_vsync_queue);
atomic_set(&ctx->wait_vsync_event, 0);
subdrv = &ctx->subdrv;
subdrv->dev = dev;
subdrv->manager = &fimd_manager;
subdrv->probe = fimd_subdrv_probe;
subdrv->remove = fimd_subdrv_remove;
mutex_init(&ctx->lock);
platform_set_drvdata(pdev, ctx);
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
ctx->clkdiv = fimd_calc_clkdiv(ctx, &panel->timing);
panel->timing.pixclock = clk_get_rate(ctx->lcd_clk) / ctx->clkdiv;
DRM_DEBUG_KMS("pixel clock = %d, clkdiv = %d\n",
panel->timing.pixclock, ctx->clkdiv);
for (win = 0; win < WINDOWS_NR; win++)
fimd_clear_win(ctx, win);
exynos_drm_subdrv_register(subdrv);
return 0;
}
static int fimd_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct fimd_context *ctx = platform_get_drvdata(pdev);
DRM_DEBUG_KMS("%s\n", __FILE__);
exynos_drm_subdrv_unregister(&ctx->subdrv);
if (ctx->suspended)
goto out;
clk_disable(ctx->lcd_clk);
clk_disable(ctx->bus_clk);
pm_runtime_set_suspended(dev);
pm_runtime_put_sync(dev);
out:
pm_runtime_disable(dev);
return 0;
}
static int fimd_suspend(struct device *dev)
{
struct fimd_context *ctx = get_fimd_context(dev);
if (!pm_runtime_suspended(dev))
return fimd_activate(ctx, false);
return 0;
}
static int fimd_resume(struct device *dev)
{
struct fimd_context *ctx = get_fimd_context(dev);
if (!pm_runtime_suspended(dev)) {
int ret;
ret = fimd_activate(ctx, true);
if (ret < 0)
return ret;
fimd_apply(dev);
}
return 0;
}
static int fimd_runtime_suspend(struct device *dev)
{
struct fimd_context *ctx = get_fimd_context(dev);
DRM_DEBUG_KMS("%s\n", __FILE__);
return fimd_activate(ctx, false);
}
static int fimd_runtime_resume(struct device *dev)
{
struct fimd_context *ctx = get_fimd_context(dev);
DRM_DEBUG_KMS("%s\n", __FILE__);
return fimd_activate(ctx, true);
}
