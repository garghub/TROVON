static int stm32_lptimer_detect_encoder(struct stm32_lptimer *ddata)
{
u32 val;
int ret;
ret = regmap_update_bits(ddata->regmap, STM32_LPTIM_CFGR,
STM32_LPTIM_ENC, STM32_LPTIM_ENC);
if (ret)
return ret;
ret = regmap_read(ddata->regmap, STM32_LPTIM_CFGR, &val);
if (ret)
return ret;
ret = regmap_update_bits(ddata->regmap, STM32_LPTIM_CFGR,
STM32_LPTIM_ENC, 0);
if (ret)
return ret;
ddata->has_encoder = !!(val & STM32_LPTIM_ENC);
return 0;
}
static int stm32_lptimer_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct stm32_lptimer *ddata;
struct resource *res;
void __iomem *mmio;
int ret;
ddata = devm_kzalloc(dev, sizeof(*ddata), GFP_KERNEL);
if (!ddata)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mmio = devm_ioremap_resource(dev, res);
if (IS_ERR(mmio))
return PTR_ERR(mmio);
ddata->regmap = devm_regmap_init_mmio_clk(dev, "mux", mmio,
&stm32_lptimer_regmap_cfg);
if (IS_ERR(ddata->regmap))
return PTR_ERR(ddata->regmap);
ddata->clk = devm_clk_get(dev, NULL);
if (IS_ERR(ddata->clk))
return PTR_ERR(ddata->clk);
ret = stm32_lptimer_detect_encoder(ddata);
if (ret)
return ret;
platform_set_drvdata(pdev, ddata);
return devm_of_platform_populate(&pdev->dev);
}
