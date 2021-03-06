phys_addr_t acpi_pci_root_get_mcfg_addr(acpi_handle handle)
{
acpi_status status = AE_NOT_EXIST;
unsigned long long mcfg_addr;
if (handle)
status = acpi_evaluate_integer(handle, METHOD_NAME__CBA,
NULL, &mcfg_addr);
if (ACPI_FAILURE(status))
return 0;
return (phys_addr_t)mcfg_addr;
}
static acpi_status decode_type0_hpx_record(union acpi_object *record,
struct hotplug_params *hpx)
{
int i;
union acpi_object *fields = record->package.elements;
u32 revision = fields[1].integer.value;
switch (revision) {
case 1:
if (record->package.count != 6)
return AE_ERROR;
for (i = 2; i < 6; i++)
if (fields[i].type != ACPI_TYPE_INTEGER)
return AE_ERROR;
hpx->t0 = &hpx->type0_data;
hpx->t0->revision = revision;
hpx->t0->cache_line_size = fields[2].integer.value;
hpx->t0->latency_timer = fields[3].integer.value;
hpx->t0->enable_serr = fields[4].integer.value;
hpx->t0->enable_perr = fields[5].integer.value;
break;
default:
printk(KERN_WARNING
"%s: Type 0 Revision %d record not supported\n",
__func__, revision);
return AE_ERROR;
}
return AE_OK;
}
static acpi_status decode_type1_hpx_record(union acpi_object *record,
struct hotplug_params *hpx)
{
int i;
union acpi_object *fields = record->package.elements;
u32 revision = fields[1].integer.value;
switch (revision) {
case 1:
if (record->package.count != 5)
return AE_ERROR;
for (i = 2; i < 5; i++)
if (fields[i].type != ACPI_TYPE_INTEGER)
return AE_ERROR;
hpx->t1 = &hpx->type1_data;
hpx->t1->revision = revision;
hpx->t1->max_mem_read = fields[2].integer.value;
hpx->t1->avg_max_split = fields[3].integer.value;
hpx->t1->tot_max_split = fields[4].integer.value;
break;
default:
printk(KERN_WARNING
"%s: Type 1 Revision %d record not supported\n",
__func__, revision);
return AE_ERROR;
}
return AE_OK;
}
static acpi_status decode_type2_hpx_record(union acpi_object *record,
struct hotplug_params *hpx)
{
int i;
union acpi_object *fields = record->package.elements;
u32 revision = fields[1].integer.value;
switch (revision) {
case 1:
if (record->package.count != 18)
return AE_ERROR;
for (i = 2; i < 18; i++)
if (fields[i].type != ACPI_TYPE_INTEGER)
return AE_ERROR;
hpx->t2 = &hpx->type2_data;
hpx->t2->revision = revision;
hpx->t2->unc_err_mask_and = fields[2].integer.value;
hpx->t2->unc_err_mask_or = fields[3].integer.value;
hpx->t2->unc_err_sever_and = fields[4].integer.value;
hpx->t2->unc_err_sever_or = fields[5].integer.value;
hpx->t2->cor_err_mask_and = fields[6].integer.value;
hpx->t2->cor_err_mask_or = fields[7].integer.value;
hpx->t2->adv_err_cap_and = fields[8].integer.value;
hpx->t2->adv_err_cap_or = fields[9].integer.value;
hpx->t2->pci_exp_devctl_and = fields[10].integer.value;
hpx->t2->pci_exp_devctl_or = fields[11].integer.value;
hpx->t2->pci_exp_lnkctl_and = fields[12].integer.value;
hpx->t2->pci_exp_lnkctl_or = fields[13].integer.value;
hpx->t2->sec_unc_err_sever_and = fields[14].integer.value;
hpx->t2->sec_unc_err_sever_or = fields[15].integer.value;
hpx->t2->sec_unc_err_mask_and = fields[16].integer.value;
hpx->t2->sec_unc_err_mask_or = fields[17].integer.value;
break;
default:
printk(KERN_WARNING
"%s: Type 2 Revision %d record not supported\n",
__func__, revision);
return AE_ERROR;
}
return AE_OK;
}
static acpi_status acpi_run_hpx(acpi_handle handle, struct hotplug_params *hpx)
{
acpi_status status;
struct acpi_buffer buffer = {ACPI_ALLOCATE_BUFFER, NULL};
union acpi_object *package, *record, *fields;
u32 type;
int i;
memset(hpx, 0, sizeof(struct hotplug_params));
status = acpi_evaluate_object(handle, "_HPX", NULL, &buffer);
if (ACPI_FAILURE(status))
return status;
package = (union acpi_object *)buffer.pointer;
if (package->type != ACPI_TYPE_PACKAGE) {
status = AE_ERROR;
goto exit;
}
for (i = 0; i < package->package.count; i++) {
record = &package->package.elements[i];
if (record->type != ACPI_TYPE_PACKAGE) {
status = AE_ERROR;
goto exit;
}
fields = record->package.elements;
if (fields[0].type != ACPI_TYPE_INTEGER ||
fields[1].type != ACPI_TYPE_INTEGER) {
status = AE_ERROR;
goto exit;
}
type = fields[0].integer.value;
switch (type) {
case 0:
status = decode_type0_hpx_record(record, hpx);
if (ACPI_FAILURE(status))
goto exit;
break;
case 1:
status = decode_type1_hpx_record(record, hpx);
if (ACPI_FAILURE(status))
goto exit;
break;
case 2:
status = decode_type2_hpx_record(record, hpx);
if (ACPI_FAILURE(status))
goto exit;
break;
default:
printk(KERN_ERR "%s: Type %d record not supported\n",
__func__, type);
status = AE_ERROR;
goto exit;
}
}
exit:
kfree(buffer.pointer);
return status;
}
static acpi_status acpi_run_hpp(acpi_handle handle, struct hotplug_params *hpp)
{
acpi_status status;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *package, *fields;
int i;
memset(hpp, 0, sizeof(struct hotplug_params));
status = acpi_evaluate_object(handle, "_HPP", NULL, &buffer);
if (ACPI_FAILURE(status))
return status;
package = (union acpi_object *) buffer.pointer;
if (package->type != ACPI_TYPE_PACKAGE ||
package->package.count != 4) {
status = AE_ERROR;
goto exit;
}
fields = package->package.elements;
for (i = 0; i < 4; i++) {
if (fields[i].type != ACPI_TYPE_INTEGER) {
status = AE_ERROR;
goto exit;
}
}
hpp->t0 = &hpp->type0_data;
hpp->t0->revision = 1;
hpp->t0->cache_line_size = fields[0].integer.value;
hpp->t0->latency_timer = fields[1].integer.value;
hpp->t0->enable_serr = fields[2].integer.value;
hpp->t0->enable_perr = fields[3].integer.value;
exit:
kfree(buffer.pointer);
return status;
}
int pci_get_hp_params(struct pci_dev *dev, struct hotplug_params *hpp)
{
acpi_status status;
acpi_handle handle, phandle;
struct pci_bus *pbus;
if (acpi_pci_disabled)
return -ENODEV;
handle = NULL;
for (pbus = dev->bus; pbus; pbus = pbus->parent) {
handle = acpi_pci_get_bridge_handle(pbus);
if (handle)
break;
}
while (handle) {
status = acpi_run_hpx(handle, hpp);
if (ACPI_SUCCESS(status))
return 0;
status = acpi_run_hpp(handle, hpp);
if (ACPI_SUCCESS(status))
return 0;
if (acpi_is_root_bridge(handle))
break;
status = acpi_get_parent(handle, &phandle);
if (ACPI_FAILURE(status))
break;
handle = phandle;
}
return -ENODEV;
}
static void pci_acpi_wake_bus(struct work_struct *work)
{
struct acpi_device *adev;
struct acpi_pci_root *root;
adev = container_of(work, struct acpi_device, wakeup.context.work);
root = acpi_driver_data(adev);
pci_pme_wakeup_bus(root->bus);
}
static void pci_acpi_wake_dev(struct work_struct *work)
{
struct acpi_device_wakeup_context *context;
struct pci_dev *pci_dev;
context = container_of(work, struct acpi_device_wakeup_context, work);
pci_dev = to_pci_dev(context->dev);
if (pci_dev->pme_poll)
pci_dev->pme_poll = false;
if (pci_dev->current_state == PCI_D3cold) {
pci_wakeup_event(pci_dev);
pm_runtime_resume(&pci_dev->dev);
return;
}
if (pci_dev->pme_support)
pci_check_pme_status(pci_dev);
pci_wakeup_event(pci_dev);
pm_runtime_resume(&pci_dev->dev);
pci_pme_wakeup_bus(pci_dev->subordinate);
}
acpi_status pci_acpi_add_bus_pm_notifier(struct acpi_device *dev)
{
return acpi_add_pm_notifier(dev, NULL, pci_acpi_wake_bus);
}
acpi_status pci_acpi_add_pm_notifier(struct acpi_device *dev,
struct pci_dev *pci_dev)
{
return acpi_add_pm_notifier(dev, &pci_dev->dev, pci_acpi_wake_dev);
}
static pci_power_t acpi_pci_choose_state(struct pci_dev *pdev)
{
int acpi_state, d_max;
if (pdev->no_d3cold)
d_max = ACPI_STATE_D3_HOT;
else
d_max = ACPI_STATE_D3_COLD;
acpi_state = acpi_pm_device_sleep_state(&pdev->dev, NULL, d_max);
if (acpi_state < 0)
return PCI_POWER_ERROR;
switch (acpi_state) {
case ACPI_STATE_D0:
return PCI_D0;
case ACPI_STATE_D1:
return PCI_D1;
case ACPI_STATE_D2:
return PCI_D2;
case ACPI_STATE_D3_HOT:
return PCI_D3hot;
case ACPI_STATE_D3_COLD:
return PCI_D3cold;
}
return PCI_POWER_ERROR;
}
static bool acpi_pci_power_manageable(struct pci_dev *dev)
{
struct acpi_device *adev = ACPI_COMPANION(&dev->dev);
return adev ? acpi_device_power_manageable(adev) : false;
}
static int acpi_pci_set_power_state(struct pci_dev *dev, pci_power_t state)
{
struct acpi_device *adev = ACPI_COMPANION(&dev->dev);
static const u8 state_conv[] = {
[PCI_D0] = ACPI_STATE_D0,
[PCI_D1] = ACPI_STATE_D1,
[PCI_D2] = ACPI_STATE_D2,
[PCI_D3hot] = ACPI_STATE_D3_HOT,
[PCI_D3cold] = ACPI_STATE_D3_COLD,
};
int error = -EINVAL;
if (!adev || acpi_has_method(adev->handle, "_EJ0"))
return -ENODEV;
switch (state) {
case PCI_D3cold:
if (dev_pm_qos_flags(&dev->dev, PM_QOS_FLAG_NO_POWER_OFF) ==
PM_QOS_FLAGS_ALL) {
error = -EBUSY;
break;
}
case PCI_D0:
case PCI_D1:
case PCI_D2:
case PCI_D3hot:
error = acpi_device_set_power(adev, state_conv[state]);
}
if (!error)
dev_dbg(&dev->dev, "power state changed by ACPI to %s\n",
acpi_power_state_string(state_conv[state]));
return error;
}
static bool acpi_pci_can_wakeup(struct pci_dev *dev)
{
struct acpi_device *adev = ACPI_COMPANION(&dev->dev);
return adev ? acpi_device_can_wakeup(adev) : false;
}
static void acpi_pci_propagate_wakeup_enable(struct pci_bus *bus, bool enable)
{
while (bus->parent) {
if (!acpi_pm_device_sleep_wake(&bus->self->dev, enable))
return;
bus = bus->parent;
}
if (bus->bridge)
acpi_pm_device_sleep_wake(bus->bridge, enable);
}
static int acpi_pci_sleep_wake(struct pci_dev *dev, bool enable)
{
if (acpi_pci_can_wakeup(dev))
return acpi_pm_device_sleep_wake(&dev->dev, enable);
acpi_pci_propagate_wakeup_enable(dev->bus, enable);
return 0;
}
static void acpi_pci_propagate_run_wake(struct pci_bus *bus, bool enable)
{
while (bus->parent) {
struct pci_dev *bridge = bus->self;
if (bridge->pme_interrupt)
return;
if (!acpi_pm_device_run_wake(&bridge->dev, enable))
return;
bus = bus->parent;
}
if (bus->bridge)
acpi_pm_device_run_wake(bus->bridge, enable);
}
static int acpi_pci_run_wake(struct pci_dev *dev, bool enable)
{
if (dev->pme_interrupt && !dev->runtime_d3cold)
return 0;
if (!acpi_pm_device_run_wake(&dev->dev, enable))
return 0;
acpi_pci_propagate_run_wake(dev->bus, enable);
return 0;
}
static bool acpi_pci_need_resume(struct pci_dev *dev)
{
struct acpi_device *adev = ACPI_COMPANION(&dev->dev);
if (!adev || !acpi_device_power_manageable(adev))
return false;
if (device_may_wakeup(&dev->dev) != !!adev->wakeup.prepare_count)
return true;
if (acpi_target_system_state() == ACPI_STATE_S0)
return false;
return !!adev->power.flags.dsw_present;
}
void acpi_pci_add_bus(struct pci_bus *bus)
{
union acpi_object *obj;
struct pci_host_bridge *bridge;
if (acpi_pci_disabled || !bus->bridge)
return;
acpi_pci_slot_enumerate(bus);
acpiphp_enumerate_slots(bus);
if (!pci_is_root_bus(bus))
return;
obj = acpi_evaluate_dsm(ACPI_HANDLE(bus->bridge), pci_acpi_dsm_uuid, 3,
RESET_DELAY_DSM, NULL);
if (!obj)
return;
if (obj->type == ACPI_TYPE_INTEGER && obj->integer.value == 1) {
bridge = pci_find_host_bridge(bus);
bridge->ignore_reset_delay = 1;
}
ACPI_FREE(obj);
}
void acpi_pci_remove_bus(struct pci_bus *bus)
{
if (acpi_pci_disabled || !bus->bridge)
return;
acpiphp_remove_slots(bus);
acpi_pci_slot_remove(bus);
}
static struct acpi_device *acpi_pci_find_companion(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
bool check_children;
u64 addr;
check_children = pci_is_bridge(pci_dev);
addr = (PCI_SLOT(pci_dev->devfn) << 16) | PCI_FUNC(pci_dev->devfn);
return acpi_find_child_device(ACPI_COMPANION(dev->parent), addr,
check_children);
}
static void pci_acpi_optimize_delay(struct pci_dev *pdev,
acpi_handle handle)
{
struct pci_host_bridge *bridge = pci_find_host_bridge(pdev->bus);
int value;
union acpi_object *obj, *elements;
if (bridge->ignore_reset_delay)
pdev->d3cold_delay = 0;
obj = acpi_evaluate_dsm(handle, pci_acpi_dsm_uuid, 3,
FUNCTION_DELAY_DSM, NULL);
if (!obj)
return;
if (obj->type == ACPI_TYPE_PACKAGE && obj->package.count == 5) {
elements = obj->package.elements;
if (elements[0].type == ACPI_TYPE_INTEGER) {
value = (int)elements[0].integer.value / 1000;
if (value < PCI_PM_D3COLD_WAIT)
pdev->d3cold_delay = value;
}
if (elements[3].type == ACPI_TYPE_INTEGER) {
value = (int)elements[3].integer.value / 1000;
if (value < PCI_PM_D3_WAIT)
pdev->d3_delay = value;
}
}
ACPI_FREE(obj);
}
static void pci_acpi_setup(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct acpi_device *adev = ACPI_COMPANION(dev);
if (!adev)
return;
pci_acpi_optimize_delay(pci_dev, adev->handle);
pci_acpi_add_pm_notifier(adev, pci_dev);
if (!adev->wakeup.flags.valid)
return;
device_set_wakeup_capable(dev, true);
acpi_pci_sleep_wake(pci_dev, false);
if (adev->wakeup.flags.run_wake)
device_set_run_wake(dev, true);
}
static void pci_acpi_cleanup(struct device *dev)
{
struct acpi_device *adev = ACPI_COMPANION(dev);
if (!adev)
return;
pci_acpi_remove_pm_notifier(adev);
if (adev->wakeup.flags.valid) {
device_set_wakeup_capable(dev, false);
device_set_run_wake(dev, false);
}
}
static bool pci_acpi_bus_match(struct device *dev)
{
return dev_is_pci(dev);
}
struct irq_domain *pci_host_bridge_acpi_msi_domain(struct pci_bus *bus)
{
struct fwnode_handle *fwnode;
if (!pci_msi_get_fwnode_cb)
return NULL;
fwnode = pci_msi_get_fwnode_cb(&bus->dev);
if (!fwnode)
return NULL;
return irq_find_matching_fwnode(fwnode, DOMAIN_BUS_PCI_MSI);
}
static int __init acpi_pci_init(void)
{
int ret;
if (acpi_gbl_FADT.boot_flags & ACPI_FADT_NO_MSI) {
pr_info("ACPI FADT declares the system doesn't support MSI, so disable it\n");
pci_no_msi();
}
if (acpi_gbl_FADT.boot_flags & ACPI_FADT_NO_ASPM) {
pr_info("ACPI FADT declares the system doesn't support PCIe ASPM, so disable it\n");
pcie_no_aspm();
}
ret = register_acpi_bus_type(&acpi_pci_bus);
if (ret)
return 0;
pci_set_platform_pm(&acpi_pci_platform_pm);
acpi_pci_slot_init();
acpiphp_init();
return 0;
}
