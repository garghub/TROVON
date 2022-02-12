static void au1xxx_start_ohc(void)
{
#ifndef CONFIG_SOC_AU1200
au_writel(USBH_ENABLE_CE, USB_HOST_CONFIG);
au_sync();
udelay(1000);
au_writel(au_readl(USB_HOST_CONFIG) | USBH_ENABLE_INIT, USB_HOST_CONFIG);
au_sync();
udelay(1000);
while (au_readl(USB_HOST_CONFIG),
!(au_readl(USB_HOST_CONFIG) & USBH_ENABLE_RD))
udelay(1000);
#else
au_writel(au_readl(USB_HOST_CONFIG) | USBH_ENABLE_CE, USB_HOST_CONFIG);
au_sync();
udelay(1000);
au_writel(au_readl(USB_HOST_CONFIG) | USBH_ENABLE_INIT, USB_HOST_CONFIG);
au_sync();
udelay(2000);
#endif
}
static void au1xxx_stop_ohc(void)
{
#ifdef CONFIG_SOC_AU1200
au_writel(au_readl(USB_HOST_CONFIG) & ~USBH_DISABLE, USB_HOST_CONFIG);
au_sync();
udelay(1000);
#endif
au_writel(au_readl(USB_HOST_CONFIG) & ~USBH_ENABLE_CE, USB_HOST_CONFIG);
au_sync();
}
static int __devinit ohci_au1xxx_start(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
int ret;
ohci_dbg(ohci, "ohci_au1xxx_start, ohci:%p", ohci);
if ((ret = ohci_init(ohci)) < 0)
return ret;
if ((ret = ohci_run(ohci)) < 0) {
err ("can't start %s", hcd->self.bus_name);
ohci_stop(hcd);
return ret;
}
return 0;
}
static int ohci_hcd_au1xxx_drv_probe(struct platform_device *pdev)
{
int ret;
struct usb_hcd *hcd;
if (usb_disabled())
return -ENODEV;
#if defined(CONFIG_SOC_AU1200) && defined(CONFIG_DMA_COHERENT)
if (!(read_c0_prid() & 0xff)) {
printk(KERN_INFO "%s: this is chip revision AB !!\n",
pdev->name);
printk(KERN_INFO "%s: update your board or re-configure "
"the kernel\n", pdev->name);
return -ENODEV;
}
#endif
if (pdev->resource[1].flags != IORESOURCE_IRQ) {
pr_debug("resource[1] is not IORESOURCE_IRQ\n");
return -ENOMEM;
}
hcd = usb_create_hcd(&ohci_au1xxx_hc_driver, &pdev->dev, "au1xxx");
if (!hcd)
return -ENOMEM;
hcd->rsrc_start = pdev->resource[0].start;
hcd->rsrc_len = pdev->resource[0].end - pdev->resource[0].start + 1;
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name)) {
pr_debug("request_mem_region failed\n");
ret = -EBUSY;
goto err1;
}
hcd->regs = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (!hcd->regs) {
pr_debug("ioremap failed\n");
ret = -ENOMEM;
goto err2;
}
au1xxx_start_ohc();
ohci_hcd_init(hcd_to_ohci(hcd));
ret = usb_add_hcd(hcd, pdev->resource[1].start,
IRQF_DISABLED | IRQF_SHARED);
if (ret == 0) {
platform_set_drvdata(pdev, hcd);
return ret;
}
au1xxx_stop_ohc();
iounmap(hcd->regs);
err2:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err1:
usb_put_hcd(hcd);
return ret;
}
static int ohci_hcd_au1xxx_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
au1xxx_stop_ohc();
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int ohci_hcd_au1xxx_drv_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
unsigned long flags;
int rc;
rc = 0;
spin_lock_irqsave(&ohci->lock, flags);
if (hcd->state != HC_STATE_SUSPENDED) {
rc = -EINVAL;
goto bail;
}
ohci_writel(ohci, OHCI_INTR_MIE, &ohci->regs->intrdisable);
(void)ohci_readl(ohci, &ohci->regs->intrdisable);
clear_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
au1xxx_stop_ohc();
bail:
spin_unlock_irqrestore(&ohci->lock, flags);
return rc;
}
static int ohci_hcd_au1xxx_drv_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
au1xxx_start_ohc();
set_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
ohci_finish_controller_resume(hcd);
return 0;
}
