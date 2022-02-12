static int sa1100_gpio_get(struct gpio_chip *chip, unsigned offset)
{
return GPLR & GPIO_GPIO(offset);
}
static void sa1100_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
if (value)
GPSR = GPIO_GPIO(offset);
else
GPCR = GPIO_GPIO(offset);
}
static int sa1100_direction_input(struct gpio_chip *chip, unsigned offset)
{
unsigned long flags;
local_irq_save(flags);
GPDR &= ~GPIO_GPIO(offset);
local_irq_restore(flags);
return 0;
}
static int sa1100_direction_output(struct gpio_chip *chip, unsigned offset, int value)
{
unsigned long flags;
local_irq_save(flags);
sa1100_gpio_set(chip, offset, value);
GPDR |= GPIO_GPIO(offset);
local_irq_restore(flags);
return 0;
}
void __init sa1100_init_gpio(void)
{
gpiochip_add(&sa1100_gpio_chip);
}
