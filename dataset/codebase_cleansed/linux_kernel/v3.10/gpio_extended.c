static int msp71xx_exd_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct msp71xx_exd_gpio_chip *msp71xx_chip =
to_msp71xx_exd_gpio_chip(chip);
const unsigned bit = MSP71XX_READ_OFFSET(offset);
return __raw_readl(msp71xx_chip->reg) & (1 << bit);
}
static void msp71xx_exd_gpio_set(struct gpio_chip *chip,
unsigned offset, int value)
{
struct msp71xx_exd_gpio_chip *msp71xx_chip =
to_msp71xx_exd_gpio_chip(chip);
const unsigned bit = MSP71XX_DATA_OFFSET(offset);
__raw_writel(1 << (bit + (value ? 1 : 0)), msp71xx_chip->reg);
}
static int msp71xx_exd_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
struct msp71xx_exd_gpio_chip *msp71xx_chip =
to_msp71xx_exd_gpio_chip(chip);
msp71xx_exd_gpio_set(chip, offset, value);
__raw_writel(1 << MSP71XX_CFG_OUT_OFFSET(offset), msp71xx_chip->reg);
return 0;
}
static int msp71xx_exd_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct msp71xx_exd_gpio_chip *msp71xx_chip =
to_msp71xx_exd_gpio_chip(chip);
__raw_writel(1 << MSP71XX_CFG_IN_OFFSET(offset), msp71xx_chip->reg);
return 0;
}
void __init msp71xx_init_gpio_extended(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(msp71xx_exd_gpio_banks); i++)
gpiochip_add(&msp71xx_exd_gpio_banks[i].chip);
}
