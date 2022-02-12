static int bd9571mwv_gpio_get_direction(struct gpio_chip *chip,
unsigned int offset)
{
struct bd9571mwv_gpio *gpio = gpiochip_get_data(chip);
int ret, val;
ret = regmap_read(gpio->bd->regmap, BD9571MWV_GPIO_DIR, &val);
if (ret < 0)
return ret;
return val & BIT(offset);
}
static int bd9571mwv_gpio_direction_input(struct gpio_chip *chip,
unsigned int offset)
{
struct bd9571mwv_gpio *gpio = gpiochip_get_data(chip);
regmap_update_bits(gpio->bd->regmap, BD9571MWV_GPIO_DIR,
BIT(offset), 0);
return 0;
}
static int bd9571mwv_gpio_direction_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
struct bd9571mwv_gpio *gpio = gpiochip_get_data(chip);
regmap_update_bits(gpio->bd->regmap, BD9571MWV_GPIO_OUT,
BIT(offset), value ? BIT(offset) : 0);
regmap_update_bits(gpio->bd->regmap, BD9571MWV_GPIO_DIR,
BIT(offset), BIT(offset));
return 0;
}
static int bd9571mwv_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
struct bd9571mwv_gpio *gpio = gpiochip_get_data(chip);
int ret, val;
ret = regmap_read(gpio->bd->regmap, BD9571MWV_GPIO_IN, &val);
if (ret < 0)
return ret;
return val & BIT(offset);
}
static void bd9571mwv_gpio_set(struct gpio_chip *chip, unsigned int offset,
int value)
{
struct bd9571mwv_gpio *gpio = gpiochip_get_data(chip);
regmap_update_bits(gpio->bd->regmap, BD9571MWV_GPIO_OUT,
BIT(offset), value ? BIT(offset) : 0);
}
static int bd9571mwv_gpio_probe(struct platform_device *pdev)
{
struct bd9571mwv_gpio *gpio;
int ret;
gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
if (!gpio)
return -ENOMEM;
platform_set_drvdata(pdev, gpio);
gpio->bd = dev_get_drvdata(pdev->dev.parent);
gpio->chip = template_chip;
gpio->chip.parent = gpio->bd->dev;
ret = devm_gpiochip_add_data(&pdev->dev, &gpio->chip, gpio);
if (ret < 0) {
dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
return ret;
}
return 0;
}
