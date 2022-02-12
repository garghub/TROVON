static struct pcibios_fwaddrmap *pcibios_fwaddrmap_lookup(struct pci_dev *dev)
{
struct pcibios_fwaddrmap *map;
WARN_ON_SMP(!spin_is_locked(&pcibios_fwaddrmap_lock));
list_for_each_entry(map, &pcibios_fwaddrmappings, list)
if (map->dev == dev)
return map;
return NULL;
}
static void
pcibios_save_fw_addr(struct pci_dev *dev, int idx, resource_size_t fw_addr)
{
unsigned long flags;
struct pcibios_fwaddrmap *map;
if (pcibios_fw_addr_done)
return;
spin_lock_irqsave(&pcibios_fwaddrmap_lock, flags);
map = pcibios_fwaddrmap_lookup(dev);
if (!map) {
spin_unlock_irqrestore(&pcibios_fwaddrmap_lock, flags);
map = kzalloc(sizeof(*map), GFP_KERNEL);
if (!map)
return;
map->dev = pci_dev_get(dev);
map->fw_addr[idx] = fw_addr;
INIT_LIST_HEAD(&map->list);
spin_lock_irqsave(&pcibios_fwaddrmap_lock, flags);
list_add_tail(&map->list, &pcibios_fwaddrmappings);
} else
map->fw_addr[idx] = fw_addr;
spin_unlock_irqrestore(&pcibios_fwaddrmap_lock, flags);
}
resource_size_t pcibios_retrieve_fw_addr(struct pci_dev *dev, int idx)
{
unsigned long flags;
struct pcibios_fwaddrmap *map;
resource_size_t fw_addr = 0;
if (pcibios_fw_addr_done)
return 0;
spin_lock_irqsave(&pcibios_fwaddrmap_lock, flags);
map = pcibios_fwaddrmap_lookup(dev);
if (map)
fw_addr = map->fw_addr[idx];
spin_unlock_irqrestore(&pcibios_fwaddrmap_lock, flags);
return fw_addr;
}
static void __init pcibios_fw_addr_list_del(void)
{
unsigned long flags;
struct pcibios_fwaddrmap *entry, *next;
spin_lock_irqsave(&pcibios_fwaddrmap_lock, flags);
list_for_each_entry_safe(entry, next, &pcibios_fwaddrmappings, list) {
list_del(&entry->list);
pci_dev_put(entry->dev);
kfree(entry);
}
spin_unlock_irqrestore(&pcibios_fwaddrmap_lock, flags);
pcibios_fw_addr_done = true;
}
static int
skip_isa_ioresource_align(struct pci_dev *dev) {
if ((pci_probe & PCI_CAN_SKIP_ISA_ALIGN) &&
!(dev->bus->bridge_ctl & PCI_BRIDGE_CTL_ISA))
return 1;
return 0;
}
resource_size_t
pcibios_align_resource(void *data, const struct resource *res,
resource_size_t size, resource_size_t align)
{
struct pci_dev *dev = data;
resource_size_t start = res->start;
if (res->flags & IORESOURCE_IO) {
if (skip_isa_ioresource_align(dev))
return start;
if (start & 0x300)
start = (start + 0x3ff) & ~0x3ff;
}
return start;
}
static void pcibios_allocate_bridge_resources(struct pci_dev *dev)
{
int idx;
struct resource *r;
for (idx = PCI_BRIDGE_RESOURCES; idx < PCI_NUM_RESOURCES; idx++) {
r = &dev->resource[idx];
if (!r->flags)
continue;
if (r->parent)
continue;
if (!r->start || pci_claim_resource(dev, idx) < 0) {
r->start = r->end = 0;
r->flags = 0;
}
}
}
static void pcibios_allocate_bus_resources(struct pci_bus *bus)
{
struct pci_bus *child;
if (bus->self)
pcibios_allocate_bridge_resources(bus->self);
list_for_each_entry(child, &bus->children, node)
pcibios_allocate_bus_resources(child);
}
static void pcibios_allocate_dev_resources(struct pci_dev *dev, int pass)
{
int idx, disabled, i;
u16 command;
struct resource *r;
struct pci_check_idx_range idx_range[] = {
{ PCI_STD_RESOURCES, PCI_STD_RESOURCE_END },
#ifdef CONFIG_PCI_IOV
{ PCI_IOV_RESOURCES, PCI_IOV_RESOURCE_END },
#endif
};
pci_read_config_word(dev, PCI_COMMAND, &command);
for (i = 0; i < ARRAY_SIZE(idx_range); i++)
for (idx = idx_range[i].start; idx <= idx_range[i].end; idx++) {
r = &dev->resource[idx];
if (r->parent)
continue;
if (!r->start)
continue;
if (r->flags & IORESOURCE_IO)
disabled = !(command & PCI_COMMAND_IO);
else
disabled = !(command & PCI_COMMAND_MEMORY);
if (pass == disabled) {
dev_dbg(&dev->dev,
"BAR %d: reserving %pr (d=%d, p=%d)\n",
idx, r, disabled, pass);
if (pci_claim_resource(dev, idx) < 0) {
pcibios_save_fw_addr(dev,
idx, r->start);
r->end -= r->start;
r->start = 0;
}
}
}
if (!pass) {
r = &dev->resource[PCI_ROM_RESOURCE];
if (r->flags & IORESOURCE_ROM_ENABLE) {
u32 reg;
dev_dbg(&dev->dev, "disabling ROM %pR\n", r);
r->flags &= ~IORESOURCE_ROM_ENABLE;
pci_read_config_dword(dev, dev->rom_base_reg, &reg);
pci_write_config_dword(dev, dev->rom_base_reg,
reg & ~PCI_ROM_ADDRESS_ENABLE);
}
}
}
static void pcibios_allocate_resources(struct pci_bus *bus, int pass)
{
struct pci_dev *dev;
struct pci_bus *child;
list_for_each_entry(dev, &bus->devices, bus_list) {
pcibios_allocate_dev_resources(dev, pass);
child = dev->subordinate;
if (child)
pcibios_allocate_resources(child, pass);
}
}
static void pcibios_allocate_dev_rom_resource(struct pci_dev *dev)
{
struct resource *r;
r = &dev->resource[PCI_ROM_RESOURCE];
if (!r->flags || !r->start)
return;
if (r->parent)
return;
if (pci_claim_resource(dev, PCI_ROM_RESOURCE) < 0) {
r->end -= r->start;
r->start = 0;
}
}
static void pcibios_allocate_rom_resources(struct pci_bus *bus)
{
struct pci_dev *dev;
struct pci_bus *child;
list_for_each_entry(dev, &bus->devices, bus_list) {
pcibios_allocate_dev_rom_resource(dev);
child = dev->subordinate;
if (child)
pcibios_allocate_rom_resources(child);
}
}
static int __init pcibios_assign_resources(void)
{
struct pci_bus *bus;
if (!(pci_probe & PCI_ASSIGN_ROMS))
list_for_each_entry(bus, &pci_root_buses, node)
pcibios_allocate_rom_resources(bus);
pci_assign_unassigned_resources();
pcibios_fw_addr_list_del();
return 0;
}
void pcibios_resource_survey_bus(struct pci_bus *bus)
{
dev_printk(KERN_DEBUG, &bus->dev, "Allocating resources\n");
pcibios_allocate_bus_resources(bus);
pcibios_allocate_resources(bus, 0);
pcibios_allocate_resources(bus, 1);
if (!(pci_probe & PCI_ASSIGN_ROMS))
pcibios_allocate_rom_resources(bus);
}
void __init pcibios_resource_survey(void)
{
struct pci_bus *bus;
DBG("PCI: Allocating resources\n");
list_for_each_entry(bus, &pci_root_buses, node)
pcibios_allocate_bus_resources(bus);
list_for_each_entry(bus, &pci_root_buses, node)
pcibios_allocate_resources(bus, 0);
list_for_each_entry(bus, &pci_root_buses, node)
pcibios_allocate_resources(bus, 1);
e820_reserve_resources_late();
ioapic_insert_resources();
}
int pci_mmap_page_range(struct pci_dev *dev, struct vm_area_struct *vma,
enum pci_mmap_state mmap_state, int write_combine)
{
unsigned long prot;
if (mmap_state == pci_mmap_io)
return -EINVAL;
prot = pgprot_val(vma->vm_page_prot);
if (!pat_enabled && write_combine)
return -EINVAL;
if (pat_enabled && write_combine)
prot |= _PAGE_CACHE_WC;
else if (pat_enabled || boot_cpu_data.x86 > 3)
prot |= _PAGE_CACHE_UC_MINUS;
prot |= _PAGE_IOMAP;
vma->vm_page_prot = __pgprot(prot);
if (io_remap_pfn_range(vma, vma->vm_start, vma->vm_pgoff,
vma->vm_end - vma->vm_start,
vma->vm_page_prot))
return -EAGAIN;
vma->vm_ops = &pci_mmap_ops;
return 0;
}
