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
return 0;
}
static int ehci_msm_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
struct resource *res;
struct usb_phy *phy;
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
hcd->regs = devm_ioremap(&pdev->dev, hcd->rsrc_start, hcd->rsrc_len);
if (!hcd->regs) {
dev_err(&pdev->dev, "ioremap failed\n");
ret = -ENOMEM;
goto put_hcd;
}
if (pdev->dev.of_node)
phy = devm_usb_get_phy_by_phandle(&pdev->dev, "usb-phy", 0);
else
phy = devm_usb_get_phy(&pdev->dev, USB_PHY_TYPE_USB2);
if (IS_ERR(phy)) {
dev_err(&pdev->dev, "unable to find transceiver\n");
ret = -EPROBE_DEFER;
goto put_hcd;
}
ret = otg_set_host(phy->otg, &hcd->self);
if (ret < 0) {
dev_err(&pdev->dev, "unable to register with transceiver\n");
goto put_hcd;
}
hcd->phy = phy;
device_init_wakeup(&pdev->dev, 1);
pm_runtime_no_callbacks(&pdev->dev);
pm_runtime_enable(&pdev->dev);
return 0;
put_hcd:
usb_put_hcd(hcd);
return ret;
}
static int ehci_msm_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
device_init_wakeup(&pdev->dev, 0);
pm_runtime_disable(&pdev->dev);
pm_runtime_set_suspended(&pdev->dev);
otg_set_host(hcd->phy->otg, NULL);
usb_put_hcd(hcd);
return 0;
}
static int ehci_msm_pm_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
bool do_wakeup = device_may_wakeup(dev);
dev_dbg(dev, "ehci-msm PM suspend\n");
return ehci_suspend(hcd, do_wakeup);
}
static int ehci_msm_pm_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
dev_dbg(dev, "ehci-msm PM resume\n");
ehci_resume(hcd, false);
return 0;
}
static int __init ehci_msm_init(void)
{
if (usb_disabled())
return -ENODEV;
pr_info("%s: " DRIVER_DESC "\n", hcd_name);
ehci_init_driver(&msm_hc_driver, &msm_overrides);
return platform_driver_register(&ehci_msm_driver);
}
static void __exit ehci_msm_cleanup(void)
{
platform_driver_unregister(&ehci_msm_driver);
}
