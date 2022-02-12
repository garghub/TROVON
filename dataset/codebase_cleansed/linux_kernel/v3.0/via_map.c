static int via_do_init_map(struct drm_device *dev, drm_via_init_t *init)
{
drm_via_private_t *dev_priv = dev->dev_private;
DRM_DEBUG("\n");
dev_priv->sarea = drm_getsarea(dev);
if (!dev_priv->sarea) {
DRM_ERROR("could not find sarea!\n");
dev->dev_private = (void *)dev_priv;
via_do_cleanup_map(dev);
return -EINVAL;
}
dev_priv->fb = drm_core_findmap(dev, init->fb_offset);
if (!dev_priv->fb) {
DRM_ERROR("could not find framebuffer!\n");
dev->dev_private = (void *)dev_priv;
via_do_cleanup_map(dev);
return -EINVAL;
}
dev_priv->mmio = drm_core_findmap(dev, init->mmio_offset);
if (!dev_priv->mmio) {
DRM_ERROR("could not find mmio region!\n");
dev->dev_private = (void *)dev_priv;
via_do_cleanup_map(dev);
return -EINVAL;
}
dev_priv->sarea_priv =
(drm_via_sarea_t *) ((u8 *) dev_priv->sarea->handle +
init->sarea_priv_offset);
dev_priv->agpAddr = init->agpAddr;
via_init_futex(dev_priv);
via_init_dmablit(dev);
dev->dev_private = (void *)dev_priv;
return 0;
}
int via_do_cleanup_map(struct drm_device *dev)
{
via_dma_cleanup(dev);
return 0;
}
int via_map_init(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_via_init_t *init = data;
DRM_DEBUG("\n");
switch (init->func) {
case VIA_INIT_MAP:
return via_do_init_map(dev, init);
case VIA_CLEANUP_MAP:
return via_do_cleanup_map(dev);
}
return -EINVAL;
}
int via_driver_load(struct drm_device *dev, unsigned long chipset)
{
drm_via_private_t *dev_priv;
int ret = 0;
dev_priv = kzalloc(sizeof(drm_via_private_t), GFP_KERNEL);
if (dev_priv == NULL)
return -ENOMEM;
dev->dev_private = (void *)dev_priv;
dev_priv->chipset = chipset;
ret = drm_sman_init(&dev_priv->sman, 2, 12, 8);
if (ret) {
kfree(dev_priv);
return ret;
}
ret = drm_vblank_init(dev, 1);
if (ret) {
drm_sman_takedown(&dev_priv->sman);
kfree(dev_priv);
return ret;
}
return 0;
}
int via_driver_unload(struct drm_device *dev)
{
drm_via_private_t *dev_priv = dev->dev_private;
drm_sman_takedown(&dev_priv->sman);
kfree(dev_priv);
return 0;
}
