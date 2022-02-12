static int tda18212_wr_regs(struct tda18212_priv *priv, u8 reg, u8 *val,
int len)
{
int ret;
u8 buf[len+1];
struct i2c_msg msg[1] = {
{
.addr = priv->cfg->i2c_address,
.flags = 0,
.len = sizeof(buf),
.buf = buf,
}
};
buf[0] = reg;
memcpy(&buf[1], val, len);
ret = i2c_transfer(priv->i2c, msg, 1);
if (ret == 1) {
ret = 0;
} else {
dev_warn(&priv->i2c->dev, "%s: i2c wr failed=%d reg=%02x " \
"len=%d\n", KBUILD_MODNAME, ret, reg, len);
ret = -EREMOTEIO;
}
return ret;
}
static int tda18212_rd_regs(struct tda18212_priv *priv, u8 reg, u8 *val,
int len)
{
int ret;
u8 buf[len];
struct i2c_msg msg[2] = {
{
.addr = priv->cfg->i2c_address,
.flags = 0,
.len = 1,
.buf = &reg,
}, {
.addr = priv->cfg->i2c_address,
.flags = I2C_M_RD,
.len = sizeof(buf),
.buf = buf,
}
};
ret = i2c_transfer(priv->i2c, msg, 2);
if (ret == 2) {
memcpy(val, buf, len);
ret = 0;
} else {
dev_warn(&priv->i2c->dev, "%s: i2c rd failed=%d reg=%02x " \
"len=%d\n", KBUILD_MODNAME, ret, reg, len);
ret = -EREMOTEIO;
}
return ret;
}
static int tda18212_wr_reg(struct tda18212_priv *priv, u8 reg, u8 val)
{
return tda18212_wr_regs(priv, reg, &val, 1);
}
static int tda18212_rd_reg(struct tda18212_priv *priv, u8 reg, u8 *val)
{
return tda18212_rd_regs(priv, reg, val, 1);
}
static int tda18212_set_params(struct dvb_frontend *fe)
{
struct tda18212_priv *priv = fe->tuner_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int ret, i;
u32 if_khz;
u8 buf[9];
#define DVBT_6 0
#define DVBT_7 1
#define DVBT_8 2
#define DVBT2_6 3
#define DVBT2_7 4
#define DVBT2_8 5
#define DVBC_6 6
#define DVBC_8 7
static const u8 bw_params[][3] = {
[DVBT_6] = { 0xb3, 0x20, 0x03 },
[DVBT_7] = { 0xb3, 0x31, 0x01 },
[DVBT_8] = { 0xb3, 0x22, 0x01 },
[DVBT2_6] = { 0xbc, 0x20, 0x03 },
[DVBT2_7] = { 0xbc, 0x72, 0x03 },
[DVBT2_8] = { 0xbc, 0x22, 0x01 },
[DVBC_6] = { 0x92, 0x50, 0x03 },
[DVBC_8] = { 0x92, 0x53, 0x03 },
};
dev_dbg(&priv->i2c->dev,
"%s: delivery_system=%d frequency=%d bandwidth_hz=%d\n",
__func__, c->delivery_system, c->frequency,
c->bandwidth_hz);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
switch (c->delivery_system) {
case SYS_DVBT:
switch (c->bandwidth_hz) {
case 6000000:
if_khz = priv->cfg->if_dvbt_6;
i = DVBT_6;
break;
case 7000000:
if_khz = priv->cfg->if_dvbt_7;
i = DVBT_7;
break;
case 8000000:
if_khz = priv->cfg->if_dvbt_8;
i = DVBT_8;
break;
default:
ret = -EINVAL;
goto error;
}
break;
case SYS_DVBT2:
switch (c->bandwidth_hz) {
case 6000000:
if_khz = priv->cfg->if_dvbt2_6;
i = DVBT2_6;
break;
case 7000000:
if_khz = priv->cfg->if_dvbt2_7;
i = DVBT2_7;
break;
case 8000000:
if_khz = priv->cfg->if_dvbt2_8;
i = DVBT2_8;
break;
default:
ret = -EINVAL;
goto error;
}
break;
case SYS_DVBC_ANNEX_A:
case SYS_DVBC_ANNEX_C:
if_khz = priv->cfg->if_dvbc;
i = DVBC_8;
break;
default:
ret = -EINVAL;
goto error;
}
ret = tda18212_wr_reg(priv, 0x23, bw_params[i][2]);
if (ret)
goto error;
ret = tda18212_wr_reg(priv, 0x06, 0x00);
if (ret)
goto error;
ret = tda18212_wr_reg(priv, 0x0f, bw_params[i][0]);
if (ret)
goto error;
buf[0] = 0x02;
buf[1] = bw_params[i][1];
buf[2] = 0x03;
buf[3] = DIV_ROUND_CLOSEST(if_khz, 50);
buf[4] = ((c->frequency / 1000) >> 16) & 0xff;
buf[5] = ((c->frequency / 1000) >> 8) & 0xff;
buf[6] = ((c->frequency / 1000) >> 0) & 0xff;
buf[7] = 0xc1;
buf[8] = 0x01;
ret = tda18212_wr_regs(priv, 0x12, buf, sizeof(buf));
if (ret)
goto error;
priv->if_frequency = buf[3] * 50 * 1000;
exit:
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
return ret;
error:
dev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);
goto exit;
}
static int tda18212_get_if_frequency(struct dvb_frontend *fe, u32 *frequency)
{
struct tda18212_priv *priv = fe->tuner_priv;
*frequency = priv->if_frequency;
return 0;
}
static int tda18212_release(struct dvb_frontend *fe)
{
kfree(fe->tuner_priv);
fe->tuner_priv = NULL;
return 0;
}
struct dvb_frontend *tda18212_attach(struct dvb_frontend *fe,
struct i2c_adapter *i2c, struct tda18212_config *cfg)
{
struct tda18212_priv *priv = NULL;
int ret;
u8 uninitialized_var(val);
priv = kzalloc(sizeof(struct tda18212_priv), GFP_KERNEL);
if (priv == NULL)
return NULL;
priv->cfg = cfg;
priv->i2c = i2c;
fe->tuner_priv = priv;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
ret = tda18212_rd_reg(priv, 0x00, &val);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
dev_dbg(&priv->i2c->dev, "%s: ret=%d chip id=%02x\n", __func__, ret,
val);
if (ret || val != 0xc7) {
kfree(priv);
return NULL;
}
dev_info(&priv->i2c->dev,
"%s: NXP TDA18212HN successfully identified\n",
KBUILD_MODNAME);
memcpy(&fe->ops.tuner_ops, &tda18212_tuner_ops,
sizeof(struct dvb_tuner_ops));
return fe;
}
