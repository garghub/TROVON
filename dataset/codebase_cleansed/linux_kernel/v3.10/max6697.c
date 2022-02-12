static struct max6697_data *max6697_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct max6697_data *data = i2c_get_clientdata(client);
struct max6697_data *ret = data;
int val;
int i;
u32 alarms;
mutex_lock(&data->update_lock);
if (data->valid &&
!time_after(jiffies, data->last_updated
+ msecs_to_jiffies(data->update_interval)))
goto abort;
for (i = 0; i < data->chip->channels; i++) {
if (data->chip->have_ext & (1 << i)) {
val = i2c_smbus_read_byte_data(client,
MAX6697_REG_TEMP_EXT[i]);
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->temp[i][MAX6697_TEMP_EXT] = val;
}
val = i2c_smbus_read_byte_data(client, MAX6697_REG_TEMP[i]);
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->temp[i][MAX6697_TEMP_INPUT] = val;
val = i2c_smbus_read_byte_data(client, MAX6697_REG_MAX[i]);
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->temp[i][MAX6697_TEMP_MAX] = val;
if (data->chip->have_crit & (1 << i)) {
val = i2c_smbus_read_byte_data(client,
MAX6697_REG_CRIT[i]);
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->temp[i][MAX6697_TEMP_CRIT] = val;
}
}
alarms = 0;
for (i = 0; i < 3; i++) {
val = i2c_smbus_read_byte_data(client, MAX6697_REG_STAT(i));
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
alarms = (alarms << 8) | val;
}
data->alarms = alarms;
data->last_updated = jiffies;
data->valid = true;
abort:
mutex_unlock(&data->update_lock);
return ret;
}
static ssize_t show_temp_input(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct max6697_data *data = max6697_update_device(dev);
int temp;
if (IS_ERR(data))
return PTR_ERR(data);
temp = (data->temp[index][MAX6697_TEMP_INPUT] - data->temp_offset) << 3;
temp |= data->temp[index][MAX6697_TEMP_EXT] >> 5;
return sprintf(buf, "%d\n", temp * 125);
}
static ssize_t show_temp(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int nr = to_sensor_dev_attr_2(devattr)->nr;
int index = to_sensor_dev_attr_2(devattr)->index;
struct max6697_data *data = max6697_update_device(dev);
int temp;
if (IS_ERR(data))
return PTR_ERR(data);
temp = data->temp[nr][index];
temp -= data->temp_offset;
return sprintf(buf, "%d\n", temp * 1000);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int index = to_sensor_dev_attr(attr)->index;
struct max6697_data *data = max6697_update_device(dev);
if (IS_ERR(data))
return PTR_ERR(data);
if (data->chip->alarm_map)
index = data->chip->alarm_map[index];
return sprintf(buf, "%u\n", (data->alarms >> index) & 0x1);
}
static ssize_t set_temp(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr_2(devattr)->nr;
int index = to_sensor_dev_attr_2(devattr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct max6697_data *data = i2c_get_clientdata(client);
long temp;
int ret;
ret = kstrtol(buf, 10, &temp);
if (ret < 0)
return ret;
mutex_lock(&data->update_lock);
temp = DIV_ROUND_CLOSEST(temp, 1000) + data->temp_offset;
temp = clamp_val(temp, 0, data->type == max6581 ? 255 : 127);
data->temp[nr][index] = temp;
ret = i2c_smbus_write_byte_data(client,
index == 2 ? MAX6697_REG_MAX[nr]
: MAX6697_REG_CRIT[nr],
temp);
mutex_unlock(&data->update_lock);
return ret < 0 ? ret : count;
}
static umode_t max6697_is_visible(struct kobject *kobj, struct attribute *attr,
int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct i2c_client *client = to_i2c_client(dev);
struct max6697_data *data = i2c_get_clientdata(client);
const struct max6697_chip_data *chip = data->chip;
int channel = index / 6;
int nr = index % 6;
if (channel >= chip->channels)
return 0;
if ((nr == 3 || nr == 4) && !(chip->have_crit & (1 << channel)))
return 0;
if (nr == 5 && !(chip->have_fault & (1 << channel)))
return 0;
return attr->mode;
}
static void max6697_get_config_of(struct device_node *node,
struct max6697_platform_data *pdata)
{
int len;
const __be32 *prop;
prop = of_get_property(node, "smbus-timeout-disable", &len);
if (prop)
pdata->smbus_timeout_disable = true;
prop = of_get_property(node, "extended-range-enable", &len);
if (prop)
pdata->extended_range_enable = true;
prop = of_get_property(node, "beta-compensation-enable", &len);
if (prop)
pdata->beta_compensation = true;
prop = of_get_property(node, "alert-mask", &len);
if (prop && len == sizeof(u32))
pdata->alert_mask = be32_to_cpu(prop[0]);
prop = of_get_property(node, "over-temperature-mask", &len);
if (prop && len == sizeof(u32))
pdata->over_temperature_mask = be32_to_cpu(prop[0]);
prop = of_get_property(node, "resistance-cancellation", &len);
if (prop) {
if (len == sizeof(u32))
pdata->resistance_cancellation = be32_to_cpu(prop[0]);
else
pdata->resistance_cancellation = 0xfe;
}
prop = of_get_property(node, "transistor-ideality", &len);
if (prop && len == 2 * sizeof(u32)) {
pdata->ideality_mask = be32_to_cpu(prop[0]);
pdata->ideality_value = be32_to_cpu(prop[1]);
}
}
static int max6697_init_chip(struct i2c_client *client)
{
struct max6697_data *data = i2c_get_clientdata(client);
struct max6697_platform_data *pdata = dev_get_platdata(&client->dev);
struct max6697_platform_data p;
const struct max6697_chip_data *chip = data->chip;
int factor = chip->channels;
int ret, reg;
if (!pdata && !client->dev.of_node) {
reg = i2c_smbus_read_byte_data(client, MAX6697_REG_CONFIG);
if (reg < 0)
return reg;
if (data->type == max6581) {
if (reg & MAX6581_CONF_EXTENDED)
data->temp_offset = 64;
reg = i2c_smbus_read_byte_data(client,
MAX6581_REG_RESISTANCE);
if (reg < 0)
return reg;
factor += hweight8(reg);
} else {
if (reg & MAX6697_CONF_RESISTANCE)
factor++;
}
goto done;
}
if (client->dev.of_node) {
memset(&p, 0, sizeof(p));
max6697_get_config_of(client->dev.of_node, &p);
pdata = &p;
}
reg = 0;
if (pdata->smbus_timeout_disable &&
(chip->valid_conf & MAX6697_CONF_TIMEOUT)) {
reg |= MAX6697_CONF_TIMEOUT;
}
if (pdata->extended_range_enable &&
(chip->valid_conf & MAX6581_CONF_EXTENDED)) {
reg |= MAX6581_CONF_EXTENDED;
data->temp_offset = 64;
}
if (pdata->resistance_cancellation &&
(chip->valid_conf & MAX6697_CONF_RESISTANCE)) {
reg |= MAX6697_CONF_RESISTANCE;
factor++;
}
if (pdata->beta_compensation &&
(chip->valid_conf & MAX6693_CONF_BETA)) {
reg |= MAX6693_CONF_BETA;
}
ret = i2c_smbus_write_byte_data(client, MAX6697_REG_CONFIG, reg);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, MAX6697_REG_ALERT_MASK,
MAX6697_MAP_BITS(pdata->alert_mask));
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, MAX6697_REG_OVERT_MASK,
MAX6697_MAP_BITS(pdata->over_temperature_mask));
if (ret < 0)
return ret;
if (data->type == max6581) {
factor += hweight8(pdata->resistance_cancellation >> 1);
ret = i2c_smbus_write_byte_data(client, MAX6581_REG_RESISTANCE,
pdata->resistance_cancellation >> 1);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, MAX6581_REG_IDEALITY,
pdata->ideality_mask >> 1);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client,
MAX6581_REG_IDEALITY_SELECT,
pdata->ideality_value);
if (ret < 0)
return ret;
}
done:
data->update_interval = factor * MAX6697_CONV_TIME;
return 0;
}
static int max6697_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct device *dev = &client->dev;
struct max6697_data *data;
int err;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
data = devm_kzalloc(dev, sizeof(struct max6697_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->type = id->driver_data;
data->chip = &max6697_chip_data[data->type];
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
err = max6697_init_chip(client);
if (err)
return err;
err = sysfs_create_group(&client->dev.kobj, &max6697_group);
if (err)
return err;
data->hwmon_dev = hwmon_device_register(dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto error;
}
return 0;
error:
sysfs_remove_group(&client->dev.kobj, &max6697_group);
return err;
}
static int max6697_remove(struct i2c_client *client)
{
struct max6697_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &max6697_group);
return 0;
}
