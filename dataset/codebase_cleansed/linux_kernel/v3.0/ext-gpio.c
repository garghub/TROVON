static void __iomem *gpio_chip_to_mmr(struct gpio_chip *chip)
{
switch (chip->base) {
default:
case GPIO_PC0: return (void __iomem *)PORTCIO;
case GPIO_PD0: return (void __iomem *)PORTDIO;
case GPIO_PE0: return (void __iomem *)PORTEIO;
}
}
static int bf538_gpio_get_value(struct gpio_chip *chip, unsigned gpio)
{
void __iomem *port = gpio_chip_to_mmr(chip);
return !!(read_PORTIO(port) & (1u << gpio));
}
static void bf538_gpio_set_value(struct gpio_chip *chip, unsigned gpio, int value)
{
void __iomem *port = gpio_chip_to_mmr(chip);
if (value)
write_PORTIO_SET(port, (1u << gpio));
else
write_PORTIO_CLEAR(port, (1u << gpio));
}
static int bf538_gpio_direction_input(struct gpio_chip *chip, unsigned gpio)
{
void __iomem *port = gpio_chip_to_mmr(chip);
write_PORTIO_DIR(port, read_PORTIO_DIR(port) & ~(1u << gpio));
write_PORTIO_INEN(port, read_PORTIO_INEN(port) | (1u << gpio));
return 0;
}
static int bf538_gpio_direction_output(struct gpio_chip *chip, unsigned gpio, int value)
{
void __iomem *port = gpio_chip_to_mmr(chip);
write_PORTIO_INEN(port, read_PORTIO_INEN(port) & ~(1u << gpio));
bf538_gpio_set_value(port, gpio, value);
write_PORTIO_DIR(port, read_PORTIO_DIR(port) | (1u << gpio));
return 0;
}
static int bf538_gpio_request(struct gpio_chip *chip, unsigned gpio)
{
return bfin_special_gpio_request(chip->base + gpio, chip->label);
}
static void bf538_gpio_free(struct gpio_chip *chip, unsigned gpio)
{
return bfin_special_gpio_free(chip->base + gpio);
}
static int __init bf538_extgpio_setup(void)
{
return gpiochip_add(&bf538_portc_chip) |
gpiochip_add(&bf538_portd_chip) |
gpiochip_add(&bf538_porte_chip);
}
