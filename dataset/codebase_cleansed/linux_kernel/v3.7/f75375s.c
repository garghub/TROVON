static inline int f75375_read8(struct i2c_client *client, u8 reg)
{
return i2c_smbus_read_byte_data(client, reg);
}
static inline u16 f75375_read16(struct i2c_client *client, u8 reg)
{
return (i2c_smbus_read_byte_data(client, reg) << 8)
| i2c_smbus_read_byte_data(client, reg + 1);
}
static inline void f75375_write8(struct i2c_client *client, u8 reg,
u8 value)
{
i2c_smbus_write_byte_data(client, reg, value);
}
static inline void f75375_write16(struct i2c_client *client, u8 reg,
u16 value)
{
int err = i2c_smbus_write_byte_data(client, reg, (value >> 8));
if (err)
return;
i2c_smbus_write_byte_data(client, reg + 1, (value & 0xFF));
}
static void f75375_write_pwm(struct i2c_client *client, int nr)
{
struct f75375_data *data = i2c_get_clientdata(client);
if (data->kind == f75387)
f75375_write16(client, F75375_REG_FAN_EXP(nr), data->pwm[nr]);
else
f75375_write8(client, F75375_REG_FAN_PWM_DUTY(nr),
data->pwm[nr]);
}
static struct f75375_data *f75375_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct f75375_data *data = i2c_get_clientdata(client);
int nr;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_limits + 60 * HZ)
|| !data->valid) {
for (nr = 0; nr < 2; nr++) {
data->temp_high[nr] =
f75375_read8(client, F75375_REG_TEMP_HIGH(nr));
data->temp_max_hyst[nr] =
f75375_read8(client, F75375_REG_TEMP_HYST(nr));
data->fan_max[nr] =
f75375_read16(client, F75375_REG_FAN_FULL(nr));
data->fan_min[nr] =
f75375_read16(client, F75375_REG_FAN_MIN(nr));
data->fan_target[nr] =
f75375_read16(client, F75375_REG_FAN_EXP(nr));
}
for (nr = 0; nr < 4; nr++) {
data->in_max[nr] =
f75375_read8(client, F75375_REG_VOLT_HIGH(nr));
data->in_min[nr] =
f75375_read8(client, F75375_REG_VOLT_LOW(nr));
}
data->fan_timer = f75375_read8(client, F75375_REG_FAN_TIMER);
data->last_limits = jiffies;
}
if (time_after(jiffies, data->last_updated + 2 * HZ)
|| !data->valid) {
for (nr = 0; nr < 2; nr++) {
data->pwm[nr] = f75375_read8(client,
F75375_REG_FAN_PWM_DUTY(nr));
data->temp11[nr] =
f75375_read8(client, F75375_REG_TEMP(nr)) << 8;
if (data->kind == f75387)
data->temp11[nr] |=
f75375_read8(client,
F75387_REG_TEMP11_LSB(nr));
data->fan[nr] =
f75375_read16(client, F75375_REG_FAN(nr));
}
for (nr = 0; nr < 4; nr++)
data->in[nr] =
f75375_read8(client, F75375_REG_VOLT(nr));
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static inline u16 rpm_from_reg(u16 reg)
{
if (reg == 0 || reg == 0xffff)
return 0;
return 1500000 / reg;
}
static inline u16 rpm_to_reg(int rpm)
{
if (rpm < 367 || rpm > 0xffff)
return 0xffff;
return 1500000 / rpm;
}
static bool duty_mode_enabled(u8 pwm_enable)
{
switch (pwm_enable) {
case 0:
case 1:
case 4:
return true;
case 2:
case 3:
return false;
default:
BUG();
return true;
}
}
static bool auto_mode_enabled(u8 pwm_enable)
{
switch (pwm_enable) {
case 0:
case 1:
case 3:
return false;
case 2:
case 4:
return true;
default:
BUG();
return false;
}
}
static ssize_t set_fan_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct f75375_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
mutex_lock(&data->update_lock);
data->fan_min[nr] = rpm_to_reg(val);
f75375_write16(client, F75375_REG_FAN_MIN(nr), data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_fan_target(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct f75375_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
if (auto_mode_enabled(data->pwm_enable[nr]))
return -EINVAL;
if (data->kind == f75387 && duty_mode_enabled(data->pwm_enable[nr]))
return -EINVAL;
mutex_lock(&data->update_lock);
data->fan_target[nr] = rpm_to_reg(val);
f75375_write16(client, F75375_REG_FAN_EXP(nr), data->fan_target[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_pwm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct f75375_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
if (auto_mode_enabled(data->pwm_enable[nr]) ||
!duty_mode_enabled(data->pwm_enable[nr]))
return -EINVAL;
mutex_lock(&data->update_lock);
data->pwm[nr] = SENSORS_LIMIT(val, 0, 255);
f75375_write_pwm(client, nr);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_enable(struct device *dev, struct device_attribute
*attr, char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct f75375_data *data = f75375_update_device(dev);
return sprintf(buf, "%d\n", data->pwm_enable[nr]);
}
static int set_pwm_enable_direct(struct i2c_client *client, int nr, int val)
{
struct f75375_data *data = i2c_get_clientdata(client);
u8 fanmode;
if (val < 0 || val > 4)
return -EINVAL;
fanmode = f75375_read8(client, F75375_REG_FAN_TIMER);
if (data->kind == f75387) {
if (duty_mode_enabled(data->pwm_enable[nr]) !=
duty_mode_enabled(val))
return -EOPNOTSUPP;
fanmode &= ~(1 << F75387_FAN_DUTY_MODE(nr));
fanmode &= ~(1 << F75387_FAN_MANU_MODE(nr));
switch (val) {
case 0:
fanmode |= (1 << F75387_FAN_MANU_MODE(nr));
fanmode |= (1 << F75387_FAN_DUTY_MODE(nr));
data->pwm[nr] = 255;
break;
case 1:
fanmode |= (1 << F75387_FAN_MANU_MODE(nr));
fanmode |= (1 << F75387_FAN_DUTY_MODE(nr));
break;
case 2:
break;
case 3:
fanmode |= (1 << F75387_FAN_MANU_MODE(nr));
break;
case 4:
fanmode |= (1 << F75387_FAN_DUTY_MODE(nr));
break;
}
} else {
fanmode &= ~(3 << FAN_CTRL_MODE(nr));
switch (val) {
case 0:
fanmode |= (3 << FAN_CTRL_MODE(nr));
data->pwm[nr] = 255;
break;
case 1:
fanmode |= (3 << FAN_CTRL_MODE(nr));
break;
case 2:
fanmode |= (1 << FAN_CTRL_MODE(nr));
break;
case 3:
break;
case 4:
return -EINVAL;
}
}
f75375_write8(client, F75375_REG_FAN_TIMER, fanmode);
data->pwm_enable[nr] = val;
if (val == 0)
f75375_write_pwm(client, nr);
return 0;
}
static ssize_t set_pwm_enable(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct f75375_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
mutex_lock(&data->update_lock);
err = set_pwm_enable_direct(client, nr, val);
mutex_unlock(&data->update_lock);
return err ? err : count;
}
static ssize_t set_pwm_mode(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct f75375_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
u8 conf;
char reg, ctrl;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
if (!(val == 0 || val == 1))
return -EINVAL;
if (data->kind == f75373 && val == 0)
return -EINVAL;
if (data->kind == f75387) {
reg = F75375_REG_FAN_TIMER;
ctrl = F75387_FAN_CTRL_LINEAR(nr);
} else {
reg = F75375_REG_CONFIG1;
ctrl = F75375_FAN_CTRL_LINEAR(nr);
}
mutex_lock(&data->update_lock);
conf = f75375_read8(client, reg);
conf &= ~(1 << ctrl);
if (val == 0)
conf |= (1 << ctrl);
f75375_write8(client, reg, conf);
data->pwm_mode[nr] = val;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm(struct device *dev, struct device_attribute
*attr, char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct f75375_data *data = f75375_update_device(dev);
return sprintf(buf, "%d\n", data->pwm[nr]);
}
static ssize_t show_pwm_mode(struct device *dev, struct device_attribute
*attr, char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct f75375_data *data = f75375_update_device(dev);
return sprintf(buf, "%d\n", data->pwm_mode[nr]);
}
static ssize_t show_in(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct f75375_data *data = f75375_update_device(dev);
return sprintf(buf, "%d\n", VOLT_FROM_REG(data->in[nr]));
}
static ssize_t show_in_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct f75375_data *data = f75375_update_device(dev);
return sprintf(buf, "%d\n", VOLT_FROM_REG(data->in_max[nr]));
}
static ssize_t show_in_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct f75375_data *data = f75375_update_device(dev);
return sprintf(buf, "%d\n", VOLT_FROM_REG(data->in_min[nr]));
}
static ssize_t set_in_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct f75375_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
val = SENSORS_LIMIT(VOLT_TO_REG(val), 0, 0xff);
mutex_lock(&data->update_lock);
data->in_max[nr] = val;
f75375_write8(client, F75375_REG_VOLT_HIGH(nr), data->in_max[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_in_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct f75375_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
val = SENSORS_LIMIT(VOLT_TO_REG(val), 0, 0xff);
mutex_lock(&data->update_lock);
data->in_min[nr] = val;
f75375_write8(client, F75375_REG_VOLT_LOW(nr), data->in_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp11(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct f75375_data *data = f75375_update_device(dev);
return sprintf(buf, "%d\n", TEMP11_FROM_REG(data->temp11[nr]));
}
static ssize_t show_temp_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct f75375_data *data = f75375_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_high[nr]));
}
static ssize_t show_temp_max_hyst(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct f75375_data *data = f75375_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_max_hyst[nr]));
}
static ssize_t set_temp_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct f75375_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
val = SENSORS_LIMIT(TEMP_TO_REG(val), 0, 127);
mutex_lock(&data->update_lock);
data->temp_high[nr] = val;
f75375_write8(client, F75375_REG_TEMP_HIGH(nr), data->temp_high[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_temp_max_hyst(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct f75375_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
val = SENSORS_LIMIT(TEMP_TO_REG(val), 0, 127);
mutex_lock(&data->update_lock);
data->temp_max_hyst[nr] = val;
f75375_write8(client, F75375_REG_TEMP_HYST(nr),
data->temp_max_hyst[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static void f75375_init(struct i2c_client *client, struct f75375_data *data,
struct f75375s_platform_data *f75375s_pdata)
{
int nr;
if (!f75375s_pdata) {
u8 conf, mode;
int nr;
conf = f75375_read8(client, F75375_REG_CONFIG1);
mode = f75375_read8(client, F75375_REG_FAN_TIMER);
for (nr = 0; nr < 2; nr++) {
if (data->kind == f75387) {
bool manu, duty;
if (!(mode & (1 << F75387_FAN_CTRL_LINEAR(nr))))
data->pwm_mode[nr] = 1;
manu = ((mode >> F75387_FAN_MANU_MODE(nr)) & 1);
duty = ((mode >> F75387_FAN_DUTY_MODE(nr)) & 1);
if (!manu && duty)
data->pwm_enable[nr] = 4;
else if (manu && !duty)
data->pwm_enable[nr] = 3;
else if (!manu && !duty)
data->pwm_enable[nr] = 2;
else
data->pwm_enable[nr] = 1;
} else {
if (!(conf & (1 << F75375_FAN_CTRL_LINEAR(nr))))
data->pwm_mode[nr] = 1;
switch ((mode >> FAN_CTRL_MODE(nr)) & 3) {
case 0:
data->pwm_enable[nr] = 3;
break;
case 1:
data->pwm_enable[nr] = 2;
break;
default:
data->pwm_enable[nr] = 1;
break;
}
}
}
return;
}
set_pwm_enable_direct(client, 0, f75375s_pdata->pwm_enable[0]);
set_pwm_enable_direct(client, 1, f75375s_pdata->pwm_enable[1]);
for (nr = 0; nr < 2; nr++) {
if (auto_mode_enabled(f75375s_pdata->pwm_enable[nr]) ||
!duty_mode_enabled(f75375s_pdata->pwm_enable[nr]))
continue;
data->pwm[nr] = SENSORS_LIMIT(f75375s_pdata->pwm[nr], 0, 255);
f75375_write_pwm(client, nr);
}
}
static int f75375_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct f75375_data *data;
struct f75375s_platform_data *f75375s_pdata = client->dev.platform_data;
int err;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
data = devm_kzalloc(&client->dev, sizeof(struct f75375_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
data->kind = id->driver_data;
err = sysfs_create_group(&client->dev.kobj, &f75375_group);
if (err)
return err;
if (data->kind != f75373) {
err = sysfs_chmod_file(&client->dev.kobj,
&sensor_dev_attr_pwm1_mode.dev_attr.attr,
S_IRUGO | S_IWUSR);
if (err)
goto exit_remove;
err = sysfs_chmod_file(&client->dev.kobj,
&sensor_dev_attr_pwm2_mode.dev_attr.attr,
S_IRUGO | S_IWUSR);
if (err)
goto exit_remove;
}
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
f75375_init(client, data, f75375s_pdata);
return 0;
exit_remove:
sysfs_remove_group(&client->dev.kobj, &f75375_group);
return err;
}
static int f75375_remove(struct i2c_client *client)
{
struct f75375_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &f75375_group);
return 0;
}
static int f75375_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
u16 vendid, chipid;
u8 version;
const char *name;
vendid = f75375_read16(client, F75375_REG_VENDOR);
chipid = f75375_read16(client, F75375_CHIP_ID);
if (vendid != 0x1934)
return -ENODEV;
if (chipid == 0x0306)
name = "f75375";
else if (chipid == 0x0204)
name = "f75373";
else if (chipid == 0x0410)
name = "f75387";
else
return -ENODEV;
version = f75375_read8(client, F75375_REG_VERSION);
dev_info(&adapter->dev, "found %s version: %02X\n", name, version);
strlcpy(info->type, name, I2C_NAME_SIZE);
return 0;
}
