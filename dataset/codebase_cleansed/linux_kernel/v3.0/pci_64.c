static int __init pcibios_init(void)
{
struct pci_controller *hose, *tmp;
printk(KERN_INFO "PCI: Probing PCI hardware\n");
ppc_md.phys_mem_access_prot = pci_phys_mem_access_prot;
if (pci_probe_only)
ppc_pci_flags |= PPC_PCI_PROBE_ONLY;
ppc_pci_flags |= PPC_PCI_ENABLE_PROC_DOMAINS | PPC_PCI_COMPAT_DOMAIN_0;
list_for_each_entry_safe(hose, tmp, &hose_list, list_node) {
pcibios_scan_phb(hose);
pci_bus_add_devices(hose->bus);
}
pcibios_resource_survey();
printk(KERN_DEBUG "PCI: Probing PCI hardware done\n");
return 0;
}
int pcibios_unmap_io_space(struct pci_bus *bus)
{
struct pci_controller *hose;
WARN_ON(bus == NULL);
if (bus->self) {
#ifdef CONFIG_PPC_STD_MMU_64
struct resource *res = bus->resource[0];
#endif
pr_debug("IO unmapping for PCI-PCI bridge %s\n",
pci_name(bus->self));
#ifdef CONFIG_PPC_STD_MMU_64
__flush_hash_table_range(&init_mm, res->start + _IO_BASE,
res->end + _IO_BASE + 1);
#endif
return 0;
}
hose = pci_bus_to_host(bus);
if (hose->io_base_alloc == 0)
return 0;
pr_debug("IO unmapping for PHB %s\n", hose->dn->full_name);
pr_debug(" alloc=0x%p\n", hose->io_base_alloc);
vunmap(hose->io_base_alloc);
return 0;
}
int __devinit pcibios_map_io_space(struct pci_bus *bus)
{
struct vm_struct *area;
unsigned long phys_page;
unsigned long size_page;
unsigned long io_virt_offset;
struct pci_controller *hose;
WARN_ON(bus == NULL);
if (bus->self) {
pr_debug("IO mapping for PCI-PCI bridge %s\n",
pci_name(bus->self));
pr_debug(" virt=0x%016llx...0x%016llx\n",
bus->resource[0]->start + _IO_BASE,
bus->resource[0]->end + _IO_BASE);
return 0;
}
hose = pci_bus_to_host(bus);
phys_page = _ALIGN_DOWN(hose->io_base_phys, PAGE_SIZE);
size_page = _ALIGN_UP(hose->pci_io_size, PAGE_SIZE);
hose->io_base_alloc = NULL;
if (hose->pci_io_size == 0 || hose->io_base_phys == 0)
return 0;
area = __get_vm_area(size_page, 0, PHB_IO_BASE, PHB_IO_END);
if (area == NULL)
return -ENOMEM;
hose->io_base_alloc = area->addr;
hose->io_base_virt = (void __iomem *)(area->addr +
hose->io_base_phys - phys_page);
pr_debug("IO mapping for PHB %s\n", hose->dn->full_name);
pr_debug(" phys=0x%016llx, virt=0x%p (alloc=0x%p)\n",
hose->io_base_phys, hose->io_base_virt, hose->io_base_alloc);
pr_debug(" size=0x%016llx (alloc=0x%016lx)\n",
hose->pci_io_size, size_page);
if (__ioremap_at(phys_page, area->addr, size_page,
_PAGE_NO_CACHE | _PAGE_GUARDED) == NULL)
return -ENOMEM;
io_virt_offset = (unsigned long)hose->io_base_virt - _IO_BASE;
hose->io_resource.start += io_virt_offset;
hose->io_resource.end += io_virt_offset;
pr_debug(" hose->io_resource=%pR\n", &hose->io_resource);
return 0;
}
void __devinit pcibios_setup_phb_io_space(struct pci_controller *hose)
{
pcibios_map_io_space(hose->bus);
}
long sys_pciconfig_iobase(long which, unsigned long in_bus,
unsigned long in_devfn)
{
struct pci_controller* hose;
struct list_head *ln;
struct pci_bus *bus = NULL;
struct device_node *hose_node;
if (in_bus == 0 && of_machine_is_compatible("MacRISC4")) {
struct device_node *agp;
agp = of_find_compatible_node(NULL, NULL, "u3-agp");
if (agp)
in_bus = 0xf0;
of_node_put(agp);
}
for (ln = pci_root_buses.next; ln != &pci_root_buses; ln = ln->next) {
bus = pci_bus_b(ln);
if (in_bus >= bus->number && in_bus <= bus->subordinate)
break;
bus = NULL;
}
if (bus == NULL || bus->dev.of_node == NULL)
return -ENODEV;
hose_node = bus->dev.of_node;
hose = PCI_DN(hose_node)->phb;
switch (which) {
case IOBASE_BRIDGE_NUMBER:
return (long)hose->first_busno;
case IOBASE_MEMORY:
return (long)hose->pci_mem_offset;
case IOBASE_IO:
return (long)hose->io_base_phys;
case IOBASE_ISA_IO:
return (long)isa_io_base;
case IOBASE_ISA_MEM:
return -EINVAL;
}
return -EOPNOTSUPP;
}
int pcibus_to_node(struct pci_bus *bus)
{
struct pci_controller *phb = pci_bus_to_host(bus);
return phb->node;
}
