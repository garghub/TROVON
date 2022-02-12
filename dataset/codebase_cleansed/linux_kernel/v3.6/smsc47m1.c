static inline void
superio_outb(int reg, int val)
{
outb(reg, REG);
outb(val, VAL);
}
static inline int
superio_inb(int reg)
{
outb(reg, REG);
return inb(VAL);
}
static inline void
superio_enter(void)
{
outb(0x55, REG);
}
static inline void
superio_exit(void)
{
outb(0xAA, REG);
}
static inline int smsc47m1_read_value(struct smsc47m1_data *data, u8 reg)
{
return inb_p(data->addr + reg);
}
static inline void smsc47m1_write_value(struct smsc47m1_data *data, u8 reg,
u8 value)
{
outb_p(value, data->addr + reg);
}
static ssize_t get_fan(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct smsc47m1_data *data = smsc47m1_update_device(dev, 0);
int nr = attr->index;
int rpm = (data->pwm[nr] & 0x7F) == 0x00 ? 0 :
FAN_FROM_REG(data->fan[nr],
DIV_FROM_REG(data->fan_div[nr]),
data->fan_preload[nr]);
return sprintf(buf, "%d\n", rpm);
}
static ssize_t get_fan_min(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct smsc47m1_data *data = smsc47m1_update_device(dev, 0);
int nr = attr->index;
int rpm = MIN_FROM_REG(data->fan_preload[nr],
DIV_FROM_REG(data->fan_div[nr]));
return sprintf(buf, "%d\n", rpm);
}
static ssize_t get_fan_div(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct smsc47m1_data *data = smsc47m1_update_device(dev, 0);
return sprintf(buf, "%d\n", DIV_FROM_REG(data->fan_div[attr->index]));
}
static ssize_t get_fan_alarm(struct device *dev, struct device_attribute
*devattr, char *buf)
{
int bitnr = to_sensor_dev_attr(devattr)->index;
struct smsc47m1_data *data = smsc47m1_update_device(dev, 0);
return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}
static ssize_t get_pwm(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct smsc47m1_data *data = smsc47m1_update_device(dev, 0);
return sprintf(buf, "%d\n", PWM_FROM_REG(data->pwm[attr->index]));
}
static ssize_t get_pwm_en(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct smsc47m1_data *data = smsc47m1_update_device(dev, 0);
return sprintf(buf, "%d\n", PWM_EN_FROM_REG(data->pwm[attr->index]));
}
static ssize_t get_alarms(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct smsc47m1_data *data = smsc47m1_update_device(dev, 0);
return sprintf(buf, "%d\n", data->alarms);
}
static ssize_t set_fan_min(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct smsc47m1_data *data = dev_get_drvdata(dev);
int nr = attr->index;
long rpmdiv;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
rpmdiv = val * DIV_FROM_REG(data->fan_div[nr]);
if (983040 > 192 * rpmdiv || 2 * rpmdiv > 983040) {
mutex_unlock(&data->update_lock);
return -EINVAL;
}
data->fan_preload[nr] = 192 - ((983040 + rpmdiv / 2) / rpmdiv);
smsc47m1_write_value(data, SMSC47M1_REG_FAN_PRELOAD[nr],
data->fan_preload[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_fan_div(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct smsc47m1_data *data = dev_get_drvdata(dev);
int nr = attr->index;
long new_div;
int err;
long tmp;
u8 old_div = DIV_FROM_REG(data->fan_div[nr]);
err = kstrtol(buf, 10, &new_div);
if (err)
return err;
if (new_div == old_div)
return count;
mutex_lock(&data->update_lock);
switch (new_div) {
case 1:
data->fan_div[nr] = 0;
break;
case 2:
data->fan_div[nr] = 1;
break;
case 4:
data->fan_div[nr] = 2;
break;
case 8:
data->fan_div[nr] = 3;
break;
default:
mutex_unlock(&data->update_lock);
return -EINVAL;
}
switch (nr) {
case 0:
case 1:
tmp = smsc47m1_read_value(data, SMSC47M1_REG_FANDIV)
& ~(0x03 << (4 + 2 * nr));
tmp |= data->fan_div[nr] << (4 + 2 * nr);
smsc47m1_write_value(data, SMSC47M1_REG_FANDIV, tmp);
break;
case 2:
tmp = smsc47m1_read_value(data, SMSC47M2_REG_FANDIV3) & 0xCF;
tmp |= data->fan_div[2] << 4;
smsc47m1_write_value(data, SMSC47M2_REG_FANDIV3, tmp);
break;
}
tmp = 192 - (old_div * (192 - data->fan_preload[nr])
+ new_div / 2) / new_div;
data->fan_preload[nr] = SENSORS_LIMIT(tmp, 0, 191);
smsc47m1_write_value(data, SMSC47M1_REG_FAN_PRELOAD[nr],
data->fan_preload[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_pwm(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct smsc47m1_data *data = dev_get_drvdata(dev);
int nr = attr->index;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
if (val < 0 || val > 255)
return -EINVAL;
mutex_lock(&data->update_lock);
data->pwm[nr] &= 0x81;
data->pwm[nr] |= PWM_TO_REG(val);
smsc47m1_write_value(data, SMSC47M1_REG_PWM[nr],
data->pwm[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_pwm_en(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct smsc47m1_data *data = dev_get_drvdata(dev);
int nr = attr->index;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
if (val > 1)
return -EINVAL;
mutex_lock(&data->update_lock);
data->pwm[nr] &= 0xFE;
data->pwm[nr] |= !val;
smsc47m1_write_value(data, SMSC47M1_REG_PWM[nr],
data->pwm[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_name(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct smsc47m1_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", data->name);
}
static int __init smsc47m1_find(struct smsc47m1_sio_data *sio_data)
{
u8 val;
unsigned short addr;
superio_enter();
val = force_id ? force_id : superio_inb(SUPERIO_REG_DEVID);
switch (val) {
case 0x51:
pr_info("Found SMSC LPC47B27x\n");
sio_data->type = smsc47m1;
break;
case 0x59:
pr_info("Found SMSC LPC47M10x/LPC47M112/LPC47M13x\n");
sio_data->type = smsc47m1;
break;
case 0x5F:
pr_info("Found SMSC LPC47M14x\n");
sio_data->type = smsc47m1;
break;
case 0x60:
pr_info("Found SMSC LPC47M15x/LPC47M192/LPC47M997\n");
sio_data->type = smsc47m1;
break;
case 0x6B:
if (superio_inb(SUPERIO_REG_DEVREV) & 0x80) {
pr_debug("Found SMSC LPC47M233, unsupported\n");
superio_exit();
return -ENODEV;
}
pr_info("Found SMSC LPC47M292\n");
sio_data->type = smsc47m2;
break;
default:
superio_exit();
return -ENODEV;
}
superio_select();
addr = (superio_inb(SUPERIO_REG_BASE) << 8)
| superio_inb(SUPERIO_REG_BASE + 1);
if (addr == 0) {
pr_info("Device address not set, will not use\n");
superio_exit();
return -ENODEV;
}
sio_data->activate = superio_inb(SUPERIO_REG_ACT);
if ((sio_data->activate & 0x01) == 0) {
pr_info("Enabling device\n");
superio_outb(SUPERIO_REG_ACT, sio_data->activate | 0x01);
}
superio_exit();
return addr;
}
static void smsc47m1_restore(const struct smsc47m1_sio_data *sio_data)
{
if ((sio_data->activate & 0x01) == 0) {
superio_enter();
superio_select();
pr_info("Disabling device\n");
superio_outb(SUPERIO_REG_ACT, sio_data->activate);
superio_exit();
}
}
static int __init smsc47m1_handle_resources(unsigned short address,
enum chips type, int action,
struct device *dev)
{
static const u8 ports_m1[] = {
0x04, 1,
0x33, 4,
0x56, 7,
};
static const u8 ports_m2[] = {
0x04, 1,
0x09, 1,
0x2c, 2,
0x35, 4,
0x56, 7,
0x69, 4,
};
int i, ports_size, err;
const u8 *ports;
switch (type) {
case smsc47m1:
default:
ports = ports_m1;
ports_size = ARRAY_SIZE(ports_m1);
break;
case smsc47m2:
ports = ports_m2;
ports_size = ARRAY_SIZE(ports_m2);
break;
}
for (i = 0; i + 1 < ports_size; i += 2) {
unsigned short start = address + ports[i];
unsigned short len = ports[i + 1];
switch (action) {
case CHECK:
err = acpi_check_region(start, len, DRVNAME);
if (err)
return err;
break;
case REQUEST:
if (!devm_request_region(dev, start, len, DRVNAME)) {
dev_err(dev,
"Region 0x%hx-0x%hx already in use!\n",
start, start + len);
return -EBUSY;
}
break;
}
}
return 0;
}
static void smsc47m1_remove_files(struct device *dev)
{
sysfs_remove_group(&dev->kobj, &smsc47m1_group);
sysfs_remove_group(&dev->kobj, &smsc47m1_group_fan1);
sysfs_remove_group(&dev->kobj, &smsc47m1_group_fan2);
sysfs_remove_group(&dev->kobj, &smsc47m1_group_fan3);
sysfs_remove_group(&dev->kobj, &smsc47m1_group_pwm1);
sysfs_remove_group(&dev->kobj, &smsc47m1_group_pwm2);
sysfs_remove_group(&dev->kobj, &smsc47m1_group_pwm3);
}
static int __init smsc47m1_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct smsc47m1_sio_data *sio_data = dev->platform_data;
struct smsc47m1_data *data;
struct resource *res;
int err;
int fan1, fan2, fan3, pwm1, pwm2, pwm3;
static const char * const names[] = {
"smsc47m1",
"smsc47m2",
};
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
err = smsc47m1_handle_resources(res->start, sio_data->type,
REQUEST, dev);
if (err < 0)
return err;
data = devm_kzalloc(dev, sizeof(struct smsc47m1_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->addr = res->start;
data->type = sio_data->type;
data->name = names[sio_data->type];
mutex_init(&data->update_lock);
platform_set_drvdata(pdev, data);
pwm1 = (smsc47m1_read_value(data, SMSC47M1_REG_PPIN(0)) & 0x05)
== 0x04;
pwm2 = (smsc47m1_read_value(data, SMSC47M1_REG_PPIN(1)) & 0x05)
== 0x04;
if (data->type == smsc47m2) {
fan1 = (smsc47m1_read_value(data, SMSC47M2_REG_TPIN1)
& 0x0d) == 0x09;
fan2 = (smsc47m1_read_value(data, SMSC47M2_REG_TPIN2)
& 0x0d) == 0x09;
fan3 = (smsc47m1_read_value(data, SMSC47M2_REG_TPIN3)
& 0x0d) == 0x0d;
pwm3 = (smsc47m1_read_value(data, SMSC47M2_REG_PPIN3)
& 0x0d) == 0x08;
} else {
fan1 = (smsc47m1_read_value(data, SMSC47M1_REG_TPIN(0))
& 0x05) == 0x05;
fan2 = (smsc47m1_read_value(data, SMSC47M1_REG_TPIN(1))
& 0x05) == 0x05;
fan3 = 0;
pwm3 = 0;
}
if (!(fan1 || fan2 || fan3 || pwm1 || pwm2 || pwm3)) {
dev_warn(dev, "Device not configured, will not use\n");
return -ENODEV;
}
smsc47m1_update_device(dev, 1);
if (fan1) {
err = sysfs_create_group(&dev->kobj,
&smsc47m1_group_fan1);
if (err)
goto error_remove_files;
} else
dev_dbg(dev, "Fan 1 not enabled by hardware, skipping\n");
if (fan2) {
err = sysfs_create_group(&dev->kobj,
&smsc47m1_group_fan2);
if (err)
goto error_remove_files;
} else
dev_dbg(dev, "Fan 2 not enabled by hardware, skipping\n");
if (fan3) {
err = sysfs_create_group(&dev->kobj,
&smsc47m1_group_fan3);
if (err)
goto error_remove_files;
} else if (data->type == smsc47m2)
dev_dbg(dev, "Fan 3 not enabled by hardware, skipping\n");
if (pwm1) {
err = sysfs_create_group(&dev->kobj,
&smsc47m1_group_pwm1);
if (err)
goto error_remove_files;
} else
dev_dbg(dev, "PWM 1 not enabled by hardware, skipping\n");
if (pwm2) {
err = sysfs_create_group(&dev->kobj,
&smsc47m1_group_pwm2);
if (err)
goto error_remove_files;
} else
dev_dbg(dev, "PWM 2 not enabled by hardware, skipping\n");
if (pwm3) {
err = sysfs_create_group(&dev->kobj,
&smsc47m1_group_pwm3);
if (err)
goto error_remove_files;
} else if (data->type == smsc47m2)
dev_dbg(dev, "PWM 3 not enabled by hardware, skipping\n");
err = sysfs_create_group(&dev->kobj, &smsc47m1_group);
if (err)
goto error_remove_files;
data->hwmon_dev = hwmon_device_register(dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto error_remove_files;
}
return 0;
error_remove_files:
smsc47m1_remove_files(dev);
return err;
}
static int __exit smsc47m1_remove(struct platform_device *pdev)
{
struct smsc47m1_data *data = platform_get_drvdata(pdev);
hwmon_device_unregister(data->hwmon_dev);
smsc47m1_remove_files(&pdev->dev);
return 0;
}
static struct smsc47m1_data *smsc47m1_update_device(struct device *dev,
int init)
{
struct smsc47m1_data *data = dev_get_drvdata(dev);
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2) || init) {
int i, fan_nr;
fan_nr = data->type == smsc47m2 ? 3 : 2;
for (i = 0; i < fan_nr; i++) {
data->fan[i] = smsc47m1_read_value(data,
SMSC47M1_REG_FAN[i]);
data->fan_preload[i] = smsc47m1_read_value(data,
SMSC47M1_REG_FAN_PRELOAD[i]);
data->pwm[i] = smsc47m1_read_value(data,
SMSC47M1_REG_PWM[i]);
}
i = smsc47m1_read_value(data, SMSC47M1_REG_FANDIV);
data->fan_div[0] = (i >> 4) & 0x03;
data->fan_div[1] = i >> 6;
data->alarms = smsc47m1_read_value(data,
SMSC47M1_REG_ALARM) >> 6;
if (data->alarms)
smsc47m1_write_value(data, SMSC47M1_REG_ALARM, 0xC0);
if (fan_nr >= 3) {
data->fan_div[2] = (smsc47m1_read_value(data,
SMSC47M2_REG_FANDIV3) >> 4) & 0x03;
data->alarms |= (smsc47m1_read_value(data,
SMSC47M2_REG_ALARM6) & 0x40) >> 4;
if (data->alarms & 0x04)
smsc47m1_write_value(data,
SMSC47M2_REG_ALARM6,
0x40);
}
data->last_updated = jiffies;
}
mutex_unlock(&data->update_lock);
return data;
}
static int __init smsc47m1_device_add(unsigned short address,
const struct smsc47m1_sio_data *sio_data)
{
struct resource res = {
.start = address,
.end = address + SMSC_EXTENT - 1,
.name = DRVNAME,
.flags = IORESOURCE_IO,
};
int err;
err = smsc47m1_handle_resources(address, sio_data->type, CHECK, NULL);
if (err)
goto exit;
pdev = platform_device_alloc(DRVNAME, address);
if (!pdev) {
err = -ENOMEM;
pr_err("Device allocation failed\n");
goto exit;
}
err = platform_device_add_resources(pdev, &res, 1);
if (err) {
pr_err("Device resource addition failed (%d)\n", err);
goto exit_device_put;
}
err = platform_device_add_data(pdev, sio_data,
sizeof(struct smsc47m1_sio_data));
if (err) {
pr_err("Platform data allocation failed\n");
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
static int __init sm_smsc47m1_init(void)
{
int err;
unsigned short address;
struct smsc47m1_sio_data sio_data;
err = smsc47m1_find(&sio_data);
if (err < 0)
return err;
address = err;
err = smsc47m1_device_add(address, &sio_data);
if (err)
return err;
err = platform_driver_probe(&smsc47m1_driver, smsc47m1_probe);
if (err)
goto exit_device;
return 0;
exit_device:
platform_device_unregister(pdev);
smsc47m1_restore(&sio_data);
return err;
}
static void __exit sm_smsc47m1_exit(void)
{
platform_driver_unregister(&smsc47m1_driver);
smsc47m1_restore(pdev->dev.platform_data);
platform_device_unregister(pdev);
}
