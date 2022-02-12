struct pci_controller *pcibios_alloc_controller(struct device_node *dev)
{
struct pci_controller *phb;
phb = zalloc_maybe_bootmem(sizeof(struct pci_controller), GFP_KERNEL);
if (!phb)
return NULL;
spin_lock(&hose_spinlock);
phb->global_number = global_phb_number++;
list_add_tail(&phb->list_node, &hose_list);
spin_unlock(&hose_spinlock);
phb->dn = dev;
phb->is_dynamic = mem_init_done;
return phb;
}
void pcibios_free_controller(struct pci_controller *phb)
{
spin_lock(&hose_spinlock);
list_del(&phb->list_node);
spin_unlock(&hose_spinlock);
if (phb->is_dynamic)
kfree(phb);
}
static resource_size_t pcibios_io_size(const struct pci_controller *hose)
{
return resource_size(&hose->io_resource);
}
int pcibios_vaddr_is_ioport(void __iomem *address)
{
int ret = 0;
struct pci_controller *hose;
resource_size_t size;
spin_lock(&hose_spinlock);
list_for_each_entry(hose, &hose_list, list_node) {
size = pcibios_io_size(hose);
if (address >= hose->io_base_virt &&
address < (hose->io_base_virt + size)) {
ret = 1;
break;
}
}
spin_unlock(&hose_spinlock);
return ret;
}
unsigned long pci_address_to_pio(phys_addr_t address)
{
struct pci_controller *hose;
resource_size_t size;
unsigned long ret = ~0;
spin_lock(&hose_spinlock);
list_for_each_entry(hose, &hose_list, list_node) {
size = pcibios_io_size(hose);
if (address >= hose->io_base_phys &&
address < (hose->io_base_phys + size)) {
unsigned long base =
(unsigned long)hose->io_base_virt - _IO_BASE;
ret = base + (address - hose->io_base_phys);
break;
}
}
spin_unlock(&hose_spinlock);
return ret;
}
int pci_domain_nr(struct pci_bus *bus)
{
struct pci_controller *hose = pci_bus_to_host(bus);
return hose->global_number;
}
struct pci_controller *pci_find_hose_for_OF_device(struct device_node *node)
{
while (node) {
struct pci_controller *hose, *tmp;
list_for_each_entry_safe(hose, tmp, &hose_list, list_node)
if (hose->dn == node)
return hose;
node = node->parent;
}
return NULL;
}
void pcibios_set_master(struct pci_dev *dev)
{
}
static struct resource *__pci_mmap_make_offset(struct pci_dev *dev,
resource_size_t *offset,
enum pci_mmap_state mmap_state)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
unsigned long io_offset = 0;
int i, res_bit;
if (!hose)
return NULL;
if (mmap_state == pci_mmap_mem) {
#if 0
*offset += hose->pci_mem_offset;
#endif
res_bit = IORESOURCE_MEM;
} else {
io_offset = (unsigned long)hose->io_base_virt - _IO_BASE;
*offset += io_offset;
res_bit = IORESOURCE_IO;
}
for (i = 0; i <= PCI_ROM_RESOURCE; i++) {
struct resource *rp = &dev->resource[i];
int flags = rp->flags;
if (i == PCI_ROM_RESOURCE)
flags |= IORESOURCE_MEM;
if ((flags & res_bit) == 0)
continue;
if (*offset < (rp->start & PAGE_MASK) || *offset > rp->end)
continue;
if (mmap_state == pci_mmap_io)
*offset += hose->io_base_phys - io_offset;
return rp;
}
return NULL;
}
static pgprot_t __pci_mmap_set_pgprot(struct pci_dev *dev, struct resource *rp,
pgprot_t protection,
enum pci_mmap_state mmap_state,
int write_combine)
{
pgprot_t prot = protection;
if (mmap_state != pci_mmap_mem)
write_combine = 0;
else if (write_combine == 0) {
if (rp->flags & IORESOURCE_PREFETCH)
write_combine = 1;
}
return pgprot_noncached(prot);
}
pgprot_t pci_phys_mem_access_prot(struct file *file,
unsigned long pfn,
unsigned long size,
pgprot_t prot)
{
struct pci_dev *pdev = NULL;
struct resource *found = NULL;
resource_size_t offset = ((resource_size_t)pfn) << PAGE_SHIFT;
int i;
if (page_is_ram(pfn))
return prot;
prot = pgprot_noncached(prot);
for_each_pci_dev(pdev) {
for (i = 0; i <= PCI_ROM_RESOURCE; i++) {
struct resource *rp = &pdev->resource[i];
int flags = rp->flags;
if ((flags & IORESOURCE_MEM) == 0)
continue;
if (offset < (rp->start & PAGE_MASK) ||
offset > rp->end)
continue;
found = rp;
break;
}
if (found)
break;
}
if (found) {
if (found->flags & IORESOURCE_PREFETCH)
prot = pgprot_noncached_wc(prot);
pci_dev_put(pdev);
}
pr_debug("PCI: Non-PCI map for %llx, prot: %lx\n",
(unsigned long long)offset, pgprot_val(prot));
return prot;
}
int pci_mmap_page_range(struct pci_dev *dev, struct vm_area_struct *vma,
enum pci_mmap_state mmap_state, int write_combine)
{
resource_size_t offset =
((resource_size_t)vma->vm_pgoff) << PAGE_SHIFT;
struct resource *rp;
int ret;
rp = __pci_mmap_make_offset(dev, &offset, mmap_state);
if (rp == NULL)
return -EINVAL;
vma->vm_pgoff = offset >> PAGE_SHIFT;
vma->vm_page_prot = __pci_mmap_set_pgprot(dev, rp,
vma->vm_page_prot,
mmap_state, write_combine);
ret = remap_pfn_range(vma, vma->vm_start, vma->vm_pgoff,
vma->vm_end - vma->vm_start, vma->vm_page_prot);
return ret;
}
int pci_legacy_read(struct pci_bus *bus, loff_t port, u32 *val, size_t size)
{
unsigned long offset;
struct pci_controller *hose = pci_bus_to_host(bus);
struct resource *rp = &hose->io_resource;
void __iomem *addr;
offset = (unsigned long)hose->io_base_virt - _IO_BASE;
offset += port;
if (!(rp->flags & IORESOURCE_IO))
return -ENXIO;
if (offset < rp->start || (offset + size) > rp->end)
return -ENXIO;
addr = hose->io_base_virt + port;
switch (size) {
case 1:
*((u8 *)val) = in_8(addr);
return 1;
case 2:
if (port & 1)
return -EINVAL;
*((u16 *)val) = in_le16(addr);
return 2;
case 4:
if (port & 3)
return -EINVAL;
*((u32 *)val) = in_le32(addr);
return 4;
}
return -EINVAL;
}
int pci_legacy_write(struct pci_bus *bus, loff_t port, u32 val, size_t size)
{
unsigned long offset;
struct pci_controller *hose = pci_bus_to_host(bus);
struct resource *rp = &hose->io_resource;
void __iomem *addr;
offset = (unsigned long)hose->io_base_virt - _IO_BASE;
offset += port;
if (!(rp->flags & IORESOURCE_IO))
return -ENXIO;
if (offset < rp->start || (offset + size) > rp->end)
return -ENXIO;
addr = hose->io_base_virt + port;
switch (size) {
case 1:
out_8(addr, val >> 24);
return 1;
case 2:
if (port & 1)
return -EINVAL;
out_le16(addr, val >> 16);
return 2;
case 4:
if (port & 3)
return -EINVAL;
out_le32(addr, val);
return 4;
}
return -EINVAL;
}
int pci_mmap_legacy_page_range(struct pci_bus *bus,
struct vm_area_struct *vma,
enum pci_mmap_state mmap_state)
{
struct pci_controller *hose = pci_bus_to_host(bus);
resource_size_t offset =
((resource_size_t)vma->vm_pgoff) << PAGE_SHIFT;
resource_size_t size = vma->vm_end - vma->vm_start;
struct resource *rp;
pr_debug("pci_mmap_legacy_page_range(%04x:%02x, %s @%llx..%llx)\n",
pci_domain_nr(bus), bus->number,
mmap_state == pci_mmap_mem ? "MEM" : "IO",
(unsigned long long)offset,
(unsigned long long)(offset + size - 1));
if (mmap_state == pci_mmap_mem) {
if ((offset + size) > hose->isa_mem_size) {
#ifdef CONFIG_MMU
pr_debug("Process %s (pid:%d) mapped non-existing PCI",
current->comm, current->pid);
pr_debug("legacy memory for 0%04x:%02x\n",
pci_domain_nr(bus), bus->number);
#endif
if (vma->vm_flags & VM_SHARED)
return shmem_zero_setup(vma);
return 0;
}
offset += hose->isa_mem_phys;
} else {
unsigned long io_offset = (unsigned long)hose->io_base_virt -
_IO_BASE;
unsigned long roffset = offset + io_offset;
rp = &hose->io_resource;
if (!(rp->flags & IORESOURCE_IO))
return -ENXIO;
if (roffset < rp->start || (roffset + size) > rp->end)
return -ENXIO;
offset += hose->io_base_phys;
}
pr_debug(" -> mapping phys %llx\n", (unsigned long long)offset);
vma->vm_pgoff = offset >> PAGE_SHIFT;
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
return remap_pfn_range(vma, vma->vm_start, vma->vm_pgoff,
vma->vm_end - vma->vm_start,
vma->vm_page_prot);
}
void pci_resource_to_user(const struct pci_dev *dev, int bar,
const struct resource *rsrc,
resource_size_t *start, resource_size_t *end)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
resource_size_t offset = 0;
if (hose == NULL)
return;
if (rsrc->flags & IORESOURCE_IO)
offset = (unsigned long)hose->io_base_virt - _IO_BASE;
#if 0
else if (rsrc->flags & IORESOURCE_MEM)
offset = hose->pci_mem_offset;
#endif
*start = rsrc->start - offset;
*end = rsrc->end - offset;
}
void pci_process_bridge_OF_ranges(struct pci_controller *hose,
struct device_node *dev, int primary)
{
int memno = 0, isa_hole = -1;
unsigned long long isa_mb = 0;
struct resource *res;
struct of_pci_range range;
struct of_pci_range_parser parser;
pr_info("PCI host bridge %s %s ranges:\n",
dev->full_name, primary ? "(primary)" : "");
if (of_pci_range_parser_init(&parser, dev))
return;
pr_debug("Parsing ranges property...\n");
for_each_of_pci_range(&parser, &range) {
pr_debug("pci_space: 0x%08x pci_addr:0x%016llx ",
range.pci_space, range.pci_addr);
pr_debug("cpu_addr:0x%016llx size:0x%016llx\n",
range.cpu_addr, range.size);
if (range.cpu_addr == OF_BAD_ADDR || range.size == 0)
continue;
res = NULL;
switch (range.flags & IORESOURCE_TYPE_BITS) {
case IORESOURCE_IO:
pr_info(" IO 0x%016llx..0x%016llx -> 0x%016llx\n",
range.cpu_addr, range.cpu_addr + range.size - 1,
range.pci_addr);
if (hose->pci_io_size) {
pr_info(" \\--> Skipped (too many) !\n");
continue;
}
if (range.size > 0x01000000)
range.size = 0x01000000;
hose->io_base_virt = ioremap(range.cpu_addr,
range.size);
if (primary)
isa_io_base =
(unsigned long)hose->io_base_virt;
hose->pci_io_size = range.pci_addr + range.size;
hose->io_base_phys = range.cpu_addr - range.pci_addr;
res = &hose->io_resource;
range.cpu_addr = range.pci_addr;
break;
case IORESOURCE_MEM:
pr_info(" MEM 0x%016llx..0x%016llx -> 0x%016llx %s\n",
range.cpu_addr, range.cpu_addr + range.size - 1,
range.pci_addr,
(range.pci_space & 0x40000000) ?
"Prefetch" : "");
if (memno >= 3) {
pr_info(" \\--> Skipped (too many) !\n");
continue;
}
if (range.pci_addr == 0) {
isa_mb = range.cpu_addr;
isa_hole = memno;
if (primary || isa_mem_base == 0)
isa_mem_base = range.cpu_addr;
hose->isa_mem_phys = range.cpu_addr;
hose->isa_mem_size = range.size;
}
if (memno == 0 ||
(isa_hole >= 0 && range.pci_addr != 0 &&
hose->pci_mem_offset == isa_mb))
hose->pci_mem_offset = range.cpu_addr -
range.pci_addr;
else if (range.pci_addr != 0 &&
hose->pci_mem_offset != range.cpu_addr -
range.pci_addr) {
pr_info(" \\--> Skipped (offset mismatch) !\n");
continue;
}
res = &hose->mem_resources[memno++];
break;
}
if (res != NULL) {
res->name = dev->full_name;
res->flags = range.flags;
res->start = range.cpu_addr;
res->end = range.cpu_addr + range.size - 1;
res->parent = res->child = res->sibling = NULL;
}
}
if (isa_hole >= 0 && hose->pci_mem_offset != isa_mb) {
unsigned int next = isa_hole + 1;
pr_info(" Removing ISA hole at 0x%016llx\n", isa_mb);
if (next < memno)
memmove(&hose->mem_resources[isa_hole],
&hose->mem_resources[next],
sizeof(struct resource) * (memno - next));
hose->mem_resources[--memno].flags = 0;
}
}
int pci_proc_domain(struct pci_bus *bus)
{
return 0;
}
static void pcibios_fixup_resources(struct pci_dev *dev)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
int i;
if (!hose) {
pr_err("No host bridge for PCI dev %s !\n",
pci_name(dev));
return;
}
for (i = 0; i < DEVICE_COUNT_RESOURCE; i++) {
struct resource *res = dev->resource + i;
if (!res->flags)
continue;
if (res->start == 0) {
pr_debug("PCI:%s Resource %d %016llx-%016llx [%x]",
pci_name(dev), i,
(unsigned long long)res->start,
(unsigned long long)res->end,
(unsigned int)res->flags);
pr_debug("is unassigned\n");
res->end -= res->start;
res->start = 0;
res->flags |= IORESOURCE_UNSET;
continue;
}
pr_debug("PCI:%s Resource %d %016llx-%016llx [%x]\n",
pci_name(dev), i,
(unsigned long long)res->start,
(unsigned long long)res->end,
(unsigned int)res->flags);
}
}
static int pcibios_uninitialized_bridge_resource(struct pci_bus *bus,
struct resource *res)
{
struct pci_controller *hose = pci_bus_to_host(bus);
struct pci_dev *dev = bus->self;
resource_size_t offset;
u16 command;
int i;
if (res->flags & IORESOURCE_MEM) {
if (res->start != hose->pci_mem_offset)
return 0;
pci_read_config_word(dev, PCI_COMMAND, &command);
if ((command & PCI_COMMAND_MEMORY) == 0)
return 1;
for (i = 0; i < 3; i++) {
if ((hose->mem_resources[i].flags & IORESOURCE_MEM) &&
hose->mem_resources[i].start == hose->pci_mem_offset)
return 0;
}
return 1;
} else {
offset = (unsigned long)hose->io_base_virt - _IO_BASE;
if (((res->start - offset) & 0xfffffffful) != 0)
return 0;
pci_read_config_word(dev, PCI_COMMAND, &command);
if (command & PCI_COMMAND_IO)
return 0;
return 1;
}
}
static void pcibios_fixup_bridge(struct pci_bus *bus)
{
struct resource *res;
int i;
struct pci_dev *dev = bus->self;
pci_bus_for_each_resource(bus, res, i) {
if (!res)
continue;
if (!res->flags)
continue;
if (i >= 3 && bus->self->transparent)
continue;
pr_debug("PCI:%s Bus rsrc %d %016llx-%016llx [%x] fixup...\n",
pci_name(dev), i,
(unsigned long long)res->start,
(unsigned long long)res->end,
(unsigned int)res->flags);
if (pcibios_uninitialized_bridge_resource(bus, res)) {
res->flags = 0;
pr_debug("PCI:%s (unassigned)\n",
pci_name(dev));
} else {
pr_debug("PCI:%s %016llx-%016llx\n",
pci_name(dev),
(unsigned long long)res->start,
(unsigned long long)res->end);
}
}
}
void pcibios_setup_bus_self(struct pci_bus *bus)
{
if (bus->self != NULL)
pcibios_fixup_bridge(bus);
}
void pcibios_setup_bus_devices(struct pci_bus *bus)
{
struct pci_dev *dev;
pr_debug("PCI: Fixup bus devices %d (%s)\n",
bus->number, bus->self ? pci_name(bus->self) : "PHB");
list_for_each_entry(dev, &bus->devices, bus_list) {
dev->dev.of_node = pci_device_to_OF_node(dev);
set_dev_node(&dev->dev, pcibus_to_node(dev->bus));
dev->irq = of_irq_parse_and_map_pci(dev, 0, 0);
}
}
void pcibios_fixup_bus(struct pci_bus *bus)
{
if (bus->self != NULL)
pci_read_bridge_bases(bus);
pcibios_setup_bus_self(bus);
pcibios_setup_bus_devices(bus);
}
static int skip_isa_ioresource_align(struct pci_dev *dev)
{
return 0;
}
resource_size_t pcibios_align_resource(void *data, const struct resource *res,
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
static int __init reparent_resources(struct resource *parent,
struct resource *res)
{
struct resource *p, **pp;
struct resource **firstpp = NULL;
for (pp = &parent->child; (p = *pp) != NULL; pp = &p->sibling) {
if (p->end < res->start)
continue;
if (res->end < p->start)
break;
if (p->start < res->start || p->end > res->end)
return -1;
if (firstpp == NULL)
firstpp = pp;
}
if (firstpp == NULL)
return -1;
res->parent = parent;
res->child = *firstpp;
res->sibling = *pp;
*firstpp = res;
*pp = NULL;
for (p = res->child; p != NULL; p = p->sibling) {
p->parent = res;
pr_debug("PCI: Reparented %s [%llx..%llx] under %s\n",
p->name,
(unsigned long long)p->start,
(unsigned long long)p->end, res->name);
}
return 0;
}
static void pcibios_allocate_bus_resources(struct pci_bus *bus)
{
struct pci_bus *b;
int i;
struct resource *res, *pr;
pr_debug("PCI: Allocating bus resources for %04x:%02x...\n",
pci_domain_nr(bus), bus->number);
pci_bus_for_each_resource(bus, res, i) {
if (!res || !res->flags
|| res->start > res->end || res->parent)
continue;
if (bus->parent == NULL)
pr = (res->flags & IORESOURCE_IO) ?
&ioport_resource : &iomem_resource;
else {
pr = pci_find_parent_resource(bus->self, res);
if (pr == res) {
continue;
}
}
pr_debug("PCI: %s (bus %d) bridge rsrc %d: %016llx-%016llx ",
bus->self ? pci_name(bus->self) : "PHB",
bus->number, i,
(unsigned long long)res->start,
(unsigned long long)res->end);
pr_debug("[0x%x], parent %p (%s)\n",
(unsigned int)res->flags,
pr, (pr && pr->name) ? pr->name : "nil");
if (pr && !(pr->flags & IORESOURCE_UNSET)) {
struct pci_dev *dev = bus->self;
if (request_resource(pr, res) == 0)
continue;
if (reparent_resources(pr, res) == 0)
continue;
if (dev && i < PCI_BRIDGE_RESOURCE_NUM &&
pci_claim_bridge_resource(dev,
i + PCI_BRIDGE_RESOURCES) == 0)
continue;
}
pr_warn("PCI: Cannot allocate resource region ");
pr_cont("%d of PCI bridge %d, will remap\n", i, bus->number);
res->start = res->end = 0;
res->flags = 0;
}
list_for_each_entry(b, &bus->children, node)
pcibios_allocate_bus_resources(b);
}
static inline void alloc_resource(struct pci_dev *dev, int idx)
{
struct resource *pr, *r = &dev->resource[idx];
pr_debug("PCI: Allocating %s: Resource %d: %016llx..%016llx [%x]\n",
pci_name(dev), idx,
(unsigned long long)r->start,
(unsigned long long)r->end,
(unsigned int)r->flags);
pr = pci_find_parent_resource(dev, r);
if (!pr || (pr->flags & IORESOURCE_UNSET) ||
request_resource(pr, r) < 0) {
pr_warn("PCI: Cannot allocate resource region %d ", idx);
pr_cont("of device %s, will remap\n", pci_name(dev));
if (pr)
pr_debug("PCI: parent is %p: %016llx-%016llx [%x]\n",
pr,
(unsigned long long)pr->start,
(unsigned long long)pr->end,
(unsigned int)pr->flags);
r->flags |= IORESOURCE_UNSET;
r->end -= r->start;
r->start = 0;
}
}
static void __init pcibios_allocate_resources(int pass)
{
struct pci_dev *dev = NULL;
int idx, disabled;
u16 command;
struct resource *r;
for_each_pci_dev(dev) {
pci_read_config_word(dev, PCI_COMMAND, &command);
for (idx = 0; idx <= PCI_ROM_RESOURCE; idx++) {
r = &dev->resource[idx];
if (r->parent)
continue;
if (!r->flags || (r->flags & IORESOURCE_UNSET))
continue;
if (idx == PCI_ROM_RESOURCE)
disabled = 1;
if (r->flags & IORESOURCE_IO)
disabled = !(command & PCI_COMMAND_IO);
else
disabled = !(command & PCI_COMMAND_MEMORY);
if (pass == disabled)
alloc_resource(dev, idx);
}
if (pass)
continue;
r = &dev->resource[PCI_ROM_RESOURCE];
if (r->flags) {
u32 reg;
pci_read_config_dword(dev, dev->rom_base_reg, &reg);
if (reg & PCI_ROM_ADDRESS_ENABLE) {
pr_debug("PCI: Switching off ROM of %s\n",
pci_name(dev));
r->flags &= ~IORESOURCE_ROM_ENABLE;
pci_write_config_dword(dev, dev->rom_base_reg,
reg & ~PCI_ROM_ADDRESS_ENABLE);
}
}
}
}
static void __init pcibios_reserve_legacy_regions(struct pci_bus *bus)
{
struct pci_controller *hose = pci_bus_to_host(bus);
resource_size_t offset;
struct resource *res, *pres;
int i;
pr_debug("Reserving legacy ranges for domain %04x\n",
pci_domain_nr(bus));
if (!(hose->io_resource.flags & IORESOURCE_IO))
goto no_io;
offset = (unsigned long)hose->io_base_virt - _IO_BASE;
res = kzalloc(sizeof(struct resource), GFP_KERNEL);
BUG_ON(res == NULL);
res->name = "Legacy IO";
res->flags = IORESOURCE_IO;
res->start = offset;
res->end = (offset + 0xfff) & 0xfffffffful;
pr_debug("Candidate legacy IO: %pR\n", res);
if (request_resource(&hose->io_resource, res)) {
pr_debug("PCI %04x:%02x Cannot reserve Legacy IO %pR\n",
pci_domain_nr(bus), bus->number, res);
kfree(res);
}
no_io:
offset = hose->pci_mem_offset;
pr_debug("hose mem offset: %016llx\n", (unsigned long long)offset);
for (i = 0; i < 3; i++) {
pres = &hose->mem_resources[i];
if (!(pres->flags & IORESOURCE_MEM))
continue;
pr_debug("hose mem res: %pR\n", pres);
if ((pres->start - offset) <= 0xa0000 &&
(pres->end - offset) >= 0xbffff)
break;
}
if (i >= 3)
return;
res = kzalloc(sizeof(struct resource), GFP_KERNEL);
BUG_ON(res == NULL);
res->name = "Legacy VGA memory";
res->flags = IORESOURCE_MEM;
res->start = 0xa0000 + offset;
res->end = 0xbffff + offset;
pr_debug("Candidate VGA memory: %pR\n", res);
if (request_resource(pres, res)) {
pr_debug("PCI %04x:%02x Cannot reserve VGA memory %pR\n",
pci_domain_nr(bus), bus->number, res);
kfree(res);
}
}
void __init pcibios_resource_survey(void)
{
struct pci_bus *b;
list_for_each_entry(b, &pci_root_buses, node)
pcibios_allocate_bus_resources(b);
pcibios_allocate_resources(0);
pcibios_allocate_resources(1);
list_for_each_entry(b, &pci_root_buses, node)
pcibios_reserve_legacy_regions(b);
pr_debug("PCI: Assigning unassigned resources...\n");
pci_assign_unassigned_resources();
}
void pcibios_claim_one_bus(struct pci_bus *bus)
{
struct pci_dev *dev;
struct pci_bus *child_bus;
list_for_each_entry(dev, &bus->devices, bus_list) {
int i;
for (i = 0; i < PCI_NUM_RESOURCES; i++) {
struct resource *r = &dev->resource[i];
if (r->parent || !r->start || !r->flags)
continue;
pr_debug("PCI: Claiming %s: ", pci_name(dev));
pr_debug("Resource %d: %016llx..%016llx [%x]\n",
i, (unsigned long long)r->start,
(unsigned long long)r->end,
(unsigned int)r->flags);
if (pci_claim_resource(dev, i) == 0)
continue;
pci_claim_bridge_resource(dev, i);
}
}
list_for_each_entry(child_bus, &bus->children, node)
pcibios_claim_one_bus(child_bus);
}
void pcibios_finish_adding_to_bus(struct pci_bus *bus)
{
pr_debug("PCI: Finishing adding to hotplug bus %04x:%02x\n",
pci_domain_nr(bus), bus->number);
pcibios_allocate_bus_resources(bus);
pcibios_claim_one_bus(bus);
pci_bus_add_devices(bus);
}
static void pcibios_setup_phb_resources(struct pci_controller *hose,
struct list_head *resources)
{
unsigned long io_offset;
struct resource *res;
int i;
res = &hose->io_resource;
io_offset = (unsigned long)hose->io_base_virt - isa_io_base;
res->start = (res->start + io_offset) & 0xffffffffu;
res->end = (res->end + io_offset) & 0xffffffffu;
if (!res->flags) {
pr_warn("PCI: I/O resource not set for host ");
pr_cont("bridge %s (domain %d)\n",
hose->dn->full_name, hose->global_number);
res->start = (unsigned long)hose->io_base_virt - isa_io_base;
res->end = res->start + IO_SPACE_LIMIT;
res->flags = IORESOURCE_IO;
}
pci_add_resource_offset(resources, res,
(__force resource_size_t)(hose->io_base_virt - _IO_BASE));
pr_debug("PCI: PHB IO resource = %016llx-%016llx [%lx]\n",
(unsigned long long)res->start,
(unsigned long long)res->end,
(unsigned long)res->flags);
for (i = 0; i < 3; ++i) {
res = &hose->mem_resources[i];
if (!res->flags) {
if (i > 0)
continue;
pr_err("PCI: Memory resource 0 not set for ");
pr_cont("host bridge %s (domain %d)\n",
hose->dn->full_name, hose->global_number);
res->start = hose->pci_mem_offset;
res->end = (resource_size_t)-1LL;
res->flags = IORESOURCE_MEM;
}
pci_add_resource_offset(resources, res, hose->pci_mem_offset);
pr_debug("PCI: PHB MEM resource %d = %016llx-%016llx [%lx]\n",
i, (unsigned long long)res->start,
(unsigned long long)res->end,
(unsigned long)res->flags);
}
pr_debug("PCI: PHB MEM offset = %016llx\n",
(unsigned long long)hose->pci_mem_offset);
pr_debug("PCI: PHB IO offset = %08lx\n",
(unsigned long)hose->io_base_virt - _IO_BASE);
}
struct device_node *pcibios_get_phb_of_node(struct pci_bus *bus)
{
struct pci_controller *hose = bus->sysdata;
return of_node_get(hose->dn);
}
static void pcibios_scan_phb(struct pci_controller *hose)
{
LIST_HEAD(resources);
struct pci_bus *bus;
struct device_node *node = hose->dn;
pr_debug("PCI: Scanning PHB %s\n", of_node_full_name(node));
pcibios_setup_phb_resources(hose, &resources);
bus = pci_scan_root_bus(hose->parent, hose->first_busno,
hose->ops, hose, &resources);
if (bus == NULL) {
pr_err("Failed to create bus for PCI domain %04x\n",
hose->global_number);
pci_free_resource_list(&resources);
return;
}
bus->busn_res.start = hose->first_busno;
hose->bus = bus;
hose->last_busno = bus->busn_res.end;
}
static int __init pcibios_init(void)
{
struct pci_controller *hose, *tmp;
int next_busno = 0;
pr_info("PCI: Probing PCI hardware\n");
list_for_each_entry_safe(hose, tmp, &hose_list, list_node) {
hose->last_busno = 0xff;
pcibios_scan_phb(hose);
if (next_busno <= hose->last_busno)
next_busno = hose->last_busno + 1;
}
pci_bus_count = next_busno;
pcibios_resource_survey();
return 0;
}
static struct pci_controller *pci_bus_to_hose(int bus)
{
struct pci_controller *hose, *tmp;
list_for_each_entry_safe(hose, tmp, &hose_list, list_node)
if (bus >= hose->first_busno && bus <= hose->last_busno)
return hose;
return NULL;
}
long sys_pciconfig_iobase(long which, unsigned long bus, unsigned long devfn)
{
struct pci_controller *hose;
long result = -EOPNOTSUPP;
hose = pci_bus_to_hose(bus);
if (!hose)
return -ENODEV;
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
return (long)isa_mem_base;
}
return result;
}
static int
null_read_config(struct pci_bus *bus, unsigned int devfn, int offset,
int len, u32 *val)
{
return PCIBIOS_DEVICE_NOT_FOUND;
}
static int
null_write_config(struct pci_bus *bus, unsigned int devfn, int offset,
int len, u32 val)
{
return PCIBIOS_DEVICE_NOT_FOUND;
}
static struct pci_bus *
fake_pci_bus(struct pci_controller *hose, int busnr)
{
static struct pci_bus bus;
if (!hose)
pr_err("Can't find hose for PCI bus %d!\n", busnr);
bus.number = busnr;
bus.sysdata = hose;
bus.ops = hose ? hose->ops : &null_pci_ops;
return &bus;
}
int early_find_capability(struct pci_controller *hose, int bus, int devfn,
int cap)
{
return pci_bus_find_capability(fake_pci_bus(hose, bus), devfn, cap);
}
