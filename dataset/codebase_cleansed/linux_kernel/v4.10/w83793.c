static inline unsigned long FAN_FROM_REG(u16 val)
{
if ((val >= 0xfff) || (val == 0))
return 0;
return 1350000UL / val;
}
static inline u16 FAN_TO_REG(long rpm)
{
if (rpm <= 0)
return 0x0fff;
return clamp_val((1350000 + (rpm >> 1)) / rpm, 1, 0xffe);
}
static inline unsigned long TIME_FROM_REG(u8 reg)
{
return reg * 100;
}
static inline u8 TIME_TO_REG(unsigned long val)
{
return clamp_val((val + 50) / 100, 0, 0xff);
}
static inline long TEMP_FROM_REG(s8 reg)
{
return reg * 1000;
}
static inline s8 TEMP_TO_REG(long val, s8 min, s8 max)
{
return clamp_val((val + (val < 0 ? -500 : 500)) / 1000, min, max);
}
static void w83793_release_resources(struct kref *ref)
{
struct w83793_data *data = container_of(ref, struct w83793_data, kref);
kfree(data);
}
static ssize_t
show_vrm(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83793_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", data->vrm);
}
static ssize_t
show_vid(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83793_data *data = w83793_update_device(dev);
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int index = sensor_attr->index;
return sprintf(buf, "%d\n", vid_from_reg(data->vid[index], data->vrm));
}
static ssize_t
store_vrm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct w83793_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
if (val > 255)
return -EINVAL;
data->vrm = val;
return count;
}
static ssize_t
show_alarm_beep(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83793_data *data = w83793_update_device(dev);
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index >> 3;
int bit = sensor_attr->index & 0x07;
u8 val;
if (nr == ALARM_STATUS) {
val = (data->alarms[index] >> (bit)) & 1;
} else {
val = (data->beeps[index] >> (bit)) & 1;
}
return sprintf(buf, "%u\n", val);
}
static ssize_t
store_beep(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct w83793_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int index = sensor_attr->index >> 3;
int shift = sensor_attr->index & 0x07;
u8 beep_bit = 1 << shift;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
if (val > 1)
return -EINVAL;
mutex_lock(&data->update_lock);
data->beeps[index] = w83793_read_value(client, W83793_REG_BEEP(index));
data->beeps[index] &= ~beep_bit;
data->beeps[index] |= val << shift;
w83793_write_value(client, W83793_REG_BEEP(index), data->beeps[index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_beep_enable(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83793_data *data = w83793_update_device(dev);
return sprintf(buf, "%u\n", (data->beep_enable >> 1) & 0x01);
}
static ssize_t
store_beep_enable(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct w83793_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
if (val > 1)
return -EINVAL;
mutex_lock(&data->update_lock);
data->beep_enable = w83793_read_value(client, W83793_REG_OVT_BEEP)
& 0xfd;
data->beep_enable |= val << 1;
w83793_write_value(client, W83793_REG_OVT_BEEP, data->beep_enable);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
store_chassis_clear(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct w83793_data *data = i2c_get_clientdata(client);
unsigned long val;
u8 reg;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
if (val)
return -EINVAL;
mutex_lock(&data->update_lock);
reg = w83793_read_value(client, W83793_REG_CLR_CHASSIS);
w83793_write_value(client, W83793_REG_CLR_CHASSIS, reg | 0x80);
data->valid = 0;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_fan(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index;
struct w83793_data *data = w83793_update_device(dev);
u16 val;
if (nr == FAN_INPUT)
val = data->fan[index] & 0x0fff;
else
val = data->fan_min[index] & 0x0fff;
return sprintf(buf, "%lu\n", FAN_FROM_REG(val));
}
static ssize_t
store_fan_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int index = sensor_attr->index;
struct i2c_client *client = to_i2c_client(dev);
struct w83793_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
val = FAN_TO_REG(val);
mutex_lock(&data->update_lock);
data->fan_min[index] = val;
w83793_write_value(client, W83793_REG_FAN_MIN(index),
(val >> 8) & 0xff);
w83793_write_value(client, W83793_REG_FAN_MIN(index) + 1, val & 0xff);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_pwm(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
struct w83793_data *data = w83793_update_device(dev);
u16 val;
int nr = sensor_attr->nr;
int index = sensor_attr->index;
if (nr == PWM_STOP_TIME)
val = TIME_FROM_REG(data->pwm_stop_time[index]);
else
val = (data->pwm[index][nr] & 0x3f) << 2;
return sprintf(buf, "%d\n", val);
}
static ssize_t
store_pwm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct w83793_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
if (nr == PWM_STOP_TIME) {
val = TIME_TO_REG(val);
data->pwm_stop_time[index] = val;
w83793_write_value(client, W83793_REG_PWM_STOP_TIME(index),
val);
} else {
val = clamp_val(val, 0, 0xff) >> 2;
data->pwm[index][nr] =
w83793_read_value(client, W83793_REG_PWM(index, nr)) & 0xc0;
data->pwm[index][nr] |= val;
w83793_write_value(client, W83793_REG_PWM(index, nr),
data->pwm[index][nr]);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_temp(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index;
struct w83793_data *data = w83793_update_device(dev);
long temp = TEMP_FROM_REG(data->temp[index][nr]);
if (nr == TEMP_READ && index < 4) {
int low = ((data->temp_low_bits >> (index * 2)) & 0x03) * 250;
temp += temp > 0 ? low : -low;
}
return sprintf(buf, "%ld\n", temp);
}
static ssize_t
store_temp(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index;
struct i2c_client *client = to_i2c_client(dev);
struct w83793_data *data = i2c_get_clientdata(client);
long tmp;
int err;
err = kstrtol(buf, 10, &tmp);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp[index][nr] = TEMP_TO_REG(tmp, -128, 127);
w83793_write_value(client, W83793_REG_TEMP[index][nr],
data->temp[index][nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_temp_mode(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83793_data *data = w83793_update_device(dev);
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int index = sensor_attr->index;
u8 mask = (index < 4) ? 0x03 : 0x01;
u8 shift = (index < 4) ? (2 * index) : (index - 4);
u8 tmp;
index = (index < 4) ? 0 : 1;
tmp = (data->temp_mode[index] >> shift) & mask;
if (tmp == 1)
tmp = index == 0 ? 3 : 4;
else
tmp = TO_TEMP_MODE[tmp];
return sprintf(buf, "%d\n", tmp);
}
static ssize_t
store_temp_mode(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct w83793_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int index = sensor_attr->index;
u8 mask = (index < 4) ? 0x03 : 0x01;
u8 shift = (index < 4) ? (2 * index) : (index - 4);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
if ((val == 6) && (index < 4)) {
val -= 3;
} else if ((val == 3 && index < 4)
|| (val == 4 && index >= 4)) {
val = !!val;
} else {
return -EINVAL;
}
index = (index < 4) ? 0 : 1;
mutex_lock(&data->update_lock);
data->temp_mode[index] =
w83793_read_value(client, W83793_REG_TEMP_MODE[index]);
data->temp_mode[index] &= ~(mask << shift);
data->temp_mode[index] |= val << shift;
w83793_write_value(client, W83793_REG_TEMP_MODE[index],
data->temp_mode[index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_sf_setup(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
struct w83793_data *data = w83793_update_device(dev);
u32 val = 0;
if (nr == SETUP_PWM_DEFAULT)
val = (data->pwm_default & 0x3f) << 2;
else if (nr == SETUP_PWM_UPTIME)
val = TIME_FROM_REG(data->pwm_uptime);
else if (nr == SETUP_PWM_DOWNTIME)
val = TIME_FROM_REG(data->pwm_downtime);
else if (nr == SETUP_TEMP_CRITICAL)
val = TEMP_FROM_REG(data->temp_critical & 0x7f);
return sprintf(buf, "%d\n", val);
}
static ssize_t
store_sf_setup(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
struct i2c_client *client = to_i2c_client(dev);
struct w83793_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
if (nr == SETUP_PWM_DEFAULT) {
data->pwm_default =
w83793_read_value(client, W83793_REG_PWM_DEFAULT) & 0xc0;
data->pwm_default |= clamp_val(val, 0, 0xff) >> 2;
w83793_write_value(client, W83793_REG_PWM_DEFAULT,
data->pwm_default);
} else if (nr == SETUP_PWM_UPTIME) {
data->pwm_uptime = TIME_TO_REG(val);
data->pwm_uptime += data->pwm_uptime == 0 ? 1 : 0;
w83793_write_value(client, W83793_REG_PWM_UPTIME,
data->pwm_uptime);
} else if (nr == SETUP_PWM_DOWNTIME) {
data->pwm_downtime = TIME_TO_REG(val);
data->pwm_downtime += data->pwm_downtime == 0 ? 1 : 0;
w83793_write_value(client, W83793_REG_PWM_DOWNTIME,
data->pwm_downtime);
} else {
data->temp_critical =
w83793_read_value(client, W83793_REG_TEMP_CRITICAL) & 0x80;
data->temp_critical |= TEMP_TO_REG(val, 0, 0x7f);
w83793_write_value(client, W83793_REG_TEMP_CRITICAL,
data->temp_critical);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_sf_ctrl(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index;
struct w83793_data *data = w83793_update_device(dev);
u32 val;
if (nr == TEMP_FAN_MAP) {
val = data->temp_fan_map[index];
} else if (nr == TEMP_PWM_ENABLE) {
val = ((data->pwm_enable >> index) & 0x01) + 2;
} else if (nr == TEMP_CRUISE) {
val = TEMP_FROM_REG(data->temp_cruise[index] & 0x7f);
} else {
val = data->tolerance[index >> 1] >> ((index & 0x01) ? 4 : 0);
val = TEMP_FROM_REG(val & 0x0f);
}
return sprintf(buf, "%d\n", val);
}
static ssize_t
store_sf_ctrl(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index;
struct i2c_client *client = to_i2c_client(dev);
struct w83793_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
if (nr == TEMP_FAN_MAP) {
val = clamp_val(val, 0, 255);
w83793_write_value(client, W83793_REG_TEMP_FAN_MAP(index), val);
data->temp_fan_map[index] = val;
} else if (nr == TEMP_PWM_ENABLE) {
if (val == 2 || val == 3) {
data->pwm_enable =
w83793_read_value(client, W83793_REG_PWM_ENABLE);
if (val - 2)
data->pwm_enable |= 1 << index;
else
data->pwm_enable &= ~(1 << index);
w83793_write_value(client, W83793_REG_PWM_ENABLE,
data->pwm_enable);
} else {
mutex_unlock(&data->update_lock);
return -EINVAL;
}
} else if (nr == TEMP_CRUISE) {
data->temp_cruise[index] =
w83793_read_value(client, W83793_REG_TEMP_CRUISE(index));
data->temp_cruise[index] &= 0x80;
data->temp_cruise[index] |= TEMP_TO_REG(val, 0, 0x7f);
w83793_write_value(client, W83793_REG_TEMP_CRUISE(index),
data->temp_cruise[index]);
} else {
int i = index >> 1;
u8 shift = (index & 0x01) ? 4 : 0;
data->tolerance[i] =
w83793_read_value(client, W83793_REG_TEMP_TOL(i));
data->tolerance[i] &= ~(0x0f << shift);
data->tolerance[i] |= TEMP_TO_REG(val, 0, 0x0f) << shift;
w83793_write_value(client, W83793_REG_TEMP_TOL(i),
data->tolerance[i]);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_sf2_pwm(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index;
struct w83793_data *data = w83793_update_device(dev);
return sprintf(buf, "%d\n", (data->sf2_pwm[index][nr] & 0x3f) << 2);
}
static ssize_t
store_sf2_pwm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct w83793_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
val = clamp_val(val, 0, 0xff) >> 2;
mutex_lock(&data->update_lock);
data->sf2_pwm[index][nr] =
w83793_read_value(client, W83793_REG_SF2_PWM(index, nr)) & 0xc0;
data->sf2_pwm[index][nr] |= val;
w83793_write_value(client, W83793_REG_SF2_PWM(index, nr),
data->sf2_pwm[index][nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_sf2_temp(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index;
struct w83793_data *data = w83793_update_device(dev);
return sprintf(buf, "%ld\n",
TEMP_FROM_REG(data->sf2_temp[index][nr] & 0x7f));
}
static ssize_t
store_sf2_temp(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct w83793_data *data = i2c_get_clientdata(client);
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
val = TEMP_TO_REG(val, 0, 0x7f);
mutex_lock(&data->update_lock);
data->sf2_temp[index][nr] =
w83793_read_value(client, W83793_REG_SF2_TEMP(index, nr)) & 0x80;
data->sf2_temp[index][nr] |= val;
w83793_write_value(client, W83793_REG_SF2_TEMP(index, nr),
data->sf2_temp[index][nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_in(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index;
struct w83793_data *data = w83793_update_device(dev);
u16 val = data->in[index][nr];
if (index < 3) {
val <<= 2;
val += (data->in_low_bits[nr] >> (index * 2)) & 0x3;
}
val = val * scale_in[index] + scale_in_add[index];
return sprintf(buf, "%d\n", val);
}
static ssize_t
store_in(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index;
struct i2c_client *client = to_i2c_client(dev);
struct w83793_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
val = (val + scale_in[index] / 2) / scale_in[index];
mutex_lock(&data->update_lock);
if (index > 2) {
if (nr == 1 || nr == 2)
val -= scale_in_add[index] / scale_in[index];
val = clamp_val(val, 0, 255);
} else {
val = clamp_val(val, 0, 0x3FF);
data->in_low_bits[nr] =
w83793_read_value(client, W83793_REG_IN_LOW_BITS[nr]);
data->in_low_bits[nr] &= ~(0x03 << (2 * index));
data->in_low_bits[nr] |= (val & 0x03) << (2 * index);
w83793_write_value(client, W83793_REG_IN_LOW_BITS[nr],
data->in_low_bits[nr]);
val >>= 2;
}
data->in[index][nr] = val;
w83793_write_value(client, W83793_REG_IN[index][nr],
data->in[index][nr]);
mutex_unlock(&data->update_lock);
return count;
}
static void w83793_init_client(struct i2c_client *client)
{
if (reset)
w83793_write_value(client, W83793_REG_CONFIG, 0x80);
w83793_write_value(client, W83793_REG_CONFIG,
w83793_read_value(client, W83793_REG_CONFIG) | 0x01);
}
static int watchdog_set_timeout(struct w83793_data *data, int timeout)
{
unsigned int mtimeout;
int ret;
mtimeout = DIV_ROUND_UP(timeout, 60);
if (mtimeout > 255)
return -EINVAL;
mutex_lock(&data->watchdog_lock);
if (!data->client) {
ret = -ENODEV;
goto leave;
}
data->watchdog_timeout = mtimeout;
w83793_write_value(data->client, W83793_REG_WDT_TIMEOUT,
data->watchdog_timeout);
ret = mtimeout * 60;
leave:
mutex_unlock(&data->watchdog_lock);
return ret;
}
static int watchdog_get_timeout(struct w83793_data *data)
{
int timeout;
mutex_lock(&data->watchdog_lock);
timeout = data->watchdog_timeout * 60;
mutex_unlock(&data->watchdog_lock);
return timeout;
}
static int watchdog_trigger(struct w83793_data *data)
{
int ret = 0;
mutex_lock(&data->watchdog_lock);
if (!data->client) {
ret = -ENODEV;
goto leave;
}
w83793_write_value(data->client, W83793_REG_WDT_TIMEOUT,
data->watchdog_timeout);
leave:
mutex_unlock(&data->watchdog_lock);
return ret;
}
static int watchdog_enable(struct w83793_data *data)
{
int ret = 0;
mutex_lock(&data->watchdog_lock);
if (!data->client) {
ret = -ENODEV;
goto leave;
}
w83793_write_value(data->client, W83793_REG_WDT_TIMEOUT,
data->watchdog_timeout);
w83793_write_value(data->client, W83793_REG_WDT_LOCK, 0x55);
leave:
mutex_unlock(&data->watchdog_lock);
return ret;
}
static int watchdog_disable(struct w83793_data *data)
{
int ret = 0;
mutex_lock(&data->watchdog_lock);
if (!data->client) {
ret = -ENODEV;
goto leave;
}
w83793_write_value(data->client, W83793_REG_WDT_LOCK, 0xAA);
leave:
mutex_unlock(&data->watchdog_lock);
return ret;
}
static int watchdog_open(struct inode *inode, struct file *filp)
{
struct w83793_data *pos, *data = NULL;
int watchdog_is_open;
if (!mutex_trylock(&watchdog_data_mutex))
return -ERESTARTSYS;
list_for_each_entry(pos, &watchdog_data_list, list) {
if (pos->watchdog_miscdev.minor == iminor(inode)) {
data = pos;
break;
}
}
watchdog_is_open = test_and_set_bit(0, &data->watchdog_is_open);
if (!watchdog_is_open)
kref_get(&data->kref);
mutex_unlock(&watchdog_data_mutex);
if (watchdog_is_open)
return -EBUSY;
watchdog_enable(data);
filp->private_data = data;
return nonseekable_open(inode, filp);
}
static int watchdog_close(struct inode *inode, struct file *filp)
{
struct w83793_data *data = filp->private_data;
if (data->watchdog_expect_close) {
watchdog_disable(data);
data->watchdog_expect_close = 0;
} else {
watchdog_trigger(data);
dev_crit(&data->client->dev,
"unexpected close, not stopping watchdog!\n");
}
clear_bit(0, &data->watchdog_is_open);
mutex_lock(&watchdog_data_mutex);
kref_put(&data->kref, w83793_release_resources);
mutex_unlock(&watchdog_data_mutex);
return 0;
}
static ssize_t watchdog_write(struct file *filp, const char __user *buf,
size_t count, loff_t *offset)
{
ssize_t ret;
struct w83793_data *data = filp->private_data;
if (count) {
if (!nowayout) {
size_t i;
data->watchdog_expect_close = 0;
for (i = 0; i != count; i++) {
char c;
if (get_user(c, buf + i))
return -EFAULT;
if (c == 'V')
data->watchdog_expect_close = 1;
}
}
ret = watchdog_trigger(data);
if (ret < 0)
return ret;
}
return count;
}
static long watchdog_ioctl(struct file *filp, unsigned int cmd,
unsigned long arg)
{
struct watchdog_info ident = {
.options = WDIOF_KEEPALIVEPING |
WDIOF_SETTIMEOUT |
WDIOF_CARDRESET,
.identity = "w83793 watchdog"
};
int val, ret = 0;
struct w83793_data *data = filp->private_data;
switch (cmd) {
case WDIOC_GETSUPPORT:
if (!nowayout)
ident.options |= WDIOF_MAGICCLOSE;
if (copy_to_user((void __user *)arg, &ident, sizeof(ident)))
ret = -EFAULT;
break;
case WDIOC_GETSTATUS:
val = data->watchdog_caused_reboot ? WDIOF_CARDRESET : 0;
ret = put_user(val, (int __user *)arg);
break;
case WDIOC_GETBOOTSTATUS:
ret = put_user(0, (int __user *)arg);
break;
case WDIOC_KEEPALIVE:
ret = watchdog_trigger(data);
break;
case WDIOC_GETTIMEOUT:
val = watchdog_get_timeout(data);
ret = put_user(val, (int __user *)arg);
break;
case WDIOC_SETTIMEOUT:
if (get_user(val, (int __user *)arg)) {
ret = -EFAULT;
break;
}
ret = watchdog_set_timeout(data, val);
if (ret > 0)
ret = put_user(ret, (int __user *)arg);
break;
case WDIOC_SETOPTIONS:
if (get_user(val, (int __user *)arg)) {
ret = -EFAULT;
break;
}
if (val & WDIOS_DISABLECARD)
ret = watchdog_disable(data);
else if (val & WDIOS_ENABLECARD)
ret = watchdog_enable(data);
else
ret = -EINVAL;
break;
default:
ret = -ENOTTY;
}
return ret;
}
static int watchdog_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
struct w83793_data *data = NULL;
if (code == SYS_DOWN || code == SYS_HALT) {
mutex_lock(&watchdog_data_mutex);
list_for_each_entry(data, &watchdog_data_list, list) {
if (data->watchdog_miscdev.minor)
watchdog_disable(data);
}
mutex_unlock(&watchdog_data_mutex);
}
return NOTIFY_DONE;
}
static int w83793_remove(struct i2c_client *client)
{
struct w83793_data *data = i2c_get_clientdata(client);
struct device *dev = &client->dev;
int i, tmp;
if (data->watchdog_miscdev.minor) {
misc_deregister(&data->watchdog_miscdev);
if (data->watchdog_is_open) {
dev_warn(&client->dev,
"i2c client detached with watchdog open! "
"Stopping watchdog.\n");
watchdog_disable(data);
}
mutex_lock(&watchdog_data_mutex);
list_del(&data->list);
mutex_unlock(&watchdog_data_mutex);
mutex_lock(&data->watchdog_lock);
data->client = NULL;
mutex_unlock(&data->watchdog_lock);
}
tmp = w83793_read_value(client, W83793_REG_CONFIG);
w83793_write_value(client, W83793_REG_CONFIG, tmp & ~0x04);
unregister_reboot_notifier(&watchdog_notifier);
hwmon_device_unregister(data->hwmon_dev);
for (i = 0; i < ARRAY_SIZE(w83793_sensor_attr_2); i++)
device_remove_file(dev,
&w83793_sensor_attr_2[i].dev_attr);
for (i = 0; i < ARRAY_SIZE(sda_single_files); i++)
device_remove_file(dev, &sda_single_files[i].dev_attr);
for (i = 0; i < ARRAY_SIZE(w83793_vid); i++)
device_remove_file(dev, &w83793_vid[i].dev_attr);
device_remove_file(dev, &dev_attr_vrm);
for (i = 0; i < ARRAY_SIZE(w83793_left_fan); i++)
device_remove_file(dev, &w83793_left_fan[i].dev_attr);
for (i = 0; i < ARRAY_SIZE(w83793_left_pwm); i++)
device_remove_file(dev, &w83793_left_pwm[i].dev_attr);
for (i = 0; i < ARRAY_SIZE(w83793_temp); i++)
device_remove_file(dev, &w83793_temp[i].dev_attr);
if (data->lm75[0] != NULL)
i2c_unregister_device(data->lm75[0]);
if (data->lm75[1] != NULL)
i2c_unregister_device(data->lm75[1]);
mutex_lock(&watchdog_data_mutex);
kref_put(&data->kref, w83793_release_resources);
mutex_unlock(&watchdog_data_mutex);
return 0;
}
static int
w83793_detect_subclients(struct i2c_client *client)
{
int i, id, err;
int address = client->addr;
u8 tmp;
struct i2c_adapter *adapter = client->adapter;
struct w83793_data *data = i2c_get_clientdata(client);
id = i2c_adapter_id(adapter);
if (force_subclients[0] == id && force_subclients[1] == address) {
for (i = 2; i <= 3; i++) {
if (force_subclients[i] < 0x48
|| force_subclients[i] > 0x4f) {
dev_err(&client->dev,
"invalid subclient "
"address %d; must be 0x48-0x4f\n",
force_subclients[i]);
err = -EINVAL;
goto ERROR_SC_0;
}
}
w83793_write_value(client, W83793_REG_I2C_SUBADDR,
(force_subclients[2] & 0x07) |
((force_subclients[3] & 0x07) << 4));
}
tmp = w83793_read_value(client, W83793_REG_I2C_SUBADDR);
if (!(tmp & 0x08))
data->lm75[0] = i2c_new_dummy(adapter, 0x48 + (tmp & 0x7));
if (!(tmp & 0x80)) {
if ((data->lm75[0] != NULL)
&& ((tmp & 0x7) == ((tmp >> 4) & 0x7))) {
dev_err(&client->dev,
"duplicate addresses 0x%x, "
"use force_subclients\n", data->lm75[0]->addr);
err = -ENODEV;
goto ERROR_SC_1;
}
data->lm75[1] = i2c_new_dummy(adapter,
0x48 + ((tmp >> 4) & 0x7));
}
return 0;
ERROR_SC_1:
if (data->lm75[0] != NULL)
i2c_unregister_device(data->lm75[0]);
ERROR_SC_0:
return err;
}
static int w83793_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
u8 tmp, bank, chip_id;
struct i2c_adapter *adapter = client->adapter;
unsigned short address = client->addr;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
bank = i2c_smbus_read_byte_data(client, W83793_REG_BANKSEL);
tmp = bank & 0x80 ? 0x5c : 0xa3;
if (tmp != i2c_smbus_read_byte_data(client, W83793_REG_VENDORID)) {
pr_debug("w83793: Detection failed at check vendor id\n");
return -ENODEV;
}
if ((bank & 0x07) == 0
&& i2c_smbus_read_byte_data(client, W83793_REG_I2C_ADDR) !=
(address << 1)) {
pr_debug("w83793: Detection failed at check i2c addr\n");
return -ENODEV;
}
chip_id = i2c_smbus_read_byte_data(client, W83793_REG_CHIPID);
if (chip_id != 0x7b)
return -ENODEV;
strlcpy(info->type, "w83793", I2C_NAME_SIZE);
return 0;
}
static int w83793_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
const int watchdog_minors[] = { WATCHDOG_MINOR, 212, 213, 214, 215 };
struct w83793_data *data;
int i, tmp, val, err;
int files_fan = ARRAY_SIZE(w83793_left_fan) / 7;
int files_pwm = ARRAY_SIZE(w83793_left_pwm) / 5;
int files_temp = ARRAY_SIZE(w83793_temp) / 6;
data = kzalloc(sizeof(struct w83793_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(client, data);
data->bank = i2c_smbus_read_byte_data(client, W83793_REG_BANKSEL);
mutex_init(&data->update_lock);
mutex_init(&data->watchdog_lock);
INIT_LIST_HEAD(&data->list);
kref_init(&data->kref);
data->client = client;
err = w83793_detect_subclients(client);
if (err)
goto free_mem;
w83793_init_client(client);
data->has_fan = 0x1f;
data->has_pwm = 0x07;
tmp = w83793_read_value(client, W83793_REG_MFC);
val = w83793_read_value(client, W83793_REG_FANIN_CTRL);
if (tmp & 0x80) {
data->has_vid |= 0x2;
} else {
data->has_pwm |= 0x18;
if (val & 0x01) {
data->has_fan |= 0x20;
data->has_pwm |= 0x20;
}
if (val & 0x02) {
data->has_fan |= 0x40;
data->has_pwm |= 0x40;
}
if (!(tmp & 0x40) && (val & 0x04)) {
data->has_fan |= 0x80;
data->has_pwm |= 0x80;
}
}
if (!(tmp & 0x29))
data->has_vid |= 0x1;
if (0x08 == (tmp & 0x0c)) {
if (val & 0x08)
data->has_fan |= 0x100;
if (val & 0x10)
data->has_fan |= 0x200;
}
if (0x20 == (tmp & 0x30)) {
if (val & 0x20)
data->has_fan |= 0x400;
if (val & 0x40)
data->has_fan |= 0x800;
}
if ((tmp & 0x01) && (val & 0x04)) {
data->has_fan |= 0x80;
data->has_pwm |= 0x80;
}
tmp = w83793_read_value(client, W83793_REG_FANIN_SEL);
if ((tmp & 0x01) && (val & 0x08)) {
data->has_fan |= 0x100;
}
if ((tmp & 0x02) && (val & 0x10)) {
data->has_fan |= 0x200;
}
if ((tmp & 0x04) && (val & 0x20)) {
data->has_fan |= 0x400;
}
if ((tmp & 0x08) && (val & 0x40)) {
data->has_fan |= 0x800;
}
tmp = w83793_read_value(client, W83793_REG_TEMP_MODE[0]);
if (tmp & 0x01)
data->has_temp |= 0x01;
if (tmp & 0x04)
data->has_temp |= 0x02;
if (tmp & 0x10)
data->has_temp |= 0x04;
if (tmp & 0x40)
data->has_temp |= 0x08;
tmp = w83793_read_value(client, W83793_REG_TEMP_MODE[1]);
if (tmp & 0x01)
data->has_temp |= 0x10;
if (tmp & 0x02)
data->has_temp |= 0x20;
for (i = 0; i < ARRAY_SIZE(w83793_sensor_attr_2); i++) {
err = device_create_file(dev,
&w83793_sensor_attr_2[i].dev_attr);
if (err)
goto exit_remove;
}
for (i = 0; i < ARRAY_SIZE(w83793_vid); i++) {
if (!(data->has_vid & (1 << i)))
continue;
err = device_create_file(dev, &w83793_vid[i].dev_attr);
if (err)
goto exit_remove;
}
if (data->has_vid) {
data->vrm = vid_which_vrm();
err = device_create_file(dev, &dev_attr_vrm);
if (err)
goto exit_remove;
}
for (i = 0; i < ARRAY_SIZE(sda_single_files); i++) {
err = device_create_file(dev, &sda_single_files[i].dev_attr);
if (err)
goto exit_remove;
}
for (i = 0; i < 6; i++) {
int j;
if (!(data->has_temp & (1 << i)))
continue;
for (j = 0; j < files_temp; j++) {
err = device_create_file(dev,
&w83793_temp[(i) * files_temp
+ j].dev_attr);
if (err)
goto exit_remove;
}
}
for (i = 5; i < 12; i++) {
int j;
if (!(data->has_fan & (1 << i)))
continue;
for (j = 0; j < files_fan; j++) {
err = device_create_file(dev,
&w83793_left_fan[(i - 5) * files_fan
+ j].dev_attr);
if (err)
goto exit_remove;
}
}
for (i = 3; i < 8; i++) {
int j;
if (!(data->has_pwm & (1 << i)))
continue;
for (j = 0; j < files_pwm; j++) {
err = device_create_file(dev,
&w83793_left_pwm[(i - 3) * files_pwm
+ j].dev_attr);
if (err)
goto exit_remove;
}
}
data->hwmon_dev = hwmon_device_register(dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
err = register_reboot_notifier(&watchdog_notifier);
if (err != 0) {
dev_err(&client->dev,
"cannot register reboot notifier (err=%d)\n", err);
goto exit_devunreg;
}
tmp = w83793_read_value(client, W83793_REG_CONFIG);
w83793_write_value(client, W83793_REG_CONFIG, tmp | 0x04);
data->watchdog_timeout = timeout;
data->watchdog_caused_reboot =
w83793_read_value(data->client, W83793_REG_WDT_STATUS) & 0x01;
watchdog_disable(data);
mutex_lock(&watchdog_data_mutex);
for (i = 0; i < ARRAY_SIZE(watchdog_minors); i++) {
snprintf(data->watchdog_name, sizeof(data->watchdog_name),
"watchdog%c", (i == 0) ? '\0' : ('0' + i));
data->watchdog_miscdev.name = data->watchdog_name;
data->watchdog_miscdev.fops = &watchdog_fops;
data->watchdog_miscdev.minor = watchdog_minors[i];
err = misc_register(&data->watchdog_miscdev);
if (err == -EBUSY)
continue;
if (err) {
data->watchdog_miscdev.minor = 0;
dev_err(&client->dev,
"Registering watchdog chardev: %d\n", err);
break;
}
list_add(&data->list, &watchdog_data_list);
dev_info(&client->dev,
"Registered watchdog chardev major 10, minor: %d\n",
watchdog_minors[i]);
break;
}
if (i == ARRAY_SIZE(watchdog_minors)) {
data->watchdog_miscdev.minor = 0;
dev_warn(&client->dev,
"Couldn't register watchdog chardev (due to no free minor)\n");
}
mutex_unlock(&watchdog_data_mutex);
return 0;
exit_devunreg:
hwmon_device_unregister(data->hwmon_dev);
exit_remove:
for (i = 0; i < ARRAY_SIZE(w83793_sensor_attr_2); i++)
device_remove_file(dev, &w83793_sensor_attr_2[i].dev_attr);
for (i = 0; i < ARRAY_SIZE(sda_single_files); i++)
device_remove_file(dev, &sda_single_files[i].dev_attr);
for (i = 0; i < ARRAY_SIZE(w83793_vid); i++)
device_remove_file(dev, &w83793_vid[i].dev_attr);
for (i = 0; i < ARRAY_SIZE(w83793_left_fan); i++)
device_remove_file(dev, &w83793_left_fan[i].dev_attr);
for (i = 0; i < ARRAY_SIZE(w83793_left_pwm); i++)
device_remove_file(dev, &w83793_left_pwm[i].dev_attr);
for (i = 0; i < ARRAY_SIZE(w83793_temp); i++)
device_remove_file(dev, &w83793_temp[i].dev_attr);
if (data->lm75[0] != NULL)
i2c_unregister_device(data->lm75[0]);
if (data->lm75[1] != NULL)
i2c_unregister_device(data->lm75[1]);
free_mem:
kfree(data);
exit:
return err;
}
static void w83793_update_nonvolatile(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct w83793_data *data = i2c_get_clientdata(client);
int i, j;
if (!(time_after(jiffies, data->last_nonvolatile + HZ * 300)
|| !data->valid))
return;
for (i = 1; i < 3; i++) {
for (j = 0; j < ARRAY_SIZE(data->in); j++) {
data->in[j][i] =
w83793_read_value(client, W83793_REG_IN[j][i]);
}
data->in_low_bits[i] =
w83793_read_value(client, W83793_REG_IN_LOW_BITS[i]);
}
for (i = 0; i < ARRAY_SIZE(data->fan_min); i++) {
if (!(data->has_fan & (1 << i)))
continue;
data->fan_min[i] =
w83793_read_value(client, W83793_REG_FAN_MIN(i)) << 8;
data->fan_min[i] |=
w83793_read_value(client, W83793_REG_FAN_MIN(i) + 1);
}
for (i = 0; i < ARRAY_SIZE(data->temp_fan_map); i++) {
if (!(data->has_temp & (1 << i)))
continue;
data->temp_fan_map[i] =
w83793_read_value(client, W83793_REG_TEMP_FAN_MAP(i));
for (j = 1; j < 5; j++) {
data->temp[i][j] =
w83793_read_value(client, W83793_REG_TEMP[i][j]);
}
data->temp_cruise[i] =
w83793_read_value(client, W83793_REG_TEMP_CRUISE(i));
for (j = 0; j < 7; j++) {
data->sf2_pwm[i][j] =
w83793_read_value(client, W83793_REG_SF2_PWM(i, j));
data->sf2_temp[i][j] =
w83793_read_value(client,
W83793_REG_SF2_TEMP(i, j));
}
}
for (i = 0; i < ARRAY_SIZE(data->temp_mode); i++)
data->temp_mode[i] =
w83793_read_value(client, W83793_REG_TEMP_MODE[i]);
for (i = 0; i < ARRAY_SIZE(data->tolerance); i++) {
data->tolerance[i] =
w83793_read_value(client, W83793_REG_TEMP_TOL(i));
}
for (i = 0; i < ARRAY_SIZE(data->pwm); i++) {
if (!(data->has_pwm & (1 << i)))
continue;
data->pwm[i][PWM_NONSTOP] =
w83793_read_value(client, W83793_REG_PWM(i, PWM_NONSTOP));
data->pwm[i][PWM_START] =
w83793_read_value(client, W83793_REG_PWM(i, PWM_START));
data->pwm_stop_time[i] =
w83793_read_value(client, W83793_REG_PWM_STOP_TIME(i));
}
data->pwm_default = w83793_read_value(client, W83793_REG_PWM_DEFAULT);
data->pwm_enable = w83793_read_value(client, W83793_REG_PWM_ENABLE);
data->pwm_uptime = w83793_read_value(client, W83793_REG_PWM_UPTIME);
data->pwm_downtime = w83793_read_value(client, W83793_REG_PWM_DOWNTIME);
data->temp_critical =
w83793_read_value(client, W83793_REG_TEMP_CRITICAL);
data->beep_enable = w83793_read_value(client, W83793_REG_OVT_BEEP);
for (i = 0; i < ARRAY_SIZE(data->beeps); i++)
data->beeps[i] = w83793_read_value(client, W83793_REG_BEEP(i));
data->last_nonvolatile = jiffies;
}
static struct w83793_data *w83793_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct w83793_data *data = i2c_get_clientdata(client);
int i;
mutex_lock(&data->update_lock);
if (!(time_after(jiffies, data->last_updated + HZ * 2)
|| !data->valid))
goto END;
for (i = 0; i < ARRAY_SIZE(data->in); i++)
data->in[i][IN_READ] =
w83793_read_value(client, W83793_REG_IN[i][IN_READ]);
data->in_low_bits[IN_READ] =
w83793_read_value(client, W83793_REG_IN_LOW_BITS[IN_READ]);
for (i = 0; i < ARRAY_SIZE(data->fan); i++) {
if (!(data->has_fan & (1 << i)))
continue;
data->fan[i] =
w83793_read_value(client, W83793_REG_FAN(i)) << 8;
data->fan[i] |=
w83793_read_value(client, W83793_REG_FAN(i) + 1);
}
for (i = 0; i < ARRAY_SIZE(data->temp); i++) {
if (!(data->has_temp & (1 << i)))
continue;
data->temp[i][TEMP_READ] =
w83793_read_value(client, W83793_REG_TEMP[i][TEMP_READ]);
}
data->temp_low_bits =
w83793_read_value(client, W83793_REG_TEMP_LOW_BITS);
for (i = 0; i < ARRAY_SIZE(data->pwm); i++) {
if (data->has_pwm & (1 << i))
data->pwm[i][PWM_DUTY] =
w83793_read_value(client,
W83793_REG_PWM(i, PWM_DUTY));
}
for (i = 0; i < ARRAY_SIZE(data->alarms); i++)
data->alarms[i] =
w83793_read_value(client, W83793_REG_ALARM(i));
if (data->has_vid & 0x01)
data->vid[0] = w83793_read_value(client, W83793_REG_VID_INA);
if (data->has_vid & 0x02)
data->vid[1] = w83793_read_value(client, W83793_REG_VID_INB);
w83793_update_nonvolatile(dev);
data->last_updated = jiffies;
data->valid = 1;
END:
mutex_unlock(&data->update_lock);
return data;
}
static u8 w83793_read_value(struct i2c_client *client, u16 reg)
{
struct w83793_data *data = i2c_get_clientdata(client);
u8 res = 0xff;
u8 new_bank = reg >> 8;
new_bank |= data->bank & 0xfc;
if (data->bank != new_bank) {
if (i2c_smbus_write_byte_data
(client, W83793_REG_BANKSEL, new_bank) >= 0)
data->bank = new_bank;
else {
dev_err(&client->dev,
"set bank to %d failed, fall back "
"to bank %d, read reg 0x%x error\n",
new_bank, data->bank, reg);
res = 0x0;
goto END;
}
}
res = i2c_smbus_read_byte_data(client, reg & 0xff);
END:
return res;
}
static int w83793_write_value(struct i2c_client *client, u16 reg, u8 value)
{
struct w83793_data *data = i2c_get_clientdata(client);
int res;
u8 new_bank = reg >> 8;
new_bank |= data->bank & 0xfc;
if (data->bank != new_bank) {
res = i2c_smbus_write_byte_data(client, W83793_REG_BANKSEL,
new_bank);
if (res < 0) {
dev_err(&client->dev,
"set bank to %d failed, fall back "
"to bank %d, write reg 0x%x error\n",
new_bank, data->bank, reg);
goto END;
}
data->bank = new_bank;
}
res = i2c_smbus_write_byte_data(client, reg & 0xff, value);
END:
return res;
}
