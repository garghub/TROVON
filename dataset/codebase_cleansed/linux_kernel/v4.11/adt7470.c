static inline int adt7470_read_word_data(struct i2c_client *client, u8 reg)
{
u16 foo;
foo = i2c_smbus_read_byte_data(client, reg);
foo |= ((u16)i2c_smbus_read_byte_data(client, reg + 1) << 8);
return foo;
}
static inline int adt7470_write_word_data(struct i2c_client *client, u8 reg,
u16 value)
{
return i2c_smbus_write_byte_data(client, reg, value & 0xFF)
|| i2c_smbus_write_byte_data(client, reg + 1, value >> 8);
}
static int adt7470_read_temperatures(struct i2c_client *client,
struct adt7470_data *data)
{
unsigned long res;
int i;
u8 cfg, pwm[4], pwm_cfg[2];
pwm_cfg[0] = i2c_smbus_read_byte_data(client, ADT7470_REG_PWM_CFG(0));
pwm_cfg[1] = i2c_smbus_read_byte_data(client, ADT7470_REG_PWM_CFG(2));
for (i = 0; i < ADT7470_FAN_COUNT; i++)
pwm[i] = i2c_smbus_read_byte_data(client, ADT7470_REG_PWM(i));
i2c_smbus_write_byte_data(client, ADT7470_REG_PWM_CFG(0),
pwm_cfg[0] & ~(ADT7470_PWM_AUTO_MASK));
i2c_smbus_write_byte_data(client, ADT7470_REG_PWM_CFG(2),
pwm_cfg[1] & ~(ADT7470_PWM_AUTO_MASK));
for (i = 0; i < ADT7470_FAN_COUNT; i++)
i2c_smbus_write_byte_data(client, ADT7470_REG_PWM(i), pwm[i]);
cfg = i2c_smbus_read_byte_data(client, ADT7470_REG_CFG);
cfg |= 0x80;
i2c_smbus_write_byte_data(client, ADT7470_REG_CFG, cfg);
res = msleep_interruptible((data->num_temp_sensors >= 0 ?
data->num_temp_sensors * 200 :
TEMP_COLLECTION_TIME));
cfg = i2c_smbus_read_byte_data(client, ADT7470_REG_CFG);
cfg &= ~0x80;
i2c_smbus_write_byte_data(client, ADT7470_REG_CFG, cfg);
i2c_smbus_write_byte_data(client, ADT7470_REG_PWM_CFG(0), pwm_cfg[0]);
i2c_smbus_write_byte_data(client, ADT7470_REG_PWM_CFG(2), pwm_cfg[1]);
if (res) {
pr_err("ha ha, interrupted\n");
return -EAGAIN;
}
if (data->num_temp_sensors >= 0)
return 0;
for (i = 0; i < ADT7470_TEMP_COUNT; i++) {
data->temp[i] = i2c_smbus_read_byte_data(client,
ADT7470_TEMP_REG(i));
if (data->temp[i])
data->num_temp_sensors = i + 1;
}
data->temperatures_probed = 1;
return 0;
}
static int adt7470_update_thread(void *p)
{
struct i2c_client *client = p;
struct adt7470_data *data = i2c_get_clientdata(client);
while (!kthread_should_stop()) {
mutex_lock(&data->lock);
adt7470_read_temperatures(client, data);
mutex_unlock(&data->lock);
set_current_state(TASK_INTERRUPTIBLE);
if (kthread_should_stop())
break;
schedule_timeout(msecs_to_jiffies(data->auto_update_interval));
}
return 0;
}
static struct adt7470_data *adt7470_update_device(struct device *dev)
{
struct adt7470_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
unsigned long local_jiffies = jiffies;
u8 cfg;
int i;
int need_sensors = 1;
int need_limits = 1;
if (time_before(local_jiffies, data->sensors_last_updated +
SENSOR_REFRESH_INTERVAL) &&
data->sensors_valid)
need_sensors = 0;
if (time_before(local_jiffies, data->limits_last_updated +
LIMIT_REFRESH_INTERVAL) &&
data->limits_valid)
need_limits = 0;
if (!need_sensors && !need_limits)
return data;
mutex_lock(&data->lock);
if (!need_sensors)
goto no_sensor_update;
if (!data->temperatures_probed)
adt7470_read_temperatures(client, data);
else
for (i = 0; i < ADT7470_TEMP_COUNT; i++)
data->temp[i] = i2c_smbus_read_byte_data(client,
ADT7470_TEMP_REG(i));
for (i = 0; i < ADT7470_FAN_COUNT; i++)
data->fan[i] = adt7470_read_word_data(client,
ADT7470_REG_FAN(i));
for (i = 0; i < ADT7470_PWM_COUNT; i++) {
int reg;
int reg_mask;
data->pwm[i] = i2c_smbus_read_byte_data(client,
ADT7470_REG_PWM(i));
if (i % 2)
reg_mask = ADT7470_PWM2_AUTO_MASK;
else
reg_mask = ADT7470_PWM1_AUTO_MASK;
reg = ADT7470_REG_PWM_CFG(i);
if (i2c_smbus_read_byte_data(client, reg) & reg_mask)
data->pwm_automatic[i] = 1;
else
data->pwm_automatic[i] = 0;
reg = ADT7470_REG_PWM_AUTO_TEMP(i);
cfg = i2c_smbus_read_byte_data(client, reg);
if (!(i % 2))
data->pwm_auto_temp[i] = cfg >> 4;
else
data->pwm_auto_temp[i] = cfg & 0xF;
}
if (i2c_smbus_read_byte_data(client, ADT7470_REG_CFG) &
ADT7470_FSPD_MASK)
data->force_pwm_max = 1;
else
data->force_pwm_max = 0;
data->alarm = i2c_smbus_read_byte_data(client, ADT7470_REG_ALARM1);
if (data->alarm & ADT7470_OOL_ALARM)
data->alarm |= ALARM2(i2c_smbus_read_byte_data(client,
ADT7470_REG_ALARM2));
data->alarms_mask = adt7470_read_word_data(client,
ADT7470_REG_ALARM1_MASK);
data->sensors_last_updated = local_jiffies;
data->sensors_valid = 1;
no_sensor_update:
if (!need_limits)
goto out;
for (i = 0; i < ADT7470_TEMP_COUNT; i++) {
data->temp_min[i] = i2c_smbus_read_byte_data(client,
ADT7470_TEMP_MIN_REG(i));
data->temp_max[i] = i2c_smbus_read_byte_data(client,
ADT7470_TEMP_MAX_REG(i));
}
for (i = 0; i < ADT7470_FAN_COUNT; i++) {
data->fan_min[i] = adt7470_read_word_data(client,
ADT7470_REG_FAN_MIN(i));
data->fan_max[i] = adt7470_read_word_data(client,
ADT7470_REG_FAN_MAX(i));
}
for (i = 0; i < ADT7470_PWM_COUNT; i++) {
data->pwm_max[i] = i2c_smbus_read_byte_data(client,
ADT7470_REG_PWM_MAX(i));
data->pwm_min[i] = i2c_smbus_read_byte_data(client,
ADT7470_REG_PWM_MIN(i));
data->pwm_tmin[i] = i2c_smbus_read_byte_data(client,
ADT7470_REG_PWM_TMIN(i));
}
data->limits_last_updated = local_jiffies;
data->limits_valid = 1;
out:
mutex_unlock(&data->lock);
return data;
}
static ssize_t auto_update_interval_show(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct adt7470_data *data = adt7470_update_device(dev);
return sprintf(buf, "%d\n", data->auto_update_interval);
}
static ssize_t auto_update_interval_store(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct adt7470_data *data = dev_get_drvdata(dev);
long temp;
if (kstrtol(buf, 10, &temp))
return -EINVAL;
temp = clamp_val(temp, 0, 60000);
mutex_lock(&data->lock);
data->auto_update_interval = temp;
mutex_unlock(&data->lock);
return count;
}
static ssize_t num_temp_sensors_show(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct adt7470_data *data = adt7470_update_device(dev);
return sprintf(buf, "%d\n", data->num_temp_sensors);
}
static ssize_t num_temp_sensors_store(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct adt7470_data *data = dev_get_drvdata(dev);
long temp;
if (kstrtol(buf, 10, &temp))
return -EINVAL;
temp = clamp_val(temp, -1, 10);
mutex_lock(&data->lock);
data->num_temp_sensors = temp;
if (temp < 0)
data->temperatures_probed = 0;
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_temp_min(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = adt7470_update_device(dev);
return sprintf(buf, "%d\n", 1000 * data->temp_min[attr->index]);
}
static ssize_t set_temp_min(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
if (kstrtol(buf, 10, &temp))
return -EINVAL;
temp = clamp_val(temp, -128000, 127000);
temp = DIV_ROUND_CLOSEST(temp, 1000);
mutex_lock(&data->lock);
data->temp_min[attr->index] = temp;
i2c_smbus_write_byte_data(client, ADT7470_TEMP_MIN_REG(attr->index),
temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_temp_max(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = adt7470_update_device(dev);
return sprintf(buf, "%d\n", 1000 * data->temp_max[attr->index]);
}
static ssize_t set_temp_max(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
if (kstrtol(buf, 10, &temp))
return -EINVAL;
temp = clamp_val(temp, -128000, 127000);
temp = DIV_ROUND_CLOSEST(temp, 1000);
mutex_lock(&data->lock);
data->temp_max[attr->index] = temp;
i2c_smbus_write_byte_data(client, ADT7470_TEMP_MAX_REG(attr->index),
temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = adt7470_update_device(dev);
return sprintf(buf, "%d\n", 1000 * data->temp[attr->index]);
}
static ssize_t alarm_mask_show(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct adt7470_data *data = adt7470_update_device(dev);
return sprintf(buf, "%x\n", data->alarms_mask);
}
static ssize_t alarm_mask_store(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct adt7470_data *data = dev_get_drvdata(dev);
long mask;
if (kstrtoul(buf, 0, &mask))
return -EINVAL;
if (mask & ~0xffff)
return -EINVAL;
mutex_lock(&data->lock);
data->alarms_mask = mask;
adt7470_write_word_data(data->client, ADT7470_REG_ALARM1_MASK, mask);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_fan_max(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = adt7470_update_device(dev);
if (FAN_DATA_VALID(data->fan_max[attr->index]))
return sprintf(buf, "%d\n",
FAN_PERIOD_TO_RPM(data->fan_max[attr->index]));
else
return sprintf(buf, "0\n");
}
static ssize_t set_fan_max(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
if (kstrtol(buf, 10, &temp) || !temp)
return -EINVAL;
temp = FAN_RPM_TO_PERIOD(temp);
temp = clamp_val(temp, 1, 65534);
mutex_lock(&data->lock);
data->fan_max[attr->index] = temp;
adt7470_write_word_data(client, ADT7470_REG_FAN_MAX(attr->index), temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_fan_min(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = adt7470_update_device(dev);
if (FAN_DATA_VALID(data->fan_min[attr->index]))
return sprintf(buf, "%d\n",
FAN_PERIOD_TO_RPM(data->fan_min[attr->index]));
else
return sprintf(buf, "0\n");
}
static ssize_t set_fan_min(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
if (kstrtol(buf, 10, &temp) || !temp)
return -EINVAL;
temp = FAN_RPM_TO_PERIOD(temp);
temp = clamp_val(temp, 1, 65534);
mutex_lock(&data->lock);
data->fan_min[attr->index] = temp;
adt7470_write_word_data(client, ADT7470_REG_FAN_MIN(attr->index), temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_fan(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = adt7470_update_device(dev);
if (FAN_DATA_VALID(data->fan[attr->index]))
return sprintf(buf, "%d\n",
FAN_PERIOD_TO_RPM(data->fan[attr->index]));
else
return sprintf(buf, "0\n");
}
static ssize_t show_force_pwm_max(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct adt7470_data *data = adt7470_update_device(dev);
return sprintf(buf, "%d\n", data->force_pwm_max);
}
static ssize_t set_force_pwm_max(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct adt7470_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
u8 reg;
if (kstrtol(buf, 10, &temp))
return -EINVAL;
mutex_lock(&data->lock);
data->force_pwm_max = temp;
reg = i2c_smbus_read_byte_data(client, ADT7470_REG_CFG);
if (temp)
reg |= ADT7470_FSPD_MASK;
else
reg &= ~ADT7470_FSPD_MASK;
i2c_smbus_write_byte_data(client, ADT7470_REG_CFG, reg);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_pwm(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = adt7470_update_device(dev);
return sprintf(buf, "%d\n", data->pwm[attr->index]);
}
static ssize_t set_pwm(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
if (kstrtol(buf, 10, &temp))
return -EINVAL;
temp = clamp_val(temp, 0, 255);
mutex_lock(&data->lock);
data->pwm[attr->index] = temp;
i2c_smbus_write_byte_data(client, ADT7470_REG_PWM(attr->index), temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t pwm1_freq_show(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct adt7470_data *data = adt7470_update_device(dev);
unsigned char cfg_reg_1;
unsigned char cfg_reg_2;
int index;
mutex_lock(&data->lock);
cfg_reg_1 = i2c_smbus_read_byte_data(data->client, ADT7470_REG_CFG);
cfg_reg_2 = i2c_smbus_read_byte_data(data->client, ADT7470_REG_CFG_2);
mutex_unlock(&data->lock);
index = (cfg_reg_2 & ADT7470_FREQ_MASK) >> ADT7470_FREQ_SHIFT;
if (!(cfg_reg_1 & ADT7470_CFG_LF))
index += 8;
if (index >= ARRAY_SIZE(adt7470_freq_map))
index = ARRAY_SIZE(adt7470_freq_map) - 1;
return scnprintf(buf, PAGE_SIZE, "%d\n", adt7470_freq_map[index]);
}
static ssize_t pwm1_freq_store(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct adt7470_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long freq;
int index;
int low_freq = ADT7470_CFG_LF;
unsigned char val;
if (kstrtol(buf, 10, &freq))
return -EINVAL;
index = find_closest(freq, adt7470_freq_map,
ARRAY_SIZE(adt7470_freq_map));
if (index >= 8) {
index -= 8;
low_freq = 0;
}
mutex_lock(&data->lock);
val = i2c_smbus_read_byte_data(client, ADT7470_REG_CFG);
i2c_smbus_write_byte_data(client, ADT7470_REG_CFG,
(val & ~ADT7470_CFG_LF) | low_freq);
val = i2c_smbus_read_byte_data(client, ADT7470_REG_CFG_2);
i2c_smbus_write_byte_data(client, ADT7470_REG_CFG_2,
(val & ~ADT7470_FREQ_MASK) | (index << ADT7470_FREQ_SHIFT));
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_pwm_max(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = adt7470_update_device(dev);
return sprintf(buf, "%d\n", data->pwm_max[attr->index]);
}
static ssize_t set_pwm_max(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
if (kstrtol(buf, 10, &temp))
return -EINVAL;
temp = clamp_val(temp, 0, 255);
mutex_lock(&data->lock);
data->pwm_max[attr->index] = temp;
i2c_smbus_write_byte_data(client, ADT7470_REG_PWM_MAX(attr->index),
temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_pwm_min(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = adt7470_update_device(dev);
return sprintf(buf, "%d\n", data->pwm_min[attr->index]);
}
static ssize_t set_pwm_min(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
if (kstrtol(buf, 10, &temp))
return -EINVAL;
temp = clamp_val(temp, 0, 255);
mutex_lock(&data->lock);
data->pwm_min[attr->index] = temp;
i2c_smbus_write_byte_data(client, ADT7470_REG_PWM_MIN(attr->index),
temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_pwm_tmax(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = adt7470_update_device(dev);
return sprintf(buf, "%d\n", 1000 * (20 + data->pwm_tmin[attr->index]));
}
static ssize_t show_pwm_tmin(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = adt7470_update_device(dev);
return sprintf(buf, "%d\n", 1000 * data->pwm_tmin[attr->index]);
}
static ssize_t set_pwm_tmin(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
if (kstrtol(buf, 10, &temp))
return -EINVAL;
temp = clamp_val(temp, -128000, 127000);
temp = DIV_ROUND_CLOSEST(temp, 1000);
mutex_lock(&data->lock);
data->pwm_tmin[attr->index] = temp;
i2c_smbus_write_byte_data(client, ADT7470_REG_PWM_TMIN(attr->index),
temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_pwm_auto(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = adt7470_update_device(dev);
return sprintf(buf, "%d\n", 1 + data->pwm_automatic[attr->index]);
}
static ssize_t set_pwm_auto(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int pwm_auto_reg = ADT7470_REG_PWM_CFG(attr->index);
int pwm_auto_reg_mask;
long temp;
u8 reg;
if (kstrtol(buf, 10, &temp))
return -EINVAL;
if (attr->index % 2)
pwm_auto_reg_mask = ADT7470_PWM2_AUTO_MASK;
else
pwm_auto_reg_mask = ADT7470_PWM1_AUTO_MASK;
if (temp != 2 && temp != 1)
return -EINVAL;
temp--;
mutex_lock(&data->lock);
data->pwm_automatic[attr->index] = temp;
reg = i2c_smbus_read_byte_data(client, pwm_auto_reg);
if (temp)
reg |= pwm_auto_reg_mask;
else
reg &= ~pwm_auto_reg_mask;
i2c_smbus_write_byte_data(client, pwm_auto_reg, reg);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_pwm_auto_temp(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = adt7470_update_device(dev);
u8 ctrl = data->pwm_auto_temp[attr->index];
if (ctrl)
return sprintf(buf, "%d\n", 1 << (ctrl - 1));
else
return sprintf(buf, "%d\n", ADT7470_PWM_ALL_TEMPS);
}
static int cvt_auto_temp(int input)
{
if (input == ADT7470_PWM_ALL_TEMPS)
return 0;
if (input < 1 || !is_power_of_2(input))
return -EINVAL;
return ilog2(input) + 1;
}
static ssize_t set_pwm_auto_temp(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int pwm_auto_reg = ADT7470_REG_PWM_AUTO_TEMP(attr->index);
long temp;
u8 reg;
if (kstrtol(buf, 10, &temp))
return -EINVAL;
temp = cvt_auto_temp(temp);
if (temp < 0)
return temp;
mutex_lock(&data->lock);
data->pwm_automatic[attr->index] = temp;
reg = i2c_smbus_read_byte_data(client, pwm_auto_reg);
if (!(attr->index % 2)) {
reg &= 0xF;
reg |= (temp << 4) & 0xF0;
} else {
reg &= 0xF0;
reg |= temp & 0xF;
}
i2c_smbus_write_byte_data(client, pwm_auto_reg, reg);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_alarm(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7470_data *data = adt7470_update_device(dev);
if (data->alarm & attr->index)
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static int adt7470_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int vendor, device, revision;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
vendor = i2c_smbus_read_byte_data(client, ADT7470_REG_VENDOR);
if (vendor != ADT7470_VENDOR)
return -ENODEV;
device = i2c_smbus_read_byte_data(client, ADT7470_REG_DEVICE);
if (device != ADT7470_DEVICE)
return -ENODEV;
revision = i2c_smbus_read_byte_data(client, ADT7470_REG_REVISION);
if (revision != ADT7470_REVISION)
return -ENODEV;
strlcpy(info->type, "adt7470", I2C_NAME_SIZE);
return 0;
}
static void adt7470_init_client(struct i2c_client *client)
{
int reg = i2c_smbus_read_byte_data(client, ADT7470_REG_CFG);
if (reg < 0) {
dev_err(&client->dev, "cannot read configuration register\n");
} else {
i2c_smbus_write_byte_data(client, ADT7470_REG_CFG, reg | 3);
}
}
static int adt7470_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct adt7470_data *data;
struct device *hwmon_dev;
data = devm_kzalloc(dev, sizeof(struct adt7470_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->num_temp_sensors = -1;
data->auto_update_interval = AUTO_UPDATE_INTERVAL;
i2c_set_clientdata(client, data);
data->client = client;
mutex_init(&data->lock);
dev_info(&client->dev, "%s chip found\n", client->name);
adt7470_init_client(client);
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data,
adt7470_groups);
if (IS_ERR(hwmon_dev))
return PTR_ERR(hwmon_dev);
data->auto_update = kthread_run(adt7470_update_thread, client, "%s",
dev_name(hwmon_dev));
if (IS_ERR(data->auto_update)) {
return PTR_ERR(data->auto_update);
}
return 0;
}
static int adt7470_remove(struct i2c_client *client)
{
struct adt7470_data *data = i2c_get_clientdata(client);
kthread_stop(data->auto_update);
return 0;
}
