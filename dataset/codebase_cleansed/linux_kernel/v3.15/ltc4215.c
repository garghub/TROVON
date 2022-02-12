static struct ltc4215_data *ltc4215_update_device(struct device *dev)
{
struct ltc4215_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
s32 val;
int i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ / 10) || !data->valid) {
dev_dbg(&client->dev, "Starting ltc4215 update\n");
for (i = 0; i < ARRAY_SIZE(data->regs); i++) {
val = i2c_smbus_read_byte_data(client, i);
if (unlikely(val < 0))
data->regs[i] = 0;
else
data->regs[i] = val;
}
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static int ltc4215_get_voltage(struct device *dev, u8 reg)
{
struct ltc4215_data *data = ltc4215_update_device(dev);
const u8 regval = data->regs[reg];
u32 voltage = 0;
switch (reg) {
case LTC4215_SENSE:
voltage = regval * 151 / 1000;
break;
case LTC4215_SOURCE:
voltage = regval * 605 / 10;
break;
case LTC4215_ADIN:
voltage = regval * 482 * 125 / 1000;
break;
default:
WARN_ON_ONCE(1);
break;
}
return voltage;
}
static unsigned int ltc4215_get_current(struct device *dev)
{
struct ltc4215_data *data = ltc4215_update_device(dev);
const unsigned int voltage = data->regs[LTC4215_SENSE] * 151;
const unsigned int curr = voltage / 4;
return curr;
}
static ssize_t ltc4215_show_voltage(struct device *dev,
struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
const int voltage = ltc4215_get_voltage(dev, attr->index);
return snprintf(buf, PAGE_SIZE, "%d\n", voltage);
}
static ssize_t ltc4215_show_current(struct device *dev,
struct device_attribute *da,
char *buf)
{
const unsigned int curr = ltc4215_get_current(dev);
return snprintf(buf, PAGE_SIZE, "%u\n", curr);
}
static ssize_t ltc4215_show_power(struct device *dev,
struct device_attribute *da,
char *buf)
{
const unsigned int curr = ltc4215_get_current(dev);
const int output_voltage = ltc4215_get_voltage(dev, LTC4215_ADIN);
const unsigned int power = abs(output_voltage * curr);
return snprintf(buf, PAGE_SIZE, "%u\n", power);
}
static ssize_t ltc4215_show_alarm(struct device *dev,
struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct ltc4215_data *data = ltc4215_update_device(dev);
const u8 reg = data->regs[LTC4215_STATUS];
const u32 mask = attr->index;
return snprintf(buf, PAGE_SIZE, "%u\n", !!(reg & mask));
}
static int ltc4215_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct device *dev = &client->dev;
struct ltc4215_data *data;
struct device *hwmon_dev;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = client;
mutex_init(&data->update_lock);
i2c_smbus_write_byte_data(client, LTC4215_FAULT, 0x00);
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data,
ltc4215_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
