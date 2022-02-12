static inline struct da9052_gpio *to_da9052_gpio(struct gpio_chip *chip)
{
return container_of(chip, struct da9052_gpio, gp);
}
static unsigned char da9052_gpio_port_odd(unsigned offset)
{
return offset % 2;
}
static int da9052_gpio_get(struct gpio_chip *gc, unsigned offset)
{
struct da9052_gpio *gpio = to_da9052_gpio(gc);
int da9052_port_direction = 0;
int ret;
ret = da9052_reg_read(gpio->da9052,
DA9052_GPIO_0_1_REG + (offset >> 1));
if (ret < 0)
return ret;
if (da9052_gpio_port_odd(offset)) {
da9052_port_direction = ret & DA9052_GPIO_ODD_PORT_PIN;
da9052_port_direction >>= 4;
} else {
da9052_port_direction = ret & DA9052_GPIO_EVEN_PORT_PIN;
}
switch (da9052_port_direction) {
case DA9052_INPUT:
if (offset < DA9052_GPIO_MAX_PORTS_PER_REGISTER)
ret = da9052_reg_read(gpio->da9052,
DA9052_STATUS_C_REG);
else
ret = da9052_reg_read(gpio->da9052,
DA9052_STATUS_D_REG);
if (ret < 0)
return ret;
if (ret & (1 << DA9052_GPIO_SHIFT_COUNT(offset)))
return 1;
else
return 0;
case DA9052_OUTPUT_PUSHPULL:
if (da9052_gpio_port_odd(offset))
return ret & DA9052_GPIO_ODD_PORT_MODE;
else
return ret & DA9052_GPIO_EVEN_PORT_MODE;
default:
return -EINVAL;
}
}
static void da9052_gpio_set(struct gpio_chip *gc, unsigned offset, int value)
{
struct da9052_gpio *gpio = to_da9052_gpio(gc);
int ret;
if (da9052_gpio_port_odd(offset)) {
ret = da9052_reg_update(gpio->da9052, (offset >> 1) +
DA9052_GPIO_0_1_REG,
DA9052_GPIO_ODD_PORT_MODE,
value << DA9052_GPIO_ODD_SHIFT);
if (ret != 0)
dev_err(gpio->da9052->dev,
"Failed to updated gpio odd reg,%d",
ret);
} else {
ret = da9052_reg_update(gpio->da9052, (offset >> 1) +
DA9052_GPIO_0_1_REG,
DA9052_GPIO_EVEN_PORT_MODE,
value << DA9052_GPIO_EVEN_SHIFT);
if (ret != 0)
dev_err(gpio->da9052->dev,
"Failed to updated gpio even reg,%d",
ret);
}
}
static int da9052_gpio_direction_input(struct gpio_chip *gc, unsigned offset)
{
struct da9052_gpio *gpio = to_da9052_gpio(gc);
unsigned char register_value;
int ret;
register_value = DA9052_INPUT | DA9052_ACTIVE_LOW << 2 |
DA9052_DEBOUNCING_ON << 3;
if (da9052_gpio_port_odd(offset))
ret = da9052_reg_update(gpio->da9052, (offset >> 1) +
DA9052_GPIO_0_1_REG,
DA9052_GPIO_MASK_UPPER_NIBBLE,
(register_value <<
DA9052_GPIO_NIBBLE_SHIFT));
else
ret = da9052_reg_update(gpio->da9052, (offset >> 1) +
DA9052_GPIO_0_1_REG,
DA9052_GPIO_MASK_LOWER_NIBBLE,
register_value);
return ret;
}
static int da9052_gpio_direction_output(struct gpio_chip *gc,
unsigned offset, int value)
{
struct da9052_gpio *gpio = to_da9052_gpio(gc);
unsigned char register_value;
int ret;
register_value = DA9052_OUTPUT_PUSHPULL | DA9052_SUPPLY_VDD_IO1 << 2 |
value << 3;
if (da9052_gpio_port_odd(offset))
ret = da9052_reg_update(gpio->da9052, (offset >> 1) +
DA9052_GPIO_0_1_REG,
DA9052_GPIO_MASK_UPPER_NIBBLE,
(register_value <<
DA9052_GPIO_NIBBLE_SHIFT));
else
ret = da9052_reg_update(gpio->da9052, (offset >> 1) +
DA9052_GPIO_0_1_REG,
DA9052_GPIO_MASK_LOWER_NIBBLE,
register_value);
return ret;
}
static int da9052_gpio_to_irq(struct gpio_chip *gc, u32 offset)
{
struct da9052_gpio *gpio = to_da9052_gpio(gc);
struct da9052 *da9052 = gpio->da9052;
int irq;
irq = regmap_irq_get_virq(da9052->irq_data, DA9052_IRQ_GPI0 + offset);
return irq;
}
static int da9052_gpio_probe(struct platform_device *pdev)
{
struct da9052_gpio *gpio;
struct da9052_pdata *pdata;
int ret;
gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
if (!gpio)
return -ENOMEM;
gpio->da9052 = dev_get_drvdata(pdev->dev.parent);
pdata = dev_get_platdata(gpio->da9052->dev);
gpio->gp = reference_gp;
if (pdata && pdata->gpio_base)
gpio->gp.base = pdata->gpio_base;
ret = gpiochip_add(&gpio->gp);
if (ret < 0) {
dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, gpio);
return 0;
}
static int da9052_gpio_remove(struct platform_device *pdev)
{
struct da9052_gpio *gpio = platform_get_drvdata(pdev);
gpiochip_remove(&gpio->gp);
return 0;
}
