static inline int ADC_TO_MV(int adc, int range)
{
return (adc * range) / 1024;
}
static inline int LIMIT_TO_MV(int limit, int range)
{
return limit * range / 256;
}
static inline int MV_TO_LIMIT(int mv, int range)
{
return SENSORS_LIMIT(DIV_ROUND_CLOSEST(mv * 256, range), 0, 255);
}
static inline int ADC_TO_CURR(int adc, int gain)
{
return adc * 1400000 / gain * 255;
}
static int max16065_read_adc(struct i2c_client *client, int reg)
{
int rv;
rv = i2c_smbus_read_word_data(client, reg);
if (unlikely(rv < 0))
return rv;
return ((rv & 0xff) << 2) | ((rv >> 14) & 0x03);
}
static struct max16065_data *max16065_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct max16065_data *data = i2c_get_clientdata(client);
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
int i;
for (i = 0; i < data->num_adc; i++)
data->adc[i]
= max16065_read_adc(client, MAX16065_ADC(i));
if (data->have_current) {
data->adc[MAX16065_NUM_ADC]
= max16065_read_adc(client, MAX16065_CSP_ADC);
data->curr_sense
= i2c_smbus_read_byte_data(client,
MAX16065_CURR_SENSE);
}
for (i = 0; i < DIV_ROUND_UP(data->num_adc, 8); i++)
data->fault[i]
= i2c_smbus_read_byte_data(client, MAX16065_FAULT(i));
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t max16065_show_alarm(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute_2 *attr2 = to_sensor_dev_attr_2(da);
struct max16065_data *data = max16065_update_device(dev);
int val = data->fault[attr2->nr];
if (val < 0)
return val;
val &= (1 << attr2->index);
if (val)
i2c_smbus_write_byte_data(to_i2c_client(dev),
MAX16065_FAULT(attr2->nr), val);
return snprintf(buf, PAGE_SIZE, "%d\n", !!val);
}
static ssize_t max16065_show_input(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct max16065_data *data = max16065_update_device(dev);
int adc = data->adc[attr->index];
if (unlikely(adc < 0))
return adc;
return snprintf(buf, PAGE_SIZE, "%d\n",
ADC_TO_MV(adc, data->range[attr->index]));
}
static ssize_t max16065_show_current(struct device *dev,
struct device_attribute *da, char *buf)
{
struct max16065_data *data = max16065_update_device(dev);
if (unlikely(data->curr_sense < 0))
return data->curr_sense;
return snprintf(buf, PAGE_SIZE, "%d\n",
ADC_TO_CURR(data->curr_sense, data->curr_gain));
}
static ssize_t max16065_set_limit(struct device *dev,
struct device_attribute *da,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *attr2 = to_sensor_dev_attr_2(da);
struct i2c_client *client = to_i2c_client(dev);
struct max16065_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
int limit;
err = strict_strtoul(buf, 10, &val);
if (unlikely(err < 0))
return err;
limit = MV_TO_LIMIT(val, data->range[attr2->index]);
mutex_lock(&data->update_lock);
data->limit[attr2->nr][attr2->index]
= LIMIT_TO_MV(limit, data->range[attr2->index]);
i2c_smbus_write_byte_data(client,
MAX16065_LIMIT(attr2->nr, attr2->index),
limit);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t max16065_show_limit(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute_2 *attr2 = to_sensor_dev_attr_2(da);
struct i2c_client *client = to_i2c_client(dev);
struct max16065_data *data = i2c_get_clientdata(client);
return snprintf(buf, PAGE_SIZE, "%d\n",
data->limit[attr2->nr][attr2->index]);
}
static void max16065_cleanup(struct i2c_client *client)
{
sysfs_remove_group(&client->dev.kobj, &max16065_max_group);
sysfs_remove_group(&client->dev.kobj, &max16065_min_group);
sysfs_remove_group(&client->dev.kobj, &max16065_current_group);
sysfs_remove_group(&client->dev.kobj, &max16065_basic_group);
}
static int max16065_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct max16065_data *data;
int i, j, val, ret;
bool have_secondary;
bool secondary_is_max = false;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA
| I2C_FUNC_SMBUS_READ_WORD_DATA))
return -ENODEV;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (unlikely(!data))
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
data->num_adc = max16065_num_adc[id->driver_data];
data->have_current = max16065_have_current[id->driver_data];
have_secondary = max16065_have_secondary[id->driver_data];
if (have_secondary) {
val = i2c_smbus_read_byte_data(client, MAX16065_SW_ENABLE);
if (unlikely(val < 0)) {
ret = val;
goto out_free;
}
secondary_is_max = val & MAX16065_WARNING_OV;
}
for (i = 0; i < DIV_ROUND_UP(data->num_adc, 4); i++) {
val = i2c_smbus_read_byte_data(client, MAX16065_SCALE(i));
if (unlikely(val < 0)) {
ret = val;
goto out_free;
}
for (j = 0; j < 4 && i * 4 + j < data->num_adc; j++) {
data->range[i * 4 + j] =
max16065_adc_range[(val >> (j * 2)) & 0x3];
}
}
for (i = 0; i < MAX16065_NUM_LIMIT; i++) {
if (i == 0 && !have_secondary)
continue;
for (j = 0; j < data->num_adc; j++) {
val = i2c_smbus_read_byte_data(client,
MAX16065_LIMIT(i, j));
if (unlikely(val < 0)) {
ret = val;
goto out_free;
}
data->limit[i][j] = LIMIT_TO_MV(val, data->range[j]);
}
}
for (i = 0; i < data->num_adc * 4; i++) {
if (!data->range[i / 4])
continue;
ret = sysfs_create_file(&client->dev.kobj,
max16065_basic_attributes[i]);
if (unlikely(ret))
goto out;
}
if (have_secondary) {
struct attribute **attr = secondary_is_max ?
max16065_max_attributes : max16065_min_attributes;
for (i = 0; i < data->num_adc; i++) {
if (!data->range[i])
continue;
ret = sysfs_create_file(&client->dev.kobj, attr[i]);
if (unlikely(ret))
goto out;
}
}
if (data->have_current) {
val = i2c_smbus_read_byte_data(client, MAX16065_CURR_CONTROL);
if (unlikely(val < 0)) {
ret = val;
goto out;
}
if (val & MAX16065_CURR_ENABLE) {
data->curr_gain = 6 << ((val >> 2) & 0x03);
data->range[MAX16065_NUM_ADC]
= max16065_csp_adc_range[(val >> 1) & 0x01];
ret = sysfs_create_group(&client->dev.kobj,
&max16065_current_group);
if (unlikely(ret))
goto out;
} else {
data->have_current = false;
}
}
data->hwmon_dev = hwmon_device_register(&client->dev);
if (unlikely(IS_ERR(data->hwmon_dev))) {
ret = PTR_ERR(data->hwmon_dev);
goto out;
}
return 0;
out:
max16065_cleanup(client);
out_free:
kfree(data);
return ret;
}
static int max16065_remove(struct i2c_client *client)
{
struct max16065_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
max16065_cleanup(client);
kfree(data);
return 0;
}
static int __init max16065_init(void)
{
return i2c_add_driver(&max16065_driver);
}
static void __exit max16065_exit(void)
{
i2c_del_driver(&max16065_driver);
}
