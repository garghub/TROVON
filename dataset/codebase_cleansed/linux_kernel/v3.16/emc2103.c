static int read_u8_from_i2c(struct i2c_client *client, u8 i2c_reg, u8 *output)
{
int status = i2c_smbus_read_byte_data(client, i2c_reg);
if (status < 0) {
dev_warn(&client->dev, "reg 0x%02x, err %d\n",
i2c_reg, status);
} else {
*output = status;
}
return status;
}
static void read_temp_from_i2c(struct i2c_client *client, u8 i2c_reg,
struct temperature *temp)
{
u8 degrees, fractional;
if (read_u8_from_i2c(client, i2c_reg, &degrees) < 0)
return;
if (read_u8_from_i2c(client, i2c_reg + 1, &fractional) < 0)
return;
temp->degrees = degrees;
temp->fraction = (fractional & 0xe0) >> 5;
}
static void read_fan_from_i2c(struct i2c_client *client, u16 *output,
u8 hi_addr, u8 lo_addr)
{
u8 high_byte, lo_byte;
if (read_u8_from_i2c(client, hi_addr, &high_byte) < 0)
return;
if (read_u8_from_i2c(client, lo_addr, &lo_byte) < 0)
return;
*output = ((u16)high_byte << 5) | (lo_byte >> 3);
}
static void write_fan_target_to_i2c(struct i2c_client *client, u16 new_target)
{
u8 high_byte = (new_target & 0x1fe0) >> 5;
u8 low_byte = (new_target & 0x001f) << 3;
i2c_smbus_write_byte_data(client, REG_FAN_TARGET_LO, low_byte);
i2c_smbus_write_byte_data(client, REG_FAN_TARGET_HI, high_byte);
}
static void read_fan_config_from_i2c(struct i2c_client *client)
{
struct emc2103_data *data = i2c_get_clientdata(client);
u8 conf1;
if (read_u8_from_i2c(client, REG_FAN_CONF1, &conf1) < 0)
return;
data->fan_multiplier = 1 << ((conf1 & 0x60) >> 5);
data->fan_rpm_control = (conf1 & 0x80) != 0;
}
static struct emc2103_data *emc2103_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct emc2103_data *data = i2c_get_clientdata(client);
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
int i;
for (i = 0; i < data->temp_count; i++) {
read_temp_from_i2c(client, REG_TEMP[i], &data->temp[i]);
read_u8_from_i2c(client, REG_TEMP_MIN[i],
&data->temp_min[i]);
read_u8_from_i2c(client, REG_TEMP_MAX[i],
&data->temp_max[i]);
}
read_u8_from_i2c(client, REG_TEMP_MIN_ALARM,
&data->temp_min_alarm);
read_u8_from_i2c(client, REG_TEMP_MAX_ALARM,
&data->temp_max_alarm);
read_fan_from_i2c(client, &data->fan_tach,
REG_FAN_TACH_HI, REG_FAN_TACH_LO);
read_fan_from_i2c(client, &data->fan_target,
REG_FAN_TARGET_HI, REG_FAN_TARGET_LO);
read_fan_config_from_i2c(client);
data->last_updated = jiffies;
data->valid = true;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t
show_temp(struct device *dev, struct device_attribute *da, char *buf)
{
int nr = to_sensor_dev_attr(da)->index;
struct emc2103_data *data = emc2103_update_device(dev);
int millidegrees = data->temp[nr].degrees * 1000
+ data->temp[nr].fraction * 125;
return sprintf(buf, "%d\n", millidegrees);
}
static ssize_t
show_temp_min(struct device *dev, struct device_attribute *da, char *buf)
{
int nr = to_sensor_dev_attr(da)->index;
struct emc2103_data *data = emc2103_update_device(dev);
int millidegrees = data->temp_min[nr] * 1000;
return sprintf(buf, "%d\n", millidegrees);
}
static ssize_t
show_temp_max(struct device *dev, struct device_attribute *da, char *buf)
{
int nr = to_sensor_dev_attr(da)->index;
struct emc2103_data *data = emc2103_update_device(dev);
int millidegrees = data->temp_max[nr] * 1000;
return sprintf(buf, "%d\n", millidegrees);
}
static ssize_t
show_temp_fault(struct device *dev, struct device_attribute *da, char *buf)
{
int nr = to_sensor_dev_attr(da)->index;
struct emc2103_data *data = emc2103_update_device(dev);
bool fault = (data->temp[nr].degrees == -128);
return sprintf(buf, "%d\n", fault ? 1 : 0);
}
static ssize_t
show_temp_min_alarm(struct device *dev, struct device_attribute *da, char *buf)
{
int nr = to_sensor_dev_attr(da)->index;
struct emc2103_data *data = emc2103_update_device(dev);
bool alarm = data->temp_min_alarm & (1 << nr);
return sprintf(buf, "%d\n", alarm ? 1 : 0);
}
static ssize_t
show_temp_max_alarm(struct device *dev, struct device_attribute *da, char *buf)
{
int nr = to_sensor_dev_attr(da)->index;
struct emc2103_data *data = emc2103_update_device(dev);
bool alarm = data->temp_max_alarm & (1 << nr);
return sprintf(buf, "%d\n", alarm ? 1 : 0);
}
static ssize_t set_temp_min(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(da)->index;
struct i2c_client *client = to_i2c_client(dev);
struct emc2103_data *data = i2c_get_clientdata(client);
long val;
int result = kstrtol(buf, 10, &val);
if (result < 0)
return result;
val = clamp_val(DIV_ROUND_CLOSEST(val, 1000), -63, 127);
mutex_lock(&data->update_lock);
data->temp_min[nr] = val;
i2c_smbus_write_byte_data(client, REG_TEMP_MIN[nr], val);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_temp_max(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(da)->index;
struct i2c_client *client = to_i2c_client(dev);
struct emc2103_data *data = i2c_get_clientdata(client);
long val;
int result = kstrtol(buf, 10, &val);
if (result < 0)
return result;
val = clamp_val(DIV_ROUND_CLOSEST(val, 1000), -63, 127);
mutex_lock(&data->update_lock);
data->temp_max[nr] = val;
i2c_smbus_write_byte_data(client, REG_TEMP_MAX[nr], val);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_fan(struct device *dev, struct device_attribute *da, char *buf)
{
struct emc2103_data *data = emc2103_update_device(dev);
int rpm = 0;
if (data->fan_tach != 0)
rpm = (FAN_RPM_FACTOR * data->fan_multiplier) / data->fan_tach;
return sprintf(buf, "%d\n", rpm);
}
static ssize_t
show_fan_div(struct device *dev, struct device_attribute *da, char *buf)
{
struct emc2103_data *data = emc2103_update_device(dev);
int fan_div = 8 / data->fan_multiplier;
return sprintf(buf, "%d\n", fan_div);
}
static ssize_t set_fan_div(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct emc2103_data *data = emc2103_update_device(dev);
struct i2c_client *client = to_i2c_client(dev);
int new_range_bits, old_div = 8 / data->fan_multiplier;
long new_div;
int status = kstrtol(buf, 10, &new_div);
if (status < 0)
return status;
if (new_div == old_div)
return count;
switch (new_div) {
case 1:
new_range_bits = 3;
break;
case 2:
new_range_bits = 2;
break;
case 4:
new_range_bits = 1;
break;
case 8:
new_range_bits = 0;
break;
default:
return -EINVAL;
}
mutex_lock(&data->update_lock);
status = i2c_smbus_read_byte_data(client, REG_FAN_CONF1);
if (status < 0) {
dev_dbg(&client->dev, "reg 0x%02x, err %d\n",
REG_FAN_CONF1, status);
mutex_unlock(&data->update_lock);
return status;
}
status &= 0x9F;
status |= (new_range_bits << 5);
i2c_smbus_write_byte_data(client, REG_FAN_CONF1, status);
data->fan_multiplier = 8 / new_div;
if ((data->fan_target & 0x1fe0) != 0x1fe0) {
u16 new_target = (data->fan_target * old_div) / new_div;
data->fan_target = min(new_target, (u16)0x1fff);
write_fan_target_to_i2c(client, data->fan_target);
}
data->valid = false;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_fan_target(struct device *dev, struct device_attribute *da, char *buf)
{
struct emc2103_data *data = emc2103_update_device(dev);
int rpm = 0;
if ((data->fan_target != 0) && ((data->fan_target & 0x1fe0) != 0x1fe0))
rpm = (FAN_RPM_FACTOR * data->fan_multiplier)
/ data->fan_target;
return sprintf(buf, "%d\n", rpm);
}
static ssize_t set_fan_target(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct emc2103_data *data = emc2103_update_device(dev);
struct i2c_client *client = to_i2c_client(dev);
unsigned long rpm_target;
int result = kstrtoul(buf, 10, &rpm_target);
if (result < 0)
return result;
rpm_target = clamp_val(rpm_target, 0, 16384);
mutex_lock(&data->update_lock);
if (rpm_target == 0)
data->fan_target = 0x1fff;
else
data->fan_target = clamp_val(
(FAN_RPM_FACTOR * data->fan_multiplier) / rpm_target,
0, 0x1fff);
write_fan_target_to_i2c(client, data->fan_target);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_fan_fault(struct device *dev, struct device_attribute *da, char *buf)
{
struct emc2103_data *data = emc2103_update_device(dev);
bool fault = ((data->fan_tach & 0x1fe0) == 0x1fe0);
return sprintf(buf, "%d\n", fault ? 1 : 0);
}
static ssize_t
show_pwm_enable(struct device *dev, struct device_attribute *da, char *buf)
{
struct emc2103_data *data = emc2103_update_device(dev);
return sprintf(buf, "%d\n", data->fan_rpm_control ? 3 : 0);
}
static ssize_t set_pwm_enable(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct emc2103_data *data = i2c_get_clientdata(client);
long new_value;
u8 conf_reg;
int result = kstrtol(buf, 10, &new_value);
if (result < 0)
return result;
mutex_lock(&data->update_lock);
switch (new_value) {
case 0:
data->fan_rpm_control = false;
break;
case 3:
data->fan_rpm_control = true;
break;
default:
count = -EINVAL;
goto err;
}
result = read_u8_from_i2c(client, REG_FAN_CONF1, &conf_reg);
if (result) {
count = result;
goto err;
}
if (data->fan_rpm_control)
conf_reg |= 0x80;
else
conf_reg &= ~0x80;
i2c_smbus_write_byte_data(client, REG_FAN_CONF1, conf_reg);
err:
mutex_unlock(&data->update_lock);
return count;
}
static int
emc2103_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct emc2103_data *data;
int status;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
data = devm_kzalloc(&client->dev, sizeof(struct emc2103_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
status = i2c_smbus_read_byte_data(client, REG_PRODUCT_ID);
if (status == 0x24) {
data->temp_count = 2;
} else {
status = i2c_smbus_read_byte_data(client, REG_CONF1);
if (status < 0) {
dev_dbg(&client->dev, "reg 0x%02x, err %d\n", REG_CONF1,
status);
return status;
}
data->temp_count = (status & 0x01) ? 4 : 3;
if (apd == 0) {
data->temp_count = 3;
status &= ~(0x01);
i2c_smbus_write_byte_data(client, REG_CONF1, status);
} else if (apd == 1) {
data->temp_count = 4;
status |= 0x01;
i2c_smbus_write_byte_data(client, REG_CONF1, status);
}
}
status = sysfs_create_group(&client->dev.kobj, &emc2103_group);
if (status)
return status;
if (data->temp_count >= 3) {
status = sysfs_create_group(&client->dev.kobj,
&emc2103_temp3_group);
if (status)
goto exit_remove;
}
if (data->temp_count == 4) {
status = sysfs_create_group(&client->dev.kobj,
&emc2103_temp4_group);
if (status)
goto exit_remove_temp3;
}
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
status = PTR_ERR(data->hwmon_dev);
goto exit_remove_temp4;
}
dev_info(&client->dev, "%s: sensor '%s'\n",
dev_name(data->hwmon_dev), client->name);
return 0;
exit_remove_temp4:
if (data->temp_count == 4)
sysfs_remove_group(&client->dev.kobj, &emc2103_temp4_group);
exit_remove_temp3:
if (data->temp_count >= 3)
sysfs_remove_group(&client->dev.kobj, &emc2103_temp3_group);
exit_remove:
sysfs_remove_group(&client->dev.kobj, &emc2103_group);
return status;
}
static int emc2103_remove(struct i2c_client *client)
{
struct emc2103_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
if (data->temp_count == 4)
sysfs_remove_group(&client->dev.kobj, &emc2103_temp4_group);
if (data->temp_count >= 3)
sysfs_remove_group(&client->dev.kobj, &emc2103_temp3_group);
sysfs_remove_group(&client->dev.kobj, &emc2103_group);
return 0;
}
static int
emc2103_detect(struct i2c_client *new_client, struct i2c_board_info *info)
{
struct i2c_adapter *adapter = new_client->adapter;
int manufacturer, product;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
manufacturer = i2c_smbus_read_byte_data(new_client, REG_MFG_ID);
if (manufacturer != 0x5D)
return -ENODEV;
product = i2c_smbus_read_byte_data(new_client, REG_PRODUCT_ID);
if ((product != 0x24) && (product != 0x26))
return -ENODEV;
strlcpy(info->type, "emc2103", I2C_NAME_SIZE);
return 0;
}
