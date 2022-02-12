int register_acpi_hed_notifier(struct notifier_block *nb)
{
return blocking_notifier_chain_register(&acpi_hed_notify_list, nb);
}
void unregister_acpi_hed_notifier(struct notifier_block *nb)
{
blocking_notifier_chain_unregister(&acpi_hed_notify_list, nb);
}
static void acpi_hed_notify(struct acpi_device *device, u32 event)
{
blocking_notifier_call_chain(&acpi_hed_notify_list, 0, NULL);
}
static int __devinit acpi_hed_add(struct acpi_device *device)
{
if (hed_handle)
return -EINVAL;
hed_handle = device->handle;
return 0;
}
static int __devexit acpi_hed_remove(struct acpi_device *device, int type)
{
hed_handle = NULL;
return 0;
}
