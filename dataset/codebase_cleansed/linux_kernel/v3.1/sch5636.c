static struct sch5636_data *sch5636_update_device(struct device *dev)
{
struct sch5636_data *data = dev_get_drvdata(dev);
struct sch5636_data *ret = data;
int i, val;
mutex_lock(&data->update_lock);
if (data->valid && !time_after(jiffies, data->last_updated + HZ))
goto abort;
for (i = 0; i < SCH5636_NO_INS; i++) {
val = sch56xx_read_virtual_reg(data->addr,
SCH5636_REG_IN_VAL[i]);
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->in[i] = val;
}
for (i = 0; i < SCH5636_NO_TEMPS; i++) {
if (data->temp_ctrl[i] & SCH5636_TEMP_DEACTIVATED)
continue;
val = sch56xx_read_virtual_reg(data->addr,
SCH5636_REG_TEMP_VAL[i]);
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->temp_val[i] = val;
val = sch56xx_read_virtual_reg(data->addr,
SCH5636_REG_TEMP_CTRL(i));
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->temp_ctrl[i] = val;
if (val & SCH5636_TEMP_ALARM) {
sch56xx_write_virtual_reg(data->addr,
SCH5636_REG_TEMP_CTRL(i), val);
}
}
for (i = 0; i < SCH5636_NO_FANS; i++) {
if (data->fan_ctrl[i] & SCH5636_FAN_DEACTIVATED)
continue;
val = sch56xx_read_virtual_reg16(data->addr,
SCH5636_REG_FAN_VAL[i]);
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->fan_val[i] = val;
val = sch56xx_read_virtual_reg(data->addr,
SCH5636_REG_FAN_CTRL(i));
if (unlikely(val < 0)) {
ret = ERR_PTR(val);
goto abort;
}
data->fan_ctrl[i] = val;
if (val & SCH5636_FAN_ALARM) {
sch56xx_write_virtual_reg(data->addr,
SCH5636_REG_FAN_CTRL(i), val);
}
}
data->last_updated = jiffies;
data->valid = 1;
abort:
mutex_unlock(&data->update_lock);
return ret;
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
static ssize_t show_in_value(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct sch5636_data *data = sch5636_update_device(dev);
int val;
if (IS_ERR(data))
return PTR_ERR(data);
val = DIV_ROUND_CLOSEST(
data->in[attr->index] * SCH5636_REG_IN_FACTORS[attr->index],
255);
return snprintf(buf, PAGE_SIZE, "%d\n", val);
}
static ssize_t show_in_label(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
return snprintf(buf, PAGE_SIZE, "%s\n",
SCH5636_IN_LABELS[attr->index]);
}
static ssize_t show_temp_value(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct sch5636_data *data = sch5636_update_device(dev);
int val;
if (IS_ERR(data))
return PTR_ERR(data);
val = (data->temp_val[attr->index] - 64) * 1000;
return snprintf(buf, PAGE_SIZE, "%d\n", val);
}
static ssize_t show_temp_fault(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct sch5636_data *data = sch5636_update_device(dev);
int val;
if (IS_ERR(data))
return PTR_ERR(data);
val = (data->temp_ctrl[attr->index] & SCH5636_TEMP_WORKING) ? 0 : 1;
return snprintf(buf, PAGE_SIZE, "%d\n", val);
}
static ssize_t show_temp_alarm(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct sch5636_data *data = sch5636_update_device(dev);
int val;
if (IS_ERR(data))
return PTR_ERR(data);
val = (data->temp_ctrl[attr->index] & SCH5636_TEMP_ALARM) ? 1 : 0;
return snprintf(buf, PAGE_SIZE, "%d\n", val);
}
static ssize_t show_fan_value(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct sch5636_data *data = sch5636_update_device(dev);
int val;
if (IS_ERR(data))
return PTR_ERR(data);
val = reg_to_rpm(data->fan_val[attr->index]);
if (val < 0)
return val;
return snprintf(buf, PAGE_SIZE, "%d\n", val);
}
static ssize_t show_fan_fault(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct sch5636_data *data = sch5636_update_device(dev);
int val;
if (IS_ERR(data))
return PTR_ERR(data);
val = (data->fan_ctrl[attr->index] & SCH5636_FAN_NOT_PRESENT) ? 1 : 0;
return snprintf(buf, PAGE_SIZE, "%d\n", val);
}
static ssize_t show_fan_alarm(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct sch5636_data *data = sch5636_update_device(dev);
int val;
if (IS_ERR(data))
return PTR_ERR(data);
val = (data->fan_ctrl[attr->index] & SCH5636_FAN_ALARM) ? 1 : 0;
return snprintf(buf, PAGE_SIZE, "%d\n", val);
}
static int sch5636_remove(struct platform_device *pdev)
{
struct sch5636_data *data = platform_get_drvdata(pdev);
int i;
if (data->hwmon_dev)
hwmon_device_unregister(data->hwmon_dev);
for (i = 0; i < ARRAY_SIZE(sch5636_attr); i++)
device_remove_file(&pdev->dev, &sch5636_attr[i].dev_attr);
for (i = 0; i < SCH5636_NO_TEMPS * 3; i++)
device_remove_file(&pdev->dev,
&sch5636_temp_attr[i].dev_attr);
for (i = 0; i < SCH5636_NO_FANS * 3; i++)
device_remove_file(&pdev->dev,
&sch5636_fan_attr[i].dev_attr);
platform_set_drvdata(pdev, NULL);
kfree(data);
return 0;
}
static int __devinit sch5636_probe(struct platform_device *pdev)
{
struct sch5636_data *data;
int i, err, val, revision[2];
char id[4];
data = kzalloc(sizeof(struct sch5636_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->addr = platform_get_resource(pdev, IORESOURCE_IO, 0)->start;
mutex_init(&data->update_lock);
platform_set_drvdata(pdev, data);
for (i = 0; i < 3; i++) {
val = sch56xx_read_virtual_reg(data->addr,
SCH5636_REG_FUJITSU_ID + i);
if (val < 0) {
pr_err("Could not read Fujitsu id byte at %#x\n",
SCH5636_REG_FUJITSU_ID + i);
err = val;
goto error;
}
id[i] = val;
}
id[i] = '\0';
if (strcmp(id, "THS")) {
pr_err("Unknown Fujitsu id: %02x%02x%02x\n",
id[0], id[1], id[2]);
err = -ENODEV;
goto error;
}
for (i = 0; i < 2; i++) {
val = sch56xx_read_virtual_reg(data->addr,
SCH5636_REG_FUJITSU_REV + i);
if (val < 0) {
err = val;
goto error;
}
revision[i] = val;
}
pr_info("Found %s chip at %#hx, revison: %d.%02d\n", DEVNAME,
data->addr, revision[0], revision[1]);
for (i = 0; i < SCH5636_NO_TEMPS; i++) {
val = sch56xx_read_virtual_reg(data->addr,
SCH5636_REG_TEMP_CTRL(i));
if (unlikely(val < 0)) {
err = val;
goto error;
}
data->temp_ctrl[i] = val;
}
for (i = 0; i < SCH5636_NO_FANS; i++) {
val = sch56xx_read_virtual_reg(data->addr,
SCH5636_REG_FAN_CTRL(i));
if (unlikely(val < 0)) {
err = val;
goto error;
}
data->fan_ctrl[i] = val;
}
for (i = 0; i < ARRAY_SIZE(sch5636_attr); i++) {
err = device_create_file(&pdev->dev,
&sch5636_attr[i].dev_attr);
if (err)
goto error;
}
for (i = 0; i < (SCH5636_NO_TEMPS * 3); i++) {
if (data->temp_ctrl[i/3] & SCH5636_TEMP_DEACTIVATED)
continue;
err = device_create_file(&pdev->dev,
&sch5636_temp_attr[i].dev_attr);
if (err)
goto error;
}
for (i = 0; i < (SCH5636_NO_FANS * 3); i++) {
if (data->fan_ctrl[i/3] & SCH5636_FAN_DEACTIVATED)
continue;
err = device_create_file(&pdev->dev,
&sch5636_fan_attr[i].dev_attr);
if (err)
goto error;
}
data->hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
data->hwmon_dev = NULL;
goto error;
}
return 0;
error:
sch5636_remove(pdev);
return err;
}
static int __init sch5636_init(void)
{
return platform_driver_register(&sch5636_driver);
}
static void __exit sch5636_exit(void)
{
platform_driver_unregister(&sch5636_driver);
}
