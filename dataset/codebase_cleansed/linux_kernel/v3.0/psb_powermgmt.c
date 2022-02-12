void gma_power_init(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
dev_priv->apm_base = dev_priv->apm_reg & 0xffff;
dev_priv->ospm_base &= 0xffff;
dev_priv->display_power = true;
dev_priv->display_count = 0;
dev_priv->suspended = false;
mutex_init(&power_mutex);
if (!IS_MRST(dev)) {
u32 gating = PSB_RSGX32(PSB_CR_CLKGATECTL);
gating &= ~3;
gating |= 1;
PSB_WSGX32(gating, PSB_CR_CLKGATECTL);
PSB_RSGX32(PSB_CR_CLKGATECTL);
}
}
void gma_power_uninit(struct drm_device *dev)
{
mutex_destroy(&power_mutex);
pm_runtime_disable(&dev->pdev->dev);
pm_runtime_set_suspended(&dev->pdev->dev);
}
static int save_display_registers(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
struct drm_connector *connector;
dev_priv->saveDSPARB = PSB_RVDC32(DSPARB);
dev_priv->saveDSPFW1 = PSB_RVDC32(DSPFW1);
dev_priv->saveDSPFW2 = PSB_RVDC32(DSPFW2);
dev_priv->saveDSPFW3 = PSB_RVDC32(DSPFW3);
dev_priv->saveDSPFW4 = PSB_RVDC32(DSPFW4);
dev_priv->saveDSPFW5 = PSB_RVDC32(DSPFW5);
dev_priv->saveDSPFW6 = PSB_RVDC32(DSPFW6);
dev_priv->saveCHICKENBIT = PSB_RVDC32(DSPCHICKENBIT);
mutex_lock(&dev->mode_config.mutex);
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
if (drm_helper_crtc_in_use(crtc))
crtc->funcs->save(crtc);
}
list_for_each_entry(connector, &dev->mode_config.connector_list, head)
connector->funcs->save(connector);
mutex_unlock(&dev->mode_config.mutex);
return 0;
}
static int restore_display_registers(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
struct drm_connector *connector;
PSB_WVDC32(dev_priv->saveDSPARB, DSPARB);
PSB_WVDC32(dev_priv->saveDSPFW1, DSPFW1);
PSB_WVDC32(dev_priv->saveDSPFW2, DSPFW2);
PSB_WVDC32(dev_priv->saveDSPFW3, DSPFW3);
PSB_WVDC32(dev_priv->saveDSPFW4, DSPFW4);
PSB_WVDC32(dev_priv->saveDSPFW5, DSPFW5);
PSB_WVDC32(dev_priv->saveDSPFW6, DSPFW6);
PSB_WVDC32(dev_priv->saveCHICKENBIT, DSPCHICKENBIT);
PSB_WVDC32(0x80000000, VGACNTRL);
mutex_lock(&dev->mode_config.mutex);
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head)
if (drm_helper_crtc_in_use(crtc))
crtc->funcs->restore(crtc);
list_for_each_entry(connector, &dev->mode_config.connector_list, head)
connector->funcs->restore(connector);
mutex_unlock(&dev->mode_config.mutex);
return 0;
}
static void power_down(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
u32 pwr_mask ;
u32 pwr_sts;
if (IS_MRST(dev)) {
pwr_mask = PSB_PWRGT_DISPLAY_MASK;
outl(pwr_mask, dev_priv->ospm_base + PSB_PM_SSC);
while (true) {
pwr_sts = inl(dev_priv->ospm_base + PSB_PM_SSS);
if ((pwr_sts & pwr_mask) == pwr_mask)
break;
else
udelay(10);
}
dev_priv->display_power = false;
}
}
static void gma_suspend_display(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
int pp_stat;
if (dev_priv->suspended)
return;
save_display_registers(dev);
if (dev_priv->iLVDS_enable) {
PSB_WVDC32(0, PP_CONTROL);
do {
pp_stat = PSB_RVDC32(PP_STATUS);
} while (pp_stat & 0x80000000);
PSB_WVDC32(0x58000000, DSPACNTR);
PSB_WVDC32(0, DSPASURF);
msleep(4);
PSB_WVDC32(0x0, PIPEACONF);
msleep(8);
PSB_WVDC32(0, MRST_DPLL_A);
} else {
PSB_WVDC32(DPI_SHUT_DOWN, DPI_CONTROL_REG);
PSB_WVDC32(0x0, PIPEACONF);
PSB_WVDC32(0x2faf0000, BLC_PWM_CTL);
while (REG_READ(0x70008) & 0x40000000);
while ((PSB_RVDC32(GEN_FIFO_STAT_REG) & DPI_FIFO_EMPTY)
!= DPI_FIFO_EMPTY);
PSB_WVDC32(0, DEVICE_READY_REG);
}
power_down(dev);
}
static void power_up(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
u32 pwr_mask = PSB_PWRGT_DISPLAY_MASK;
u32 pwr_sts, pwr_cnt;
if (IS_MRST(dev)) {
pwr_cnt = inl(dev_priv->ospm_base + PSB_PM_SSC);
pwr_cnt &= ~pwr_mask;
outl(pwr_cnt, (dev_priv->ospm_base + PSB_PM_SSC));
while (true) {
pwr_sts = inl(dev_priv->ospm_base + PSB_PM_SSS);
if ((pwr_sts & pwr_mask) == 0)
break;
else
udelay(10);
}
}
dev_priv->suspended = false;
dev_priv->display_power = true;
}
static void gma_resume_display(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
struct drm_psb_private *dev_priv = dev->dev_private;
if (dev_priv->suspended == false)
return;
power_up(dev);
PSB_WVDC32(dev_priv->pge_ctl | _PSB_PGETBL_ENABLED, PSB_PGETBL_CTL);
pci_write_config_word(pdev, PSB_GMCH_CTRL,
dev_priv->gmch_ctrl | _PSB_GMCH_ENABLED);
restore_display_registers(dev);
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
int gma_power_suspend(struct pci_dev *pdev, pm_message_t state)
{
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
int gma_power_resume(struct pci_dev *pdev)
{
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
if (dev_priv->display_power) {
dev_priv->display_count++;
pm_runtime_get(&dev->pdev->dev);
return true;
}
if (force_on == false)
return false;
ret = gma_resume_pci(dev->pdev);
if (ret == 0) {
psb_irq_preinstall(dev);
psb_irq_postinstall(dev);
pm_runtime_get(&dev->pdev->dev);
dev_priv->display_count++;
return true;
}
return false;
}
void gma_power_end(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
dev_priv->display_count--;
WARN_ON(dev_priv->display_count < 0);
pm_runtime_put(&dev->pdev->dev);
}
int psb_runtime_suspend(struct device *dev)
{
static pm_message_t dummy;
return gma_power_suspend(to_pci_dev(dev), dummy);
}
int psb_runtime_resume(struct device *dev)
{
return 0;
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
