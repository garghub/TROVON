void copy_timings_omap_to_drm(struct drm_display_mode *mode,
struct omap_video_timings *timings)
{
mode->clock = timings->pixel_clock;
mode->hdisplay = timings->x_res;
mode->hsync_start = mode->hdisplay + timings->hfp;
mode->hsync_end = mode->hsync_start + timings->hsw;
mode->htotal = mode->hsync_end + timings->hbp;
mode->vdisplay = timings->y_res;
mode->vsync_start = mode->vdisplay + timings->vfp;
mode->vsync_end = mode->vsync_start + timings->vsw;
mode->vtotal = mode->vsync_end + timings->vbp;
mode->flags = 0;
if (timings->interlace)
mode->flags |= DRM_MODE_FLAG_INTERLACE;
if (timings->hsync_level == OMAPDSS_SIG_ACTIVE_HIGH)
mode->flags |= DRM_MODE_FLAG_PHSYNC;
else
mode->flags |= DRM_MODE_FLAG_NHSYNC;
if (timings->vsync_level == OMAPDSS_SIG_ACTIVE_HIGH)
mode->flags |= DRM_MODE_FLAG_PVSYNC;
else
mode->flags |= DRM_MODE_FLAG_NVSYNC;
}
void copy_timings_drm_to_omap(struct omap_video_timings *timings,
struct drm_display_mode *mode)
{
timings->pixel_clock = mode->clock;
timings->x_res = mode->hdisplay;
timings->hfp = mode->hsync_start - mode->hdisplay;
timings->hsw = mode->hsync_end - mode->hsync_start;
timings->hbp = mode->htotal - mode->hsync_end;
timings->y_res = mode->vdisplay;
timings->vfp = mode->vsync_start - mode->vdisplay;
timings->vsw = mode->vsync_end - mode->vsync_start;
timings->vbp = mode->vtotal - mode->vsync_end;
timings->interlace = !!(mode->flags & DRM_MODE_FLAG_INTERLACE);
if (mode->flags & DRM_MODE_FLAG_PHSYNC)
timings->hsync_level = OMAPDSS_SIG_ACTIVE_HIGH;
else
timings->hsync_level = OMAPDSS_SIG_ACTIVE_LOW;
if (mode->flags & DRM_MODE_FLAG_PVSYNC)
timings->vsync_level = OMAPDSS_SIG_ACTIVE_HIGH;
else
timings->vsync_level = OMAPDSS_SIG_ACTIVE_LOW;
timings->data_pclk_edge = OMAPDSS_DRIVE_SIG_RISING_EDGE;
timings->de_level = OMAPDSS_SIG_ACTIVE_HIGH;
timings->sync_pclk_edge = OMAPDSS_DRIVE_SIG_OPPOSITE_EDGES;
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
drm_sysfs_connector_remove(connector);
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
} else {
drm_mode_connector_update_edid_property(
connector, NULL);
}
kfree(edid);
} else {
struct drm_display_mode *mode = drm_mode_create(dev);
struct omap_video_timings timings = {0};
dssdrv->get_timings(dssdev, &timings);
copy_timings_omap_to_drm(mode, &timings);
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
struct omap_video_timings timings = {0};
struct drm_device *dev = connector->dev;
struct drm_display_mode *new_mode;
int ret = MODE_BAD;
copy_timings_drm_to_omap(&timings, mode);
mode->vrefresh = drm_mode_vrefresh(mode);
if (!dssdrv->check_timings(dssdev, &timings)) {
new_mode = drm_mode_duplicate(dev, mode);
new_mode->clock = timings.pixel_clock;
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
struct drm_encoder *omap_connector_attached_encoder(
struct drm_connector *connector)
{
struct omap_connector *omap_connector = to_omap_connector(connector);
return omap_connector->encoder;
}
void omap_connector_flush(struct drm_connector *connector,
int x, int y, int w, int h)
{
struct omap_connector *omap_connector = to_omap_connector(connector);
VERB("%s: %d,%d, %dx%d", omap_connector->dssdev->name, x, y, w, h);
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
if (!omap_connector) {
dev_err(dev->dev, "could not allocate connector\n");
goto fail;
}
omap_connector->dssdev = dssdev;
omap_connector->encoder = encoder;
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
drm_sysfs_connector_add(connector);
return connector;
fail:
if (connector)
omap_connector_destroy(connector);
return NULL;
}
