static int ehci_msm_reset(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int retval;
ehci->caps = USB_CAPLENGTH;
hcd->has_tt = 1;
retval = ehci_setup(hcd);
if (retval)
return retval;
writel(0, USB_AHBBURST);
writel(0, USB_AHBMODE);
writel(0x13, USB_USBMODE);
ehci_port_power(ehci, 1);
return 0;
}
static int ehci_msm_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
struct resource *res;
int ret;
dev_dbg(&pdev->dev, "ehci_msm proble\n");
hcd = usb_create_hcd(&msm_hc_driver, &pdev->dev, dev_name(&pdev->dev));
if (!hcd) {
dev_err(&pdev->dev, "Unable to create HCD\n");
return -ENOMEM;
}
hcd->irq = platform_get_irq(pdev, 0);
if (hcd->irq < 0) {
dev_err(&pdev->dev, "Unable to get IRQ resource\n");
ret = hcd->irq;
goto put_hcd;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Unable to get memory resource\n");
ret = -ENODEV;
goto put_hcd;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
hcd->regs = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (!hcd->regs) {
dev_err(&pdev->dev, "ioremap failed\n");
ret = -ENOMEM;
goto put_hcd;
}
otg = otg_get_transceiver();
if (!otg) {
dev_err(&pdev->dev, "unable to find transceiver\n");
ret = -ENODEV;
goto unmap;
}
ret = otg_set_host(otg, &hcd->self);
if (ret < 0) {
dev_err(&pdev->dev, "unable to register with transceiver\n");
goto put_transceiver;
}
device_init_wakeup(&pdev->dev, 1);
pm_runtime_no_callbacks(&pdev->dev);
pm_runtime_enable(&pdev->dev);
return 0;
put_transceiver:
otg_put_transceiver(otg);
unmap:
iounmap(hcd->regs);
put_hcd:
usb_put_hcd(hcd);
return ret;
}
static int __devexit ehci_msm_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
device_init_wakeup(&pdev->dev, 0);
pm_runtime_disable(&pdev->dev);
pm_runtime_set_suspended(&pdev->dev);
otg_set_host(otg, NULL);
otg_put_transceiver(otg);
usb_put_hcd(hcd);
return 0;
}
static int ehci_msm_pm_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
bool wakeup = device_may_wakeup(dev);
dev_dbg(dev, "ehci-msm PM suspend\n");
if (hcd->self.root_hub->do_remote_wakeup && !wakeup) {
pm_runtime_resume(dev);
ehci_prepare_ports_for_controller_suspend(hcd_to_ehci(hcd),
wakeup);
}
return 0;
}
static int ehci_msm_pm_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
dev_dbg(dev, "ehci-msm PM resume\n");
ehci_prepare_ports_for_controller_resume(hcd_to_ehci(hcd));
return 0;
}
