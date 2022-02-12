static void sti_drm_mode_config_init(struct drm_device *dev)
{
dev->mode_config.min_width = 0;
dev->mode_config.min_height = 0;
dev->mode_config.max_width = STI_MAX_FB_HEIGHT;
dev->mode_config.max_height = STI_MAX_FB_WIDTH;
dev->mode_config.funcs = &sti_drm_mode_config_funcs;
}
static int sti_drm_load(struct drm_device *dev, unsigned long flags)
{
struct sti_drm_private *private;
int ret;
private = kzalloc(sizeof(struct sti_drm_private), GFP_KERNEL);
if (!private) {
DRM_ERROR("Failed to allocate private\n");
return -ENOMEM;
}
dev->dev_private = (void *)private;
private->drm_dev = dev;
drm_mode_config_init(dev);
drm_kms_helper_poll_init(dev);
sti_drm_mode_config_init(dev);
ret = component_bind_all(dev->dev, dev);
if (ret)
return ret;
drm_helper_disable_unused_functions(dev);
#ifdef CONFIG_DRM_STI_FBDEV
drm_fbdev_cma_init(dev, 32,
dev->mode_config.num_crtc,
dev->mode_config.num_connector);
#endif
return 0;
}
static struct dma_buf *sti_drm_gem_prime_export(struct drm_device *dev,
struct drm_gem_object *obj,
int flags)
{
flags |= O_RDWR;
return drm_gem_prime_export(dev, obj, flags);
}
static int compare_of(struct device *dev, void *data)
{
return dev->of_node == data;
}
static int sti_drm_bind(struct device *dev)
{
return drm_platform_init(&sti_drm_driver, to_platform_device(dev));
}
static void sti_drm_unbind(struct device *dev)
{
drm_put_dev(dev_get_drvdata(dev));
}
static int sti_drm_master_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = dev->parent->of_node;
struct device_node *child_np;
struct component_match *match = NULL;
dma_set_coherent_mask(dev, DMA_BIT_MASK(32));
child_np = of_get_next_available_child(node, NULL);
while (child_np) {
component_match_add(dev, &match, compare_of, child_np);
of_node_put(child_np);
child_np = of_get_next_available_child(node, child_np);
}
return component_master_add_with_match(dev, &sti_drm_ops, match);
}
static int sti_drm_master_remove(struct platform_device *pdev)
{
component_master_del(&pdev->dev, &sti_drm_ops);
return 0;
}
static int sti_drm_platform_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct platform_device *master;
of_platform_populate(node, NULL, NULL, dev);
platform_driver_register(&sti_drm_master_driver);
master = platform_device_register_resndata(dev,
DRIVER_NAME "__master", -1,
NULL, 0, NULL, 0);
if (IS_ERR(master))
return PTR_ERR(master);
platform_set_drvdata(pdev, master);
return 0;
}
static int sti_drm_platform_remove(struct platform_device *pdev)
{
struct platform_device *master = platform_get_drvdata(pdev);
of_platform_depopulate(&pdev->dev);
platform_device_unregister(master);
platform_driver_unregister(&sti_drm_master_driver);
return 0;
}
