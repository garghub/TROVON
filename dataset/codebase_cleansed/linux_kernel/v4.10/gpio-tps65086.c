static int tps65086_gpio_get_direction(struct gpio_chip *chip,
unsigned offset)
{
return 0;
}
static int tps65086_gpio_direction_input(struct gpio_chip *chip,
unsigned offset)
{
return -EINVAL;
}
static int tps65086_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
struct tps65086_gpio *gpio = gpiochip_get_data(chip);
regmap_update_bits(gpio->tps->regmap, TPS65086_GPOCTRL,
BIT(4 + offset), value ? BIT(4 + offset) : 0);
return 0;
}
static int tps65086_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct tps65086_gpio *gpio = gpiochip_get_data(chip);
int ret, val;
ret = regmap_read(gpio->tps->regmap, TPS65086_GPOCTRL, &val);
if (ret < 0)
return ret;
return val & BIT(4 + offset);
}
static void tps65086_gpio_set(struct gpio_chip *chip, unsigned offset,
int value)
{
struct tps65086_gpio *gpio = gpiochip_get_data(chip);
regmap_update_bits(gpio->tps->regmap, TPS65086_GPOCTRL,
BIT(4 + offset), value ? BIT(4 + offset) : 0);
}
static int tps65086_gpio_probe(struct platform_device *pdev)
{
struct tps65086_gpio *gpio;
int ret;
gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
if (!gpio)
return -ENOMEM;
platform_set_drvdata(pdev, gpio);
gpio->tps = dev_get_drvdata(pdev->dev.parent);
gpio->chip = template_chip;
gpio->chip.parent = gpio->tps->dev;
ret = gpiochip_add_data(&gpio->chip, gpio);
if (ret < 0) {
dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
return ret;
}
return 0;
}
static int tps65086_gpio_remove(struct platform_device *pdev)
{
struct tps65086_gpio *gpio = platform_get_drvdata(pdev);
gpiochip_remove(&gpio->chip);
return 0;
}
