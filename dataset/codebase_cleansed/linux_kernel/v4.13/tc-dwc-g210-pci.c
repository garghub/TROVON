static int tc_dwc_g210_pci_suspend(struct device *dev)
{
return ufshcd_system_suspend(dev_get_drvdata(dev));
}
static int tc_dwc_g210_pci_resume(struct device *dev)
{
return ufshcd_system_resume(dev_get_drvdata(dev));
}
static int tc_dwc_g210_pci_runtime_suspend(struct device *dev)
{
return ufshcd_runtime_suspend(dev_get_drvdata(dev));
}
static int tc_dwc_g210_pci_runtime_resume(struct device *dev)
{
return ufshcd_runtime_resume(dev_get_drvdata(dev));
}
static int tc_dwc_g210_pci_runtime_idle(struct device *dev)
{
return ufshcd_runtime_idle(dev_get_drvdata(dev));
}
static void tc_dwc_g210_pci_shutdown(struct pci_dev *pdev)
{
ufshcd_shutdown((struct ufs_hba *)pci_get_drvdata(pdev));
}
static void tc_dwc_g210_pci_remove(struct pci_dev *pdev)
{
struct ufs_hba *hba = pci_get_drvdata(pdev);
pm_runtime_forbid(&pdev->dev);
pm_runtime_get_noresume(&pdev->dev);
ufshcd_remove(hba);
}
static int
tc_dwc_g210_pci_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct ufs_hba *hba;
void __iomem *mmio_base;
int err;
if (tc_type == TC_G210_20BIT) {
tc_dwc_g210_pci_hba_vops.phy_initialization =
tc_dwc_g210_config_20_bit;
} else if (tc_type == TC_G210_40BIT) {
tc_dwc_g210_pci_hba_vops.phy_initialization =
tc_dwc_g210_config_40_bit;
} else {
dev_err(&pdev->dev, "test chip version not specified\n");
return -EPERM;
}
err = pcim_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "pcim_enable_device failed\n");
return err;
}
pci_set_master(pdev);
err = pcim_iomap_regions(pdev, 1 << 0, UFSHCD);
if (err < 0) {
dev_err(&pdev->dev, "request and iomap failed\n");
return err;
}
mmio_base = pcim_iomap_table(pdev)[0];
err = ufshcd_alloc_host(&pdev->dev, &hba);
if (err) {
dev_err(&pdev->dev, "Allocation failed\n");
return err;
}
hba->vops = &tc_dwc_g210_pci_hba_vops;
err = ufshcd_init(hba, mmio_base, pdev->irq);
if (err) {
dev_err(&pdev->dev, "Initialization failed\n");
return err;
}
pci_set_drvdata(pdev, hba);
pm_runtime_put_noidle(&pdev->dev);
pm_runtime_allow(&pdev->dev);
return 0;
}
