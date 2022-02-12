static inline void superio_outb(int reg, int val)
{
outb(reg, REG);
outb(val, VAL);
}
static inline int superio_inb(int reg)
{
outb(reg, REG);
return inb(VAL);
}
static inline void superio_select(int ld)
{
superio_outb(0x07, ld);
}
static inline void superio_enter(void)
{
outb(0x55, REG);
}
static inline void superio_exit(void)
{
outb(0xAA, REG);
}
static int smsc47b397_read_value(struct smsc47b397_data *data, u8 reg)
{
int res;
mutex_lock(&data->lock);
outb(reg, data->addr);
res = inb_p(data->addr + 1);
mutex_unlock(&data->lock);
return res;
}
static struct smsc47b397_data *smsc47b397_update_device(struct device *dev)
{
struct smsc47b397_data *data = dev_get_drvdata(dev);
int i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
dev_dbg(dev, "starting device update...\n");
for (i = 0; i < 4; i++) {
data->temp[i] = smsc47b397_read_value(data,
SMSC47B397_REG_TEMP(i));
data->fan[i] = smsc47b397_read_value(data,
SMSC47B397_REG_FAN_LSB(i));
data->fan[i] |= smsc47b397_read_value(data,
SMSC47B397_REG_FAN_MSB(i)) << 8;
}
data->last_updated = jiffies;
data->valid = 1;
dev_dbg(dev, "... device update complete\n");
}
mutex_unlock(&data->update_lock);
return data;
}
static int temp_from_reg(u8 reg)
{
return (s8)reg * 1000;
}
static ssize_t show_temp(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct smsc47b397_data *data = smsc47b397_update_device(dev);
return sprintf(buf, "%d\n", temp_from_reg(data->temp[attr->index]));
}
static int fan_from_reg(u16 reg)
{
if (reg == 0 || reg == 0xffff)
return 0;
return 90000 * 60 / reg;
}
static ssize_t show_fan(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct smsc47b397_data *data = smsc47b397_update_device(dev);
return sprintf(buf, "%d\n", fan_from_reg(data->fan[attr->index]));
}
static ssize_t show_name(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct smsc47b397_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", data->name);
}
static int __devexit smsc47b397_remove(struct platform_device *pdev)
{
struct smsc47b397_data *data = platform_get_drvdata(pdev);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&pdev->dev.kobj, &smsc47b397_group);
return 0;
}
static int __devinit smsc47b397_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct smsc47b397_data *data;
struct resource *res;
int err = 0;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!devm_request_region(dev, res->start, SMSC_EXTENT,
smsc47b397_driver.driver.name)) {
dev_err(dev, "Region 0x%lx-0x%lx already in use!\n",
(unsigned long)res->start,
(unsigned long)res->start + SMSC_EXTENT - 1);
return -EBUSY;
}
data = devm_kzalloc(dev, sizeof(struct smsc47b397_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->addr = res->start;
data->name = "smsc47b397";
mutex_init(&data->lock);
mutex_init(&data->update_lock);
platform_set_drvdata(pdev, data);
err = sysfs_create_group(&dev->kobj, &smsc47b397_group);
if (err)
return err;
data->hwmon_dev = hwmon_device_register(dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto error_remove;
}
return 0;
error_remove:
sysfs_remove_group(&dev->kobj, &smsc47b397_group);
return err;
}
static int __init smsc47b397_device_add(unsigned short address)
{
struct resource res = {
.start = address,
.end = address + SMSC_EXTENT - 1,
.name = DRVNAME,
.flags = IORESOURCE_IO,
};
int err;
err = acpi_check_resource_conflict(&res);
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
static int __init smsc47b397_find(void)
{
u8 id, rev;
char *name;
unsigned short addr;
superio_enter();
id = force_id ? force_id : superio_inb(SUPERIO_REG_DEVID);
switch (id) {
case 0x81:
name = "SCH5307-NS";
break;
case 0x6f:
name = "LPC47B397-NC";
break;
case 0x85:
case 0x8c:
name = "SCH5317";
break;
default:
superio_exit();
return -ENODEV;
}
rev = superio_inb(SUPERIO_REG_DEVREV);
superio_select(SUPERIO_REG_LD8);
addr = (superio_inb(SUPERIO_REG_BASE_MSB) << 8)
| superio_inb(SUPERIO_REG_BASE_LSB);
pr_info("found SMSC %s (base address 0x%04x, revision %u)\n",
name, addr, rev);
superio_exit();
return addr;
}
static int __init smsc47b397_init(void)
{
unsigned short address;
int ret;
ret = smsc47b397_find();
if (ret < 0)
return ret;
address = ret;
ret = platform_driver_register(&smsc47b397_driver);
if (ret)
goto exit;
ret = smsc47b397_device_add(address);
if (ret)
goto exit_driver;
return 0;
exit_driver:
platform_driver_unregister(&smsc47b397_driver);
exit:
return ret;
}
static void __exit smsc47b397_exit(void)
{
platform_device_unregister(pdev);
platform_driver_unregister(&smsc47b397_driver);
}
