int drm_create_iommu_mapping(struct drm_device *drm_dev)
{
struct dma_iommu_mapping *mapping = NULL;
struct exynos_drm_private *priv = drm_dev->dev_private;
struct device *dev = drm_dev->dev;
if (!priv->da_start)
priv->da_start = EXYNOS_DEV_ADDR_START;
if (!priv->da_space_size)
priv->da_space_size = EXYNOS_DEV_ADDR_SIZE;
if (!priv->da_space_order)
priv->da_space_order = EXYNOS_DEV_ADDR_ORDER;
mapping = arm_iommu_create_mapping(&platform_bus_type, priv->da_start,
priv->da_space_size,
priv->da_space_order);
if (IS_ERR(mapping))
return PTR_ERR(mapping);
dev->dma_parms = devm_kzalloc(dev, sizeof(*dev->dma_parms),
GFP_KERNEL);
if (!dev->dma_parms)
goto error;
dma_set_max_seg_size(dev, 0xffffffffu);
dev->archdata.mapping = mapping;
return 0;
error:
arm_iommu_release_mapping(mapping);
return -ENOMEM;
}
void drm_release_iommu_mapping(struct drm_device *drm_dev)
{
struct device *dev = drm_dev->dev;
arm_iommu_release_mapping(dev->archdata.mapping);
}
int drm_iommu_attach_device(struct drm_device *drm_dev,
struct device *subdrv_dev)
{
struct device *dev = drm_dev->dev;
int ret;
if (!dev->archdata.mapping) {
DRM_ERROR("iommu_mapping is null.\n");
return -EFAULT;
}
subdrv_dev->dma_parms = devm_kzalloc(subdrv_dev,
sizeof(*subdrv_dev->dma_parms),
GFP_KERNEL);
if (!subdrv_dev->dma_parms)
return -ENOMEM;
dma_set_max_seg_size(subdrv_dev, 0xffffffffu);
ret = arm_iommu_attach_device(subdrv_dev, dev->archdata.mapping);
if (ret < 0) {
DRM_DEBUG_KMS("failed iommu attach.\n");
return ret;
}
if (!dev->archdata.dma_ops)
dev->archdata.dma_ops = subdrv_dev->archdata.dma_ops;
return 0;
}
void drm_iommu_detach_device(struct drm_device *drm_dev,
struct device *subdrv_dev)
{
struct device *dev = drm_dev->dev;
struct dma_iommu_mapping *mapping = dev->archdata.mapping;
if (!mapping || !mapping->domain)
return;
iommu_detach_device(mapping->domain, subdrv_dev);
drm_release_iommu_mapping(drm_dev);
}
