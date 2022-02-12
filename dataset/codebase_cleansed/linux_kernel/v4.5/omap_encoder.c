struct omap_dss_device *omap_encoder_get_dssdev(struct drm_encoder *encoder)
{
struct omap_encoder *omap_encoder = to_omap_encoder(encoder);
return omap_encoder->dssdev;
}
static void omap_encoder_destroy(struct drm_encoder *encoder)
{
struct omap_encoder *omap_encoder = to_omap_encoder(encoder);
drm_encoder_cleanup(encoder);
kfree(omap_encoder);
}
static void omap_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = encoder->dev;
struct omap_encoder *omap_encoder = to_omap_encoder(encoder);
struct omap_dss_device *dssdev = omap_encoder->dssdev;
struct drm_connector *connector;
bool hdmi_mode;
int r;
hdmi_mode = false;
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
if (connector->encoder == encoder) {
hdmi_mode = omap_connector_get_hdmi_mode(connector);
break;
}
}
if (dssdev->driver->set_hdmi_mode)
dssdev->driver->set_hdmi_mode(dssdev, hdmi_mode);
if (hdmi_mode && dssdev->driver->set_hdmi_infoframe) {
struct hdmi_avi_infoframe avi;
r = drm_hdmi_avi_infoframe_from_display_mode(&avi, adjusted_mode);
if (r == 0)
dssdev->driver->set_hdmi_infoframe(dssdev, &avi);
}
}
static void omap_encoder_disable(struct drm_encoder *encoder)
{
struct omap_encoder *omap_encoder = to_omap_encoder(encoder);
struct omap_dss_device *dssdev = omap_encoder->dssdev;
struct omap_dss_driver *dssdrv = dssdev->driver;
dssdrv->disable(dssdev);
}
static int omap_encoder_update(struct drm_encoder *encoder,
enum omap_channel channel,
struct omap_video_timings *timings)
{
struct drm_device *dev = encoder->dev;
struct omap_encoder *omap_encoder = to_omap_encoder(encoder);
struct omap_dss_device *dssdev = omap_encoder->dssdev;
struct omap_dss_driver *dssdrv = dssdev->driver;
int ret;
if (dssdrv->check_timings) {
ret = dssdrv->check_timings(dssdev, timings);
} else {
struct omap_video_timings t = {0};
dssdrv->get_timings(dssdev, &t);
if (memcmp(timings, &t, sizeof(struct omap_video_timings)))
ret = -EINVAL;
else
ret = 0;
}
if (ret) {
dev_err(dev->dev, "could not set timings: %d\n", ret);
return ret;
}
if (dssdrv->set_timings)
dssdrv->set_timings(dssdev, timings);
return 0;
}
static void omap_encoder_enable(struct drm_encoder *encoder)
{
struct omap_encoder *omap_encoder = to_omap_encoder(encoder);
struct omap_dss_device *dssdev = omap_encoder->dssdev;
struct omap_dss_driver *dssdrv = dssdev->driver;
omap_encoder_update(encoder, omap_crtc_channel(encoder->crtc),
omap_crtc_timings(encoder->crtc));
dssdrv->enable(dssdev);
}
static int omap_encoder_atomic_check(struct drm_encoder *encoder,
struct drm_crtc_state *crtc_state,
struct drm_connector_state *conn_state)
{
return 0;
}
struct drm_encoder *omap_encoder_init(struct drm_device *dev,
struct omap_dss_device *dssdev)
{
struct drm_encoder *encoder = NULL;
struct omap_encoder *omap_encoder;
omap_encoder = kzalloc(sizeof(*omap_encoder), GFP_KERNEL);
if (!omap_encoder)
goto fail;
omap_encoder->dssdev = dssdev;
encoder = &omap_encoder->base;
drm_encoder_init(dev, encoder, &omap_encoder_funcs,
DRM_MODE_ENCODER_TMDS, NULL);
drm_encoder_helper_add(encoder, &omap_encoder_helper_funcs);
return encoder;
fail:
if (encoder)
omap_encoder_destroy(encoder);
return NULL;
}
