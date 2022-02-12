static int adt7411_read_10_bit(struct i2c_client *client, u8 lsb_reg,
u8 msb_reg, u8 lsb_shift)
{
struct adt7411_data *data = i2c_get_clientdata(client);
int val, tmp;
mutex_lock(&data->device_lock);
val = i2c_smbus_read_byte_data(client, lsb_reg);
if (val < 0)
goto exit_unlock;
tmp = (val >> lsb_shift) & 3;
val = i2c_smbus_read_byte_data(client, msb_reg);
if (val >= 0)
val = (val << 2) | tmp;
exit_unlock:
mutex_unlock(&data->device_lock);
return val;
}
static int adt7411_modify_bit(struct i2c_client *client, u8 reg, u8 bit,
bool flag)
{
struct adt7411_data *data = i2c_get_clientdata(client);
int ret, val;
mutex_lock(&data->device_lock);
ret = i2c_smbus_read_byte_data(client, reg);
if (ret < 0)
goto exit_unlock;
if (flag)
val = ret | bit;
else
val = ret & ~bit;
ret = i2c_smbus_write_byte_data(client, reg, val);
exit_unlock:
mutex_unlock(&data->device_lock);
return ret;
}
static ssize_t adt7411_show_vdd(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
int ret = adt7411_read_10_bit(client, ADT7411_REG_INT_TEMP_VDD_LSB,
ADT7411_REG_VDD_MSB, 2);
return ret < 0 ? ret : sprintf(buf, "%u\n", ret * 7000 / 1024);
}
static ssize_t adt7411_show_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
int val = adt7411_read_10_bit(client, ADT7411_REG_INT_TEMP_VDD_LSB,
ADT7411_REG_INT_TEMP_MSB, 0);
if (val < 0)
return val;
val = val & 0x200 ? val - 0x400 : val;
return sprintf(buf, "%d\n", val * 250);
}
static ssize_t adt7411_show_input(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct adt7411_data *data = i2c_get_clientdata(client);
int val;
u8 lsb_reg, lsb_shift;
mutex_lock(&data->update_lock);
if (time_after_eq(jiffies, data->next_update)) {
val = i2c_smbus_read_byte_data(client, ADT7411_REG_CFG3);
if (val < 0)
goto exit_unlock;
if (val & ADT7411_CFG3_REF_VDD) {
val = adt7411_read_10_bit(client,
ADT7411_REG_INT_TEMP_VDD_LSB,
ADT7411_REG_VDD_MSB, 2);
if (val < 0)
goto exit_unlock;
data->vref_cached = val * 7000 / 1024;
} else {
data->vref_cached = 2250;
}
data->next_update = jiffies + HZ;
}
lsb_reg = ADT7411_REG_EXT_TEMP_AIN14_LSB + (nr >> 2);
lsb_shift = 2 * (nr & 0x03);
val = adt7411_read_10_bit(client, lsb_reg,
ADT7411_REG_EXT_TEMP_AIN1_MSB + nr, lsb_shift);
if (val < 0)
goto exit_unlock;
val = sprintf(buf, "%u\n", val * data->vref_cached / 1024);
exit_unlock:
mutex_unlock(&data->update_lock);
return val;
}
static ssize_t adt7411_show_bit(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute_2 *attr2 = to_sensor_dev_attr_2(attr);
struct i2c_client *client = to_i2c_client(dev);
int ret = i2c_smbus_read_byte_data(client, attr2->index);
return ret < 0 ? ret : sprintf(buf, "%u\n", !!(ret & attr2->nr));
}
static ssize_t adt7411_set_bit(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
struct sensor_device_attribute_2 *s_attr2 = to_sensor_dev_attr_2(attr);
struct i2c_client *client = to_i2c_client(dev);
struct adt7411_data *data = i2c_get_clientdata(client);
int ret;
unsigned long flag;
ret = kstrtoul(buf, 0, &flag);
if (ret || flag > 1)
return -EINVAL;
ret = adt7411_modify_bit(client, s_attr2->index, s_attr2->nr, flag);
mutex_lock(&data->update_lock);
data->next_update = jiffies;
mutex_unlock(&data->update_lock);
return ret < 0 ? ret : count;
}
static int adt7411_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
int val;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
val = i2c_smbus_read_byte_data(client, ADT7411_REG_MANUFACTURER_ID);
if (val < 0 || val != ADT7411_MANUFACTURER_ID) {
dev_dbg(&client->dev, "Wrong manufacturer ID. Got %d, "
"expected %d\n", val, ADT7411_MANUFACTURER_ID);
return -ENODEV;
}
val = i2c_smbus_read_byte_data(client, ADT7411_REG_DEVICE_ID);
if (val < 0 || val != ADT7411_DEVICE_ID) {
dev_dbg(&client->dev, "Wrong device ID. Got %d, "
"expected %d\n", val, ADT7411_DEVICE_ID);
return -ENODEV;
}
strlcpy(info->type, "adt7411", I2C_NAME_SIZE);
return 0;
}
static int __devinit adt7411_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct adt7411_data *data;
int ret;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->device_lock);
mutex_init(&data->update_lock);
ret = adt7411_modify_bit(client, ADT7411_REG_CFG1,
ADT7411_CFG1_START_MONITOR, 1);
if (ret < 0)
goto exit_free;
data->next_update = jiffies;
ret = sysfs_create_group(&client->dev.kobj, &adt7411_attr_grp);
if (ret)
goto exit_free;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
ret = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
dev_info(&client->dev, "successfully registered\n");
return 0;
exit_remove:
sysfs_remove_group(&client->dev.kobj, &adt7411_attr_grp);
exit_free:
kfree(data);
return ret;
}
static int __devexit adt7411_remove(struct i2c_client *client)
{
struct adt7411_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &adt7411_attr_grp);
kfree(data);
return 0;
}
