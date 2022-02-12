static int tmp401_register_to_temp(u16 reg, u8 config)
{
int temp = reg;
if (config & TMP401_CONFIG_RANGE)
temp -= 64 * 256;
return (temp * 625 + 80) / 160;
}
static u16 tmp401_temp_to_register(long temp, u8 config)
{
if (config & TMP401_CONFIG_RANGE) {
temp = SENSORS_LIMIT(temp, -64000, 191000);
temp += 64000;
} else
temp = SENSORS_LIMIT(temp, 0, 127000);
return (temp * 160 + 312) / 625;
}
static int tmp401_crit_register_to_temp(u8 reg, u8 config)
{
int temp = reg;
if (config & TMP401_CONFIG_RANGE)
temp -= 64;
return temp * 1000;
}
static u8 tmp401_crit_temp_to_register(long temp, u8 config)
{
if (config & TMP401_CONFIG_RANGE) {
temp = SENSORS_LIMIT(temp, -64000, 191000);
temp += 64000;
} else
temp = SENSORS_LIMIT(temp, 0, 127000);
return (temp + 500) / 1000;
}
static struct tmp401_data *tmp401_update_device_reg16(
struct i2c_client *client, struct tmp401_data *data)
{
int i;
for (i = 0; i < 2; i++) {
data->temp[i] = i2c_smbus_read_byte_data(client,
TMP401_TEMP_MSB[i]) << 8;
data->temp[i] |= i2c_smbus_read_byte_data(client,
TMP401_TEMP_LSB[i]);
data->temp_low[i] = i2c_smbus_read_byte_data(client,
TMP401_TEMP_LOW_LIMIT_MSB_READ[i]) << 8;
data->temp_low[i] |= i2c_smbus_read_byte_data(client,
TMP401_TEMP_LOW_LIMIT_LSB[i]);
data->temp_high[i] = i2c_smbus_read_byte_data(client,
TMP401_TEMP_HIGH_LIMIT_MSB_READ[i]) << 8;
data->temp_high[i] |= i2c_smbus_read_byte_data(client,
TMP401_TEMP_HIGH_LIMIT_LSB[i]);
data->temp_crit[i] = i2c_smbus_read_byte_data(client,
TMP401_TEMP_CRIT_LIMIT[i]);
if (data->kind == tmp411) {
data->temp_lowest[i] = i2c_smbus_read_byte_data(client,
TMP411_TEMP_LOWEST_MSB[i]) << 8;
data->temp_lowest[i] |= i2c_smbus_read_byte_data(
client, TMP411_TEMP_LOWEST_LSB[i]);
data->temp_highest[i] = i2c_smbus_read_byte_data(
client, TMP411_TEMP_HIGHEST_MSB[i]) << 8;
data->temp_highest[i] |= i2c_smbus_read_byte_data(
client, TMP411_TEMP_HIGHEST_LSB[i]);
}
}
return data;
}
static struct tmp401_data *tmp401_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct tmp401_data *data = i2c_get_clientdata(client);
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
data->status = i2c_smbus_read_byte_data(client, TMP401_STATUS);
data->config = i2c_smbus_read_byte_data(client,
TMP401_CONFIG_READ);
tmp401_update_device_reg16(client, data);
data->temp_crit_hyst = i2c_smbus_read_byte_data(client,
TMP401_TEMP_CRIT_HYST);
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
struct tmp401_data *data = tmp401_update_device(dev);
return sprintf(buf, "%d\n",
tmp401_register_to_temp(data->temp[index], data->config));
}
static ssize_t show_temp_min(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct tmp401_data *data = tmp401_update_device(dev);
return sprintf(buf, "%d\n",
tmp401_register_to_temp(data->temp_low[index], data->config));
}
static ssize_t show_temp_max(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct tmp401_data *data = tmp401_update_device(dev);
return sprintf(buf, "%d\n",
tmp401_register_to_temp(data->temp_high[index], data->config));
}
static ssize_t show_temp_crit(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct tmp401_data *data = tmp401_update_device(dev);
return sprintf(buf, "%d\n",
tmp401_crit_register_to_temp(data->temp_crit[index],
data->config));
}
static ssize_t show_temp_crit_hyst(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int temp, index = to_sensor_dev_attr(devattr)->index;
struct tmp401_data *data = tmp401_update_device(dev);
mutex_lock(&data->update_lock);
temp = tmp401_crit_register_to_temp(data->temp_crit[index],
data->config);
temp -= data->temp_crit_hyst * 1000;
mutex_unlock(&data->update_lock);
return sprintf(buf, "%d\n", temp);
}
static ssize_t show_temp_lowest(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct tmp401_data *data = tmp401_update_device(dev);
return sprintf(buf, "%d\n",
tmp401_register_to_temp(data->temp_lowest[index],
data->config));
}
static ssize_t show_temp_highest(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct tmp401_data *data = tmp401_update_device(dev);
return sprintf(buf, "%d\n",
tmp401_register_to_temp(data->temp_highest[index],
data->config));
}
static ssize_t show_status(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int mask = to_sensor_dev_attr(devattr)->index;
struct tmp401_data *data = tmp401_update_device(dev);
if (data->status & mask)
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static ssize_t store_temp_min(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
int index = to_sensor_dev_attr(devattr)->index;
struct tmp401_data *data = tmp401_update_device(dev);
long val;
u16 reg;
if (kstrtol(buf, 10, &val))
return -EINVAL;
reg = tmp401_temp_to_register(val, data->config);
mutex_lock(&data->update_lock);
i2c_smbus_write_byte_data(to_i2c_client(dev),
TMP401_TEMP_LOW_LIMIT_MSB_WRITE[index], reg >> 8);
i2c_smbus_write_byte_data(to_i2c_client(dev),
TMP401_TEMP_LOW_LIMIT_LSB[index], reg & 0xFF);
data->temp_low[index] = reg;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t store_temp_max(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
int index = to_sensor_dev_attr(devattr)->index;
struct tmp401_data *data = tmp401_update_device(dev);
long val;
u16 reg;
if (kstrtol(buf, 10, &val))
return -EINVAL;
reg = tmp401_temp_to_register(val, data->config);
mutex_lock(&data->update_lock);
i2c_smbus_write_byte_data(to_i2c_client(dev),
TMP401_TEMP_HIGH_LIMIT_MSB_WRITE[index], reg >> 8);
i2c_smbus_write_byte_data(to_i2c_client(dev),
TMP401_TEMP_HIGH_LIMIT_LSB[index], reg & 0xFF);
data->temp_high[index] = reg;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t store_temp_crit(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
int index = to_sensor_dev_attr(devattr)->index;
struct tmp401_data *data = tmp401_update_device(dev);
long val;
u8 reg;
if (kstrtol(buf, 10, &val))
return -EINVAL;
reg = tmp401_crit_temp_to_register(val, data->config);
mutex_lock(&data->update_lock);
i2c_smbus_write_byte_data(to_i2c_client(dev),
TMP401_TEMP_CRIT_LIMIT[index], reg);
data->temp_crit[index] = reg;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t store_temp_crit_hyst(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
int temp, index = to_sensor_dev_attr(devattr)->index;
struct tmp401_data *data = tmp401_update_device(dev);
long val;
u8 reg;
if (kstrtol(buf, 10, &val))
return -EINVAL;
if (data->config & TMP401_CONFIG_RANGE)
val = SENSORS_LIMIT(val, -64000, 191000);
else
val = SENSORS_LIMIT(val, 0, 127000);
mutex_lock(&data->update_lock);
temp = tmp401_crit_register_to_temp(data->temp_crit[index],
data->config);
val = SENSORS_LIMIT(val, temp - 255000, temp);
reg = ((temp - val) + 500) / 1000;
i2c_smbus_write_byte_data(to_i2c_client(dev),
TMP401_TEMP_CRIT_HYST, reg);
data->temp_crit_hyst = reg;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t reset_temp_history(struct device *dev,
struct device_attribute *devattr, const char *buf, size_t count)
{
long val;
if (kstrtol(buf, 10, &val))
return -EINVAL;
if (val != 1) {
dev_err(dev, "temp_reset_history value %ld not"
" supported. Use 1 to reset the history!\n", val);
return -EINVAL;
}
i2c_smbus_write_byte_data(to_i2c_client(dev),
TMP411_TEMP_LOWEST_MSB[0], val);
return count;
}
static void tmp401_init_client(struct i2c_client *client)
{
int config, config_orig;
i2c_smbus_write_byte_data(client, TMP401_CONVERSION_RATE_WRITE, 5);
config = i2c_smbus_read_byte_data(client, TMP401_CONFIG_READ);
if (config < 0) {
dev_warn(&client->dev, "Initialization failed!\n");
return;
}
config_orig = config;
config &= ~TMP401_CONFIG_SHUTDOWN;
if (config != config_orig)
i2c_smbus_write_byte_data(client, TMP401_CONFIG_WRITE, config);
}
static int tmp401_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
enum chips kind;
struct i2c_adapter *adapter = client->adapter;
u8 reg;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
reg = i2c_smbus_read_byte_data(client, TMP401_MANUFACTURER_ID_REG);
if (reg != TMP401_MANUFACTURER_ID)
return -ENODEV;
reg = i2c_smbus_read_byte_data(client, TMP401_DEVICE_ID_REG);
switch (reg) {
case TMP401_DEVICE_ID:
kind = tmp401;
break;
case TMP411_DEVICE_ID:
kind = tmp411;
break;
default:
return -ENODEV;
}
reg = i2c_smbus_read_byte_data(client, TMP401_CONFIG_READ);
if (reg & 0x1b)
return -ENODEV;
reg = i2c_smbus_read_byte_data(client, TMP401_CONVERSION_RATE_READ);
if (reg > 15)
return -ENODEV;
strlcpy(info->type, tmp401_id[kind].name, I2C_NAME_SIZE);
return 0;
}
static int tmp401_remove(struct i2c_client *client)
{
struct tmp401_data *data = i2c_get_clientdata(client);
int i;
if (data->hwmon_dev)
hwmon_device_unregister(data->hwmon_dev);
for (i = 0; i < ARRAY_SIZE(tmp401_attr); i++)
device_remove_file(&client->dev, &tmp401_attr[i].dev_attr);
if (data->kind == tmp411) {
for (i = 0; i < ARRAY_SIZE(tmp411_attr); i++)
device_remove_file(&client->dev,
&tmp411_attr[i].dev_attr);
}
return 0;
}
static int tmp401_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int i, err = 0;
struct tmp401_data *data;
const char *names[] = { "TMP401", "TMP411" };
data = devm_kzalloc(&client->dev, sizeof(struct tmp401_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
data->kind = id->driver_data;
tmp401_init_client(client);
for (i = 0; i < ARRAY_SIZE(tmp401_attr); i++) {
err = device_create_file(&client->dev,
&tmp401_attr[i].dev_attr);
if (err)
goto exit_remove;
}
if (data->kind == tmp411) {
for (i = 0; i < ARRAY_SIZE(tmp411_attr); i++) {
err = device_create_file(&client->dev,
&tmp411_attr[i].dev_attr);
if (err)
goto exit_remove;
}
}
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
data->hwmon_dev = NULL;
goto exit_remove;
}
dev_info(&client->dev, "Detected TI %s chip\n", names[data->kind]);
return 0;
exit_remove:
tmp401_remove(client);
return err;
}
