void pci_realloc(void)
{
pci_realloc_enable = 1;
}
static void add_to_list(struct resource_list_x *head,
struct pci_dev *dev, struct resource *res,
resource_size_t add_size)
{
struct resource_list_x *list = head;
struct resource_list_x *ln = list->next;
struct resource_list_x *tmp;
tmp = kmalloc(sizeof(*tmp), GFP_KERNEL);
if (!tmp) {
pr_warning("add_to_list: kmalloc() failed!\n");
return;
}
tmp->next = ln;
tmp->res = res;
tmp->dev = dev;
tmp->start = res->start;
tmp->end = res->end;
tmp->flags = res->flags;
tmp->add_size = add_size;
list->next = tmp;
}
static void add_to_failed_list(struct resource_list_x *head,
struct pci_dev *dev, struct resource *res)
{
add_to_list(head, dev, res, 0);
}
static void __dev_sort_resources(struct pci_dev *dev,
struct resource_list *head)
{
u16 class = dev->class >> 8;
if (class == PCI_CLASS_NOT_DEFINED || class == PCI_CLASS_BRIDGE_HOST)
return;
if (class == PCI_CLASS_SYSTEM_PIC) {
u16 command;
pci_read_config_word(dev, PCI_COMMAND, &command);
if (command & (PCI_COMMAND_IO | PCI_COMMAND_MEMORY))
return;
}
pdev_sort_resources(dev, head);
}
static inline void reset_resource(struct resource *res)
{
res->start = 0;
res->end = 0;
res->flags = 0;
}
static void adjust_resources_sorted(struct resource_list_x *add_head,
struct resource_list *head)
{
struct resource *res;
struct resource_list_x *list, *tmp, *prev;
struct resource_list *hlist;
resource_size_t add_size;
int idx;
prev = add_head;
for (list = add_head->next; list;) {
res = list->res;
if (!res->flags)
goto out;
for (hlist = head->next; hlist && hlist->res != res;
hlist = hlist->next);
if (!hlist) {
prev = list;
list = list->next;
continue;
}
idx = res - &list->dev->resource[0];
add_size=list->add_size;
if (!resource_size(res) && add_size) {
res->end = res->start + add_size - 1;
if(pci_assign_resource(list->dev, idx))
reset_resource(res);
} else if (add_size) {
adjust_resource(res, res->start,
resource_size(res) + add_size);
}
out:
tmp = list;
prev->next = list = list->next;
kfree(tmp);
}
}
static void assign_requested_resources_sorted(struct resource_list *head,
struct resource_list_x *fail_head)
{
struct resource *res;
struct resource_list *list;
int idx;
for (list = head->next; list; list = list->next) {
res = list->res;
idx = res - &list->dev->resource[0];
if (resource_size(res) && pci_assign_resource(list->dev, idx)) {
if (fail_head && !pci_is_root_bus(list->dev->bus)) {
if (!((idx == PCI_ROM_RESOURCE) &&
(!(res->flags & IORESOURCE_ROM_ENABLE))))
add_to_failed_list(fail_head, list->dev, res);
}
reset_resource(res);
}
}
}
static void __assign_resources_sorted(struct resource_list *head,
struct resource_list_x *add_head,
struct resource_list_x *fail_head)
{
assign_requested_resources_sorted(head, fail_head);
if (add_head)
adjust_resources_sorted(add_head, head);
free_list(resource_list, head);
}
static void pdev_assign_resources_sorted(struct pci_dev *dev,
struct resource_list_x *fail_head)
{
struct resource_list head;
head.next = NULL;
__dev_sort_resources(dev, &head);
__assign_resources_sorted(&head, NULL, fail_head);
}
static void pbus_assign_resources_sorted(const struct pci_bus *bus,
struct resource_list_x *add_head,
struct resource_list_x *fail_head)
{
struct pci_dev *dev;
struct resource_list head;
head.next = NULL;
list_for_each_entry(dev, &bus->devices, bus_list)
__dev_sort_resources(dev, &head);
__assign_resources_sorted(&head, add_head, fail_head);
}
void pci_setup_cardbus(struct pci_bus *bus)
{
struct pci_dev *bridge = bus->self;
struct resource *res;
struct pci_bus_region region;
dev_info(&bridge->dev, "CardBus bridge to [bus %02x-%02x]\n",
bus->secondary, bus->subordinate);
res = bus->resource[0];
pcibios_resource_to_bus(bridge, &region, res);
if (res->flags & IORESOURCE_IO) {
dev_info(&bridge->dev, " bridge window %pR\n", res);
pci_write_config_dword(bridge, PCI_CB_IO_BASE_0,
region.start);
pci_write_config_dword(bridge, PCI_CB_IO_LIMIT_0,
region.end);
}
res = bus->resource[1];
pcibios_resource_to_bus(bridge, &region, res);
if (res->flags & IORESOURCE_IO) {
dev_info(&bridge->dev, " bridge window %pR\n", res);
pci_write_config_dword(bridge, PCI_CB_IO_BASE_1,
region.start);
pci_write_config_dword(bridge, PCI_CB_IO_LIMIT_1,
region.end);
}
res = bus->resource[2];
pcibios_resource_to_bus(bridge, &region, res);
if (res->flags & IORESOURCE_MEM) {
dev_info(&bridge->dev, " bridge window %pR\n", res);
pci_write_config_dword(bridge, PCI_CB_MEMORY_BASE_0,
region.start);
pci_write_config_dword(bridge, PCI_CB_MEMORY_LIMIT_0,
region.end);
}
res = bus->resource[3];
pcibios_resource_to_bus(bridge, &region, res);
if (res->flags & IORESOURCE_MEM) {
dev_info(&bridge->dev, " bridge window %pR\n", res);
pci_write_config_dword(bridge, PCI_CB_MEMORY_BASE_1,
region.start);
pci_write_config_dword(bridge, PCI_CB_MEMORY_LIMIT_1,
region.end);
}
}
static void pci_setup_bridge_io(struct pci_bus *bus)
{
struct pci_dev *bridge = bus->self;
struct resource *res;
struct pci_bus_region region;
u32 l, io_upper16;
res = bus->resource[0];
pcibios_resource_to_bus(bridge, &region, res);
if (res->flags & IORESOURCE_IO) {
pci_read_config_dword(bridge, PCI_IO_BASE, &l);
l &= 0xffff0000;
l |= (region.start >> 8) & 0x00f0;
l |= region.end & 0xf000;
io_upper16 = (region.end & 0xffff0000) | (region.start >> 16);
dev_info(&bridge->dev, " bridge window %pR\n", res);
} else {
io_upper16 = 0;
l = 0x00f0;
dev_info(&bridge->dev, " bridge window [io disabled]\n");
}
pci_write_config_dword(bridge, PCI_IO_BASE_UPPER16, 0x0000ffff);
pci_write_config_dword(bridge, PCI_IO_BASE, l);
pci_write_config_dword(bridge, PCI_IO_BASE_UPPER16, io_upper16);
}
static void pci_setup_bridge_mmio(struct pci_bus *bus)
{
struct pci_dev *bridge = bus->self;
struct resource *res;
struct pci_bus_region region;
u32 l;
res = bus->resource[1];
pcibios_resource_to_bus(bridge, &region, res);
if (res->flags & IORESOURCE_MEM) {
l = (region.start >> 16) & 0xfff0;
l |= region.end & 0xfff00000;
dev_info(&bridge->dev, " bridge window %pR\n", res);
} else {
l = 0x0000fff0;
dev_info(&bridge->dev, " bridge window [mem disabled]\n");
}
pci_write_config_dword(bridge, PCI_MEMORY_BASE, l);
}
static void pci_setup_bridge_mmio_pref(struct pci_bus *bus)
{
struct pci_dev *bridge = bus->self;
struct resource *res;
struct pci_bus_region region;
u32 l, bu, lu;
pci_write_config_dword(bridge, PCI_PREF_LIMIT_UPPER32, 0);
bu = lu = 0;
res = bus->resource[2];
pcibios_resource_to_bus(bridge, &region, res);
if (res->flags & IORESOURCE_PREFETCH) {
l = (region.start >> 16) & 0xfff0;
l |= region.end & 0xfff00000;
if (res->flags & IORESOURCE_MEM_64) {
bu = upper_32_bits(region.start);
lu = upper_32_bits(region.end);
}
dev_info(&bridge->dev, " bridge window %pR\n", res);
} else {
l = 0x0000fff0;
dev_info(&bridge->dev, " bridge window [mem pref disabled]\n");
}
pci_write_config_dword(bridge, PCI_PREF_MEMORY_BASE, l);
pci_write_config_dword(bridge, PCI_PREF_BASE_UPPER32, bu);
pci_write_config_dword(bridge, PCI_PREF_LIMIT_UPPER32, lu);
}
static void __pci_setup_bridge(struct pci_bus *bus, unsigned long type)
{
struct pci_dev *bridge = bus->self;
dev_info(&bridge->dev, "PCI bridge to [bus %02x-%02x]\n",
bus->secondary, bus->subordinate);
if (type & IORESOURCE_IO)
pci_setup_bridge_io(bus);
if (type & IORESOURCE_MEM)
pci_setup_bridge_mmio(bus);
if (type & IORESOURCE_PREFETCH)
pci_setup_bridge_mmio_pref(bus);
pci_write_config_word(bridge, PCI_BRIDGE_CONTROL, bus->bridge_ctl);
}
static void pci_setup_bridge(struct pci_bus *bus)
{
unsigned long type = IORESOURCE_IO | IORESOURCE_MEM |
IORESOURCE_PREFETCH;
__pci_setup_bridge(bus, type);
}
static void pci_bridge_check_ranges(struct pci_bus *bus)
{
u16 io;
u32 pmem;
struct pci_dev *bridge = bus->self;
struct resource *b_res;
b_res = &bridge->resource[PCI_BRIDGE_RESOURCES];
b_res[1].flags |= IORESOURCE_MEM;
pci_read_config_word(bridge, PCI_IO_BASE, &io);
if (!io) {
pci_write_config_word(bridge, PCI_IO_BASE, 0xf0f0);
pci_read_config_word(bridge, PCI_IO_BASE, &io);
pci_write_config_word(bridge, PCI_IO_BASE, 0x0);
}
if (io)
b_res[0].flags |= IORESOURCE_IO;
if (bridge->vendor == PCI_VENDOR_ID_DEC && bridge->device == 0x0001)
return;
pci_read_config_dword(bridge, PCI_PREF_MEMORY_BASE, &pmem);
if (!pmem) {
pci_write_config_dword(bridge, PCI_PREF_MEMORY_BASE,
0xfff0fff0);
pci_read_config_dword(bridge, PCI_PREF_MEMORY_BASE, &pmem);
pci_write_config_dword(bridge, PCI_PREF_MEMORY_BASE, 0x0);
}
if (pmem) {
b_res[2].flags |= IORESOURCE_MEM | IORESOURCE_PREFETCH;
if ((pmem & PCI_PREF_RANGE_TYPE_MASK) ==
PCI_PREF_RANGE_TYPE_64) {
b_res[2].flags |= IORESOURCE_MEM_64;
b_res[2].flags |= PCI_PREF_RANGE_TYPE_64;
}
}
if (b_res[2].flags & IORESOURCE_MEM_64) {
u32 mem_base_hi, tmp;
pci_read_config_dword(bridge, PCI_PREF_BASE_UPPER32,
&mem_base_hi);
pci_write_config_dword(bridge, PCI_PREF_BASE_UPPER32,
0xffffffff);
pci_read_config_dword(bridge, PCI_PREF_BASE_UPPER32, &tmp);
if (!tmp)
b_res[2].flags &= ~IORESOURCE_MEM_64;
pci_write_config_dword(bridge, PCI_PREF_BASE_UPPER32,
mem_base_hi);
}
}
static struct resource *find_free_bus_resource(struct pci_bus *bus, unsigned long type)
{
int i;
struct resource *r;
unsigned long type_mask = IORESOURCE_IO | IORESOURCE_MEM |
IORESOURCE_PREFETCH;
pci_bus_for_each_resource(bus, r, i) {
if (r == &ioport_resource || r == &iomem_resource)
continue;
if (r && (r->flags & type_mask) == type && !r->parent)
return r;
}
return NULL;
}
static resource_size_t calculate_iosize(resource_size_t size,
resource_size_t min_size,
resource_size_t size1,
resource_size_t old_size,
resource_size_t align)
{
if (size < min_size)
size = min_size;
if (old_size == 1 )
old_size = 0;
#if defined(CONFIG_ISA) || defined(CONFIG_EISA)
size = (size & 0xff) + ((size & ~0xffUL) << 2);
#endif
size = ALIGN(size + size1, align);
if (size < old_size)
size = old_size;
return size;
}
static resource_size_t calculate_memsize(resource_size_t size,
resource_size_t min_size,
resource_size_t size1,
resource_size_t old_size,
resource_size_t align)
{
if (size < min_size)
size = min_size;
if (old_size == 1 )
old_size = 0;
if (size < old_size)
size = old_size;
size = ALIGN(size + size1, align);
return size;
}
static void pbus_size_io(struct pci_bus *bus, resource_size_t min_size,
resource_size_t add_size, struct resource_list_x *add_head)
{
struct pci_dev *dev;
struct resource *b_res = find_free_bus_resource(bus, IORESOURCE_IO);
unsigned long size = 0, size0 = 0, size1 = 0;
if (!b_res)
return;
list_for_each_entry(dev, &bus->devices, bus_list) {
int i;
for (i = 0; i < PCI_NUM_RESOURCES; i++) {
struct resource *r = &dev->resource[i];
unsigned long r_size;
if (r->parent || !(r->flags & IORESOURCE_IO))
continue;
r_size = resource_size(r);
if (r_size < 0x400)
size += r_size;
else
size1 += r_size;
}
}
size0 = calculate_iosize(size, min_size, size1,
resource_size(b_res), 4096);
size1 = (!add_head || (add_head && !add_size)) ? size0 :
calculate_iosize(size, min_size+add_size, size1,
resource_size(b_res), 4096);
if (!size0 && !size1) {
if (b_res->start || b_res->end)
dev_info(&bus->self->dev, "disabling bridge window "
"%pR to [bus %02x-%02x] (unused)\n", b_res,
bus->secondary, bus->subordinate);
b_res->flags = 0;
return;
}
b_res->start = 4096;
b_res->end = b_res->start + size0 - 1;
b_res->flags |= IORESOURCE_STARTALIGN;
if (size1 > size0 && add_head)
add_to_list(add_head, bus->self, b_res, size1-size0);
}
static int pbus_size_mem(struct pci_bus *bus, unsigned long mask,
unsigned long type, resource_size_t min_size,
resource_size_t add_size,
struct resource_list_x *add_head)
{
struct pci_dev *dev;
resource_size_t min_align, align, size, size0, size1;
resource_size_t aligns[12];
int order, max_order;
struct resource *b_res = find_free_bus_resource(bus, type);
unsigned int mem64_mask = 0;
if (!b_res)
return 0;
memset(aligns, 0, sizeof(aligns));
max_order = 0;
size = 0;
mem64_mask = b_res->flags & IORESOURCE_MEM_64;
b_res->flags &= ~IORESOURCE_MEM_64;
list_for_each_entry(dev, &bus->devices, bus_list) {
int i;
for (i = 0; i < PCI_NUM_RESOURCES; i++) {
struct resource *r = &dev->resource[i];
resource_size_t r_size;
if (r->parent || (r->flags & mask) != type)
continue;
r_size = resource_size(r);
align = pci_resource_alignment(dev, r);
order = __ffs(align) - 20;
if (order > 11) {
dev_warn(&dev->dev, "disabling BAR %d: %pR "
"(bad alignment %#llx)\n", i, r,
(unsigned long long) align);
r->flags = 0;
continue;
}
size += r_size;
if (order < 0)
order = 0;
if (r_size == align)
aligns[order] += align;
if (order > max_order)
max_order = order;
mem64_mask &= r->flags & IORESOURCE_MEM_64;
}
}
align = 0;
min_align = 0;
for (order = 0; order <= max_order; order++) {
resource_size_t align1 = 1;
align1 <<= (order + 20);
if (!align)
min_align = align1;
else if (ALIGN(align + min_align, min_align) < align1)
min_align = align1 >> 1;
align += aligns[order];
}
size0 = calculate_memsize(size, min_size, 0, resource_size(b_res), min_align);
size1 = (!add_head || (add_head && !add_size)) ? size0 :
calculate_memsize(size, min_size+add_size, 0,
resource_size(b_res), min_align);
if (!size0 && !size1) {
if (b_res->start || b_res->end)
dev_info(&bus->self->dev, "disabling bridge window "
"%pR to [bus %02x-%02x] (unused)\n", b_res,
bus->secondary, bus->subordinate);
b_res->flags = 0;
return 1;
}
b_res->start = min_align;
b_res->end = size0 + min_align - 1;
b_res->flags |= IORESOURCE_STARTALIGN | mem64_mask;
if (size1 > size0 && add_head)
add_to_list(add_head, bus->self, b_res, size1-size0);
return 1;
}
static void pci_bus_size_cardbus(struct pci_bus *bus)
{
struct pci_dev *bridge = bus->self;
struct resource *b_res = &bridge->resource[PCI_BRIDGE_RESOURCES];
u16 ctrl;
b_res[0].start = 0;
b_res[0].end = pci_cardbus_io_size - 1;
b_res[0].flags |= IORESOURCE_IO | IORESOURCE_SIZEALIGN;
b_res[1].start = 0;
b_res[1].end = pci_cardbus_io_size - 1;
b_res[1].flags |= IORESOURCE_IO | IORESOURCE_SIZEALIGN;
pci_read_config_word(bridge, PCI_CB_BRIDGE_CONTROL, &ctrl);
if (!(ctrl & PCI_CB_BRIDGE_CTL_PREFETCH_MEM0)) {
ctrl |= PCI_CB_BRIDGE_CTL_PREFETCH_MEM0;
pci_write_config_word(bridge, PCI_CB_BRIDGE_CONTROL, ctrl);
pci_read_config_word(bridge, PCI_CB_BRIDGE_CONTROL, &ctrl);
}
if (ctrl & PCI_CB_BRIDGE_CTL_PREFETCH_MEM0) {
b_res[2].start = 0;
b_res[2].end = pci_cardbus_mem_size - 1;
b_res[2].flags |= IORESOURCE_MEM | IORESOURCE_PREFETCH | IORESOURCE_SIZEALIGN;
b_res[3].start = 0;
b_res[3].end = pci_cardbus_mem_size - 1;
b_res[3].flags |= IORESOURCE_MEM | IORESOURCE_SIZEALIGN;
} else {
b_res[3].start = 0;
b_res[3].end = pci_cardbus_mem_size * 2 - 1;
b_res[3].flags |= IORESOURCE_MEM | IORESOURCE_SIZEALIGN;
}
}
void __ref __pci_bus_size_bridges(struct pci_bus *bus,
struct resource_list_x *add_head)
{
struct pci_dev *dev;
unsigned long mask, prefmask;
resource_size_t additional_mem_size = 0, additional_io_size = 0;
list_for_each_entry(dev, &bus->devices, bus_list) {
struct pci_bus *b = dev->subordinate;
if (!b)
continue;
switch (dev->class >> 8) {
case PCI_CLASS_BRIDGE_CARDBUS:
pci_bus_size_cardbus(b);
break;
case PCI_CLASS_BRIDGE_PCI:
default:
__pci_bus_size_bridges(b, add_head);
break;
}
}
if (!bus->self)
return;
switch (bus->self->class >> 8) {
case PCI_CLASS_BRIDGE_CARDBUS:
break;
case PCI_CLASS_BRIDGE_PCI:
pci_bridge_check_ranges(bus);
if (bus->self->is_hotplug_bridge) {
additional_io_size = pci_hotplug_io_size;
additional_mem_size = pci_hotplug_mem_size;
}
default:
pbus_size_io(bus, 0, additional_io_size, add_head);
mask = IORESOURCE_MEM;
prefmask = IORESOURCE_MEM | IORESOURCE_PREFETCH;
if (pbus_size_mem(bus, prefmask, prefmask, 0, additional_mem_size, add_head))
mask = prefmask;
else
additional_mem_size += additional_mem_size;
pbus_size_mem(bus, mask, IORESOURCE_MEM, 0, additional_mem_size, add_head);
break;
}
}
void __ref pci_bus_size_bridges(struct pci_bus *bus)
{
__pci_bus_size_bridges(bus, NULL);
}
static void __ref __pci_bus_assign_resources(const struct pci_bus *bus,
struct resource_list_x *add_head,
struct resource_list_x *fail_head)
{
struct pci_bus *b;
struct pci_dev *dev;
pbus_assign_resources_sorted(bus, add_head, fail_head);
list_for_each_entry(dev, &bus->devices, bus_list) {
b = dev->subordinate;
if (!b)
continue;
__pci_bus_assign_resources(b, add_head, fail_head);
switch (dev->class >> 8) {
case PCI_CLASS_BRIDGE_PCI:
if (!pci_is_enabled(dev))
pci_setup_bridge(b);
break;
case PCI_CLASS_BRIDGE_CARDBUS:
pci_setup_cardbus(b);
break;
default:
dev_info(&dev->dev, "not setting up bridge for bus "
"%04x:%02x\n", pci_domain_nr(b), b->number);
break;
}
}
}
void __ref pci_bus_assign_resources(const struct pci_bus *bus)
{
__pci_bus_assign_resources(bus, NULL, NULL);
}
static void __ref __pci_bridge_assign_resources(const struct pci_dev *bridge,
struct resource_list_x *fail_head)
{
struct pci_bus *b;
pdev_assign_resources_sorted((struct pci_dev *)bridge, fail_head);
b = bridge->subordinate;
if (!b)
return;
__pci_bus_assign_resources(b, NULL, fail_head);
switch (bridge->class >> 8) {
case PCI_CLASS_BRIDGE_PCI:
pci_setup_bridge(b);
break;
case PCI_CLASS_BRIDGE_CARDBUS:
pci_setup_cardbus(b);
break;
default:
dev_info(&bridge->dev, "not setting up bridge for bus "
"%04x:%02x\n", pci_domain_nr(b), b->number);
break;
}
}
static void pci_bridge_release_resources(struct pci_bus *bus,
unsigned long type)
{
int idx;
bool changed = false;
struct pci_dev *dev;
struct resource *r;
unsigned long type_mask = IORESOURCE_IO | IORESOURCE_MEM |
IORESOURCE_PREFETCH;
dev = bus->self;
for (idx = PCI_BRIDGE_RESOURCES; idx <= PCI_BRIDGE_RESOURCE_END;
idx++) {
r = &dev->resource[idx];
if ((r->flags & type_mask) != type)
continue;
if (!r->parent)
continue;
release_child_resources(r);
if (!release_resource(r)) {
dev_printk(KERN_DEBUG, &dev->dev,
"resource %d %pR released\n", idx, r);
r->end = resource_size(r) - 1;
r->start = 0;
r->flags = 0;
changed = true;
}
}
if (changed) {
if (type & IORESOURCE_PREFETCH)
type = IORESOURCE_PREFETCH;
__pci_setup_bridge(bus, type);
}
}
static void __ref pci_bus_release_bridge_resources(struct pci_bus *bus,
unsigned long type,
enum release_type rel_type)
{
struct pci_dev *dev;
bool is_leaf_bridge = true;
list_for_each_entry(dev, &bus->devices, bus_list) {
struct pci_bus *b = dev->subordinate;
if (!b)
continue;
is_leaf_bridge = false;
if ((dev->class >> 8) != PCI_CLASS_BRIDGE_PCI)
continue;
if (rel_type == whole_subtree)
pci_bus_release_bridge_resources(b, type,
whole_subtree);
}
if (pci_is_root_bus(bus))
return;
if ((bus->self->class >> 8) != PCI_CLASS_BRIDGE_PCI)
return;
if ((rel_type == whole_subtree) || is_leaf_bridge)
pci_bridge_release_resources(bus, type);
}
static void pci_bus_dump_res(struct pci_bus *bus)
{
struct resource *res;
int i;
pci_bus_for_each_resource(bus, res, i) {
if (!res || !res->end || !res->flags)
continue;
dev_printk(KERN_DEBUG, &bus->dev, "resource %d %pR\n", i, res);
}
}
static void pci_bus_dump_resources(struct pci_bus *bus)
{
struct pci_bus *b;
struct pci_dev *dev;
pci_bus_dump_res(bus);
list_for_each_entry(dev, &bus->devices, bus_list) {
b = dev->subordinate;
if (!b)
continue;
pci_bus_dump_resources(b);
}
}
static int __init pci_bus_get_depth(struct pci_bus *bus)
{
int depth = 0;
struct pci_dev *dev;
list_for_each_entry(dev, &bus->devices, bus_list) {
int ret;
struct pci_bus *b = dev->subordinate;
if (!b)
continue;
ret = pci_bus_get_depth(b);
if (ret + 1 > depth)
depth = ret + 1;
}
return depth;
}
static int __init pci_get_max_depth(void)
{
int depth = 0;
struct pci_bus *bus;
list_for_each_entry(bus, &pci_root_buses, node) {
int ret;
ret = pci_bus_get_depth(bus);
if (ret > depth)
depth = ret;
}
return depth;
}
void __init
pci_assign_unassigned_resources(void)
{
struct pci_bus *bus;
struct resource_list_x add_list;
int tried_times = 0;
enum release_type rel_type = leaf_only;
struct resource_list_x head, *list;
unsigned long type_mask = IORESOURCE_IO | IORESOURCE_MEM |
IORESOURCE_PREFETCH;
unsigned long failed_type;
int max_depth = pci_get_max_depth();
int pci_try_num;
head.next = NULL;
add_list.next = NULL;
pci_try_num = max_depth + 1;
printk(KERN_DEBUG "PCI: max bus depth: %d pci_try_num: %d\n",
max_depth, pci_try_num);
again:
list_for_each_entry(bus, &pci_root_buses, node)
__pci_bus_size_bridges(bus, &add_list);
list_for_each_entry(bus, &pci_root_buses, node)
__pci_bus_assign_resources(bus, &add_list, &head);
BUG_ON(add_list.next);
tried_times++;
if (!head.next)
goto enable_and_dump;
if (!pci_realloc_enabled()) {
free_list(resource_list_x, &head);
goto enable_and_dump;
}
failed_type = 0;
for (list = head.next; list;) {
failed_type |= list->flags;
list = list->next;
}
failed_type &= type_mask;
if ((failed_type == IORESOURCE_IO) || (tried_times >= pci_try_num)) {
free_list(resource_list_x, &head);
goto enable_and_dump;
}
printk(KERN_DEBUG "PCI: No. %d try to assign unassigned res\n",
tried_times + 1);
if ((tried_times + 1) > 2)
rel_type = whole_subtree;
for (list = head.next; list;) {
bus = list->dev->bus;
pci_bus_release_bridge_resources(bus, list->flags & type_mask,
rel_type);
list = list->next;
}
for (list = head.next; list;) {
struct resource *res = list->res;
res->start = list->start;
res->end = list->end;
res->flags = list->flags;
if (list->dev->subordinate)
res->flags = 0;
list = list->next;
}
free_list(resource_list_x, &head);
goto again;
enable_and_dump:
list_for_each_entry(bus, &pci_root_buses, node)
pci_enable_bridges(bus);
list_for_each_entry(bus, &pci_root_buses, node)
pci_bus_dump_resources(bus);
}
void pci_assign_unassigned_bridge_resources(struct pci_dev *bridge)
{
struct pci_bus *parent = bridge->subordinate;
int tried_times = 0;
struct resource_list_x head, *list;
int retval;
unsigned long type_mask = IORESOURCE_IO | IORESOURCE_MEM |
IORESOURCE_PREFETCH;
head.next = NULL;
again:
pci_bus_size_bridges(parent);
__pci_bridge_assign_resources(bridge, &head);
tried_times++;
if (!head.next)
goto enable_all;
if (tried_times >= 2) {
free_list(resource_list_x, &head);
goto enable_all;
}
printk(KERN_DEBUG "PCI: No. %d try to assign unassigned res\n",
tried_times + 1);
for (list = head.next; list;) {
struct pci_bus *bus = list->dev->bus;
unsigned long flags = list->flags;
pci_bus_release_bridge_resources(bus, flags & type_mask,
whole_subtree);
list = list->next;
}
for (list = head.next; list;) {
struct resource *res = list->res;
res->start = list->start;
res->end = list->end;
res->flags = list->flags;
if (list->dev->subordinate)
res->flags = 0;
list = list->next;
}
free_list(resource_list_x, &head);
goto again;
enable_all:
retval = pci_reenable_device(bridge);
pci_set_master(bridge);
pci_enable_bridges(parent);
}
