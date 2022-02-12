static void panel_encoder_dpms(struct drm_encoder *encoder, int mode)
{
struct panel_encoder *panel_encoder = to_panel_encoder(encoder);
struct backlight_device *backlight = panel_encoder->mod->backlight;
struct gpio_desc *gpio = panel_encoder->mod->enable_gpio;
if (backlight) {
backlight->props.power = mode == DRM_MODE_DPMS_ON ?
FB_BLANK_UNBLANK : FB_BLANK_POWERDOWN;
backlight_update_status(backlight);
}
if (gpio)
gpiod_set_value_cansleep(gpio,
mode == DRM_MODE_DPMS_ON ? 1 : 0);
}
static void panel_encoder_prepare(struct drm_encoder *encoder)
{
panel_encoder_dpms(encoder, DRM_MODE_DPMS_OFF);
}
static void panel_encoder_commit(struct drm_encoder *encoder)
{
panel_encoder_dpms(encoder, DRM_MODE_DPMS_ON);
}
static void panel_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
}
static struct drm_encoder *panel_encoder_create(struct drm_device *dev,
struct panel_module *mod)
{
struct panel_encoder *panel_encoder;
struct drm_encoder *encoder;
int ret;
panel_encoder = devm_kzalloc(dev->dev, sizeof(*panel_encoder),
GFP_KERNEL);
if (!panel_encoder) {
dev_err(dev->dev, "allocation failed\n");
return NULL;
}
panel_encoder->mod = mod;
encoder = &panel_encoder->base;
encoder->possible_crtcs = 1;
ret = drm_encoder_init(dev, encoder, &panel_encoder_funcs,
DRM_MODE_ENCODER_LVDS, NULL);
if (ret < 0)
goto fail;
drm_encoder_helper_add(encoder, &panel_encoder_helper_funcs);
return encoder;
fail:
drm_encoder_cleanup(encoder);
return NULL;
}
static void panel_connector_destroy(struct drm_connector *connector)
{
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
}
static int panel_connector_get_modes(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct panel_connector *panel_connector = to_panel_connector(connector);
struct display_timings *timings = panel_connector->mod->timings;
int i;
for (i = 0; i < timings->num_timings; i++) {
struct drm_display_mode *mode = drm_mode_create(dev);
struct videomode vm;
if (videomode_from_timings(timings, &vm, i))
break;
drm_display_mode_from_videomode(&vm, mode);
mode->type = DRM_MODE_TYPE_DRIVER;
if (timings->native_mode == i)
mode->type |= DRM_MODE_TYPE_PREFERRED;
drm_mode_set_name(mode);
drm_mode_probed_add(connector, mode);
}
return i;
}
static int panel_connector_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct tilcdc_drm_private *priv = connector->dev->dev_private;
return tilcdc_crtc_mode_valid(priv->crtc, mode);
}
static struct drm_encoder *panel_connector_best_encoder(
struct drm_connector *connector)
{
struct panel_connector *panel_connector = to_panel_connector(connector);
return panel_connector->encoder;
}
static struct drm_connector *panel_connector_create(struct drm_device *dev,
struct panel_module *mod, struct drm_encoder *encoder)
{
struct panel_connector *panel_connector;
struct drm_connector *connector;
int ret;
panel_connector = devm_kzalloc(dev->dev, sizeof(*panel_connector),
GFP_KERNEL);
if (!panel_connector) {
dev_err(dev->dev, "allocation failed\n");
return NULL;
}
panel_connector->encoder = encoder;
panel_connector->mod = mod;
connector = &panel_connector->base;
drm_connector_init(dev, connector, &panel_connector_funcs,
DRM_MODE_CONNECTOR_LVDS);
drm_connector_helper_add(connector, &panel_connector_helper_funcs);
connector->interlace_allowed = 0;
connector->doublescan_allowed = 0;
ret = drm_mode_connector_attach_encoder(connector, encoder);
if (ret)
goto fail;
return connector;
fail:
panel_connector_destroy(connector);
return NULL;
}
static int panel_modeset_init(struct tilcdc_module *mod, struct drm_device *dev)
{
struct panel_module *panel_mod = to_panel_module(mod);
struct tilcdc_drm_private *priv = dev->dev_private;
struct drm_encoder *encoder;
struct drm_connector *connector;
encoder = panel_encoder_create(dev, panel_mod);
if (!encoder)
return -ENOMEM;
connector = panel_connector_create(dev, panel_mod, encoder);
if (!connector)
return -ENOMEM;
priv->encoders[priv->num_encoders++] = encoder;
priv->connectors[priv->num_connectors++] = connector;
tilcdc_crtc_set_panel_info(priv->crtc,
to_panel_encoder(encoder)->mod->info);
return 0;
}
static struct tilcdc_panel_info *of_get_panel_info(struct device_node *np)
{
struct device_node *info_np;
struct tilcdc_panel_info *info;
int ret = 0;
if (!np) {
pr_err("%s: no devicenode given\n", __func__);
return NULL;
}
info_np = of_get_child_by_name(np, "panel-info");
if (!info_np) {
pr_err("%s: could not find panel-info node\n", __func__);
return NULL;
}
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info) {
pr_err("%s: allocation failed\n", __func__);
of_node_put(info_np);
return NULL;
}
ret |= of_property_read_u32(info_np, "ac-bias", &info->ac_bias);
ret |= of_property_read_u32(info_np, "ac-bias-intrpt", &info->ac_bias_intrpt);
ret |= of_property_read_u32(info_np, "dma-burst-sz", &info->dma_burst_sz);
ret |= of_property_read_u32(info_np, "bpp", &info->bpp);
ret |= of_property_read_u32(info_np, "fdd", &info->fdd);
ret |= of_property_read_u32(info_np, "sync-edge", &info->sync_edge);
ret |= of_property_read_u32(info_np, "sync-ctrl", &info->sync_ctrl);
ret |= of_property_read_u32(info_np, "raster-order", &info->raster_order);
ret |= of_property_read_u32(info_np, "fifo-th", &info->fifo_th);
info->tft_alt_mode = of_property_read_bool(info_np, "tft-alt-mode");
info->invert_pxl_clk = of_property_read_bool(info_np, "invert-pxl-clk");
if (ret) {
pr_err("%s: error reading panel-info properties\n", __func__);
kfree(info);
of_node_put(info_np);
return NULL;
}
of_node_put(info_np);
return info;
}
static int panel_probe(struct platform_device *pdev)
{
struct device_node *bl_node, *node = pdev->dev.of_node;
struct panel_module *panel_mod;
struct tilcdc_module *mod;
struct pinctrl *pinctrl;
int ret;
if (!node) {
dev_err(&pdev->dev, "device-tree data is missing\n");
return -ENXIO;
}
panel_mod = devm_kzalloc(&pdev->dev, sizeof(*panel_mod), GFP_KERNEL);
if (!panel_mod)
return -ENOMEM;
bl_node = of_parse_phandle(node, "backlight", 0);
if (bl_node) {
panel_mod->backlight = of_find_backlight_by_node(bl_node);
of_node_put(bl_node);
if (!panel_mod->backlight)
return -EPROBE_DEFER;
dev_info(&pdev->dev, "found backlight\n");
}
panel_mod->enable_gpio = devm_gpiod_get_optional(&pdev->dev, "enable",
GPIOD_OUT_LOW);
if (IS_ERR(panel_mod->enable_gpio)) {
ret = PTR_ERR(panel_mod->enable_gpio);
dev_err(&pdev->dev, "failed to request enable GPIO\n");
goto fail_backlight;
}
if (panel_mod->enable_gpio)
dev_info(&pdev->dev, "found enable GPIO\n");
mod = &panel_mod->base;
pdev->dev.platform_data = mod;
tilcdc_module_init(mod, "panel", &panel_module_ops);
pinctrl = devm_pinctrl_get_select_default(&pdev->dev);
if (IS_ERR(pinctrl))
dev_warn(&pdev->dev, "pins are not configured\n");
panel_mod->timings = of_get_display_timings(node);
if (!panel_mod->timings) {
dev_err(&pdev->dev, "could not get panel timings\n");
ret = -EINVAL;
goto fail_free;
}
panel_mod->info = of_get_panel_info(node);
if (!panel_mod->info) {
dev_err(&pdev->dev, "could not get panel info\n");
ret = -EINVAL;
goto fail_timings;
}
return 0;
fail_timings:
display_timings_release(panel_mod->timings);
fail_free:
tilcdc_module_cleanup(mod);
fail_backlight:
if (panel_mod->backlight)
put_device(&panel_mod->backlight->dev);
return ret;
}
static int panel_remove(struct platform_device *pdev)
{
struct tilcdc_module *mod = dev_get_platdata(&pdev->dev);
struct panel_module *panel_mod = to_panel_module(mod);
struct backlight_device *backlight = panel_mod->backlight;
if (backlight)
put_device(&backlight->dev);
display_timings_release(panel_mod->timings);
tilcdc_module_cleanup(mod);
kfree(panel_mod->info);
return 0;
}
int __init tilcdc_panel_init(void)
{
return platform_driver_register(&panel_driver);
}
void __exit tilcdc_panel_fini(void)
{
platform_driver_unregister(&panel_driver);
}
