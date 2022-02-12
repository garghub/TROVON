static void omap_encoder_destroy(struct drm_encoder *encoder)
{
struct omap_encoder *omap_encoder = to_omap_encoder(encoder);
DBG("%s", omap_encoder->mgr->name);
drm_encoder_cleanup(encoder);
kfree(omap_encoder);
}
static void omap_encoder_dpms(struct drm_encoder *encoder, int mode)
{
struct omap_encoder *omap_encoder = to_omap_encoder(encoder);
DBG("%s: %d", omap_encoder->mgr->name, mode);
}
static bool omap_encoder_mode_fixup(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct omap_encoder *omap_encoder = to_omap_encoder(encoder);
DBG("%s", omap_encoder->mgr->name);
return true;
}
static void omap_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct omap_encoder *omap_encoder = to_omap_encoder(encoder);
struct drm_device *dev = encoder->dev;
struct omap_drm_private *priv = dev->dev_private;
int i;
mode = adjusted_mode;
DBG("%s: set mode: %dx%d", omap_encoder->mgr->name,
mode->hdisplay, mode->vdisplay);
for (i = 0; i < priv->num_connectors; i++) {
struct drm_connector *connector = priv->connectors[i];
if (connector->encoder == encoder) {
omap_connector_mode_set(connector, mode);
}
}
}
static void omap_encoder_prepare(struct drm_encoder *encoder)
{
struct omap_encoder *omap_encoder = to_omap_encoder(encoder);
struct drm_encoder_helper_funcs *encoder_funcs =
encoder->helper_private;
DBG("%s", omap_encoder->mgr->name);
encoder_funcs->dpms(encoder, DRM_MODE_DPMS_OFF);
}
static void omap_encoder_commit(struct drm_encoder *encoder)
{
struct omap_encoder *omap_encoder = to_omap_encoder(encoder);
struct drm_encoder_helper_funcs *encoder_funcs =
encoder->helper_private;
DBG("%s", omap_encoder->mgr->name);
omap_encoder->mgr->apply(omap_encoder->mgr);
encoder_funcs->dpms(encoder, DRM_MODE_DPMS_ON);
}
struct omap_overlay_manager *omap_encoder_get_manager(
struct drm_encoder *encoder)
{
struct omap_encoder *omap_encoder = to_omap_encoder(encoder);
return omap_encoder->mgr;
}
struct drm_encoder *omap_encoder_init(struct drm_device *dev,
struct omap_overlay_manager *mgr)
{
struct drm_encoder *encoder = NULL;
struct omap_encoder *omap_encoder;
struct omap_overlay_manager_info info;
int ret;
DBG("%s", mgr->name);
omap_encoder = kzalloc(sizeof(*omap_encoder), GFP_KERNEL);
if (!omap_encoder) {
dev_err(dev->dev, "could not allocate encoder\n");
goto fail;
}
omap_encoder->mgr = mgr;
encoder = &omap_encoder->base;
drm_encoder_init(dev, encoder, &omap_encoder_funcs,
DRM_MODE_ENCODER_TMDS);
drm_encoder_helper_add(encoder, &omap_encoder_helper_funcs);
mgr->get_manager_info(mgr, &info);
info.default_color = 0x00000000;
info.trans_key = 0x00000000;
info.trans_key_type = OMAP_DSS_COLOR_KEY_GFX_DST;
info.trans_enabled = false;
ret = mgr->set_manager_info(mgr, &info);
if (ret) {
dev_err(dev->dev, "could not set manager info\n");
goto fail;
}
ret = mgr->apply(mgr);
if (ret) {
dev_err(dev->dev, "could not apply\n");
goto fail;
}
return encoder;
fail:
if (encoder) {
omap_encoder_destroy(encoder);
}
return NULL;
}
