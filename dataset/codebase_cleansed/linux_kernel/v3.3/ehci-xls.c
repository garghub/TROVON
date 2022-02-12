static int ehci_xls_setup(struct usb_hcd *hcd)
{
int retval;
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
ehci->caps = hcd->regs;
ehci->regs = hcd->regs +
HC_LENGTH(ehci, ehci_readl(ehci, &ehci->caps->hc_capbase));
dbg_hcs_params(ehci, "reset");
dbg_hcc_params(ehci, "reset");
ehci->hcs_params = ehci_readl(ehci, &ehci->caps->hcs_params);
retval = ehci_halt(ehci);
if (retval)
return retval;
retval = ehci_init(hcd);
if (retval)
return retval;
ehci_reset(ehci);
return retval;
}
int ehci_xls_probe_internal(const struct hc_driver *driver,
struct platform_device *pdev)
{
struct usb_hcd *hcd;
struct resource *res;
int retval, irq;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "Found HC with no IRQ. Check %s setup!\n",
dev_name(&pdev->dev));
return -ENODEV;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Error: MMIO Handle %s setup!\n",
dev_name(&pdev->dev));
return -ENODEV;
}
hcd = usb_create_hcd(driver, &pdev->dev, dev_name(&pdev->dev));
if (!hcd) {
retval = -ENOMEM;
goto err1;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len,
driver->description)) {
dev_dbg(&pdev->dev, "controller already in use\n");
retval = -EBUSY;
goto err2;
}
hcd->regs = ioremap_nocache(hcd->rsrc_start, hcd->rsrc_len);
if (hcd->regs == NULL) {
dev_dbg(&pdev->dev, "error mapping memory\n");
retval = -EFAULT;
goto err3;
}
retval = usb_add_hcd(hcd, irq, IRQF_SHARED);
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
dev_err(&pdev->dev, "init %s fail, %d\n", dev_name(&pdev->dev),
retval);
return retval;
}
static int ehci_xls_probe(struct platform_device *pdev)
{
if (usb_disabled())
return -ENODEV;
return ehci_xls_probe_internal(&ehci_xls_hc_driver, pdev);
}
static int ehci_xls_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
return 0;
}
