static void imx_drm_driver_lastclose(struct drm_device *drm)
{
struct imx_drm_device *imxdrm = drm->dev_private;
drm_fbdev_cma_restore_mode(imxdrm->fbhelper);
}
void imx_drm_connector_destroy(struct drm_connector *connector)
{
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
}
void imx_drm_encoder_destroy(struct drm_encoder *encoder)
{
drm_encoder_cleanup(encoder);
}
static void imx_drm_output_poll_changed(struct drm_device *drm)
{
struct imx_drm_device *imxdrm = drm->dev_private;
drm_fbdev_cma_hotplug_event(imxdrm->fbhelper);
}
static int imx_drm_atomic_check(struct drm_device *dev,
struct drm_atomic_state *state)
{
int ret;
ret = drm_atomic_helper_check_modeset(dev, state);
if (ret)
return ret;
ret = drm_atomic_helper_check_planes(dev, state);
if (ret)
return ret;
ret = drm_atomic_helper_check_modeset(dev, state);
if (ret)
return ret;
ret = ipu_planes_assign_pre(dev, state);
if (ret)
return ret;
return ret;
}
static void imx_drm_atomic_commit_tail(struct drm_atomic_state *state)
{
struct drm_device *dev = state->dev;
struct drm_plane *plane;
struct drm_plane_state *old_plane_state;
bool plane_disabling = false;
int i;
drm_atomic_helper_commit_modeset_disables(dev, state);
drm_atomic_helper_commit_planes(dev, state,
DRM_PLANE_COMMIT_ACTIVE_ONLY |
DRM_PLANE_COMMIT_NO_DISABLE_AFTER_MODESET);
drm_atomic_helper_commit_modeset_enables(dev, state);
for_each_plane_in_state(state, plane, old_plane_state, i) {
if (drm_atomic_plane_disabling(old_plane_state, plane->state))
plane_disabling = true;
}
if (plane_disabling) {
drm_atomic_helper_wait_for_vblanks(dev, state);
for_each_plane_in_state(state, plane, old_plane_state, i)
ipu_plane_disable_deferred(plane);
}
drm_atomic_helper_commit_hw_done(state);
}
int imx_drm_encoder_parse_of(struct drm_device *drm,
struct drm_encoder *encoder, struct device_node *np)
{
uint32_t crtc_mask = drm_of_find_possible_crtcs(drm, np);
if (crtc_mask == 0)
return -EPROBE_DEFER;
encoder->possible_crtcs = crtc_mask;
encoder->possible_clones = ~0;
return 0;
}
static int compare_of(struct device *dev, void *data)
{
struct device_node *np = data;
if (strcmp(dev->driver->name, "imx-ipuv3-crtc") == 0) {
struct ipu_client_platformdata *pdata = dev->platform_data;
return pdata->of_node == np;
}
if (of_node_cmp(np->name, "lvds-channel") == 0) {
np = of_get_parent(np);
of_node_put(np);
}
return dev->of_node == np;
}
static int imx_drm_bind(struct device *dev)
{
struct drm_device *drm;
struct imx_drm_device *imxdrm;
int ret;
drm = drm_dev_alloc(&imx_drm_driver, dev);
if (IS_ERR(drm))
return PTR_ERR(drm);
imxdrm = devm_kzalloc(dev, sizeof(*imxdrm), GFP_KERNEL);
if (!imxdrm) {
ret = -ENOMEM;
goto err_unref;
}
imxdrm->drm = drm;
drm->dev_private = imxdrm;
drm->irq_enabled = true;
drm->mode_config.min_width = 1;
drm->mode_config.min_height = 1;
drm->mode_config.max_width = 4096;
drm->mode_config.max_height = 4096;
drm->mode_config.funcs = &imx_drm_mode_config_funcs;
drm->mode_config.helper_private = &imx_drm_mode_config_helpers;
drm_mode_config_init(drm);
ret = drm_vblank_init(drm, MAX_CRTC);
if (ret)
goto err_kms;
dev_set_drvdata(dev, drm);
ret = component_bind_all(dev, drm);
if (ret)
goto err_vblank;
drm_mode_config_reset(drm);
#if IS_ENABLED(CONFIG_DRM_FBDEV_EMULATION)
if (legacyfb_depth != 16 && legacyfb_depth != 32) {
dev_warn(dev, "Invalid legacyfb_depth. Defaulting to 16bpp\n");
legacyfb_depth = 16;
}
imxdrm->fbhelper = drm_fbdev_cma_init(drm, legacyfb_depth, MAX_CRTC);
if (IS_ERR(imxdrm->fbhelper)) {
ret = PTR_ERR(imxdrm->fbhelper);
imxdrm->fbhelper = NULL;
goto err_unbind;
}
#endif
drm_kms_helper_poll_init(drm);
ret = drm_dev_register(drm, 0);
if (ret)
goto err_fbhelper;
return 0;
err_fbhelper:
drm_kms_helper_poll_fini(drm);
#if IS_ENABLED(CONFIG_DRM_FBDEV_EMULATION)
if (imxdrm->fbhelper)
drm_fbdev_cma_fini(imxdrm->fbhelper);
err_unbind:
#endif
component_unbind_all(drm->dev, drm);
err_vblank:
drm_vblank_cleanup(drm);
err_kms:
drm_mode_config_cleanup(drm);
err_unref:
drm_dev_unref(drm);
return ret;
}
static void imx_drm_unbind(struct device *dev)
{
struct drm_device *drm = dev_get_drvdata(dev);
struct imx_drm_device *imxdrm = drm->dev_private;
drm_dev_unregister(drm);
drm_kms_helper_poll_fini(drm);
if (imxdrm->fbhelper)
drm_fbdev_cma_fini(imxdrm->fbhelper);
drm_mode_config_cleanup(drm);
component_unbind_all(drm->dev, drm);
dev_set_drvdata(dev, NULL);
drm_dev_unref(drm);
}
static int imx_drm_platform_probe(struct platform_device *pdev)
{
int ret = drm_of_component_probe(&pdev->dev, compare_of, &imx_drm_ops);
if (!ret)
ret = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(32));
return ret;
}
static int imx_drm_platform_remove(struct platform_device *pdev)
{
component_master_del(&pdev->dev, &imx_drm_ops);
return 0;
}
static int imx_drm_suspend(struct device *dev)
{
struct drm_device *drm_dev = dev_get_drvdata(dev);
struct imx_drm_device *imxdrm;
if (drm_dev == NULL)
return 0;
drm_kms_helper_poll_disable(drm_dev);
imxdrm = drm_dev->dev_private;
imxdrm->state = drm_atomic_helper_suspend(drm_dev);
if (IS_ERR(imxdrm->state)) {
drm_kms_helper_poll_enable(drm_dev);
return PTR_ERR(imxdrm->state);
}
return 0;
}
static int imx_drm_resume(struct device *dev)
{
struct drm_device *drm_dev = dev_get_drvdata(dev);
struct imx_drm_device *imx_drm;
if (drm_dev == NULL)
return 0;
imx_drm = drm_dev->dev_private;
drm_atomic_helper_resume(drm_dev, imx_drm->state);
drm_kms_helper_poll_enable(drm_dev);
return 0;
}
static int __init imx_drm_init(void)
{
return platform_register_drivers(drivers, ARRAY_SIZE(drivers));
}
static void __exit imx_drm_exit(void)
{
platform_unregister_drivers(drivers, ARRAY_SIZE(drivers));
}
