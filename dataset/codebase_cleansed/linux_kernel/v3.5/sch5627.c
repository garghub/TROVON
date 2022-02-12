static struct sch5627_data *sch5627_update_device(struct device *dev)
{
struct sch5627_data *data = dev_get_drvdata(dev);
struct sch5627_data *ret = data;
int i, val;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_battery + 300 * HZ)) {
sch56xx_write_virtual_reg(data->addr, SCH5627_REG_CTRL,
data->control | 0x10);
data->last_battery = jiffies;
}
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
for (i = 0; i < SCH5627_NO_TEMPS; i++) {
val = sch56xx_read_virtual_reg12(data->addr,
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
val = sch56xx_read_virtual_reg16(data->addr,
SCH5627_REG_FAN[i]);
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->fan[i] = val;
}
for (i = 0; i < SCH5627_NO_IN; i++) {
val = sch56xx_read_virtual_reg12(data->addr,
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
val = sch56xx_read_virtual_reg(data->addr,
SCH5627_REG_TEMP_ABS[i]);
if (val < 0)
return val;
data->temp_max[i] = val;
val = sch56xx_read_virtual_reg(data->addr,
SCH5627_REG_TEMP_HIGH[i]);
if (val < 0)
return val;
data->temp_crit[i] = val;
}
for (i = 0; i < SCH5627_NO_FANS; i++) {
val = sch56xx_read_virtual_reg16(data->addr,
SCH5627_REG_FAN_MIN[i]);
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
if (data->watchdog)
sch56xx_watchdog_unregister(data->watchdog);
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
val = sch56xx_read_virtual_reg(data->addr, SCH5627_REG_HWMON_ID);
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
val = sch56xx_read_virtual_reg(data->addr, SCH5627_REG_COMPANY_ID);
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
val = sch56xx_read_virtual_reg(data->addr, SCH5627_REG_PRIMARY_ID);
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
build_code = sch56xx_read_virtual_reg(data->addr,
SCH5627_REG_BUILD_CODE);
if (build_code < 0) {
err = build_code;
goto error;
}
build_id = sch56xx_read_virtual_reg16(data->addr,
SCH5627_REG_BUILD_ID);
if (build_id < 0) {
err = build_id;
goto error;
}
hwmon_rev = sch56xx_read_virtual_reg(data->addr,
SCH5627_REG_HWMON_REV);
if (hwmon_rev < 0) {
err = hwmon_rev;
goto error;
}
val = sch56xx_read_virtual_reg(data->addr, SCH5627_REG_CTRL);
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
sch56xx_write_virtual_reg(data->addr, SCH5627_REG_CTRL,
data->control | 0x10);
data->last_battery = jiffies;
err = sch5627_read_limits(data);
if (err)
goto error;
pr_info("found %s chip at %#hx\n", DEVNAME, data->addr);
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
data->watchdog = sch56xx_watchdog_register(&pdev->dev, data->addr,
(build_code << 24) | (build_id << 8) | hwmon_rev,
&data->update_lock, 1);
return 0;
error:
sch5627_remove(pdev);
return err;
}
