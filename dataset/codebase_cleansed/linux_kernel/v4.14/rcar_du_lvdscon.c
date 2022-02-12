static int rcar_du_lvds_connector_get_modes(struct drm_connector *connector)
{
struct rcar_du_connector *rcon = to_rcar_connector(connector);
return drm_panel_get_modes(rcon->panel);
}
static void rcar_du_lvds_connector_destroy(struct drm_connector *connector)
{
struct rcar_du_connector *rcon = to_rcar_connector(connector);
drm_panel_detach(rcon->panel);
drm_connector_cleanup(connector);
}
int rcar_du_lvds_connector_init(struct rcar_du_device *rcdu,
struct rcar_du_encoder *renc,
const struct device_node *np)
{
struct drm_encoder *encoder = rcar_encoder_to_drm_encoder(renc);
struct rcar_du_connector *rcon;
struct drm_connector *connector;
int ret;
rcon = devm_kzalloc(rcdu->dev, sizeof(*rcon), GFP_KERNEL);
if (rcon == NULL)
return -ENOMEM;
connector = &rcon->connector;
rcon->panel = of_drm_find_panel(np);
if (!rcon->panel)
return -EPROBE_DEFER;
ret = drm_connector_init(rcdu->ddev, connector, &connector_funcs,
DRM_MODE_CONNECTOR_LVDS);
if (ret < 0)
return ret;
drm_connector_helper_add(connector, &connector_helper_funcs);
connector->dpms = DRM_MODE_DPMS_OFF;
drm_object_property_set_value(&connector->base,
rcdu->ddev->mode_config.dpms_property, DRM_MODE_DPMS_OFF);
ret = drm_mode_connector_attach_encoder(connector, encoder);
if (ret < 0)
return ret;
ret = drm_panel_attach(rcon->panel, connector);
if (ret < 0)
return ret;
rcon->encoder = renc;
return 0;
}
