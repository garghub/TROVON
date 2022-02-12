static inline int superio_inb(int base, int reg)
{
outb(reg, base);
return inb(base + 1);
}
static inline int superio_enter(int base)
{
if (!request_muxed_region(base, 2, DRVNAME)) {
pr_err("I/O address 0x%04x already in use\n", base);
return -EBUSY;
}
outb(SIO_UNLOCK_KEY, base);
return 0;
}
static inline void superio_select(int base, int ld)
{
outb(SIO_REG_LDSEL, base);
outb(ld, base + 1);
}
static inline void superio_exit(int base)
{
outb(SIO_LOCK_KEY, base);
release_region(base, 2);
}
static int sch5627_send_cmd(struct sch5627_data *data, u8 cmd, u16 reg, u8 v)
{
u8 val;
int i;
const int max_busy_polls = 64;
const int max_lazy_polls = 32;
val = inb(data->addr + 1);
outb(val, data->addr + 1);
outb(0x00, data->addr + 2);
outb(0x80, data->addr + 3);
outb(cmd, data->addr + 4);
outb(0x01, data->addr + 5);
outb(0x04, data->addr + 2);
if (cmd == SCH5627_CMD_WRITE)
outb(v, data->addr + 4);
outb(reg & 0xff, data->addr + 6);
outb(reg >> 8, data->addr + 7);
outb(0x01, data->addr);
for (i = 0; i < max_busy_polls + max_lazy_polls; i++) {
if (i >= max_busy_polls)
msleep(1);
val = inb(data->addr + 8);
if (val)
outb(val, data->addr + 8);
if (val & 0x01)
break;
}
if (i == max_busy_polls + max_lazy_polls) {
pr_err("Max retries exceeded reading virtual "
"register 0x%04hx (%d)\n", reg, 1);
return -EIO;
}
for (i = 0; i < max_busy_polls; i++) {
val = inb(data->addr + 1);
if (val == 0x01)
break;
if (i == 0)
pr_warn("EC reports: 0x%02x reading virtual register "
"0x%04hx\n", (unsigned int)val, reg);
}
if (i == max_busy_polls) {
pr_err("Max retries exceeded reading virtual "
"register 0x%04hx (%d)\n", reg, 2);
return -EIO;
}
if (cmd == SCH5627_CMD_READ)
return inb(data->addr + 4);
return 0;
}
static int sch5627_read_virtual_reg(struct sch5627_data *data, u16 reg)
{
return sch5627_send_cmd(data, SCH5627_CMD_READ, reg, 0);
}
static int sch5627_write_virtual_reg(struct sch5627_data *data,
u16 reg, u8 val)
{
return sch5627_send_cmd(data, SCH5627_CMD_WRITE, reg, val);
}
static int sch5627_read_virtual_reg16(struct sch5627_data *data, u16 reg)
{
int lsb, msb;
lsb = sch5627_read_virtual_reg(data, reg);
if (lsb < 0)
return lsb;
msb = sch5627_read_virtual_reg(data, reg + 1);
if (msb < 0)
return msb;
return lsb | (msb << 8);
}
static int sch5627_read_virtual_reg12(struct sch5627_data *data, u16 msb_reg,
u16 lsn_reg, int high_nibble)
{
int msb, lsn;
msb = sch5627_read_virtual_reg(data, msb_reg);
if (msb < 0)
return msb;
lsn = sch5627_read_virtual_reg(data, lsn_reg);
if (lsn < 0)
return lsn;
if (high_nibble)
return (msb << 4) | (lsn >> 4);
else
return (msb << 4) | (lsn & 0x0f);
}
static struct sch5627_data *sch5627_update_device(struct device *dev)
{
struct sch5627_data *data = dev_get_drvdata(dev);
struct sch5627_data *ret = data;
int i, val;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_battery + 300 * HZ)) {
sch5627_write_virtual_reg(data, SCH5627_REG_CTRL,
data->control | 0x10);
data->last_battery = jiffies;
}
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
for (i = 0; i < SCH5627_NO_TEMPS; i++) {
val = sch5627_read_virtual_reg12(data,
SCH5627_REG_TEMP_MSB[i],
SCH5627_REG_TEMP_LSN[i],
SCH5627_REG_TEMP_HIGH_NIBBLE[i]);
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->temp[i] = val;
}
for (i = 0; i < SCH5627_NO_FANS; i++) {
val = sch5627_read_virtual_reg16(data,
SCH5627_REG_FAN[i]);
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->fan[i] = val;
}
for (i = 0; i < SCH5627_NO_IN; i++) {
val = sch5627_read_virtual_reg12(data,
SCH5627_REG_IN_MSB[i],
SCH5627_REG_IN_LSN[i],
SCH5627_REG_IN_HIGH_NIBBLE[i]);
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->in[i] = val;
}
data->last_updated = jiffies;
data->valid = 1;
}
abort:
mutex_unlock(&data->update_lock);
return ret;
}
static int __devinit sch5627_read_limits(struct sch5627_data *data)
{
int i, val;
for (i = 0; i < SCH5627_NO_TEMPS; i++) {
val = sch5627_read_virtual_reg(data, SCH5627_REG_TEMP_ABS[i]);
if (val < 0)
return val;
data->temp_max[i] = val;
val = sch5627_read_virtual_reg(data, SCH5627_REG_TEMP_HIGH[i]);
if (val < 0)
return val;
data->temp_crit[i] = val;
}
for (i = 0; i < SCH5627_NO_FANS; i++) {
val = sch5627_read_virtual_reg16(data, SCH5627_REG_FAN_MIN[i]);
if (val < 0)
return val;
data->fan_min[i] = val;
}
return 0;
}
static int reg_to_temp(u16 reg)
{
return (reg * 625) / 10 - 64000;
}
static int reg_to_temp_limit(u8 reg)
{
return (reg - 64) * 1000;
}
static int reg_to_rpm(u16 reg)
{
if (reg == 0)
return -EIO;
if (reg == 0xffff)
return 0;
return 5400540 / reg;
}
static ssize_t show_name(struct device *dev, struct device_attribute *devattr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n", DEVNAME);
}
static ssize_t show_temp(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct sch5627_data *data = sch5627_update_device(dev);
int val;
if (IS_ERR(data))
return PTR_ERR(data);
val = reg_to_temp(data->temp[attr->index]);
return snprintf(buf, PAGE_SIZE, "%d\n", val);
}
static ssize_t show_temp_fault(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct sch5627_data *data = sch5627_update_device(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return snprintf(buf, PAGE_SIZE, "%d\n", data->temp[attr->index] == 0);
}
static ssize_t show_temp_max(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct sch5627_data *data = dev_get_drvdata(dev);
int val;
val = reg_to_temp_limit(data->temp_max[attr->index]);
return snprintf(buf, PAGE_SIZE, "%d\n", val);
}
static ssize_t show_temp_crit(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct sch5627_data *data = dev_get_drvdata(dev);
int val;
val = reg_to_temp_limit(data->temp_crit[attr->index]);
return snprintf(buf, PAGE_SIZE, "%d\n", val);
}
static ssize_t show_fan(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct sch5627_data *data = sch5627_update_device(dev);
int val;
if (IS_ERR(data))
return PTR_ERR(data);
val = reg_to_rpm(data->fan[attr->index]);
if (val < 0)
return val;
return snprintf(buf, PAGE_SIZE, "%d\n", val);
}
static ssize_t show_fan_fault(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct sch5627_data *data = sch5627_update_device(dev);
if (IS_ERR(data))
return PTR_ERR(data);
return snprintf(buf, PAGE_SIZE, "%d\n",
data->fan[attr->index] == 0xffff);
}
static ssize_t show_fan_min(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct sch5627_data *data = dev_get_drvdata(dev);
int val = reg_to_rpm(data->fan_min[attr->index]);
if (val < 0)
return val;
return snprintf(buf, PAGE_SIZE, "%d\n", val);
}
static ssize_t show_in(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct sch5627_data *data = sch5627_update_device(dev);
int val;
if (IS_ERR(data))
return PTR_ERR(data);
val = DIV_ROUND_CLOSEST(
data->in[attr->index] * SCH5627_REG_IN_FACTOR[attr->index],
10000);
return snprintf(buf, PAGE_SIZE, "%d\n", val);
}
static ssize_t show_in_label(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
return snprintf(buf, PAGE_SIZE, "%s\n",
SCH5627_IN_LABELS[attr->index]);
}
static int sch5627_remove(struct platform_device *pdev)
{
struct sch5627_data *data = platform_get_drvdata(pdev);
if (data->hwmon_dev)
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&pdev->dev.kobj, &sch5627_group);
platform_set_drvdata(pdev, NULL);
kfree(data);
return 0;
}
static int __devinit sch5627_probe(struct platform_device *pdev)
{
struct sch5627_data *data;
int err, build_code, build_id, hwmon_rev, val;
data = kzalloc(sizeof(struct sch5627_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->addr = platform_get_resource(pdev, IORESOURCE_IO, 0)->start;
mutex_init(&data->update_lock);
platform_set_drvdata(pdev, data);
val = sch5627_read_virtual_reg(data, SCH5627_REG_HWMON_ID);
if (val < 0) {
err = val;
goto error;
}
if (val != SCH5627_HWMON_ID) {
pr_err("invalid %s id: 0x%02X (expected 0x%02X)\n", "hwmon",
val, SCH5627_HWMON_ID);
err = -ENODEV;
goto error;
}
val = sch5627_read_virtual_reg(data, SCH5627_REG_COMPANY_ID);
if (val < 0) {
err = val;
goto error;
}
if (val != SCH5627_COMPANY_ID) {
pr_err("invalid %s id: 0x%02X (expected 0x%02X)\n", "company",
val, SCH5627_COMPANY_ID);
err = -ENODEV;
goto error;
}
val = sch5627_read_virtual_reg(data, SCH5627_REG_PRIMARY_ID);
if (val < 0) {
err = val;
goto error;
}
if (val != SCH5627_PRIMARY_ID) {
pr_err("invalid %s id: 0x%02X (expected 0x%02X)\n", "primary",
val, SCH5627_PRIMARY_ID);
err = -ENODEV;
goto error;
}
build_code = sch5627_read_virtual_reg(data, SCH5627_REG_BUILD_CODE);
if (build_code < 0) {
err = build_code;
goto error;
}
build_id = sch5627_read_virtual_reg16(data, SCH5627_REG_BUILD_ID);
if (build_id < 0) {
err = build_id;
goto error;
}
hwmon_rev = sch5627_read_virtual_reg(data, SCH5627_REG_HWMON_REV);
if (hwmon_rev < 0) {
err = hwmon_rev;
goto error;
}
val = sch5627_read_virtual_reg(data, SCH5627_REG_CTRL);
if (val < 0) {
err = val;
goto error;
}
data->control = val;
if (!(data->control & 0x01)) {
pr_err("hardware monitoring not enabled\n");
err = -ENODEV;
goto error;
}
sch5627_write_virtual_reg(data, SCH5627_REG_CTRL,
data->control | 0x10);
data->last_battery = jiffies;
err = sch5627_read_limits(data);
if (err)
goto error;
pr_info("firmware build: code 0x%02X, id 0x%04X, hwmon: rev 0x%02X\n",
build_code, build_id, hwmon_rev);
err = sysfs_create_group(&pdev->dev.kobj, &sch5627_group);
if (err)
goto error;
data->hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
data->hwmon_dev = NULL;
goto error;
}
return 0;
error:
sch5627_remove(pdev);
return err;
}
static int __init sch5627_find(int sioaddr, unsigned short *address)
{
u8 devid;
int err = superio_enter(sioaddr);
if (err)
return err;
devid = superio_inb(sioaddr, SIO_REG_DEVID);
if (devid != SIO_SCH5627_ID) {
pr_debug("Unsupported device id: 0x%02x\n",
(unsigned int)devid);
err = -ENODEV;
goto exit;
}
superio_select(sioaddr, SIO_SCH5627_EM_LD);
if (!(superio_inb(sioaddr, SIO_REG_ENABLE) & 0x01)) {
pr_warn("Device not activated\n");
err = -ENODEV;
goto exit;
}
*address = superio_inb(sioaddr, SIO_REG_ADDR) |
superio_inb(sioaddr, SIO_REG_ADDR + 1) << 8;
if (*address == 0) {
pr_warn("Base address not set\n");
err = -ENODEV;
goto exit;
}
pr_info("Found %s chip at %#hx\n", DEVNAME, *address);
exit:
superio_exit(sioaddr);
return err;
}
static int __init sch5627_device_add(unsigned short address)
{
struct resource res = {
.start = address,
.end = address + REGION_LENGTH - 1,
.flags = IORESOURCE_IO,
};
int err;
sch5627_pdev = platform_device_alloc(DRVNAME, address);
if (!sch5627_pdev)
return -ENOMEM;
res.name = sch5627_pdev->name;
err = acpi_check_resource_conflict(&res);
if (err)
goto exit_device_put;
err = platform_device_add_resources(sch5627_pdev, &res, 1);
if (err) {
pr_err("Device resource addition failed\n");
goto exit_device_put;
}
err = platform_device_add(sch5627_pdev);
if (err) {
pr_err("Device addition failed\n");
goto exit_device_put;
}
return 0;
exit_device_put:
platform_device_put(sch5627_pdev);
return err;
}
static int __init sch5627_init(void)
{
int err = -ENODEV;
unsigned short address;
if (sch5627_find(0x4e, &address) && sch5627_find(0x2e, &address))
goto exit;
err = platform_driver_register(&sch5627_driver);
if (err)
goto exit;
err = sch5627_device_add(address);
if (err)
goto exit_driver;
return 0;
exit_driver:
platform_driver_unregister(&sch5627_driver);
exit:
return err;
}
static void __exit sch5627_exit(void)
{
platform_device_unregister(sch5627_pdev);
platform_driver_unregister(&sch5627_driver);
}
