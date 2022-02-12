void pcibios_release_device(struct pci_dev *dev)
{
struct pci_controller *phb = pci_bus_to_host(dev->bus);
eeh_remove_device(dev);
if (phb->controller_ops.release_device)
phb->controller_ops.release_device(dev);
}
void pcibios_remove_pci_devices(struct pci_bus *bus)
{
struct pci_dev *dev, *tmp;
struct pci_bus *child_bus;
list_for_each_entry(child_bus, &bus->children, node)
pcibios_remove_pci_devices(child_bus);
pr_debug("PCI: Removing devices on bus %04x:%02x\n",
pci_domain_nr(bus), bus->number);
list_for_each_entry_safe(dev, tmp, &bus->devices, bus_list) {
pr_debug(" Removing %s...\n", pci_name(dev));
pci_stop_and_remove_bus_device(dev);
}
}
void pcibios_add_pci_devices(struct pci_bus * bus)
{
int slotno, mode, pass, max;
struct pci_dev *dev;
struct pci_controller *phb;
struct device_node *dn = pci_bus_to_OF_node(bus);
eeh_add_device_tree_early(PCI_DN(dn));
phb = pci_bus_to_host(bus);
mode = PCI_PROBE_NORMAL;
if (phb->controller_ops.probe_mode)
mode = phb->controller_ops.probe_mode(bus);
if (mode == PCI_PROBE_DEVTREE) {
of_rescan_bus(dn, bus);
} else if (mode == PCI_PROBE_NORMAL) {
slotno = PCI_SLOT(PCI_DN(dn->child)->devfn);
pci_scan_slot(bus, PCI_DEVFN(slotno, 0));
pcibios_setup_bus_devices(bus);
max = bus->busn_res.start;
for (pass = 0; pass < 2; pass++) {
list_for_each_entry(dev, &bus->devices, bus_list) {
if (pci_is_bridge(dev))
max = pci_scan_bridge(bus, dev,
max, pass);
}
}
}
pcibios_finish_adding_to_bus(bus);
}
