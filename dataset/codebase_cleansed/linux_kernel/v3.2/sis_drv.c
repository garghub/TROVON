static int sis_driver_load(struct drm_device *dev, unsigned long chipset)
{
drm_sis_private_t *dev_priv;
int ret;
dev_priv = kzalloc(sizeof(drm_sis_private_t), GFP_KERNEL);
if (dev_priv == NULL)
return -ENOMEM;
dev->dev_private = (void *)dev_priv;
dev_priv->chipset = chipset;
ret = drm_sman_init(&dev_priv->sman, 2, 12, 8);
if (ret)
kfree(dev_priv);
return ret;
}
static int sis_driver_unload(struct drm_device *dev)
{
drm_sis_private_t *dev_priv = dev->dev_private;
drm_sman_takedown(&dev_priv->sman);
kfree(dev_priv);
return 0;
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
