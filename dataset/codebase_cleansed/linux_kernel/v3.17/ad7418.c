static struct ad7418_data *ad7418_update_device(struct device *dev)
{
struct ad7418_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
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
struct ad7418_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
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
static int ad7418_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct i2c_adapter *adapter = client->adapter;
struct ad7418_data *data;
struct device *hwmon_dev;
const struct attribute_group **attr_groups = NULL;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA))
return -EOPNOTSUPP;
data = devm_kzalloc(dev, sizeof(struct ad7418_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->lock);
data->client = client;
data->type = id->driver_data;
switch (data->type) {
case ad7416:
data->adc_max = 0;
attr_groups = ad7416_groups;
break;
case ad7417:
data->adc_max = 4;
attr_groups = ad7417_groups;
break;
case ad7418:
data->adc_max = 1;
attr_groups = ad7418_groups;
break;
}
dev_info(dev, "%s chip found\n", client->name);
ad7418_init_client(client);
hwmon_dev = devm_hwmon_device_register_with_groups(dev,
client->name,
data, attr_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
