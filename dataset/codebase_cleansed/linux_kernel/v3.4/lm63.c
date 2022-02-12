static inline int temp8_from_reg(struct lm63_data *data, int nr)
{
if (data->remote_unsigned)
return TEMP8_FROM_REG((u8)data->temp8[nr]);
return TEMP8_FROM_REG(data->temp8[nr]);
}
static inline int lut_temp_from_reg(struct lm63_data *data, int nr)
{
return data->temp8[nr] * (data->lut_temp_highres ? 500 : 1000);
}
static inline int lut_temp_to_reg(struct lm63_data *data, long val)
{
val -= data->temp2_offset;
if (data->lut_temp_highres)
return DIV_ROUND_CLOSEST(SENSORS_LIMIT(val, 0, 127500), 500);
else
return DIV_ROUND_CLOSEST(SENSORS_LIMIT(val, 0, 127000), 1000);
}
static void lm63_update_lut(struct i2c_client *client)
{
struct lm63_data *data = i2c_get_clientdata(client);
int i;
if (time_after(jiffies, data->lut_last_updated + 5 * HZ) ||
!data->lut_valid) {
for (i = 0; i < data->lut_size; i++) {
data->pwm1[1 + i] = i2c_smbus_read_byte_data(client,
LM63_REG_LUT_PWM(i));
data->temp8[3 + i] = i2c_smbus_read_byte_data(client,
LM63_REG_LUT_TEMP(i));
}
data->lut_temp_hyst = i2c_smbus_read_byte_data(client,
LM63_REG_LUT_TEMP_HYST);
data->lut_last_updated = jiffies;
data->lut_valid = 1;
}
}
static struct lm63_data *lm63_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm63_data *data = i2c_get_clientdata(client);
unsigned long next_update;
mutex_lock(&data->update_lock);
next_update = data->last_updated
+ msecs_to_jiffies(data->update_interval) + 1;
if (time_after(jiffies, next_update) || !data->valid) {
if (data->config & 0x04) {
data->fan[0] = i2c_smbus_read_byte_data(client,
LM63_REG_TACH_COUNT_LSB) & 0xFC;
data->fan[0] |= i2c_smbus_read_byte_data(client,
LM63_REG_TACH_COUNT_MSB) << 8;
data->fan[1] = (i2c_smbus_read_byte_data(client,
LM63_REG_TACH_LIMIT_LSB) & 0xFC)
| (i2c_smbus_read_byte_data(client,
LM63_REG_TACH_LIMIT_MSB) << 8);
}
data->pwm1_freq = i2c_smbus_read_byte_data(client,
LM63_REG_PWM_FREQ);
if (data->pwm1_freq == 0)
data->pwm1_freq = 1;
data->pwm1[0] = i2c_smbus_read_byte_data(client,
LM63_REG_PWM_VALUE);
data->temp8[0] = i2c_smbus_read_byte_data(client,
LM63_REG_LOCAL_TEMP);
data->temp8[1] = i2c_smbus_read_byte_data(client,
LM63_REG_LOCAL_HIGH);
data->temp11[0] = i2c_smbus_read_byte_data(client,
LM63_REG_REMOTE_TEMP_MSB) << 8;
data->temp11[0] |= i2c_smbus_read_byte_data(client,
LM63_REG_REMOTE_TEMP_LSB);
data->temp11[1] = (i2c_smbus_read_byte_data(client,
LM63_REG_REMOTE_LOW_MSB) << 8)
| i2c_smbus_read_byte_data(client,
LM63_REG_REMOTE_LOW_LSB);
data->temp11[2] = (i2c_smbus_read_byte_data(client,
LM63_REG_REMOTE_HIGH_MSB) << 8)
| i2c_smbus_read_byte_data(client,
LM63_REG_REMOTE_HIGH_LSB);
data->temp11[3] = (i2c_smbus_read_byte_data(client,
LM63_REG_REMOTE_OFFSET_MSB) << 8)
| i2c_smbus_read_byte_data(client,
LM63_REG_REMOTE_OFFSET_LSB);
if (data->kind == lm96163)
data->temp11u = (i2c_smbus_read_byte_data(client,
LM96163_REG_REMOTE_TEMP_U_MSB) << 8)
| i2c_smbus_read_byte_data(client,
LM96163_REG_REMOTE_TEMP_U_LSB);
data->temp8[2] = i2c_smbus_read_byte_data(client,
LM63_REG_REMOTE_TCRIT);
data->temp2_crit_hyst = i2c_smbus_read_byte_data(client,
LM63_REG_REMOTE_TCRIT_HYST);
data->alarms = i2c_smbus_read_byte_data(client,
LM63_REG_ALERT_STATUS) & 0x7F;
data->last_updated = jiffies;
data->valid = 1;
}
lm63_update_lut(client);
mutex_unlock(&data->update_lock);
return data;
}
static int lm63_lut_looks_bad(struct i2c_client *client)
{
struct lm63_data *data = i2c_get_clientdata(client);
int i;
mutex_lock(&data->update_lock);
lm63_update_lut(client);
for (i = 1; i < data->lut_size; i++) {
if (data->pwm1[1 + i - 1] > data->pwm1[1 + i]
|| data->temp8[3 + i - 1] > data->temp8[3 + i]) {
dev_warn(&client->dev,
"Lookup table doesn't look sane (check entries %d and %d)\n",
i, i + 1);
break;
}
}
mutex_unlock(&data->update_lock);
return i == data->lut_size ? 0 : 1;
}
static ssize_t show_fan(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm63_data *data = lm63_update_device(dev);
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan[attr->index]));
}
static ssize_t set_fan(struct device *dev, struct device_attribute *dummy,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm63_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->fan[1] = FAN_TO_REG(val);
i2c_smbus_write_byte_data(client, LM63_REG_TACH_LIMIT_LSB,
data->fan[1] & 0xFF);
i2c_smbus_write_byte_data(client, LM63_REG_TACH_LIMIT_MSB,
data->fan[1] >> 8);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm1(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm63_data *data = lm63_update_device(dev);
int nr = attr->index;
int pwm;
if (data->pwm_highres)
pwm = data->pwm1[nr];
else
pwm = data->pwm1[nr] >= 2 * data->pwm1_freq ?
255 : (data->pwm1[nr] * 255 + data->pwm1_freq) /
(2 * data->pwm1_freq);
return sprintf(buf, "%d\n", pwm);
}
static ssize_t set_pwm1(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct i2c_client *client = to_i2c_client(dev);
struct lm63_data *data = i2c_get_clientdata(client);
int nr = attr->index;
unsigned long val;
int err;
u8 reg;
if (!(data->config_fan & 0x20))
return -EPERM;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
reg = nr ? LM63_REG_LUT_PWM(nr - 1) : LM63_REG_PWM_VALUE;
val = SENSORS_LIMIT(val, 0, 255);
mutex_lock(&data->update_lock);
data->pwm1[nr] = data->pwm_highres ? val :
(val * data->pwm1_freq * 2 + 127) / 255;
i2c_smbus_write_byte_data(client, reg, data->pwm1[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm1_enable(struct device *dev,
struct device_attribute *dummy, char *buf)
{
struct lm63_data *data = lm63_update_device(dev);
return sprintf(buf, "%d\n", data->config_fan & 0x20 ? 1 : 2);
}
static ssize_t set_pwm1_enable(struct device *dev,
struct device_attribute *dummy,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm63_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
if (val < 1 || val > 2)
return -EINVAL;
if (val == 2 && lm63_lut_looks_bad(client))
return -EPERM;
mutex_lock(&data->update_lock);
data->config_fan = i2c_smbus_read_byte_data(client,
LM63_REG_CONFIG_FAN);
if (val == 1)
data->config_fan |= 0x20;
else
data->config_fan &= ~0x20;
i2c_smbus_write_byte_data(client, LM63_REG_CONFIG_FAN,
data->config_fan);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_local_temp8(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm63_data *data = lm63_update_device(dev);
return sprintf(buf, "%d\n", TEMP8_FROM_REG(data->temp8[attr->index]));
}
static ssize_t show_remote_temp8(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm63_data *data = lm63_update_device(dev);
return sprintf(buf, "%d\n", temp8_from_reg(data, attr->index)
+ data->temp2_offset);
}
static ssize_t show_lut_temp(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm63_data *data = lm63_update_device(dev);
return sprintf(buf, "%d\n", lut_temp_from_reg(data, attr->index)
+ data->temp2_offset);
}
static ssize_t set_temp8(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct i2c_client *client = to_i2c_client(dev);
struct lm63_data *data = i2c_get_clientdata(client);
int nr = attr->index;
long val;
int err;
int temp;
u8 reg;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
switch (nr) {
case 2:
reg = LM63_REG_REMOTE_TCRIT;
if (data->remote_unsigned)
temp = TEMP8U_TO_REG(val - data->temp2_offset);
else
temp = TEMP8_TO_REG(val - data->temp2_offset);
break;
case 1:
reg = LM63_REG_LOCAL_HIGH;
temp = TEMP8_TO_REG(val);
break;
default:
reg = LM63_REG_LUT_TEMP(nr - 3);
temp = lut_temp_to_reg(data, val);
}
data->temp8[nr] = temp;
i2c_smbus_write_byte_data(client, reg, temp);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp11(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm63_data *data = lm63_update_device(dev);
int nr = attr->index;
int temp;
if (!nr) {
if (data->temp11u)
temp = TEMP11_FROM_REG(data->temp11u);
else
temp = TEMP11_FROM_REG(data->temp11[nr]);
} else {
if (data->remote_unsigned && nr == 2)
temp = TEMP11_FROM_REG((u16)data->temp11[nr]);
else
temp = TEMP11_FROM_REG(data->temp11[nr]);
}
return sprintf(buf, "%d\n", temp + data->temp2_offset);
}
static ssize_t set_temp11(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
static const u8 reg[6] = {
LM63_REG_REMOTE_LOW_MSB,
LM63_REG_REMOTE_LOW_LSB,
LM63_REG_REMOTE_HIGH_MSB,
LM63_REG_REMOTE_HIGH_LSB,
LM63_REG_REMOTE_OFFSET_MSB,
LM63_REG_REMOTE_OFFSET_LSB,
};
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct i2c_client *client = to_i2c_client(dev);
struct lm63_data *data = i2c_get_clientdata(client);
long val;
int err;
int nr = attr->index;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
if (data->remote_unsigned && nr == 2)
data->temp11[nr] = TEMP11U_TO_REG(val - data->temp2_offset);
else
data->temp11[nr] = TEMP11_TO_REG(val - data->temp2_offset);
i2c_smbus_write_byte_data(client, reg[(nr - 1) * 2],
data->temp11[nr] >> 8);
i2c_smbus_write_byte_data(client, reg[(nr - 1) * 2 + 1],
data->temp11[nr] & 0xff);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp2_crit_hyst(struct device *dev,
struct device_attribute *dummy, char *buf)
{
struct lm63_data *data = lm63_update_device(dev);
return sprintf(buf, "%d\n", temp8_from_reg(data, 2)
+ data->temp2_offset
- TEMP8_FROM_REG(data->temp2_crit_hyst));
}
static ssize_t show_lut_temp_hyst(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm63_data *data = lm63_update_device(dev);
return sprintf(buf, "%d\n", lut_temp_from_reg(data, attr->index)
+ data->temp2_offset
- TEMP8_FROM_REG(data->lut_temp_hyst));
}
static ssize_t set_temp2_crit_hyst(struct device *dev,
struct device_attribute *dummy,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm63_data *data = i2c_get_clientdata(client);
long val;
int err;
long hyst;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
hyst = temp8_from_reg(data, 2) + data->temp2_offset - val;
i2c_smbus_write_byte_data(client, LM63_REG_REMOTE_TCRIT_HYST,
HYST_TO_REG(hyst));
mutex_unlock(&data->update_lock);
return count;
}
static void lm63_set_convrate(struct i2c_client *client, struct lm63_data *data,
unsigned int interval)
{
int i;
unsigned int update_interval;
interval <<= 6;
update_interval = (1 << (LM63_MAX_CONVRATE + 6)) * 1000
/ data->max_convrate_hz;
for (i = 0; i < LM63_MAX_CONVRATE; i++, update_interval >>= 1)
if (interval >= update_interval * 3 / 4)
break;
i2c_smbus_write_byte_data(client, LM63_REG_CONVRATE, i);
data->update_interval = UPDATE_INTERVAL(data->max_convrate_hz, i);
}
static ssize_t show_update_interval(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lm63_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", data->update_interval);
}
static ssize_t set_update_interval(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm63_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
lm63_set_convrate(client, data, SENSORS_LIMIT(val, 0, 100000));
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_type(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm63_data *data = i2c_get_clientdata(client);
return sprintf(buf, data->trutherm ? "1\n" : "2\n");
}
static ssize_t set_type(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm63_data *data = i2c_get_clientdata(client);
unsigned long val;
int ret;
u8 reg;
ret = kstrtoul(buf, 10, &val);
if (ret < 0)
return ret;
if (val != 1 && val != 2)
return -EINVAL;
mutex_lock(&data->update_lock);
data->trutherm = val == 1;
reg = i2c_smbus_read_byte_data(client, LM96163_REG_TRUTHERM) & ~0x02;
i2c_smbus_write_byte_data(client, LM96163_REG_TRUTHERM,
reg | (data->trutherm ? 0x02 : 0x00));
data->valid = 0;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarms(struct device *dev, struct device_attribute *dummy,
char *buf)
{
struct lm63_data *data = lm63_update_device(dev);
return sprintf(buf, "%u\n", data->alarms);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm63_data *data = lm63_update_device(dev);
int bitnr = attr->index;
return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}
static umode_t lm63_attribute_mode(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct i2c_client *client = to_i2c_client(dev);
struct lm63_data *data = i2c_get_clientdata(client);
if (attr == &sensor_dev_attr_temp2_crit.dev_attr.attr
&& (data->kind == lm64 ||
(data->kind == lm96163 && (data->config & 0x02))))
return attr->mode | S_IWUSR;
return attr->mode;
}
static int lm63_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
u8 man_id, chip_id, reg_config1, reg_config2;
u8 reg_alert_status, reg_alert_mask;
int address = client->addr;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
man_id = i2c_smbus_read_byte_data(client, LM63_REG_MAN_ID);
chip_id = i2c_smbus_read_byte_data(client, LM63_REG_CHIP_ID);
reg_config1 = i2c_smbus_read_byte_data(client, LM63_REG_CONFIG1);
reg_config2 = i2c_smbus_read_byte_data(client, LM63_REG_CONFIG2);
reg_alert_status = i2c_smbus_read_byte_data(client,
LM63_REG_ALERT_STATUS);
reg_alert_mask = i2c_smbus_read_byte_data(client, LM63_REG_ALERT_MASK);
if (man_id != 0x01
|| (reg_config1 & 0x18) != 0x00
|| (reg_config2 & 0xF8) != 0x00
|| (reg_alert_status & 0x20) != 0x00
|| (reg_alert_mask & 0xA4) != 0xA4) {
dev_dbg(&adapter->dev,
"Unsupported chip (man_id=0x%02X, chip_id=0x%02X)\n",
man_id, chip_id);
return -ENODEV;
}
if (chip_id == 0x41 && address == 0x4c)
strlcpy(info->type, "lm63", I2C_NAME_SIZE);
else if (chip_id == 0x51 && (address == 0x18 || address == 0x4e))
strlcpy(info->type, "lm64", I2C_NAME_SIZE);
else if (chip_id == 0x49 && address == 0x4c)
strlcpy(info->type, "lm96163", I2C_NAME_SIZE);
else
return -ENODEV;
return 0;
}
static void lm63_init_client(struct i2c_client *client)
{
struct lm63_data *data = i2c_get_clientdata(client);
u8 convrate;
data->config = i2c_smbus_read_byte_data(client, LM63_REG_CONFIG1);
data->config_fan = i2c_smbus_read_byte_data(client,
LM63_REG_CONFIG_FAN);
if (data->config & 0x40) {
dev_dbg(&client->dev, "Switching to operational mode\n");
data->config &= 0xA7;
i2c_smbus_write_byte_data(client, LM63_REG_CONFIG1,
data->config);
}
if (data->kind == lm64)
data->config |= 0x04;
data->pwm1_freq = i2c_smbus_read_byte_data(client, LM63_REG_PWM_FREQ);
if (data->pwm1_freq == 0)
data->pwm1_freq = 1;
switch (data->kind) {
case lm63:
case lm64:
data->max_convrate_hz = LM63_MAX_CONVRATE_HZ;
data->lut_size = 8;
break;
case lm96163:
data->max_convrate_hz = LM96163_MAX_CONVRATE_HZ;
data->lut_size = 12;
data->trutherm
= i2c_smbus_read_byte_data(client,
LM96163_REG_TRUTHERM) & 0x02;
break;
}
convrate = i2c_smbus_read_byte_data(client, LM63_REG_CONVRATE);
if (unlikely(convrate > LM63_MAX_CONVRATE))
convrate = LM63_MAX_CONVRATE;
data->update_interval = UPDATE_INTERVAL(data->max_convrate_hz,
convrate);
if (data->kind == lm96163) {
u8 config_enhanced
= i2c_smbus_read_byte_data(client,
LM96163_REG_CONFIG_ENHANCED);
if (config_enhanced & 0x20)
data->lut_temp_highres = true;
if ((config_enhanced & 0x10)
&& !(data->config_fan & 0x08) && data->pwm1_freq == 8)
data->pwm_highres = true;
if (config_enhanced & 0x08)
data->remote_unsigned = true;
}
if (data->kind == lm63)
dev_dbg(&client->dev, "Alert/tach pin configured for %s\n",
(data->config & 0x04) ? "tachometer input" :
"alert output");
dev_dbg(&client->dev, "PWM clock %s kHz, output frequency %u Hz\n",
(data->config_fan & 0x08) ? "1.4" : "360",
((data->config_fan & 0x08) ? 700 : 180000) / data->pwm1_freq);
dev_dbg(&client->dev, "PWM output active %s, %s mode\n",
(data->config_fan & 0x10) ? "low" : "high",
(data->config_fan & 0x20) ? "manual" : "auto");
}
static int lm63_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct lm63_data *data;
int err;
data = kzalloc(sizeof(struct lm63_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(client, data);
data->valid = 0;
mutex_init(&data->update_lock);
data->kind = id->driver_data;
if (data->kind == lm64)
data->temp2_offset = 16000;
lm63_init_client(client);
err = sysfs_create_group(&client->dev.kobj, &lm63_group);
if (err)
goto exit_free;
if (data->config & 0x04) {
err = sysfs_create_group(&client->dev.kobj, &lm63_group_fan1);
if (err)
goto exit_remove_files;
}
if (data->kind == lm96163) {
err = device_create_file(&client->dev, &dev_attr_temp2_type);
if (err)
goto exit_remove_files;
err = sysfs_create_group(&client->dev.kobj,
&lm63_group_extra_lut);
if (err)
goto exit_remove_files;
}
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
return 0;
exit_remove_files:
sysfs_remove_group(&client->dev.kobj, &lm63_group);
sysfs_remove_group(&client->dev.kobj, &lm63_group_fan1);
if (data->kind == lm96163) {
device_remove_file(&client->dev, &dev_attr_temp2_type);
sysfs_remove_group(&client->dev.kobj, &lm63_group_extra_lut);
}
exit_free:
kfree(data);
exit:
return err;
}
static int lm63_remove(struct i2c_client *client)
{
struct lm63_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &lm63_group);
sysfs_remove_group(&client->dev.kobj, &lm63_group_fan1);
if (data->kind == lm96163) {
device_remove_file(&client->dev, &dev_attr_temp2_type);
sysfs_remove_group(&client->dev.kobj, &lm63_group_extra_lut);
}
kfree(data);
return 0;
}
