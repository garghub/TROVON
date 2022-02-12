static int dwc3_exynos_register_phys(struct dwc3_exynos *exynos)
{
struct usb_phy_gen_xceiv_platform_data pdata;
struct platform_device *pdev;
int ret;
memset(&pdata, 0x00, sizeof(pdata));
pdev = platform_device_alloc("usb_phy_gen_xceiv", PLATFORM_DEVID_AUTO);
if (!pdev)
return -ENOMEM;
exynos->usb2_phy = pdev;
pdata.type = USB_PHY_TYPE_USB2;
pdata.gpio_reset = -1;
ret = platform_device_add_data(exynos->usb2_phy, &pdata, sizeof(pdata));
if (ret)
goto err1;
pdev = platform_device_alloc("usb_phy_gen_xceiv", PLATFORM_DEVID_AUTO);
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
int ret = -ENOMEM;
exynos = devm_kzalloc(dev, sizeof(*exynos), GFP_KERNEL);
if (!exynos) {
dev_err(dev, "not enough memory\n");
goto err1;
}
ret = dma_coerce_mask_and_coherent(dev, DMA_BIT_MASK(32));
if (ret)
goto err1;
platform_set_drvdata(pdev, exynos);
ret = dwc3_exynos_register_phys(exynos);
if (ret) {
dev_err(dev, "couldn't register PHYs\n");
goto err1;
}
clk = devm_clk_get(dev, "usbdrd30");
if (IS_ERR(clk)) {
dev_err(dev, "couldn't get clock\n");
ret = -EINVAL;
goto err1;
}
exynos->dev = dev;
exynos->clk = clk;
clk_prepare_enable(exynos->clk);
if (node) {
ret = of_platform_populate(node, NULL, NULL, dev);
if (ret) {
dev_err(dev, "failed to add dwc3 core\n");
goto err2;
}
} else {
dev_err(dev, "no device node, failed to add dwc3 core\n");
ret = -ENODEV;
goto err2;
}
return 0;
err2:
clk_disable_unprepare(clk);
err1:
return ret;
}
static int dwc3_exynos_remove(struct platform_device *pdev)
{
struct dwc3_exynos *exynos = platform_get_drvdata(pdev);
device_for_each_child(&pdev->dev, NULL, dwc3_exynos_remove_child);
platform_device_unregister(exynos->usb2_phy);
platform_device_unregister(exynos->usb3_phy);
clk_disable_unprepare(exynos->clk);
return 0;
}
static int dwc3_exynos_suspend(struct device *dev)
{
struct dwc3_exynos *exynos = dev_get_drvdata(dev);
clk_disable(exynos->clk);
return 0;
}
static int dwc3_exynos_resume(struct device *dev)
{
struct dwc3_exynos *exynos = dev_get_drvdata(dev);
clk_enable(exynos->clk);
pm_runtime_disable(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
return 0;
}
