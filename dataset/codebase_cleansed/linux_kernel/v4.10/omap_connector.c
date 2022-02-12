bool omap_connector_get_hdmi_mode(struct drm_connector *connector)
{
struct omap_connector *omap_connector = to_omap_connector(connector);
return omap_connector->hdmi_mode;
}
static enum drm_connector_status omap_connector_detect(
struct drm_connector *connector, bool force)
{
struct omap_connector *omap_connector = to_omap_connector(connector);
struct omap_dss_device *dssdev = omap_connector->dssdev;
struct omap_dss_driver *dssdrv = dssdev->driver;
enum drm_connector_status ret;
if (dssdrv->detect) {
if (dssdrv->detect(dssdev))
ret = connector_status_connected;
else
ret = connector_status_disconnected;
} else if (dssdev->type == OMAP_DISPLAY_TYPE_DPI ||
dssdev->type == OMAP_DISPLAY_TYPE_DBI ||
dssdev->type == OMAP_DISPLAY_TYPE_SDI ||
dssdev->type == OMAP_DISPLAY_TYPE_DSI) {
ret = connector_status_connected;
} else {
ret = connector_status_unknown;
}
VERB("%s: %d (force=%d)", omap_connector->dssdev->name, ret, force);
return ret;
}
static void omap_connector_destroy(struct drm_connector *connector)
{
struct omap_connector *omap_connector = to_omap_connector(connector);
struct omap_dss_device *dssdev = omap_connector->dssdev;
DBG("%s", omap_connector->dssdev->name);
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
kfree(omap_connector);
omap_dss_put_device(dssdev);
}
static int omap_connector_get_modes(struct drm_connector *connector)
{
struct omap_connector *omap_connector = to_omap_connector(connector);
struct omap_dss_device *dssdev = omap_connector->dssdev;
struct omap_dss_driver *dssdrv = dssdev->driver;
struct drm_device *dev = connector->dev;
int n = 0;
DBG("%s", omap_connector->dssdev->name);
if (dssdrv->read_edid) {
void *edid = kzalloc(MAX_EDID, GFP_KERNEL);
if ((dssdrv->read_edid(dssdev, edid, MAX_EDID) > 0) &&
drm_edid_is_valid(edid)) {
drm_mode_connector_update_edid_property(
connector, edid);
n = drm_add_edid_modes(connector, edid);
omap_connector->hdmi_mode =
drm_detect_hdmi_monitor(edid);
} else {
drm_mode_connector_update_edid_property(
connector, NULL);
}
kfree(edid);
} else {
struct drm_display_mode *mode = drm_mode_create(dev);
struct videomode vm = {0};
dssdrv->get_timings(dssdev, &vm);
drm_display_mode_from_videomode(&vm, mode);
mode->type = DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED;
drm_mode_set_name(mode);
drm_mode_probed_add(connector, mode);
n = 1;
}
return n;
}
static int omap_connector_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct omap_connector *omap_connector = to_omap_connector(connector);
struct omap_dss_device *dssdev = omap_connector->dssdev;
struct omap_dss_driver *dssdrv = dssdev->driver;
struct videomode vm = {0};
struct drm_device *dev = connector->dev;
struct drm_display_mode *new_mode;
int r, ret = MODE_BAD;
drm_display_mode_to_videomode(mode, &vm);
vm.flags |= DISPLAY_FLAGS_DE_HIGH | DISPLAY_FLAGS_PIXDATA_POSEDGE |
DISPLAY_FLAGS_SYNC_NEGEDGE;
mode->vrefresh = drm_mode_vrefresh(mode);
if (dssdrv->check_timings) {
r = dssdrv->check_timings(dssdev, &vm);
} else {
struct videomode t = {0};
dssdrv->get_timings(dssdev, &t);
if (memcmp(&vm, &t, sizeof(struct videomode)))
r = -EINVAL;
else
r = 0;
}
if (!r) {
new_mode = drm_mode_duplicate(dev, mode);
new_mode->clock = vm.pixelclock / 1000;
new_mode->vrefresh = 0;
if (mode->vrefresh == drm_mode_vrefresh(new_mode))
ret = MODE_OK;
drm_mode_destroy(dev, new_mode);
}
DBG("connector: mode %s: "
"%d:\"%s\" %d %d %d %d %d %d %d %d %d %d 0x%x 0x%x",
(ret == MODE_OK) ? "valid" : "invalid",
mode->base.id, mode->name, mode->vrefresh, mode->clock,
mode->hdisplay, mode->hsync_start,
mode->hsync_end, mode->htotal,
mode->vdisplay, mode->vsync_start,
mode->vsync_end, mode->vtotal, mode->type, mode->flags);
return ret;
}
struct drm_connector *omap_connector_init(struct drm_device *dev,
int connector_type, struct omap_dss_device *dssdev,
struct drm_encoder *encoder)
{
struct drm_connector *connector = NULL;
struct omap_connector *omap_connector;
DBG("%s", dssdev->name);
omap_dss_get_device(dssdev);
omap_connector = kzalloc(sizeof(struct omap_connector), GFP_KERNEL);
if (!omap_connector)
goto fail;
omap_connector->dssdev = dssdev;
connector = &omap_connector->base;
drm_connector_init(dev, connector, &omap_connector_funcs,
connector_type);
drm_connector_helper_add(connector, &omap_connector_helper_funcs);
#if 0
if (dssdev->caps & OMAP_DSS_DISPLAY_CAP_HPD)
connector->polled = 0;
else
#endif
connector->polled = DRM_CONNECTOR_POLL_CONNECT |
DRM_CONNECTOR_POLL_DISCONNECT;
connector->interlace_allowed = 1;
connector->doublescan_allowed = 0;
drm_connector_register(connector);
return connector;
fail:
if (connector)
omap_connector_destroy(connector);
return NULL;
}
