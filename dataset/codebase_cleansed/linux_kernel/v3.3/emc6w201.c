static u16 emc6w201_read16(struct i2c_client *client, u8 reg)
{
int lsb, msb;
lsb = i2c_smbus_read_byte_data(client, reg);
msb = i2c_smbus_read_byte_data(client, reg + 1);
if (unlikely(lsb < 0 || msb < 0)) {
dev_err(&client->dev, "%d-bit %s failed at 0x%02x\n",
16, "read", reg);
return 0xFFFF;
}
return (msb << 8) | lsb;
}
static int emc6w201_write16(struct i2c_client *client, u8 reg, u16 val)
{
int err;
err = i2c_smbus_write_byte_data(client, reg, val & 0xff);
if (likely(!err))
err = i2c_smbus_write_byte_data(client, reg + 1, val >> 8);
if (unlikely(err < 0))
dev_err(&client->dev, "%d-bit %s failed at 0x%02x\n",
16, "write", reg);
return err;
}
static u8 emc6w201_read8(struct i2c_client *client, u8 reg)
{
int val;
val = i2c_smbus_read_byte_data(client, reg);
if (unlikely(val < 0)) {
dev_err(&client->dev, "%d-bit %s failed at 0x%02x\n",
8, "read", reg);
return 0x00;
}
return val;
}
static int emc6w201_write8(struct i2c_client *client, u8 reg, u8 val)
{
int err;
err = i2c_smbus_write_byte_data(client, reg, val);
if (unlikely(err < 0))
dev_err(&client->dev, "%d-bit %s failed at 0x%02x\n",
8, "write", reg);
return err;
}
static struct emc6w201_data *emc6w201_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct emc6w201_data *data = i2c_get_clientdata(client);
int nr;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
for (nr = 0; nr < 6; nr++) {
data->in[input][nr] =
emc6w201_read8(client,
EMC6W201_REG_IN(nr));
data->in[min][nr] =
emc6w201_read8(client,
EMC6W201_REG_IN_LOW(nr));
data->in[max][nr] =
emc6w201_read8(client,
EMC6W201_REG_IN_HIGH(nr));
}
for (nr = 0; nr < 6; nr++) {
data->temp[input][nr] =
emc6w201_read8(client,
EMC6W201_REG_TEMP(nr));
data->temp[min][nr] =
emc6w201_read8(client,
EMC6W201_REG_TEMP_LOW(nr));
data->temp[max][nr] =
emc6w201_read8(client,
EMC6W201_REG_TEMP_HIGH(nr));
}
for (nr = 0; nr < 5; nr++) {
data->fan[input][nr] =
emc6w201_read16(client,
EMC6W201_REG_FAN(nr));
data->fan[min][nr] =
emc6w201_read16(client,
EMC6W201_REG_FAN_MIN(nr));
}
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t show_in(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct emc6w201_data *data = emc6w201_update_device(dev);
int sf = to_sensor_dev_attr_2(devattr)->index;
int nr = to_sensor_dev_attr_2(devattr)->nr;
return sprintf(buf, "%u\n",
(unsigned)data->in[sf][nr] * nominal_mv[nr] / 0xC0);
}
static ssize_t set_in(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct emc6w201_data *data = i2c_get_clientdata(client);
int sf = to_sensor_dev_attr_2(devattr)->index;
int nr = to_sensor_dev_attr_2(devattr)->nr;
int err;
long val;
u8 reg;
err = kstrtol(buf, 10, &val);
if (err < 0)
return err;
val = DIV_ROUND_CLOSEST(val * 0xC0, nominal_mv[nr]);
reg = (sf == min) ? EMC6W201_REG_IN_LOW(nr)
: EMC6W201_REG_IN_HIGH(nr);
mutex_lock(&data->update_lock);
data->in[sf][nr] = SENSORS_LIMIT(val, 0, 255);
err = emc6w201_write8(client, reg, data->in[sf][nr]);
mutex_unlock(&data->update_lock);
return err < 0 ? err : count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct emc6w201_data *data = emc6w201_update_device(dev);
int sf = to_sensor_dev_attr_2(devattr)->index;
int nr = to_sensor_dev_attr_2(devattr)->nr;
return sprintf(buf, "%d\n", (int)data->temp[sf][nr] * 1000);
}
static ssize_t set_temp(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct emc6w201_data *data = i2c_get_clientdata(client);
int sf = to_sensor_dev_attr_2(devattr)->index;
int nr = to_sensor_dev_attr_2(devattr)->nr;
int err;
long val;
u8 reg;
err = kstrtol(buf, 10, &val);
if (err < 0)
return err;
val /= 1000;
reg = (sf == min) ? EMC6W201_REG_TEMP_LOW(nr)
: EMC6W201_REG_TEMP_HIGH(nr);
mutex_lock(&data->update_lock);
data->temp[sf][nr] = SENSORS_LIMIT(val, -127, 128);
err = emc6w201_write8(client, reg, data->temp[sf][nr]);
mutex_unlock(&data->update_lock);
return err < 0 ? err : count;
}
static ssize_t show_fan(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct emc6w201_data *data = emc6w201_update_device(dev);
int sf = to_sensor_dev_attr_2(devattr)->index;
int nr = to_sensor_dev_attr_2(devattr)->nr;
unsigned rpm;
if (data->fan[sf][nr] == 0 || data->fan[sf][nr] == 0xFFFF)
rpm = 0;
else
rpm = 5400000U / data->fan[sf][nr];
return sprintf(buf, "%u\n", rpm);
}
static ssize_t set_fan(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct emc6w201_data *data = i2c_get_clientdata(client);
int sf = to_sensor_dev_attr_2(devattr)->index;
int nr = to_sensor_dev_attr_2(devattr)->nr;
int err;
unsigned long val;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
if (val == 0) {
val = 0xFFFF;
} else {
val = DIV_ROUND_CLOSEST(5400000U, val);
val = SENSORS_LIMIT(val, 0, 0xFFFE);
}
mutex_lock(&data->update_lock);
data->fan[sf][nr] = val;
err = emc6w201_write16(client, EMC6W201_REG_FAN_MIN(nr),
data->fan[sf][nr]);
mutex_unlock(&data->update_lock);
return err < 0 ? err : count;
}
static int emc6w201_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int company, verstep, config;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
company = i2c_smbus_read_byte_data(client, EMC6W201_REG_COMPANY);
if (company != 0x5C)
return -ENODEV;
verstep = i2c_smbus_read_byte_data(client, EMC6W201_REG_VERSTEP);
if (verstep < 0 || (verstep & 0xF0) != 0xB0)
return -ENODEV;
if ((verstep & 0x0F) > 2) {
dev_dbg(&client->dev, "Unknwown EMC6W201 stepping %d\n",
verstep & 0x0F);
return -ENODEV;
}
config = i2c_smbus_read_byte_data(client, EMC6W201_REG_CONFIG);
if (config < 0 || (config & 0xF4) != 0x04)
return -ENODEV;
if (!(config & 0x01)) {
dev_err(&client->dev, "Monitoring not enabled\n");
return -ENODEV;
}
strlcpy(info->type, "emc6w201", I2C_NAME_SIZE);
return 0;
}
static int emc6w201_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct emc6w201_data *data;
int err;
data = kzalloc(sizeof(struct emc6w201_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
err = sysfs_create_group(&client->dev.kobj, &emc6w201_group);
if (err)
goto exit_free;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
return 0;
exit_remove:
sysfs_remove_group(&client->dev.kobj, &emc6w201_group);
exit_free:
kfree(data);
exit:
return err;
}
static int emc6w201_remove(struct i2c_client *client)
{
struct emc6w201_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &emc6w201_group);
kfree(data);
return 0;
}
static int __init sensors_emc6w201_init(void)
{
return i2c_add_driver(&emc6w201_driver);
}
static void __exit sensors_emc6w201_exit(void)
{
i2c_del_driver(&emc6w201_driver);
}
