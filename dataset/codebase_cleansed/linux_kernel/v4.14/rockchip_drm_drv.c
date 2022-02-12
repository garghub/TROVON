int rockchip_drm_dma_attach_device(struct drm_device *drm_dev,
struct device *dev)
{
struct rockchip_drm_private *private = drm_dev->dev_private;
int ret;
if (!is_support_iommu)
return 0;
ret = iommu_attach_device(private->domain, dev);
if (ret) {
dev_err(dev, "Failed to attach iommu device\n");
return ret;
}
return 0;
}
void rockchip_drm_dma_detach_device(struct drm_device *drm_dev,
struct device *dev)
{
struct rockchip_drm_private *private = drm_dev->dev_private;
struct iommu_domain *domain = private->domain;
if (!is_support_iommu)
return;
iommu_detach_device(domain, dev);
}
static int rockchip_drm_init_iommu(struct drm_device *drm_dev)
{
struct rockchip_drm_private *private = drm_dev->dev_private;
struct iommu_domain_geometry *geometry;
u64 start, end;
if (!is_support_iommu)
return 0;
private->domain = iommu_domain_alloc(&platform_bus_type);
if (!private->domain)
return -ENOMEM;
geometry = &private->domain->geometry;
start = geometry->aperture_start;
end = geometry->aperture_end;
DRM_DEBUG("IOMMU context initialized (aperture: %#llx-%#llx)\n",
start, end);
drm_mm_init(&private->mm, start, end - start + 1);
mutex_init(&private->mm_lock);
return 0;
}
static void rockchip_iommu_cleanup(struct drm_device *drm_dev)
{
struct rockchip_drm_private *private = drm_dev->dev_private;
if (!is_support_iommu)
return;
drm_mm_takedown(&private->mm);
iommu_domain_free(private->domain);
}
static int rockchip_drm_bind(struct device *dev)
{
struct drm_device *drm_dev;
struct rockchip_drm_private *private;
int ret;
drm_dev = drm_dev_alloc(&rockchip_drm_driver, dev);
if (IS_ERR(drm_dev))
return PTR_ERR(drm_dev);
dev_set_drvdata(dev, drm_dev);
private = devm_kzalloc(drm_dev->dev, sizeof(*private), GFP_KERNEL);
if (!private) {
ret = -ENOMEM;
goto err_free;
}
drm_dev->dev_private = private;
INIT_LIST_HEAD(&private->psr_list);
spin_lock_init(&private->psr_list_lock);
ret = rockchip_drm_init_iommu(drm_dev);
if (ret)
goto err_free;
drm_mode_config_init(drm_dev);
rockchip_drm_mode_config_init(drm_dev);
ret = component_bind_all(dev, drm_dev);
if (ret)
goto err_mode_config_cleanup;
ret = drm_vblank_init(drm_dev, drm_dev->mode_config.num_crtc);
if (ret)
goto err_unbind_all;
drm_mode_config_reset(drm_dev);
drm_dev->irq_enabled = true;
ret = rockchip_drm_fbdev_init(drm_dev);
if (ret)
goto err_unbind_all;
drm_kms_helper_poll_init(drm_dev);
ret = drm_dev_register(drm_dev, 0);
if (ret)
goto err_kms_helper_poll_fini;
return 0;
err_kms_helper_poll_fini:
drm_kms_helper_poll_fini(drm_dev);
rockchip_drm_fbdev_fini(drm_dev);
err_unbind_all:
component_unbind_all(dev, drm_dev);
err_mode_config_cleanup:
drm_mode_config_cleanup(drm_dev);
rockchip_iommu_cleanup(drm_dev);
err_free:
drm_dev->dev_private = NULL;
dev_set_drvdata(dev, NULL);
drm_dev_unref(drm_dev);
return ret;
}
static void rockchip_drm_unbind(struct device *dev)
{
struct drm_device *drm_dev = dev_get_drvdata(dev);
drm_dev_unregister(drm_dev);
rockchip_drm_fbdev_fini(drm_dev);
drm_kms_helper_poll_fini(drm_dev);
drm_atomic_helper_shutdown(drm_dev);
component_unbind_all(dev, drm_dev);
drm_mode_config_cleanup(drm_dev);
rockchip_iommu_cleanup(drm_dev);
drm_dev->dev_private = NULL;
dev_set_drvdata(dev, NULL);
drm_dev_unref(drm_dev);
}
static void rockchip_drm_lastclose(struct drm_device *dev)
{
struct rockchip_drm_private *priv = dev->dev_private;
drm_fb_helper_restore_fbdev_mode_unlocked(&priv->fbdev_helper);
}
static void rockchip_drm_fb_suspend(struct drm_device *drm)
{
struct rockchip_drm_private *priv = drm->dev_private;
console_lock();
drm_fb_helper_set_suspend(&priv->fbdev_helper, 1);
console_unlock();
}
static void rockchip_drm_fb_resume(struct drm_device *drm)
{
struct rockchip_drm_private *priv = drm->dev_private;
console_lock();
drm_fb_helper_set_suspend(&priv->fbdev_helper, 0);
console_unlock();
}
static int rockchip_drm_sys_suspend(struct device *dev)
{
struct drm_device *drm = dev_get_drvdata(dev);
struct rockchip_drm_private *priv;
if (!drm)
return 0;
drm_kms_helper_poll_disable(drm);
rockchip_drm_fb_suspend(drm);
priv = drm->dev_private;
priv->state = drm_atomic_helper_suspend(drm);
if (IS_ERR(priv->state)) {
rockchip_drm_fb_resume(drm);
drm_kms_helper_poll_enable(drm);
return PTR_ERR(priv->state);
}
return 0;
}
static int rockchip_drm_sys_resume(struct device *dev)
{
struct drm_device *drm = dev_get_drvdata(dev);
struct rockchip_drm_private *priv;
if (!drm)
return 0;
priv = drm->dev_private;
drm_atomic_helper_resume(drm, priv->state);
rockchip_drm_fb_resume(drm);
drm_kms_helper_poll_enable(drm);
return 0;
}
static int compare_dev(struct device *dev, void *data)
{
return dev == (struct device *)data;
}
static struct component_match *rockchip_drm_match_add(struct device *dev)
{
struct component_match *match = NULL;
int i;
for (i = 0; i < num_rockchip_sub_drivers; i++) {
struct platform_driver *drv = rockchip_sub_drivers[i];
struct device *p = NULL, *d;
do {
d = bus_find_device(&platform_bus_type, p, &drv->driver,
(void *)platform_bus_type.match);
put_device(p);
p = d;
if (!d)
break;
component_match_add(dev, &match, compare_dev, d);
} while (true);
}
return match ?: ERR_PTR(-ENODEV);
}
static int rockchip_drm_platform_of_probe(struct device *dev)
{
struct device_node *np = dev->of_node;
struct device_node *port;
bool found = false;
int i;
if (!np)
return -ENODEV;
for (i = 0;; i++) {
struct device_node *iommu;
port = of_parse_phandle(np, "ports", i);
if (!port)
break;
if (!of_device_is_available(port->parent)) {
of_node_put(port);
continue;
}
iommu = of_parse_phandle(port->parent, "iommus", 0);
if (!iommu || !of_device_is_available(iommu->parent)) {
dev_dbg(dev, "no iommu attached for %pOF, using non-iommu buffers\n",
port->parent);
is_support_iommu = false;
}
found = true;
of_node_put(iommu);
of_node_put(port);
}
if (i == 0) {
dev_err(dev, "missing 'ports' property\n");
return -ENODEV;
}
if (!found) {
dev_err(dev, "No available vop found for display-subsystem.\n");
return -ENODEV;
}
return 0;
}
static int rockchip_drm_platform_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct component_match *match = NULL;
int ret;
ret = rockchip_drm_platform_of_probe(dev);
if (ret)
return ret;
match = rockchip_drm_match_add(dev);
if (IS_ERR(match))
return PTR_ERR(match);
return component_master_add_with_match(dev, &rockchip_drm_ops, match);
}
static int rockchip_drm_platform_remove(struct platform_device *pdev)
{
component_master_del(&pdev->dev, &rockchip_drm_ops);
return 0;
}
static int __init rockchip_drm_init(void)
{
int ret;
num_rockchip_sub_drivers = 0;
ADD_ROCKCHIP_SUB_DRIVER(vop_platform_driver, CONFIG_DRM_ROCKCHIP);
ADD_ROCKCHIP_SUB_DRIVER(rockchip_dp_driver,
CONFIG_ROCKCHIP_ANALOGIX_DP);
ADD_ROCKCHIP_SUB_DRIVER(cdn_dp_driver, CONFIG_ROCKCHIP_CDN_DP);
ADD_ROCKCHIP_SUB_DRIVER(dw_hdmi_rockchip_pltfm_driver,
CONFIG_ROCKCHIP_DW_HDMI);
ADD_ROCKCHIP_SUB_DRIVER(dw_mipi_dsi_driver,
CONFIG_ROCKCHIP_DW_MIPI_DSI);
ADD_ROCKCHIP_SUB_DRIVER(inno_hdmi_driver, CONFIG_ROCKCHIP_INNO_HDMI);
ret = platform_register_drivers(rockchip_sub_drivers,
num_rockchip_sub_drivers);
if (ret)
return ret;
ret = platform_driver_register(&rockchip_drm_platform_driver);
if (ret)
goto err_unreg_drivers;
return 0;
err_unreg_drivers:
platform_unregister_drivers(rockchip_sub_drivers,
num_rockchip_sub_drivers);
return ret;
}
static void __exit rockchip_drm_fini(void)
{
platform_driver_unregister(&rockchip_drm_platform_driver);
platform_unregister_drivers(rockchip_sub_drivers,
num_rockchip_sub_drivers);
}
