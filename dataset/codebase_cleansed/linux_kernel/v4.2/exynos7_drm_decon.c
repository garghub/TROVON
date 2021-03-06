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
static void decon_clear_channels(struct exynos_drm_crtc *crtc)
{
struct decon_context *ctx = crtc->ctx;
unsigned int win, ch_enabled = 0;
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
int ret;
ctx->drm_dev = drm_dev;
ctx->pipe = priv->pipe++;
ret = drm_iommu_attach_device_if_possible(ctx->crtc, drm_dev, ctx->dev);
if (ret)
priv->pipe--;
return ret;
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
struct drm_display_mode *mode = &crtc->base.state->adjusted_mode;
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
static void decon_win_set_pixfmt(struct decon_context *ctx, unsigned int win)
{
struct exynos_drm_plane *plane = &ctx->planes[win];
unsigned long val;
int padding;
val = readl(ctx->regs + WINCON(win));
val &= ~WINCONx_BPPMODE_MASK;
switch (plane->pixel_format) {
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
DRM_DEBUG_KMS("bpp = %d\n", plane->bpp);
padding = (plane->pitch / (plane->bpp >> 3)) - plane->fb_width;
if (plane->fb_width + padding < MIN_FB_WIDTH_FOR_16WORD_BURST) {
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
unsigned int win, bool protect)
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
static void decon_win_commit(struct exynos_drm_crtc *crtc, unsigned int win)
{
struct decon_context *ctx = crtc->ctx;
struct drm_display_mode *mode = &crtc->base.state->adjusted_mode;
struct exynos_drm_plane *plane;
int padding;
unsigned long val, alpha;
unsigned int last_x;
unsigned int last_y;
if (ctx->suspended)
return;
if (win < 0 || win >= WINDOWS_NR)
return;
plane = &ctx->planes[win];
if (ctx->suspended)
return;
decon_shadow_protect_win(ctx, win, true);
val = (unsigned long)plane->dma_addr[0];
writel(val, ctx->regs + VIDW_BUF_START(win));
padding = (plane->pitch / (plane->bpp >> 3)) - plane->fb_width;
writel(plane->fb_width + padding, ctx->regs + VIDW_WHOLE_X(win));
writel(plane->fb_height, ctx->regs + VIDW_WHOLE_Y(win));
writel(plane->src_x, ctx->regs + VIDW_OFFSET_X(win));
writel(plane->src_y, ctx->regs + VIDW_OFFSET_Y(win));
DRM_DEBUG_KMS("start addr = 0x%lx\n",
(unsigned long)val);
DRM_DEBUG_KMS("ovl_width = %d, ovl_height = %d\n",
plane->crtc_width, plane->crtc_height);
if ((plane->crtc_x + plane->crtc_width) > mode->hdisplay)
plane->crtc_x = mode->hdisplay - plane->crtc_width;
if ((plane->crtc_y + plane->crtc_height) > mode->vdisplay)
plane->crtc_y = mode->vdisplay - plane->crtc_height;
val = VIDOSDxA_TOPLEFT_X(plane->crtc_x) |
VIDOSDxA_TOPLEFT_Y(plane->crtc_y);
writel(val, ctx->regs + VIDOSD_A(win));
last_x = plane->crtc_x + plane->crtc_width;
if (last_x)
last_x--;
last_y = plane->crtc_y + plane->crtc_height;
if (last_y)
last_y--;
val = VIDOSDxB_BOTRIGHT_X(last_x) | VIDOSDxB_BOTRIGHT_Y(last_y);
writel(val, ctx->regs + VIDOSD_B(win));
DRM_DEBUG_KMS("osd pos: tx = %d, ty = %d, bx = %d, by = %d\n",
plane->crtc_x, plane->crtc_y, last_x, last_y);
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
}
static void decon_win_disable(struct exynos_drm_crtc *crtc, unsigned int win)
{
struct decon_context *ctx = crtc->ctx;
struct exynos_drm_plane *plane;
u32 val;
if (win < 0 || win >= WINDOWS_NR)
return;
plane = &ctx->planes[win];
if (ctx->suspended)
return;
decon_shadow_protect_win(ctx, win, true);
val = readl(ctx->regs + WINCON(win));
val &= ~WINCONx_ENWIN;
writel(val, ctx->regs + WINCON(win));
decon_shadow_protect_win(ctx, win, false);
val = readl(ctx->regs + DECON_UPDATE);
val |= DECON_UPDATE_STANDALONE_F;
writel(val, ctx->regs + DECON_UPDATE);
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
static void decon_enable(struct exynos_drm_crtc *crtc)
{
struct decon_context *ctx = crtc->ctx;
int ret;
if (!ctx->suspended)
return;
ctx->suspended = false;
pm_runtime_get_sync(ctx->dev);
ret = clk_prepare_enable(ctx->pclk);
if (ret < 0) {
DRM_ERROR("Failed to prepare_enable the pclk [%d]\n", ret);
return;
}
ret = clk_prepare_enable(ctx->aclk);
if (ret < 0) {
DRM_ERROR("Failed to prepare_enable the aclk [%d]\n", ret);
return;
}
ret = clk_prepare_enable(ctx->eclk);
if (ret < 0) {
DRM_ERROR("Failed to prepare_enable the eclk [%d]\n", ret);
return;
}
ret = clk_prepare_enable(ctx->vclk);
if (ret < 0) {
DRM_ERROR("Failed to prepare_enable the vclk [%d]\n", ret);
return;
}
decon_init(ctx);
if (test_and_clear_bit(0, &ctx->irq_flags))
decon_enable_vblank(ctx->crtc);
decon_commit(ctx->crtc);
}
static void decon_disable(struct exynos_drm_crtc *crtc)
{
struct decon_context *ctx = crtc->ctx;
int i;
if (ctx->suspended)
return;
for (i = 0; i < WINDOWS_NR; i++)
decon_win_disable(crtc, i);
clk_disable_unprepare(ctx->vclk);
clk_disable_unprepare(ctx->eclk);
clk_disable_unprepare(ctx->aclk);
clk_disable_unprepare(ctx->pclk);
pm_runtime_put_sync(ctx->dev);
ctx->suspended = true;
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
struct exynos_drm_plane *exynos_plane;
enum drm_plane_type type;
unsigned int zpos;
int ret;
ret = decon_ctx_initialize(ctx, drm_dev);
if (ret) {
DRM_ERROR("decon_ctx_initialize failed.\n");
return ret;
}
for (zpos = 0; zpos < WINDOWS_NR; zpos++) {
type = (zpos == ctx->default_win) ? DRM_PLANE_TYPE_PRIMARY :
DRM_PLANE_TYPE_OVERLAY;
ret = exynos_plane_init(drm_dev, &ctx->planes[zpos],
1 << ctx->pipe, type, zpos);
if (ret)
return ret;
}
exynos_plane = &ctx->planes[ctx->default_win];
ctx->crtc = exynos_drm_crtc_create(drm_dev, &exynos_plane->base,
ctx->pipe, EXYNOS_DISPLAY_TYPE_LCD,
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
decon_disable(ctx->crtc);
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
ctx->dev = dev;
ctx->suspended = true;
i80_if_timings = of_get_child_by_name(dev->of_node, "i80-if-timings");
if (i80_if_timings)
ctx->i80_if = true;
of_node_put(i80_if_timings);
ctx->regs = of_iomap(dev->of_node, 0);
if (!ctx->regs)
return -ENOMEM;
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
return ret;
}
static int decon_remove(struct platform_device *pdev)
{
struct decon_context *ctx = dev_get_drvdata(&pdev->dev);
pm_runtime_disable(&pdev->dev);
iounmap(ctx->regs);
component_del(&pdev->dev, &decon_component_ops);
return 0;
}
