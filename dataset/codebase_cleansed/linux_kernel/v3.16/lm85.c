static inline u16 FAN_TO_REG(unsigned long val)
{
if (!val)
return 0xffff;
return clamp_val(5400000 / val, 1, 0xfffe);
}
static int RANGE_TO_REG(int range)
{
int i;
for (i = 0; i < 15; ++i) {
if (range <= (lm85_range_map[i] + lm85_range_map[i + 1]) / 2)
break;
}
return i;
}
static int FREQ_TO_REG(const int *map, int freq)
{
int i;
for (i = 0; i < 7; ++i)
if (freq <= (map[i] + map[i + 1]) / 2)
break;
return i;
}
static int FREQ_FROM_REG(const int *map, u8 reg)
{
return map[reg & 0x07];
}
static int ZONE_TO_REG(int zone)
{
int i;
for (i = 0; i <= 7; ++i)
if (zone == lm85_zone_map[i])
break;
if (i > 7)
i = 3;
return i << 5;
}
static ssize_t show_fan(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm85_data *data = lm85_update_device(dev);
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan[nr]));
}
static ssize_t show_fan_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm85_data *data = lm85_update_device(dev);
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan_min[nr]));
}
static ssize_t set_fan_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm85_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->fan_min[nr] = FAN_TO_REG(val);
lm85_write_value(client, LM85_REG_FAN_MIN(nr), data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_vid_reg(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct lm85_data *data = lm85_update_device(dev);
int vid;
if (data->has_vid5) {
vid = vid_from_reg(data->vid & 0x3f, data->vrm);
} else {
vid = vid_from_reg(data->vid & 0x1f, data->vrm);
}
return sprintf(buf, "%d\n", vid);
}
static ssize_t show_vrm_reg(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct lm85_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%ld\n", (long) data->vrm);
}
static ssize_t store_vrm_reg(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct lm85_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
data->vrm = val;
return count;
}
static ssize_t show_alarms_reg(struct device *dev, struct device_attribute
*attr, char *buf)
{
struct lm85_data *data = lm85_update_device(dev);
return sprintf(buf, "%u\n", data->alarms);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm85_data *data = lm85_update_device(dev);
return sprintf(buf, "%u\n", (data->alarms >> nr) & 1);
}
static ssize_t show_pwm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm85_data *data = lm85_update_device(dev);
return sprintf(buf, "%d\n", PWM_FROM_REG(data->pwm[nr]));
}
static ssize_t set_pwm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm85_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->pwm[nr] = PWM_TO_REG(val);
lm85_write_value(client, LM85_REG_PWM(nr), data->pwm[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_enable(struct device *dev, struct device_attribute
*attr, char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm85_data *data = lm85_update_device(dev);
int pwm_zone, enable;
pwm_zone = ZONE_FROM_REG(data->autofan[nr].config);
switch (pwm_zone) {
case -1:
enable = 0;
break;
case 0:
case -2:
enable = 1;
break;
default:
enable = 2;
}
return sprintf(buf, "%d\n", enable);
}
static ssize_t set_pwm_enable(struct device *dev, struct device_attribute
*attr, const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm85_data *data = i2c_get_clientdata(client);
u8 config;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
switch (val) {
case 0:
config = 3;
break;
case 1:
config = 7;
break;
case 2:
config = 6;
break;
default:
return -EINVAL;
}
mutex_lock(&data->update_lock);
data->autofan[nr].config = lm85_read_value(client,
LM85_REG_AFAN_CONFIG(nr));
data->autofan[nr].config = (data->autofan[nr].config & ~0xe0)
| (config << 5);
lm85_write_value(client, LM85_REG_AFAN_CONFIG(nr),
data->autofan[nr].config);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_freq(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm85_data *data = lm85_update_device(dev);
int freq;
if (IS_ADT7468_HFPWM(data))
freq = 22500;
else
freq = FREQ_FROM_REG(data->freq_map, data->pwm_freq[nr]);
return sprintf(buf, "%d\n", freq);
}
static ssize_t set_pwm_freq(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm85_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
if (data->type == adt7468 && val >= 11300) {
data->cfg5 &= ~ADT7468_HFPWM;
lm85_write_value(client, ADT7468_REG_CFG5, data->cfg5);
} else {
data->pwm_freq[nr] = FREQ_TO_REG(data->freq_map, val);
lm85_write_value(client, LM85_REG_AFAN_RANGE(nr),
(data->zone[nr].range << 4)
| data->pwm_freq[nr]);
if (data->type == adt7468) {
data->cfg5 |= ADT7468_HFPWM;
lm85_write_value(client, ADT7468_REG_CFG5, data->cfg5);
}
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_in(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm85_data *data = lm85_update_device(dev);
return sprintf(buf, "%d\n", INSEXT_FROM_REG(nr, data->in[nr],
data->in_ext[nr]));
}
static ssize_t show_in_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm85_data *data = lm85_update_device(dev);
return sprintf(buf, "%d\n", INS_FROM_REG(nr, data->in_min[nr]));
}
static ssize_t set_in_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm85_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_min[nr] = INS_TO_REG(nr, val);
lm85_write_value(client, LM85_REG_IN_MIN(nr), data->in_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_in_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm85_data *data = lm85_update_device(dev);
return sprintf(buf, "%d\n", INS_FROM_REG(nr, data->in_max[nr]));
}
static ssize_t set_in_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm85_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_max[nr] = INS_TO_REG(nr, val);
lm85_write_value(client, LM85_REG_IN_MAX(nr), data->in_max[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm85_data *data = lm85_update_device(dev);
return sprintf(buf, "%d\n", TEMPEXT_FROM_REG(data->temp[nr],
data->temp_ext[nr]));
}
static ssize_t show_temp_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm85_data *data = lm85_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_min[nr]));
}
static ssize_t set_temp_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm85_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
if (IS_ADT7468_OFF64(data))
val += 64;
mutex_lock(&data->update_lock);
data->temp_min[nr] = TEMP_TO_REG(val);
lm85_write_value(client, LM85_REG_TEMP_MIN(nr), data->temp_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm85_data *data = lm85_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_max[nr]));
}
static ssize_t set_temp_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm85_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
if (IS_ADT7468_OFF64(data))
val += 64;
mutex_lock(&data->update_lock);
data->temp_max[nr] = TEMP_TO_REG(val);
lm85_write_value(client, LM85_REG_TEMP_MAX(nr), data->temp_max[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_auto_channels(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm85_data *data = lm85_update_device(dev);
return sprintf(buf, "%d\n", ZONE_FROM_REG(data->autofan[nr].config));
}
static ssize_t set_pwm_auto_channels(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm85_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->autofan[nr].config = (data->autofan[nr].config & (~0xe0))
| ZONE_TO_REG(val);
lm85_write_value(client, LM85_REG_AFAN_CONFIG(nr),
data->autofan[nr].config);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_auto_pwm_min(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm85_data *data = lm85_update_device(dev);
return sprintf(buf, "%d\n", PWM_FROM_REG(data->autofan[nr].min_pwm));
}
static ssize_t set_pwm_auto_pwm_min(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm85_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->autofan[nr].min_pwm = PWM_TO_REG(val);
lm85_write_value(client, LM85_REG_AFAN_MINPWM(nr),
data->autofan[nr].min_pwm);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_auto_pwm_minctl(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm85_data *data = lm85_update_device(dev);
return sprintf(buf, "%d\n", data->autofan[nr].min_off);
}
static ssize_t set_pwm_auto_pwm_minctl(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm85_data *data = i2c_get_clientdata(client);
u8 tmp;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->autofan[nr].min_off = val;
tmp = lm85_read_value(client, LM85_REG_AFAN_SPIKE1);
tmp &= ~(0x20 << nr);
if (data->autofan[nr].min_off)
tmp |= 0x20 << nr;
lm85_write_value(client, LM85_REG_AFAN_SPIKE1, tmp);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_auto_temp_off(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm85_data *data = lm85_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->zone[nr].limit) -
HYST_FROM_REG(data->zone[nr].hyst));
}
static ssize_t set_temp_auto_temp_off(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm85_data *data = i2c_get_clientdata(client);
int min;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
min = TEMP_FROM_REG(data->zone[nr].limit);
data->zone[nr].hyst = HYST_TO_REG(min - val);
if (nr == 0 || nr == 1) {
lm85_write_value(client, LM85_REG_AFAN_HYST1,
(data->zone[0].hyst << 4)
| data->zone[1].hyst);
} else {
lm85_write_value(client, LM85_REG_AFAN_HYST2,
(data->zone[2].hyst << 4));
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_auto_temp_min(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm85_data *data = lm85_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->zone[nr].limit));
}
static ssize_t set_temp_auto_temp_min(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm85_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->zone[nr].limit = TEMP_TO_REG(val);
lm85_write_value(client, LM85_REG_AFAN_LIMIT(nr),
data->zone[nr].limit);
data->zone[nr].range = RANGE_TO_REG(
TEMP_FROM_REG(data->zone[nr].max_desired) -
TEMP_FROM_REG(data->zone[nr].limit));
lm85_write_value(client, LM85_REG_AFAN_RANGE(nr),
((data->zone[nr].range & 0x0f) << 4)
| (data->pwm_freq[nr] & 0x07));
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_auto_temp_max(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm85_data *data = lm85_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->zone[nr].limit) +
RANGE_FROM_REG(data->zone[nr].range));
}
static ssize_t set_temp_auto_temp_max(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm85_data *data = i2c_get_clientdata(client);
int min;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
min = TEMP_FROM_REG(data->zone[nr].limit);
data->zone[nr].max_desired = TEMP_TO_REG(val);
data->zone[nr].range = RANGE_TO_REG(
val - min);
lm85_write_value(client, LM85_REG_AFAN_RANGE(nr),
((data->zone[nr].range & 0x0f) << 4)
| (data->pwm_freq[nr] & 0x07));
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_auto_temp_crit(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct lm85_data *data = lm85_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->zone[nr].critical));
}
static ssize_t set_temp_auto_temp_crit(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct lm85_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->zone[nr].critical = TEMP_TO_REG(val);
lm85_write_value(client, LM85_REG_AFAN_CRITICAL(nr),
data->zone[nr].critical);
mutex_unlock(&data->update_lock);
return count;
}
static void lm85_init_client(struct i2c_client *client)
{
int value;
value = lm85_read_value(client, LM85_REG_CONFIG);
if (!(value & 0x01)) {
dev_info(&client->dev, "Starting monitoring\n");
lm85_write_value(client, LM85_REG_CONFIG, value | 0x01);
}
if (value & 0x02)
dev_warn(&client->dev, "Device configuration is locked\n");
if (!(value & 0x04))
dev_warn(&client->dev, "Device is not ready\n");
}
static int lm85_is_fake(struct i2c_client *client)
{
int i;
u8 in_temp, fan;
for (i = 0; i < 8; i++) {
in_temp = i2c_smbus_read_byte_data(client, 0x20 + i);
fan = i2c_smbus_read_byte_data(client, 0x28 + i);
if (in_temp != 0x00 || fan != 0xff)
return 0;
}
return 1;
}
static int lm85_detect(struct i2c_client *client, struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int address = client->addr;
const char *type_name = NULL;
int company, verstep;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
return -ENODEV;
}
company = lm85_read_value(client, LM85_REG_COMPANY);
verstep = lm85_read_value(client, LM85_REG_VERSTEP);
dev_dbg(&adapter->dev,
"Detecting device at 0x%02x with COMPANY: 0x%02x and VERSTEP: 0x%02x\n",
address, company, verstep);
if (company == LM85_COMPANY_NATIONAL) {
switch (verstep) {
case LM85_VERSTEP_LM85C:
type_name = "lm85c";
break;
case LM85_VERSTEP_LM85B:
type_name = "lm85b";
break;
case LM85_VERSTEP_LM96000_1:
case LM85_VERSTEP_LM96000_2:
if (lm85_is_fake(client)) {
dev_dbg(&adapter->dev,
"Found Winbond WPCD377I, ignoring\n");
return -ENODEV;
}
type_name = "lm85";
break;
}
} else if (company == LM85_COMPANY_ANALOG_DEV) {
switch (verstep) {
case LM85_VERSTEP_ADM1027:
type_name = "adm1027";
break;
case LM85_VERSTEP_ADT7463:
case LM85_VERSTEP_ADT7463C:
type_name = "adt7463";
break;
case LM85_VERSTEP_ADT7468_1:
case LM85_VERSTEP_ADT7468_2:
type_name = "adt7468";
break;
}
} else if (company == LM85_COMPANY_SMSC) {
switch (verstep) {
case LM85_VERSTEP_EMC6D100_A0:
case LM85_VERSTEP_EMC6D100_A1:
type_name = "emc6d100";
break;
case LM85_VERSTEP_EMC6D102:
type_name = "emc6d102";
break;
case LM85_VERSTEP_EMC6D103_A0:
case LM85_VERSTEP_EMC6D103_A1:
type_name = "emc6d103";
break;
case LM85_VERSTEP_EMC6D103S:
type_name = "emc6d103s";
break;
}
}
if (!type_name)
return -ENODEV;
strlcpy(info->type, type_name, I2C_NAME_SIZE);
return 0;
}
static void lm85_remove_files(struct i2c_client *client, struct lm85_data *data)
{
sysfs_remove_group(&client->dev.kobj, &lm85_group);
if (data->type != emc6d103s) {
sysfs_remove_group(&client->dev.kobj, &lm85_group_minctl);
sysfs_remove_group(&client->dev.kobj, &lm85_group_temp_off);
}
if (!data->has_vid5)
sysfs_remove_group(&client->dev.kobj, &lm85_group_in4);
if (data->type == emc6d100)
sysfs_remove_group(&client->dev.kobj, &lm85_group_in567);
}
static int lm85_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct lm85_data *data;
int err;
data = devm_kzalloc(&client->dev, sizeof(struct lm85_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
data->type = id->driver_data;
mutex_init(&data->update_lock);
switch (data->type) {
case adm1027:
case adt7463:
case adt7468:
case emc6d100:
case emc6d102:
case emc6d103:
case emc6d103s:
data->freq_map = adm1027_freq_map;
break;
default:
data->freq_map = lm85_freq_map;
}
data->vrm = vid_which_vrm();
lm85_init_client(client);
err = sysfs_create_group(&client->dev.kobj, &lm85_group);
if (err)
return err;
if (data->type != emc6d103s) {
err = sysfs_create_group(&client->dev.kobj, &lm85_group_minctl);
if (err)
goto err_remove_files;
err = sysfs_create_group(&client->dev.kobj,
&lm85_group_temp_off);
if (err)
goto err_remove_files;
}
if (data->type == adt7463 || data->type == adt7468) {
u8 vid = lm85_read_value(client, LM85_REG_VID);
if (vid & 0x80)
data->has_vid5 = true;
}
if (!data->has_vid5) {
err = sysfs_create_group(&client->dev.kobj, &lm85_group_in4);
if (err)
goto err_remove_files;
}
if (data->type == emc6d100) {
err = sysfs_create_group(&client->dev.kobj, &lm85_group_in567);
if (err)
goto err_remove_files;
}
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto err_remove_files;
}
return 0;
err_remove_files:
lm85_remove_files(client, data);
return err;
}
static int lm85_remove(struct i2c_client *client)
{
struct lm85_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
lm85_remove_files(client, data);
return 0;
}
static int lm85_read_value(struct i2c_client *client, u8 reg)
{
int res;
switch (reg) {
case LM85_REG_FAN(0):
case LM85_REG_FAN(1):
case LM85_REG_FAN(2):
case LM85_REG_FAN(3):
case LM85_REG_FAN_MIN(0):
case LM85_REG_FAN_MIN(1):
case LM85_REG_FAN_MIN(2):
case LM85_REG_FAN_MIN(3):
case LM85_REG_ALARM1:
res = i2c_smbus_read_byte_data(client, reg) & 0xff;
res |= i2c_smbus_read_byte_data(client, reg + 1) << 8;
break;
default:
res = i2c_smbus_read_byte_data(client, reg);
break;
}
return res;
}
static void lm85_write_value(struct i2c_client *client, u8 reg, int value)
{
switch (reg) {
case LM85_REG_FAN(0):
case LM85_REG_FAN(1):
case LM85_REG_FAN(2):
case LM85_REG_FAN(3):
case LM85_REG_FAN_MIN(0):
case LM85_REG_FAN_MIN(1):
case LM85_REG_FAN_MIN(2):
case LM85_REG_FAN_MIN(3):
i2c_smbus_write_byte_data(client, reg, value & 0xff);
i2c_smbus_write_byte_data(client, reg + 1, value >> 8);
break;
default:
i2c_smbus_write_byte_data(client, reg, value);
break;
}
}
static struct lm85_data *lm85_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm85_data *data = i2c_get_clientdata(client);
int i;
mutex_lock(&data->update_lock);
if (!data->valid ||
time_after(jiffies, data->last_reading + LM85_DATA_INTERVAL)) {
dev_dbg(&client->dev, "Reading sensor values\n");
if (data->type == adm1027 || data->type == adt7463 ||
data->type == adt7468) {
int ext1 = lm85_read_value(client,
ADM1027_REG_EXTEND_ADC1);
int ext2 = lm85_read_value(client,
ADM1027_REG_EXTEND_ADC2);
int val = (ext1 << 8) + ext2;
for (i = 0; i <= 4; i++)
data->in_ext[i] =
((val >> (i * 2)) & 0x03) << 2;
for (i = 0; i <= 2; i++)
data->temp_ext[i] =
(val >> ((i + 4) * 2)) & 0x0c;
}
data->vid = lm85_read_value(client, LM85_REG_VID);
for (i = 0; i <= 3; ++i) {
data->in[i] =
lm85_read_value(client, LM85_REG_IN(i));
data->fan[i] =
lm85_read_value(client, LM85_REG_FAN(i));
}
if (!data->has_vid5)
data->in[4] = lm85_read_value(client, LM85_REG_IN(4));
if (data->type == adt7468)
data->cfg5 = lm85_read_value(client, ADT7468_REG_CFG5);
for (i = 0; i <= 2; ++i) {
data->temp[i] =
lm85_read_value(client, LM85_REG_TEMP(i));
data->pwm[i] =
lm85_read_value(client, LM85_REG_PWM(i));
if (IS_ADT7468_OFF64(data))
data->temp[i] -= 64;
}
data->alarms = lm85_read_value(client, LM85_REG_ALARM1);
if (data->type == emc6d100) {
for (i = 5; i <= 7; ++i) {
data->in[i] = lm85_read_value(client,
EMC6D100_REG_IN(i));
}
data->alarms |= lm85_read_value(client,
EMC6D100_REG_ALARM3) << 16;
} else if (data->type == emc6d102 || data->type == emc6d103 ||
data->type == emc6d103s) {
int ext1 = lm85_read_value(client,
EMC6D102_REG_EXTEND_ADC1);
int ext2 = lm85_read_value(client,
EMC6D102_REG_EXTEND_ADC2);
int ext3 = lm85_read_value(client,
EMC6D102_REG_EXTEND_ADC3);
int ext4 = lm85_read_value(client,
EMC6D102_REG_EXTEND_ADC4);
data->in_ext[0] = ext3 & 0x0f;
data->in_ext[1] = ext4 & 0x0f;
data->in_ext[2] = ext4 >> 4;
data->in_ext[3] = ext3 >> 4;
data->in_ext[4] = ext2 >> 4;
data->temp_ext[0] = ext1 & 0x0f;
data->temp_ext[1] = ext2 & 0x0f;
data->temp_ext[2] = ext1 >> 4;
}
data->last_reading = jiffies;
}
if (!data->valid ||
time_after(jiffies, data->last_config + LM85_CONFIG_INTERVAL)) {
dev_dbg(&client->dev, "Reading config values\n");
for (i = 0; i <= 3; ++i) {
data->in_min[i] =
lm85_read_value(client, LM85_REG_IN_MIN(i));
data->in_max[i] =
lm85_read_value(client, LM85_REG_IN_MAX(i));
data->fan_min[i] =
lm85_read_value(client, LM85_REG_FAN_MIN(i));
}
if (!data->has_vid5) {
data->in_min[4] = lm85_read_value(client,
LM85_REG_IN_MIN(4));
data->in_max[4] = lm85_read_value(client,
LM85_REG_IN_MAX(4));
}
if (data->type == emc6d100) {
for (i = 5; i <= 7; ++i) {
data->in_min[i] = lm85_read_value(client,
EMC6D100_REG_IN_MIN(i));
data->in_max[i] = lm85_read_value(client,
EMC6D100_REG_IN_MAX(i));
}
}
for (i = 0; i <= 2; ++i) {
int val;
data->temp_min[i] =
lm85_read_value(client, LM85_REG_TEMP_MIN(i));
data->temp_max[i] =
lm85_read_value(client, LM85_REG_TEMP_MAX(i));
data->autofan[i].config =
lm85_read_value(client, LM85_REG_AFAN_CONFIG(i));
val = lm85_read_value(client, LM85_REG_AFAN_RANGE(i));
data->pwm_freq[i] = val & 0x07;
data->zone[i].range = val >> 4;
data->autofan[i].min_pwm =
lm85_read_value(client, LM85_REG_AFAN_MINPWM(i));
data->zone[i].limit =
lm85_read_value(client, LM85_REG_AFAN_LIMIT(i));
data->zone[i].critical =
lm85_read_value(client, LM85_REG_AFAN_CRITICAL(i));
if (IS_ADT7468_OFF64(data)) {
data->temp_min[i] -= 64;
data->temp_max[i] -= 64;
data->zone[i].limit -= 64;
data->zone[i].critical -= 64;
}
}
if (data->type != emc6d103s) {
i = lm85_read_value(client, LM85_REG_AFAN_SPIKE1);
data->autofan[0].min_off = (i & 0x20) != 0;
data->autofan[1].min_off = (i & 0x40) != 0;
data->autofan[2].min_off = (i & 0x80) != 0;
i = lm85_read_value(client, LM85_REG_AFAN_HYST1);
data->zone[0].hyst = i >> 4;
data->zone[1].hyst = i & 0x0f;
i = lm85_read_value(client, LM85_REG_AFAN_HYST2);
data->zone[2].hyst = i >> 4;
}
data->last_config = jiffies;
}
data->valid = 1;
mutex_unlock(&data->update_lock);
return data;
}
