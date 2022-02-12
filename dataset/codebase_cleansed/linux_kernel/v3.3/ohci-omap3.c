static int ohci_omap3_init(struct usb_hcd *hcd)
{
dev_dbg(hcd->self.controller, "starting OHCI controller\n");
return ohci_init(hcd_to_ohci(hcd));
}
static int ohci_omap3_start(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
int ret;
ohci->hc_control = OHCI_CTRL_RWC;
writel(OHCI_CTRL_RWC, &ohci->regs->control);
ret = ohci_run(ohci);
if (ret < 0) {
dev_err(hcd->self.controller, "can't start\n");
ohci_stop(hcd);
}
return ret;
}
static int __devinit ohci_hcd_omap3_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct usb_hcd *hcd = NULL;
void __iomem *regs = NULL;
struct resource *res;
int ret = -ENODEV;
int irq;
if (usb_disabled())
return -ENODEV;
if (!dev->parent) {
dev_err(dev, "Missing parent device\n");
return -ENODEV;
}
irq = platform_get_irq_byname(pdev, "ohci-irq");
if (irq < 0) {
dev_err(dev, "OHCI irq failed\n");
return -ENODEV;
}
res = platform_get_resource_byname(pdev,
IORESOURCE_MEM, "ohci");
if (!res) {
dev_err(dev, "UHH OHCI get resource failed\n");
return -ENOMEM;
}
regs = ioremap(res->start, resource_size(res));
if (!regs) {
dev_err(dev, "UHH OHCI ioremap failed\n");
return -ENOMEM;
}
hcd = usb_create_hcd(&ohci_omap3_hc_driver, dev,
dev_name(dev));
if (!hcd) {
dev_err(dev, "usb_create_hcd failed\n");
goto err_io;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
hcd->regs = regs;
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
ohci_hcd_init(hcd_to_ohci(hcd));
ret = usb_add_hcd(hcd, irq, 0);
if (ret) {
dev_dbg(dev, "failed to add hcd with err %d\n", ret);
goto err_add_hcd;
}
return 0;
err_add_hcd:
pm_runtime_put_sync(dev);
usb_put_hcd(hcd);
err_io:
iounmap(regs);
return ret;
}
static int __devexit ohci_hcd_omap3_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct usb_hcd *hcd = dev_get_drvdata(dev);
iounmap(hcd->regs);
usb_remove_hcd(hcd);
pm_runtime_put_sync(dev);
pm_runtime_disable(dev);
usb_put_hcd(hcd);
return 0;
}
static void ohci_hcd_omap3_shutdown(struct platform_device *pdev)
{
struct usb_hcd *hcd = dev_get_drvdata(&pdev->dev);
if (hcd->driver->shutdown)
hcd->driver->shutdown(hcd);
}
