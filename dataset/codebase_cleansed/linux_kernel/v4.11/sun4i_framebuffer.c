static void sun4i_de_output_poll_changed(struct drm_device *drm)
{
struct sun4i_drv *drv = drm->dev_private;
drm_fbdev_cma_hotplug_event(drv->fbdev);
}
struct drm_fbdev_cma *sun4i_framebuffer_init(struct drm_device *drm)
{
drm_mode_config_reset(drm);
drm->mode_config.max_width = 8192;
drm->mode_config.max_height = 8192;
drm->mode_config.funcs = &sun4i_de_mode_config_funcs;
return drm_fbdev_cma_init(drm, 32, drm->mode_config.num_connector);
}
void sun4i_framebuffer_free(struct drm_device *drm)
{
struct sun4i_drv *drv = drm->dev_private;
drm_fbdev_cma_fini(drv->fbdev);
drm_mode_config_cleanup(drm);
}
