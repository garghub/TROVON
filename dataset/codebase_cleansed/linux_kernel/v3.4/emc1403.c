static ssize_t show_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
int retval = i2c_smbus_read_byte_data(client, sda->index);
if (retval < 0)
return retval;
return sprintf(buf, "%d000\n", retval);
}
static ssize_t show_bit(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct sensor_device_attribute_2 *sda = to_sensor_dev_attr_2(attr);
int retval = i2c_smbus_read_byte_data(client, sda->nr);
if (retval < 0)
return retval;
retval &= sda->index;
return sprintf(buf, "%d\n", retval ? 1 : 0);
}
static ssize_t store_temp(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
struct i2c_client *client = to_i2c_client(dev);
unsigned long val;
int retval;
if (kstrtoul(buf, 10, &val))
return -EINVAL;
retval = i2c_smbus_write_byte_data(client, sda->index,
DIV_ROUND_CLOSEST(val, 1000));
if (retval < 0)
return retval;
return count;
}
static ssize_t store_bit(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct thermal_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute_2 *sda = to_sensor_dev_attr_2(attr);
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
struct i2c_client *client = to_i2c_client(dev);
struct thermal_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
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
struct i2c_client *client = to_i2c_client(dev);
struct thermal_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
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
int res;
struct thermal_data *data;
data = kzalloc(sizeof(struct thermal_data), GFP_KERNEL);
if (data == NULL) {
dev_warn(&client->dev, "out of memory");
return -ENOMEM;
}
i2c_set_clientdata(client, data);
mutex_init(&data->mutex);
data->hyst_valid = jiffies - 1;
res = sysfs_create_group(&client->dev.kobj, &m_thermal_gr);
if (res) {
dev_warn(&client->dev, "create group failed\n");
goto thermal_error1;
}
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
res = PTR_ERR(data->hwmon_dev);
dev_warn(&client->dev, "register hwmon dev failed\n");
goto thermal_error2;
}
dev_info(&client->dev, "EMC1403 Thermal chip found\n");
return res;
thermal_error2:
sysfs_remove_group(&client->dev.kobj, &m_thermal_gr);
thermal_error1:
kfree(data);
return res;
}
static int emc1403_remove(struct i2c_client *client)
{
struct thermal_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &m_thermal_gr);
kfree(data);
return 0;
}
