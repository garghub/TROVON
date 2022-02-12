static int ina226_avg_bits(int avg)
{
int i;
for (i = 0; i < ARRAY_SIZE(ina226_avg_tab) - 1; i++) {
if (avg <= (ina226_avg_tab[i] + ina226_avg_tab[i + 1]) / 2)
break;
}
return i;
}
static int ina226_reg_to_interval(u16 config)
{
int avg = ina226_avg_tab[INA226_READ_AVG(config)];
return DIV_ROUND_CLOSEST(avg * INA226_TOTAL_CONV_TIME_DEFAULT, 1000);
}
static u16 ina226_interval_to_reg(int interval, u16 config)
{
int avg, avg_bits;
avg = DIV_ROUND_CLOSEST(interval * 1000,
INA226_TOTAL_CONV_TIME_DEFAULT);
avg_bits = ina226_avg_bits(avg);
return (config & ~INA226_AVG_RD_MASK) | INA226_SHIFT_AVG(avg_bits);
}
static void ina226_set_update_interval(struct ina2xx_data *data)
{
int ms;
ms = ina226_reg_to_interval(data->curr_config);
data->update_interval = msecs_to_jiffies(ms);
}
static int ina2xx_calibrate(struct ina2xx_data *data)
{
u16 val = DIV_ROUND_CLOSEST(data->config->calibration_factor,
data->rshunt);
return i2c_smbus_write_word_swapped(data->client,
INA2XX_CALIBRATION, val);
}
static int ina2xx_init(struct ina2xx_data *data)
{
struct i2c_client *client = data->client;
int ret;
ret = i2c_smbus_write_word_swapped(client, INA2XX_CONFIG,
data->curr_config);
if (ret < 0)
return ret;
return ina2xx_calibrate(data);
}
static int ina2xx_do_update(struct device *dev)
{
struct ina2xx_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int i, rv, retry;
dev_dbg(&client->dev, "Starting ina2xx update\n");
for (retry = 5; retry; retry--) {
for (i = 0; i < data->config->registers; i++) {
rv = i2c_smbus_read_word_swapped(client, i);
if (rv < 0)
return rv;
data->regs[i] = rv;
}
if (data->regs[INA2XX_CALIBRATION] == 0) {
dev_warn(dev, "chip not calibrated, reinitializing\n");
rv = ina2xx_init(data);
if (rv < 0)
return rv;
msleep(INA2XX_MAX_DELAY);
continue;
}
data->last_updated = jiffies;
data->valid = 1;
return 0;
}
dev_err(dev, "unable to reinitialize the chip\n");
return -ENODEV;
}
static struct ina2xx_data *ina2xx_update_device(struct device *dev)
{
struct ina2xx_data *data = dev_get_drvdata(dev);
struct ina2xx_data *ret = data;
unsigned long after;
int rv;
mutex_lock(&data->update_lock);
after = data->last_updated + data->update_interval;
if (time_after(jiffies, after) || !data->valid) {
rv = ina2xx_do_update(dev);
if (rv < 0)
ret = ERR_PTR(rv);
}
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
case INA2XX_CALIBRATION:
val = DIV_ROUND_CLOSEST(data->config->calibration_factor,
data->regs[reg]);
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
static ssize_t ina2xx_set_shunt(struct device *dev,
struct device_attribute *da,
const char *buf, size_t count)
{
struct ina2xx_data *data = ina2xx_update_device(dev);
unsigned long val;
int status;
if (IS_ERR(data))
return PTR_ERR(data);
status = kstrtoul(buf, 10, &val);
if (status < 0)
return status;
if (val == 0 ||
val > data->config->calibration_factor)
return -EINVAL;
mutex_lock(&data->update_lock);
data->rshunt = val;
status = ina2xx_calibrate(data);
mutex_unlock(&data->update_lock);
if (status < 0)
return status;
return count;
}
static ssize_t ina226_set_interval(struct device *dev,
struct device_attribute *da,
const char *buf, size_t count)
{
struct ina2xx_data *data = dev_get_drvdata(dev);
unsigned long val;
int status;
status = kstrtoul(buf, 10, &val);
if (status < 0)
return status;
if (val > INT_MAX || val == 0)
return -EINVAL;
mutex_lock(&data->update_lock);
data->curr_config = ina226_interval_to_reg(val,
data->regs[INA2XX_CONFIG]);
status = i2c_smbus_write_word_swapped(data->client,
INA2XX_CONFIG,
data->curr_config);
ina226_set_update_interval(data);
data->valid = 0;
mutex_unlock(&data->update_lock);
if (status < 0)
return status;
return count;
}
static ssize_t ina226_show_interval(struct device *dev,
struct device_attribute *da, char *buf)
{
struct ina2xx_data *data = ina2xx_update_device(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return snprintf(buf, PAGE_SIZE, "%d\n",
ina226_reg_to_interval(data->regs[INA2XX_CONFIG]));
}
static int ina2xx_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct ina2xx_platform_data *pdata;
struct device *dev = &client->dev;
struct ina2xx_data *data;
struct device *hwmon_dev;
u32 val;
int ret, group = 0;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
if (dev_get_platdata(dev)) {
pdata = dev_get_platdata(dev);
data->rshunt = pdata->shunt_uohms;
} else if (!of_property_read_u32(dev->of_node,
"shunt-resistor", &val)) {
data->rshunt = val;
} else {
data->rshunt = INA2XX_RSHUNT_DEFAULT;
}
data->kind = id->driver_data;
data->config = &ina2xx_config[data->kind];
data->curr_config = data->config->config_default;
data->client = client;
if (data->kind == ina226)
ina226_set_update_interval(data);
else
data->update_interval = HZ / INA2XX_CONVERSION_RATE;
if (data->rshunt <= 0 ||
data->rshunt > data->config->calibration_factor)
return -ENODEV;
ret = ina2xx_init(data);
if (ret < 0) {
dev_err(dev, "error configuring the device: %d\n", ret);
return -ENODEV;
}
mutex_init(&data->update_lock);
data->groups[group++] = &ina2xx_group;
if (data->kind == ina226)
data->groups[group++] = &ina226_group;
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data, data->groups);
if (IS_ERR(hwmon_dev))
return PTR_ERR(hwmon_dev);
dev_info(dev, "power monitor %s (Rshunt = %li uOhm)\n",
id->name, data->rshunt);
return 0;
}
