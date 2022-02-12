static int au1xxx_ehci_setup(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int ret;
ehci->caps = hcd->regs;
ret = ehci_setup(hcd);
ehci->need_io_watchdog = 0;
return ret;
}
static int ehci_hcd_au1xxx_drv_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
struct resource *res;
int ret;
if (usb_disabled())
return -ENODEV;
if (pdev->resource[1].flags != IORESOURCE_IRQ) {
pr_debug("resource[1] is not IORESOURCE_IRQ");
return -ENOMEM;
}
hcd = usb_create_hcd(&ehci_au1xxx_hc_driver, &pdev->dev, "Au1xxx");
if (!hcd)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name)) {
pr_debug("request_mem_region failed");
ret = -EBUSY;
goto err1;
}
hcd->regs = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (!hcd->regs) {
pr_debug("ioremap failed");
ret = -ENOMEM;
goto err2;
}
if (alchemy_usb_control(ALCHEMY_USB_EHCI0, 1)) {
printk(KERN_INFO "%s: controller init failed!\n", pdev->name);
ret = -ENODEV;
goto err3;
}
ret = usb_add_hcd(hcd, pdev->resource[1].start,
IRQF_SHARED);
if (ret == 0) {
platform_set_drvdata(pdev, hcd);
return ret;
}
alchemy_usb_control(ALCHEMY_USB_EHCI0, 0);
err3:
iounmap(hcd->regs);
err2:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err1:
usb_put_hcd(hcd);
return ret;
}
static int ehci_hcd_au1xxx_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
alchemy_usb_control(ALCHEMY_USB_EHCI0, 0);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int ehci_hcd_au1xxx_drv_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
bool do_wakeup = device_may_wakeup(dev);
int rc;
rc = ehci_suspend(hcd, do_wakeup);
alchemy_usb_control(ALCHEMY_USB_EHCI0, 0);
return rc;
}
static int ehci_hcd_au1xxx_drv_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
alchemy_usb_control(ALCHEMY_USB_EHCI0, 1);
ehci_resume(hcd, false);
return 0;
}
