static inline s16 LM77_TEMP_TO_REG(int temp)
{
return (temp / 500) * 8;
}
static inline int LM77_TEMP_FROM_REG(s16 reg)
{
return (reg / 8) * 500;
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
static struct lm77_data *lm77_update_device(struct device *dev)
{
struct lm77_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
dev_dbg(&client->dev, "Starting lm77 update\n");
for (i = 0; i < t_num_temp; i++) {
data->temp[i] =
LM77_TEMP_FROM_REG(lm77_read_value(client,
temp_regs[i]));
}
data->alarms =
lm77_read_value(client, LM77_REG_TEMP) & 0x0007;
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm77_data *data = lm77_update_device(dev);
return sprintf(buf, "%d\n", data->temp[attr->index]);
}
static ssize_t show_temp_hyst(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm77_data *data = lm77_update_device(dev);
int nr = attr->index;
int temp;
temp = nr == t_min ? data->temp[nr] + data->temp[t_hyst] :
data->temp[nr] - data->temp[t_hyst];
return sprintf(buf, "%d\n", temp);
}
static ssize_t set_temp(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm77_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int nr = attr->index;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
val = clamp_val(val, LM77_TEMP_MIN, LM77_TEMP_MAX);
mutex_lock(&data->update_lock);
data->temp[nr] = val;
lm77_write_value(client, temp_regs[nr], LM77_TEMP_TO_REG(val));
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_temp_hyst(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct lm77_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
val = clamp_val(data->temp[t_crit] - val, LM77_TEMP_MIN, LM77_TEMP_MAX);
data->temp[t_hyst] = val;
lm77_write_value(client, LM77_REG_TEMP_HYST,
LM77_TEMP_TO_REG(data->temp[t_hyst]));
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
static void lm77_init_client(struct i2c_client *client)
{
int conf = lm77_read_value(client, LM77_REG_CONF);
if (conf & 1)
lm77_write_value(client, LM77_REG_CONF, conf & 0xfe);
}
static int lm77_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct device *hwmon_dev;
struct lm77_data *data;
data = devm_kzalloc(dev, sizeof(struct lm77_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = client;
mutex_init(&data->update_lock);
lm77_init_client(client);
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data, lm77_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
