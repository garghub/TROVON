static int via_driver_open(struct drm_device *dev, struct drm_file *file)
{
struct via_file_private *file_priv;
DRM_DEBUG_DRIVER("\n");
file_priv = kmalloc(sizeof(*file_priv), GFP_KERNEL);
if (!file_priv)
return -ENOMEM;
file->driver_priv = file_priv;
INIT_LIST_HEAD(&file_priv->obj_list);
return 0;
}
void via_driver_postclose(struct drm_device *dev, struct drm_file *file)
{
struct via_file_private *file_priv = file->driver_priv;
kfree(file_priv);
}
static int __init via_init(void)
{
driver.num_ioctls = via_max_ioctl;
via_init_command_verifier();
return drm_pci_init(&driver, &via_pci_driver);
}
static void __exit via_exit(void)
{
drm_pci_exit(&driver, &via_pci_driver);
}
