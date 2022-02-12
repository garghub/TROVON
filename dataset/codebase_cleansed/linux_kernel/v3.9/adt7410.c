static int adt7410_temp_ready(struct i2c_client *client)
{
int i, status;
for (i = 0; i < 6; i++) {
status = i2c_smbus_read_byte_data(client, ADT7410_STATUS);
if (status < 0)
return status;
if (!(status & ADT7410_STAT_NOT_RDY))
return 0;
msleep(60);
}
return -ETIMEDOUT;
}
static struct adt7410_data *adt7410_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct adt7410_data *data = i2c_get_clientdata(client);
struct adt7410_data *ret = data;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
int i, status;
dev_dbg(&client->dev, "Starting update\n");
status = adt7410_temp_ready(client);
if (unlikely(status)) {
ret = ERR_PTR(status);
goto abort;
}
for (i = 0; i < ARRAY_SIZE(data->temp); i++) {
status = i2c_smbus_read_word_swapped(client,
ADT7410_REG_TEMP[i]);
if (unlikely(status < 0)) {
dev_dbg(dev,
"Failed to read value: reg %d, error %d\n",
ADT7410_REG_TEMP[i], status);
ret = ERR_PTR(status);
goto abort;
}
data->temp[i] = status;
}
status = i2c_smbus_read_byte_data(client, ADT7410_T_HYST);
if (unlikely(status < 0)) {
dev_dbg(dev,
"Failed to read value: reg %d, error %d\n",
ADT7410_T_HYST, status);
ret = ERR_PTR(status);
goto abort;
}
data->hyst = status;
data->last_updated = jiffies;
data->valid = true;
}
abort:
mutex_unlock(&data->update_lock);
return ret;
}
static s16 ADT7410_TEMP_TO_REG(long temp)
{
return DIV_ROUND_CLOSEST(clamp_val(temp, ADT7410_TEMP_MIN,
ADT7410_TEMP_MAX) * 128, 1000);
}
static int ADT7410_REG_TO_TEMP(struct adt7410_data *data, s16 reg)
{
if (!(data->config & ADT7410_RESOLUTION))
reg &= ADT7410_T13_VALUE_MASK;
return DIV_ROUND_CLOSEST(reg * 1000, 128);
}
static ssize_t adt7410_show_temp(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct adt7410_data *data = adt7410_update_device(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n", ADT7410_REG_TO_TEMP(data,
data->temp[attr->index]));
}
static ssize_t adt7410_set_temp(struct device *dev,
struct device_attribute *da,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct i2c_client *client = to_i2c_client(dev);
struct adt7410_data *data = i2c_get_clientdata(client);
int nr = attr->index;
long temp;
int ret;
ret = kstrtol(buf, 10, &temp);
if (ret)
return ret;
mutex_lock(&data->update_lock);
data->temp[nr] = ADT7410_TEMP_TO_REG(temp);
ret = i2c_smbus_write_word_swapped(client, ADT7410_REG_TEMP[nr],
data->temp[nr]);
if (ret)
count = ret;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t adt7410_show_t_hyst(struct device *dev,
struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct adt7410_data *data;
int nr = attr->index;
int hyst;
data = adt7410_update_device(dev);
if (IS_ERR(data))
return PTR_ERR(data);
hyst = (data->hyst & ADT7410_T_HYST_MASK) * 1000;
if (nr == 2)
hyst = -hyst;
return sprintf(buf, "%d\n",
ADT7410_REG_TO_TEMP(data, data->temp[nr]) - hyst);
}
static ssize_t adt7410_set_t_hyst(struct device *dev,
struct device_attribute *da,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct adt7410_data *data = i2c_get_clientdata(client);
int limit, ret;
long hyst;
ret = kstrtol(buf, 10, &hyst);
if (ret)
return ret;
limit = ADT7410_REG_TO_TEMP(data, data->temp[1]);
hyst = clamp_val(hyst, ADT7410_TEMP_MIN, ADT7410_TEMP_MAX);
data->hyst = clamp_val(DIV_ROUND_CLOSEST(limit - hyst, 1000), 0,
ADT7410_T_HYST_MASK);
ret = i2c_smbus_write_byte_data(client, ADT7410_T_HYST, data->hyst);
if (ret)
return ret;
return count;
}
static ssize_t adt7410_show_alarm(struct device *dev,
struct device_attribute *da,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int ret;
ret = i2c_smbus_read_byte_data(client, ADT7410_STATUS);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", !!(ret & attr->index));
}
static int adt7410_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct adt7410_data *data;
int ret;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
data = devm_kzalloc(&client->dev, sizeof(struct adt7410_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
ret = i2c_smbus_read_byte_data(client, ADT7410_CONFIG);
if (ret < 0) {
dev_dbg(&client->dev, "Can't read config? %d\n", ret);
return ret;
}
data->oldconfig = ret;
ret &= ~ADT7410_MODE_MASK;
data->config = ret | ADT7410_FULL | ADT7410_RESOLUTION |
ADT7410_EVENT_MODE;
if (data->config != data->oldconfig) {
ret = i2c_smbus_write_byte_data(client, ADT7410_CONFIG,
data->config);
if (ret)
return ret;
}
dev_dbg(&client->dev, "Config %02x\n", data->config);
ret = sysfs_create_group(&client->dev.kobj, &adt7410_group);
if (ret)
goto exit_restore;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
ret = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
dev_info(&client->dev, "sensor '%s'\n", client->name);
return 0;
exit_remove:
sysfs_remove_group(&client->dev.kobj, &adt7410_group);
exit_restore:
i2c_smbus_write_byte_data(client, ADT7410_CONFIG, data->oldconfig);
return ret;
}
static int adt7410_remove(struct i2c_client *client)
{
struct adt7410_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &adt7410_group);
if (data->oldconfig != data->config)
i2c_smbus_write_byte_data(client, ADT7410_CONFIG,
data->oldconfig);
return 0;
}
static int adt7410_suspend(struct device *dev)
{
int ret;
struct i2c_client *client = to_i2c_client(dev);
struct adt7410_data *data = i2c_get_clientdata(client);
ret = i2c_smbus_write_byte_data(client, ADT7410_CONFIG,
data->config | ADT7410_PD);
return ret;
}
static int adt7410_resume(struct device *dev)
{
int ret;
struct i2c_client *client = to_i2c_client(dev);
struct adt7410_data *data = i2c_get_clientdata(client);
ret = i2c_smbus_write_byte_data(client, ADT7410_CONFIG, data->config);
return ret;
}
