static int rcar_du_vga_connector_get_modes(struct drm_connector *connector)
{
return 0;
}
static void rcar_du_vga_connector_destroy(struct drm_connector *connector)
{
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
}
static enum drm_connector_status
rcar_du_vga_connector_detect(struct drm_connector *connector, bool force)
{
return connector_status_connected;
}
int rcar_du_vga_connector_init(struct rcar_du_device *rcdu,
struct rcar_du_encoder *renc)
{
struct drm_encoder *encoder = rcar_encoder_to_drm_encoder(renc);
struct rcar_du_connector *rcon;
struct drm_connector *connector;
int ret;
rcon = devm_kzalloc(rcdu->dev, sizeof(*rcon), GFP_KERNEL);
if (rcon == NULL)
return -ENOMEM;
connector = &rcon->connector;
connector->display_info.width_mm = 0;
connector->display_info.height_mm = 0;
connector->interlace_allowed = true;
ret = drm_connector_init(rcdu->ddev, connector, &connector_funcs,
DRM_MODE_CONNECTOR_VGA);
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
rcon->encoder = renc;
return 0;
}
