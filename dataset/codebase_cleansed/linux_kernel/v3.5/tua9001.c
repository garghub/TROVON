static int tua9001_wr_reg(struct tua9001_priv *priv, u8 reg, u16 val)
{
int ret;
u8 buf[3] = { reg, (val >> 8) & 0xff, (val >> 0) & 0xff };
struct i2c_msg msg[1] = {
{
.addr = priv->cfg->i2c_addr,
.flags = 0,
.len = sizeof(buf),
.buf = buf,
}
};
ret = i2c_transfer(priv->i2c, msg, 1);
if (ret == 1) {
ret = 0;
} else {
printk(KERN_WARNING "%s: I2C wr failed=%d reg=%02x\n",
__func__, ret, reg);
ret = -EREMOTEIO;
}
return ret;
}
static int tua9001_release(struct dvb_frontend *fe)
{
kfree(fe->tuner_priv);
fe->tuner_priv = NULL;
return 0;
}
static int tua9001_init(struct dvb_frontend *fe)
{
struct tua9001_priv *priv = fe->tuner_priv;
int ret = 0;
u8 i;
struct reg_val data[] = {
{ 0x1e, 0x6512 },
{ 0x25, 0xb888 },
{ 0x39, 0x5460 },
{ 0x3b, 0x00c0 },
{ 0x3a, 0xf000 },
{ 0x08, 0x0000 },
{ 0x32, 0x0030 },
{ 0x41, 0x703a },
{ 0x40, 0x1c78 },
{ 0x2c, 0x1c00 },
{ 0x36, 0xc013 },
{ 0x37, 0x6f18 },
{ 0x27, 0x0008 },
{ 0x2a, 0x0001 },
{ 0x34, 0x0a40 },
};
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
for (i = 0; i < ARRAY_SIZE(data); i++) {
ret = tua9001_wr_reg(priv, data[i].reg, data[i].val);
if (ret)
break;
}
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
if (ret < 0)
pr_debug("%s: failed=%d\n", __func__, ret);
return ret;
}
static int tua9001_set_params(struct dvb_frontend *fe)
{
struct tua9001_priv *priv = fe->tuner_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int ret, i;
u16 val;
u32 frequency;
struct reg_val data[2];
pr_debug("%s: delivery_system=%d frequency=%d bandwidth_hz=%d\n",
__func__, c->delivery_system, c->frequency,
c->bandwidth_hz);
switch (c->delivery_system) {
case SYS_DVBT:
switch (c->bandwidth_hz) {
case 8000000:
val = 0x0000;
break;
case 7000000:
val = 0x1000;
break;
case 6000000:
val = 0x2000;
break;
case 5000000:
val = 0x3000;
break;
default:
ret = -EINVAL;
goto err;
}
break;
default:
ret = -EINVAL;
goto err;
}
data[0].reg = 0x04;
data[0].val = val;
frequency = (c->frequency - 150000000);
frequency /= 100;
frequency *= 48;
frequency /= 10000;
data[1].reg = 0x1f;
data[1].val = frequency;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
for (i = 0; i < ARRAY_SIZE(data); i++) {
ret = tua9001_wr_reg(priv, data[i].reg, data[i].val);
if (ret < 0)
break;
}
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
err:
if (ret < 0)
pr_debug("%s: failed=%d\n", __func__, ret);
return ret;
}
static int tua9001_get_if_frequency(struct dvb_frontend *fe, u32 *frequency)
{
*frequency = 0;
return 0;
}
struct dvb_frontend *tua9001_attach(struct dvb_frontend *fe,
struct i2c_adapter *i2c, struct tua9001_config *cfg)
{
struct tua9001_priv *priv = NULL;
priv = kzalloc(sizeof(struct tua9001_priv), GFP_KERNEL);
if (priv == NULL)
return NULL;
priv->cfg = cfg;
priv->i2c = i2c;
printk(KERN_INFO "Infineon TUA 9001 successfully attached.");
memcpy(&fe->ops.tuner_ops, &tua9001_tuner_ops,
sizeof(struct dvb_tuner_ops));
fe->tuner_priv = priv;
return fe;
}
