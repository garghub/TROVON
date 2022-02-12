static int rcar_du_lvds_connector_get_modes(struct drm_connector *connector)
{
struct rcar_du_lvds_connector *lvdscon =
to_rcar_lvds_connector(connector);
struct drm_display_mode *mode;
mode = drm_mode_create(connector->dev);
if (mode == NULL)
return 0;
mode->type = DRM_MODE_TYPE_PREFERRED | DRM_MODE_TYPE_DRIVER;
drm_display_mode_from_videomode(&lvdscon->panel.mode, mode);
drm_mode_probed_add(connector, mode);
return 1;
}
static void rcar_du_lvds_connector_destroy(struct drm_connector *connector)
{
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
}
static enum drm_connector_status
rcar_du_lvds_connector_detect(struct drm_connector *connector, bool force)
{
return connector_status_connected;
}
int rcar_du_lvds_connector_init(struct rcar_du_device *rcdu,
struct rcar_du_encoder *renc,
struct device_node *np)
{
struct drm_encoder *encoder = rcar_encoder_to_drm_encoder(renc);
struct rcar_du_lvds_connector *lvdscon;
struct drm_connector *connector;
struct display_timing timing;
int ret;
lvdscon = devm_kzalloc(rcdu->dev, sizeof(*lvdscon), GFP_KERNEL);
if (lvdscon == NULL)
return -ENOMEM;
ret = of_get_display_timing(np, "panel-timing", &timing);
if (ret < 0)
return ret;
videomode_from_timing(&timing, &lvdscon->panel.mode);
of_property_read_u32(np, "width-mm", &lvdscon->panel.width_mm);
of_property_read_u32(np, "height-mm", &lvdscon->panel.height_mm);
connector = &lvdscon->connector.connector;
connector->display_info.width_mm = lvdscon->panel.width_mm;
connector->display_info.height_mm = lvdscon->panel.height_mm;
ret = drm_connector_init(rcdu->ddev, connector, &connector_funcs,
DRM_MODE_CONNECTOR_LVDS);
if (ret < 0)
return ret;
drm_connector_helper_add(connector, &connector_helper_funcs);
ret = drm_connector_register(connector);
if (ret < 0)
return ret;
connector->dpms = DRM_MODE_DPMS_OFF;
drm_object_property_set_value(&connector->base,
rcdu->ddev->mode_config.dpms_property, DRM_MODE_DPMS_OFF);
ret = drm_mode_connector_attach_encoder(connector, encoder);
if (ret < 0)
return ret;
lvdscon->connector.encoder = renc;
return 0;
}
