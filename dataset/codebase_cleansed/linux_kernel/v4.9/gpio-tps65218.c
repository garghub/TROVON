static int tps65218_gpio_get(struct gpio_chip *gc, unsigned offset)
{
struct tps65218_gpio *tps65218_gpio = gpiochip_get_data(gc);
struct tps65218 *tps65218 = tps65218_gpio->tps65218;
unsigned int val;
int ret;
ret = tps65218_reg_read(tps65218, TPS65218_REG_ENABLE2, &val);
if (ret)
return ret;
return !!(val & (TPS65218_ENABLE2_GPIO1 << offset));
}
static void tps65218_gpio_set(struct gpio_chip *gc, unsigned offset,
int value)
{
struct tps65218_gpio *tps65218_gpio = gpiochip_get_data(gc);
struct tps65218 *tps65218 = tps65218_gpio->tps65218;
if (value)
tps65218_set_bits(tps65218, TPS65218_REG_ENABLE2,
TPS65218_ENABLE2_GPIO1 << offset,
TPS65218_ENABLE2_GPIO1 << offset,
TPS65218_PROTECT_L1);
else
tps65218_clear_bits(tps65218, TPS65218_REG_ENABLE2,
TPS65218_ENABLE2_GPIO1 << offset,
TPS65218_PROTECT_L1);
}
static int tps65218_gpio_output(struct gpio_chip *gc, unsigned offset,
int value)
{
tps65218_gpio_set(gc, offset, value);
return 0;
}
static int tps65218_gpio_input(struct gpio_chip *gc, unsigned offset)
{
return -EPERM;
}
static int tps65218_gpio_request(struct gpio_chip *gc, unsigned offset)
{
struct tps65218_gpio *tps65218_gpio = gpiochip_get_data(gc);
struct tps65218 *tps65218 = tps65218_gpio->tps65218;
int ret;
if (gpiochip_line_is_open_source(gc, offset)) {
dev_err(gc->parent, "can't work as open source\n");
return -EINVAL;
}
switch (offset) {
case 0:
if (!gpiochip_line_is_open_drain(gc, offset)) {
dev_err(gc->parent, "GPO1 works only as open drain\n");
return -EINVAL;
}
ret = tps65218_clear_bits(tps65218, TPS65218_REG_SEQ7,
TPS65218_SEQ7_GPO1_SEQ_MASK,
TPS65218_PROTECT_L1);
if (ret)
return ret;
ret = tps65218_clear_bits(tps65218, TPS65218_REG_CONFIG1,
TPS65218_CONFIG1_IO1_SEL,
TPS65218_PROTECT_L1);
if (ret)
return ret;
break;
case 1:
ret = tps65218_clear_bits(tps65218, TPS65218_REG_CONFIG1,
TPS65218_CONFIG1_IO1_SEL,
TPS65218_PROTECT_L1);
if (ret)
return ret;
break;
case 2:
if (!gpiochip_line_is_open_drain(gc, offset)) {
dev_err(gc->parent, "GPO3 works only as open drain\n");
return -EINVAL;
}
ret = tps65218_clear_bits(tps65218, TPS65218_REG_SEQ7,
TPS65218_SEQ7_GPO3_SEQ_MASK,
TPS65218_PROTECT_L1);
if (ret)
return ret;
ret = tps65218_clear_bits(tps65218, TPS65218_REG_CONFIG2,
TPS65218_CONFIG2_DC12_RST,
TPS65218_PROTECT_L1);
if (ret)
return ret;
break;
default:
return -EINVAL;
}
return 0;
}
static int tps65218_gpio_set_single_ended(struct gpio_chip *gc,
unsigned offset,
enum single_ended_mode mode)
{
struct tps65218_gpio *tps65218_gpio = gpiochip_get_data(gc);
struct tps65218 *tps65218 = tps65218_gpio->tps65218;
switch (offset) {
case 0:
case 2:
if (mode == LINE_MODE_OPEN_DRAIN)
return 0;
return -ENOTSUPP;
case 1:
if (mode == LINE_MODE_OPEN_DRAIN)
return tps65218_clear_bits(tps65218,
TPS65218_REG_CONFIG1,
TPS65218_CONFIG1_GPO2_BUF,
TPS65218_PROTECT_L1);
if (mode == LINE_MODE_PUSH_PULL)
return tps65218_set_bits(tps65218,
TPS65218_REG_CONFIG1,
TPS65218_CONFIG1_GPO2_BUF,
TPS65218_CONFIG1_GPO2_BUF,
TPS65218_PROTECT_L1);
return -ENOTSUPP;
default:
break;
}
return -ENOTSUPP;
}
static int tps65218_gpio_probe(struct platform_device *pdev)
{
struct tps65218 *tps65218 = dev_get_drvdata(pdev->dev.parent);
struct tps65218_gpio *tps65218_gpio;
int ret;
tps65218_gpio = devm_kzalloc(&pdev->dev, sizeof(*tps65218_gpio),
GFP_KERNEL);
if (!tps65218_gpio)
return -ENOMEM;
tps65218_gpio->tps65218 = tps65218;
tps65218_gpio->gpio_chip = template_chip;
tps65218_gpio->gpio_chip.parent = &pdev->dev;
#ifdef CONFIG_OF_GPIO
tps65218_gpio->gpio_chip.of_node = pdev->dev.of_node;
#endif
ret = devm_gpiochip_add_data(&pdev->dev, &tps65218_gpio->gpio_chip,
tps65218_gpio);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to register gpiochip, %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, tps65218_gpio);
return ret;
}
