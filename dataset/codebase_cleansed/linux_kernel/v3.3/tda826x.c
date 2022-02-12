static int tda826x_release(struct dvb_frontend *fe)
{
kfree(fe->tuner_priv);
fe->tuner_priv = NULL;
return 0;
}
static int tda826x_sleep(struct dvb_frontend *fe)
{
struct tda826x_priv *priv = fe->tuner_priv;
int ret;
u8 buf [] = { 0x00, 0x8d };
struct i2c_msg msg = { .addr = priv->i2c_address, .flags = 0, .buf = buf, .len = 2 };
dprintk("%s:\n", __func__);
if (!priv->has_loopthrough)
buf[1] = 0xad;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if ((ret = i2c_transfer (priv->i2c, &msg, 1)) != 1) {
dprintk("%s: i2c error\n", __func__);
}
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
return (ret == 1) ? 0 : ret;
}
static int tda826x_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct tda826x_priv *priv = fe->tuner_priv;
int ret;
u32 div;
u32 ksyms;
u32 bandwidth;
u8 buf [11];
struct i2c_msg msg = { .addr = priv->i2c_address, .flags = 0, .buf = buf, .len = 11 };
dprintk("%s:\n", __func__);
div = (p->frequency + (1000-1)) / 1000;
ksyms = p->symbol_rate / 1000;
bandwidth = (878 * ksyms + 6500000) / 1000000 + 1;
if (bandwidth < 5)
bandwidth = 5;
else if (bandwidth > 36)
bandwidth = 36;
buf[0] = 0x00;
buf[1] = 0x09;
if (!priv->has_loopthrough)
buf[1] |= 0x20;
buf[2] = (1<<5) | 0x0b;
buf[3] = div >> 7;
buf[4] = div << 1;
buf[5] = ((bandwidth - 5) << 3) | 7;
buf[6] = 0xfe;
buf[7] = 0x83;
buf[8] = 0x80;
buf[9] = 0x1a;
buf[10] = 0xd4;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if ((ret = i2c_transfer (priv->i2c, &msg, 1)) != 1) {
dprintk("%s: i2c error\n", __func__);
}
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
priv->frequency = div * 1000;
return (ret == 1) ? 0 : ret;
}
static int tda826x_get_frequency(struct dvb_frontend *fe, u32 *frequency)
{
struct tda826x_priv *priv = fe->tuner_priv;
*frequency = priv->frequency;
return 0;
}
struct dvb_frontend *tda826x_attach(struct dvb_frontend *fe, int addr, struct i2c_adapter *i2c, int has_loopthrough)
{
struct tda826x_priv *priv = NULL;
u8 b1 [] = { 0, 0 };
struct i2c_msg msg[2] = {
{ .addr = addr, .flags = 0, .buf = NULL, .len = 0 },
{ .addr = addr, .flags = I2C_M_RD, .buf = b1, .len = 2 }
};
int ret;
dprintk("%s:\n", __func__);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
ret = i2c_transfer (i2c, msg, 2);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
if (ret != 2)
return NULL;
if (!(b1[1] & 0x80))
return NULL;
priv = kzalloc(sizeof(struct tda826x_priv), GFP_KERNEL);
if (priv == NULL)
return NULL;
priv->i2c_address = addr;
priv->i2c = i2c;
priv->has_loopthrough = has_loopthrough;
memcpy(&fe->ops.tuner_ops, &tda826x_tuner_ops, sizeof(struct dvb_tuner_ops));
fe->tuner_priv = priv;
return fe;
}
