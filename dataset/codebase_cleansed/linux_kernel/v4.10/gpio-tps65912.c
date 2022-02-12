static int tps65912_gpio_get_direction(struct gpio_chip *gc,
unsigned offset)
{
struct tps65912_gpio *gpio = gpiochip_get_data(gc);
int ret, val;
ret = regmap_read(gpio->tps->regmap, TPS65912_GPIO1 + offset, &val);
if (ret)
return ret;
if (val & GPIO_CFG_MASK)
return GPIOF_DIR_OUT;
else
return GPIOF_DIR_IN;
}
static int tps65912_gpio_direction_input(struct gpio_chip *gc, unsigned offset)
{
struct tps65912_gpio *gpio = gpiochip_get_data(gc);
return regmap_update_bits(gpio->tps->regmap, TPS65912_GPIO1 + offset,
GPIO_CFG_MASK, 0);
}
static int tps65912_gpio_direction_output(struct gpio_chip *gc,
unsigned offset, int value)
{
struct tps65912_gpio *gpio = gpiochip_get_data(gc);
regmap_update_bits(gpio->tps->regmap, TPS65912_GPIO1 + offset,
GPIO_SET_MASK, value ? GPIO_SET_MASK : 0);
return regmap_update_bits(gpio->tps->regmap, TPS65912_GPIO1 + offset,
GPIO_CFG_MASK, GPIO_CFG_MASK);
}
static int tps65912_gpio_get(struct gpio_chip *gc, unsigned offset)
{
struct tps65912_gpio *gpio = gpiochip_get_data(gc);
int ret, val;
ret = regmap_read(gpio->tps->regmap, TPS65912_GPIO1 + offset, &val);
if (ret)
return ret;
if (val & GPIO_STS_MASK)
return 1;
return 0;
}
static void tps65912_gpio_set(struct gpio_chip *gc, unsigned offset,
int value)
{
struct tps65912_gpio *gpio = gpiochip_get_data(gc);
regmap_update_bits(gpio->tps->regmap, TPS65912_GPIO1 + offset,
GPIO_SET_MASK, value ? GPIO_SET_MASK : 0);
}
static int tps65912_gpio_probe(struct platform_device *pdev)
{
struct tps65912 *tps = dev_get_drvdata(pdev->dev.parent);
struct tps65912_gpio *gpio;
int ret;
gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
if (!gpio)
return -ENOMEM;
gpio->tps = dev_get_drvdata(pdev->dev.parent);
gpio->gpio_chip = template_chip;
gpio->gpio_chip.parent = tps->dev;
ret = devm_gpiochip_add_data(&pdev->dev, &gpio->gpio_chip,
gpio);
if (ret < 0) {
dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, gpio);
return 0;
}
