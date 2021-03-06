static void
fixup_cpc710_pci64(struct pci_dev* dev)
{
dev->resource[0].start = dev->resource[0].end = 0;
dev->resource[0].flags = 0;
dev->resource[1].start = dev->resource[1].end = 0;
dev->resource[1].flags = 0;
}
static void
make_one_node_map(struct device_node* node, u8 pci_bus)
{
const int *bus_range;
int len;
if (pci_bus >= pci_bus_count)
return;
bus_range = of_get_property(node, "bus-range", &len);
if (bus_range == NULL || len < 2 * sizeof(int)) {
printk(KERN_WARNING "Can't get bus-range for %s, "
"assuming it starts at 0\n", node->full_name);
pci_to_OF_bus_map[pci_bus] = 0;
} else
pci_to_OF_bus_map[pci_bus] = bus_range[0];
for_each_child_of_node(node, node) {
struct pci_dev* dev;
const unsigned int *class_code, *reg;
class_code = of_get_property(node, "class-code", NULL);
if (!class_code || ((*class_code >> 8) != PCI_CLASS_BRIDGE_PCI &&
(*class_code >> 8) != PCI_CLASS_BRIDGE_CARDBUS))
continue;
reg = of_get_property(node, "reg", NULL);
if (!reg)
continue;
dev = pci_get_bus_and_slot(pci_bus, ((reg[0] >> 8) & 0xff));
if (!dev || !dev->subordinate) {
pci_dev_put(dev);
continue;
}
make_one_node_map(node, dev->subordinate->number);
pci_dev_put(dev);
}
}
void
pcibios_make_OF_bus_map(void)
{
int i;
struct pci_controller *hose, *tmp;
struct property *map_prop;
struct device_node *dn;
pci_to_OF_bus_map = kmalloc(pci_bus_count, GFP_KERNEL);
if (!pci_to_OF_bus_map) {
printk(KERN_ERR "Can't allocate OF bus map !\n");
return;
}
for (i=0; i<pci_bus_count; i++)
pci_to_OF_bus_map[i] = 0xff;
list_for_each_entry_safe(hose, tmp, &hose_list, list_node) {
struct device_node* node = hose->dn;
if (!node)
continue;
make_one_node_map(node, hose->first_busno);
}
dn = of_find_node_by_path("/");
map_prop = of_find_property(dn, "pci-OF-bus-map", NULL);
if (map_prop) {
BUG_ON(pci_bus_count > map_prop->length);
memcpy(map_prop->value, pci_to_OF_bus_map, pci_bus_count);
}
of_node_put(dn);
#ifdef DEBUG
printk("PCI->OF bus map:\n");
for (i=0; i<pci_bus_count; i++) {
if (pci_to_OF_bus_map[i] == 0xff)
continue;
printk("%d -> %d\n", i, pci_to_OF_bus_map[i]);
}
#endif
}
int pci_device_from_OF_node(struct device_node *node, u8 *bus, u8 *devfn)
{
struct pci_dev *dev = NULL;
const __be32 *reg;
int size;
if (!pci_find_hose_for_OF_device(node))
return -ENODEV;
reg = of_get_property(node, "reg", &size);
if (!reg || size < 5 * sizeof(u32))
return -ENODEV;
*bus = (be32_to_cpup(&reg[0]) >> 16) & 0xff;
*devfn = (be32_to_cpup(&reg[0]) >> 8) & 0xff;
if (!pci_to_OF_bus_map)
return 0;
for_each_pci_dev(dev)
if (pci_to_OF_bus_map[dev->bus->number] == *bus &&
dev->devfn == *devfn) {
*bus = dev->bus->number;
pci_dev_put(dev);
return 0;
}
return -ENODEV;
}
void __init
pci_create_OF_bus_map(void)
{
struct property* of_prop;
struct device_node *dn;
of_prop = memblock_virt_alloc(sizeof(struct property) + 256, 0);
dn = of_find_node_by_path("/");
if (dn) {
memset(of_prop, -1, sizeof(struct property) + 256);
of_prop->name = "pci-OF-bus-map";
of_prop->length = 256;
of_prop->value = &of_prop[1];
of_add_property(dn, of_prop);
of_node_put(dn);
}
}
void pcibios_setup_phb_io_space(struct pci_controller *hose)
{
unsigned long io_offset;
struct resource *res = &hose->io_resource;
io_offset = pcibios_io_space_offset(hose);
res->start += io_offset;
res->end += io_offset;
}
static int __init pcibios_init(void)
{
struct pci_controller *hose, *tmp;
int next_busno = 0;
printk(KERN_INFO "PCI: Probing PCI hardware\n");
if (pci_has_flag(PCI_REASSIGN_ALL_BUS))
pci_assign_all_buses = 1;
list_for_each_entry_safe(hose, tmp, &hose_list, list_node) {
if (pci_assign_all_buses)
hose->first_busno = next_busno;
hose->last_busno = 0xff;
pcibios_scan_phb(hose);
pci_bus_add_devices(hose->bus);
if (pci_assign_all_buses || next_busno <= hose->last_busno)
next_busno = hose->last_busno + pcibios_assign_bus_offset;
}
pci_bus_count = next_busno;
if (pci_assign_all_buses)
pcibios_make_OF_bus_map();
pcibios_resource_survey();
if (ppc_md.pcibios_after_init)
ppc_md.pcibios_after_init();
return 0;
}
static struct pci_controller*
pci_bus_to_hose(int bus)
{
struct pci_controller *hose, *tmp;
list_for_each_entry_safe(hose, tmp, &hose_list, list_node)
if (bus >= hose->first_busno && bus <= hose->last_busno)
return hose;
return NULL;
}
long sys_pciconfig_iobase(long which, unsigned long bus, unsigned long devfn)
{
struct pci_controller* hose;
long result = -EOPNOTSUPP;
hose = pci_bus_to_hose(bus);
if (!hose)
return -ENODEV;
switch (which) {
case IOBASE_BRIDGE_NUMBER:
return (long)hose->first_busno;
case IOBASE_MEMORY:
return (long)hose->mem_offset[0];
case IOBASE_IO:
return (long)hose->io_base_phys;
case IOBASE_ISA_IO:
return (long)isa_io_base;
case IOBASE_ISA_MEM:
return (long)isa_mem_base;
}
return result;
}
