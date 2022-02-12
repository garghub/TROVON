static void tegra_drm_fb_output_poll_changed(struct drm_device *drm)
{
struct host1x *host1x = drm->dev_private;
drm_fbdev_cma_hotplug_event(host1x->fbdev);
}
int tegra_drm_fb_init(struct drm_device *drm)
{
struct host1x *host1x = drm->dev_private;
struct drm_fbdev_cma *fbdev;
drm->mode_config.min_width = 0;
drm->mode_config.min_height = 0;
drm->mode_config.max_width = 4096;
drm->mode_config.max_height = 4096;
drm->mode_config.funcs = &tegra_drm_mode_funcs;
fbdev = drm_fbdev_cma_init(drm, 32, drm->mode_config.num_crtc,
drm->mode_config.num_connector);
if (IS_ERR(fbdev))
return PTR_ERR(fbdev);
#ifndef CONFIG_FRAMEBUFFER_CONSOLE
drm_fbdev_cma_restore_mode(fbdev);
#endif
host1x->fbdev = fbdev;
return 0;
}
void tegra_drm_fb_exit(struct drm_device *drm)
{
struct host1x *host1x = drm->dev_private;
drm_fbdev_cma_fini(host1x->fbdev);
}
