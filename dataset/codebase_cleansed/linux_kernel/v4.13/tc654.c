static struct tc654_data *tc654_update_client(struct device *dev)
{
struct tc654_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int ret = 0;
mutex_lock(&data->update_lock);
if (time_before(jiffies, data->last_updated + TC654_UPDATE_INTERVAL) &&
likely(data->valid))
goto out;
ret = i2c_smbus_read_byte_data(client, TC654_REG_RPM(0));
if (ret < 0)
goto out;
data->rpm_output[0] = ret;
ret = i2c_smbus_read_byte_data(client, TC654_REG_RPM(1));
if (ret < 0)
goto out;
data->rpm_output[1] = ret;
ret = i2c_smbus_read_byte_data(client, TC654_REG_FAN_FAULT(0));
if (ret < 0)
goto out;
data->fan_fault[0] = ret;
ret = i2c_smbus_read_byte_data(client, TC654_REG_FAN_FAULT(1));
if (ret < 0)
goto out;
data->fan_fault[1] = ret;
ret = i2c_smbus_read_byte_data(client, TC654_REG_CONFIG);
if (ret < 0)
goto out;
data->config = ret;
ret = i2c_smbus_read_byte_data(client, TC654_REG_STATUS);
if (ret < 0)
goto out;
data->status = ret;
ret = i2c_smbus_read_byte_data(client, TC654_REG_DUTY_CYCLE);
if (ret < 0)
goto out;
data->duty_cycle = ret & 0x0f;
data->last_updated = jiffies;
data->valid = true;
out:
mutex_unlock(&data->update_lock);
if (ret < 0)
data = ERR_PTR(ret);
return data;
}
static ssize_t show_fan(struct device *dev, struct device_attribute *da,
char *buf)
{
int nr = to_sensor_dev_attr(da)->index;
struct tc654_data *data = tc654_update_client(dev);
int val;
if (IS_ERR(data))
return PTR_ERR(data);
if (data->config & TC654_REG_CONFIG_RES)
val = data->rpm_output[nr] * TC654_HIGH_RPM_RESOLUTION;
else
val = data->rpm_output[nr] * TC654_LOW_RPM_RESOLUTION;
return sprintf(buf, "%d\n", val);
}
static ssize_t show_fan_min(struct device *dev, struct device_attribute *da,
char *buf)
{
int nr = to_sensor_dev_attr(da)->index;
struct tc654_data *data = tc654_update_client(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n",
TC654_FAN_FAULT_FROM_REG(data->fan_fault[nr]));
}
static ssize_t set_fan_min(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(da)->index;
struct tc654_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
unsigned long val;
int ret;
if (kstrtoul(buf, 10, &val))
return -EINVAL;
val = clamp_val(val, 0, 12750);
mutex_lock(&data->update_lock);
data->fan_fault[nr] = TC654_FAN_FAULT_TO_REG(val);
ret = i2c_smbus_write_byte_data(client, TC654_REG_FAN_FAULT(nr),
data->fan_fault[nr]);
mutex_unlock(&data->update_lock);
return ret < 0 ? ret : count;
}
static ssize_t show_fan_alarm(struct device *dev, struct device_attribute *da,
char *buf)
{
int nr = to_sensor_dev_attr(da)->index;
struct tc654_data *data = tc654_update_client(dev);
int val;
if (IS_ERR(data))
return PTR_ERR(data);
if (nr == 0)
val = !!(data->status & TC654_REG_STATUS_F1F);
else
val = !!(data->status & TC654_REG_STATUS_F2F);
return sprintf(buf, "%d\n", val);
}
static ssize_t show_fan_pulses(struct device *dev, struct device_attribute *da,
char *buf)
{
int nr = to_sensor_dev_attr(da)->index;
struct tc654_data *data = tc654_update_client(dev);
u8 val;
if (IS_ERR(data))
return PTR_ERR(data);
val = BIT((data->config >> TC654_FAN_PULSE_SHIFT[nr]) & 0x03);
return sprintf(buf, "%d\n", val);
}
static ssize_t set_fan_pulses(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(da)->index;
struct tc654_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
u8 config;
unsigned long val;
int ret;
if (kstrtoul(buf, 10, &val))
return -EINVAL;
switch (val) {
case 1:
config = 0;
break;
case 2:
config = 1;
break;
case 4:
config = 2;
break;
case 8:
config = 3;
break;
default:
return -EINVAL;
}
mutex_lock(&data->update_lock);
data->config &= ~(0x03 << TC654_FAN_PULSE_SHIFT[nr]);
data->config |= (config << TC654_FAN_PULSE_SHIFT[nr]);
ret = i2c_smbus_write_byte_data(client, TC654_REG_CONFIG, data->config);
mutex_unlock(&data->update_lock);
return ret < 0 ? ret : count;
}
static ssize_t show_pwm_mode(struct device *dev,
struct device_attribute *da, char *buf)
{
struct tc654_data *data = tc654_update_client(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n", !!(data->config & TC654_REG_CONFIG_DUTYC));
}
static ssize_t set_pwm_mode(struct device *dev,
struct device_attribute *da,
const char *buf, size_t count)
{
struct tc654_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
unsigned long val;
int ret;
if (kstrtoul(buf, 10, &val))
return -EINVAL;
if (val != 0 && val != 1)
return -EINVAL;
mutex_lock(&data->update_lock);
if (val)
data->config |= TC654_REG_CONFIG_DUTYC;
else
data->config &= ~TC654_REG_CONFIG_DUTYC;
ret = i2c_smbus_write_byte_data(client, TC654_REG_CONFIG, data->config);
mutex_unlock(&data->update_lock);
return ret < 0 ? ret : count;
}
static ssize_t show_pwm(struct device *dev, struct device_attribute *da,
char *buf)
{
struct tc654_data *data = tc654_update_client(dev);
int pwm;
if (IS_ERR(data))
return PTR_ERR(data);
if (data->config & TC654_REG_CONFIG_SDM)
pwm = 0;
else
pwm = tc654_pwm_map[data->duty_cycle];
return sprintf(buf, "%d\n", pwm);
}
static ssize_t set_pwm(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct tc654_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
unsigned long val;
int ret;
if (kstrtoul(buf, 10, &val))
return -EINVAL;
if (val > 255)
return -EINVAL;
mutex_lock(&data->update_lock);
if (val == 0)
data->config |= TC654_REG_CONFIG_SDM;
else
data->config &= ~TC654_REG_CONFIG_SDM;
data->duty_cycle = find_closest(val, tc654_pwm_map,
ARRAY_SIZE(tc654_pwm_map));
ret = i2c_smbus_write_byte_data(client, TC654_REG_CONFIG, data->config);
if (ret < 0)
goto out;
ret = i2c_smbus_write_byte_data(client, TC654_REG_DUTY_CYCLE,
data->duty_cycle);
out:
mutex_unlock(&data->update_lock);
return ret < 0 ? ret : count;
}
static int tc654_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct tc654_data *data;
struct device *hwmon_dev;
int ret;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
data = devm_kzalloc(dev, sizeof(struct tc654_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = client;
mutex_init(&data->update_lock);
ret = i2c_smbus_read_byte_data(client, TC654_REG_CONFIG);
if (ret < 0)
return ret;
data->config = ret;
hwmon_dev =
devm_hwmon_device_register_with_groups(dev, client->name, data,
tc654_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
