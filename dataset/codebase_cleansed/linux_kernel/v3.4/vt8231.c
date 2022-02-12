static inline u8 FAN_TO_REG(long rpm, int div)
{
if (rpm == 0)
return 0;
return SENSORS_LIMIT(1310720 / (rpm * div), 1, 255);
}
static inline int vt8231_read_value(struct vt8231_data *data, u8 reg)
{
return inb_p(data->addr + reg);
}
static inline void vt8231_write_value(struct vt8231_data *data, u8 reg,
u8 value)
{
outb_p(value, data->addr + reg);
}
static ssize_t show_in(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct vt8231_data *data = vt8231_update_device(dev);
return sprintf(buf, "%d\n", ((data->in[nr] - 3) * 10000) / 958);
}
static ssize_t show_in_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct vt8231_data *data = vt8231_update_device(dev);
return sprintf(buf, "%d\n", ((data->in_min[nr] - 3) * 10000) / 958);
}
static ssize_t show_in_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct vt8231_data *data = vt8231_update_device(dev);
return sprintf(buf, "%d\n", (((data->in_max[nr] - 3) * 10000) / 958));
}
static ssize_t set_in_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct vt8231_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_min[nr] = SENSORS_LIMIT(((val * 958) / 10000) + 3, 0, 255);
vt8231_write_value(data, regvoltmin[nr], data->in_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_in_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct vt8231_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_max[nr] = SENSORS_LIMIT(((val * 958) / 10000) + 3, 0, 255);
vt8231_write_value(data, regvoltmax[nr], data->in_max[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_in5(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct vt8231_data *data = vt8231_update_device(dev);
return sprintf(buf, "%d\n",
(((data->in[5] - 3) * 10000 * 54) / (958 * 34)));
}
static ssize_t show_in5_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct vt8231_data *data = vt8231_update_device(dev);
return sprintf(buf, "%d\n",
(((data->in_min[5] - 3) * 10000 * 54) / (958 * 34)));
}
static ssize_t show_in5_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct vt8231_data *data = vt8231_update_device(dev);
return sprintf(buf, "%d\n",
(((data->in_max[5] - 3) * 10000 * 54) / (958 * 34)));
}
static ssize_t set_in5_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct vt8231_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_min[5] = SENSORS_LIMIT(((val * 958 * 34) / (10000 * 54)) + 3,
0, 255);
vt8231_write_value(data, regvoltmin[5], data->in_min[5]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_in5_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct vt8231_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_max[5] = SENSORS_LIMIT(((val * 958 * 34) / (10000 * 54)) + 3,
0, 255);
vt8231_write_value(data, regvoltmax[5], data->in_max[5]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp0(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct vt8231_data *data = vt8231_update_device(dev);
return sprintf(buf, "%d\n", data->temp[0] * 250);
}
static ssize_t show_temp0_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct vt8231_data *data = vt8231_update_device(dev);
return sprintf(buf, "%d\n", data->temp_max[0] * 1000);
}
static ssize_t show_temp0_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct vt8231_data *data = vt8231_update_device(dev);
return sprintf(buf, "%d\n", data->temp_min[0] * 1000);
}
static ssize_t set_temp0_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct vt8231_data *data = dev_get_drvdata(dev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_max[0] = SENSORS_LIMIT((val + 500) / 1000, 0, 255);
vt8231_write_value(data, regtempmax[0], data->temp_max[0]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_temp0_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct vt8231_data *data = dev_get_drvdata(dev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_min[0] = SENSORS_LIMIT((val + 500) / 1000, 0, 255);
vt8231_write_value(data, regtempmin[0], data->temp_min[0]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct vt8231_data *data = vt8231_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[nr]));
}
static ssize_t show_temp_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct vt8231_data *data = vt8231_update_device(dev);
return sprintf(buf, "%d\n", TEMP_MAXMIN_FROM_REG(data->temp_max[nr]));
}
static ssize_t show_temp_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct vt8231_data *data = vt8231_update_device(dev);
return sprintf(buf, "%d\n", TEMP_MAXMIN_FROM_REG(data->temp_min[nr]));
}
static ssize_t set_temp_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct vt8231_data *data = dev_get_drvdata(dev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_max[nr] = SENSORS_LIMIT(TEMP_MAXMIN_TO_REG(val), 0, 255);
vt8231_write_value(data, regtempmax[nr], data->temp_max[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_temp_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct vt8231_data *data = dev_get_drvdata(dev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_min[nr] = SENSORS_LIMIT(TEMP_MAXMIN_TO_REG(val), 0, 255);
vt8231_write_value(data, regtempmin[nr], data->temp_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_fan(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct vt8231_data *data = vt8231_update_device(dev);
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan[nr],
DIV_FROM_REG(data->fan_div[nr])));
}
static ssize_t show_fan_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct vt8231_data *data = vt8231_update_device(dev);
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan_min[nr],
DIV_FROM_REG(data->fan_div[nr])));
}
static ssize_t show_fan_div(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct vt8231_data *data = vt8231_update_device(dev);
return sprintf(buf, "%d\n", DIV_FROM_REG(data->fan_div[nr]));
}
static ssize_t set_fan_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct vt8231_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->fan_min[nr] = FAN_TO_REG(val, DIV_FROM_REG(data->fan_div[nr]));
vt8231_write_value(data, VT8231_REG_FAN_MIN(nr), data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_fan_div(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct vt8231_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
unsigned long val;
int nr = sensor_attr->index;
int old = vt8231_read_value(data, VT8231_REG_FANDIV);
long min = FAN_FROM_REG(data->fan_min[nr],
DIV_FROM_REG(data->fan_div[nr]));
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
switch (val) {
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
dev_err(dev, "fan_div value %ld not supported. "
"Choose one of 1, 2, 4 or 8!\n", val);
mutex_unlock(&data->update_lock);
return -EINVAL;
}
data->fan_min[nr] = FAN_TO_REG(min, DIV_FROM_REG(data->fan_div[nr]));
vt8231_write_value(data, VT8231_REG_FAN_MIN(nr), data->fan_min[nr]);
old = (old & 0x0f) | (data->fan_div[1] << 6) | (data->fan_div[0] << 4);
vt8231_write_value(data, VT8231_REG_FANDIV, old);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarms(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct vt8231_data *data = vt8231_update_device(dev);
return sprintf(buf, "%d\n", data->alarms);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int bitnr = to_sensor_dev_attr(attr)->index;
struct vt8231_data *data = vt8231_update_device(dev);
return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}
static ssize_t show_name(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct vt8231_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", data->name);
}
static int vt8231_probe(struct platform_device *pdev)
{
struct resource *res;
struct vt8231_data *data;
int err = 0, i;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!request_region(res->start, VT8231_EXTENT,
vt8231_driver.driver.name)) {
dev_err(&pdev->dev, "Region 0x%lx-0x%lx already in use!\n",
(unsigned long)res->start, (unsigned long)res->end);
return -ENODEV;
}
data = kzalloc(sizeof(struct vt8231_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit_release;
}
platform_set_drvdata(pdev, data);
data->addr = res->start;
data->name = "vt8231";
mutex_init(&data->update_lock);
vt8231_init_device(data);
err = sysfs_create_group(&pdev->dev.kobj, &vt8231_group);
if (err)
goto exit_free;
data->uch_config = vt8231_read_value(data, VT8231_REG_UCH_CONFIG);
for (i = 0; i < ARRAY_SIZE(vt8231_group_temps); i++) {
if (ISTEMP(i, data->uch_config)) {
err = sysfs_create_group(&pdev->dev.kobj,
&vt8231_group_temps[i]);
if (err)
goto exit_remove_files;
}
}
for (i = 0; i < ARRAY_SIZE(vt8231_group_volts); i++) {
if (ISVOLT(i, data->uch_config)) {
err = sysfs_create_group(&pdev->dev.kobj,
&vt8231_group_volts[i]);
if (err)
goto exit_remove_files;
}
}
data->hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
return 0;
exit_remove_files:
for (i = 0; i < ARRAY_SIZE(vt8231_group_volts); i++)
sysfs_remove_group(&pdev->dev.kobj, &vt8231_group_volts[i]);
for (i = 0; i < ARRAY_SIZE(vt8231_group_temps); i++)
sysfs_remove_group(&pdev->dev.kobj, &vt8231_group_temps[i]);
sysfs_remove_group(&pdev->dev.kobj, &vt8231_group);
exit_free:
platform_set_drvdata(pdev, NULL);
kfree(data);
exit_release:
release_region(res->start, VT8231_EXTENT);
return err;
}
static int __devexit vt8231_remove(struct platform_device *pdev)
{
struct vt8231_data *data = platform_get_drvdata(pdev);
int i;
hwmon_device_unregister(data->hwmon_dev);
for (i = 0; i < ARRAY_SIZE(vt8231_group_volts); i++)
sysfs_remove_group(&pdev->dev.kobj, &vt8231_group_volts[i]);
for (i = 0; i < ARRAY_SIZE(vt8231_group_temps); i++)
sysfs_remove_group(&pdev->dev.kobj, &vt8231_group_temps[i]);
sysfs_remove_group(&pdev->dev.kobj, &vt8231_group);
release_region(data->addr, VT8231_EXTENT);
platform_set_drvdata(pdev, NULL);
kfree(data);
return 0;
}
static void vt8231_init_device(struct vt8231_data *data)
{
vt8231_write_value(data, VT8231_REG_TEMP1_CONFIG, 0);
vt8231_write_value(data, VT8231_REG_TEMP2_CONFIG, 0);
}
static struct vt8231_data *vt8231_update_device(struct device *dev)
{
struct vt8231_data *data = dev_get_drvdata(dev);
int i;
u16 low;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
for (i = 0; i < 6; i++) {
if (ISVOLT(i, data->uch_config)) {
data->in[i] = vt8231_read_value(data,
regvolt[i]);
data->in_min[i] = vt8231_read_value(data,
regvoltmin[i]);
data->in_max[i] = vt8231_read_value(data,
regvoltmax[i]);
}
}
for (i = 0; i < 2; i++) {
data->fan[i] = vt8231_read_value(data,
VT8231_REG_FAN(i));
data->fan_min[i] = vt8231_read_value(data,
VT8231_REG_FAN_MIN(i));
}
low = vt8231_read_value(data, VT8231_REG_TEMP_LOW01);
low = (low >> 6) | ((low & 0x30) >> 2)
| (vt8231_read_value(data, VT8231_REG_TEMP_LOW25) << 4);
for (i = 0; i < 6; i++) {
if (ISTEMP(i, data->uch_config)) {
data->temp[i] = (vt8231_read_value(data,
regtemp[i]) << 2)
| ((low >> (2 * i)) & 0x03);
data->temp_max[i] = vt8231_read_value(data,
regtempmax[i]);
data->temp_min[i] = vt8231_read_value(data,
regtempmin[i]);
}
}
i = vt8231_read_value(data, VT8231_REG_FANDIV);
data->fan_div[0] = (i >> 4) & 0x03;
data->fan_div[1] = i >> 6;
data->alarms = vt8231_read_value(data, VT8231_REG_ALARM1) |
(vt8231_read_value(data, VT8231_REG_ALARM2) << 8);
if (!data->fan[0] && data->fan_min[0])
data->alarms |= 0x40;
else if (data->fan[0] && !data->fan_min[0])
data->alarms &= ~0x40;
if (!data->fan[1] && data->fan_min[1])
data->alarms |= 0x80;
else if (data->fan[1] && !data->fan_min[1])
data->alarms &= ~0x80;
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static int __devinit vt8231_device_add(unsigned short address)
{
struct resource res = {
.start = address,
.end = address + VT8231_EXTENT - 1,
.name = "vt8231",
.flags = IORESOURCE_IO,
};
int err;
err = acpi_check_resource_conflict(&res);
if (err)
goto exit;
pdev = platform_device_alloc("vt8231", address);
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
static int __devinit vt8231_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
u16 address, val;
if (force_addr) {
address = force_addr & 0xff00;
dev_warn(&dev->dev, "Forcing ISA address 0x%x\n",
address);
if (PCIBIOS_SUCCESSFUL !=
pci_write_config_word(dev, VT8231_BASE_REG, address | 1))
return -ENODEV;
}
if (PCIBIOS_SUCCESSFUL != pci_read_config_word(dev, VT8231_BASE_REG,
&val))
return -ENODEV;
address = val & ~(VT8231_EXTENT - 1);
if (address == 0) {
dev_err(&dev->dev, "base address not set - upgrade BIOS or use force_addr=0xaddr\n");
return -ENODEV;
}
if (PCIBIOS_SUCCESSFUL != pci_read_config_word(dev, VT8231_ENABLE_REG,
&val))
return -ENODEV;
if (!(val & 0x0001)) {
dev_warn(&dev->dev, "enabling sensors\n");
if (PCIBIOS_SUCCESSFUL !=
pci_write_config_word(dev, VT8231_ENABLE_REG,
val | 0x0001))
return -ENODEV;
}
if (platform_driver_register(&vt8231_driver))
goto exit;
if (vt8231_device_add(address))
goto exit_unregister;
s_bridge = pci_dev_get(dev);
return -ENODEV;
exit_unregister:
platform_driver_unregister(&vt8231_driver);
exit:
return -ENODEV;
}
static int __init sm_vt8231_init(void)
{
return pci_register_driver(&vt8231_pci_driver);
}
static void __exit sm_vt8231_exit(void)
{
pci_unregister_driver(&vt8231_pci_driver);
if (s_bridge != NULL) {
platform_device_unregister(pdev);
platform_driver_unregister(&vt8231_driver);
pci_dev_put(s_bridge);
s_bridge = NULL;
}
}
