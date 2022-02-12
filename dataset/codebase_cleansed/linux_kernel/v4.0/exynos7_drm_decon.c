static void decon_wait_for_vblank(struct exynos_drm_crtc *crtc)
{
struct decon_context *ctx = crtc->ctx;
if (ctx->suspended)
return;
atomic_set(&ctx->wait_vsync_event, 1);
if (!wait_event_timeout(ctx->wait_vsync_queue,
!atomic_read(&ctx->wait_vsync_event),
HZ/20))
DRM_DEBUG_KMS("vblank wait timed out.\n");
}
static void decon_clear_channel(struct decon_context *ctx)
{
int win, ch_enabled = 0;
DRM_DEBUG_KMS("%s\n", __FILE__);
for (win = 0; win < WINDOWS_NR; win++) {
u32 val = readl(ctx->regs + WINCON(win));
if (val & WINCONx_ENWIN) {
val &= ~WINCONx_ENWIN;
writel(val, ctx->regs + WINCON(win));
ch_enabled = 1;
}
}
if (ch_enabled) {
unsigned int state = ctx->suspended;
ctx->suspended = 0;
decon_wait_for_vblank(ctx->crtc);
ctx->suspended = state;
}
}
static int decon_ctx_initialize(struct decon_context *ctx,
struct drm_device *drm_dev)
{
struct exynos_drm_private *priv = drm_dev->dev_private;
ctx->drm_dev = drm_dev;
ctx->pipe = priv->pipe++;
if (is_drm_iommu_supported(ctx->drm_dev)) {
int ret;
decon_clear_channel(ctx);
ret = drm_iommu_attach_device(ctx->drm_dev, ctx->dev);
if (ret) {
DRM_ERROR("drm_iommu_attach failed.\n");
return ret;
}
}
return 0;
}
static void decon_ctx_remove(struct decon_context *ctx)
{
if (is_drm_iommu_supported(ctx->drm_dev))
drm_iommu_detach_device(ctx->drm_dev, ctx->dev);
}
static u32 decon_calc_clkdiv(struct decon_context *ctx,
const struct drm_display_mode *mode)
{
unsigned long ideal_clk = mode->htotal * mode->vtotal * mode->vrefresh;
u32 clkdiv;
clkdiv = DIV_ROUND_UP(clk_get_rate(ctx->vclk), ideal_clk);
return (clkdiv < 0x100) ? clkdiv : 0xff;
}
static bool decon_mode_fixup(struct exynos_drm_crtc *crtc,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
if (adjusted_mode->vrefresh == 0)
adjusted_mode->vrefresh = DECON_DEFAULT_FRAMERATE;
return true;
}
static void decon_commit(struct exynos_drm_crtc *crtc)
{
struct decon_context *ctx = crtc->ctx;
struct drm_display_mode *mode = &crtc->base.mode;
u32 val, clkdiv;
if (ctx->suspended)
return;
if (mode->htotal == 0 || mode->vtotal == 0)
return;
if (!ctx->i80_if) {
int vsync_len, vbpd, vfpd, hsync_len, hbpd, hfpd;
vsync_len = mode->crtc_vsync_end - mode->crtc_vsync_start;
vbpd = mode->crtc_vtotal - mode->crtc_vsync_end;
vfpd = mode->crtc_vsync_start - mode->crtc_vdisplay;
val = VIDTCON0_VBPD(vbpd - 1) | VIDTCON0_VFPD(vfpd - 1);
writel(val, ctx->regs + VIDTCON0);
val = VIDTCON1_VSPW(vsync_len - 1);
writel(val, ctx->regs + VIDTCON1);
hsync_len = mode->crtc_hsync_end - mode->crtc_hsync_start;
hbpd = mode->crtc_htotal - mode->crtc_hsync_end;
hfpd = mode->crtc_hsync_start - mode->crtc_hdisplay;
val = VIDTCON2_HBPD(hbpd - 1) | VIDTCON2_HFPD(hfpd - 1);
writel(val, ctx->regs + VIDTCON2);
val = VIDTCON3_HSPW(hsync_len - 1);
writel(val, ctx->regs + VIDTCON3);
}
val = VIDTCON4_LINEVAL(mode->vdisplay - 1) |
VIDTCON4_HOZVAL(mode->hdisplay - 1);
writel(val, ctx->regs + VIDTCON4);
writel(mode->vdisplay - 1, ctx->regs + LINECNT_OP_THRESHOLD);
val = VIDCON0_ENVID | VIDCON0_ENVID_F;
writel(val, ctx->regs + VIDCON0);
clkdiv = decon_calc_clkdiv(ctx, mode);
if (clkdiv > 1) {
val = VCLKCON1_CLKVAL_NUM_VCLK(clkdiv - 1);
writel(val, ctx->regs + VCLKCON1);
writel(val, ctx->regs + VCLKCON2);
}
val = readl(ctx->regs + DECON_UPDATE);
val |= DECON_UPDATE_STANDALONE_F;
writel(val, ctx->regs + DECON_UPDATE);
}
static int decon_enable_vblank(struct exynos_drm_crtc *crtc)
{
struct decon_context *ctx = crtc->ctx;
u32 val;
if (ctx->suspended)
return -EPERM;
if (!test_and_set_bit(0, &ctx->irq_flags)) {
val = readl(ctx->regs + VIDINTCON0);
val |= VIDINTCON0_INT_ENABLE;
if (!ctx->i80_if) {
val |= VIDINTCON0_INT_FRAME;
val &= ~VIDINTCON0_FRAMESEL0_MASK;
val |= VIDINTCON0_FRAMESEL0_VSYNC;
}
writel(val, ctx->regs + VIDINTCON0);
}
return 0;
}
static void decon_disable_vblank(struct exynos_drm_crtc *crtc)
{
struct decon_context *ctx = crtc->ctx;
u32 val;
if (ctx->suspended)
return;
if (test_and_clear_bit(0, &ctx->irq_flags)) {
val = readl(ctx->regs + VIDINTCON0);
val &= ~VIDINTCON0_INT_ENABLE;
if (!ctx->i80_if)
val &= ~VIDINTCON0_INT_FRAME;
writel(val, ctx->regs + VIDINTCON0);
}
}
static void decon_win_mode_set(struct exynos_drm_crtc *crtc,
struct exynos_drm_plane *plane)
{
struct decon_context *ctx = crtc->ctx;
struct decon_win_data *win_data;
int win, padding;
if (!plane) {
DRM_ERROR("plane is NULL\n");
return;
}
win = plane->zpos;
if (win == DEFAULT_ZPOS)
win = ctx->default_win;
if (win < 0 || win >= WINDOWS_NR)
return;
win_data = &ctx->win_data[win];
padding = (plane->pitch / (plane->bpp >> 3)) - plane->fb_width;
win_data->offset_x = plane->fb_x;
win_data->offset_y = plane->fb_y;
win_data->fb_width = plane->fb_width + padding;
win_data->fb_height = plane->fb_height;
win_data->ovl_x = plane->crtc_x;
win_data->ovl_y = plane->crtc_y;
win_data->ovl_width = plane->crtc_width;
win_data->ovl_height = plane->crtc_height;
win_data->dma_addr = plane->dma_addr[0];
win_data->bpp = plane->bpp;
win_data->pixel_format = plane->pixel_format;
DRM_DEBUG_KMS("offset_x = %d, offset_y = %d\n",
win_data->offset_x, win_data->offset_y);
DRM_DEBUG_KMS("ovl_width = %d, ovl_height = %d\n",
win_data->ovl_width, win_data->ovl_height);
DRM_DEBUG_KMS("paddr = 0x%lx\n", (unsigned long)win_data->dma_addr);
DRM_DEBUG_KMS("fb_width = %d, crtc_width = %d\n",
plane->fb_width, plane->crtc_width);
}
static void decon_win_set_pixfmt(struct decon_context *ctx, unsigned int win)
{
struct decon_win_data *win_data = &ctx->win_data[win];
unsigned long val;
val = readl(ctx->regs + WINCON(win));
val &= ~WINCONx_BPPMODE_MASK;
switch (win_data->pixel_format) {
case DRM_FORMAT_RGB565:
val |= WINCONx_BPPMODE_16BPP_565;
val |= WINCONx_BURSTLEN_16WORD;
break;
case DRM_FORMAT_XRGB8888:
val |= WINCONx_BPPMODE_24BPP_xRGB;
val |= WINCONx_BURSTLEN_16WORD;
break;
case DRM_FORMAT_XBGR8888:
val |= WINCONx_BPPMODE_24BPP_xBGR;
val |= WINCONx_BURSTLEN_16WORD;
break;
case DRM_FORMAT_RGBX8888:
val |= WINCONx_BPPMODE_24BPP_RGBx;
val |= WINCONx_BURSTLEN_16WORD;
break;
case DRM_FORMAT_BGRX8888:
val |= WINCONx_BPPMODE_24BPP_BGRx;
val |= WINCONx_BURSTLEN_16WORD;
break;
case DRM_FORMAT_ARGB8888:
val |= WINCONx_BPPMODE_32BPP_ARGB | WINCONx_BLD_PIX |
WINCONx_ALPHA_SEL;
val |= WINCONx_BURSTLEN_16WORD;
break;
case DRM_FORMAT_ABGR8888:
val |= WINCONx_BPPMODE_32BPP_ABGR | WINCONx_BLD_PIX |
WINCONx_ALPHA_SEL;
val |= WINCONx_BURSTLEN_16WORD;
break;
case DRM_FORMAT_RGBA8888:
val |= WINCONx_BPPMODE_32BPP_RGBA | WINCONx_BLD_PIX |
WINCONx_ALPHA_SEL;
val |= WINCONx_BURSTLEN_16WORD;
break;
case DRM_FORMAT_BGRA8888:
val |= WINCONx_BPPMODE_32BPP_BGRA | WINCONx_BLD_PIX |
WINCONx_ALPHA_SEL;
val |= WINCONx_BURSTLEN_16WORD;
break;
default:
DRM_DEBUG_KMS("invalid pixel size so using unpacked 24bpp.\n");
val |= WINCONx_BPPMODE_24BPP_xRGB;
val |= WINCONx_BURSTLEN_16WORD;
break;
}
DRM_DEBUG_KMS("bpp = %d\n", win_data->bpp);
if (win_data->fb_width < MIN_FB_WIDTH_FOR_16WORD_BURST) {
val &= ~WINCONx_BURSTLEN_MASK;
val |= WINCONx_BURSTLEN_8WORD;
}
writel(val, ctx->regs + WINCON(win));
}
static void decon_win_set_colkey(struct decon_context *ctx, unsigned int win)
{
unsigned int keycon0 = 0, keycon1 = 0;
keycon0 = ~(WxKEYCON0_KEYBL_EN | WxKEYCON0_KEYEN_F |
WxKEYCON0_DIRCON) | WxKEYCON0_COMPKEY(0);
keycon1 = WxKEYCON1_COLVAL(0xffffffff);
writel(keycon0, ctx->regs + WKEYCON0_BASE(win));
writel(keycon1, ctx->regs + WKEYCON1_BASE(win));
}
static void decon_shadow_protect_win(struct decon_context *ctx,
int win, bool protect)
{
u32 bits, val;
bits = SHADOWCON_WINx_PROTECT(win);
val = readl(ctx->regs + SHADOWCON);
if (protect)
val |= bits;
else
val &= ~bits;
writel(val, ctx->regs + SHADOWCON);
}
static void decon_win_commit(struct exynos_drm_crtc *crtc, int zpos)
{
struct decon_context *ctx = crtc->ctx;
struct drm_display_mode *mode = &crtc->base.mode;
struct decon_win_data *win_data;
int win = zpos;
unsigned long val, alpha;
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
decon_shadow_protect_win(ctx, win, true);
val = (unsigned long)win_data->dma_addr;
writel(val, ctx->regs + VIDW_BUF_START(win));
writel(win_data->fb_width, ctx->regs + VIDW_WHOLE_X(win));
writel(win_data->fb_height, ctx->regs + VIDW_WHOLE_Y(win));
writel(win_data->offset_x, ctx->regs + VIDW_OFFSET_X(win));
writel(win_data->offset_y, ctx->regs + VIDW_OFFSET_Y(win));
DRM_DEBUG_KMS("start addr = 0x%lx\n",
(unsigned long)win_data->dma_addr);
DRM_DEBUG_KMS("ovl_width = %d, ovl_height = %d\n",
win_data->ovl_width, win_data->ovl_height);
if ((win_data->ovl_x + win_data->ovl_width) > mode->hdisplay)
win_data->ovl_x = mode->hdisplay - win_data->ovl_width;
if ((win_data->ovl_y + win_data->ovl_height) > mode->vdisplay)
win_data->ovl_y = mode->vdisplay - win_data->ovl_height;
val = VIDOSDxA_TOPLEFT_X(win_data->ovl_x) |
VIDOSDxA_TOPLEFT_Y(win_data->ovl_y);
writel(val, ctx->regs + VIDOSD_A(win));
last_x = win_data->ovl_x + win_data->ovl_width;
if (last_x)
last_x--;
last_y = win_data->ovl_y + win_data->ovl_height;
if (last_y)
last_y--;
val = VIDOSDxB_BOTRIGHT_X(last_x) | VIDOSDxB_BOTRIGHT_Y(last_y);
writel(val, ctx->regs + VIDOSD_B(win));
DRM_DEBUG_KMS("osd pos: tx = %d, ty = %d, bx = %d, by = %d\n",
win_data->ovl_x, win_data->ovl_y, last_x, last_y);
alpha = VIDOSDxC_ALPHA0_R_F(0x0) |
VIDOSDxC_ALPHA0_G_F(0x0) |
VIDOSDxC_ALPHA0_B_F(0x0);
writel(alpha, ctx->regs + VIDOSD_C(win));
alpha = VIDOSDxD_ALPHA1_R_F(0xff) |
VIDOSDxD_ALPHA1_G_F(0xff) |
VIDOSDxD_ALPHA1_B_F(0xff);
writel(alpha, ctx->regs + VIDOSD_D(win));
decon_win_set_pixfmt(ctx, win);
if (win != 0)
decon_win_set_colkey(ctx, win);
val = readl(ctx->regs + WINCON(win));
val |= WINCONx_TRIPLE_BUF_MODE;
val |= WINCONx_ENWIN;
writel(val, ctx->regs + WINCON(win));
decon_shadow_protect_win(ctx, win, false);
val = readl(ctx->regs + DECON_UPDATE);
val |= DECON_UPDATE_STANDALONE_F;
writel(val, ctx->regs + DECON_UPDATE);
win_data->enabled = true;
}
static void decon_win_disable(struct exynos_drm_crtc *crtc, int zpos)
{
struct decon_context *ctx = crtc->ctx;
struct decon_win_data *win_data;
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
decon_shadow_protect_win(ctx, win, true);
val = readl(ctx->regs + WINCON(win));
val &= ~WINCONx_ENWIN;
writel(val, ctx->regs + WINCON(win));
decon_shadow_protect_win(ctx, win, false);
val = readl(ctx->regs + DECON_UPDATE);
val |= DECON_UPDATE_STANDALONE_F;
writel(val, ctx->regs + DECON_UPDATE);
win_data->enabled = false;
}
static void decon_window_suspend(struct decon_context *ctx)
{
struct decon_win_data *win_data;
int i;
for (i = 0; i < WINDOWS_NR; i++) {
win_data = &ctx->win_data[i];
win_data->resume = win_data->enabled;
if (win_data->enabled)
decon_win_disable(ctx->crtc, i);
}
}
static void decon_window_resume(struct decon_context *ctx)
{
struct decon_win_data *win_data;
int i;
for (i = 0; i < WINDOWS_NR; i++) {
win_data = &ctx->win_data[i];
win_data->enabled = win_data->resume;
win_data->resume = false;
}
}
static void decon_apply(struct decon_context *ctx)
{
struct decon_win_data *win_data;
int i;
for (i = 0; i < WINDOWS_NR; i++) {
win_data = &ctx->win_data[i];
if (win_data->enabled)
decon_win_commit(ctx->crtc, i);
else
decon_win_disable(ctx->crtc, i);
}
decon_commit(ctx->crtc);
}
static void decon_init(struct decon_context *ctx)
{
u32 val;
writel(VIDCON0_SWRESET, ctx->regs + VIDCON0);
val = VIDOUTCON0_DISP_IF_0_ON;
if (!ctx->i80_if)
val |= VIDOUTCON0_RGBIF;
writel(val, ctx->regs + VIDOUTCON0);
writel(VCLKCON0_CLKVALUP | VCLKCON0_VCLKFREE, ctx->regs + VCLKCON0);
if (!ctx->i80_if)
writel(VIDCON1_VCLK_HOLD, ctx->regs + VIDCON1(0));
}
static int decon_poweron(struct decon_context *ctx)
{
int ret;
if (!ctx->suspended)
return 0;
ctx->suspended = false;
pm_runtime_get_sync(ctx->dev);
ret = clk_prepare_enable(ctx->pclk);
if (ret < 0) {
DRM_ERROR("Failed to prepare_enable the pclk [%d]\n", ret);
goto pclk_err;
}
ret = clk_prepare_enable(ctx->aclk);
if (ret < 0) {
DRM_ERROR("Failed to prepare_enable the aclk [%d]\n", ret);
goto aclk_err;
}
ret = clk_prepare_enable(ctx->eclk);
if (ret < 0) {
DRM_ERROR("Failed to prepare_enable the eclk [%d]\n", ret);
goto eclk_err;
}
ret = clk_prepare_enable(ctx->vclk);
if (ret < 0) {
DRM_ERROR("Failed to prepare_enable the vclk [%d]\n", ret);
goto vclk_err;
}
decon_init(ctx);
if (test_and_clear_bit(0, &ctx->irq_flags)) {
ret = decon_enable_vblank(ctx->crtc);
if (ret) {
DRM_ERROR("Failed to re-enable vblank [%d]\n", ret);
goto err;
}
}
decon_window_resume(ctx);
decon_apply(ctx);
return 0;
err:
clk_disable_unprepare(ctx->vclk);
vclk_err:
clk_disable_unprepare(ctx->eclk);
eclk_err:
clk_disable_unprepare(ctx->aclk);
aclk_err:
clk_disable_unprepare(ctx->pclk);
pclk_err:
ctx->suspended = true;
return ret;
}
static int decon_poweroff(struct decon_context *ctx)
{
if (ctx->suspended)
return 0;
decon_window_suspend(ctx);
clk_disable_unprepare(ctx->vclk);
clk_disable_unprepare(ctx->eclk);
clk_disable_unprepare(ctx->aclk);
clk_disable_unprepare(ctx->pclk);
pm_runtime_put_sync(ctx->dev);
ctx->suspended = true;
return 0;
}
static void decon_dpms(struct exynos_drm_crtc *crtc, int mode)
{
DRM_DEBUG_KMS("%s, %d\n", __FILE__, mode);
switch (mode) {
case DRM_MODE_DPMS_ON:
decon_poweron(crtc->ctx);
break;
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
case DRM_MODE_DPMS_OFF:
decon_poweroff(crtc->ctx);
break;
default:
DRM_DEBUG_KMS("unspecified mode %d\n", mode);
break;
}
}
static irqreturn_t decon_irq_handler(int irq, void *dev_id)
{
struct decon_context *ctx = (struct decon_context *)dev_id;
u32 val, clear_bit;
val = readl(ctx->regs + VIDINTCON1);
clear_bit = ctx->i80_if ? VIDINTCON1_INT_I80 : VIDINTCON1_INT_FRAME;
if (val & clear_bit)
writel(clear_bit, ctx->regs + VIDINTCON1);
if (ctx->pipe < 0 || !ctx->drm_dev)
goto out;
if (!ctx->i80_if) {
drm_handle_vblank(ctx->drm_dev, ctx->pipe);
exynos_drm_crtc_finish_pageflip(ctx->drm_dev, ctx->pipe);
if (atomic_read(&ctx->wait_vsync_event)) {
atomic_set(&ctx->wait_vsync_event, 0);
wake_up(&ctx->wait_vsync_queue);
}
}
out:
return IRQ_HANDLED;
}
static int decon_bind(struct device *dev, struct device *master, void *data)
{
struct decon_context *ctx = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
int ret;
ret = decon_ctx_initialize(ctx, drm_dev);
if (ret) {
DRM_ERROR("decon_ctx_initialize failed.\n");
return ret;
}
ctx->crtc = exynos_drm_crtc_create(drm_dev, ctx->pipe,
EXYNOS_DISPLAY_TYPE_LCD,
&decon_crtc_ops, ctx);
if (IS_ERR(ctx->crtc)) {
decon_ctx_remove(ctx);
return PTR_ERR(ctx->crtc);
}
if (ctx->display)
exynos_drm_create_enc_conn(drm_dev, ctx->display);
return 0;
}
static void decon_unbind(struct device *dev, struct device *master,
void *data)
{
struct decon_context *ctx = dev_get_drvdata(dev);
decon_dpms(ctx->crtc, DRM_MODE_DPMS_OFF);
if (ctx->display)
exynos_dpi_remove(ctx->display);
decon_ctx_remove(ctx);
}
static int decon_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct decon_context *ctx;
struct device_node *i80_if_timings;
struct resource *res;
int ret;
if (!dev->of_node)
return -ENODEV;
ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ret = exynos_drm_component_add(dev, EXYNOS_DEVICE_TYPE_CRTC,
EXYNOS_DISPLAY_TYPE_LCD);
if (ret)
return ret;
ctx->dev = dev;
ctx->suspended = true;
i80_if_timings = of_get_child_by_name(dev->of_node, "i80-if-timings");
if (i80_if_timings)
ctx->i80_if = true;
of_node_put(i80_if_timings);
ctx->regs = of_iomap(dev->of_node, 0);
if (!ctx->regs) {
ret = -ENOMEM;
goto err_del_component;
}
ctx->pclk = devm_clk_get(dev, "pclk_decon0");
if (IS_ERR(ctx->pclk)) {
dev_err(dev, "failed to get bus clock pclk\n");
ret = PTR_ERR(ctx->pclk);
goto err_iounmap;
}
ctx->aclk = devm_clk_get(dev, "aclk_decon0");
if (IS_ERR(ctx->aclk)) {
dev_err(dev, "failed to get bus clock aclk\n");
ret = PTR_ERR(ctx->aclk);
goto err_iounmap;
}
ctx->eclk = devm_clk_get(dev, "decon0_eclk");
if (IS_ERR(ctx->eclk)) {
dev_err(dev, "failed to get eclock\n");
ret = PTR_ERR(ctx->eclk);
goto err_iounmap;
}
ctx->vclk = devm_clk_get(dev, "decon0_vclk");
if (IS_ERR(ctx->vclk)) {
dev_err(dev, "failed to get vclock\n");
ret = PTR_ERR(ctx->vclk);
goto err_iounmap;
}
res = platform_get_resource_byname(pdev, IORESOURCE_IRQ,
ctx->i80_if ? "lcd_sys" : "vsync");
if (!res) {
dev_err(dev, "irq request failed.\n");
ret = -ENXIO;
goto err_iounmap;
}
ret = devm_request_irq(dev, res->start, decon_irq_handler,
0, "drm_decon", ctx);
if (ret) {
dev_err(dev, "irq request failed.\n");
goto err_iounmap;
}
init_waitqueue_head(&ctx->wait_vsync_queue);
atomic_set(&ctx->wait_vsync_event, 0);
platform_set_drvdata(pdev, ctx);
ctx->display = exynos_dpi_probe(dev);
if (IS_ERR(ctx->display)) {
ret = PTR_ERR(ctx->display);
goto err_iounmap;
}
pm_runtime_enable(dev);
ret = component_add(dev, &decon_component_ops);
if (ret)
goto err_disable_pm_runtime;
return ret;
err_disable_pm_runtime:
pm_runtime_disable(dev);
err_iounmap:
iounmap(ctx->regs);
err_del_component:
exynos_drm_component_del(dev, EXYNOS_DEVICE_TYPE_CRTC);
return ret;
}
static int decon_remove(struct platform_device *pdev)
{
struct decon_context *ctx = dev_get_drvdata(&pdev->dev);
pm_runtime_disable(&pdev->dev);
iounmap(ctx->regs);
component_del(&pdev->dev, &decon_component_ops);
exynos_drm_component_del(&pdev->dev, EXYNOS_DEVICE_TYPE_CRTC);
return 0;
}
