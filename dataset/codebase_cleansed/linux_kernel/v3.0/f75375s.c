static inline int f75375_read8(struct i2c_client *client, u8 reg)
{
return i2c_smbus_read_byte_data(client, reg);
}
static inline u16 f75375_read16(struct i2c_client *client, u8 reg)
{
return ((i2c_smbus_read_byte_data(client, reg) << 8)
| i2c_smbus_read_byte_data(client, reg + 1));
}
static inline void f75375_write8(struct i2c_client *client, u8 reg,
u8 value)
{
i2c_smbus_write_byte_data(client, reg, value);
}
static inline void f75375_write16(struct i2c_client *client, u8 reg,
u16 value)
{
int err = i2c_smbus_write_byte_data(client, reg, (value << 8));
if (err)
return;
i2c_smbus_write_byte_data(client, reg + 1, (value & 0xFF));
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
data->fan_full[nr] =
f75375_read16(client, F75375_REG_FAN_FULL(nr));
data->fan_min[nr] =
f75375_read16(client, F75375_REG_FAN_MIN(nr));
data->fan_exp[nr] =
f75375_read16(client, F75375_REG_FAN_EXP(nr));
data->pwm[nr] = f75375_read8(client,
F75375_REG_FAN_PWM_DUTY(nr));
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
data->temp[nr] =
f75375_read8(client, F75375_REG_TEMP(nr));
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
return (1500000 / reg);
}
static inline u16 rpm_to_reg(int rpm)
{
if (rpm < 367 || rpm > 0xffff)
return 0xffff;
return (1500000 / rpm);
}
static ssize_t set_fan_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct f75375_data *data = i2c_get_clientdata(client);
int val = simple_strtoul(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->fan_min[nr] = rpm_to_reg(val);
f75375_write16(client, F75375_REG_FAN_MIN(nr), data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_fan_exp(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct f75375_data *data = i2c_get_clientdata(client);
int val = simple_strtoul(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->fan_exp[nr] = rpm_to_reg(val);
f75375_write16(client, F75375_REG_FAN_EXP(nr), data->fan_exp[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_pwm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct f75375_data *data = i2c_get_clientdata(client);
int val = simple_strtoul(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->pwm[nr] = SENSORS_LIMIT(val, 0, 255);
f75375_write8(client, F75375_REG_FAN_PWM_DUTY(nr), data->pwm[nr]);
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
fanmode &= ~(3 << FAN_CTRL_MODE(nr));
switch (val) {
case 0:
fanmode |= (3 << FAN_CTRL_MODE(nr));
data->pwm[nr] = 255;
f75375_write8(client, F75375_REG_FAN_PWM_DUTY(nr),
data->pwm[nr]);
break;
case 1:
fanmode |= (3 << FAN_CTRL_MODE(nr));
break;
case 2:
fanmode |= (2 << FAN_CTRL_MODE(nr));
break;
case 3:
break;
}
f75375_write8(client, F75375_REG_FAN_TIMER, fanmode);
data->pwm_enable[nr] = val;
return 0;
}
static ssize_t set_pwm_enable(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct f75375_data *data = i2c_get_clientdata(client);
int val = simple_strtoul(buf, NULL, 10);
int err = 0;
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
int val = simple_strtoul(buf, NULL, 10);
u8 conf = 0;
if (!(val == 0 || val == 1))
return -EINVAL;
mutex_lock(&data->update_lock);
conf = f75375_read8(client, F75375_REG_CONFIG1);
conf &= ~(1 << FAN_CTRL_LINEAR(nr));
if (val == 0)
conf |= (1 << FAN_CTRL_LINEAR(nr)) ;
f75375_write8(client, F75375_REG_CONFIG1, conf);
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
int val = simple_strtoul(buf, NULL, 10);
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
int val = simple_strtoul(buf, NULL, 10);
val = SENSORS_LIMIT(VOLT_TO_REG(val), 0, 0xff);
mutex_lock(&data->update_lock);
data->in_min[nr] = val;
f75375_write8(client, F75375_REG_VOLT_LOW(nr), data->in_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct f75375_data *data = f75375_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[nr]));
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
int val = simple_strtol(buf, NULL, 10);
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
int val = simple_strtol(buf, NULL, 10);
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
set_pwm_enable_direct(client, 0, f75375s_pdata->pwm_enable[0]);
set_pwm_enable_direct(client, 1, f75375s_pdata->pwm_enable[1]);
for (nr = 0; nr < 2; nr++) {
data->pwm[nr] = SENSORS_LIMIT(f75375s_pdata->pwm[nr], 0, 255);
f75375_write8(client, F75375_REG_FAN_PWM_DUTY(nr),
data->pwm[nr]);
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
if (!(data = kzalloc(sizeof(struct f75375_data), GFP_KERNEL)))
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
data->kind = id->driver_data;
if ((err = sysfs_create_group(&client->dev.kobj, &f75375_group)))
goto exit_free;
if (data->kind == f75375) {
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
if (f75375s_pdata != NULL)
f75375_init(client, data, f75375s_pdata);
return 0;
exit_remove:
sysfs_remove_group(&client->dev.kobj, &f75375_group);
exit_free:
kfree(data);
return err;
}
static int f75375_remove(struct i2c_client *client)
{
struct f75375_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &f75375_group);
kfree(data);
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
if (chipid == 0x0306 && vendid == 0x1934)
name = "f75375";
else if (chipid == 0x0204 && vendid == 0x1934)
name = "f75373";
else
return -ENODEV;
version = f75375_read8(client, F75375_REG_VERSION);
dev_info(&adapter->dev, "found %s version: %02X\n", name, version);
strlcpy(info->type, name, I2C_NAME_SIZE);
return 0;
}
static int __init sensors_f75375_init(void)
{
return i2c_add_driver(&f75375_driver);
}
static void __exit sensors_f75375_exit(void)
{
i2c_del_driver(&f75375_driver);
}
