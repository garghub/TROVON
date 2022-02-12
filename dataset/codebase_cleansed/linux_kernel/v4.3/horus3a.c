static void horus3a_i2c_debug(struct horus3a_priv *priv,
u8 reg, u8 write, const u8 *data, u32 len)
{
dev_dbg(&priv->i2c->dev, "horus3a: I2C %s reg 0x%02x size %d\n",
(write == 0 ? "read" : "write"), reg, len);
print_hex_dump_bytes("horus3a: I2C data: ",
DUMP_PREFIX_OFFSET, data, len);
}
static int horus3a_write_regs(struct horus3a_priv *priv,
u8 reg, const u8 *data, u32 len)
{
int ret;
u8 buf[MAX_WRITE_REGSIZE + 1];
struct i2c_msg msg[1] = {
{
.addr = priv->i2c_address,
.flags = 0,
.len = len + 1,
.buf = buf,
}
};
if (len + 1 >= sizeof(buf)) {
dev_warn(&priv->i2c->dev,"wr reg=%04x: len=%d is too big!\n",
reg, len + 1);
return -E2BIG;
}
horus3a_i2c_debug(priv, reg, 1, data, len);
buf[0] = reg;
memcpy(&buf[1], data, len);
ret = i2c_transfer(priv->i2c, msg, 1);
if (ret >= 0 && ret != 1)
ret = -EREMOTEIO;
if (ret < 0) {
dev_warn(&priv->i2c->dev,
"%s: i2c wr failed=%d reg=%02x len=%d\n",
KBUILD_MODNAME, ret, reg, len);
return ret;
}
return 0;
}
static int horus3a_write_reg(struct horus3a_priv *priv, u8 reg, u8 val)
{
return horus3a_write_regs(priv, reg, &val, 1);
}
static int horus3a_enter_power_save(struct horus3a_priv *priv)
{
u8 data[2];
dev_dbg(&priv->i2c->dev, "%s()\n", __func__);
if (priv->state == STATE_SLEEP)
return 0;
horus3a_write_reg(priv, 0x2a, 0x79);
horus3a_write_reg(priv, 0x29, 0x70);
horus3a_write_reg(priv, 0x28, 0x3e);
horus3a_write_reg(priv, 0x2a, 0x19);
horus3a_write_reg(priv, 0x1c, 0x00);
data[0] = 0xC0;
data[1] = 0xA7;
horus3a_write_regs(priv, 0x11, data, sizeof(data));
priv->state = STATE_SLEEP;
return 0;
}
static int horus3a_leave_power_save(struct horus3a_priv *priv)
{
u8 data[2];
dev_dbg(&priv->i2c->dev, "%s()\n", __func__);
if (priv->state == STATE_ACTIVE)
return 0;
data[0] = 0x00;
data[1] = 0xa7;
horus3a_write_regs(priv, 0x11, data, sizeof(data));
horus3a_write_reg(priv, 0x2a, 0x79);
horus3a_write_reg(priv, 0x1c, 0xc0);
horus3a_write_reg(priv, 0x29, 0x71);
usleep_range(5000, 7000);
priv->state = STATE_ACTIVE;
return 0;
}
static int horus3a_init(struct dvb_frontend *fe)
{
struct horus3a_priv *priv = fe->tuner_priv;
dev_dbg(&priv->i2c->dev, "%s()\n", __func__);
return 0;
}
static int horus3a_release(struct dvb_frontend *fe)
{
struct horus3a_priv *priv = fe->tuner_priv;
dev_dbg(&priv->i2c->dev, "%s()\n", __func__);
kfree(fe->tuner_priv);
fe->tuner_priv = NULL;
return 0;
}
static int horus3a_sleep(struct dvb_frontend *fe)
{
struct horus3a_priv *priv = fe->tuner_priv;
dev_dbg(&priv->i2c->dev, "%s()\n", __func__);
horus3a_enter_power_save(priv);
return 0;
}
static int horus3a_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct horus3a_priv *priv = fe->tuner_priv;
u32 frequency = p->frequency;
u32 symbol_rate = p->symbol_rate/1000;
u8 mixdiv = 0;
u8 mdiv = 0;
u32 ms = 0;
u8 f_ctl = 0;
u8 g_ctl = 0;
u8 fc_lpf = 0;
u8 data[5];
dev_dbg(&priv->i2c->dev, "%s(): frequency %dkHz symbol_rate %dksps\n",
__func__, frequency, symbol_rate);
if (priv->set_tuner)
priv->set_tuner(priv->set_tuner_data, 0);
if (priv->state == STATE_SLEEP)
horus3a_leave_power_save(priv);
frequency = DIV_ROUND_CLOSEST(frequency, 1000) * 1000;
if (frequency <= 1155000) {
mixdiv = 4;
mdiv = 1;
} else {
mixdiv = 2;
mdiv = 0;
}
ms = DIV_ROUND_CLOSEST((frequency * mixdiv) / 2, 1000);
if (ms > 0x7FFF) {
dev_err(&priv->i2c->dev, "horus3a: invalid frequency %d\n",
frequency);
return -EINVAL;
}
if (frequency < 975000) {
f_ctl = 0x1C;
g_ctl = 0x01;
} else if (frequency < 1050000) {
f_ctl = 0x18;
g_ctl = 0x02;
} else if (frequency < 1150000) {
f_ctl = 0x14;
g_ctl = 0x02;
} else if (frequency < 1250000) {
f_ctl = 0x10;
g_ctl = 0x03;
} else if (frequency < 1350000) {
f_ctl = 0x0C;
g_ctl = 0x04;
} else if (frequency < 1450000) {
f_ctl = 0x0A;
g_ctl = 0x04;
} else if (frequency < 1600000) {
f_ctl = 0x07;
g_ctl = 0x05;
} else if (frequency < 1800000) {
f_ctl = 0x04;
g_ctl = 0x02;
} else if (frequency < 2000000) {
f_ctl = 0x02;
g_ctl = 0x01;
} else {
f_ctl = 0x00;
g_ctl = 0x00;
}
if (p->delivery_system == SYS_DVBS) {
if (symbol_rate <= 4300)
fc_lpf = 5;
else if (symbol_rate <= 10000)
fc_lpf = (u8)DIV_ROUND_UP(symbol_rate * 47, 40000);
else
fc_lpf = (u8)DIV_ROUND_UP(symbol_rate * 27, 40000) + 5;
if (fc_lpf > 36)
fc_lpf = 36;
} else if (p->delivery_system == SYS_DVBS2) {
int rolloff;
switch (p->rolloff) {
case ROLLOFF_35:
rolloff = 35;
break;
case ROLLOFF_25:
rolloff = 25;
break;
case ROLLOFF_20:
rolloff = 20;
break;
case ROLLOFF_AUTO:
default:
dev_err(&priv->i2c->dev,
"horus3a: auto roll-off is not supported\n");
return -EINVAL;
}
if (symbol_rate <= 4500)
fc_lpf = 5;
else if (symbol_rate <= 10000)
fc_lpf = (u8)DIV_ROUND_UP(
symbol_rate * (200 + rolloff), 200000);
else
fc_lpf = (u8)DIV_ROUND_UP(
symbol_rate * (100 + rolloff), 200000) + 5;
if (fc_lpf > 36)
fc_lpf = 36;
} else {
dev_err(&priv->i2c->dev,
"horus3a: invalid delivery system %d\n",
p->delivery_system);
return -EINVAL;
}
data[0] = (u8)((ms >> 7) & 0xFF);
data[1] = (u8)((ms << 1) & 0xFF);
data[2] = 0x00;
data[3] = 0x00;
data[4] = (u8)(mdiv << 7);
horus3a_write_regs(priv, 0x00, data, sizeof(data));
horus3a_write_reg(priv, 0x09, (u8)((g_ctl << 5) | f_ctl));
horus3a_write_reg(priv, 0x37, (u8)(0x80 | (fc_lpf << 1)));
horus3a_write_reg(priv, 0x05, 0x80);
horus3a_write_reg(priv, 0x2a, 0x7b);
msleep(60);
priv->frequency = ms * 2 * 1000 / mixdiv;
return 0;
}
static int horus3a_get_frequency(struct dvb_frontend *fe, u32 *frequency)
{
struct horus3a_priv *priv = fe->tuner_priv;
*frequency = priv->frequency;
return 0;
}
struct dvb_frontend *horus3a_attach(struct dvb_frontend *fe,
const struct horus3a_config *config,
struct i2c_adapter *i2c)
{
u8 buf[3], val;
struct horus3a_priv *priv = NULL;
priv = kzalloc(sizeof(struct horus3a_priv), GFP_KERNEL);
if (priv == NULL)
return NULL;
priv->i2c_address = (config->i2c_address >> 1);
priv->i2c = i2c;
priv->set_tuner_data = config->set_tuner_priv;
priv->set_tuner = config->set_tuner_callback;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
usleep_range(4000, 6000);
horus3a_write_reg(priv, 0x2a, 0x79);
buf[0] = config->xtal_freq_mhz;
buf[1] = config->xtal_freq_mhz;
buf[2] = 0;
horus3a_write_regs(priv, 0x6, buf, 3);
horus3a_write_reg(priv, 0x0a, 0x40);
switch (config->xtal_freq_mhz) {
case 27:
val = 0x1f;
break;
case 24:
val = 0x10;
break;
case 16:
val = 0xc;
break;
default:
val = 0;
dev_warn(&priv->i2c->dev,
"horus3a: invalid xtal frequency %dMHz\n",
config->xtal_freq_mhz);
break;
}
val <<= 2;
horus3a_write_reg(priv, 0x0e, val);
horus3a_enter_power_save(priv);
usleep_range(3000, 5000);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
memcpy(&fe->ops.tuner_ops, &horus3a_tuner_ops,
sizeof(struct dvb_tuner_ops));
fe->tuner_priv = priv;
dev_info(&priv->i2c->dev,
"Sony HORUS3A attached on addr=%x at I2C adapter %p\n",
priv->i2c_address, priv->i2c);
return fe;
}
