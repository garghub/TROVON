static int ast_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
return drm_get_pci_dev(pdev, ent, &driver);
}
static void
ast_pci_remove(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
drm_put_dev(dev);
}
static int ast_drm_freeze(struct drm_device *dev)
{
drm_kms_helper_poll_disable(dev);
pci_save_state(dev->pdev);
console_lock();
ast_fbdev_set_suspend(dev, 1);
console_unlock();
return 0;
}
static int ast_drm_thaw(struct drm_device *dev)
{
int error = 0;
ast_post_gpu(dev);
drm_mode_config_reset(dev);
drm_helper_resume_force_mode(dev);
console_lock();
ast_fbdev_set_suspend(dev, 0);
console_unlock();
return error;
}
static int ast_drm_resume(struct drm_device *dev)
{
int ret;
if (pci_enable_device(dev->pdev))
return -EIO;
ret = ast_drm_thaw(dev);
if (ret)
return ret;
drm_kms_helper_poll_enable(dev);
return 0;
}
static int ast_pm_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *ddev = pci_get_drvdata(pdev);
int error;
error = ast_drm_freeze(ddev);
if (error)
return error;
pci_disable_device(pdev);
pci_set_power_state(pdev, PCI_D3hot);
return 0;
}
static int ast_pm_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *ddev = pci_get_drvdata(pdev);
return ast_drm_resume(ddev);
}
static int ast_pm_freeze(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *ddev = pci_get_drvdata(pdev);
if (!ddev || !ddev->dev_private)
return -ENODEV;
return ast_drm_freeze(ddev);
}
static int ast_pm_thaw(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *ddev = pci_get_drvdata(pdev);
return ast_drm_thaw(ddev);
}
static int ast_pm_poweroff(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *ddev = pci_get_drvdata(pdev);
return ast_drm_freeze(ddev);
}
static int __init ast_init(void)
{
if (vgacon_text_force() && ast_modeset == -1)
return -EINVAL;
if (ast_modeset == 0)
return -EINVAL;
return pci_register_driver(&ast_pci_driver);
}
static void __exit ast_exit(void)
{
pci_unregister_driver(&ast_pci_driver);
}
