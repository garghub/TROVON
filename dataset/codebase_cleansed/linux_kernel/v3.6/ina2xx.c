static struct ina2xx_data *ina2xx_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct ina2xx_data *data = i2c_get_clientdata(client);
struct ina2xx_data *ret = data;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated +
HZ / INA2XX_CONVERSION_RATE) || !data->valid) {
int i;
dev_dbg(&client->dev, "Starting ina2xx update\n");
for (i = 0; i < data->registers; i++) {
int rv = i2c_smbus_read_word_swapped(client, i);
if (rv < 0) {
ret = ERR_PTR(rv);
goto abort;
}
data->regs[i] = rv;
}
data->last_updated = jiffies;
data->valid = 1;
}
abort:
mutex_unlock(&data->update_lock);
return ret;
}
static int ina219_get_value(struct ina2xx_data *data, u8 reg)
{
int val = data->regs[reg];
switch (reg) {
case INA2XX_SHUNT_VOLTAGE:
val = DIV_ROUND_CLOSEST(val, 100);
break;
case INA2XX_BUS_VOLTAGE:
val = (val >> 3) * 4;
break;
case INA2XX_POWER:
val = val * 20 * 1000;
break;
case INA2XX_CURRENT:
break;
default:
WARN_ON_ONCE(1);
val = 0;
break;
}
return val;
}
static int ina226_get_value(struct ina2xx_data *data, u8 reg)
{
int val = data->regs[reg];
switch (reg) {
case INA2XX_SHUNT_VOLTAGE:
val = DIV_ROUND_CLOSEST(val, 400);
break;
case INA2XX_BUS_VOLTAGE:
val = val + DIV_ROUND_CLOSEST(val, 4);
break;
case INA2XX_POWER:
val = val * 25 * 1000;
break;
case INA2XX_CURRENT:
break;
default:
WARN_ON_ONCE(1);
val = 0;
break;
}
return val;
}
static ssize_t ina2xx_show_value(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct ina2xx_data *data = ina2xx_update_device(dev);
int value = 0;
if (IS_ERR(data))
return PTR_ERR(data);
switch (data->kind) {
case ina219:
value = ina219_get_value(data, attr->index);
break;
case ina226:
value = ina226_get_value(data, attr->index);
break;
default:
WARN_ON_ONCE(1);
break;
}
return snprintf(buf, PAGE_SIZE, "%d\n", value);
}
static int ina2xx_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct ina2xx_data *data;
struct ina2xx_platform_data *pdata;
int ret = 0;
long shunt = 10000;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
if (client->dev.platform_data) {
pdata =
(struct ina2xx_platform_data *)client->dev.platform_data;
shunt = pdata->shunt_uohms;
}
if (shunt <= 0)
return -ENODEV;
data->kind = id->driver_data;
switch (data->kind) {
case ina219:
i2c_smbus_write_word_swapped(client, INA2XX_CONFIG,
INA219_CONFIG_DEFAULT);
i2c_smbus_write_word_swapped(client, INA2XX_CALIBRATION,
40960000 / shunt);
dev_info(&client->dev,
"power monitor INA219 (Rshunt = %li uOhm)\n", shunt);
data->registers = INA219_REGISTERS;
break;
case ina226:
i2c_smbus_write_word_swapped(client, INA2XX_CONFIG,
INA226_CONFIG_DEFAULT);
i2c_smbus_write_word_swapped(client, INA2XX_CALIBRATION,
5120000 / shunt);
dev_info(&client->dev,
"power monitor INA226 (Rshunt = %li uOhm)\n", shunt);
data->registers = INA226_REGISTERS;
break;
default:
return -ENODEV;
}
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
ret = sysfs_create_group(&client->dev.kobj, &ina2xx_group);
if (ret)
return ret;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
ret = PTR_ERR(data->hwmon_dev);
goto out_err_hwmon;
}
return 0;
out_err_hwmon:
sysfs_remove_group(&client->dev.kobj, &ina2xx_group);
return ret;
}
static int ina2xx_remove(struct i2c_client *client)
{
struct ina2xx_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &ina2xx_group);
return 0;
}
static int __init ina2xx_init(void)
{
return i2c_add_driver(&ina2xx_driver);
}
static void __exit ina2xx_exit(void)
{
i2c_del_driver(&ina2xx_driver);
}
