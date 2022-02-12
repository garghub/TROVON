static int vmic_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
int retval;
u32 data;
retval = pci_enable_device(pdev);
if (retval) {
dev_err(&pdev->dev, "Unable to enable device\n");
goto err;
}
retval = pci_request_regions(pdev, driver_name);
if (retval) {
dev_err(&pdev->dev, "Unable to reserve resources\n");
goto err_resource;
}
vmic_base = ioremap_nocache(pci_resource_start(pdev, 0), 16);
if (!vmic_base) {
dev_err(&pdev->dev, "Unable to remap CRG region\n");
retval = -EIO;
goto err_remap;
}
iowrite32(0, vmic_base + VME_CONTROL);
data = ioread32(vmic_base + VME_CONTROL) & 0x00000FFF;
data |= BM_VME_CONTROL_BERRST;
iowrite32(data, vmic_base + VME_CONTROL);
data = ioread32(vmic_base + VME_CONTROL) & 0x00000FFF;
data = data | BM_VME_CONTROL_MASTER_ENDIAN |
BM_VME_CONTROL_SLAVE_ENDIAN |
BM_VME_CONTROL_ABLE |
BM_VME_CONTROL_BERRI |
BM_VME_CONTROL_BPENA |
BM_VME_CONTROL_VBENA;
iowrite32(data, vmic_base + VME_CONTROL);
return 0;
err_remap:
pci_release_regions(pdev);
err_resource:
pci_disable_device(pdev);
err:
return retval;
}
static void vmic_remove(struct pci_dev *pdev)
{
iounmap(vmic_base);
pci_release_regions(pdev);
pci_disable_device(pdev);
}
