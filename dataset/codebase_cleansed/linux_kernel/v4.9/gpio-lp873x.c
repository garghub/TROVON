static int lp873x_gpio_get_direction(struct gpio_chip *chip,
unsigned int offset)
{
return 0;
}
static int lp873x_gpio_direction_input(struct gpio_chip *chip,
unsigned int offset)
{
return -EINVAL;
}
static int lp873x_gpio_direction_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
struct lp873x_gpio *gpio = gpiochip_get_data(chip);
return regmap_update_bits(gpio->lp873->regmap, LP873X_REG_GPO_CTRL,
BIT(offset * BITS_PER_GPO),
value ? BIT(offset * BITS_PER_GPO) : 0);
}
static int lp873x_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
struct lp873x_gpio *gpio = gpiochip_get_data(chip);
int ret, val;
ret = regmap_read(gpio->lp873->regmap, LP873X_REG_GPO_CTRL, &val);
if (ret < 0)
return ret;
return val & BIT(offset * BITS_PER_GPO);
}
static void lp873x_gpio_set(struct gpio_chip *chip, unsigned int offset,
int value)
{
struct lp873x_gpio *gpio = gpiochip_get_data(chip);
regmap_update_bits(gpio->lp873->regmap, LP873X_REG_GPO_CTRL,
BIT(offset * BITS_PER_GPO),
value ? BIT(offset * BITS_PER_GPO) : 0);
}
static int lp873x_gpio_request(struct gpio_chip *gc, unsigned int offset)
{
struct lp873x_gpio *gpio = gpiochip_get_data(gc);
int ret;
switch (offset) {
case 0:
break;
case 1:
ret = regmap_update_bits(gpio->lp873->regmap, LP873X_REG_CONFIG,
LP873X_CONFIG_CLKIN_PIN_SEL, 0);
if (ret)
return ret;
break;
default:
return -EINVAL;
}
return 0;
}
static int lp873x_gpio_set_single_ended(struct gpio_chip *gc,
unsigned int offset,
enum single_ended_mode mode)
{
struct lp873x_gpio *gpio = gpiochip_get_data(gc);
switch (mode) {
case LINE_MODE_OPEN_DRAIN:
return regmap_update_bits(gpio->lp873->regmap,
LP873X_REG_GPO_CTRL,
BIT(offset * BITS_PER_GPO +
LP873X_GPO_CTRL_OD),
BIT(offset * BITS_PER_GPO +
LP873X_GPO_CTRL_OD));
case LINE_MODE_PUSH_PULL:
return regmap_update_bits(gpio->lp873->regmap,
LP873X_REG_GPO_CTRL,
BIT(offset * BITS_PER_GPO +
LP873X_GPO_CTRL_OD), 0);
default:
return -ENOTSUPP;
}
}
static int lp873x_gpio_probe(struct platform_device *pdev)
{
struct lp873x_gpio *gpio;
int ret;
gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
if (!gpio)
return -ENOMEM;
platform_set_drvdata(pdev, gpio);
gpio->lp873 = dev_get_drvdata(pdev->dev.parent);
gpio->chip = template_chip;
gpio->chip.parent = gpio->lp873->dev;
ret = devm_gpiochip_add_data(&pdev->dev, &gpio->chip, gpio);
if (ret < 0) {
dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
return ret;
}
return 0;
}
