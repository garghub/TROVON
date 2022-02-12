static struct max1668_data *max1668_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct max1668_data *data = i2c_get_clientdata(client);
struct max1668_data *ret = data;
s32 val;
int i;
mutex_lock(&data->update_lock);
if (data->valid && !time_after(jiffies,
data->last_updated + HZ + HZ / 2))
goto abort;
for (i = 0; i < 5; i++) {
val = i2c_smbus_read_byte_data(client, MAX1668_REG_TEMP(i));
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->temp[i] = (s8) val;
val = i2c_smbus_read_byte_data(client, MAX1668_REG_LIMH_RD(i));
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->temp_max[i] = (s8) val;
val = i2c_smbus_read_byte_data(client, MAX1668_REG_LIML_RD(i));
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->temp_min[i] = (s8) val;
}
val = i2c_smbus_read_byte_data(client, MAX1668_REG_STAT1);
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->alarms = val << 8;
val = i2c_smbus_read_byte_data(client, MAX1668_REG_STAT2);
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->alarms |= val;
data->last_updated = jiffies;
data->valid = 1;
abort:
mutex_unlock(&data->update_lock);
return ret;
}
static ssize_t show_temp(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct max1668_data *data = max1668_update_device(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n", data->temp[index] * 1000);
}
static ssize_t show_temp_max(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct max1668_data *data = max1668_update_device(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n", data->temp_max[index] * 1000);
}
static ssize_t show_temp_min(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct max1668_data *data = max1668_update_device(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n", data->temp_min[index] * 1000);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int index = to_sensor_dev_attr(attr)->index;
struct max1668_data *data = max1668_update_device(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%u\n", (data->alarms >> index) & 0x1);
}
static ssize_t show_fault(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct max1668_data *data = max1668_update_device(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%u\n",
(data->alarms & (1 << 12)) && data->temp[index] == 127);
}
static ssize_t set_temp_max(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
int index = to_sensor_dev_attr(devattr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct max1668_data *data = i2c_get_clientdata(client);
long temp;
int ret;
ret = kstrtol(buf, 10, &temp);
if (ret < 0)
return ret;
mutex_lock(&data->update_lock);
data->temp_max[index] = SENSORS_LIMIT(temp/1000, -128, 127);
if (i2c_smbus_write_byte_data(client,
MAX1668_REG_LIMH_WR(index),
data->temp_max[index]))
count = -EIO;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_temp_min(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
int index = to_sensor_dev_attr(devattr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct max1668_data *data = i2c_get_clientdata(client);
long temp;
int ret;
ret = kstrtol(buf, 10, &temp);
if (ret < 0)
return ret;
mutex_lock(&data->update_lock);
data->temp_min[index] = SENSORS_LIMIT(temp/1000, -128, 127);
if (i2c_smbus_write_byte_data(client,
MAX1668_REG_LIML_WR(index),
data->temp_max[index]))
count = -EIO;
mutex_unlock(&data->update_lock);
return count;
}
static umode_t max1668_attribute_mode(struct kobject *kobj,
struct attribute *attr, int index)
{
umode_t ret = S_IRUGO;
if (read_only)
return ret;
if (attr == &sensor_dev_attr_temp1_max.dev_attr.attr ||
attr == &sensor_dev_attr_temp2_max.dev_attr.attr ||
attr == &sensor_dev_attr_temp3_max.dev_attr.attr ||
attr == &sensor_dev_attr_temp4_max.dev_attr.attr ||
attr == &sensor_dev_attr_temp5_max.dev_attr.attr ||
attr == &sensor_dev_attr_temp1_min.dev_attr.attr ||
attr == &sensor_dev_attr_temp2_min.dev_attr.attr ||
attr == &sensor_dev_attr_temp3_min.dev_attr.attr ||
attr == &sensor_dev_attr_temp4_min.dev_attr.attr ||
attr == &sensor_dev_attr_temp5_min.dev_attr.attr)
ret |= S_IWUSR;
return ret;
}
static int max1668_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
const char *type_name;
int man_id, dev_id;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
man_id = i2c_smbus_read_byte_data(client, MAX1668_REG_MAN_ID);
if (man_id != MAN_ID_MAXIM)
return -ENODEV;
dev_id = i2c_smbus_read_byte_data(client, MAX1668_REG_DEV_ID);
if (dev_id < 0)
return -ENODEV;
type_name = NULL;
if (dev_id == DEV_ID_MAX1668)
type_name = "max1668";
else if (dev_id == DEV_ID_MAX1805)
type_name = "max1805";
else if (dev_id == DEV_ID_MAX1989)
type_name = "max1989";
if (!type_name)
return -ENODEV;
strlcpy(info->type, type_name, I2C_NAME_SIZE);
return 0;
}
static int max1668_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct max1668_data *data;
int err;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
data = kzalloc(sizeof(struct max1668_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
data->type = id->driver_data;
mutex_init(&data->update_lock);
err = sysfs_create_group(&client->dev.kobj, &max1668_group_common);
if (err)
goto error_free;
if (data->type == max1668 || data->type == max1989) {
err = sysfs_create_group(&client->dev.kobj,
&max1668_group_unique);
if (err)
goto error_sysrem0;
}
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto error_sysrem1;
}
return 0;
error_sysrem1:
if (data->type == max1668 || data->type == max1989)
sysfs_remove_group(&client->dev.kobj, &max1668_group_unique);
error_sysrem0:
sysfs_remove_group(&client->dev.kobj, &max1668_group_common);
error_free:
kfree(data);
return err;
}
static int max1668_remove(struct i2c_client *client)
{
struct max1668_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
if (data->type == max1668 || data->type == max1989)
sysfs_remove_group(&client->dev.kobj, &max1668_group_unique);
sysfs_remove_group(&client->dev.kobj, &max1668_group_common);
kfree(data);
return 0;
}
