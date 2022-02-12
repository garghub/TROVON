static struct pci_bus *
find_bus_among_children(struct pci_bus *bus,
struct device_node *dn)
{
struct pci_bus *child = NULL;
struct list_head *tmp;
struct device_node *busdn;
busdn = pci_bus_to_OF_node(bus);
if (busdn == dn)
return bus;
list_for_each(tmp, &bus->children) {
child = find_bus_among_children(pci_bus_b(tmp), dn);
if (child)
break;
};
return child;
}
struct pci_bus *
pcibios_find_pci_bus(struct device_node *dn)
{
struct pci_dn *pdn = dn->data;
if (!pdn || !pdn->phb || !pdn->phb->bus)
return NULL;
return find_bus_among_children(pdn->phb->bus, dn);
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
pr_debug(" * Removing %s...\n", pci_name(dev));
eeh_remove_bus_device(dev);
pci_stop_and_remove_bus_device(dev);
}
}
void pcibios_add_pci_devices(struct pci_bus * bus)
{
int slotno, num, mode, pass, max;
struct pci_dev *dev;
struct device_node *dn = pci_bus_to_OF_node(bus);
eeh_add_device_tree_early(dn);
mode = PCI_PROBE_NORMAL;
if (ppc_md.pci_probe_mode)
mode = ppc_md.pci_probe_mode(bus);
if (mode == PCI_PROBE_DEVTREE) {
of_rescan_bus(dn, bus);
} else if (mode == PCI_PROBE_NORMAL) {
slotno = PCI_SLOT(PCI_DN(dn->child)->devfn);
num = pci_scan_slot(bus, PCI_DEVFN(slotno, 0));
if (!num)
return;
pcibios_setup_bus_devices(bus);
max = bus->secondary;
for (pass=0; pass < 2; pass++)
list_for_each_entry(dev, &bus->devices, bus_list) {
if (dev->hdr_type == PCI_HEADER_TYPE_BRIDGE ||
dev->hdr_type == PCI_HEADER_TYPE_CARDBUS)
max = pci_scan_bridge(bus, dev, max, pass);
}
}
pcibios_finish_adding_to_bus(bus);
}
struct pci_controller * __devinit init_phb_dynamic(struct device_node *dn)
{
struct pci_controller *phb;
pr_debug("PCI: Initializing new hotplug PHB %s\n", dn->full_name);
phb = pcibios_alloc_controller(dn);
if (!phb)
return NULL;
rtas_setup_phb(phb);
pci_process_bridge_OF_ranges(phb, dn, 0);
pci_devs_phb_init_dynamic(phb);
eeh_dev_phb_init_dynamic(phb);
if (dn->child)
eeh_add_device_tree_early(dn);
pcibios_scan_phb(phb);
pcibios_finish_adding_to_bus(phb->bus);
return phb;
}
int remove_phb_dynamic(struct pci_controller *phb)
{
struct pci_bus *b = phb->bus;
struct resource *res;
int rc, i;
pr_debug("PCI: Removing PHB %04x:%02x...\n",
pci_domain_nr(b), b->number);
if (!(list_empty(&b->children) && list_empty(&b->devices)))
return -EBUSY;
res = &phb->io_resource;
if (res->flags & IORESOURCE_IO) {
rc = pcibios_unmap_io_space(b);
if (rc) {
printk(KERN_ERR "%s: failed to unmap IO on bus %s\n",
__func__, b->name);
return 1;
}
}
device_unregister(b->bridge);
phb->bus = NULL;
pci_remove_bus(b);
if (res->flags & IORESOURCE_IO)
release_resource(res);
for (i = 0; i < 3; ++i) {
res = &phb->mem_resources[i];
if (!(res->flags & IORESOURCE_MEM))
continue;
release_resource(res);
}
pcibios_free_controller(phb);
return 0;
}
