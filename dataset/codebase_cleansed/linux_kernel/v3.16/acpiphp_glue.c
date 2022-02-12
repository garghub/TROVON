static struct acpiphp_context *acpiphp_init_context(struct acpi_device *adev)
{
struct acpiphp_context *context;
context = kzalloc(sizeof(*context), GFP_KERNEL);
if (!context)
return NULL;
context->refcount = 1;
acpi_set_hp_context(adev, &context->hp, acpiphp_hotplug_notify, NULL,
acpiphp_post_dock_fixup);
return context;
}
static struct acpiphp_context *acpiphp_get_context(struct acpi_device *adev)
{
struct acpiphp_context *context;
if (!adev->hp)
return NULL;
context = to_acpiphp_context(adev->hp);
context->refcount++;
return context;
}
static void acpiphp_put_context(struct acpiphp_context *context)
{
if (--context->refcount)
return;
WARN_ON(context->bridge);
context->hp.self->hp = NULL;
kfree(context);
}
static inline void get_bridge(struct acpiphp_bridge *bridge)
{
kref_get(&bridge->ref);
}
static inline void put_bridge(struct acpiphp_bridge *bridge)
{
kref_put(&bridge->ref, free_bridge);
}
static struct acpiphp_context *acpiphp_grab_context(struct acpi_device *adev)
{
struct acpiphp_context *context;
acpi_lock_hp_context();
context = acpiphp_get_context(adev);
if (!context || context->func.parent->is_going_away) {
acpi_unlock_hp_context();
return NULL;
}
get_bridge(context->func.parent);
acpiphp_put_context(context);
acpi_unlock_hp_context();
return context;
}
static void acpiphp_let_context_go(struct acpiphp_context *context)
{
put_bridge(context->func.parent);
}
static void free_bridge(struct kref *kref)
{
struct acpiphp_context *context;
struct acpiphp_bridge *bridge;
struct acpiphp_slot *slot, *next;
struct acpiphp_func *func, *tmp;
acpi_lock_hp_context();
bridge = container_of(kref, struct acpiphp_bridge, ref);
list_for_each_entry_safe(slot, next, &bridge->slots, node) {
list_for_each_entry_safe(func, tmp, &slot->funcs, sibling)
acpiphp_put_context(func_to_context(func));
kfree(slot);
}
context = bridge->context;
if (context) {
put_bridge(context->func.parent);
context->bridge = NULL;
acpiphp_put_context(context);
}
put_device(&bridge->pci_bus->dev);
pci_dev_put(bridge->pci_dev);
kfree(bridge);
acpi_unlock_hp_context();
}
static void acpiphp_post_dock_fixup(struct acpi_device *adev)
{
struct acpiphp_context *context = acpiphp_grab_context(adev);
struct pci_bus *bus;
u32 buses;
if (!context)
return;
bus = context->func.slot->bus;
if (!bus->self)
goto out;
pci_read_config_dword(bus->self, PCI_PRIMARY_BUS, &buses);
if (((buses >> 8) & 0xff) != bus->busn_res.start) {
buses = (buses & 0xff000000)
| ((unsigned int)(bus->primary) << 0)
| ((unsigned int)(bus->busn_res.start) << 8)
| ((unsigned int)(bus->busn_res.end) << 16);
pci_write_config_dword(bus->self, PCI_PRIMARY_BUS, buses);
}
out:
acpiphp_let_context_go(context);
}
static bool device_is_managed_by_native_pciehp(struct pci_dev *pdev)
{
u32 reg32;
acpi_handle tmp;
struct acpi_pci_root *root;
if (pcie_capability_read_dword(pdev, PCI_EXP_SLTCAP, &reg32))
return false;
if (!(reg32 & PCI_EXP_SLTCAP_HPC))
return false;
tmp = acpi_find_root_bridge_handle(pdev);
if (!tmp)
return false;
root = acpi_pci_find_root(tmp);
if (!root)
return false;
if (!(root->osc_control_set & OSC_PCI_EXPRESS_NATIVE_HP_CONTROL))
return false;
return true;
}
static acpi_status acpiphp_add_context(acpi_handle handle, u32 lvl, void *data,
void **rv)
{
struct acpiphp_bridge *bridge = data;
struct acpiphp_context *context;
struct acpi_device *adev;
struct acpiphp_slot *slot;
struct acpiphp_func *newfunc;
acpi_status status = AE_OK;
unsigned long long adr;
int device, function;
struct pci_bus *pbus = bridge->pci_bus;
struct pci_dev *pdev = bridge->pci_dev;
u32 val;
status = acpi_evaluate_integer(handle, "_ADR", NULL, &adr);
if (ACPI_FAILURE(status)) {
if (status != AE_NOT_FOUND)
acpi_handle_warn(handle,
"can't evaluate _ADR (%#x)\n", status);
return AE_OK;
}
if (acpi_bus_get_device(handle, &adev))
return AE_OK;
device = (adr >> 16) & 0xffff;
function = adr & 0xffff;
acpi_lock_hp_context();
context = acpiphp_init_context(adev);
if (!context) {
acpi_unlock_hp_context();
acpi_handle_err(handle, "No hotplug context\n");
return AE_NOT_EXIST;
}
newfunc = &context->func;
newfunc->function = function;
newfunc->parent = bridge;
acpi_unlock_hp_context();
if (!is_dock_device(adev) && acpi_has_method(handle, "_EJ0"))
newfunc->flags = FUNC_HAS_EJ0;
if (acpi_has_method(handle, "_STA"))
newfunc->flags |= FUNC_HAS_STA;
list_for_each_entry(slot, &bridge->slots, node)
if (slot->device == device)
goto slot_found;
slot = kzalloc(sizeof(struct acpiphp_slot), GFP_KERNEL);
if (!slot) {
acpi_lock_hp_context();
acpiphp_put_context(context);
acpi_unlock_hp_context();
return AE_NO_MEMORY;
}
slot->bus = bridge->pci_bus;
slot->device = device;
INIT_LIST_HEAD(&slot->funcs);
list_add_tail(&slot->node, &bridge->slots);
if ((acpi_pci_check_ejectable(pbus, handle) || is_dock_device(adev))
&& !(pdev && device_is_managed_by_native_pciehp(pdev))) {
unsigned long long sun;
int retval;
bridge->nr_slots++;
status = acpi_evaluate_integer(handle, "_SUN", NULL, &sun);
if (ACPI_FAILURE(status))
sun = bridge->nr_slots;
pr_debug("found ACPI PCI Hotplug slot %llu at PCI %04x:%02x:%02x\n",
sun, pci_domain_nr(pbus), pbus->number, device);
retval = acpiphp_register_hotplug_slot(slot, sun);
if (retval) {
slot->slot = NULL;
bridge->nr_slots--;
if (retval == -EBUSY)
pr_warn("Slot %llu already registered by another hotplug driver\n", sun);
else
pr_warn("acpiphp_register_hotplug_slot failed (err code = 0x%x)\n", retval);
}
}
slot_found:
newfunc->slot = slot;
list_add_tail(&newfunc->sibling, &slot->funcs);
if (pci_bus_read_dev_vendor_id(pbus, PCI_DEVFN(device, function),
&val, 60*1000))
slot->flags |= SLOT_ENABLED;
return AE_OK;
}
static struct acpiphp_bridge *acpiphp_dev_to_bridge(struct acpi_device *adev)
{
struct acpiphp_bridge *bridge = NULL;
acpi_lock_hp_context();
if (adev->hp) {
bridge = to_acpiphp_root_context(adev->hp)->root_bridge;
if (bridge)
get_bridge(bridge);
}
acpi_unlock_hp_context();
return bridge;
}
static void cleanup_bridge(struct acpiphp_bridge *bridge)
{
struct acpiphp_slot *slot;
struct acpiphp_func *func;
list_for_each_entry(slot, &bridge->slots, node) {
list_for_each_entry(func, &slot->funcs, sibling) {
struct acpi_device *adev = func_to_acpi_device(func);
acpi_lock_hp_context();
adev->hp->notify = NULL;
adev->hp->fixup = NULL;
acpi_unlock_hp_context();
}
slot->flags |= SLOT_IS_GOING_AWAY;
if (slot->slot)
acpiphp_unregister_hotplug_slot(slot);
}
mutex_lock(&bridge_mutex);
list_del(&bridge->list);
mutex_unlock(&bridge_mutex);
acpi_lock_hp_context();
bridge->is_going_away = true;
acpi_unlock_hp_context();
}
static unsigned char acpiphp_max_busnr(struct pci_bus *bus)
{
struct pci_bus *tmp;
unsigned char max, n;
max = bus->busn_res.start;
list_for_each_entry(tmp, &bus->children, node) {
n = pci_bus_max_busnr(tmp);
if (n > max)
max = n;
}
return max;
}
static void acpiphp_set_acpi_region(struct acpiphp_slot *slot)
{
struct acpiphp_func *func;
union acpi_object params[2];
struct acpi_object_list arg_list;
list_for_each_entry(func, &slot->funcs, sibling) {
arg_list.count = 2;
arg_list.pointer = params;
params[0].type = ACPI_TYPE_INTEGER;
params[0].integer.value = ACPI_ADR_SPACE_PCI_CONFIG;
params[1].type = ACPI_TYPE_INTEGER;
params[1].integer.value = 1;
acpi_evaluate_object(func_to_handle(func), "_REG", &arg_list,
NULL);
}
}
static void check_hotplug_bridge(struct acpiphp_slot *slot, struct pci_dev *dev)
{
struct acpiphp_func *func;
if (dev->is_hotplug_bridge)
return;
list_for_each_entry(func, &slot->funcs, sibling) {
if (PCI_FUNC(dev->devfn) == func->function) {
dev->is_hotplug_bridge = 1;
break;
}
}
}
static int acpiphp_rescan_slot(struct acpiphp_slot *slot)
{
struct acpiphp_func *func;
list_for_each_entry(func, &slot->funcs, sibling) {
struct acpi_device *adev = func_to_acpi_device(func);
acpi_bus_scan(adev->handle);
if (acpi_device_enumerated(adev))
acpi_device_set_power(adev, ACPI_STATE_D0);
}
return pci_scan_slot(slot->bus, PCI_DEVFN(slot->device, 0));
}
static void enable_slot(struct acpiphp_slot *slot)
{
struct pci_dev *dev;
struct pci_bus *bus = slot->bus;
struct acpiphp_func *func;
int max, pass;
LIST_HEAD(add_list);
acpiphp_rescan_slot(slot);
max = acpiphp_max_busnr(bus);
for (pass = 0; pass < 2; pass++) {
list_for_each_entry(dev, &bus->devices, bus_list) {
if (PCI_SLOT(dev->devfn) != slot->device)
continue;
if (pci_is_bridge(dev)) {
max = pci_scan_bridge(bus, dev, max, pass);
if (pass && dev->subordinate) {
check_hotplug_bridge(slot, dev);
pcibios_resource_survey_bus(dev->subordinate);
__pci_bus_size_bridges(dev->subordinate,
&add_list);
}
}
}
}
__pci_bus_assign_resources(bus, &add_list, NULL);
acpiphp_sanitize_bus(bus);
acpiphp_set_hpp_values(bus);
acpiphp_set_acpi_region(slot);
list_for_each_entry(dev, &bus->devices, bus_list) {
if (!dev->is_added)
dev->current_state = PCI_D0;
}
pci_bus_add_devices(bus);
slot->flags |= SLOT_ENABLED;
list_for_each_entry(func, &slot->funcs, sibling) {
dev = pci_get_slot(bus, PCI_DEVFN(slot->device,
func->function));
if (!dev) {
slot->flags &= (~SLOT_ENABLED);
continue;
}
}
}
static void disable_slot(struct acpiphp_slot *slot)
{
struct pci_bus *bus = slot->bus;
struct pci_dev *dev, *prev;
struct acpiphp_func *func;
list_for_each_entry_safe_reverse(dev, prev, &bus->devices, bus_list)
if (PCI_SLOT(dev->devfn) == slot->device)
pci_stop_and_remove_bus_device(dev);
list_for_each_entry(func, &slot->funcs, sibling)
acpi_bus_trim(func_to_acpi_device(func));
slot->flags &= (~SLOT_ENABLED);
}
static bool acpiphp_no_hotplug(struct acpi_device *adev)
{
return adev && adev->flags.no_hotplug;
}
static bool slot_no_hotplug(struct acpiphp_slot *slot)
{
struct acpiphp_func *func;
list_for_each_entry(func, &slot->funcs, sibling)
if (acpiphp_no_hotplug(func_to_acpi_device(func)))
return true;
return false;
}
static unsigned int get_slot_status(struct acpiphp_slot *slot)
{
unsigned long long sta = 0;
struct acpiphp_func *func;
list_for_each_entry(func, &slot->funcs, sibling) {
if (func->flags & FUNC_HAS_STA) {
acpi_status status;
status = acpi_evaluate_integer(func_to_handle(func),
"_STA", NULL, &sta);
if (ACPI_SUCCESS(status) && sta)
break;
} else {
u32 dvid;
pci_bus_read_config_dword(slot->bus,
PCI_DEVFN(slot->device,
func->function),
PCI_VENDOR_ID, &dvid);
if (dvid != 0xffffffff) {
sta = ACPI_STA_ALL;
break;
}
}
}
return (unsigned int)sta;
}
static inline bool device_status_valid(unsigned int sta)
{
unsigned int mask = ACPI_STA_DEVICE_ENABLED | ACPI_STA_DEVICE_FUNCTIONING;
return (sta & mask) == mask;
}
static void trim_stale_devices(struct pci_dev *dev)
{
struct acpi_device *adev = ACPI_COMPANION(&dev->dev);
struct pci_bus *bus = dev->subordinate;
bool alive = false;
if (adev) {
acpi_status status;
unsigned long long sta;
status = acpi_evaluate_integer(adev->handle, "_STA", NULL, &sta);
alive = (ACPI_SUCCESS(status) && device_status_valid(sta))
|| acpiphp_no_hotplug(adev);
}
if (!alive)
alive = pci_device_is_present(dev);
if (!alive) {
pci_stop_and_remove_bus_device(dev);
if (adev)
acpi_bus_trim(adev);
} else if (bus) {
struct pci_dev *child, *tmp;
pm_runtime_get_sync(&dev->dev);
list_for_each_entry_safe_reverse(child, tmp, &bus->devices, bus_list)
trim_stale_devices(child);
pm_runtime_put(&dev->dev);
}
}
static void acpiphp_check_bridge(struct acpiphp_bridge *bridge)
{
struct acpiphp_slot *slot;
if (bridge->is_going_away)
return;
list_for_each_entry(slot, &bridge->slots, node) {
struct pci_bus *bus = slot->bus;
struct pci_dev *dev, *tmp;
if (slot_no_hotplug(slot)) {
;
} else if (device_status_valid(get_slot_status(slot))) {
list_for_each_entry_safe_reverse(dev, tmp,
&bus->devices, bus_list)
if (PCI_SLOT(dev->devfn) == slot->device)
trim_stale_devices(dev);
enable_slot(slot);
} else {
disable_slot(slot);
}
}
}
static void acpiphp_set_hpp_values(struct pci_bus *bus)
{
struct pci_dev *dev;
list_for_each_entry(dev, &bus->devices, bus_list)
pci_configure_slot(dev);
}
static void acpiphp_sanitize_bus(struct pci_bus *bus)
{
struct pci_dev *dev, *tmp;
int i;
unsigned long type_mask = IORESOURCE_IO | IORESOURCE_MEM;
list_for_each_entry_safe_reverse(dev, tmp, &bus->devices, bus_list) {
for (i=0; i<PCI_BRIDGE_RESOURCES; i++) {
struct resource *res = &dev->resource[i];
if ((res->flags & type_mask) && !res->start &&
res->end) {
pci_stop_and_remove_bus_device(dev);
break;
}
}
}
}
void acpiphp_check_host_bridge(struct acpi_device *adev)
{
struct acpiphp_bridge *bridge;
bridge = acpiphp_dev_to_bridge(adev);
if (bridge) {
pci_lock_rescan_remove();
acpiphp_check_bridge(bridge);
pci_unlock_rescan_remove();
put_bridge(bridge);
}
}
static void hotplug_event(u32 type, struct acpiphp_context *context)
{
acpi_handle handle = context->hp.self->handle;
struct acpiphp_func *func = &context->func;
struct acpiphp_slot *slot = func->slot;
struct acpiphp_bridge *bridge;
acpi_lock_hp_context();
bridge = context->bridge;
if (bridge)
get_bridge(bridge);
acpi_unlock_hp_context();
pci_lock_rescan_remove();
switch (type) {
case ACPI_NOTIFY_BUS_CHECK:
acpi_handle_debug(handle, "Bus check in %s()\n", __func__);
if (bridge)
acpiphp_check_bridge(bridge);
else if (!(slot->flags & SLOT_IS_GOING_AWAY))
enable_slot(slot);
break;
case ACPI_NOTIFY_DEVICE_CHECK:
acpi_handle_debug(handle, "Device check in %s()\n", __func__);
if (bridge) {
acpiphp_check_bridge(bridge);
} else if (!(slot->flags & SLOT_IS_GOING_AWAY)) {
if (acpiphp_rescan_slot(slot))
acpiphp_check_bridge(func->parent);
}
break;
case ACPI_NOTIFY_EJECT_REQUEST:
acpi_handle_debug(handle, "Eject request in %s()\n", __func__);
acpiphp_disable_and_eject_slot(slot);
break;
}
pci_unlock_rescan_remove();
if (bridge)
put_bridge(bridge);
}
static int acpiphp_hotplug_notify(struct acpi_device *adev, u32 type)
{
struct acpiphp_context *context;
context = acpiphp_grab_context(adev);
if (!context)
return -ENODATA;
hotplug_event(type, context);
acpiphp_let_context_go(context);
return 0;
}
void acpiphp_enumerate_slots(struct pci_bus *bus)
{
struct acpiphp_bridge *bridge;
struct acpi_device *adev;
acpi_handle handle;
acpi_status status;
if (acpiphp_disabled)
return;
adev = ACPI_COMPANION(bus->bridge);
if (!adev)
return;
handle = adev->handle;
bridge = kzalloc(sizeof(struct acpiphp_bridge), GFP_KERNEL);
if (!bridge) {
acpi_handle_err(handle, "No memory for bridge object\n");
return;
}
INIT_LIST_HEAD(&bridge->slots);
kref_init(&bridge->ref);
bridge->pci_dev = pci_dev_get(bus->self);
bridge->pci_bus = bus;
get_device(&bus->dev);
acpi_lock_hp_context();
if (pci_is_root_bus(bridge->pci_bus)) {
struct acpiphp_root_context *root_context;
root_context = kzalloc(sizeof(*root_context), GFP_KERNEL);
if (!root_context)
goto err;
root_context->root_bridge = bridge;
acpi_set_hp_context(adev, &root_context->hp, NULL, NULL, NULL);
} else {
struct acpiphp_context *context;
context = acpiphp_get_context(adev);
if (!context)
goto err;
bridge->context = context;
context->bridge = bridge;
get_bridge(context->func.parent);
}
acpi_unlock_hp_context();
mutex_lock(&bridge_mutex);
list_add(&bridge->list, &bridge_list);
mutex_unlock(&bridge_mutex);
status = acpi_walk_namespace(ACPI_TYPE_DEVICE, handle, 1,
acpiphp_add_context, NULL, bridge, NULL);
if (ACPI_FAILURE(status)) {
acpi_handle_err(handle, "failed to register slots\n");
cleanup_bridge(bridge);
put_bridge(bridge);
}
return;
err:
acpi_unlock_hp_context();
put_device(&bus->dev);
pci_dev_put(bridge->pci_dev);
kfree(bridge);
}
void acpiphp_drop_bridge(struct acpiphp_bridge *bridge)
{
if (pci_is_root_bus(bridge->pci_bus)) {
struct acpiphp_root_context *root_context;
struct acpi_device *adev;
acpi_lock_hp_context();
adev = ACPI_COMPANION(bridge->pci_bus->bridge);
root_context = to_acpiphp_root_context(adev->hp);
adev->hp = NULL;
acpi_unlock_hp_context();
kfree(root_context);
}
cleanup_bridge(bridge);
put_bridge(bridge);
}
void acpiphp_remove_slots(struct pci_bus *bus)
{
struct acpiphp_bridge *bridge;
if (acpiphp_disabled)
return;
mutex_lock(&bridge_mutex);
list_for_each_entry(bridge, &bridge_list, list)
if (bridge->pci_bus == bus) {
mutex_unlock(&bridge_mutex);
acpiphp_drop_bridge(bridge);
return;
}
mutex_unlock(&bridge_mutex);
}
int acpiphp_enable_slot(struct acpiphp_slot *slot)
{
pci_lock_rescan_remove();
if (slot->flags & SLOT_IS_GOING_AWAY)
return -ENODEV;
if (!(slot->flags & SLOT_ENABLED))
enable_slot(slot);
pci_unlock_rescan_remove();
return 0;
}
static int acpiphp_disable_and_eject_slot(struct acpiphp_slot *slot)
{
struct acpiphp_func *func;
if (slot->flags & SLOT_IS_GOING_AWAY)
return -ENODEV;
disable_slot(slot);
list_for_each_entry(func, &slot->funcs, sibling)
if (func->flags & FUNC_HAS_EJ0) {
acpi_handle handle = func_to_handle(func);
if (ACPI_FAILURE(acpi_evaluate_ej0(handle)))
acpi_handle_err(handle, "_EJ0 failed\n");
break;
}
return 0;
}
int acpiphp_disable_slot(struct acpiphp_slot *slot)
{
int ret;
acpi_scan_lock_acquire();
pci_lock_rescan_remove();
ret = acpiphp_disable_and_eject_slot(slot);
pci_unlock_rescan_remove();
acpi_scan_lock_release();
return ret;
}
u8 acpiphp_get_power_status(struct acpiphp_slot *slot)
{
return (slot->flags & SLOT_ENABLED);
}
u8 acpiphp_get_latch_status(struct acpiphp_slot *slot)
{
return !(get_slot_status(slot) & ACPI_STA_DEVICE_UI);
}
u8 acpiphp_get_adapter_status(struct acpiphp_slot *slot)
{
return !!get_slot_status(slot);
}
