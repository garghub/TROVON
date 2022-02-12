static int sunxi_de2_clk_probe(struct platform_device *pdev)
{
struct resource *res;
struct clk *bus_clk, *mod_clk;
struct reset_control *rstc;
void __iomem *reg;
const struct sunxi_ccu_desc *ccu_desc;
int ret;
ccu_desc = of_device_get_match_data(&pdev->dev);
if (!ccu_desc)
return -EINVAL;
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
mod_clk = devm_clk_get(&pdev->dev, "mod");
if (IS_ERR(mod_clk)) {
ret = PTR_ERR(mod_clk);
if (ret != -EPROBE_DEFER)
dev_err(&pdev->dev, "Couldn't get mod clk: %d\n", ret);
return ret;
}
rstc = devm_reset_control_get_exclusive(&pdev->dev, NULL);
if (IS_ERR(rstc)) {
ret = PTR_ERR(rstc);
if (ret != -EPROBE_DEFER)
dev_err(&pdev->dev,
"Couldn't get reset control: %d\n", ret);
return ret;
}
ret = clk_prepare_enable(bus_clk);
if (ret) {
dev_err(&pdev->dev, "Couldn't enable bus clk: %d\n", ret);
return ret;
}
ret = clk_prepare_enable(mod_clk);
if (ret) {
dev_err(&pdev->dev, "Couldn't enable mod clk: %d\n", ret);
goto err_disable_bus_clk;
}
ret = reset_control_deassert(rstc);
if (ret) {
dev_err(&pdev->dev,
"Couldn't deassert reset control: %d\n", ret);
goto err_disable_mod_clk;
}
ret = sunxi_ccu_probe(pdev->dev.of_node, reg, ccu_desc);
if (ret)
goto err_assert_reset;
return 0;
err_assert_reset:
reset_control_assert(rstc);
err_disable_mod_clk:
clk_disable_unprepare(mod_clk);
err_disable_bus_clk:
clk_disable_unprepare(bus_clk);
return ret;
}
