static void au1xxx_start_ehc(void)
{
au_writel(au_readl(USB_HOST_CONFIG) | USBH_ENABLE_CE, USB_HOST_CONFIG);
au_sync();
udelay(1000);
au_writel(au_readl(USB_HOST_CONFIG) | USBH_ENABLE_INIT, USB_HOST_CONFIG);
au_sync();
udelay(1000);
}
static void au1xxx_stop_ehc(void)
{
unsigned long c;
au_writel(au_readl(USB_HOST_CONFIG) & ~USBH_DISABLE, USB_HOST_CONFIG);
au_sync();
udelay(1000);
c = au_readl(USB_HOST_CONFIG) & ~USB_MCFG_EHCCLKEN;
if (!(c & USB_MCFG_UCECLKEN))
c &= ~USB_MCFG_PHYPLLEN;
au_writel(c, USB_HOST_CONFIG);
au_sync();
}
static int au1xxx_ehci_setup(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int ret = ehci_init(hcd);
ehci->need_io_watchdog = 0;
return ret;
}
static int ehci_hcd_au1xxx_drv_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
struct ehci_hcd *ehci;
struct resource *res;
int ret;
if (usb_disabled())
return -ENODEV;
#if defined(CONFIG_SOC_AU1200) && defined(CONFIG_DMA_COHERENT)
if (!(read_c0_prid() & 0xff)) {
printk(KERN_INFO "%s: this is chip revision AB!\n", pdev->name);
printk(KERN_INFO "%s: update your board or re-configure"
" the kernel\n", pdev->name);
return -ENODEV;
}
#endif
if (pdev->resource[1].flags != IORESOURCE_IRQ) {
pr_debug("resource[1] is not IORESOURCE_IRQ");
return -ENOMEM;
}
hcd = usb_create_hcd(&ehci_au1xxx_hc_driver, &pdev->dev, "Au1xxx");
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
au1xxx_start_ehc();
ehci = hcd_to_ehci(hcd);
ehci->caps = hcd->regs;
ehci->regs = hcd->regs +
HC_LENGTH(ehci, readl(&ehci->caps->hc_capbase));
ehci->hcs_params = readl(&ehci->caps->hcs_params);
ret = usb_add_hcd(hcd, pdev->resource[1].start,
IRQF_DISABLED | IRQF_SHARED);
if (ret == 0) {
platform_set_drvdata(pdev, hcd);
return ret;
}
au1xxx_stop_ehc();
iounmap(hcd->regs);
err2:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err1:
usb_put_hcd(hcd);
return ret;
}
static int ehci_hcd_au1xxx_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
au1xxx_stop_ehc();
platform_set_drvdata(pdev, NULL);
return 0;
}
static int ehci_hcd_au1xxx_drv_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
unsigned long flags;
int rc = 0;
if (time_before(jiffies, ehci->next_statechange))
msleep(10);
ehci_prepare_ports_for_controller_suspend(ehci, device_may_wakeup(dev));
spin_lock_irqsave(&ehci->lock, flags);
ehci_writel(ehci, 0, &ehci->regs->intr_enable);
(void)ehci_readl(ehci, &ehci->regs->intr_enable);
clear_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
spin_unlock_irqrestore(&ehci->lock, flags);
au1xxx_stop_ehc();
return rc;
}
static int ehci_hcd_au1xxx_drv_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
au1xxx_start_ehc();
if (time_before(jiffies, ehci->next_statechange))
msleep(100);
set_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
if (ehci_readl(ehci, &ehci->regs->configured_flag) == FLAG_CF) {
int mask = INTR_MASK;
ehci_prepare_ports_for_controller_resume(ehci);
if (!hcd->self.root_hub->do_remote_wakeup)
mask &= ~STS_PCD;
ehci_writel(ehci, mask, &ehci->regs->intr_enable);
ehci_readl(ehci, &ehci->regs->intr_enable);
return 0;
}
ehci_dbg(ehci, "lost power, restarting\n");
usb_root_hub_lost_power(hcd->self.root_hub);
(void) ehci_halt(ehci);
(void) ehci_reset(ehci);
spin_lock_irq(&ehci->lock);
if (ehci->reclaim)
end_unlink_async(ehci);
ehci_work(ehci);
spin_unlock_irq(&ehci->lock);
ehci_writel(ehci, ehci->command, &ehci->regs->command);
ehci_writel(ehci, FLAG_CF, &ehci->regs->configured_flag);
ehci_readl(ehci, &ehci->regs->command);
ehci_port_power(ehci, 1);
hcd->state = HC_STATE_SUSPENDED;
return 0;
}
