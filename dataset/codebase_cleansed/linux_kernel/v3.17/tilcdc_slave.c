static inline struct drm_encoder_slave_funcs *
get_slave_funcs(struct drm_encoder *enc)
{
return to_encoder_slave(enc)->slave_funcs;
}
static void slave_encoder_destroy(struct drm_encoder *encoder)
{
struct slave_encoder *slave_encoder = to_slave_encoder(encoder);
if (get_slave_funcs(encoder))
get_slave_funcs(encoder)->destroy(encoder);
drm_encoder_cleanup(encoder);
kfree(slave_encoder);
}
static void slave_encoder_prepare(struct drm_encoder *encoder)
{
drm_i2c_encoder_prepare(encoder);
tilcdc_crtc_set_panel_info(encoder->crtc, &slave_info);
}
static bool slave_encoder_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
adjusted_mode->hskew = mode->hsync_end - mode->hsync_start;
adjusted_mode->flags |= DRM_MODE_FLAG_HSKEW;
if (mode->flags & DRM_MODE_FLAG_NHSYNC) {
adjusted_mode->flags |= DRM_MODE_FLAG_PHSYNC;
adjusted_mode->flags &= ~DRM_MODE_FLAG_NHSYNC;
} else {
adjusted_mode->flags |= DRM_MODE_FLAG_NHSYNC;
adjusted_mode->flags &= ~DRM_MODE_FLAG_PHSYNC;
}
return drm_i2c_encoder_mode_fixup(encoder, mode, adjusted_mode);
}
static struct drm_encoder *slave_encoder_create(struct drm_device *dev,
struct slave_module *mod)
{
struct slave_encoder *slave_encoder;
struct drm_encoder *encoder;
int ret;
slave_encoder = kzalloc(sizeof(*slave_encoder), GFP_KERNEL);
if (!slave_encoder) {
dev_err(dev->dev, "allocation failed\n");
return NULL;
}
slave_encoder->mod = mod;
encoder = &slave_encoder->base.base;
encoder->possible_crtcs = 1;
ret = drm_encoder_init(dev, encoder, &slave_encoder_funcs,
DRM_MODE_ENCODER_TMDS);
if (ret)
goto fail;
drm_encoder_helper_add(encoder, &slave_encoder_helper_funcs);
ret = drm_i2c_encoder_init(dev, to_encoder_slave(encoder), mod->i2c, &info);
if (ret)
goto fail;
return encoder;
fail:
slave_encoder_destroy(encoder);
return NULL;
}
static void slave_connector_destroy(struct drm_connector *connector)
{
struct slave_connector *slave_connector = to_slave_connector(connector);
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
kfree(slave_connector);
}
static enum drm_connector_status slave_connector_detect(
struct drm_connector *connector,
bool force)
{
struct drm_encoder *encoder = to_slave_connector(connector)->encoder;
return get_slave_funcs(encoder)->detect(encoder, connector);
}
static int slave_connector_get_modes(struct drm_connector *connector)
{
struct drm_encoder *encoder = to_slave_connector(connector)->encoder;
return get_slave_funcs(encoder)->get_modes(encoder, connector);
}
static int slave_connector_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct drm_encoder *encoder = to_slave_connector(connector)->encoder;
struct tilcdc_drm_private *priv = connector->dev->dev_private;
int ret;
ret = tilcdc_crtc_mode_valid(priv->crtc, mode);
if (ret != MODE_OK)
return ret;
return get_slave_funcs(encoder)->mode_valid(encoder, mode);
}
static struct drm_encoder *slave_connector_best_encoder(
struct drm_connector *connector)
{
struct slave_connector *slave_connector = to_slave_connector(connector);
return slave_connector->encoder;
}
static int slave_connector_set_property(struct drm_connector *connector,
struct drm_property *property, uint64_t value)
{
struct drm_encoder *encoder = to_slave_connector(connector)->encoder;
return get_slave_funcs(encoder)->set_property(encoder,
connector, property, value);
}
static struct drm_connector *slave_connector_create(struct drm_device *dev,
struct slave_module *mod, struct drm_encoder *encoder)
{
struct slave_connector *slave_connector;
struct drm_connector *connector;
int ret;
slave_connector = kzalloc(sizeof(*slave_connector), GFP_KERNEL);
if (!slave_connector) {
dev_err(dev->dev, "allocation failed\n");
return NULL;
}
slave_connector->encoder = encoder;
slave_connector->mod = mod;
connector = &slave_connector->base;
drm_connector_init(dev, connector, &slave_connector_funcs,
DRM_MODE_CONNECTOR_HDMIA);
drm_connector_helper_add(connector, &slave_connector_helper_funcs);
connector->polled = DRM_CONNECTOR_POLL_CONNECT |
DRM_CONNECTOR_POLL_DISCONNECT;
connector->interlace_allowed = 0;
connector->doublescan_allowed = 0;
get_slave_funcs(encoder)->create_resources(encoder, connector);
ret = drm_mode_connector_attach_encoder(connector, encoder);
if (ret)
goto fail;
drm_connector_register(connector);
return connector;
fail:
slave_connector_destroy(connector);
return NULL;
}
static int slave_modeset_init(struct tilcdc_module *mod, struct drm_device *dev)
{
struct slave_module *slave_mod = to_slave_module(mod);
struct tilcdc_drm_private *priv = dev->dev_private;
struct drm_encoder *encoder;
struct drm_connector *connector;
encoder = slave_encoder_create(dev, slave_mod);
if (!encoder)
return -ENOMEM;
connector = slave_connector_create(dev, slave_mod, encoder);
if (!connector)
return -ENOMEM;
priv->encoders[priv->num_encoders++] = encoder;
priv->connectors[priv->num_connectors++] = connector;
return 0;
}
static int slave_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct device_node *i2c_node;
struct slave_module *slave_mod;
struct tilcdc_module *mod;
struct pinctrl *pinctrl;
uint32_t i2c_phandle;
struct i2c_adapter *slavei2c;
int ret = -EINVAL;
if (!node) {
dev_err(&pdev->dev, "device-tree data is missing\n");
return -ENXIO;
}
if (of_property_read_u32(node, "i2c", &i2c_phandle)) {
dev_err(&pdev->dev, "could not get i2c bus phandle\n");
return ret;
}
i2c_node = of_find_node_by_phandle(i2c_phandle);
if (!i2c_node) {
dev_err(&pdev->dev, "could not get i2c bus node\n");
return ret;
}
slavei2c = of_find_i2c_adapter_by_node(i2c_node);
of_node_put(i2c_node);
if (!slavei2c) {
ret = -EPROBE_DEFER;
tilcdc_slave_probedefer(true);
dev_err(&pdev->dev, "could not get i2c\n");
return ret;
}
slave_mod = kzalloc(sizeof(*slave_mod), GFP_KERNEL);
if (!slave_mod) {
ret = -ENOMEM;
goto fail_adapter;
}
mod = &slave_mod->base;
pdev->dev.platform_data = mod;
mod->preferred_bpp = slave_info.bpp;
slave_mod->i2c = slavei2c;
tilcdc_module_init(mod, "slave", &slave_module_ops);
pinctrl = devm_pinctrl_get_select_default(&pdev->dev);
if (IS_ERR(pinctrl))
dev_warn(&pdev->dev, "pins are not configured\n");
tilcdc_slave_probedefer(false);
return 0;
fail_adapter:
i2c_put_adapter(slavei2c);
return ret;
}
static int slave_remove(struct platform_device *pdev)
{
struct tilcdc_module *mod = dev_get_platdata(&pdev->dev);
struct slave_module *slave_mod = to_slave_module(mod);
tilcdc_module_cleanup(mod);
kfree(slave_mod);
return 0;
}
int __init tilcdc_slave_init(void)
{
return platform_driver_register(&slave_driver);
}
void __exit tilcdc_slave_fini(void)
{
platform_driver_unregister(&slave_driver);
}
