static void ad7418_init_client(struct i2c_client *client)
{
struct ad7418_data *data = i2c_get_clientdata(client);
int reg = i2c_smbus_read_byte_data(client, AD7418_REG_CONF);
if (reg < 0) {
dev_err(&client->dev, "cannot read configuration register\n");
} else {
dev_info(&client->dev, "configuring for mode 1\n");
i2c_smbus_write_byte_data(client, AD7418_REG_CONF, reg & 0xfe);
if (data->type == ad7417 || data->type == ad7418)
i2c_smbus_write_byte_data(client,
AD7418_REG_CONF2, 0x00);
}
}
static struct ad7418_data *ad7418_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct ad7418_data *data = i2c_get_clientdata(client);
mutex_lock(&data->lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
u8 cfg;
int i, ch;
cfg = i2c_smbus_read_byte_data(client, AD7418_REG_CONF);
cfg &= 0x1F;
i2c_smbus_write_byte_data(client, AD7418_REG_CONF,
cfg | AD7418_CH_TEMP);
udelay(30);
for (i = 0; i < 3; i++) {
data->temp[i] =
i2c_smbus_read_word_swapped(client,
AD7418_REG_TEMP[i]);
}
for (i = 0, ch = 4; i < data->adc_max; i++, ch--) {
i2c_smbus_write_byte_data(client,
AD7418_REG_CONF,
cfg | AD7418_REG_ADC_CH(ch));
udelay(15);
data->in[data->adc_max - 1 - i] =
i2c_smbus_read_word_swapped(client,
AD7418_REG_ADC);
}
i2c_smbus_write_word_swapped(client, AD7418_REG_CONF, cfg);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->lock);
return data;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct ad7418_data *data = ad7418_update_device(dev);
return sprintf(buf, "%d\n",
LM75_TEMP_FROM_REG(data->temp[attr->index]));
}
static ssize_t show_adc(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct ad7418_data *data = ad7418_update_device(dev);
return sprintf(buf, "%d\n",
((data->in[attr->index] >> 6) * 2500 + 512) / 1024);
}
static ssize_t set_temp(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct i2c_client *client = to_i2c_client(dev);
struct ad7418_data *data = i2c_get_clientdata(client);
long temp;
int ret = kstrtol(buf, 10, &temp);
if (ret < 0)
return ret;
mutex_lock(&data->lock);
data->temp[attr->index] = LM75_TEMP_TO_REG(temp);
i2c_smbus_write_word_swapped(client,
AD7418_REG_TEMP[attr->index],
data->temp[attr->index]);
mutex_unlock(&data->lock);
return count;
}
static int ad7418_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct ad7418_data *data;
int err;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA)) {
err = -EOPNOTSUPP;
goto exit;
}
data = kzalloc(sizeof(struct ad7418_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(client, data);
mutex_init(&data->lock);
data->type = id->driver_data;
switch (data->type) {
case ad7416:
data->adc_max = 0;
data->attrs.attrs = ad7416_attributes;
break;
case ad7417:
data->adc_max = 4;
data->attrs.attrs = ad7417_attributes;
break;
case ad7418:
data->adc_max = 1;
data->attrs.attrs = ad7418_attributes;
break;
}
dev_info(&client->dev, "%s chip found\n", client->name);
ad7418_init_client(client);
err = sysfs_create_group(&client->dev.kobj, &data->attrs);
if (err)
goto exit_free;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
return 0;
exit_remove:
sysfs_remove_group(&client->dev.kobj, &data->attrs);
exit_free:
kfree(data);
exit:
return err;
}
static int ad7418_remove(struct i2c_client *client)
{
struct ad7418_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &data->attrs);
kfree(data);
return 0;
}
