static void fschmd_release_resources(struct kref *ref)
{
struct fschmd_data *data = container_of(ref, struct fschmd_data, kref);
kfree(data);
}
static ssize_t show_in_value(struct device *dev,
struct device_attribute *devattr, char *buf)
{
const int max_reading[3] = { 14200, 6600, 3300 };
int index = to_sensor_dev_attr(devattr)->index;
struct fschmd_data *data = fschmd_update_device(dev);
if (data->kind == fscher || data->kind >= fschrc)
return sprintf(buf, "%d\n", (data->volt[index] * dmi_vref *
dmi_mult[index]) / 255 + dmi_offset[index]);
else
return sprintf(buf, "%d\n", (data->volt[index] *
max_reading[index] + 128) / 255);
}
static ssize_t show_temp_value(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct fschmd_data *data = fschmd_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_act[index]));
}
static ssize_t show_temp_max(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct fschmd_data *data = fschmd_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_max[index]));
}
static ssize_t store_temp_max(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
int index = to_sensor_dev_attr(devattr)->index;
struct fschmd_data *data = dev_get_drvdata(dev);
long v;
int err;
err = kstrtol(buf, 10, &v);
if (err)
return err;
v = SENSORS_LIMIT(v / 1000, -128, 127) + 128;
mutex_lock(&data->update_lock);
i2c_smbus_write_byte_data(to_i2c_client(dev),
FSCHMD_REG_TEMP_LIMIT[data->kind][index], v);
data->temp_max[index] = v;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_fault(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct fschmd_data *data = fschmd_update_device(dev);
if (data->temp_status[index] & FSCHMD_TEMP_WORKING)
return sprintf(buf, "0\n");
else
return sprintf(buf, "1\n");
}
static ssize_t show_temp_alarm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct fschmd_data *data = fschmd_update_device(dev);
if ((data->temp_status[index] & FSCHMD_TEMP_ALARM_MASK) ==
FSCHMD_TEMP_ALARM_MASK)
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static ssize_t show_fan_value(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct fschmd_data *data = fschmd_update_device(dev);
return sprintf(buf, "%u\n", RPM_FROM_REG(data->fan_act[index]));
}
static ssize_t show_fan_div(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct fschmd_data *data = fschmd_update_device(dev);
return sprintf(buf, "%d\n", 1 << (data->fan_ripple[index] & 3));
}
static ssize_t store_fan_div(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
u8 reg;
int index = to_sensor_dev_attr(devattr)->index;
struct fschmd_data *data = dev_get_drvdata(dev);
unsigned long v;
int err;
err = kstrtoul(buf, 10, &v);
if (err)
return err;
switch (v) {
case 2:
v = 1;
break;
case 4:
v = 2;
break;
case 8:
v = 3;
break;
default:
dev_err(dev, "fan_div value %lu not supported. "
"Choose one of 2, 4 or 8!\n", v);
return -EINVAL;
}
mutex_lock(&data->update_lock);
reg = i2c_smbus_read_byte_data(to_i2c_client(dev),
FSCHMD_REG_FAN_RIPPLE[data->kind][index]);
reg &= ~0x03;
reg |= v;
i2c_smbus_write_byte_data(to_i2c_client(dev),
FSCHMD_REG_FAN_RIPPLE[data->kind][index], reg);
data->fan_ripple[index] = reg;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_fan_alarm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct fschmd_data *data = fschmd_update_device(dev);
if (data->fan_status[index] & FSCHMD_FAN_ALARM)
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static ssize_t show_fan_fault(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct fschmd_data *data = fschmd_update_device(dev);
if (data->fan_status[index] & FSCHMD_FAN_NOT_PRESENT)
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static ssize_t show_pwm_auto_point1_pwm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
struct fschmd_data *data = fschmd_update_device(dev);
int val = data->fan_min[index];
if (val || data->kind == fscsyl)
val = val / 2 + 128;
return sprintf(buf, "%d\n", val);
}
static ssize_t store_pwm_auto_point1_pwm(struct device *dev,
struct device_attribute *devattr, const char *buf, size_t count)
{
int index = to_sensor_dev_attr(devattr)->index;
struct fschmd_data *data = dev_get_drvdata(dev);
unsigned long v;
int err;
err = kstrtoul(buf, 10, &v);
if (err)
return err;
if (v || data->kind == fscsyl) {
v = SENSORS_LIMIT(v, 128, 255);
v = (v - 128) * 2 + 1;
}
mutex_lock(&data->update_lock);
i2c_smbus_write_byte_data(to_i2c_client(dev),
FSCHMD_REG_FAN_MIN[data->kind][index], v);
data->fan_min[index] = v;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alert_led(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct fschmd_data *data = fschmd_update_device(dev);
if (data->global_control & FSCHMD_CONTROL_ALERT_LED)
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static ssize_t store_alert_led(struct device *dev,
struct device_attribute *devattr, const char *buf, size_t count)
{
u8 reg;
struct fschmd_data *data = dev_get_drvdata(dev);
unsigned long v;
int err;
err = kstrtoul(buf, 10, &v);
if (err)
return err;
mutex_lock(&data->update_lock);
reg = i2c_smbus_read_byte_data(to_i2c_client(dev), FSCHMD_REG_CONTROL);
if (v)
reg |= FSCHMD_CONTROL_ALERT_LED;
else
reg &= ~FSCHMD_CONTROL_ALERT_LED;
i2c_smbus_write_byte_data(to_i2c_client(dev), FSCHMD_REG_CONTROL, reg);
data->global_control = reg;
mutex_unlock(&data->update_lock);
return count;
}
static int watchdog_set_timeout(struct fschmd_data *data, int timeout)
{
int ret, resolution;
int kind = data->kind + 1;
if (timeout <= 510 || kind == fscpos || kind == fscscy)
resolution = 2;
else
resolution = 60;
if (timeout < resolution || timeout > (resolution * 255))
return -EINVAL;
mutex_lock(&data->watchdog_lock);
if (!data->client) {
ret = -ENODEV;
goto leave;
}
if (resolution == 2)
data->watchdog_control &= ~FSCHMD_WDOG_CONTROL_RESOLUTION;
else
data->watchdog_control |= FSCHMD_WDOG_CONTROL_RESOLUTION;
data->watchdog_preset = DIV_ROUND_UP(timeout, resolution);
i2c_smbus_write_byte_data(data->client,
FSCHMD_REG_WDOG_PRESET[data->kind], data->watchdog_preset);
i2c_smbus_write_byte_data(data->client,
FSCHMD_REG_WDOG_CONTROL[data->kind],
data->watchdog_control & ~FSCHMD_WDOG_CONTROL_TRIGGER);
ret = data->watchdog_preset * resolution;
leave:
mutex_unlock(&data->watchdog_lock);
return ret;
}
static int watchdog_get_timeout(struct fschmd_data *data)
{
int timeout;
mutex_lock(&data->watchdog_lock);
if (data->watchdog_control & FSCHMD_WDOG_CONTROL_RESOLUTION)
timeout = data->watchdog_preset * 60;
else
timeout = data->watchdog_preset * 2;
mutex_unlock(&data->watchdog_lock);
return timeout;
}
static int watchdog_trigger(struct fschmd_data *data)
{
int ret = 0;
mutex_lock(&data->watchdog_lock);
if (!data->client) {
ret = -ENODEV;
goto leave;
}
data->watchdog_control |= FSCHMD_WDOG_CONTROL_TRIGGER;
i2c_smbus_write_byte_data(data->client,
FSCHMD_REG_WDOG_CONTROL[data->kind],
data->watchdog_control);
leave:
mutex_unlock(&data->watchdog_lock);
return ret;
}
static int watchdog_stop(struct fschmd_data *data)
{
int ret = 0;
mutex_lock(&data->watchdog_lock);
if (!data->client) {
ret = -ENODEV;
goto leave;
}
data->watchdog_control &= ~FSCHMD_WDOG_CONTROL_STARTED;
i2c_smbus_write_byte_data(data->client,
FSCHMD_REG_WDOG_CONTROL[data->kind],
data->watchdog_control | FSCHMD_WDOG_CONTROL_STOP);
leave:
mutex_unlock(&data->watchdog_lock);
return ret;
}
static int watchdog_open(struct inode *inode, struct file *filp)
{
struct fschmd_data *pos, *data = NULL;
int watchdog_is_open;
if (!mutex_trylock(&watchdog_data_mutex))
return -ERESTARTSYS;
list_for_each_entry(pos, &watchdog_data_list, list) {
if (pos->watchdog_miscdev.minor == iminor(inode)) {
data = pos;
break;
}
}
watchdog_is_open = test_and_set_bit(0, &data->watchdog_is_open);
if (!watchdog_is_open)
kref_get(&data->kref);
mutex_unlock(&watchdog_data_mutex);
if (watchdog_is_open)
return -EBUSY;
watchdog_trigger(data);
filp->private_data = data;
return nonseekable_open(inode, filp);
}
static int watchdog_release(struct inode *inode, struct file *filp)
{
struct fschmd_data *data = filp->private_data;
if (data->watchdog_expect_close) {
watchdog_stop(data);
data->watchdog_expect_close = 0;
} else {
watchdog_trigger(data);
dev_crit(&data->client->dev,
"unexpected close, not stopping watchdog!\n");
}
clear_bit(0, &data->watchdog_is_open);
mutex_lock(&watchdog_data_mutex);
kref_put(&data->kref, fschmd_release_resources);
mutex_unlock(&watchdog_data_mutex);
return 0;
}
static ssize_t watchdog_write(struct file *filp, const char __user *buf,
size_t count, loff_t *offset)
{
int ret;
struct fschmd_data *data = filp->private_data;
if (count) {
if (!nowayout) {
size_t i;
data->watchdog_expect_close = 0;
for (i = 0; i != count; i++) {
char c;
if (get_user(c, buf + i))
return -EFAULT;
if (c == 'V')
data->watchdog_expect_close = 1;
}
}
ret = watchdog_trigger(data);
if (ret < 0)
return ret;
}
return count;
}
static long watchdog_ioctl(struct file *filp, unsigned int cmd,
unsigned long arg)
{
struct watchdog_info ident = {
.options = WDIOF_KEEPALIVEPING | WDIOF_SETTIMEOUT |
WDIOF_CARDRESET,
.identity = "FSC watchdog"
};
int i, ret = 0;
struct fschmd_data *data = filp->private_data;
switch (cmd) {
case WDIOC_GETSUPPORT:
ident.firmware_version = data->revision;
if (!nowayout)
ident.options |= WDIOF_MAGICCLOSE;
if (copy_to_user((void __user *)arg, &ident, sizeof(ident)))
ret = -EFAULT;
break;
case WDIOC_GETSTATUS:
ret = put_user(0, (int __user *)arg);
break;
case WDIOC_GETBOOTSTATUS:
if (data->watchdog_state & FSCHMD_WDOG_STATE_CARDRESET)
ret = put_user(WDIOF_CARDRESET, (int __user *)arg);
else
ret = put_user(0, (int __user *)arg);
break;
case WDIOC_KEEPALIVE:
ret = watchdog_trigger(data);
break;
case WDIOC_GETTIMEOUT:
i = watchdog_get_timeout(data);
ret = put_user(i, (int __user *)arg);
break;
case WDIOC_SETTIMEOUT:
if (get_user(i, (int __user *)arg)) {
ret = -EFAULT;
break;
}
ret = watchdog_set_timeout(data, i);
if (ret > 0)
ret = put_user(ret, (int __user *)arg);
break;
case WDIOC_SETOPTIONS:
if (get_user(i, (int __user *)arg)) {
ret = -EFAULT;
break;
}
if (i & WDIOS_DISABLECARD)
ret = watchdog_stop(data);
else if (i & WDIOS_ENABLECARD)
ret = watchdog_trigger(data);
else
ret = -EINVAL;
break;
default:
ret = -ENOTTY;
}
return ret;
}
static void fschmd_dmi_decode(const struct dmi_header *header, void *dummy)
{
int i, mult[3] = { 0 }, offset[3] = { 0 }, vref = 0, found = 0;
u8 *dmi_data = (u8 *)header;
if (header->type != 185)
return;
if (header->length < 5 || dmi_data[4] != 19)
return;
for (i = 6; (i + 4) < header->length; i += 5) {
if (dmi_data[i] >= 1 && dmi_data[i] <= 3) {
const int shuffle[3] = { 1, 0, 2 };
int in = shuffle[dmi_data[i] - 1];
if (found & (1 << in))
return;
mult[in] = dmi_data[i + 1] | (dmi_data[i + 2] << 8);
offset[in] = dmi_data[i + 3] | (dmi_data[i + 4] << 8);
found |= 1 << in;
}
if (dmi_data[i] == 7) {
if (found & 0x08)
return;
vref = dmi_data[i + 1] | (dmi_data[i + 2] << 8);
found |= 0x08;
}
}
if (found == 0x0F) {
for (i = 0; i < 3; i++) {
dmi_mult[i] = mult[i] * 10;
dmi_offset[i] = offset[i] * 10;
}
dmi_mult[3] = dmi_mult[2];
dmi_mult[4] = dmi_mult[1];
dmi_mult[5] = dmi_mult[2];
dmi_offset[3] = dmi_offset[2];
dmi_offset[4] = dmi_offset[1];
dmi_offset[5] = dmi_offset[2];
dmi_vref = vref;
}
}
static int fschmd_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
enum chips kind;
struct i2c_adapter *adapter = client->adapter;
char id[4];
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
id[0] = i2c_smbus_read_byte_data(client, FSCHMD_REG_IDENT_0);
id[1] = i2c_smbus_read_byte_data(client, FSCHMD_REG_IDENT_1);
id[2] = i2c_smbus_read_byte_data(client, FSCHMD_REG_IDENT_2);
id[3] = '\0';
if (!strcmp(id, "PEG"))
kind = fscpos;
else if (!strcmp(id, "HER"))
kind = fscher;
else if (!strcmp(id, "SCY"))
kind = fscscy;
else if (!strcmp(id, "HRC"))
kind = fschrc;
else if (!strcmp(id, "HMD"))
kind = fschmd;
else if (!strcmp(id, "HDS"))
kind = fschds;
else if (!strcmp(id, "SYL"))
kind = fscsyl;
else
return -ENODEV;
strlcpy(info->type, fschmd_id[kind].name, I2C_NAME_SIZE);
return 0;
}
static int fschmd_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct fschmd_data *data;
const char * const names[7] = { "Poseidon", "Hermes", "Scylla",
"Heracles", "Heimdall", "Hades", "Syleus" };
const int watchdog_minors[] = { WATCHDOG_MINOR, 212, 213, 214, 215 };
int i, err;
enum chips kind = id->driver_data;
data = kzalloc(sizeof(struct fschmd_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
mutex_init(&data->watchdog_lock);
INIT_LIST_HEAD(&data->list);
kref_init(&data->kref);
data->client = client;
data->kind = kind;
if (kind == fscpos) {
data->temp_max[0] = 70 + 128;
data->temp_max[1] = 50 + 128;
data->temp_max[2] = 50 + 128;
}
if ((kind == fscher || kind >= fschrc) && dmi_vref == -1) {
dmi_walk(fschmd_dmi_decode, NULL);
if (dmi_vref == -1) {
dev_warn(&client->dev,
"Couldn't get voltage scaling factors from "
"BIOS DMI table, using builtin defaults\n");
dmi_vref = 33;
}
}
data->revision = i2c_smbus_read_byte_data(client, FSCHMD_REG_REVISION);
data->global_control = i2c_smbus_read_byte_data(client,
FSCHMD_REG_CONTROL);
data->watchdog_control = i2c_smbus_read_byte_data(client,
FSCHMD_REG_WDOG_CONTROL[data->kind]);
data->watchdog_state = i2c_smbus_read_byte_data(client,
FSCHMD_REG_WDOG_STATE[data->kind]);
data->watchdog_preset = i2c_smbus_read_byte_data(client,
FSCHMD_REG_WDOG_PRESET[data->kind]);
err = device_create_file(&client->dev, &dev_attr_alert_led);
if (err)
goto exit_detach;
for (i = 0; i < FSCHMD_NO_VOLT_SENSORS[data->kind]; i++) {
err = device_create_file(&client->dev,
&fschmd_attr[i].dev_attr);
if (err)
goto exit_detach;
}
for (i = 0; i < (FSCHMD_NO_TEMP_SENSORS[data->kind] * 4); i++) {
if (kind == fscpos && fschmd_temp_attr[i].dev_attr.show ==
show_temp_max)
continue;
if (kind == fscsyl) {
if (i % 4 == 0)
data->temp_status[i / 4] =
i2c_smbus_read_byte_data(client,
FSCHMD_REG_TEMP_STATE
[data->kind][i / 4]);
if (data->temp_status[i / 4] & FSCHMD_TEMP_DISABLED)
continue;
}
err = device_create_file(&client->dev,
&fschmd_temp_attr[i].dev_attr);
if (err)
goto exit_detach;
}
for (i = 0; i < (FSCHMD_NO_FAN_SENSORS[data->kind] * 5); i++) {
if (kind == fscpos &&
!strcmp(fschmd_fan_attr[i].dev_attr.attr.name,
"pwm3_auto_point1_pwm"))
continue;
if (kind == fscsyl) {
if (i % 5 == 0)
data->fan_status[i / 5] =
i2c_smbus_read_byte_data(client,
FSCHMD_REG_FAN_STATE
[data->kind][i / 5]);
if (data->fan_status[i / 5] & FSCHMD_FAN_DISABLED)
continue;
}
err = device_create_file(&client->dev,
&fschmd_fan_attr[i].dev_attr);
if (err)
goto exit_detach;
}
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
data->hwmon_dev = NULL;
goto exit_detach;
}
mutex_lock(&watchdog_data_mutex);
for (i = 0; i < ARRAY_SIZE(watchdog_minors); i++) {
snprintf(data->watchdog_name, sizeof(data->watchdog_name),
"watchdog%c", (i == 0) ? '\0' : ('0' + i));
data->watchdog_miscdev.name = data->watchdog_name;
data->watchdog_miscdev.fops = &watchdog_fops;
data->watchdog_miscdev.minor = watchdog_minors[i];
err = misc_register(&data->watchdog_miscdev);
if (err == -EBUSY)
continue;
if (err) {
data->watchdog_miscdev.minor = 0;
dev_err(&client->dev,
"Registering watchdog chardev: %d\n", err);
break;
}
list_add(&data->list, &watchdog_data_list);
watchdog_set_timeout(data, 60);
dev_info(&client->dev,
"Registered watchdog chardev major 10, minor: %d\n",
watchdog_minors[i]);
break;
}
if (i == ARRAY_SIZE(watchdog_minors)) {
data->watchdog_miscdev.minor = 0;
dev_warn(&client->dev, "Couldn't register watchdog chardev "
"(due to no free minor)\n");
}
mutex_unlock(&watchdog_data_mutex);
dev_info(&client->dev, "Detected FSC %s chip, revision: %d\n",
names[data->kind], (int) data->revision);
return 0;
exit_detach:
fschmd_remove(client);
return err;
}
static int fschmd_remove(struct i2c_client *client)
{
struct fschmd_data *data = i2c_get_clientdata(client);
int i;
if (data->watchdog_miscdev.minor) {
misc_deregister(&data->watchdog_miscdev);
if (data->watchdog_is_open) {
dev_warn(&client->dev,
"i2c client detached with watchdog open! "
"Stopping watchdog.\n");
watchdog_stop(data);
}
mutex_lock(&watchdog_data_mutex);
list_del(&data->list);
mutex_unlock(&watchdog_data_mutex);
mutex_lock(&data->watchdog_lock);
data->client = NULL;
mutex_unlock(&data->watchdog_lock);
}
if (data->hwmon_dev)
hwmon_device_unregister(data->hwmon_dev);
device_remove_file(&client->dev, &dev_attr_alert_led);
for (i = 0; i < (FSCHMD_NO_VOLT_SENSORS[data->kind]); i++)
device_remove_file(&client->dev, &fschmd_attr[i].dev_attr);
for (i = 0; i < (FSCHMD_NO_TEMP_SENSORS[data->kind] * 4); i++)
device_remove_file(&client->dev,
&fschmd_temp_attr[i].dev_attr);
for (i = 0; i < (FSCHMD_NO_FAN_SENSORS[data->kind] * 5); i++)
device_remove_file(&client->dev,
&fschmd_fan_attr[i].dev_attr);
mutex_lock(&watchdog_data_mutex);
kref_put(&data->kref, fschmd_release_resources);
mutex_unlock(&watchdog_data_mutex);
return 0;
}
static struct fschmd_data *fschmd_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct fschmd_data *data = i2c_get_clientdata(client);
int i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + 2 * HZ) || !data->valid) {
for (i = 0; i < FSCHMD_NO_TEMP_SENSORS[data->kind]; i++) {
data->temp_act[i] = i2c_smbus_read_byte_data(client,
FSCHMD_REG_TEMP_ACT[data->kind][i]);
data->temp_status[i] = i2c_smbus_read_byte_data(client,
FSCHMD_REG_TEMP_STATE[data->kind][i]);
if (FSCHMD_REG_TEMP_LIMIT[data->kind][i])
data->temp_max[i] = i2c_smbus_read_byte_data(
client,
FSCHMD_REG_TEMP_LIMIT[data->kind][i]);
if ((data->temp_status[i] & FSCHMD_TEMP_ALARM_MASK) ==
FSCHMD_TEMP_ALARM_MASK &&
data->temp_act[i] < data->temp_max[i])
i2c_smbus_write_byte_data(client,
FSCHMD_REG_TEMP_STATE[data->kind][i],
data->temp_status[i]);
}
for (i = 0; i < FSCHMD_NO_FAN_SENSORS[data->kind]; i++) {
data->fan_act[i] = i2c_smbus_read_byte_data(client,
FSCHMD_REG_FAN_ACT[data->kind][i]);
data->fan_status[i] = i2c_smbus_read_byte_data(client,
FSCHMD_REG_FAN_STATE[data->kind][i]);
data->fan_ripple[i] = i2c_smbus_read_byte_data(client,
FSCHMD_REG_FAN_RIPPLE[data->kind][i]);
if (FSCHMD_REG_FAN_MIN[data->kind][i])
data->fan_min[i] = i2c_smbus_read_byte_data(
client,
FSCHMD_REG_FAN_MIN[data->kind][i]);
if ((data->fan_status[i] & FSCHMD_FAN_ALARM) &&
data->fan_act[i])
i2c_smbus_write_byte_data(client,
FSCHMD_REG_FAN_STATE[data->kind][i],
data->fan_status[i]);
}
for (i = 0; i < FSCHMD_NO_VOLT_SENSORS[data->kind]; i++)
data->volt[i] = i2c_smbus_read_byte_data(client,
FSCHMD_REG_VOLT[data->kind][i]);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
