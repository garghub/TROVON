static int spi_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct dw_spi_pci *dwpci;
struct dw_spi *dws;
int pci_bar = 0;
int ret;
dev_info(&pdev->dev, "found PCI SPI controller(ID: %04x:%04x)\n",
pdev->vendor, pdev->device);
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
ret = pcim_iomap_regions(pdev, 1, dev_name(&pdev->dev));
if (ret)
return ret;
dws->bus_num = 0;
dws->num_cs = 4;
dws->irq = pdev->irq;
if (pdev->device == 0x0800) {
ret = dw_spi_mid_init(dws);
if (ret)
return ret;
}
ret = dw_spi_add_host(&pdev->dev, dws);
if (ret)
return ret;
pci_set_drvdata(pdev, dwpci);
return 0;
}
static void spi_pci_remove(struct pci_dev *pdev)
{
struct dw_spi_pci *dwpci = pci_get_drvdata(pdev);
dw_spi_remove_host(&dwpci->dws);
}
static int spi_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct dw_spi_pci *dwpci = pci_get_drvdata(pdev);
int ret;
ret = dw_spi_suspend_host(&dwpci->dws);
if (ret)
return ret;
pci_save_state(pdev);
pci_disable_device(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return ret;
}
static int spi_resume(struct pci_dev *pdev)
{
struct dw_spi_pci *dwpci = pci_get_drvdata(pdev);
int ret;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
ret = pci_enable_device(pdev);
if (ret)
return ret;
return dw_spi_resume_host(&dwpci->dws);
}
