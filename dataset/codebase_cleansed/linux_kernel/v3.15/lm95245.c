static int temp_from_reg_unsigned(u8 val_h, u8 val_l)
{
return val_h * 1000 + val_l * 1000 / 256;
}
static int temp_from_reg_signed(u8 val_h, u8 val_l)
{
if (val_h & 0x80)
return (val_h - 0x100) * 1000;
return temp_from_reg_unsigned(val_h, val_l);
}
static struct lm95245_data *lm95245_update_device(struct device *dev)
{
struct lm95245_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated
+ msecs_to_jiffies(data->interval)) || !data->valid) {
int i;
for (i = 0; i < ARRAY_SIZE(lm95245_reg_address); i++)
data->regs[i]
= i2c_smbus_read_byte_data(client,
lm95245_reg_address[i]);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static unsigned long lm95245_read_conversion_rate(struct i2c_client *client)
{
int rate;
unsigned long interval;
rate = i2c_smbus_read_byte_data(client, LM95245_REG_RW_CONVERS_RATE);
switch (rate) {
case RATE_CR0063:
interval = 63;
break;
case RATE_CR0364:
interval = 364;
break;
case RATE_CR1000:
interval = 1000;
break;
case RATE_CR2500:
default:
interval = 2500;
break;
}
return interval;
}
static unsigned long lm95245_set_conversion_rate(struct i2c_client *client,
unsigned long interval)
{
int rate;
if (interval <= 63) {
interval = 63;
rate = RATE_CR0063;
} else if (interval <= 364) {
interval = 364;
rate = RATE_CR0364;
} else if (interval <= 1000) {
interval = 1000;
rate = RATE_CR1000;
} else {
interval = 2500;
rate = RATE_CR2500;
}
i2c_smbus_write_byte_data(client, LM95245_REG_RW_CONVERS_RATE, rate);
return interval;
}
static ssize_t show_input(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct lm95245_data *data = lm95245_update_device(dev);
int temp;
int index = to_sensor_dev_attr(attr)->index;
if (index == 0 || data->regs[index] & 0x80)
temp = temp_from_reg_signed(data->regs[index],
data->regs[index + 1]);
else
temp = temp_from_reg_unsigned(data->regs[index + 2],
data->regs[index + 3]);
return snprintf(buf, PAGE_SIZE - 1, "%d\n", temp);
}
static ssize_t show_limit(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct lm95245_data *data = lm95245_update_device(dev);
int index = to_sensor_dev_attr(attr)->index;
return snprintf(buf, PAGE_SIZE - 1, "%d\n",
data->regs[index] * 1000);
}
static ssize_t set_limit(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct lm95245_data *data = dev_get_drvdata(dev);
int index = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = data->client;
unsigned long val;
if (kstrtoul(buf, 10, &val) < 0)
return -EINVAL;
val /= 1000;
val = clamp_val(val, 0, (index == 6 ? 127 : 255));
mutex_lock(&data->update_lock);
data->valid = 0;
i2c_smbus_write_byte_data(client, lm95245_reg_address[index], val);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_crit_hyst(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct lm95245_data *data = lm95245_update_device(dev);
int index = to_sensor_dev_attr(attr)->index;
int hyst = data->regs[index] - data->regs[8];
return snprintf(buf, PAGE_SIZE - 1, "%d\n", hyst * 1000);
}
static ssize_t set_crit_hyst(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct lm95245_data *data = dev_get_drvdata(dev);
int index = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = data->client;
unsigned long val;
int hyst, limit;
if (kstrtoul(buf, 10, &val) < 0)
return -EINVAL;
mutex_lock(&data->update_lock);
limit = i2c_smbus_read_byte_data(client, lm95245_reg_address[index]);
hyst = limit - val / 1000;
hyst = clamp_val(hyst, 0, 31);
data->regs[8] = hyst;
i2c_smbus_write_byte_data(client, LM95245_REG_RW_COMMON_HYSTERESIS,
hyst);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_type(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct lm95245_data *data = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE - 1,
data->config2 & CFG2_REMOTE_TT ? "1\n" : "2\n");
}
static ssize_t set_type(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct lm95245_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
unsigned long val;
if (kstrtoul(buf, 10, &val) < 0)
return -EINVAL;
if (val != 1 && val != 2)
return -EINVAL;
mutex_lock(&data->update_lock);
if (val == 1)
data->config2 |= CFG2_REMOTE_TT;
else
data->config2 &= ~CFG2_REMOTE_TT;
data->valid = 0;
i2c_smbus_write_byte_data(client, LM95245_REG_RW_CONFIG2,
data->config2);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct lm95245_data *data = lm95245_update_device(dev);
int index = to_sensor_dev_attr(attr)->index;
return snprintf(buf, PAGE_SIZE - 1, "%d\n",
!!(data->regs[9] & index));
}
static ssize_t show_interval(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct lm95245_data *data = lm95245_update_device(dev);
return snprintf(buf, PAGE_SIZE - 1, "%lu\n", data->interval);
}
static ssize_t set_interval(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct lm95245_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
unsigned long val;
if (kstrtoul(buf, 10, &val) < 0)
return -EINVAL;
mutex_lock(&data->update_lock);
data->interval = lm95245_set_conversion_rate(client, val);
mutex_unlock(&data->update_lock);
return count;
}
static int lm95245_detect(struct i2c_client *new_client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = new_client->adapter;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
if (i2c_smbus_read_byte_data(new_client, LM95245_REG_R_MAN_ID)
!= MANUFACTURER_ID
|| i2c_smbus_read_byte_data(new_client, LM95245_REG_R_CHIP_ID)
!= DEFAULT_REVISION)
return -ENODEV;
strlcpy(info->type, DEVNAME, I2C_NAME_SIZE);
return 0;
}
static void lm95245_init_client(struct i2c_client *client,
struct lm95245_data *data)
{
data->interval = lm95245_read_conversion_rate(client);
data->config1 = i2c_smbus_read_byte_data(client,
LM95245_REG_RW_CONFIG1);
data->config2 = i2c_smbus_read_byte_data(client,
LM95245_REG_RW_CONFIG2);
if (data->config1 & CFG_STOP) {
data->config1 &= ~CFG_STOP;
i2c_smbus_write_byte_data(client, LM95245_REG_RW_CONFIG1,
data->config1);
}
}
static int lm95245_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct lm95245_data *data;
struct device *hwmon_dev;
data = devm_kzalloc(dev, sizeof(struct lm95245_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = client;
mutex_init(&data->update_lock);
lm95245_init_client(client, data);
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data,
lm95245_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
