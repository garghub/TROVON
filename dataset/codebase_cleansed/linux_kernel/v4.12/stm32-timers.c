static void stm32_timers_get_arr_size(struct stm32_timers *ddata)
{
regmap_write(ddata->regmap, TIM_ARR, ~0L);
regmap_read(ddata->regmap, TIM_ARR, &ddata->max_arr);
regmap_write(ddata->regmap, TIM_ARR, 0x0);
}
static int stm32_timers_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct stm32_timers *ddata;
struct resource *res;
void __iomem *mmio;
ddata = devm_kzalloc(dev, sizeof(*ddata), GFP_KERNEL);
if (!ddata)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mmio = devm_ioremap_resource(dev, res);
if (IS_ERR(mmio))
return PTR_ERR(mmio);
ddata->regmap = devm_regmap_init_mmio_clk(dev, "int", mmio,
&stm32_timers_regmap_cfg);
if (IS_ERR(ddata->regmap))
return PTR_ERR(ddata->regmap);
ddata->clk = devm_clk_get(dev, NULL);
if (IS_ERR(ddata->clk))
return PTR_ERR(ddata->clk);
stm32_timers_get_arr_size(ddata);
platform_set_drvdata(pdev, ddata);
return of_platform_populate(pdev->dev.of_node, NULL, NULL, &pdev->dev);
}
static int stm32_timers_remove(struct platform_device *pdev)
{
of_platform_depopulate(&pdev->dev);
return 0;
}
