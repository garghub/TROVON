static int lm95234_read_temp(struct i2c_client *client, int index, int *t)
{
int val;
u16 temp = 0;
if (index) {
val = i2c_smbus_read_byte_data(client,
LM95234_REG_UTEMPH(index - 1));
if (val < 0)
return val;
temp = val << 8;
val = i2c_smbus_read_byte_data(client,
LM95234_REG_UTEMPL(index - 1));
if (val < 0)
return val;
temp |= val;
*t = temp;
}
if (!temp) {
val = i2c_smbus_read_byte_data(client,
LM95234_REG_TEMPH(index));
if (val < 0)
return val;
temp = val << 8;
val = i2c_smbus_read_byte_data(client,
LM95234_REG_TEMPL(index));
if (val < 0)
return val;
temp |= val;
*t = (s16)temp;
}
return 0;
}
static int lm95234_fill_cache(struct i2c_client *client)
{
struct lm95234_data *data = i2c_get_clientdata(client);
int i, ret;
ret = i2c_smbus_read_byte_data(client, LM95234_REG_CONVRATE);
if (ret < 0)
return ret;
data->interval = msecs_to_jiffies(update_intervals[ret & 0x03]);
for (i = 0; i < ARRAY_SIZE(data->tcrit1); i++) {
ret = i2c_smbus_read_byte_data(client, LM95234_REG_TCRIT1(i));
if (ret < 0)
return ret;
data->tcrit1[i] = ret;
}
for (i = 0; i < ARRAY_SIZE(data->tcrit2); i++) {
ret = i2c_smbus_read_byte_data(client, LM95234_REG_TCRIT2(i));
if (ret < 0)
return ret;
data->tcrit2[i] = ret;
}
for (i = 0; i < ARRAY_SIZE(data->toffset); i++) {
ret = i2c_smbus_read_byte_data(client, LM95234_REG_OFFSET(i));
if (ret < 0)
return ret;
data->toffset[i] = ret;
}
ret = i2c_smbus_read_byte_data(client, LM95234_REG_TCRIT_HYST);
if (ret < 0)
return ret;
data->thyst = ret;
ret = i2c_smbus_read_byte_data(client, LM95234_REG_REM_MODEL);
if (ret < 0)
return ret;
data->sensor_type = ret;
return 0;
}
static int lm95234_update_device(struct i2c_client *client,
struct lm95234_data *data)
{
int ret;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + data->interval) ||
!data->valid) {
int i;
if (!data->valid) {
ret = lm95234_fill_cache(client);
if (ret < 0)
goto abort;
}
data->valid = false;
for (i = 0; i < ARRAY_SIZE(data->temp); i++) {
ret = lm95234_read_temp(client, i, &data->temp[i]);
if (ret < 0)
goto abort;
}
ret = i2c_smbus_read_byte_data(client, LM95234_REG_STS_FAULT);
if (ret < 0)
goto abort;
data->status = ret;
ret = i2c_smbus_read_byte_data(client, LM95234_REG_STS_TCRIT1);
if (ret < 0)
goto abort;
data->status |= ret << 8;
ret = i2c_smbus_read_byte_data(client, LM95234_REG_STS_TCRIT2);
if (ret < 0)
goto abort;
data->status |= ret << 16;
data->last_updated = jiffies;
data->valid = true;
}
ret = 0;
abort:
mutex_unlock(&data->update_lock);
return ret;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95234_data *data = i2c_get_clientdata(client);
int index = to_sensor_dev_attr(attr)->index;
int ret = lm95234_update_device(client, data);
if (ret)
return ret;
return sprintf(buf, "%d\n",
DIV_ROUND_CLOSEST(data->temp[index] * 125, 32));
}
static ssize_t show_alarm(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95234_data *data = i2c_get_clientdata(client);
u32 mask = to_sensor_dev_attr(attr)->index;
int ret = lm95234_update_device(client, data);
if (ret)
return ret;
return sprintf(buf, "%u", !!(data->status & mask));
}
static ssize_t show_type(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95234_data *data = i2c_get_clientdata(client);
u8 mask = to_sensor_dev_attr(attr)->index;
int ret = lm95234_update_device(client, data);
if (ret)
return ret;
return sprintf(buf, data->sensor_type & mask ? "1\n" : "2\n");
}
static ssize_t set_type(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95234_data *data = i2c_get_clientdata(client);
unsigned long val;
u8 mask = to_sensor_dev_attr(attr)->index;
int ret = lm95234_update_device(client, data);
if (ret)
return ret;
ret = kstrtoul(buf, 10, &val);
if (ret < 0)
return ret;
if (val != 1 && val != 2)
return -EINVAL;
mutex_lock(&data->update_lock);
if (val == 1)
data->sensor_type |= mask;
else
data->sensor_type &= ~mask;
data->valid = false;
i2c_smbus_write_byte_data(client, LM95234_REG_REM_MODEL,
data->sensor_type);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_tcrit2(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95234_data *data = i2c_get_clientdata(client);
int index = to_sensor_dev_attr(attr)->index;
int ret = lm95234_update_device(client, data);
if (ret)
return ret;
return sprintf(buf, "%u", data->tcrit2[index] * 1000);
}
static ssize_t set_tcrit2(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95234_data *data = i2c_get_clientdata(client);
int index = to_sensor_dev_attr(attr)->index;
long val;
int ret = lm95234_update_device(client, data);
if (ret)
return ret;
ret = kstrtol(buf, 10, &val);
if (ret < 0)
return ret;
val = clamp_val(DIV_ROUND_CLOSEST(val, 1000), 0, index ? 255 : 127);
mutex_lock(&data->update_lock);
data->tcrit2[index] = val;
i2c_smbus_write_byte_data(client, LM95234_REG_TCRIT2(index), val);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_tcrit2_hyst(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95234_data *data = i2c_get_clientdata(client);
int index = to_sensor_dev_attr(attr)->index;
int ret = lm95234_update_device(client, data);
if (ret)
return ret;
return sprintf(buf, "%d",
((int)data->tcrit2[index] - (int)data->thyst) * 1000);
}
static ssize_t show_tcrit1(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95234_data *data = i2c_get_clientdata(client);
int index = to_sensor_dev_attr(attr)->index;
return sprintf(buf, "%u", data->tcrit1[index] * 1000);
}
static ssize_t set_tcrit1(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95234_data *data = i2c_get_clientdata(client);
int index = to_sensor_dev_attr(attr)->index;
long val;
int ret = lm95234_update_device(client, data);
if (ret)
return ret;
ret = kstrtol(buf, 10, &val);
if (ret < 0)
return ret;
val = clamp_val(DIV_ROUND_CLOSEST(val, 1000), 0, 255);
mutex_lock(&data->update_lock);
data->tcrit1[index] = val;
i2c_smbus_write_byte_data(client, LM95234_REG_TCRIT1(index), val);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_tcrit1_hyst(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95234_data *data = i2c_get_clientdata(client);
int index = to_sensor_dev_attr(attr)->index;
int ret = lm95234_update_device(client, data);
if (ret)
return ret;
return sprintf(buf, "%d",
((int)data->tcrit1[index] - (int)data->thyst) * 1000);
}
static ssize_t set_tcrit1_hyst(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95234_data *data = i2c_get_clientdata(client);
int index = to_sensor_dev_attr(attr)->index;
long val;
int ret = lm95234_update_device(client, data);
if (ret)
return ret;
ret = kstrtol(buf, 10, &val);
if (ret < 0)
return ret;
val = DIV_ROUND_CLOSEST(val, 1000);
val = clamp_val((int)data->tcrit1[index] - val, 0, 31);
mutex_lock(&data->update_lock);
data->thyst = val;
i2c_smbus_write_byte_data(client, LM95234_REG_TCRIT_HYST, val);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_offset(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95234_data *data = i2c_get_clientdata(client);
int index = to_sensor_dev_attr(attr)->index;
int ret = lm95234_update_device(client, data);
if (ret)
return ret;
return sprintf(buf, "%d", data->toffset[index] * 500);
}
static ssize_t set_offset(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95234_data *data = i2c_get_clientdata(client);
int index = to_sensor_dev_attr(attr)->index;
long val;
int ret = lm95234_update_device(client, data);
if (ret)
return ret;
ret = kstrtol(buf, 10, &val);
if (ret < 0)
return ret;
val = clamp_val(DIV_ROUND_CLOSEST(val, 500), -128, 127);
mutex_lock(&data->update_lock);
data->toffset[index] = val;
i2c_smbus_write_byte_data(client, LM95234_REG_OFFSET(index), val);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_interval(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95234_data *data = i2c_get_clientdata(client);
int ret = lm95234_update_device(client, data);
if (ret)
return ret;
return sprintf(buf, "%lu\n",
DIV_ROUND_CLOSEST(data->interval * 1000, HZ));
}
static ssize_t set_interval(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95234_data *data = i2c_get_clientdata(client);
unsigned long val;
u8 regval;
int ret = lm95234_update_device(client, data);
if (ret)
return ret;
ret = kstrtoul(buf, 10, &val);
if (ret < 0)
return ret;
for (regval = 0; regval < 3; regval++) {
if (val <= update_intervals[regval])
break;
}
mutex_lock(&data->update_lock);
data->interval = msecs_to_jiffies(update_intervals[regval]);
i2c_smbus_write_byte_data(client, LM95234_REG_CONVRATE, regval);
mutex_unlock(&data->update_lock);
return count;
}
static int lm95234_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int mfg_id, chip_id, val;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
mfg_id = i2c_smbus_read_byte_data(client, LM95234_REG_MAN_ID);
if (mfg_id != NATSEMI_MAN_ID)
return -ENODEV;
chip_id = i2c_smbus_read_byte_data(client, LM95234_REG_CHIP_ID);
if (chip_id != LM95234_CHIP_ID)
return -ENODEV;
val = i2c_smbus_read_byte_data(client, LM95234_REG_STATUS);
if (val & 0x30)
return -ENODEV;
val = i2c_smbus_read_byte_data(client, LM95234_REG_CONFIG);
if (val & 0xbc)
return -ENODEV;
val = i2c_smbus_read_byte_data(client, LM95234_REG_CONVRATE);
if (val & 0xfc)
return -ENODEV;
val = i2c_smbus_read_byte_data(client, LM95234_REG_REM_MODEL);
if (val & 0xe1)
return -ENODEV;
val = i2c_smbus_read_byte_data(client, LM95234_REG_REM_MODEL_STS);
if (val & 0xe1)
return -ENODEV;
strlcpy(info->type, "lm95234", I2C_NAME_SIZE);
return 0;
}
static int lm95234_init_client(struct i2c_client *client)
{
int val, model;
val = i2c_smbus_read_byte_data(client, LM95234_REG_CONFIG);
if (val < 0)
return val;
if (val & 0x40)
i2c_smbus_write_byte_data(client, LM95234_REG_CONFIG,
val & ~0x40);
val = i2c_smbus_read_byte_data(client, LM95234_REG_REM_MODEL_STS);
if (val < 0)
return val;
model = i2c_smbus_read_byte_data(client, LM95234_REG_REM_MODEL);
if (model < 0)
return model;
if (model & val) {
dev_notice(&client->dev,
"Fixing remote diode type misconfiguration (0x%x)\n",
val);
i2c_smbus_write_byte_data(client, LM95234_REG_REM_MODEL,
model & ~val);
}
return 0;
}
static int lm95234_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct lm95234_data *data;
int err;
data = devm_kzalloc(dev, sizeof(struct lm95234_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
err = lm95234_init_client(client);
if (err < 0)
return err;
err = sysfs_create_group(&dev->kobj, &lm95234_group);
if (err)
return err;
data->hwmon_dev = hwmon_device_register(dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
return 0;
exit_remove_files:
sysfs_remove_group(&dev->kobj, &lm95234_group);
return err;
}
static int lm95234_remove(struct i2c_client *client)
{
struct lm95234_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &lm95234_group);
return 0;
}
