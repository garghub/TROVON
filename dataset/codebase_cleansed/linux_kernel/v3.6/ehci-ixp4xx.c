static int ixp4xx_ehci_init(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int retval = 0;
ehci->big_endian_desc = 1;
ehci->big_endian_mmio = 1;
ehci->caps = hcd->regs + 0x100;
hcd->has_tt = 1;
retval = ehci_setup(hcd);
if (retval)
return retval;
ehci_port_power(ehci, 0);
return retval;
}
static int ixp4xx_ehci_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
const struct hc_driver *driver = &ixp4xx_ehci_hc_driver;
struct resource *res;
int irq;
int retval;
if (usb_disabled())
return -ENODEV;
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_err(&pdev->dev,
"Found HC with no IRQ. Check %s setup!\n",
dev_name(&pdev->dev));
return -ENODEV;
}
irq = res->start;
hcd = usb_create_hcd(driver, &pdev->dev, dev_name(&pdev->dev));
if (!hcd) {
retval = -ENOMEM;
goto fail_create_hcd;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev,
"Found HC with no register addr. Check %s setup!\n",
dev_name(&pdev->dev));
retval = -ENODEV;
goto fail_request_resource;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len,
driver->description)) {
dev_dbg(&pdev->dev, "controller already in use\n");
retval = -EBUSY;
goto fail_request_resource;
}
hcd->regs = ioremap_nocache(hcd->rsrc_start, hcd->rsrc_len);
if (hcd->regs == NULL) {
dev_dbg(&pdev->dev, "error mapping memory\n");
retval = -EFAULT;
goto fail_ioremap;
}
retval = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (retval)
goto fail_add_hcd;
return retval;
fail_add_hcd:
iounmap(hcd->regs);
fail_ioremap:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
fail_request_resource:
usb_put_hcd(hcd);
fail_create_hcd:
dev_err(&pdev->dev, "init %s fail, %d\n", dev_name(&pdev->dev), retval);
return retval;
}
static int ixp4xx_ehci_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
return 0;
}
