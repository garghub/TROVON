static ssize_t show_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
struct thermal_data *data = dev_get_drvdata(dev);
unsigned int val;
int retval;
retval = regmap_read(data->regmap, sda->index, &val);
if (retval < 0)
return retval;
return sprintf(buf, "%d000\n", val);
}
static ssize_t show_bit(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute_2 *sda = to_sensor_dev_attr_2(attr);
struct thermal_data *data = dev_get_drvdata(dev);
unsigned int val;
int retval;
retval = regmap_read(data->regmap, sda->nr, &val);
if (retval < 0)
return retval;
return sprintf(buf, "%d\n", !!(val & sda->index));
}
static ssize_t store_temp(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
struct thermal_data *data = dev_get_drvdata(dev);
unsigned long val;
int retval;
if (kstrtoul(buf, 10, &val))
return -EINVAL;
retval = regmap_write(data->regmap, sda->index,
DIV_ROUND_CLOSEST(val, 1000));
if (retval < 0)
return retval;
return count;
}
static ssize_t store_bit(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sda = to_sensor_dev_attr_2(attr);
struct thermal_data *data = dev_get_drvdata(dev);
unsigned long val;
int retval;
if (kstrtoul(buf, 10, &val))
return -EINVAL;
retval = regmap_update_bits(data->regmap, sda->nr, sda->index,
val ? sda->index : 0);
if (retval < 0)
return retval;
return count;
}
static ssize_t show_hyst_common(struct device *dev,
struct device_attribute *attr, char *buf,
bool is_min)
{
struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
struct thermal_data *data = dev_get_drvdata(dev);
struct regmap *regmap = data->regmap;
unsigned int limit;
unsigned int hyst;
int retval;
retval = regmap_read(regmap, sda->index, &limit);
if (retval < 0)
return retval;
retval = regmap_read(regmap, 0x21, &hyst);
if (retval < 0)
return retval;
return sprintf(buf, "%d000\n", is_min ? limit + hyst : limit - hyst);
}
static ssize_t show_hyst(struct device *dev,
struct device_attribute *attr, char *buf)
{
return show_hyst_common(dev, attr, buf, false);
}
static ssize_t show_min_hyst(struct device *dev,
struct device_attribute *attr, char *buf)
{
return show_hyst_common(dev, attr, buf, true);
}
static ssize_t store_hyst(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
struct thermal_data *data = dev_get_drvdata(dev);
struct regmap *regmap = data->regmap;
unsigned int limit;
int retval;
int hyst;
unsigned long val;
if (kstrtoul(buf, 10, &val))
return -EINVAL;
mutex_lock(&data->mutex);
retval = regmap_read(regmap, sda->index, &limit);
if (retval < 0)
goto fail;
hyst = limit * 1000 - val;
hyst = clamp_val(DIV_ROUND_CLOSEST(hyst, 1000), 0, 255);
retval = regmap_write(regmap, 0x21, hyst);
if (retval == 0)
retval = count;
fail:
mutex_unlock(&data->mutex);
return retval;
}
static int emc1403_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
int id;
id = i2c_smbus_read_byte_data(client, THERMAL_SMSC_ID_REG);
if (id != 0x5d)
return -ENODEV;
id = i2c_smbus_read_byte_data(client, THERMAL_PID_REG);
switch (id) {
case 0x20:
strlcpy(info->type, "emc1402", I2C_NAME_SIZE);
break;
case 0x21:
strlcpy(info->type, "emc1403", I2C_NAME_SIZE);
break;
case 0x22:
strlcpy(info->type, "emc1422", I2C_NAME_SIZE);
break;
case 0x23:
strlcpy(info->type, "emc1423", I2C_NAME_SIZE);
break;
case 0x25:
strlcpy(info->type, "emc1404", I2C_NAME_SIZE);
break;
case 0x27:
strlcpy(info->type, "emc1424", I2C_NAME_SIZE);
break;
default:
return -ENODEV;
}
id = i2c_smbus_read_byte_data(client, THERMAL_REVISION_REG);
if (id < 0x01 || id > 0x04)
return -ENODEV;
return 0;
}
static bool emc1403_regmap_is_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case 0x00:
case 0x01:
case 0x02:
case 0x10:
case 0x1b:
case 0x23:
case 0x24:
case 0x29:
case 0x2a:
case 0x2b:
case 0x35:
case 0x36:
case 0x37:
return true;
default:
return false;
}
}
static int emc1403_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct thermal_data *data;
struct device *hwmon_dev;
data = devm_kzalloc(&client->dev, sizeof(struct thermal_data),
GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
data->regmap = devm_regmap_init_i2c(client, &emc1403_regmap_config);
if (IS_ERR(data->regmap))
return PTR_ERR(data->regmap);
mutex_init(&data->mutex);
switch (id->driver_data) {
case emc1404:
data->groups[2] = &emc1404_group;
case emc1403:
data->groups[1] = &emc1403_group;
case emc1402:
data->groups[0] = &emc1402_group;
}
if (id->driver_data == emc1402)
data->groups[1] = &emc1402_alarm_group;
hwmon_dev = devm_hwmon_device_register_with_groups(&client->dev,
client->name, data,
data->groups);
if (IS_ERR(hwmon_dev))
return PTR_ERR(hwmon_dev);
dev_info(&client->dev, "%s Thermal chip found\n", id->name);
return 0;
}
