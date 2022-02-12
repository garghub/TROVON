static int get_state(u32 *out, u8 instance)
{
u32 tmp;
acpi_status status;
struct acpi_buffer result = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *obj;
if (!out)
return -EINVAL;
if (instance > 2)
return -ENODEV;
status = wmi_query_block(GUID, instance, &result);
if (ACPI_FAILURE(status))
return -ENODEV;
obj = (union acpi_object *) result.pointer;
if (obj && obj->type == ACPI_TYPE_INTEGER) {
tmp = obj->integer.value;
} else {
tmp = 0;
}
if (result.length > 0 && result.pointer)
kfree(result.pointer);
switch (instance) {
case TC1100_INSTANCE_WIRELESS:
*out = (tmp == 3) ? 1 : 0;
return 0;
case TC1100_INSTANCE_JOGDIAL:
*out = (tmp == 1) ? 0 : 1;
return 0;
default:
return -ENODEV;
}
}
static int set_state(u32 *in, u8 instance)
{
u32 value;
acpi_status status;
struct acpi_buffer input;
if (!in)
return -EINVAL;
if (instance > 2)
return -ENODEV;
switch (instance) {
case TC1100_INSTANCE_WIRELESS:
value = (*in) ? 1 : 2;
break;
case TC1100_INSTANCE_JOGDIAL:
value = (*in) ? 0 : 1;
break;
default:
return -ENODEV;
}
input.length = sizeof(u32);
input.pointer = &value;
status = wmi_set_block(GUID, instance, &input);
if (ACPI_FAILURE(status))
return -ENODEV;
return 0;
}
static int __init tc1100_probe(struct platform_device *device)
{
return sysfs_create_group(&device->dev.kobj, &tc1100_attribute_group);
}
static int tc1100_remove(struct platform_device *device)
{
sysfs_remove_group(&device->dev.kobj, &tc1100_attribute_group);
return 0;
}
static int tc1100_suspend(struct device *dev)
{
int ret;
ret = get_state(&suspend_data.wireless, TC1100_INSTANCE_WIRELESS);
if (ret)
return ret;
ret = get_state(&suspend_data.jogdial, TC1100_INSTANCE_JOGDIAL);
if (ret)
return ret;
return 0;
}
static int tc1100_resume(struct device *dev)
{
int ret;
ret = set_state(&suspend_data.wireless, TC1100_INSTANCE_WIRELESS);
if (ret)
return ret;
ret = set_state(&suspend_data.jogdial, TC1100_INSTANCE_JOGDIAL);
if (ret)
return ret;
return 0;
}
static int __init tc1100_init(void)
{
int error;
if (!wmi_has_guid(GUID))
return -ENODEV;
tc1100_device = platform_device_alloc("tc1100-wmi", -1);
if (!tc1100_device)
return -ENOMEM;
error = platform_device_add(tc1100_device);
if (error)
goto err_device_put;
error = platform_driver_probe(&tc1100_driver, tc1100_probe);
if (error)
goto err_device_del;
pr_info("HP Compaq TC1100 Tablet WMI Extras loaded\n");
return 0;
err_device_del:
platform_device_del(tc1100_device);
err_device_put:
platform_device_put(tc1100_device);
return error;
}
static void __exit tc1100_exit(void)
{
platform_device_unregister(tc1100_device);
platform_driver_unregister(&tc1100_driver);
}
