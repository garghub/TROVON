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
}
int solo_gpio_init(struct solo_dev *solo_dev)
{
solo_gpio_config(solo_dev);
return 0;
}
void solo_gpio_exit(struct solo_dev *solo_dev)
{
solo_gpio_clear(solo_dev, 0x30);
solo_gpio_config(solo_dev);
}
