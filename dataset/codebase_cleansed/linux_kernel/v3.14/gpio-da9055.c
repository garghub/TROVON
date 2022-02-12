static inline struct da9055_gpio *to_da9055_gpio(struct gpio_chip *chip)
{
return container_of(chip, struct da9055_gpio, gp);
}
static int da9055_gpio_get(struct gpio_chip *gc, unsigned offset)
{
struct da9055_gpio *gpio = to_da9055_gpio(gc);
int gpio_direction = 0;
int ret;
ret = da9055_reg_read(gpio->da9055, (offset >> 1) + DA9055_REG_GPIO0_1);
if (ret < 0)
return ret;
gpio_direction = ret & (DA9055_PORT_MASK) << DA9055_PORT_SHIFT(offset);
gpio_direction >>= DA9055_PORT_SHIFT(offset);
switch (gpio_direction) {
case DA9055_INPUT:
ret = da9055_reg_read(gpio->da9055, DA9055_REG_STATUS_B);
if (ret < 0)
return ret;
break;
case DA9055_OUTPUT:
ret = da9055_reg_read(gpio->da9055, DA9055_REG_GPIO_MODE0_2);
if (ret < 0)
return ret;
}
return ret & (1 << offset);
}
static void da9055_gpio_set(struct gpio_chip *gc, unsigned offset, int value)
{
struct da9055_gpio *gpio = to_da9055_gpio(gc);
da9055_reg_update(gpio->da9055,
DA9055_REG_GPIO_MODE0_2,
1 << offset,
value << offset);
}
static int da9055_gpio_direction_input(struct gpio_chip *gc, unsigned offset)
{
struct da9055_gpio *gpio = to_da9055_gpio(gc);
unsigned char reg_byte;
reg_byte = (DA9055_ACT_LOW | DA9055_GPI)
<< DA9055_PORT_SHIFT(offset);
return da9055_reg_update(gpio->da9055, (offset >> 1) +
DA9055_REG_GPIO0_1,
DA9055_PORT_MASK <<
DA9055_PORT_SHIFT(offset),
reg_byte);
}
static int da9055_gpio_direction_output(struct gpio_chip *gc,
unsigned offset, int value)
{
struct da9055_gpio *gpio = to_da9055_gpio(gc);
unsigned char reg_byte;
int ret;
reg_byte = (DA9055_VDD_IO | DA9055_PUSH_PULL)
<< DA9055_PORT_SHIFT(offset);
ret = da9055_reg_update(gpio->da9055, (offset >> 1) +
DA9055_REG_GPIO0_1,
DA9055_PORT_MASK <<
DA9055_PORT_SHIFT(offset),
reg_byte);
if (ret < 0)
return ret;
da9055_gpio_set(gc, offset, value);
return 0;
}
static int da9055_gpio_to_irq(struct gpio_chip *gc, u32 offset)
{
struct da9055_gpio *gpio = to_da9055_gpio(gc);
struct da9055 *da9055 = gpio->da9055;
return regmap_irq_get_virq(da9055->irq_data,
DA9055_IRQ_GPI0 + offset);
}
static int da9055_gpio_probe(struct platform_device *pdev)
{
struct da9055_gpio *gpio;
struct da9055_pdata *pdata;
int ret;
gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
if (gpio == NULL)
return -ENOMEM;
gpio->da9055 = dev_get_drvdata(pdev->dev.parent);
pdata = dev_get_platdata(gpio->da9055->dev);
gpio->gp = reference_gp;
if (pdata && pdata->gpio_base)
gpio->gp.base = pdata->gpio_base;
ret = gpiochip_add(&gpio->gp);
if (ret < 0) {
dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
goto err_mem;
}
platform_set_drvdata(pdev, gpio);
return 0;
err_mem:
return ret;
}
static int da9055_gpio_remove(struct platform_device *pdev)
{
struct da9055_gpio *gpio = platform_get_drvdata(pdev);
return gpiochip_remove(&gpio->gp);
}
static int __init da9055_gpio_init(void)
{
return platform_driver_register(&da9055_gpio_driver);
}
static void __exit da9055_gpio_exit(void)
{
platform_driver_unregister(&da9055_gpio_driver);
}
