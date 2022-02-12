static struct adc128_data *adc128_update_device(struct device *dev)
{
struct adc128_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
struct adc128_data *ret = data;
int i, rv;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
for (i = 0; i < 7; i++) {
rv = i2c_smbus_read_word_swapped(client,
ADC128_REG_IN(i));
if (rv < 0)
goto abort;
data->in[0][i] = rv >> 4;
rv = i2c_smbus_read_byte_data(client,
ADC128_REG_IN_MIN(i));
if (rv < 0)
goto abort;
data->in[1][i] = rv << 4;
rv = i2c_smbus_read_byte_data(client,
ADC128_REG_IN_MAX(i));
if (rv < 0)
goto abort;
data->in[2][i] = rv << 4;
}
rv = i2c_smbus_read_word_swapped(client, ADC128_REG_TEMP);
if (rv < 0)
goto abort;
data->temp[0] = rv >> 7;
rv = i2c_smbus_read_byte_data(client, ADC128_REG_TEMP_MAX);
if (rv < 0)
goto abort;
data->temp[1] = rv << 1;
rv = i2c_smbus_read_byte_data(client, ADC128_REG_TEMP_HYST);
if (rv < 0)
goto abort;
data->temp[2] = rv << 1;
rv = i2c_smbus_read_byte_data(client, ADC128_REG_ALARM);
if (rv < 0)
goto abort;
data->alarms |= rv;
data->last_updated = jiffies;
data->valid = true;
}
goto done;
abort:
ret = ERR_PTR(rv);
data->valid = false;
done:
mutex_unlock(&data->update_lock);
return ret;
}
static ssize_t adc128_show_in(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct adc128_data *data = adc128_update_device(dev);
int index = to_sensor_dev_attr_2(attr)->index;
int nr = to_sensor_dev_attr_2(attr)->nr;
int val;
if (IS_ERR(data))
return PTR_ERR(data);
val = DIV_ROUND_CLOSEST(data->in[index][nr] * data->vref, 4095);
return sprintf(buf, "%d\n", val);
}
static ssize_t adc128_set_in(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct adc128_data *data = dev_get_drvdata(dev);
int index = to_sensor_dev_attr_2(attr)->index;
int nr = to_sensor_dev_attr_2(attr)->nr;
u8 reg, regval;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err < 0)
return err;
mutex_lock(&data->update_lock);
regval = clamp_val(DIV_ROUND_CLOSEST(val, 10), 0, 255);
data->in[index][nr] = regval << 4;
reg = index == 1 ? ADC128_REG_IN_MIN(nr) : ADC128_REG_IN_MAX(nr);
i2c_smbus_write_byte_data(data->client, reg, regval);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t adc128_show_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adc128_data *data = adc128_update_device(dev);
int index = to_sensor_dev_attr(attr)->index;
int temp;
if (IS_ERR(data))
return PTR_ERR(data);
temp = (data->temp[index] << 7) >> 7;
return sprintf(buf, "%d\n", temp * 500);
}
static ssize_t adc128_set_temp(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct adc128_data *data = dev_get_drvdata(dev);
int index = to_sensor_dev_attr(attr)->index;
long val;
int err;
s8 regval;
err = kstrtol(buf, 10, &val);
if (err < 0)
return err;
mutex_lock(&data->update_lock);
regval = clamp_val(DIV_ROUND_CLOSEST(val, 1000), -128, 127);
data->temp[index] = regval << 1;
i2c_smbus_write_byte_data(data->client,
index == 1 ? ADC128_REG_TEMP_MAX
: ADC128_REG_TEMP_HYST,
regval);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t adc128_show_alarm(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adc128_data *data = adc128_update_device(dev);
int mask = 1 << to_sensor_dev_attr(attr)->index;
u8 alarms;
if (IS_ERR(data))
return PTR_ERR(data);
alarms = data->alarms;
data->alarms &= ~mask;
return sprintf(buf, "%u\n", !!(alarms & mask));
}
static int adc128_detect(struct i2c_client *client, struct i2c_board_info *info)
{
int man_id, dev_id;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
man_id = i2c_smbus_read_byte_data(client, ADC128_REG_MAN_ID);
dev_id = i2c_smbus_read_byte_data(client, ADC128_REG_DEV_ID);
if (man_id != 0x01 || dev_id != 0x09)
return -ENODEV;
if (i2c_smbus_read_byte_data(client, ADC128_REG_CONFIG) & 0xf4)
return -ENODEV;
if (i2c_smbus_read_byte_data(client, ADC128_REG_CONV_RATE) & 0xfe)
return -ENODEV;
if (i2c_smbus_read_byte_data(client, ADC128_REG_ONESHOT) & 0xfe)
return -ENODEV;
if (i2c_smbus_read_byte_data(client, ADC128_REG_SHUTDOWN) & 0xfe)
return -ENODEV;
if (i2c_smbus_read_byte_data(client, ADC128_REG_CONFIG_ADV) & 0xf8)
return -ENODEV;
if (i2c_smbus_read_byte_data(client, ADC128_REG_BUSY_STATUS) & 0xfc)
return -ENODEV;
strlcpy(info->type, "adc128d818", I2C_NAME_SIZE);
return 0;
}
static int adc128_init_client(struct adc128_data *data)
{
struct i2c_client *client = data->client;
int err;
err = i2c_smbus_write_byte_data(client, ADC128_REG_CONFIG, 0x80);
if (err)
return err;
err = i2c_smbus_write_byte_data(client, ADC128_REG_CONFIG, 0x01);
if (err)
return err;
if (data->regulator) {
err = i2c_smbus_write_byte_data(client,
ADC128_REG_CONFIG_ADV, 0x01);
if (err)
return err;
}
return 0;
}
static int adc128_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct regulator *regulator;
struct device *hwmon_dev;
struct adc128_data *data;
int err, vref;
data = devm_kzalloc(dev, sizeof(struct adc128_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
regulator = devm_regulator_get_optional(dev, "vref");
if (!IS_ERR(regulator)) {
data->regulator = regulator;
err = regulator_enable(regulator);
if (err < 0)
return err;
vref = regulator_get_voltage(regulator);
if (vref < 0) {
err = vref;
goto error;
}
data->vref = DIV_ROUND_CLOSEST(vref, 1000);
} else {
data->vref = 2560;
}
data->client = client;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
err = adc128_init_client(data);
if (err < 0)
goto error;
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data, adc128_groups);
if (IS_ERR(hwmon_dev)) {
err = PTR_ERR(hwmon_dev);
goto error;
}
return 0;
error:
if (data->regulator)
regulator_disable(data->regulator);
return err;
}
static int adc128_remove(struct i2c_client *client)
{
struct adc128_data *data = i2c_get_clientdata(client);
if (data->regulator)
regulator_disable(data->regulator);
return 0;
}
