int acpi_pci_register_driver(struct acpi_pci_driver *driver)
{
int n = 0;
struct acpi_pci_root *root;
struct acpi_pci_driver **pptr = &sub_driver;
while (*pptr)
pptr = &(*pptr)->next;
*pptr = driver;
if (!driver->add)
return 0;
list_for_each_entry(root, &acpi_pci_roots, node) {
driver->add(root->device->handle);
n++;
}
return n;
}
void acpi_pci_unregister_driver(struct acpi_pci_driver *driver)
{
struct acpi_pci_root *root;
struct acpi_pci_driver **pptr = &sub_driver;
while (*pptr) {
if (*pptr == driver)
break;
pptr = &(*pptr)->next;
}
BUG_ON(!*pptr);
*pptr = (*pptr)->next;
if (!driver->remove)
return;
list_for_each_entry(root, &acpi_pci_roots, node)
driver->remove(root->device->handle);
}
acpi_handle acpi_get_pci_rootbridge_handle(unsigned int seg, unsigned int bus)
{
struct acpi_pci_root *root;
list_for_each_entry(root, &acpi_pci_roots, node)
if ((root->segment == (u16) seg) &&
(root->secondary.start == (u16) bus))
return root->device->handle;
return NULL;
}
int acpi_is_root_bridge(acpi_handle handle)
{
int ret;
struct acpi_device *device;
ret = acpi_bus_get_device(handle, &device);
if (ret)
return 0;
ret = acpi_match_device_ids(device, root_device_ids);
if (ret)
return 0;
else
return 1;
}
static acpi_status
get_root_bridge_busnr_callback(struct acpi_resource *resource, void *data)
{
struct resource *res = data;
struct acpi_resource_address64 address;
if (resource->type != ACPI_RESOURCE_TYPE_ADDRESS16 &&
resource->type != ACPI_RESOURCE_TYPE_ADDRESS32 &&
resource->type != ACPI_RESOURCE_TYPE_ADDRESS64)
return AE_OK;
acpi_resource_to_address64(resource, &address);
if ((address.address_length > 0) &&
(address.resource_type == ACPI_BUS_NUMBER_RANGE)) {
res->start = address.minimum;
res->end = address.minimum + address.address_length - 1;
}
return AE_OK;
}
static acpi_status try_get_root_bridge_busnr(acpi_handle handle,
struct resource *res)
{
acpi_status status;
res->start = -1;
status =
acpi_walk_resources(handle, METHOD_NAME__CRS,
get_root_bridge_busnr_callback, res);
if (ACPI_FAILURE(status))
return status;
if (res->start == -1)
return AE_ERROR;
return AE_OK;
}
static void acpi_pci_bridge_scan(struct acpi_device *device)
{
int status;
struct acpi_device *child = NULL;
if (device->flags.bus_address)
if (device->parent && device->parent->ops.bind) {
status = device->parent->ops.bind(device);
if (!status) {
list_for_each_entry(child, &device->children, node)
acpi_pci_bridge_scan(child);
}
}
}
static acpi_status acpi_pci_run_osc(acpi_handle handle,
const u32 *capbuf, u32 *retval)
{
struct acpi_osc_context context = {
.uuid_str = pci_osc_uuid_str,
.rev = 1,
.cap.length = 12,
.cap.pointer = (void *)capbuf,
};
acpi_status status;
status = acpi_run_osc(handle, &context);
if (ACPI_SUCCESS(status)) {
*retval = *((u32 *)(context.ret.pointer + 8));
kfree(context.ret.pointer);
}
return status;
}
static acpi_status acpi_pci_query_osc(struct acpi_pci_root *root,
u32 support,
u32 *control)
{
acpi_status status;
u32 result, capbuf[3];
support &= OSC_PCI_SUPPORT_MASKS;
support |= root->osc_support_set;
capbuf[OSC_QUERY_TYPE] = OSC_QUERY_ENABLE;
capbuf[OSC_SUPPORT_TYPE] = support;
if (control) {
*control &= OSC_PCI_CONTROL_MASKS;
capbuf[OSC_CONTROL_TYPE] = *control | root->osc_control_set;
} else {
capbuf[OSC_CONTROL_TYPE] = OSC_PCI_CONTROL_MASKS;
}
status = acpi_pci_run_osc(root->device->handle, capbuf, &result);
if (ACPI_SUCCESS(status)) {
root->osc_support_set = support;
if (control)
*control = result;
}
return status;
}
static acpi_status acpi_pci_osc_support(struct acpi_pci_root *root, u32 flags)
{
acpi_status status;
acpi_handle tmp;
status = acpi_get_handle(root->device->handle, "_OSC", &tmp);
if (ACPI_FAILURE(status))
return status;
mutex_lock(&osc_lock);
status = acpi_pci_query_osc(root, flags, NULL);
mutex_unlock(&osc_lock);
return status;
}
struct acpi_pci_root *acpi_pci_find_root(acpi_handle handle)
{
struct acpi_pci_root *root;
list_for_each_entry(root, &acpi_pci_roots, node) {
if (root->device->handle == handle)
return root;
}
return NULL;
}
struct pci_dev *acpi_get_pci_dev(acpi_handle handle)
{
int dev, fn;
unsigned long long adr;
acpi_status status;
acpi_handle phandle;
struct pci_bus *pbus;
struct pci_dev *pdev = NULL;
struct acpi_handle_node *node, *tmp;
struct acpi_pci_root *root;
LIST_HEAD(device_list);
phandle = handle;
while (!acpi_is_root_bridge(phandle)) {
node = kzalloc(sizeof(struct acpi_handle_node), GFP_KERNEL);
if (!node)
goto out;
INIT_LIST_HEAD(&node->node);
node->handle = phandle;
list_add(&node->node, &device_list);
status = acpi_get_parent(phandle, &phandle);
if (ACPI_FAILURE(status))
goto out;
}
root = acpi_pci_find_root(phandle);
if (!root)
goto out;
pbus = root->bus;
list_for_each_entry(node, &device_list, node) {
acpi_handle hnd = node->handle;
status = acpi_evaluate_integer(hnd, "_ADR", NULL, &adr);
if (ACPI_FAILURE(status))
goto out;
dev = (adr >> 16) & 0xffff;
fn = adr & 0xffff;
pdev = pci_get_slot(pbus, PCI_DEVFN(dev, fn));
if (!pdev || hnd == handle)
break;
pbus = pdev->subordinate;
pci_dev_put(pdev);
if (!pbus) {
dev_dbg(&pdev->dev, "Not a PCI-to-PCI bridge\n");
pdev = NULL;
break;
}
}
out:
list_for_each_entry_safe(node, tmp, &device_list, node)
kfree(node);
return pdev;
}
acpi_status acpi_pci_osc_control_set(acpi_handle handle, u32 *mask, u32 req)
{
struct acpi_pci_root *root;
acpi_status status;
u32 ctrl, capbuf[3];
acpi_handle tmp;
if (!mask)
return AE_BAD_PARAMETER;
ctrl = *mask & OSC_PCI_CONTROL_MASKS;
if ((ctrl & req) != req)
return AE_TYPE;
root = acpi_pci_find_root(handle);
if (!root)
return AE_NOT_EXIST;
status = acpi_get_handle(handle, "_OSC", &tmp);
if (ACPI_FAILURE(status))
return status;
mutex_lock(&osc_lock);
*mask = ctrl | root->osc_control_set;
if ((root->osc_control_set & ctrl) == ctrl)
goto out;
while (*mask) {
status = acpi_pci_query_osc(root, root->osc_support_set, mask);
if (ACPI_FAILURE(status))
goto out;
if (ctrl == *mask)
break;
ctrl = *mask;
}
if ((ctrl & req) != req) {
status = AE_SUPPORT;
goto out;
}
capbuf[OSC_QUERY_TYPE] = 0;
capbuf[OSC_SUPPORT_TYPE] = root->osc_support_set;
capbuf[OSC_CONTROL_TYPE] = ctrl;
status = acpi_pci_run_osc(handle, capbuf, mask);
if (ACPI_SUCCESS(status))
root->osc_control_set = *mask;
out:
mutex_unlock(&osc_lock);
return status;
}
static int __devinit acpi_pci_root_add(struct acpi_device *device)
{
unsigned long long segment, bus;
acpi_status status;
int result;
struct acpi_pci_root *root;
acpi_handle handle;
struct acpi_device *child;
u32 flags, base_flags;
root = kzalloc(sizeof(struct acpi_pci_root), GFP_KERNEL);
if (!root)
return -ENOMEM;
segment = 0;
status = acpi_evaluate_integer(device->handle, METHOD_NAME__SEG, NULL,
&segment);
if (ACPI_FAILURE(status) && status != AE_NOT_FOUND) {
printk(KERN_ERR PREFIX "can't evaluate _SEG\n");
result = -ENODEV;
goto end;
}
root->secondary.flags = IORESOURCE_BUS;
status = try_get_root_bridge_busnr(device->handle, &root->secondary);
if (ACPI_FAILURE(status)) {
root->secondary.end = 0xFF;
printk(KERN_WARNING FW_BUG PREFIX
"no secondary bus range in _CRS\n");
status = acpi_evaluate_integer(device->handle, METHOD_NAME__BBN, NULL, &bus);
if (ACPI_SUCCESS(status))
root->secondary.start = bus;
else if (status == AE_NOT_FOUND)
root->secondary.start = 0;
else {
printk(KERN_ERR PREFIX "can't evaluate _BBN\n");
result = -ENODEV;
goto end;
}
}
INIT_LIST_HEAD(&root->node);
root->device = device;
root->segment = segment & 0xFFFF;
strcpy(acpi_device_name(device), ACPI_PCI_ROOT_DEVICE_NAME);
strcpy(acpi_device_class(device), ACPI_PCI_ROOT_CLASS);
device->driver_data = root;
flags = base_flags = OSC_PCI_SEGMENT_GROUPS_SUPPORT;
acpi_pci_osc_support(root, flags);
list_add_tail(&root->node, &acpi_pci_roots);
printk(KERN_INFO PREFIX "%s [%s] (domain %04x %pR)\n",
acpi_device_name(device), acpi_device_bid(device),
root->segment, &root->secondary);
root->bus = pci_acpi_scan_root(root);
if (!root->bus) {
printk(KERN_ERR PREFIX
"Bus %04x:%02x not present in PCI namespace\n",
root->segment, (unsigned int)root->secondary.start);
result = -ENODEV;
goto end;
}
result = acpi_pci_bind_root(device);
if (result)
goto end;
status = acpi_get_handle(device->handle, METHOD_NAME__PRT, &handle);
if (ACPI_SUCCESS(status))
result = acpi_pci_irq_add_prt(device->handle, root->bus);
list_for_each_entry(child, &device->children, node)
acpi_pci_bridge_scan(child);
if (pci_ext_cfg_avail(root->bus->self))
flags |= OSC_EXT_PCI_CONFIG_SUPPORT;
if (pcie_aspm_support_enabled())
flags |= OSC_ACTIVE_STATE_PWR_SUPPORT |
OSC_CLOCK_PWR_CAPABILITY_SUPPORT;
if (pci_msi_enabled())
flags |= OSC_MSI_SUPPORT;
if (flags != base_flags)
acpi_pci_osc_support(root, flags);
if (!pcie_ports_disabled
&& (flags & ACPI_PCIE_REQ_SUPPORT) == ACPI_PCIE_REQ_SUPPORT) {
flags = OSC_PCI_EXPRESS_CAP_STRUCTURE_CONTROL
| OSC_PCI_EXPRESS_NATIVE_HP_CONTROL
| OSC_PCI_EXPRESS_PME_CONTROL;
if (pci_aer_available()) {
if (aer_acpi_firmware_first())
dev_dbg(root->bus->bridge,
"PCIe errors handled by BIOS.\n");
else
flags |= OSC_PCI_EXPRESS_AER_CONTROL;
}
dev_info(root->bus->bridge,
"Requesting ACPI _OSC control (0x%02x)\n", flags);
status = acpi_pci_osc_control_set(device->handle, &flags,
OSC_PCI_EXPRESS_CAP_STRUCTURE_CONTROL);
if (ACPI_SUCCESS(status)) {
dev_info(root->bus->bridge,
"ACPI _OSC control (0x%02x) granted\n", flags);
} else {
dev_info(root->bus->bridge,
"ACPI _OSC request failed (%s), "
"returned control mask: 0x%02x\n",
acpi_format_exception(status), flags);
pr_info("ACPI _OSC control for PCIe not granted, "
"disabling ASPM\n");
pcie_no_aspm();
}
} else {
dev_info(root->bus->bridge,
"Unable to request _OSC control "
"(_OSC support mask: 0x%02x)\n", flags);
}
pci_acpi_add_bus_pm_notifier(device, root->bus);
if (device->wakeup.flags.run_wake)
device_set_run_wake(root->bus->bridge, true);
return 0;
end:
if (!list_empty(&root->node))
list_del(&root->node);
kfree(root);
return result;
}
static int acpi_pci_root_start(struct acpi_device *device)
{
struct acpi_pci_root *root = acpi_driver_data(device);
pci_bus_add_devices(root->bus);
return 0;
}
static int acpi_pci_root_remove(struct acpi_device *device, int type)
{
struct acpi_pci_root *root = acpi_driver_data(device);
device_set_run_wake(root->bus->bridge, false);
pci_acpi_remove_bus_pm_notifier(device);
kfree(root);
return 0;
}
static int __init acpi_pci_root_init(void)
{
acpi_hest_init();
if (acpi_pci_disabled)
return 0;
pci_acpi_crs_quirks();
if (acpi_bus_register_driver(&acpi_pci_root_driver) < 0)
return -ENODEV;
return 0;
}
