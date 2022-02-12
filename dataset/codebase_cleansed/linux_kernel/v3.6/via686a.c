static inline u8 IN_TO_REG(long val, int inNum)
{
if (inNum <= 1)
return (u8)
SENSORS_LIMIT((val * 21024 - 1205000) / 250000, 0, 255);
else if (inNum == 2)
return (u8)
SENSORS_LIMIT((val * 15737 - 1205000) / 250000, 0, 255);
else if (inNum == 3)
return (u8)
SENSORS_LIMIT((val * 10108 - 1205000) / 250000, 0, 255);
else
return (u8)
SENSORS_LIMIT((val * 41714 - 12050000) / 2500000, 0, 255);
}
static inline long IN_FROM_REG(u8 val, int inNum)
{
if (inNum <= 1)
return (long) ((250000 * val + 1330000 + 21024 / 2) / 21024);
else if (inNum == 2)
return (long) ((250000 * val + 1330000 + 15737 / 2) / 15737);
else if (inNum == 3)
return (long) ((250000 * val + 1330000 + 10108 / 2) / 10108);
else
return (long) ((2500000 * val + 13300000 + 41714 / 2) / 41714);
}
static inline u8 FAN_TO_REG(long rpm, int div)
{
if (rpm == 0)
return 0;
rpm = SENSORS_LIMIT(rpm, 1, 1000000);
return SENSORS_LIMIT((1350000 + rpm * div / 2) / (rpm * div), 1, 255);
}
static inline u8 TEMP_TO_REG(long val)
{
return viaLUT[val <= -50000 ? 0 : val >= 110000 ? 160 :
(val < 0 ? val - 500 : val + 500) / 1000 + 50];
}
static inline long TEMP_FROM_REG10(u16 val)
{
u16 eightBits = val >> 2;
u16 twoBits = val & 3;
if (twoBits == 0 || eightBits == 255)
return TEMP_FROM_REG(eightBits);
return (tempLUT[eightBits] * (4 - twoBits) +
tempLUT[eightBits + 1] * twoBits) * 25;
}
static inline int via686a_read_value(struct via686a_data *data, u8 reg)
{
return inb_p(data->addr + reg);
}
static inline void via686a_write_value(struct via686a_data *data, u8 reg,
u8 value)
{
outb_p(value, data->addr + reg);
}
static ssize_t show_in(struct device *dev, struct device_attribute *da,
char *buf) {
struct via686a_data *data = via686a_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
return sprintf(buf, "%ld\n", IN_FROM_REG(data->in[nr], nr));
}
static ssize_t show_in_min(struct device *dev, struct device_attribute *da,
char *buf) {
struct via686a_data *data = via686a_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
return sprintf(buf, "%ld\n", IN_FROM_REG(data->in_min[nr], nr));
}
static ssize_t show_in_max(struct device *dev, struct device_attribute *da,
char *buf) {
struct via686a_data *data = via686a_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
return sprintf(buf, "%ld\n", IN_FROM_REG(data->in_max[nr], nr));
}
static ssize_t set_in_min(struct device *dev, struct device_attribute *da,
const char *buf, size_t count) {
struct via686a_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_min[nr] = IN_TO_REG(val, nr);
via686a_write_value(data, VIA686A_REG_IN_MIN(nr),
data->in_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_in_max(struct device *dev, struct device_attribute *da,
const char *buf, size_t count) {
struct via686a_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_max[nr] = IN_TO_REG(val, nr);
via686a_write_value(data, VIA686A_REG_IN_MAX(nr),
data->in_max[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *da,
char *buf) {
struct via686a_data *data = via686a_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
return sprintf(buf, "%ld\n", TEMP_FROM_REG10(data->temp[nr]));
}
static ssize_t show_temp_over(struct device *dev, struct device_attribute *da,
char *buf) {
struct via686a_data *data = via686a_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
return sprintf(buf, "%ld\n", TEMP_FROM_REG(data->temp_over[nr]));
}
static ssize_t show_temp_hyst(struct device *dev, struct device_attribute *da,
char *buf) {
struct via686a_data *data = via686a_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
return sprintf(buf, "%ld\n", TEMP_FROM_REG(data->temp_hyst[nr]));
}
static ssize_t set_temp_over(struct device *dev, struct device_attribute *da,
const char *buf, size_t count) {
struct via686a_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_over[nr] = TEMP_TO_REG(val);
via686a_write_value(data, VIA686A_REG_TEMP_OVER[nr],
data->temp_over[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_temp_hyst(struct device *dev, struct device_attribute *da,
const char *buf, size_t count) {
struct via686a_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_hyst[nr] = TEMP_TO_REG(val);
via686a_write_value(data, VIA686A_REG_TEMP_HYST[nr],
data->temp_hyst[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_fan(struct device *dev, struct device_attribute *da,
char *buf) {
struct via686a_data *data = via686a_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan[nr],
DIV_FROM_REG(data->fan_div[nr])));
}
static ssize_t show_fan_min(struct device *dev, struct device_attribute *da,
char *buf) {
struct via686a_data *data = via686a_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
return sprintf(buf, "%d\n",
FAN_FROM_REG(data->fan_min[nr],
DIV_FROM_REG(data->fan_div[nr])));
}
static ssize_t show_fan_div(struct device *dev, struct device_attribute *da,
char *buf) {
struct via686a_data *data = via686a_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
return sprintf(buf, "%d\n", DIV_FROM_REG(data->fan_div[nr]));
}
static ssize_t set_fan_min(struct device *dev, struct device_attribute *da,
const char *buf, size_t count) {
struct via686a_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->fan_min[nr] = FAN_TO_REG(val, DIV_FROM_REG(data->fan_div[nr]));
via686a_write_value(data, VIA686A_REG_FAN_MIN(nr+1), data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_fan_div(struct device *dev, struct device_attribute *da,
const char *buf, size_t count) {
struct via686a_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int nr = attr->index;
int old;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
old = via686a_read_value(data, VIA686A_REG_FANDIV);
data->fan_div[nr] = DIV_TO_REG(val);
old = (old & 0x0f) | (data->fan_div[1] << 6) | (data->fan_div[0] << 4);
via686a_write_value(data, VIA686A_REG_FANDIV, old);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarms(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct via686a_data *data = via686a_update_device(dev);
return sprintf(buf, "%u\n", data->alarms);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int bitnr = to_sensor_dev_attr(attr)->index;
struct via686a_data *data = via686a_update_device(dev);
return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}
static ssize_t show_name(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct via686a_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", data->name);
}
static int __devinit via686a_probe(struct platform_device *pdev)
{
struct via686a_data *data;
struct resource *res;
int err;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!devm_request_region(&pdev->dev, res->start, VIA686A_EXTENT,
via686a_driver.driver.name)) {
dev_err(&pdev->dev, "Region 0x%lx-0x%lx already in use!\n",
(unsigned long)res->start, (unsigned long)res->end);
return -ENODEV;
}
data = devm_kzalloc(&pdev->dev, sizeof(struct via686a_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
platform_set_drvdata(pdev, data);
data->addr = res->start;
data->name = "via686a";
mutex_init(&data->update_lock);
via686a_init_device(data);
err = sysfs_create_group(&pdev->dev.kobj, &via686a_group);
if (err)
return err;
data->hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
return 0;
exit_remove_files:
sysfs_remove_group(&pdev->dev.kobj, &via686a_group);
return err;
}
static int __devexit via686a_remove(struct platform_device *pdev)
{
struct via686a_data *data = platform_get_drvdata(pdev);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&pdev->dev.kobj, &via686a_group);
return 0;
}
static void via686a_update_fan_div(struct via686a_data *data)
{
int reg = via686a_read_value(data, VIA686A_REG_FANDIV);
data->fan_div[0] = (reg >> 4) & 0x03;
data->fan_div[1] = reg >> 6;
}
static void __devinit via686a_init_device(struct via686a_data *data)
{
u8 reg;
reg = via686a_read_value(data, VIA686A_REG_CONFIG);
via686a_write_value(data, VIA686A_REG_CONFIG, (reg | 0x01) & 0x7F);
reg = via686a_read_value(data, VIA686A_REG_TEMP_MODE);
via686a_write_value(data, VIA686A_REG_TEMP_MODE,
(reg & ~VIA686A_TEMP_MODE_MASK)
| VIA686A_TEMP_MODE_CONTINUOUS);
via686a_update_fan_div(data);
}
static struct via686a_data *via686a_update_device(struct device *dev)
{
struct via686a_data *data = dev_get_drvdata(dev);
int i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
for (i = 0; i <= 4; i++) {
data->in[i] =
via686a_read_value(data, VIA686A_REG_IN(i));
data->in_min[i] = via686a_read_value(data,
VIA686A_REG_IN_MIN
(i));
data->in_max[i] =
via686a_read_value(data, VIA686A_REG_IN_MAX(i));
}
for (i = 1; i <= 2; i++) {
data->fan[i - 1] =
via686a_read_value(data, VIA686A_REG_FAN(i));
data->fan_min[i - 1] = via686a_read_value(data,
VIA686A_REG_FAN_MIN(i));
}
for (i = 0; i <= 2; i++) {
data->temp[i] = via686a_read_value(data,
VIA686A_REG_TEMP[i]) << 2;
data->temp_over[i] =
via686a_read_value(data,
VIA686A_REG_TEMP_OVER[i]);
data->temp_hyst[i] =
via686a_read_value(data,
VIA686A_REG_TEMP_HYST[i]);
}
data->temp[0] |= (via686a_read_value(data,
VIA686A_REG_TEMP_LOW1)
& 0xc0) >> 6;
data->temp[1] |=
(via686a_read_value(data, VIA686A_REG_TEMP_LOW23) &
0x30) >> 4;
data->temp[2] |=
(via686a_read_value(data, VIA686A_REG_TEMP_LOW23) &
0xc0) >> 6;
via686a_update_fan_div(data);
data->alarms =
via686a_read_value(data,
VIA686A_REG_ALARM1) |
(via686a_read_value(data, VIA686A_REG_ALARM2) << 8);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static int __devinit via686a_device_add(unsigned short address)
{
struct resource res = {
.start = address,
.end = address + VIA686A_EXTENT - 1,
.name = "via686a",
.flags = IORESOURCE_IO,
};
int err;
err = acpi_check_resource_conflict(&res);
if (err)
goto exit;
pdev = platform_device_alloc("via686a", address);
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
static int __devinit via686a_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
u16 address, val;
if (force_addr) {
address = force_addr & ~(VIA686A_EXTENT - 1);
dev_warn(&dev->dev, "Forcing ISA address 0x%x\n", address);
if (PCIBIOS_SUCCESSFUL !=
pci_write_config_word(dev, VIA686A_BASE_REG, address | 1))
return -ENODEV;
}
if (PCIBIOS_SUCCESSFUL !=
pci_read_config_word(dev, VIA686A_BASE_REG, &val))
return -ENODEV;
address = val & ~(VIA686A_EXTENT - 1);
if (address == 0) {
dev_err(&dev->dev, "base address not set - upgrade BIOS "
"or use force_addr=0xaddr\n");
return -ENODEV;
}
if (PCIBIOS_SUCCESSFUL !=
pci_read_config_word(dev, VIA686A_ENABLE_REG, &val))
return -ENODEV;
if (!(val & 0x0001)) {
if (!force_addr) {
dev_warn(&dev->dev, "Sensors disabled, enable "
"with force_addr=0x%x\n", address);
return -ENODEV;
}
dev_warn(&dev->dev, "Enabling sensors\n");
if (PCIBIOS_SUCCESSFUL !=
pci_write_config_word(dev, VIA686A_ENABLE_REG,
val | 0x0001))
return -ENODEV;
}
if (platform_driver_register(&via686a_driver))
goto exit;
if (via686a_device_add(address))
goto exit_unregister;
s_bridge = pci_dev_get(dev);
return -ENODEV;
exit_unregister:
platform_driver_unregister(&via686a_driver);
exit:
return -ENODEV;
}
static int __init sm_via686a_init(void)
{
return pci_register_driver(&via686a_pci_driver);
}
static void __exit sm_via686a_exit(void)
{
pci_unregister_driver(&via686a_pci_driver);
if (s_bridge != NULL) {
platform_device_unregister(pdev);
platform_driver_unregister(&via686a_driver);
pci_dev_put(s_bridge);
s_bridge = NULL;
}
}
