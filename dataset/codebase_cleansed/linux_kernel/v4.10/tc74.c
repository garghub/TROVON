static int tc74_update_device(struct device *dev)
{
struct tc74_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int ret;
ret = mutex_lock_interruptible(&data->lock);
if (ret)
return ret;
if (time_after(jiffies, data->next_update) || !data->valid) {
s32 value;
value = i2c_smbus_read_byte_data(client, TC74_REG_CONFIG);
if (value < 0) {
dev_dbg(&client->dev, "TC74_REG_CONFIG read err %d\n",
(int)value);
ret = value;
goto ret_unlock;
}
if (!(value & BIT(6))) {
ret = -EAGAIN;
goto ret_unlock;
}
value = i2c_smbus_read_byte_data(client, TC74_REG_TEMP);
if (value < 0) {
dev_dbg(&client->dev, "TC74_REG_TEMP read err %d\n",
(int)value);
ret = value;
goto ret_unlock;
}
data->temp_input = value;
data->next_update = jiffies + HZ / 4;
data->valid = true;
}
ret_unlock:
mutex_unlock(&data->lock);
return ret;
}
static ssize_t show_temp_input(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct tc74_data *data = dev_get_drvdata(dev);
int ret;
ret = tc74_update_device(dev);
if (ret)
return ret;
return sprintf(buf, "%d\n", data->temp_input * 1000);
}
static int tc74_probe(struct i2c_client *client,
const struct i2c_device_id *dev_id)
{
struct device *dev = &client->dev;
struct tc74_data *data;
struct device *hwmon_dev;
s32 conf;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EOPNOTSUPP;
data = devm_kzalloc(dev, sizeof(struct tc74_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = client;
mutex_init(&data->lock);
conf = i2c_smbus_read_byte_data(client, TC74_REG_CONFIG);
if (conf < 0) {
dev_err(dev, "unable to read config register\n");
return conf;
}
if (conf & 0x3f) {
dev_err(dev, "invalid config register value\n");
return -ENODEV;
}
if (conf & BIT(7)) {
s32 ret;
conf &= ~BIT(7);
ret = i2c_smbus_write_byte_data(client, TC74_REG_CONFIG, conf);
if (ret)
dev_warn(dev, "unable to disable STANDBY\n");
}
hwmon_dev = devm_hwmon_device_register_with_groups(dev,
client->name,
data, tc74_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
