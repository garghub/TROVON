static int acpi_pci_root_scan_dependent(struct acpi_device *adev)
{
acpiphp_check_host_bridge(adev);
return 0;
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
acpi_status status;
status = acpi_resource_to_address64(resource, &address);
if (ACPI_FAILURE(status))
return AE_OK;
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
static void decode_osc_bits(struct acpi_pci_root *root, char *msg, u32 word,
struct pci_osc_bit_struct *table, int size)
{
char buf[80];
int i, len = 0;
struct pci_osc_bit_struct *entry;
buf[0] = '\0';
for (i = 0, entry = table; i < size; i++, entry++)
if (word & entry->bit)
len += snprintf(buf + len, sizeof(buf) - len, "%s%s",
len ? " " : "", entry->desc);
dev_info(&root->device->dev, "_OSC: %s [%s]\n", msg, buf);
}
static void decode_osc_support(struct acpi_pci_root *root, char *msg, u32 word)
{
decode_osc_bits(root, msg, word, pci_osc_support_bit,
ARRAY_SIZE(pci_osc_support_bit));
}
static void decode_osc_control(struct acpi_pci_root *root, char *msg, u32 word)
{
decode_osc_bits(root, msg, word, pci_osc_control_bit,
ARRAY_SIZE(pci_osc_control_bit));
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
capbuf[OSC_QUERY_DWORD] = OSC_QUERY_ENABLE;
capbuf[OSC_SUPPORT_DWORD] = support;
if (control) {
*control &= OSC_PCI_CONTROL_MASKS;
capbuf[OSC_CONTROL_DWORD] = *control | root->osc_control_set;
} else {
capbuf[OSC_CONTROL_DWORD] = root->osc_control_set;
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
mutex_lock(&osc_lock);
status = acpi_pci_query_osc(root, flags, NULL);
mutex_unlock(&osc_lock);
return status;
}
struct acpi_pci_root *acpi_pci_find_root(acpi_handle handle)
{
struct acpi_pci_root *root;
struct acpi_device *device;
if (acpi_bus_get_device(handle, &device) ||
acpi_match_device_ids(device, root_device_ids))
return NULL;
root = acpi_driver_data(device);
return root;
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
acpi_status status = AE_OK;
u32 ctrl, capbuf[3];
if (!mask)
return AE_BAD_PARAMETER;
ctrl = *mask & OSC_PCI_CONTROL_MASKS;
if ((ctrl & req) != req)
return AE_TYPE;
root = acpi_pci_find_root(handle);
if (!root)
return AE_NOT_EXIST;
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
decode_osc_control(root, "platform does not support",
ctrl & ~(*mask));
ctrl = *mask;
}
if ((ctrl & req) != req) {
decode_osc_control(root, "not requesting control; platform does not support",
req & ~(ctrl));
status = AE_SUPPORT;
goto out;
}
capbuf[OSC_QUERY_DWORD] = 0;
capbuf[OSC_SUPPORT_DWORD] = root->osc_support_set;
capbuf[OSC_CONTROL_DWORD] = ctrl;
status = acpi_pci_run_osc(handle, capbuf, mask);
if (ACPI_SUCCESS(status))
root->osc_control_set = *mask;
out:
mutex_unlock(&osc_lock);
return status;
}
static void negotiate_os_control(struct acpi_pci_root *root, int *no_aspm,
int *clear_aspm)
{
u32 support, control, requested;
acpi_status status;
struct acpi_device *device = root->device;
acpi_handle handle = device->handle;
support = OSC_PCI_SEGMENT_GROUPS_SUPPORT;
if (pci_ext_cfg_avail())
support |= OSC_PCI_EXT_CONFIG_SUPPORT;
if (pcie_aspm_support_enabled())
support |= OSC_PCI_ASPM_SUPPORT | OSC_PCI_CLOCK_PM_SUPPORT;
if (pci_msi_enabled())
support |= OSC_PCI_MSI_SUPPORT;
decode_osc_support(root, "OS supports", support);
status = acpi_pci_osc_support(root, support);
if (ACPI_FAILURE(status)) {
dev_info(&device->dev, "_OSC failed (%s); disabling ASPM\n",
acpi_format_exception(status));
*no_aspm = 1;
return;
}
if (pcie_ports_disabled) {
dev_info(&device->dev, "PCIe port services disabled; not requesting _OSC control\n");
return;
}
if ((support & ACPI_PCIE_REQ_SUPPORT) != ACPI_PCIE_REQ_SUPPORT) {
decode_osc_support(root, "not requesting OS control; OS requires",
ACPI_PCIE_REQ_SUPPORT);
return;
}
control = OSC_PCI_EXPRESS_CAPABILITY_CONTROL
| OSC_PCI_EXPRESS_NATIVE_HP_CONTROL
| OSC_PCI_EXPRESS_PME_CONTROL;
if (pci_aer_available()) {
if (aer_acpi_firmware_first())
dev_info(&device->dev,
"PCIe AER handled by firmware\n");
else
control |= OSC_PCI_EXPRESS_AER_CONTROL;
}
requested = control;
status = acpi_pci_osc_control_set(handle, &control,
OSC_PCI_EXPRESS_CAPABILITY_CONTROL);
if (ACPI_SUCCESS(status)) {
decode_osc_control(root, "OS now controls", control);
if (acpi_gbl_FADT.boot_flags & ACPI_FADT_NO_ASPM) {
*clear_aspm = 1;
}
} else {
decode_osc_control(root, "OS requested", requested);
decode_osc_control(root, "platform willing to grant", control);
dev_info(&device->dev, "_OSC failed (%s); disabling ASPM\n",
acpi_format_exception(status));
*no_aspm = 1;
}
}
static int acpi_pci_root_add(struct acpi_device *device,
const struct acpi_device_id *not_used)
{
unsigned long long segment, bus;
acpi_status status;
int result;
struct acpi_pci_root *root;
acpi_handle handle = device->handle;
int no_aspm = 0, clear_aspm = 0;
root = kzalloc(sizeof(struct acpi_pci_root), GFP_KERNEL);
if (!root)
return -ENOMEM;
segment = 0;
status = acpi_evaluate_integer(handle, METHOD_NAME__SEG, NULL,
&segment);
if (ACPI_FAILURE(status) && status != AE_NOT_FOUND) {
dev_err(&device->dev, "can't evaluate _SEG\n");
result = -ENODEV;
goto end;
}
root->secondary.flags = IORESOURCE_BUS;
status = try_get_root_bridge_busnr(handle, &root->secondary);
if (ACPI_FAILURE(status)) {
root->secondary.end = 0xFF;
dev_warn(&device->dev,
FW_BUG "no secondary bus range in _CRS\n");
status = acpi_evaluate_integer(handle, METHOD_NAME__BBN,
NULL, &bus);
if (ACPI_SUCCESS(status))
root->secondary.start = bus;
else if (status == AE_NOT_FOUND)
root->secondary.start = 0;
else {
dev_err(&device->dev, "can't evaluate _BBN\n");
result = -ENODEV;
goto end;
}
}
root->device = device;
root->segment = segment & 0xFFFF;
strcpy(acpi_device_name(device), ACPI_PCI_ROOT_DEVICE_NAME);
strcpy(acpi_device_class(device), ACPI_PCI_ROOT_CLASS);
device->driver_data = root;
pr_info(PREFIX "%s [%s] (domain %04x %pR)\n",
acpi_device_name(device), acpi_device_bid(device),
root->segment, &root->secondary);
root->mcfg_addr = acpi_pci_root_get_mcfg_addr(handle);
negotiate_os_control(root, &no_aspm, &clear_aspm);
root->bus = pci_acpi_scan_root(root);
if (!root->bus) {
dev_err(&device->dev,
"Bus %04x:%02x not present in PCI namespace\n",
root->segment, (unsigned int)root->secondary.start);
device->driver_data = NULL;
result = -ENODEV;
goto end;
}
if (clear_aspm) {
dev_info(&device->dev, "Disabling ASPM (FADT indicates it is unsupported)\n");
pcie_clear_aspm(root->bus);
}
if (no_aspm)
pcie_no_aspm();
pci_acpi_add_bus_pm_notifier(device);
if (device->wakeup.flags.run_wake)
device_set_run_wake(root->bus->bridge, true);
if (system_state != SYSTEM_BOOTING) {
pcibios_resource_survey_bus(root->bus);
pci_assign_unassigned_root_bus_resources(root->bus);
}
pci_lock_rescan_remove();
pci_bus_add_devices(root->bus);
pci_unlock_rescan_remove();
return 1;
end:
kfree(root);
return result;
}
static void acpi_pci_root_remove(struct acpi_device *device)
{
struct acpi_pci_root *root = acpi_driver_data(device);
pci_lock_rescan_remove();
pci_stop_root_bus(root->bus);
device_set_run_wake(root->bus->bridge, false);
pci_acpi_remove_bus_pm_notifier(device);
pci_remove_root_bus(root->bus);
pci_unlock_rescan_remove();
kfree(root);
}
void __init acpi_pci_root_init(void)
{
acpi_hest_init();
if (acpi_pci_disabled)
return;
pci_acpi_crs_quirks();
acpi_scan_add_handler_with_hotplug(&pci_root_handler, "pci_root");
}
