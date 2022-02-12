static inline struct tps65910_gpio *to_tps65910_gpio(struct gpio_chip *chip)
{
return container_of(chip, struct tps65910_gpio, gpio_chip);
}
static int tps65910_gpio_get(struct gpio_chip *gc, unsigned offset)
{
struct tps65910_gpio *tps65910_gpio = to_tps65910_gpio(gc);
struct tps65910 *tps65910 = tps65910_gpio->tps65910;
unsigned int val;
tps65910_reg_read(tps65910, TPS65910_GPIO0 + offset, &val);
if (val & GPIO_STS_MASK)
return 1;
return 0;
}
static void tps65910_gpio_set(struct gpio_chip *gc, unsigned offset,
int value)
{
struct tps65910_gpio *tps65910_gpio = to_tps65910_gpio(gc);
struct tps65910 *tps65910 = tps65910_gpio->tps65910;
if (value)
tps65910_reg_set_bits(tps65910, TPS65910_GPIO0 + offset,
GPIO_SET_MASK);
else
tps65910_reg_clear_bits(tps65910, TPS65910_GPIO0 + offset,
GPIO_SET_MASK);
}
static int tps65910_gpio_output(struct gpio_chip *gc, unsigned offset,
int value)
{
struct tps65910_gpio *tps65910_gpio = to_tps65910_gpio(gc);
struct tps65910 *tps65910 = tps65910_gpio->tps65910;
tps65910_gpio_set(gc, offset, value);
return tps65910_reg_set_bits(tps65910, TPS65910_GPIO0 + offset,
GPIO_CFG_MASK);
}
static int tps65910_gpio_input(struct gpio_chip *gc, unsigned offset)
{
struct tps65910_gpio *tps65910_gpio = to_tps65910_gpio(gc);
struct tps65910 *tps65910 = tps65910_gpio->tps65910;
return tps65910_reg_clear_bits(tps65910, TPS65910_GPIO0 + offset,
GPIO_CFG_MASK);
}
static struct tps65910_board *tps65910_parse_dt_for_gpio(struct device *dev,
struct tps65910 *tps65910, int chip_ngpio)
{
struct tps65910_board *tps65910_board = tps65910->of_plat_data;
unsigned int prop_array[TPS6591X_MAX_NUM_GPIO];
int ngpio = min(chip_ngpio, TPS6591X_MAX_NUM_GPIO);
int ret;
int idx;
tps65910_board->gpio_base = -1;
ret = of_property_read_u32_array(tps65910->dev->of_node,
"ti,en-gpio-sleep", prop_array, ngpio);
if (ret < 0) {
dev_dbg(dev, "ti,en-gpio-sleep not specified\n");
return tps65910_board;
}
for (idx = 0; idx < ngpio; idx++)
tps65910_board->en_gpio_sleep[idx] = (prop_array[idx] != 0);
return tps65910_board;
}
static struct tps65910_board *tps65910_parse_dt_for_gpio(struct device *dev,
struct tps65910 *tps65910, int chip_ngpio)
{
return NULL;
}
static int tps65910_gpio_probe(struct platform_device *pdev)
{
struct tps65910 *tps65910 = dev_get_drvdata(pdev->dev.parent);
struct tps65910_board *pdata = dev_get_platdata(tps65910->dev);
struct tps65910_gpio *tps65910_gpio;
int ret;
int i;
tps65910_gpio = devm_kzalloc(&pdev->dev,
sizeof(*tps65910_gpio), GFP_KERNEL);
if (!tps65910_gpio)
return -ENOMEM;
tps65910_gpio->tps65910 = tps65910;
tps65910_gpio->gpio_chip.owner = THIS_MODULE;
tps65910_gpio->gpio_chip.label = tps65910->i2c_client->name;
switch (tps65910_chip_id(tps65910)) {
case TPS65910:
tps65910_gpio->gpio_chip.ngpio = TPS65910_NUM_GPIO;
break;
case TPS65911:
tps65910_gpio->gpio_chip.ngpio = TPS65911_NUM_GPIO;
break;
default:
return -EINVAL;
}
tps65910_gpio->gpio_chip.can_sleep = true;
tps65910_gpio->gpio_chip.direction_input = tps65910_gpio_input;
tps65910_gpio->gpio_chip.direction_output = tps65910_gpio_output;
tps65910_gpio->gpio_chip.set = tps65910_gpio_set;
tps65910_gpio->gpio_chip.get = tps65910_gpio_get;
tps65910_gpio->gpio_chip.dev = &pdev->dev;
#ifdef CONFIG_OF_GPIO
tps65910_gpio->gpio_chip.of_node = tps65910->dev->of_node;
#endif
if (pdata && pdata->gpio_base)
tps65910_gpio->gpio_chip.base = pdata->gpio_base;
else
tps65910_gpio->gpio_chip.base = -1;
if (!pdata && tps65910->dev->of_node)
pdata = tps65910_parse_dt_for_gpio(&pdev->dev, tps65910,
tps65910_gpio->gpio_chip.ngpio);
if (!pdata)
goto skip_init;
for (i = 0; i < tps65910_gpio->gpio_chip.ngpio; ++i) {
if (!pdata->en_gpio_sleep[i])
continue;
ret = tps65910_reg_set_bits(tps65910,
TPS65910_GPIO0 + i, GPIO_SLEEP_MASK);
if (ret < 0)
dev_warn(tps65910->dev,
"GPIO Sleep setting failed with err %d\n", ret);
}
skip_init:
ret = gpiochip_add(&tps65910_gpio->gpio_chip);
if (ret < 0) {
dev_err(&pdev->dev, "Could not register gpiochip, %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, tps65910_gpio);
return ret;
}
static int tps65910_gpio_remove(struct platform_device *pdev)
{
struct tps65910_gpio *tps65910_gpio = platform_get_drvdata(pdev);
gpiochip_remove(&tps65910_gpio->gpio_chip);
return 0;
}
static int __init tps65910_gpio_init(void)
{
return platform_driver_register(&tps65910_gpio_driver);
}
static void __exit tps65910_gpio_exit(void)
{
platform_driver_unregister(&tps65910_gpio_driver);
}
