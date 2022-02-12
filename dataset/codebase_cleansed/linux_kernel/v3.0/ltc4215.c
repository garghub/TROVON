static struct ltc4215_data *ltc4215_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct ltc4215_data *data = i2c_get_clientdata(client);
s32 val;
int i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ / 10) || !data->valid) {
dev_dbg(&client->dev, "Starting ltc4215 update\n");
for (i = 0; i < ARRAY_SIZE(data->regs); i++) {
val = i2c_smbus_read_byte_data(client, i);
if (unlikely(val < 0))
data->regs[i] = 0;
else
data->regs[i] = val;
}
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static int ltc4215_get_voltage(struct device *dev, u8 reg)
{
struct ltc4215_data *data = ltc4215_update_device(dev);
const u8 regval = data->regs[reg];
u32 voltage = 0;
switch (reg) {
case LTC4215_SENSE:
voltage = regval * 151 / 1000;
break;
case LTC4215_SOURCE:
voltage = regval * 605 / 10;
break;
case LTC4215_ADIN:
voltage = regval * 482 * 125 / 1000;
break;
default:
WARN_ON_ONCE(1);
break;
}
return voltage;
}
static unsigned int ltc4215_get_current(struct device *dev)
{
struct ltc4215_data *data = ltc4215_update_device(dev);
const unsigned int voltage = data->regs[LTC4215_SENSE] * 151;
const unsigned int curr = voltage / 4;
return curr;
}
static ssize_t ltc4215_show_voltage(struct device *dev,
struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
const int voltage = ltc4215_get_voltage(dev, attr->index);
return snprintf(buf, PAGE_SIZE, "%d\n", voltage);
}
static ssize_t ltc4215_show_current(struct device *dev,
struct device_attribute *da,
char *buf)
{
const unsigned int curr = ltc4215_get_current(dev);
return snprintf(buf, PAGE_SIZE, "%u\n", curr);
}
static ssize_t ltc4215_show_power(struct device *dev,
struct device_attribute *da,
char *buf)
{
const unsigned int curr = ltc4215_get_current(dev);
const int output_voltage = ltc4215_get_voltage(dev, LTC4215_ADIN);
const unsigned int power = abs(output_voltage * curr);
return snprintf(buf, PAGE_SIZE, "%u\n", power);
}
static ssize_t ltc4215_show_alarm(struct device *dev,
struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(da);
struct ltc4215_data *data = ltc4215_update_device(dev);
const u8 reg = data->regs[attr->index];
const u32 mask = attr->nr;
return snprintf(buf, PAGE_SIZE, "%u\n", (reg & mask) ? 1 : 0);
}
static int ltc4215_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct ltc4215_data *data;
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
i2c_smbus_write_byte_data(client, LTC4215_FAULT, 0x00);
ret = sysfs_create_group(&client->dev.kobj, &ltc4215_group);
if (ret)
goto out_sysfs_create_group;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
ret = PTR_ERR(data->hwmon_dev);
goto out_hwmon_device_register;
}
return 0;
out_hwmon_device_register:
sysfs_remove_group(&client->dev.kobj, &ltc4215_group);
out_sysfs_create_group:
kfree(data);
out_kzalloc:
return ret;
}
static int ltc4215_remove(struct i2c_client *client)
{
struct ltc4215_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &ltc4215_group);
kfree(data);
return 0;
}
static int __init ltc4215_init(void)
{
return i2c_add_driver(&ltc4215_driver);
}
static void __exit ltc4215_exit(void)
{
i2c_del_driver(&ltc4215_driver);
}
