static int rcar_du_lvds_connector_get_modes(struct drm_connector *connector)
{
struct rcar_du_lvds_connector *lvdscon =
to_rcar_lvds_connector(connector);
struct drm_display_mode *mode;
mode = drm_mode_create(connector->dev);
if (mode == NULL)
return 0;
mode->type = DRM_MODE_TYPE_PREFERRED | DRM_MODE_TYPE_DRIVER;
mode->clock = lvdscon->panel->mode.clock;
mode->hdisplay = lvdscon->panel->mode.hdisplay;
mode->hsync_start = lvdscon->panel->mode.hsync_start;
mode->hsync_end = lvdscon->panel->mode.hsync_end;
mode->htotal = lvdscon->panel->mode.htotal;
mode->vdisplay = lvdscon->panel->mode.vdisplay;
mode->vsync_start = lvdscon->panel->mode.vsync_start;
mode->vsync_end = lvdscon->panel->mode.vsync_end;
mode->vtotal = lvdscon->panel->mode.vtotal;
mode->flags = lvdscon->panel->mode.flags;
drm_mode_set_name(mode);
drm_mode_probed_add(connector, mode);
return 1;
}
static void rcar_du_lvds_connector_destroy(struct drm_connector *connector)
{
drm_sysfs_connector_remove(connector);
drm_connector_cleanup(connector);
}
static enum drm_connector_status
rcar_du_lvds_connector_detect(struct drm_connector *connector, bool force)
{
return connector_status_connected;
}
int rcar_du_lvds_connector_init(struct rcar_du_device *rcdu,
struct rcar_du_encoder *renc,
const struct rcar_du_panel_data *panel)
{
struct rcar_du_lvds_connector *lvdscon;
struct drm_connector *connector;
int ret;
lvdscon = devm_kzalloc(rcdu->dev, sizeof(*lvdscon), GFP_KERNEL);
if (lvdscon == NULL)
return -ENOMEM;
lvdscon->panel = panel;
connector = &lvdscon->connector.connector;
connector->display_info.width_mm = panel->width_mm;
connector->display_info.height_mm = panel->height_mm;
ret = drm_connector_init(rcdu->ddev, connector, &connector_funcs,
DRM_MODE_CONNECTOR_LVDS);
if (ret < 0)
return ret;
drm_connector_helper_add(connector, &connector_helper_funcs);
ret = drm_sysfs_connector_add(connector);
if (ret < 0)
return ret;
drm_helper_connector_dpms(connector, DRM_MODE_DPMS_OFF);
drm_object_property_set_value(&connector->base,
rcdu->ddev->mode_config.dpms_property, DRM_MODE_DPMS_OFF);
ret = drm_mode_connector_attach_encoder(connector, &renc->encoder);
if (ret < 0)
return ret;
connector->encoder = &renc->encoder;
lvdscon->connector.encoder = renc;
return 0;
}
