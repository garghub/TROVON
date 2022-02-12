static int __init imx_fb_helper_init(void)
{
struct drm_device *drm = imx_drm_device_get();
if (!drm)
return -EINVAL;
if (legacyfb_depth != 16 && legacyfb_depth != 32) {
pr_warn("i.MX legacyfb: invalid legacyfb_depth setting. defaulting to 16bpp\n");
legacyfb_depth = 16;
}
fbdev_cma = drm_fbdev_cma_init(drm, legacyfb_depth,
drm->mode_config.num_crtc, MAX_CONNECTOR);
if (IS_ERR(fbdev_cma)) {
imx_drm_device_put();
return PTR_ERR(fbdev_cma);
}
imx_drm_fb_helper_set(fbdev_cma);
return 0;
}
static void __exit imx_fb_helper_exit(void)
{
imx_drm_fb_helper_set(NULL);
drm_fbdev_cma_fini(fbdev_cma);
imx_drm_device_put();
}
