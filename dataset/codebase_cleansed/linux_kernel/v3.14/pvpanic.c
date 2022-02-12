static void
pvpanic_send_event(unsigned int event)
{
outb(event, port);
}
static int
pvpanic_panic_notify(struct notifier_block *nb, unsigned long code,
void *unused)
{
pvpanic_send_event(PVPANIC_PANICKED);
return NOTIFY_DONE;
}
static acpi_status
pvpanic_walk_resources(struct acpi_resource *res, void *context)
{
switch (res->type) {
case ACPI_RESOURCE_TYPE_END_TAG:
return AE_OK;
case ACPI_RESOURCE_TYPE_IO:
port = res->data.io.minimum;
return AE_OK;
default:
return AE_ERROR;
}
}
static int pvpanic_add(struct acpi_device *device)
{
acpi_status status;
u64 ret;
status = acpi_evaluate_integer(device->handle, "_STA", NULL,
&ret);
if (ACPI_FAILURE(status) || (ret & 0x0B) != 0x0B)
return -ENODEV;
acpi_walk_resources(device->handle, METHOD_NAME__CRS,
pvpanic_walk_resources, NULL);
if (!port)
return -ENODEV;
atomic_notifier_chain_register(&panic_notifier_list,
&pvpanic_panic_nb);
return 0;
}
static int pvpanic_remove(struct acpi_device *device)
{
atomic_notifier_chain_unregister(&panic_notifier_list,
&pvpanic_panic_nb);
return 0;
}
