static inline int ad7414_temp_from_reg(s16 reg)
{
return ((int)reg / 64) * 250;
}
static inline int ad7414_read(struct i2c_client *client, u8 reg)
{
if (reg == AD7414_REG_TEMP)
return i2c_smbus_read_word_swapped(client, reg);
else
return i2c_smbus_read_byte_data(client, reg);
}
static inline int ad7414_write(struct i2c_client *client, u8 reg, u8 value)
{
return i2c_smbus_write_byte_data(client, reg, value);
}
static struct ad7414_data *ad7414_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct ad7414_data *data = i2c_get_clientdata(client);
mutex_lock(&data->lock);
if (time_after(jiffies, data->next_update) || !data->valid) {
int value, i;
dev_dbg(&client->dev, "starting ad7414 update\n");
value = ad7414_read(client, AD7414_REG_TEMP);
if (value < 0)
dev_dbg(&client->dev, "AD7414_REG_TEMP err %d\n",
value);
else
data->temp_input = value;
for (i = 0; i < ARRAY_SIZE(AD7414_REG_LIMIT); ++i) {
value = ad7414_read(client, AD7414_REG_LIMIT[i]);
if (value < 0)
dev_dbg(&client->dev, "AD7414 reg %d err %d\n",
AD7414_REG_LIMIT[i], value);
else
data->temps[i] = value;
}
data->next_update = jiffies + HZ + HZ / 2;
data->valid = 1;
}
mutex_unlock(&data->lock);
return data;
}
static ssize_t show_temp_input(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ad7414_data *data = ad7414_update_device(dev);
return sprintf(buf, "%d\n", ad7414_temp_from_reg(data->temp_input));
}
static ssize_t show_max_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
int index = to_sensor_dev_attr(attr)->index;
struct ad7414_data *data = ad7414_update_device(dev);
return sprintf(buf, "%d\n", data->temps[index] * 1000);
}
static ssize_t set_max_min(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct ad7414_data *data = i2c_get_clientdata(client);
int index = to_sensor_dev_attr(attr)->index;
u8 reg = AD7414_REG_LIMIT[index];
long temp;
int ret = kstrtol(buf, 10, &temp);
if (ret < 0)
return ret;
temp = SENSORS_LIMIT(temp, -40000, 85000);
temp = (temp + (temp < 0 ? -500 : 500)) / 1000;
mutex_lock(&data->lock);
data->temps[index] = temp;
ad7414_write(client, reg, temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int bitnr = to_sensor_dev_attr(attr)->index;
struct ad7414_data *data = ad7414_update_device(dev);
int value = (data->temp_input >> bitnr) & 1;
return sprintf(buf, "%d\n", value);
}
static int ad7414_probe(struct i2c_client *client,
const struct i2c_device_id *dev_id)
{
struct ad7414_data *data;
int conf;
int err;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_READ_WORD_DATA))
return -EOPNOTSUPP;
data = devm_kzalloc(&client->dev, sizeof(struct ad7414_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->lock);
dev_info(&client->dev, "chip found\n");
conf = i2c_smbus_read_byte_data(client, AD7414_REG_CONF);
if (conf < 0)
dev_warn(&client->dev,
"ad7414_probe unable to read config register.\n");
else {
conf &= ~(1 << 7);
i2c_smbus_write_byte_data(client, AD7414_REG_CONF, conf);
}
err = sysfs_create_group(&client->dev.kobj, &ad7414_group);
if (err)
return err;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
return 0;
exit_remove:
sysfs_remove_group(&client->dev.kobj, &ad7414_group);
return err;
}
static int __devexit ad7414_remove(struct i2c_client *client)
{
struct ad7414_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &ad7414_group);
return 0;
}
