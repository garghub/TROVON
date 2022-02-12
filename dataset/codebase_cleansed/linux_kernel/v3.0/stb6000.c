static int stb6000_release(struct dvb_frontend *fe)
{
kfree(fe->tuner_priv);
fe->tuner_priv = NULL;
return 0;
}
static int stb6000_sleep(struct dvb_frontend *fe)
{
struct stb6000_priv *priv = fe->tuner_priv;
int ret;
u8 buf[] = { 10, 0 };
struct i2c_msg msg = {
.addr = priv->i2c_address,
.flags = 0,
.buf = buf,
.len = 2
};
dprintk("%s:\n", __func__);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
ret = i2c_transfer(priv->i2c, &msg, 1);
if (ret != 1)
dprintk("%s: i2c error\n", __func__);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
return (ret == 1) ? 0 : ret;
}
static int stb6000_set_params(struct dvb_frontend *fe,
struct dvb_frontend_parameters *params)
{
struct stb6000_priv *priv = fe->tuner_priv;
unsigned int n, m;
int ret;
u32 freq_mhz;
int bandwidth;
u8 buf[12];
struct i2c_msg msg = {
.addr = priv->i2c_address,
.flags = 0,
.buf = buf,
.len = 12
};
dprintk("%s:\n", __func__);
freq_mhz = params->frequency / 1000;
bandwidth = params->u.qpsk.symbol_rate / 1000000;
if (bandwidth > 31)
bandwidth = 31;
if ((freq_mhz > 949) && (freq_mhz < 2151)) {
buf[0] = 0x01;
buf[1] = 0xac;
if (freq_mhz < 1950)
buf[1] = 0xaa;
if (freq_mhz < 1800)
buf[1] = 0xa8;
if (freq_mhz < 1650)
buf[1] = 0xa6;
if (freq_mhz < 1530)
buf[1] = 0xa5;
if (freq_mhz < 1470)
buf[1] = 0xa4;
if (freq_mhz < 1370)
buf[1] = 0xa2;
if (freq_mhz < 1300)
buf[1] = 0xa1;
if (freq_mhz < 1200)
buf[1] = 0xa0;
if (freq_mhz < 1075)
buf[1] = 0xbc;
if (freq_mhz < 1000)
buf[1] = 0xba;
if (freq_mhz < 1075) {
n = freq_mhz / 8;
m = 2;
} else {
n = freq_mhz / 16;
m = 1;
}
buf[2] = n >> 1;
buf[3] = (unsigned char)(((n & 1) << 7) |
(m * freq_mhz - n * 16) | 0x60);
buf[4] = 0x04;
buf[5] = 0x0e;
buf[6] = (unsigned char)(bandwidth);
buf[7] = 0xd8;
buf[8] = 0xd0;
buf[9] = 0x50;
buf[10] = 0xeb;
buf[11] = 0x4f;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
ret = i2c_transfer(priv->i2c, &msg, 1);
if (ret != 1)
dprintk("%s: i2c error\n", __func__);
udelay(10);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
buf[0] = 0x07;
buf[1] = 0xdf;
buf[2] = 0xd0;
buf[3] = 0x50;
buf[4] = 0xfb;
msg.len = 5;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
ret = i2c_transfer(priv->i2c, &msg, 1);
if (ret != 1)
dprintk("%s: i2c error\n", __func__);
udelay(10);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
priv->frequency = freq_mhz * 1000;
return (ret == 1) ? 0 : ret;
}
return -1;
}
static int stb6000_get_frequency(struct dvb_frontend *fe, u32 *frequency)
{
struct stb6000_priv *priv = fe->tuner_priv;
*frequency = priv->frequency;
return 0;
}
struct dvb_frontend *stb6000_attach(struct dvb_frontend *fe, int addr,
struct i2c_adapter *i2c)
{
struct stb6000_priv *priv = NULL;
u8 b0[] = { 0 };
u8 b1[] = { 0, 0 };
struct i2c_msg msg[2] = {
{
.addr = addr,
.flags = 0,
.buf = b0,
.len = 0
}, {
.addr = addr,
.flags = I2C_M_RD,
.buf = b1,
.len = 2
}
};
int ret;
dprintk("%s:\n", __func__);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
ret = i2c_transfer(i2c, msg, 2);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
if (ret != 2)
return NULL;
priv = kzalloc(sizeof(struct stb6000_priv), GFP_KERNEL);
if (priv == NULL)
return NULL;
priv->i2c_address = addr;
priv->i2c = i2c;
memcpy(&fe->ops.tuner_ops, &stb6000_tuner_ops,
sizeof(struct dvb_tuner_ops));
fe->tuner_priv = priv;
return fe;
}
