static int dw_mci_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *entries)
{
struct dw_mci *host;
int ret;
ret = pci_enable_device(pdev);
if (ret)
return ret;
if (pci_request_regions(pdev, "dw_mmc_pci")) {
ret = -ENODEV;
goto err_disable_dev;
}
host = kzalloc(sizeof(struct dw_mci), GFP_KERNEL);
if (!host) {
ret = -ENOMEM;
goto err_release;
}
host->irq = pdev->irq;
host->irq_flags = IRQF_SHARED;
host->dev = &pdev->dev;
host->pdata = &pci_board_data;
host->regs = pci_iomap(pdev, PCI_BAR_NO, COMPLETE_BAR);
if (!host->regs) {
ret = -EIO;
goto err_unmap;
}
pci_set_drvdata(pdev, host);
ret = dw_mci_probe(host);
if (ret)
goto err_probe_failed;
return ret;
err_probe_failed:
pci_iounmap(pdev, host->regs);
err_unmap:
kfree(host);
err_release:
pci_release_regions(pdev);
err_disable_dev:
pci_disable_device(pdev);
return ret;
}
static void dw_mci_pci_remove(struct pci_dev *pdev)
{
struct dw_mci *host = pci_get_drvdata(pdev);
dw_mci_remove(host);
pci_set_drvdata(pdev, NULL);
pci_release_regions(pdev);
pci_iounmap(pdev, host->regs);
kfree(host);
pci_disable_device(pdev);
}
static int dw_mci_pci_suspend(struct device *dev)
{
int ret;
struct pci_dev *pdev = to_pci_dev(dev);
struct dw_mci *host = pci_get_drvdata(pdev);
ret = dw_mci_suspend(host);
return ret;
}
static int dw_mci_pci_resume(struct device *dev)
{
int ret;
struct pci_dev *pdev = to_pci_dev(dev);
struct dw_mci *host = pci_get_drvdata(pdev);
ret = dw_mci_resume(host);
return ret;
}
