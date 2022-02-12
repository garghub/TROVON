unsigned int __devinit pci_do_scan_bus(struct pci_bus *bus)
{
unsigned int max;
max = pci_scan_child_bus(bus);
pci_bus_add_devices(bus);
return max;
}
