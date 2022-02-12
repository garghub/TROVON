static int ehci_update_device(struct usb_hcd *hcd, struct usb_device *udev)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int rc = 0;
if (!udev->parent)
rc = -1;
if (ehci->has_lpm && !udev->parent->parent) {
rc = ehci_lpm_set_da(ehci, udev->devnum, udev->portnum);
if (!rc)
rc = ehci_lpm_check(ehci, udev->portnum);
}
return rc;
}
static int vt8500_ehci_drv_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
struct ehci_hcd *ehci;
struct resource *res;
int ret;
if (usb_disabled())
return -ENODEV;
if (pdev->resource[1].flags != IORESOURCE_IRQ) {
pr_debug("resource[1] is not IORESOURCE_IRQ");
return -ENOMEM;
}
hcd = usb_create_hcd(&vt8500_ehci_hc_driver, &pdev->dev, "VT8500");
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
ehci = hcd_to_ehci(hcd);
ehci->caps = hcd->regs;
ehci->regs = hcd->regs +
HC_LENGTH(ehci, readl(&ehci->caps->hc_capbase));
dbg_hcs_params(ehci, "reset");
dbg_hcc_params(ehci, "reset");
ehci->hcs_params = readl(&ehci->caps->hcs_params);
ehci_port_power(ehci, 1);
ret = usb_add_hcd(hcd, pdev->resource[1].start,
IRQF_DISABLED | IRQF_SHARED);
if (ret == 0) {
platform_set_drvdata(pdev, hcd);
return ret;
}
iounmap(hcd->regs);
err2:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err1:
usb_put_hcd(hcd);
return ret;
}
static int vt8500_ehci_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
platform_set_drvdata(pdev, NULL);
return 0;
}
