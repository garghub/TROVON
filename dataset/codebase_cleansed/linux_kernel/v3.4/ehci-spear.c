static void spear_start_ehci(struct spear_ehci *ehci)
{
clk_enable(ehci->clk);
}
static void spear_stop_ehci(struct spear_ehci *ehci)
{
clk_disable(ehci->clk);
}
static int ehci_spear_setup(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int retval = 0;
ehci->caps = hcd->regs;
ehci->regs = hcd->regs + HC_LENGTH(ehci, ehci_readl(ehci,
&ehci->caps->hc_capbase));
ehci->hcs_params = ehci_readl(ehci, &ehci->caps->hcs_params);
retval = ehci_halt(ehci);
if (retval)
return retval;
retval = ehci_init(hcd);
if (retval)
return retval;
ehci_reset(ehci);
ehci_port_power(ehci, 0);
return retval;
}
static int ehci_spear_drv_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
unsigned long flags;
int rc = 0;
if (time_before(jiffies, ehci->next_statechange))
msleep(10);
spin_lock_irqsave(&ehci->lock, flags);
ehci_prepare_ports_for_controller_suspend(ehci, device_may_wakeup(dev));
ehci_writel(ehci, 0, &ehci->regs->intr_enable);
ehci_readl(ehci, &ehci->regs->intr_enable);
spin_unlock_irqrestore(&ehci->lock, flags);
return rc;
}
static int ehci_spear_drv_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
if (time_before(jiffies, ehci->next_statechange))
msleep(100);
if (ehci_readl(ehci, &ehci->regs->configured_flag) == FLAG_CF) {
int mask = INTR_MASK;
ehci_prepare_ports_for_controller_resume(ehci);
if (!hcd->self.root_hub->do_remote_wakeup)
mask &= ~STS_PCD;
ehci_writel(ehci, mask, &ehci->regs->intr_enable);
ehci_readl(ehci, &ehci->regs->intr_enable);
return 0;
}
usb_root_hub_lost_power(hcd->self.root_hub);
ehci_halt(ehci);
ehci_reset(ehci);
spin_lock_irq(&ehci->lock);
if (ehci->reclaim)
end_unlink_async(ehci);
ehci_work(ehci);
spin_unlock_irq(&ehci->lock);
ehci_writel(ehci, ehci->command, &ehci->regs->command);
ehci_writel(ehci, FLAG_CF, &ehci->regs->configured_flag);
ehci_readl(ehci, &ehci->regs->command);
ehci_port_power(ehci, 1);
return 0;
}
static int spear_ehci_hcd_drv_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd ;
struct spear_ehci *ehci;
struct resource *res;
struct clk *usbh_clk;
const struct hc_driver *driver = &ehci_spear_hc_driver;
int *pdata = pdev->dev.platform_data;
int irq, retval;
char clk_name[20] = "usbh_clk";
if (pdata == NULL)
return -EFAULT;
if (usb_disabled())
return -ENODEV;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
retval = irq;
goto fail_irq_get;
}
if (*pdata >= 0)
sprintf(clk_name, "usbh.%01d_clk", *pdata);
usbh_clk = clk_get(NULL, clk_name);
if (IS_ERR(usbh_clk)) {
dev_err(&pdev->dev, "Error getting interface clock\n");
retval = PTR_ERR(usbh_clk);
goto fail_get_usbh_clk;
}
hcd = usb_create_hcd(driver, &pdev->dev, dev_name(&pdev->dev));
if (!hcd) {
retval = -ENOMEM;
goto fail_create_hcd;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
retval = -ENODEV;
goto fail_request_resource;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len,
driver->description)) {
retval = -EBUSY;
goto fail_request_resource;
}
hcd->regs = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (hcd->regs == NULL) {
dev_dbg(&pdev->dev, "error mapping memory\n");
retval = -ENOMEM;
goto fail_ioremap;
}
ehci = (struct spear_ehci *)hcd_to_ehci(hcd);
ehci->clk = usbh_clk;
spear_start_ehci(ehci);
retval = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (retval)
goto fail_add_hcd;
return retval;
fail_add_hcd:
spear_stop_ehci(ehci);
iounmap(hcd->regs);
fail_ioremap:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
fail_request_resource:
usb_put_hcd(hcd);
fail_create_hcd:
clk_put(usbh_clk);
fail_get_usbh_clk:
fail_irq_get:
dev_err(&pdev->dev, "init fail, %d\n", retval);
return retval ;
}
static int spear_ehci_hcd_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct spear_ehci *ehci_p = to_spear_ehci(hcd);
if (!hcd)
return 0;
if (in_interrupt())
BUG();
usb_remove_hcd(hcd);
if (ehci_p->clk)
spear_stop_ehci(ehci_p);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
if (ehci_p->clk)
clk_put(ehci_p->clk);
return 0;
}
