static int __devinit ci13xxx_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct ci13xxx_udc_driver *driver = (void *)id->driver_data;
struct platform_device *plat_ci;
struct resource res[3];
int retval = 0, nres = 2;
if (!driver) {
dev_err(&pdev->dev, "device doesn't provide driver data\n");
return -ENODEV;
}
retval = pci_enable_device(pdev);
if (retval)
goto done;
if (!pdev->irq) {
dev_err(&pdev->dev, "No IRQ, check BIOS/PCI setup!");
retval = -ENODEV;
goto disable_device;
}
pci_set_power_state(pdev, PCI_D0);
pci_set_master(pdev);
pci_try_set_mwi(pdev);
plat_ci = platform_device_alloc("ci_hdrc", -1);
if (!plat_ci) {
dev_err(&pdev->dev, "can't allocate ci_hdrc platform device\n");
retval = -ENOMEM;
goto disable_device;
}
memset(res, 0, sizeof(res));
res[0].start = pci_resource_start(pdev, 0);
res[0].end = pci_resource_end(pdev, 0);
res[0].flags = IORESOURCE_MEM;
res[1].start = pdev->irq;
res[1].flags = IORESOURCE_IRQ;
retval = platform_device_add_resources(plat_ci, res, nres);
if (retval) {
dev_err(&pdev->dev, "can't add resources to platform device\n");
goto put_platform;
}
retval = platform_device_add_data(plat_ci, driver, sizeof(*driver));
if (retval)
goto put_platform;
dma_set_coherent_mask(&plat_ci->dev, pdev->dev.coherent_dma_mask);
plat_ci->dev.dma_mask = pdev->dev.dma_mask;
plat_ci->dev.dma_parms = pdev->dev.dma_parms;
plat_ci->dev.parent = &pdev->dev;
pci_set_drvdata(pdev, plat_ci);
retval = platform_device_add(plat_ci);
if (retval)
goto put_platform;
return 0;
put_platform:
pci_set_drvdata(pdev, NULL);
platform_device_put(plat_ci);
disable_device:
pci_disable_device(pdev);
done:
return retval;
}
static void __devexit ci13xxx_pci_remove(struct pci_dev *pdev)
{
struct platform_device *plat_ci = pci_get_drvdata(pdev);
platform_device_unregister(plat_ci);
pci_set_drvdata(pdev, NULL);
pci_disable_device(pdev);
}
