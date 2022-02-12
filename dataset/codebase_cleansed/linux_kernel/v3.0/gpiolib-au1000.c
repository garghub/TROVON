static int gpio2_get(struct gpio_chip *chip, unsigned offset)
{
return alchemy_gpio2_get_value(offset + ALCHEMY_GPIO2_BASE);
}
static void gpio2_set(struct gpio_chip *chip, unsigned offset, int value)
{
alchemy_gpio2_set_value(offset + ALCHEMY_GPIO2_BASE, value);
}
static int gpio2_direction_input(struct gpio_chip *chip, unsigned offset)
{
return alchemy_gpio2_direction_input(offset + ALCHEMY_GPIO2_BASE);
}
static int gpio2_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
return alchemy_gpio2_direction_output(offset + ALCHEMY_GPIO2_BASE,
value);
}
static int gpio2_to_irq(struct gpio_chip *chip, unsigned offset)
{
return alchemy_gpio2_to_irq(offset + ALCHEMY_GPIO2_BASE);
}
static int gpio1_get(struct gpio_chip *chip, unsigned offset)
{
return alchemy_gpio1_get_value(offset + ALCHEMY_GPIO1_BASE);
}
static void gpio1_set(struct gpio_chip *chip,
unsigned offset, int value)
{
alchemy_gpio1_set_value(offset + ALCHEMY_GPIO1_BASE, value);
}
static int gpio1_direction_input(struct gpio_chip *chip, unsigned offset)
{
return alchemy_gpio1_direction_input(offset + ALCHEMY_GPIO1_BASE);
}
static int gpio1_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
return alchemy_gpio1_direction_output(offset + ALCHEMY_GPIO1_BASE,
value);
}
static int gpio1_to_irq(struct gpio_chip *chip, unsigned offset)
{
return alchemy_gpio1_to_irq(offset + ALCHEMY_GPIO1_BASE);
}
static int __init alchemy_gpiolib_init(void)
{
gpiochip_add(&alchemy_gpio_chip[0]);
if (alchemy_get_cputype() != ALCHEMY_CPU_AU1000)
gpiochip_add(&alchemy_gpio_chip[1]);
return 0;
}
