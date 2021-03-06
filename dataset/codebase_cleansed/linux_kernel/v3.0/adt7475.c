static inline u16 temp2reg(struct adt7475_data *data, long val)
{
u16 ret;
if (!(data->config5 & CONFIG5_TWOSCOMP)) {
val = SENSORS_LIMIT(val, -64000, 191000);
ret = (val + 64500) / 1000;
} else {
val = SENSORS_LIMIT(val, -128000, 127000);
if (val < -500)
ret = (256500 + val) / 1000;
else
ret = (val + 500) / 1000;
}
return ret << 2;
}
static inline int reg2temp(struct adt7475_data *data, u16 reg)
{
if (data->config5 & CONFIG5_TWOSCOMP) {
if (reg >= 512)
return (reg - 1024) * 250;
else
return reg * 250;
} else
return (reg - 256) * 250;
}
static inline int tach2rpm(u16 tach)
{
if (tach == 0 || tach == 0xFFFF)
return 0;
return (90000 * 60) / tach;
}
static inline u16 rpm2tach(unsigned long rpm)
{
if (rpm == 0)
return 0;
return SENSORS_LIMIT((90000 * 60) / rpm, 1, 0xFFFF);
}
static inline int reg2volt(int channel, u16 reg, u8 bypass_attn)
{
const int *r = adt7473_in_scaling[channel];
if (bypass_attn & (1 << channel))
return DIV_ROUND_CLOSEST(reg * 2250, 1024);
return DIV_ROUND_CLOSEST(reg * (r[0] + r[1]) * 2250, r[1] * 1024);
}
static inline u16 volt2reg(int channel, long volt, u8 bypass_attn)
{
const int *r = adt7473_in_scaling[channel];
long reg;
if (bypass_attn & (1 << channel))
reg = (volt * 1024) / 2250;
else
reg = (volt * r[1] * 1024) / ((r[0] + r[1]) * 2250);
return SENSORS_LIMIT(reg, 0, 1023) & (0xff << 2);
}
static u16 adt7475_read_word(struct i2c_client *client, int reg)
{
u16 val;
val = i2c_smbus_read_byte_data(client, reg);
val |= (i2c_smbus_read_byte_data(client, reg + 1) << 8);
return val;
}
static void adt7475_write_word(struct i2c_client *client, int reg, u16 val)
{
i2c_smbus_write_byte_data(client, reg + 1, val >> 8);
i2c_smbus_write_byte_data(client, reg, val & 0xFF);
}
static int find_nearest(long val, const int *array, int size)
{
int i;
if (val < array[0])
return 0;
if (val > array[size - 1])
return size - 1;
for (i = 0; i < size - 1; i++) {
int a, b;
if (val > array[i + 1])
continue;
a = val - array[i];
b = array[i + 1] - val;
return (a <= b) ? i : i + 1;
}
return 0;
}
static ssize_t show_voltage(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct adt7475_data *data = adt7475_update_device(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
unsigned short val;
switch (sattr->nr) {
case ALARM:
return sprintf(buf, "%d\n",
(data->alarms >> sattr->index) & 1);
default:
val = data->voltage[sattr->nr][sattr->index];
return sprintf(buf, "%d\n",
reg2volt(sattr->index, val, data->bypass_attn));
}
}
static ssize_t set_voltage(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct i2c_client *client = to_i2c_client(dev);
struct adt7475_data *data = i2c_get_clientdata(client);
unsigned char reg;
long val;
if (strict_strtol(buf, 10, &val))
return -EINVAL;
mutex_lock(&data->lock);
data->voltage[sattr->nr][sattr->index] =
volt2reg(sattr->index, val, data->bypass_attn);
if (sattr->index < ADT7475_VOLTAGE_COUNT) {
if (sattr->nr == MIN)
reg = VOLTAGE_MIN_REG(sattr->index);
else
reg = VOLTAGE_MAX_REG(sattr->index);
} else {
if (sattr->nr == MIN)
reg = REG_VTT_MIN;
else
reg = REG_VTT_MAX;
}
i2c_smbus_write_byte_data(client, reg,
data->voltage[sattr->nr][sattr->index] >> 2);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct adt7475_data *data = adt7475_update_device(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int out;
switch (sattr->nr) {
case HYSTERSIS:
mutex_lock(&data->lock);
out = data->temp[sattr->nr][sattr->index];
if (sattr->index != 1)
out = (out >> 4) & 0xF;
else
out = (out & 0xF);
out = reg2temp(data, data->temp[THERM][sattr->index]) -
out * 1000;
mutex_unlock(&data->lock);
break;
case OFFSET:
mutex_lock(&data->lock);
out = (s8)data->temp[sattr->nr][sattr->index];
if (data->config5 & CONFIG5_TEMPOFFSET)
out *= 1000;
else
out *= 500;
mutex_unlock(&data->lock);
break;
case ALARM:
out = (data->alarms >> (sattr->index + 4)) & 1;
break;
case FAULT:
out = !!(data->alarms & (sattr->index ? 0x8000 : 0x4000));
break;
default:
out = reg2temp(data, data->temp[sattr->nr][sattr->index]);
}
return sprintf(buf, "%d\n", out);
}
static ssize_t set_temp(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct i2c_client *client = to_i2c_client(dev);
struct adt7475_data *data = i2c_get_clientdata(client);
unsigned char reg = 0;
u8 out;
int temp;
long val;
if (strict_strtol(buf, 10, &val))
return -EINVAL;
mutex_lock(&data->lock);
data->config5 = adt7475_read(REG_CONFIG5);
switch (sattr->nr) {
case OFFSET:
if (data->config5 & CONFIG5_TEMPOFFSET) {
val = SENSORS_LIMIT(val, -63000, 127000);
out = data->temp[OFFSET][sattr->index] = val / 1000;
} else {
val = SENSORS_LIMIT(val, -63000, 64000);
out = data->temp[OFFSET][sattr->index] = val / 500;
}
break;
case HYSTERSIS:
data->temp[THERM][sattr->index] =
adt7475_read(TEMP_THERM_REG(sattr->index)) << 2;
adt7475_read_hystersis(client);
temp = reg2temp(data, data->temp[THERM][sattr->index]);
val = SENSORS_LIMIT(val, temp - 15000, temp);
val = (temp - val) / 1000;
if (sattr->index != 1) {
data->temp[HYSTERSIS][sattr->index] &= 0xF0;
data->temp[HYSTERSIS][sattr->index] |= (val & 0xF) << 4;
} else {
data->temp[HYSTERSIS][sattr->index] &= 0x0F;
data->temp[HYSTERSIS][sattr->index] |= (val & 0xF);
}
out = data->temp[HYSTERSIS][sattr->index];
break;
default:
data->temp[sattr->nr][sattr->index] = temp2reg(data, val);
out = (u8) (data->temp[sattr->nr][sattr->index] >> 2);
}
switch (sattr->nr) {
case MIN:
reg = TEMP_MIN_REG(sattr->index);
break;
case MAX:
reg = TEMP_MAX_REG(sattr->index);
break;
case OFFSET:
reg = TEMP_OFFSET_REG(sattr->index);
break;
case AUTOMIN:
reg = TEMP_TMIN_REG(sattr->index);
break;
case THERM:
reg = TEMP_THERM_REG(sattr->index);
break;
case HYSTERSIS:
if (sattr->index != 2)
reg = REG_REMOTE1_HYSTERSIS;
else
reg = REG_REMOTE2_HYSTERSIS;
break;
}
i2c_smbus_write_byte_data(client, reg, out);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_point2(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct adt7475_data *data = adt7475_update_device(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int out, val;
mutex_lock(&data->lock);
out = (data->range[sattr->index] >> 4) & 0x0F;
val = reg2temp(data, data->temp[AUTOMIN][sattr->index]);
mutex_unlock(&data->lock);
return sprintf(buf, "%d\n", val + autorange_table[out]);
}
static ssize_t set_point2(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct adt7475_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int temp;
long val;
if (strict_strtol(buf, 10, &val))
return -EINVAL;
mutex_lock(&data->lock);
data->config5 = adt7475_read(REG_CONFIG5);
data->temp[AUTOMIN][sattr->index] =
adt7475_read(TEMP_TMIN_REG(sattr->index)) << 2;
data->range[sattr->index] =
adt7475_read(TEMP_TRANGE_REG(sattr->index));
temp = reg2temp(data, data->temp[AUTOMIN][sattr->index]);
val = SENSORS_LIMIT(val, temp + autorange_table[0],
temp + autorange_table[ARRAY_SIZE(autorange_table) - 1]);
val -= temp;
val = find_nearest(val, autorange_table, ARRAY_SIZE(autorange_table));
data->range[sattr->index] &= ~0xF0;
data->range[sattr->index] |= val << 4;
i2c_smbus_write_byte_data(client, TEMP_TRANGE_REG(sattr->index),
data->range[sattr->index]);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_tach(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct adt7475_data *data = adt7475_update_device(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int out;
if (sattr->nr == ALARM)
out = (data->alarms >> (sattr->index + 10)) & 1;
else
out = tach2rpm(data->tach[sattr->nr][sattr->index]);
return sprintf(buf, "%d\n", out);
}
static ssize_t set_tach(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct i2c_client *client = to_i2c_client(dev);
struct adt7475_data *data = i2c_get_clientdata(client);
unsigned long val;
if (strict_strtoul(buf, 10, &val))
return -EINVAL;
mutex_lock(&data->lock);
data->tach[MIN][sattr->index] = rpm2tach(val);
adt7475_write_word(client, TACH_MIN_REG(sattr->index),
data->tach[MIN][sattr->index]);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_pwm(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct adt7475_data *data = adt7475_update_device(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
return sprintf(buf, "%d\n", data->pwm[sattr->nr][sattr->index]);
}
static ssize_t show_pwmchan(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct adt7475_data *data = adt7475_update_device(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
return sprintf(buf, "%d\n", data->pwmchan[sattr->index]);
}
static ssize_t show_pwmctrl(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct adt7475_data *data = adt7475_update_device(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
return sprintf(buf, "%d\n", data->pwmctl[sattr->index]);
}
static ssize_t set_pwm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct i2c_client *client = to_i2c_client(dev);
struct adt7475_data *data = i2c_get_clientdata(client);
unsigned char reg = 0;
long val;
if (strict_strtol(buf, 10, &val))
return -EINVAL;
mutex_lock(&data->lock);
switch (sattr->nr) {
case INPUT:
data->pwm[CONTROL][sattr->index] =
adt7475_read(PWM_CONFIG_REG(sattr->index));
if (((data->pwm[CONTROL][sattr->index] >> 5) & 7) != 7) {
mutex_unlock(&data->lock);
return count;
}
reg = PWM_REG(sattr->index);
break;
case MIN:
reg = PWM_MIN_REG(sattr->index);
break;
case MAX:
reg = PWM_MAX_REG(sattr->index);
break;
}
data->pwm[sattr->nr][sattr->index] = SENSORS_LIMIT(val, 0, 0xFF);
i2c_smbus_write_byte_data(client, reg,
data->pwm[sattr->nr][sattr->index]);
mutex_unlock(&data->lock);
return count;
}
static int hw_set_pwm(struct i2c_client *client, int index,
unsigned int pwmctl, unsigned int pwmchan)
{
struct adt7475_data *data = i2c_get_clientdata(client);
long val = 0;
switch (pwmctl) {
case 0:
val = 0x03;
break;
case 1:
val = 0x07;
break;
case 2:
switch (pwmchan) {
case 1:
val = 0x00;
break;
case 2:
val = 0x01;
break;
case 4:
val = 0x02;
break;
case 6:
val = 0x05;
break;
case 7:
val = 0x06;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
data->pwmctl[index] = pwmctl;
data->pwmchan[index] = pwmchan;
data->pwm[CONTROL][index] &= ~0xE0;
data->pwm[CONTROL][index] |= (val & 7) << 5;
i2c_smbus_write_byte_data(client, PWM_CONFIG_REG(index),
data->pwm[CONTROL][index]);
return 0;
}
static ssize_t set_pwmchan(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct i2c_client *client = to_i2c_client(dev);
struct adt7475_data *data = i2c_get_clientdata(client);
int r;
long val;
if (strict_strtol(buf, 10, &val))
return -EINVAL;
mutex_lock(&data->lock);
adt7475_read_pwm(client, sattr->index);
r = hw_set_pwm(client, sattr->index, data->pwmctl[sattr->index], val);
if (r)
count = r;
mutex_unlock(&data->lock);
return count;
}
static ssize_t set_pwmctrl(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct i2c_client *client = to_i2c_client(dev);
struct adt7475_data *data = i2c_get_clientdata(client);
int r;
long val;
if (strict_strtol(buf, 10, &val))
return -EINVAL;
mutex_lock(&data->lock);
adt7475_read_pwm(client, sattr->index);
r = hw_set_pwm(client, sattr->index, val, data->pwmchan[sattr->index]);
if (r)
count = r;
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_pwmfreq(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct adt7475_data *data = adt7475_update_device(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
return sprintf(buf, "%d\n",
pwmfreq_table[data->range[sattr->index] & 7]);
}
static ssize_t set_pwmfreq(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct i2c_client *client = to_i2c_client(dev);
struct adt7475_data *data = i2c_get_clientdata(client);
int out;
long val;
if (strict_strtol(buf, 10, &val))
return -EINVAL;
out = find_nearest(val, pwmfreq_table, ARRAY_SIZE(pwmfreq_table));
mutex_lock(&data->lock);
data->range[sattr->index] =
adt7475_read(TEMP_TRANGE_REG(sattr->index));
data->range[sattr->index] &= ~7;
data->range[sattr->index] |= out;
i2c_smbus_write_byte_data(client, TEMP_TRANGE_REG(sattr->index),
data->range[sattr->index]);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_pwm_at_crit(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct adt7475_data *data = adt7475_update_device(dev);
return sprintf(buf, "%d\n", !!(data->config4 & CONFIG4_MAXDUTY));
}
static ssize_t set_pwm_at_crit(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct adt7475_data *data = i2c_get_clientdata(client);
long val;
if (strict_strtol(buf, 10, &val))
return -EINVAL;
if (val != 0 && val != 1)
return -EINVAL;
mutex_lock(&data->lock);
data->config4 = i2c_smbus_read_byte_data(client, REG_CONFIG4);
if (val)
data->config4 |= CONFIG4_MAXDUTY;
else
data->config4 &= ~CONFIG4_MAXDUTY;
i2c_smbus_write_byte_data(client, REG_CONFIG4, data->config4);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_vrm(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct adt7475_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", (int)data->vrm);
}
static ssize_t set_vrm(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct adt7475_data *data = dev_get_drvdata(dev);
long val;
if (strict_strtol(buf, 10, &val))
return -EINVAL;
if (val < 0 || val > 255)
return -EINVAL;
data->vrm = val;
return count;
}
static ssize_t show_vid(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct adt7475_data *data = adt7475_update_device(dev);
return sprintf(buf, "%d\n", vid_from_reg(data->vid, data->vrm));
}
static int adt7475_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int vendid, devid, devid2;
const char *name;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
vendid = adt7475_read(REG_VENDID);
devid2 = adt7475_read(REG_DEVID2);
if (vendid != 0x41 ||
(devid2 & 0xf8) != 0x68)
return -ENODEV;
devid = adt7475_read(REG_DEVID);
if (devid == 0x73)
name = "adt7473";
else if (devid == 0x75 && client->addr == 0x2e)
name = "adt7475";
else if (devid == 0x76)
name = "adt7476";
else if ((devid2 & 0xfc) == 0x6c)
name = "adt7490";
else {
dev_dbg(&adapter->dev,
"Couldn't detect an ADT7473/75/76/90 part at "
"0x%02x\n", (unsigned int)client->addr);
return -ENODEV;
}
strlcpy(info->type, name, I2C_NAME_SIZE);
return 0;
}
static void adt7475_remove_files(struct i2c_client *client,
struct adt7475_data *data)
{
sysfs_remove_group(&client->dev.kobj, &adt7475_attr_group);
if (data->has_fan4)
sysfs_remove_group(&client->dev.kobj, &fan4_attr_group);
if (data->has_pwm2)
sysfs_remove_group(&client->dev.kobj, &pwm2_attr_group);
if (data->has_voltage & (1 << 0))
sysfs_remove_group(&client->dev.kobj, &in0_attr_group);
if (data->has_voltage & (1 << 3))
sysfs_remove_group(&client->dev.kobj, &in3_attr_group);
if (data->has_voltage & (1 << 4))
sysfs_remove_group(&client->dev.kobj, &in4_attr_group);
if (data->has_voltage & (1 << 5))
sysfs_remove_group(&client->dev.kobj, &in5_attr_group);
if (data->has_vid)
sysfs_remove_group(&client->dev.kobj, &vid_attr_group);
}
static int adt7475_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
static const char *names[] = {
[adt7473] = "ADT7473",
[adt7475] = "ADT7475",
[adt7476] = "ADT7476",
[adt7490] = "ADT7490",
};
struct adt7475_data *data;
int i, ret = 0, revision;
u8 config2, config3;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
mutex_init(&data->lock);
i2c_set_clientdata(client, data);
switch (id->driver_data) {
case adt7476:
data->has_voltage = 0x0e;
revision = adt7475_read(REG_DEVID2) & 0x07;
break;
case adt7490:
data->has_voltage = 0x3e;
revision = adt7475_read(REG_DEVID2) & 0x03;
if (revision == 0x03)
revision += adt7475_read(REG_DEVREV2);
break;
default:
data->has_voltage = 0x06;
revision = adt7475_read(REG_DEVID2) & 0x07;
}
config3 = adt7475_read(REG_CONFIG3);
if (!(config3 & CONFIG3_SMBALERT))
data->has_pwm2 = 1;
if (id->driver_data == adt7473 && revision >= 1)
data->has_pwm2 = !data->has_pwm2;
data->config4 = adt7475_read(REG_CONFIG4);
if ((data->config4 & CONFIG4_PINFUNC) == 0x0)
data->has_fan4 = 1;
if (id->driver_data == adt7490) {
if ((data->config4 & CONFIG4_PINFUNC) == 0x1 &&
!(config3 & CONFIG3_THERM))
data->has_fan4 = 1;
}
if (id->driver_data == adt7476 || id->driver_data == adt7490) {
if (!(config3 & CONFIG3_THERM) ||
(data->config4 & CONFIG4_PINFUNC) == 0x1)
data->has_voltage |= (1 << 0);
}
if (id->driver_data == adt7476) {
u8 vid = adt7475_read(REG_VID);
if (!(vid & VID_VIDSEL))
data->has_voltage |= (1 << 4);
data->has_vid = !(adt7475_read(REG_CONFIG5) & CONFIG5_VIDGPIO);
}
config2 = adt7475_read(REG_CONFIG2);
if (config2 & CONFIG2_ATTN) {
data->bypass_attn = (0x3 << 3) | 0x3;
} else {
data->bypass_attn = ((data->config4 & CONFIG4_ATTN_IN10) >> 4) |
((data->config4 & CONFIG4_ATTN_IN43) >> 3);
}
data->bypass_attn &= data->has_voltage;
for (i = 0; i < ADT7475_PWM_COUNT; i++)
adt7475_read_pwm(client, i);
ret = sysfs_create_group(&client->dev.kobj, &adt7475_attr_group);
if (ret)
goto efree;
if (data->has_fan4) {
ret = sysfs_create_group(&client->dev.kobj, &fan4_attr_group);
if (ret)
goto eremove;
}
if (data->has_pwm2) {
ret = sysfs_create_group(&client->dev.kobj, &pwm2_attr_group);
if (ret)
goto eremove;
}
if (data->has_voltage & (1 << 0)) {
ret = sysfs_create_group(&client->dev.kobj, &in0_attr_group);
if (ret)
goto eremove;
}
if (data->has_voltage & (1 << 3)) {
ret = sysfs_create_group(&client->dev.kobj, &in3_attr_group);
if (ret)
goto eremove;
}
if (data->has_voltage & (1 << 4)) {
ret = sysfs_create_group(&client->dev.kobj, &in4_attr_group);
if (ret)
goto eremove;
}
if (data->has_voltage & (1 << 5)) {
ret = sysfs_create_group(&client->dev.kobj, &in5_attr_group);
if (ret)
goto eremove;
}
if (data->has_vid) {
data->vrm = vid_which_vrm();
ret = sysfs_create_group(&client->dev.kobj, &vid_attr_group);
if (ret)
goto eremove;
}
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
ret = PTR_ERR(data->hwmon_dev);
goto eremove;
}
dev_info(&client->dev, "%s device, revision %d\n",
names[id->driver_data], revision);
if ((data->has_voltage & 0x11) || data->has_fan4 || data->has_pwm2)
dev_info(&client->dev, "Optional features:%s%s%s%s%s\n",
(data->has_voltage & (1 << 0)) ? " in0" : "",
(data->has_voltage & (1 << 4)) ? " in4" : "",
data->has_fan4 ? " fan4" : "",
data->has_pwm2 ? " pwm2" : "",
data->has_vid ? " vid" : "");
if (data->bypass_attn)
dev_info(&client->dev, "Bypassing attenuators on:%s%s%s%s\n",
(data->bypass_attn & (1 << 0)) ? " in0" : "",
(data->bypass_attn & (1 << 1)) ? " in1" : "",
(data->bypass_attn & (1 << 3)) ? " in3" : "",
(data->bypass_attn & (1 << 4)) ? " in4" : "");
return 0;
eremove:
adt7475_remove_files(client, data);
efree:
kfree(data);
return ret;
}
static int adt7475_remove(struct i2c_client *client)
{
struct adt7475_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
adt7475_remove_files(client, data);
kfree(data);
return 0;
}
static void adt7475_read_hystersis(struct i2c_client *client)
{
struct adt7475_data *data = i2c_get_clientdata(client);
data->temp[HYSTERSIS][0] = (u16) adt7475_read(REG_REMOTE1_HYSTERSIS);
data->temp[HYSTERSIS][1] = data->temp[HYSTERSIS][0];
data->temp[HYSTERSIS][2] = (u16) adt7475_read(REG_REMOTE2_HYSTERSIS);
}
static void adt7475_read_pwm(struct i2c_client *client, int index)
{
struct adt7475_data *data = i2c_get_clientdata(client);
unsigned int v;
data->pwm[CONTROL][index] = adt7475_read(PWM_CONFIG_REG(index));
v = (data->pwm[CONTROL][index] >> 5) & 7;
if (v == 3)
data->pwmctl[index] = 0;
else if (v == 7)
data->pwmctl[index] = 1;
else if (v == 4) {
data->pwm[INPUT][index] = 0;
data->pwm[CONTROL][index] &= ~0xE0;
data->pwm[CONTROL][index] |= (7 << 5);
i2c_smbus_write_byte_data(client, PWM_CONFIG_REG(index),
data->pwm[INPUT][index]);
i2c_smbus_write_byte_data(client, PWM_CONFIG_REG(index),
data->pwm[CONTROL][index]);
data->pwmctl[index] = 1;
} else {
data->pwmctl[index] = 2;
switch (v) {
case 0:
data->pwmchan[index] = 1;
break;
case 1:
data->pwmchan[index] = 2;
break;
case 2:
data->pwmchan[index] = 4;
break;
case 5:
data->pwmchan[index] = 6;
break;
case 6:
data->pwmchan[index] = 7;
break;
}
}
}
static struct adt7475_data *adt7475_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct adt7475_data *data = i2c_get_clientdata(client);
u16 ext;
int i;
mutex_lock(&data->lock);
if (time_after(jiffies, data->measure_updated + HZ * 2) ||
!data->valid) {
data->alarms = adt7475_read(REG_STATUS2) << 8;
data->alarms |= adt7475_read(REG_STATUS1);
ext = (adt7475_read(REG_EXTEND2) << 8) |
adt7475_read(REG_EXTEND1);
for (i = 0; i < ADT7475_VOLTAGE_COUNT; i++) {
if (!(data->has_voltage & (1 << i)))
continue;
data->voltage[INPUT][i] =
(adt7475_read(VOLTAGE_REG(i)) << 2) |
((ext >> (i * 2)) & 3);
}
for (i = 0; i < ADT7475_TEMP_COUNT; i++)
data->temp[INPUT][i] =
(adt7475_read(TEMP_REG(i)) << 2) |
((ext >> ((i + 5) * 2)) & 3);
if (data->has_voltage & (1 << 5)) {
data->alarms |= adt7475_read(REG_STATUS4) << 24;
ext = adt7475_read(REG_EXTEND3);
data->voltage[INPUT][5] = adt7475_read(REG_VTT) << 2 |
((ext >> 4) & 3);
}
for (i = 0; i < ADT7475_TACH_COUNT; i++) {
if (i == 3 && !data->has_fan4)
continue;
data->tach[INPUT][i] =
adt7475_read_word(client, TACH_REG(i));
}
for (i = 0; i < ADT7475_PWM_COUNT; i++) {
if (i == 1 && !data->has_pwm2)
continue;
data->pwm[INPUT][i] = adt7475_read(PWM_REG(i));
}
if (data->has_vid)
data->vid = adt7475_read(REG_VID) & 0x3f;
data->measure_updated = jiffies;
}
if (time_after(jiffies, data->limits_updated + HZ * 60) ||
!data->valid) {
data->config4 = adt7475_read(REG_CONFIG4);
data->config5 = adt7475_read(REG_CONFIG5);
for (i = 0; i < ADT7475_VOLTAGE_COUNT; i++) {
if (!(data->has_voltage & (1 << i)))
continue;
data->voltage[MIN][i] =
adt7475_read(VOLTAGE_MIN_REG(i)) << 2;
data->voltage[MAX][i] =
adt7475_read(VOLTAGE_MAX_REG(i)) << 2;
}
if (data->has_voltage & (1 << 5)) {
data->voltage[MIN][5] = adt7475_read(REG_VTT_MIN) << 2;
data->voltage[MAX][5] = adt7475_read(REG_VTT_MAX) << 2;
}
for (i = 0; i < ADT7475_TEMP_COUNT; i++) {
data->temp[MIN][i] =
adt7475_read(TEMP_MIN_REG(i)) << 2;
data->temp[MAX][i] =
adt7475_read(TEMP_MAX_REG(i)) << 2;
data->temp[AUTOMIN][i] =
adt7475_read(TEMP_TMIN_REG(i)) << 2;
data->temp[THERM][i] =
adt7475_read(TEMP_THERM_REG(i)) << 2;
data->temp[OFFSET][i] =
adt7475_read(TEMP_OFFSET_REG(i));
}
adt7475_read_hystersis(client);
for (i = 0; i < ADT7475_TACH_COUNT; i++) {
if (i == 3 && !data->has_fan4)
continue;
data->tach[MIN][i] =
adt7475_read_word(client, TACH_MIN_REG(i));
}
for (i = 0; i < ADT7475_PWM_COUNT; i++) {
if (i == 1 && !data->has_pwm2)
continue;
data->pwm[MAX][i] = adt7475_read(PWM_MAX_REG(i));
data->pwm[MIN][i] = adt7475_read(PWM_MIN_REG(i));
adt7475_read_pwm(client, i);
}
data->range[0] = adt7475_read(TEMP_TRANGE_REG(0));
data->range[1] = adt7475_read(TEMP_TRANGE_REG(1));
data->range[2] = adt7475_read(TEMP_TRANGE_REG(2));
data->limits_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->lock);
return data;
}
static int __init sensors_adt7475_init(void)
{
return i2c_add_driver(&adt7475_driver);
}
static void __exit sensors_adt7475_exit(void)
{
i2c_del_driver(&adt7475_driver);
}
