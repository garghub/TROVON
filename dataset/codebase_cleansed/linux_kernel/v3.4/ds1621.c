static void ds1621_init_client(struct i2c_client *client)
{
u8 conf, new_conf;
new_conf = conf = i2c_smbus_read_byte_data(client, DS1621_REG_CONF);
new_conf &= ~DS1621_REG_CONFIG_1SHOT;
if (polarity == 0)
new_conf &= ~DS1621_REG_CONFIG_POLARITY;
else if (polarity == 1)
new_conf |= DS1621_REG_CONFIG_POLARITY;
if (conf != new_conf)
i2c_smbus_write_byte_data(client, DS1621_REG_CONF, new_conf);
i2c_smbus_write_byte(client, DS1621_COM_START);
}
static struct ds1621_data *ds1621_update_client(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct ds1621_data *data = i2c_get_clientdata(client);
u8 new_conf;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
int i;
dev_dbg(&client->dev, "Starting ds1621 update\n");
data->conf = i2c_smbus_read_byte_data(client, DS1621_REG_CONF);
for (i = 0; i < ARRAY_SIZE(data->temp); i++)
data->temp[i] = i2c_smbus_read_word_swapped(client,
DS1621_REG_TEMP[i]);
new_conf = data->conf;
if (data->temp[0] > data->temp[1])
new_conf &= ~DS1621_ALARM_TEMP_LOW;
if (data->temp[0] < data->temp[2])
new_conf &= ~DS1621_ALARM_TEMP_HIGH;
if (data->conf != new_conf)
i2c_smbus_write_byte_data(client, DS1621_REG_CONF,
new_conf);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct ds1621_data *data = ds1621_update_client(dev);
return sprintf(buf, "%d\n",
LM75_TEMP_FROM_REG(data->temp[attr->index]));
}
static ssize_t set_temp(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct i2c_client *client = to_i2c_client(dev);
struct ds1621_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp[attr->index] = LM75_TEMP_TO_REG(val);
i2c_smbus_write_word_swapped(client, DS1621_REG_TEMP[attr->index],
data->temp[attr->index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarms(struct device *dev, struct device_attribute *da,
char *buf)
{
struct ds1621_data *data = ds1621_update_client(dev);
return sprintf(buf, "%d\n", ALARMS_FROM_REG(data->conf));
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct ds1621_data *data = ds1621_update_client(dev);
return sprintf(buf, "%d\n", !!(data->conf & attr->index));
}
static int ds1621_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int conf, temp;
int i;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA
| I2C_FUNC_SMBUS_WORD_DATA
| I2C_FUNC_SMBUS_WRITE_BYTE))
return -ENODEV;
conf = i2c_smbus_read_byte_data(client, DS1621_REG_CONF);
if (conf < 0 || conf & DS1621_REG_CONFIG_NVB)
return -ENODEV;
for (i = 0; i < ARRAY_SIZE(DS1621_REG_TEMP); i++) {
temp = i2c_smbus_read_word_data(client, DS1621_REG_TEMP[i]);
if (temp < 0 || (temp & 0x7f00))
return -ENODEV;
}
strlcpy(info->type, "ds1621", I2C_NAME_SIZE);
return 0;
}
static int ds1621_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ds1621_data *data;
int err;
data = kzalloc(sizeof(struct ds1621_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
ds1621_init_client(client);
err = sysfs_create_group(&client->dev.kobj, &ds1621_group);
if (err)
goto exit_free;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
return 0;
exit_remove_files:
sysfs_remove_group(&client->dev.kobj, &ds1621_group);
exit_free:
kfree(data);
exit:
return err;
}
static int ds1621_remove(struct i2c_client *client)
{
struct ds1621_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &ds1621_group);
kfree(data);
return 0;
}
