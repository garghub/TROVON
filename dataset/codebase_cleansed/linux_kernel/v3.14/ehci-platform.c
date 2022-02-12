static int ehci_platform_reset(struct usb_hcd *hcd)
{
struct platform_device *pdev = to_platform_device(hcd->self.controller);
struct usb_ehci_pdata *pdata = dev_get_platdata(&pdev->dev);
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int retval;
hcd->has_tt = pdata->has_tt;
ehci->has_synopsys_hc_bug = pdata->has_synopsys_hc_bug;
ehci->big_endian_desc = pdata->big_endian_desc;
ehci->big_endian_mmio = pdata->big_endian_mmio;
if (pdata->pre_setup) {
retval = pdata->pre_setup(hcd);
if (retval < 0)
return retval;
}
ehci->caps = hcd->regs + pdata->caps_offset;
retval = ehci_setup(hcd);
if (retval)
return retval;
if (pdata->no_io_watchdog)
ehci->need_io_watchdog = 0;
return 0;
}
static int ehci_platform_probe(struct platform_device *dev)
{
struct usb_hcd *hcd;
struct resource *res_mem;
struct usb_ehci_pdata *pdata;
int irq;
int err;
if (usb_disabled())
return -ENODEV;
if (!dev_get_platdata(&dev->dev))
dev->dev.platform_data = &ehci_platform_defaults;
err = dma_coerce_mask_and_coherent(&dev->dev, DMA_BIT_MASK(32));
if (err)
return err;
pdata = dev_get_platdata(&dev->dev);
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
hcd = usb_create_hcd(&ehci_platform_hc_driver, &dev->dev,
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
device_wakeup_enable(hcd->self.controller);
platform_set_drvdata(dev, hcd);
return err;
err_put_hcd:
usb_put_hcd(hcd);
err_power:
if (pdata->power_off)
pdata->power_off(dev);
return err;
}
static int ehci_platform_remove(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct usb_ehci_pdata *pdata = dev_get_platdata(&dev->dev);
usb_remove_hcd(hcd);
usb_put_hcd(hcd);
if (pdata->power_off)
pdata->power_off(dev);
if (pdata == &ehci_platform_defaults)
dev->dev.platform_data = NULL;
return 0;
}
static int ehci_platform_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct usb_ehci_pdata *pdata = dev_get_platdata(dev);
struct platform_device *pdev =
container_of(dev, struct platform_device, dev);
bool do_wakeup = device_may_wakeup(dev);
int ret;
ret = ehci_suspend(hcd, do_wakeup);
if (pdata->power_suspend)
pdata->power_suspend(pdev);
return ret;
}
static int ehci_platform_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct usb_ehci_pdata *pdata = dev_get_platdata(dev);
struct platform_device *pdev =
container_of(dev, struct platform_device, dev);
if (pdata->power_on) {
int err = pdata->power_on(pdev);
if (err < 0)
return err;
}
ehci_resume(hcd, false);
return 0;
}
static int __init ehci_platform_init(void)
{
if (usb_disabled())
return -ENODEV;
pr_info("%s: " DRIVER_DESC "\n", hcd_name);
ehci_init_driver(&ehci_platform_hc_driver, &platform_overrides);
return platform_driver_register(&ehci_platform_driver);
}
static void __exit ehci_platform_cleanup(void)
{
platform_driver_unregister(&ehci_platform_driver);
}
