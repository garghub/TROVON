int pci_add_dynid(struct pci_driver *drv,
unsigned int vendor, unsigned int device,
unsigned int subvendor, unsigned int subdevice,
unsigned int class, unsigned int class_mask,
unsigned long driver_data)
{
struct pci_dynid *dynid;
int retval;
dynid = kzalloc(sizeof(*dynid), GFP_KERNEL);
if (!dynid)
return -ENOMEM;
dynid->id.vendor = vendor;
dynid->id.device = device;
dynid->id.subvendor = subvendor;
dynid->id.subdevice = subdevice;
dynid->id.class = class;
dynid->id.class_mask = class_mask;
dynid->id.driver_data = driver_data;
spin_lock(&drv->dynids.lock);
list_add_tail(&dynid->node, &drv->dynids.list);
spin_unlock(&drv->dynids.lock);
retval = driver_attach(&drv->driver);
return retval;
}
static void pci_free_dynids(struct pci_driver *drv)
{
struct pci_dynid *dynid, *n;
spin_lock(&drv->dynids.lock);
list_for_each_entry_safe(dynid, n, &drv->dynids.list, node) {
list_del(&dynid->node);
kfree(dynid);
}
spin_unlock(&drv->dynids.lock);
}
static ssize_t store_new_id(struct device_driver *driver, const char *buf,
size_t count)
{
struct pci_driver *pdrv = to_pci_driver(driver);
const struct pci_device_id *ids = pdrv->id_table;
__u32 vendor, device, subvendor = PCI_ANY_ID,
subdevice = PCI_ANY_ID, class = 0, class_mask = 0;
unsigned long driver_data = 0;
int fields = 0;
int retval = 0;
fields = sscanf(buf, "%x %x %x %x %x %x %lx",
&vendor, &device, &subvendor, &subdevice,
&class, &class_mask, &driver_data);
if (fields < 2)
return -EINVAL;
if (fields != 7) {
struct pci_dev *pdev = kzalloc(sizeof(*pdev), GFP_KERNEL);
if (!pdev)
return -ENOMEM;
pdev->vendor = vendor;
pdev->device = device;
pdev->subsystem_vendor = subvendor;
pdev->subsystem_device = subdevice;
pdev->class = class;
if (pci_match_id(pdrv->id_table, pdev))
retval = -EEXIST;
kfree(pdev);
if (retval)
return retval;
}
if (ids) {
retval = -EINVAL;
while (ids->vendor || ids->subvendor || ids->class_mask) {
if (driver_data == ids->driver_data) {
retval = 0;
break;
}
ids++;
}
if (retval)
return retval;
}
retval = pci_add_dynid(pdrv, vendor, device, subvendor, subdevice,
class, class_mask, driver_data);
if (retval)
return retval;
return count;
}
static ssize_t store_remove_id(struct device_driver *driver, const char *buf,
size_t count)
{
struct pci_dynid *dynid, *n;
struct pci_driver *pdrv = to_pci_driver(driver);
__u32 vendor, device, subvendor = PCI_ANY_ID,
subdevice = PCI_ANY_ID, class = 0, class_mask = 0;
int fields = 0;
int retval = -ENODEV;
fields = sscanf(buf, "%x %x %x %x %x %x",
&vendor, &device, &subvendor, &subdevice,
&class, &class_mask);
if (fields < 2)
return -EINVAL;
spin_lock(&pdrv->dynids.lock);
list_for_each_entry_safe(dynid, n, &pdrv->dynids.list, node) {
struct pci_device_id *id = &dynid->id;
if ((id->vendor == vendor) &&
(id->device == device) &&
(subvendor == PCI_ANY_ID || id->subvendor == subvendor) &&
(subdevice == PCI_ANY_ID || id->subdevice == subdevice) &&
!((id->class ^ class) & class_mask)) {
list_del(&dynid->node);
kfree(dynid);
retval = 0;
break;
}
}
spin_unlock(&pdrv->dynids.lock);
if (retval)
return retval;
return count;
}
const struct pci_device_id *pci_match_id(const struct pci_device_id *ids,
struct pci_dev *dev)
{
if (ids) {
while (ids->vendor || ids->subvendor || ids->class_mask) {
if (pci_match_one_device(ids, dev))
return ids;
ids++;
}
}
return NULL;
}
static const struct pci_device_id *pci_match_device(struct pci_driver *drv,
struct pci_dev *dev)
{
struct pci_dynid *dynid;
const struct pci_device_id *found_id = NULL;
if (dev->driver_override && strcmp(dev->driver_override, drv->name))
return NULL;
spin_lock(&drv->dynids.lock);
list_for_each_entry(dynid, &drv->dynids.list, node) {
if (pci_match_one_device(&dynid->id, dev)) {
found_id = &dynid->id;
break;
}
}
spin_unlock(&drv->dynids.lock);
if (!found_id)
found_id = pci_match_id(drv->id_table, dev);
if (!found_id && dev->driver_override)
found_id = &pci_device_id_any;
return found_id;
}
static long local_pci_probe(void *_ddi)
{
struct drv_dev_and_id *ddi = _ddi;
struct pci_dev *pci_dev = ddi->dev;
struct pci_driver *pci_drv = ddi->drv;
struct device *dev = &pci_dev->dev;
int rc;
pm_runtime_get_sync(dev);
pci_dev->driver = pci_drv;
rc = pci_drv->probe(pci_dev, ddi->id);
if (!rc)
return rc;
if (rc < 0) {
pci_dev->driver = NULL;
pm_runtime_put_sync(dev);
return rc;
}
dev_warn(dev, "Driver probe function unexpectedly returned %d\n", rc);
return 0;
}
static int pci_call_probe(struct pci_driver *drv, struct pci_dev *dev,
const struct pci_device_id *id)
{
int error, node;
struct drv_dev_and_id ddi = { drv, dev, id };
node = dev_to_node(&dev->dev);
if (node >= 0 && node != numa_node_id()) {
int cpu;
get_online_cpus();
cpu = cpumask_any_and(cpumask_of_node(node), cpu_online_mask);
if (cpu < nr_cpu_ids)
error = work_on_cpu(cpu, local_pci_probe, &ddi);
else
error = local_pci_probe(&ddi);
put_online_cpus();
} else
error = local_pci_probe(&ddi);
return error;
}
static int __pci_device_probe(struct pci_driver *drv, struct pci_dev *pci_dev)
{
const struct pci_device_id *id;
int error = 0;
if (!pci_dev->driver && drv->probe) {
error = -ENODEV;
id = pci_match_device(drv, pci_dev);
if (id)
error = pci_call_probe(drv, pci_dev, id);
if (error >= 0)
error = 0;
}
return error;
}
static int pci_device_probe(struct device *dev)
{
int error = 0;
struct pci_driver *drv;
struct pci_dev *pci_dev;
drv = to_pci_driver(dev->driver);
pci_dev = to_pci_dev(dev);
pci_dev_get(pci_dev);
error = __pci_device_probe(drv, pci_dev);
if (error)
pci_dev_put(pci_dev);
return error;
}
static int pci_device_remove(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct pci_driver *drv = pci_dev->driver;
if (drv) {
if (drv->remove) {
pm_runtime_get_sync(dev);
drv->remove(pci_dev);
pm_runtime_put_noidle(dev);
}
pci_dev->driver = NULL;
}
pm_runtime_put_sync(dev);
if (pci_dev->current_state == PCI_D0)
pci_dev->current_state = PCI_UNKNOWN;
pci_dev_put(pci_dev);
return 0;
}
static void pci_device_shutdown(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct pci_driver *drv = pci_dev->driver;
pm_runtime_resume(dev);
if (drv && drv->shutdown)
drv->shutdown(pci_dev);
pci_msi_shutdown(pci_dev);
pci_msix_shutdown(pci_dev);
#ifdef CONFIG_KEXEC
if (kexec_in_progress && (pci_dev->current_state <= PCI_D3hot))
pci_clear_master(pci_dev);
#endif
}
static int pci_restore_standard_config(struct pci_dev *pci_dev)
{
pci_update_current_state(pci_dev, PCI_UNKNOWN);
if (pci_dev->current_state != PCI_D0) {
int error = pci_set_power_state(pci_dev, PCI_D0);
if (error)
return error;
}
pci_restore_state(pci_dev);
return 0;
}
static void pci_pm_default_resume_early(struct pci_dev *pci_dev)
{
pci_power_up(pci_dev);
pci_restore_state(pci_dev);
pci_fixup_device(pci_fixup_resume_early, pci_dev);
}
static void pci_pm_set_unknown_state(struct pci_dev *pci_dev)
{
if (pci_dev->current_state == PCI_D0)
pci_dev->current_state = PCI_UNKNOWN;
}
static int pci_pm_reenable_device(struct pci_dev *pci_dev)
{
int retval;
retval = pci_reenable_device(pci_dev);
if (pci_dev->is_busmaster)
pci_set_master(pci_dev);
return retval;
}
static int pci_legacy_suspend(struct device *dev, pm_message_t state)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct pci_driver *drv = pci_dev->driver;
if (drv && drv->suspend) {
pci_power_t prev = pci_dev->current_state;
int error;
error = drv->suspend(pci_dev, state);
suspend_report_result(drv->suspend, error);
if (error)
return error;
if (!pci_dev->state_saved && pci_dev->current_state != PCI_D0
&& pci_dev->current_state != PCI_UNKNOWN) {
WARN_ONCE(pci_dev->current_state != prev,
"PCI PM: Device state not saved by %pF\n",
drv->suspend);
}
}
pci_fixup_device(pci_fixup_suspend, pci_dev);
return 0;
}
static int pci_legacy_suspend_late(struct device *dev, pm_message_t state)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct pci_driver *drv = pci_dev->driver;
if (drv && drv->suspend_late) {
pci_power_t prev = pci_dev->current_state;
int error;
error = drv->suspend_late(pci_dev, state);
suspend_report_result(drv->suspend_late, error);
if (error)
return error;
if (!pci_dev->state_saved && pci_dev->current_state != PCI_D0
&& pci_dev->current_state != PCI_UNKNOWN) {
WARN_ONCE(pci_dev->current_state != prev,
"PCI PM: Device state not saved by %pF\n",
drv->suspend_late);
return 0;
}
}
if (!pci_dev->state_saved)
pci_save_state(pci_dev);
pci_pm_set_unknown_state(pci_dev);
return 0;
}
static int pci_legacy_resume_early(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct pci_driver *drv = pci_dev->driver;
return drv && drv->resume_early ?
drv->resume_early(pci_dev) : 0;
}
static int pci_legacy_resume(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct pci_driver *drv = pci_dev->driver;
pci_fixup_device(pci_fixup_resume, pci_dev);
return drv && drv->resume ?
drv->resume(pci_dev) : pci_pm_reenable_device(pci_dev);
}
static void pci_pm_default_resume(struct pci_dev *pci_dev)
{
pci_fixup_device(pci_fixup_resume, pci_dev);
if (!pci_has_subordinate(pci_dev))
pci_enable_wake(pci_dev, PCI_D0, false);
}
static void pci_pm_default_suspend(struct pci_dev *pci_dev)
{
if (!pci_has_subordinate(pci_dev))
pci_disable_enabled_device(pci_dev);
}
static bool pci_has_legacy_pm_support(struct pci_dev *pci_dev)
{
struct pci_driver *drv = pci_dev->driver;
bool ret = drv && (drv->suspend || drv->suspend_late || drv->resume
|| drv->resume_early);
WARN(ret && drv->driver.pm, "driver %s device %04x:%04x\n",
drv->name, pci_dev->vendor, pci_dev->device);
return ret;
}
static int pci_pm_prepare(struct device *dev)
{
struct device_driver *drv = dev->driver;
int error = 0;
if (dev->power.ignore_children)
pm_runtime_resume(dev);
if (drv && drv->pm && drv->pm->prepare)
error = drv->pm->prepare(dev);
return error;
}
static int pci_pm_suspend(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
if (pci_has_legacy_pm_support(pci_dev))
return pci_legacy_suspend(dev, PMSG_SUSPEND);
if (!pm) {
pci_pm_default_suspend(pci_dev);
goto Fixup;
}
pm_runtime_resume(dev);
pci_dev->state_saved = false;
if (pm->suspend) {
pci_power_t prev = pci_dev->current_state;
int error;
error = pm->suspend(dev);
suspend_report_result(pm->suspend, error);
if (error)
return error;
if (!pci_dev->state_saved && pci_dev->current_state != PCI_D0
&& pci_dev->current_state != PCI_UNKNOWN) {
WARN_ONCE(pci_dev->current_state != prev,
"PCI PM: State of device not saved by %pF\n",
pm->suspend);
}
}
Fixup:
pci_fixup_device(pci_fixup_suspend, pci_dev);
return 0;
}
static int pci_pm_suspend_noirq(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
if (pci_has_legacy_pm_support(pci_dev))
return pci_legacy_suspend_late(dev, PMSG_SUSPEND);
if (!pm) {
pci_save_state(pci_dev);
return 0;
}
if (pm->suspend_noirq) {
pci_power_t prev = pci_dev->current_state;
int error;
error = pm->suspend_noirq(dev);
suspend_report_result(pm->suspend_noirq, error);
if (error)
return error;
if (!pci_dev->state_saved && pci_dev->current_state != PCI_D0
&& pci_dev->current_state != PCI_UNKNOWN) {
WARN_ONCE(pci_dev->current_state != prev,
"PCI PM: State of device not saved by %pF\n",
pm->suspend_noirq);
return 0;
}
}
if (!pci_dev->state_saved) {
pci_save_state(pci_dev);
if (!pci_has_subordinate(pci_dev))
pci_prepare_to_sleep(pci_dev);
}
pci_pm_set_unknown_state(pci_dev);
if (pci_dev->class == PCI_CLASS_SERIAL_USB_EHCI)
pci_write_config_word(pci_dev, PCI_COMMAND, 0);
return 0;
}
static int pci_pm_resume_noirq(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct device_driver *drv = dev->driver;
int error = 0;
pci_pm_default_resume_early(pci_dev);
if (pci_has_legacy_pm_support(pci_dev))
return pci_legacy_resume_early(dev);
if (drv && drv->pm && drv->pm->resume_noirq)
error = drv->pm->resume_noirq(dev);
return error;
}
static int pci_pm_resume(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
int error = 0;
if (pci_dev->state_saved)
pci_restore_standard_config(pci_dev);
if (pci_has_legacy_pm_support(pci_dev))
return pci_legacy_resume(dev);
pci_pm_default_resume(pci_dev);
if (pm) {
if (pm->resume)
error = pm->resume(dev);
} else {
pci_pm_reenable_device(pci_dev);
}
return error;
}
static int pci_pm_freeze(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
if (pci_has_legacy_pm_support(pci_dev))
return pci_legacy_suspend(dev, PMSG_FREEZE);
if (!pm) {
pci_pm_default_suspend(pci_dev);
return 0;
}
pm_runtime_resume(dev);
pci_dev->state_saved = false;
if (pm->freeze) {
int error;
error = pm->freeze(dev);
suspend_report_result(pm->freeze, error);
if (error)
return error;
}
if (pcibios_pm_ops.freeze)
return pcibios_pm_ops.freeze(dev);
return 0;
}
static int pci_pm_freeze_noirq(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct device_driver *drv = dev->driver;
if (pci_has_legacy_pm_support(pci_dev))
return pci_legacy_suspend_late(dev, PMSG_FREEZE);
if (drv && drv->pm && drv->pm->freeze_noirq) {
int error;
error = drv->pm->freeze_noirq(dev);
suspend_report_result(drv->pm->freeze_noirq, error);
if (error)
return error;
}
if (!pci_dev->state_saved)
pci_save_state(pci_dev);
pci_pm_set_unknown_state(pci_dev);
if (pcibios_pm_ops.freeze_noirq)
return pcibios_pm_ops.freeze_noirq(dev);
return 0;
}
static int pci_pm_thaw_noirq(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct device_driver *drv = dev->driver;
int error = 0;
if (pcibios_pm_ops.thaw_noirq) {
error = pcibios_pm_ops.thaw_noirq(dev);
if (error)
return error;
}
if (pci_has_legacy_pm_support(pci_dev))
return pci_legacy_resume_early(dev);
pci_update_current_state(pci_dev, PCI_D0);
if (drv && drv->pm && drv->pm->thaw_noirq)
error = drv->pm->thaw_noirq(dev);
return error;
}
static int pci_pm_thaw(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
int error = 0;
if (pcibios_pm_ops.thaw) {
error = pcibios_pm_ops.thaw(dev);
if (error)
return error;
}
if (pci_has_legacy_pm_support(pci_dev))
return pci_legacy_resume(dev);
if (pm) {
if (pm->thaw)
error = pm->thaw(dev);
} else {
pci_pm_reenable_device(pci_dev);
}
pci_dev->state_saved = false;
return error;
}
static int pci_pm_poweroff(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
if (pci_has_legacy_pm_support(pci_dev))
return pci_legacy_suspend(dev, PMSG_HIBERNATE);
if (!pm) {
pci_pm_default_suspend(pci_dev);
goto Fixup;
}
pm_runtime_resume(dev);
pci_dev->state_saved = false;
if (pm->poweroff) {
int error;
error = pm->poweroff(dev);
suspend_report_result(pm->poweroff, error);
if (error)
return error;
}
Fixup:
pci_fixup_device(pci_fixup_suspend, pci_dev);
if (pcibios_pm_ops.poweroff)
return pcibios_pm_ops.poweroff(dev);
return 0;
}
static int pci_pm_poweroff_noirq(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct device_driver *drv = dev->driver;
if (pci_has_legacy_pm_support(to_pci_dev(dev)))
return pci_legacy_suspend_late(dev, PMSG_HIBERNATE);
if (!drv || !drv->pm)
return 0;
if (drv->pm->poweroff_noirq) {
int error;
error = drv->pm->poweroff_noirq(dev);
suspend_report_result(drv->pm->poweroff_noirq, error);
if (error)
return error;
}
if (!pci_dev->state_saved && !pci_has_subordinate(pci_dev))
pci_prepare_to_sleep(pci_dev);
if (pci_dev->class == PCI_CLASS_SERIAL_USB_EHCI)
pci_write_config_word(pci_dev, PCI_COMMAND, 0);
if (pcibios_pm_ops.poweroff_noirq)
return pcibios_pm_ops.poweroff_noirq(dev);
return 0;
}
static int pci_pm_restore_noirq(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct device_driver *drv = dev->driver;
int error = 0;
if (pcibios_pm_ops.restore_noirq) {
error = pcibios_pm_ops.restore_noirq(dev);
if (error)
return error;
}
pci_pm_default_resume_early(pci_dev);
if (pci_has_legacy_pm_support(pci_dev))
return pci_legacy_resume_early(dev);
if (drv && drv->pm && drv->pm->restore_noirq)
error = drv->pm->restore_noirq(dev);
return error;
}
static int pci_pm_restore(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
int error = 0;
if (pcibios_pm_ops.restore) {
error = pcibios_pm_ops.restore(dev);
if (error)
return error;
}
if (pci_dev->state_saved)
pci_restore_standard_config(pci_dev);
if (pci_has_legacy_pm_support(pci_dev))
return pci_legacy_resume(dev);
pci_pm_default_resume(pci_dev);
if (pm) {
if (pm->restore)
error = pm->restore(dev);
} else {
pci_pm_reenable_device(pci_dev);
}
return error;
}
static int pci_pm_runtime_suspend(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
pci_power_t prev = pci_dev->current_state;
int error;
if (!pci_dev->driver)
return 0;
if (!pm || !pm->runtime_suspend)
return -ENOSYS;
pci_dev->state_saved = false;
pci_dev->no_d3cold = false;
error = pm->runtime_suspend(dev);
suspend_report_result(pm->runtime_suspend, error);
if (error)
return error;
if (!pci_dev->d3cold_allowed)
pci_dev->no_d3cold = true;
pci_fixup_device(pci_fixup_suspend, pci_dev);
if (!pci_dev->state_saved && pci_dev->current_state != PCI_D0
&& pci_dev->current_state != PCI_UNKNOWN) {
WARN_ONCE(pci_dev->current_state != prev,
"PCI PM: State of device not saved by %pF\n",
pm->runtime_suspend);
return 0;
}
if (!pci_dev->state_saved) {
pci_save_state(pci_dev);
pci_finish_runtime_suspend(pci_dev);
}
return 0;
}
static int pci_pm_runtime_resume(struct device *dev)
{
int rc;
struct pci_dev *pci_dev = to_pci_dev(dev);
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
if (!pci_dev->driver)
return 0;
if (!pm || !pm->runtime_resume)
return -ENOSYS;
pci_restore_standard_config(pci_dev);
pci_fixup_device(pci_fixup_resume_early, pci_dev);
__pci_enable_wake(pci_dev, PCI_D0, true, false);
pci_fixup_device(pci_fixup_resume, pci_dev);
rc = pm->runtime_resume(dev);
pci_dev->runtime_d3cold = false;
return rc;
}
static int pci_pm_runtime_idle(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
int ret = 0;
if (!pci_dev->driver)
return 0;
if (!pm)
return -ENOSYS;
if (pm->runtime_idle)
ret = pm->runtime_idle(dev);
return ret;
}
int __pci_register_driver(struct pci_driver *drv, struct module *owner,
const char *mod_name)
{
drv->driver.name = drv->name;
drv->driver.bus = &pci_bus_type;
drv->driver.owner = owner;
drv->driver.mod_name = mod_name;
spin_lock_init(&drv->dynids.lock);
INIT_LIST_HEAD(&drv->dynids.list);
return driver_register(&drv->driver);
}
void pci_unregister_driver(struct pci_driver *drv)
{
driver_unregister(&drv->driver);
pci_free_dynids(drv);
}
struct pci_driver *pci_dev_driver(const struct pci_dev *dev)
{
if (dev->driver)
return dev->driver;
else {
int i;
for (i = 0; i <= PCI_ROM_RESOURCE; i++)
if (dev->resource[i].flags & IORESOURCE_BUSY)
return &pci_compat_driver;
}
return NULL;
}
static int pci_bus_match(struct device *dev, struct device_driver *drv)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct pci_driver *pci_drv;
const struct pci_device_id *found_id;
if (!pci_dev->match_driver)
return 0;
pci_drv = to_pci_driver(drv);
found_id = pci_match_device(pci_drv, pci_dev);
if (found_id)
return 1;
return 0;
}
struct pci_dev *pci_dev_get(struct pci_dev *dev)
{
if (dev)
get_device(&dev->dev);
return dev;
}
void pci_dev_put(struct pci_dev *dev)
{
if (dev)
put_device(&dev->dev);
}
static int pci_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct pci_dev *pdev;
if (!dev)
return -ENODEV;
pdev = to_pci_dev(dev);
if (add_uevent_var(env, "PCI_CLASS=%04X", pdev->class))
return -ENOMEM;
if (add_uevent_var(env, "PCI_ID=%04X:%04X", pdev->vendor, pdev->device))
return -ENOMEM;
if (add_uevent_var(env, "PCI_SUBSYS_ID=%04X:%04X", pdev->subsystem_vendor,
pdev->subsystem_device))
return -ENOMEM;
if (add_uevent_var(env, "PCI_SLOT_NAME=%s", pci_name(pdev)))
return -ENOMEM;
if (add_uevent_var(env, "MODALIAS=pci:v%08Xd%08Xsv%08Xsd%08Xbc%02Xsc%02Xi%02x",
pdev->vendor, pdev->device,
pdev->subsystem_vendor, pdev->subsystem_device,
(u8)(pdev->class >> 16), (u8)(pdev->class >> 8),
(u8)(pdev->class)))
return -ENOMEM;
return 0;
}
static int __init pci_driver_init(void)
{
return bus_register(&pci_bus_type);
}
