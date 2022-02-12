static int ehci_sead3_setup(struct usb_hcd *hcd)
{
int ret;
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
ehci->caps = hcd->regs + 0x100;
#ifdef __BIG_ENDIAN
ehci->big_endian_mmio = 1;
ehci->big_endian_desc = 1;
#endif
ret = ehci_setup(hcd);
if (ret)
return ret;
ehci->need_io_watchdog = 0;
ehci_writel(ehci, 0x1010, &ehci->regs->reserved1[1]);
return ret;
}
static int ehci_hcd_sead3_drv_probe(struct platform_device *pdev)
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
hcd = usb_create_hcd(&ehci_sead3_hc_driver, &pdev->dev, "SEAD-3");
if (!hcd)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hcd->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hcd->regs)) {
ret = PTR_ERR(hcd->regs);
goto err1;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
hcd->has_tt = 1;
ret = usb_add_hcd(hcd, pdev->resource[1].start,
IRQF_SHARED);
if (ret == 0) {
platform_set_drvdata(pdev, hcd);
device_wakeup_enable(hcd->self.controller);
return ret;
}
err1:
usb_put_hcd(hcd);
return ret;
}
static int ehci_hcd_sead3_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
usb_put_hcd(hcd);
return 0;
}
static int ehci_hcd_sead3_drv_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
bool do_wakeup = device_may_wakeup(dev);
return ehci_suspend(hcd, do_wakeup);
}
static int ehci_hcd_sead3_drv_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
ehci_resume(hcd, false);
return 0;
}
