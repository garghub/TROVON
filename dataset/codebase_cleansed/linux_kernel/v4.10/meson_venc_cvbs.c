static void meson_cvbs_connector_destroy(struct drm_connector *connector)
{
drm_connector_cleanup(connector);
}
static enum drm_connector_status
meson_cvbs_connector_detect(struct drm_connector *connector, bool force)
{
return connector_status_connected;
}
static int meson_cvbs_connector_get_modes(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct drm_display_mode *mode;
int i;
for (i = 0; i < MESON_CVBS_MODES_COUNT; ++i) {
struct meson_cvbs_mode *meson_mode = &meson_cvbs_modes[i];
mode = drm_mode_duplicate(dev, &meson_mode->mode);
if (!mode) {
DRM_ERROR("Failed to create a new display mode\n");
return 0;
}
drm_mode_probed_add(connector, mode);
}
return i;
}
static int meson_cvbs_connector_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
return MODE_OK;
}
static void meson_venc_cvbs_encoder_destroy(struct drm_encoder *encoder)
{
drm_encoder_cleanup(encoder);
}
static int meson_venc_cvbs_encoder_atomic_check(struct drm_encoder *encoder,
struct drm_crtc_state *crtc_state,
struct drm_connector_state *conn_state)
{
int i;
for (i = 0; i < MESON_CVBS_MODES_COUNT; ++i) {
struct meson_cvbs_mode *meson_mode = &meson_cvbs_modes[i];
if (drm_mode_equal(&crtc_state->mode, &meson_mode->mode))
return 0;
}
return -EINVAL;
}
static void meson_venc_cvbs_encoder_disable(struct drm_encoder *encoder)
{
struct meson_venc_cvbs *meson_venc_cvbs =
encoder_to_meson_venc_cvbs(encoder);
struct meson_drm *priv = meson_venc_cvbs->priv;
regmap_write(priv->hhi, HHI_VDAC_CNTL0, 0);
regmap_write(priv->hhi, HHI_VDAC_CNTL1, 8);
}
static void meson_venc_cvbs_encoder_enable(struct drm_encoder *encoder)
{
struct meson_venc_cvbs *meson_venc_cvbs =
encoder_to_meson_venc_cvbs(encoder);
struct meson_drm *priv = meson_venc_cvbs->priv;
writel_bits_relaxed(BIT(5), 0, priv->io_base + _REG(VENC_VDAC_DACSEL0));
if (meson_vpu_is_compatible(priv, "amlogic,meson-gxbb-vpu"))
regmap_write(priv->hhi, HHI_VDAC_CNTL0, 1);
else if (meson_vpu_is_compatible(priv, "amlogic,meson-gxm-vpu") ||
meson_vpu_is_compatible(priv, "amlogic,meson-gxl-vpu"))
regmap_write(priv->hhi, HHI_VDAC_CNTL0, 0xf0001);
regmap_write(priv->hhi, HHI_VDAC_CNTL1, 0);
}
static void meson_venc_cvbs_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct meson_venc_cvbs *meson_venc_cvbs =
encoder_to_meson_venc_cvbs(encoder);
int i;
for (i = 0; i < MESON_CVBS_MODES_COUNT; ++i) {
struct meson_cvbs_mode *meson_mode = &meson_cvbs_modes[i];
if (drm_mode_equal(mode, &meson_mode->mode)) {
meson_venci_cvbs_mode_set(meson_venc_cvbs->priv,
meson_mode->enci);
break;
}
}
}
static bool meson_venc_cvbs_connector_is_available(struct meson_drm *priv)
{
struct device_node *ep, *remote;
ep = of_graph_get_endpoint_by_regs(priv->dev->of_node, 0, 0);
if (!ep)
return false;
remote = of_graph_get_remote_port(ep);
if (remote) {
of_node_put(ep);
return true;
}
of_node_put(ep);
of_node_put(remote);
return false;
}
int meson_venc_cvbs_create(struct meson_drm *priv)
{
struct drm_device *drm = priv->drm;
struct meson_venc_cvbs *meson_venc_cvbs;
struct drm_connector *connector;
struct drm_encoder *encoder;
int ret;
if (!meson_venc_cvbs_connector_is_available(priv)) {
dev_info(drm->dev, "CVBS Output connector not available\n");
return -ENODEV;
}
meson_venc_cvbs = devm_kzalloc(priv->dev, sizeof(*meson_venc_cvbs),
GFP_KERNEL);
if (!meson_venc_cvbs)
return -ENOMEM;
meson_venc_cvbs->priv = priv;
encoder = &meson_venc_cvbs->encoder;
connector = &meson_venc_cvbs->connector;
drm_connector_helper_add(connector,
&meson_cvbs_connector_helper_funcs);
ret = drm_connector_init(drm, connector, &meson_cvbs_connector_funcs,
DRM_MODE_CONNECTOR_Composite);
if (ret) {
dev_err(priv->dev, "Failed to init CVBS connector\n");
return ret;
}
connector->interlace_allowed = 1;
drm_encoder_helper_add(encoder, &meson_venc_cvbs_encoder_helper_funcs);
ret = drm_encoder_init(drm, encoder, &meson_venc_cvbs_encoder_funcs,
DRM_MODE_ENCODER_TVDAC, "meson_venc_cvbs");
if (ret) {
dev_err(priv->dev, "Failed to init CVBS encoder\n");
return ret;
}
encoder->possible_crtcs = BIT(0);
drm_mode_connector_attach_encoder(connector, encoder);
return 0;
}
