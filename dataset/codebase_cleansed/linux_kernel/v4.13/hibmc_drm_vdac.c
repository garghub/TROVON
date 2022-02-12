static int hibmc_connector_get_modes(struct drm_connector *connector)
{
return drm_add_modes_noedid(connector, 800, 600);
}
static int hibmc_connector_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
return MODE_OK;
}
static struct drm_encoder *
hibmc_connector_best_encoder(struct drm_connector *connector)
{
return drm_encoder_find(connector->dev, connector->encoder_ids[0]);
}
static struct drm_connector *
hibmc_connector_init(struct hibmc_drm_private *priv)
{
struct drm_device *dev = priv->dev;
struct drm_connector *connector;
int ret;
connector = devm_kzalloc(dev->dev, sizeof(*connector), GFP_KERNEL);
if (!connector) {
DRM_ERROR("failed to alloc memory when init connector\n");
return ERR_PTR(-ENOMEM);
}
ret = drm_connector_init(dev, connector,
&hibmc_connector_funcs,
DRM_MODE_CONNECTOR_VGA);
if (ret) {
DRM_ERROR("failed to init connector: %d\n", ret);
return ERR_PTR(ret);
}
drm_connector_helper_add(connector,
&hibmc_connector_helper_funcs);
return connector;
}
static void hibmc_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adj_mode)
{
u32 reg;
struct drm_device *dev = encoder->dev;
struct hibmc_drm_private *priv = dev->dev_private;
reg = readl(priv->mmio + HIBMC_DISPLAY_CONTROL_HISILE);
reg |= HIBMC_DISPLAY_CONTROL_FPVDDEN(1);
reg |= HIBMC_DISPLAY_CONTROL_PANELDATE(1);
reg |= HIBMC_DISPLAY_CONTROL_FPEN(1);
reg |= HIBMC_DISPLAY_CONTROL_VBIASEN(1);
writel(reg, priv->mmio + HIBMC_DISPLAY_CONTROL_HISILE);
}
int hibmc_vdac_init(struct hibmc_drm_private *priv)
{
struct drm_device *dev = priv->dev;
struct drm_encoder *encoder;
struct drm_connector *connector;
int ret;
connector = hibmc_connector_init(priv);
if (IS_ERR(connector)) {
DRM_ERROR("failed to create connector: %ld\n",
PTR_ERR(connector));
return PTR_ERR(connector);
}
encoder = devm_kzalloc(dev->dev, sizeof(*encoder), GFP_KERNEL);
if (!encoder) {
DRM_ERROR("failed to alloc memory when init encoder\n");
return -ENOMEM;
}
encoder->possible_crtcs = 0x1;
ret = drm_encoder_init(dev, encoder, &hibmc_encoder_funcs,
DRM_MODE_ENCODER_DAC, NULL);
if (ret) {
DRM_ERROR("failed to init encoder: %d\n", ret);
return ret;
}
drm_encoder_helper_add(encoder, &hibmc_encoder_helper_funcs);
drm_mode_connector_attach_encoder(connector, encoder);
return 0;
}
