static inline u8 IN_TO_REG(unsigned long val)
{
unsigned long nval = SENSORS_LIMIT(val, 0, 4080);
return (nval + 8) / 16;
}
static inline u8 FAN_TO_REG(long rpm, int div)
{
if (rpm <= 0)
return 255;
return SENSORS_LIMIT((1350000 + rpm * div / 2) / (rpm * div), 1, 254);
}
static inline int FAN_FROM_REG(u8 val, int div)
{
return val==0 ? -1 : val==255 ? 0 : 1350000/(val*div);
}
static inline int TEMP_FROM_REG(s8 val)
{
return val * 830 + 52120;
}
static inline s8 TEMP_TO_REG(int val)
{
int nval = SENSORS_LIMIT(val, -54120, 157530) ;
return nval<0 ? (nval-5212-415)/830 : (nval-5212+415)/830;
}
static inline u8 DIV_TO_REG(int val)
{
return val==8 ? 3 : val==4 ? 2 : val==1 ? 0 : 1;
}
static ssize_t show_in(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sis5595_data *data = sis5595_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
return sprintf(buf, "%d\n", IN_FROM_REG(data->in[nr]));
}
static ssize_t show_in_min(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sis5595_data *data = sis5595_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
return sprintf(buf, "%d\n", IN_FROM_REG(data->in_min[nr]));
}
static ssize_t show_in_max(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sis5595_data *data = sis5595_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
return sprintf(buf, "%d\n", IN_FROM_REG(data->in_max[nr]));
}
static ssize_t set_in_min(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct sis5595_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
unsigned long val = simple_strtoul(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->in_min[nr] = IN_TO_REG(val);
sis5595_write_value(data, SIS5595_REG_IN_MIN(nr), data->in_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_in_max(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct sis5595_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
unsigned long val = simple_strtoul(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->in_max[nr] = IN_TO_REG(val);
sis5595_write_value(data, SIS5595_REG_IN_MAX(nr), data->in_max[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sis5595_data *data = sis5595_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp));
}
static ssize_t show_temp_over(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sis5595_data *data = sis5595_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_over));
}
static ssize_t set_temp_over(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
struct sis5595_data *data = dev_get_drvdata(dev);
long val = simple_strtol(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->temp_over = TEMP_TO_REG(val);
sis5595_write_value(data, SIS5595_REG_TEMP_OVER, data->temp_over);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_hyst(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sis5595_data *data = sis5595_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_hyst));
}
static ssize_t set_temp_hyst(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
struct sis5595_data *data = dev_get_drvdata(dev);
long val = simple_strtol(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->temp_hyst = TEMP_TO_REG(val);
sis5595_write_value(data, SIS5595_REG_TEMP_HYST, data->temp_hyst);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_fan(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sis5595_data *data = sis5595_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan[nr],
DIV_FROM_REG(data->fan_div[nr])) );
}
static ssize_t show_fan_min(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sis5595_data *data = sis5595_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
return sprintf(buf,"%d\n", FAN_FROM_REG(data->fan_min[nr],
DIV_FROM_REG(data->fan_div[nr])) );
}
static ssize_t set_fan_min(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct sis5595_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
unsigned long val = simple_strtoul(buf, NULL, 10);
mutex_lock(&data->update_lock);
data->fan_min[nr] = FAN_TO_REG(val, DIV_FROM_REG(data->fan_div[nr]));
sis5595_write_value(data, SIS5595_REG_FAN_MIN(nr), data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_fan_div(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sis5595_data *data = sis5595_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
return sprintf(buf, "%d\n", DIV_FROM_REG(data->fan_div[nr]) );
}
static ssize_t set_fan_div(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct sis5595_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
unsigned long min;
unsigned long val = simple_strtoul(buf, NULL, 10);
int reg;
mutex_lock(&data->update_lock);
min = FAN_FROM_REG(data->fan_min[nr],
DIV_FROM_REG(data->fan_div[nr]));
reg = sis5595_read_value(data, SIS5595_REG_FANDIV);
switch (val) {
case 1: data->fan_div[nr] = 0; break;
case 2: data->fan_div[nr] = 1; break;
case 4: data->fan_div[nr] = 2; break;
case 8: data->fan_div[nr] = 3; break;
default:
dev_err(dev, "fan_div value %ld not "
"supported. Choose one of 1, 2, 4 or 8!\n", val);
mutex_unlock(&data->update_lock);
return -EINVAL;
}
switch (nr) {
case 0:
reg = (reg & 0xcf) | (data->fan_div[nr] << 4);
break;
case 1:
reg = (reg & 0x3f) | (data->fan_div[nr] << 6);
break;
}
sis5595_write_value(data, SIS5595_REG_FANDIV, reg);
data->fan_min[nr] =
FAN_TO_REG(min, DIV_FROM_REG(data->fan_div[nr]));
sis5595_write_value(data, SIS5595_REG_FAN_MIN(nr), data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarms(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sis5595_data *data = sis5595_update_device(dev);
return sprintf(buf, "%d\n", data->alarms);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sis5595_data *data = sis5595_update_device(dev);
int nr = to_sensor_dev_attr(da)->index;
return sprintf(buf, "%u\n", (data->alarms >> nr) & 1);
}
static ssize_t show_name(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sis5595_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", data->name);
}
static int __devinit sis5595_probe(struct platform_device *pdev)
{
int err = 0;
int i;
struct sis5595_data *data;
struct resource *res;
char val;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!request_region(res->start, SIS5595_EXTENT,
sis5595_driver.driver.name)) {
err = -EBUSY;
goto exit;
}
if (!(data = kzalloc(sizeof(struct sis5595_data), GFP_KERNEL))) {
err = -ENOMEM;
goto exit_release;
}
mutex_init(&data->lock);
mutex_init(&data->update_lock);
data->addr = res->start;
data->name = "sis5595";
platform_set_drvdata(pdev, data);
data->revision = s_bridge->revision;
data->maxins = 3;
if (data->revision >= REV2MIN) {
pci_read_config_byte(s_bridge, SIS5595_PIN_REG, &val);
if (!(val & 0x80))
data->maxins = 4;
}
sis5595_init_device(data);
for (i = 0; i < 2; i++) {
data->fan_min[i] = sis5595_read_value(data,
SIS5595_REG_FAN_MIN(i));
}
if ((err = sysfs_create_group(&pdev->dev.kobj, &sis5595_group)))
goto exit_free;
if (data->maxins == 4) {
if ((err = sysfs_create_group(&pdev->dev.kobj,
&sis5595_group_in4)))
goto exit_remove_files;
} else {
if ((err = sysfs_create_group(&pdev->dev.kobj,
&sis5595_group_temp1)))
goto exit_remove_files;
}
data->hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
return 0;
exit_remove_files:
sysfs_remove_group(&pdev->dev.kobj, &sis5595_group);
sysfs_remove_group(&pdev->dev.kobj, &sis5595_group_in4);
sysfs_remove_group(&pdev->dev.kobj, &sis5595_group_temp1);
exit_free:
kfree(data);
exit_release:
release_region(res->start, SIS5595_EXTENT);
exit:
return err;
}
static int __devexit sis5595_remove(struct platform_device *pdev)
{
struct sis5595_data *data = platform_get_drvdata(pdev);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&pdev->dev.kobj, &sis5595_group);
sysfs_remove_group(&pdev->dev.kobj, &sis5595_group_in4);
sysfs_remove_group(&pdev->dev.kobj, &sis5595_group_temp1);
release_region(data->addr, SIS5595_EXTENT);
platform_set_drvdata(pdev, NULL);
kfree(data);
return 0;
}
static int sis5595_read_value(struct sis5595_data *data, u8 reg)
{
int res;
mutex_lock(&data->lock);
outb_p(reg, data->addr + SIS5595_ADDR_REG_OFFSET);
res = inb_p(data->addr + SIS5595_DATA_REG_OFFSET);
mutex_unlock(&data->lock);
return res;
}
static void sis5595_write_value(struct sis5595_data *data, u8 reg, u8 value)
{
mutex_lock(&data->lock);
outb_p(reg, data->addr + SIS5595_ADDR_REG_OFFSET);
outb_p(value, data->addr + SIS5595_DATA_REG_OFFSET);
mutex_unlock(&data->lock);
}
static void __devinit sis5595_init_device(struct sis5595_data *data)
{
u8 config = sis5595_read_value(data, SIS5595_REG_CONFIG);
if (!(config & 0x01))
sis5595_write_value(data, SIS5595_REG_CONFIG,
(config & 0xf7) | 0x01);
}
static struct sis5595_data *sis5595_update_device(struct device *dev)
{
struct sis5595_data *data = dev_get_drvdata(dev);
int i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
for (i = 0; i <= data->maxins; i++) {
data->in[i] =
sis5595_read_value(data, SIS5595_REG_IN(i));
data->in_min[i] =
sis5595_read_value(data,
SIS5595_REG_IN_MIN(i));
data->in_max[i] =
sis5595_read_value(data,
SIS5595_REG_IN_MAX(i));
}
for (i = 0; i < 2; i++) {
data->fan[i] =
sis5595_read_value(data, SIS5595_REG_FAN(i));
data->fan_min[i] =
sis5595_read_value(data,
SIS5595_REG_FAN_MIN(i));
}
if (data->maxins == 3) {
data->temp =
sis5595_read_value(data, SIS5595_REG_TEMP);
data->temp_over =
sis5595_read_value(data, SIS5595_REG_TEMP_OVER);
data->temp_hyst =
sis5595_read_value(data, SIS5595_REG_TEMP_HYST);
}
i = sis5595_read_value(data, SIS5595_REG_FANDIV);
data->fan_div[0] = (i >> 4) & 0x03;
data->fan_div[1] = i >> 6;
data->alarms =
sis5595_read_value(data, SIS5595_REG_ALARM1) |
(sis5595_read_value(data, SIS5595_REG_ALARM2) << 8);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static int __devinit sis5595_device_add(unsigned short address)
{
struct resource res = {
.start = address,
.end = address + SIS5595_EXTENT - 1,
.name = "sis5595",
.flags = IORESOURCE_IO,
};
int err;
err = acpi_check_resource_conflict(&res);
if (err)
goto exit;
pdev = platform_device_alloc("sis5595", address);
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
static int __devinit sis5595_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
u16 address;
u8 enable;
int *i;
for (i = blacklist; *i != 0; i++) {
struct pci_dev *d;
if ((d = pci_get_device(PCI_VENDOR_ID_SI, *i, NULL))) {
dev_err(&d->dev, "Looked for SIS5595 but found unsupported device %.4x\n", *i);
pci_dev_put(d);
return -ENODEV;
}
}
force_addr &= ~(SIS5595_EXTENT - 1);
if (force_addr) {
dev_warn(&dev->dev, "Forcing ISA address 0x%x\n", force_addr);
pci_write_config_word(dev, SIS5595_BASE_REG, force_addr);
}
if (PCIBIOS_SUCCESSFUL !=
pci_read_config_word(dev, SIS5595_BASE_REG, &address)) {
dev_err(&dev->dev, "Failed to read ISA address\n");
return -ENODEV;
}
address &= ~(SIS5595_EXTENT - 1);
if (!address) {
dev_err(&dev->dev, "Base address not set - upgrade BIOS or use force_addr=0xaddr\n");
return -ENODEV;
}
if (force_addr && address != force_addr) {
dev_err(&dev->dev, "Failed to force ISA address\n");
return -ENODEV;
}
if (PCIBIOS_SUCCESSFUL !=
pci_read_config_byte(dev, SIS5595_ENABLE_REG, &enable)) {
dev_err(&dev->dev, "Failed to read enable register\n");
return -ENODEV;
}
if (!(enable & 0x80)) {
if ((PCIBIOS_SUCCESSFUL !=
pci_write_config_byte(dev, SIS5595_ENABLE_REG,
enable | 0x80))
|| (PCIBIOS_SUCCESSFUL !=
pci_read_config_byte(dev, SIS5595_ENABLE_REG, &enable))
|| (!(enable & 0x80))) {
dev_err(&dev->dev, "Failed to enable HWM device\n");
return -ENODEV;
}
}
if (platform_driver_register(&sis5595_driver)) {
dev_dbg(&dev->dev, "Failed to register sis5595 driver\n");
goto exit;
}
s_bridge = pci_dev_get(dev);
if (sis5595_device_add(address))
goto exit_unregister;
return -ENODEV;
exit_unregister:
pci_dev_put(dev);
platform_driver_unregister(&sis5595_driver);
exit:
return -ENODEV;
}
static int __init sm_sis5595_init(void)
{
return pci_register_driver(&sis5595_pci_driver);
}
static void __exit sm_sis5595_exit(void)
{
pci_unregister_driver(&sis5595_pci_driver);
if (s_bridge != NULL) {
platform_device_unregister(pdev);
platform_driver_unregister(&sis5595_driver);
pci_dev_put(s_bridge);
s_bridge = NULL;
}
}
