static int gl520_read_value(struct i2c_client *client, u8 reg)
{
if ((reg >= 0x07) && (reg <= 0x0c))
return i2c_smbus_read_word_swapped(client, reg);
else
return i2c_smbus_read_byte_data(client, reg);
}
static int gl520_write_value(struct i2c_client *client, u8 reg, u16 value)
{
if ((reg >= 0x07) && (reg <= 0x0c))
return i2c_smbus_write_word_swapped(client, reg, value);
else
return i2c_smbus_write_byte_data(client, reg, value);
}
static struct gl520_data *gl520_update_device(struct device *dev)
{
struct gl520_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int val, i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + 2 * HZ) || !data->valid) {
dev_dbg(&client->dev, "Starting gl520sm update\n");
data->alarms = gl520_read_value(client, GL520_REG_ALARMS);
data->beep_mask = gl520_read_value(client, GL520_REG_BEEP_MASK);
data->vid = gl520_read_value(client,
GL520_REG_VID_INPUT) & 0x1f;
for (i = 0; i < 4; i++) {
data->in_input[i] = gl520_read_value(client,
GL520_REG_IN_INPUT[i]);
val = gl520_read_value(client, GL520_REG_IN_LIMIT[i]);
data->in_min[i] = val & 0xff;
data->in_max[i] = (val >> 8) & 0xff;
}
val = gl520_read_value(client, GL520_REG_FAN_INPUT);
data->fan_input[0] = (val >> 8) & 0xff;
data->fan_input[1] = val & 0xff;
val = gl520_read_value(client, GL520_REG_FAN_MIN);
data->fan_min[0] = (val >> 8) & 0xff;
data->fan_min[1] = val & 0xff;
data->temp_input[0] = gl520_read_value(client,
GL520_REG_TEMP_INPUT[0]);
data->temp_max[0] = gl520_read_value(client,
GL520_REG_TEMP_MAX[0]);
data->temp_max_hyst[0] = gl520_read_value(client,
GL520_REG_TEMP_MAX_HYST[0]);
val = gl520_read_value(client, GL520_REG_FAN_DIV);
data->fan_div[0] = (val >> 6) & 0x03;
data->fan_div[1] = (val >> 4) & 0x03;
data->fan_off = (val >> 2) & 0x01;
data->alarms &= data->alarm_mask;
val = gl520_read_value(client, GL520_REG_CONF);
data->beep_enable = !((val >> 2) & 1);
if (data->two_temps) {
data->temp_input[1] = gl520_read_value(client,
GL520_REG_TEMP_INPUT[1]);
data->temp_max[1] = gl520_read_value(client,
GL520_REG_TEMP_MAX[1]);
data->temp_max_hyst[1] = gl520_read_value(client,
GL520_REG_TEMP_MAX_HYST[1]);
} else {
data->in_input[4] = gl520_read_value(client,
GL520_REG_IN_INPUT[4]);
data->in_min[4] = gl520_read_value(client,
GL520_REG_IN_MIN[4]);
data->in_max[4] = gl520_read_value(client,
GL520_REG_IN_MAX[4]);
}
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t get_cpu_vid(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct gl520_data *data = gl520_update_device(dev);
return sprintf(buf, "%u\n", vid_from_reg(data->vid, data->vrm));
}
static ssize_t get_in_input(struct device *dev, struct device_attribute *attr,
char *buf)
{
int n = to_sensor_dev_attr(attr)->index;
struct gl520_data *data = gl520_update_device(dev);
u8 r = data->in_input[n];
if (n == 0)
return sprintf(buf, "%d\n", VDD_FROM_REG(r));
else
return sprintf(buf, "%d\n", IN_FROM_REG(r));
}
static ssize_t get_in_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
int n = to_sensor_dev_attr(attr)->index;
struct gl520_data *data = gl520_update_device(dev);
u8 r = data->in_min[n];
if (n == 0)
return sprintf(buf, "%d\n", VDD_FROM_REG(r));
else
return sprintf(buf, "%d\n", IN_FROM_REG(r));
}
static ssize_t get_in_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
int n = to_sensor_dev_attr(attr)->index;
struct gl520_data *data = gl520_update_device(dev);
u8 r = data->in_max[n];
if (n == 0)
return sprintf(buf, "%d\n", VDD_FROM_REG(r));
else
return sprintf(buf, "%d\n", IN_FROM_REG(r));
}
static ssize_t set_in_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct gl520_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int n = to_sensor_dev_attr(attr)->index;
u8 r;
long v;
int err;
err = kstrtol(buf, 10, &v);
if (err)
return err;
mutex_lock(&data->update_lock);
if (n == 0)
r = VDD_TO_REG(v);
else
r = IN_TO_REG(v);
data->in_min[n] = r;
if (n < 4)
gl520_write_value(client, GL520_REG_IN_MIN[n],
(gl520_read_value(client, GL520_REG_IN_MIN[n])
& ~0xff) | r);
else
gl520_write_value(client, GL520_REG_IN_MIN[n], r);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_in_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct gl520_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int n = to_sensor_dev_attr(attr)->index;
u8 r;
long v;
int err;
err = kstrtol(buf, 10, &v);
if (err)
return err;
if (n == 0)
r = VDD_TO_REG(v);
else
r = IN_TO_REG(v);
mutex_lock(&data->update_lock);
data->in_max[n] = r;
if (n < 4)
gl520_write_value(client, GL520_REG_IN_MAX[n],
(gl520_read_value(client, GL520_REG_IN_MAX[n])
& ~0xff00) | (r << 8));
else
gl520_write_value(client, GL520_REG_IN_MAX[n], r);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t get_fan_input(struct device *dev, struct device_attribute *attr,
char *buf)
{
int n = to_sensor_dev_attr(attr)->index;
struct gl520_data *data = gl520_update_device(dev);
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan_input[n],
data->fan_div[n]));
}
static ssize_t get_fan_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
int n = to_sensor_dev_attr(attr)->index;
struct gl520_data *data = gl520_update_device(dev);
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan_min[n],
data->fan_div[n]));
}
static ssize_t get_fan_div(struct device *dev, struct device_attribute *attr,
char *buf)
{
int n = to_sensor_dev_attr(attr)->index;
struct gl520_data *data = gl520_update_device(dev);
return sprintf(buf, "%d\n", DIV_FROM_REG(data->fan_div[n]));
}
static ssize_t get_fan_off(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct gl520_data *data = gl520_update_device(dev);
return sprintf(buf, "%d\n", data->fan_off);
}
static ssize_t set_fan_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct gl520_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int n = to_sensor_dev_attr(attr)->index;
u8 r;
unsigned long v;
int err;
err = kstrtoul(buf, 10, &v);
if (err)
return err;
mutex_lock(&data->update_lock);
r = FAN_TO_REG(v, data->fan_div[n]);
data->fan_min[n] = r;
if (n == 0)
gl520_write_value(client, GL520_REG_FAN_MIN,
(gl520_read_value(client, GL520_REG_FAN_MIN)
& ~0xff00) | (r << 8));
else
gl520_write_value(client, GL520_REG_FAN_MIN,
(gl520_read_value(client, GL520_REG_FAN_MIN)
& ~0xff) | r);
data->beep_mask = gl520_read_value(client, GL520_REG_BEEP_MASK);
if (data->fan_min[n] == 0)
data->alarm_mask &= (n == 0) ? ~0x20 : ~0x40;
else
data->alarm_mask |= (n == 0) ? 0x20 : 0x40;
data->beep_mask &= data->alarm_mask;
gl520_write_value(client, GL520_REG_BEEP_MASK, data->beep_mask);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_fan_div(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct gl520_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int n = to_sensor_dev_attr(attr)->index;
u8 r;
unsigned long v;
int err;
err = kstrtoul(buf, 10, &v);
if (err)
return err;
switch (v) {
case 1:
r = 0;
break;
case 2:
r = 1;
break;
case 4:
r = 2;
break;
case 8:
r = 3;
break;
default:
dev_err(&client->dev,
"fan_div value %ld not supported. Choose one of 1, 2, 4 or 8!\n", v);
return -EINVAL;
}
mutex_lock(&data->update_lock);
data->fan_div[n] = r;
if (n == 0)
gl520_write_value(client, GL520_REG_FAN_DIV,
(gl520_read_value(client, GL520_REG_FAN_DIV)
& ~0xc0) | (r << 6));
else
gl520_write_value(client, GL520_REG_FAN_DIV,
(gl520_read_value(client, GL520_REG_FAN_DIV)
& ~0x30) | (r << 4));
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_fan_off(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct gl520_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
u8 r;
unsigned long v;
int err;
err = kstrtoul(buf, 10, &v);
if (err)
return err;
r = (v ? 1 : 0);
mutex_lock(&data->update_lock);
data->fan_off = r;
gl520_write_value(client, GL520_REG_FAN_OFF,
(gl520_read_value(client, GL520_REG_FAN_OFF)
& ~0x0c) | (r << 2));
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t get_temp_input(struct device *dev, struct device_attribute *attr,
char *buf)
{
int n = to_sensor_dev_attr(attr)->index;
struct gl520_data *data = gl520_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_input[n]));
}
static ssize_t get_temp_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
int n = to_sensor_dev_attr(attr)->index;
struct gl520_data *data = gl520_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_max[n]));
}
static ssize_t get_temp_max_hyst(struct device *dev,
struct device_attribute *attr, char *buf)
{
int n = to_sensor_dev_attr(attr)->index;
struct gl520_data *data = gl520_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_max_hyst[n]));
}
static ssize_t set_temp_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct gl520_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int n = to_sensor_dev_attr(attr)->index;
long v;
int err;
err = kstrtol(buf, 10, &v);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_max[n] = TEMP_TO_REG(v);
gl520_write_value(client, GL520_REG_TEMP_MAX[n], data->temp_max[n]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_temp_max_hyst(struct device *dev, struct device_attribute
*attr, const char *buf, size_t count)
{
struct gl520_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int n = to_sensor_dev_attr(attr)->index;
long v;
int err;
err = kstrtol(buf, 10, &v);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_max_hyst[n] = TEMP_TO_REG(v);
gl520_write_value(client, GL520_REG_TEMP_MAX_HYST[n],
data->temp_max_hyst[n]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t get_alarms(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct gl520_data *data = gl520_update_device(dev);
return sprintf(buf, "%d\n", data->alarms);
}
static ssize_t get_beep_enable(struct device *dev, struct device_attribute
*attr, char *buf)
{
struct gl520_data *data = gl520_update_device(dev);
return sprintf(buf, "%d\n", data->beep_enable);
}
static ssize_t get_beep_mask(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct gl520_data *data = gl520_update_device(dev);
return sprintf(buf, "%d\n", data->beep_mask);
}
static ssize_t set_beep_enable(struct device *dev, struct device_attribute
*attr, const char *buf, size_t count)
{
struct gl520_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
u8 r;
unsigned long v;
int err;
err = kstrtoul(buf, 10, &v);
if (err)
return err;
r = (v ? 0 : 1);
mutex_lock(&data->update_lock);
data->beep_enable = !r;
gl520_write_value(client, GL520_REG_BEEP_ENABLE,
(gl520_read_value(client, GL520_REG_BEEP_ENABLE)
& ~0x04) | (r << 2));
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_beep_mask(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct gl520_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
unsigned long r;
int err;
err = kstrtoul(buf, 10, &r);
if (err)
return err;
mutex_lock(&data->update_lock);
r &= data->alarm_mask;
data->beep_mask = r;
gl520_write_value(client, GL520_REG_BEEP_MASK, r);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t get_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int bit_nr = to_sensor_dev_attr(attr)->index;
struct gl520_data *data = gl520_update_device(dev);
return sprintf(buf, "%d\n", (data->alarms >> bit_nr) & 1);
}
static ssize_t get_beep(struct device *dev, struct device_attribute *attr,
char *buf)
{
int bitnr = to_sensor_dev_attr(attr)->index;
struct gl520_data *data = gl520_update_device(dev);
return sprintf(buf, "%d\n", (data->beep_mask >> bitnr) & 1);
}
static ssize_t set_beep(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct gl520_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int bitnr = to_sensor_dev_attr(attr)->index;
unsigned long bit;
int err;
err = kstrtoul(buf, 10, &bit);
if (err)
return err;
if (bit & ~1)
return -EINVAL;
mutex_lock(&data->update_lock);
data->beep_mask = gl520_read_value(client, GL520_REG_BEEP_MASK);
if (bit)
data->beep_mask |= (1 << bitnr);
else
data->beep_mask &= ~(1 << bitnr);
gl520_write_value(client, GL520_REG_BEEP_MASK, data->beep_mask);
mutex_unlock(&data->update_lock);
return count;
}
static int gl520_detect(struct i2c_client *client, struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
if ((gl520_read_value(client, GL520_REG_CHIP_ID) != 0x20) ||
((gl520_read_value(client, GL520_REG_REVISION) & 0x7f) != 0x00) ||
((gl520_read_value(client, GL520_REG_CONF) & 0x80) != 0x00)) {
dev_dbg(&client->dev, "Unknown chip type, skipping\n");
return -ENODEV;
}
strlcpy(info->type, "gl520sm", I2C_NAME_SIZE);
return 0;
}
static void gl520_init_client(struct i2c_client *client)
{
struct gl520_data *data = i2c_get_clientdata(client);
u8 oldconf, conf;
conf = oldconf = gl520_read_value(client, GL520_REG_CONF);
data->alarm_mask = 0xff;
data->vrm = vid_which_vrm();
if (extra_sensor_type == 1)
conf &= ~0x10;
else if (extra_sensor_type == 2)
conf |= 0x10;
data->two_temps = !(conf & 0x10);
if (!(conf & 0x20))
conf &= 0xf7;
conf |= 0x40;
if (conf != oldconf)
gl520_write_value(client, GL520_REG_CONF, conf);
gl520_update_device(&(client->dev));
if (data->fan_min[0] == 0)
data->alarm_mask &= ~0x20;
if (data->fan_min[1] == 0)
data->alarm_mask &= ~0x40;
data->beep_mask &= data->alarm_mask;
gl520_write_value(client, GL520_REG_BEEP_MASK, data->beep_mask);
}
static int gl520_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct device *hwmon_dev;
struct gl520_data *data;
data = devm_kzalloc(dev, sizeof(struct gl520_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
data->client = client;
gl520_init_client(client);
data->groups[0] = &gl520_group;
if (data->two_temps)
data->groups[1] = &gl520_group_temp2;
else
data->groups[1] = &gl520_group_in4;
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data, data->groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
