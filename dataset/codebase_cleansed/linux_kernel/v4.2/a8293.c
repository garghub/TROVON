static int a8293_i2c(struct a8293_priv *priv, u8 *val, int len, bool rd)
{
int ret;
struct i2c_msg msg[1] = {
{
.addr = priv->i2c_addr,
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
dev_warn(&priv->i2c->dev, "%s: i2c failed=%d rd=%d\n",
KBUILD_MODNAME, ret, rd);
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
enum fe_sec_voltage fe_sec_voltage)
{
struct a8293_priv *priv = fe->sec_priv;
int ret;
dev_dbg(&priv->i2c->dev, "%s: fe_sec_voltage=%d\n", __func__,
fe_sec_voltage);
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
}
ret = a8293_wr(priv, &priv->reg[0], 1);
if (ret)
goto err;
usleep_range(1500, 50000);
return ret;
err:
dev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static void a8293_release_sec(struct dvb_frontend *fe)
{
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
priv->i2c_addr = cfg->i2c_addr;
fe->sec_priv = priv;
ret = a8293_rd(priv, buf, 2);
if (ret)
goto err;
priv->reg[0] = 0x10;
ret = a8293_wr(priv, &priv->reg[0], 1);
if (ret)
goto err;
priv->reg[1] = 0x82;
ret = a8293_wr(priv, &priv->reg[1], 1);
if (ret)
goto err;
fe->ops.release_sec = a8293_release_sec;
fe->ops.set_voltage = a8293_set_voltage;
dev_info(&priv->i2c->dev, "%s: Allegro A8293 SEC attached\n",
KBUILD_MODNAME);
return fe;
err:
dev_dbg(&i2c->dev, "%s: failed=%d\n", __func__, ret);
kfree(priv);
return NULL;
}
static int a8293_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct a8293_priv *dev;
struct a8293_platform_data *pdata = client->dev.platform_data;
struct dvb_frontend *fe = pdata->dvb_frontend;
int ret;
u8 buf[2];
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) {
ret = -ENOMEM;
goto err;
}
dev->client = client;
dev->i2c = client->adapter;
dev->i2c_addr = client->addr;
ret = a8293_rd(dev, buf, 2);
if (ret)
goto err_kfree;
dev->reg[0] = 0x10;
ret = a8293_wr(dev, &dev->reg[0], 1);
if (ret)
goto err_kfree;
dev->reg[1] = 0x82;
ret = a8293_wr(dev, &dev->reg[1], 1);
if (ret)
goto err_kfree;
fe->ops.set_voltage = a8293_set_voltage;
fe->sec_priv = dev;
i2c_set_clientdata(client, dev);
dev_info(&client->dev, "Allegro A8293 SEC successfully attached\n");
return 0;
err_kfree:
kfree(dev);
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int a8293_remove(struct i2c_client *client)
{
struct a8293_dev *dev = i2c_get_clientdata(client);
dev_dbg(&client->dev, "\n");
kfree(dev);
return 0;
}
