static struct atxp1_data *atxp1_update_device(struct device *dev)
{
struct atxp1_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
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
struct atxp1_data *data = atxp1_update_device(dev);
struct i2c_client *client = data->client;
int vid, cvid;
unsigned long vcore;
int err;
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
struct atxp1_data *data = atxp1_update_device(dev);
struct i2c_client *client = data->client;
unsigned long value;
int err;
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
struct i2c_client *client = data->client;
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
static int atxp1_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct atxp1_data *data;
struct device *hwmon_dev;
data = devm_kzalloc(dev, sizeof(struct atxp1_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->vrm = vid_which_vrm();
data->client = client;
mutex_init(&data->update_lock);
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data,
atxp1_groups);
if (IS_ERR(hwmon_dev))
return PTR_ERR(hwmon_dev);
dev_info(dev, "Using VRM: %d.%d\n", data->vrm / 10, data->vrm % 10);
return 0;
}
