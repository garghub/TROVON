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
struct irq_desc *desc;
if ((edev->mode) & EEH_DEV_IRQ_DISABLED) {
edev->mode &= ~EEH_DEV_IRQ_DISABLED;
desc = irq_to_desc(dev->irq);
if (desc && desc->depth > 0)
enable_irq(dev->irq);
}
}
static void *eeh_report_error(void *data, void *userdata)
{
struct eeh_dev *edev = (struct eeh_dev *)data;
struct pci_dev *dev = eeh_dev_to_pci_dev(edev);
enum pci_ers_result rc, *res = userdata;
struct pci_driver *driver;
if (!dev) return NULL;
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
driver = eeh_pcid_get(dev);
if (!driver) return NULL;
if (!driver->err_handler ||
!driver->err_handler->mmio_enabled) {
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
if (!dev) return NULL;
dev->error_state = pci_channel_io_normal;
driver = eeh_pcid_get(dev);
if (!driver) return NULL;
eeh_enable_irq(dev);
if (!driver->err_handler ||
!driver->err_handler->slot_reset) {
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
if (!dev) return NULL;
dev->error_state = pci_channel_io_normal;
driver = eeh_pcid_get(dev);
if (!driver) return NULL;
eeh_enable_irq(dev);
if (!driver->err_handler ||
!driver->err_handler->resume) {
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
if (!dev) return NULL;
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
driver = eeh_pcid_get(dev);
if (driver && driver->err_handler)
return NULL;
pr_debug("EEH: Removing %s without EEH sensitive driver\n",
pci_name(dev));
edev->bus = dev->bus;
edev->mode |= EEH_DEV_DISCONNECTED;
(*removed)++;
pci_stop_and_remove_bus_device(dev);
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
static int eeh_reset_device(struct eeh_pe *pe, struct pci_bus *bus)
{
struct pci_bus *frozen_bus = eeh_pe_bus_get(pe);
struct timeval tstamp;
int cnt, rc, removed = 0;
cnt = pe->freeze_count;
tstamp = pe->tstamp;
eeh_pe_state_mark(pe, EEH_PE_KEEP);
if (bus)
pcibios_remove_pci_devices(bus);
else if (frozen_bus)
eeh_pe_dev_traverse(pe, eeh_rmv_device, &removed);
rc = eeh_reset_pe(pe);
if (rc)
return rc;
eeh_ops->configure_bridge(pe);
eeh_pe_restore_bars(pe);
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
pr_warning("EEH: This PCI device has failed %d times in the last hour\n",
pe->freeze_count);
pr_info("EEH: Notify device drivers to shutdown\n");
eeh_pe_dev_traverse(pe, eeh_report_error, &result);
rc = eeh_ops->wait_state(pe, MAX_WAIT_FOR_RECOVERY*1000);
if (rc < 0 || rc == EEH_STATE_NOT_SUPPORT) {
pr_warning("EEH: Permanent failure\n");
goto hard_fail;
}
pr_info("EEH: Collect temporary log\n");
eeh_slot_error_detail(pe, EEH_LOG_TEMP);
if (result == PCI_ERS_RESULT_NONE) {
pr_info("EEH: Reset with hotplug activity\n");
rc = eeh_reset_device(pe, frozen_bus);
if (rc) {
pr_warning("%s: Unable to reset, err=%d\n",
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
result = PCI_ERS_RESULT_NONE;
eeh_pe_dev_traverse(pe, eeh_report_mmio_enabled, &result);
}
}
if (result == PCI_ERS_RESULT_CAN_RECOVER) {
pr_info("EEH: Enabled DMA for affected devices\n");
rc = eeh_pci_enable(pe, EEH_OPT_THAW_DMA);
if (rc < 0)
goto hard_fail;
if (rc)
result = PCI_ERS_RESULT_NEED_RESET;
else
result = PCI_ERS_RESULT_RECOVERED;
}
if (result == PCI_ERS_RESULT_DISCONNECT) {
pr_warning("EEH: Device driver gave up\n");
goto hard_fail;
}
if (result == PCI_ERS_RESULT_NEED_RESET) {
pr_info("EEH: Reset without hotplug activity\n");
rc = eeh_reset_device(pe, NULL);
if (rc) {
pr_warning("%s: Cannot reset, err=%d\n",
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
pr_warning("EEH: Not recovered\n");
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
if (frozen_bus)
pcibios_remove_pci_devices(frozen_bus);
}
static void eeh_handle_special_event(void)
{
struct eeh_pe *pe, *phb_pe;
struct pci_bus *bus;
struct pci_controller *hose, *tmp;
unsigned long flags;
int rc = 0;
rc = eeh_ops->next_error(&pe);
if (rc <= 0)
return;
switch (rc) {
case 4:
eeh_serialize_lock(&flags);
list_for_each_entry_safe(hose, tmp,
&hose_list, list_node) {
phb_pe = eeh_phb_pe_get(hose);
if (!phb_pe) continue;
eeh_pe_state_mark(phb_pe,
EEH_PE_ISOLATED | EEH_PE_PHB_DEAD);
}
eeh_serialize_unlock(flags);
eeh_remove_event(NULL);
break;
case 3:
case 2:
case 1:
eeh_serialize_lock(&flags);
if (rc == 3)
eeh_pe_state_mark(pe,
EEH_PE_ISOLATED | EEH_PE_PHB_DEAD);
else
eeh_pe_state_mark(pe,
EEH_PE_ISOLATED | EEH_PE_RECOVERING);
eeh_serialize_unlock(flags);
eeh_remove_event(pe);
break;
default:
pr_err("%s: Invalid value %d from next_error()\n",
__func__, rc);
return;
}
if (rc == 2 || rc == 1)
eeh_handle_normal_event(pe);
else {
list_for_each_entry_safe(hose, tmp,
&hose_list, list_node) {
phb_pe = eeh_phb_pe_get(hose);
if (!phb_pe || !(phb_pe->state & EEH_PE_PHB_DEAD))
continue;
bus = eeh_pe_bus_get(phb_pe);
eeh_pe_dev_traverse(pe, eeh_report_failure, NULL);
pcibios_remove_pci_devices(bus);
}
}
}
void eeh_handle_event(struct eeh_pe *pe)
{
if (pe)
eeh_handle_normal_event(pe);
else
eeh_handle_special_event();
}
