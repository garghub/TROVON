static int __devinit s5p_ehci_probe(struct platform_device *pdev)
{
struct s5p_ehci_platdata *pdata;
struct s5p_ehci_hcd *s5p_ehci;
struct usb_hcd *hcd;
struct ehci_hcd *ehci;
struct resource *res;
int irq;
int err;
pdata = pdev->dev.platform_data;
if (!pdata) {
dev_err(&pdev->dev, "No platform data defined\n");
return -EINVAL;
}
s5p_ehci = kzalloc(sizeof(struct s5p_ehci_hcd), GFP_KERNEL);
if (!s5p_ehci)
return -ENOMEM;
s5p_ehci->dev = &pdev->dev;
hcd = usb_create_hcd(&s5p_ehci_hc_driver, &pdev->dev,
dev_name(&pdev->dev));
if (!hcd) {
dev_err(&pdev->dev, "Unable to create HCD\n");
err = -ENOMEM;
goto fail_hcd;
}
s5p_ehci->hcd = hcd;
s5p_ehci->clk = clk_get(&pdev->dev, "usbhost");
if (IS_ERR(s5p_ehci->clk)) {
dev_err(&pdev->dev, "Failed to get usbhost clock\n");
err = PTR_ERR(s5p_ehci->clk);
goto fail_clk;
}
err = clk_enable(s5p_ehci->clk);
if (err)
goto fail_clken;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Failed to get I/O memory\n");
err = -ENXIO;
goto fail_io;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
hcd->regs = ioremap(res->start, resource_size(res));
if (!hcd->regs) {
dev_err(&pdev->dev, "Failed to remap I/O memory\n");
err = -ENOMEM;
goto fail_io;
}
irq = platform_get_irq(pdev, 0);
if (!irq) {
dev_err(&pdev->dev, "Failed to get IRQ\n");
err = -ENODEV;
goto fail;
}
if (pdata->phy_init)
pdata->phy_init(pdev, S5P_USB_PHY_HOST);
ehci = hcd_to_ehci(hcd);
ehci->caps = hcd->regs;
ehci->regs = hcd->regs +
HC_LENGTH(ehci, readl(&ehci->caps->hc_capbase));
dbg_hcs_params(ehci, "reset");
dbg_hcc_params(ehci, "reset");
ehci->hcs_params = readl(&ehci->caps->hcs_params);
ehci_reset(ehci);
err = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (err) {
dev_err(&pdev->dev, "Failed to add USB HCD\n");
goto fail;
}
platform_set_drvdata(pdev, s5p_ehci);
return 0;
fail:
iounmap(hcd->regs);
fail_io:
clk_disable(s5p_ehci->clk);
fail_clken:
clk_put(s5p_ehci->clk);
fail_clk:
usb_put_hcd(hcd);
fail_hcd:
kfree(s5p_ehci);
return err;
}
static int __devexit s5p_ehci_remove(struct platform_device *pdev)
{
struct s5p_ehci_platdata *pdata = pdev->dev.platform_data;
struct s5p_ehci_hcd *s5p_ehci = platform_get_drvdata(pdev);
struct usb_hcd *hcd = s5p_ehci->hcd;
usb_remove_hcd(hcd);
if (pdata && pdata->phy_exit)
pdata->phy_exit(pdev, S5P_USB_PHY_HOST);
iounmap(hcd->regs);
clk_disable(s5p_ehci->clk);
clk_put(s5p_ehci->clk);
usb_put_hcd(hcd);
kfree(s5p_ehci);
return 0;
}
static void s5p_ehci_shutdown(struct platform_device *pdev)
{
struct s5p_ehci_hcd *s5p_ehci = platform_get_drvdata(pdev);
struct usb_hcd *hcd = s5p_ehci->hcd;
if (hcd->driver->shutdown)
hcd->driver->shutdown(hcd);
}
static int s5p_ehci_suspend(struct device *dev)
{
struct s5p_ehci_hcd *s5p_ehci = dev_get_drvdata(dev);
struct usb_hcd *hcd = s5p_ehci->hcd;
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
struct platform_device *pdev = to_platform_device(dev);
struct s5p_ehci_platdata *pdata = pdev->dev.platform_data;
unsigned long flags;
int rc = 0;
if (time_before(jiffies, ehci->next_statechange))
msleep(20);
ehci_prepare_ports_for_controller_suspend(ehci, device_may_wakeup(dev));
spin_lock_irqsave(&ehci->lock, flags);
ehci_writel(ehci, 0, &ehci->regs->intr_enable);
(void)ehci_readl(ehci, &ehci->regs->intr_enable);
clear_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
spin_unlock_irqrestore(&ehci->lock, flags);
if (pdata && pdata->phy_exit)
pdata->phy_exit(pdev, S5P_USB_PHY_HOST);
return rc;
}
static int s5p_ehci_resume(struct device *dev)
{
struct s5p_ehci_hcd *s5p_ehci = dev_get_drvdata(dev);
struct usb_hcd *hcd = s5p_ehci->hcd;
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
struct platform_device *pdev = to_platform_device(dev);
struct s5p_ehci_platdata *pdata = pdev->dev.platform_data;
if (pdata && pdata->phy_init)
pdata->phy_init(pdev, S5P_USB_PHY_HOST);
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
ehci->rh_state = EHCI_RH_SUSPENDED;
return 0;
}
