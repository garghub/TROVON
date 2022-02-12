void gma_power_init(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
dev_priv->apm_base = dev_priv->apm_reg & 0xffff;
dev_priv->ospm_base &= 0xffff;
dev_priv->display_power = true;
dev_priv->display_count = 0;
dev_priv->suspended = false;
spin_lock_init(&power_ctrl_lock);
mutex_init(&power_mutex);
dev_priv->ops->init_pm(dev);
}
void gma_power_uninit(struct drm_device *dev)
{
pm_runtime_disable(&dev->pdev->dev);
pm_runtime_set_suspended(&dev->pdev->dev);
}
static void gma_suspend_display(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
if (!dev_priv->display_power)
return;
dev_priv->ops->save_regs(dev);
dev_priv->ops->power_down(dev);
dev_priv->display_power = false;
}
static void gma_resume_display(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
struct drm_psb_private *dev_priv = dev->dev_private;
if (dev_priv->display_power)
return;
dev_priv->ops->power_up(dev);
dev_priv->suspended = false;
dev_priv->display_power = true;
PSB_WVDC32(dev_priv->pge_ctl | _PSB_PGETBL_ENABLED, PSB_PGETBL_CTL);
pci_write_config_word(pdev, PSB_GMCH_CTRL,
dev_priv->gmch_ctrl | _PSB_GMCH_ENABLED);
dev_priv->ops->restore_regs(dev);
}
static void gma_suspend_pci(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
struct drm_psb_private *dev_priv = dev->dev_private;
int bsm, vbt;
if (dev_priv->suspended)
return;
pci_save_state(pdev);
pci_read_config_dword(pdev, 0x5C, &bsm);
dev_priv->saveBSM = bsm;
pci_read_config_dword(pdev, 0xFC, &vbt);
dev_priv->saveVBT = vbt;
pci_read_config_dword(pdev, PSB_PCIx_MSI_ADDR_LOC, &dev_priv->msi_addr);
pci_read_config_dword(pdev, PSB_PCIx_MSI_DATA_LOC, &dev_priv->msi_data);
pci_disable_device(pdev);
pci_set_power_state(pdev, PCI_D3hot);
dev_priv->suspended = true;
}
static bool gma_resume_pci(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
struct drm_psb_private *dev_priv = dev->dev_private;
int ret;
if (!dev_priv->suspended)
return true;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
pci_write_config_dword(pdev, 0x5c, dev_priv->saveBSM);
pci_write_config_dword(pdev, 0xFC, dev_priv->saveVBT);
pci_write_config_dword(pdev, PSB_PCIx_MSI_ADDR_LOC, dev_priv->msi_addr);
pci_write_config_dword(pdev, PSB_PCIx_MSI_DATA_LOC, dev_priv->msi_data);
ret = pci_enable_device(pdev);
if (ret != 0)
dev_err(&pdev->dev, "pci_enable failed: %d\n", ret);
else
dev_priv->suspended = false;
return !dev_priv->suspended;
}
int gma_power_suspend(struct device *_dev)
{
struct pci_dev *pdev = container_of(_dev, struct pci_dev, dev);
struct drm_device *dev = pci_get_drvdata(pdev);
struct drm_psb_private *dev_priv = dev->dev_private;
mutex_lock(&power_mutex);
if (!dev_priv->suspended) {
if (dev_priv->display_count) {
mutex_unlock(&power_mutex);
return -EBUSY;
}
psb_irq_uninstall(dev);
gma_suspend_display(dev);
gma_suspend_pci(pdev);
}
mutex_unlock(&power_mutex);
return 0;
}
int gma_power_resume(struct device *_dev)
{
struct pci_dev *pdev = container_of(_dev, struct pci_dev, dev);
struct drm_device *dev = pci_get_drvdata(pdev);
mutex_lock(&power_mutex);
gma_resume_pci(pdev);
gma_resume_display(pdev);
psb_irq_preinstall(dev);
psb_irq_postinstall(dev);
mutex_unlock(&power_mutex);
return 0;
}
bool gma_power_is_on(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
return dev_priv->display_power;
}
bool gma_power_begin(struct drm_device *dev, bool force_on)
{
struct drm_psb_private *dev_priv = dev->dev_private;
int ret;
unsigned long flags;
spin_lock_irqsave(&power_ctrl_lock, flags);
if (dev_priv->display_power) {
dev_priv->display_count++;
pm_runtime_get(&dev->pdev->dev);
spin_unlock_irqrestore(&power_ctrl_lock, flags);
return true;
}
if (force_on == false)
goto out_false;
ret = gma_resume_pci(dev->pdev);
if (ret == 0) {
gma_resume_display(dev);
psb_irq_preinstall(dev);
psb_irq_postinstall(dev);
pm_runtime_get(&dev->pdev->dev);
dev_priv->display_count++;
spin_unlock_irqrestore(&power_ctrl_lock, flags);
return true;
}
out_false:
spin_unlock_irqrestore(&power_ctrl_lock, flags);
return false;
}
void gma_power_end(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
unsigned long flags;
spin_lock_irqsave(&power_ctrl_lock, flags);
dev_priv->display_count--;
WARN_ON(dev_priv->display_count < 0);
spin_unlock_irqrestore(&power_ctrl_lock, flags);
pm_runtime_put(&dev->pdev->dev);
}
int psb_runtime_suspend(struct device *dev)
{
return gma_power_suspend(dev);
}
int psb_runtime_resume(struct device *dev)
{
return gma_power_resume(dev);;
}
int psb_runtime_idle(struct device *dev)
{
struct drm_device *drmdev = pci_get_drvdata(to_pci_dev(dev));
struct drm_psb_private *dev_priv = drmdev->dev_private;
if (dev_priv->display_count)
return 0;
else
return 1;
}
