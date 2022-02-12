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
val = clamp_val(val, 0, nom_mv[n] * 255 / 192);
return SCALE(val, 192, nom_mv[n]);
}
static inline s8 TEMP_TO_REG(long val)
{
return SCALE(clamp_val(val, -128000, 127000), 1, 1000);
}
static inline int TEMP_FROM_REG(s8 val)
{
return val * 1000;
}
static struct smsc47m192_data *smsc47m192_update_device(struct device *dev)
{
struct smsc47m192_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int i, config;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
u8 sfr = i2c_smbus_read_byte_data(client, SMSC47M192_REG_SFR);
dev_dbg(&client->dev, "Starting smsc47m192 update\n");
for (i = 0; i <= 7; i++) {
data->in[i] = i2c_smbus_read_byte_data(client,
SMSC47M192_REG_IN(i));
data->in_min[i] = i2c_smbus_read_byte_data(client,
SMSC47M192_REG_IN_MIN(i));
data->in_max[i] = i2c_smbus_read_byte_data(client,
SMSC47M192_REG_IN_MAX(i));
}
for (i = 0; i < 3; i++) {
data->temp[i] = i2c_smbus_read_byte_data(client,
SMSC47M192_REG_TEMP[i]);
data->temp_max[i] = i2c_smbus_read_byte_data(client,
SMSC47M192_REG_TEMP_MAX[i]);
data->temp_min[i] = i2c_smbus_read_byte_data(client,
SMSC47M192_REG_TEMP_MIN[i]);
}
for (i = 1; i < 3; i++)
data->temp_offset[i] = i2c_smbus_read_byte_data(client,
SMSC47M192_REG_TEMP_OFFSET(i));
if (sfr & 0x10) {
data->temp_offset[0] = data->temp_offset[1];
data->temp_offset[1] = 0;
} else
data->temp_offset[0] = 0;
data->vid = i2c_smbus_read_byte_data(client, SMSC47M192_REG_VID)
& 0x0f;
config = i2c_smbus_read_byte_data(client,
SMSC47M192_REG_CONFIG);
if (config & 0x20)
data->vid |= (i2c_smbus_read_byte_data(client,
SMSC47M192_REG_VID4) & 0x01) << 4;
data->alarms = i2c_smbus_read_byte_data(client,
SMSC47M192_REG_ALARM1) |
(i2c_smbus_read_byte_data(client,
SMSC47M192_REG_ALARM2) << 8);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t show_in(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct smsc47m192_data *data = smsc47m192_update_device(dev);
return sprintf(buf, "%d\n", IN_FROM_REG(data->in[nr], nr));
}
static ssize_t show_in_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct smsc47m192_data *data = smsc47m192_update_device(dev);
return sprintf(buf, "%d\n", IN_FROM_REG(data->in_min[nr], nr));
}
static ssize_t show_in_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct smsc47m192_data *data = smsc47m192_update_device(dev);
return sprintf(buf, "%d\n", IN_FROM_REG(data->in_max[nr], nr));
}
static ssize_t set_in_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct smsc47m192_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_min[nr] = IN_TO_REG(val, nr);
i2c_smbus_write_byte_data(client, SMSC47M192_REG_IN_MIN(nr),
data->in_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_in_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct smsc47m192_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_max[nr] = IN_TO_REG(val, nr);
i2c_smbus_write_byte_data(client, SMSC47M192_REG_IN_MAX(nr),
data->in_max[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct smsc47m192_data *data = smsc47m192_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[nr]));
}
static ssize_t show_temp_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct smsc47m192_data *data = smsc47m192_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_min[nr]));
}
static ssize_t show_temp_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct smsc47m192_data *data = smsc47m192_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_max[nr]));
}
static ssize_t set_temp_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct smsc47m192_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_min[nr] = TEMP_TO_REG(val);
i2c_smbus_write_byte_data(client, SMSC47M192_REG_TEMP_MIN[nr],
data->temp_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_temp_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct smsc47m192_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_max[nr] = TEMP_TO_REG(val);
i2c_smbus_write_byte_data(client, SMSC47M192_REG_TEMP_MAX[nr],
data->temp_max[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_offset(struct device *dev, struct device_attribute
*attr, char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct smsc47m192_data *data = smsc47m192_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_offset[nr]));
}
static ssize_t set_temp_offset(struct device *dev, struct device_attribute
*attr, const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct smsc47m192_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
u8 sfr = i2c_smbus_read_byte_data(client, SMSC47M192_REG_SFR);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_offset[nr] = TEMP_TO_REG(val);
if (nr > 1)
i2c_smbus_write_byte_data(client,
SMSC47M192_REG_TEMP_OFFSET(nr), data->temp_offset[nr]);
else if (data->temp_offset[nr] != 0) {
i2c_smbus_write_byte_data(client, SMSC47M192_REG_SFR,
(sfr & 0xef) | (nr == 0 ? 0x10 : 0));
data->temp_offset[1-nr] = 0;
i2c_smbus_write_byte_data(client,
SMSC47M192_REG_TEMP_OFFSET(nr), data->temp_offset[nr]);
} else if ((sfr & 0x10) == (nr == 0 ? 0x10 : 0))
i2c_smbus_write_byte_data(client,
SMSC47M192_REG_TEMP_OFFSET(nr), 0);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t cpu0_vid_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct smsc47m192_data *data = smsc47m192_update_device(dev);
return sprintf(buf, "%d\n", vid_from_reg(data->vid, data->vrm));
}
static ssize_t vrm_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct smsc47m192_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", data->vrm);
}
static ssize_t vrm_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct smsc47m192_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
if (val > 255)
return -EINVAL;
data->vrm = val;
return count;
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct smsc47m192_data *data = smsc47m192_update_device(dev);
return sprintf(buf, "%u\n", (data->alarms & nr) ? 1 : 0);
}
static void smsc47m192_init_client(struct i2c_client *client)
{
int i;
u8 config = i2c_smbus_read_byte_data(client, SMSC47M192_REG_CONFIG);
u8 sfr = i2c_smbus_read_byte_data(client, SMSC47M192_REG_SFR);
i2c_smbus_write_byte_data(client, SMSC47M192_REG_SFR,
(sfr & 0xfd) | 0x02);
if (!(config & 0x01)) {
for (i = 0; i < 8; i++) {
i2c_smbus_write_byte_data(client,
SMSC47M192_REG_IN_MIN(i), 0);
i2c_smbus_write_byte_data(client,
SMSC47M192_REG_IN_MAX(i), 0xff);
}
for (i = 0; i < 3; i++) {
i2c_smbus_write_byte_data(client,
SMSC47M192_REG_TEMP_MIN[i], 0x80);
i2c_smbus_write_byte_data(client,
SMSC47M192_REG_TEMP_MAX[i], 0x7f);
}
i2c_smbus_write_byte_data(client, SMSC47M192_REG_CONFIG,
(config & 0xf7) | 0x01);
}
}
static int smsc47m192_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int version;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
version = i2c_smbus_read_byte_data(client, SMSC47M192_REG_VERSION);
if (i2c_smbus_read_byte_data(client,
SMSC47M192_REG_COMPANY_ID) == 0x55
&& (version & 0xf0) == 0x20
&& (i2c_smbus_read_byte_data(client,
SMSC47M192_REG_VID) & 0x70) == 0x00
&& (i2c_smbus_read_byte_data(client,
SMSC47M192_REG_VID4) & 0xfe) == 0x80) {
dev_info(&adapter->dev,
"found SMSC47M192 or compatible, "
"version 2, stepping A%d\n", version & 0x0f);
} else {
dev_dbg(&adapter->dev,
"SMSC47M192 detection failed at 0x%02x\n",
client->addr);
return -ENODEV;
}
strlcpy(info->type, "smsc47m192", I2C_NAME_SIZE);
return 0;
}
static int smsc47m192_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct device *hwmon_dev;
struct smsc47m192_data *data;
int config;
data = devm_kzalloc(dev, sizeof(struct smsc47m192_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = client;
data->vrm = vid_which_vrm();
mutex_init(&data->update_lock);
smsc47m192_init_client(client);
data->groups[0] = &smsc47m192_group;
config = i2c_smbus_read_byte_data(client, SMSC47M192_REG_CONFIG);
if (!(config & 0x20))
data->groups[1] = &smsc47m192_group_in4;
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data, data->groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
