static int ci_hdrc_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct ci_hdrc_platform_data *platdata = (void *)id->driver_data;
struct platform_device *plat_ci;
struct resource res[3];
int retval = 0, nres = 2;
if (!platdata) {
dev_err(&pdev->dev, "device doesn't provide driver data\n");
return -ENODEV;
}
retval = pcim_enable_device(pdev);
if (retval)
return retval;
if (!pdev->irq) {
dev_err(&pdev->dev, "No IRQ, check BIOS/PCI setup!");
return -ENODEV;
}
pci_set_master(pdev);
pci_try_set_mwi(pdev);
memset(res, 0, sizeof(res));
res[0].start = pci_resource_start(pdev, 0);
res[0].end = pci_resource_end(pdev, 0);
res[0].flags = IORESOURCE_MEM;
res[1].start = pdev->irq;
res[1].flags = IORESOURCE_IRQ;
plat_ci = ci_hdrc_add_device(&pdev->dev, res, nres, platdata);
if (IS_ERR(plat_ci)) {
dev_err(&pdev->dev, "ci_hdrc_add_device failed!\n");
return PTR_ERR(plat_ci);
}
pci_set_drvdata(pdev, plat_ci);
return 0;
}
static void ci_hdrc_pci_remove(struct pci_dev *pdev)
{
struct platform_device *plat_ci = pci_get_drvdata(pdev);
ci_hdrc_remove_device(plat_ci);
}
