static int
check_slot(acpi_handle handle, unsigned long long *sun)
{
int device = -1;
unsigned long long adr, sta;
acpi_status status;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
acpi_get_name(handle, ACPI_FULL_PATHNAME, &buffer);
dbg("Checking slot on path: %s\n", (char *)buffer.pointer);
if (check_sta_before_sun) {
status = acpi_evaluate_integer(handle, "_STA", NULL, &sta);
if (ACPI_SUCCESS(status) && !(sta & ACPI_STA_DEVICE_PRESENT))
goto out;
}
status = acpi_evaluate_integer(handle, "_ADR", NULL, &adr);
if (ACPI_FAILURE(status)) {
dbg("_ADR returned %d on %s\n", status, (char *)buffer.pointer);
goto out;
}
status = acpi_evaluate_integer(handle, "_SUN", NULL, sun);
if (ACPI_FAILURE(status)) {
dbg("_SUN returned %d on %s\n", status, (char *)buffer.pointer);
goto out;
}
device = (adr >> 16) & 0xffff;
out:
kfree(buffer.pointer);
return device;
}
static acpi_status
register_slot(acpi_handle handle, u32 lvl, void *context, void **rv)
{
int device;
unsigned long long sun;
char name[SLOT_NAME_SIZE];
struct acpi_pci_slot *slot;
struct pci_slot *pci_slot;
struct pci_bus *pci_bus = context;
device = check_slot(handle, &sun);
if (device < 0)
return AE_OK;
list_for_each_entry(slot, &slot_list, list) {
pci_slot = slot->pci_slot;
if (pci_slot->bus == pci_bus && pci_slot->number == device)
return AE_OK;
}
slot = kmalloc(sizeof(*slot), GFP_KERNEL);
if (!slot) {
err("%s: cannot allocate memory\n", __func__);
return AE_OK;
}
snprintf(name, sizeof(name), "%llu", sun);
pci_slot = pci_create_slot(pci_bus, device, name, NULL);
if (IS_ERR(pci_slot)) {
err("pci_create_slot returned %ld\n", PTR_ERR(pci_slot));
kfree(slot);
return AE_OK;
}
slot->pci_slot = pci_slot;
list_add(&slot->list, &slot_list);
get_device(&pci_bus->dev);
dbg("pci_slot: %p, pci_bus: %x, device: %d, name: %s\n",
pci_slot, pci_bus->number, device, name);
return AE_OK;
}
void acpi_pci_slot_enumerate(struct pci_bus *bus)
{
acpi_handle handle = ACPI_HANDLE(bus->bridge);
if (handle) {
mutex_lock(&slot_list_lock);
acpi_walk_namespace(ACPI_TYPE_DEVICE, handle, 1,
register_slot, NULL, bus, NULL);
mutex_unlock(&slot_list_lock);
}
}
void acpi_pci_slot_remove(struct pci_bus *bus)
{
struct acpi_pci_slot *slot, *tmp;
mutex_lock(&slot_list_lock);
list_for_each_entry_safe(slot, tmp, &slot_list, list) {
if (slot->pci_slot->bus == bus) {
list_del(&slot->list);
pci_destroy_slot(slot->pci_slot);
put_device(&bus->dev);
kfree(slot);
}
}
mutex_unlock(&slot_list_lock);
}
static int do_sta_before_sun(const struct dmi_system_id *d)
{
info("%s detected: will evaluate _STA before calling _SUN\n", d->ident);
check_sta_before_sun = 1;
return 0;
}
void __init acpi_pci_slot_init(void)
{
dmi_check_system(acpi_pci_slot_dmi_table);
}
