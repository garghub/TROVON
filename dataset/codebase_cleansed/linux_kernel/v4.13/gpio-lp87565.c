static int lp87565_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
struct lp87565_gpio *gpio = gpiochip_get_data(chip);
int ret, val;
ret = regmap_read(gpio->map, LP87565_REG_GPIO_IN, &val);
if (ret < 0)
return ret;
return !!(val & BIT(offset));
}
static void lp87565_gpio_set(struct gpio_chip *chip, unsigned int offset,
int value)
{
struct lp87565_gpio *gpio = gpiochip_get_data(chip);
regmap_update_bits(gpio->map, LP87565_REG_GPIO_OUT,
BIT(offset), value ? BIT(offset) : 0);
}
static int lp87565_gpio_get_direction(struct gpio_chip *chip,
unsigned int offset)
{
struct lp87565_gpio *gpio = gpiochip_get_data(chip);
int ret, val;
ret = regmap_read(gpio->map, LP87565_REG_GPIO_CONFIG, &val);
if (ret < 0)
return ret;
return !(val & BIT(offset));
}
static int lp87565_gpio_direction_input(struct gpio_chip *chip,
unsigned int offset)
{
struct lp87565_gpio *gpio = gpiochip_get_data(chip);
return regmap_update_bits(gpio->map,
LP87565_REG_GPIO_CONFIG,
BIT(offset), 0);
}
static int lp87565_gpio_direction_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
struct lp87565_gpio *gpio = gpiochip_get_data(chip);
lp87565_gpio_set(chip, offset, value);
return regmap_update_bits(gpio->map,
LP87565_REG_GPIO_CONFIG,
BIT(offset), BIT(offset));
}
static int lp87565_gpio_request(struct gpio_chip *gc, unsigned int offset)
{
struct lp87565_gpio *gpio = gpiochip_get_data(gc);
int ret;
switch (offset) {
case 0:
case 1:
case 2:
ret = regmap_update_bits(gpio->map,
LP87565_REG_PIN_FUNCTION,
BIT(offset), BIT(offset));
if (ret)
return ret;
break;
default:
return -EINVAL;
}
return 0;
}
static int lp87565_gpio_set_config(struct gpio_chip *gc, unsigned int offset,
unsigned long config)
{
struct lp87565_gpio *gpio = gpiochip_get_data(gc);
switch (pinconf_to_config_param(config)) {
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
return regmap_update_bits(gpio->map,
LP87565_REG_GPIO_CONFIG,
BIT(offset +
__ffs(LP87565_GOIO1_OD)),
BIT(offset +
__ffs(LP87565_GOIO1_OD)));
case PIN_CONFIG_DRIVE_PUSH_PULL:
return regmap_update_bits(gpio->map,
LP87565_REG_GPIO_CONFIG,
BIT(offset +
__ffs(LP87565_GOIO1_OD)), 0);
default:
return -ENOTSUPP;
}
}
static int lp87565_gpio_probe(struct platform_device *pdev)
{
struct lp87565_gpio *gpio;
struct lp87565 *lp87565;
int ret;
gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
if (!gpio)
return -ENOMEM;
lp87565 = dev_get_drvdata(pdev->dev.parent);
gpio->chip = template_chip;
gpio->chip.parent = lp87565->dev;
gpio->map = lp87565->regmap;
ret = devm_gpiochip_add_data(&pdev->dev, &gpio->chip, gpio);
if (ret < 0) {
dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
return ret;
}
return 0;
}
