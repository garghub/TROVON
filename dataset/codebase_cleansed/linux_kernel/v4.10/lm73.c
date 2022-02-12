static ssize_t set_temp(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct lm73_data *data = dev_get_drvdata(dev);
long temp;
short value;
s32 err;
int status = kstrtol(buf, 10, &temp);
if (status < 0)
return status;
value = clamp_val(temp / 250, LM73_TEMP_MIN, LM73_TEMP_MAX) << 5;
err = i2c_smbus_write_word_swapped(data->client, attr->index, value);
return (err < 0) ? err : count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct lm73_data *data = dev_get_drvdata(dev);
int temp;
s32 err = i2c_smbus_read_word_swapped(data->client, attr->index);
if (err < 0)
return err;
temp = (((s16) err) * 250) / 32;
return scnprintf(buf, PAGE_SIZE, "%d\n", temp);
}
static ssize_t set_convrate(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct lm73_data *data = dev_get_drvdata(dev);
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
err = i2c_smbus_write_byte_data(data->client, LM73_REG_CTRL,
data->ctrl);
mutex_unlock(&data->lock);
if (err < 0)
return err;
return count;
}
static ssize_t show_convrate(struct device *dev, struct device_attribute *da,
char *buf)
{
struct lm73_data *data = dev_get_drvdata(dev);
int res;
res = (data->ctrl & LM73_CTRL_RES_MASK) >> LM73_CTRL_RES_SHIFT;
return scnprintf(buf, PAGE_SIZE, "%hu\n", lm73_convrates[res]);
}
static ssize_t show_maxmin_alarm(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct lm73_data *data = dev_get_drvdata(dev);
s32 ctrl;
mutex_lock(&data->lock);
ctrl = i2c_smbus_read_byte_data(data->client, LM73_REG_CTRL);
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
struct device *dev = &client->dev;
struct device *hwmon_dev;
struct lm73_data *data;
int ctrl;
data = devm_kzalloc(dev, sizeof(struct lm73_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = client;
mutex_init(&data->lock);
ctrl = i2c_smbus_read_byte_data(client, LM73_REG_CTRL);
if (ctrl < 0)
return ctrl;
data->ctrl = ctrl;
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data, lm73_groups);
if (IS_ERR(hwmon_dev))
return PTR_ERR(hwmon_dev);
dev_info(dev, "sensor '%s'\n", client->name);
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
