static int pcie_port_bus_match(struct device *dev, struct device_driver *drv)
{
struct pcie_device *pciedev;
struct pcie_port_service_driver *driver;
if (drv->bus != &pcie_port_bus_type || dev->bus != &pcie_port_bus_type)
return 0;
pciedev = to_pcie_device(dev);
driver = to_service_driver(drv);
if (driver->service != pciedev->service)
return 0;
if ((driver->port_type != PCIE_ANY_PORT) &&
(driver->port_type != pci_pcie_type(pciedev->port)))
return 0;
return 1;
}
int pcie_port_bus_register(void)
{
return bus_register(&pcie_port_bus_type);
}
void pcie_port_bus_unregister(void)
{
bus_unregister(&pcie_port_bus_type);
}
