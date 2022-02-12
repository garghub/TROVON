static int spi_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct dw_spi_pci *dwpci;
struct dw_spi *dws;
int pci_bar = 0;
int ret;
dev_info(&pdev->dev, "found PCI SPI controller(ID: %04x:%04x)\n",
pdev->vendor, pdev->device);
ret = pci_enable_device(pdev);
if (ret)
return ret;
dwpci = kzalloc(sizeof(struct dw_spi_pci), GFP_KERNEL);
if (!dwpci) {
ret = -ENOMEM;
goto err_disable;
}
dwpci->pdev = pdev;
dws = &dwpci->dws;
dws->paddr = pci_resource_start(pdev, pci_bar);
dws->iolen = pci_resource_len(pdev, pci_bar);
ret = pci_request_region(pdev, pci_bar, dev_name(&pdev->dev));
if (ret)
goto err_kfree;
dws->regs = ioremap_nocache((unsigned long)dws->paddr,
pci_resource_len(pdev, pci_bar));
if (!dws->regs) {
ret = -ENOMEM;
goto err_release_reg;
}
dws->parent_dev = &pdev->dev;
dws->bus_num = 0;
dws->num_cs = 4;
dws->irq = pdev->irq;
if (pdev->device == 0x0800) {
ret = dw_spi_mid_init(dws);
if (ret)
goto err_unmap;
}
ret = dw_spi_add_host(dws);
if (ret)
goto err_unmap;
pci_set_drvdata(pdev, dwpci);
return 0;
err_unmap:
iounmap(dws->regs);
err_release_reg:
pci_release_region(pdev, pci_bar);
err_kfree:
kfree(dwpci);
err_disable:
pci_disable_device(pdev);
return ret;
}
static void spi_pci_remove(struct pci_dev *pdev)
{
struct dw_spi_pci *dwpci = pci_get_drvdata(pdev);
dw_spi_remove_host(&dwpci->dws);
iounmap(dwpci->dws.regs);
pci_release_region(pdev, 0);
kfree(dwpci);
pci_disable_device(pdev);
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
