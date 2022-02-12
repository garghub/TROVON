static int xlgmac_probe(struct pci_dev *pcidev, const struct pci_device_id *id)
{
struct device *dev = &pcidev->dev;
struct xlgmac_resources res;
int i, ret;
ret = pcim_enable_device(pcidev);
if (ret) {
dev_err(dev, "ERROR: failed to enable device\n");
return ret;
}
for (i = 0; i <= PCI_STD_RESOURCE_END; i++) {
if (pci_resource_len(pcidev, i) == 0)
continue;
ret = pcim_iomap_regions(pcidev, BIT(i), XLGMAC_DRV_NAME);
if (ret)
return ret;
break;
}
pci_set_master(pcidev);
memset(&res, 0, sizeof(res));
res.irq = pcidev->irq;
res.addr = pcim_iomap_table(pcidev)[i];
return xlgmac_drv_probe(&pcidev->dev, &res);
}
static void xlgmac_remove(struct pci_dev *pcidev)
{
xlgmac_drv_remove(&pcidev->dev);
}
