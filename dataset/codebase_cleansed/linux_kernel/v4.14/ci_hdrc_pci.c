static int ci_hdrc_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct ci_hdrc_platform_data *platdata = (void *)id->driver_data;
struct ci_hdrc_pci *ci;
struct resource res[3];
int retval = 0, nres = 2;
if (!platdata) {
dev_err(&pdev->dev, "device doesn't provide driver data\n");
return -ENODEV;
}
ci = devm_kzalloc(&pdev->dev, sizeof(*ci), GFP_KERNEL);
if (!ci)
return -ENOMEM;
retval = pcim_enable_device(pdev);
if (retval)
return retval;
if (!pdev->irq) {
dev_err(&pdev->dev, "No IRQ, check BIOS/PCI setup!");
return -ENODEV;
}
pci_set_master(pdev);
pci_try_set_mwi(pdev);
ci->phy = usb_phy_generic_register();
if (IS_ERR(ci->phy))
return PTR_ERR(ci->phy);
memset(res, 0, sizeof(res));
res[0].start = pci_resource_start(pdev, 0);
res[0].end = pci_resource_end(pdev, 0);
res[0].flags = IORESOURCE_MEM;
res[1].start = pdev->irq;
res[1].flags = IORESOURCE_IRQ;
ci->ci = ci_hdrc_add_device(&pdev->dev, res, nres, platdata);
if (IS_ERR(ci->ci)) {
dev_err(&pdev->dev, "ci_hdrc_add_device failed!\n");
usb_phy_generic_unregister(ci->phy);
return PTR_ERR(ci->ci);
}
pci_set_drvdata(pdev, ci);
return 0;
}
static void ci_hdrc_pci_remove(struct pci_dev *pdev)
{
struct ci_hdrc_pci *ci = pci_get_drvdata(pdev);
ci_hdrc_remove_device(ci->ci);
usb_phy_generic_unregister(ci->phy);
}
