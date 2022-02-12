static int __init pciehp_setup(char *str)
{
if (!strncmp(str, "nomsi", 5))
pciehp_msi_disabled = true;
return 1;
}
static void release_pcie_device(struct device *dev)
{
kfree(to_pcie_device(dev));
}
static int pcie_port_enable_irq_vec(struct pci_dev *dev, int *irqs, int mask)
{
int nr_entries, entry, nvec = 0;
nr_entries = pci_alloc_irq_vectors(dev, 1, PCIE_PORT_MAX_MSI_ENTRIES,
PCI_IRQ_MSIX | PCI_IRQ_MSI);
if (nr_entries < 0)
return nr_entries;
if (mask & (PCIE_PORT_SERVICE_PME | PCIE_PORT_SERVICE_HP)) {
u16 reg16;
pcie_capability_read_word(dev, PCI_EXP_FLAGS, &reg16);
entry = (reg16 & PCI_EXP_FLAGS_IRQ) >> 9;
if (entry >= nr_entries)
goto out_free_irqs;
irqs[PCIE_PORT_SERVICE_PME_SHIFT] = pci_irq_vector(dev, entry);
irqs[PCIE_PORT_SERVICE_HP_SHIFT] = pci_irq_vector(dev, entry);
nvec = max(nvec, entry + 1);
}
if (mask & PCIE_PORT_SERVICE_AER) {
u32 reg32, pos;
pos = pci_find_ext_capability(dev, PCI_EXT_CAP_ID_ERR);
pci_read_config_dword(dev, pos + PCI_ERR_ROOT_STATUS, &reg32);
entry = reg32 >> 27;
if (entry >= nr_entries)
goto out_free_irqs;
irqs[PCIE_PORT_SERVICE_AER_SHIFT] = pci_irq_vector(dev, entry);
nvec = max(nvec, entry + 1);
}
if (mask & PCIE_PORT_SERVICE_DPC) {
u16 reg16, pos;
pos = pci_find_ext_capability(dev, PCI_EXT_CAP_ID_DPC);
pci_read_config_word(dev, pos + PCI_EXP_DPC_CAP, &reg16);
entry = reg16 & 0x1f;
if (entry >= nr_entries)
goto out_free_irqs;
irqs[PCIE_PORT_SERVICE_DPC_SHIFT] = pci_irq_vector(dev, entry);
nvec = max(nvec, entry + 1);
}
if (nvec != nr_entries) {
pci_free_irq_vectors(dev);
nr_entries = pci_alloc_irq_vectors(dev, nvec, nvec,
PCI_IRQ_MSIX | PCI_IRQ_MSI);
if (nr_entries < 0)
return nr_entries;
}
return 0;
out_free_irqs:
pci_free_irq_vectors(dev);
return -EIO;
}
static int pcie_init_service_irqs(struct pci_dev *dev, int *irqs, int mask)
{
int ret, i;
for (i = 0; i < PCIE_PORT_DEVICE_MAXSERVICES; i++)
irqs[i] = -1;
if ((mask & PCIE_PORT_SERVICE_PME) && pcie_pme_no_msi())
goto legacy_irq;
if ((mask & PCIE_PORT_SERVICE_HP) && pciehp_no_msi())
goto legacy_irq;
if (pcie_port_enable_irq_vec(dev, irqs, mask) == 0)
return 0;
legacy_irq:
ret = pci_alloc_irq_vectors(dev, 1, 1, PCI_IRQ_LEGACY);
if (ret < 0)
return -ENODEV;
for (i = 0; i < PCIE_PORT_DEVICE_MAXSERVICES; i++) {
if (i != PCIE_PORT_SERVICE_VC_SHIFT)
irqs[i] = pci_irq_vector(dev, 0);
}
return 0;
}
static int get_port_device_capability(struct pci_dev *dev)
{
int services = 0;
int cap_mask = 0;
if (pcie_ports_disabled)
return 0;
cap_mask = PCIE_PORT_SERVICE_PME | PCIE_PORT_SERVICE_HP
| PCIE_PORT_SERVICE_VC | PCIE_PORT_SERVICE_DPC;
if (pci_aer_available())
cap_mask |= PCIE_PORT_SERVICE_AER;
if (pcie_ports_auto)
pcie_port_platform_notify(dev, &cap_mask);
if ((cap_mask & PCIE_PORT_SERVICE_HP) && dev->is_hotplug_bridge) {
services |= PCIE_PORT_SERVICE_HP;
pcie_capability_clear_word(dev, PCI_EXP_SLTCTL,
PCI_EXP_SLTCTL_CCIE | PCI_EXP_SLTCTL_HPIE);
}
if ((cap_mask & PCIE_PORT_SERVICE_AER)
&& pci_find_ext_capability(dev, PCI_EXT_CAP_ID_ERR)) {
services |= PCIE_PORT_SERVICE_AER;
pci_disable_pcie_error_reporting(dev);
}
if (pci_find_ext_capability(dev, PCI_EXT_CAP_ID_VC))
services |= PCIE_PORT_SERVICE_VC;
if ((cap_mask & PCIE_PORT_SERVICE_PME)
&& pci_pcie_type(dev) == PCI_EXP_TYPE_ROOT_PORT) {
services |= PCIE_PORT_SERVICE_PME;
pcie_pme_interrupt_enable(dev, false);
}
if (pci_find_ext_capability(dev, PCI_EXT_CAP_ID_DPC))
services |= PCIE_PORT_SERVICE_DPC;
return services;
}
static int pcie_device_init(struct pci_dev *pdev, int service, int irq)
{
int retval;
struct pcie_device *pcie;
struct device *device;
pcie = kzalloc(sizeof(*pcie), GFP_KERNEL);
if (!pcie)
return -ENOMEM;
pcie->port = pdev;
pcie->irq = irq;
pcie->service = service;
device = &pcie->device;
device->bus = &pcie_port_bus_type;
device->release = release_pcie_device;
dev_set_name(device, "%s:pcie%03x",
pci_name(pdev),
get_descriptor_id(pci_pcie_type(pdev), service));
device->parent = &pdev->dev;
device_enable_async_suspend(device);
retval = device_register(device);
if (retval) {
put_device(device);
return retval;
}
pm_runtime_no_callbacks(device);
return 0;
}
int pcie_port_device_register(struct pci_dev *dev)
{
int status, capabilities, i, nr_service;
int irqs[PCIE_PORT_DEVICE_MAXSERVICES];
status = pci_enable_device(dev);
if (status)
return status;
capabilities = get_port_device_capability(dev);
if (!capabilities)
return 0;
pci_set_master(dev);
status = pcie_init_service_irqs(dev, irqs, capabilities);
if (status) {
capabilities &= PCIE_PORT_SERVICE_VC | PCIE_PORT_SERVICE_HP;
if (!capabilities)
goto error_disable;
}
status = -ENODEV;
nr_service = 0;
for (i = 0; i < PCIE_PORT_DEVICE_MAXSERVICES; i++) {
int service = 1 << i;
if (!(capabilities & service))
continue;
if (!pcie_device_init(dev, service, irqs[i]))
nr_service++;
}
if (!nr_service)
goto error_cleanup_irqs;
return 0;
error_cleanup_irqs:
pci_free_irq_vectors(dev);
error_disable:
pci_disable_device(dev);
return status;
}
static int suspend_iter(struct device *dev, void *data)
{
struct pcie_port_service_driver *service_driver;
if ((dev->bus == &pcie_port_bus_type) && dev->driver) {
service_driver = to_service_driver(dev->driver);
if (service_driver->suspend)
service_driver->suspend(to_pcie_device(dev));
}
return 0;
}
int pcie_port_device_suspend(struct device *dev)
{
return device_for_each_child(dev, NULL, suspend_iter);
}
static int resume_iter(struct device *dev, void *data)
{
struct pcie_port_service_driver *service_driver;
if ((dev->bus == &pcie_port_bus_type) &&
(dev->driver)) {
service_driver = to_service_driver(dev->driver);
if (service_driver->resume)
service_driver->resume(to_pcie_device(dev));
}
return 0;
}
int pcie_port_device_resume(struct device *dev)
{
return device_for_each_child(dev, NULL, resume_iter);
}
static int remove_iter(struct device *dev, void *data)
{
if (dev->bus == &pcie_port_bus_type)
device_unregister(dev);
return 0;
}
void pcie_port_device_remove(struct pci_dev *dev)
{
device_for_each_child(&dev->dev, NULL, remove_iter);
pci_free_irq_vectors(dev);
pci_disable_device(dev);
}
static int pcie_port_probe_service(struct device *dev)
{
struct pcie_device *pciedev;
struct pcie_port_service_driver *driver;
int status;
if (!dev || !dev->driver)
return -ENODEV;
driver = to_service_driver(dev->driver);
if (!driver || !driver->probe)
return -ENODEV;
pciedev = to_pcie_device(dev);
status = driver->probe(pciedev);
if (status)
return status;
get_device(dev);
return 0;
}
static int pcie_port_remove_service(struct device *dev)
{
struct pcie_device *pciedev;
struct pcie_port_service_driver *driver;
if (!dev || !dev->driver)
return 0;
pciedev = to_pcie_device(dev);
driver = to_service_driver(dev->driver);
if (driver && driver->remove) {
driver->remove(pciedev);
put_device(dev);
}
return 0;
}
static void pcie_port_shutdown_service(struct device *dev) {}
int pcie_port_service_register(struct pcie_port_service_driver *new)
{
if (pcie_ports_disabled)
return -ENODEV;
new->driver.name = new->name;
new->driver.bus = &pcie_port_bus_type;
new->driver.probe = pcie_port_probe_service;
new->driver.remove = pcie_port_remove_service;
new->driver.shutdown = pcie_port_shutdown_service;
return driver_register(&new->driver);
}
void pcie_port_service_unregister(struct pcie_port_service_driver *drv)
{
driver_unregister(&drv->driver);
}
