static int sis_driver_load(struct drm_device *dev, unsigned long chipset)
{
drm_sis_private_t *dev_priv;
pci_set_master(dev->pdev);
dev_priv = kzalloc(sizeof(drm_sis_private_t), GFP_KERNEL);
if (dev_priv == NULL)
return -ENOMEM;
idr_init(&dev_priv->object_idr);
dev->dev_private = (void *)dev_priv;
dev_priv->chipset = chipset;
return 0;
}
static void sis_driver_unload(struct drm_device *dev)
{
drm_sis_private_t *dev_priv = dev->dev_private;
idr_destroy(&dev_priv->object_idr);
kfree(dev_priv);
}
static int sis_driver_open(struct drm_device *dev, struct drm_file *file)
{
struct sis_file_private *file_priv;
DRM_DEBUG_DRIVER("\n");
file_priv = kmalloc(sizeof(*file_priv), GFP_KERNEL);
if (!file_priv)
return -ENOMEM;
file->driver_priv = file_priv;
INIT_LIST_HEAD(&file_priv->obj_list);
return 0;
}
static void sis_driver_postclose(struct drm_device *dev, struct drm_file *file)
{
struct sis_file_private *file_priv = file->driver_priv;
kfree(file_priv);
}
static int __init sis_init(void)
{
driver.num_ioctls = sis_max_ioctl;
return drm_pci_init(&driver, &sis_pci_driver);
}
static void __exit sis_exit(void)
{
drm_pci_exit(&driver, &sis_pci_driver);
}
