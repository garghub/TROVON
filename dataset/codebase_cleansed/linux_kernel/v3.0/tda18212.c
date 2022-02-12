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
warn("i2c wr failed ret:%d reg:%02x len:%d", ret, reg, len);
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
warn("i2c rd failed ret:%d reg:%02x len:%d", ret, reg, len);
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
static int tda18212_set_params(struct dvb_frontend *fe,
struct dvb_frontend_parameters *p)
{
struct tda18212_priv *priv = fe->tuner_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int ret, i;
u32 if_khz;
u8 buf[9];
static const u8 bw_params[][3] = {
{ 0xb3, 0x20, 0x03 },
{ 0xb3, 0x31, 0x01 },
{ 0xb3, 0x22, 0x01 },
{ 0x92, 0x53, 0x03 },
};
dbg("%s: delsys=%d RF=%d BW=%d", __func__,
c->delivery_system, c->frequency, c->bandwidth_hz);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
switch (c->delivery_system) {
case SYS_DVBT:
switch (c->bandwidth_hz) {
case 6000000:
if_khz = priv->cfg->if_dvbt_6;
i = 0;
break;
case 7000000:
if_khz = priv->cfg->if_dvbt_7;
i = 1;
break;
case 8000000:
if_khz = priv->cfg->if_dvbt_8;
i = 2;
break;
default:
ret = -EINVAL;
goto error;
}
break;
case SYS_DVBC_ANNEX_AC:
if_khz = priv->cfg->if_dvbc;
i = 3;
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
buf[3] = if_khz / 50;
buf[4] = ((c->frequency / 1000) >> 16) & 0xff;
buf[5] = ((c->frequency / 1000) >> 8) & 0xff;
buf[6] = ((c->frequency / 1000) >> 0) & 0xff;
buf[7] = 0xc1;
buf[8] = 0x01;
ret = tda18212_wr_regs(priv, 0x12, buf, sizeof(buf));
if (ret)
goto error;
exit:
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
return ret;
error:
dbg("%s: failed:%d", __func__, ret);
goto exit;
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
u8 val;
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
dbg("%s: ret:%d chip ID:%02x", __func__, ret, val);
if (ret || val != 0xc7) {
kfree(priv);
return NULL;
}
info("NXP TDA18212HN successfully identified.");
memcpy(&fe->ops.tuner_ops, &tda18212_tuner_ops,
sizeof(struct dvb_tuner_ops));
return fe;
}
