static int exynos_ohci_get_phy(struct device *dev,
struct exynos_ohci_hcd *exynos_ohci)
{
struct device_node *child;
struct phy *phy;
int phy_number;
int ret;
for_each_available_child_of_node(dev->of_node, child) {
ret = of_property_read_u32(child, "reg", &phy_number);
if (ret) {
dev_err(dev, "Failed to parse device tree\n");
of_node_put(child);
return ret;
}
if (phy_number >= PHY_NUMBER) {
dev_err(dev, "Invalid number of PHYs\n");
of_node_put(child);
return -EINVAL;
}
phy = devm_of_phy_get(dev, child, NULL);
exynos_ohci->phy[phy_number] = phy;
if (IS_ERR(phy)) {
ret = PTR_ERR(phy);
if (ret == -EPROBE_DEFER) {
of_node_put(child);
return ret;
} else if (ret != -ENOSYS && ret != -ENODEV) {
dev_err(dev,
"Error retrieving usb2 phy: %d\n", ret);
of_node_put(child);
return ret;
}
}
}
return 0;
}
static int exynos_ohci_phy_enable(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct exynos_ohci_hcd *exynos_ohci = to_exynos_ohci(hcd);
int i;
int ret = 0;
for (i = 0; ret == 0 && i < PHY_NUMBER; i++)
if (!IS_ERR(exynos_ohci->phy[i]))
ret = phy_power_on(exynos_ohci->phy[i]);
if (ret)
for (i--; i >= 0; i--)
if (!IS_ERR(exynos_ohci->phy[i]))
phy_power_off(exynos_ohci->phy[i]);
return ret;
}
static void exynos_ohci_phy_disable(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct exynos_ohci_hcd *exynos_ohci = to_exynos_ohci(hcd);
int i;
for (i = 0; i < PHY_NUMBER; i++)
if (!IS_ERR(exynos_ohci->phy[i]))
phy_power_off(exynos_ohci->phy[i]);
}
static int exynos_ohci_probe(struct platform_device *pdev)
{
struct exynos_ohci_hcd *exynos_ohci;
struct usb_hcd *hcd;
struct resource *res;
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
err = exynos_ohci_get_phy(&pdev->dev, exynos_ohci);
if (err)
goto fail_clk;
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
hcd->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hcd->regs)) {
err = PTR_ERR(hcd->regs);
goto fail_io;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
irq = platform_get_irq(pdev, 0);
if (!irq) {
dev_err(&pdev->dev, "Failed to get IRQ\n");
err = -ENODEV;
goto fail_io;
}
platform_set_drvdata(pdev, hcd);
err = exynos_ohci_phy_enable(&pdev->dev);
if (err) {
dev_err(&pdev->dev, "Failed to enable USB phy\n");
goto fail_io;
}
err = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (err) {
dev_err(&pdev->dev, "Failed to add USB HCD\n");
goto fail_add_hcd;
}
device_wakeup_enable(hcd->self.controller);
return 0;
fail_add_hcd:
exynos_ohci_phy_disable(&pdev->dev);
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
exynos_ohci_phy_disable(&pdev->dev);
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
bool do_wakeup = device_may_wakeup(dev);
int rc = ohci_suspend(hcd, do_wakeup);
if (rc)
return rc;
exynos_ohci_phy_disable(dev);
clk_disable_unprepare(exynos_ohci->clk);
return 0;
}
static int exynos_ohci_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct exynos_ohci_hcd *exynos_ohci = to_exynos_ohci(hcd);
int ret;
clk_prepare_enable(exynos_ohci->clk);
ret = exynos_ohci_phy_enable(dev);
if (ret) {
dev_err(dev, "Failed to enable USB phy\n");
clk_disable_unprepare(exynos_ohci->clk);
return ret;
}
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
