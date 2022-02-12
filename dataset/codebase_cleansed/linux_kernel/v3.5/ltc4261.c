static struct ltc4261_data *ltc4261_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct ltc4261_data *data = i2c_get_clientdata(client);
struct ltc4261_data *ret = data;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ / 4) || !data->valid) {
int i;
for (i = 0; i < ARRAY_SIZE(data->regs); i++) {
int val;
val = i2c_smbus_read_byte_data(client, i);
if (unlikely(val < 0)) {
dev_dbg(dev,
"Failed to read ADC value: error %d\n",
val);
ret = ERR_PTR(val);
data->valid = 0;
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
static int ltc4261_get_value(struct ltc4261_data *data, u8 reg)
{
u32 val;
val = (data->regs[reg] << 2) + (data->regs[reg + 1] >> 6);
switch (reg) {
case LTC4261_ADIN_H:
case LTC4261_ADIN2_H:
val = val * 25 / 10;
break;
case LTC4261_SENSE_H:
val = val * 625 / 10;
break;
default:
WARN_ON_ONCE(1);
val = 0;
break;
}
return val;
}
static ssize_t ltc4261_show_value(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct ltc4261_data *data = ltc4261_update_device(dev);
int value;
if (IS_ERR(data))
return PTR_ERR(data);
value = ltc4261_get_value(data, attr->index);
return snprintf(buf, PAGE_SIZE, "%d\n", value);
}
static ssize_t ltc4261_show_bool(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct i2c_client *client = to_i2c_client(dev);
struct ltc4261_data *data = ltc4261_update_device(dev);
u8 fault;
if (IS_ERR(data))
return PTR_ERR(data);
fault = data->regs[LTC4261_FAULT] & attr->index;
if (fault)
i2c_smbus_write_byte_data(client, LTC4261_FAULT, ~fault);
return snprintf(buf, PAGE_SIZE, "%d\n", fault ? 1 : 0);
}
static int ltc4261_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct ltc4261_data *data;
int ret;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
if (i2c_smbus_read_byte_data(client, LTC4261_STATUS) < 0) {
dev_err(&client->dev, "Failed to read status register\n");
return -ENODEV;
}
data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
i2c_smbus_write_byte_data(client, LTC4261_FAULT, 0x00);
ret = sysfs_create_group(&client->dev.kobj, &ltc4261_group);
if (ret)
return ret;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
ret = PTR_ERR(data->hwmon_dev);
goto out_hwmon_device_register;
}
return 0;
out_hwmon_device_register:
sysfs_remove_group(&client->dev.kobj, &ltc4261_group);
return ret;
}
static int ltc4261_remove(struct i2c_client *client)
{
struct ltc4261_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &ltc4261_group);
return 0;
}
