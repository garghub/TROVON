static struct ina2xx_data *ina2xx_update_device(struct device *dev)
{
struct ina2xx_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
struct ina2xx_data *ret = data;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated +
HZ / INA2XX_CONVERSION_RATE) || !data->valid) {
int i;
dev_dbg(&client->dev, "Starting ina2xx update\n");
for (i = 0; i < data->config->registers; i++) {
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
static int ina2xx_get_value(struct ina2xx_data *data, u8 reg)
{
int val;
switch (reg) {
case INA2XX_SHUNT_VOLTAGE:
val = DIV_ROUND_CLOSEST((s16)data->regs[reg],
data->config->shunt_div);
break;
case INA2XX_BUS_VOLTAGE:
val = (data->regs[reg] >> data->config->bus_voltage_shift)
* data->config->bus_voltage_lsb;
val = DIV_ROUND_CLOSEST(val, 1000);
break;
case INA2XX_POWER:
val = data->regs[reg] * data->config->power_lsb;
break;
case INA2XX_CURRENT:
val = (s16)data->regs[reg];
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
if (IS_ERR(data))
return PTR_ERR(data);
return snprintf(buf, PAGE_SIZE, "%d\n",
ina2xx_get_value(data, attr->index));
}
static int ina2xx_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct ina2xx_platform_data *pdata;
struct device *dev = &client->dev;
struct ina2xx_data *data;
struct device *hwmon_dev;
long shunt = 10000;
u32 val;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
if (dev_get_platdata(dev)) {
pdata = dev_get_platdata(dev);
shunt = pdata->shunt_uohms;
} else if (!of_property_read_u32(dev->of_node,
"shunt-resistor", &val)) {
shunt = val;
}
if (shunt <= 0)
return -ENODEV;
data->kind = id->driver_data;
data->config = &ina2xx_config[data->kind];
i2c_smbus_write_word_swapped(client, INA2XX_CONFIG,
data->config->config_default);
i2c_smbus_write_word_swapped(client, INA2XX_CALIBRATION,
data->config->calibration_factor / shunt);
data->client = client;
mutex_init(&data->update_lock);
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data, ina2xx_groups);
if (IS_ERR(hwmon_dev))
return PTR_ERR(hwmon_dev);
dev_info(dev, "power monitor %s (Rshunt = %li uOhm)\n",
id->name, shunt);
return 0;
}
