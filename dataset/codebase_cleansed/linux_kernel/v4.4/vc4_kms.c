static void vc4_output_poll_changed(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
if (vc4->fbdev)
drm_fbdev_cma_hotplug_event(vc4->fbdev);
}
int vc4_kms_load(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
int ret;
ret = drm_vblank_init(dev, dev->mode_config.num_crtc);
if (ret < 0) {
dev_err(dev->dev, "failed to initialize vblank\n");
return ret;
}
dev->mode_config.max_width = 2048;
dev->mode_config.max_height = 2048;
dev->mode_config.funcs = &vc4_mode_funcs;
dev->mode_config.preferred_depth = 24;
dev->vblank_disable_allowed = true;
drm_mode_config_reset(dev);
vc4->fbdev = drm_fbdev_cma_init(dev, 32,
dev->mode_config.num_crtc,
dev->mode_config.num_connector);
if (IS_ERR(vc4->fbdev))
vc4->fbdev = NULL;
drm_kms_helper_poll_init(dev);
return 0;
}
