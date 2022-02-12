static inline int lm87_read_value(struct i2c_client *client, u8 reg)
{
return i2c_smbus_read_byte_data(client, reg);
}
static inline int lm87_write_value(struct i2c_client *client, u8 reg, u8 value)
{
return i2c_smbus_write_byte_data(client, reg, value);
}
static void set_in_min(struct device *dev, const char *buf, int nr)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm87_data *data = i2c_get_clientdata(client);
long val = simple_strtol(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->in_min[nr] = IN_TO_REG(val, data->in_scale[nr]);
lm87_write_value(client, nr<6 ? LM87_REG_IN_MIN(nr) :
LM87_REG_AIN_MIN(nr-6), data->in_min[nr]);
mutex_unlock(&data->update_lock);
}
static void set_in_max(struct device *dev, const char *buf, int nr)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm87_data *data = i2c_get_clientdata(client);
long val = simple_strtol(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->in_max[nr] = IN_TO_REG(val, data->in_scale[nr]);
lm87_write_value(client, nr<6 ? LM87_REG_IN_MAX(nr) :
LM87_REG_AIN_MAX(nr-6), data->in_max[nr]);
mutex_unlock(&data->update_lock);
}
static void set_temp_low(struct device *dev, const char *buf, int nr)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm87_data *data = i2c_get_clientdata(client);
long val = simple_strtol(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->temp_low[nr] = TEMP_TO_REG(val);
lm87_write_value(client, LM87_REG_TEMP_LOW[nr], data->temp_low[nr]);
mutex_unlock(&data->update_lock);
}
static void set_temp_high(struct device *dev, const char *buf, int nr)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm87_data *data = i2c_get_clientdata(client);
long val = simple_strtol(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->temp_high[nr] = TEMP_TO_REG(val);
lm87_write_value(client, LM87_REG_TEMP_HIGH[nr], data->temp_high[nr]);
mutex_unlock(&data->update_lock);
}
static ssize_t show_temp_crit_int(struct device *dev, struct device_attribute *attr, char *buf)
{
struct lm87_data *data = lm87_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_crit_int));
}
static ssize_t show_temp_crit_ext(struct device *dev, struct device_attribute *attr, char *buf)
{
struct lm87_data *data = lm87_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_crit_ext));
}
static void set_fan_min(struct device *dev, const char *buf, int nr)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm87_data *data = i2c_get_clientdata(client);
long val = simple_strtol(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->fan_min[nr] = FAN_TO_REG(val,
FAN_DIV_FROM_REG(data->fan_div[nr]));
lm87_write_value(client, LM87_REG_FAN_MIN(nr), data->fan_min[nr]);
mutex_unlock(&data->update_lock);
}
static ssize_t set_fan_div(struct device *dev, const char *buf,
size_t count, int nr)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm87_data *data = i2c_get_clientdata(client);
long val = simple_strtol(buf, NULL, 10);
unsigned long min;
u8 reg;
mutex_lock(&data->update_lock);
min = FAN_FROM_REG(data->fan_min[nr],
FAN_DIV_FROM_REG(data->fan_div[nr]));
switch (val) {
case 1: data->fan_div[nr] = 0; break;
case 2: data->fan_div[nr] = 1; break;
case 4: data->fan_div[nr] = 2; break;
case 8: data->fan_div[nr] = 3; break;
default:
mutex_unlock(&data->update_lock);
return -EINVAL;
}
reg = lm87_read_value(client, LM87_REG_VID_FAN_DIV);
switch (nr) {
case 0:
reg = (reg & 0xCF) | (data->fan_div[0] << 4);
break;
case 1:
reg = (reg & 0x3F) | (data->fan_div[1] << 6);
break;
}
lm87_write_value(client, LM87_REG_VID_FAN_DIV, reg);
data->fan_min[nr] = FAN_TO_REG(min, val);
lm87_write_value(client, LM87_REG_FAN_MIN(nr),
data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarms(struct device *dev, struct device_attribute *attr, char *buf)
{
struct lm87_data *data = lm87_update_device(dev);
return sprintf(buf, "%d\n", data->alarms);
}
static ssize_t show_vid(struct device *dev, struct device_attribute *attr, char *buf)
{
struct lm87_data *data = lm87_update_device(dev);
return sprintf(buf, "%d\n", vid_from_reg(data->vid, data->vrm));
}
static ssize_t show_vrm(struct device *dev, struct device_attribute *attr, char *buf)
{
struct lm87_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", data->vrm);
}
static ssize_t set_vrm(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
struct lm87_data *data = dev_get_drvdata(dev);
data->vrm = simple_strtoul(buf, NULL, 10);
return count;
}
static ssize_t show_aout(struct device *dev, struct device_attribute *attr, char *buf)
{
struct lm87_data *data = lm87_update_device(dev);
return sprintf(buf, "%d\n", AOUT_FROM_REG(data->aout));
}
static ssize_t set_aout(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm87_data *data = i2c_get_clientdata(client);
long val = simple_strtol(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->aout = AOUT_TO_REG(val);
lm87_write_value(client, LM87_REG_AOUT, data->aout);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct lm87_data *data = lm87_update_device(dev);
int bitnr = to_sensor_dev_attr(attr)->index;
return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}
static int lm87_detect(struct i2c_client *new_client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = new_client->adapter;
const char *name;
u8 cid, rev;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
if (lm87_read_value(new_client, LM87_REG_CONFIG) & 0x80)
return -ENODEV;
cid = lm87_read_value(new_client, LM87_REG_COMPANY_ID);
rev = lm87_read_value(new_client, LM87_REG_REVISION);
if (cid == 0x02
&& (rev >= 0x01 && rev <= 0x08))
name = "lm87";
else if (cid == 0x41
&& (rev & 0xf0) == 0x10)
name = "adm1024";
else {
dev_dbg(&adapter->dev, "LM87 detection failed at 0x%02x\n",
new_client->addr);
return -ENODEV;
}
strlcpy(info->type, name, I2C_NAME_SIZE);
return 0;
}
static int lm87_probe(struct i2c_client *new_client,
const struct i2c_device_id *id)
{
struct lm87_data *data;
int err;
data = kzalloc(sizeof(struct lm87_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(new_client, data);
data->valid = 0;
mutex_init(&data->update_lock);
lm87_init_client(new_client);
data->in_scale[0] = 2500;
data->in_scale[1] = 2700;
data->in_scale[2] = (data->channel & CHAN_VCC_5V) ? 5000 : 3300;
data->in_scale[3] = 5000;
data->in_scale[4] = 12000;
data->in_scale[5] = 2700;
data->in_scale[6] = 1875;
data->in_scale[7] = 1875;
if ((err = sysfs_create_group(&new_client->dev.kobj, &lm87_group)))
goto exit_free;
if (data->channel & CHAN_NO_FAN(0)) {
if ((err = device_create_file(&new_client->dev,
&dev_attr_in6_input))
|| (err = device_create_file(&new_client->dev,
&dev_attr_in6_min))
|| (err = device_create_file(&new_client->dev,
&dev_attr_in6_max))
|| (err = device_create_file(&new_client->dev,
&sensor_dev_attr_in6_alarm.dev_attr)))
goto exit_remove;
} else {
if ((err = device_create_file(&new_client->dev,
&dev_attr_fan1_input))
|| (err = device_create_file(&new_client->dev,
&dev_attr_fan1_min))
|| (err = device_create_file(&new_client->dev,
&dev_attr_fan1_div))
|| (err = device_create_file(&new_client->dev,
&sensor_dev_attr_fan1_alarm.dev_attr)))
goto exit_remove;
}
if (data->channel & CHAN_NO_FAN(1)) {
if ((err = device_create_file(&new_client->dev,
&dev_attr_in7_input))
|| (err = device_create_file(&new_client->dev,
&dev_attr_in7_min))
|| (err = device_create_file(&new_client->dev,
&dev_attr_in7_max))
|| (err = device_create_file(&new_client->dev,
&sensor_dev_attr_in7_alarm.dev_attr)))
goto exit_remove;
} else {
if ((err = device_create_file(&new_client->dev,
&dev_attr_fan2_input))
|| (err = device_create_file(&new_client->dev,
&dev_attr_fan2_min))
|| (err = device_create_file(&new_client->dev,
&dev_attr_fan2_div))
|| (err = device_create_file(&new_client->dev,
&sensor_dev_attr_fan2_alarm.dev_attr)))
goto exit_remove;
}
if (data->channel & CHAN_TEMP3) {
if ((err = device_create_file(&new_client->dev,
&dev_attr_temp3_input))
|| (err = device_create_file(&new_client->dev,
&dev_attr_temp3_max))
|| (err = device_create_file(&new_client->dev,
&dev_attr_temp3_min))
|| (err = device_create_file(&new_client->dev,
&dev_attr_temp3_crit))
|| (err = device_create_file(&new_client->dev,
&sensor_dev_attr_temp3_alarm.dev_attr))
|| (err = device_create_file(&new_client->dev,
&sensor_dev_attr_temp3_fault.dev_attr)))
goto exit_remove;
} else {
if ((err = device_create_file(&new_client->dev,
&dev_attr_in0_input))
|| (err = device_create_file(&new_client->dev,
&dev_attr_in0_min))
|| (err = device_create_file(&new_client->dev,
&dev_attr_in0_max))
|| (err = device_create_file(&new_client->dev,
&sensor_dev_attr_in0_alarm.dev_attr))
|| (err = device_create_file(&new_client->dev,
&dev_attr_in5_input))
|| (err = device_create_file(&new_client->dev,
&dev_attr_in5_min))
|| (err = device_create_file(&new_client->dev,
&dev_attr_in5_max))
|| (err = device_create_file(&new_client->dev,
&sensor_dev_attr_in5_alarm.dev_attr)))
goto exit_remove;
}
if (!(data->channel & CHAN_NO_VID)) {
data->vrm = vid_which_vrm();
if ((err = device_create_file(&new_client->dev,
&dev_attr_cpu0_vid))
|| (err = device_create_file(&new_client->dev,
&dev_attr_vrm)))
goto exit_remove;
}
data->hwmon_dev = hwmon_device_register(&new_client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
return 0;
exit_remove:
sysfs_remove_group(&new_client->dev.kobj, &lm87_group);
sysfs_remove_group(&new_client->dev.kobj, &lm87_group_opt);
exit_free:
lm87_write_value(new_client, LM87_REG_CONFIG, data->config);
kfree(data);
exit:
return err;
}
static void lm87_init_client(struct i2c_client *client)
{
struct lm87_data *data = i2c_get_clientdata(client);
if (client->dev.platform_data) {
data->channel = *(u8 *)client->dev.platform_data;
lm87_write_value(client,
LM87_REG_CHANNEL_MODE, data->channel);
} else {
data->channel = lm87_read_value(client, LM87_REG_CHANNEL_MODE);
}
data->config = lm87_read_value(client, LM87_REG_CONFIG) & 0x6F;
if (!(data->config & 0x01)) {
int i;
for (i = 1; i < 6; i++) {
lm87_write_value(client, LM87_REG_IN_MIN(i), 0x00);
lm87_write_value(client, LM87_REG_IN_MAX(i), 0xFF);
}
for (i = 0; i < 2; i++) {
lm87_write_value(client, LM87_REG_TEMP_HIGH[i], 0x7F);
lm87_write_value(client, LM87_REG_TEMP_LOW[i], 0x00);
lm87_write_value(client, LM87_REG_AIN_MIN(i), 0x00);
lm87_write_value(client, LM87_REG_AIN_MAX(i), 0xFF);
}
if (data->channel & CHAN_TEMP3) {
lm87_write_value(client, LM87_REG_TEMP_HIGH[2], 0x7F);
lm87_write_value(client, LM87_REG_TEMP_LOW[2], 0x00);
} else {
lm87_write_value(client, LM87_REG_IN_MIN(0), 0x00);
lm87_write_value(client, LM87_REG_IN_MAX(0), 0xFF);
}
}
if ((data->config & 0x09) != 0x01)
lm87_write_value(client, LM87_REG_CONFIG,
(data->config & 0x77) | 0x01);
}
static int lm87_remove(struct i2c_client *client)
{
struct lm87_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &lm87_group);
sysfs_remove_group(&client->dev.kobj, &lm87_group_opt);
lm87_write_value(client, LM87_REG_CONFIG, data->config);
kfree(data);
return 0;
}
static struct lm87_data *lm87_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm87_data *data = i2c_get_clientdata(client);
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
int i, j;
dev_dbg(&client->dev, "Updating data.\n");
i = (data->channel & CHAN_TEMP3) ? 1 : 0;
j = (data->channel & CHAN_TEMP3) ? 5 : 6;
for (; i < j; i++) {
data->in[i] = lm87_read_value(client,
LM87_REG_IN(i));
data->in_min[i] = lm87_read_value(client,
LM87_REG_IN_MIN(i));
data->in_max[i] = lm87_read_value(client,
LM87_REG_IN_MAX(i));
}
for (i = 0; i < 2; i++) {
if (data->channel & CHAN_NO_FAN(i)) {
data->in[6+i] = lm87_read_value(client,
LM87_REG_AIN(i));
data->in_max[6+i] = lm87_read_value(client,
LM87_REG_AIN_MAX(i));
data->in_min[6+i] = lm87_read_value(client,
LM87_REG_AIN_MIN(i));
} else {
data->fan[i] = lm87_read_value(client,
LM87_REG_FAN(i));
data->fan_min[i] = lm87_read_value(client,
LM87_REG_FAN_MIN(i));
}
}
j = (data->channel & CHAN_TEMP3) ? 3 : 2;
for (i = 0 ; i < j; i++) {
data->temp[i] = lm87_read_value(client,
LM87_REG_TEMP[i]);
data->temp_high[i] = lm87_read_value(client,
LM87_REG_TEMP_HIGH[i]);
data->temp_low[i] = lm87_read_value(client,
LM87_REG_TEMP_LOW[i]);
}
i = lm87_read_value(client, LM87_REG_TEMP_HW_INT_LOCK);
j = lm87_read_value(client, LM87_REG_TEMP_HW_INT);
data->temp_crit_int = min(i, j);
i = lm87_read_value(client, LM87_REG_TEMP_HW_EXT_LOCK);
j = lm87_read_value(client, LM87_REG_TEMP_HW_EXT);
data->temp_crit_ext = min(i, j);
i = lm87_read_value(client, LM87_REG_VID_FAN_DIV);
data->fan_div[0] = (i >> 4) & 0x03;
data->fan_div[1] = (i >> 6) & 0x03;
data->vid = (i & 0x0F)
| (lm87_read_value(client, LM87_REG_VID4) & 0x01)
<< 4;
data->alarms = lm87_read_value(client, LM87_REG_ALARMS1)
| (lm87_read_value(client, LM87_REG_ALARMS2)
<< 8);
data->aout = lm87_read_value(client, LM87_REG_AOUT);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static int __init sensors_lm87_init(void)
{
return i2c_add_driver(&lm87_driver);
}
static void __exit sensors_lm87_exit(void)
{
i2c_del_driver(&lm87_driver);
}
