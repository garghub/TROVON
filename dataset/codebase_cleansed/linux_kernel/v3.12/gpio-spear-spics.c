static int spics_get_value(struct gpio_chip *chip, unsigned offset)
{
return -ENXIO;
}
static void spics_set_value(struct gpio_chip *chip, unsigned offset, int value)
{
struct spear_spics *spics = container_of(chip, struct spear_spics,
chip);
u32 tmp;
tmp = readl_relaxed(spics->base + spics->perip_cfg);
if (spics->last_off != offset) {
spics->last_off = offset;
tmp &= ~(spics->cs_enable_mask << spics->cs_enable_shift);
tmp |= offset << spics->cs_enable_shift;
}
tmp &= ~(0x1 << spics->cs_value_bit);
tmp |= value << spics->cs_value_bit;
writel_relaxed(tmp, spics->base + spics->perip_cfg);
}
static int spics_direction_input(struct gpio_chip *chip, unsigned offset)
{
return -ENXIO;
}
static int spics_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
spics_set_value(chip, offset, value);
return 0;
}
static int spics_request(struct gpio_chip *chip, unsigned offset)
{
struct spear_spics *spics = container_of(chip, struct spear_spics,
chip);
u32 tmp;
if (!spics->use_count++) {
tmp = readl_relaxed(spics->base + spics->perip_cfg);
tmp |= 0x1 << spics->sw_enable_bit;
tmp |= 0x1 << spics->cs_value_bit;
writel_relaxed(tmp, spics->base + spics->perip_cfg);
}
return 0;
}
static void spics_free(struct gpio_chip *chip, unsigned offset)
{
struct spear_spics *spics = container_of(chip, struct spear_spics,
chip);
u32 tmp;
if (!--spics->use_count) {
tmp = readl_relaxed(spics->base + spics->perip_cfg);
tmp &= ~(0x1 << spics->sw_enable_bit);
writel_relaxed(tmp, spics->base + spics->perip_cfg);
}
}
static int spics_gpio_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct spear_spics *spics;
struct resource *res;
int ret;
spics = devm_kzalloc(&pdev->dev, sizeof(*spics), GFP_KERNEL);
if (!spics) {
dev_err(&pdev->dev, "memory allocation fail\n");
return -ENOMEM;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
spics->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(spics->base))
return PTR_ERR(spics->base);
if (of_property_read_u32(np, "st-spics,peripcfg-reg",
&spics->perip_cfg))
goto err_dt_data;
if (of_property_read_u32(np, "st-spics,sw-enable-bit",
&spics->sw_enable_bit))
goto err_dt_data;
if (of_property_read_u32(np, "st-spics,cs-value-bit",
&spics->cs_value_bit))
goto err_dt_data;
if (of_property_read_u32(np, "st-spics,cs-enable-mask",
&spics->cs_enable_mask))
goto err_dt_data;
if (of_property_read_u32(np, "st-spics,cs-enable-shift",
&spics->cs_enable_shift))
goto err_dt_data;
platform_set_drvdata(pdev, spics);
spics->chip.ngpio = NUM_OF_GPIO;
spics->chip.base = -1;
spics->chip.request = spics_request;
spics->chip.free = spics_free;
spics->chip.direction_input = spics_direction_input;
spics->chip.direction_output = spics_direction_output;
spics->chip.get = spics_get_value;
spics->chip.set = spics_set_value;
spics->chip.label = dev_name(&pdev->dev);
spics->chip.dev = &pdev->dev;
spics->chip.owner = THIS_MODULE;
spics->last_off = -1;
ret = gpiochip_add(&spics->chip);
if (ret) {
dev_err(&pdev->dev, "unable to add gpio chip\n");
return ret;
}
dev_info(&pdev->dev, "spear spics registered\n");
return 0;
err_dt_data:
dev_err(&pdev->dev, "DT probe failed\n");
return -EINVAL;
}
static int __init spics_gpio_init(void)
{
return platform_driver_register(&spics_gpio_driver);
}
