static int ohci_platform_reset(struct usb_hcd *hcd)
{
struct platform_device *pdev = to_platform_device(hcd->self.controller);
struct usb_ohci_pdata *pdata = dev_get_platdata(&pdev->dev);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
if (pdata->big_endian_desc)
ohci->flags |= OHCI_QUIRK_BE_DESC;
if (pdata->big_endian_mmio)
ohci->flags |= OHCI_QUIRK_BE_MMIO;
if (pdata->no_big_frame_no)
ohci->flags |= OHCI_QUIRK_FRAME_NO;
if (pdata->num_ports)
ohci->num_ports = pdata->num_ports;
return ohci_setup(hcd);
}
static int ohci_platform_probe(struct platform_device *dev)
{
struct usb_hcd *hcd;
struct resource *res_mem;
struct usb_ohci_pdata *pdata = dev_get_platdata(&dev->dev);
int irq;
int err = -ENOMEM;
if (!pdata) {
WARN_ON(1);
return -ENODEV;
}
if (usb_disabled())
return -ENODEV;
irq = platform_get_irq(dev, 0);
if (irq < 0) {
dev_err(&dev->dev, "no irq provided");
return irq;
}
res_mem = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!res_mem) {
dev_err(&dev->dev, "no memory resource provided");
return -ENXIO;
}
if (pdata->power_on) {
err = pdata->power_on(dev);
if (err < 0)
return err;
}
hcd = usb_create_hcd(&ohci_platform_hc_driver, &dev->dev,
dev_name(&dev->dev));
if (!hcd) {
err = -ENOMEM;
goto err_power;
}
hcd->rsrc_start = res_mem->start;
hcd->rsrc_len = resource_size(res_mem);
hcd->regs = devm_ioremap_resource(&dev->dev, res_mem);
if (IS_ERR(hcd->regs)) {
err = PTR_ERR(hcd->regs);
goto err_put_hcd;
}
err = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (err)
goto err_put_hcd;
platform_set_drvdata(dev, hcd);
return err;
err_put_hcd:
usb_put_hcd(hcd);
err_power:
if (pdata->power_off)
pdata->power_off(dev);
return err;
}
static int ohci_platform_remove(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct usb_ohci_pdata *pdata = dev_get_platdata(&dev->dev);
usb_remove_hcd(hcd);
usb_put_hcd(hcd);
if (pdata->power_off)
pdata->power_off(dev);
return 0;
}
static int ohci_platform_suspend(struct device *dev)
{
struct usb_ohci_pdata *pdata = dev_get_platdata(dev);
struct platform_device *pdev =
container_of(dev, struct platform_device, dev);
if (pdata->power_suspend)
pdata->power_suspend(pdev);
return 0;
}
static int ohci_platform_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct usb_ohci_pdata *pdata = dev_get_platdata(dev);
struct platform_device *pdev =
container_of(dev, struct platform_device, dev);
if (pdata->power_on) {
int err = pdata->power_on(pdev);
if (err < 0)
return err;
}
ohci_resume(hcd, false);
return 0;
}
static int __init ohci_platform_init(void)
{
if (usb_disabled())
return -ENODEV;
pr_info("%s: " DRIVER_DESC "\n", hcd_name);
ohci_init_driver(&ohci_platform_hc_driver, &platform_overrides);
return platform_driver_register(&ohci_platform_driver);
}
static void __exit ohci_platform_cleanup(void)
{
platform_driver_unregister(&ohci_platform_driver);
}
