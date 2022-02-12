static int dwc3_pci_register_phys(struct dwc3_pci *glue)
{
struct usb_phy_generic_platform_data pdata;
struct platform_device *pdev;
int ret;
memset(&pdata, 0x00, sizeof(pdata));
pdev = platform_device_alloc("usb_phy_generic", 0);
if (!pdev)
return -ENOMEM;
glue->usb2_phy = pdev;
pdata.type = USB_PHY_TYPE_USB2;
pdata.gpio_reset = -1;
ret = platform_device_add_data(glue->usb2_phy, &pdata, sizeof(pdata));
if (ret)
goto err1;
pdev = platform_device_alloc("usb_phy_generic", 1);
if (!pdev) {
ret = -ENOMEM;
goto err1;
}
glue->usb3_phy = pdev;
pdata.type = USB_PHY_TYPE_USB3;
ret = platform_device_add_data(glue->usb3_phy, &pdata, sizeof(pdata));
if (ret)
goto err2;
ret = platform_device_add(glue->usb2_phy);
if (ret)
goto err2;
ret = platform_device_add(glue->usb3_phy);
if (ret)
goto err3;
return 0;
err3:
platform_device_del(glue->usb2_phy);
err2:
platform_device_put(glue->usb3_phy);
err1:
platform_device_put(glue->usb2_phy);
return ret;
}
static int dwc3_pci_probe(struct pci_dev *pci,
const struct pci_device_id *id)
{
struct resource res[2];
struct platform_device *dwc3;
struct dwc3_pci *glue;
int ret;
struct device *dev = &pci->dev;
glue = devm_kzalloc(dev, sizeof(*glue), GFP_KERNEL);
if (!glue) {
dev_err(dev, "not enough memory\n");
return -ENOMEM;
}
glue->dev = dev;
ret = pcim_enable_device(pci);
if (ret) {
dev_err(dev, "failed to enable pci device\n");
return -ENODEV;
}
pci_set_master(pci);
ret = dwc3_pci_register_phys(glue);
if (ret) {
dev_err(dev, "couldn't register PHYs\n");
return ret;
}
dwc3 = platform_device_alloc("dwc3", PLATFORM_DEVID_AUTO);
if (!dwc3) {
dev_err(dev, "couldn't allocate dwc3 device\n");
return -ENOMEM;
}
memset(res, 0x00, sizeof(struct resource) * ARRAY_SIZE(res));
res[0].start = pci_resource_start(pci, 0);
res[0].end = pci_resource_end(pci, 0);
res[0].name = "dwc_usb3";
res[0].flags = IORESOURCE_MEM;
res[1].start = pci->irq;
res[1].name = "dwc_usb3";
res[1].flags = IORESOURCE_IRQ;
ret = platform_device_add_resources(dwc3, res, ARRAY_SIZE(res));
if (ret) {
dev_err(dev, "couldn't add resources to dwc3 device\n");
return ret;
}
pci_set_drvdata(pci, glue);
dma_set_coherent_mask(&dwc3->dev, dev->coherent_dma_mask);
dwc3->dev.dma_mask = dev->dma_mask;
dwc3->dev.dma_parms = dev->dma_parms;
dwc3->dev.parent = dev;
glue->dwc3 = dwc3;
ret = platform_device_add(dwc3);
if (ret) {
dev_err(dev, "failed to register dwc3 device\n");
goto err3;
}
return 0;
err3:
platform_device_put(dwc3);
return ret;
}
static void dwc3_pci_remove(struct pci_dev *pci)
{
struct dwc3_pci *glue = pci_get_drvdata(pci);
platform_device_unregister(glue->dwc3);
platform_device_unregister(glue->usb2_phy);
platform_device_unregister(glue->usb3_phy);
}
static int dwc3_pci_suspend(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
pci_disable_device(pci);
return 0;
}
static int dwc3_pci_resume(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
int ret;
ret = pci_enable_device(pci);
if (ret) {
dev_err(dev, "can't re-enable device --> %d\n", ret);
return ret;
}
pci_set_master(pci);
return 0;
}
