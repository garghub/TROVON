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
static int acpi_processor_errata(struct acpi_processor *pr)
{
int result = 0;
struct pci_dev *dev = NULL;
if (!pr)
return -EINVAL;
dev = pci_get_subsys(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_82371AB_3, PCI_ANY_ID,
PCI_ANY_ID, NULL);
if (dev) {
result = acpi_processor_errata_piix4(dev);
pci_dev_put(dev);
}
return result;
}
static int acpi_processor_get_info(struct acpi_device *device)
{
acpi_status status = 0;
union acpi_object object = { 0 };
struct acpi_buffer buffer = { sizeof(union acpi_object), &object };
struct acpi_processor *pr;
int cpu_index, device_declaration = 0;
static int cpu0_initialized;
pr = acpi_driver_data(device);
if (!pr)
return -EINVAL;
if (num_online_cpus() > 1)
errata.smp = TRUE;
acpi_processor_errata(pr);
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
printk(KERN_ERR PREFIX "Evaluating processor object\n");
return -ENODEV;
}
pr->acpi_id = object.processor.proc_id;
} else {
unsigned long long value;
status = acpi_evaluate_integer(pr->handle, METHOD_NAME__UID,
NULL, &value);
if (ACPI_FAILURE(status)) {
printk(KERN_ERR PREFIX
"Evaluating processor _UID [%#x]\n", status);
return -ENODEV;
}
device_declaration = 1;
pr->acpi_id = value;
}
cpu_index = acpi_get_cpuid(pr->handle, device_declaration, pr->acpi_id);
if (!cpu0_initialized && (cpu_index == -1) &&
(num_online_cpus() == 1)) {
cpu_index = 0;
}
cpu0_initialized = 1;
pr->id = cpu_index;
if (pr->id == -1) {
if (ACPI_FAILURE
(acpi_processor_hotadd_init(pr->handle, &pr->id))) {
return -ENODEV;
}
}
sprintf(acpi_device_bid(device), "CPU%X", pr->id);
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Processor [%d:%d]\n", pr->id,
pr->acpi_id));
if (!object.processor.pblk_address)
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "No PBLK (NULL address)\n"));
else if (object.processor.pblk_length != 6)
printk(KERN_ERR PREFIX "Invalid PBLK length [%d]\n",
object.processor.pblk_length);
else {
pr->throttling.address = object.processor.pblk_address;
pr->throttling.duty_offset = acpi_gbl_FADT.duty_offset;
pr->throttling.duty_width = acpi_gbl_FADT.duty_width;
pr->pblk = object.processor.pblk_address;
request_region(pr->throttling.address, 6, "ACPI CPU throttle");
}
status = acpi_evaluate_object(pr->handle, "_SUN", NULL, &buffer);
if (ACPI_SUCCESS(status))
arch_fix_phys_package_id(pr->id, object.integer.value);
return 0;
}
static void acpi_processor_notify(struct acpi_device *device, u32 event)
{
struct acpi_processor *pr = acpi_driver_data(device);
int saved;
if (!pr)
return;
switch (event) {
case ACPI_PROCESSOR_NOTIFY_PERFORMANCE:
saved = pr->performance_platform_limit;
acpi_processor_ppc_has_changed(pr, 1);
if (saved == pr->performance_platform_limit)
break;
acpi_bus_generate_proc_event(device, event,
pr->performance_platform_limit);
acpi_bus_generate_netlink_event(device->pnp.device_class,
dev_name(&device->dev), event,
pr->performance_platform_limit);
break;
case ACPI_PROCESSOR_NOTIFY_POWER:
acpi_processor_cst_has_changed(pr);
acpi_bus_generate_proc_event(device, event, 0);
acpi_bus_generate_netlink_event(device->pnp.device_class,
dev_name(&device->dev), event, 0);
break;
case ACPI_PROCESSOR_NOTIFY_THROTTLING:
acpi_processor_tstate_has_changed(pr);
acpi_bus_generate_proc_event(device, event, 0);
acpi_bus_generate_netlink_event(device->pnp.device_class,
dev_name(&device->dev), event, 0);
default:
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Unsupported event [0x%x]\n", event));
break;
}
return;
}
static int acpi_cpu_soft_notify(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
unsigned int cpu = (unsigned long)hcpu;
struct acpi_processor *pr = per_cpu(processors, cpu);
if (action == CPU_ONLINE && pr) {
acpi_processor_ppc_has_changed(pr, 0);
acpi_processor_hotplug(pr);
acpi_processor_reevaluate_tstate(pr, action);
acpi_processor_tstate_has_changed(pr);
}
if (action == CPU_DEAD && pr) {
acpi_processor_reevaluate_tstate(pr, action);
}
return NOTIFY_OK;
}
static int __cpuinit acpi_processor_add(struct acpi_device *device)
{
struct acpi_processor *pr = NULL;
int result = 0;
struct sys_device *sysdev;
pr = kzalloc(sizeof(struct acpi_processor), GFP_KERNEL);
if (!pr)
return -ENOMEM;
if (!zalloc_cpumask_var(&pr->throttling.shared_cpu_map, GFP_KERNEL)) {
kfree(pr);
return -ENOMEM;
}
pr->handle = device->handle;
strcpy(acpi_device_name(device), ACPI_PROCESSOR_DEVICE_NAME);
strcpy(acpi_device_class(device), ACPI_PROCESSOR_CLASS);
device->driver_data = pr;
result = acpi_processor_get_info(device);
if (result) {
return 0;
}
#ifdef CONFIG_SMP
if (pr->id >= setup_max_cpus && pr->id != 0)
return 0;
#endif
BUG_ON((pr->id >= nr_cpu_ids) || (pr->id < 0));
if (per_cpu(processor_device_array, pr->id) != NULL &&
per_cpu(processor_device_array, pr->id) != device) {
printk(KERN_WARNING "BIOS reported wrong ACPI id "
"for the processor\n");
result = -ENODEV;
goto err_free_cpumask;
}
per_cpu(processor_device_array, pr->id) = device;
per_cpu(processors, pr->id) = pr;
sysdev = get_cpu_sysdev(pr->id);
if (sysfs_create_link(&device->dev.kobj, &sysdev->kobj, "sysdev")) {
result = -EFAULT;
goto err_free_cpumask;
}
#ifdef CONFIG_CPU_FREQ
acpi_processor_ppc_has_changed(pr, 0);
#endif
acpi_processor_get_throttling_info(pr);
acpi_processor_get_limit_info(pr);
if (!cpuidle_get_driver() || cpuidle_get_driver() == &acpi_idle_driver)
acpi_processor_power_init(pr, device);
pr->cdev = thermal_cooling_device_register("Processor", device,
&processor_cooling_ops);
if (IS_ERR(pr->cdev)) {
result = PTR_ERR(pr->cdev);
goto err_power_exit;
}
dev_dbg(&device->dev, "registered as cooling_device%d\n",
pr->cdev->id);
result = sysfs_create_link(&device->dev.kobj,
&pr->cdev->device.kobj,
"thermal_cooling");
if (result) {
printk(KERN_ERR PREFIX "Create sysfs link\n");
goto err_thermal_unregister;
}
result = sysfs_create_link(&pr->cdev->device.kobj,
&device->dev.kobj,
"device");
if (result) {
printk(KERN_ERR PREFIX "Create sysfs link\n");
goto err_remove_sysfs;
}
return 0;
err_remove_sysfs:
sysfs_remove_link(&device->dev.kobj, "thermal_cooling");
err_thermal_unregister:
thermal_cooling_device_unregister(pr->cdev);
err_power_exit:
acpi_processor_power_exit(pr, device);
err_free_cpumask:
free_cpumask_var(pr->throttling.shared_cpu_map);
return result;
}
static int acpi_processor_remove(struct acpi_device *device, int type)
{
struct acpi_processor *pr = NULL;
if (!device || !acpi_driver_data(device))
return -EINVAL;
pr = acpi_driver_data(device);
if (pr->id >= nr_cpu_ids)
goto free;
if (type == ACPI_BUS_REMOVAL_EJECT) {
if (acpi_processor_handle_eject(pr))
return -EINVAL;
}
acpi_processor_power_exit(pr, device);
sysfs_remove_link(&device->dev.kobj, "sysdev");
if (pr->cdev) {
sysfs_remove_link(&device->dev.kobj, "thermal_cooling");
sysfs_remove_link(&pr->cdev->device.kobj, "device");
thermal_cooling_device_unregister(pr->cdev);
pr->cdev = NULL;
}
per_cpu(processors, pr->id) = NULL;
per_cpu(processor_device_array, pr->id) = NULL;
free:
free_cpumask_var(pr->throttling.shared_cpu_map);
kfree(pr);
return 0;
}
static int is_processor_present(acpi_handle handle)
{
acpi_status status;
unsigned long long sta = 0;
status = acpi_evaluate_integer(handle, "_STA", NULL, &sta);
if (ACPI_SUCCESS(status) && (sta & ACPI_STA_DEVICE_PRESENT))
return 1;
if (status == AE_NOT_FOUND)
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Processor does not support hot plug\n"));
else
ACPI_EXCEPTION((AE_INFO, status,
"Processor Device is not present"));
return 0;
}
static
int acpi_processor_device_add(acpi_handle handle, struct acpi_device **device)
{
acpi_handle phandle;
struct acpi_device *pdev;
if (acpi_get_parent(handle, &phandle)) {
return -ENODEV;
}
if (acpi_bus_get_device(phandle, &pdev)) {
return -ENODEV;
}
if (acpi_bus_add(device, pdev, handle, ACPI_BUS_TYPE_PROCESSOR)) {
return -ENODEV;
}
return 0;
}
static void acpi_processor_hotplug_notify(acpi_handle handle,
u32 event, void *data)
{
struct acpi_processor *pr;
struct acpi_device *device = NULL;
int result;
switch (event) {
case ACPI_NOTIFY_BUS_CHECK:
case ACPI_NOTIFY_DEVICE_CHECK:
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Processor driver received %s event\n",
(event == ACPI_NOTIFY_BUS_CHECK) ?
"ACPI_NOTIFY_BUS_CHECK" : "ACPI_NOTIFY_DEVICE_CHECK"));
if (!is_processor_present(handle))
break;
if (acpi_bus_get_device(handle, &device)) {
result = acpi_processor_device_add(handle, &device);
if (result)
printk(KERN_ERR PREFIX
"Unable to add the device\n");
break;
}
break;
case ACPI_NOTIFY_EJECT_REQUEST:
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"received ACPI_NOTIFY_EJECT_REQUEST\n"));
if (acpi_bus_get_device(handle, &device)) {
printk(KERN_ERR PREFIX
"Device don't exist, dropping EJECT\n");
break;
}
pr = acpi_driver_data(device);
if (!pr) {
printk(KERN_ERR PREFIX
"Driver data is NULL, dropping EJECT\n");
return;
}
break;
default:
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Unsupported event [0x%x]\n", event));
break;
}
return;
}
static acpi_status
processor_walk_namespace_cb(acpi_handle handle,
u32 lvl, void *context, void **rv)
{
acpi_status status;
int *action = context;
acpi_object_type type = 0;
status = acpi_get_type(handle, &type);
if (ACPI_FAILURE(status))
return (AE_OK);
if (type != ACPI_TYPE_PROCESSOR)
return (AE_OK);
switch (*action) {
case INSTALL_NOTIFY_HANDLER:
acpi_install_notify_handler(handle,
ACPI_SYSTEM_NOTIFY,
acpi_processor_hotplug_notify,
NULL);
break;
case UNINSTALL_NOTIFY_HANDLER:
acpi_remove_notify_handler(handle,
ACPI_SYSTEM_NOTIFY,
acpi_processor_hotplug_notify);
break;
default:
break;
}
return (AE_OK);
}
static acpi_status acpi_processor_hotadd_init(acpi_handle handle, int *p_cpu)
{
if (!is_processor_present(handle)) {
return AE_ERROR;
}
if (acpi_map_lsapic(handle, p_cpu))
return AE_ERROR;
if (arch_register_cpu(*p_cpu)) {
acpi_unmap_lsapic(*p_cpu);
return AE_ERROR;
}
return AE_OK;
}
static int acpi_processor_handle_eject(struct acpi_processor *pr)
{
if (cpu_online(pr->id))
cpu_down(pr->id);
arch_unregister_cpu(pr->id);
acpi_unmap_lsapic(pr->id);
return (0);
}
static acpi_status acpi_processor_hotadd_init(acpi_handle handle, int *p_cpu)
{
return AE_ERROR;
}
static int acpi_processor_handle_eject(struct acpi_processor *pr)
{
return (-EINVAL);
}
static
void acpi_processor_install_hotplug_notify(void)
{
#ifdef CONFIG_ACPI_HOTPLUG_CPU
int action = INSTALL_NOTIFY_HANDLER;
acpi_walk_namespace(ACPI_TYPE_PROCESSOR,
ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX,
processor_walk_namespace_cb, NULL, &action, NULL);
#endif
register_hotcpu_notifier(&acpi_cpu_notifier);
}
static
void acpi_processor_uninstall_hotplug_notify(void)
{
#ifdef CONFIG_ACPI_HOTPLUG_CPU
int action = UNINSTALL_NOTIFY_HANDLER;
acpi_walk_namespace(ACPI_TYPE_PROCESSOR,
ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX,
processor_walk_namespace_cb, NULL, &action, NULL);
#endif
unregister_hotcpu_notifier(&acpi_cpu_notifier);
}
static int __init acpi_processor_init(void)
{
int result = 0;
if (acpi_disabled)
return 0;
memset(&errata, 0, sizeof(errata));
result = acpi_bus_register_driver(&acpi_processor_driver);
if (result < 0)
return result;
acpi_processor_install_hotplug_notify();
acpi_thermal_cpufreq_init();
acpi_processor_ppc_init();
acpi_processor_throttling_init();
return 0;
}
static void __exit acpi_processor_exit(void)
{
if (acpi_disabled)
return;
acpi_processor_ppc_exit();
acpi_thermal_cpufreq_exit();
acpi_processor_uninstall_hotplug_notify();
acpi_bus_unregister_driver(&acpi_processor_driver);
cpuidle_unregister_driver(&acpi_idle_driver);
return;
}
