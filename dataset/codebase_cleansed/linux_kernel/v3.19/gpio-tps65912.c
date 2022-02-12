static int tps65912_gpio_get(struct gpio_chip *gc, unsigned offset)
{
struct tps65912 *tps65912 = container_of(gc, struct tps65912, gpio);
int val;
val = tps65912_reg_read(tps65912, TPS65912_GPIO1 + offset);
if (val & GPIO_STS_MASK)
return 1;
return 0;
}
static void tps65912_gpio_set(struct gpio_chip *gc, unsigned offset,
int value)
{
struct tps65912 *tps65912 = container_of(gc, struct tps65912, gpio);
if (value)
tps65912_set_bits(tps65912, TPS65912_GPIO1 + offset,
GPIO_SET_MASK);
else
tps65912_clear_bits(tps65912, TPS65912_GPIO1 + offset,
GPIO_SET_MASK);
}
static int tps65912_gpio_output(struct gpio_chip *gc, unsigned offset,
int value)
{
struct tps65912 *tps65912 = container_of(gc, struct tps65912, gpio);
tps65912_gpio_set(gc, offset, value);
return tps65912_set_bits(tps65912, TPS65912_GPIO1 + offset,
GPIO_CFG_MASK);
}
static int tps65912_gpio_input(struct gpio_chip *gc, unsigned offset)
{
struct tps65912 *tps65912 = container_of(gc, struct tps65912, gpio);
return tps65912_clear_bits(tps65912, TPS65912_GPIO1 + offset,
GPIO_CFG_MASK);
}
static int tps65912_gpio_probe(struct platform_device *pdev)
{
struct tps65912 *tps65912 = dev_get_drvdata(pdev->dev.parent);
struct tps65912_board *pdata = dev_get_platdata(tps65912->dev);
struct tps65912_gpio_data *tps65912_gpio;
int ret;
tps65912_gpio = devm_kzalloc(&pdev->dev, sizeof(*tps65912_gpio),
GFP_KERNEL);
if (tps65912_gpio == NULL)
return -ENOMEM;
tps65912_gpio->tps65912 = tps65912;
tps65912_gpio->gpio_chip = template_chip;
tps65912_gpio->gpio_chip.dev = &pdev->dev;
if (pdata && pdata->gpio_base)
tps65912_gpio->gpio_chip.base = pdata->gpio_base;
ret = gpiochip_add(&tps65912_gpio->gpio_chip);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to register gpiochip, %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, tps65912_gpio);
return ret;
}
static int tps65912_gpio_remove(struct platform_device *pdev)
{
struct tps65912_gpio_data *tps65912_gpio = platform_get_drvdata(pdev);
gpiochip_remove(&tps65912_gpio->gpio_chip);
return 0;
}
static int __init tps65912_gpio_init(void)
{
return platform_driver_register(&tps65912_gpio_driver);
}
static void __exit tps65912_gpio_exit(void)
{
platform_driver_unregister(&tps65912_gpio_driver);
}
