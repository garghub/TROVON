static inline struct tps6586x_gpio *to_tps6586x_gpio(struct gpio_chip *chip)
{
return container_of(chip, struct tps6586x_gpio, gpio_chip);
}
static int tps6586x_gpio_get(struct gpio_chip *gc, unsigned offset)
{
struct tps6586x_gpio *tps6586x_gpio = to_tps6586x_gpio(gc);
uint8_t val;
int ret;
ret = tps6586x_read(tps6586x_gpio->parent, TPS6586X_GPIOSET2, &val);
if (ret)
return ret;
return !!(val & (1 << offset));
}
static void tps6586x_gpio_set(struct gpio_chip *gc, unsigned offset,
int value)
{
struct tps6586x_gpio *tps6586x_gpio = to_tps6586x_gpio(gc);
tps6586x_update(tps6586x_gpio->parent, TPS6586X_GPIOSET2,
value << offset, 1 << offset);
}
static int tps6586x_gpio_output(struct gpio_chip *gc, unsigned offset,
int value)
{
struct tps6586x_gpio *tps6586x_gpio = to_tps6586x_gpio(gc);
uint8_t val, mask;
tps6586x_gpio_set(gc, offset, value);
val = 0x1 << (offset * 2);
mask = 0x3 << (offset * 2);
return tps6586x_update(tps6586x_gpio->parent, TPS6586X_GPIOSET1,
val, mask);
}
static int __devinit tps6586x_gpio_probe(struct platform_device *pdev)
{
struct tps6586x_platform_data *pdata;
struct tps6586x_gpio *tps6586x_gpio;
int ret;
pdata = dev_get_platdata(pdev->dev.parent);
tps6586x_gpio = devm_kzalloc(&pdev->dev,
sizeof(*tps6586x_gpio), GFP_KERNEL);
if (!tps6586x_gpio) {
dev_err(&pdev->dev, "Could not allocate tps6586x_gpio\n");
return -ENOMEM;
}
tps6586x_gpio->parent = pdev->dev.parent;
tps6586x_gpio->gpio_chip.owner = THIS_MODULE;
tps6586x_gpio->gpio_chip.label = pdev->name;
tps6586x_gpio->gpio_chip.dev = &pdev->dev;
tps6586x_gpio->gpio_chip.ngpio = 4;
tps6586x_gpio->gpio_chip.can_sleep = 1;
tps6586x_gpio->gpio_chip.direction_output = tps6586x_gpio_output;
tps6586x_gpio->gpio_chip.set = tps6586x_gpio_set;
tps6586x_gpio->gpio_chip.get = tps6586x_gpio_get;
#ifdef CONFIG_OF_GPIO
tps6586x_gpio->gpio_chip.of_node = pdev->dev.parent->of_node;
#endif
if (pdata && pdata->gpio_base)
tps6586x_gpio->gpio_chip.base = pdata->gpio_base;
else
tps6586x_gpio->gpio_chip.base = -1;
ret = gpiochip_add(&tps6586x_gpio->gpio_chip);
if (ret < 0) {
dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, tps6586x_gpio);
return ret;
}
static int __devexit tps6586x_gpio_remove(struct platform_device *pdev)
{
struct tps6586x_gpio *tps6586x_gpio = platform_get_drvdata(pdev);
return gpiochip_remove(&tps6586x_gpio->gpio_chip);
}
static int __init tps6586x_gpio_init(void)
{
return platform_driver_register(&tps6586x_gpio_driver);
}
static void __exit tps6586x_gpio_exit(void)
{
platform_driver_unregister(&tps6586x_gpio_driver);
}
