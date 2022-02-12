static int atmel_hlcdc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct atmel_hlcdc *hlcdc;
struct resource *res;
void __iomem *regs;
hlcdc = devm_kzalloc(dev, sizeof(*hlcdc), GFP_KERNEL);
if (!hlcdc)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(dev, res);
if (IS_ERR(regs))
return PTR_ERR(regs);
hlcdc->irq = platform_get_irq(pdev, 0);
if (hlcdc->irq < 0)
return hlcdc->irq;
hlcdc->periph_clk = devm_clk_get(dev, "periph_clk");
if (IS_ERR(hlcdc->periph_clk)) {
dev_err(dev, "failed to get peripheral clock\n");
return PTR_ERR(hlcdc->periph_clk);
}
hlcdc->sys_clk = devm_clk_get(dev, "sys_clk");
if (IS_ERR(hlcdc->sys_clk)) {
dev_err(dev, "failed to get system clock\n");
return PTR_ERR(hlcdc->sys_clk);
}
hlcdc->slow_clk = devm_clk_get(dev, "slow_clk");
if (IS_ERR(hlcdc->slow_clk)) {
dev_err(dev, "failed to get slow clock\n");
return PTR_ERR(hlcdc->slow_clk);
}
hlcdc->regmap = devm_regmap_init_mmio(dev, regs,
&atmel_hlcdc_regmap_config);
if (IS_ERR(hlcdc->regmap))
return PTR_ERR(hlcdc->regmap);
dev_set_drvdata(dev, hlcdc);
return mfd_add_devices(dev, -1, atmel_hlcdc_cells,
ARRAY_SIZE(atmel_hlcdc_cells),
NULL, 0, NULL);
}
static int atmel_hlcdc_remove(struct platform_device *pdev)
{
mfd_remove_devices(&pdev->dev);
return 0;
}
