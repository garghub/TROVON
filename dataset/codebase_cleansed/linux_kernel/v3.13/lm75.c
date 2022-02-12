static ssize_t show_temp(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct lm75_data *data = lm75_update_device(dev);
long temp;
if (IS_ERR(data))
return PTR_ERR(data);
temp = ((data->temp[attr->index] >> (16 - data->resolution)) * 1000)
>> (data->resolution - 8);
return sprintf(buf, "%ld\n", temp);
}
static ssize_t set_temp(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct i2c_client *client = to_i2c_client(dev);
struct lm75_data *data = i2c_get_clientdata(client);
int nr = attr->index;
long temp;
int error;
u8 resolution;
error = kstrtol(buf, 10, &temp);
if (error)
return error;
if (attr->index && data->resolution_limits)
resolution = data->resolution_limits;
else
resolution = data->resolution;
mutex_lock(&data->update_lock);
temp = clamp_val(temp, LM75_TEMP_MIN, LM75_TEMP_MAX);
data->temp[nr] = DIV_ROUND_CLOSEST(temp << (resolution - 8),
1000) << (16 - resolution);
lm75_write_value(client, LM75_REG_TEMP[nr], data->temp[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static int
lm75_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct lm75_data *data;
int status;
u8 set_mask, clr_mask;
int new;
enum lm75_type kind = id->driver_data;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA))
return -EIO;
data = devm_kzalloc(&client->dev, sizeof(struct lm75_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
set_mask = 0;
clr_mask = LM75_SHUTDOWN;
switch (kind) {
case adt75:
clr_mask |= 1 << 5;
data->resolution = 12;
data->sample_time = HZ / 8;
break;
case ds1775:
case ds75:
case stds75:
clr_mask |= 3 << 5;
set_mask |= 2 << 5;
data->resolution = 11;
data->sample_time = HZ;
break;
case ds7505:
set_mask |= 3 << 5;
data->resolution = 12;
data->sample_time = HZ / 4;
break;
case g751:
case lm75:
case lm75a:
data->resolution = 9;
data->sample_time = HZ / 2;
break;
case max6625:
data->resolution = 9;
data->sample_time = HZ / 4;
break;
case max6626:
data->resolution = 12;
data->resolution_limits = 9;
data->sample_time = HZ / 4;
break;
case tcn75:
data->resolution = 9;
data->sample_time = HZ / 8;
break;
case mcp980x:
data->resolution_limits = 9;
case tmp100:
case tmp101:
set_mask |= 3 << 5;
data->resolution = 12;
data->sample_time = HZ;
clr_mask |= 1 << 7;
break;
case tmp105:
case tmp175:
case tmp275:
case tmp75:
set_mask |= 3 << 5;
clr_mask |= 1 << 7;
data->resolution = 12;
data->sample_time = HZ / 2;
break;
}
status = lm75_read_value(client, LM75_REG_CONF);
if (status < 0) {
dev_dbg(&client->dev, "Can't read config? %d\n", status);
return status;
}
data->orig_conf = status;
new = status & ~clr_mask;
new |= set_mask;
if (status != new)
lm75_write_value(client, LM75_REG_CONF, new);
dev_dbg(&client->dev, "Config %02x\n", new);
status = sysfs_create_group(&client->dev.kobj, &lm75_group);
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
sysfs_remove_group(&client->dev.kobj, &lm75_group);
return status;
}
static int lm75_remove(struct i2c_client *client)
{
struct lm75_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &lm75_group);
lm75_write_value(client, LM75_REG_CONF, data->orig_conf);
return 0;
}
static int lm75_detect(struct i2c_client *new_client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = new_client->adapter;
int i;
int conf, hyst, os;
bool is_lm75a = 0;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
conf = i2c_smbus_read_byte_data(new_client, 1);
if (conf & 0xe0)
return -ENODEV;
if (i2c_smbus_read_byte_data(new_client, 7) == LM75A_ID) {
if (i2c_smbus_read_byte_data(new_client, 4) != 0xff
|| i2c_smbus_read_byte_data(new_client, 5) != 0xff
|| i2c_smbus_read_byte_data(new_client, 6) != 0xff)
return -ENODEV;
is_lm75a = 1;
hyst = i2c_smbus_read_byte_data(new_client, 2);
os = i2c_smbus_read_byte_data(new_client, 3);
} else {
hyst = i2c_smbus_read_byte_data(new_client, 2);
if (i2c_smbus_read_byte_data(new_client, 4) != hyst
|| i2c_smbus_read_byte_data(new_client, 5) != hyst
|| i2c_smbus_read_byte_data(new_client, 6) != hyst
|| i2c_smbus_read_byte_data(new_client, 7) != hyst)
return -ENODEV;
os = i2c_smbus_read_byte_data(new_client, 3);
if (i2c_smbus_read_byte_data(new_client, 4) != os
|| i2c_smbus_read_byte_data(new_client, 5) != os
|| i2c_smbus_read_byte_data(new_client, 6) != os
|| i2c_smbus_read_byte_data(new_client, 7) != os)
return -ENODEV;
}
for (i = 8; i <= 248; i += 40) {
if (i2c_smbus_read_byte_data(new_client, i + 1) != conf
|| i2c_smbus_read_byte_data(new_client, i + 2) != hyst
|| i2c_smbus_read_byte_data(new_client, i + 3) != os)
return -ENODEV;
if (is_lm75a && i2c_smbus_read_byte_data(new_client, i + 7)
!= LM75A_ID)
return -ENODEV;
}
strlcpy(info->type, is_lm75a ? "lm75a" : "lm75", I2C_NAME_SIZE);
return 0;
}
static int lm75_suspend(struct device *dev)
{
int status;
struct i2c_client *client = to_i2c_client(dev);
status = lm75_read_value(client, LM75_REG_CONF);
if (status < 0) {
dev_dbg(&client->dev, "Can't read config? %d\n", status);
return status;
}
status = status | LM75_SHUTDOWN;
lm75_write_value(client, LM75_REG_CONF, status);
return 0;
}
static int lm75_resume(struct device *dev)
{
int status;
struct i2c_client *client = to_i2c_client(dev);
status = lm75_read_value(client, LM75_REG_CONF);
if (status < 0) {
dev_dbg(&client->dev, "Can't read config? %d\n", status);
return status;
}
status = status & ~LM75_SHUTDOWN;
lm75_write_value(client, LM75_REG_CONF, status);
return 0;
}
static int lm75_read_value(struct i2c_client *client, u8 reg)
{
if (reg == LM75_REG_CONF)
return i2c_smbus_read_byte_data(client, reg);
else
return i2c_smbus_read_word_swapped(client, reg);
}
static int lm75_write_value(struct i2c_client *client, u8 reg, u16 value)
{
if (reg == LM75_REG_CONF)
return i2c_smbus_write_byte_data(client, reg, value);
else
return i2c_smbus_write_word_swapped(client, reg, value);
}
static struct lm75_data *lm75_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm75_data *data = i2c_get_clientdata(client);
struct lm75_data *ret = data;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + data->sample_time)
|| !data->valid) {
int i;
dev_dbg(&client->dev, "Starting lm75 update\n");
for (i = 0; i < ARRAY_SIZE(data->temp); i++) {
int status;
status = lm75_read_value(client, LM75_REG_TEMP[i]);
if (unlikely(status < 0)) {
dev_dbg(dev,
"LM75: Failed to read value: reg %d, error %d\n",
LM75_REG_TEMP[i], status);
ret = ERR_PTR(status);
data->valid = 0;
goto abort;
}
data->temp[i] = status;
}
data->last_updated = jiffies;
data->valid = 1;
}
abort:
mutex_unlock(&data->update_lock);
return ret;
}
