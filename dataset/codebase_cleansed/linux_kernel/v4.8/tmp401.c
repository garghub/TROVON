static int tmp401_register_to_temp(u16 reg, u8 config)
{
int temp = reg;
if (config & TMP401_CONFIG_RANGE)
temp -= 64 * 256;
return DIV_ROUND_CLOSEST(temp * 125, 32);
}
static u16 tmp401_temp_to_register(long temp, u8 config, int zbits)
{
if (config & TMP401_CONFIG_RANGE) {
temp = clamp_val(temp, -64000, 191000);
temp += 64000;
} else
temp = clamp_val(temp, 0, 127000);
return DIV_ROUND_CLOSEST(temp * (1 << (8 - zbits)), 1000) << zbits;
}
static int tmp401_update_device_reg16(struct i2c_client *client,
struct tmp401_data *data)
{
int i, j, val;
int num_regs = data->kind == tmp411 ? 6 : 4;
int num_sensors = data->kind == tmp432 ? 3 : 2;
for (i = 0; i < num_sensors; i++) {
for (j = 0; j < num_regs; j++) {
u8 regaddr;
regaddr = data->kind == tmp432 ?
TMP432_TEMP_MSB_READ[j][i] :
TMP401_TEMP_MSB_READ[j][i];
val = i2c_smbus_read_byte_data(client, regaddr);
if (val < 0)
return val;
data->temp[j][i] = val << 8;
if (j == 3)
continue;
regaddr = data->kind == tmp432 ? TMP432_TEMP_LSB[j][i]
: TMP401_TEMP_LSB[j][i];
val = i2c_smbus_read_byte_data(client, regaddr);
if (val < 0)
return val;
data->temp[j][i] |= val;
}
}
return 0;
}
static struct tmp401_data *tmp401_update_device(struct device *dev)
{
struct tmp401_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
struct tmp401_data *ret = data;
int i, val;
unsigned long next_update;
mutex_lock(&data->update_lock);
next_update = data->last_updated +
msecs_to_jiffies(data->update_interval);
if (time_after(jiffies, next_update) || !data->valid) {
if (data->kind != tmp432) {
val = i2c_smbus_read_byte_data(client, TMP401_STATUS);
if (val < 0) {
ret = ERR_PTR(val);
goto abort;
}
data->status[0] =
(val & TMP401_STATUS_REMOTE_OPEN) >> 1;
data->status[1] =
((val & TMP401_STATUS_REMOTE_LOW) >> 2) |
((val & TMP401_STATUS_LOCAL_LOW) >> 5);
data->status[2] =
((val & TMP401_STATUS_REMOTE_HIGH) >> 3) |
((val & TMP401_STATUS_LOCAL_HIGH) >> 6);
data->status[3] = val & (TMP401_STATUS_LOCAL_CRIT
| TMP401_STATUS_REMOTE_CRIT);
} else {
for (i = 0; i < ARRAY_SIZE(data->status); i++) {
val = i2c_smbus_read_byte_data(client,
TMP432_STATUS_REG[i]);
if (val < 0) {
ret = ERR_PTR(val);
goto abort;
}
data->status[i] = val;
}
}
val = i2c_smbus_read_byte_data(client, TMP401_CONFIG_READ);
if (val < 0) {
ret = ERR_PTR(val);
goto abort;
}
data->config = val;
val = tmp401_update_device_reg16(client, data);
if (val < 0) {
ret = ERR_PTR(val);
goto abort;
}
val = i2c_smbus_read_byte_data(client, TMP401_TEMP_CRIT_HYST);
if (val < 0) {
ret = ERR_PTR(val);
goto abort;
}
data->temp_crit_hyst = val;
data->last_updated = jiffies;
data->valid = 1;
}
abort:
mutex_unlock(&data->update_lock);
return ret;
}
static ssize_t show_temp(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int nr = to_sensor_dev_attr_2(devattr)->nr;
int index = to_sensor_dev_attr_2(devattr)->index;
struct tmp401_data *data = tmp401_update_device(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n",
tmp401_register_to_temp(data->temp[nr][index], data->config));
}
static ssize_t show_temp_crit_hyst(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int temp, index = to_sensor_dev_attr(devattr)->index;
struct tmp401_data *data = tmp401_update_device(dev);
if (IS_ERR(data))
return PTR_ERR(data);
mutex_lock(&data->update_lock);
temp = tmp401_register_to_temp(data->temp[3][index], data->config);
temp -= data->temp_crit_hyst * 1000;
mutex_unlock(&data->update_lock);
return sprintf(buf, "%d\n", temp);
}
static ssize_t show_status(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int nr = to_sensor_dev_attr_2(devattr)->nr;
int mask = to_sensor_dev_attr_2(devattr)->index;
struct tmp401_data *data = tmp401_update_device(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return sprintf(buf, "%d\n", !!(data->status[nr] & mask));
}
static ssize_t store_temp(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr_2(devattr)->nr;
int index = to_sensor_dev_attr_2(devattr)->index;
struct tmp401_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long val;
u16 reg;
u8 regaddr;
if (kstrtol(buf, 10, &val))
return -EINVAL;
reg = tmp401_temp_to_register(val, data->config, nr == 3 ? 8 : 4);
mutex_lock(&data->update_lock);
regaddr = data->kind == tmp432 ? TMP432_TEMP_MSB_WRITE[nr][index]
: TMP401_TEMP_MSB_WRITE[nr][index];
i2c_smbus_write_byte_data(client, regaddr, reg >> 8);
if (nr != 3) {
regaddr = data->kind == tmp432 ? TMP432_TEMP_LSB[nr][index]
: TMP401_TEMP_LSB[nr][index];
i2c_smbus_write_byte_data(client, regaddr, reg & 0xFF);
}
data->temp[nr][index] = reg;
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
if (IS_ERR(data))
return PTR_ERR(data);
if (kstrtol(buf, 10, &val))
return -EINVAL;
if (data->config & TMP401_CONFIG_RANGE)
val = clamp_val(val, -64000, 191000);
else
val = clamp_val(val, 0, 127000);
mutex_lock(&data->update_lock);
temp = tmp401_register_to_temp(data->temp[3][index], data->config);
val = clamp_val(val, temp - 255000, temp);
reg = ((temp - val) + 500) / 1000;
i2c_smbus_write_byte_data(data->client, TMP401_TEMP_CRIT_HYST,
reg);
data->temp_crit_hyst = reg;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t reset_temp_history(struct device *dev,
struct device_attribute *devattr, const char *buf, size_t count)
{
struct tmp401_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long val;
if (kstrtol(buf, 10, &val))
return -EINVAL;
if (val != 1) {
dev_err(dev,
"temp_reset_history value %ld not supported. Use 1 to reset the history!\n",
val);
return -EINVAL;
}
mutex_lock(&data->update_lock);
i2c_smbus_write_byte_data(client, TMP401_TEMP_MSB_WRITE[5][0], val);
data->valid = 0;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_update_interval(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct tmp401_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", data->update_interval);
}
static ssize_t set_update_interval(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct tmp401_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
unsigned long val;
int err, rate;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
val = clamp_val(val, 125, 16000);
rate = 7 - __fls(val * 4 / (125 * 3));
mutex_lock(&data->update_lock);
i2c_smbus_write_byte_data(client, TMP401_CONVERSION_RATE_WRITE, rate);
data->update_interval = (1 << (7 - rate)) * 125;
mutex_unlock(&data->update_lock);
return count;
}
static int tmp401_init_client(struct tmp401_data *data,
struct i2c_client *client)
{
int config, config_orig, status = 0;
i2c_smbus_write_byte_data(client, TMP401_CONVERSION_RATE_WRITE, 5);
data->update_interval = 500;
config = i2c_smbus_read_byte_data(client, TMP401_CONFIG_READ);
if (config < 0)
return config;
config_orig = config;
config &= ~TMP401_CONFIG_SHUTDOWN;
if (config != config_orig)
status = i2c_smbus_write_byte_data(client,
TMP401_CONFIG_WRITE,
config);
return status;
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
if (client->addr != 0x4c)
return -ENODEV;
kind = tmp401;
break;
case TMP411A_DEVICE_ID:
if (client->addr != 0x4c)
return -ENODEV;
kind = tmp411;
break;
case TMP411B_DEVICE_ID:
if (client->addr != 0x4d)
return -ENODEV;
kind = tmp411;
break;
case TMP411C_DEVICE_ID:
if (client->addr != 0x4e)
return -ENODEV;
kind = tmp411;
break;
case TMP431_DEVICE_ID:
if (client->addr != 0x4c && client->addr != 0x4d)
return -ENODEV;
kind = tmp431;
break;
case TMP432_DEVICE_ID:
if (client->addr != 0x4c && client->addr != 0x4d)
return -ENODEV;
kind = tmp432;
break;
case TMP435_DEVICE_ID:
kind = tmp435;
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
static int tmp401_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
static const char * const names[] = {
"TMP401", "TMP411", "TMP431", "TMP432", "TMP435", "TMP461"
};
struct device *dev = &client->dev;
struct device *hwmon_dev;
struct tmp401_data *data;
int groups = 0, status;
data = devm_kzalloc(dev, sizeof(struct tmp401_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = client;
mutex_init(&data->update_lock);
data->kind = id->driver_data;
status = tmp401_init_client(data, client);
if (status < 0)
return status;
data->groups[groups++] = &tmp401_group;
if (data->kind == tmp411)
data->groups[groups++] = &tmp411_group;
if (data->kind == tmp432)
data->groups[groups++] = &tmp432_group;
if (data->kind == tmp461)
data->groups[groups++] = &tmp461_group;
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data, data->groups);
if (IS_ERR(hwmon_dev))
return PTR_ERR(hwmon_dev);
dev_info(dev, "Detected TI %s chip\n", names[data->kind]);
return 0;
}
