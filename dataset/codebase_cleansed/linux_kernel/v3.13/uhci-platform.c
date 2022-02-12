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
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name)) {
pr_err("%s: request_mem_region failed\n", __func__);
ret = -EBUSY;
goto err_rmr;
}
hcd->regs = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (!hcd->regs) {
pr_err("%s: ioremap failed\n", __func__);
ret = -ENOMEM;
goto err_irq;
}
uhci = hcd_to_uhci(hcd);
uhci->regs = hcd->regs;
ret = usb_add_hcd(hcd, pdev->resource[1].start, IRQF_SHARED);
if (ret)
goto err_uhci;
return 0;
err_uhci:
iounmap(hcd->regs);
err_irq:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err_rmr:
usb_put_hcd(hcd);
return ret;
}
static int uhci_hcd_platform_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
return 0;
}
static void uhci_hcd_platform_shutdown(struct platform_device *op)
{
struct usb_hcd *hcd = platform_get_drvdata(op);
uhci_hc_died(hcd_to_uhci(hcd));
}
