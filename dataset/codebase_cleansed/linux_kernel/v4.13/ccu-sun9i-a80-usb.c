static int sun9i_a80_usb_clk_probe(struct platform_device *pdev)
{
struct resource *res;
struct clk *bus_clk;
void __iomem *reg;
int ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(reg))
return PTR_ERR(reg);
bus_clk = devm_clk_get(&pdev->dev, "bus");
if (IS_ERR(bus_clk)) {
ret = PTR_ERR(bus_clk);
if (ret != -EPROBE_DEFER)
dev_err(&pdev->dev, "Couldn't get bus clk: %d\n", ret);
return ret;
}
ret = clk_prepare_enable(bus_clk);
if (ret) {
dev_err(&pdev->dev, "Couldn't enable bus clk: %d\n", ret);
return ret;
}
ret = sunxi_ccu_probe(pdev->dev.of_node, reg,
&sun9i_a80_usb_clk_desc);
if (ret)
goto err_disable_clk;
return 0;
err_disable_clk:
clk_disable_unprepare(bus_clk);
return ret;
}
