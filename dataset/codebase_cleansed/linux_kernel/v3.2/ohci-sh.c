static int ohci_sh_start(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
ohci_hcd_init(ohci);
ohci_init(ohci);
ohci_run(ohci);
hcd->state = HC_STATE_RUNNING;
return 0;
}
static int ohci_hcd_sh_probe(struct platform_device *pdev)
{
struct resource *res = NULL;
struct usb_hcd *hcd = NULL;
int irq = -1;
int ret;
if (usb_disabled())
return -ENODEV;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
err("platform_get_resource error.");
return -ENODEV;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
err("platform_get_irq error.");
return -ENODEV;
}
hcd = usb_create_hcd(&ohci_sh_hc_driver, &pdev->dev, (char *)hcd_name);
if (!hcd) {
err("Failed to create hcd");
return -ENOMEM;
}
hcd->regs = (void __iomem *)res->start;
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
ret = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (ret != 0) {
err("Failed to add hcd");
usb_put_hcd(hcd);
return ret;
}
return ret;
}
static int ohci_hcd_sh_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
usb_put_hcd(hcd);
return 0;
}
