void xcv_init_hw(void)
{
u64 cfg;
cfg = readq_relaxed(xcv->reg_base + XCV_RESET);
cfg &= ~DLL_RESET;
writeq_relaxed(cfg, xcv->reg_base + XCV_RESET);
cfg = readq_relaxed(xcv->reg_base + XCV_RESET);
cfg &= ~CLK_RESET;
writeq_relaxed(cfg, xcv->reg_base + XCV_RESET);
msleep(1);
cfg = readq_relaxed(xcv->reg_base + XCV_DLL_CTL);
cfg &= ~0xFF03;
cfg |= CLKRX_BYP;
writeq_relaxed(cfg, xcv->reg_base + XCV_DLL_CTL);
cfg = readq_relaxed(xcv->reg_base + XCV_RESET);
cfg |= COMP_EN;
writeq_relaxed(cfg, xcv->reg_base + XCV_RESET);
readq_relaxed(xcv->reg_base + XCV_RESET);
msleep(10);
cfg = readq_relaxed(xcv->reg_base + XCV_RESET);
cfg |= PORT_EN;
writeq_relaxed(cfg, xcv->reg_base + XCV_RESET);
cfg = readq_relaxed(xcv->reg_base + XCV_RESET);
cfg |= CLK_RESET;
writeq_relaxed(cfg, xcv->reg_base + XCV_RESET);
}
void xcv_setup_link(bool link_up, int link_speed)
{
u64 cfg;
int speed = 2;
if (!xcv) {
pr_err("XCV init not done, probe may have failed\n");
return;
}
if (link_speed == 100)
speed = 1;
else if (link_speed == 10)
speed = 0;
if (link_up) {
cfg = readq_relaxed(xcv->reg_base + XCV_CTL);
cfg &= ~0x03;
cfg |= speed;
writeq_relaxed(cfg, xcv->reg_base + XCV_CTL);
cfg = readq_relaxed(xcv->reg_base + XCV_RESET);
cfg |= TX_DATA_RESET | RX_DATA_RESET;
writeq_relaxed(cfg, xcv->reg_base + XCV_RESET);
cfg = readq_relaxed(xcv->reg_base + XCV_RESET);
cfg |= TX_PKT_RESET | RX_PKT_RESET;
writeq_relaxed(cfg, xcv->reg_base + XCV_RESET);
writeq_relaxed(0x01, xcv->reg_base + XCV_BATCH_CRD_RET);
} else {
cfg = readq_relaxed(xcv->reg_base + XCV_RESET);
cfg &= ~(TX_PKT_RESET | RX_PKT_RESET);
writeq_relaxed(cfg, xcv->reg_base + XCV_RESET);
readq_relaxed(xcv->reg_base + XCV_RESET);
}
}
static int xcv_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int err;
struct device *dev = &pdev->dev;
xcv = devm_kzalloc(dev, sizeof(struct xcv), GFP_KERNEL);
if (!xcv)
return -ENOMEM;
xcv->pdev = pdev;
pci_set_drvdata(pdev, xcv);
err = pci_enable_device(pdev);
if (err) {
dev_err(dev, "Failed to enable PCI device\n");
goto err_kfree;
}
err = pci_request_regions(pdev, DRV_NAME);
if (err) {
dev_err(dev, "PCI request regions failed 0x%x\n", err);
goto err_disable_device;
}
xcv->reg_base = pcim_iomap(pdev, PCI_CFG_REG_BAR_NUM, 0);
if (!xcv->reg_base) {
dev_err(dev, "XCV: Cannot map CSR memory space, aborting\n");
err = -ENOMEM;
goto err_release_regions;
}
return 0;
err_release_regions:
pci_release_regions(pdev);
err_disable_device:
pci_disable_device(pdev);
err_kfree:
devm_kfree(dev, xcv);
xcv = NULL;
return err;
}
static void xcv_remove(struct pci_dev *pdev)
{
struct device *dev = &pdev->dev;
if (xcv) {
devm_kfree(dev, xcv);
xcv = NULL;
}
pci_release_regions(pdev);
pci_disable_device(pdev);
}
static int __init xcv_init_module(void)
{
pr_info("%s, ver %s\n", DRV_NAME, DRV_VERSION);
return pci_register_driver(&xcv_driver);
}
static void __exit xcv_cleanup_module(void)
{
pci_unregister_driver(&xcv_driver);
}
