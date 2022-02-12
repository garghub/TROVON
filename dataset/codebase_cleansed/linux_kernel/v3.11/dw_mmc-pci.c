static int dw_mci_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *entries)
{
struct dw_mci *host;
int ret;
ret = pcim_enable_device(pdev);
if (ret)
return ret;
host = devm_kzalloc(&pdev->dev, sizeof(struct dw_mci), GFP_KERNEL);
if (!host)
return -ENOMEM;
host->irq = pdev->irq;
host->irq_flags = IRQF_SHARED;
host->dev = &pdev->dev;
host->pdata = &pci_board_data;
ret = pcim_iomap_regions(pdev, 1 << PCI_BAR_NO, pci_name(pdev));
if (ret)
return ret;
host->regs = pcim_iomap_table(pdev)[0];
ret = dw_mci_probe(host);
if (ret)
return ret;
pci_set_drvdata(pdev, host);
return 0;
}
static void dw_mci_pci_remove(struct pci_dev *pdev)
{
struct dw_mci *host = pci_get_drvdata(pdev);
dw_mci_remove(host);
}
static int dw_mci_pci_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct dw_mci *host = pci_get_drvdata(pdev);
return dw_mci_suspend(host);
}
static int dw_mci_pci_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct dw_mci *host = pci_get_drvdata(pdev);
return dw_mci_resume(host);
}
