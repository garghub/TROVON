static inline int configure_dma_max_seg_size(struct device *dev)
{
if (!dev->dma_parms)
dev->dma_parms = kzalloc(sizeof(*dev->dma_parms), GFP_KERNEL);
if (!dev->dma_parms)
return -ENOMEM;
dma_set_max_seg_size(dev, DMA_BIT_MASK(32));
return 0;
}
static inline void clear_dma_max_seg_size(struct device *dev)
{
kfree(dev->dma_parms);
dev->dma_parms = NULL;
}
int drm_create_iommu_mapping(struct drm_device *drm_dev)
{
struct exynos_drm_private *priv = drm_dev->dev_private;
return __exynos_iommu_create_mapping(priv, EXYNOS_DEV_ADDR_START,
EXYNOS_DEV_ADDR_SIZE);
}
void drm_release_iommu_mapping(struct drm_device *drm_dev)
{
struct exynos_drm_private *priv = drm_dev->dev_private;
__exynos_iommu_release_mapping(priv);
}
int drm_iommu_attach_device(struct drm_device *drm_dev,
struct device *subdrv_dev)
{
struct exynos_drm_private *priv = drm_dev->dev_private;
int ret;
if (get_dma_ops(priv->dma_dev) != get_dma_ops(subdrv_dev)) {
DRM_ERROR("Device %s lacks support for IOMMU\n",
dev_name(subdrv_dev));
return -EINVAL;
}
ret = configure_dma_max_seg_size(subdrv_dev);
if (ret)
return ret;
ret = __exynos_iommu_attach(priv, subdrv_dev);
if (ret)
clear_dma_max_seg_size(subdrv_dev);
return 0;
}
void drm_iommu_detach_device(struct drm_device *drm_dev,
struct device *subdrv_dev)
{
struct exynos_drm_private *priv = drm_dev->dev_private;
__exynos_iommu_detach(priv, subdrv_dev);
clear_dma_max_seg_size(subdrv_dev);
}
