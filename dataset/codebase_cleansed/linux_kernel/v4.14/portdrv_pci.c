static int __init pcie_port_setup(char *str)
{
if (!strncmp(str, "compat", 6)) {
pcie_ports_disabled = true;
} else if (!strncmp(str, "native", 6)) {
pcie_ports_disabled = false;
pcie_ports_auto = false;
} else if (!strncmp(str, "auto", 4)) {
pcie_ports_disabled = false;
pcie_ports_auto = true;
}
return 1;
}
void pcie_clear_root_pme_status(struct pci_dev *dev)
{
pcie_capability_set_dword(dev, PCI_EXP_RTSTA, PCI_EXP_RTSTA_PME);
}
static int pcie_portdrv_restore_config(struct pci_dev *dev)
{
int retval;
retval = pci_enable_device(dev);
if (retval)
return retval;
pci_set_master(dev);
return 0;
}
static int pcie_port_resume_noirq(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
if (pci_pcie_type(pdev) == PCI_EXP_TYPE_ROOT_PORT)
pcie_clear_root_pme_status(pdev);
return 0;
}
static int pcie_port_runtime_suspend(struct device *dev)
{
return to_pci_dev(dev)->bridge_d3 ? 0 : -EBUSY;
}
static int pcie_port_runtime_resume(struct device *dev)
{
return 0;
}
static int pcie_port_runtime_idle(struct device *dev)
{
return to_pci_dev(dev)->bridge_d3 ? 0 : -EBUSY;
}
static int pcie_portdrv_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
int status;
if (!pci_is_pcie(dev) ||
((pci_pcie_type(dev) != PCI_EXP_TYPE_ROOT_PORT) &&
(pci_pcie_type(dev) != PCI_EXP_TYPE_UPSTREAM) &&
(pci_pcie_type(dev) != PCI_EXP_TYPE_DOWNSTREAM)))
return -ENODEV;
status = pcie_port_device_register(dev);
if (status)
return status;
pci_save_state(dev);
if (pci_bridge_d3_possible(dev)) {
pm_runtime_set_autosuspend_delay(&dev->dev, 100);
pm_runtime_use_autosuspend(&dev->dev);
pm_runtime_mark_last_busy(&dev->dev);
pm_runtime_put_autosuspend(&dev->dev);
pm_runtime_allow(&dev->dev);
}
return 0;
}
static void pcie_portdrv_remove(struct pci_dev *dev)
{
if (pci_bridge_d3_possible(dev)) {
pm_runtime_forbid(&dev->dev);
pm_runtime_get_noresume(&dev->dev);
pm_runtime_dont_use_autosuspend(&dev->dev);
}
pcie_port_device_remove(dev);
}
static pci_ers_result_t pcie_portdrv_error_detected(struct pci_dev *dev,
enum pci_channel_state error)
{
return PCI_ERS_RESULT_CAN_RECOVER;
}
static pci_ers_result_t pcie_portdrv_mmio_enabled(struct pci_dev *dev)
{
return PCI_ERS_RESULT_RECOVERED;
}
static pci_ers_result_t pcie_portdrv_slot_reset(struct pci_dev *dev)
{
if (dev->error_state == pci_channel_io_frozen) {
dev->state_saved = true;
pci_restore_state(dev);
pcie_portdrv_restore_config(dev);
pci_enable_pcie_error_reporting(dev);
}
return PCI_ERS_RESULT_RECOVERED;
}
static int resume_iter(struct device *device, void *data)
{
struct pcie_device *pcie_device;
struct pcie_port_service_driver *driver;
if (device->bus == &pcie_port_bus_type && device->driver) {
driver = to_service_driver(device->driver);
if (driver && driver->error_resume) {
pcie_device = to_pcie_device(device);
driver->error_resume(pcie_device->port);
}
}
return 0;
}
static void pcie_portdrv_err_resume(struct pci_dev *dev)
{
device_for_each_child(&dev->dev, NULL, resume_iter);
}
static int __init dmi_pcie_pme_disable_msi(const struct dmi_system_id *d)
{
pr_notice("%s detected: will not use MSI for PCIe PME signaling\n",
d->ident);
pcie_pme_disable_msi();
return 0;
}
static int __init pcie_portdrv_init(void)
{
int retval;
if (pcie_ports_disabled)
return pci_register_driver(&pcie_portdriver);
dmi_check_system(pcie_portdrv_dmi_table);
retval = pcie_port_bus_register();
if (retval) {
printk(KERN_WARNING "PCIE: bus_register error: %d\n", retval);
goto out;
}
retval = pci_register_driver(&pcie_portdriver);
if (retval)
pcie_port_bus_unregister();
out:
return retval;
}
