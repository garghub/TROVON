static void tua6100_release(struct dvb_frontend *fe)
{
kfree(fe->tuner_priv);
fe->tuner_priv = NULL;
}
static int tua6100_sleep(struct dvb_frontend *fe)
{
struct tua6100_priv *priv = fe->tuner_priv;
int ret;
u8 reg0[] = { 0x00, 0x00 };
struct i2c_msg msg = { .addr = priv->i2c_address, .flags = 0, .buf = reg0, .len = 2 };
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if ((ret = i2c_transfer (priv->i2c, &msg, 1)) != 1) {
printk("%s: i2c error\n", __func__);
}
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
return (ret == 1) ? 0 : ret;
}
static int tua6100_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct tua6100_priv *priv = fe->tuner_priv;
u32 div;
u32 prediv;
u8 reg0[] = { 0x00, 0x00 };
u8 reg1[] = { 0x01, 0x00, 0x00, 0x00 };
u8 reg2[] = { 0x02, 0x00, 0x00 };
struct i2c_msg msg0 = { .addr = priv->i2c_address, .flags = 0, .buf = reg0, .len = 2 };
struct i2c_msg msg1 = { .addr = priv->i2c_address, .flags = 0, .buf = reg1, .len = 4 };
struct i2c_msg msg2 = { .addr = priv->i2c_address, .flags = 0, .buf = reg2, .len = 3 };
#define _R 4
#define _P 32
#define _ri 4000000
if (c->frequency < 2000000)
reg0[1] = 0x03;
else
reg0[1] = 0x07;
if (c->frequency < 1630000)
reg1[1] = 0x2c;
else
reg1[1] = 0x0c;
if (_P == 64)
reg1[1] |= 0x40;
if (c->frequency >= 1525000)
reg1[1] |= 0x80;
reg2[1] = (_R >> 8) & 0x03;
reg2[2] = _R;
if (c->frequency < 1455000)
reg2[1] |= 0x1c;
else if (c->frequency < 1630000)
reg2[1] |= 0x0c;
else
reg2[1] |= 0x1c;
prediv = (c->frequency * _R) / (_ri / 1000);
div = prediv / _P;
reg1[1] |= (div >> 9) & 0x03;
reg1[2] = div >> 1;
reg1[3] = (div << 7);
priv->frequency = ((div * _P) * (_ri / 1000)) / _R;
reg1[3] |= (prediv - (div*_P)) & 0x7f;
#undef _R
#undef _P
#undef _ri
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(priv->i2c, &msg0, 1) != 1)
return -EIO;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(priv->i2c, &msg2, 1) != 1)
return -EIO;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(priv->i2c, &msg1, 1) != 1)
return -EIO;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
return 0;
}
static int tua6100_get_frequency(struct dvb_frontend *fe, u32 *frequency)
{
struct tua6100_priv *priv = fe->tuner_priv;
*frequency = priv->frequency;
return 0;
}
struct dvb_frontend *tua6100_attach(struct dvb_frontend *fe, int addr, struct i2c_adapter *i2c)
{
struct tua6100_priv *priv = NULL;
u8 b1 [] = { 0x80 };
u8 b2 [] = { 0x00 };
struct i2c_msg msg [] = { { .addr = addr, .flags = 0, .buf = b1, .len = 1 },
{ .addr = addr, .flags = I2C_M_RD, .buf = b2, .len = 1 } };
int ret;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
ret = i2c_transfer (i2c, msg, 2);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
if (ret != 2)
return NULL;
priv = kzalloc(sizeof(struct tua6100_priv), GFP_KERNEL);
if (priv == NULL)
return NULL;
priv->i2c_address = addr;
priv->i2c = i2c;
memcpy(&fe->ops.tuner_ops, &tua6100_tuner_ops, sizeof(struct dvb_tuner_ops));
fe->tuner_priv = priv;
return fe;
}
