static ssize_t show_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
struct thermal_data *data = dev_get_drvdata(dev);
int retval;
retval = i2c_smbus_read_byte_data(data->client, sda->index);
if (retval < 0)
return retval;
return sprintf(buf, "%d000\n", retval);
}
static ssize_t show_bit(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute_2 *sda = to_sensor_dev_attr_2(attr);
struct thermal_data *data = dev_get_drvdata(dev);
int retval;
retval = i2c_smbus_read_byte_data(data->client, sda->nr);
if (retval < 0)
return retval;
return sprintf(buf, "%d\n", !!(retval & sda->index));
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
retval = i2c_smbus_write_byte_data(data->client, sda->index,
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
struct i2c_client *client = data->client;
unsigned long val;
int retval;
if (kstrtoul(buf, 10, &val))
return -EINVAL;
mutex_lock(&data->mutex);
retval = i2c_smbus_read_byte_data(client, sda->nr);
if (retval < 0)
goto fail;
retval &= ~sda->index;
if (val)
retval |= sda->index;
retval = i2c_smbus_write_byte_data(client, sda->index, retval);
if (retval == 0)
retval = count;
fail:
mutex_unlock(&data->mutex);
return retval;
}
static ssize_t show_hyst(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
struct thermal_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int retval;
int hyst;
retval = i2c_smbus_read_byte_data(client, sda->index);
if (retval < 0)
return retval;
if (time_after(jiffies, data->hyst_valid)) {
hyst = i2c_smbus_read_byte_data(client, 0x21);
if (hyst < 0)
return retval;
data->cached_hyst = hyst;
data->hyst_valid = jiffies + HZ;
}
return sprintf(buf, "%d000\n", retval - data->cached_hyst);
}
static ssize_t store_hyst(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
struct thermal_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int retval;
int hyst;
unsigned long val;
if (kstrtoul(buf, 10, &val))
return -EINVAL;
mutex_lock(&data->mutex);
retval = i2c_smbus_read_byte_data(client, sda->index);
if (retval < 0)
goto fail;
hyst = val - retval * 1000;
hyst = DIV_ROUND_CLOSEST(hyst, 1000);
if (hyst < 0 || hyst > 255) {
retval = -ERANGE;
goto fail;
}
retval = i2c_smbus_write_byte_data(client, 0x21, hyst);
if (retval == 0) {
retval = count;
data->cached_hyst = hyst;
data->hyst_valid = jiffies + HZ;
}
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
case 0x21:
strlcpy(info->type, "emc1403", I2C_NAME_SIZE);
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
if (id != 0x01)
return -ENODEV;
return 0;
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
data->client = client;
mutex_init(&data->mutex);
data->hyst_valid = jiffies - 1;
data->groups[0] = &emc1403_group;
if (id->driver_data)
data->groups[1] = &emc1404_group;
hwmon_dev = hwmon_device_register_with_groups(&client->dev,
client->name, data,
data->groups);
if (IS_ERR(hwmon_dev))
return PTR_ERR(hwmon_dev);
dev_info(&client->dev, "%s Thermal chip found\n", id->name);
return 0;
}
