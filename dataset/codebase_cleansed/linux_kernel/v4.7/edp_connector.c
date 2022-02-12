static enum drm_connector_status edp_connector_detect(
struct drm_connector *connector, bool force)
{
struct edp_connector *edp_connector = to_edp_connector(connector);
struct msm_edp *edp = edp_connector->edp;
DBG("");
return msm_edp_ctrl_panel_connected(edp->ctrl) ?
connector_status_connected : connector_status_disconnected;
}
static void edp_connector_destroy(struct drm_connector *connector)
{
struct edp_connector *edp_connector = to_edp_connector(connector);
DBG("");
drm_connector_cleanup(connector);
kfree(edp_connector);
}
static int edp_connector_get_modes(struct drm_connector *connector)
{
struct edp_connector *edp_connector = to_edp_connector(connector);
struct msm_edp *edp = edp_connector->edp;
struct edid *drm_edid = NULL;
int ret = 0;
DBG("");
ret = msm_edp_ctrl_get_panel_info(edp->ctrl, connector, &drm_edid);
if (ret)
return ret;
drm_mode_connector_update_edid_property(connector, drm_edid);
if (drm_edid)
ret = drm_add_edid_modes(connector, drm_edid);
return ret;
}
static int edp_connector_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct edp_connector *edp_connector = to_edp_connector(connector);
struct msm_edp *edp = edp_connector->edp;
struct msm_drm_private *priv = connector->dev->dev_private;
struct msm_kms *kms = priv->kms;
long actual, requested;
requested = 1000 * mode->clock;
actual = kms->funcs->round_pixclk(kms,
requested, edp_connector->edp->encoder);
DBG("requested=%ld, actual=%ld", requested, actual);
if (actual != requested)
return MODE_CLOCK_RANGE;
if (!msm_edp_ctrl_pixel_clock_valid(
edp->ctrl, mode->clock, NULL, NULL))
return MODE_CLOCK_RANGE;
if (connector->display_info.bpc > 8)
return MODE_BAD;
return MODE_OK;
}
static struct drm_encoder *
edp_connector_best_encoder(struct drm_connector *connector)
{
struct edp_connector *edp_connector = to_edp_connector(connector);
DBG("");
return edp_connector->edp->encoder;
}
struct drm_connector *msm_edp_connector_init(struct msm_edp *edp)
{
struct drm_connector *connector = NULL;
struct edp_connector *edp_connector;
int ret;
edp_connector = kzalloc(sizeof(*edp_connector), GFP_KERNEL);
if (!edp_connector)
return ERR_PTR(-ENOMEM);
edp_connector->edp = edp;
connector = &edp_connector->base;
ret = drm_connector_init(edp->dev, connector, &edp_connector_funcs,
DRM_MODE_CONNECTOR_eDP);
if (ret)
return ERR_PTR(ret);
drm_connector_helper_add(connector, &edp_connector_helper_funcs);
connector->polled = DRM_CONNECTOR_POLL_CONNECT;
connector->interlace_allowed = false;
connector->doublescan_allowed = false;
drm_mode_connector_attach_encoder(connector, edp->encoder);
return connector;
}
