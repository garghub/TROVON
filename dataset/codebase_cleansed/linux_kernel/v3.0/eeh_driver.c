static inline const char * pcid_name (struct pci_dev *pdev)
{
if (pdev && pdev->dev.driver)
return pdev->dev.driver->name;
return "";
}
static void eeh_disable_irq(struct pci_dev *dev)
{
struct device_node *dn = pci_device_to_OF_node(dev);
if (dev->msi_enabled || dev->msix_enabled)
return;
if (!irq_has_action(dev->irq))
return;
PCI_DN(dn)->eeh_mode |= EEH_MODE_IRQ_DISABLED;
disable_irq_nosync(dev->irq);
}
static void eeh_enable_irq(struct pci_dev *dev)
{
struct device_node *dn = pci_device_to_OF_node(dev);
if ((PCI_DN(dn)->eeh_mode) & EEH_MODE_IRQ_DISABLED) {
PCI_DN(dn)->eeh_mode &= ~EEH_MODE_IRQ_DISABLED;
enable_irq(dev->irq);
}
}
static int eeh_report_error(struct pci_dev *dev, void *userdata)
{
enum pci_ers_result rc, *res = userdata;
struct pci_driver *driver = dev->driver;
dev->error_state = pci_channel_io_frozen;
if (!driver)
return 0;
eeh_disable_irq(dev);
if (!driver->err_handler ||
!driver->err_handler->error_detected)
return 0;
rc = driver->err_handler->error_detected (dev, pci_channel_io_frozen);
if (rc == PCI_ERS_RESULT_NEED_RESET) *res = rc;
if (*res == PCI_ERS_RESULT_NONE) *res = rc;
return 0;
}
static int eeh_report_mmio_enabled(struct pci_dev *dev, void *userdata)
{
enum pci_ers_result rc, *res = userdata;
struct pci_driver *driver = dev->driver;
if (!driver ||
!driver->err_handler ||
!driver->err_handler->mmio_enabled)
return 0;
rc = driver->err_handler->mmio_enabled (dev);
if (rc == PCI_ERS_RESULT_NEED_RESET) *res = rc;
if (*res == PCI_ERS_RESULT_NONE) *res = rc;
return 0;
}
static int eeh_report_reset(struct pci_dev *dev, void *userdata)
{
enum pci_ers_result rc, *res = userdata;
struct pci_driver *driver = dev->driver;
if (!driver)
return 0;
dev->error_state = pci_channel_io_normal;
eeh_enable_irq(dev);
if (!driver->err_handler ||
!driver->err_handler->slot_reset)
return 0;
rc = driver->err_handler->slot_reset(dev);
if ((*res == PCI_ERS_RESULT_NONE) ||
(*res == PCI_ERS_RESULT_RECOVERED)) *res = rc;
if (*res == PCI_ERS_RESULT_DISCONNECT &&
rc == PCI_ERS_RESULT_NEED_RESET) *res = rc;
return 0;
}
static int eeh_report_resume(struct pci_dev *dev, void *userdata)
{
struct pci_driver *driver = dev->driver;
dev->error_state = pci_channel_io_normal;
if (!driver)
return 0;
eeh_enable_irq(dev);
if (!driver->err_handler ||
!driver->err_handler->resume)
return 0;
driver->err_handler->resume(dev);
return 0;
}
static int eeh_report_failure(struct pci_dev *dev, void *userdata)
{
struct pci_driver *driver = dev->driver;
dev->error_state = pci_channel_io_perm_failure;
if (!driver)
return 0;
eeh_disable_irq(dev);
if (!driver->err_handler ||
!driver->err_handler->error_detected)
return 0;
driver->err_handler->error_detected(dev, pci_channel_io_perm_failure);
return 0;
}
static int eeh_reset_device (struct pci_dn *pe_dn, struct pci_bus *bus)
{
struct device_node *dn;
int cnt, rc;
cnt = pe_dn->eeh_freeze_count;
if (bus)
pcibios_remove_pci_devices(bus);
rc = rtas_set_slot_reset(pe_dn);
if (rc)
return rc;
dn = pe_dn->node;
if (!pcibios_find_pci_bus(dn) && PCI_DN(dn->parent))
dn = dn->parent->child;
while (dn) {
struct pci_dn *ppe = PCI_DN(dn);
if (pe_dn->eeh_pe_config_addr == ppe->eeh_pe_config_addr) {
rtas_configure_bridge(ppe);
eeh_restore_bars(ppe);
}
dn = dn->sibling;
}
if (bus) {
ssleep (5);
pcibios_add_pci_devices(bus);
}
pe_dn->eeh_freeze_count = cnt;
return 0;
}
struct pci_dn * handle_eeh_events (struct eeh_event *event)
{
struct device_node *frozen_dn;
struct pci_dn *frozen_pdn;
struct pci_bus *frozen_bus;
int rc = 0;
enum pci_ers_result result = PCI_ERS_RESULT_NONE;
const char *location, *pci_str, *drv_str, *bus_pci_str, *bus_drv_str;
frozen_dn = find_device_pe(event->dn);
if (!frozen_dn) {
location = of_get_property(event->dn, "ibm,loc-code", NULL);
location = location ? location : "unknown";
printk(KERN_ERR "EEH: Error: Cannot find partition endpoint "
"for location=%s pci addr=%s\n",
location, eeh_pci_name(event->dev));
return NULL;
}
frozen_bus = pcibios_find_pci_bus(frozen_dn);
location = of_get_property(frozen_dn, "ibm,loc-code", NULL);
location = location ? location : "unknown";
if (!frozen_bus)
frozen_bus = pcibios_find_pci_bus (frozen_dn->parent);
if (!frozen_bus) {
printk(KERN_ERR "EEH: Cannot find PCI bus "
"for location=%s dn=%s\n",
location, frozen_dn->full_name);
return NULL;
}
frozen_pdn = PCI_DN(frozen_dn);
frozen_pdn->eeh_freeze_count++;
pci_str = eeh_pci_name(event->dev);
drv_str = pcid_name(event->dev);
if (frozen_pdn->eeh_freeze_count > EEH_MAX_ALLOWED_FREEZES)
goto excess_failures;
printk(KERN_WARNING
"EEH: This PCI device has failed %d times in the last hour:\n",
frozen_pdn->eeh_freeze_count);
if (frozen_pdn->pcidev) {
bus_pci_str = pci_name(frozen_pdn->pcidev);
bus_drv_str = pcid_name(frozen_pdn->pcidev);
printk(KERN_WARNING
"EEH: Bus location=%s driver=%s pci addr=%s\n",
location, bus_drv_str, bus_pci_str);
}
printk(KERN_WARNING
"EEH: Device location=%s driver=%s pci addr=%s\n",
location, drv_str, pci_str);
pci_walk_bus(frozen_bus, eeh_report_error, &result);
rc = eeh_wait_for_slot_status (frozen_pdn, MAX_WAIT_FOR_RECOVERY*1000);
if (rc < 0) {
printk(KERN_WARNING "EEH: Permanent failure\n");
goto hard_fail;
}
eeh_slot_error_detail(frozen_pdn, EEH_LOG_TEMP_FAILURE);
if (result == PCI_ERS_RESULT_NONE) {
rc = eeh_reset_device(frozen_pdn, frozen_bus);
if (rc) {
printk(KERN_WARNING "EEH: Unable to reset, rc=%d\n", rc);
goto hard_fail;
}
}
if (result == PCI_ERS_RESULT_CAN_RECOVER) {
rc = rtas_pci_enable(frozen_pdn, EEH_THAW_MMIO);
if (rc < 0)
goto hard_fail;
if (rc) {
result = PCI_ERS_RESULT_NEED_RESET;
} else {
result = PCI_ERS_RESULT_NONE;
pci_walk_bus(frozen_bus, eeh_report_mmio_enabled, &result);
}
}
if (result == PCI_ERS_RESULT_CAN_RECOVER) {
rc = rtas_pci_enable(frozen_pdn, EEH_THAW_DMA);
if (rc < 0)
goto hard_fail;
if (rc)
result = PCI_ERS_RESULT_NEED_RESET;
else
result = PCI_ERS_RESULT_RECOVERED;
}
if (result == PCI_ERS_RESULT_DISCONNECT) {
printk(KERN_WARNING "EEH: Device driver gave up\n");
goto hard_fail;
}
if (result == PCI_ERS_RESULT_NEED_RESET) {
rc = eeh_reset_device(frozen_pdn, NULL);
if (rc) {
printk(KERN_WARNING "EEH: Cannot reset, rc=%d\n", rc);
goto hard_fail;
}
result = PCI_ERS_RESULT_NONE;
pci_walk_bus(frozen_bus, eeh_report_reset, &result);
}
if ((result != PCI_ERS_RESULT_RECOVERED) &&
(result != PCI_ERS_RESULT_NONE)) {
printk(KERN_WARNING "EEH: Not recovered\n");
goto hard_fail;
}
pci_walk_bus(frozen_bus, eeh_report_resume, NULL);
return frozen_pdn;
excess_failures:
printk(KERN_ERR
"EEH: PCI device at location=%s driver=%s pci addr=%s\n"
"has failed %d times in the last hour "
"and has been permanently disabled.\n"
"Please try reseating this device or replacing it.\n",
location, drv_str, pci_str, frozen_pdn->eeh_freeze_count);
goto perm_error;
hard_fail:
printk(KERN_ERR
"EEH: Unable to recover from failure of PCI device "
"at location=%s driver=%s pci addr=%s\n"
"Please try reseating this device or replacing it.\n",
location, drv_str, pci_str);
perm_error:
eeh_slot_error_detail(frozen_pdn, EEH_LOG_PERM_FAILURE);
pci_walk_bus(frozen_bus, eeh_report_failure, NULL);
pcibios_remove_pci_devices(frozen_bus);
return NULL;
}
