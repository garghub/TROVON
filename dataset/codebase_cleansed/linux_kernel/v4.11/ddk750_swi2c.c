static void sw_i2c_wait(void)
{
int i, tmp;
for (i = 0; i < 600; i++) {
tmp = i;
tmp += i;
}
}
static void sw_i2c_scl(unsigned char value)
{
unsigned long gpio_data;
unsigned long gpio_dir;
gpio_dir = peek32(sw_i2c_clk_gpio_data_dir_reg);
if (value) {
gpio_dir &= ~(1 << sw_i2c_clk_gpio);
poke32(sw_i2c_clk_gpio_data_dir_reg, gpio_dir);
} else {
gpio_data = peek32(sw_i2c_clk_gpio_data_reg);
gpio_data &= ~(1 << sw_i2c_clk_gpio);
poke32(sw_i2c_clk_gpio_data_reg, gpio_data);
gpio_dir |= (1 << sw_i2c_clk_gpio);
poke32(sw_i2c_clk_gpio_data_dir_reg, gpio_dir);
}
}
static void sw_i2c_sda(unsigned char value)
{
unsigned long gpio_data;
unsigned long gpio_dir;
gpio_dir = peek32(sw_i2c_data_gpio_data_dir_reg);
if (value) {
gpio_dir &= ~(1 << sw_i2c_data_gpio);
poke32(sw_i2c_data_gpio_data_dir_reg, gpio_dir);
} else {
gpio_data = peek32(sw_i2c_data_gpio_data_reg);
gpio_data &= ~(1 << sw_i2c_data_gpio);
poke32(sw_i2c_data_gpio_data_reg, gpio_data);
gpio_dir |= (1 << sw_i2c_data_gpio);
poke32(sw_i2c_data_gpio_data_dir_reg, gpio_dir);
}
}
static unsigned char sw_i2c_read_sda(void)
{
unsigned long gpio_dir;
unsigned long gpio_data;
unsigned long dir_mask = 1 << sw_i2c_data_gpio;
gpio_dir = peek32(sw_i2c_data_gpio_data_dir_reg);
if ((gpio_dir & dir_mask) != ~dir_mask) {
gpio_dir &= ~(1 << sw_i2c_data_gpio);
poke32(sw_i2c_data_gpio_data_dir_reg, gpio_dir);
}
gpio_data = peek32(sw_i2c_data_gpio_data_reg);
if (gpio_data & (1 << sw_i2c_data_gpio))
return 1;
else
return 0;
}
static void sw_i2c_ack(void)
{
return;
}
static void sw_i2c_start(void)
{
sw_i2c_sda(1);
sw_i2c_scl(1);
sw_i2c_sda(0);
}
static void sw_i2c_stop(void)
{
sw_i2c_scl(1);
sw_i2c_sda(0);
sw_i2c_sda(1);
}
static long sw_i2c_write_byte(unsigned char data)
{
unsigned char value = data;
int i;
for (i = 0; i < 8; i++) {
sw_i2c_scl(0);
if ((value & 0x80) != 0)
sw_i2c_sda(1);
else
sw_i2c_sda(0);
sw_i2c_wait();
sw_i2c_scl(1);
sw_i2c_wait();
value = value << 1;
}
sw_i2c_scl(0);
sw_i2c_sda(1);
sw_i2c_wait();
sw_i2c_scl(1);
sw_i2c_wait();
for (i = 0; i < 0xff; i++) {
if (!sw_i2c_read_sda())
break;
sw_i2c_scl(0);
sw_i2c_wait();
sw_i2c_scl(1);
sw_i2c_wait();
}
sw_i2c_scl(0);
sw_i2c_sda(1);
if (i < 0xff)
return 0;
else
return -1;
}
static unsigned char sw_i2c_read_byte(unsigned char ack)
{
int i;
unsigned char data = 0;
for (i = 7; i >= 0; i--) {
sw_i2c_scl(0);
sw_i2c_sda(1);
sw_i2c_wait();
sw_i2c_scl(1);
sw_i2c_wait();
data |= (sw_i2c_read_sda() << i);
}
if (ack)
sw_i2c_ack();
sw_i2c_scl(0);
sw_i2c_sda(1);
return data;
}
static long sm750le_i2c_init(unsigned char clk_gpio,
unsigned char data_gpio)
{
int i;
sw_i2c_clk_gpio_data_reg = GPIO_DATA_SM750LE;
sw_i2c_clk_gpio_data_dir_reg = GPIO_DATA_DIRECTION_SM750LE;
sw_i2c_clk_gpio = clk_gpio;
sw_i2c_data_gpio_data_reg = GPIO_DATA_SM750LE;
sw_i2c_data_gpio_data_dir_reg = GPIO_DATA_DIRECTION_SM750LE;
sw_i2c_data_gpio = data_gpio;
for (i = 0; i < 9; i++)
sw_i2c_stop();
return 0;
}
long sm750_sw_i2c_init(
unsigned char clk_gpio,
unsigned char data_gpio
)
{
int i;
if ((clk_gpio > 31) || (data_gpio > 31))
return -1;
if (sm750_get_chip_type() == SM750LE)
return sm750le_i2c_init(clk_gpio, data_gpio);
sw_i2c_clk_gpio_mux_reg = GPIO_MUX;
sw_i2c_clk_gpio_data_reg = GPIO_DATA;
sw_i2c_clk_gpio_data_dir_reg = GPIO_DATA_DIRECTION;
sw_i2c_clk_gpio = clk_gpio;
sw_i2c_data_gpio_mux_reg = GPIO_MUX;
sw_i2c_data_gpio_data_reg = GPIO_DATA;
sw_i2c_data_gpio_data_dir_reg = GPIO_DATA_DIRECTION;
sw_i2c_data_gpio = data_gpio;
poke32(sw_i2c_clk_gpio_mux_reg,
peek32(sw_i2c_clk_gpio_mux_reg) & ~(1 << sw_i2c_clk_gpio));
poke32(sw_i2c_data_gpio_mux_reg,
peek32(sw_i2c_data_gpio_mux_reg) & ~(1 << sw_i2c_data_gpio));
sm750_enable_gpio(1);
for (i = 0; i < 9; i++)
sw_i2c_stop();
return 0;
}
unsigned char sm750_sw_i2c_read_reg(
unsigned char addr,
unsigned char reg
)
{
unsigned char data;
sw_i2c_start();
sw_i2c_write_byte(addr);
sw_i2c_write_byte(reg);
sw_i2c_start();
sw_i2c_write_byte(addr + 1);
data = sw_i2c_read_byte(1);
sw_i2c_stop();
return data;
}
long sm750_sw_i2c_write_reg(
unsigned char addr,
unsigned char reg,
unsigned char data
)
{
long ret = 0;
sw_i2c_start();
if ((sw_i2c_write_byte(addr) != 0) ||
(sw_i2c_write_byte(reg) != 0) ||
(sw_i2c_write_byte(data) != 0)) {
ret = -1;
}
sw_i2c_stop();
return ret;
}
