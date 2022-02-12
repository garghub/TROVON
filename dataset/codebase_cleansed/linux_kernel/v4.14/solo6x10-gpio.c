static void solo_gpio_mode(struct solo_dev *solo_dev,
unsigned int port_mask, unsigned int mode)
{
int port;
unsigned int ret;
ret = solo_reg_read(solo_dev, SOLO_GPIO_CONFIG_0);
for (port = 0; port < 16; port++) {
if (!((1 << port) & port_mask))
continue;
ret &= (~(3 << (port << 1)));
ret |= ((mode & 3) << (port << 1));
}
solo_reg_write(solo_dev, SOLO_GPIO_CONFIG_0, ret);
ret = solo_reg_read(solo_dev, SOLO_GPIO_CONFIG_1);
for (port = 0; port < 16; port++) {
if (!((1 << (port + 16)) & port_mask))
continue;
if (!mode)
ret &= ~(1 << port);
else
ret |= 1 << port;
}
ret |= 0xffff0000;
solo_reg_write(solo_dev, SOLO_GPIO_CONFIG_1, ret);
}
static void solo_gpio_set(struct solo_dev *solo_dev, unsigned int value)
{
solo_reg_write(solo_dev, SOLO_GPIO_DATA_OUT,
solo_reg_read(solo_dev, SOLO_GPIO_DATA_OUT) | value);
}
static void solo_gpio_clear(struct solo_dev *solo_dev, unsigned int value)
{
solo_reg_write(solo_dev, SOLO_GPIO_DATA_OUT,
solo_reg_read(solo_dev, SOLO_GPIO_DATA_OUT) & ~value);
}
static void solo_gpio_config(struct solo_dev *solo_dev)
{
solo_gpio_mode(solo_dev, 0x30, 1);
solo_gpio_clear(solo_dev, 0x30);
udelay(100);
solo_gpio_set(solo_dev, 0x30);
udelay(100);
solo_gpio_mode(solo_dev, 0x0f, 2);
solo_gpio_mode(solo_dev, 0xff00, 1);
solo_gpio_clear(solo_dev, 0xff00);
solo_gpio_mode(solo_dev, 0xffff0000, 0);
}
static int solo_gpiochip_get_direction(struct gpio_chip *chip,
unsigned int offset)
{
int ret, mode;
struct solo_dev *solo_dev = gpiochip_get_data(chip);
if (offset < 8) {
ret = solo_reg_read(solo_dev, SOLO_GPIO_CONFIG_0);
mode = 3 & (ret >> ((offset + 8) * 2));
} else {
ret = solo_reg_read(solo_dev, SOLO_GPIO_CONFIG_1);
mode = 1 & (ret >> (offset - 8));
}
if (!mode)
return 1;
else if (mode == 1)
return 0;
return -1;
}
static int solo_gpiochip_direction_input(struct gpio_chip *chip,
unsigned int offset)
{
return -1;
}
static int solo_gpiochip_direction_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
return -1;
}
static int solo_gpiochip_get(struct gpio_chip *chip,
unsigned int offset)
{
int ret;
struct solo_dev *solo_dev = gpiochip_get_data(chip);
ret = solo_reg_read(solo_dev, SOLO_GPIO_DATA_IN);
return 1 & (ret >> (offset + 8));
}
static void solo_gpiochip_set(struct gpio_chip *chip,
unsigned int offset, int value)
{
struct solo_dev *solo_dev = gpiochip_get_data(chip);
if (value)
solo_gpio_set(solo_dev, 1 << (offset + 8));
else
solo_gpio_clear(solo_dev, 1 << (offset + 8));
}
int solo_gpio_init(struct solo_dev *solo_dev)
{
int ret;
solo_gpio_config(solo_dev);
#ifdef CONFIG_GPIOLIB
solo_dev->gpio_dev.label = SOLO6X10_NAME"_gpio";
solo_dev->gpio_dev.parent = &solo_dev->pdev->dev;
solo_dev->gpio_dev.owner = THIS_MODULE;
solo_dev->gpio_dev.base = -1;
solo_dev->gpio_dev.ngpio = 24;
solo_dev->gpio_dev.can_sleep = 0;
solo_dev->gpio_dev.get_direction = solo_gpiochip_get_direction;
solo_dev->gpio_dev.direction_input = solo_gpiochip_direction_input;
solo_dev->gpio_dev.direction_output = solo_gpiochip_direction_output;
solo_dev->gpio_dev.get = solo_gpiochip_get;
solo_dev->gpio_dev.set = solo_gpiochip_set;
ret = gpiochip_add_data(&solo_dev->gpio_dev, solo_dev);
if (ret) {
solo_dev->gpio_dev.label = NULL;
return -1;
}
#endif
return 0;
}
void solo_gpio_exit(struct solo_dev *solo_dev)
{
#ifdef CONFIG_GPIOLIB
if (solo_dev->gpio_dev.label) {
gpiochip_remove(&solo_dev->gpio_dev);
solo_dev->gpio_dev.label = NULL;
}
#endif
solo_gpio_clear(solo_dev, 0x30);
solo_gpio_config(solo_dev);
}
