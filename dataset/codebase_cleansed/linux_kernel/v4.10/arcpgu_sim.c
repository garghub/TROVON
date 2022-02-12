static int arcpgu_drm_connector_get_modes(struct drm_connector *connector)
{
int count;
count = drm_add_modes_noedid(connector, XRES_MAX, YRES_MAX);
drm_set_preferred_mode(connector, XRES_DEF, YRES_DEF);
return count;
}
static void arcpgu_drm_connector_destroy(struct drm_connector *connector)
{
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
}
int arcpgu_drm_sim_init(struct drm_device *drm, struct device_node *np)
{
struct arcpgu_drm_connector *arcpgu_connector;
struct drm_encoder_slave *encoder;
struct drm_connector *connector;
int ret;
encoder = devm_kzalloc(drm->dev, sizeof(*encoder), GFP_KERNEL);
if (encoder == NULL)
return -ENOMEM;
encoder->base.possible_crtcs = 1;
encoder->base.possible_clones = 0;
ret = drm_encoder_init(drm, &encoder->base, &arcpgu_drm_encoder_funcs,
DRM_MODE_ENCODER_VIRTUAL, NULL);
if (ret)
return ret;
arcpgu_connector = devm_kzalloc(drm->dev, sizeof(*arcpgu_connector),
GFP_KERNEL);
if (!arcpgu_connector) {
ret = -ENOMEM;
goto error_encoder_cleanup;
}
connector = &arcpgu_connector->connector;
drm_connector_helper_add(connector, &arcpgu_drm_connector_helper_funcs);
ret = drm_connector_init(drm, connector, &arcpgu_drm_connector_funcs,
DRM_MODE_CONNECTOR_VIRTUAL);
if (ret < 0) {
dev_err(drm->dev, "failed to initialize drm connector\n");
goto error_encoder_cleanup;
}
ret = drm_mode_connector_attach_encoder(connector, &encoder->base);
if (ret < 0) {
dev_err(drm->dev, "could not attach connector to encoder\n");
drm_connector_unregister(connector);
goto error_connector_cleanup;
}
arcpgu_connector->encoder_slave = encoder;
return 0;
error_connector_cleanup:
drm_connector_cleanup(connector);
error_encoder_cleanup:
drm_encoder_cleanup(&encoder->base);
return ret;
}
