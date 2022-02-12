static int a8293_set_voltage(struct dvb_frontend *fe,
enum fe_sec_voltage fe_sec_voltage)
{
struct a8293_dev *dev = fe->sec_priv;
struct i2c_client *client = dev->client;
int ret;
u8 reg0, reg1;
dev_dbg(&client->dev, "fe_sec_voltage=%d\n", fe_sec_voltage);
switch (fe_sec_voltage) {
case SEC_VOLTAGE_OFF:
reg0 = 0x10;
break;
case SEC_VOLTAGE_13:
reg0 = 0x31;
break;
case SEC_VOLTAGE_18:
reg0 = 0x38;
break;
default:
ret = -EINVAL;
goto err;
}
if (reg0 != dev->reg[0]) {
ret = i2c_master_send(client, &reg0, 1);
if (ret < 0)
goto err;
dev->reg[0] = reg0;
}
reg1 = 0x82;
if (reg1 != dev->reg[1]) {
ret = i2c_master_send(client, &reg1, 1);
if (ret < 0)
goto err;
dev->reg[1] = reg1;
}
usleep_range(1500, 50000);
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int a8293_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct a8293_dev *dev;
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
ret = i2c_master_recv(client, buf, 2);
if (ret < 0)
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
