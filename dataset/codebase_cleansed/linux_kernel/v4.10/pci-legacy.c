resource_size_t
pcibios_align_resource(void *data, const struct resource *res,
resource_size_t size, resource_size_t align)
{
struct pci_dev *dev = data;
struct pci_controller *hose = dev->sysdata;
resource_size_t start = res->start;
if (res->flags & IORESOURCE_IO) {
if (start < PCIBIOS_MIN_IO + hose->io_resource->start)
start = PCIBIOS_MIN_IO + hose->io_resource->start;
if (start & 0x300)
start = (start + 0x3ff) & ~0x3ff;
} else if (res->flags & IORESOURCE_MEM) {
if (start < PCIBIOS_MIN_MEM + hose->mem_resource->start)
start = PCIBIOS_MIN_MEM + hose->mem_resource->start;
}
return start;
}
static void pcibios_scanbus(struct pci_controller *hose)
{
static int next_busno;
static int need_domain_info;
LIST_HEAD(resources);
struct pci_bus *bus;
if (hose->get_busno && pci_has_flag(PCI_PROBE_ONLY))
next_busno = (*hose->get_busno)();
pci_add_resource_offset(&resources,
hose->mem_resource, hose->mem_offset);
pci_add_resource_offset(&resources,
hose->io_resource, hose->io_offset);
pci_add_resource_offset(&resources,
hose->busn_resource, hose->busn_offset);
bus = pci_scan_root_bus(NULL, next_busno, hose->pci_ops, hose,
&resources);
hose->bus = bus;
need_domain_info = need_domain_info || pci_domain_nr(bus);
set_pci_need_domain_info(hose, need_domain_info);
if (!bus) {
pci_free_resource_list(&resources);
return;
}
next_busno = bus->busn_res.end + 1;
if (next_busno > 224) {
next_busno = 0;
need_domain_info = 1;
}
if (pci_has_flag(PCI_PROBE_ONLY)) {
pci_bus_claim_resources(bus);
} else {
pci_bus_size_bridges(bus);
pci_bus_assign_resources(bus);
}
pci_bus_add_devices(bus);
}
void pci_load_of_ranges(struct pci_controller *hose, struct device_node *node)
{
struct of_pci_range range;
struct of_pci_range_parser parser;
pr_info("PCI host bridge %s ranges:\n", node->full_name);
hose->of_node = node;
if (of_pci_range_parser_init(&parser, node))
return;
for_each_of_pci_range(&parser, &range) {
struct resource *res = NULL;
switch (range.flags & IORESOURCE_TYPE_BITS) {
case IORESOURCE_IO:
pr_info(" IO 0x%016llx..0x%016llx\n",
range.cpu_addr,
range.cpu_addr + range.size - 1);
hose->io_map_base =
(unsigned long)ioremap(range.cpu_addr,
range.size);
res = hose->io_resource;
break;
case IORESOURCE_MEM:
pr_info(" MEM 0x%016llx..0x%016llx\n",
range.cpu_addr,
range.cpu_addr + range.size - 1);
res = hose->mem_resource;
break;
}
if (res != NULL)
of_pci_range_to_resource(&range, node, res);
}
}
struct device_node *pcibios_get_phb_of_node(struct pci_bus *bus)
{
struct pci_controller *hose = bus->sysdata;
return of_node_get(hose->of_node);
}
void register_pci_controller(struct pci_controller *hose)
{
struct resource *parent;
parent = hose->mem_resource->parent;
if (!parent)
parent = &iomem_resource;
if (request_resource(parent, hose->mem_resource) < 0)
goto out;
parent = hose->io_resource->parent;
if (!parent)
parent = &ioport_resource;
if (request_resource(parent, hose->io_resource) < 0) {
release_resource(hose->mem_resource);
goto out;
}
INIT_LIST_HEAD(&hose->list);
list_add(&hose->list, &controllers);
if (!hose->io_map_base) {
printk(KERN_WARNING
"registering PCI controller with io_map_base unset\n");
}
if (pci_initialized) {
mutex_lock(&pci_scan_mutex);
pcibios_scanbus(hose);
mutex_unlock(&pci_scan_mutex);
}
return;
out:
printk(KERN_WARNING
"Skipping PCI bus scan due to resource conflict\n");
}
static int __init pcibios_init(void)
{
struct pci_controller *hose;
list_for_each_entry(hose, &controllers, list)
pcibios_scanbus(hose);
pci_fixup_irqs(pci_common_swizzle, pcibios_map_irq);
pci_initialized = 1;
return 0;
}
static int pcibios_enable_resources(struct pci_dev *dev, int mask)
{
u16 cmd, old_cmd;
int idx;
struct resource *r;
pci_read_config_word(dev, PCI_COMMAND, &cmd);
old_cmd = cmd;
for (idx=0; idx < PCI_NUM_RESOURCES; idx++) {
if (!(mask & (1<<idx)))
continue;
r = &dev->resource[idx];
if (!(r->flags & (IORESOURCE_IO | IORESOURCE_MEM)))
continue;
if ((idx == PCI_ROM_RESOURCE) &&
(!(r->flags & IORESOURCE_ROM_ENABLE)))
continue;
if (!r->start && r->end) {
printk(KERN_ERR "PCI: Device %s not available "
"because of resource collisions\n",
pci_name(dev));
return -EINVAL;
}
if (r->flags & IORESOURCE_IO)
cmd |= PCI_COMMAND_IO;
if (r->flags & IORESOURCE_MEM)
cmd |= PCI_COMMAND_MEMORY;
}
if (cmd != old_cmd) {
printk("PCI: Enabling device %s (%04x -> %04x)\n",
pci_name(dev), old_cmd, cmd);
pci_write_config_word(dev, PCI_COMMAND, cmd);
}
return 0;
}
int pcibios_enable_device(struct pci_dev *dev, int mask)
{
int err;
if ((err = pcibios_enable_resources(dev, mask)) < 0)
return err;
return pcibios_plat_dev_init(dev);
}
void pcibios_fixup_bus(struct pci_bus *bus)
{
struct pci_dev *dev = bus->self;
if (pci_has_flag(PCI_PROBE_ONLY) && dev &&
(dev->class >> 8) == PCI_CLASS_BRIDGE_PCI) {
pci_read_bridge_bases(bus);
}
}
char *__init pcibios_setup(char *str)
{
if (pcibios_plat_setup)
return pcibios_plat_setup(str);
return str;
}
