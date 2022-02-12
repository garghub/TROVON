static inline const char *eeh_pcid_name(struct pci_dev *pdev)
{
if (pdev && pdev->dev.driver)
return pdev->dev.driver->name;
return "";
}
static inline struct pci_driver *eeh_pcid_get(struct pci_dev *pdev)
{
if (!pdev || !pdev->driver)
return NULL;
if (!try_module_get(pdev->driver->driver.owner))
return NULL;
return pdev->driver;
}
static inline void eeh_pcid_put(struct pci_dev *pdev)
{
if (!pdev || !pdev->driver)
return;
module_put(pdev->driver->driver.owner);
}
static void eeh_disable_irq(struct pci_dev *dev)
{
struct eeh_dev *edev = pci_dev_to_eeh_dev(dev);
if (dev->msi_enabled || dev->msix_enabled)
return;
if (!irq_has_action(dev->irq))
return;
edev->mode |= EEH_DEV_IRQ_DISABLED;
disable_irq_nosync(dev->irq);
}
static void eeh_enable_irq(struct pci_dev *dev)
{
struct eeh_dev *edev = pci_dev_to_eeh_dev(dev);
if ((edev->mode) & EEH_DEV_IRQ_DISABLED) {
edev->mode &= ~EEH_DEV_IRQ_DISABLED;
if (irqd_irq_disabled(irq_get_irq_data(dev->irq)))
enable_irq(dev->irq);
}
}
static bool eeh_dev_removed(struct eeh_dev *edev)
{
if (!edev || (edev->mode & EEH_DEV_REMOVED))
return true;
return false;
}
static void *eeh_report_error(void *data, void *userdata)
{
struct eeh_dev *edev = (struct eeh_dev *)data;
struct pci_dev *dev = eeh_dev_to_pci_dev(edev);
enum pci_ers_result rc, *res = userdata;
struct pci_driver *driver;
if (!dev || eeh_dev_removed(edev))
return NULL;
dev->error_state = pci_channel_io_frozen;
driver = eeh_pcid_get(dev);
if (!driver) return NULL;
eeh_disable_irq(dev);
if (!driver->err_handler ||
!driver->err_handler->error_detected) {
eeh_pcid_put(dev);
return NULL;
}
rc = driver->err_handler->error_detected(dev, pci_channel_io_frozen);
if (rc == PCI_ERS_RESULT_NEED_RESET) *res = rc;
if (*res == PCI_ERS_RESULT_NONE) *res = rc;
eeh_pcid_put(dev);
return NULL;
}
static void *eeh_report_mmio_enabled(void *data, void *userdata)
{
struct eeh_dev *edev = (struct eeh_dev *)data;
struct pci_dev *dev = eeh_dev_to_pci_dev(edev);
enum pci_ers_result rc, *res = userdata;
struct pci_driver *driver;
if (!dev || eeh_dev_removed(edev))
return NULL;
driver = eeh_pcid_get(dev);
if (!driver) return NULL;
if (!driver->err_handler ||
!driver->err_handler->mmio_enabled ||
(edev->mode & EEH_DEV_NO_HANDLER)) {
eeh_pcid_put(dev);
return NULL;
}
rc = driver->err_handler->mmio_enabled(dev);
if (rc == PCI_ERS_RESULT_NEED_RESET) *res = rc;
if (*res == PCI_ERS_RESULT_NONE) *res = rc;
eeh_pcid_put(dev);
return NULL;
}
static void *eeh_report_reset(void *data, void *userdata)
{
struct eeh_dev *edev = (struct eeh_dev *)data;
struct pci_dev *dev = eeh_dev_to_pci_dev(edev);
enum pci_ers_result rc, *res = userdata;
struct pci_driver *driver;
if (!dev || eeh_dev_removed(edev))
return NULL;
dev->error_state = pci_channel_io_normal;
driver = eeh_pcid_get(dev);
if (!driver) return NULL;
eeh_enable_irq(dev);
if (!driver->err_handler ||
!driver->err_handler->slot_reset ||
(edev->mode & EEH_DEV_NO_HANDLER)) {
eeh_pcid_put(dev);
return NULL;
}
rc = driver->err_handler->slot_reset(dev);
if ((*res == PCI_ERS_RESULT_NONE) ||
(*res == PCI_ERS_RESULT_RECOVERED)) *res = rc;
if (*res == PCI_ERS_RESULT_DISCONNECT &&
rc == PCI_ERS_RESULT_NEED_RESET) *res = rc;
eeh_pcid_put(dev);
return NULL;
}
static void *eeh_report_resume(void *data, void *userdata)
{
struct eeh_dev *edev = (struct eeh_dev *)data;
struct pci_dev *dev = eeh_dev_to_pci_dev(edev);
struct pci_driver *driver;
if (!dev || eeh_dev_removed(edev))
return NULL;
dev->error_state = pci_channel_io_normal;
driver = eeh_pcid_get(dev);
if (!driver) return NULL;
eeh_enable_irq(dev);
if (!driver->err_handler ||
!driver->err_handler->resume ||
(edev->mode & EEH_DEV_NO_HANDLER)) {
edev->mode &= ~EEH_DEV_NO_HANDLER;
eeh_pcid_put(dev);
return NULL;
}
driver->err_handler->resume(dev);
eeh_pcid_put(dev);
return NULL;
}
static void *eeh_report_failure(void *data, void *userdata)
{
struct eeh_dev *edev = (struct eeh_dev *)data;
struct pci_dev *dev = eeh_dev_to_pci_dev(edev);
struct pci_driver *driver;
if (!dev || eeh_dev_removed(edev))
return NULL;
dev->error_state = pci_channel_io_perm_failure;
driver = eeh_pcid_get(dev);
if (!driver) return NULL;
eeh_disable_irq(dev);
if (!driver->err_handler ||
!driver->err_handler->error_detected) {
eeh_pcid_put(dev);
return NULL;
}
driver->err_handler->error_detected(dev, pci_channel_io_perm_failure);
eeh_pcid_put(dev);
return NULL;
}
static void *eeh_rmv_device(void *data, void *userdata)
{
struct pci_driver *driver;
struct eeh_dev *edev = (struct eeh_dev *)data;
struct pci_dev *dev = eeh_dev_to_pci_dev(edev);
int *removed = (int *)userdata;
if (!dev || (dev->hdr_type & PCI_HEADER_TYPE_BRIDGE))
return NULL;
if (eeh_dev_removed(edev))
return NULL;
driver = eeh_pcid_get(dev);
if (driver) {
eeh_pcid_put(dev);
if (driver->err_handler)
return NULL;
}
pr_debug("EEH: Removing %s without EEH sensitive driver\n",
pci_name(dev));
edev->bus = dev->bus;
edev->mode |= EEH_DEV_DISCONNECTED;
(*removed)++;
pci_lock_rescan_remove();
pci_stop_and_remove_bus_device(dev);
pci_unlock_rescan_remove();
return NULL;
}
static void *eeh_pe_detach_dev(void *data, void *userdata)
{
struct eeh_pe *pe = (struct eeh_pe *)data;
struct eeh_dev *edev, *tmp;
eeh_pe_for_each_dev(pe, edev, tmp) {
if (!(edev->mode & EEH_DEV_DISCONNECTED))
continue;
edev->mode &= ~(EEH_DEV_DISCONNECTED | EEH_DEV_IRQ_DISABLED);
eeh_rmv_from_parent_pe(edev);
}
return NULL;
}
static void *__eeh_clear_pe_frozen_state(void *data, void *flag)
{
struct eeh_pe *pe = (struct eeh_pe *)data;
int i, rc;
for (i = 0; i < 3; i++) {
rc = eeh_pci_enable(pe, EEH_OPT_THAW_MMIO);
if (rc)
continue;
rc = eeh_pci_enable(pe, EEH_OPT_THAW_DMA);
if (!rc)
break;
}
if (rc) {
pr_warn("%s: Can't clear frozen PHB#%x-PE#%x (%d)\n",
__func__, pe->phb->global_number, pe->addr, rc);
return (void *)pe;
}
return NULL;
}
static int eeh_clear_pe_frozen_state(struct eeh_pe *pe)
{
void *rc;
rc = eeh_pe_traverse(pe, __eeh_clear_pe_frozen_state, NULL);
if (!rc)
eeh_pe_state_clear(pe, EEH_PE_ISOLATED);
return rc ? -EIO : 0;
}
static int eeh_reset_device(struct eeh_pe *pe, struct pci_bus *bus)
{
struct pci_bus *frozen_bus = eeh_pe_bus_get(pe);
struct timeval tstamp;
int cnt, rc, removed = 0;
cnt = pe->freeze_count;
tstamp = pe->tstamp;
eeh_pe_state_mark(pe, EEH_PE_KEEP);
if (bus) {
pci_lock_rescan_remove();
pcibios_remove_pci_devices(bus);
pci_unlock_rescan_remove();
} else if (frozen_bus) {
eeh_pe_dev_traverse(pe, eeh_rmv_device, &removed);
}
eeh_pe_state_mark(pe, EEH_PE_RESET);
rc = eeh_reset_pe(pe);
if (rc) {
eeh_pe_state_clear(pe, EEH_PE_RESET);
return rc;
}
pci_lock_rescan_remove();
eeh_ops->configure_bridge(pe);
eeh_pe_restore_bars(pe);
eeh_pe_state_clear(pe, EEH_PE_RESET);
rc = eeh_clear_pe_frozen_state(pe);
if (rc)
return rc;
if (bus) {
pr_info("EEH: Sleep 5s ahead of complete hotplug\n");
ssleep(5);
eeh_pe_traverse(pe, eeh_pe_detach_dev, NULL);
pcibios_add_pci_devices(bus);
} else if (frozen_bus && removed) {
pr_info("EEH: Sleep 5s ahead of partial hotplug\n");
ssleep(5);
eeh_pe_traverse(pe, eeh_pe_detach_dev, NULL);
pcibios_add_pci_devices(frozen_bus);
}
eeh_pe_state_clear(pe, EEH_PE_KEEP);
pe->tstamp = tstamp;
pe->freeze_count = cnt;
pci_unlock_rescan_remove();
return 0;
}
static void eeh_handle_normal_event(struct eeh_pe *pe)
{
struct pci_bus *frozen_bus;
int rc = 0;
enum pci_ers_result result = PCI_ERS_RESULT_NONE;
frozen_bus = eeh_pe_bus_get(pe);
if (!frozen_bus) {
pr_err("%s: Cannot find PCI bus for PHB#%d-PE#%x\n",
__func__, pe->phb->global_number, pe->addr);
return;
}
eeh_pe_update_time_stamp(pe);
pe->freeze_count++;
if (pe->freeze_count > EEH_MAX_ALLOWED_FREEZES)
goto excess_failures;
pr_warn("EEH: This PCI device has failed %d times in the last hour\n",
pe->freeze_count);
pr_info("EEH: Notify device drivers to shutdown\n");
eeh_pe_dev_traverse(pe, eeh_report_error, &result);
rc = eeh_ops->wait_state(pe, MAX_WAIT_FOR_RECOVERY*1000);
if (rc < 0 || rc == EEH_STATE_NOT_SUPPORT) {
pr_warn("EEH: Permanent failure\n");
goto hard_fail;
}
pr_info("EEH: Collect temporary log\n");
eeh_slot_error_detail(pe, EEH_LOG_TEMP);
if (result == PCI_ERS_RESULT_NONE) {
pr_info("EEH: Reset with hotplug activity\n");
rc = eeh_reset_device(pe, frozen_bus);
if (rc) {
pr_warn("%s: Unable to reset, err=%d\n",
__func__, rc);
goto hard_fail;
}
}
if (result == PCI_ERS_RESULT_CAN_RECOVER) {
pr_info("EEH: Enable I/O for affected devices\n");
rc = eeh_pci_enable(pe, EEH_OPT_THAW_MMIO);
if (rc < 0)
goto hard_fail;
if (rc) {
result = PCI_ERS_RESULT_NEED_RESET;
} else {
pr_info("EEH: Notify device drivers to resume I/O\n");
eeh_pe_dev_traverse(pe, eeh_report_mmio_enabled, &result);
}
}
if (result == PCI_ERS_RESULT_CAN_RECOVER) {
pr_info("EEH: Enabled DMA for affected devices\n");
rc = eeh_pci_enable(pe, EEH_OPT_THAW_DMA);
if (rc < 0)
goto hard_fail;
if (rc) {
result = PCI_ERS_RESULT_NEED_RESET;
} else {
eeh_pe_state_clear(pe, EEH_PE_ISOLATED);
result = PCI_ERS_RESULT_RECOVERED;
}
}
if (result == PCI_ERS_RESULT_DISCONNECT) {
pr_warn("EEH: Device driver gave up\n");
goto hard_fail;
}
if (result == PCI_ERS_RESULT_NEED_RESET) {
pr_info("EEH: Reset without hotplug activity\n");
rc = eeh_reset_device(pe, NULL);
if (rc) {
pr_warn("%s: Cannot reset, err=%d\n",
__func__, rc);
goto hard_fail;
}
pr_info("EEH: Notify device drivers "
"the completion of reset\n");
result = PCI_ERS_RESULT_NONE;
eeh_pe_dev_traverse(pe, eeh_report_reset, &result);
}
if ((result != PCI_ERS_RESULT_RECOVERED) &&
(result != PCI_ERS_RESULT_NONE)) {
pr_warn("EEH: Not recovered\n");
goto hard_fail;
}
pr_info("EEH: Notify device driver to resume\n");
eeh_pe_dev_traverse(pe, eeh_report_resume, NULL);
return;
excess_failures:
pr_err("EEH: PHB#%d-PE#%x has failed %d times in the\n"
"last hour and has been permanently disabled.\n"
"Please try reseating or replacing it.\n",
pe->phb->global_number, pe->addr,
pe->freeze_count);
goto perm_error;
hard_fail:
pr_err("EEH: Unable to recover from failure from PHB#%d-PE#%x.\n"
"Please try reseating or replacing it\n",
pe->phb->global_number, pe->addr);
perm_error:
eeh_slot_error_detail(pe, EEH_LOG_PERM);
eeh_pe_dev_traverse(pe, eeh_report_failure, NULL);
pe->freeze_count = EEH_MAX_ALLOWED_FREEZES + 1;
if (frozen_bus) {
eeh_pe_dev_mode_mark(pe, EEH_DEV_REMOVED);
pci_lock_rescan_remove();
pcibios_remove_pci_devices(frozen_bus);
pci_unlock_rescan_remove();
}
}
static void eeh_handle_special_event(void)
{
struct eeh_pe *pe, *phb_pe;
struct pci_bus *bus;
struct pci_controller *hose;
unsigned long flags;
int rc;
do {
rc = eeh_ops->next_error(&pe);
switch (rc) {
case EEH_NEXT_ERR_DEAD_IOC:
eeh_serialize_lock(&flags);
eeh_remove_event(NULL, true);
list_for_each_entry(hose, &hose_list, list_node) {
phb_pe = eeh_phb_pe_get(hose);
if (!phb_pe) continue;
eeh_pe_state_mark(phb_pe, EEH_PE_ISOLATED);
}
eeh_serialize_unlock(flags);
break;
case EEH_NEXT_ERR_FROZEN_PE:
case EEH_NEXT_ERR_FENCED_PHB:
case EEH_NEXT_ERR_DEAD_PHB:
eeh_serialize_lock(&flags);
eeh_remove_event(pe, true);
if (rc == EEH_NEXT_ERR_DEAD_PHB)
eeh_pe_state_mark(pe, EEH_PE_ISOLATED);
else
eeh_pe_state_mark(pe,
EEH_PE_ISOLATED | EEH_PE_RECOVERING);
eeh_serialize_unlock(flags);
break;
case EEH_NEXT_ERR_NONE:
return;
default:
pr_warn("%s: Invalid value %d from next_error()\n",
__func__, rc);
return;
}
if (rc == EEH_NEXT_ERR_FROZEN_PE ||
rc == EEH_NEXT_ERR_FENCED_PHB) {
eeh_handle_normal_event(pe);
eeh_pe_state_clear(pe, EEH_PE_RECOVERING);
} else {
pci_lock_rescan_remove();
list_for_each_entry(hose, &hose_list, list_node) {
phb_pe = eeh_phb_pe_get(hose);
if (!phb_pe ||
!(phb_pe->state & EEH_PE_ISOLATED) ||
(phb_pe->state & EEH_PE_RECOVERING))
continue;
bus = eeh_pe_bus_get(phb_pe);
eeh_pe_dev_traverse(pe,
eeh_report_failure, NULL);
pcibios_remove_pci_devices(bus);
}
pci_unlock_rescan_remove();
}
if (rc == EEH_NEXT_ERR_DEAD_IOC)
break;
} while (rc != EEH_NEXT_ERR_NONE);
}
void eeh_handle_event(struct eeh_pe *pe)
{
if (pe)
eeh_handle_normal_event(pe);
else
eeh_handle_special_event();
}
