static inline struct palmas_gpio *to_palmas_gpio(struct gpio_chip *chip)
{
return container_of(chip, struct palmas_gpio, gpio_chip);
}
static int palmas_gpio_get(struct gpio_chip *gc, unsigned offset)
{
struct palmas_gpio *pg = to_palmas_gpio(gc);
struct palmas *palmas = pg->palmas;
unsigned int val;
int ret;
ret = palmas_read(palmas, PALMAS_GPIO_BASE, PALMAS_GPIO_DATA_IN, &val);
if (ret < 0) {
dev_err(gc->dev, "GPIO_DATA_IN read failed, err = %d\n", ret);
return ret;
}
return !!(val & BIT(offset));
}
static void palmas_gpio_set(struct gpio_chip *gc, unsigned offset,
int value)
{
struct palmas_gpio *pg = to_palmas_gpio(gc);
struct palmas *palmas = pg->palmas;
int ret;
if (value)
ret = palmas_write(palmas, PALMAS_GPIO_BASE,
PALMAS_GPIO_SET_DATA_OUT, BIT(offset));
else
ret = palmas_write(palmas, PALMAS_GPIO_BASE,
PALMAS_GPIO_CLEAR_DATA_OUT, BIT(offset));
if (ret < 0)
dev_err(gc->dev, "%s write failed, err = %d\n",
(value) ? "GPIO_SET_DATA_OUT" : "GPIO_CLEAR_DATA_OUT",
ret);
}
static int palmas_gpio_output(struct gpio_chip *gc, unsigned offset,
int value)
{
struct palmas_gpio *pg = to_palmas_gpio(gc);
struct palmas *palmas = pg->palmas;
int ret;
palmas_gpio_set(gc, offset, value);
ret = palmas_update_bits(palmas, PALMAS_GPIO_BASE,
PALMAS_GPIO_DATA_DIR, BIT(offset), BIT(offset));
if (ret < 0)
dev_err(gc->dev, "GPIO_DATA_DIR write failed, err = %d\n", ret);
return ret;
}
static int palmas_gpio_input(struct gpio_chip *gc, unsigned offset)
{
struct palmas_gpio *pg = to_palmas_gpio(gc);
struct palmas *palmas = pg->palmas;
int ret;
ret = palmas_update_bits(palmas, PALMAS_GPIO_BASE,
PALMAS_GPIO_DATA_DIR, BIT(offset), 0);
if (ret < 0)
dev_err(gc->dev, "GPIO_DATA_DIR write failed, err = %d\n", ret);
return ret;
}
static int palmas_gpio_to_irq(struct gpio_chip *gc, unsigned offset)
{
struct palmas_gpio *pg = to_palmas_gpio(gc);
struct palmas *palmas = pg->palmas;
return palmas_irq_get_virq(palmas, PALMAS_GPIO_0_IRQ + offset);
}
static int palmas_gpio_probe(struct platform_device *pdev)
{
struct palmas *palmas = dev_get_drvdata(pdev->dev.parent);
struct palmas_platform_data *palmas_pdata;
struct palmas_gpio *palmas_gpio;
int ret;
palmas_gpio = devm_kzalloc(&pdev->dev,
sizeof(*palmas_gpio), GFP_KERNEL);
if (!palmas_gpio) {
dev_err(&pdev->dev, "Could not allocate palmas_gpio\n");
return -ENOMEM;
}
palmas_gpio->palmas = palmas;
palmas_gpio->gpio_chip.owner = THIS_MODULE;
palmas_gpio->gpio_chip.label = dev_name(&pdev->dev);
palmas_gpio->gpio_chip.ngpio = 8;
palmas_gpio->gpio_chip.can_sleep = 1;
palmas_gpio->gpio_chip.direction_input = palmas_gpio_input;
palmas_gpio->gpio_chip.direction_output = palmas_gpio_output;
palmas_gpio->gpio_chip.to_irq = palmas_gpio_to_irq;
palmas_gpio->gpio_chip.set = palmas_gpio_set;
palmas_gpio->gpio_chip.get = palmas_gpio_get;
palmas_gpio->gpio_chip.dev = &pdev->dev;
#ifdef CONFIG_OF_GPIO
palmas_gpio->gpio_chip.of_node = palmas->dev->of_node;
#endif
palmas_pdata = dev_get_platdata(palmas->dev);
if (palmas_pdata && palmas_pdata->gpio_base)
palmas_gpio->gpio_chip.base = palmas_pdata->gpio_base;
else
palmas_gpio->gpio_chip.base = -1;
ret = gpiochip_add(&palmas_gpio->gpio_chip);
if (ret < 0) {
dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, palmas_gpio);
return ret;
}
static int palmas_gpio_remove(struct platform_device *pdev)
{
struct palmas_gpio *palmas_gpio = platform_get_drvdata(pdev);
return gpiochip_remove(&palmas_gpio->gpio_chip);
}
static int __init palmas_gpio_init(void)
{
return platform_driver_register(&palmas_gpio_driver);
}
static void __exit palmas_gpio_exit(void)
{
platform_driver_unregister(&palmas_gpio_driver);
}
