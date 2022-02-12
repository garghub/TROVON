static int regmap_atmel_hlcdc_reg_write(void *context, unsigned int reg,
unsigned int val)
{
struct atmel_hlcdc_regmap *hregmap = context;
if (reg <= ATMEL_HLCDC_DIS) {
u32 status;
readl_poll_timeout_atomic(hregmap->regs + ATMEL_HLCDC_SR,
status, !(status & ATMEL_HLCDC_SIP),
1, 100);
}
writel(val, hregmap->regs + reg);
return 0;
}
static int regmap_atmel_hlcdc_reg_read(void *context, unsigned int reg,
unsigned int *val)
{
struct atmel_hlcdc_regmap *hregmap = context;
*val = readl(hregmap->regs + reg);
return 0;
}
static int atmel_hlcdc_probe(struct platform_device *pdev)
{
struct atmel_hlcdc_regmap *hregmap;
struct device *dev = &pdev->dev;
struct atmel_hlcdc *hlcdc;
struct resource *res;
hregmap = devm_kzalloc(dev, sizeof(*hregmap), GFP_KERNEL);
if (!hregmap)
return -ENOMEM;
hlcdc = devm_kzalloc(dev, sizeof(*hlcdc), GFP_KERNEL);
if (!hlcdc)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hregmap->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(hregmap->regs))
return PTR_ERR(hregmap->regs);
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
hlcdc->regmap = devm_regmap_init(dev, NULL, hregmap,
&atmel_hlcdc_regmap_config);
if (IS_ERR(hlcdc->regmap))
return PTR_ERR(hlcdc->regmap);
dev_set_drvdata(dev, hlcdc);
return devm_mfd_add_devices(dev, -1, atmel_hlcdc_cells,
ARRAY_SIZE(atmel_hlcdc_cells),
NULL, 0, NULL);
}
