static void ds620_init_client(struct i2c_client *client)
{
struct ds620_platform_data *ds620_info = client->dev.platform_data;
u16 conf, new_conf;
new_conf = conf =
i2c_smbus_read_word_swapped(client, DS620_REG_CONF);
new_conf &= ~DS620_REG_CONFIG_1SHOT;
new_conf |= DS620_REG_CONFIG_PO2;
if (ds620_info && ds620_info->pomode == 1)
new_conf &= ~DS620_REG_CONFIG_PO1;
else if (ds620_info && ds620_info->pomode == 2)
new_conf |= DS620_REG_CONFIG_PO1;
else
new_conf &= ~DS620_REG_CONFIG_PO2;
new_conf |= DS620_REG_CONFIG_R1 | DS620_REG_CONFIG_R0;
if (conf != new_conf)
i2c_smbus_write_word_swapped(client, DS620_REG_CONF, new_conf);
i2c_smbus_write_byte(client, DS620_COM_START);
}
static struct ds620_data *ds620_update_client(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct ds620_data *data = i2c_get_clientdata(client);
struct ds620_data *ret = data;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
int i;
int res;
dev_dbg(&client->dev, "Starting ds620 update\n");
for (i = 0; i < ARRAY_SIZE(data->temp); i++) {
res = i2c_smbus_read_word_swapped(client,
DS620_REG_TEMP[i]);
if (res < 0) {
ret = ERR_PTR(res);
goto abort;
}
data->temp[i] = res;
}
data->last_updated = jiffies;
data->valid = 1;
}
abort:
mutex_unlock(&data->update_lock);
return ret;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct ds620_data *data = ds620_update_client(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n", ((data->temp[attr->index] / 8) * 625) / 10);
}
static ssize_t set_temp(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
int res;
long val;
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct i2c_client *client = to_i2c_client(dev);
struct ds620_data *data = i2c_get_clientdata(client);
res = kstrtol(buf, 10, &val);
if (res)
return res;
val = (val * 10 / 625) * 8;
mutex_lock(&data->update_lock);
data->temp[attr->index] = val;
i2c_smbus_write_word_swapped(client, DS620_REG_TEMP[attr->index],
data->temp[attr->index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct ds620_data *data = ds620_update_client(dev);
struct i2c_client *client = to_i2c_client(dev);
u16 conf, new_conf;
int res;
if (IS_ERR(data))
return PTR_ERR(data);
res = i2c_smbus_read_word_swapped(client, DS620_REG_CONF);
if (res < 0)
return res;
new_conf = conf = res;
new_conf &= ~attr->index;
if (conf != new_conf) {
res = i2c_smbus_write_word_swapped(client, DS620_REG_CONF,
new_conf);
if (res < 0)
return res;
}
return sprintf(buf, "%d\n", !!(conf & attr->index));
}
static int ds620_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ds620_data *data;
int err;
data = kzalloc(sizeof(struct ds620_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
ds620_init_client(client);
err = sysfs_create_group(&client->dev.kobj, &ds620_group);
if (err)
goto exit_free;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
dev_info(&client->dev, "temperature sensor found\n");
return 0;
exit_remove_files:
sysfs_remove_group(&client->dev.kobj, &ds620_group);
exit_free:
kfree(data);
exit:
return err;
}
static int ds620_remove(struct i2c_client *client)
{
struct ds620_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &ds620_group);
kfree(data);
return 0;
}
static int __init ds620_init(void)
{
return i2c_add_driver(&ds620_driver);
}
static void __exit ds620_exit(void)
{
i2c_del_driver(&ds620_driver);
}
