static void xhci_plat_quirks(struct device *dev, struct xhci_hcd *xhci)
{
xhci->quirks |= XHCI_BROKEN_MSI;
}
static int xhci_plat_setup(struct usb_hcd *hcd)
{
return xhci_gen_setup(hcd, xhci_plat_quirks);
}
static int xhci_plat_probe(struct platform_device *pdev)
{
const struct hc_driver *driver;
struct xhci_hcd *xhci;
struct resource *res;
struct usb_hcd *hcd;
int ret;
int irq;
if (usb_disabled())
return -ENODEV;
driver = &xhci_plat_xhci_driver;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return -ENODEV;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
hcd = usb_create_hcd(driver, &pdev->dev, dev_name(&pdev->dev));
if (!hcd)
return -ENOMEM;
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len,
driver->description)) {
dev_dbg(&pdev->dev, "controller already in use\n");
ret = -EBUSY;
goto put_hcd;
}
hcd->regs = ioremap_nocache(hcd->rsrc_start, hcd->rsrc_len);
if (!hcd->regs) {
dev_dbg(&pdev->dev, "error mapping memory\n");
ret = -EFAULT;
goto release_mem_region;
}
ret = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (ret)
goto unmap_registers;
hcd = dev_get_drvdata(&pdev->dev);
xhci = hcd_to_xhci(hcd);
xhci->shared_hcd = usb_create_shared_hcd(driver, &pdev->dev,
dev_name(&pdev->dev), hcd);
if (!xhci->shared_hcd) {
ret = -ENOMEM;
goto dealloc_usb2_hcd;
}
*((struct xhci_hcd **) xhci->shared_hcd->hcd_priv) = xhci;
ret = usb_add_hcd(xhci->shared_hcd, irq, IRQF_SHARED);
if (ret)
goto put_usb3_hcd;
return 0;
put_usb3_hcd:
usb_put_hcd(xhci->shared_hcd);
dealloc_usb2_hcd:
usb_remove_hcd(hcd);
unmap_registers:
iounmap(hcd->regs);
release_mem_region:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
put_hcd:
usb_put_hcd(hcd);
return ret;
}
static int xhci_plat_remove(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
usb_remove_hcd(xhci->shared_hcd);
usb_put_hcd(xhci->shared_hcd);
usb_remove_hcd(hcd);
iounmap(hcd->regs);
usb_put_hcd(hcd);
kfree(xhci);
return 0;
}
int xhci_register_plat(void)
{
return platform_driver_register(&usb_xhci_driver);
}
void xhci_unregister_plat(void)
{
platform_driver_unregister(&usb_xhci_driver);
}
