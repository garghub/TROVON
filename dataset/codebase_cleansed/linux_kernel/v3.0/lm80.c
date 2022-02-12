static inline unsigned char FAN_TO_REG(unsigned rpm, unsigned div)
{
if (rpm == 0)
return 255;
rpm = SENSORS_LIMIT(rpm, 1, 1000000);
return SENSORS_LIMIT((1350000 + rpm*div / 2) / (rpm*div), 1, 254);
}
static inline long TEMP_FROM_REG(u16 temp)
{
long res;
temp >>= 4;
if (temp < 0x0800)
res = 625 * (long) temp;
else
res = ((long) temp - 0x01000) * 625;
return res / 10;
}
static ssize_t show_fan_div(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm80_data *data = lm80_update_device(dev);
return sprintf(buf, "%d\n", DIV_FROM_REG(data->fan_div[nr]));
}
static ssize_t set_fan_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm80_data *data = i2c_get_clientdata(client);
long val = simple_strtoul(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->fan_min[nr] = FAN_TO_REG(val, DIV_FROM_REG(data->fan_div[nr]));
lm80_write_value(client, LM80_REG_FAN_MIN(nr + 1), data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_fan_div(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm80_data *data = i2c_get_clientdata(client);
unsigned long min, val = simple_strtoul(buf, NULL, 10);
u8 reg;
mutex_lock(&data->update_lock);
min = FAN_FROM_REG(data->fan_min[nr],
DIV_FROM_REG(data->fan_div[nr]));
switch (val) {
case 1: data->fan_div[nr] = 0; break;
case 2: data->fan_div[nr] = 1; break;
case 4: data->fan_div[nr] = 2; break;
case 8: data->fan_div[nr] = 3; break;
default:
dev_err(&client->dev, "fan_div value %ld not "
"supported. Choose one of 1, 2, 4 or 8!\n", val);
mutex_unlock(&data->update_lock);
return -EINVAL;
}
reg = (lm80_read_value(client, LM80_REG_FANDIV) & ~(3 << (2 * (nr + 1))))
| (data->fan_div[nr] << (2 * (nr + 1)));
lm80_write_value(client, LM80_REG_FANDIV, reg);
data->fan_min[nr] = FAN_TO_REG(min, DIV_FROM_REG(data->fan_div[nr]));
lm80_write_value(client, LM80_REG_FAN_MIN(nr + 1), data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_input1(struct device *dev, struct device_attribute *attr, char *buf)
{
struct lm80_data *data = lm80_update_device(dev);
return sprintf(buf, "%ld\n", TEMP_FROM_REG(data->temp));
}
static ssize_t show_alarms(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct lm80_data *data = lm80_update_device(dev);
return sprintf(buf, "%u\n", data->alarms);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int bitnr = to_sensor_dev_attr(attr)->index;
struct lm80_data *data = lm80_update_device(dev);
return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}
static int lm80_detect(struct i2c_client *client, struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int i, cur;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
if (lm80_read_value(client, LM80_REG_ALARM2) & 0xc0)
return -ENODEV;
for (i = 0x2a; i <= 0x3d; i++) {
cur = i2c_smbus_read_byte_data(client, i);
if ((i2c_smbus_read_byte_data(client, i + 0x40) != cur)
|| (i2c_smbus_read_byte_data(client, i + 0x80) != cur)
|| (i2c_smbus_read_byte_data(client, i + 0xc0) != cur))
return -ENODEV;
}
strlcpy(info->type, "lm80", I2C_NAME_SIZE);
return 0;
}
static int lm80_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct lm80_data *data;
int err;
data = kzalloc(sizeof(struct lm80_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
lm80_init_client(client);
data->fan_min[0] = lm80_read_value(client, LM80_REG_FAN_MIN(1));
data->fan_min[1] = lm80_read_value(client, LM80_REG_FAN_MIN(2));
if ((err = sysfs_create_group(&client->dev.kobj, &lm80_group)))
goto error_free;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto error_remove;
}
return 0;
error_remove:
sysfs_remove_group(&client->dev.kobj, &lm80_group);
error_free:
kfree(data);
exit:
return err;
}
static int lm80_remove(struct i2c_client *client)
{
struct lm80_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &lm80_group);
kfree(data);
return 0;
}
static int lm80_read_value(struct i2c_client *client, u8 reg)
{
return i2c_smbus_read_byte_data(client, reg);
}
static int lm80_write_value(struct i2c_client *client, u8 reg, u8 value)
{
return i2c_smbus_write_byte_data(client, reg, value);
}
static void lm80_init_client(struct i2c_client *client)
{
lm80_write_value(client, LM80_REG_CONFIG, 0x80);
lm80_write_value(client, LM80_REG_RES, 0x08);
lm80_write_value(client, LM80_REG_CONFIG, 0x01);
}
static struct lm80_data *lm80_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm80_data *data = i2c_get_clientdata(client);
int i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + 2 * HZ) || !data->valid) {
dev_dbg(&client->dev, "Starting lm80 update\n");
for (i = 0; i <= 6; i++) {
data->in[i] =
lm80_read_value(client, LM80_REG_IN(i));
data->in_min[i] =
lm80_read_value(client, LM80_REG_IN_MIN(i));
data->in_max[i] =
lm80_read_value(client, LM80_REG_IN_MAX(i));
}
data->fan[0] = lm80_read_value(client, LM80_REG_FAN1);
data->fan_min[0] =
lm80_read_value(client, LM80_REG_FAN_MIN(1));
data->fan[1] = lm80_read_value(client, LM80_REG_FAN2);
data->fan_min[1] =
lm80_read_value(client, LM80_REG_FAN_MIN(2));
data->temp =
(lm80_read_value(client, LM80_REG_TEMP) << 8) |
(lm80_read_value(client, LM80_REG_RES) & 0xf0);
data->temp_os_max =
lm80_read_value(client, LM80_REG_TEMP_OS_MAX);
data->temp_os_hyst =
lm80_read_value(client, LM80_REG_TEMP_OS_HYST);
data->temp_hot_max =
lm80_read_value(client, LM80_REG_TEMP_HOT_MAX);
data->temp_hot_hyst =
lm80_read_value(client, LM80_REG_TEMP_HOT_HYST);
i = lm80_read_value(client, LM80_REG_FANDIV);
data->fan_div[0] = (i >> 2) & 0x03;
data->fan_div[1] = (i >> 4) & 0x03;
data->alarms = lm80_read_value(client, LM80_REG_ALARM1) +
(lm80_read_value(client, LM80_REG_ALARM2) << 8);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static int __init sensors_lm80_init(void)
{
return i2c_add_driver(&lm80_driver);
}
static void __exit sensors_lm80_exit(void)
{
i2c_del_driver(&lm80_driver);
}
