static int ehci_platform_reset(struct usb_hcd *hcd)
{
struct platform_device *pdev = to_platform_device(hcd->self.controller);
struct usb_ehci_pdata *pdata = pdev->dev.platform_data;
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int retval;
hcd->has_tt = pdata->has_tt;
ehci->has_synopsys_hc_bug = pdata->has_synopsys_hc_bug;
ehci->big_endian_desc = pdata->big_endian_desc;
ehci->big_endian_mmio = pdata->big_endian_mmio;
ehci->caps = hcd->regs + pdata->caps_offset;
retval = ehci_setup(hcd);
if (retval)
return retval;
if (pdata->port_power_on)
ehci_port_power(ehci, 1);
if (pdata->port_power_off)
ehci_port_power(ehci, 0);
return 0;
}
static int __devinit ehci_platform_probe(struct platform_device *dev)
{
struct usb_hcd *hcd;
struct resource *res_mem;
int irq;
int err = -ENOMEM;
BUG_ON(!dev->dev.platform_data);
if (usb_disabled())
return -ENODEV;
irq = platform_get_irq(dev, 0);
if (irq < 0) {
pr_err("no irq provided");
return irq;
}
res_mem = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!res_mem) {
pr_err("no memory recourse provided");
return -ENXIO;
}
hcd = usb_create_hcd(&ehci_platform_hc_driver, &dev->dev,
dev_name(&dev->dev));
if (!hcd)
return -ENOMEM;
hcd->rsrc_start = res_mem->start;
hcd->rsrc_len = resource_size(res_mem);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name)) {
pr_err("controller already in use");
err = -EBUSY;
goto err_put_hcd;
}
hcd->regs = ioremap_nocache(hcd->rsrc_start, hcd->rsrc_len);
if (!hcd->regs)
goto err_release_region;
err = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (err)
goto err_iounmap;
platform_set_drvdata(dev, hcd);
return err;
err_iounmap:
iounmap(hcd->regs);
err_release_region:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err_put_hcd:
usb_put_hcd(hcd);
return err;
}
static int __devexit ehci_platform_remove(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
usb_remove_hcd(hcd);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
platform_set_drvdata(dev, NULL);
return 0;
}
static int ehci_platform_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
bool do_wakeup = device_may_wakeup(dev);
return ehci_suspend(hcd, do_wakeup);
}
static int ehci_platform_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
ehci_resume(hcd, false);
return 0;
}
