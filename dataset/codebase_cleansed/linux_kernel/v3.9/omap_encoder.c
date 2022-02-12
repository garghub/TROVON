static void omap_encoder_destroy(struct drm_encoder *encoder)
{
struct omap_encoder *omap_encoder = to_omap_encoder(encoder);
drm_encoder_cleanup(encoder);
kfree(omap_encoder);
}
static void omap_encoder_dpms(struct drm_encoder *encoder, int mode)
{
}
static bool omap_encoder_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static void omap_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
}
static void omap_encoder_prepare(struct drm_encoder *encoder)
{
}
static void omap_encoder_commit(struct drm_encoder *encoder)
{
}
int omap_encoder_set_enabled(struct drm_encoder *encoder, bool enabled)
{
struct omap_encoder *omap_encoder = to_omap_encoder(encoder);
struct omap_dss_device *dssdev = omap_encoder->dssdev;
struct omap_dss_driver *dssdrv = dssdev->driver;
if (enabled) {
return dssdrv->enable(dssdev);
} else {
dssdrv->disable(dssdev);
return 0;
}
}
int omap_encoder_update(struct drm_encoder *encoder,
struct omap_overlay_manager *mgr,
struct omap_video_timings *timings)
{
struct drm_device *dev = encoder->dev;
struct omap_encoder *omap_encoder = to_omap_encoder(encoder);
struct omap_dss_device *dssdev = omap_encoder->dssdev;
struct omap_dss_driver *dssdrv = dssdev->driver;
int ret;
dssdev->output->manager = mgr;
ret = dssdrv->check_timings(dssdev, timings);
if (ret) {
dev_err(dev->dev, "could not set timings: %d\n", ret);
return ret;
}
dssdrv->set_timings(dssdev, timings);
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
DRM_MODE_ENCODER_TMDS);
drm_encoder_helper_add(encoder, &omap_encoder_helper_funcs);
return encoder;
fail:
if (encoder)
omap_encoder_destroy(encoder);
return NULL;
}
