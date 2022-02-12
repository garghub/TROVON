int drm_create_iommu_mapping(struct drm_device *drm_dev)
{
struct dma_iommu_mapping *mapping = NULL;
struct exynos_drm_private *priv = drm_dev->dev_private;
if (!priv->da_start)
priv->da_start = EXYNOS_DEV_ADDR_START;
if (!priv->da_space_size)
priv->da_space_size = EXYNOS_DEV_ADDR_SIZE;
mapping = arm_iommu_create_mapping(&platform_bus_type, priv->da_start,
priv->da_space_size);
if (IS_ERR(mapping))
return PTR_ERR(mapping);
priv->mapping = mapping;
return 0;
}
void drm_release_iommu_mapping(struct drm_device *drm_dev)
{
struct exynos_drm_private *priv = drm_dev->dev_private;
arm_iommu_release_mapping(priv->mapping);
}
int drm_iommu_attach_device(struct drm_device *drm_dev,
struct device *subdrv_dev)
{
struct exynos_drm_private *priv = drm_dev->dev_private;
int ret;
if (!priv->mapping)
return 0;
subdrv_dev->dma_parms = devm_kzalloc(subdrv_dev,
sizeof(*subdrv_dev->dma_parms),
GFP_KERNEL);
if (!subdrv_dev->dma_parms)
return -ENOMEM;
dma_set_max_seg_size(subdrv_dev, 0xffffffffu);
if (subdrv_dev->archdata.mapping)
arm_iommu_detach_device(subdrv_dev);
ret = arm_iommu_attach_device(subdrv_dev, priv->mapping);
if (ret < 0) {
DRM_DEBUG_KMS("failed iommu attach.\n");
return ret;
}
return 0;
}
void drm_iommu_detach_device(struct drm_device *drm_dev,
struct device *subdrv_dev)
{
struct exynos_drm_private *priv = drm_dev->dev_private;
struct dma_iommu_mapping *mapping = priv->mapping;
if (!mapping || !mapping->domain)
return;
arm_iommu_detach_device(subdrv_dev);
}
