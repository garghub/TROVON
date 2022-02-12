int sx1_i2c_write_byte(u8 devaddr, u8 regoffset, u8 value)
{
struct i2c_adapter *adap;
int err;
struct i2c_msg msg[1];
unsigned char data[2];
adap = i2c_get_adapter(0);
if (!adap)
return -ENODEV;
msg->addr = devaddr;
msg->flags = 0;
msg->len = 2;
msg->buf = data;
data[0] = regoffset;
data[1] = value;
err = i2c_transfer(adap, msg, 1);
i2c_put_adapter(adap);
if (err >= 0)
return 0;
return err;
}
int sx1_i2c_read_byte(u8 devaddr, u8 regoffset, u8 *value)
{
struct i2c_adapter *adap;
int err;
struct i2c_msg msg[1];
unsigned char data[2];
adap = i2c_get_adapter(0);
if (!adap)
return -ENODEV;
msg->addr = devaddr;
msg->flags = 0;
msg->len = 1;
msg->buf = data;
data[0] = regoffset;
err = i2c_transfer(adap, msg, 1);
msg->addr = devaddr;
msg->flags = I2C_M_RD;
msg->len = 1;
msg->buf = data;
err = i2c_transfer(adap, msg, 1);
*value = data[0];
i2c_put_adapter(adap);
if (err >= 0)
return 0;
return err;
}
int sx1_setkeylight(u8 keylight)
{
if (keylight > SOFIA_MAX_LIGHT_VAL)
keylight = SOFIA_MAX_LIGHT_VAL;
return sx1_i2c_write_byte(SOFIA_I2C_ADDR, SOFIA_KEYLIGHT_REG, keylight);
}
int sx1_getkeylight(u8 * keylight)
{
return sx1_i2c_read_byte(SOFIA_I2C_ADDR, SOFIA_KEYLIGHT_REG, keylight);
}
int sx1_setbacklight(u8 backlight)
{
if (backlight > SOFIA_MAX_LIGHT_VAL)
backlight = SOFIA_MAX_LIGHT_VAL;
return sx1_i2c_write_byte(SOFIA_I2C_ADDR, SOFIA_BACKLIGHT_REG,
backlight);
}
int sx1_getbacklight (u8 * backlight)
{
return sx1_i2c_read_byte(SOFIA_I2C_ADDR, SOFIA_BACKLIGHT_REG,
backlight);
}
int sx1_setmmipower(u8 onoff)
{
int err;
u8 dat = 0;
err = sx1_i2c_read_byte(SOFIA_I2C_ADDR, SOFIA_POWER1_REG, &dat);
if (err < 0)
return err;
if (onoff)
dat |= SOFIA_MMILIGHT_POWER;
else
dat &= ~SOFIA_MMILIGHT_POWER;
return sx1_i2c_write_byte(SOFIA_I2C_ADDR, SOFIA_POWER1_REG, dat);
}
int sx1_setusbpower(u8 onoff)
{
int err;
u8 dat = 0;
err = sx1_i2c_read_byte(SOFIA_I2C_ADDR, SOFIA_POWER1_REG, &dat);
if (err < 0)
return err;
if (onoff)
dat |= SOFIA_USB_POWER;
else
dat &= ~SOFIA_USB_POWER;
return sx1_i2c_write_byte(SOFIA_I2C_ADDR, SOFIA_POWER1_REG, dat);
}
static void __init omap_sx1_init(void)
{
omap_cfg_reg(UART1_TX);
omap_cfg_reg(UART1_RTS);
omap_cfg_reg(UART2_TX);
omap_cfg_reg(UART2_RTS);
omap_cfg_reg(UART3_TX);
omap_cfg_reg(UART3_RX);
platform_add_devices(sx1_devices, ARRAY_SIZE(sx1_devices));
omap_board_config = sx1_config;
omap_board_config_size = ARRAY_SIZE(sx1_config);
omap_serial_init();
omap_register_i2c_bus(1, 100, NULL, 0);
omap1_usb_init(&sx1_usb_config);
sx1_mmc_init();
gpio_request(1, "A_IRDA_OFF");
gpio_request(11, "A_SWITCH");
gpio_request(15, "A_USB_ON");
gpio_direction_output(1, 1);
gpio_direction_output(11, 0);
gpio_direction_output(15, 0);
}
static void __init omap_sx1_init_irq(void)
{
omap1_init_common_hw();
omap_init_irq();
}
static void __init omap_sx1_map_io(void)
{
omap1_map_common_io();
}
