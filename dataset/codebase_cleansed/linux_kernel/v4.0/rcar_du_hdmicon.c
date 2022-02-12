static int rcar_du_hdmi_connector_get_modes(struct drm_connector *connector)
{
struct rcar_du_connector *con = to_rcar_connector(connector);
struct drm_encoder *encoder = rcar_encoder_to_drm_encoder(con->encoder);
struct drm_encoder_slave_funcs *sfuncs = to_slave_funcs(encoder);
if (sfuncs->get_modes == NULL)
return 0;
return sfuncs->get_modes(encoder, connector);
}
static int rcar_du_hdmi_connector_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct rcar_du_connector *con = to_rcar_connector(connector);
struct drm_encoder *encoder = rcar_encoder_to_drm_encoder(con->encoder);
struct drm_encoder_slave_funcs *sfuncs = to_slave_funcs(encoder);
if (sfuncs->mode_valid == NULL)
return MODE_OK;
return sfuncs->mode_valid(encoder, mode);
}
static void rcar_du_hdmi_connector_destroy(struct drm_connector *connector)
{
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
}
static enum drm_connector_status
rcar_du_hdmi_connector_detect(struct drm_connector *connector, bool force)
{
struct rcar_du_connector *con = to_rcar_connector(connector);
struct drm_encoder *encoder = rcar_encoder_to_drm_encoder(con->encoder);
struct drm_encoder_slave_funcs *sfuncs = to_slave_funcs(encoder);
if (sfuncs->detect == NULL)
return connector_status_unknown;
return sfuncs->detect(encoder, connector);
}
int rcar_du_hdmi_connector_init(struct rcar_du_device *rcdu,
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
connector->polled = DRM_CONNECTOR_POLL_HPD;
ret = drm_connector_init(rcdu->ddev, connector, &connector_funcs,
DRM_MODE_CONNECTOR_HDMIA);
if (ret < 0)
return ret;
drm_connector_helper_add(connector, &connector_helper_funcs);
ret = drm_connector_register(connector);
if (ret < 0)
return ret;
drm_helper_connector_dpms(connector, DRM_MODE_DPMS_OFF);
drm_object_property_set_value(&connector->base,
rcdu->ddev->mode_config.dpms_property, DRM_MODE_DPMS_OFF);
ret = drm_mode_connector_attach_encoder(connector, encoder);
if (ret < 0)
return ret;
connector->encoder = encoder;
rcon->encoder = renc;
return 0;
}
