static int vbox_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
return drm_get_pci_dev(pdev, ent, &driver);
}
static void vbox_pci_remove(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
drm_put_dev(dev);
}
static int vbox_drm_freeze(struct drm_device *dev)
{
struct vbox_private *vbox = dev->dev_private;
drm_kms_helper_poll_disable(dev);
pci_save_state(dev->pdev);
drm_fb_helper_set_suspend_unlocked(&vbox->fbdev->helper, true);
return 0;
}
static int vbox_drm_thaw(struct drm_device *dev)
{
struct vbox_private *vbox = dev->dev_private;
drm_mode_config_reset(dev);
drm_helper_resume_force_mode(dev);
drm_fb_helper_set_suspend_unlocked(&vbox->fbdev->helper, false);
return 0;
}
static int vbox_drm_resume(struct drm_device *dev)
{
int ret;
if (pci_enable_device(dev->pdev))
return -EIO;
ret = vbox_drm_thaw(dev);
if (ret)
return ret;
drm_kms_helper_poll_enable(dev);
return 0;
}
static int vbox_pm_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *ddev = pci_get_drvdata(pdev);
int error;
error = vbox_drm_freeze(ddev);
if (error)
return error;
pci_disable_device(pdev);
pci_set_power_state(pdev, PCI_D3hot);
return 0;
}
static int vbox_pm_resume(struct device *dev)
{
struct drm_device *ddev = pci_get_drvdata(to_pci_dev(dev));
return vbox_drm_resume(ddev);
}
static int vbox_pm_freeze(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *ddev = pci_get_drvdata(pdev);
if (!ddev || !ddev->dev_private)
return -ENODEV;
return vbox_drm_freeze(ddev);
}
static int vbox_pm_thaw(struct device *dev)
{
struct drm_device *ddev = pci_get_drvdata(to_pci_dev(dev));
return vbox_drm_thaw(ddev);
}
static int vbox_pm_poweroff(struct device *dev)
{
struct drm_device *ddev = pci_get_drvdata(to_pci_dev(dev));
return vbox_drm_freeze(ddev);
}
static int vbox_master_set(struct drm_device *dev,
struct drm_file *file_priv, bool from_open)
{
struct vbox_private *vbox = dev->dev_private;
vbox->initial_mode_queried = false;
mutex_lock(&vbox->hw_mutex);
vbox_disable_accel(vbox);
mutex_unlock(&vbox->hw_mutex);
return 0;
}
static void vbox_master_drop(struct drm_device *dev, struct drm_file *file_priv)
{
struct vbox_private *vbox = dev->dev_private;
vbox->initial_mode_queried = false;
mutex_lock(&vbox->hw_mutex);
vbox_disable_accel(vbox);
mutex_unlock(&vbox->hw_mutex);
}
static int __init vbox_init(void)
{
#ifdef CONFIG_VGA_CONSOLE
if (vgacon_text_force() && vbox_modeset == -1)
return -EINVAL;
#endif
if (vbox_modeset == 0)
return -EINVAL;
return drm_pci_init(&driver, &vbox_pci_driver);
}
static void __exit vbox_exit(void)
{
drm_pci_exit(&driver, &vbox_pci_driver);
}
