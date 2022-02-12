static struct atxp1_data *atxp1_update_device(struct device *dev)
{
struct i2c_client *client;
struct atxp1_data *data;
client = to_i2c_client(dev);
data = i2c_get_clientdata(client);
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
data->reg.vid = i2c_smbus_read_byte_data(client, ATXP1_VID);
data->reg.cpu_vid = i2c_smbus_read_byte_data(client,
ATXP1_CVID);
data->reg.gpio1 = i2c_smbus_read_byte_data(client, ATXP1_GPIO1);
data->reg.gpio2 = i2c_smbus_read_byte_data(client, ATXP1_GPIO2);
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t atxp1_showvcore(struct device *dev,
struct device_attribute *attr, char *buf)
{
int size;
struct atxp1_data *data;
data = atxp1_update_device(dev);
size = sprintf(buf, "%d\n", vid_from_reg(data->reg.vid & ATXP1_VIDMASK,
data->vrm));
return size;
}
static ssize_t atxp1_storevcore(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct atxp1_data *data;
struct i2c_client *client;
int vid, cvid;
unsigned long vcore;
int err;
client = to_i2c_client(dev);
data = atxp1_update_device(dev);
err = kstrtoul(buf, 10, &vcore);
if (err)
return err;
vcore /= 25;
vcore *= 25;
vid = vid_to_reg(vcore, data->vrm);
if (vid < 0) {
dev_err(dev, "VID calculation failed.\n");
return vid;
}
if (data->reg.vid & ATXP1_VIDENA)
cvid = data->reg.vid & ATXP1_VIDMASK;
else
cvid = data->reg.cpu_vid;
if (vid == cvid)
return count;
dev_dbg(dev, "Setting VCore to %d mV (0x%02x)\n", (int)vcore, vid);
if (cvid > vid) {
for (; cvid >= vid; cvid--)
i2c_smbus_write_byte_data(client,
ATXP1_VID, cvid | ATXP1_VIDENA);
} else {
for (; cvid <= vid; cvid++)
i2c_smbus_write_byte_data(client,
ATXP1_VID, cvid | ATXP1_VIDENA);
}
data->valid = 0;
return count;
}
static ssize_t atxp1_showgpio1(struct device *dev,
struct device_attribute *attr, char *buf)
{
int size;
struct atxp1_data *data;
data = atxp1_update_device(dev);
size = sprintf(buf, "0x%02x\n", data->reg.gpio1 & ATXP1_GPIO1MASK);
return size;
}
static ssize_t atxp1_storegpio1(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
struct atxp1_data *data;
struct i2c_client *client;
unsigned long value;
int err;
client = to_i2c_client(dev);
data = atxp1_update_device(dev);
err = kstrtoul(buf, 16, &value);
if (err)
return err;
value &= ATXP1_GPIO1MASK;
if (value != (data->reg.gpio1 & ATXP1_GPIO1MASK)) {
dev_info(dev, "Writing 0x%x to GPIO1.\n", (unsigned int)value);
i2c_smbus_write_byte_data(client, ATXP1_GPIO1, value);
data->valid = 0;
}
return count;
}
static ssize_t atxp1_showgpio2(struct device *dev,
struct device_attribute *attr, char *buf)
{
int size;
struct atxp1_data *data;
data = atxp1_update_device(dev);
size = sprintf(buf, "0x%02x\n", data->reg.gpio2);
return size;
}
static ssize_t atxp1_storegpio2(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct atxp1_data *data = atxp1_update_device(dev);
struct i2c_client *client = to_i2c_client(dev);
unsigned long value;
int err;
err = kstrtoul(buf, 16, &value);
if (err)
return err;
value &= 0xff;
if (value != data->reg.gpio2) {
dev_info(dev, "Writing 0x%x to GPIO1.\n", (unsigned int)value);
i2c_smbus_write_byte_data(client, ATXP1_GPIO2, value);
data->valid = 0;
}
return count;
}
static int atxp1_detect(struct i2c_client *new_client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = new_client->adapter;
u8 temp;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
if (!((i2c_smbus_read_byte_data(new_client, 0x3e) == 0) &&
(i2c_smbus_read_byte_data(new_client, 0x3f) == 0) &&
(i2c_smbus_read_byte_data(new_client, 0xfe) == 0) &&
(i2c_smbus_read_byte_data(new_client, 0xff) == 0)))
return -ENODEV;
temp = i2c_smbus_read_byte_data(new_client, 0x00);
if (!((i2c_smbus_read_byte_data(new_client, 0x10) == temp) &&
(i2c_smbus_read_byte_data(new_client, 0x11) == temp)))
return -ENODEV;
temp = vid_which_vrm();
if ((temp != 90) && (temp != 91)) {
dev_err(&adapter->dev, "atxp1: Not supporting VRM %d.%d\n",
temp / 10, temp % 10);
return -ENODEV;
}
strlcpy(info->type, "atxp1", I2C_NAME_SIZE);
return 0;
}
static int atxp1_probe(struct i2c_client *new_client,
const struct i2c_device_id *id)
{
struct atxp1_data *data;
int err;
data = devm_kzalloc(&new_client->dev, sizeof(struct atxp1_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
data->vrm = vid_which_vrm();
i2c_set_clientdata(new_client, data);
data->valid = 0;
mutex_init(&data->update_lock);
err = sysfs_create_group(&new_client->dev.kobj, &atxp1_group);
if (err)
return err;
data->hwmon_dev = hwmon_device_register(&new_client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
dev_info(&new_client->dev, "Using VRM: %d.%d\n",
data->vrm / 10, data->vrm % 10);
return 0;
exit_remove_files:
sysfs_remove_group(&new_client->dev.kobj, &atxp1_group);
return err;
}
static int atxp1_remove(struct i2c_client *client)
{
struct atxp1_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &atxp1_group);
return 0;
}
