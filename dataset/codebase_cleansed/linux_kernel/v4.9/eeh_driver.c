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
static void *eeh_dev_save_state(void *data, void *userdata)
{
struct eeh_dev *edev = data;
struct pci_dev *pdev;
if (!edev)
return NULL;
if (edev->pe && (edev->pe->state & EEH_PE_CFG_RESTRICTED))
return NULL;
pdev = eeh_dev_to_pci_dev(edev);
if (!pdev)
return NULL;
pci_save_state(pdev);
return NULL;
}
static void *eeh_report_error(void *data, void *userdata)
{
struct eeh_dev *edev = (struct eeh_dev *)data;
struct pci_dev *dev = eeh_dev_to_pci_dev(edev);
enum pci_ers_result rc, *res = userdata;
struct pci_driver *driver;
if (!dev || eeh_dev_removed(edev) || eeh_pe_passed(edev->pe))
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
edev->in_error = true;
eeh_pcid_put(dev);
return NULL;
}
static void *eeh_report_mmio_enabled(void *data, void *userdata)
{
struct eeh_dev *edev = (struct eeh_dev *)data;
struct pci_dev *dev = eeh_dev_to_pci_dev(edev);
enum pci_ers_result rc, *res = userdata;
struct pci_driver *driver;
if (!dev || eeh_dev_removed(edev) || eeh_pe_passed(edev->pe))
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
if (!dev || eeh_dev_removed(edev) || eeh_pe_passed(edev->pe))
return NULL;
dev->error_state = pci_channel_io_normal;
driver = eeh_pcid_get(dev);
if (!driver) return NULL;
eeh_enable_irq(dev);
if (!driver->err_handler ||
!driver->err_handler->slot_reset ||
(edev->mode & EEH_DEV_NO_HANDLER) ||
(!edev->in_error)) {
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
static void *eeh_dev_restore_state(void *data, void *userdata)
{
struct eeh_dev *edev = data;
struct pci_dev *pdev;
if (!edev)
return NULL;
if (edev->pe && (edev->pe->state & EEH_PE_CFG_RESTRICTED)) {
if (list_is_last(&edev->list, &edev->pe->edevs))
eeh_pe_restore_bars(edev->pe);
return NULL;
}
pdev = eeh_dev_to_pci_dev(edev);
if (!pdev)
return NULL;
pci_restore_state(pdev);
return NULL;
}
static void *eeh_report_resume(void *data, void *userdata)
{
struct eeh_dev *edev = (struct eeh_dev *)data;
struct pci_dev *dev = eeh_dev_to_pci_dev(edev);
bool was_in_error;
struct pci_driver *driver;
if (!dev || eeh_dev_removed(edev) || eeh_pe_passed(edev->pe))
return NULL;
dev->error_state = pci_channel_io_normal;
driver = eeh_pcid_get(dev);
if (!driver) return NULL;
was_in_error = edev->in_error;
edev->in_error = false;
eeh_enable_irq(dev);
if (!driver->err_handler ||
!driver->err_handler->resume ||
(edev->mode & EEH_DEV_NO_HANDLER) || !was_in_error) {
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
if (!dev || eeh_dev_removed(edev) || eeh_pe_passed(edev->pe))
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
static void *eeh_add_virt_device(void *data, void *userdata)
{
struct pci_driver *driver;
struct eeh_dev *edev = (struct eeh_dev *)data;
struct pci_dev *dev = eeh_dev_to_pci_dev(edev);
struct pci_dn *pdn = eeh_dev_to_pdn(edev);
if (!(edev->physfn)) {
pr_warn("%s: EEH dev %04x:%02x:%02x.%01x not for VF\n",
__func__, edev->phb->global_number, pdn->busno,
PCI_SLOT(pdn->devfn), PCI_FUNC(pdn->devfn));
return NULL;
}
driver = eeh_pcid_get(dev);
if (driver) {
eeh_pcid_put(dev);
if (driver->err_handler)
return NULL;
}
#ifdef CONFIG_PPC_POWERNV
pci_iov_add_virtfn(edev->physfn, pdn->vf_index, 0);
#endif
return NULL;
}
static void *eeh_rmv_device(void *data, void *userdata)
{
struct pci_driver *driver;
struct eeh_dev *edev = (struct eeh_dev *)data;
struct pci_dev *dev = eeh_dev_to_pci_dev(edev);
struct eeh_rmv_data *rmv_data = (struct eeh_rmv_data *)userdata;
int *removed = rmv_data ? &rmv_data->removed : NULL;
if (!dev || (dev->hdr_type == PCI_HEADER_TYPE_BRIDGE))
return NULL;
if (eeh_dev_removed(edev))
return NULL;
driver = eeh_pcid_get(dev);
if (driver) {
eeh_pcid_put(dev);
if (removed &&
eeh_pe_passed(edev->pe))
return NULL;
if (removed &&
driver->err_handler &&
driver->err_handler->error_detected &&
driver->err_handler->slot_reset)
return NULL;
}
pr_debug("EEH: Removing %s without EEH sensitive driver\n",
pci_name(dev));
edev->bus = dev->bus;
edev->mode |= EEH_DEV_DISCONNECTED;
if (removed)
(*removed)++;
if (edev->physfn) {
#ifdef CONFIG_PPC_POWERNV
struct pci_dn *pdn = eeh_dev_to_pdn(edev);
pci_iov_remove_virtfn(edev->physfn, pdn->vf_index, 0);
edev->pdev = NULL;
pdn->pe_number = IODA_INVALID_PE;
#endif
if (rmv_data)
list_add(&edev->rmv_list, &rmv_data->edev_list);
} else {
pci_lock_rescan_remove();
pci_stop_and_remove_bus_device(dev);
pci_unlock_rescan_remove();
}
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
bool *clear_sw_state = flag;
int i, rc = 1;
for (i = 0; rc && i < 3; i++)
rc = eeh_unfreeze_pe(pe, clear_sw_state);
if (rc) {
pr_warn("%s: Failure %d unfreezing PHB#%x-PE#%x\n",
__func__, rc, pe->phb->global_number, pe->addr);
return (void *)pe;
}
return NULL;
}
static int eeh_clear_pe_frozen_state(struct eeh_pe *pe,
bool clear_sw_state)
{
void *rc;
rc = eeh_pe_traverse(pe, __eeh_clear_pe_frozen_state, &clear_sw_state);
if (!rc)
eeh_pe_state_clear(pe, EEH_PE_ISOLATED);
return rc ? -EIO : 0;
}
int eeh_pe_reset_and_recover(struct eeh_pe *pe)
{
int ret;
if (pe->state & EEH_PE_RECOVERING)
return 0;
eeh_pe_state_mark(pe, EEH_PE_RECOVERING);
eeh_pe_dev_traverse(pe, eeh_dev_save_state, NULL);
ret = eeh_reset_pe(pe);
if (ret) {
eeh_pe_state_clear(pe, EEH_PE_RECOVERING);
return ret;
}
ret = eeh_clear_pe_frozen_state(pe, true);
if (ret) {
eeh_pe_state_clear(pe, EEH_PE_RECOVERING);
return ret;
}
eeh_pe_dev_traverse(pe, eeh_dev_restore_state, NULL);
eeh_pe_state_clear(pe, EEH_PE_RECOVERING);
return 0;
}
static int eeh_reset_device(struct eeh_pe *pe, struct pci_bus *bus,
struct eeh_rmv_data *rmv_data)
{
struct pci_bus *frozen_bus = eeh_pe_bus_get(pe);
struct timeval tstamp;
int cnt, rc;
struct eeh_dev *edev;
cnt = pe->freeze_count;
tstamp = pe->tstamp;
eeh_pe_state_mark(pe, EEH_PE_KEEP);
if (bus) {
if (pe->type & EEH_PE_VF) {
eeh_pe_dev_traverse(pe, eeh_rmv_device, NULL);
} else {
pci_lock_rescan_remove();
pci_hp_remove_devices(bus);
pci_unlock_rescan_remove();
}
} else if (frozen_bus) {
eeh_pe_dev_traverse(pe, eeh_rmv_device, rmv_data);
}
rc = eeh_reset_pe(pe);
if (rc)
return rc;
pci_lock_rescan_remove();
eeh_ops->configure_bridge(pe);
eeh_pe_restore_bars(pe);
rc = eeh_clear_pe_frozen_state(pe, false);
if (rc) {
pci_unlock_rescan_remove();
return rc;
}
if (bus) {
pr_info("EEH: Sleep 5s ahead of complete hotplug\n");
ssleep(5);
edev = list_first_entry(&pe->edevs, struct eeh_dev, list);
eeh_pe_traverse(pe, eeh_pe_detach_dev, NULL);
if (pe->type & EEH_PE_VF) {
eeh_add_virt_device(edev, NULL);
} else {
eeh_pe_state_clear(pe, EEH_PE_PRI_BUS);
pci_hp_add_devices(bus);
}
} else if (frozen_bus && rmv_data->removed) {
pr_info("EEH: Sleep 5s ahead of partial hotplug\n");
ssleep(5);
edev = list_first_entry(&pe->edevs, struct eeh_dev, list);
eeh_pe_traverse(pe, eeh_pe_detach_dev, NULL);
if (pe->type & EEH_PE_VF)
eeh_add_virt_device(edev, NULL);
else
pci_hp_add_devices(frozen_bus);
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
struct eeh_dev *edev, *tmp;
int rc = 0;
enum pci_ers_result result = PCI_ERS_RESULT_NONE;
struct eeh_rmv_data rmv_data = {LIST_HEAD_INIT(rmv_data.edev_list), 0};
frozen_bus = eeh_pe_bus_get(pe);
if (!frozen_bus) {
pr_err("%s: Cannot find PCI bus for PHB#%d-PE#%x\n",
__func__, pe->phb->global_number, pe->addr);
return;
}
eeh_pe_update_time_stamp(pe);
pe->freeze_count++;
if (pe->freeze_count > eeh_max_freezes)
goto excess_failures;
pr_warn("EEH: This PCI device has failed %d times in the last hour\n",
pe->freeze_count);
pr_info("EEH: Notify device drivers to shutdown\n");
eeh_pe_dev_traverse(pe, eeh_report_error, &result);
if ((pe->type & EEH_PE_PHB) &&
result != PCI_ERS_RESULT_NONE &&
result != PCI_ERS_RESULT_NEED_RESET)
result = PCI_ERS_RESULT_NEED_RESET;
rc = eeh_ops->wait_state(pe, MAX_WAIT_FOR_RECOVERY*1000);
if (rc < 0 || rc == EEH_STATE_NOT_SUPPORT) {
pr_warn("EEH: Permanent failure\n");
goto hard_fail;
}
pr_info("EEH: Collect temporary log\n");
eeh_slot_error_detail(pe, EEH_LOG_TEMP);
if (result == PCI_ERS_RESULT_NONE) {
pr_info("EEH: Reset with hotplug activity\n");
rc = eeh_reset_device(pe, frozen_bus, NULL);
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
rc = eeh_reset_device(pe, NULL, &rmv_data);
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
list_for_each_entry_safe(edev, tmp, &rmv_data.edev_list, rmv_list) {
eeh_add_virt_device(edev, NULL);
list_del(&edev->rmv_list);
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
eeh_pe_state_mark(pe, EEH_PE_REMOVED);
if (frozen_bus) {
if (pe->type & EEH_PE_VF) {
eeh_pe_dev_traverse(pe, eeh_rmv_device, NULL);
eeh_pe_dev_mode_mark(pe, EEH_DEV_REMOVED);
} else {
eeh_pe_state_clear(pe, EEH_PE_PRI_BUS);
eeh_pe_dev_mode_mark(pe, EEH_DEV_REMOVED);
pci_lock_rescan_remove();
pci_hp_remove_devices(frozen_bus);
pci_unlock_rescan_remove();
}
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
eeh_pe_state_clear(pe, EEH_PE_PRI_BUS);
eeh_pe_dev_traverse(pe,
eeh_report_failure, NULL);
bus = eeh_pe_bus_get(phb_pe);
if (!bus) {
pr_err("%s: Cannot find PCI bus for "
"PHB#%d-PE#%x\n",
__func__,
pe->phb->global_number,
pe->addr);
break;
}
pci_hp_remove_devices(bus);
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
