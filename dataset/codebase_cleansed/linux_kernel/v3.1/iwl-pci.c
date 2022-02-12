static u16 iwl_pciexp_link_ctrl(struct iwl_bus *bus)
{
int pos;
u16 pci_lnk_ctl;
struct pci_dev *pci_dev = IWL_BUS_GET_PCI_DEV(bus);
pos = pci_pcie_cap(pci_dev);
pci_read_config_word(pci_dev, pos + PCI_EXP_LNKCTL, &pci_lnk_ctl);
return pci_lnk_ctl;
}
static bool iwl_pci_is_pm_supported(struct iwl_bus *bus)
{
u16 lctl = iwl_pciexp_link_ctrl(bus);
return !(lctl & PCI_CFG_LINK_CTRL_VAL_L0S_EN);
}
static void iwl_pci_apm_config(struct iwl_bus *bus)
{
u16 lctl = iwl_pciexp_link_ctrl(bus);
if ((lctl & PCI_CFG_LINK_CTRL_VAL_L1_EN) ==
PCI_CFG_LINK_CTRL_VAL_L1_EN) {
iwl_set_bit(bus->drv_data, CSR_GIO_REG,
CSR_GIO_REG_VAL_L0S_ENABLED);
dev_printk(KERN_INFO, bus->dev, "L1 Enabled; Disabling L0S\n");
} else {
iwl_clear_bit(bus->drv_data, CSR_GIO_REG,
CSR_GIO_REG_VAL_L0S_ENABLED);
dev_printk(KERN_INFO, bus->dev, "L1 Disabled; Enabling L0S\n");
}
}
static void iwl_pci_set_drv_data(struct iwl_bus *bus, void *drv_data)
{
bus->drv_data = drv_data;
pci_set_drvdata(IWL_BUS_GET_PCI_DEV(bus), drv_data);
}
static void iwl_pci_get_hw_id(struct iwl_bus *bus, char buf[],
int buf_len)
{
struct pci_dev *pci_dev = IWL_BUS_GET_PCI_DEV(bus);
snprintf(buf, buf_len, "PCI ID: 0x%04X:0x%04X", pci_dev->device,
pci_dev->subsystem_device);
}
static void iwl_pci_write8(struct iwl_bus *bus, u32 ofs, u8 val)
{
iowrite8(val, IWL_BUS_GET_PCI_BUS(bus)->hw_base + ofs);
}
static void iwl_pci_write32(struct iwl_bus *bus, u32 ofs, u32 val)
{
iowrite32(val, IWL_BUS_GET_PCI_BUS(bus)->hw_base + ofs);
}
static u32 iwl_pci_read32(struct iwl_bus *bus, u32 ofs)
{
u32 val = ioread32(IWL_BUS_GET_PCI_BUS(bus)->hw_base + ofs);
return val;
}
static int iwl_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct iwl_cfg *cfg = (struct iwl_cfg *)(ent->driver_data);
struct iwl_bus *bus;
struct iwl_pci_bus *pci_bus;
u16 pci_cmd;
int err;
bus = kzalloc(sizeof(*bus) + sizeof(*pci_bus), GFP_KERNEL);
if (!bus) {
dev_printk(KERN_ERR, &pdev->dev,
"Couldn't allocate iwl_pci_bus");
err = -ENOMEM;
goto out_no_pci;
}
pci_bus = IWL_BUS_GET_PCI_BUS(bus);
pci_bus->pci_dev = pdev;
pci_disable_link_state(pdev, PCIE_LINK_STATE_L0S | PCIE_LINK_STATE_L1 |
PCIE_LINK_STATE_CLKPM);
if (pci_enable_device(pdev)) {
err = -ENODEV;
goto out_no_pci;
}
pci_set_master(pdev);
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(36));
if (!err)
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(36));
if (err) {
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (!err)
err = pci_set_consistent_dma_mask(pdev,
DMA_BIT_MASK(32));
if (err) {
dev_printk(KERN_ERR, bus->dev,
"No suitable DMA available.\n");
goto out_pci_disable_device;
}
}
err = pci_request_regions(pdev, DRV_NAME);
if (err) {
dev_printk(KERN_ERR, bus->dev, "pci_request_regions failed");
goto out_pci_disable_device;
}
pci_bus->hw_base = pci_iomap(pdev, 0, 0);
if (!pci_bus->hw_base) {
dev_printk(KERN_ERR, bus->dev, "pci_iomap failed");
err = -ENODEV;
goto out_pci_release_regions;
}
dev_printk(KERN_INFO, &pdev->dev,
"pci_resource_len = 0x%08llx\n",
(unsigned long long) pci_resource_len(pdev, 0));
dev_printk(KERN_INFO, &pdev->dev,
"pci_resource_base = %p\n", pci_bus->hw_base);
dev_printk(KERN_INFO, &pdev->dev,
"HW Revision ID = 0x%X\n", pdev->revision);
pci_write_config_byte(pdev, PCI_CFG_RETRY_TIMEOUT, 0x00);
err = pci_enable_msi(pdev);
if (err) {
dev_printk(KERN_ERR, &pdev->dev, "pci_enable_msi failed");
goto out_iounmap;
}
pci_read_config_word(pdev, PCI_COMMAND, &pci_cmd);
if (pci_cmd & PCI_COMMAND_INTX_DISABLE) {
pci_cmd &= ~PCI_COMMAND_INTX_DISABLE;
pci_write_config_word(pdev, PCI_COMMAND, pci_cmd);
}
bus->dev = &pdev->dev;
bus->irq = pdev->irq;
bus->ops = &pci_ops;
err = iwl_probe(bus, cfg);
if (err)
goto out_disable_msi;
return 0;
out_disable_msi:
pci_disable_msi(pdev);
out_iounmap:
pci_iounmap(pdev, pci_bus->hw_base);
out_pci_release_regions:
pci_set_drvdata(pdev, NULL);
pci_release_regions(pdev);
out_pci_disable_device:
pci_disable_device(pdev);
out_no_pci:
kfree(bus);
return err;
}
static void __devexit iwl_pci_remove(struct pci_dev *pdev)
{
struct iwl_priv *priv = pci_get_drvdata(pdev);
struct iwl_bus *bus = priv->bus;
struct iwl_pci_bus *pci_bus = IWL_BUS_GET_PCI_BUS(bus);
struct pci_dev *pci_dev = IWL_BUS_GET_PCI_DEV(bus);
iwl_remove(priv);
pci_disable_msi(pci_dev);
pci_iounmap(pci_dev, pci_bus->hw_base);
pci_release_regions(pci_dev);
pci_disable_device(pci_dev);
pci_set_drvdata(pci_dev, NULL);
kfree(bus);
}
static int iwl_pci_suspend(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct iwl_priv *priv = pci_get_drvdata(pdev);
return iwl_suspend(priv);
}
static int iwl_pci_resume(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct iwl_priv *priv = pci_get_drvdata(pdev);
pci_write_config_byte(pdev, PCI_CFG_RETRY_TIMEOUT, 0x00);
return iwl_resume(priv);
}
int __must_check iwl_pci_register_driver(void)
{
int ret;
ret = pci_register_driver(&iwl_pci_driver);
if (ret)
pr_err("Unable to initialize PCI module\n");
return ret;
}
void iwl_pci_unregister_driver(void)
{
pci_unregister_driver(&iwl_pci_driver);
}
