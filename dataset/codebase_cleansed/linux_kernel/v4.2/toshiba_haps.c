static int toshiba_haps_reset_protection(acpi_handle handle)
{
acpi_status status;
status = acpi_evaluate_object(handle, "RSSS", NULL, NULL);
if (ACPI_FAILURE(status)) {
pr_err("Unable to reset the HDD protection\n");
return -EIO;
}
return 0;
}
static int toshiba_haps_protection_level(acpi_handle handle, int level)
{
acpi_status status;
status = acpi_execute_simple_method(handle, "PTLV", level);
if (ACPI_FAILURE(status)) {
pr_err("Error while setting the protection level\n");
return -EIO;
}
pr_info("HDD protection level set to: %d\n", level);
return 0;
}
static ssize_t protection_level_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct toshiba_haps_dev *haps = dev_get_drvdata(dev);
return sprintf(buf, "%i\n", haps->protection_level);
}
static ssize_t protection_level_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct toshiba_haps_dev *haps = dev_get_drvdata(dev);
int level;
int ret;
ret = kstrtoint(buf, 0, &level);
if (ret)
return ret;
if (level < 0 || level > 3)
return -EINVAL;
ret = toshiba_haps_protection_level(haps->acpi_dev->handle, level);
if (ret != 0)
return ret;
haps->protection_level = level;
return count;
}
static ssize_t reset_protection_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct toshiba_haps_dev *haps = dev_get_drvdata(dev);
int reset;
int ret;
ret = kstrtoint(buf, 0, &reset);
if (ret)
return ret;
if (reset != 1)
return -EINVAL;
ret = toshiba_haps_reset_protection(haps->acpi_dev->handle);
if (ret != 0)
return ret;
return count;
}
static void toshiba_haps_notify(struct acpi_device *device, u32 event)
{
pr_info("Received event: 0x%x", event);
acpi_bus_generate_netlink_event(device->pnp.device_class,
dev_name(&device->dev),
event, 0);
}
static int toshiba_haps_remove(struct acpi_device *device)
{
sysfs_remove_group(&device->dev.kobj, &haps_attr_group);
if (toshiba_haps)
toshiba_haps = NULL;
return 0;
}
static int toshiba_haps_available(acpi_handle handle)
{
acpi_status status;
u64 hdd_present;
status = acpi_evaluate_integer(handle, "_STA", NULL,
&hdd_present);
if (ACPI_FAILURE(status) || !hdd_present) {
pr_info("HDD protection not available or using SSD\n");
return 0;
}
return 1;
}
static int toshiba_haps_add(struct acpi_device *acpi_dev)
{
struct toshiba_haps_dev *haps;
int ret;
if (toshiba_haps)
return -EBUSY;
if (!toshiba_haps_available(acpi_dev->handle))
return -ENODEV;
pr_info("Toshiba HDD Active Protection Sensor device\n");
haps = kzalloc(sizeof(struct toshiba_haps_dev), GFP_KERNEL);
if (!haps)
return -ENOMEM;
haps->acpi_dev = acpi_dev;
haps->protection_level = 2;
acpi_dev->driver_data = haps;
dev_set_drvdata(&acpi_dev->dev, haps);
ret = toshiba_haps_protection_level(acpi_dev->handle, 2);
if (ret != 0)
return ret;
ret = sysfs_create_group(&acpi_dev->dev.kobj, &haps_attr_group);
if (ret)
return ret;
toshiba_haps = haps;
return 0;
}
static int toshiba_haps_suspend(struct device *device)
{
struct toshiba_haps_dev *haps;
int ret;
haps = acpi_driver_data(to_acpi_device(device));
ret = toshiba_haps_protection_level(haps->acpi_dev->handle, 0);
return ret;
}
static int toshiba_haps_resume(struct device *device)
{
struct toshiba_haps_dev *haps;
int ret;
haps = acpi_driver_data(to_acpi_device(device));
ret = toshiba_haps_protection_level(haps->acpi_dev->handle,
haps->protection_level);
ret = toshiba_haps_reset_protection(haps->acpi_dev->handle);
if (ret != 0)
return ret;
return ret;
}
