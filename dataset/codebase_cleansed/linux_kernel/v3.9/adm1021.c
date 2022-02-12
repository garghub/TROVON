static ssize_t show_temp(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct adm1021_data *data = adm1021_update_device(dev);
return sprintf(buf, "%d\n", data->temp[index]);
}
static ssize_t show_temp_max(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct adm1021_data *data = adm1021_update_device(dev);
return sprintf(buf, "%d\n", data->temp_max[index]);
}
static ssize_t show_temp_min(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct adm1021_data *data = adm1021_update_device(dev);
return sprintf(buf, "%d\n", data->temp_min[index]);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int index = to_sensor_dev_attr(attr)->index;
struct adm1021_data *data = adm1021_update_device(dev);
return sprintf(buf, "%u\n", (data->alarms >> index) & 1);
}
static ssize_t show_alarms(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct adm1021_data *data = adm1021_update_device(dev);
return sprintf(buf, "%u\n", data->alarms);
}
static ssize_t set_temp_max(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
int index = to_sensor_dev_attr(devattr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct adm1021_data *data = i2c_get_clientdata(client);
long temp;
int err;
err = kstrtol(buf, 10, &temp);
if (err)
return err;
temp /= 1000;
mutex_lock(&data->update_lock);
data->temp_max[index] = clamp_val(temp, -128, 127);
if (!read_only)
i2c_smbus_write_byte_data(client, ADM1021_REG_TOS_W(index),
data->temp_max[index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_temp_min(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
int index = to_sensor_dev_attr(devattr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct adm1021_data *data = i2c_get_clientdata(client);
long temp;
int err;
err = kstrtol(buf, 10, &temp);
if (err)
return err;
temp /= 1000;
mutex_lock(&data->update_lock);
data->temp_min[index] = clamp_val(temp, -128, 127);
if (!read_only)
i2c_smbus_write_byte_data(client, ADM1021_REG_THYST_W(index),
data->temp_min[index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_low_power(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct adm1021_data *data = adm1021_update_device(dev);
return sprintf(buf, "%d\n", data->low_power);
}
static ssize_t set_low_power(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct adm1021_data *data = i2c_get_clientdata(client);
char low_power;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
low_power = val != 0;
mutex_lock(&data->update_lock);
if (low_power != data->low_power) {
int config = i2c_smbus_read_byte_data(
client, ADM1021_REG_CONFIG_R);
data->low_power = low_power;
i2c_smbus_write_byte_data(client, ADM1021_REG_CONFIG_W,
(config & 0xBF) | (low_power << 6));
}
mutex_unlock(&data->update_lock);
return count;
}
static int adm1021_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
const char *type_name;
int conv_rate, status, config, man_id, dev_id;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
pr_debug("adm1021: detect failed, "
"smbus byte data not supported!\n");
return -ENODEV;
}
status = i2c_smbus_read_byte_data(client, ADM1021_REG_STATUS);
conv_rate = i2c_smbus_read_byte_data(client,
ADM1021_REG_CONV_RATE_R);
config = i2c_smbus_read_byte_data(client, ADM1021_REG_CONFIG_R);
if ((status & 0x03) || (config & 0x3F) || (conv_rate & 0xF8)) {
pr_debug("adm1021: detect failed, chip not detected!\n");
return -ENODEV;
}
man_id = i2c_smbus_read_byte_data(client, ADM1021_REG_MAN_ID);
dev_id = i2c_smbus_read_byte_data(client, ADM1021_REG_DEV_ID);
if (man_id == 0x4d && dev_id == 0x01)
type_name = "max1617a";
else if (man_id == 0x41) {
if ((dev_id & 0xF0) == 0x30)
type_name = "adm1023";
else
type_name = "adm1021";
} else if (man_id == 0x49)
type_name = "thmc10";
else if (man_id == 0x23)
type_name = "gl523sm";
else if (man_id == 0x54)
type_name = "mc1066";
else if (conv_rate == 0x00
&& (config & 0x7F) == 0x00
&& (status & 0xAB) == 0x00)
type_name = "lm84";
else
type_name = "max1617";
pr_debug("adm1021: Detected chip %s at adapter %d, address 0x%02x.\n",
type_name, i2c_adapter_id(adapter), client->addr);
strlcpy(info->type, type_name, I2C_NAME_SIZE);
return 0;
}
static int adm1021_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct adm1021_data *data;
int err;
data = devm_kzalloc(&client->dev, sizeof(struct adm1021_data),
GFP_KERNEL);
if (!data) {
pr_debug("adm1021: detect failed, devm_kzalloc failed!\n");
return -ENOMEM;
}
i2c_set_clientdata(client, data);
data->type = id->driver_data;
mutex_init(&data->update_lock);
if (data->type != lm84 && !read_only)
adm1021_init_client(client);
err = sysfs_create_group(&client->dev.kobj, &adm1021_group);
if (err)
return err;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto error;
}
return 0;
error:
sysfs_remove_group(&client->dev.kobj, &adm1021_group);
return err;
}
static void adm1021_init_client(struct i2c_client *client)
{
i2c_smbus_write_byte_data(client, ADM1021_REG_CONFIG_W,
i2c_smbus_read_byte_data(client, ADM1021_REG_CONFIG_R) & 0xBF);
i2c_smbus_write_byte_data(client, ADM1021_REG_CONV_RATE_W, 0x04);
}
static int adm1021_remove(struct i2c_client *client)
{
struct adm1021_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &adm1021_group);
return 0;
}
static struct adm1021_data *adm1021_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct adm1021_data *data = i2c_get_clientdata(client);
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
int i;
dev_dbg(&client->dev, "Starting adm1021 update\n");
for (i = 0; i < 2; i++) {
data->temp[i] = 1000 *
(s8) i2c_smbus_read_byte_data(
client, ADM1021_REG_TEMP(i));
data->temp_max[i] = 1000 *
(s8) i2c_smbus_read_byte_data(
client, ADM1021_REG_TOS_R(i));
data->temp_min[i] = 1000 *
(s8) i2c_smbus_read_byte_data(
client, ADM1021_REG_THYST_R(i));
}
data->alarms = i2c_smbus_read_byte_data(client,
ADM1021_REG_STATUS) & 0x7c;
if (data->type == adm1023) {
data->temp[1] += 125 * (i2c_smbus_read_byte_data(
client, ADM1023_REG_REM_TEMP_PREC) >> 5);
data->temp_max[1] += 125 * (i2c_smbus_read_byte_data(
client, ADM1023_REG_REM_TOS_PREC) >> 5);
data->temp_min[1] += 125 * (i2c_smbus_read_byte_data(
client, ADM1023_REG_REM_THYST_PREC) >> 5);
data->remote_temp_offset =
i2c_smbus_read_byte_data(client,
ADM1023_REG_REM_OFFSET);
data->remote_temp_offset_prec =
i2c_smbus_read_byte_data(client,
ADM1023_REG_REM_OFFSET_PREC);
}
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
