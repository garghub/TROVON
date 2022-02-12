static void hi655x_local_irq_clear(struct regmap *map)
{
int i;
regmap_write(map, HI655X_ANA_IRQM_BASE, HI655X_IRQ_CLR);
for (i = 0; i < HI655X_IRQ_ARRAY; i++) {
regmap_write(map, HI655X_IRQ_STAT_BASE + i * HI655X_STRIDE,
HI655X_IRQ_CLR);
}
}
static int hi655x_pmic_probe(struct platform_device *pdev)
{
int ret;
struct hi655x_pmic *pmic;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
void __iomem *base;
pmic = devm_kzalloc(dev, sizeof(*pmic), GFP_KERNEL);
if (!pmic)
return -ENOMEM;
pmic->dev = dev;
pmic->res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, pmic->res);
if (IS_ERR(base))
return PTR_ERR(base);
pmic->regmap = devm_regmap_init_mmio_clk(dev, NULL, base,
&hi655x_regmap_config);
regmap_read(pmic->regmap, HI655X_BUS_ADDR(HI655X_VER_REG), &pmic->ver);
if ((pmic->ver < PMU_VER_START) || (pmic->ver > PMU_VER_END)) {
dev_warn(dev, "PMU version %d unsupported\n", pmic->ver);
return -EINVAL;
}
hi655x_local_irq_clear(pmic->regmap);
pmic->gpio = of_get_named_gpio(np, "pmic-gpios", 0);
if (!gpio_is_valid(pmic->gpio)) {
dev_err(dev, "Failed to get the pmic-gpios\n");
return -ENODEV;
}
ret = devm_gpio_request_one(dev, pmic->gpio, GPIOF_IN,
"hi655x_pmic_irq");
if (ret < 0) {
dev_err(dev, "Failed to request gpio %d ret = %d\n",
pmic->gpio, ret);
return ret;
}
ret = regmap_add_irq_chip(pmic->regmap, gpio_to_irq(pmic->gpio),
IRQF_TRIGGER_LOW | IRQF_NO_SUSPEND, 0,
&hi655x_irq_chip, &pmic->irq_data);
if (ret) {
dev_err(dev, "Failed to obtain 'hi655x_pmic_irq' %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, pmic);
ret = mfd_add_devices(dev, PLATFORM_DEVID_AUTO, hi655x_pmic_devs,
ARRAY_SIZE(hi655x_pmic_devs), NULL, 0,
regmap_irq_get_domain(pmic->irq_data));
if (ret) {
dev_err(dev, "Failed to register device %d\n", ret);
regmap_del_irq_chip(gpio_to_irq(pmic->gpio), pmic->irq_data);
return ret;
}
return 0;
}
static int hi655x_pmic_remove(struct platform_device *pdev)
{
struct hi655x_pmic *pmic = platform_get_drvdata(pdev);
regmap_del_irq_chip(gpio_to_irq(pmic->gpio), pmic->irq_data);
mfd_remove_devices(&pdev->dev);
return 0;
}
