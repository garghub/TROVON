static int kirin_drm_kms_cleanup(struct drm_device *dev)
{
struct kirin_drm_private *priv = dev->dev_private;
#ifdef CONFIG_DRM_FBDEV_EMULATION
if (priv->fbdev) {
drm_fbdev_cma_fini(priv->fbdev);
priv->fbdev = NULL;
}
#endif
drm_kms_helper_poll_fini(dev);
drm_vblank_cleanup(dev);
dc_ops->cleanup(dev);
drm_mode_config_cleanup(dev);
devm_kfree(dev->dev, priv);
dev->dev_private = NULL;
return 0;
}
static void kirin_fbdev_output_poll_changed(struct drm_device *dev)
{
struct kirin_drm_private *priv = dev->dev_private;
if (priv->fbdev) {
drm_fbdev_cma_hotplug_event(priv->fbdev);
} else {
priv->fbdev = drm_fbdev_cma_init(dev, 32,
dev->mode_config.num_crtc,
dev->mode_config.num_connector);
if (IS_ERR(priv->fbdev))
priv->fbdev = NULL;
}
}
static void kirin_drm_mode_config_init(struct drm_device *dev)
{
dev->mode_config.min_width = 0;
dev->mode_config.min_height = 0;
dev->mode_config.max_width = 2048;
dev->mode_config.max_height = 2048;
dev->mode_config.funcs = &kirin_drm_mode_config_funcs;
}
static int kirin_drm_kms_init(struct drm_device *dev)
{
struct kirin_drm_private *priv;
int ret;
priv = devm_kzalloc(dev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
dev->dev_private = priv;
dev_set_drvdata(dev->dev, dev);
drm_mode_config_init(dev);
kirin_drm_mode_config_init(dev);
ret = dc_ops->init(dev);
if (ret)
goto err_mode_config_cleanup;
ret = component_bind_all(dev->dev, dev);
if (ret) {
DRM_ERROR("failed to bind all component.\n");
goto err_dc_cleanup;
}
ret = drm_vblank_init(dev, dev->mode_config.num_crtc);
if (ret) {
DRM_ERROR("failed to initialize vblank.\n");
goto err_unbind_all;
}
dev->irq_enabled = true;
drm_mode_config_reset(dev);
drm_kms_helper_poll_init(dev);
(void)drm_helper_hpd_irq_event(dev);
return 0;
err_unbind_all:
component_unbind_all(dev->dev, dev);
err_dc_cleanup:
dc_ops->cleanup(dev);
err_mode_config_cleanup:
drm_mode_config_cleanup(dev);
devm_kfree(dev->dev, priv);
dev->dev_private = NULL;
return ret;
}
static int kirin_gem_cma_dumb_create(struct drm_file *file,
struct drm_device *dev,
struct drm_mode_create_dumb *args)
{
return drm_gem_cma_dumb_create_internal(file, dev, args);
}
static int compare_of(struct device *dev, void *data)
{
return dev->of_node == data;
}
static int kirin_drm_bind(struct device *dev)
{
struct drm_driver *driver = &kirin_drm_driver;
struct drm_device *drm_dev;
int ret;
drm_dev = drm_dev_alloc(driver, dev);
if (IS_ERR(drm_dev))
return PTR_ERR(drm_dev);
drm_dev->platformdev = to_platform_device(dev);
ret = kirin_drm_kms_init(drm_dev);
if (ret)
goto err_drm_dev_unref;
ret = drm_dev_register(drm_dev, 0);
if (ret)
goto err_kms_cleanup;
DRM_INFO("Initialized %s %d.%d.%d %s on minor %d\n",
driver->name, driver->major, driver->minor, driver->patchlevel,
driver->date, drm_dev->primary->index);
return 0;
err_kms_cleanup:
kirin_drm_kms_cleanup(drm_dev);
err_drm_dev_unref:
drm_dev_unref(drm_dev);
return ret;
}
static void kirin_drm_unbind(struct device *dev)
{
struct drm_device *drm_dev = dev_get_drvdata(dev);
drm_dev_unregister(drm_dev);
kirin_drm_kms_cleanup(drm_dev);
drm_dev_unref(drm_dev);
}
static struct device_node *kirin_get_remote_node(struct device_node *np)
{
struct device_node *endpoint, *remote;
endpoint = of_graph_get_next_endpoint(np, NULL);
if (!endpoint) {
DRM_ERROR("no valid endpoint node\n");
return ERR_PTR(-ENODEV);
}
of_node_put(endpoint);
remote = of_graph_get_remote_port_parent(endpoint);
if (!remote) {
DRM_ERROR("no valid remote node\n");
return ERR_PTR(-ENODEV);
}
of_node_put(remote);
if (!of_device_is_available(remote)) {
DRM_ERROR("not available for remote node\n");
return ERR_PTR(-ENODEV);
}
return remote;
}
static int kirin_drm_platform_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct component_match *match = NULL;
struct device_node *remote;
dc_ops = (struct kirin_dc_ops *)of_device_get_match_data(dev);
if (!dc_ops) {
DRM_ERROR("failed to get dt id data\n");
return -EINVAL;
}
remote = kirin_get_remote_node(np);
if (IS_ERR(remote))
return PTR_ERR(remote);
component_match_add(dev, &match, compare_of, remote);
return component_master_add_with_match(dev, &kirin_drm_ops, match);
return 0;
}
static int kirin_drm_platform_remove(struct platform_device *pdev)
{
component_master_del(&pdev->dev, &kirin_drm_ops);
dc_ops = NULL;
return 0;
}
