static int memory_get_max_bandwidth(struct thermal_cooling_device *cdev,
unsigned long *max_state)
{
struct acpi_device *device = cdev->devdata;
acpi_handle handle = device->handle;
unsigned long long value;
struct acpi_object_list arg_list;
union acpi_object arg;
acpi_status status = AE_OK;
arg_list.count = 1;
arg_list.pointer = &arg;
arg.type = ACPI_TYPE_INTEGER;
arg.integer.value = MEMORY_ARG_MAX_BANDWIDTH;
status = acpi_evaluate_integer(handle, MEMORY_GET_BANDWIDTH,
&arg_list, &value);
if (ACPI_FAILURE(status))
return -EFAULT;
if (!value)
return -EINVAL;
*max_state = value - 1;
return 0;
}
static int memory_get_cur_bandwidth(struct thermal_cooling_device *cdev,
unsigned long *value)
{
struct acpi_device *device = cdev->devdata;
acpi_handle handle = device->handle;
unsigned long long result;
struct acpi_object_list arg_list;
union acpi_object arg;
acpi_status status = AE_OK;
arg_list.count = 1;
arg_list.pointer = &arg;
arg.type = ACPI_TYPE_INTEGER;
arg.integer.value = MEMORY_ARG_CUR_BANDWIDTH;
status = acpi_evaluate_integer(handle, MEMORY_GET_BANDWIDTH,
&arg_list, &result);
if (ACPI_FAILURE(status))
return -EFAULT;
*value = result;
return 0;
}
static int memory_set_cur_bandwidth(struct thermal_cooling_device *cdev,
unsigned long state)
{
struct acpi_device *device = cdev->devdata;
acpi_handle handle = device->handle;
struct acpi_object_list arg_list;
union acpi_object arg;
acpi_status status;
unsigned long long temp;
unsigned long max_state;
if (memory_get_max_bandwidth(cdev, &max_state))
return -EFAULT;
if (state > max_state)
return -EINVAL;
arg_list.count = 1;
arg_list.pointer = &arg;
arg.type = ACPI_TYPE_INTEGER;
arg.integer.value = state;
status =
acpi_evaluate_integer(handle, MEMORY_SET_BANDWIDTH, &arg_list,
&temp);
pr_info("Bandwidth value was %ld: status is %d\n", state, status);
if (ACPI_FAILURE(status))
return -EFAULT;
return 0;
}
static int intel_menlow_memory_add(struct acpi_device *device)
{
int result = -ENODEV;
struct thermal_cooling_device *cdev;
if (!device)
return -EINVAL;
if (!acpi_has_method(device->handle, MEMORY_GET_BANDWIDTH))
goto end;
if (!acpi_has_method(device->handle, MEMORY_SET_BANDWIDTH))
goto end;
cdev = thermal_cooling_device_register("Memory controller", device,
&memory_cooling_ops);
if (IS_ERR(cdev)) {
result = PTR_ERR(cdev);
goto end;
}
device->driver_data = cdev;
result = sysfs_create_link(&device->dev.kobj,
&cdev->device.kobj, "thermal_cooling");
if (result)
goto unregister;
result = sysfs_create_link(&cdev->device.kobj,
&device->dev.kobj, "device");
if (result) {
sysfs_remove_link(&device->dev.kobj, "thermal_cooling");
goto unregister;
}
end:
return result;
unregister:
thermal_cooling_device_unregister(cdev);
return result;
}
static int intel_menlow_memory_remove(struct acpi_device *device)
{
struct thermal_cooling_device *cdev = acpi_driver_data(device);
if (!device || !cdev)
return -EINVAL;
sysfs_remove_link(&device->dev.kobj, "thermal_cooling");
sysfs_remove_link(&cdev->device.kobj, "device");
thermal_cooling_device_unregister(cdev);
return 0;
}
static int sensor_get_auxtrip(acpi_handle handle, int index,
unsigned long long *value)
{
acpi_status status;
if ((index != 0 && index != 1) || !value)
return -EINVAL;
status = acpi_evaluate_integer(handle, index ? GET_AUX1 : GET_AUX0,
NULL, value);
if (ACPI_FAILURE(status))
return -EIO;
return 0;
}
static int sensor_set_auxtrip(acpi_handle handle, int index, int value)
{
acpi_status status;
union acpi_object arg = {
ACPI_TYPE_INTEGER
};
struct acpi_object_list args = {
1, &arg
};
unsigned long long temp;
if (index != 0 && index != 1)
return -EINVAL;
status = acpi_evaluate_integer(handle, index ? GET_AUX0 : GET_AUX1,
NULL, &temp);
if (ACPI_FAILURE(status))
return -EIO;
if ((index && value < temp) || (!index && value > temp))
return -EINVAL;
arg.integer.value = value;
status = acpi_evaluate_integer(handle, index ? SET_AUX1 : SET_AUX0,
&args, &temp);
if (ACPI_FAILURE(status))
return -EIO;
return 0;
}
static ssize_t aux0_show(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct intel_menlow_attribute *attr = to_intel_menlow_attr(dev_attr);
unsigned long long value;
int result;
result = sensor_get_auxtrip(attr->handle, 0, &value);
return result ? result : sprintf(buf, "%lu", KELVIN_TO_CELSIUS(value));
}
static ssize_t aux1_show(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct intel_menlow_attribute *attr = to_intel_menlow_attr(dev_attr);
unsigned long long value;
int result;
result = sensor_get_auxtrip(attr->handle, 1, &value);
return result ? result : sprintf(buf, "%lu", KELVIN_TO_CELSIUS(value));
}
static ssize_t aux0_store(struct device *dev,
struct device_attribute *dev_attr,
const char *buf, size_t count)
{
struct intel_menlow_attribute *attr = to_intel_menlow_attr(dev_attr);
int value;
int result;
if (!sscanf(buf, "%d", &value))
return -EINVAL;
if (value < 0)
return -EINVAL;
result = sensor_set_auxtrip(attr->handle, 0, CELSIUS_TO_KELVIN(value));
return result ? result : count;
}
static ssize_t aux1_store(struct device *dev,
struct device_attribute *dev_attr,
const char *buf, size_t count)
{
struct intel_menlow_attribute *attr = to_intel_menlow_attr(dev_attr);
int value;
int result;
if (!sscanf(buf, "%d", &value))
return -EINVAL;
if (value < 0)
return -EINVAL;
result = sensor_set_auxtrip(attr->handle, 1, CELSIUS_TO_KELVIN(value));
return result ? result : count;
}
static ssize_t bios_enabled_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
acpi_status status;
unsigned long long bios_enabled;
status = acpi_evaluate_integer(NULL, BIOS_ENABLED, NULL, &bios_enabled);
if (ACPI_FAILURE(status))
return -ENODEV;
return sprintf(buf, "%s\n", bios_enabled ? "enabled" : "disabled");
}
static int intel_menlow_add_one_attribute(char *name, umode_t mode, void *show,
void *store, struct device *dev,
acpi_handle handle)
{
struct intel_menlow_attribute *attr;
int result;
attr = kzalloc(sizeof(struct intel_menlow_attribute), GFP_KERNEL);
if (!attr)
return -ENOMEM;
sysfs_attr_init(&attr->attr.attr);
attr->attr.attr.name = name;
attr->attr.attr.mode = mode;
attr->attr.show = show;
attr->attr.store = store;
attr->device = dev;
attr->handle = handle;
result = device_create_file(dev, &attr->attr);
if (result) {
kfree(attr);
return result;
}
mutex_lock(&intel_menlow_attr_lock);
list_add_tail(&attr->node, &intel_menlow_attr_list);
mutex_unlock(&intel_menlow_attr_lock);
return 0;
}
static acpi_status intel_menlow_register_sensor(acpi_handle handle, u32 lvl,
void *context, void **rv)
{
acpi_status status;
acpi_handle dummy;
struct thermal_zone_device *thermal;
int result;
result = acpi_bus_get_private_data(handle, (void **)&thermal);
if (result)
return 0;
status = acpi_get_handle(handle, GET_AUX0, &dummy);
if (ACPI_FAILURE(status))
return (status == AE_NOT_FOUND) ? AE_OK : status;
status = acpi_get_handle(handle, SET_AUX0, &dummy);
if (ACPI_FAILURE(status))
return (status == AE_NOT_FOUND) ? AE_OK : status;
result = intel_menlow_add_one_attribute("aux0", 0644,
aux0_show, aux0_store,
&thermal->device, handle);
if (result)
return AE_ERROR;
status = acpi_get_handle(handle, GET_AUX1, &dummy);
if (ACPI_FAILURE(status))
goto aux1_not_found;
status = acpi_get_handle(handle, SET_AUX1, &dummy);
if (ACPI_FAILURE(status))
goto aux1_not_found;
result = intel_menlow_add_one_attribute("aux1", 0644,
aux1_show, aux1_store,
&thermal->device, handle);
if (result) {
intel_menlow_unregister_sensor();
return AE_ERROR;
}
result = intel_menlow_add_one_attribute("bios_enabled", 0444,
bios_enabled_show, NULL,
&thermal->device, handle);
if (result) {
intel_menlow_unregister_sensor();
return AE_ERROR;
}
return AE_OK;
aux1_not_found:
if (status == AE_NOT_FOUND)
return AE_OK;
intel_menlow_unregister_sensor();
return status;
}
static void intel_menlow_unregister_sensor(void)
{
struct intel_menlow_attribute *pos, *next;
mutex_lock(&intel_menlow_attr_lock);
list_for_each_entry_safe(pos, next, &intel_menlow_attr_list, node) {
list_del(&pos->node);
device_remove_file(pos->device, &pos->attr);
kfree(pos);
}
mutex_unlock(&intel_menlow_attr_lock);
return;
}
static int __init intel_menlow_module_init(void)
{
int result = -ENODEV;
acpi_status status;
unsigned long long enable;
if (acpi_disabled)
return result;
status = acpi_evaluate_integer(NULL, BIOS_ENABLED, NULL, &enable);
if (ACPI_FAILURE(status) || !enable)
return -ENODEV;
result = acpi_bus_register_driver(&intel_menlow_memory_driver);
if (result)
return result;
status = acpi_walk_namespace(ACPI_TYPE_THERMAL, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX,
intel_menlow_register_sensor, NULL, NULL, NULL);
if (ACPI_FAILURE(status)) {
acpi_bus_unregister_driver(&intel_menlow_memory_driver);
return -ENODEV;
}
return 0;
}
static void __exit intel_menlow_module_exit(void)
{
acpi_bus_unregister_driver(&intel_menlow_memory_driver);
intel_menlow_unregister_sensor();
}
