static u8 get_mode_from_update_interval(u16 value)
{
size_t index;
u8 number_of_modes = ARRAY_SIZE(mode_to_update_interval);
if (value == 0)
return 0;
for (index = 1; index < number_of_modes; index++) {
if (mode_to_update_interval[index] <= value)
return index;
}
return number_of_modes - 1;
}
static int sht3x_read_from_command(struct i2c_client *client,
struct sht3x_data *data,
const char *command,
char *buf, int length, u32 wait_time)
{
int ret;
mutex_lock(&data->i2c_lock);
ret = i2c_master_send(client, command, SHT3X_CMD_LENGTH);
if (ret != SHT3X_CMD_LENGTH) {
ret = ret < 0 ? ret : -EIO;
goto out;
}
if (wait_time)
usleep_range(wait_time, wait_time + 1000);
ret = i2c_master_recv(client, buf, length);
if (ret != length) {
ret = ret < 0 ? ret : -EIO;
goto out;
}
ret = 0;
out:
mutex_unlock(&data->i2c_lock);
return ret;
}
static int sht3x_extract_temperature(u16 raw)
{
return ((21875 * (int)raw) >> 13) - 45000;
}
static u32 sht3x_extract_humidity(u16 raw)
{
return (12500 * (u32)raw) >> 13;
}
static struct sht3x_data *sht3x_update_client(struct device *dev)
{
struct sht3x_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
u16 interval_ms = mode_to_update_interval[data->mode];
unsigned long interval_jiffies = msecs_to_jiffies(interval_ms);
unsigned char buf[SHT3X_RESPONSE_LENGTH];
u16 val;
int ret = 0;
mutex_lock(&data->data_lock);
if (time_after(jiffies, data->last_update + interval_jiffies)) {
ret = sht3x_read_from_command(client, data, data->command, buf,
sizeof(buf), data->wait_time);
if (ret)
goto out;
val = be16_to_cpup((__be16 *)buf);
data->temperature = sht3x_extract_temperature(val);
val = be16_to_cpup((__be16 *)(buf + 3));
data->humidity = sht3x_extract_humidity(val);
data->last_update = jiffies;
}
out:
mutex_unlock(&data->data_lock);
if (ret)
return ERR_PTR(ret);
return data;
}
static ssize_t temp1_input_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sht3x_data *data = sht3x_update_client(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n", data->temperature);
}
static ssize_t humidity1_input_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sht3x_data *data = sht3x_update_client(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%u\n", data->humidity);
}
static int limits_update(struct sht3x_data *data)
{
int ret;
u8 index;
int temperature;
u32 humidity;
u16 raw;
char buffer[SHT3X_RESPONSE_LENGTH];
const struct sht3x_limit_commands *commands;
struct i2c_client *client = data->client;
for (index = 0; index < SHT3X_NUM_LIMIT_CMD; index++) {
commands = &limit_commands[index];
ret = sht3x_read_from_command(client, data,
commands->read_command, buffer,
SHT3X_RESPONSE_LENGTH, 0);
if (ret)
return ret;
raw = be16_to_cpup((__be16 *)buffer);
temperature = sht3x_extract_temperature((raw & 0x01ff) << 7);
humidity = sht3x_extract_humidity(raw & 0xfe00);
data->temperature_limits[index] = temperature;
data->humidity_limits[index] = humidity;
}
return ret;
}
static ssize_t temp1_limit_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct sht3x_data *data = dev_get_drvdata(dev);
u8 index = to_sensor_dev_attr(attr)->index;
int temperature_limit = data->temperature_limits[index];
return scnprintf(buf, PAGE_SIZE, "%d\n", temperature_limit);
}
static ssize_t humidity1_limit_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct sht3x_data *data = dev_get_drvdata(dev);
u8 index = to_sensor_dev_attr(attr)->index;
u32 humidity_limit = data->humidity_limits[index];
return scnprintf(buf, PAGE_SIZE, "%u\n", humidity_limit);
}
static size_t limit_store(struct device *dev,
size_t count,
u8 index,
int temperature,
u32 humidity)
{
char buffer[SHT3X_CMD_LENGTH + SHT3X_WORD_LEN + SHT3X_CRC8_LEN];
char *position = buffer;
int ret;
u16 raw;
struct sht3x_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
const struct sht3x_limit_commands *commands;
commands = &limit_commands[index];
memcpy(position, commands->write_command, SHT3X_CMD_LENGTH);
position += SHT3X_CMD_LENGTH;
raw = ((u32)(temperature + 45000) * 24543) >> (16 + 7);
raw |= ((humidity * 42950) >> 16) & 0xfe00;
*((__be16 *)position) = cpu_to_be16(raw);
position += SHT3X_WORD_LEN;
*position = crc8(sht3x_crc8_table,
position - SHT3X_WORD_LEN,
SHT3X_WORD_LEN,
SHT3X_CRC8_INIT);
mutex_lock(&data->i2c_lock);
ret = i2c_master_send(client, buffer, sizeof(buffer));
mutex_unlock(&data->i2c_lock);
if (ret != sizeof(buffer))
return ret < 0 ? ret : -EIO;
data->temperature_limits[index] = temperature;
data->humidity_limits[index] = humidity;
return count;
}
static ssize_t temp1_limit_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
int temperature;
int ret;
struct sht3x_data *data = dev_get_drvdata(dev);
u8 index = to_sensor_dev_attr(attr)->index;
ret = kstrtoint(buf, 0, &temperature);
if (ret)
return ret;
temperature = clamp_val(temperature, SHT3X_MIN_TEMPERATURE,
SHT3X_MAX_TEMPERATURE);
mutex_lock(&data->data_lock);
ret = limit_store(dev, count, index, temperature,
data->humidity_limits[index]);
mutex_unlock(&data->data_lock);
return ret;
}
static ssize_t humidity1_limit_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
u32 humidity;
int ret;
struct sht3x_data *data = dev_get_drvdata(dev);
u8 index = to_sensor_dev_attr(attr)->index;
ret = kstrtou32(buf, 0, &humidity);
if (ret)
return ret;
humidity = clamp_val(humidity, SHT3X_MIN_HUMIDITY, SHT3X_MAX_HUMIDITY);
mutex_lock(&data->data_lock);
ret = limit_store(dev, count, index, data->temperature_limits[index],
humidity);
mutex_unlock(&data->data_lock);
return ret;
}
static void sht3x_select_command(struct sht3x_data *data)
{
if (data->mode > 0) {
data->command = sht3x_cmd_measure_periodic_mode;
data->wait_time = 0;
} else if (data->setup.blocking_io) {
data->command = data->setup.high_precision ?
sht3x_cmd_measure_blocking_hpm :
sht3x_cmd_measure_blocking_lpm;
data->wait_time = 0;
} else {
if (data->setup.high_precision) {
data->command = sht3x_cmd_measure_nonblocking_hpm;
data->wait_time = SHT3X_NONBLOCKING_WAIT_TIME_HPM;
} else {
data->command = sht3x_cmd_measure_nonblocking_lpm;
data->wait_time = SHT3X_NONBLOCKING_WAIT_TIME_LPM;
}
}
}
static int status_register_read(struct device *dev,
struct device_attribute *attr,
char *buffer, int length)
{
int ret;
struct sht3x_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
ret = sht3x_read_from_command(client, data, sht3x_cmd_read_status_reg,
buffer, length, 0);
return ret;
}
static ssize_t temp1_alarm_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
char buffer[SHT3X_WORD_LEN + SHT3X_CRC8_LEN];
int ret;
ret = status_register_read(dev, attr, buffer,
SHT3X_WORD_LEN + SHT3X_CRC8_LEN);
if (ret)
return ret;
return scnprintf(buf, PAGE_SIZE, "%d\n", !!(buffer[0] & 0x04));
}
static ssize_t humidity1_alarm_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
char buffer[SHT3X_WORD_LEN + SHT3X_CRC8_LEN];
int ret;
ret = status_register_read(dev, attr, buffer,
SHT3X_WORD_LEN + SHT3X_CRC8_LEN);
if (ret)
return ret;
return scnprintf(buf, PAGE_SIZE, "%d\n", !!(buffer[0] & 0x08));
}
static ssize_t heater_enable_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
char buffer[SHT3X_WORD_LEN + SHT3X_CRC8_LEN];
int ret;
ret = status_register_read(dev, attr, buffer,
SHT3X_WORD_LEN + SHT3X_CRC8_LEN);
if (ret)
return ret;
return scnprintf(buf, PAGE_SIZE, "%d\n", !!(buffer[0] & 0x20));
}
static ssize_t heater_enable_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct sht3x_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int ret;
bool status;
ret = kstrtobool(buf, &status);
if (ret)
return ret;
mutex_lock(&data->i2c_lock);
if (status)
ret = i2c_master_send(client, (char *)&sht3x_cmd_heater_on,
SHT3X_CMD_LENGTH);
else
ret = i2c_master_send(client, (char *)&sht3x_cmd_heater_off,
SHT3X_CMD_LENGTH);
mutex_unlock(&data->i2c_lock);
return ret;
}
static ssize_t update_interval_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct sht3x_data *data = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%u\n",
mode_to_update_interval[data->mode]);
}
static ssize_t update_interval_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
u16 update_interval;
u8 mode;
int ret;
const char *command;
struct sht3x_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
ret = kstrtou16(buf, 0, &update_interval);
if (ret)
return ret;
mode = get_mode_from_update_interval(update_interval);
mutex_lock(&data->data_lock);
if (mode == data->mode) {
mutex_unlock(&data->data_lock);
return count;
}
mutex_lock(&data->i2c_lock);
if (data->mode > 0) {
ret = i2c_master_send(client, sht3x_cmd_break,
SHT3X_CMD_LENGTH);
if (ret != SHT3X_CMD_LENGTH)
goto out;
data->mode = 0;
}
if (mode > 0) {
if (data->setup.high_precision)
command = periodic_measure_commands_hpm[mode - 1];
else
command = periodic_measure_commands_lpm[mode - 1];
ret = i2c_master_send(client, command, SHT3X_CMD_LENGTH);
if (ret != SHT3X_CMD_LENGTH)
goto out;
}
data->mode = mode;
sht3x_select_command(data);
out:
mutex_unlock(&data->i2c_lock);
mutex_unlock(&data->data_lock);
if (ret != SHT3X_CMD_LENGTH)
return ret < 0 ? ret : -EIO;
return count;
}
static int sht3x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct sht3x_data *data;
struct device *hwmon_dev;
struct i2c_adapter *adap = client->adapter;
struct device *dev = &client->dev;
const struct attribute_group **attribute_groups;
if (!i2c_check_functionality(adap, I2C_FUNC_I2C))
return -ENODEV;
ret = i2c_master_send(client, sht3x_cmd_clear_status_reg,
SHT3X_CMD_LENGTH);
if (ret != SHT3X_CMD_LENGTH)
return ret < 0 ? ret : -ENODEV;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->setup.blocking_io = false;
data->setup.high_precision = true;
data->mode = 0;
data->last_update = jiffies - msecs_to_jiffies(3000);
data->client = client;
crc8_populate_msb(sht3x_crc8_table, SHT3X_CRC8_POLYNOMIAL);
if (client->dev.platform_data)
data->setup = *(struct sht3x_platform_data *)dev->platform_data;
sht3x_select_command(data);
mutex_init(&data->i2c_lock);
mutex_init(&data->data_lock);
ret = limits_update(data);
if (ret)
return ret;
if (id->driver_data == sts3x)
attribute_groups = sts3x_groups;
else
attribute_groups = sht3x_groups;
hwmon_dev = devm_hwmon_device_register_with_groups(dev,
client->name,
data,
attribute_groups);
if (IS_ERR(hwmon_dev))
dev_dbg(dev, "unable to register hwmon device\n");
return PTR_ERR_OR_ZERO(hwmon_dev);
}
