static int loongson_gpio_direction_input(struct gpio_chip *chip, unsigned gpio)
{
u32 temp;
u32 mask;
spin_lock(&gpio_lock);
mask = 1 << gpio;
temp = LOONGSON_GPIOIE;
temp |= mask;
LOONGSON_GPIOIE = temp;
spin_unlock(&gpio_lock);
return 0;
}
static int loongson_gpio_direction_output(struct gpio_chip *chip,
unsigned gpio, int level)
{
u32 temp;
u32 mask;
gpio_set_value(gpio, level);
spin_lock(&gpio_lock);
mask = 1 << gpio;
temp = LOONGSON_GPIOIE;
temp &= (~mask);
LOONGSON_GPIOIE = temp;
spin_unlock(&gpio_lock);
return 0;
}
static int loongson_gpio_get_value(struct gpio_chip *chip, unsigned gpio)
{
u32 val;
u32 mask;
mask = 1 << (gpio + LOONGSON_GPIO_IN_OFFSET);
spin_lock(&gpio_lock);
val = LOONGSON_GPIODATA;
spin_unlock(&gpio_lock);
return (val & mask) != 0;
}
static void loongson_gpio_set_value(struct gpio_chip *chip,
unsigned gpio, int value)
{
u32 val;
u32 mask;
mask = 1 << gpio;
spin_lock(&gpio_lock);
val = LOONGSON_GPIODATA;
if (value)
val |= mask;
else
val &= (~mask);
LOONGSON_GPIODATA = val;
spin_unlock(&gpio_lock);
}
static int __init loongson_gpio_setup(void)
{
return gpiochip_add_data(&loongson_chip, NULL);
}
