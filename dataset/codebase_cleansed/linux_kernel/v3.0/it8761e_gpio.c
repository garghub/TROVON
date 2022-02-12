static u8 read_reg(u8 addr, u8 port)
{
outb(addr, port);
return inb(port + 1);
}
static void write_reg(u8 data, u8 addr, u8 port)
{
outb(addr, port);
outb(data, port + 1);
}
static void enter_conf_mode(u8 port)
{
outb(0x87, port);
outb(0x61, port);
outb(0x55, port);
outb((port == 0x2e) ? 0x55 : 0xaa, port);
}
static void exit_conf_mode(u8 port)
{
outb(0x2, port);
outb(0x2, port + 1);
}
static void enter_gpio_mode(u8 port)
{
write_reg(0x2, 0x7, port);
}
static int it8761e_gpio_get(struct gpio_chip *gc, unsigned gpio_num)
{
u16 reg;
u8 bit;
bit = gpio_num % 8;
reg = (gpio_num >= 8) ? gpio_ba + 1 : gpio_ba;
return !!(inb(reg) & (1 << bit));
}
static int it8761e_gpio_direction_in(struct gpio_chip *gc, unsigned gpio_num)
{
u8 curr_dirs;
u8 io_reg, bit;
bit = gpio_num % 8;
io_reg = (gpio_num >= 8) ? GPIO2X_IO : GPIO1X_IO;
spin_lock(&sio_lock);
enter_conf_mode(port);
enter_gpio_mode(port);
curr_dirs = read_reg(io_reg, port);
if (curr_dirs & (1 << bit))
write_reg(curr_dirs & ~(1 << bit), io_reg, port);
exit_conf_mode(port);
spin_unlock(&sio_lock);
return 0;
}
static void it8761e_gpio_set(struct gpio_chip *gc,
unsigned gpio_num, int val)
{
u8 curr_vals, bit;
u16 reg;
bit = gpio_num % 8;
reg = (gpio_num >= 8) ? gpio_ba + 1 : gpio_ba;
spin_lock(&sio_lock);
curr_vals = inb(reg);
if (val)
outb(curr_vals | (1 << bit) , reg);
else
outb(curr_vals & ~(1 << bit), reg);
spin_unlock(&sio_lock);
}
static int it8761e_gpio_direction_out(struct gpio_chip *gc,
unsigned gpio_num, int val)
{
u8 curr_dirs, io_reg, bit;
bit = gpio_num % 8;
io_reg = (gpio_num >= 8) ? GPIO2X_IO : GPIO1X_IO;
it8761e_gpio_set(gc, gpio_num, val);
spin_lock(&sio_lock);
enter_conf_mode(port);
enter_gpio_mode(port);
curr_dirs = read_reg(io_reg, port);
if (!(curr_dirs & (1 << bit)))
write_reg(curr_dirs | (1 << bit), io_reg, port);
exit_conf_mode(port);
spin_unlock(&sio_lock);
return 0;
}
static int __init it8761e_gpio_init(void)
{
int i, id, err;
for (i = 0; i < ARRAY_SIZE(ports); i++) {
spin_lock(&sio_lock);
enter_conf_mode(ports[i]);
id = (read_reg(CHIP_ID_HIGH_BYTE, ports[i]) << 8) +
read_reg(CHIP_ID_LOW_BYTE, ports[i]);
exit_conf_mode(ports[i]);
spin_unlock(&sio_lock);
if (id == SIO_CHIP_ID) {
port = ports[i];
break;
}
}
if (!port)
return -ENODEV;
enter_conf_mode(port);
enter_gpio_mode(port);
gpio_ba = (read_reg(GPIO_BA_HIGH_BYTE, port) << 8) +
read_reg(GPIO_BA_LOW_BYTE, port);
exit_conf_mode(port);
if (!request_region(gpio_ba, GPIO_IOSIZE, GPIO_NAME))
return -EBUSY;
it8761e_gpio_chip.base = -1;
it8761e_gpio_chip.ngpio = 16;
err = gpiochip_add(&it8761e_gpio_chip);
if (err < 0)
goto gpiochip_add_err;
return 0;
gpiochip_add_err:
release_region(gpio_ba, GPIO_IOSIZE);
gpio_ba = 0;
return err;
}
static void __exit it8761e_gpio_exit(void)
{
if (gpio_ba) {
int ret = gpiochip_remove(&it8761e_gpio_chip);
WARN(ret, "%s(): gpiochip_remove() failed, ret=%d\n",
__func__, ret);
release_region(gpio_ba, GPIO_IOSIZE);
gpio_ba = 0;
}
}
