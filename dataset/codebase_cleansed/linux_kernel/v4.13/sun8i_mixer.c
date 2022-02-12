static void sun8i_mixer_commit(struct sunxi_engine *engine)
{
DRM_DEBUG_DRIVER("Committing changes\n");
regmap_write(engine->regs, SUN8I_MIXER_GLOBAL_DBUFF,
SUN8I_MIXER_GLOBAL_DBUFF_ENABLE);
}
void sun8i_mixer_layer_enable(struct sun8i_mixer *mixer,
int layer, bool enable)
{
u32 val;
int chan = mixer->cfg->vi_num;
DRM_DEBUG_DRIVER("Enabling layer %d in channel %d\n", layer, chan);
if (enable)
val = SUN8I_MIXER_CHAN_UI_LAYER_ATTR_EN;
else
val = 0;
regmap_update_bits(mixer->engine.regs,
SUN8I_MIXER_CHAN_UI_LAYER_ATTR(chan, layer),
SUN8I_MIXER_CHAN_UI_LAYER_ATTR_EN, val);
regmap_update_bits(mixer->engine.regs,
SUN8I_MIXER_CHAN_UI_LAYER_ATTR(chan, layer),
SUN8I_MIXER_CHAN_UI_LAYER_ATTR_ALPHA_MODE_MASK,
SUN8I_MIXER_CHAN_UI_LAYER_ATTR_ALPHA_MODE_DEF);
regmap_update_bits(mixer->engine.regs,
SUN8I_MIXER_CHAN_UI_LAYER_ATTR(chan, layer),
SUN8I_MIXER_CHAN_UI_LAYER_ATTR_ALPHA_MASK,
SUN8I_MIXER_CHAN_UI_LAYER_ATTR_ALPHA_DEF);
}
static int sun8i_mixer_drm_format_to_layer(struct drm_plane *plane,
u32 format, u32 *mode)
{
switch (format) {
case DRM_FORMAT_ARGB8888:
*mode = SUN8I_MIXER_CHAN_UI_LAYER_ATTR_FBFMT_ARGB8888;
break;
case DRM_FORMAT_XRGB8888:
*mode = SUN8I_MIXER_CHAN_UI_LAYER_ATTR_FBFMT_XRGB8888;
break;
case DRM_FORMAT_RGB888:
*mode = SUN8I_MIXER_CHAN_UI_LAYER_ATTR_FBFMT_RGB888;
break;
default:
return -EINVAL;
}
return 0;
}
int sun8i_mixer_update_layer_coord(struct sun8i_mixer *mixer,
int layer, struct drm_plane *plane)
{
struct drm_plane_state *state = plane->state;
struct drm_framebuffer *fb = state->fb;
int chan = mixer->cfg->vi_num;
DRM_DEBUG_DRIVER("Updating layer %d\n", layer);
if (plane->type == DRM_PLANE_TYPE_PRIMARY) {
DRM_DEBUG_DRIVER("Primary layer, updating global size W: %u H: %u\n",
state->crtc_w, state->crtc_h);
regmap_write(mixer->engine.regs, SUN8I_MIXER_GLOBAL_SIZE,
SUN8I_MIXER_SIZE(state->crtc_w,
state->crtc_h));
DRM_DEBUG_DRIVER("Updating blender size\n");
regmap_write(mixer->engine.regs,
SUN8I_MIXER_BLEND_ATTR_INSIZE(0),
SUN8I_MIXER_SIZE(state->crtc_w,
state->crtc_h));
regmap_write(mixer->engine.regs, SUN8I_MIXER_BLEND_OUTSIZE,
SUN8I_MIXER_SIZE(state->crtc_w,
state->crtc_h));
DRM_DEBUG_DRIVER("Updating channel size\n");
regmap_write(mixer->engine.regs,
SUN8I_MIXER_CHAN_UI_OVL_SIZE(chan),
SUN8I_MIXER_SIZE(state->crtc_w,
state->crtc_h));
}
DRM_DEBUG_DRIVER("Layer line width: %d bytes\n", fb->pitches[0]);
regmap_write(mixer->engine.regs,
SUN8I_MIXER_CHAN_UI_LAYER_PITCH(chan, layer),
fb->pitches[0]);
DRM_DEBUG_DRIVER("Layer size W: %u H: %u\n",
state->crtc_w, state->crtc_h);
regmap_write(mixer->engine.regs,
SUN8I_MIXER_CHAN_UI_LAYER_SIZE(chan, layer),
SUN8I_MIXER_SIZE(state->crtc_w, state->crtc_h));
DRM_DEBUG_DRIVER("Layer coordinates X: %d Y: %d\n",
state->crtc_x, state->crtc_y);
regmap_write(mixer->engine.regs,
SUN8I_MIXER_CHAN_UI_LAYER_COORD(chan, layer),
SUN8I_MIXER_COORD(state->crtc_x, state->crtc_y));
return 0;
}
int sun8i_mixer_update_layer_formats(struct sun8i_mixer *mixer,
int layer, struct drm_plane *plane)
{
struct drm_plane_state *state = plane->state;
struct drm_framebuffer *fb = state->fb;
bool interlaced = false;
u32 val;
int chan = mixer->cfg->vi_num;
int ret;
if (plane->state->crtc)
interlaced = plane->state->crtc->state->adjusted_mode.flags
& DRM_MODE_FLAG_INTERLACE;
regmap_update_bits(mixer->engine.regs, SUN8I_MIXER_BLEND_OUTCTL,
SUN8I_MIXER_BLEND_OUTCTL_INTERLACED,
interlaced ?
SUN8I_MIXER_BLEND_OUTCTL_INTERLACED : 0);
DRM_DEBUG_DRIVER("Switching display mixer interlaced mode %s\n",
interlaced ? "on" : "off");
ret = sun8i_mixer_drm_format_to_layer(plane, fb->format->format,
&val);
if (ret) {
DRM_DEBUG_DRIVER("Invalid format\n");
return ret;
}
regmap_update_bits(mixer->engine.regs,
SUN8I_MIXER_CHAN_UI_LAYER_ATTR(chan, layer),
SUN8I_MIXER_CHAN_UI_LAYER_ATTR_FBFMT_MASK, val);
return 0;
}
int sun8i_mixer_update_layer_buffer(struct sun8i_mixer *mixer,
int layer, struct drm_plane *plane)
{
struct drm_plane_state *state = plane->state;
struct drm_framebuffer *fb = state->fb;
struct drm_gem_cma_object *gem;
dma_addr_t paddr;
int chan = mixer->cfg->vi_num;
int bpp;
gem = drm_fb_cma_get_gem_obj(fb, 0);
DRM_DEBUG_DRIVER("Using GEM @ %pad\n", &gem->paddr);
bpp = fb->format->cpp[0];
paddr = gem->paddr + fb->offsets[0];
paddr += (state->src_x >> 16) * bpp;
paddr += (state->src_y >> 16) * fb->pitches[0];
if (state->crtc_x < 0)
paddr += -state->crtc_x * bpp;
if (state->crtc_y < 0)
paddr += -state->crtc_y * fb->pitches[0];
DRM_DEBUG_DRIVER("Setting buffer address to %pad\n", &paddr);
regmap_write(mixer->engine.regs,
SUN8I_MIXER_CHAN_UI_LAYER_TOP_LADDR(chan, layer),
lower_32_bits(paddr));
return 0;
}
static int sun8i_mixer_bind(struct device *dev, struct device *master,
void *data)
{
struct platform_device *pdev = to_platform_device(dev);
struct drm_device *drm = data;
struct sun4i_drv *drv = drm->dev_private;
struct sun8i_mixer *mixer;
struct resource *res;
void __iomem *regs;
int i, ret;
ret = dma_set_mask(dev, DMA_BIT_MASK(32));
if (ret) {
dev_err(dev, "Cannot do 32-bit DMA.\n");
return ret;
}
mixer = devm_kzalloc(dev, sizeof(*mixer), GFP_KERNEL);
if (!mixer)
return -ENOMEM;
dev_set_drvdata(dev, mixer);
mixer->engine.ops = &sun8i_engine_ops;
mixer->engine.node = dev->of_node;
mixer->engine.id = -1;
mixer->cfg = of_device_get_match_data(dev);
if (!mixer->cfg)
return -EINVAL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(dev, res);
if (IS_ERR(regs))
return PTR_ERR(regs);
mixer->engine.regs = devm_regmap_init_mmio(dev, regs,
&sun8i_mixer_regmap_config);
if (IS_ERR(mixer->engine.regs)) {
dev_err(dev, "Couldn't create the mixer regmap\n");
return PTR_ERR(mixer->engine.regs);
}
mixer->reset = devm_reset_control_get(dev, NULL);
if (IS_ERR(mixer->reset)) {
dev_err(dev, "Couldn't get our reset line\n");
return PTR_ERR(mixer->reset);
}
ret = reset_control_deassert(mixer->reset);
if (ret) {
dev_err(dev, "Couldn't deassert our reset line\n");
return ret;
}
mixer->bus_clk = devm_clk_get(dev, "bus");
if (IS_ERR(mixer->bus_clk)) {
dev_err(dev, "Couldn't get the mixer bus clock\n");
ret = PTR_ERR(mixer->bus_clk);
goto err_assert_reset;
}
clk_prepare_enable(mixer->bus_clk);
mixer->mod_clk = devm_clk_get(dev, "mod");
if (IS_ERR(mixer->mod_clk)) {
dev_err(dev, "Couldn't get the mixer module clock\n");
ret = PTR_ERR(mixer->mod_clk);
goto err_disable_bus_clk;
}
clk_prepare_enable(mixer->mod_clk);
list_add_tail(&mixer->engine.list, &drv->engine_list);
for (i = 0x0; i < 0x20000; i += 4)
regmap_write(mixer->engine.regs, i, 0);
regmap_write(mixer->engine.regs, SUN8I_MIXER_GLOBAL_CTL,
SUN8I_MIXER_GLOBAL_CTL_RT_EN);
regmap_write(mixer->engine.regs, SUN8I_MIXER_BLEND_FCOLOR_CTL,
SUN8I_MIXER_BLEND_FCOLOR_CTL_DEF);
regmap_write(mixer->engine.regs, SUN8I_MIXER_BLEND_PREMULTIPLY,
SUN8I_MIXER_BLEND_PREMULTIPLY_DEF);
regmap_write(mixer->engine.regs, SUN8I_MIXER_BLEND_BKCOLOR,
SUN8I_MIXER_BLEND_BKCOLOR_DEF);
regmap_write(mixer->engine.regs, SUN8I_MIXER_BLEND_MODE(0),
SUN8I_MIXER_BLEND_MODE_DEF);
regmap_write(mixer->engine.regs, SUN8I_MIXER_BLEND_CK_CTL,
SUN8I_MIXER_BLEND_CK_CTL_DEF);
regmap_write(mixer->engine.regs,
SUN8I_MIXER_BLEND_ATTR_FCOLOR(0),
SUN8I_MIXER_BLEND_ATTR_FCOLOR_DEF);
DRM_DEBUG_DRIVER("Selecting channel %d (first UI channel)\n",
mixer->cfg->vi_num);
regmap_write(mixer->engine.regs, SUN8I_MIXER_BLEND_ROUTE,
mixer->cfg->vi_num);
return 0;
err_disable_bus_clk:
clk_disable_unprepare(mixer->bus_clk);
err_assert_reset:
reset_control_assert(mixer->reset);
return ret;
}
static void sun8i_mixer_unbind(struct device *dev, struct device *master,
void *data)
{
struct sun8i_mixer *mixer = dev_get_drvdata(dev);
list_del(&mixer->engine.list);
clk_disable_unprepare(mixer->mod_clk);
clk_disable_unprepare(mixer->bus_clk);
reset_control_assert(mixer->reset);
}
static int sun8i_mixer_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &sun8i_mixer_ops);
}
static int sun8i_mixer_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &sun8i_mixer_ops);
return 0;
}
