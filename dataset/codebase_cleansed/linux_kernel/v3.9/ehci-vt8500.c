static int vt8500_ehci_drv_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
struct ehci_hcd *ehci;
struct resource *res;
int ret;
if (usb_disabled())
return -ENODEV;
if (!pdev->dev.dma_mask)
pdev->dev.dma_mask = &vt8500_ehci_dma_mask;
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
hcd->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hcd->regs)) {
ret = PTR_ERR(hcd->regs);
goto err1;
}
ehci = hcd_to_ehci(hcd);
ehci->caps = hcd->regs;
ret = usb_add_hcd(hcd, pdev->resource[1].start,
IRQF_SHARED);
if (ret == 0) {
platform_set_drvdata(pdev, hcd);
return ret;
}
err1:
usb_put_hcd(hcd);
return ret;
}
static int vt8500_ehci_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
usb_put_hcd(hcd);
platform_set_drvdata(pdev, NULL);
return 0;
}
