static int acpi_processor_errata_piix4(struct pci_dev *dev)
{
u8 value1 = 0;
u8 value2 = 0;
if (!dev)
return -EINVAL;
switch (dev->revision) {
case 0:
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Found PIIX4 A-step\n"));
break;
case 1:
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Found PIIX4 B-step\n"));
break;
case 2:
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Found PIIX4E\n"));
break;
case 3:
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Found PIIX4M\n"));
break;
default:
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Found unknown PIIX4\n"));
break;
}
switch (dev->revision) {
case 0:
case 1:
errata.piix4.throttle = 1;
case 2:
case 3:
dev = pci_get_subsys(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_82371AB,
PCI_ANY_ID, PCI_ANY_ID, NULL);
if (dev) {
errata.piix4.bmisx = pci_resource_start(dev, 4);
pci_dev_put(dev);
}
dev = pci_get_subsys(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_82371AB_0,
PCI_ANY_ID, PCI_ANY_ID, NULL);
if (dev) {
pci_read_config_byte(dev, 0x76, &value1);
pci_read_config_byte(dev, 0x77, &value2);
if ((value1 & 0x80) || (value2 & 0x80))
errata.piix4.fdma = 1;
pci_dev_put(dev);
}
break;
}
if (errata.piix4.bmisx)
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Bus master activity detection (BM-IDE) erratum enabled\n"));
if (errata.piix4.fdma)
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Type-F DMA livelock erratum (C3 disabled)\n"));
return 0;
}
static int acpi_processor_errata(void)
{
int result = 0;
struct pci_dev *dev = NULL;
dev = pci_get_subsys(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_82371AB_3, PCI_ANY_ID,
PCI_ANY_ID, NULL);
if (dev) {
result = acpi_processor_errata_piix4(dev);
pci_dev_put(dev);
}
return result;
}
int __weak acpi_map_cpu(acpi_handle handle,
phys_cpuid_t physid, u32 acpi_id, int *pcpu)
{
return -ENODEV;
}
int __weak acpi_unmap_cpu(int cpu)
{
return -ENODEV;
}
int __weak arch_register_cpu(int cpu)
{
return -ENODEV;
}
void __weak arch_unregister_cpu(int cpu) {}
static int acpi_processor_hotadd_init(struct acpi_processor *pr)
{
unsigned long long sta;
acpi_status status;
int ret;
if (invalid_phys_cpuid(pr->phys_id))
return -ENODEV;
status = acpi_evaluate_integer(pr->handle, "_STA", NULL, &sta);
if (ACPI_FAILURE(status) || !(sta & ACPI_STA_DEVICE_PRESENT))
return -ENODEV;
cpu_maps_update_begin();
cpu_hotplug_begin();
ret = acpi_map_cpu(pr->handle, pr->phys_id, pr->acpi_id, &pr->id);
if (ret)
goto out;
ret = arch_register_cpu(pr->id);
if (ret) {
acpi_unmap_cpu(pr->id);
goto out;
}
pr_info("CPU%d has been hot-added\n", pr->id);
pr->flags.need_hotplug_init = 1;
out:
cpu_hotplug_done();
cpu_maps_update_done();
return ret;
}
static inline int acpi_processor_hotadd_init(struct acpi_processor *pr)
{
return -ENODEV;
}
static int acpi_processor_get_info(struct acpi_device *device)
{
union acpi_object object = { 0 };
struct acpi_buffer buffer = { sizeof(union acpi_object), &object };
struct acpi_processor *pr = acpi_driver_data(device);
int device_declaration = 0;
acpi_status status = AE_OK;
static int cpu0_initialized;
unsigned long long value;
acpi_processor_errata();
if (acpi_gbl_FADT.pm2_control_block && acpi_gbl_FADT.pm2_control_length) {
pr->flags.bm_control = 1;
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Bus mastering arbitration control present\n"));
} else
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"No bus mastering arbitration control\n"));
if (!strcmp(acpi_device_hid(device), ACPI_PROCESSOR_OBJECT_HID)) {
status = acpi_evaluate_object(pr->handle, NULL, NULL, &buffer);
if (ACPI_FAILURE(status)) {
dev_err(&device->dev,
"Failed to evaluate processor object (0x%x)\n",
status);
return -ENODEV;
}
pr->acpi_id = object.processor.proc_id;
} else {
status = acpi_evaluate_integer(pr->handle, METHOD_NAME__UID,
NULL, &value);
if (ACPI_FAILURE(status)) {
dev_err(&device->dev,
"Failed to evaluate processor _UID (0x%x)\n",
status);
return -ENODEV;
}
device_declaration = 1;
pr->acpi_id = value;
}
if (acpi_duplicate_processor_id(pr->acpi_id)) {
dev_err(&device->dev,
"Failed to get unique processor _UID (0x%x)\n",
pr->acpi_id);
return -ENODEV;
}
pr->phys_id = acpi_get_phys_id(pr->handle, device_declaration,
pr->acpi_id);
if (invalid_phys_cpuid(pr->phys_id))
acpi_handle_debug(pr->handle, "failed to get CPU physical ID.\n");
pr->id = acpi_map_cpuid(pr->phys_id, pr->acpi_id);
if (!cpu0_initialized && !acpi_has_cpu_in_madt()) {
cpu0_initialized = 1;
if (invalid_logical_cpuid(pr->id) && (num_online_cpus() == 1))
pr->id = 0;
}
if (invalid_logical_cpuid(pr->id) || !cpu_present(pr->id)) {
int ret = acpi_processor_hotadd_init(pr);
if (ret)
return ret;
}
sprintf(acpi_device_bid(device), "CPU%X", pr->id);
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Processor [%d:%d]\n", pr->id,
pr->acpi_id));
if (!object.processor.pblk_address)
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "No PBLK (NULL address)\n"));
else if (object.processor.pblk_length != 6)
dev_err(&device->dev, "Invalid PBLK length [%d]\n",
object.processor.pblk_length);
else {
pr->throttling.address = object.processor.pblk_address;
pr->throttling.duty_offset = acpi_gbl_FADT.duty_offset;
pr->throttling.duty_width = acpi_gbl_FADT.duty_width;
pr->pblk = object.processor.pblk_address;
}
status = acpi_evaluate_integer(pr->handle, "_SUN", NULL, &value);
if (ACPI_SUCCESS(status))
arch_fix_phys_package_id(pr->id, value);
return 0;
}
static int acpi_processor_add(struct acpi_device *device,
const struct acpi_device_id *id)
{
struct acpi_processor *pr;
struct device *dev;
int result = 0;
pr = kzalloc(sizeof(struct acpi_processor), GFP_KERNEL);
if (!pr)
return -ENOMEM;
if (!zalloc_cpumask_var(&pr->throttling.shared_cpu_map, GFP_KERNEL)) {
result = -ENOMEM;
goto err_free_pr;
}
pr->handle = device->handle;
strcpy(acpi_device_name(device), ACPI_PROCESSOR_DEVICE_NAME);
strcpy(acpi_device_class(device), ACPI_PROCESSOR_CLASS);
device->driver_data = pr;
result = acpi_processor_get_info(device);
if (result)
return 0;
BUG_ON(pr->id >= nr_cpu_ids);
if (per_cpu(processor_device_array, pr->id) != NULL &&
per_cpu(processor_device_array, pr->id) != device) {
dev_warn(&device->dev,
"BIOS reported wrong ACPI id %d for the processor\n",
pr->id);
goto err;
}
per_cpu(processor_device_array, pr->id) = device;
per_cpu(processors, pr->id) = pr;
dev = get_cpu_device(pr->id);
if (!dev) {
result = -ENODEV;
goto err;
}
result = acpi_bind_one(dev, device);
if (result)
goto err;
pr->dev = dev;
if (device_attach(dev) >= 0)
return 1;
dev_err(dev, "Processor driver could not be attached\n");
acpi_unbind_one(dev);
err:
free_cpumask_var(pr->throttling.shared_cpu_map);
device->driver_data = NULL;
per_cpu(processors, pr->id) = NULL;
err_free_pr:
kfree(pr);
return result;
}
static void acpi_processor_remove(struct acpi_device *device)
{
struct acpi_processor *pr;
if (!device || !acpi_driver_data(device))
return;
pr = acpi_driver_data(device);
if (pr->id >= nr_cpu_ids)
goto out;
device_release_driver(pr->dev);
acpi_unbind_one(pr->dev);
per_cpu(processor_device_array, pr->id) = NULL;
per_cpu(processors, pr->id) = NULL;
cpu_maps_update_begin();
cpu_hotplug_begin();
arch_unregister_cpu(pr->id);
acpi_unmap_cpu(pr->id);
cpu_hotplug_done();
cpu_maps_update_done();
try_offline_node(cpu_to_node(pr->id));
out:
free_cpumask_var(pr->throttling.shared_cpu_map);
kfree(pr);
}
static acpi_status __init acpi_hwp_native_thermal_lvt_osc(acpi_handle handle,
u32 lvl,
void *context,
void **rv)
{
u8 sb_uuid_str[] = "4077A616-290C-47BE-9EBD-D87058713953";
u32 capbuf[2];
struct acpi_osc_context osc_context = {
.uuid_str = sb_uuid_str,
.rev = 1,
.cap.length = 8,
.cap.pointer = capbuf,
};
if (acpi_hwp_native_thermal_lvt_set)
return AE_CTRL_TERMINATE;
capbuf[0] = 0x0000;
capbuf[1] = 0x1000;
if (ACPI_SUCCESS(acpi_run_osc(handle, &osc_context))) {
if (osc_context.ret.pointer && osc_context.ret.length > 1) {
u32 *capbuf_ret = osc_context.ret.pointer;
if (capbuf_ret[1] & 0x1000) {
acpi_handle_info(handle,
"_OSC native thermal LVT Acked\n");
acpi_hwp_native_thermal_lvt_set = true;
}
}
kfree(osc_context.ret.pointer);
}
return AE_OK;
}
void __init acpi_early_processor_osc(void)
{
if (boot_cpu_has(X86_FEATURE_HWP)) {
acpi_walk_namespace(ACPI_TYPE_PROCESSOR, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX,
acpi_hwp_native_thermal_lvt_osc,
NULL, NULL, NULL);
acpi_get_devices(ACPI_PROCESSOR_DEVICE_HID,
acpi_hwp_native_thermal_lvt_osc,
NULL, NULL);
}
}
static int acpi_processor_container_attach(struct acpi_device *dev,
const struct acpi_device_id *id)
{
return 1;
}
static void __init processor_validated_ids_update(int proc_id)
{
int i;
if (nr_unique_ids == NR_CPUS||nr_duplicate_ids == NR_CPUS)
return;
for (i = 0; i < nr_duplicate_ids; i++) {
if (duplicate_processor_ids[i] == proc_id)
return;
}
for (i = 0; i < nr_unique_ids; i++) {
if (unique_processor_ids[i] == proc_id) {
duplicate_processor_ids[nr_duplicate_ids] = proc_id;
nr_duplicate_ids++;
return;
}
}
unique_processor_ids[nr_unique_ids] = proc_id;
nr_unique_ids++;
}
static acpi_status __init acpi_processor_ids_walk(acpi_handle handle,
u32 lvl,
void *context,
void **rv)
{
acpi_status status;
acpi_object_type acpi_type;
unsigned long long uid;
union acpi_object object = { 0 };
struct acpi_buffer buffer = { sizeof(union acpi_object), &object };
status = acpi_get_type(handle, &acpi_type);
if (ACPI_FAILURE(status))
return false;
switch (acpi_type) {
case ACPI_TYPE_PROCESSOR:
status = acpi_evaluate_object(handle, NULL, NULL, &buffer);
if (ACPI_FAILURE(status))
goto err;
uid = object.processor.proc_id;
break;
case ACPI_TYPE_DEVICE:
status = acpi_evaluate_integer(handle, "_UID", NULL, &uid);
if (ACPI_FAILURE(status))
goto err;
break;
default:
goto err;
}
processor_validated_ids_update(uid);
return true;
err:
acpi_handle_info(handle, "Invalid processor object\n");
return false;
}
void __init acpi_processor_check_duplicates(void)
{
acpi_walk_namespace(ACPI_TYPE_PROCESSOR, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX,
acpi_processor_ids_walk,
NULL, NULL, NULL);
acpi_get_devices(ACPI_PROCESSOR_DEVICE_HID, acpi_processor_ids_walk,
NULL, NULL);
}
bool acpi_duplicate_processor_id(int proc_id)
{
int i;
for (i = 0; i < nr_duplicate_ids; i++) {
if (duplicate_processor_ids[i] == proc_id)
return true;
}
return false;
}
void __init acpi_processor_init(void)
{
acpi_processor_check_duplicates();
acpi_scan_add_handler_with_hotplug(&processor_handler, "processor");
acpi_scan_add_handler(&processor_container_handler);
}
