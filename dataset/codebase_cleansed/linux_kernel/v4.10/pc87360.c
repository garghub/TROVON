static inline void superio_outb(int sioaddr, int reg, int val)
{
outb(reg, sioaddr);
outb(val, sioaddr + 1);
}
static inline int superio_inb(int sioaddr, int reg)
{
outb(reg, sioaddr);
return inb(sioaddr + 1);
}
static inline void superio_exit(int sioaddr)
{
outb(0x02, sioaddr);
outb(0x02, sioaddr + 1);
}
static inline u8 PWM_TO_REG(int val, int inv)
{
if (inv)
val = 255 - val;
if (val < 0)
return 0;
if (val > 255)
return 255;
return val;
}
static ssize_t show_fan_input(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%u\n", FAN_FROM_REG(data->fan[attr->index],
FAN_DIV_FROM_REG(data->fan_status[attr->index])));
}
static ssize_t show_fan_min(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%u\n", FAN_FROM_REG(data->fan_min[attr->index],
FAN_DIV_FROM_REG(data->fan_status[attr->index])));
}
static ssize_t show_fan_div(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%u\n",
FAN_DIV_FROM_REG(data->fan_status[attr->index]));
}
static ssize_t show_fan_status(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%u\n",
FAN_STATUS_FROM_REG(data->fan_status[attr->index]));
}
static ssize_t set_fan_min(struct device *dev,
struct device_attribute *devattr, const char *buf,
size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = dev_get_drvdata(dev);
long fan_min;
int err;
err = kstrtol(buf, 10, &fan_min);
if (err)
return err;
mutex_lock(&data->update_lock);
fan_min = FAN_TO_REG(fan_min,
FAN_DIV_FROM_REG(data->fan_status[attr->index]));
while (fan_min > 255
&& (data->fan_status[attr->index] & 0x60) != 0x60) {
fan_min >>= 1;
data->fan[attr->index] >>= 1;
data->fan_status[attr->index] += 0x20;
}
data->fan_min[attr->index] = fan_min > 255 ? 255 : fan_min;
pc87360_write_value(data, LD_FAN, NO_BANK,
PC87360_REG_FAN_MIN(attr->index),
data->fan_min[attr->index]);
pc87360_write_value(data, LD_FAN, NO_BANK,
PC87360_REG_FAN_STATUS(attr->index),
data->fan_status[attr->index] & 0xF9);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%u\n",
PWM_FROM_REG(data->pwm[attr->index],
FAN_CONFIG_INVERT(data->fan_conf,
attr->index)));
}
static ssize_t set_pwm(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = dev_get_drvdata(dev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->pwm[attr->index] = PWM_TO_REG(val,
FAN_CONFIG_INVERT(data->fan_conf, attr->index));
pc87360_write_value(data, LD_FAN, NO_BANK, PC87360_REG_PWM(attr->index),
data->pwm[attr->index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_in_input(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%u\n", IN_FROM_REG(data->in[attr->index],
data->in_vref));
}
static ssize_t show_in_min(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%u\n", IN_FROM_REG(data->in_min[attr->index],
data->in_vref));
}
static ssize_t show_in_max(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%u\n", IN_FROM_REG(data->in_max[attr->index],
data->in_vref));
}
static ssize_t show_in_status(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%u\n", data->in_status[attr->index]);
}
static ssize_t set_in_min(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = dev_get_drvdata(dev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_min[attr->index] = IN_TO_REG(val, data->in_vref);
pc87360_write_value(data, LD_IN, attr->index, PC87365_REG_IN_MIN,
data->in_min[attr->index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_in_max(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = dev_get_drvdata(dev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_max[attr->index] = IN_TO_REG(val,
data->in_vref);
pc87360_write_value(data, LD_IN, attr->index, PC87365_REG_IN_MAX,
data->in_max[attr->index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_in_min_alarm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct pc87360_data *data = pc87360_update_device(dev);
unsigned nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%u\n", !!(data->in_status[nr] & CHAN_ALM_MIN));
}
static ssize_t show_in_max_alarm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct pc87360_data *data = pc87360_update_device(dev);
unsigned nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%u\n", !!(data->in_status[nr] & CHAN_ALM_MAX));
}
static ssize_t show_vid(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%u\n", vid_from_reg(data->vid, data->vrm));
}
static ssize_t show_vrm(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct pc87360_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", data->vrm);
}
static ssize_t set_vrm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct pc87360_data *data = dev_get_drvdata(dev);
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
static ssize_t show_in_alarms(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%u\n", data->in_alarms);
}
static ssize_t show_therm_input(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%u\n", IN_FROM_REG(data->in[attr->index],
data->in_vref));
}
static ssize_t show_therm_min(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%u\n", IN_FROM_REG(data->in_min[attr->index],
data->in_vref));
}
static ssize_t show_therm_max(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%u\n", IN_FROM_REG(data->in_max[attr->index],
data->in_vref));
}
static ssize_t show_therm_crit(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%u\n", IN_FROM_REG(data->in_crit[attr->index-11],
data->in_vref));
}
static ssize_t show_therm_status(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%u\n", data->in_status[attr->index]);
}
static ssize_t set_therm_min(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = dev_get_drvdata(dev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_min[attr->index] = IN_TO_REG(val, data->in_vref);
pc87360_write_value(data, LD_IN, attr->index, PC87365_REG_TEMP_MIN,
data->in_min[attr->index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_therm_max(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = dev_get_drvdata(dev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_max[attr->index] = IN_TO_REG(val, data->in_vref);
pc87360_write_value(data, LD_IN, attr->index, PC87365_REG_TEMP_MAX,
data->in_max[attr->index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_therm_crit(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = dev_get_drvdata(dev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_crit[attr->index-11] = IN_TO_REG(val, data->in_vref);
pc87360_write_value(data, LD_IN, attr->index, PC87365_REG_TEMP_CRIT,
data->in_crit[attr->index-11]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_therm_min_alarm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct pc87360_data *data = pc87360_update_device(dev);
unsigned nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%u\n", !!(data->in_status[nr] & CHAN_ALM_MIN));
}
static ssize_t show_therm_max_alarm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct pc87360_data *data = pc87360_update_device(dev);
unsigned nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%u\n", !!(data->in_status[nr] & CHAN_ALM_MAX));
}
static ssize_t show_therm_crit_alarm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct pc87360_data *data = pc87360_update_device(dev);
unsigned nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%u\n", !!(data->in_status[nr] & TEMP_ALM_CRIT));
}
static ssize_t show_temp_input(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[attr->index]));
}
static ssize_t show_temp_min(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_min[attr->index]));
}
static ssize_t show_temp_max(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_max[attr->index]));
}
static ssize_t show_temp_crit(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%d\n",
TEMP_FROM_REG(data->temp_crit[attr->index]));
}
static ssize_t show_temp_status(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%d\n", data->temp_status[attr->index]);
}
static ssize_t set_temp_min(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = dev_get_drvdata(dev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_min[attr->index] = TEMP_TO_REG(val);
pc87360_write_value(data, LD_TEMP, attr->index, PC87365_REG_TEMP_MIN,
data->temp_min[attr->index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_temp_max(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = dev_get_drvdata(dev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_max[attr->index] = TEMP_TO_REG(val);
pc87360_write_value(data, LD_TEMP, attr->index, PC87365_REG_TEMP_MAX,
data->temp_max[attr->index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_temp_crit(struct device *dev,
struct device_attribute *devattr, const char *buf,
size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct pc87360_data *data = dev_get_drvdata(dev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_crit[attr->index] = TEMP_TO_REG(val);
pc87360_write_value(data, LD_TEMP, attr->index, PC87365_REG_TEMP_CRIT,
data->temp_crit[attr->index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_alarms(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct pc87360_data *data = pc87360_update_device(dev);
return sprintf(buf, "%u\n", data->temp_alarms);
}
static ssize_t show_temp_min_alarm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct pc87360_data *data = pc87360_update_device(dev);
unsigned nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%u\n", !!(data->temp_status[nr] & CHAN_ALM_MIN));
}
static ssize_t show_temp_max_alarm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct pc87360_data *data = pc87360_update_device(dev);
unsigned nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%u\n", !!(data->temp_status[nr] & CHAN_ALM_MAX));
}
static ssize_t show_temp_crit_alarm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct pc87360_data *data = pc87360_update_device(dev);
unsigned nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%u\n", !!(data->temp_status[nr] & TEMP_ALM_CRIT));
}
static ssize_t show_temp_fault(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct pc87360_data *data = pc87360_update_device(dev);
unsigned nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%u\n", !!(data->temp_status[nr] & TEMP_FAULT));
}
static ssize_t show_name(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct pc87360_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", data->name);
}
static int __init pc87360_find(int sioaddr, u8 *devid,
unsigned short *addresses)
{
u16 val;
int i;
int nrdev;
val = force_id ? force_id : superio_inb(sioaddr, DEVID);
switch (val) {
case 0xE1:
case 0xE8:
case 0xE4:
nrdev = 1;
break;
case 0xE5:
case 0xE9:
nrdev = 3;
break;
default:
superio_exit(sioaddr);
return -ENODEV;
}
*devid = val;
for (i = 0; i < nrdev; i++) {
superio_outb(sioaddr, DEV, logdev[i]);
val = superio_inb(sioaddr, ACT);
if (!(val & 0x01)) {
pr_info("Device 0x%02x not activated\n", logdev[i]);
continue;
}
val = (superio_inb(sioaddr, BASE) << 8)
| superio_inb(sioaddr, BASE + 1);
if (!val) {
pr_info("Base address not set for device 0x%02x\n",
logdev[i]);
continue;
}
addresses[i] = val;
if (i == 0) {
confreg[0] = superio_inb(sioaddr, 0xF0);
confreg[1] = superio_inb(sioaddr, 0xF1);
pr_debug("Fan %d: mon=%d ctrl=%d inv=%d\n", 1,
(confreg[0] >> 2) & 1, (confreg[0] >> 3) & 1,
(confreg[0] >> 4) & 1);
pr_debug("Fan %d: mon=%d ctrl=%d inv=%d\n", 2,
(confreg[0] >> 5) & 1, (confreg[0] >> 6) & 1,
(confreg[0] >> 7) & 1);
pr_debug("Fan %d: mon=%d ctrl=%d inv=%d\n", 3,
confreg[1] & 1, (confreg[1] >> 1) & 1,
(confreg[1] >> 2) & 1);
} else if (i == 1) {
if (*devid == 0xE9) {
confreg[2] = superio_inb(sioaddr, 0x2B);
confreg[3] = superio_inb(sioaddr, 0x25);
if (confreg[2] & 0x40) {
pr_info("Using thermistors for temperature monitoring\n");
}
if (confreg[3] & 0xE0) {
pr_info("VID inputs routed (mode %u)\n",
confreg[3] >> 5);
}
}
}
}
superio_exit(sioaddr);
return 0;
}
static void pc87360_remove_files(struct device *dev)
{
int i;
device_remove_file(dev, &dev_attr_name);
device_remove_file(dev, &dev_attr_alarms_temp);
for (i = 0; i < ARRAY_SIZE(pc8736x_temp_attr_group); i++)
sysfs_remove_group(&dev->kobj, &pc8736x_temp_attr_group[i]);
for (i = 0; i < ARRAY_SIZE(pc8736x_fan_attr_group); i++) {
sysfs_remove_group(&pdev->dev.kobj, &pc8736x_fan_attr_group[i]);
device_remove_file(dev, &pwm[i].dev_attr);
}
sysfs_remove_group(&dev->kobj, &pc8736x_therm_group);
sysfs_remove_group(&dev->kobj, &pc8736x_vin_group);
}
static int pc87360_probe(struct platform_device *pdev)
{
int i;
struct pc87360_data *data;
int err = 0;
const char *name;
int use_thermistors = 0;
struct device *dev = &pdev->dev;
data = devm_kzalloc(dev, sizeof(struct pc87360_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
switch (devid) {
default:
name = "pc87360";
data->fannr = 2;
break;
case 0xe8:
name = "pc87363";
data->fannr = 2;
break;
case 0xe4:
name = "pc87364";
data->fannr = 3;
break;
case 0xe5:
name = "pc87365";
data->fannr = extra_isa[0] ? 3 : 0;
data->innr = extra_isa[1] ? 11 : 0;
data->tempnr = extra_isa[2] ? 2 : 0;
break;
case 0xe9:
name = "pc87366";
data->fannr = extra_isa[0] ? 3 : 0;
data->innr = extra_isa[1] ? 14 : 0;
data->tempnr = extra_isa[2] ? 3 : 0;
break;
}
data->name = name;
mutex_init(&data->lock);
mutex_init(&data->update_lock);
platform_set_drvdata(pdev, data);
for (i = 0; i < LDNI_MAX; i++) {
data->address[i] = extra_isa[i];
if (data->address[i]
&& !devm_request_region(dev, extra_isa[i], PC87360_EXTENT,
pc87360_driver.driver.name)) {
dev_err(dev,
"Region 0x%x-0x%x already in use!\n",
extra_isa[i], extra_isa[i]+PC87360_EXTENT-1);
return -EBUSY;
}
}
if (data->fannr)
data->fan_conf = confreg[0] | (confreg[1] << 8);
if (data->innr) {
i = pc87360_read_value(data, LD_IN, NO_BANK,
PC87365_REG_IN_CONFIG);
if (data->tempnr) {
i &= pc87360_read_value(data, LD_TEMP, NO_BANK,
PC87365_REG_TEMP_CONFIG);
}
data->in_vref = (i&0x02) ? 3025 : 2966;
dev_dbg(dev, "Using %s reference voltage\n",
(i&0x02) ? "external" : "internal");
data->vid_conf = confreg[3];
data->vrm = vid_which_vrm();
}
for (i = 0; i < data->fannr; i++) {
if (FAN_CONFIG_MONITOR(data->fan_conf, i))
data->fan_status[i] = pc87360_read_value(data,
LD_FAN, NO_BANK,
PC87360_REG_FAN_STATUS(i));
}
if (init > 0) {
if (devid == 0xe9 && data->address[1])
use_thermistors = confreg[2] & 0x40;
pc87360_init_device(pdev, use_thermistors);
}
if (data->innr) {
err = sysfs_create_group(&dev->kobj, &pc8736x_vin_group);
if (err)
goto error;
}
if (data->innr == 14) {
err = sysfs_create_group(&dev->kobj, &pc8736x_therm_group);
if (err)
goto error;
}
if (data->tempnr) {
for (i = 0; i < data->tempnr; i++) {
err = sysfs_create_group(&dev->kobj,
&pc8736x_temp_attr_group[i]);
if (err)
goto error;
}
err = device_create_file(dev, &dev_attr_alarms_temp);
if (err)
goto error;
}
for (i = 0; i < data->fannr; i++) {
if (FAN_CONFIG_MONITOR(data->fan_conf, i)) {
err = sysfs_create_group(&dev->kobj,
&pc8736x_fan_attr_group[i]);
if (err)
goto error;
}
if (FAN_CONFIG_CONTROL(data->fan_conf, i)) {
err = device_create_file(dev, &pwm[i].dev_attr);
if (err)
goto error;
}
}
err = device_create_file(dev, &dev_attr_name);
if (err)
goto error;
data->hwmon_dev = hwmon_device_register(dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto error;
}
return 0;
error:
pc87360_remove_files(dev);
return err;
}
static int pc87360_remove(struct platform_device *pdev)
{
struct pc87360_data *data = platform_get_drvdata(pdev);
hwmon_device_unregister(data->hwmon_dev);
pc87360_remove_files(&pdev->dev);
return 0;
}
static int pc87360_read_value(struct pc87360_data *data, u8 ldi, u8 bank,
u8 reg)
{
int res;
mutex_lock(&(data->lock));
if (bank != NO_BANK)
outb_p(bank, data->address[ldi] + PC87365_REG_BANK);
res = inb_p(data->address[ldi] + reg);
mutex_unlock(&(data->lock));
return res;
}
static void pc87360_write_value(struct pc87360_data *data, u8 ldi, u8 bank,
u8 reg, u8 value)
{
mutex_lock(&(data->lock));
if (bank != NO_BANK)
outb_p(bank, data->address[ldi] + PC87365_REG_BANK);
outb_p(value, data->address[ldi] + reg);
mutex_unlock(&(data->lock));
}
static void pc87360_init_device(struct platform_device *pdev,
int use_thermistors)
{
struct pc87360_data *data = platform_get_drvdata(pdev);
int i, nr;
const u8 init_in[14] = { 2, 2, 2, 2, 2, 2, 2, 1, 1, 3, 1, 2, 2, 2 };
const u8 init_temp[3] = { 2, 2, 1 };
u8 reg;
if (init >= 2 && data->innr) {
reg = pc87360_read_value(data, LD_IN, NO_BANK,
PC87365_REG_IN_CONVRATE);
dev_info(&pdev->dev,
"VLM conversion set to 1s period, 160us delay\n");
pc87360_write_value(data, LD_IN, NO_BANK,
PC87365_REG_IN_CONVRATE,
(reg & 0xC0) | 0x11);
}
nr = data->innr < 11 ? data->innr : 11;
for (i = 0; i < nr; i++) {
reg = pc87360_read_value(data, LD_IN, i,
PC87365_REG_IN_STATUS);
dev_dbg(&pdev->dev, "bios in%d status:0x%02x\n", i, reg);
if (init >= init_in[i]) {
if (!(reg & CHAN_ENA)) {
dev_dbg(&pdev->dev, "Forcibly enabling in%d\n",
i);
pc87360_write_value(data, LD_IN, i,
PC87365_REG_IN_STATUS,
(reg & 0x68) | 0x87);
}
}
}
dev_dbg(&pdev->dev, "bios thermistors:%d\n", use_thermistors);
for (i = 11; i < data->innr; i++) {
reg = pc87360_read_value(data, LD_IN, i,
PC87365_REG_TEMP_STATUS);
use_thermistors = use_thermistors || (reg & CHAN_ENA);
dev_dbg(&pdev->dev, "bios temp%d_status:0x%02x\n", i-7, reg);
}
dev_dbg(&pdev->dev, "using thermistors:%d\n", use_thermistors);
i = use_thermistors ? 2 : 0;
for (; i < data->tempnr; i++) {
reg = pc87360_read_value(data, LD_TEMP, i,
PC87365_REG_TEMP_STATUS);
dev_dbg(&pdev->dev, "bios temp%d_status:0x%02x\n", i + 1, reg);
if (init >= init_temp[i]) {
if (!(reg & CHAN_ENA)) {
dev_dbg(&pdev->dev,
"Forcibly enabling temp%d\n", i + 1);
pc87360_write_value(data, LD_TEMP, i,
PC87365_REG_TEMP_STATUS,
0xCF);
}
}
}
if (use_thermistors) {
for (i = 11; i < data->innr; i++) {
if (init >= init_in[i]) {
reg = pc87360_read_value(data, LD_TEMP,
(i - 11) / 2, PC87365_REG_TEMP_STATUS);
if (reg & CHAN_ENA) {
dev_dbg(&pdev->dev,
"Skipping temp%d, pin already in use by temp%d\n",
i - 7, (i - 11) / 2);
continue;
}
reg = pc87360_read_value(data, LD_IN, i,
PC87365_REG_IN_STATUS);
if (!(reg & CHAN_ENA)) {
dev_dbg(&pdev->dev,
"Forcibly enabling temp%d\n",
i - 7);
pc87360_write_value(data, LD_IN, i,
PC87365_REG_TEMP_STATUS,
(reg & 0x60) | 0x8F);
}
}
}
}
if (data->innr) {
reg = pc87360_read_value(data, LD_IN, NO_BANK,
PC87365_REG_IN_CONFIG);
dev_dbg(&pdev->dev, "bios vin-cfg:0x%02x\n", reg);
if (reg & CHAN_ENA) {
dev_dbg(&pdev->dev,
"Forcibly enabling monitoring (VLM)\n");
pc87360_write_value(data, LD_IN, NO_BANK,
PC87365_REG_IN_CONFIG,
reg & 0xFE);
}
}
if (data->tempnr) {
reg = pc87360_read_value(data, LD_TEMP, NO_BANK,
PC87365_REG_TEMP_CONFIG);
dev_dbg(&pdev->dev, "bios temp-cfg:0x%02x\n", reg);
if (reg & CHAN_ENA) {
dev_dbg(&pdev->dev,
"Forcibly enabling monitoring (TMS)\n");
pc87360_write_value(data, LD_TEMP, NO_BANK,
PC87365_REG_TEMP_CONFIG,
reg & 0xFE);
}
if (init >= 2) {
pc87360_write_value(data, LD_TEMP, 0xF, 0xA, 0x08);
pc87360_write_value(data, LD_TEMP, NO_BANK, 0xB, 0x04);
pc87360_write_value(data, LD_TEMP, NO_BANK, 0xC, 0x35);
pc87360_write_value(data, LD_TEMP, NO_BANK, 0xD, 0x05);
pc87360_write_value(data, LD_TEMP, NO_BANK, 0xE, 0x05);
}
}
}
static void pc87360_autodiv(struct device *dev, int nr)
{
struct pc87360_data *data = dev_get_drvdata(dev);
u8 old_min = data->fan_min[nr];
if ((data->fan_status[nr] & 0x04)
|| (data->fan[nr] >= 224)) {
if ((data->fan_status[nr] & 0x60) != 0x60) {
data->fan_status[nr] += 0x20;
data->fan_min[nr] >>= 1;
data->fan[nr] >>= 1;
dev_dbg(dev,
"Increasing clock divider to %d for fan %d\n",
FAN_DIV_FROM_REG(data->fan_status[nr]), nr + 1);
}
} else {
while (!(data->fan_min[nr] & 0x80)
&& data->fan[nr] < 85
&& (data->fan_status[nr] & 0x60) != 0x00) {
data->fan_status[nr] -= 0x20;
data->fan_min[nr] <<= 1;
data->fan[nr] <<= 1;
dev_dbg(dev,
"Decreasing clock divider to %d for fan %d\n",
FAN_DIV_FROM_REG(data->fan_status[nr]),
nr + 1);
}
}
if (old_min != data->fan_min[nr]) {
pc87360_write_value(data, LD_FAN, NO_BANK,
PC87360_REG_FAN_MIN(nr),
data->fan_min[nr]);
}
}
static struct pc87360_data *pc87360_update_device(struct device *dev)
{
struct pc87360_data *data = dev_get_drvdata(dev);
u8 i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ * 2) || !data->valid) {
dev_dbg(dev, "Data update\n");
for (i = 0; i < data->fannr; i++) {
if (FAN_CONFIG_MONITOR(data->fan_conf, i)) {
data->fan_status[i] =
pc87360_read_value(data, LD_FAN,
NO_BANK, PC87360_REG_FAN_STATUS(i));
data->fan[i] = pc87360_read_value(data, LD_FAN,
NO_BANK, PC87360_REG_FAN(i));
data->fan_min[i] = pc87360_read_value(data,
LD_FAN, NO_BANK,
PC87360_REG_FAN_MIN(i));
pc87360_autodiv(dev, i);
pc87360_write_value(data, LD_FAN, NO_BANK,
PC87360_REG_FAN_STATUS(i),
data->fan_status[i]);
}
if (FAN_CONFIG_CONTROL(data->fan_conf, i))
data->pwm[i] = pc87360_read_value(data, LD_FAN,
NO_BANK, PC87360_REG_PWM(i));
}
for (i = 0; i < data->innr; i++) {
data->in_status[i] = pc87360_read_value(data, LD_IN, i,
PC87365_REG_IN_STATUS);
pc87360_write_value(data, LD_IN, i,
PC87365_REG_IN_STATUS,
data->in_status[i]);
if ((data->in_status[i] & CHAN_READY) == CHAN_READY) {
data->in[i] = pc87360_read_value(data, LD_IN,
i, PC87365_REG_IN);
}
if (data->in_status[i] & CHAN_ENA) {
data->in_min[i] = pc87360_read_value(data,
LD_IN, i,
PC87365_REG_IN_MIN);
data->in_max[i] = pc87360_read_value(data,
LD_IN, i,
PC87365_REG_IN_MAX);
if (i >= 11)
data->in_crit[i-11] =
pc87360_read_value(data, LD_IN,
i, PC87365_REG_TEMP_CRIT);
}
}
if (data->innr) {
data->in_alarms = pc87360_read_value(data, LD_IN,
NO_BANK, PC87365_REG_IN_ALARMS1)
| ((pc87360_read_value(data, LD_IN,
NO_BANK, PC87365_REG_IN_ALARMS2)
& 0x07) << 8);
data->vid = (data->vid_conf & 0xE0) ?
pc87360_read_value(data, LD_IN,
NO_BANK, PC87365_REG_VID) : 0x1F;
}
for (i = 0; i < data->tempnr; i++) {
data->temp_status[i] = pc87360_read_value(data,
LD_TEMP, i,
PC87365_REG_TEMP_STATUS);
pc87360_write_value(data, LD_TEMP, i,
PC87365_REG_TEMP_STATUS,
data->temp_status[i]);
if ((data->temp_status[i] & CHAN_READY) == CHAN_READY) {
data->temp[i] = pc87360_read_value(data,
LD_TEMP, i,
PC87365_REG_TEMP);
}
if (data->temp_status[i] & CHAN_ENA) {
data->temp_min[i] = pc87360_read_value(data,
LD_TEMP, i,
PC87365_REG_TEMP_MIN);
data->temp_max[i] = pc87360_read_value(data,
LD_TEMP, i,
PC87365_REG_TEMP_MAX);
data->temp_crit[i] = pc87360_read_value(data,
LD_TEMP, i,
PC87365_REG_TEMP_CRIT);
}
}
if (data->tempnr) {
data->temp_alarms = pc87360_read_value(data, LD_TEMP,
NO_BANK, PC87365_REG_TEMP_ALARMS)
& 0x3F;
}
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static int __init pc87360_device_add(unsigned short address)
{
struct resource res[3];
int err, i, res_count;
pdev = platform_device_alloc("pc87360", address);
if (!pdev) {
err = -ENOMEM;
pr_err("Device allocation failed\n");
goto exit;
}
memset(res, 0, 3 * sizeof(struct resource));
res_count = 0;
for (i = 0; i < 3; i++) {
if (!extra_isa[i])
continue;
res[res_count].start = extra_isa[i];
res[res_count].end = extra_isa[i] + PC87360_EXTENT - 1;
res[res_count].name = "pc87360",
res[res_count].flags = IORESOURCE_IO,
err = acpi_check_resource_conflict(&res[res_count]);
if (err)
goto exit_device_put;
res_count++;
}
err = platform_device_add_resources(pdev, res, res_count);
if (err) {
pr_err("Device resources addition failed (%d)\n", err);
goto exit_device_put;
}
err = platform_device_add(pdev);
if (err) {
pr_err("Device addition failed (%d)\n", err);
goto exit_device_put;
}
return 0;
exit_device_put:
platform_device_put(pdev);
exit:
return err;
}
static int __init pc87360_init(void)
{
int err, i;
unsigned short address = 0;
if (pc87360_find(0x2e, &devid, extra_isa)
&& pc87360_find(0x4e, &devid, extra_isa)) {
pr_warn("PC8736x not detected, module not inserted\n");
return -ENODEV;
}
for (i = 0; i < 3; i++) {
if (extra_isa[i] != 0x0000) {
address = extra_isa[i];
break;
}
}
if (address == 0x0000) {
pr_warn("No active logical device, module not inserted\n");
return -ENODEV;
}
err = platform_driver_register(&pc87360_driver);
if (err)
goto exit;
err = pc87360_device_add(address);
if (err)
goto exit_driver;
return 0;
exit_driver:
platform_driver_unregister(&pc87360_driver);
exit:
return err;
}
static void __exit pc87360_exit(void)
{
platform_device_unregister(pdev);
platform_driver_unregister(&pc87360_driver);
}
