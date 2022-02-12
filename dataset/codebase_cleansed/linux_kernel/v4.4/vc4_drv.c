void __iomem *vc4_ioremap_regs(struct platform_device *dev, int index)
{
struct resource *res;
void __iomem *map;
res = platform_get_resource(dev, IORESOURCE_MEM, index);
map = devm_ioremap_resource(&dev->dev, res);
if (IS_ERR(map)) {
DRM_ERROR("Failed to map registers: %ld\n", PTR_ERR(map));
return map;
}
return map;
}
static void vc4_drm_preclose(struct drm_device *dev, struct drm_file *file)
{
struct drm_crtc *crtc;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head)
vc4_cancel_page_flip(crtc, file);
}
static void vc4_lastclose(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
if (vc4->fbdev)
drm_fbdev_cma_restore_mode(vc4->fbdev);
}
static int compare_dev(struct device *dev, void *data)
{
return dev == data;
}
static void vc4_match_add_drivers(struct device *dev,
struct component_match **match,
struct platform_driver *const *drivers,
int count)
{
int i;
for (i = 0; i < count; i++) {
struct device_driver *drv = &drivers[i]->driver;
struct device *p = NULL, *d;
while ((d = bus_find_device(&platform_bus_type, p, drv,
(void *)platform_bus_type.match))) {
put_device(p);
component_match_add(dev, match, compare_dev, d);
p = d;
}
put_device(p);
}
}
static int vc4_drm_bind(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct drm_device *drm;
struct drm_connector *connector;
struct vc4_dev *vc4;
int ret = 0;
dev->coherent_dma_mask = DMA_BIT_MASK(32);
vc4 = devm_kzalloc(dev, sizeof(*vc4), GFP_KERNEL);
if (!vc4)
return -ENOMEM;
drm = drm_dev_alloc(&vc4_drm_driver, dev);
if (!drm)
return -ENOMEM;
platform_set_drvdata(pdev, drm);
vc4->dev = drm;
drm->dev_private = vc4;
drm_dev_set_unique(drm, dev_name(dev));
drm_mode_config_init(drm);
if (ret)
goto unref;
ret = component_bind_all(dev, drm);
if (ret)
goto unref;
ret = drm_dev_register(drm, 0);
if (ret < 0)
goto unbind_all;
list_for_each_entry(connector, &drm->mode_config.connector_list, head) {
ret = drm_connector_register(connector);
if (ret)
goto unregister;
}
vc4_kms_load(drm);
return 0;
unregister:
drm_dev_unregister(drm);
unbind_all:
component_unbind_all(dev, drm);
unref:
drm_dev_unref(drm);
return ret;
}
static void vc4_drm_unbind(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct drm_device *drm = platform_get_drvdata(pdev);
struct vc4_dev *vc4 = to_vc4_dev(drm);
if (vc4->fbdev)
drm_fbdev_cma_fini(vc4->fbdev);
drm_mode_config_cleanup(drm);
drm_put_dev(drm);
}
static int vc4_platform_drm_probe(struct platform_device *pdev)
{
struct component_match *match = NULL;
struct device *dev = &pdev->dev;
vc4_match_add_drivers(dev, &match,
component_drivers, ARRAY_SIZE(component_drivers));
return component_master_add_with_match(dev, &vc4_drm_ops, match);
}
static int vc4_platform_drm_remove(struct platform_device *pdev)
{
component_master_del(&pdev->dev, &vc4_drm_ops);
return 0;
}
static int __init vc4_drm_register(void)
{
int i, ret;
for (i = 0; i < ARRAY_SIZE(component_drivers); i++) {
ret = platform_driver_register(component_drivers[i]);
if (ret) {
while (--i >= 0)
platform_driver_unregister(component_drivers[i]);
return ret;
}
}
return platform_driver_register(&vc4_platform_driver);
}
static void __exit vc4_drm_unregister(void)
{
int i;
for (i = ARRAY_SIZE(component_drivers) - 1; i >= 0; i--)
platform_driver_unregister(component_drivers[i]);
platform_driver_unregister(&vc4_platform_driver);
}
