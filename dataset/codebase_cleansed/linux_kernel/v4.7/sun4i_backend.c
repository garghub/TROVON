void sun4i_backend_apply_color_correction(struct sun4i_backend *backend)
{
int i;
DRM_DEBUG_DRIVER("Applying RGB to YUV color correction\n");
regmap_write(backend->regs, SUN4I_BACKEND_OCCTL_REG,
SUN4I_BACKEND_OCCTL_ENABLE);
for (i = 0; i < 12; i++)
regmap_write(backend->regs, SUN4I_BACKEND_OCRCOEF_REG(i),
sunxi_rgb2yuv_coef[i]);
}
void sun4i_backend_disable_color_correction(struct sun4i_backend *backend)
{
DRM_DEBUG_DRIVER("Disabling color correction\n");
regmap_update_bits(backend->regs, SUN4I_BACKEND_OCCTL_REG,
SUN4I_BACKEND_OCCTL_ENABLE, 0);
}
void sun4i_backend_commit(struct sun4i_backend *backend)
{
DRM_DEBUG_DRIVER("Committing changes\n");
regmap_write(backend->regs, SUN4I_BACKEND_REGBUFFCTL_REG,
SUN4I_BACKEND_REGBUFFCTL_AUTOLOAD_DIS |
SUN4I_BACKEND_REGBUFFCTL_LOADCTL);
}
void sun4i_backend_layer_enable(struct sun4i_backend *backend,
int layer, bool enable)
{
u32 val;
DRM_DEBUG_DRIVER("Enabling layer %d\n", layer);
if (enable)
val = SUN4I_BACKEND_MODCTL_LAY_EN(layer);
else
val = 0;
regmap_update_bits(backend->regs, SUN4I_BACKEND_MODCTL_REG,
SUN4I_BACKEND_MODCTL_LAY_EN(layer), val);
}
static int sun4i_backend_drm_format_to_layer(u32 format, u32 *mode)
{
switch (format) {
case DRM_FORMAT_ARGB8888:
*mode = SUN4I_BACKEND_LAY_FBFMT_ARGB8888;
break;
case DRM_FORMAT_XRGB8888:
*mode = SUN4I_BACKEND_LAY_FBFMT_XRGB8888;
break;
case DRM_FORMAT_RGB888:
*mode = SUN4I_BACKEND_LAY_FBFMT_RGB888;
break;
default:
return -EINVAL;
}
return 0;
}
int sun4i_backend_update_layer_coord(struct sun4i_backend *backend,
int layer, struct drm_plane *plane)
{
struct drm_plane_state *state = plane->state;
struct drm_framebuffer *fb = state->fb;
DRM_DEBUG_DRIVER("Updating layer %d\n", layer);
if (plane->type == DRM_PLANE_TYPE_PRIMARY) {
DRM_DEBUG_DRIVER("Primary layer, updating global size W: %u H: %u\n",
state->crtc_w, state->crtc_h);
regmap_write(backend->regs, SUN4I_BACKEND_DISSIZE_REG,
SUN4I_BACKEND_DISSIZE(state->crtc_w,
state->crtc_h));
}
DRM_DEBUG_DRIVER("Layer line width: %d bits\n", fb->pitches[0] * 8);
regmap_write(backend->regs, SUN4I_BACKEND_LAYLINEWIDTH_REG(layer),
fb->pitches[0] * 8);
DRM_DEBUG_DRIVER("Layer size W: %u H: %u\n",
state->crtc_w, state->crtc_h);
regmap_write(backend->regs, SUN4I_BACKEND_LAYSIZE_REG(layer),
SUN4I_BACKEND_LAYSIZE(state->crtc_w,
state->crtc_h));
DRM_DEBUG_DRIVER("Layer coordinates X: %d Y: %d\n",
state->crtc_x, state->crtc_y);
regmap_write(backend->regs, SUN4I_BACKEND_LAYCOOR_REG(layer),
SUN4I_BACKEND_LAYCOOR(state->crtc_x,
state->crtc_y));
return 0;
}
int sun4i_backend_update_layer_formats(struct sun4i_backend *backend,
int layer, struct drm_plane *plane)
{
struct drm_plane_state *state = plane->state;
struct drm_framebuffer *fb = state->fb;
bool interlaced = false;
u32 val;
int ret;
if (plane->state->crtc)
interlaced = plane->state->crtc->state->adjusted_mode.flags
& DRM_MODE_FLAG_INTERLACE;
regmap_update_bits(backend->regs, SUN4I_BACKEND_MODCTL_REG,
SUN4I_BACKEND_MODCTL_ITLMOD_EN,
interlaced ? SUN4I_BACKEND_MODCTL_ITLMOD_EN : 0);
DRM_DEBUG_DRIVER("Switching display backend interlaced mode %s\n",
interlaced ? "on" : "off");
ret = sun4i_backend_drm_format_to_layer(fb->pixel_format, &val);
if (ret) {
DRM_DEBUG_DRIVER("Invalid format\n");
return val;
}
regmap_update_bits(backend->regs, SUN4I_BACKEND_ATTCTL_REG1(layer),
SUN4I_BACKEND_ATTCTL_REG1_LAY_FBFMT, val);
return 0;
}
int sun4i_backend_update_layer_buffer(struct sun4i_backend *backend,
int layer, struct drm_plane *plane)
{
struct drm_plane_state *state = plane->state;
struct drm_framebuffer *fb = state->fb;
struct drm_gem_cma_object *gem;
u32 lo_paddr, hi_paddr;
dma_addr_t paddr;
int bpp;
gem = drm_fb_cma_get_gem_obj(fb, 0);
DRM_DEBUG_DRIVER("Using GEM @ %pad\n", &gem->paddr);
bpp = drm_format_plane_cpp(fb->pixel_format, 0);
paddr = gem->paddr + fb->offsets[0];
paddr += (state->src_x >> 16) * bpp;
paddr += (state->src_y >> 16) * fb->pitches[0];
DRM_DEBUG_DRIVER("Setting buffer address to %pad\n", &paddr);
lo_paddr = paddr << 3;
DRM_DEBUG_DRIVER("Setting address lower bits to 0x%x\n", lo_paddr);
regmap_write(backend->regs, SUN4I_BACKEND_LAYFB_L32ADD_REG(layer),
lo_paddr);
hi_paddr = paddr >> 29;
DRM_DEBUG_DRIVER("Setting address high bits to 0x%x\n", hi_paddr);
regmap_update_bits(backend->regs, SUN4I_BACKEND_LAYFB_H4ADD_REG,
SUN4I_BACKEND_LAYFB_H4ADD_MSK(layer),
SUN4I_BACKEND_LAYFB_H4ADD(layer, hi_paddr));
return 0;
}
static int sun4i_backend_bind(struct device *dev, struct device *master,
void *data)
{
struct platform_device *pdev = to_platform_device(dev);
struct drm_device *drm = data;
struct sun4i_drv *drv = drm->dev_private;
struct sun4i_backend *backend;
struct resource *res;
void __iomem *regs;
int i, ret;
backend = devm_kzalloc(dev, sizeof(*backend), GFP_KERNEL);
if (!backend)
return -ENOMEM;
dev_set_drvdata(dev, backend);
drv->backend = backend;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(dev, res);
if (IS_ERR(regs)) {
dev_err(dev, "Couldn't map the backend registers\n");
return PTR_ERR(regs);
}
backend->regs = devm_regmap_init_mmio(dev, regs,
&sun4i_backend_regmap_config);
if (IS_ERR(backend->regs)) {
dev_err(dev, "Couldn't create the backend0 regmap\n");
return PTR_ERR(backend->regs);
}
backend->reset = devm_reset_control_get(dev, NULL);
if (IS_ERR(backend->reset)) {
dev_err(dev, "Couldn't get our reset line\n");
return PTR_ERR(backend->reset);
}
ret = reset_control_deassert(backend->reset);
if (ret) {
dev_err(dev, "Couldn't deassert our reset line\n");
return ret;
}
backend->bus_clk = devm_clk_get(dev, "ahb");
if (IS_ERR(backend->bus_clk)) {
dev_err(dev, "Couldn't get the backend bus clock\n");
ret = PTR_ERR(backend->bus_clk);
goto err_assert_reset;
}
clk_prepare_enable(backend->bus_clk);
backend->mod_clk = devm_clk_get(dev, "mod");
if (IS_ERR(backend->mod_clk)) {
dev_err(dev, "Couldn't get the backend module clock\n");
ret = PTR_ERR(backend->mod_clk);
goto err_disable_bus_clk;
}
clk_prepare_enable(backend->mod_clk);
backend->ram_clk = devm_clk_get(dev, "ram");
if (IS_ERR(backend->ram_clk)) {
dev_err(dev, "Couldn't get the backend RAM clock\n");
ret = PTR_ERR(backend->ram_clk);
goto err_disable_mod_clk;
}
clk_prepare_enable(backend->ram_clk);
for (i = 0x800; i < 0x1000; i += 4)
regmap_write(backend->regs, i, 0);
regmap_write(backend->regs, SUN4I_BACKEND_REGBUFFCTL_REG,
SUN4I_BACKEND_REGBUFFCTL_AUTOLOAD_DIS);
regmap_write(backend->regs, SUN4I_BACKEND_MODCTL_REG,
SUN4I_BACKEND_MODCTL_DEBE_EN |
SUN4I_BACKEND_MODCTL_START_CTL);
return 0;
err_disable_mod_clk:
clk_disable_unprepare(backend->mod_clk);
err_disable_bus_clk:
clk_disable_unprepare(backend->bus_clk);
err_assert_reset:
reset_control_assert(backend->reset);
return ret;
}
static void sun4i_backend_unbind(struct device *dev, struct device *master,
void *data)
{
struct sun4i_backend *backend = dev_get_drvdata(dev);
clk_disable_unprepare(backend->ram_clk);
clk_disable_unprepare(backend->mod_clk);
clk_disable_unprepare(backend->bus_clk);
reset_control_assert(backend->reset);
}
static int sun4i_backend_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &sun4i_backend_ops);
}
static int sun4i_backend_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &sun4i_backend_ops);
return 0;
}
