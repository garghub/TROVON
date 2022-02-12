static int uhci_platform_init(struct usb_hcd *hcd)
{
struct uhci_hcd *uhci = hcd_to_uhci(hcd);
uhci->rh_numports = uhci_count_ports(hcd);
uhci->reset_hc = uhci_generic_reset_hc;
uhci->check_and_reset_hc = uhci_generic_check_and_reset_hc;
uhci->configure_hc = NULL;
uhci->resume_detect_interrupts_are_broken = NULL;
uhci->global_suspend_mode_is_broken = NULL;
check_and_reset_hc(uhci);
return 0;
}
static int uhci_hcd_platform_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
struct uhci_hcd *uhci;
struct resource *res;
int ret;
if (usb_disabled())
return -ENODEV;
ret = dma_coerce_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (ret)
return ret;
hcd = usb_create_hcd(&uhci_platform_hc_driver, &pdev->dev,
pdev->name);
if (!hcd)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hcd->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hcd->regs)) {
ret = PTR_ERR(hcd->regs);
goto err_rmr;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
uhci = hcd_to_uhci(hcd);
uhci->regs = hcd->regs;
ret = usb_add_hcd(hcd, pdev->resource[1].start, IRQF_SHARED);
if (ret)
goto err_rmr;
device_wakeup_enable(hcd->self.controller);
return 0;
err_rmr:
usb_put_hcd(hcd);
return ret;
}
static int uhci_hcd_platform_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
usb_put_hcd(hcd);
return 0;
}
static void uhci_hcd_platform_shutdown(struct platform_device *op)
{
struct usb_hcd *hcd = platform_get_drvdata(op);
uhci_hc_died(hcd_to_uhci(hcd));
}
