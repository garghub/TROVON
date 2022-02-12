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
static int tmp421_read(struct device *dev, enum hwmon_sensor_types type,
u32 attr, int channel, long *val)
{
struct tmp421_data *tmp421 = tmp421_update_device(dev);
switch (attr) {
case hwmon_temp_input:
if (tmp421->config & TMP421_CONFIG_RANGE)
*val = temp_from_u16(tmp421->temp[channel]);
else
*val = temp_from_s16(tmp421->temp[channel]);
return 0;
case hwmon_temp_fault:
*val = tmp421->temp[channel] & 0x01;
return 0;
default:
return -EOPNOTSUPP;
}
}
static umode_t tmp421_is_visible(const void *data, enum hwmon_sensor_types type,
u32 attr, int channel)
{
switch (attr) {
case hwmon_temp_fault:
if (channel == 0)
return 0;
return S_IRUGO;
case hwmon_temp_input:
return S_IRUGO;
default:
return 0;
}
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
const char * const names[] = { "TMP421", "TMP422", "TMP423",
"TMP441", "TMP442" };
int addr = client->addr;
u8 reg;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
reg = i2c_smbus_read_byte_data(client, TMP421_MANUFACTURER_ID_REG);
if (reg != TMP421_MANUFACTURER_ID)
return -ENODEV;
reg = i2c_smbus_read_byte_data(client, TMP421_CONVERSION_RATE_REG);
if (reg & 0xf8)
return -ENODEV;
reg = i2c_smbus_read_byte_data(client, TMP421_STATUS_REG);
if (reg & 0x7f)
return -ENODEV;
reg = i2c_smbus_read_byte_data(client, TMP421_DEVICE_ID_REG);
switch (reg) {
case TMP421_DEVICE_ID:
kind = tmp421;
break;
case TMP422_DEVICE_ID:
if (addr == 0x2a)
return -ENODEV;
kind = tmp422;
break;
case TMP423_DEVICE_ID:
if (addr != 0x4c && addr != 0x4d)
return -ENODEV;
kind = tmp423;
break;
case TMP441_DEVICE_ID:
kind = tmp441;
break;
case TMP442_DEVICE_ID:
if (addr != 0x4c && addr != 0x4d)
return -ENODEV;
kind = tmp442;
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
int i, err;
data = devm_kzalloc(dev, sizeof(struct tmp421_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
mutex_init(&data->update_lock);
if (client->dev.of_node)
data->channels = (unsigned long)
of_device_get_match_data(&client->dev);
else
data->channels = id->driver_data;
data->client = client;
err = tmp421_init_client(client);
if (err)
return err;
for (i = 0; i < data->channels; i++)
data->temp_config[i] = HWMON_T_INPUT | HWMON_T_FAULT;
data->chip.ops = &tmp421_ops;
data->chip.info = data->info;
data->info[0] = &data->temp_info;
data->temp_info.type = hwmon_temp;
data->temp_info.config = data->temp_config;
hwmon_dev = devm_hwmon_device_register_with_info(dev, client->name,
data,
&data->chip,
NULL);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
