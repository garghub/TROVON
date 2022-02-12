static int ina226_reg_to_interval(u16 config)
{
int avg = ina226_avg_tab[INA226_READ_AVG(config)];
return DIV_ROUND_CLOSEST(avg * INA226_TOTAL_CONV_TIME_DEFAULT, 1000);
}
static u16 ina226_interval_to_reg(int interval)
{
int avg, avg_bits;
avg = DIV_ROUND_CLOSEST(interval * 1000,
INA226_TOTAL_CONV_TIME_DEFAULT);
avg_bits = find_closest(avg, ina226_avg_tab,
ARRAY_SIZE(ina226_avg_tab));
return INA226_SHIFT_AVG(avg_bits);
}
static int ina2xx_calibrate(struct ina2xx_data *data)
{
u16 val = DIV_ROUND_CLOSEST(data->config->calibration_factor,
data->rshunt);
return regmap_write(data->regmap, INA2XX_CALIBRATION, val);
}
static int ina2xx_init(struct ina2xx_data *data)
{
int ret = regmap_write(data->regmap, INA2XX_CONFIG,
data->config->config_default);
if (ret < 0)
return ret;
return ina2xx_calibrate(data);
}
static int ina2xx_read_reg(struct device *dev, int reg, unsigned int *regval)
{
struct ina2xx_data *data = dev_get_drvdata(dev);
int ret, retry;
dev_dbg(dev, "Starting register %d read\n", reg);
for (retry = 5; retry; retry--) {
ret = regmap_read(data->regmap, reg, regval);
if (ret < 0)
return ret;
dev_dbg(dev, "read %d, val = 0x%04x\n", reg, *regval);
if (*regval == 0) {
unsigned int cal;
ret = regmap_read(data->regmap, INA2XX_CALIBRATION,
&cal);
if (ret < 0)
return ret;
if (cal == 0) {
dev_warn(dev, "chip not calibrated, reinitializing\n");
ret = ina2xx_init(data);
if (ret < 0)
return ret;
msleep(INA2XX_MAX_DELAY);
continue;
}
}
return 0;
}
dev_err(dev, "unable to reinitialize the chip\n");
return -ENODEV;
}
static int ina2xx_get_value(struct ina2xx_data *data, u8 reg,
unsigned int regval)
{
int val;
switch (reg) {
case INA2XX_SHUNT_VOLTAGE:
val = DIV_ROUND_CLOSEST((s16)regval, data->config->shunt_div);
break;
case INA2XX_BUS_VOLTAGE:
val = (regval >> data->config->bus_voltage_shift)
* data->config->bus_voltage_lsb;
val = DIV_ROUND_CLOSEST(val, 1000);
break;
case INA2XX_POWER:
val = regval * data->config->power_lsb;
break;
case INA2XX_CURRENT:
val = (s16)regval;
break;
case INA2XX_CALIBRATION:
val = DIV_ROUND_CLOSEST(data->config->calibration_factor,
regval);
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
struct ina2xx_data *data = dev_get_drvdata(dev);
unsigned int regval;
int err = ina2xx_read_reg(dev, attr->index, &regval);
if (err < 0)
return err;
return snprintf(buf, PAGE_SIZE, "%d\n",
ina2xx_get_value(data, attr->index, regval));
}
static ssize_t ina2xx_set_shunt(struct device *dev,
struct device_attribute *da,
const char *buf, size_t count)
{
unsigned long val;
int status;
struct ina2xx_data *data = dev_get_drvdata(dev);
status = kstrtoul(buf, 10, &val);
if (status < 0)
return status;
if (val == 0 ||
val > data->config->calibration_factor)
return -EINVAL;
mutex_lock(&data->config_lock);
data->rshunt = val;
status = ina2xx_calibrate(data);
mutex_unlock(&data->config_lock);
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
status = regmap_update_bits(data->regmap, INA2XX_CONFIG,
INA226_AVG_RD_MASK,
ina226_interval_to_reg(val));
if (status < 0)
return status;
return count;
}
static ssize_t ina226_show_interval(struct device *dev,
struct device_attribute *da, char *buf)
{
struct ina2xx_data *data = dev_get_drvdata(dev);
int status;
unsigned int regval;
status = regmap_read(data->regmap, INA2XX_CONFIG, &regval);
if (status)
return status;
return snprintf(buf, PAGE_SIZE, "%d\n", ina226_reg_to_interval(regval));
}
static int ina2xx_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct ina2xx_data *data;
struct device *hwmon_dev;
u32 val;
int ret, group = 0;
enum ina2xx_ids chip;
if (client->dev.of_node)
chip = (enum ina2xx_ids)of_device_get_match_data(&client->dev);
else
chip = id->driver_data;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->config = &ina2xx_config[chip];
if (of_property_read_u32(dev->of_node, "shunt-resistor", &val) < 0) {
struct ina2xx_platform_data *pdata = dev_get_platdata(dev);
if (pdata)
val = pdata->shunt_uohms;
else
val = INA2XX_RSHUNT_DEFAULT;
}
if (val <= 0 || val > data->config->calibration_factor)
return -ENODEV;
data->rshunt = val;
ina2xx_regmap_config.max_register = data->config->registers;
data->regmap = devm_regmap_init_i2c(client, &ina2xx_regmap_config);
if (IS_ERR(data->regmap)) {
dev_err(dev, "failed to allocate register map\n");
return PTR_ERR(data->regmap);
}
ret = ina2xx_init(data);
if (ret < 0) {
dev_err(dev, "error configuring the device: %d\n", ret);
return -ENODEV;
}
mutex_init(&data->config_lock);
data->groups[group++] = &ina2xx_group;
if (id->driver_data == ina226)
data->groups[group++] = &ina226_group;
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data, data->groups);
if (IS_ERR(hwmon_dev))
return PTR_ERR(hwmon_dev);
dev_info(dev, "power monitor %s (Rshunt = %li uOhm)\n",
id->name, data->rshunt);
return 0;
}
