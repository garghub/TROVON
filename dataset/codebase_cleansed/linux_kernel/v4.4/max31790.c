static struct max31790_data *max31790_update_device(struct device *dev)
{
struct max31790_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
struct max31790_data *ret = data;
int i;
int rv;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
rv = i2c_smbus_read_byte_data(client,
MAX31790_REG_FAN_FAULT_STATUS1);
if (rv < 0)
goto abort;
data->fault_status = rv & 0x3F;
rv = i2c_smbus_read_byte_data(client,
MAX31790_REG_FAN_FAULT_STATUS2);
if (rv < 0)
goto abort;
data->fault_status |= (rv & 0x3F) << 6;
for (i = 0; i < NR_CHANNEL; i++) {
rv = i2c_smbus_read_word_swapped(client,
MAX31790_REG_TACH_COUNT(i));
if (rv < 0)
goto abort;
data->tach[i] = rv;
if (data->fan_config[i]
& MAX31790_FAN_CFG_TACH_INPUT) {
rv = i2c_smbus_read_word_swapped(client,
MAX31790_REG_TACH_COUNT(NR_CHANNEL
+ i));
if (rv < 0)
goto abort;
data->tach[NR_CHANNEL + i] = rv;
} else {
rv = i2c_smbus_read_word_swapped(client,
MAX31790_REG_PWMOUT(i));
if (rv < 0)
goto abort;
data->pwm[i] = rv;
rv = i2c_smbus_read_word_swapped(client,
MAX31790_REG_TARGET_COUNT(i));
if (rv < 0)
goto abort;
data->target_count[i] = rv;
}
}
data->last_updated = jiffies;
data->valid = true;
}
goto done;
abort:
data->valid = false;
ret = ERR_PTR(rv);
done:
mutex_unlock(&data->update_lock);
return ret;
}
static u8 get_tach_period(u8 fan_dynamics)
{
return tach_period[SR_FROM_REG(fan_dynamics)];
}
static u8 bits_for_tach_period(int rpm)
{
u8 bits;
if (rpm < 500)
bits = 0x0;
else if (rpm < 1000)
bits = 0x1;
else if (rpm < 2000)
bits = 0x2;
else if (rpm < 4000)
bits = 0x3;
else if (rpm < 8000)
bits = 0x4;
else
bits = 0x5;
return bits;
}
static ssize_t get_fan(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct max31790_data *data = max31790_update_device(dev);
int sr, rpm;
if (IS_ERR(data))
return PTR_ERR(data);
sr = get_tach_period(data->fan_dynamics[attr->index]);
rpm = RPM_FROM_REG(data->tach[attr->index], sr);
return sprintf(buf, "%d\n", rpm);
}
static ssize_t get_fan_target(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct max31790_data *data = max31790_update_device(dev);
int sr, rpm;
if (IS_ERR(data))
return PTR_ERR(data);
sr = get_tach_period(data->fan_dynamics[attr->index]);
rpm = RPM_FROM_REG(data->target_count[attr->index], sr);
return sprintf(buf, "%d\n", rpm);
}
static ssize_t set_fan_target(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct max31790_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
u8 bits;
int sr;
int target_count;
unsigned long rpm;
int err;
err = kstrtoul(buf, 10, &rpm);
if (err)
return err;
mutex_lock(&data->update_lock);
rpm = clamp_val(rpm, FAN_RPM_MIN, FAN_RPM_MAX);
bits = bits_for_tach_period(rpm);
data->fan_dynamics[attr->index] =
((data->fan_dynamics[attr->index]
& ~MAX31790_FAN_DYN_SR_MASK)
| (bits << MAX31790_FAN_DYN_SR_SHIFT));
err = i2c_smbus_write_byte_data(client,
MAX31790_REG_FAN_DYNAMICS(attr->index),
data->fan_dynamics[attr->index]);
if (err < 0) {
mutex_unlock(&data->update_lock);
return err;
}
sr = get_tach_period(data->fan_dynamics[attr->index]);
target_count = RPM_TO_REG(rpm, sr);
target_count = clamp_val(target_count, 0x1, 0x7FF);
data->target_count[attr->index] = target_count << 5;
err = i2c_smbus_write_word_swapped(client,
MAX31790_REG_TARGET_COUNT(attr->index),
data->target_count[attr->index]);
mutex_unlock(&data->update_lock);
if (err < 0)
return err;
return count;
}
static ssize_t get_pwm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct max31790_data *data = max31790_update_device(dev);
int pwm;
if (IS_ERR(data))
return PTR_ERR(data);
pwm = data->pwm[attr->index] >> 8;
return sprintf(buf, "%d\n", pwm);
}
static ssize_t set_pwm(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct max31790_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
unsigned long pwm;
int err;
err = kstrtoul(buf, 10, &pwm);
if (err)
return err;
if (pwm > 255)
return -EINVAL;
mutex_lock(&data->update_lock);
data->pwm[attr->index] = pwm << 8;
err = i2c_smbus_write_word_swapped(client,
MAX31790_REG_PWMOUT(attr->index),
data->pwm[attr->index]);
mutex_unlock(&data->update_lock);
if (err < 0)
return err;
return count;
}
static ssize_t get_pwm_enable(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct max31790_data *data = max31790_update_device(dev);
int mode;
if (IS_ERR(data))
return PTR_ERR(data);
if (data->fan_config[attr->index] & MAX31790_FAN_CFG_RPM_MODE)
mode = 2;
else if (data->fan_config[attr->index] & MAX31790_FAN_CFG_TACH_INPUT_EN)
mode = 1;
else
mode = 0;
return sprintf(buf, "%d\n", mode);
}
static ssize_t set_pwm_enable(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct max31790_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
unsigned long mode;
int err;
err = kstrtoul(buf, 10, &mode);
if (err)
return err;
switch (mode) {
case 0:
data->fan_config[attr->index] =
data->fan_config[attr->index]
& ~(MAX31790_FAN_CFG_TACH_INPUT_EN
| MAX31790_FAN_CFG_RPM_MODE);
break;
case 1:
data->fan_config[attr->index] =
(data->fan_config[attr->index]
| MAX31790_FAN_CFG_TACH_INPUT_EN)
& ~MAX31790_FAN_CFG_RPM_MODE;
break;
case 2:
data->fan_config[attr->index] =
data->fan_config[attr->index]
| MAX31790_FAN_CFG_TACH_INPUT_EN
| MAX31790_FAN_CFG_RPM_MODE;
break;
default:
return -EINVAL;
}
mutex_lock(&data->update_lock);
err = i2c_smbus_write_byte_data(client,
MAX31790_REG_FAN_CONFIG(attr->index),
data->fan_config[attr->index]);
mutex_unlock(&data->update_lock);
if (err < 0)
return err;
return count;
}
static ssize_t get_fan_fault(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct max31790_data *data = max31790_update_device(dev);
int fault;
if (IS_ERR(data))
return PTR_ERR(data);
fault = !!(data->fault_status & (1 << attr->index));
return sprintf(buf, "%d\n", fault);
}
static umode_t max31790_attrs_visible(struct kobject *kobj,
struct attribute *a, int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct max31790_data *data = dev_get_drvdata(dev);
struct device_attribute *devattr =
container_of(a, struct device_attribute, attr);
int index = to_sensor_dev_attr(devattr)->index % NR_CHANNEL;
u8 fan_config;
fan_config = data->fan_config[index];
if (n >= NR_CHANNEL * 2 && n < NR_CHANNEL * 4 &&
!(fan_config & MAX31790_FAN_CFG_TACH_INPUT))
return 0;
if (n >= NR_CHANNEL * 4 && (fan_config & MAX31790_FAN_CFG_TACH_INPUT))
return 0;
return a->mode;
}
static int max31790_init_client(struct i2c_client *client,
struct max31790_data *data)
{
int i, rv;
for (i = 0; i < NR_CHANNEL; i++) {
rv = i2c_smbus_read_byte_data(client,
MAX31790_REG_FAN_CONFIG(i));
if (rv < 0)
return rv;
data->fan_config[i] = rv;
rv = i2c_smbus_read_byte_data(client,
MAX31790_REG_FAN_DYNAMICS(i));
if (rv < 0)
return rv;
data->fan_dynamics[i] = rv;
}
return 0;
}
static int max31790_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct device *dev = &client->dev;
struct max31790_data *data;
struct device *hwmon_dev;
int err;
if (!i2c_check_functionality(adapter,
I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
data = devm_kzalloc(dev, sizeof(struct max31790_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = client;
mutex_init(&data->update_lock);
err = max31790_init_client(client, data);
if (err)
return err;
hwmon_dev = devm_hwmon_device_register_with_groups(dev,
client->name, data, max31790_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
