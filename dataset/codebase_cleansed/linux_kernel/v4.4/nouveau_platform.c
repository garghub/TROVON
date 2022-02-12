static int nouveau_platform_probe(struct platform_device *pdev)
{
const struct nvkm_device_tegra_func *func;
struct nvkm_device *device;
struct drm_device *drm;
int ret;
func = of_device_get_match_data(&pdev->dev);
drm = nouveau_platform_device_create(func, pdev, &device);
if (IS_ERR(drm))
return PTR_ERR(drm);
ret = drm_dev_register(drm, 0);
if (ret < 0) {
drm_dev_unref(drm);
return ret;
}
return 0;
}
static int nouveau_platform_remove(struct platform_device *pdev)
{
struct drm_device *dev = platform_get_drvdata(pdev);
nouveau_drm_device_remove(dev);
return 0;
}
