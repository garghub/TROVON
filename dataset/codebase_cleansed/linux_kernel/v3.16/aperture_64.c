static u32 __init allocate_aperture(void)
{
u32 aper_size;
unsigned long addr;
if (fallback_aper_order > 5)
fallback_aper_order = 5;
aper_size = (32 * 1024 * 1024) << fallback_aper_order;
addr = memblock_find_in_range(GART_MIN_ADDR, GART_MAX_ADDR,
aper_size, aper_size);
if (!addr) {
pr_err("Cannot allocate aperture memory hole [mem %#010lx-%#010lx] (%uKB)\n",
addr, addr + aper_size - 1, aper_size >> 10);
return 0;
}
memblock_reserve(addr, aper_size);
pr_info("Mapping aperture over RAM [mem %#010lx-%#010lx] (%uKB)\n",
addr, addr + aper_size - 1, aper_size >> 10);
register_nosave_region(addr >> PAGE_SHIFT,
(addr+aper_size) >> PAGE_SHIFT);
return (u32)addr;
}
static u32 __init find_cap(int bus, int slot, int func, int cap)
{
int bytes;
u8 pos;
if (!(read_pci_config_16(bus, slot, func, PCI_STATUS) &
PCI_STATUS_CAP_LIST))
return 0;
pos = read_pci_config_byte(bus, slot, func, PCI_CAPABILITY_LIST);
for (bytes = 0; bytes < 48 && pos >= 0x40; bytes++) {
u8 id;
pos &= ~3;
id = read_pci_config_byte(bus, slot, func, pos+PCI_CAP_LIST_ID);
if (id == 0xff)
break;
if (id == cap)
return pos;
pos = read_pci_config_byte(bus, slot, func,
pos+PCI_CAP_LIST_NEXT);
}
return 0;
}
static u32 __init read_agp(int bus, int slot, int func, int cap, u32 *order)
{
u32 apsize;
u32 apsizereg;
int nbits;
u32 aper_low, aper_hi;
u64 aper;
u32 old_order;
pr_info("pci 0000:%02x:%02x:%02x: AGP bridge\n", bus, slot, func);
apsizereg = read_pci_config_16(bus, slot, func, cap + 0x14);
if (apsizereg == 0xffffffff) {
pr_err("pci 0000:%02x:%02x.%d: APSIZE unreadable\n",
bus, slot, func);
return 0;
}
old_order = *order;
apsize = apsizereg & 0xfff;
if (apsize & 0xff)
apsize |= 0xf00;
nbits = hweight16(apsize);
*order = 7 - nbits;
if ((int)*order < 0)
*order = 0;
aper_low = read_pci_config(bus, slot, func, 0x10);
aper_hi = read_pci_config(bus, slot, func, 0x14);
aper = (aper_low & ~((1<<22)-1)) | ((u64)aper_hi << 32);
pr_info("pci 0000:%02x:%02x.%d: AGP aperture [bus addr %#010Lx-%#010Lx] (old size %uMB)\n",
bus, slot, func, aper, aper + (32ULL << (old_order + 20)) - 1,
32 << old_order);
if (aper + (32ULL<<(20 + *order)) > 0x100000000ULL) {
pr_info("pci 0000:%02x:%02x.%d: AGP aperture size %uMB (APSIZE %#x) is not right, using settings from NB\n",
bus, slot, func, 32 << *order, apsizereg);
*order = old_order;
}
pr_info("pci 0000:%02x:%02x.%d: AGP aperture [bus addr %#010Lx-%#010Lx] (%uMB, APSIZE %#x)\n",
bus, slot, func, aper, aper + (32ULL << (*order + 20)) - 1,
32 << *order, apsizereg);
if (!aperture_valid(aper, (32*1024*1024) << *order, 32<<20))
return 0;
return (u32)aper;
}
static u32 __init search_agp_bridge(u32 *order, int *valid_agp)
{
int bus, slot, func;
for (bus = 0; bus < 256; bus++) {
for (slot = 0; slot < 32; slot++) {
for (func = 0; func < 8; func++) {
u32 class, cap;
u8 type;
class = read_pci_config(bus, slot, func,
PCI_CLASS_REVISION);
if (class == 0xffffffff)
break;
switch (class >> 16) {
case PCI_CLASS_BRIDGE_HOST:
case PCI_CLASS_BRIDGE_OTHER:
cap = find_cap(bus, slot, func,
PCI_CAP_ID_AGP);
if (!cap)
break;
*valid_agp = 1;
return read_agp(bus, slot, func, cap,
order);
}
type = read_pci_config_byte(bus, slot, func,
PCI_HEADER_TYPE);
if (!(type & 0x80))
break;
}
}
}
pr_info("No AGP bridge found\n");
return 0;
}
static int __init parse_gart_mem(char *p)
{
if (!p)
return -EINVAL;
if (!strncmp(p, "off", 3))
gart_fix_e820 = 0;
else if (!strncmp(p, "on", 2))
gart_fix_e820 = 1;
return 0;
}
void __init early_gart_iommu_check(void)
{
u32 agp_aper_order = 0;
int i, fix, slot, valid_agp = 0;
u32 ctl;
u32 aper_size = 0, aper_order = 0, last_aper_order = 0;
u64 aper_base = 0, last_aper_base = 0;
int aper_enabled = 0, last_aper_enabled = 0, last_valid = 0;
if (!early_pci_allowed())
return;
search_agp_bridge(&agp_aper_order, &valid_agp);
fix = 0;
for (i = 0; amd_nb_bus_dev_ranges[i].dev_limit; i++) {
int bus;
int dev_base, dev_limit;
bus = amd_nb_bus_dev_ranges[i].bus;
dev_base = amd_nb_bus_dev_ranges[i].dev_base;
dev_limit = amd_nb_bus_dev_ranges[i].dev_limit;
for (slot = dev_base; slot < dev_limit; slot++) {
if (!early_is_amd_nb(read_pci_config(bus, slot, 3, 0x00)))
continue;
ctl = read_pci_config(bus, slot, 3, AMD64_GARTAPERTURECTL);
aper_enabled = ctl & GARTEN;
aper_order = (ctl >> 1) & 7;
aper_size = (32 * 1024 * 1024) << aper_order;
aper_base = read_pci_config(bus, slot, 3, AMD64_GARTAPERTUREBASE) & 0x7fff;
aper_base <<= 25;
if (last_valid) {
if ((aper_order != last_aper_order) ||
(aper_base != last_aper_base) ||
(aper_enabled != last_aper_enabled)) {
fix = 1;
break;
}
}
last_aper_order = aper_order;
last_aper_base = aper_base;
last_aper_enabled = aper_enabled;
last_valid = 1;
}
}
if (!fix && !aper_enabled)
return;
if (!aper_base || !aper_size || aper_base + aper_size > 0x100000000UL)
fix = 1;
if (gart_fix_e820 && !fix && aper_enabled) {
if (e820_any_mapped(aper_base, aper_base + aper_size,
E820_RAM)) {
pr_info("e820: reserve [mem %#010Lx-%#010Lx] for GART\n",
aper_base, aper_base + aper_size - 1);
e820_add_region(aper_base, aper_size, E820_RESERVED);
update_e820();
}
}
if (valid_agp)
return;
for (i = 0; i < amd_nb_bus_dev_ranges[i].dev_limit; i++) {
int bus;
int dev_base, dev_limit;
bus = amd_nb_bus_dev_ranges[i].bus;
dev_base = amd_nb_bus_dev_ranges[i].dev_base;
dev_limit = amd_nb_bus_dev_ranges[i].dev_limit;
for (slot = dev_base; slot < dev_limit; slot++) {
if (!early_is_amd_nb(read_pci_config(bus, slot, 3, 0x00)))
continue;
ctl = read_pci_config(bus, slot, 3, AMD64_GARTAPERTURECTL);
ctl &= ~GARTEN;
write_pci_config(bus, slot, 3, AMD64_GARTAPERTURECTL, ctl);
}
}
}
int __init gart_iommu_hole_init(void)
{
u32 agp_aper_base = 0, agp_aper_order = 0;
u32 aper_size, aper_alloc = 0, aper_order = 0, last_aper_order = 0;
u64 aper_base, last_aper_base = 0;
int fix, slot, valid_agp = 0;
int i, node;
if (gart_iommu_aperture_disabled || !fix_aperture ||
!early_pci_allowed())
return -ENODEV;
pr_info("Checking aperture...\n");
if (!fallback_aper_force)
agp_aper_base = search_agp_bridge(&agp_aper_order, &valid_agp);
fix = 0;
node = 0;
for (i = 0; i < amd_nb_bus_dev_ranges[i].dev_limit; i++) {
int bus;
int dev_base, dev_limit;
u32 ctl;
bus = amd_nb_bus_dev_ranges[i].bus;
dev_base = amd_nb_bus_dev_ranges[i].dev_base;
dev_limit = amd_nb_bus_dev_ranges[i].dev_limit;
for (slot = dev_base; slot < dev_limit; slot++) {
if (!early_is_amd_nb(read_pci_config(bus, slot, 3, 0x00)))
continue;
iommu_detected = 1;
gart_iommu_aperture = 1;
x86_init.iommu.iommu_init = gart_iommu_init;
ctl = read_pci_config(bus, slot, 3,
AMD64_GARTAPERTURECTL);
ctl &= ~GARTEN;
write_pci_config(bus, slot, 3, AMD64_GARTAPERTURECTL, ctl);
aper_order = (ctl >> 1) & 7;
aper_size = (32 * 1024 * 1024) << aper_order;
aper_base = read_pci_config(bus, slot, 3, AMD64_GARTAPERTUREBASE) & 0x7fff;
aper_base <<= 25;
pr_info("Node %d: aperture [bus addr %#010Lx-%#010Lx] (%uMB)\n",
node, aper_base, aper_base + aper_size - 1,
aper_size >> 20);
node++;
if (!aperture_valid(aper_base, aper_size, 64<<20)) {
if (valid_agp && agp_aper_base &&
agp_aper_base == aper_base &&
agp_aper_order == aper_order) {
if (!no_iommu &&
max_pfn > MAX_DMA32_PFN &&
!printed_gart_size_msg) {
pr_err("you are using iommu with agp, but GART size is less than 64MB\n");
pr_err("please increase GART size in your BIOS setup\n");
pr_err("if BIOS doesn't have that option, contact your HW vendor!\n");
printed_gart_size_msg = 1;
}
} else {
fix = 1;
goto out;
}
}
if ((last_aper_order && aper_order != last_aper_order) ||
(last_aper_base && aper_base != last_aper_base)) {
fix = 1;
goto out;
}
last_aper_order = aper_order;
last_aper_base = aper_base;
}
}
out:
if (!fix && !fallback_aper_force) {
if (last_aper_base)
return 1;
return 0;
}
if (!fallback_aper_force) {
aper_alloc = agp_aper_base;
aper_order = agp_aper_order;
}
if (aper_alloc) {
} else if ((!no_iommu && max_pfn > MAX_DMA32_PFN) ||
force_iommu ||
valid_agp ||
fallback_aper_force) {
pr_info("Your BIOS doesn't leave a aperture memory hole\n");
pr_info("Please enable the IOMMU option in the BIOS setup\n");
pr_info("This costs you %dMB of RAM\n",
32 << fallback_aper_order);
aper_order = fallback_aper_order;
aper_alloc = allocate_aperture();
if (!aper_alloc) {
panic("Not enough memory for aperture");
}
} else {
return 0;
}
for (i = 0; i < amd_nb_bus_dev_ranges[i].dev_limit; i++) {
int bus, dev_base, dev_limit;
u32 ctl = aper_order << 1;
bus = amd_nb_bus_dev_ranges[i].bus;
dev_base = amd_nb_bus_dev_ranges[i].dev_base;
dev_limit = amd_nb_bus_dev_ranges[i].dev_limit;
for (slot = dev_base; slot < dev_limit; slot++) {
if (!early_is_amd_nb(read_pci_config(bus, slot, 3, 0x00)))
continue;
write_pci_config(bus, slot, 3, AMD64_GARTAPERTURECTL, ctl);
write_pci_config(bus, slot, 3, AMD64_GARTAPERTUREBASE, aper_alloc >> 25);
}
}
set_up_gart_resume(aper_order, aper_alloc);
return 1;
}
