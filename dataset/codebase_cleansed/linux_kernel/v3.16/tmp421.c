static int temp_from_s16(s16 reg)
{
int temp = reg & ~0xf;
return (temp * 1000 + 128) / 256;
}
static int temp_from_u16(u16 reg)
{
int temp = reg & ~0xf;
temp -= 64 * 256;
return (temp * 1000 + 128) / 256;
}
static struct tmp421_data *tmp421_update_device(struct device *dev)
{
struct tmp421_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + 2 * HZ) || !data->valid) {
data->config = i2c_smbus_read_byte_data(client,
TMP421_CONFIG_REG_1);
for (i = 0; i < data->channels; i++) {
data->temp[i] = i2c_smbus_read_byte_data(client,
TMP421_TEMP_MSB[i]) << 8;
data->temp[i] |= i2c_smbus_read_byte_data(client,
TMP421_TEMP_LSB[i]);
}
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t show_temp_value(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct tmp421_data *data = tmp421_update_device(dev);
int temp;
mutex_lock(&data->update_lock);
if (data->config & TMP421_CONFIG_RANGE)
temp = temp_from_u16(data->temp[index]);
else
temp = temp_from_s16(data->temp[index]);
mutex_unlock(&data->update_lock);
return sprintf(buf, "%d\n", temp);
}
static ssize_t show_fault(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct tmp421_data *data = tmp421_update_device(dev);
if (data->temp[index] & 0x01)
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static umode_t tmp421_is_visible(struct kobject *kobj, struct attribute *a,
int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct tmp421_data *data = dev_get_drvdata(dev);
struct device_attribute *devattr;
unsigned int index;
devattr = container_of(a, struct device_attribute, attr);
index = to_sensor_dev_attr(devattr)->index;
if (index < data->channels)
return a->mode;
return 0;
}
static int tmp421_init_client(struct i2c_client *client)
{
int config, config_orig;
i2c_smbus_write_byte_data(client, TMP421_CONVERSION_RATE_REG, 0x05);
config = i2c_smbus_read_byte_data(client, TMP421_CONFIG_REG_1);
if (config < 0) {
dev_err(&client->dev,
"Could not read configuration register (%d)\n", config);
return config;
}
config_orig = config;
config &= ~TMP421_CONFIG_SHUTDOWN;
if (config != config_orig) {
dev_info(&client->dev, "Enable monitoring chip\n");
i2c_smbus_write_byte_data(client, TMP421_CONFIG_REG_1, config);
}
return 0;
}
static int tmp421_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
enum chips kind;
struct i2c_adapter *adapter = client->adapter;
const char *names[] = { "TMP421", "TMP422", "TMP423" };
u8 reg;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
reg = i2c_smbus_read_byte_data(client, TMP421_MANUFACTURER_ID_REG);
if (reg != TMP421_MANUFACTURER_ID)
return -ENODEV;
reg = i2c_smbus_read_byte_data(client, TMP421_DEVICE_ID_REG);
switch (reg) {
case TMP421_DEVICE_ID:
kind = tmp421;
break;
case TMP422_DEVICE_ID:
kind = tmp422;
break;
case TMP423_DEVICE_ID:
kind = tmp423;
break;
default:
return -ENODEV;
}
strlcpy(info->type, tmp421_id[kind].name, I2C_NAME_SIZE);
dev_info(&adapter->dev, "Detected TI %s chip at 0x%02x\n",
names[kind], client->addr);
return 0;
}
static int tmp421_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct device *hwmon_dev;
struct tmp421_data *data;
int err;
data = devm_kzalloc(dev, sizeof(struct tmp421_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
mutex_init(&data->update_lock);
data->channels = id->driver_data;
data->client = client;
err = tmp421_init_client(client);
if (err)
return err;
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data, tmp421_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
