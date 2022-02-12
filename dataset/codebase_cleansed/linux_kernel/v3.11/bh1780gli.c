static int bh1780_write(struct bh1780_data *ddata, u8 reg, u8 val, char *msg)
{
int ret = i2c_smbus_write_byte_data(ddata->client, reg, val);
if (ret < 0)
dev_err(&ddata->client->dev,
"i2c_smbus_write_byte_data failed error %d Register (%s)\n",
ret, msg);
return ret;
}
static int bh1780_read(struct bh1780_data *ddata, u8 reg, char *msg)
{
int ret = i2c_smbus_read_byte_data(ddata->client, reg);
if (ret < 0)
dev_err(&ddata->client->dev,
"i2c_smbus_read_byte_data failed error %d Register (%s)\n",
ret, msg);
return ret;
}
static ssize_t bh1780_show_lux(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct bh1780_data *ddata = platform_get_drvdata(pdev);
int lsb, msb;
lsb = bh1780_read(ddata, BH1780_REG_DLOW, "DLOW");
if (lsb < 0)
return lsb;
msb = bh1780_read(ddata, BH1780_REG_DHIGH, "DHIGH");
if (msb < 0)
return msb;
return sprintf(buf, "%d\n", (msb << 8) | lsb);
}
static ssize_t bh1780_show_power_state(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct bh1780_data *ddata = platform_get_drvdata(pdev);
int state;
state = bh1780_read(ddata, BH1780_REG_CONTROL, "CONTROL");
if (state < 0)
return state;
return sprintf(buf, "%d\n", state & BH1780_POWMASK);
}
static ssize_t bh1780_store_power_state(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct platform_device *pdev = to_platform_device(dev);
struct bh1780_data *ddata = platform_get_drvdata(pdev);
unsigned long val;
int error;
error = kstrtoul(buf, 0, &val);
if (error)
return error;
if (val < BH1780_POFF || val > BH1780_PON)
return -EINVAL;
mutex_lock(&ddata->lock);
error = bh1780_write(ddata, BH1780_REG_CONTROL, val, "CONTROL");
if (error < 0) {
mutex_unlock(&ddata->lock);
return error;
}
msleep(BH1780_PON_DELAY);
ddata->power_state = val;
mutex_unlock(&ddata->lock);
return count;
}
static int bh1780_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct bh1780_data *ddata = NULL;
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE)) {
ret = -EIO;
goto err_op_failed;
}
ddata = kzalloc(sizeof(struct bh1780_data), GFP_KERNEL);
if (ddata == NULL) {
ret = -ENOMEM;
goto err_op_failed;
}
ddata->client = client;
i2c_set_clientdata(client, ddata);
ret = bh1780_read(ddata, BH1780_REG_PARTID, "PART ID");
if (ret < 0)
goto err_op_failed;
dev_info(&client->dev, "Ambient Light Sensor, Rev : %d\n",
(ret & BH1780_REVMASK));
mutex_init(&ddata->lock);
ret = sysfs_create_group(&client->dev.kobj, &bh1780_attr_group);
if (ret)
goto err_op_failed;
return 0;
err_op_failed:
kfree(ddata);
return ret;
}
static int bh1780_remove(struct i2c_client *client)
{
struct bh1780_data *ddata;
ddata = i2c_get_clientdata(client);
sysfs_remove_group(&client->dev.kobj, &bh1780_attr_group);
kfree(ddata);
return 0;
}
static int bh1780_suspend(struct device *dev)
{
struct bh1780_data *ddata;
int state, ret;
struct i2c_client *client = to_i2c_client(dev);
ddata = i2c_get_clientdata(client);
state = bh1780_read(ddata, BH1780_REG_CONTROL, "CONTROL");
if (state < 0)
return state;
ddata->power_state = state & BH1780_POWMASK;
ret = bh1780_write(ddata, BH1780_REG_CONTROL, BH1780_POFF,
"CONTROL");
if (ret < 0)
return ret;
return 0;
}
static int bh1780_resume(struct device *dev)
{
struct bh1780_data *ddata;
int state, ret;
struct i2c_client *client = to_i2c_client(dev);
ddata = i2c_get_clientdata(client);
state = ddata->power_state;
ret = bh1780_write(ddata, BH1780_REG_CONTROL, state,
"CONTROL");
if (ret < 0)
return ret;
return 0;
}
