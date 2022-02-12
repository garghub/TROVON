static void sendbyte(struct l3_pins *adap, unsigned int byte)
{
int i;
for (i = 0; i < 8; i++) {
adap->setclk(adap, 0);
udelay(adap->data_hold);
adap->setdat(adap, byte & 1);
udelay(adap->data_setup);
adap->setclk(adap, 1);
udelay(adap->clock_high);
byte >>= 1;
}
}
static void sendbytes(struct l3_pins *adap, const u8 *buf,
int len)
{
int i;
for (i = 0; i < len; i++) {
if (i) {
udelay(adap->mode_hold);
adap->setmode(adap, 0);
udelay(adap->mode);
}
adap->setmode(adap, 1);
udelay(adap->mode_setup);
sendbyte(adap, buf[i]);
}
}
int l3_write(struct l3_pins *adap, u8 addr, u8 *data, int len)
{
adap->setclk(adap, 1);
adap->setdat(adap, 1);
adap->setmode(adap, 1);
udelay(adap->mode);
adap->setmode(adap, 0);
udelay(adap->mode_setup);
sendbyte(adap, addr);
udelay(adap->mode_hold);
sendbytes(adap, data, len);
adap->setclk(adap, 1);
adap->setdat(adap, 1);
adap->setmode(adap, 0);
return len;
}
static void l3_set_clk(struct l3_pins *adap, int val)
{
gpio_set_value(adap->gpio_clk, val);
}
static void l3_set_data(struct l3_pins *adap, int val)
{
gpio_set_value(adap->gpio_data, val);
}
static void l3_set_mode(struct l3_pins *adap, int val)
{
gpio_set_value(adap->gpio_mode, val);
}
int l3_set_gpio_ops(struct device *dev, struct l3_pins *adap)
{
int ret;
if (!adap->use_gpios)
return -EINVAL;
ret = devm_gpio_request_one(dev, adap->gpio_data,
GPIOF_OUT_INIT_LOW, "l3_data");
if (ret < 0)
return ret;
adap->setdat = l3_set_data;
ret = devm_gpio_request_one(dev, adap->gpio_clk,
GPIOF_OUT_INIT_LOW, "l3_clk");
if (ret < 0)
return ret;
adap->setclk = l3_set_clk;
ret = devm_gpio_request_one(dev, adap->gpio_mode,
GPIOF_OUT_INIT_LOW, "l3_mode");
if (ret < 0)
return ret;
adap->setmode = l3_set_mode;
return 0;
}
