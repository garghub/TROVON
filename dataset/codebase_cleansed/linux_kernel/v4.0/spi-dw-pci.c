static int spi_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct dw_spi_pci *dwpci;
struct dw_spi *dws;
struct spi_pci_desc *desc = (struct spi_pci_desc *)ent->driver_data;
int pci_bar = 0;
int ret;
ret = pcim_enable_device(pdev);
if (ret)
return ret;
dwpci = devm_kzalloc(&pdev->dev, sizeof(struct dw_spi_pci),
GFP_KERNEL);
if (!dwpci)
return -ENOMEM;
dwpci->pdev = pdev;
dws = &dwpci->dws;
dws->paddr = pci_resource_start(pdev, pci_bar);
ret = pcim_iomap_regions(pdev, 1 << pci_bar, pci_name(pdev));
if (ret)
return ret;
dws->regs = pcim_iomap_table(pdev)[pci_bar];
dws->irq = pdev->irq;
if (desc) {
dws->num_cs = desc->num_cs;
dws->bus_num = desc->bus_num;
if (desc->setup) {
ret = desc->setup(dws);
if (ret)
return ret;
}
} else {
return -ENODEV;
}
ret = dw_spi_add_host(&pdev->dev, dws);
if (ret)
return ret;
pci_set_drvdata(pdev, dwpci);
dev_info(&pdev->dev, "found PCI SPI controller(ID: %04x:%04x)\n",
pdev->vendor, pdev->device);
return 0;
}
static void spi_pci_remove(struct pci_dev *pdev)
{
struct dw_spi_pci *dwpci = pci_get_drvdata(pdev);
dw_spi_remove_host(&dwpci->dws);
}
static int spi_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct dw_spi_pci *dwpci = pci_get_drvdata(pdev);
return dw_spi_suspend_host(&dwpci->dws);
}
static int spi_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct dw_spi_pci *dwpci = pci_get_drvdata(pdev);
return dw_spi_resume_host(&dwpci->dws);
}
