static int ohci_xls_probe_internal(const struct hc_driver *driver,
struct platform_device *dev)
{
struct resource *res;
struct usb_hcd *hcd;
int retval, irq;
irq = platform_get_irq(dev, 0);
if (irq < 0) {
dev_err(&dev->dev, "Found HC with no IRQ\n");
return -ENODEV;
}
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&dev->dev, "MMIO Handle incorrect!\n");
return -ENODEV;
}
hcd = usb_create_hcd(driver, &dev->dev, "XLS");
if (!hcd) {
retval = -ENOMEM;
goto err1;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len,
driver->description)) {
dev_dbg(&dev->dev, "Controller already in use\n");
retval = -EBUSY;
goto err2;
}
hcd->regs = ioremap_nocache(hcd->rsrc_start, hcd->rsrc_len);
if (hcd->regs == NULL) {
dev_dbg(&dev->dev, "error mapping memory\n");
retval = -EFAULT;
goto err3;
}
retval = usb_add_hcd(hcd, irq, IRQF_DISABLED | IRQF_SHARED);
if (retval != 0)
goto err4;
return retval;
err4:
iounmap(hcd->regs);
err3:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err2:
usb_put_hcd(hcd);
err1:
dev_err(&dev->dev, "init fail, %d\n", retval);
return retval;
}
static int ohci_xls_reset(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
ohci_hcd_init(ohci);
return ohci_init(ohci);
}
static int __devinit ohci_xls_start(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci;
int ret;
ohci = hcd_to_ohci(hcd);
ret = ohci_run(ohci);
if (ret < 0) {
err("can't start %s", hcd->self.bus_name);
ohci_stop(hcd);
return ret;
}
return 0;
}
static int ohci_xls_probe(struct platform_device *dev)
{
int ret;
pr_debug("In ohci_xls_probe");
if (usb_disabled())
return -ENODEV;
ret = ohci_xls_probe_internal(&ohci_xls_hc_driver, dev);
return ret;
}
static int ohci_xls_remove(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
usb_remove_hcd(hcd);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
return 0;
}
