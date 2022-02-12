static int axp20x_gpio_get_reg(unsigned offset)
{
switch (offset) {
case 0:
return AXP20X_GPIO0_CTRL;
case 1:
return AXP20X_GPIO1_CTRL;
case 2:
return AXP20X_GPIO2_CTRL;
}
return -EINVAL;
}
static int axp20x_gpio_input(struct gpio_chip *chip, unsigned offset)
{
struct axp20x_gpio *gpio = gpiochip_get_data(chip);
int reg;
reg = axp20x_gpio_get_reg(offset);
if (reg < 0)
return reg;
return regmap_update_bits(gpio->regmap, reg,
AXP20X_GPIO_FUNCTIONS,
AXP20X_GPIO_FUNCTION_INPUT);
}
static int axp20x_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct axp20x_gpio *gpio = gpiochip_get_data(chip);
unsigned int val;
int reg, ret;
reg = axp20x_gpio_get_reg(offset);
if (reg < 0)
return reg;
ret = regmap_read(gpio->regmap, reg, &val);
if (ret)
return ret;
return !!(val & BIT(offset + 4));
}
static int axp20x_gpio_get_direction(struct gpio_chip *chip, unsigned offset)
{
struct axp20x_gpio *gpio = gpiochip_get_data(chip);
unsigned int val;
int reg, ret;
reg = axp20x_gpio_get_reg(offset);
if (reg < 0)
return reg;
ret = regmap_read(gpio->regmap, reg, &val);
if (ret)
return ret;
if ((val & AXP20X_GPIO_FUNCTIONS) > 2)
return 0;
return val & 2;
}
static int axp20x_gpio_output(struct gpio_chip *chip, unsigned offset,
int value)
{
struct axp20x_gpio *gpio = gpiochip_get_data(chip);
int reg;
reg = axp20x_gpio_get_reg(offset);
if (reg < 0)
return reg;
return regmap_update_bits(gpio->regmap, reg,
AXP20X_GPIO_FUNCTIONS,
value ? AXP20X_GPIO_FUNCTION_OUT_HIGH
: AXP20X_GPIO_FUNCTION_OUT_LOW);
}
static void axp20x_gpio_set(struct gpio_chip *chip, unsigned offset,
int value)
{
axp20x_gpio_output(chip, offset, value);
}
static int axp20x_gpio_probe(struct platform_device *pdev)
{
struct axp20x_dev *axp20x = dev_get_drvdata(pdev->dev.parent);
struct axp20x_gpio *gpio;
int ret;
if (!of_device_is_available(pdev->dev.of_node))
return -ENODEV;
if (!axp20x) {
dev_err(&pdev->dev, "Parent drvdata not set\n");
return -EINVAL;
}
gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
if (!gpio)
return -ENOMEM;
gpio->chip.base = -1;
gpio->chip.can_sleep = true;
gpio->chip.parent = &pdev->dev;
gpio->chip.label = dev_name(&pdev->dev);
gpio->chip.owner = THIS_MODULE;
gpio->chip.get = axp20x_gpio_get;
gpio->chip.get_direction = axp20x_gpio_get_direction;
gpio->chip.set = axp20x_gpio_set;
gpio->chip.direction_input = axp20x_gpio_input;
gpio->chip.direction_output = axp20x_gpio_output;
gpio->chip.ngpio = 3;
gpio->regmap = axp20x->regmap;
ret = devm_gpiochip_add_data(&pdev->dev, &gpio->chip, gpio);
if (ret) {
dev_err(&pdev->dev, "Failed to register GPIO chip\n");
return ret;
}
dev_info(&pdev->dev, "AXP209 GPIO driver loaded\n");
return 0;
}
