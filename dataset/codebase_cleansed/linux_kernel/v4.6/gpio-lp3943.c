static int lp3943_gpio_request(struct gpio_chip *chip, unsigned offset)
{
struct lp3943_gpio *lp3943_gpio = gpiochip_get_data(chip);
struct lp3943 *lp3943 = lp3943_gpio->lp3943;
if (test_and_set_bit(offset, &lp3943->pin_used))
return -EBUSY;
return 0;
}
static void lp3943_gpio_free(struct gpio_chip *chip, unsigned offset)
{
struct lp3943_gpio *lp3943_gpio = gpiochip_get_data(chip);
struct lp3943 *lp3943 = lp3943_gpio->lp3943;
clear_bit(offset, &lp3943->pin_used);
}
static int lp3943_gpio_set_mode(struct lp3943_gpio *lp3943_gpio, u8 offset,
u8 val)
{
struct lp3943 *lp3943 = lp3943_gpio->lp3943;
const struct lp3943_reg_cfg *mux = lp3943->mux_cfg;
return lp3943_update_bits(lp3943, mux[offset].reg, mux[offset].mask,
val << mux[offset].shift);
}
static int lp3943_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct lp3943_gpio *lp3943_gpio = gpiochip_get_data(chip);
lp3943_gpio->input_mask |= BIT(offset);
return lp3943_gpio_set_mode(lp3943_gpio, offset, LP3943_GPIO_IN);
}
static int lp3943_get_gpio_in_status(struct lp3943_gpio *lp3943_gpio,
struct gpio_chip *chip, unsigned offset)
{
u8 addr, read;
int err;
switch (offset) {
case LP3943_GPIO1 ... LP3943_GPIO8:
addr = LP3943_REG_GPIO_A;
break;
case LP3943_GPIO9 ... LP3943_GPIO16:
addr = LP3943_REG_GPIO_B;
offset = offset - 8;
break;
default:
return -EINVAL;
}
err = lp3943_read_byte(lp3943_gpio->lp3943, addr, &read);
if (err)
return err;
return !!(read & BIT(offset));
}
static int lp3943_get_gpio_out_status(struct lp3943_gpio *lp3943_gpio,
struct gpio_chip *chip, unsigned offset)
{
struct lp3943 *lp3943 = lp3943_gpio->lp3943;
const struct lp3943_reg_cfg *mux = lp3943->mux_cfg;
u8 read;
int err;
err = lp3943_read_byte(lp3943, mux[offset].reg, &read);
if (err)
return err;
read = (read & mux[offset].mask) >> mux[offset].shift;
if (read == LP3943_GPIO_OUT_HIGH)
return 1;
else if (read == LP3943_GPIO_OUT_LOW)
return 0;
else
return -EINVAL;
}
static int lp3943_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct lp3943_gpio *lp3943_gpio = gpiochip_get_data(chip);
if (lp3943_gpio->input_mask & BIT(offset))
return lp3943_get_gpio_in_status(lp3943_gpio, chip, offset);
else
return lp3943_get_gpio_out_status(lp3943_gpio, chip, offset);
}
static void lp3943_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct lp3943_gpio *lp3943_gpio = gpiochip_get_data(chip);
u8 data;
if (value)
data = LP3943_GPIO_OUT_HIGH;
else
data = LP3943_GPIO_OUT_LOW;
lp3943_gpio_set_mode(lp3943_gpio, offset, data);
}
static int lp3943_gpio_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
struct lp3943_gpio *lp3943_gpio = gpiochip_get_data(chip);
lp3943_gpio_set(chip, offset, value);
lp3943_gpio->input_mask &= ~BIT(offset);
return 0;
}
static int lp3943_gpio_probe(struct platform_device *pdev)
{
struct lp3943 *lp3943 = dev_get_drvdata(pdev->dev.parent);
struct lp3943_gpio *lp3943_gpio;
lp3943_gpio = devm_kzalloc(&pdev->dev, sizeof(*lp3943_gpio),
GFP_KERNEL);
if (!lp3943_gpio)
return -ENOMEM;
lp3943_gpio->lp3943 = lp3943;
lp3943_gpio->chip = lp3943_gpio_chip;
lp3943_gpio->chip.parent = &pdev->dev;
platform_set_drvdata(pdev, lp3943_gpio);
return devm_gpiochip_add_data(&pdev->dev, &lp3943_gpio->chip,
lp3943_gpio);
}
