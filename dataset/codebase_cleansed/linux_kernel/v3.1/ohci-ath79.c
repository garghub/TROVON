static int __devinit ohci_ath79_start(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
int ret;
ret = ohci_init(ohci);
if (ret < 0)
return ret;
ret = ohci_run(ohci);
if (ret < 0)
goto err;
return 0;
err:
ohci_stop(hcd);
return ret;
}
static int ohci_ath79_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
struct resource *res;
int irq;
int ret;
if (usb_disabled())
return -ENODEV;
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_dbg(&pdev->dev, "no IRQ specified\n");
return -ENODEV;
}
irq = res->start;
hcd = usb_create_hcd(&ohci_ath79_hc_driver, &pdev->dev,
dev_name(&pdev->dev));
if (!hcd)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_dbg(&pdev->dev, "no base address specified\n");
ret = -ENODEV;
goto err_put_hcd;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name)) {
dev_dbg(&pdev->dev, "controller already in use\n");
ret = -EBUSY;
goto err_put_hcd;
}
hcd->regs = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (!hcd->regs) {
dev_dbg(&pdev->dev, "error mapping memory\n");
ret = -EFAULT;
goto err_release_region;
}
ohci_hcd_init(hcd_to_ohci(hcd));
ret = usb_add_hcd(hcd, irq, IRQF_DISABLED);
if (ret)
goto err_stop_hcd;
return 0;
err_stop_hcd:
iounmap(hcd->regs);
err_release_region:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err_put_hcd:
usb_put_hcd(hcd);
return ret;
}
static int ohci_ath79_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
return 0;
}
