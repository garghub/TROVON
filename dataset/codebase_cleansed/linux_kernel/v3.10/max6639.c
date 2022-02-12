static struct max6639_data *max6639_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct max6639_data *data = i2c_get_clientdata(client);
struct max6639_data *ret = data;
int i;
int status_reg;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + 2 * HZ) || !data->valid) {
int res;
dev_dbg(&client->dev, "Starting max6639 update\n");
status_reg = i2c_smbus_read_byte_data(client,
MAX6639_REG_STATUS);
if (status_reg < 0) {
ret = ERR_PTR(status_reg);
goto abort;
}
data->status = status_reg;
for (i = 0; i < 2; i++) {
res = i2c_smbus_read_byte_data(client,
MAX6639_REG_FAN_CNT(i));
if (res < 0) {
ret = ERR_PTR(res);
goto abort;
}
data->fan[i] = res;
res = i2c_smbus_read_byte_data(client,
MAX6639_REG_TEMP_EXT(i));
if (res < 0) {
ret = ERR_PTR(res);
goto abort;
}
data->temp[i] = res >> 5;
data->temp_fault[i] = res & 0x01;
res = i2c_smbus_read_byte_data(client,
MAX6639_REG_TEMP(i));
if (res < 0) {
ret = ERR_PTR(res);
goto abort;
}
data->temp[i] |= res << 3;
}
data->last_updated = jiffies;
data->valid = 1;
}
abort:
mutex_unlock(&data->update_lock);
return ret;
}
static ssize_t show_temp_input(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
long temp;
struct max6639_data *data = max6639_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
if (IS_ERR(data))
return PTR_ERR(data);
temp = data->temp[attr->index] * 125;
return sprintf(buf, "%ld\n", temp);
}
static ssize_t show_temp_fault(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct max6639_data *data = max6639_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n", data->temp_fault[attr->index]);
}
static ssize_t show_temp_max(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct max6639_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
return sprintf(buf, "%d\n", (data->temp_therm[attr->index] * 1000));
}
static ssize_t set_temp_max(struct device *dev,
struct device_attribute *dev_attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct max6639_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
unsigned long val;
int res;
res = kstrtoul(buf, 10, &val);
if (res)
return res;
mutex_lock(&data->update_lock);
data->temp_therm[attr->index] = TEMP_LIMIT_TO_REG(val);
i2c_smbus_write_byte_data(client,
MAX6639_REG_THERM_LIMIT(attr->index),
data->temp_therm[attr->index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_crit(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct max6639_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
return sprintf(buf, "%d\n", (data->temp_alert[attr->index] * 1000));
}
static ssize_t set_temp_crit(struct device *dev,
struct device_attribute *dev_attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct max6639_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
unsigned long val;
int res;
res = kstrtoul(buf, 10, &val);
if (res)
return res;
mutex_lock(&data->update_lock);
data->temp_alert[attr->index] = TEMP_LIMIT_TO_REG(val);
i2c_smbus_write_byte_data(client,
MAX6639_REG_ALERT_LIMIT(attr->index),
data->temp_alert[attr->index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_emergency(struct device *dev,
struct device_attribute *dev_attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct max6639_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
return sprintf(buf, "%d\n", (data->temp_ot[attr->index] * 1000));
}
static ssize_t set_temp_emergency(struct device *dev,
struct device_attribute *dev_attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct max6639_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
unsigned long val;
int res;
res = kstrtoul(buf, 10, &val);
if (res)
return res;
mutex_lock(&data->update_lock);
data->temp_ot[attr->index] = TEMP_LIMIT_TO_REG(val);
i2c_smbus_write_byte_data(client,
MAX6639_REG_OT_LIMIT(attr->index),
data->temp_ot[attr->index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct max6639_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
return sprintf(buf, "%d\n", data->pwm[attr->index] * 255 / 120);
}
static ssize_t set_pwm(struct device *dev,
struct device_attribute *dev_attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct max6639_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
unsigned long val;
int res;
res = kstrtoul(buf, 10, &val);
if (res)
return res;
val = clamp_val(val, 0, 255);
mutex_lock(&data->update_lock);
data->pwm[attr->index] = (u8)(val * 120 / 255);
i2c_smbus_write_byte_data(client,
MAX6639_REG_TARGTDUTY(attr->index),
data->pwm[attr->index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_fan_input(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct max6639_data *data = max6639_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan[attr->index],
data->rpm_range));
}
static ssize_t show_alarm(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct max6639_data *data = max6639_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n", !!(data->status & (1 << attr->index)));
}
static int rpm_range_to_reg(int range)
{
int i;
for (i = 0; i < ARRAY_SIZE(rpm_ranges); i++) {
if (rpm_ranges[i] == range)
return i;
}
return 1;
}
static int max6639_init_client(struct i2c_client *client)
{
struct max6639_data *data = i2c_get_clientdata(client);
struct max6639_platform_data *max6639_info =
client->dev.platform_data;
int i;
int rpm_range = 1;
int err;
err = i2c_smbus_write_byte_data(client, MAX6639_REG_GCONFIG,
MAX6639_GCONFIG_POR);
if (err)
goto exit;
if (max6639_info && max6639_info->ppr > 0 &&
max6639_info->ppr < 5)
data->ppr = max6639_info->ppr;
else
data->ppr = 2;
data->ppr -= 1;
if (max6639_info)
rpm_range = rpm_range_to_reg(max6639_info->rpm_range);
data->rpm_range = rpm_range;
for (i = 0; i < 2; i++) {
err = i2c_smbus_write_byte_data(client,
MAX6639_REG_FAN_PPR(i),
data->ppr << 6);
if (err)
goto exit;
err = i2c_smbus_write_byte_data(client,
MAX6639_REG_FAN_CONFIG1(i),
MAX6639_FAN_CONFIG1_PWM | rpm_range);
if (err)
goto exit;
if (max6639_info && max6639_info->pwm_polarity == 0)
err = i2c_smbus_write_byte_data(client,
MAX6639_REG_FAN_CONFIG2a(i), 0x00);
else
err = i2c_smbus_write_byte_data(client,
MAX6639_REG_FAN_CONFIG2a(i), 0x02);
if (err)
goto exit;
err = i2c_smbus_write_byte_data(client,
MAX6639_REG_FAN_CONFIG3(i),
MAX6639_FAN_CONFIG3_THERM_FULL_SPEED | 0x03);
if (err)
goto exit;
data->temp_therm[i] = 80;
data->temp_alert[i] = 90;
data->temp_ot[i] = 100;
err = i2c_smbus_write_byte_data(client,
MAX6639_REG_THERM_LIMIT(i),
data->temp_therm[i]);
if (err)
goto exit;
err = i2c_smbus_write_byte_data(client,
MAX6639_REG_ALERT_LIMIT(i),
data->temp_alert[i]);
if (err)
goto exit;
err = i2c_smbus_write_byte_data(client,
MAX6639_REG_OT_LIMIT(i), data->temp_ot[i]);
if (err)
goto exit;
data->pwm[i] = 120;
err = i2c_smbus_write_byte_data(client,
MAX6639_REG_TARGTDUTY(i), data->pwm[i]);
if (err)
goto exit;
}
err = i2c_smbus_write_byte_data(client, MAX6639_REG_GCONFIG,
MAX6639_GCONFIG_DISABLE_TIMEOUT | MAX6639_GCONFIG_CH2_LOCAL |
MAX6639_GCONFIG_PWM_FREQ_HI);
exit:
return err;
}
static int max6639_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int dev_id, manu_id;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
dev_id = i2c_smbus_read_byte_data(client, MAX6639_REG_DEVID);
manu_id = i2c_smbus_read_byte_data(client, MAX6639_REG_MANUID);
if (dev_id != 0x58 || manu_id != 0x4D)
return -ENODEV;
strlcpy(info->type, "max6639", I2C_NAME_SIZE);
return 0;
}
static int max6639_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct max6639_data *data;
int err;
data = devm_kzalloc(&client->dev, sizeof(struct max6639_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
err = max6639_init_client(client);
if (err < 0)
return err;
err = sysfs_create_group(&client->dev.kobj, &max6639_group);
if (err)
return err;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto error_remove;
}
dev_info(&client->dev, "temperature sensor and fan control found\n");
return 0;
error_remove:
sysfs_remove_group(&client->dev.kobj, &max6639_group);
return err;
}
static int max6639_remove(struct i2c_client *client)
{
struct max6639_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &max6639_group);
return 0;
}
static int max6639_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
int data = i2c_smbus_read_byte_data(client, MAX6639_REG_GCONFIG);
if (data < 0)
return data;
return i2c_smbus_write_byte_data(client,
MAX6639_REG_GCONFIG, data | MAX6639_GCONFIG_STANDBY);
}
static int max6639_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
int data = i2c_smbus_read_byte_data(client, MAX6639_REG_GCONFIG);
if (data < 0)
return data;
return i2c_smbus_write_byte_data(client,
MAX6639_REG_GCONFIG, data & ~MAX6639_GCONFIG_STANDBY);
}
