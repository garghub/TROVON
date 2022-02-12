static int temp_from_reg_signed(u8 val_h, u8 val_l)
{
s16 val_hl = (val_h << 8) | val_l;
return val_hl * 1000 / 256;
}
static int temp_from_reg_unsigned(u8 val_h, u8 val_l)
{
u16 val_hl = (val_h << 8) | val_l;
return val_hl * 1000 / 256;
}
static struct lm95241_data *lm95241_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95241_data *data = i2c_get_clientdata(client);
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + data->interval) ||
!data->valid) {
int i;
dev_dbg(&client->dev, "Updating lm95241 data.\n");
for (i = 0; i < ARRAY_SIZE(lm95241_reg_address); i++)
data->temp[i]
= i2c_smbus_read_byte_data(client,
lm95241_reg_address[i]);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t show_input(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct lm95241_data *data = lm95241_update_device(dev);
int index = to_sensor_dev_attr(attr)->index;
return snprintf(buf, PAGE_SIZE - 1, "%d\n",
index == 0 || (data->config & (1 << (index / 2))) ?
temp_from_reg_signed(data->temp[index], data->temp[index + 1]) :
temp_from_reg_unsigned(data->temp[index],
data->temp[index + 1]));
}
static ssize_t show_type(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95241_data *data = i2c_get_clientdata(client);
return snprintf(buf, PAGE_SIZE - 1,
data->model & to_sensor_dev_attr(attr)->index ? "1\n" : "2\n");
}
static ssize_t set_type(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95241_data *data = i2c_get_clientdata(client);
unsigned long val;
int shift;
u8 mask = to_sensor_dev_attr(attr)->index;
if (strict_strtoul(buf, 10, &val) < 0)
return -EINVAL;
if (val != 1 && val != 2)
return -EINVAL;
shift = mask == R1MS_MASK ? TT1_SHIFT : TT2_SHIFT;
mutex_lock(&data->update_lock);
data->trutherm &= ~(TT_MASK << shift);
if (val == 1) {
data->model |= mask;
data->trutherm |= (TT_ON << shift);
} else {
data->model &= ~mask;
data->trutherm |= (TT_OFF << shift);
}
data->valid = 0;
i2c_smbus_write_byte_data(client, LM95241_REG_RW_REMOTE_MODEL,
data->model);
i2c_smbus_write_byte_data(client, LM95241_REG_RW_TRUTHERM,
data->trutherm);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95241_data *data = i2c_get_clientdata(client);
return snprintf(buf, PAGE_SIZE - 1,
data->config & to_sensor_dev_attr(attr)->index ?
"-127000\n" : "0\n");
}
static ssize_t set_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95241_data *data = i2c_get_clientdata(client);
long val;
if (strict_strtol(buf, 10, &val) < 0)
return -EINVAL;
if (val < -128000)
return -EINVAL;
mutex_lock(&data->update_lock);
if (val < 0)
data->config |= to_sensor_dev_attr(attr)->index;
else
data->config &= ~to_sensor_dev_attr(attr)->index;
data->valid = 0;
i2c_smbus_write_byte_data(client, LM95241_REG_RW_CONFIG, data->config);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95241_data *data = i2c_get_clientdata(client);
return snprintf(buf, PAGE_SIZE - 1,
data->config & to_sensor_dev_attr(attr)->index ?
"127000\n" : "255000\n");
}
static ssize_t set_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95241_data *data = i2c_get_clientdata(client);
long val;
if (strict_strtol(buf, 10, &val) < 0)
return -EINVAL;
if (val >= 256000)
return -EINVAL;
mutex_lock(&data->update_lock);
if (val <= 127000)
data->config |= to_sensor_dev_attr(attr)->index;
else
data->config &= ~to_sensor_dev_attr(attr)->index;
data->valid = 0;
i2c_smbus_write_byte_data(client, LM95241_REG_RW_CONFIG, data->config);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_interval(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct lm95241_data *data = lm95241_update_device(dev);
return snprintf(buf, PAGE_SIZE - 1, "%lu\n", 1000 * data->interval
/ HZ);
}
static ssize_t set_interval(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct lm95241_data *data = i2c_get_clientdata(client);
unsigned long val;
if (strict_strtoul(buf, 10, &val) < 0)
return -EINVAL;
data->interval = val * HZ / 1000;
return count;
}
static int lm95241_detect(struct i2c_client *new_client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = new_client->adapter;
const char *name;
int mfg_id, chip_id;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
mfg_id = i2c_smbus_read_byte_data(new_client, LM95241_REG_R_MAN_ID);
if (mfg_id != NATSEMI_MAN_ID)
return -ENODEV;
chip_id = i2c_smbus_read_byte_data(new_client, LM95241_REG_R_CHIP_ID);
switch (chip_id) {
case LM95231_CHIP_ID:
name = "lm95231";
break;
case LM95241_CHIP_ID:
name = "lm95241";
break;
default:
return -ENODEV;
}
strlcpy(info->type, name, I2C_NAME_SIZE);
return 0;
}
static void lm95241_init_client(struct i2c_client *client)
{
struct lm95241_data *data = i2c_get_clientdata(client);
data->interval = HZ;
data->valid = 0;
data->config = CFG_CR0076;
data->model = 0;
data->trutherm = (TT_OFF << TT1_SHIFT) | (TT_OFF << TT2_SHIFT);
i2c_smbus_write_byte_data(client, LM95241_REG_RW_CONFIG, data->config);
i2c_smbus_write_byte_data(client, LM95241_REG_RW_REM_FILTER,
R1FE_MASK | R2FE_MASK);
i2c_smbus_write_byte_data(client, LM95241_REG_RW_TRUTHERM,
data->trutherm);
i2c_smbus_write_byte_data(client, LM95241_REG_RW_REMOTE_MODEL,
data->model);
}
static int lm95241_probe(struct i2c_client *new_client,
const struct i2c_device_id *id)
{
struct lm95241_data *data;
int err;
data = kzalloc(sizeof(struct lm95241_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(new_client, data);
mutex_init(&data->update_lock);
lm95241_init_client(new_client);
err = sysfs_create_group(&new_client->dev.kobj, &lm95241_group);
if (err)
goto exit_free;
data->hwmon_dev = hwmon_device_register(&new_client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
return 0;
exit_remove_files:
sysfs_remove_group(&new_client->dev.kobj, &lm95241_group);
exit_free:
kfree(data);
exit:
return err;
}
static int lm95241_remove(struct i2c_client *client)
{
struct lm95241_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &lm95241_group);
kfree(data);
return 0;
}
static int __init sensors_lm95241_init(void)
{
return i2c_add_driver(&lm95241_driver);
}
static void __exit sensors_lm95241_exit(void)
{
i2c_del_driver(&lm95241_driver);
}
