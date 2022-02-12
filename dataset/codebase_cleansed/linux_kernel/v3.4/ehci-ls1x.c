static int ehci_ls1x_reset(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int ret;
ehci->caps = hcd->regs;
ret = ehci_setup(hcd);
if (ret)
return ret;
ehci_port_power(ehci, 0);
return 0;
}
static int ehci_hcd_ls1x_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
struct resource *res;
int irq;
int ret;
pr_debug("initializing loongson1 ehci USB Controller\n");
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
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev,
"Found HC with no register addr. Check %s setup!\n",
dev_name(&pdev->dev));
return -ENODEV;
}
hcd = usb_create_hcd(&ehci_ls1x_hc_driver, &pdev->dev,
dev_name(&pdev->dev));
if (!hcd)
return -ENOMEM;
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name)) {
dev_dbg(&pdev->dev, "controller already in use\n");
ret = -EBUSY;
goto err_put_hcd;
}
hcd->regs = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (hcd->regs == NULL) {
dev_dbg(&pdev->dev, "error mapping memory\n");
ret = -EFAULT;
goto err_release_region;
}
ret = usb_add_hcd(hcd, irq, IRQF_DISABLED | IRQF_SHARED);
if (ret)
goto err_iounmap;
return ret;
err_iounmap:
iounmap(hcd->regs);
err_release_region:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err_put_hcd:
usb_put_hcd(hcd);
return ret;
}
static int ehci_hcd_ls1x_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
return 0;
}
