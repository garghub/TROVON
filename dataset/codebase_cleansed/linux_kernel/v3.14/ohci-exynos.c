static void exynos_ohci_phy_enable(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct exynos_ohci_hcd *exynos_ohci = to_exynos_ohci(hcd);
if (exynos_ohci->phy)
usb_phy_init(exynos_ohci->phy);
}
static void exynos_ohci_phy_disable(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct exynos_ohci_hcd *exynos_ohci = to_exynos_ohci(hcd);
if (exynos_ohci->phy)
usb_phy_shutdown(exynos_ohci->phy);
}
static int exynos_ohci_probe(struct platform_device *pdev)
{
struct exynos_ohci_hcd *exynos_ohci;
struct usb_hcd *hcd;
struct resource *res;
struct usb_phy *phy;
int irq;
int err;
err = dma_coerce_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (err)
return err;
hcd = usb_create_hcd(&exynos_ohci_hc_driver,
&pdev->dev, dev_name(&pdev->dev));
if (!hcd) {
dev_err(&pdev->dev, "Unable to create HCD\n");
return -ENOMEM;
}
exynos_ohci = to_exynos_ohci(hcd);
if (of_device_is_compatible(pdev->dev.of_node,
"samsung,exynos5440-ohci"))
goto skip_phy;
phy = devm_usb_get_phy(&pdev->dev, USB_PHY_TYPE_USB2);
if (IS_ERR(phy)) {
usb_put_hcd(hcd);
dev_warn(&pdev->dev, "no platform data or transceiver defined\n");
return -EPROBE_DEFER;
} else {
exynos_ohci->phy = phy;
exynos_ohci->otg = phy->otg;
}
skip_phy:
exynos_ohci->clk = devm_clk_get(&pdev->dev, "usbhost");
if (IS_ERR(exynos_ohci->clk)) {
dev_err(&pdev->dev, "Failed to get usbhost clock\n");
err = PTR_ERR(exynos_ohci->clk);
goto fail_clk;
}
err = clk_prepare_enable(exynos_ohci->clk);
if (err)
goto fail_clk;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Failed to get I/O memory\n");
err = -ENXIO;
goto fail_io;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
hcd->regs = devm_ioremap(&pdev->dev, res->start, hcd->rsrc_len);
if (!hcd->regs) {
dev_err(&pdev->dev, "Failed to remap I/O memory\n");
err = -ENOMEM;
goto fail_io;
}
irq = platform_get_irq(pdev, 0);
if (!irq) {
dev_err(&pdev->dev, "Failed to get IRQ\n");
err = -ENODEV;
goto fail_io;
}
if (exynos_ohci->otg)
exynos_ohci->otg->set_host(exynos_ohci->otg, &hcd->self);
platform_set_drvdata(pdev, hcd);
exynos_ohci_phy_enable(pdev);
err = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (err) {
dev_err(&pdev->dev, "Failed to add USB HCD\n");
goto fail_add_hcd;
}
device_wakeup_enable(hcd->self.controller);
return 0;
fail_add_hcd:
exynos_ohci_phy_disable(pdev);
fail_io:
clk_disable_unprepare(exynos_ohci->clk);
fail_clk:
usb_put_hcd(hcd);
return err;
}
static int exynos_ohci_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct exynos_ohci_hcd *exynos_ohci = to_exynos_ohci(hcd);
usb_remove_hcd(hcd);
if (exynos_ohci->otg)
exynos_ohci->otg->set_host(exynos_ohci->otg, &hcd->self);
exynos_ohci_phy_disable(pdev);
clk_disable_unprepare(exynos_ohci->clk);
usb_put_hcd(hcd);
return 0;
}
static void exynos_ohci_shutdown(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
if (hcd->driver->shutdown)
hcd->driver->shutdown(hcd);
}
static int exynos_ohci_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct exynos_ohci_hcd *exynos_ohci = to_exynos_ohci(hcd);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
struct platform_device *pdev = to_platform_device(dev);
bool do_wakeup = device_may_wakeup(dev);
unsigned long flags;
int rc = ohci_suspend(hcd, do_wakeup);
if (rc)
return rc;
spin_lock_irqsave(&ohci->lock, flags);
if (exynos_ohci->otg)
exynos_ohci->otg->set_host(exynos_ohci->otg, &hcd->self);
exynos_ohci_phy_disable(pdev);
clk_disable_unprepare(exynos_ohci->clk);
spin_unlock_irqrestore(&ohci->lock, flags);
return 0;
}
static int exynos_ohci_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct exynos_ohci_hcd *exynos_ohci = to_exynos_ohci(hcd);
struct platform_device *pdev = to_platform_device(dev);
clk_prepare_enable(exynos_ohci->clk);
if (exynos_ohci->otg)
exynos_ohci->otg->set_host(exynos_ohci->otg, &hcd->self);
exynos_ohci_phy_enable(pdev);
ohci_resume(hcd, false);
return 0;
}
static int __init ohci_exynos_init(void)
{
if (usb_disabled())
return -ENODEV;
pr_info("%s: " DRIVER_DESC "\n", hcd_name);
ohci_init_driver(&exynos_ohci_hc_driver, &exynos_overrides);
return platform_driver_register(&exynos_ohci_driver);
}
static void __exit ohci_exynos_cleanup(void)
{
platform_driver_unregister(&exynos_ohci_driver);
}
