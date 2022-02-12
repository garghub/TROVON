static struct lm83_data *lm83_update_device(struct device *dev)
{
struct lm83_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ * 2) || !data->valid) {
int nr;
dev_dbg(&client->dev, "Updating lm83 data.\n");
for (nr = 0; nr < 9; nr++) {
data->temp[nr] =
i2c_smbus_read_byte_data(client,
LM83_REG_R_TEMP[nr]);
}
data->alarms =
i2c_smbus_read_byte_data(client, LM83_REG_R_STATUS1)
+ (i2c_smbus_read_byte_data(client, LM83_REG_R_STATUS2)
<< 8);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm83_data *data = lm83_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[attr->index]));
}
static ssize_t set_temp(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm83_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long val;
int nr = attr->index;
int err;
err = kstrtol(buf, 10, &val);
if (err < 0)
return err;
mutex_lock(&data->update_lock);
data->temp[nr] = TEMP_TO_REG(val);
i2c_smbus_write_byte_data(client, LM83_REG_W_HIGH[nr - 4],
data->temp[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarms(struct device *dev, struct device_attribute *dummy,
char *buf)
{
struct lm83_data *data = lm83_update_device(dev);
return sprintf(buf, "%d\n", data->alarms);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct lm83_data *data = lm83_update_device(dev);
int bitnr = attr->index;
return sprintf(buf, "%d\n", (data->alarms >> bitnr) & 1);
}
static int lm83_detect(struct i2c_client *new_client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = new_client->adapter;
const char *name;
u8 man_id, chip_id;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
if ((i2c_smbus_read_byte_data(new_client, LM83_REG_R_STATUS1) & 0xA8) ||
(i2c_smbus_read_byte_data(new_client, LM83_REG_R_STATUS2) & 0x48) ||
(i2c_smbus_read_byte_data(new_client, LM83_REG_R_CONFIG) & 0x41)) {
dev_dbg(&adapter->dev, "LM83 detection failed at 0x%02x\n",
new_client->addr);
return -ENODEV;
}
man_id = i2c_smbus_read_byte_data(new_client, LM83_REG_R_MAN_ID);
if (man_id != 0x01)
return -ENODEV;
chip_id = i2c_smbus_read_byte_data(new_client, LM83_REG_R_CHIP_ID);
switch (chip_id) {
case 0x03:
name = "lm83";
break;
case 0x01:
name = "lm82";
break;
default:
dev_info(&adapter->dev,
"Unsupported chip (man_id=0x%02X, chip_id=0x%02X)\n",
man_id, chip_id);
return -ENODEV;
}
strlcpy(info->type, name, I2C_NAME_SIZE);
return 0;
}
static int lm83_probe(struct i2c_client *new_client,
const struct i2c_device_id *id)
{
struct device *hwmon_dev;
struct lm83_data *data;
data = devm_kzalloc(&new_client->dev, sizeof(struct lm83_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = new_client;
mutex_init(&data->update_lock);
data->groups[0] = &lm83_group;
if (id->driver_data == lm83)
data->groups[1] = &lm83_group_opt;
hwmon_dev = devm_hwmon_device_register_with_groups(&new_client->dev,
new_client->name,
data, data->groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
