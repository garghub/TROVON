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
struct callback_args *parent_context = context;
struct pci_bus *pci_bus = parent_context->pci_bus;
device = check_slot(handle, &sun);
if (device < 0)
return AE_OK;
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
slot->root_handle = parent_context->root_handle;
slot->pci_slot = pci_slot;
INIT_LIST_HEAD(&slot->list);
mutex_lock(&slot_list_lock);
list_add(&slot->list, &slot_list);
mutex_unlock(&slot_list_lock);
get_device(&pci_bus->dev);
dbg("pci_slot: %p, pci_bus: %x, device: %d, name: %s\n",
pci_slot, pci_bus->number, device, name);
return AE_OK;
}
static acpi_status
walk_p2p_bridge(acpi_handle handle, u32 lvl, void *context, void **rv)
{
int device, function;
unsigned long long adr;
acpi_status status;
acpi_handle dummy_handle;
acpi_walk_callback user_function;
struct pci_dev *dev;
struct pci_bus *pci_bus;
struct callback_args child_context;
struct callback_args *parent_context = context;
pci_bus = parent_context->pci_bus;
user_function = parent_context->user_function;
status = acpi_get_handle(handle, "_ADR", &dummy_handle);
if (ACPI_FAILURE(status))
return AE_OK;
status = acpi_evaluate_integer(handle, "_ADR", NULL, &adr);
if (ACPI_FAILURE(status))
return AE_OK;
device = (adr >> 16) & 0xffff;
function = adr & 0xffff;
dev = pci_get_slot(pci_bus, PCI_DEVFN(device, function));
if (!dev || !dev->subordinate)
goto out;
child_context.pci_bus = dev->subordinate;
child_context.user_function = user_function;
child_context.root_handle = parent_context->root_handle;
dbg("p2p bridge walk, pci_bus = %x\n", dev->subordinate->number);
status = acpi_walk_namespace(ACPI_TYPE_DEVICE, handle, (u32)1,
user_function, NULL, &child_context, NULL);
if (ACPI_FAILURE(status))
goto out;
status = acpi_walk_namespace(ACPI_TYPE_DEVICE, handle, (u32)1,
walk_p2p_bridge, NULL, &child_context, NULL);
out:
pci_dev_put(dev);
return AE_OK;
}
static int
walk_root_bridge(struct acpi_pci_root *root, acpi_walk_callback user_function)
{
acpi_status status;
acpi_handle handle = root->device->handle;
struct pci_bus *pci_bus = root->bus;
struct callback_args context;
context.pci_bus = pci_bus;
context.user_function = user_function;
context.root_handle = handle;
dbg("root bridge walk, pci_bus = %x\n", pci_bus->number);
status = acpi_walk_namespace(ACPI_TYPE_DEVICE, handle, (u32)1,
user_function, NULL, &context, NULL);
if (ACPI_FAILURE(status))
return status;
status = acpi_walk_namespace(ACPI_TYPE_DEVICE, handle, (u32)1,
walk_p2p_bridge, NULL, &context, NULL);
if (ACPI_FAILURE(status))
err("%s: walk_p2p_bridge failure - %d\n", __func__, status);
return status;
}
static int
acpi_pci_slot_add(struct acpi_pci_root *root)
{
acpi_status status;
status = walk_root_bridge(root, register_slot);
if (ACPI_FAILURE(status))
err("%s: register_slot failure - %d\n", __func__, status);
return status;
}
static void
acpi_pci_slot_remove(struct acpi_pci_root *root)
{
struct acpi_pci_slot *slot, *tmp;
struct pci_bus *pbus;
acpi_handle handle = root->device->handle;
mutex_lock(&slot_list_lock);
list_for_each_entry_safe(slot, tmp, &slot_list, list) {
if (slot->root_handle == handle) {
list_del(&slot->list);
pbus = slot->pci_slot->bus;
pci_destroy_slot(slot->pci_slot);
put_device(&pbus->dev);
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
acpi_pci_register_driver(&acpi_pci_slot_driver);
}
