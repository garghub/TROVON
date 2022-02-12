static void zx_drm_fb_output_poll_changed(struct drm_device *drm)
{
struct zx_drm_private *priv = drm->dev_private;
drm_fbdev_cma_hotplug_event(priv->fbdev);
}
static void zx_drm_lastclose(struct drm_device *drm)
{
struct zx_drm_private *priv = drm->dev_private;
drm_fbdev_cma_restore_mode(priv->fbdev);
}
static int zx_drm_bind(struct device *dev)
{
struct drm_device *drm;
struct zx_drm_private *priv;
int ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
drm = drm_dev_alloc(&zx_drm_driver, dev);
if (IS_ERR(drm))
return PTR_ERR(drm);
drm->dev_private = priv;
dev_set_drvdata(dev, drm);
drm_mode_config_init(drm);
drm->mode_config.min_width = 16;
drm->mode_config.min_height = 16;
drm->mode_config.max_width = 4096;
drm->mode_config.max_height = 4096;
drm->mode_config.funcs = &zx_drm_mode_config_funcs;
ret = component_bind_all(dev, drm);
if (ret) {
DRM_DEV_ERROR(dev, "failed to bind all components: %d\n", ret);
goto out_unregister;
}
ret = drm_vblank_init(drm, drm->mode_config.num_crtc);
if (ret < 0) {
DRM_DEV_ERROR(dev, "failed to init vblank: %d\n", ret);
goto out_unbind;
}
drm->irq_enabled = true;
drm_mode_config_reset(drm);
drm_kms_helper_poll_init(drm);
priv->fbdev = drm_fbdev_cma_init(drm, 32,
drm->mode_config.num_connector);
if (IS_ERR(priv->fbdev)) {
ret = PTR_ERR(priv->fbdev);
DRM_DEV_ERROR(dev, "failed to init cma fbdev: %d\n", ret);
priv->fbdev = NULL;
goto out_poll_fini;
}
ret = drm_dev_register(drm, 0);
if (ret)
goto out_fbdev_fini;
return 0;
out_fbdev_fini:
if (priv->fbdev) {
drm_fbdev_cma_fini(priv->fbdev);
priv->fbdev = NULL;
}
out_poll_fini:
drm_kms_helper_poll_fini(drm);
drm_mode_config_cleanup(drm);
out_unbind:
component_unbind_all(dev, drm);
out_unregister:
dev_set_drvdata(dev, NULL);
drm->dev_private = NULL;
drm_dev_unref(drm);
return ret;
}
static void zx_drm_unbind(struct device *dev)
{
struct drm_device *drm = dev_get_drvdata(dev);
struct zx_drm_private *priv = drm->dev_private;
drm_dev_unregister(drm);
if (priv->fbdev) {
drm_fbdev_cma_fini(priv->fbdev);
priv->fbdev = NULL;
}
drm_kms_helper_poll_fini(drm);
drm_mode_config_cleanup(drm);
component_unbind_all(dev, drm);
dev_set_drvdata(dev, NULL);
drm->dev_private = NULL;
drm_dev_unref(drm);
}
static int compare_of(struct device *dev, void *data)
{
return dev->of_node == data;
}
static int zx_drm_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *parent = dev->of_node;
struct device_node *child;
struct component_match *match = NULL;
int ret;
ret = devm_of_platform_populate(dev);
if (ret)
return ret;
for_each_available_child_of_node(parent, child) {
component_match_add(dev, &match, compare_of, child);
of_node_put(child);
}
return component_master_add_with_match(dev, &zx_drm_master_ops, match);
}
static int zx_drm_remove(struct platform_device *pdev)
{
component_master_del(&pdev->dev, &zx_drm_master_ops);
return 0;
}
static int zx_drm_init(void)
{
return platform_register_drivers(drivers, ARRAY_SIZE(drivers));
}
static void zx_drm_exit(void)
{
platform_unregister_drivers(drivers, ARRAY_SIZE(drivers));
}
