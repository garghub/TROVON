static struct ltc4151_data *ltc4151_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct ltc4151_data *data = i2c_get_clientdata(client);
struct ltc4151_data *ret = data;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ / 6) || !data->valid) {
int i;
dev_dbg(&client->dev, "Starting ltc4151 update\n");
for (i = 0; i < ARRAY_SIZE(data->regs); i++) {
int val;
val = i2c_smbus_read_byte_data(client, i);
if (unlikely(val < 0)) {
dev_dbg(dev,
"Failed to read ADC value: error %d\n",
val);
ret = ERR_PTR(val);
goto abort;
}
data->regs[i] = val;
}
data->last_updated = jiffies;
data->valid = 1;
}
abort:
mutex_unlock(&data->update_lock);
return ret;
}
static int ltc4151_get_value(struct ltc4151_data *data, u8 reg)
{
u32 val;
val = (data->regs[reg] << 4) + (data->regs[reg + 1] >> 4);
switch (reg) {
case LTC4151_ADIN_H:
val = val * 500 / 1000;
break;
case LTC4151_SENSE_H:
val = val * 20;
break;
case LTC4151_VIN_H:
val = val * 25;
break;
default:
WARN_ON_ONCE(1);
val = 0;
break;
}
return val;
}
static ssize_t ltc4151_show_value(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct ltc4151_data *data = ltc4151_update_device(dev);
int value;
if (IS_ERR(data))
return PTR_ERR(data);
value = ltc4151_get_value(data, attr->index);
return snprintf(buf, PAGE_SIZE, "%d\n", value);
}
static int ltc4151_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct ltc4151_data *data;
int ret;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data) {
ret = -ENOMEM;
goto out_kzalloc;
}
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
ret = sysfs_create_group(&client->dev.kobj, &ltc4151_group);
if (ret)
goto out_sysfs_create_group;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
ret = PTR_ERR(data->hwmon_dev);
goto out_hwmon_device_register;
}
return 0;
out_hwmon_device_register:
sysfs_remove_group(&client->dev.kobj, &ltc4151_group);
out_sysfs_create_group:
kfree(data);
out_kzalloc:
return ret;
}
static int ltc4151_remove(struct i2c_client *client)
{
struct ltc4151_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &ltc4151_group);
kfree(data);
return 0;
}
static int __init ltc4151_init(void)
{
return i2c_add_driver(&ltc4151_driver);
}
static void __exit ltc4151_exit(void)
{
i2c_del_driver(&ltc4151_driver);
}
