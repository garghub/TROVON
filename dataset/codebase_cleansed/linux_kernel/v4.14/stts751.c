static int stts751_to_deg(s16 hw_val)
{
return hw_val * 125 / 32;
}
static s32 stts751_to_hw(int val)
{
return DIV_ROUND_CLOSEST(val, 125) * 32;
}
static int stts751_adjust_resolution(struct stts751_priv *priv)
{
u8 res;
switch (priv->interval) {
case 9:
res = 0;
break;
case 8:
res = 1;
break;
default:
res = 3;
break;
}
if (priv->res == res)
return 0;
priv->config &= ~STTS751_CONF_RES_MASK;
priv->config |= res << STTS751_CONF_RES_SHIFT;
dev_dbg(&priv->client->dev, "setting res %d. config %x",
res, priv->config);
priv->res = res;
return i2c_smbus_write_byte_data(priv->client,
STTS751_REG_CONF, priv->config);
}
static int stts751_update_temp(struct stts751_priv *priv)
{
s32 integer1, integer2, frac;
integer1 = i2c_smbus_read_byte_data(priv->client, STTS751_REG_TEMP_H);
if (integer1 < 0) {
dev_dbg(&priv->client->dev,
"I2C read failed (temp H). ret: %x\n", integer1);
return integer1;
}
frac = i2c_smbus_read_byte_data(priv->client, STTS751_REG_TEMP_L);
if (frac < 0) {
dev_dbg(&priv->client->dev,
"I2C read failed (temp L). ret: %x\n", frac);
return frac;
}
integer2 = i2c_smbus_read_byte_data(priv->client, STTS751_REG_TEMP_H);
if (integer2 < 0) {
dev_dbg(&priv->client->dev,
"I2C 2nd read failed (temp H). ret: %x\n", integer2);
return integer2;
}
if (integer1 != integer2) {
frac = i2c_smbus_read_byte_data(priv->client,
STTS751_REG_TEMP_L);
if (frac < 0) {
dev_dbg(&priv->client->dev,
"I2C 2nd read failed (temp L). ret: %x\n",
frac);
return frac;
}
}
priv->temp = stts751_to_deg((integer1 << 8) | frac);
return 0;
}
static int stts751_set_temp_reg16(struct stts751_priv *priv, int temp,
u8 hreg, u8 lreg)
{
s32 hwval;
int ret;
hwval = stts751_to_hw(temp);
ret = i2c_smbus_write_byte_data(priv->client, hreg, hwval >> 8);
if (ret)
return ret;
return i2c_smbus_write_byte_data(priv->client, lreg, hwval & 0xff);
}
static int stts751_set_temp_reg8(struct stts751_priv *priv, int temp, u8 reg)
{
s32 hwval;
hwval = stts751_to_hw(temp);
return i2c_smbus_write_byte_data(priv->client, reg, hwval >> 8);
}
static int stts751_read_reg16(struct stts751_priv *priv, int *temp,
u8 hreg, u8 lreg)
{
int integer, frac;
integer = i2c_smbus_read_byte_data(priv->client, hreg);
if (integer < 0)
return integer;
frac = i2c_smbus_read_byte_data(priv->client, lreg);
if (frac < 0)
return frac;
*temp = stts751_to_deg((integer << 8) | frac);
return 0;
}
static int stts751_read_reg8(struct stts751_priv *priv, int *temp, u8 reg)
{
int integer;
integer = i2c_smbus_read_byte_data(priv->client, reg);
if (integer < 0)
return integer;
*temp = stts751_to_deg(integer << 8);
return 0;
}
static int stts751_update_alert(struct stts751_priv *priv)
{
int ret;
bool conv_done;
int cache_time = msecs_to_jiffies(stts751_intervals[priv->interval]);
cache_time += cache_time / 10;
ret = i2c_smbus_read_byte_data(priv->client, STTS751_REG_STATUS);
if (ret < 0)
return ret;
dev_dbg(&priv->client->dev, "status reg %x\n", ret);
conv_done = ret & (STTS751_STATUS_TRIPH | STTS751_STATUS_TRIPL);
if (time_after(jiffies, priv->last_alert_update + cache_time) ||
conv_done || !priv->alert_valid) {
priv->max_alert = false;
priv->min_alert = false;
priv->alert_valid = true;
priv->last_alert_update = jiffies;
dev_dbg(&priv->client->dev, "invalidating alert cache\n");
}
priv->max_alert |= !!(ret & STTS751_STATUS_TRIPH);
priv->min_alert |= !!(ret & STTS751_STATUS_TRIPL);
priv->therm_trip = !!(ret & STTS751_STATUS_TRIPT);
dev_dbg(&priv->client->dev, "max_alert: %d, min_alert: %d, therm_trip: %d\n",
priv->max_alert, priv->min_alert, priv->therm_trip);
return 0;
}
static void stts751_alert(struct i2c_client *client,
enum i2c_alert_protocol type, unsigned int data)
{
int ret;
struct stts751_priv *priv = i2c_get_clientdata(client);
if (type != I2C_PROTOCOL_SMBUS_ALERT)
return;
dev_dbg(&client->dev, "alert!");
mutex_lock(&priv->access_lock);
ret = stts751_update_alert(priv);
if (ret < 0) {
priv->max_alert = true;
priv->min_alert = true;
dev_warn(priv->dev,
"Alert received, but can't communicate to the device. Triggering all alarms!");
}
if (priv->max_alert) {
if (priv->notify_max)
dev_notice(priv->dev, "got alert for HIGH temperature");
priv->notify_max = false;
sysfs_notify(&priv->dev->kobj, NULL, "temp1_max_alarm");
}
if (priv->min_alert) {
if (priv->notify_min)
dev_notice(priv->dev, "got alert for LOW temperature");
priv->notify_min = false;
sysfs_notify(&priv->dev->kobj, NULL, "temp1_min_alarm");
}
if (priv->min_alert || priv->max_alert)
kobject_uevent(&priv->dev->kobj, KOBJ_CHANGE);
mutex_unlock(&priv->access_lock);
}
static int stts751_update(struct stts751_priv *priv)
{
int ret;
int cache_time = msecs_to_jiffies(stts751_intervals[priv->interval]);
if (time_after(jiffies, priv->last_update + cache_time) ||
!priv->data_valid) {
ret = stts751_update_temp(priv);
if (ret)
return ret;
ret = stts751_update_alert(priv);
if (ret)
return ret;
priv->data_valid = true;
priv->last_update = jiffies;
}
return 0;
}
static ssize_t show_max_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int ret;
struct stts751_priv *priv = dev_get_drvdata(dev);
mutex_lock(&priv->access_lock);
ret = stts751_update(priv);
if (!ret)
priv->notify_max = true;
mutex_unlock(&priv->access_lock);
if (ret < 0)
return ret;
return snprintf(buf, PAGE_SIZE - 1, "%d\n", priv->max_alert);
}
static ssize_t show_min_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int ret;
struct stts751_priv *priv = dev_get_drvdata(dev);
mutex_lock(&priv->access_lock);
ret = stts751_update(priv);
if (!ret)
priv->notify_min = true;
mutex_unlock(&priv->access_lock);
if (ret < 0)
return ret;
return snprintf(buf, PAGE_SIZE - 1, "%d\n", priv->min_alert);
}
static ssize_t show_input(struct device *dev, struct device_attribute *attr,
char *buf)
{
int ret;
struct stts751_priv *priv = dev_get_drvdata(dev);
mutex_lock(&priv->access_lock);
ret = stts751_update(priv);
mutex_unlock(&priv->access_lock);
if (ret < 0)
return ret;
return snprintf(buf, PAGE_SIZE - 1, "%d\n", priv->temp);
}
static ssize_t show_therm(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct stts751_priv *priv = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE - 1, "%d\n", priv->therm);
}
static ssize_t set_therm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int ret;
long temp;
struct stts751_priv *priv = dev_get_drvdata(dev);
if (kstrtol(buf, 10, &temp) < 0)
return -EINVAL;
temp = clamp_val(temp, -64000, 127937);
mutex_lock(&priv->access_lock);
ret = stts751_set_temp_reg8(priv, temp, STTS751_REG_TLIM);
if (ret)
goto exit;
dev_dbg(&priv->client->dev, "setting therm %ld", temp);
priv->hyst = temp - (priv->therm - priv->hyst);
priv->therm = temp;
exit:
mutex_unlock(&priv->access_lock);
if (ret)
return ret;
return count;
}
static ssize_t show_hyst(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct stts751_priv *priv = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE - 1, "%d\n", priv->hyst);
}
static ssize_t set_hyst(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int ret;
long temp;
struct stts751_priv *priv = dev_get_drvdata(dev);
if (kstrtol(buf, 10, &temp) < 0)
return -EINVAL;
mutex_lock(&priv->access_lock);
temp = clamp_val(temp, -64000, priv->therm);
priv->hyst = temp;
dev_dbg(&priv->client->dev, "setting hyst %ld", temp);
temp = priv->therm - temp;
ret = stts751_set_temp_reg8(priv, temp, STTS751_REG_HYST);
mutex_unlock(&priv->access_lock);
if (ret)
return ret;
return count;
}
static ssize_t show_therm_trip(struct device *dev,
struct device_attribute *attr, char *buf)
{
int ret;
struct stts751_priv *priv = dev_get_drvdata(dev);
mutex_lock(&priv->access_lock);
ret = stts751_update(priv);
mutex_unlock(&priv->access_lock);
if (ret < 0)
return ret;
return snprintf(buf, PAGE_SIZE - 1, "%d\n", priv->therm_trip);
}
static ssize_t show_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct stts751_priv *priv = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE - 1, "%d\n", priv->event_max);
}
static ssize_t set_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int ret;
long temp;
struct stts751_priv *priv = dev_get_drvdata(dev);
if (kstrtol(buf, 10, &temp) < 0)
return -EINVAL;
mutex_lock(&priv->access_lock);
temp = clamp_val(temp, priv->event_min, 127937);
ret = stts751_set_temp_reg16(priv, temp,
STTS751_REG_HLIM_H, STTS751_REG_HLIM_L);
if (ret)
goto exit;
dev_dbg(&priv->client->dev, "setting event max %ld", temp);
priv->event_max = temp;
ret = count;
exit:
mutex_unlock(&priv->access_lock);
return ret;
}
static ssize_t show_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct stts751_priv *priv = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE - 1, "%d\n", priv->event_min);
}
static ssize_t set_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int ret;
long temp;
struct stts751_priv *priv = dev_get_drvdata(dev);
if (kstrtol(buf, 10, &temp) < 0)
return -EINVAL;
mutex_lock(&priv->access_lock);
temp = clamp_val(temp, -64000, priv->event_max);
ret = stts751_set_temp_reg16(priv, temp,
STTS751_REG_LLIM_H, STTS751_REG_LLIM_L);
if (ret)
goto exit;
dev_dbg(&priv->client->dev, "setting event min %ld", temp);
priv->event_min = temp;
ret = count;
exit:
mutex_unlock(&priv->access_lock);
return ret;
}
static ssize_t show_interval(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct stts751_priv *priv = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE - 1, "%d\n",
stts751_intervals[priv->interval]);
}
static ssize_t set_interval(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned long val;
int idx;
int ret = count;
struct stts751_priv *priv = dev_get_drvdata(dev);
if (kstrtoul(buf, 10, &val) < 0)
return -EINVAL;
idx = find_closest_descending(val, stts751_intervals,
ARRAY_SIZE(stts751_intervals));
dev_dbg(&priv->client->dev, "setting interval. req:%lu, idx: %d, val: %d",
val, idx, stts751_intervals[idx]);
mutex_lock(&priv->access_lock);
if (priv->interval == idx)
goto exit;
if (priv->interval < idx) {
dev_dbg(&priv->client->dev, "lower resolution, then modify convrate");
priv->interval = idx;
ret = stts751_adjust_resolution(priv);
if (ret)
goto exit;
}
ret = i2c_smbus_write_byte_data(priv->client, STTS751_REG_RATE, idx);
if (ret)
goto exit;
if (priv->interval != idx) {
dev_dbg(&priv->client->dev, "modify convrate, then raise resolution");
priv->interval = idx;
ret = stts751_adjust_resolution(priv);
if (ret)
goto exit;
}
ret = count;
exit:
mutex_unlock(&priv->access_lock);
return ret;
}
static int stts751_detect(struct i2c_client *new_client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = new_client->adapter;
const char *name;
int tmp;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
tmp = i2c_smbus_read_byte_data(new_client, STTS751_REG_MAN_ID);
if (tmp != ST_MAN_ID)
return -ENODEV;
tmp = i2c_smbus_read_byte_data(new_client, STTS751_REG_TEMP_L);
if (tmp & 0xf)
return -ENODEV;
tmp = i2c_smbus_read_byte_data(new_client, STTS751_REG_HLIM_L);
if (tmp & 0xf)
return -ENODEV;
tmp = i2c_smbus_read_byte_data(new_client, STTS751_REG_LLIM_L);
if (tmp & 0xf)
return -ENODEV;
tmp = i2c_smbus_read_byte_data(new_client, STTS751_REG_SMBUS_TO);
if (tmp & 0x7f)
return -ENODEV;
tmp = i2c_smbus_read_byte_data(new_client, STTS751_REG_PROD_ID);
switch (tmp) {
case STTS751_0_PROD_ID:
name = "STTS751-0";
break;
case STTS751_1_PROD_ID:
name = "STTS751-1";
break;
default:
return -ENODEV;
}
dev_dbg(&new_client->dev, "Chip %s detected", name);
strlcpy(info->type, stts751_id[0].name, I2C_NAME_SIZE);
return 0;
}
static int stts751_read_chip_config(struct stts751_priv *priv)
{
int ret;
int tmp;
ret = i2c_smbus_read_byte_data(priv->client, STTS751_REG_CONF);
if (ret < 0)
return ret;
priv->config = ret;
priv->res = (ret & STTS751_CONF_RES_MASK) >> STTS751_CONF_RES_SHIFT;
ret = i2c_smbus_read_byte_data(priv->client, STTS751_REG_RATE);
if (ret < 0)
return ret;
if (ret >= ARRAY_SIZE(stts751_intervals)) {
dev_err(priv->dev, "Unrecognized conversion rate 0x%x\n", ret);
return -ENODEV;
}
priv->interval = ret;
ret = stts751_read_reg16(priv, &priv->event_max,
STTS751_REG_HLIM_H, STTS751_REG_HLIM_L);
if (ret)
return ret;
ret = stts751_read_reg16(priv, &priv->event_min,
STTS751_REG_LLIM_H, STTS751_REG_LLIM_L);
if (ret)
return ret;
ret = stts751_read_reg8(priv, &priv->therm, STTS751_REG_TLIM);
if (ret)
return ret;
ret = stts751_read_reg8(priv, &tmp, STTS751_REG_HYST);
if (ret)
return ret;
priv->hyst = priv->therm - tmp;
return 0;
}
static int stts751_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct stts751_priv *priv;
int ret;
bool smbus_nto;
int rev_id;
priv = devm_kzalloc(&client->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->client = client;
priv->notify_max = true;
priv->notify_min = true;
i2c_set_clientdata(client, priv);
mutex_init(&priv->access_lock);
if (device_property_present(&client->dev,
"smbus-timeout-disable")) {
smbus_nto = device_property_read_bool(&client->dev,
"smbus-timeout-disable");
ret = i2c_smbus_write_byte_data(client, STTS751_REG_SMBUS_TO,
smbus_nto ? 0 : 0x80);
if (ret)
return ret;
}
rev_id = i2c_smbus_read_byte_data(client, STTS751_REG_REV_ID);
if (rev_id < 0)
return -ENODEV;
if (rev_id != 0x1) {
dev_dbg(&client->dev, "Chip revision 0x%x is untested\n",
rev_id);
}
ret = stts751_read_chip_config(priv);
if (ret)
return ret;
priv->config &= ~(STTS751_CONF_STOP | STTS751_CONF_EVENT_DIS);
ret = i2c_smbus_write_byte_data(client, STTS751_REG_CONF, priv->config);
if (ret)
return ret;
priv->dev = devm_hwmon_device_register_with_groups(&client->dev,
client->name, priv,
stts751_groups);
return PTR_ERR_OR_ZERO(priv->dev);
}
