static int exynos_ehci_get_phy(struct device *dev,
struct exynos_ehci_hcd *exynos_ehci)
{
struct device_node *child;
struct phy *phy;
int phy_number;
int ret = 0;
exynos_ehci->phy = devm_usb_get_phy(dev, USB_PHY_TYPE_USB2);
if (IS_ERR(exynos_ehci->phy)) {
ret = PTR_ERR(exynos_ehci->phy);
if (ret != -ENXIO && ret != -ENODEV) {
dev_err(dev, "no usb2 phy configured\n");
return ret;
}
dev_dbg(dev, "Failed to get usb2 phy\n");
} else {
exynos_ehci->otg = exynos_ehci->phy->otg;
}
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
phy = devm_of_phy_get(dev, child, 0);
of_node_put(child);
if (IS_ERR(phy)) {
ret = PTR_ERR(phy);
if (ret != -ENOSYS && ret != -ENODEV) {
dev_err(dev, "no usb2 phy configured\n");
return ret;
}
dev_dbg(dev, "Failed to get usb2 phy\n");
}
exynos_ehci->phy_g[phy_number] = phy;
}
return ret;
}
static int exynos_ehci_phy_enable(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct exynos_ehci_hcd *exynos_ehci = to_exynos_ehci(hcd);
int i;
int ret = 0;
if (!IS_ERR(exynos_ehci->phy))
return usb_phy_init(exynos_ehci->phy);
for (i = 0; ret == 0 && i < PHY_NUMBER; i++)
if (!IS_ERR(exynos_ehci->phy_g[i]))
ret = phy_power_on(exynos_ehci->phy_g[i]);
if (ret)
for (i--; i >= 0; i--)
if (!IS_ERR(exynos_ehci->phy_g[i]))
phy_power_off(exynos_ehci->phy_g[i]);
return ret;
}
static void exynos_ehci_phy_disable(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct exynos_ehci_hcd *exynos_ehci = to_exynos_ehci(hcd);
int i;
if (!IS_ERR(exynos_ehci->phy)) {
usb_phy_shutdown(exynos_ehci->phy);
return;
}
for (i = 0; i < PHY_NUMBER; i++)
if (!IS_ERR(exynos_ehci->phy_g[i]))
phy_power_off(exynos_ehci->phy_g[i]);
}
static void exynos_setup_vbus_gpio(struct device *dev)
{
int err;
int gpio;
if (!dev->of_node)
return;
gpio = of_get_named_gpio(dev->of_node, "samsung,vbus-gpio", 0);
if (!gpio_is_valid(gpio))
return;
err = devm_gpio_request_one(dev, gpio, GPIOF_OUT_INIT_HIGH,
"ehci_vbus_gpio");
if (err)
dev_err(dev, "can't request ehci vbus gpio %d", gpio);
}
static int exynos_ehci_probe(struct platform_device *pdev)
{
struct exynos_ehci_hcd *exynos_ehci;
struct usb_hcd *hcd;
struct ehci_hcd *ehci;
struct resource *res;
int irq;
int err;
err = dma_coerce_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (err)
return err;
exynos_setup_vbus_gpio(&pdev->dev);
hcd = usb_create_hcd(&exynos_ehci_hc_driver,
&pdev->dev, dev_name(&pdev->dev));
if (!hcd) {
dev_err(&pdev->dev, "Unable to create HCD\n");
return -ENOMEM;
}
exynos_ehci = to_exynos_ehci(hcd);
if (of_device_is_compatible(pdev->dev.of_node,
"samsung,exynos5440-ehci"))
goto skip_phy;
err = exynos_ehci_get_phy(&pdev->dev, exynos_ehci);
if (err)
goto fail_clk;
skip_phy:
exynos_ehci->clk = devm_clk_get(&pdev->dev, "usbhost");
if (IS_ERR(exynos_ehci->clk)) {
dev_err(&pdev->dev, "Failed to get usbhost clock\n");
err = PTR_ERR(exynos_ehci->clk);
goto fail_clk;
}
err = clk_prepare_enable(exynos_ehci->clk);
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
hcd->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hcd->regs)) {
err = PTR_ERR(hcd->regs);
goto fail_io;
}
irq = platform_get_irq(pdev, 0);
if (!irq) {
dev_err(&pdev->dev, "Failed to get IRQ\n");
err = -ENODEV;
goto fail_io;
}
if (exynos_ehci->otg)
exynos_ehci->otg->set_host(exynos_ehci->otg, &hcd->self);
err = exynos_ehci_phy_enable(&pdev->dev);
if (err) {
dev_err(&pdev->dev, "Failed to enable USB phy\n");
goto fail_io;
}
ehci = hcd_to_ehci(hcd);
ehci->caps = hcd->regs;
writel(EHCI_INSNREG00_ENABLE_DMA_BURST, EHCI_INSNREG00(hcd->regs));
err = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (err) {
dev_err(&pdev->dev, "Failed to add USB HCD\n");
goto fail_add_hcd;
}
device_wakeup_enable(hcd->self.controller);
platform_set_drvdata(pdev, hcd);
return 0;
fail_add_hcd:
exynos_ehci_phy_disable(&pdev->dev);
fail_io:
clk_disable_unprepare(exynos_ehci->clk);
fail_clk:
usb_put_hcd(hcd);
return err;
}
static int exynos_ehci_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct exynos_ehci_hcd *exynos_ehci = to_exynos_ehci(hcd);
usb_remove_hcd(hcd);
if (exynos_ehci->otg)
exynos_ehci->otg->set_host(exynos_ehci->otg, &hcd->self);
exynos_ehci_phy_disable(&pdev->dev);
clk_disable_unprepare(exynos_ehci->clk);
usb_put_hcd(hcd);
return 0;
}
static int exynos_ehci_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct exynos_ehci_hcd *exynos_ehci = to_exynos_ehci(hcd);
bool do_wakeup = device_may_wakeup(dev);
int rc;
rc = ehci_suspend(hcd, do_wakeup);
if (rc)
return rc;
if (exynos_ehci->otg)
exynos_ehci->otg->set_host(exynos_ehci->otg, &hcd->self);
exynos_ehci_phy_disable(dev);
clk_disable_unprepare(exynos_ehci->clk);
return rc;
}
static int exynos_ehci_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct exynos_ehci_hcd *exynos_ehci = to_exynos_ehci(hcd);
int ret;
clk_prepare_enable(exynos_ehci->clk);
if (exynos_ehci->otg)
exynos_ehci->otg->set_host(exynos_ehci->otg, &hcd->self);
ret = exynos_ehci_phy_enable(dev);
if (ret) {
dev_err(dev, "Failed to enable USB phy\n");
clk_disable_unprepare(exynos_ehci->clk);
return ret;
}
writel(EHCI_INSNREG00_ENABLE_DMA_BURST, EHCI_INSNREG00(hcd->regs));
ehci_resume(hcd, false);
return 0;
}
static int __init ehci_exynos_init(void)
{
if (usb_disabled())
return -ENODEV;
pr_info("%s: " DRIVER_DESC "\n", hcd_name);
ehci_init_driver(&exynos_ehci_hc_driver, &exynos_overrides);
return platform_driver_register(&exynos_ehci_driver);
}
static void __exit ehci_exynos_cleanup(void)
{
platform_driver_unregister(&exynos_ehci_driver);
}
