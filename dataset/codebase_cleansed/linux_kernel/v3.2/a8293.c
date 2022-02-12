static int a8293_i2c(struct a8293_priv *priv, u8 *val, int len, bool rd)
{
int ret;
struct i2c_msg msg[1] = {
{
.addr = priv->cfg->i2c_addr,
.len = len,
.buf = val,
}
};
if (rd)
msg[0].flags = I2C_M_RD;
else
msg[0].flags = 0;
ret = i2c_transfer(priv->i2c, msg, 1);
if (ret == 1) {
ret = 0;
} else {
warn("i2c failed=%d rd=%d", ret, rd);
ret = -EREMOTEIO;
}
return ret;
}
static int a8293_wr(struct a8293_priv *priv, u8 *val, int len)
{
return a8293_i2c(priv, val, len, 0);
}
static int a8293_rd(struct a8293_priv *priv, u8 *val, int len)
{
return a8293_i2c(priv, val, len, 1);
}
static int a8293_set_voltage(struct dvb_frontend *fe,
fe_sec_voltage_t fe_sec_voltage)
{
struct a8293_priv *priv = fe->sec_priv;
int ret;
dbg("%s: fe_sec_voltage=%d", __func__, fe_sec_voltage);
switch (fe_sec_voltage) {
case SEC_VOLTAGE_OFF:
priv->reg[0] = 0x10;
break;
case SEC_VOLTAGE_13:
priv->reg[0] = 0x31;
break;
case SEC_VOLTAGE_18:
priv->reg[0] = 0x38;
break;
default:
ret = -EINVAL;
goto err;
};
ret = a8293_wr(priv, &priv->reg[0], 1);
if (ret)
goto err;
return ret;
err:
dbg("%s: failed=%d", __func__, ret);
return ret;
}
static void a8293_release_sec(struct dvb_frontend *fe)
{
dbg("%s:", __func__);
a8293_set_voltage(fe, SEC_VOLTAGE_OFF);
kfree(fe->sec_priv);
fe->sec_priv = NULL;
}
struct dvb_frontend *a8293_attach(struct dvb_frontend *fe,
struct i2c_adapter *i2c, const struct a8293_config *cfg)
{
int ret;
struct a8293_priv *priv = NULL;
u8 buf[2];
priv = kzalloc(sizeof(struct a8293_priv), GFP_KERNEL);
if (priv == NULL) {
ret = -ENOMEM;
goto err;
}
priv->i2c = i2c;
priv->cfg = cfg;
fe->sec_priv = priv;
ret = a8293_rd(priv, buf, 2);
if (ret)
goto err;
priv->reg[0] = 0x10;
ret = a8293_wr(priv, &priv->reg[1], 1);
if (ret)
goto err;
priv->reg[1] = 0x82;
ret = a8293_wr(priv, &priv->reg[1], 1);
if (ret)
goto err;
info("Allegro A8293 SEC attached.");
fe->ops.release_sec = a8293_release_sec;
fe->ops.set_voltage = a8293_set_voltage;
return fe;
err:
dbg("%s: failed=%d", __func__, ret);
kfree(priv);
return NULL;
}
