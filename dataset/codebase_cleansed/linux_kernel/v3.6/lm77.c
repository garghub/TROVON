static inline s16 LM77_TEMP_TO_REG(int temp)
{
int ntemp = SENSORS_LIMIT(temp, LM77_TEMP_MIN, LM77_TEMP_MAX);
return (ntemp / 500) * 8;
}
static inline int LM77_TEMP_FROM_REG(s16 reg)
{
return (reg / 8) * 500;
}
static ssize_t show_temp_crit_hyst(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lm77_data *data = lm77_update_device(dev);
return sprintf(buf, "%d\n", data->temp_crit - data->temp_hyst);
}
static ssize_t show_temp_min_hyst(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lm77_data *data = lm77_update_device(dev);
return sprintf(buf, "%d\n", data->temp_min + data->temp_hyst);
}
static ssize_t show_temp_max_hyst(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lm77_data *data = lm77_update_device(dev);
return sprintf(buf, "%d\n", data->temp_max - data->temp_hyst);
}
static ssize_t set_temp_crit_hyst(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm77_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_hyst = data->temp_crit - val;
lm77_write_value(client, LM77_REG_TEMP_HYST,
LM77_TEMP_TO_REG(data->temp_hyst));
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_temp_crit(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm77_data *data = i2c_get_clientdata(client);
int oldcrithyst;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
oldcrithyst = data->temp_crit - data->temp_hyst;
data->temp_crit = val;
data->temp_hyst = data->temp_crit - oldcrithyst;
lm77_write_value(client, LM77_REG_TEMP_CRIT,
LM77_TEMP_TO_REG(data->temp_crit));
lm77_write_value(client, LM77_REG_TEMP_HYST,
LM77_TEMP_TO_REG(data->temp_hyst));
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int bitnr = to_sensor_dev_attr(attr)->index;
struct lm77_data *data = lm77_update_device(dev);
return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}
static int lm77_detect(struct i2c_client *client, struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int i, cur, conf, hyst, crit, min, max;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
cur = i2c_smbus_read_word_data(client, 0);
conf = i2c_smbus_read_byte_data(client, 1);
hyst = i2c_smbus_read_word_data(client, 2);
crit = i2c_smbus_read_word_data(client, 3);
min = i2c_smbus_read_word_data(client, 4);
max = i2c_smbus_read_word_data(client, 5);
for (i = 8; i <= 0xff; i += 8) {
if (i2c_smbus_read_byte_data(client, i + 1) != conf
|| i2c_smbus_read_word_data(client, i + 2) != hyst
|| i2c_smbus_read_word_data(client, i + 3) != crit
|| i2c_smbus_read_word_data(client, i + 4) != min
|| i2c_smbus_read_word_data(client, i + 5) != max)
return -ENODEV;
}
if (((cur & 0x00f0) != 0xf0 && (cur & 0x00f0) != 0x0)
|| ((hyst & 0x00f0) != 0xf0 && (hyst & 0x00f0) != 0x0)
|| ((crit & 0x00f0) != 0xf0 && (crit & 0x00f0) != 0x0)
|| ((min & 0x00f0) != 0xf0 && (min & 0x00f0) != 0x0)
|| ((max & 0x00f0) != 0xf0 && (max & 0x00f0) != 0x0))
return -ENODEV;
if (conf & 0xe0)
return -ENODEV;
cur = i2c_smbus_read_word_data(client, 0);
if (i2c_smbus_read_word_data(client, 6) != cur
|| i2c_smbus_read_word_data(client, 7) != cur)
return -ENODEV;
hyst = i2c_smbus_read_word_data(client, 2);
if (i2c_smbus_read_word_data(client, 6) != hyst
|| i2c_smbus_read_word_data(client, 7) != hyst)
return -ENODEV;
min = i2c_smbus_read_word_data(client, 4);
if (i2c_smbus_read_word_data(client, 6) != min
|| i2c_smbus_read_word_data(client, 7) != min)
return -ENODEV;
strlcpy(info->type, "lm77", I2C_NAME_SIZE);
return 0;
}
static int lm77_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct lm77_data *data;
int err;
data = devm_kzalloc(dev, sizeof(struct lm77_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
data->valid = 0;
mutex_init(&data->update_lock);
lm77_init_client(client);
err = sysfs_create_group(&dev->kobj, &lm77_group);
if (err)
return err;
data->hwmon_dev = hwmon_device_register(dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
return 0;
exit_remove:
sysfs_remove_group(&dev->kobj, &lm77_group);
return err;
}
static int lm77_remove(struct i2c_client *client)
{
struct lm77_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &lm77_group);
return 0;
}
static u16 lm77_read_value(struct i2c_client *client, u8 reg)
{
if (reg == LM77_REG_CONF)
return i2c_smbus_read_byte_data(client, reg);
else
return i2c_smbus_read_word_swapped(client, reg);
}
static int lm77_write_value(struct i2c_client *client, u8 reg, u16 value)
{
if (reg == LM77_REG_CONF)
return i2c_smbus_write_byte_data(client, reg, value);
else
return i2c_smbus_write_word_swapped(client, reg, value);
}
static void lm77_init_client(struct i2c_client *client)
{
int conf = lm77_read_value(client, LM77_REG_CONF);
if (conf & 1)
lm77_write_value(client, LM77_REG_CONF, conf & 0xfe);
}
static struct lm77_data *lm77_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm77_data *data = i2c_get_clientdata(client);
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
dev_dbg(&client->dev, "Starting lm77 update\n");
data->temp_input =
LM77_TEMP_FROM_REG(lm77_read_value(client,
LM77_REG_TEMP));
data->temp_hyst =
LM77_TEMP_FROM_REG(lm77_read_value(client,
LM77_REG_TEMP_HYST));
data->temp_crit =
LM77_TEMP_FROM_REG(lm77_read_value(client,
LM77_REG_TEMP_CRIT));
data->temp_min =
LM77_TEMP_FROM_REG(lm77_read_value(client,
LM77_REG_TEMP_MIN));
data->temp_max =
LM77_TEMP_FROM_REG(lm77_read_value(client,
LM77_REG_TEMP_MAX));
data->alarms =
lm77_read_value(client, LM77_REG_TEMP) & 0x0007;
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
