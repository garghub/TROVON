static int dwc3_exynos_register_phys(struct dwc3_exynos *exynos)
{
struct usb_phy_generic_platform_data pdata;
struct platform_device *pdev;
int ret;
memset(&pdata, 0x00, sizeof(pdata));
pdev = platform_device_alloc("usb_phy_generic", PLATFORM_DEVID_AUTO);
if (!pdev)
return -ENOMEM;
exynos->usb2_phy = pdev;
pdata.type = USB_PHY_TYPE_USB2;
pdata.gpio_reset = -1;
ret = platform_device_add_data(exynos->usb2_phy, &pdata, sizeof(pdata));
if (ret)
goto err1;
pdev = platform_device_alloc("usb_phy_generic", PLATFORM_DEVID_AUTO);
if (!pdev) {
ret = -ENOMEM;
goto err1;
}
exynos->usb3_phy = pdev;
pdata.type = USB_PHY_TYPE_USB3;
ret = platform_device_add_data(exynos->usb3_phy, &pdata, sizeof(pdata));
if (ret)
goto err2;
ret = platform_device_add(exynos->usb2_phy);
if (ret)
goto err2;
ret = platform_device_add(exynos->usb3_phy);
if (ret)
goto err3;
return 0;
err3:
platform_device_del(exynos->usb2_phy);
err2:
platform_device_put(exynos->usb3_phy);
err1:
platform_device_put(exynos->usb2_phy);
return ret;
}
static int dwc3_exynos_remove_child(struct device *dev, void *unused)
{
struct platform_device *pdev = to_platform_device(dev);
platform_device_unregister(pdev);
return 0;
}
static int dwc3_exynos_probe(struct platform_device *pdev)
{
struct dwc3_exynos *exynos;
struct clk *clk;
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
int ret;
exynos = devm_kzalloc(dev, sizeof(*exynos), GFP_KERNEL);
if (!exynos) {
dev_err(dev, "not enough memory\n");
return -ENOMEM;
}
ret = dma_coerce_mask_and_coherent(dev, DMA_BIT_MASK(32));
if (ret)
return ret;
platform_set_drvdata(pdev, exynos);
ret = dwc3_exynos_register_phys(exynos);
if (ret) {
dev_err(dev, "couldn't register PHYs\n");
return ret;
}
clk = devm_clk_get(dev, "usbdrd30");
if (IS_ERR(clk)) {
dev_err(dev, "couldn't get clock\n");
return -EINVAL;
}
exynos->dev = dev;
exynos->clk = clk;
clk_prepare_enable(exynos->clk);
exynos->vdd33 = devm_regulator_get(dev, "vdd33");
if (IS_ERR(exynos->vdd33)) {
ret = PTR_ERR(exynos->vdd33);
goto err2;
}
ret = regulator_enable(exynos->vdd33);
if (ret) {
dev_err(dev, "Failed to enable VDD33 supply\n");
goto err2;
}
exynos->vdd10 = devm_regulator_get(dev, "vdd10");
if (IS_ERR(exynos->vdd10)) {
ret = PTR_ERR(exynos->vdd10);
goto err3;
}
ret = regulator_enable(exynos->vdd10);
if (ret) {
dev_err(dev, "Failed to enable VDD10 supply\n");
goto err3;
}
if (node) {
ret = of_platform_populate(node, NULL, NULL, dev);
if (ret) {
dev_err(dev, "failed to add dwc3 core\n");
goto err4;
}
} else {
dev_err(dev, "no device node, failed to add dwc3 core\n");
ret = -ENODEV;
goto err4;
}
return 0;
err4:
regulator_disable(exynos->vdd10);
err3:
regulator_disable(exynos->vdd33);
err2:
clk_disable_unprepare(clk);
return ret;
}
static int dwc3_exynos_remove(struct platform_device *pdev)
{
struct dwc3_exynos *exynos = platform_get_drvdata(pdev);
device_for_each_child(&pdev->dev, NULL, dwc3_exynos_remove_child);
platform_device_unregister(exynos->usb2_phy);
platform_device_unregister(exynos->usb3_phy);
clk_disable_unprepare(exynos->clk);
regulator_disable(exynos->vdd33);
regulator_disable(exynos->vdd10);
return 0;
}
static int dwc3_exynos_suspend(struct device *dev)
{
struct dwc3_exynos *exynos = dev_get_drvdata(dev);
clk_disable(exynos->clk);
regulator_disable(exynos->vdd33);
regulator_disable(exynos->vdd10);
return 0;
}
static int dwc3_exynos_resume(struct device *dev)
{
struct dwc3_exynos *exynos = dev_get_drvdata(dev);
int ret;
ret = regulator_enable(exynos->vdd33);
if (ret) {
dev_err(dev, "Failed to enable VDD33 supply\n");
return ret;
}
ret = regulator_enable(exynos->vdd10);
if (ret) {
dev_err(dev, "Failed to enable VDD10 supply\n");
return ret;
}
clk_enable(exynos->clk);
pm_runtime_disable(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
return 0;
}
