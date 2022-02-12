static int
nvkm_acpi_ntfy(struct notifier_block *nb, unsigned long val, void *data)
{
struct nvkm_device *device =
container_of(nb, typeof(*device), acpi.nb);
struct acpi_bus_event *info = data;
if (!strcmp(info->device_class, "ac_adapter"))
nvkm_event_send(&device->event, 1, 0, NULL, 0);
return NOTIFY_DONE;
}
void
nvkm_acpi_fini(struct nvkm_device *device)
{
#ifdef CONFIG_ACPI
unregister_acpi_notifier(&device->acpi.nb);
#endif
}
void
nvkm_acpi_init(struct nvkm_device *device)
{
#ifdef CONFIG_ACPI
device->acpi.nb.notifier_call = nvkm_acpi_ntfy;
register_acpi_notifier(&device->acpi.nb);
#endif
}
