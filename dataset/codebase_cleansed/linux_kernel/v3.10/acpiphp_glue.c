static acpi_status
is_pci_dock_device(acpi_handle handle, u32 lvl, void *context, void **rv)
{
int *count = (int *)context;
if (is_dock_device(handle)) {
(*count)++;
return AE_CTRL_TERMINATE;
} else {
return AE_OK;
}
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
struct acpiphp_bridge *bridge;
struct acpiphp_slot *slot, *next;
struct acpiphp_func *func, *tmp;
bridge = container_of(kref, struct acpiphp_bridge, ref);
list_for_each_entry_safe(slot, next, &bridge->slots, node) {
list_for_each_entry_safe(func, tmp, &slot->funcs, sibling) {
kfree(func);
}
kfree(slot);
}
if ((bridge->flags & BRIDGE_HAS_EJ0) && bridge->func)
put_bridge(bridge->func->slot->bridge);
put_device(&bridge->pci_bus->dev);
pci_dev_put(bridge->pci_dev);
kfree(bridge);
}
static int post_dock_fixups(struct notifier_block *nb, unsigned long val,
void *v)
{
struct acpiphp_func *func = container_of(nb, struct acpiphp_func, nb);
struct pci_bus *bus = func->slot->bridge->pci_bus;
u32 buses;
if (!bus->self)
return NOTIFY_OK;
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
return NOTIFY_OK;
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
struct acpiphp_func *func = data;
get_bridge(func->slot->bridge);
}
static void acpiphp_dock_release(void *data)
{
struct acpiphp_func *func = data;
put_bridge(func->slot->bridge);
}
static acpi_status
register_slot(acpi_handle handle, u32 lvl, void *context, void **rv)
{
struct acpiphp_bridge *bridge = (struct acpiphp_bridge *)context;
struct acpiphp_slot *slot;
struct acpiphp_func *newfunc;
acpi_handle tmp;
acpi_status status = AE_OK;
unsigned long long adr, sun;
int device, function, retval, found = 0;
struct pci_bus *pbus = bridge->pci_bus;
struct pci_dev *pdev;
u32 val;
if (!acpi_pci_check_ejectable(pbus, handle) && !is_dock_device(handle))
return AE_OK;
status = acpi_evaluate_integer(handle, "_ADR", NULL, &adr);
if (ACPI_FAILURE(status)) {
warn("can't evaluate _ADR (%#x)\n", status);
return AE_OK;
}
device = (adr >> 16) & 0xffff;
function = adr & 0xffff;
pdev = bridge->pci_dev;
if (pdev && device_is_managed_by_native_pciehp(pdev))
return AE_OK;
newfunc = kzalloc(sizeof(struct acpiphp_func), GFP_KERNEL);
if (!newfunc)
return AE_NO_MEMORY;
newfunc->handle = handle;
newfunc->function = function;
if (ACPI_SUCCESS(acpi_get_handle(handle, "_EJ0", &tmp)))
newfunc->flags = FUNC_HAS_EJ0;
if (ACPI_SUCCESS(acpi_get_handle(handle, "_STA", &tmp)))
newfunc->flags |= FUNC_HAS_STA;
if (ACPI_SUCCESS(acpi_get_handle(handle, "_PS0", &tmp)))
newfunc->flags |= FUNC_HAS_PS0;
if (ACPI_SUCCESS(acpi_get_handle(handle, "_PS3", &tmp)))
newfunc->flags |= FUNC_HAS_PS3;
if (ACPI_SUCCESS(acpi_get_handle(handle, "_DCK", &tmp)))
newfunc->flags |= FUNC_HAS_DCK;
status = acpi_evaluate_integer(handle, "_SUN", NULL, &sun);
if (ACPI_FAILURE(status)) {
sun = bridge->nr_slots+1;
}
list_for_each_entry(slot, &bridge->slots, node)
if (slot->device == device) {
if (slot->sun != sun)
warn("sibling found, but _SUN doesn't match!\n");
found = 1;
break;
}
if (!found) {
slot = kzalloc(sizeof(struct acpiphp_slot), GFP_KERNEL);
if (!slot) {
kfree(newfunc);
return AE_NO_MEMORY;
}
slot->bridge = bridge;
slot->device = device;
slot->sun = sun;
INIT_LIST_HEAD(&slot->funcs);
mutex_init(&slot->crit_sect);
mutex_lock(&bridge_mutex);
list_add_tail(&slot->node, &bridge->slots);
mutex_unlock(&bridge_mutex);
bridge->nr_slots++;
dbg("found ACPI PCI Hotplug slot %llu at PCI %04x:%02x:%02x\n",
slot->sun, pci_domain_nr(pbus), pbus->number, device);
retval = acpiphp_register_hotplug_slot(slot);
if (retval) {
if (retval == -EBUSY)
warn("Slot %llu already registered by another "
"hotplug driver\n", slot->sun);
else
warn("acpiphp_register_hotplug_slot failed "
"(err code = 0x%x)\n", retval);
goto err_exit;
}
}
newfunc->slot = slot;
mutex_lock(&bridge_mutex);
list_add_tail(&newfunc->sibling, &slot->funcs);
mutex_unlock(&bridge_mutex);
if (pci_bus_read_dev_vendor_id(pbus, PCI_DEVFN(device, function),
&val, 60*1000))
slot->flags |= (SLOT_ENABLED | SLOT_POWEREDON);
if (is_dock_device(handle)) {
newfunc->flags &= ~FUNC_HAS_EJ0;
if (register_hotplug_dock_device(handle,
&acpiphp_dock_ops, newfunc,
acpiphp_dock_init, acpiphp_dock_release))
dbg("failed to register dock device\n");
newfunc->nb.notifier_call = post_dock_fixups;
if (register_dock_notifier(&newfunc->nb))
dbg("failed to register a dock notifier");
}
if (!(newfunc->flags & FUNC_HAS_DCK)) {
status = acpi_install_notify_handler(handle,
ACPI_SYSTEM_NOTIFY,
handle_hotplug_event_func,
newfunc);
if (ACPI_FAILURE(status))
err("failed to register interrupt notify handler\n");
} else
status = AE_OK;
return status;
err_exit:
bridge->nr_slots--;
mutex_lock(&bridge_mutex);
list_del(&slot->node);
mutex_unlock(&bridge_mutex);
kfree(slot);
kfree(newfunc);
return AE_OK;
}
static int detect_ejectable_slots(acpi_handle handle)
{
int found = acpi_pci_detect_ejectable(handle);
if (!found) {
acpi_walk_namespace(ACPI_TYPE_DEVICE, handle, (u32)1,
is_pci_dock_device, NULL, (void *)&found, NULL);
}
return found;
}
static void init_bridge_misc(struct acpiphp_bridge *bridge)
{
acpi_status status;
mutex_lock(&bridge_mutex);
list_add(&bridge->list, &bridge_list);
mutex_unlock(&bridge_mutex);
status = acpi_walk_namespace(ACPI_TYPE_DEVICE, bridge->handle, (u32)1,
register_slot, NULL, bridge, NULL);
if (ACPI_FAILURE(status)) {
mutex_lock(&bridge_mutex);
list_del(&bridge->list);
mutex_unlock(&bridge_mutex);
return;
}
if (!pci_is_root_bus(bridge->pci_bus)) {
if ((bridge->flags & BRIDGE_HAS_EJ0) && bridge->func) {
status = acpi_remove_notify_handler(bridge->func->handle,
ACPI_SYSTEM_NOTIFY,
handle_hotplug_event_func);
if (ACPI_FAILURE(status))
err("failed to remove notify handler\n");
}
status = acpi_install_notify_handler(bridge->handle,
ACPI_SYSTEM_NOTIFY,
handle_hotplug_event_bridge,
bridge);
if (ACPI_FAILURE(status)) {
err("failed to register interrupt notify handler\n");
}
}
}
static struct acpiphp_func *acpiphp_bridge_handle_to_function(acpi_handle handle)
{
struct acpiphp_bridge *bridge;
struct acpiphp_slot *slot;
struct acpiphp_func *func = NULL;
mutex_lock(&bridge_mutex);
list_for_each_entry(bridge, &bridge_list, list) {
list_for_each_entry(slot, &bridge->slots, node) {
list_for_each_entry(func, &slot->funcs, sibling) {
if (func->handle == handle) {
get_bridge(func->slot->bridge);
mutex_unlock(&bridge_mutex);
return func;
}
}
}
}
mutex_unlock(&bridge_mutex);
return NULL;
}
static struct acpiphp_bridge *acpiphp_handle_to_bridge(acpi_handle handle)
{
struct acpiphp_bridge *bridge;
mutex_lock(&bridge_mutex);
list_for_each_entry(bridge, &bridge_list, list)
if (bridge->handle == handle) {
get_bridge(bridge);
mutex_unlock(&bridge_mutex);
return bridge;
}
mutex_unlock(&bridge_mutex);
return NULL;
}
static void cleanup_bridge(struct acpiphp_bridge *bridge)
{
struct acpiphp_slot *slot;
struct acpiphp_func *func;
acpi_status status;
acpi_handle handle = bridge->handle;
if (!pci_is_root_bus(bridge->pci_bus)) {
status = acpi_remove_notify_handler(handle,
ACPI_SYSTEM_NOTIFY,
handle_hotplug_event_bridge);
if (ACPI_FAILURE(status))
err("failed to remove notify handler\n");
}
if ((bridge->flags & BRIDGE_HAS_EJ0) && bridge->func) {
status = acpi_install_notify_handler(bridge->func->handle,
ACPI_SYSTEM_NOTIFY,
handle_hotplug_event_func,
bridge->func);
if (ACPI_FAILURE(status))
err("failed to install interrupt notify handler\n");
}
list_for_each_entry(slot, &bridge->slots, node) {
list_for_each_entry(func, &slot->funcs, sibling) {
if (is_dock_device(func->handle)) {
unregister_hotplug_dock_device(func->handle);
unregister_dock_notifier(&func->nb);
}
if (!(func->flags & FUNC_HAS_DCK)) {
status = acpi_remove_notify_handler(func->handle,
ACPI_SYSTEM_NOTIFY,
handle_hotplug_event_func);
if (ACPI_FAILURE(status))
err("failed to remove notify handler\n");
}
}
acpiphp_unregister_hotplug_slot(slot);
}
mutex_lock(&bridge_mutex);
list_del(&bridge->list);
mutex_unlock(&bridge_mutex);
}
static int power_on_slot(struct acpiphp_slot *slot)
{
acpi_status status;
struct acpiphp_func *func;
int retval = 0;
if (slot->flags & SLOT_POWEREDON)
goto err_exit;
list_for_each_entry(func, &slot->funcs, sibling) {
if (func->flags & FUNC_HAS_PS0) {
dbg("%s: executing _PS0\n", __func__);
status = acpi_evaluate_object(func->handle, "_PS0", NULL, NULL);
if (ACPI_FAILURE(status)) {
warn("%s: _PS0 failed\n", __func__);
retval = -1;
goto err_exit;
} else
break;
}
}
slot->flags |= SLOT_POWEREDON;
err_exit:
return retval;
}
static int power_off_slot(struct acpiphp_slot *slot)
{
acpi_status status;
struct acpiphp_func *func;
int retval = 0;
if ((slot->flags & SLOT_POWEREDON) == 0)
goto err_exit;
list_for_each_entry(func, &slot->funcs, sibling) {
if (func->flags & FUNC_HAS_PS3) {
status = acpi_evaluate_object(func->handle, "_PS3", NULL, NULL);
if (ACPI_FAILURE(status)) {
warn("%s: _PS3 failed\n", __func__);
retval = -1;
goto err_exit;
} else
break;
}
}
slot->flags &= (~SLOT_POWEREDON);
err_exit:
return retval;
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
static int acpiphp_bus_add(struct acpiphp_func *func)
{
struct acpi_device *device;
int ret_val;
if (!acpi_bus_get_device(func->handle, &device)) {
dbg("bus exists... trim\n");
acpi_bus_trim(device);
}
ret_val = acpi_bus_scan(func->handle);
if (!ret_val)
ret_val = acpi_bus_get_device(func->handle, &device);
if (ret_val)
dbg("error adding bus, %x\n", -ret_val);
return ret_val;
}
static int acpiphp_bus_trim(acpi_handle handle)
{
struct acpi_device *device;
int retval;
retval = acpi_bus_get_device(handle, &device);
if (retval) {
dbg("acpi_device not found\n");
return retval;
}
acpi_bus_trim(device);
return 0;
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
acpi_evaluate_object(func->handle, "_REG", &arg_list, NULL);
}
}
static void check_hotplug_bridge(struct acpiphp_slot *slot, struct pci_dev *dev)
{
struct acpiphp_func *func;
if (!dev->subordinate)
return;
if (dev->is_hotplug_bridge)
return;
if (PCI_SLOT(dev->devfn) != slot->device)
return;
list_for_each_entry(func, &slot->funcs, sibling) {
if (PCI_FUNC(dev->devfn) == func->function) {
if ((detect_ejectable_slots(func->handle) > 0))
dev->is_hotplug_bridge = 1;
break;
}
}
}
static int __ref enable_device(struct acpiphp_slot *slot)
{
struct pci_dev *dev;
struct pci_bus *bus = slot->bridge->pci_bus;
struct acpiphp_func *func;
int num, max, pass;
LIST_HEAD(add_list);
if (slot->flags & SLOT_ENABLED)
goto err_exit;
list_for_each_entry(func, &slot->funcs, sibling)
acpiphp_bus_add(func);
num = pci_scan_slot(bus, PCI_DEVFN(slot->device, 0));
if (num == 0) {
dbg("No new device found\n");
goto err_exit;
}
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
pci_enable_bridges(bus);
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
err_exit:
return 0;
}
static struct pci_dev *dev_in_slot(struct acpiphp_slot *slot)
{
struct pci_bus *bus = slot->bridge->pci_bus;
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
static int disable_device(struct acpiphp_slot *slot)
{
struct acpiphp_func *func;
struct pci_dev *pdev;
while ((pdev = dev_in_slot(slot))) {
pci_stop_and_remove_bus_device(pdev);
pci_dev_put(pdev);
}
list_for_each_entry(func, &slot->funcs, sibling) {
acpiphp_bus_trim(func->handle);
}
slot->flags &= (~SLOT_ENABLED);
return 0;
}
static unsigned int get_slot_status(struct acpiphp_slot *slot)
{
acpi_status status;
unsigned long long sta = 0;
u32 dvid;
struct acpiphp_func *func;
list_for_each_entry(func, &slot->funcs, sibling) {
if (func->flags & FUNC_HAS_STA) {
status = acpi_evaluate_integer(func->handle, "_STA", NULL, &sta);
if (ACPI_SUCCESS(status) && sta)
break;
} else {
pci_bus_read_config_dword(slot->bridge->pci_bus,
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
int acpiphp_eject_slot(struct acpiphp_slot *slot)
{
acpi_status status;
struct acpiphp_func *func;
struct acpi_object_list arg_list;
union acpi_object arg;
list_for_each_entry(func, &slot->funcs, sibling) {
if ((func->flags & FUNC_HAS_EJ0)) {
arg_list.count = 1;
arg_list.pointer = &arg;
arg.type = ACPI_TYPE_INTEGER;
arg.integer.value = 1;
status = acpi_evaluate_object(func->handle, "_EJ0", &arg_list, NULL);
if (ACPI_FAILURE(status)) {
warn("%s: _EJ0 failed\n", __func__);
return -1;
} else
break;
}
}
return 0;
}
static int acpiphp_check_bridge(struct acpiphp_bridge *bridge)
{
struct acpiphp_slot *slot;
int retval = 0;
int enabled, disabled;
enabled = disabled = 0;
list_for_each_entry(slot, &bridge->slots, node) {
unsigned int status = get_slot_status(slot);
if (slot->flags & SLOT_ENABLED) {
if (status == ACPI_STA_ALL)
continue;
retval = acpiphp_disable_slot(slot);
if (retval) {
err("Error occurred in disabling\n");
goto err_exit;
} else {
acpiphp_eject_slot(slot);
}
disabled++;
} else {
if (status != ACPI_STA_ALL)
continue;
retval = acpiphp_enable_slot(slot);
if (retval) {
err("Error occurred in enabling\n");
goto err_exit;
}
enabled++;
}
}
dbg("%s: %d enabled, %d disabled\n", __func__, enabled, disabled);
err_exit:
return retval;
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
list_for_each_entry_safe(dev, tmp, &bus->devices, bus_list) {
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
static acpi_status
check_sub_bridges(acpi_handle handle, u32 lvl, void *context, void **rv)
{
struct acpiphp_bridge *bridge;
char objname[64];
struct acpi_buffer buffer = { .length = sizeof(objname),
.pointer = objname };
bridge = acpiphp_handle_to_bridge(handle);
if (bridge) {
acpi_get_name(handle, ACPI_FULL_PATHNAME, &buffer);
dbg("%s: re-enumerating slots under %s\n",
__func__, objname);
acpiphp_check_bridge(bridge);
put_bridge(bridge);
}
return AE_OK ;
}
void acpiphp_check_host_bridge(acpi_handle handle)
{
struct acpiphp_bridge *bridge;
bridge = acpiphp_handle_to_bridge(handle);
if (bridge) {
acpiphp_check_bridge(bridge);
put_bridge(bridge);
}
acpi_walk_namespace(ACPI_TYPE_DEVICE, handle,
ACPI_UINT32_MAX, check_sub_bridges, NULL, NULL, NULL);
}
static void _handle_hotplug_event_bridge(struct work_struct *work)
{
struct acpiphp_bridge *bridge;
char objname[64];
struct acpi_buffer buffer = { .length = sizeof(objname),
.pointer = objname };
struct acpi_hp_work *hp_work;
acpi_handle handle;
u32 type;
hp_work = container_of(work, struct acpi_hp_work, work);
handle = hp_work->handle;
type = hp_work->type;
bridge = (struct acpiphp_bridge *)hp_work->context;
acpi_scan_lock_acquire();
acpi_get_name(handle, ACPI_FULL_PATHNAME, &buffer);
switch (type) {
case ACPI_NOTIFY_BUS_CHECK:
dbg("%s: Bus check notify on %s\n", __func__, objname);
dbg("%s: re-enumerating slots under %s\n", __func__, objname);
acpiphp_check_bridge(bridge);
acpi_walk_namespace(ACPI_TYPE_DEVICE, handle,
ACPI_UINT32_MAX, check_sub_bridges, NULL, NULL, NULL);
break;
case ACPI_NOTIFY_DEVICE_CHECK:
dbg("%s: Device check notify on %s\n", __func__, objname);
acpiphp_check_bridge(bridge);
break;
case ACPI_NOTIFY_DEVICE_WAKE:
dbg("%s: Device wake notify on %s\n", __func__, objname);
break;
case ACPI_NOTIFY_EJECT_REQUEST:
dbg("%s: Device eject notify on %s\n", __func__, objname);
if ((bridge->flags & BRIDGE_HAS_EJ0) && bridge->func) {
struct acpiphp_slot *slot;
slot = bridge->func->slot;
if (!acpiphp_disable_slot(slot))
acpiphp_eject_slot(slot);
}
break;
case ACPI_NOTIFY_FREQUENCY_MISMATCH:
printk(KERN_ERR "Device %s cannot be configured due"
" to a frequency mismatch\n", objname);
break;
case ACPI_NOTIFY_BUS_MODE_MISMATCH:
printk(KERN_ERR "Device %s cannot be configured due"
" to a bus mode mismatch\n", objname);
break;
case ACPI_NOTIFY_POWER_FAULT:
printk(KERN_ERR "Device %s has suffered a power fault\n",
objname);
break;
default:
warn("notify_handler: unknown event type 0x%x for %s\n", type, objname);
break;
}
acpi_scan_lock_release();
kfree(hp_work);
put_bridge(bridge);
}
static void handle_hotplug_event_bridge(acpi_handle handle, u32 type,
void *context)
{
struct acpiphp_bridge *bridge = context;
get_bridge(bridge);
alloc_acpi_hp_work(handle, type, context, _handle_hotplug_event_bridge);
}
static void hotplug_event_func(acpi_handle handle, u32 type, void *context)
{
struct acpiphp_func *func = context;
char objname[64];
struct acpi_buffer buffer = { .length = sizeof(objname),
.pointer = objname };
acpi_get_name(handle, ACPI_FULL_PATHNAME, &buffer);
switch (type) {
case ACPI_NOTIFY_BUS_CHECK:
dbg("%s: Bus check notify on %s\n", __func__, objname);
acpiphp_enable_slot(func->slot);
break;
case ACPI_NOTIFY_DEVICE_CHECK:
dbg("%s: Device check notify on %s\n", __func__, objname);
acpiphp_check_bridge(func->slot->bridge);
break;
case ACPI_NOTIFY_DEVICE_WAKE:
dbg("%s: Device wake notify on %s\n", __func__, objname);
break;
case ACPI_NOTIFY_EJECT_REQUEST:
dbg("%s: Device eject notify on %s\n", __func__, objname);
if (!(acpiphp_disable_slot(func->slot)))
acpiphp_eject_slot(func->slot);
break;
default:
warn("notify_handler: unknown event type 0x%x for %s\n", type, objname);
break;
}
}
static void _handle_hotplug_event_func(struct work_struct *work)
{
struct acpi_hp_work *hp_work;
struct acpiphp_func *func;
hp_work = container_of(work, struct acpi_hp_work, work);
func = hp_work->context;
acpi_scan_lock_acquire();
hotplug_event_func(hp_work->handle, hp_work->type, func);
acpi_scan_lock_release();
kfree(hp_work);
put_bridge(func->slot->bridge);
}
static void handle_hotplug_event_func(acpi_handle handle, u32 type,
void *context)
{
struct acpiphp_func *func = context;
get_bridge(func->slot->bridge);
alloc_acpi_hp_work(handle, type, context, _handle_hotplug_event_func);
}
void acpiphp_enumerate_slots(struct pci_bus *bus, acpi_handle handle)
{
acpi_handle dummy_handle;
struct acpiphp_bridge *bridge;
if (acpiphp_disabled)
return;
if (detect_ejectable_slots(handle) <= 0)
return;
bridge = kzalloc(sizeof(struct acpiphp_bridge), GFP_KERNEL);
if (bridge == NULL) {
err("out of memory\n");
return;
}
INIT_LIST_HEAD(&bridge->slots);
kref_init(&bridge->ref);
bridge->handle = handle;
bridge->pci_dev = pci_dev_get(bus->self);
bridge->pci_bus = bus;
get_device(&bus->dev);
if (!pci_is_root_bus(bridge->pci_bus) &&
ACPI_SUCCESS(acpi_get_handle(bridge->handle,
"_EJ0", &dummy_handle))) {
dbg("found ejectable p2p bridge\n");
bridge->flags |= BRIDGE_HAS_EJ0;
bridge->func = acpiphp_bridge_handle_to_function(handle);
}
init_bridge_misc(bridge);
}
void acpiphp_remove_slots(struct pci_bus *bus)
{
struct acpiphp_bridge *bridge, *tmp;
if (acpiphp_disabled)
return;
list_for_each_entry_safe(bridge, tmp, &bridge_list, list)
if (bridge->pci_bus == bus) {
cleanup_bridge(bridge);
put_bridge(bridge);
break;
}
}
int acpiphp_enable_slot(struct acpiphp_slot *slot)
{
int retval;
mutex_lock(&slot->crit_sect);
retval = power_on_slot(slot);
if (retval)
goto err_exit;
if (get_slot_status(slot) == ACPI_STA_ALL) {
retval = enable_device(slot);
if (retval)
power_off_slot(slot);
} else {
dbg("%s: Slot status is not ACPI_STA_ALL\n", __func__);
power_off_slot(slot);
}
err_exit:
mutex_unlock(&slot->crit_sect);
return retval;
}
int acpiphp_disable_slot(struct acpiphp_slot *slot)
{
int retval = 0;
mutex_lock(&slot->crit_sect);
retval = disable_device(slot);
if (retval)
goto err_exit;
retval = power_off_slot(slot);
if (retval)
goto err_exit;
err_exit:
mutex_unlock(&slot->crit_sect);
return retval;
}
u8 acpiphp_get_power_status(struct acpiphp_slot *slot)
{
return (slot->flags & SLOT_POWEREDON);
}
u8 acpiphp_get_latch_status(struct acpiphp_slot *slot)
{
unsigned int sta;
sta = get_slot_status(slot);
return (sta & ACPI_STA_DEVICE_UI) ? 0 : 1;
}
u8 acpiphp_get_adapter_status(struct acpiphp_slot *slot)
{
unsigned int sta;
sta = get_slot_status(slot);
return (sta == 0) ? 0 : 1;
}
