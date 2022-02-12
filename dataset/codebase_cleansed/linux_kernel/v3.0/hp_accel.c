static inline void delayed_set_status_worker(struct work_struct *work)
{
struct delayed_led_classdev *data =
container_of(work, struct delayed_led_classdev, work);
data->set_brightness(data, data->new_brightness);
}
static inline void delayed_sysfs_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct delayed_led_classdev *data = container_of(led_cdev,
struct delayed_led_classdev, led_classdev);
data->new_brightness = brightness;
schedule_work(&data->work);
}
int lis3lv02d_acpi_init(struct lis3lv02d *lis3)
{
struct acpi_device *dev = lis3->bus_priv;
if (acpi_evaluate_object(dev->handle, METHOD_NAME__INI,
NULL, NULL) != AE_OK)
return -EINVAL;
return 0;
}
int lis3lv02d_acpi_read(struct lis3lv02d *lis3, int reg, u8 *ret)
{
struct acpi_device *dev = lis3->bus_priv;
union acpi_object arg0 = { ACPI_TYPE_INTEGER };
struct acpi_object_list args = { 1, &arg0 };
unsigned long long lret;
acpi_status status;
arg0.integer.value = reg;
status = acpi_evaluate_integer(dev->handle, "ALRD", &args, &lret);
*ret = lret;
return (status != AE_OK) ? -EINVAL : 0;
}
int lis3lv02d_acpi_write(struct lis3lv02d *lis3, int reg, u8 val)
{
struct acpi_device *dev = lis3->bus_priv;
unsigned long long ret;
union acpi_object in_obj[2];
struct acpi_object_list args = { 2, in_obj };
in_obj[0].type = ACPI_TYPE_INTEGER;
in_obj[0].integer.value = reg;
in_obj[1].type = ACPI_TYPE_INTEGER;
in_obj[1].integer.value = val;
if (acpi_evaluate_integer(dev->handle, "ALWR", &args, &ret) != AE_OK)
return -EINVAL;
return 0;
}
static int lis3lv02d_dmi_matched(const struct dmi_system_id *dmi)
{
lis3_dev.ac = *((union axis_conversion *)dmi->driver_data);
pr_info("hardware type %s found\n", dmi->ident);
return 1;
}
static void hpled_set(struct delayed_led_classdev *led_cdev, enum led_brightness value)
{
struct acpi_device *dev = lis3_dev.bus_priv;
unsigned long long ret;
union acpi_object in_obj[1];
struct acpi_object_list args = { 1, in_obj };
in_obj[0].type = ACPI_TYPE_INTEGER;
in_obj[0].integer.value = !!value;
acpi_evaluate_integer(dev->handle, "ALED", &args, &ret);
}
static acpi_status
lis3lv02d_get_resource(struct acpi_resource *resource, void *context)
{
if (resource->type == ACPI_RESOURCE_TYPE_EXTENDED_IRQ) {
struct acpi_resource_extended_irq *irq;
u32 *device_irq = context;
irq = &resource->data.extended_irq;
*device_irq = irq->interrupts[0];
}
return AE_OK;
}
static void lis3lv02d_enum_resources(struct acpi_device *device)
{
acpi_status status;
status = acpi_walk_resources(device->handle, METHOD_NAME__CRS,
lis3lv02d_get_resource, &lis3_dev.irq);
if (ACPI_FAILURE(status))
printk(KERN_DEBUG DRIVER_NAME ": Error getting resources\n");
}
static int lis3lv02d_add(struct acpi_device *device)
{
int ret;
if (!device)
return -EINVAL;
lis3_dev.bus_priv = device;
lis3_dev.init = lis3lv02d_acpi_init;
lis3_dev.read = lis3lv02d_acpi_read;
lis3_dev.write = lis3lv02d_acpi_write;
strcpy(acpi_device_name(device), DRIVER_NAME);
strcpy(acpi_device_class(device), ACPI_MDPS_CLASS);
device->driver_data = &lis3_dev;
lis3lv02d_enum_resources(device);
if (lis3_dev.ac.x && lis3_dev.ac.y && lis3_dev.ac.z) {
pr_info("Using custom axes %d,%d,%d\n",
lis3_dev.ac.x, lis3_dev.ac.y, lis3_dev.ac.z);
} else if (dmi_check_system(lis3lv02d_dmi_ids) == 0) {
pr_info("laptop model unknown, using default axes configuration\n");
lis3_dev.ac = lis3lv02d_axis_normal;
}
ret = lis3lv02d_init_device(&lis3_dev);
if (ret)
return ret;
INIT_WORK(&hpled_led.work, delayed_set_status_worker);
ret = led_classdev_register(NULL, &hpled_led.led_classdev);
if (ret) {
lis3lv02d_joystick_disable();
lis3lv02d_poweroff(&lis3_dev);
flush_work(&hpled_led.work);
return ret;
}
return ret;
}
static int lis3lv02d_remove(struct acpi_device *device, int type)
{
if (!device)
return -EINVAL;
lis3lv02d_joystick_disable();
lis3lv02d_poweroff(&lis3_dev);
led_classdev_unregister(&hpled_led.led_classdev);
flush_work(&hpled_led.work);
return lis3lv02d_remove_fs(&lis3_dev);
}
static int lis3lv02d_suspend(struct acpi_device *device, pm_message_t state)
{
lis3lv02d_poweroff(&lis3_dev);
return 0;
}
static int lis3lv02d_resume(struct acpi_device *device)
{
lis3lv02d_poweron(&lis3_dev);
return 0;
}
static int __init lis3lv02d_init_module(void)
{
int ret;
if (acpi_disabled)
return -ENODEV;
ret = acpi_bus_register_driver(&lis3lv02d_driver);
if (ret < 0)
return ret;
pr_info("driver loaded\n");
return 0;
}
static void __exit lis3lv02d_exit_module(void)
{
acpi_bus_unregister_driver(&lis3lv02d_driver);
}
