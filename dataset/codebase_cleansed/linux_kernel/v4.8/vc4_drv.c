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
static int vc4_get_param_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct drm_vc4_get_param *args = data;
int ret;
if (args->pad != 0)
return -EINVAL;
switch (args->param) {
case DRM_VC4_PARAM_V3D_IDENT0:
ret = pm_runtime_get_sync(&vc4->v3d->pdev->dev);
if (ret < 0)
return ret;
args->value = V3D_READ(V3D_IDENT0);
pm_runtime_put(&vc4->v3d->pdev->dev);
break;
case DRM_VC4_PARAM_V3D_IDENT1:
ret = pm_runtime_get_sync(&vc4->v3d->pdev->dev);
if (ret < 0)
return ret;
args->value = V3D_READ(V3D_IDENT1);
pm_runtime_put(&vc4->v3d->pdev->dev);
break;
case DRM_VC4_PARAM_V3D_IDENT2:
ret = pm_runtime_get_sync(&vc4->v3d->pdev->dev);
if (ret < 0)
return ret;
args->value = V3D_READ(V3D_IDENT2);
pm_runtime_put(&vc4->v3d->pdev->dev);
break;
case DRM_VC4_PARAM_SUPPORTS_BRANCHES:
args->value = true;
break;
default:
DRM_DEBUG("Unknown parameter %d\n", args->param);
return -EINVAL;
}
return 0;
}
static void vc4_lastclose(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
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
static void vc4_kick_out_firmware_fb(void)
{
struct apertures_struct *ap;
ap = alloc_apertures(1);
if (!ap)
return;
ap->ranges[0].base = 0;
ap->ranges[0].size = ~0;
remove_conflicting_framebuffers(ap, "vc4drmfb", false);
kfree(ap);
}
static int vc4_drm_bind(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct drm_device *drm;
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
vc4_bo_cache_init(drm);
drm_mode_config_init(drm);
vc4_gem_init(drm);
ret = component_bind_all(dev, drm);
if (ret)
goto gem_destroy;
vc4_kick_out_firmware_fb();
ret = drm_dev_register(drm, 0);
if (ret < 0)
goto unbind_all;
vc4_kms_load(drm);
return 0;
unbind_all:
component_unbind_all(dev, drm);
gem_destroy:
vc4_gem_destroy(drm);
drm_dev_unref(drm);
vc4_bo_cache_destroy(drm);
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
