static int powr1220_read_adc(struct device *dev, int ch_num)
{
struct powr1220_data *data = dev_get_drvdata(dev);
int reading;
int result;
int adc_range = 0;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->adc_last_updated[ch_num] + HZ) ||
!data->adc_valid[ch_num]) {
if (data->adc_maxes[ch_num] > ADC_MAX_LOW_MEASUREMENT_MV ||
data->adc_maxes[ch_num] == 0)
adc_range = 1 << 4;
result = i2c_smbus_write_byte_data(data->client, ADC_MUX,
adc_range | ch_num);
if (result)
goto exit;
udelay(200);
result = i2c_smbus_read_byte_data(data->client, ADC_VALUE_LOW);
if (result < 0)
goto exit;
reading = result >> 4;
result = i2c_smbus_read_byte_data(data->client, ADC_VALUE_HIGH);
if (result < 0)
goto exit;
reading |= result << 4;
reading *= ADC_STEP_MV;
data->adc_values[ch_num] = reading;
data->adc_valid[ch_num] = true;
data->adc_last_updated[ch_num] = jiffies;
result = reading;
if (reading > data->adc_maxes[ch_num])
data->adc_maxes[ch_num] = reading;
} else {
result = data->adc_values[ch_num];
}
exit:
mutex_unlock(&data->update_lock);
return result;
}
static ssize_t powr1220_show_voltage(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
int adc_val = powr1220_read_adc(dev, attr->index);
if (adc_val < 0)
return adc_val;
return sprintf(buf, "%d\n", adc_val);
}
static ssize_t powr1220_show_max(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
struct powr1220_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", data->adc_maxes[attr->index]);
}
static ssize_t powr1220_show_label(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(dev_attr);
return sprintf(buf, "%s\n", input_names[attr->index]);
}
static int powr1220_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct powr1220_data *data;
struct device *hwmon_dev;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
mutex_init(&data->update_lock);
data->client = client;
hwmon_dev = devm_hwmon_device_register_with_groups(&client->dev,
client->name, data, powr1220_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
