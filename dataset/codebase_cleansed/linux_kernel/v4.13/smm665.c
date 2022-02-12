static int smm665_read16(struct i2c_client *client, int reg)
{
int rv, val;
rv = i2c_smbus_read_byte_data(client, reg);
if (rv < 0)
return rv;
val = rv << 8;
rv = i2c_smbus_read_byte_data(client, reg + 1);
if (rv < 0)
return rv;
val |= rv;
return val;
}
static int smm665_read_adc(struct smm665_data *data, int adc)
{
struct i2c_client *client = data->cmdreg;
int rv;
int radc;
rv = i2c_smbus_read_byte_data(client, adc << 3);
if (rv != -ENXIO) {
dev_dbg(&client->dev,
"Unexpected return code %d when setting ADC index", rv);
return (rv < 0) ? rv : -EIO;
}
udelay(data->conversion_time);
rv = i2c_smbus_read_word_swapped(client, 0);
if (rv < 0) {
dev_dbg(&client->dev, "Failed to read ADC value: error %d", rv);
return rv;
}
radc = (rv >> 11) & 0x0f;
if (radc != adc) {
dev_dbg(&client->dev, "Unexpected RADC: Expected %d got %d",
adc, radc);
return -EIO;
}
return rv & SMM665_ADC_MASK;
}
static struct smm665_data *smm665_update_device(struct device *dev)
{
struct smm665_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
struct smm665_data *ret = data;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
int i, val;
val = smm665_read16(client, SMM665_MISC8_STATUS1);
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->faults = val;
for (i = 0; i < SMM665_NUM_ADC; i++) {
val = smm665_read_adc(data, i);
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->adc[i] = val;
}
data->last_updated = jiffies;
data->valid = 1;
}
abort:
mutex_unlock(&data->update_lock);
return ret;
}
static int smm665_convert(u16 adcval, int index)
{
int val = 0;
switch (index) {
case SMM665_MISC16_ADC_DATA_12V:
val = SMM665_12VIN_ADC_TO_VOLTS(adcval & SMM665_ADC_MASK);
break;
case SMM665_MISC16_ADC_DATA_VDD:
case SMM665_MISC16_ADC_DATA_A:
case SMM665_MISC16_ADC_DATA_B:
case SMM665_MISC16_ADC_DATA_C:
case SMM665_MISC16_ADC_DATA_D:
case SMM665_MISC16_ADC_DATA_E:
case SMM665_MISC16_ADC_DATA_F:
val = SMM665_VMON_ADC_TO_VOLTS(adcval & SMM665_ADC_MASK);
break;
case SMM665_MISC16_ADC_DATA_AIN1:
case SMM665_MISC16_ADC_DATA_AIN2:
val = SMM665_AIN_ADC_TO_VOLTS(adcval & SMM665_ADC_MASK);
break;
case SMM665_MISC16_ADC_DATA_INT_TEMP:
val = SMM665_TEMP_ADC_TO_CELSIUS(adcval & SMM665_ADC_MASK);
break;
default:
WARN_ON_ONCE(1);
break;
}
return val;
}
static int smm665_get_min(struct device *dev, int index)
{
struct smm665_data *data = dev_get_drvdata(dev);
return data->alarm_min_limit[index];
}
static int smm665_get_max(struct device *dev, int index)
{
struct smm665_data *data = dev_get_drvdata(dev);
return data->alarm_max_limit[index];
}
static int smm665_get_lcrit(struct device *dev, int index)
{
struct smm665_data *data = dev_get_drvdata(dev);
return data->critical_min_limit[index];
}
static int smm665_get_crit(struct device *dev, int index)
{
struct smm665_data *data = dev_get_drvdata(dev);
return data->critical_max_limit[index];
}
static ssize_t smm665_show_crit_alarm(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct smm665_data *data = smm665_update_device(dev);
int val = 0;
if (IS_ERR(data))
return PTR_ERR(data);
if (data->faults & (1 << attr->index))
val = 1;
return snprintf(buf, PAGE_SIZE, "%d\n", val);
}
static ssize_t smm665_show_input(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct smm665_data *data = smm665_update_device(dev);
int adc = attr->index;
int val;
if (IS_ERR(data))
return PTR_ERR(data);
val = smm665_convert(data->adc[adc], adc);
return snprintf(buf, PAGE_SIZE, "%d\n", val);
}
static int smm665_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct smm665_data *data;
struct device *hwmon_dev;
int i, ret;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA
| I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
if (i2c_smbus_read_byte_data(client, SMM665_ADOC_ENABLE) < 0)
return -ENODEV;
data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
data->client = client;
data->type = id->driver_data;
data->cmdreg = i2c_new_dummy(adapter, (client->addr & ~SMM665_REGMASK)
| SMM665_CMDREG_BASE);
if (!data->cmdreg)
return -ENOMEM;
switch (data->type) {
case smm465:
case smm665:
data->conversion_time = SMM665_ADC_WAIT_SMM665;
break;
case smm665c:
case smm764:
case smm766:
data->conversion_time = SMM665_ADC_WAIT_SMM766;
break;
}
ret = -ENODEV;
if (i2c_smbus_read_byte_data(data->cmdreg, SMM665_MISC8_CMD_STS) < 0)
goto out_unregister;
for (i = 0; i < SMM665_NUM_ADC; i++) {
int val;
val = smm665_read16(client, SMM665_LIMIT_BASE + i * 8);
if (unlikely(val < 0))
goto out_unregister;
data->critical_min_limit[i] = data->alarm_min_limit[i]
= smm665_convert(val, i);
val = smm665_read16(client, SMM665_LIMIT_BASE + i * 8 + 2);
if (unlikely(val < 0))
goto out_unregister;
if (smm665_is_critical(val))
data->critical_min_limit[i] = smm665_convert(val, i);
else
data->alarm_min_limit[i] = smm665_convert(val, i);
val = smm665_read16(client, SMM665_LIMIT_BASE + i * 8 + 4);
if (unlikely(val < 0))
goto out_unregister;
data->critical_max_limit[i] = data->alarm_max_limit[i]
= smm665_convert(val, i);
val = smm665_read16(client, SMM665_LIMIT_BASE + i * 8 + 6);
if (unlikely(val < 0))
goto out_unregister;
if (smm665_is_critical(val))
data->critical_max_limit[i] = smm665_convert(val, i);
else
data->alarm_max_limit[i] = smm665_convert(val, i);
}
hwmon_dev = devm_hwmon_device_register_with_groups(&client->dev,
client->name, data,
smm665_groups);
if (IS_ERR(hwmon_dev)) {
ret = PTR_ERR(hwmon_dev);
goto out_unregister;
}
return 0;
out_unregister:
i2c_unregister_device(data->cmdreg);
return ret;
}
static int smm665_remove(struct i2c_client *client)
{
struct smm665_data *data = i2c_get_clientdata(client);
i2c_unregister_device(data->cmdreg);
return 0;
}
