static int acpi_container_offline(struct container_dev *cdev)
{
struct acpi_device *adev = ACPI_COMPANION(&cdev->dev);
struct acpi_device *child;
list_for_each_entry(child, &adev->children, node)
if (!acpi_scan_is_offline(child, false))
return -EBUSY;
return 0;
}
static void acpi_container_release(struct device *dev)
{
kfree(to_container_dev(dev));
}
static int container_device_attach(struct acpi_device *adev,
const struct acpi_device_id *not_used)
{
struct container_dev *cdev;
struct device *dev;
int ret;
cdev = kzalloc(sizeof(*cdev), GFP_KERNEL);
if (!cdev)
return -ENOMEM;
cdev->offline = acpi_container_offline;
dev = &cdev->dev;
dev->bus = &container_subsys;
dev_set_name(dev, "%s", dev_name(&adev->dev));
ACPI_COMPANION_SET(dev, adev);
dev->release = acpi_container_release;
ret = device_register(dev);
if (ret) {
put_device(dev);
return ret;
}
adev->driver_data = dev;
return 1;
}
static void container_device_detach(struct acpi_device *adev)
{
struct device *dev = acpi_driver_data(adev);
adev->driver_data = NULL;
if (dev)
device_unregister(dev);
}
void __init acpi_container_init(void)
{
acpi_scan_add_handler_with_hotplug(&container_handler, "container");
}
