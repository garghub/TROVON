static void acpiphp_context_handler(acpi_handle handle, void *context)
{
}
static struct acpiphp_context *acpiphp_init_context(acpi_handle handle)
{
struct acpiphp_context *context;
acpi_status status;
context = kzalloc(sizeof(*context), GFP_KERNEL);
if (!context)
return NULL;
context->handle = handle;
context->refcount = 1;
status = acpi_attach_data(handle, acpiphp_context_handler, context);
if (ACPI_FAILURE(status)) {
kfree(context);
return NULL;
}
return context;
}
static struct acpiphp_context *acpiphp_get_context(acpi_handle handle)
{
struct acpiphp_context *context = NULL;
acpi_status status;
void *data;
status = acpi_get_data(handle, acpiphp_context_handler, &data);
if (ACPI_SUCCESS(status)) {
context = data;
context->refcount++;
}
return context;
}
static void acpiphp_put_context(struct acpiphp_context *context)
{
if (--context->refcount)
return;
WARN_ON(context->bridge);
acpi_detach_data(context->handle, acpiphp_context_handler);
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
static void free_bridge(struct kref *kref)
{
struct acpiphp_context *context;
struct acpiphp_bridge *bridge;
struct acpiphp_slot *slot, *next;
struct acpiphp_func *func, *tmp;
mutex_lock(&acpiphp_context_lock);
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
mutex_unlock(&acpiphp_context_lock);
}
static void post_dock_fixups(acpi_handle not_used, u32 event, void *data)
{
struct acpiphp_context *context = data;
struct pci_bus *bus = context->func.slot->bus;
u32 buses;
if (!bus->self)
return;
pci_read_config_dword(bus->self,
PCI_PRIMARY_BUS,
&buses);
if (((buses >> 8) & 0xff) != bus->busn_res.start) {
buses = (buses & 0xff000000)
| ((unsigned int)(bus->primary) << 0)
| ((unsigned int)(bus->busn_res.start) << 8)
| ((unsigned int)(bus->busn_res.end) << 16);
pci_write_config_dword(bus->self, PCI_PRIMARY_BUS, buses);
}
}
static void dock_event(acpi_handle handle, u32 type, void *data)
{
struct acpiphp_context *context;
mutex_lock(&acpiphp_context_lock);
context = acpiphp_get_context(handle);
if (!context || WARN_ON(context->handle != handle)
|| context->func.parent->is_going_away) {
mutex_unlock(&acpiphp_context_lock);
return;
}
get_bridge(context->func.parent);
acpiphp_put_context(context);
mutex_unlock(&acpiphp_context_lock);
hotplug_event(handle, type, data);
put_bridge(context->func.parent);
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
static void acpiphp_dock_init(void *data)
{
struct acpiphp_context *context = data;
get_bridge(context->func.parent);
}
static void acpiphp_dock_release(void *data)
{
struct acpiphp_context *context = data;
put_bridge(context->func.parent);
}
static acpi_status register_slot(acpi_handle handle, u32 lvl, void *data,
void **rv)
{
struct acpiphp_bridge *bridge = data;
struct acpiphp_context *context;
struct acpiphp_slot *slot;
struct acpiphp_func *newfunc;
acpi_status status = AE_OK;
unsigned long long adr;
int device, function;
struct pci_bus *pbus = bridge->pci_bus;
struct pci_dev *pdev = bridge->pci_dev;
u32 val;
if (pdev && device_is_managed_by_native_pciehp(pdev))
return AE_OK;
status = acpi_evaluate_integer(handle, "_ADR", NULL, &adr);
if (ACPI_FAILURE(status)) {
if (status != AE_NOT_FOUND)
acpi_handle_warn(handle,
"can't evaluate _ADR (%#x)\n", status);
return AE_OK;
}
device = (adr >> 16) & 0xffff;
function = adr & 0xffff;
mutex_lock(&acpiphp_context_lock);
context = acpiphp_init_context(handle);
if (!context) {
mutex_unlock(&acpiphp_context_lock);
acpi_handle_err(handle, "No hotplug context\n");
return AE_NOT_EXIST;
}
newfunc = &context->func;
newfunc->function = function;
newfunc->parent = bridge;
mutex_unlock(&acpiphp_context_lock);
if (acpi_has_method(handle, "_EJ0"))
newfunc->flags = FUNC_HAS_EJ0;
if (acpi_has_method(handle, "_STA"))
newfunc->flags |= FUNC_HAS_STA;
if (acpi_has_method(handle, "_DCK"))
newfunc->flags |= FUNC_HAS_DCK;
list_for_each_entry(slot, &bridge->slots, node)
if (slot->device == device)
goto slot_found;
slot = kzalloc(sizeof(struct acpiphp_slot), GFP_KERNEL);
if (!slot) {
status = AE_NO_MEMORY;
goto err;
}
slot->bus = bridge->pci_bus;
slot->device = device;
INIT_LIST_HEAD(&slot->funcs);
mutex_init(&slot->crit_sect);
list_add_tail(&slot->node, &bridge->slots);
if (acpi_pci_check_ejectable(pbus, handle) || is_dock_device(handle)) {
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
pr_warn("Slot %llu already registered by another "
"hotplug driver\n", sun);
else
pr_warn("acpiphp_register_hotplug_slot failed "
"(err code = 0x%x)\n", retval);
}
}
slot_found:
newfunc->slot = slot;
list_add_tail(&newfunc->sibling, &slot->funcs);
if (pci_bus_read_dev_vendor_id(pbus, PCI_DEVFN(device, function),
&val, 60*1000))
slot->flags |= SLOT_ENABLED;
if (is_dock_device(handle)) {
newfunc->flags &= ~FUNC_HAS_EJ0;
if (register_hotplug_dock_device(handle,
&acpiphp_dock_ops, context,
acpiphp_dock_init, acpiphp_dock_release))
pr_debug("failed to register dock device\n");
}
if (!(newfunc->flags & FUNC_HAS_DCK)) {
status = acpi_install_notify_handler(handle, ACPI_SYSTEM_NOTIFY,
handle_hotplug_event,
context);
if (ACPI_FAILURE(status))
acpi_handle_err(handle,
"failed to install notify handler\n");
}
return AE_OK;
err:
mutex_lock(&acpiphp_context_lock);
acpiphp_put_context(context);
mutex_unlock(&acpiphp_context_lock);
return status;
}
static struct acpiphp_bridge *acpiphp_handle_to_bridge(acpi_handle handle)
{
struct acpiphp_context *context;
struct acpiphp_bridge *bridge = NULL;
mutex_lock(&acpiphp_context_lock);
context = acpiphp_get_context(handle);
if (context) {
bridge = context->bridge;
if (bridge)
get_bridge(bridge);
acpiphp_put_context(context);
}
mutex_unlock(&acpiphp_context_lock);
return bridge;
}
static void cleanup_bridge(struct acpiphp_bridge *bridge)
{
struct acpiphp_slot *slot;
struct acpiphp_func *func;
acpi_status status;
list_for_each_entry(slot, &bridge->slots, node) {
list_for_each_entry(func, &slot->funcs, sibling) {
acpi_handle handle = func_to_handle(func);
if (is_dock_device(handle))
unregister_hotplug_dock_device(handle);
if (!(func->flags & FUNC_HAS_DCK)) {
status = acpi_remove_notify_handler(handle,
ACPI_SYSTEM_NOTIFY,
handle_hotplug_event);
if (ACPI_FAILURE(status))
pr_err("failed to remove notify handler\n");
}
}
slot->flags |= SLOT_IS_GOING_AWAY;
if (slot->slot)
acpiphp_unregister_hotplug_slot(slot);
}
mutex_lock(&bridge_mutex);
list_del(&bridge->list);
mutex_unlock(&bridge_mutex);
mutex_lock(&acpiphp_context_lock);
bridge->is_going_away = true;
mutex_unlock(&acpiphp_context_lock);
}
static unsigned char acpiphp_max_busnr(struct pci_bus *bus)
{
struct list_head *tmp;
unsigned char max, n;
max = bus->busn_res.start;
list_for_each(tmp, &bus->children) {
n = pci_bus_max_busnr(pci_bus_b(tmp));
if (n > max)
max = n;
}
return max;
}
static void acpiphp_bus_trim(acpi_handle handle)
{
struct acpi_device *adev = NULL;
acpi_bus_get_device(handle, &adev);
if (adev)
acpi_bus_trim(adev);
}
static void acpiphp_bus_add(acpi_handle handle)
{
struct acpi_device *adev = NULL;
acpi_bus_scan(handle);
acpi_bus_get_device(handle, &adev);
if (acpi_device_enumerated(adev))
acpi_device_set_power(adev, ACPI_STATE_D0);
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
list_for_each_entry(func, &slot->funcs, sibling)
acpiphp_bus_add(func_to_handle(func));
return pci_scan_slot(slot->bus, PCI_DEVFN(slot->device, 0));
}
static void __ref enable_slot(struct acpiphp_slot *slot)
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
if (dev->hdr_type == PCI_HEADER_TYPE_BRIDGE ||
dev->hdr_type == PCI_HEADER_TYPE_CARDBUS) {
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
static struct pci_dev *dev_in_slot(struct acpiphp_slot *slot)
{
struct pci_bus *bus = slot->bus;
struct pci_dev *dev;
struct pci_dev *ret = NULL;
down_read(&pci_bus_sem);
list_for_each_entry(dev, &bus->devices, bus_list)
if (PCI_SLOT(dev->devfn) == slot->device) {
ret = pci_dev_get(dev);
break;
}
up_read(&pci_bus_sem);
return ret;
}
static void disable_slot(struct acpiphp_slot *slot)
{
struct acpiphp_func *func;
struct pci_dev *pdev;
while ((pdev = dev_in_slot(slot))) {
pci_stop_and_remove_bus_device(pdev);
pci_dev_put(pdev);
}
list_for_each_entry(func, &slot->funcs, sibling)
acpiphp_bus_trim(func_to_handle(func));
slot->flags &= (~SLOT_ENABLED);
}
static bool acpiphp_no_hotplug(acpi_handle handle)
{
struct acpi_device *adev = NULL;
acpi_bus_get_device(handle, &adev);
return adev && adev->flags.no_hotplug;
}
static bool slot_no_hotplug(struct acpiphp_slot *slot)
{
struct acpiphp_func *func;
list_for_each_entry(func, &slot->funcs, sibling)
if (acpiphp_no_hotplug(func_to_handle(func)))
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
acpi_handle handle = ACPI_HANDLE(&dev->dev);
struct pci_bus *bus = dev->subordinate;
bool alive = false;
if (handle) {
acpi_status status;
unsigned long long sta;
status = acpi_evaluate_integer(handle, "_STA", NULL, &sta);
alive = (ACPI_SUCCESS(status) && device_status_valid(sta))
|| acpiphp_no_hotplug(handle);
}
if (!alive) {
u32 v;
alive = pci_bus_read_dev_vendor_id(dev->bus, dev->devfn, &v, 0);
}
if (!alive) {
pci_stop_and_remove_bus_device(dev);
if (handle)
acpiphp_bus_trim(handle);
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
mutex_lock(&slot->crit_sect);
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
mutex_unlock(&slot->crit_sect);
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
void acpiphp_check_host_bridge(acpi_handle handle)
{
struct acpiphp_bridge *bridge;
bridge = acpiphp_handle_to_bridge(handle);
if (bridge) {
pci_lock_rescan_remove();
acpiphp_check_bridge(bridge);
pci_unlock_rescan_remove();
put_bridge(bridge);
}
}
static void hotplug_event(acpi_handle handle, u32 type, void *data)
{
struct acpiphp_context *context = data;
struct acpiphp_func *func = &context->func;
struct acpiphp_bridge *bridge;
char objname[64];
struct acpi_buffer buffer = { .length = sizeof(objname),
.pointer = objname };
mutex_lock(&acpiphp_context_lock);
bridge = context->bridge;
if (bridge)
get_bridge(bridge);
mutex_unlock(&acpiphp_context_lock);
pci_lock_rescan_remove();
acpi_get_name(handle, ACPI_FULL_PATHNAME, &buffer);
switch (type) {
case ACPI_NOTIFY_BUS_CHECK:
pr_debug("%s: Bus check notify on %s\n", __func__, objname);
pr_debug("%s: re-enumerating slots under %s\n",
__func__, objname);
if (bridge) {
acpiphp_check_bridge(bridge);
} else {
struct acpiphp_slot *slot = func->slot;
if (slot->flags & SLOT_IS_GOING_AWAY)
break;
mutex_lock(&slot->crit_sect);
enable_slot(slot);
mutex_unlock(&slot->crit_sect);
}
break;
case ACPI_NOTIFY_DEVICE_CHECK:
pr_debug("%s: Device check notify on %s\n", __func__, objname);
if (bridge) {
acpiphp_check_bridge(bridge);
} else {
struct acpiphp_slot *slot = func->slot;
int ret;
if (slot->flags & SLOT_IS_GOING_AWAY)
break;
mutex_lock(&slot->crit_sect);
ret = acpiphp_rescan_slot(slot);
mutex_unlock(&slot->crit_sect);
if (ret)
acpiphp_check_bridge(func->parent);
}
break;
case ACPI_NOTIFY_EJECT_REQUEST:
pr_debug("%s: Device eject notify on %s\n", __func__, objname);
acpiphp_disable_and_eject_slot(func->slot);
break;
}
pci_unlock_rescan_remove();
if (bridge)
put_bridge(bridge);
}
static void hotplug_event_work(void *data, u32 type)
{
struct acpiphp_context *context = data;
acpi_handle handle = context->handle;
acpi_scan_lock_acquire();
hotplug_event(handle, type, context);
acpi_scan_lock_release();
acpi_evaluate_hotplug_ost(handle, type, ACPI_OST_SC_SUCCESS, NULL);
put_bridge(context->func.parent);
}
static void handle_hotplug_event(acpi_handle handle, u32 type, void *data)
{
struct acpiphp_context *context;
u32 ost_code = ACPI_OST_SC_SUCCESS;
acpi_status status;
switch (type) {
case ACPI_NOTIFY_BUS_CHECK:
case ACPI_NOTIFY_DEVICE_CHECK:
break;
case ACPI_NOTIFY_EJECT_REQUEST:
ost_code = ACPI_OST_SC_EJECT_IN_PROGRESS;
acpi_evaluate_hotplug_ost(handle, type, ost_code, NULL);
break;
case ACPI_NOTIFY_DEVICE_WAKE:
return;
case ACPI_NOTIFY_FREQUENCY_MISMATCH:
acpi_handle_err(handle, "Device cannot be configured due "
"to a frequency mismatch\n");
goto out;
case ACPI_NOTIFY_BUS_MODE_MISMATCH:
acpi_handle_err(handle, "Device cannot be configured due "
"to a bus mode mismatch\n");
goto out;
case ACPI_NOTIFY_POWER_FAULT:
acpi_handle_err(handle, "Device has suffered a power fault\n");
goto out;
default:
acpi_handle_warn(handle, "Unsupported event type 0x%x\n", type);
ost_code = ACPI_OST_SC_UNRECOGNIZED_NOTIFY;
goto out;
}
mutex_lock(&acpiphp_context_lock);
context = acpiphp_get_context(handle);
if (!context || WARN_ON(context->handle != handle)
|| context->func.parent->is_going_away)
goto err_out;
get_bridge(context->func.parent);
acpiphp_put_context(context);
status = acpi_hotplug_execute(hotplug_event_work, context, type);
if (ACPI_SUCCESS(status)) {
mutex_unlock(&acpiphp_context_lock);
return;
}
put_bridge(context->func.parent);
err_out:
mutex_unlock(&acpiphp_context_lock);
ost_code = ACPI_OST_SC_NON_SPECIFIC_FAILURE;
out:
acpi_evaluate_hotplug_ost(handle, type, ost_code, NULL);
}
void acpiphp_enumerate_slots(struct pci_bus *bus)
{
struct acpiphp_bridge *bridge;
acpi_handle handle;
acpi_status status;
if (acpiphp_disabled)
return;
handle = ACPI_HANDLE(bus->bridge);
if (!handle)
return;
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
if (!pci_is_root_bus(bridge->pci_bus)) {
struct acpiphp_context *context;
mutex_lock(&acpiphp_context_lock);
context = acpiphp_get_context(handle);
if (!context) {
mutex_unlock(&acpiphp_context_lock);
put_device(&bus->dev);
pci_dev_put(bridge->pci_dev);
kfree(bridge);
return;
}
bridge->context = context;
context->bridge = bridge;
get_bridge(context->func.parent);
mutex_unlock(&acpiphp_context_lock);
}
mutex_lock(&bridge_mutex);
list_add(&bridge->list, &bridge_list);
mutex_unlock(&bridge_mutex);
status = acpi_walk_namespace(ACPI_TYPE_DEVICE, handle, 1,
register_slot, NULL, bridge, NULL);
if (ACPI_FAILURE(status)) {
acpi_handle_err(handle, "failed to register slots\n");
cleanup_bridge(bridge);
put_bridge(bridge);
}
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
cleanup_bridge(bridge);
put_bridge(bridge);
return;
}
mutex_unlock(&bridge_mutex);
}
int acpiphp_enable_slot(struct acpiphp_slot *slot)
{
pci_lock_rescan_remove();
if (slot->flags & SLOT_IS_GOING_AWAY)
return -ENODEV;
mutex_lock(&slot->crit_sect);
if (!(slot->flags & SLOT_ENABLED))
enable_slot(slot);
mutex_unlock(&slot->crit_sect);
pci_unlock_rescan_remove();
return 0;
}
static int acpiphp_disable_and_eject_slot(struct acpiphp_slot *slot)
{
struct acpiphp_func *func;
if (slot->flags & SLOT_IS_GOING_AWAY)
return -ENODEV;
mutex_lock(&slot->crit_sect);
disable_slot(slot);
list_for_each_entry(func, &slot->funcs, sibling)
if (func->flags & FUNC_HAS_EJ0) {
acpi_handle handle = func_to_handle(func);
if (ACPI_FAILURE(acpi_evaluate_ej0(handle)))
acpi_handle_err(handle, "_EJ0 failed\n");
break;
}
mutex_unlock(&slot->crit_sect);
return 0;
}
int acpiphp_disable_slot(struct acpiphp_slot *slot)
{
int ret;
pci_lock_rescan_remove();
ret = acpiphp_disable_and_eject_slot(slot);
pci_unlock_rescan_remove();
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
