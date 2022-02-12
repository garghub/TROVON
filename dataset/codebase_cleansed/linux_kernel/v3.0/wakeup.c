void acpi_enable_wakeup_devices(u8 sleep_state)
{
struct list_head *node, *next;
list_for_each_safe(node, next, &acpi_wakeup_device_list) {
struct acpi_device *dev =
container_of(node, struct acpi_device, wakeup_list);
if (!dev->wakeup.flags.valid
|| sleep_state > (u32) dev->wakeup.sleep_state
|| !(device_may_wakeup(&dev->dev)
|| dev->wakeup.prepare_count))
continue;
if (device_may_wakeup(&dev->dev))
acpi_enable_wakeup_device_power(dev, sleep_state);
acpi_set_gpe_wake_mask(dev->wakeup.gpe_device, dev->wakeup.gpe_number,
ACPI_GPE_ENABLE);
}
}
void acpi_disable_wakeup_devices(u8 sleep_state)
{
struct list_head *node, *next;
list_for_each_safe(node, next, &acpi_wakeup_device_list) {
struct acpi_device *dev =
container_of(node, struct acpi_device, wakeup_list);
if (!dev->wakeup.flags.valid
|| sleep_state > (u32) dev->wakeup.sleep_state
|| !(device_may_wakeup(&dev->dev)
|| dev->wakeup.prepare_count))
continue;
acpi_set_gpe_wake_mask(dev->wakeup.gpe_device, dev->wakeup.gpe_number,
ACPI_GPE_DISABLE);
if (device_may_wakeup(&dev->dev))
acpi_disable_wakeup_device_power(dev);
}
}
int __init acpi_wakeup_device_init(void)
{
struct list_head *node, *next;
mutex_lock(&acpi_device_lock);
list_for_each_safe(node, next, &acpi_wakeup_device_list) {
struct acpi_device *dev = container_of(node,
struct acpi_device,
wakeup_list);
if (device_can_wakeup(&dev->dev)) {
acpi_enable_gpe(dev->wakeup.gpe_device,
dev->wakeup.gpe_number);
device_set_wakeup_enable(&dev->dev, true);
}
}
mutex_unlock(&acpi_device_lock);
return 0;
}
