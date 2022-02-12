static int decon_enable_vblank(struct exynos_drm_crtc *crtc)
{
struct decon_context *ctx = crtc->ctx;
u32 val;
if (ctx->suspended)
return -EPERM;
if (test_and_set_bit(0, &ctx->irq_flags)) {
val = VIDINTCON0_INTEN;
if (ctx->i80_if)
val |= VIDINTCON0_FRAMEDONE;
else
val |= VIDINTCON0_INTFRMEN;
writel(val, ctx->addr + DECON_VIDINTCON0);
}
return 0;
}
static void decon_disable_vblank(struct exynos_drm_crtc *crtc)
{
struct decon_context *ctx = crtc->ctx;
if (ctx->suspended)
return;
if (test_and_clear_bit(0, &ctx->irq_flags))
writel(0, ctx->addr + DECON_VIDINTCON0);
}
static void decon_setup_trigger(struct decon_context *ctx)
{
u32 val = TRIGCON_TRIGEN_PER_F | TRIGCON_TRIGEN_F |
TRIGCON_TE_AUTO_MASK | TRIGCON_SWTRIGEN;
writel(val, ctx->addr + DECON_TRIGCON);
}
static void decon_commit(struct exynos_drm_crtc *crtc)
{
struct decon_context *ctx = crtc->ctx;
struct drm_display_mode *mode = &crtc->base.mode;
u32 val;
if (ctx->suspended)
return;
val = CMU_CLKGAGE_MODE_SFR_F | CMU_CLKGAGE_MODE_MEM_F;
writel(val, ctx->addr + DECON_CMU);
val = VIDOUT_LCD_ON;
if (ctx->i80_if)
val |= VIDOUT_COMMAND_IF;
else
val |= VIDOUT_RGB_IF;
writel(val, ctx->addr + DECON_VIDOUTCON0);
val = VIDTCON2_LINEVAL(mode->vdisplay - 1) |
VIDTCON2_HOZVAL(mode->hdisplay - 1);
writel(val, ctx->addr + DECON_VIDTCON2);
if (!ctx->i80_if) {
val = VIDTCON00_VBPD_F(
mode->crtc_vtotal - mode->crtc_vsync_end) |
VIDTCON00_VFPD_F(
mode->crtc_vsync_start - mode->crtc_vdisplay);
writel(val, ctx->addr + DECON_VIDTCON00);
val = VIDTCON01_VSPW_F(
mode->crtc_vsync_end - mode->crtc_vsync_start);
writel(val, ctx->addr + DECON_VIDTCON01);
val = VIDTCON10_HBPD_F(
mode->crtc_htotal - mode->crtc_hsync_end) |
VIDTCON10_HFPD_F(
mode->crtc_hsync_start - mode->crtc_hdisplay);
writel(val, ctx->addr + DECON_VIDTCON10);
val = VIDTCON11_HSPW_F(
mode->crtc_hsync_end - mode->crtc_hsync_start);
writel(val, ctx->addr + DECON_VIDTCON11);
}
decon_setup_trigger(ctx);
val = VIDCON0_ENVID | VIDCON0_ENVID_F;
writel(val, ctx->addr + DECON_VIDCON0);
}
static void decon_win_set_pixfmt(struct decon_context *ctx, unsigned int win,
struct drm_framebuffer *fb)
{
unsigned long val;
val = readl(ctx->addr + DECON_WINCONx(win));
val &= ~WINCONx_BPPMODE_MASK;
switch (fb->pixel_format) {
case DRM_FORMAT_XRGB1555:
val |= WINCONx_BPPMODE_16BPP_I1555;
val |= WINCONx_HAWSWP_F;
val |= WINCONx_BURSTLEN_16WORD;
break;
case DRM_FORMAT_RGB565:
val |= WINCONx_BPPMODE_16BPP_565;
val |= WINCONx_HAWSWP_F;
val |= WINCONx_BURSTLEN_16WORD;
break;
case DRM_FORMAT_XRGB8888:
val |= WINCONx_BPPMODE_24BPP_888;
val |= WINCONx_WSWP_F;
val |= WINCONx_BURSTLEN_16WORD;
break;
case DRM_FORMAT_ARGB8888:
val |= WINCONx_BPPMODE_32BPP_A8888;
val |= WINCONx_WSWP_F | WINCONx_BLD_PIX_F | WINCONx_ALPHA_SEL_F;
val |= WINCONx_BURSTLEN_16WORD;
break;
default:
DRM_ERROR("Proper pixel format is not set\n");
return;
}
DRM_DEBUG_KMS("bpp = %u\n", fb->bits_per_pixel);
if (fb->width < MIN_FB_WIDTH_FOR_16WORD_BURST) {
val &= ~WINCONx_BURSTLEN_MASK;
val |= WINCONx_BURSTLEN_8WORD;
}
writel(val, ctx->addr + DECON_WINCONx(win));
}
static void decon_shadow_protect_win(struct decon_context *ctx, int win,
bool protect)
{
u32 val;
val = readl(ctx->addr + DECON_SHADOWCON);
if (protect)
val |= SHADOWCON_Wx_PROTECT(win);
else
val &= ~SHADOWCON_Wx_PROTECT(win);
writel(val, ctx->addr + DECON_SHADOWCON);
}
static void decon_atomic_begin(struct exynos_drm_crtc *crtc,
struct exynos_drm_plane *plane)
{
struct decon_context *ctx = crtc->ctx;
if (ctx->suspended)
return;
decon_shadow_protect_win(ctx, plane->zpos, true);
}
static void decon_update_plane(struct exynos_drm_crtc *crtc,
struct exynos_drm_plane *plane)
{
struct decon_context *ctx = crtc->ctx;
struct drm_plane_state *state = plane->base.state;
unsigned int win = plane->zpos;
unsigned int bpp = state->fb->bits_per_pixel >> 3;
unsigned int pitch = state->fb->pitches[0];
u32 val;
if (ctx->suspended)
return;
val = COORDINATE_X(plane->crtc_x) | COORDINATE_Y(plane->crtc_y);
writel(val, ctx->addr + DECON_VIDOSDxA(win));
val = COORDINATE_X(plane->crtc_x + plane->crtc_w - 1) |
COORDINATE_Y(plane->crtc_y + plane->crtc_h - 1);
writel(val, ctx->addr + DECON_VIDOSDxB(win));
val = VIDOSD_Wx_ALPHA_R_F(0x0) | VIDOSD_Wx_ALPHA_G_F(0x0) |
VIDOSD_Wx_ALPHA_B_F(0x0);
writel(val, ctx->addr + DECON_VIDOSDxC(win));
val = VIDOSD_Wx_ALPHA_R_F(0x0) | VIDOSD_Wx_ALPHA_G_F(0x0) |
VIDOSD_Wx_ALPHA_B_F(0x0);
writel(val, ctx->addr + DECON_VIDOSDxD(win));
writel(plane->dma_addr[0], ctx->addr + DECON_VIDW0xADD0B0(win));
val = plane->dma_addr[0] + pitch * plane->crtc_h;
writel(val, ctx->addr + DECON_VIDW0xADD1B0(win));
val = OFFSIZE(pitch - plane->crtc_w * bpp)
| PAGEWIDTH(plane->crtc_w * bpp);
writel(val, ctx->addr + DECON_VIDW0xADD2(win));
decon_win_set_pixfmt(ctx, win, state->fb);
val = readl(ctx->addr + DECON_WINCONx(win));
val |= WINCONx_ENWIN_F;
writel(val, ctx->addr + DECON_WINCONx(win));
val = readl(ctx->addr + DECON_UPDATE);
val |= STANDALONE_UPDATE_F;
writel(val, ctx->addr + DECON_UPDATE);
}
static void decon_disable_plane(struct exynos_drm_crtc *crtc,
struct exynos_drm_plane *plane)
{
struct decon_context *ctx = crtc->ctx;
unsigned int win = plane->zpos;
u32 val;
if (ctx->suspended)
return;
decon_shadow_protect_win(ctx, win, true);
val = readl(ctx->addr + DECON_WINCONx(win));
val &= ~WINCONx_ENWIN_F;
writel(val, ctx->addr + DECON_WINCONx(win));
decon_shadow_protect_win(ctx, win, false);
val = readl(ctx->addr + DECON_UPDATE);
val |= STANDALONE_UPDATE_F;
writel(val, ctx->addr + DECON_UPDATE);
}
static void decon_atomic_flush(struct exynos_drm_crtc *crtc,
struct exynos_drm_plane *plane)
{
struct decon_context *ctx = crtc->ctx;
if (ctx->suspended)
return;
decon_shadow_protect_win(ctx, plane->zpos, false);
if (ctx->i80_if)
atomic_set(&ctx->win_updated, 1);
}
static void decon_swreset(struct decon_context *ctx)
{
unsigned int tries;
writel(0, ctx->addr + DECON_VIDCON0);
for (tries = 2000; tries; --tries) {
if (~readl(ctx->addr + DECON_VIDCON0) & VIDCON0_STOP_STATUS)
break;
udelay(10);
}
WARN(tries == 0, "failed to disable DECON\n");
writel(VIDCON0_SWRESET, ctx->addr + DECON_VIDCON0);
for (tries = 2000; tries; --tries) {
if (~readl(ctx->addr + DECON_VIDCON0) & VIDCON0_SWRESET)
break;
udelay(10);
}
WARN(tries == 0, "failed to software reset DECON\n");
}
static void decon_enable(struct exynos_drm_crtc *crtc)
{
struct decon_context *ctx = crtc->ctx;
int ret;
int i;
if (!ctx->suspended)
return;
ctx->suspended = false;
pm_runtime_get_sync(ctx->dev);
for (i = 0; i < ARRAY_SIZE(decon_clks_name); i++) {
ret = clk_prepare_enable(ctx->clks[i]);
if (ret < 0)
goto err;
}
set_bit(BIT_CLKS_ENABLED, &ctx->enabled);
if (test_and_clear_bit(0, &ctx->irq_flags))
decon_enable_vblank(ctx->crtc);
decon_commit(ctx->crtc);
return;
err:
while (--i >= 0)
clk_disable_unprepare(ctx->clks[i]);
ctx->suspended = true;
}
static void decon_disable(struct exynos_drm_crtc *crtc)
{
struct decon_context *ctx = crtc->ctx;
int i;
if (ctx->suspended)
return;
for (i = 0; i < WINDOWS_NR; i++)
decon_disable_plane(crtc, &ctx->planes[i]);
decon_swreset(ctx);
for (i = 0; i < ARRAY_SIZE(decon_clks_name); i++)
clk_disable_unprepare(ctx->clks[i]);
clear_bit(BIT_CLKS_ENABLED, &ctx->enabled);
pm_runtime_put_sync(ctx->dev);
ctx->suspended = true;
}
void decon_te_irq_handler(struct exynos_drm_crtc *crtc)
{
struct decon_context *ctx = crtc->ctx;
u32 val;
if (!test_bit(BIT_CLKS_ENABLED, &ctx->enabled))
return;
if (atomic_add_unless(&ctx->win_updated, -1, 0)) {
val = readl(ctx->addr + DECON_TRIGCON);
val |= TRIGCON_SWTRIGCMD;
writel(val, ctx->addr + DECON_TRIGCON);
}
drm_crtc_handle_vblank(&ctx->crtc->base);
}
static void decon_clear_channels(struct exynos_drm_crtc *crtc)
{
struct decon_context *ctx = crtc->ctx;
int win, i, ret;
u32 val;
DRM_DEBUG_KMS("%s\n", __FILE__);
for (i = 0; i < ARRAY_SIZE(decon_clks_name); i++) {
ret = clk_prepare_enable(ctx->clks[i]);
if (ret < 0)
goto err;
}
for (win = 0; win < WINDOWS_NR; win++) {
val = readl(ctx->addr + DECON_SHADOWCON);
val |= SHADOWCON_Wx_PROTECT(win);
writel(val, ctx->addr + DECON_SHADOWCON);
val = readl(ctx->addr + DECON_WINCONx(win));
val &= ~WINCONx_ENWIN_F;
writel(val, ctx->addr + DECON_WINCONx(win));
val = readl(ctx->addr + DECON_SHADOWCON);
val &= ~SHADOWCON_Wx_PROTECT(win);
writel(val, ctx->addr + DECON_SHADOWCON);
val = readl(ctx->addr + DECON_UPDATE);
val |= STANDALONE_UPDATE_F;
writel(val, ctx->addr + DECON_UPDATE);
}
msleep(50);
err:
while (--i >= 0)
clk_disable_unprepare(ctx->clks[i]);
}
static int decon_bind(struct device *dev, struct device *master, void *data)
{
struct decon_context *ctx = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
struct exynos_drm_private *priv = drm_dev->dev_private;
struct exynos_drm_plane *exynos_plane;
enum drm_plane_type type;
unsigned int zpos;
int ret;
ctx->drm_dev = drm_dev;
ctx->pipe = priv->pipe++;
for (zpos = 0; zpos < WINDOWS_NR; zpos++) {
type = (zpos == ctx->default_win) ? DRM_PLANE_TYPE_PRIMARY :
DRM_PLANE_TYPE_OVERLAY;
ret = exynos_plane_init(drm_dev, &ctx->planes[zpos],
1 << ctx->pipe, type, decon_formats,
ARRAY_SIZE(decon_formats), zpos);
if (ret)
return ret;
}
exynos_plane = &ctx->planes[ctx->default_win];
ctx->crtc = exynos_drm_crtc_create(drm_dev, &exynos_plane->base,
ctx->pipe, EXYNOS_DISPLAY_TYPE_LCD,
&decon_crtc_ops, ctx);
if (IS_ERR(ctx->crtc)) {
ret = PTR_ERR(ctx->crtc);
goto err;
}
decon_clear_channels(ctx->crtc);
ret = drm_iommu_attach_device(drm_dev, dev);
if (ret)
goto err;
return ret;
err:
priv->pipe--;
return ret;
}
static void decon_unbind(struct device *dev, struct device *master, void *data)
{
struct decon_context *ctx = dev_get_drvdata(dev);
decon_disable(ctx->crtc);
drm_iommu_detach_device(ctx->drm_dev, ctx->dev);
}
static irqreturn_t decon_vsync_irq_handler(int irq, void *dev_id)
{
struct decon_context *ctx = dev_id;
u32 val;
if (!test_bit(BIT_CLKS_ENABLED, &ctx->enabled))
goto out;
val = readl(ctx->addr + DECON_VIDINTCON1);
if (val & VIDINTCON1_INTFRMPEND) {
drm_crtc_handle_vblank(&ctx->crtc->base);
writel(VIDINTCON1_INTFRMPEND, ctx->addr + DECON_VIDINTCON1);
}
out:
return IRQ_HANDLED;
}
static irqreturn_t decon_lcd_sys_irq_handler(int irq, void *dev_id)
{
struct decon_context *ctx = dev_id;
u32 val;
int win;
if (!test_bit(BIT_CLKS_ENABLED, &ctx->enabled))
goto out;
val = readl(ctx->addr + DECON_VIDINTCON1);
if (val & VIDINTCON1_INTFRMDONEPEND) {
for (win = 0 ; win < WINDOWS_NR ; win++) {
struct exynos_drm_plane *plane = &ctx->planes[win];
if (!plane->pending_fb)
continue;
exynos_drm_crtc_finish_update(ctx->crtc, plane);
}
writel(VIDINTCON1_INTFRMDONEPEND,
ctx->addr + DECON_VIDINTCON1);
}
out:
return IRQ_HANDLED;
}
static int exynos5433_decon_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct decon_context *ctx;
struct resource *res;
int ret;
int i;
ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->default_win = 0;
ctx->suspended = true;
ctx->dev = dev;
if (of_get_child_by_name(dev->of_node, "i80-if-timings"))
ctx->i80_if = true;
for (i = 0; i < ARRAY_SIZE(decon_clks_name); i++) {
struct clk *clk;
clk = devm_clk_get(ctx->dev, decon_clks_name[i]);
if (IS_ERR(clk))
return PTR_ERR(clk);
ctx->clks[i] = clk;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "cannot find IO resource\n");
return -ENXIO;
}
ctx->addr = devm_ioremap_resource(dev, res);
if (IS_ERR(ctx->addr)) {
dev_err(dev, "ioremap failed\n");
return PTR_ERR(ctx->addr);
}
res = platform_get_resource_byname(pdev, IORESOURCE_IRQ,
ctx->i80_if ? "lcd_sys" : "vsync");
if (!res) {
dev_err(dev, "cannot find IRQ resource\n");
return -ENXIO;
}
ret = devm_request_irq(dev, res->start, ctx->i80_if ?
decon_lcd_sys_irq_handler : decon_vsync_irq_handler, 0,
"drm_decon", ctx);
if (ret < 0) {
dev_err(dev, "lcd_sys irq request failed\n");
return ret;
}
platform_set_drvdata(pdev, ctx);
pm_runtime_enable(dev);
ret = component_add(dev, &decon_component_ops);
if (ret)
goto err_disable_pm_runtime;
return 0;
err_disable_pm_runtime:
pm_runtime_disable(dev);
return ret;
}
static int exynos5433_decon_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
component_del(&pdev->dev, &decon_component_ops);
return 0;
}
