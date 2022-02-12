static int fan_get_max_state(struct thermal_cooling_device *cdev, unsigned long
*state)
{
*state = 1;
return 0;
}
static int fan_get_cur_state(struct thermal_cooling_device *cdev, unsigned long
*state)
{
struct acpi_device *device = cdev->devdata;
int result;
int acpi_state;
if (!device)
return -EINVAL;
result = acpi_bus_update_power(device->handle, &acpi_state);
if (result)
return result;
*state = (acpi_state == ACPI_STATE_D3 ? 0 :
(acpi_state == ACPI_STATE_D0 ? 1 : -1));
return 0;
}
static int
fan_set_cur_state(struct thermal_cooling_device *cdev, unsigned long state)
{
struct acpi_device *device = cdev->devdata;
int result;
if (!device || (state != 0 && state != 1))
return -EINVAL;
result = acpi_bus_set_power(device->handle,
state ? ACPI_STATE_D0 : ACPI_STATE_D3);
return result;
}
static int acpi_fan_add(struct acpi_device *device)
{
int result = 0;
struct thermal_cooling_device *cdev;
if (!device)
return -EINVAL;
strcpy(acpi_device_name(device), "Fan");
strcpy(acpi_device_class(device), ACPI_FAN_CLASS);
result = acpi_bus_update_power(device->handle, NULL);
if (result) {
printk(KERN_ERR PREFIX "Setting initial power state\n");
goto end;
}
cdev = thermal_cooling_device_register("Fan", device,
&fan_cooling_ops);
if (IS_ERR(cdev)) {
result = PTR_ERR(cdev);
goto end;
}
dev_dbg(&device->dev, "registered as cooling_device%d\n", cdev->id);
device->driver_data = cdev;
result = sysfs_create_link(&device->dev.kobj,
&cdev->device.kobj,
"thermal_cooling");
if (result)
dev_err(&device->dev, "Failed to create sysfs link "
"'thermal_cooling'\n");
result = sysfs_create_link(&cdev->device.kobj,
&device->dev.kobj,
"device");
if (result)
dev_err(&device->dev, "Failed to create sysfs link "
"'device'\n");
printk(KERN_INFO PREFIX "%s [%s] (%s)\n",
acpi_device_name(device), acpi_device_bid(device),
!device->power.state ? "on" : "off");
end:
return result;
}
static int acpi_fan_remove(struct acpi_device *device, int type)
{
struct thermal_cooling_device *cdev = acpi_driver_data(device);
if (!device || !cdev)
return -EINVAL;
sysfs_remove_link(&device->dev.kobj, "thermal_cooling");
sysfs_remove_link(&cdev->device.kobj, "device");
thermal_cooling_device_unregister(cdev);
return 0;
}
static int acpi_fan_suspend(struct acpi_device *device, pm_message_t state)
{
if (!device)
return -EINVAL;
acpi_bus_set_power(device->handle, ACPI_STATE_D0);
return AE_OK;
}
static int acpi_fan_resume(struct acpi_device *device)
{
int result;
if (!device)
return -EINVAL;
result = acpi_bus_update_power(device->handle, NULL);
if (result)
printk(KERN_ERR PREFIX "Error updating fan power state\n");
return result;
}
static int __init acpi_fan_init(void)
{
int result = 0;
result = acpi_bus_register_driver(&acpi_fan_driver);
if (result < 0)
return -ENODEV;
return 0;
}
static void __exit acpi_fan_exit(void)
{
acpi_bus_unregister_driver(&acpi_fan_driver);
return;
}
