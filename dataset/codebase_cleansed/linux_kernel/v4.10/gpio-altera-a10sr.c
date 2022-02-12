static int altr_a10sr_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
struct altr_a10sr_gpio *gpio = gpiochip_get_data(chip);
int ret, val;
ret = regmap_read(gpio->regmap, ALTR_A10SR_PBDSW_REG, &val);
if (ret < 0)
return ret;
return !!(val & BIT(offset - ALTR_A10SR_LED_VALID_SHIFT));
}
static void altr_a10sr_gpio_set(struct gpio_chip *chip, unsigned int offset,
int value)
{
struct altr_a10sr_gpio *gpio = gpiochip_get_data(chip);
regmap_update_bits(gpio->regmap, ALTR_A10SR_LED_REG,
BIT(ALTR_A10SR_LED_VALID_SHIFT + offset),
value ? BIT(ALTR_A10SR_LED_VALID_SHIFT + offset)
: 0);
}
static int altr_a10sr_gpio_direction_input(struct gpio_chip *gc,
unsigned int nr)
{
if (nr >= (ALTR_A10SR_IN_VALID_RANGE_LO - ALTR_A10SR_LED_VALID_SHIFT))
return 0;
return -EINVAL;
}
static int altr_a10sr_gpio_direction_output(struct gpio_chip *gc,
unsigned int nr, int value)
{
if (nr <= (ALTR_A10SR_OUT_VALID_RANGE_HI - ALTR_A10SR_LED_VALID_SHIFT))
return 0;
return -EINVAL;
}
static int altr_a10sr_gpio_probe(struct platform_device *pdev)
{
struct altr_a10sr_gpio *gpio;
int ret;
struct altr_a10sr *a10sr = dev_get_drvdata(pdev->dev.parent);
gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
if (!gpio)
return -ENOMEM;
gpio->regmap = a10sr->regmap;
gpio->gp = altr_a10sr_gc;
gpio->gp.of_node = pdev->dev.of_node;
ret = devm_gpiochip_add_data(&pdev->dev, &gpio->gp, gpio);
if (ret < 0) {
dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, gpio);
return 0;
}
