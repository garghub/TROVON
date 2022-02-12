static struct thmc50_data *thmc50_update_device(struct device *dev)
{
struct thmc50_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int timeout = HZ / 5 + (data->type == thmc50 ? HZ : 0);
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + timeout)
|| !data->valid) {
int temps = data->has_temp3 ? 3 : 2;
int i;
int prog = i2c_smbus_read_byte_data(client, THMC50_REG_CONF);
prog &= THMC50_REG_CONF_PROGRAMMED;
for (i = 0; i < temps; i++) {
data->temp_input[i] = i2c_smbus_read_byte_data(client,
THMC50_REG_TEMP[i]);
data->temp_max[i] = i2c_smbus_read_byte_data(client,
THMC50_REG_TEMP_MAX[i]);
data->temp_min[i] = i2c_smbus_read_byte_data(client,
THMC50_REG_TEMP_MIN[i]);
data->temp_critical[i] =
i2c_smbus_read_byte_data(client,
prog ? THMC50_REG_TEMP_CRITICAL[i]
: THMC50_REG_TEMP_DEFAULT[i]);
}
data->analog_out =
i2c_smbus_read_byte_data(client, THMC50_REG_ANALOG_OUT);
data->alarms =
i2c_smbus_read_byte_data(client, THMC50_REG_INTR);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t show_analog_out(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct thmc50_data *data = thmc50_update_device(dev);
return sprintf(buf, "%d\n", data->analog_out);
}
static ssize_t set_analog_out(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct thmc50_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int config;
unsigned long tmp;
int err;
err = kstrtoul(buf, 10, &tmp);
if (err)
return err;
mutex_lock(&data->update_lock);
data->analog_out = clamp_val(tmp, 0, 255);
i2c_smbus_write_byte_data(client, THMC50_REG_ANALOG_OUT,
data->analog_out);
config = i2c_smbus_read_byte_data(client, THMC50_REG_CONF);
if (data->analog_out == 0)
config &= ~THMC50_REG_CONF_nFANOFF;
else
config |= THMC50_REG_CONF_nFANOFF;
i2c_smbus_write_byte_data(client, THMC50_REG_CONF, config);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_mode(struct device *dev, struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "0\n");
}
static ssize_t show_temp(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct thmc50_data *data = thmc50_update_device(dev);
return sprintf(buf, "%d\n", data->temp_input[nr] * 1000);
}
static ssize_t show_temp_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct thmc50_data *data = thmc50_update_device(dev);
return sprintf(buf, "%d\n", data->temp_min[nr] * 1000);
}
static ssize_t set_temp_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct thmc50_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_min[nr] = clamp_val(val / 1000, -128, 127);
i2c_smbus_write_byte_data(client, THMC50_REG_TEMP_MIN[nr],
data->temp_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct thmc50_data *data = thmc50_update_device(dev);
return sprintf(buf, "%d\n", data->temp_max[nr] * 1000);
}
static ssize_t set_temp_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct thmc50_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_max[nr] = clamp_val(val / 1000, -128, 127);
i2c_smbus_write_byte_data(client, THMC50_REG_TEMP_MAX[nr],
data->temp_max[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_critical(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct thmc50_data *data = thmc50_update_device(dev);
return sprintf(buf, "%d\n", data->temp_critical[nr] * 1000);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int index = to_sensor_dev_attr(attr)->index;
struct thmc50_data *data = thmc50_update_device(dev);
return sprintf(buf, "%u\n", (data->alarms >> index) & 1);
}
static int thmc50_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
unsigned company;
unsigned revision;
unsigned config;
struct i2c_adapter *adapter = client->adapter;
const char *type_name;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
pr_debug("thmc50: detect failed, smbus byte data not supported!\n");
return -ENODEV;
}
pr_debug("thmc50: Probing for THMC50 at 0x%2X on bus %d\n",
client->addr, i2c_adapter_id(client->adapter));
company = i2c_smbus_read_byte_data(client, THMC50_REG_COMPANY_ID);
revision = i2c_smbus_read_byte_data(client, THMC50_REG_DIE_CODE);
config = i2c_smbus_read_byte_data(client, THMC50_REG_CONF);
if (revision < 0xc0 || (config & 0x10))
return -ENODEV;
if (company == 0x41) {
int id = i2c_adapter_id(client->adapter);
int i;
type_name = "adm1022";
for (i = 0; i + 1 < adm1022_temp3_num; i += 2)
if (adm1022_temp3[i] == id &&
adm1022_temp3[i + 1] == client->addr) {
config |= (1 << 7);
i2c_smbus_write_byte_data(client,
THMC50_REG_CONF,
config);
break;
}
} else if (company == 0x49) {
type_name = "thmc50";
} else {
pr_debug("thmc50: Detection of THMC50/ADM1022 failed\n");
return -ENODEV;
}
pr_debug("thmc50: Detected %s (version %x, revision %x)\n",
type_name, (revision >> 4) - 0xc, revision & 0xf);
strlcpy(info->type, type_name, I2C_NAME_SIZE);
return 0;
}
static void thmc50_init_client(struct thmc50_data *data)
{
struct i2c_client *client = data->client;
int config;
data->analog_out = i2c_smbus_read_byte_data(client,
THMC50_REG_ANALOG_OUT);
if (data->analog_out == 0) {
data->analog_out = 1;
i2c_smbus_write_byte_data(client, THMC50_REG_ANALOG_OUT,
data->analog_out);
}
config = i2c_smbus_read_byte_data(client, THMC50_REG_CONF);
config |= 0x1;
if (data->type == adm1022 && (config & (1 << 7)))
data->has_temp3 = 1;
i2c_smbus_write_byte_data(client, THMC50_REG_CONF, config);
}
static int thmc50_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct thmc50_data *data;
struct device *hwmon_dev;
int idx = 0;
data = devm_kzalloc(dev, sizeof(struct thmc50_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = client;
data->type = id->driver_data;
mutex_init(&data->update_lock);
thmc50_init_client(data);
data->groups[idx++] = &thmc50_group;
if (data->has_temp3)
data->groups[idx++] = &temp3_group;
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data, data->groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
