static ssize_t set_temp(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct i2c_client *client = to_i2c_client(dev);
long temp;
short value;
s32 err;
int status = kstrtol(buf, 10, &temp);
if (status < 0)
return status;
value = clamp_val(temp / 250, LM73_TEMP_MIN, LM73_TEMP_MAX) << 5;
err = i2c_smbus_write_word_swapped(client, attr->index, value);
return (err < 0) ? err : count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct i2c_client *client = to_i2c_client(dev);
int temp;
s32 err = i2c_smbus_read_word_swapped(client, attr->index);
if (err < 0)
return err;
temp = (((s16) err) * 250) / 32;
return scnprintf(buf, PAGE_SIZE, "%d\n", temp);
}
static ssize_t set_convrate(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm73_data *data = i2c_get_clientdata(client);
unsigned long convrate;
s32 err;
int res = 0;
err = kstrtoul(buf, 10, &convrate);
if (err < 0)
return err;
while (res < (ARRAY_SIZE(lm73_convrates) - 1) &&
convrate > lm73_convrates[res])
res++;
mutex_lock(&data->lock);
data->ctrl &= LM73_CTRL_TO_MASK;
data->ctrl |= res << LM73_CTRL_RES_SHIFT;
err = i2c_smbus_write_byte_data(client, LM73_REG_CTRL, data->ctrl);
mutex_unlock(&data->lock);
if (err < 0)
return err;
return count;
}
static ssize_t show_convrate(struct device *dev, struct device_attribute *da,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm73_data *data = i2c_get_clientdata(client);
int res;
res = (data->ctrl & LM73_CTRL_RES_MASK) >> LM73_CTRL_RES_SHIFT;
return scnprintf(buf, PAGE_SIZE, "%hu\n", lm73_convrates[res]);
}
static ssize_t show_maxmin_alarm(struct device *dev,
struct device_attribute *da, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct lm73_data *data = i2c_get_clientdata(client);
s32 ctrl;
mutex_lock(&data->lock);
ctrl = i2c_smbus_read_byte_data(client, LM73_REG_CTRL);
if (ctrl < 0)
goto abort;
data->ctrl = ctrl;
mutex_unlock(&data->lock);
return scnprintf(buf, PAGE_SIZE, "%d\n", (ctrl >> attr->index) & 1);
abort:
mutex_unlock(&data->lock);
return ctrl;
}
static int
lm73_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
int status;
struct lm73_data *data;
int ctrl;
data = devm_kzalloc(&client->dev, sizeof(struct lm73_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->lock);
ctrl = i2c_smbus_read_byte_data(client, LM73_REG_CTRL);
if (ctrl < 0)
return ctrl;
data->ctrl = ctrl;
status = sysfs_create_group(&client->dev.kobj, &lm73_group);
if (status)
return status;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
status = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
dev_info(&client->dev, "%s: sensor '%s'\n",
dev_name(data->hwmon_dev), client->name);
return 0;
exit_remove:
sysfs_remove_group(&client->dev.kobj, &lm73_group);
return status;
}
static int lm73_remove(struct i2c_client *client)
{
struct lm73_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &lm73_group);
return 0;
}
static int lm73_detect(struct i2c_client *new_client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = new_client->adapter;
int id, ctrl, conf;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
ctrl = i2c_smbus_read_byte_data(new_client, LM73_REG_CTRL);
if (ctrl < 0 || (ctrl & 0x10))
return -ENODEV;
conf = i2c_smbus_read_byte_data(new_client, LM73_REG_CONF);
if (conf < 0 || (conf & 0x0c))
return -ENODEV;
id = i2c_smbus_read_byte_data(new_client, LM73_REG_ID);
if (id < 0 || id != (LM73_ID & 0xff))
return -ENODEV;
id = i2c_smbus_read_word_data(new_client, LM73_REG_ID);
if (id < 0 || id != LM73_ID)
return -ENODEV;
strlcpy(info->type, "lm73", I2C_NAME_SIZE);
return 0;
}
