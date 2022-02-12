static inline int SCALE(long val, int mul, int div)
{
if (val < 0)
return (val * mul - div / 2) / div;
else
return (val * mul + div / 2) / div;
}
static inline unsigned int IN_FROM_REG(u8 reg, int n)
{
return SCALE(reg, nom_mv[n], 192);
}
static inline u8 IN_TO_REG(unsigned long val, int n)
{
return SENSORS_LIMIT(SCALE(val, 192, nom_mv[n]), 0, 255);
}
static inline s8 TEMP_TO_REG(long val)
{
return SENSORS_LIMIT(SCALE(val, 1, 1000), -40, 127);
}
static inline unsigned int FAN_FROM_REG(u8 reg, u8 div)
{
if (!reg)
return -1;
if (reg == 255)
return 0;
return SCALE(1350000, 1, reg * div);
}
static inline u8 AOUT_TO_REG(unsigned long val)
{
return SENSORS_LIMIT(SCALE(val, 255, 1250), 0, 255);
}
static inline unsigned int AOUT_FROM_REG(u8 reg)
{
return SCALE(reg, 1250, 255);
}
static ssize_t show_temp(struct device *dev, struct device_attribute *dummy,
char *buf)
{
struct adm9240_data *data = adm9240_update_device(dev);
return sprintf(buf, "%d\n", data->temp * 500);
}
static ssize_t show_max(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adm9240_data *data = adm9240_update_device(dev);
return sprintf(buf, "%d\n", data->temp_max[attr->index] * 1000);
}
static ssize_t set_max(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct i2c_client *client = to_i2c_client(dev);
struct adm9240_data *data = i2c_get_clientdata(client);
long val = simple_strtol(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->temp_max[attr->index] = TEMP_TO_REG(val);
i2c_smbus_write_byte_data(client, ADM9240_REG_TEMP_MAX(attr->index),
data->temp_max[attr->index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_in(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adm9240_data *data = adm9240_update_device(dev);
return sprintf(buf, "%d\n", IN_FROM_REG(data->in[attr->index],
attr->index));
}
static ssize_t show_in_min(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adm9240_data *data = adm9240_update_device(dev);
return sprintf(buf, "%d\n", IN_FROM_REG(data->in_min[attr->index],
attr->index));
}
static ssize_t show_in_max(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adm9240_data *data = adm9240_update_device(dev);
return sprintf(buf, "%d\n", IN_FROM_REG(data->in_max[attr->index],
attr->index));
}
static ssize_t set_in_min(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct i2c_client *client = to_i2c_client(dev);
struct adm9240_data *data = i2c_get_clientdata(client);
unsigned long val = simple_strtoul(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->in_min[attr->index] = IN_TO_REG(val, attr->index);
i2c_smbus_write_byte_data(client, ADM9240_REG_IN_MIN(attr->index),
data->in_min[attr->index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_in_max(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct i2c_client *client = to_i2c_client(dev);
struct adm9240_data *data = i2c_get_clientdata(client);
unsigned long val = simple_strtoul(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->in_max[attr->index] = IN_TO_REG(val, attr->index);
i2c_smbus_write_byte_data(client, ADM9240_REG_IN_MAX(attr->index),
data->in_max[attr->index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_fan(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adm9240_data *data = adm9240_update_device(dev);
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan[attr->index],
1 << data->fan_div[attr->index]));
}
static ssize_t show_fan_min(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adm9240_data *data = adm9240_update_device(dev);
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan_min[attr->index],
1 << data->fan_div[attr->index]));
}
static ssize_t show_fan_div(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adm9240_data *data = adm9240_update_device(dev);
return sprintf(buf, "%d\n", 1 << data->fan_div[attr->index]);
}
static void adm9240_write_fan_div(struct i2c_client *client, int nr,
u8 fan_div)
{
u8 reg, old, shift = (nr + 2) * 2;
reg = i2c_smbus_read_byte_data(client, ADM9240_REG_VID_FAN_DIV);
old = (reg >> shift) & 3;
reg &= ~(3 << shift);
reg |= (fan_div << shift);
i2c_smbus_write_byte_data(client, ADM9240_REG_VID_FAN_DIV, reg);
dev_dbg(&client->dev, "fan%d clock divider changed from %u "
"to %u\n", nr + 1, 1 << old, 1 << fan_div);
}
static ssize_t set_fan_min(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct i2c_client *client = to_i2c_client(dev);
struct adm9240_data *data = i2c_get_clientdata(client);
unsigned long val = simple_strtoul(buf, NULL, 10);
int nr = attr->index;
u8 new_div;
mutex_lock(&data->update_lock);
if (!val) {
data->fan_min[nr] = 255;
new_div = data->fan_div[nr];
dev_dbg(&client->dev, "fan%u low limit set disabled\n",
nr + 1);
} else if (val < 1350000 / (8 * 254)) {
new_div = 3;
data->fan_min[nr] = 254;
dev_dbg(&client->dev, "fan%u low limit set minimum %u\n",
nr + 1, FAN_FROM_REG(254, 1 << new_div));
} else {
unsigned int new_min = 1350000 / val;
new_div = 0;
while (new_min > 192 && new_div < 3) {
new_div++;
new_min /= 2;
}
if (!new_min)
new_min++;
data->fan_min[nr] = new_min;
dev_dbg(&client->dev, "fan%u low limit set fan speed %u\n",
nr + 1, FAN_FROM_REG(new_min, 1 << new_div));
}
if (new_div != data->fan_div[nr]) {
data->fan_div[nr] = new_div;
adm9240_write_fan_div(client, nr, new_div);
}
i2c_smbus_write_byte_data(client, ADM9240_REG_FAN_MIN(nr),
data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarms(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adm9240_data *data = adm9240_update_device(dev);
return sprintf(buf, "%u\n", data->alarms);
}
static ssize_t show_alarm(struct device *dev,
struct device_attribute *attr, char *buf)
{
int bitnr = to_sensor_dev_attr(attr)->index;
struct adm9240_data *data = adm9240_update_device(dev);
return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}
static ssize_t show_vid(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adm9240_data *data = adm9240_update_device(dev);
return sprintf(buf, "%d\n", vid_from_reg(data->vid, data->vrm));
}
static ssize_t show_aout(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adm9240_data *data = adm9240_update_device(dev);
return sprintf(buf, "%d\n", AOUT_FROM_REG(data->aout));
}
static ssize_t set_aout(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct adm9240_data *data = i2c_get_clientdata(client);
unsigned long val = simple_strtol(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->aout = AOUT_TO_REG(val);
i2c_smbus_write_byte_data(client, ADM9240_REG_ANALOG_OUT, data->aout);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t chassis_clear_legacy(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
unsigned long val = simple_strtol(buf, NULL, 10);
dev_warn(dev, "Attribute chassis_clear is deprecated, "
"use intrusion0_alarm instead\n");
if (val == 1) {
i2c_smbus_write_byte_data(client,
ADM9240_REG_CHASSIS_CLEAR, 0x80);
dev_dbg(&client->dev, "chassis intrusion latch cleared\n");
}
return count;
}
static ssize_t chassis_clear(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct adm9240_data *data = i2c_get_clientdata(client);
unsigned long val;
if (strict_strtoul(buf, 10, &val) || val != 0)
return -EINVAL;
mutex_lock(&data->update_lock);
i2c_smbus_write_byte_data(client, ADM9240_REG_CHASSIS_CLEAR, 0x80);
data->valid = 0;
mutex_unlock(&data->update_lock);
dev_dbg(&client->dev, "chassis intrusion latch cleared\n");
return count;
}
static int adm9240_detect(struct i2c_client *new_client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = new_client->adapter;
const char *name = "";
int address = new_client->addr;
u8 man_id, die_rev;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
if (i2c_smbus_read_byte_data(new_client, ADM9240_REG_I2C_ADDR)
!= address) {
dev_err(&adapter->dev, "detect fail: address match, 0x%02x\n",
address);
return -ENODEV;
}
man_id = i2c_smbus_read_byte_data(new_client, ADM9240_REG_MAN_ID);
if (man_id == 0x23) {
name = "adm9240";
} else if (man_id == 0xda) {
name = "ds1780";
} else if (man_id == 0x01) {
name = "lm81";
} else {
dev_err(&adapter->dev, "detect fail: unknown manuf, 0x%02x\n",
man_id);
return -ENODEV;
}
die_rev = i2c_smbus_read_byte_data(new_client, ADM9240_REG_DIE_REV);
dev_info(&adapter->dev, "found %s revision %u\n",
man_id == 0x23 ? "ADM9240" :
man_id == 0xda ? "DS1780" : "LM81", die_rev);
strlcpy(info->type, name, I2C_NAME_SIZE);
return 0;
}
static int adm9240_probe(struct i2c_client *new_client,
const struct i2c_device_id *id)
{
struct adm9240_data *data;
int err;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(new_client, data);
mutex_init(&data->update_lock);
adm9240_init_client(new_client);
if ((err = sysfs_create_group(&new_client->dev.kobj, &adm9240_group)))
goto exit_free;
data->hwmon_dev = hwmon_device_register(&new_client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
return 0;
exit_remove:
sysfs_remove_group(&new_client->dev.kobj, &adm9240_group);
exit_free:
kfree(data);
exit:
return err;
}
static int adm9240_remove(struct i2c_client *client)
{
struct adm9240_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &adm9240_group);
kfree(data);
return 0;
}
static void adm9240_init_client(struct i2c_client *client)
{
struct adm9240_data *data = i2c_get_clientdata(client);
u8 conf = i2c_smbus_read_byte_data(client, ADM9240_REG_CONFIG);
u8 mode = i2c_smbus_read_byte_data(client, ADM9240_REG_TEMP_CONF) & 3;
data->vrm = vid_which_vrm();
dev_info(&client->dev, "Using VRM: %d.%d\n", data->vrm / 10,
data->vrm % 10);
if (conf & 1) {
dev_info(&client->dev, "status: config 0x%02x mode %u\n",
conf, mode);
} else {
int i;
for (i = 0; i < 6; i++)
{
i2c_smbus_write_byte_data(client,
ADM9240_REG_IN_MIN(i), 0);
i2c_smbus_write_byte_data(client,
ADM9240_REG_IN_MAX(i), 255);
}
i2c_smbus_write_byte_data(client,
ADM9240_REG_FAN_MIN(0), 255);
i2c_smbus_write_byte_data(client,
ADM9240_REG_FAN_MIN(1), 255);
i2c_smbus_write_byte_data(client,
ADM9240_REG_TEMP_MAX(0), 127);
i2c_smbus_write_byte_data(client,
ADM9240_REG_TEMP_MAX(1), 127);
i2c_smbus_write_byte_data(client, ADM9240_REG_CONFIG, 1);
dev_info(&client->dev, "cold start: config was 0x%02x "
"mode %u\n", conf, mode);
}
}
static struct adm9240_data *adm9240_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct adm9240_data *data = i2c_get_clientdata(client);
int i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated_measure + (HZ * 7 / 4))
|| !data->valid) {
for (i = 0; i < 6; i++)
{
data->in[i] = i2c_smbus_read_byte_data(client,
ADM9240_REG_IN(i));
}
data->alarms = i2c_smbus_read_byte_data(client,
ADM9240_REG_INT(0)) |
i2c_smbus_read_byte_data(client,
ADM9240_REG_INT(1)) << 8;
data->temp = ((i2c_smbus_read_byte_data(client,
ADM9240_REG_TEMP) << 8) |
i2c_smbus_read_byte_data(client,
ADM9240_REG_TEMP_CONF)) / 128;
for (i = 0; i < 2; i++)
{
data->fan[i] = i2c_smbus_read_byte_data(client,
ADM9240_REG_FAN(i));
if (data->valid && data->fan[i] == 255 &&
data->fan_div[i] < 3) {
adm9240_write_fan_div(client, i,
++data->fan_div[i]);
if (data->fan_min[i] < 255 &&
data->fan_min[i] >= 2)
data->fan_min[i] /= 2;
}
}
data->last_updated_measure = jiffies;
}
if (time_after(jiffies, data->last_updated_config + (HZ * 300))
|| !data->valid) {
for (i = 0; i < 6; i++)
{
data->in_min[i] = i2c_smbus_read_byte_data(client,
ADM9240_REG_IN_MIN(i));
data->in_max[i] = i2c_smbus_read_byte_data(client,
ADM9240_REG_IN_MAX(i));
}
for (i = 0; i < 2; i++)
{
data->fan_min[i] = i2c_smbus_read_byte_data(client,
ADM9240_REG_FAN_MIN(i));
}
data->temp_max[0] = i2c_smbus_read_byte_data(client,
ADM9240_REG_TEMP_MAX(0));
data->temp_max[1] = i2c_smbus_read_byte_data(client,
ADM9240_REG_TEMP_MAX(1));
i = i2c_smbus_read_byte_data(client, ADM9240_REG_VID_FAN_DIV);
data->fan_div[0] = (i >> 4) & 3;
data->fan_div[1] = (i >> 6) & 3;
data->vid = i & 0x0f;
data->vid |= (i2c_smbus_read_byte_data(client,
ADM9240_REG_VID4) & 1) << 4;
data->aout = i2c_smbus_read_byte_data(client,
ADM9240_REG_ANALOG_OUT);
data->last_updated_config = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static int __init sensors_adm9240_init(void)
{
return i2c_add_driver(&adm9240_driver);
}
static void __exit sensors_adm9240_exit(void)
{
i2c_del_driver(&adm9240_driver);
}
