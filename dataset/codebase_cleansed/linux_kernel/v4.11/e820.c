int
e820_any_mapped(u64 start, u64 end, unsigned type)
{
int i;
for (i = 0; i < e820->nr_map; i++) {
struct e820entry *ei = &e820->map[i];
if (type && ei->type != type)
continue;
if (ei->addr >= end || ei->addr + ei->size <= start)
continue;
return 1;
}
return 0;
}
int __init e820_all_mapped(u64 start, u64 end, unsigned type)
{
int i;
for (i = 0; i < e820->nr_map; i++) {
struct e820entry *ei = &e820->map[i];
if (type && ei->type != type)
continue;
if (ei->addr >= end || ei->addr + ei->size <= start)
continue;
if (ei->addr <= start)
start = ei->addr + ei->size;
if (start >= end)
return 1;
}
return 0;
}
static void __init __e820_add_region(struct e820map *e820x, u64 start, u64 size,
int type)
{
int x = e820x->nr_map;
if (x >= ARRAY_SIZE(e820x->map)) {
printk(KERN_ERR "e820: too many entries; ignoring [mem %#010llx-%#010llx]\n",
(unsigned long long) start,
(unsigned long long) (start + size - 1));
return;
}
e820x->map[x].addr = start;
e820x->map[x].size = size;
e820x->map[x].type = type;
e820x->nr_map++;
}
void __init e820_add_region(u64 start, u64 size, int type)
{
__e820_add_region(e820, start, size, type);
}
static void __init e820_print_type(u32 type)
{
switch (type) {
case E820_RAM:
case E820_RESERVED_KERN:
printk(KERN_CONT "usable");
break;
case E820_RESERVED:
printk(KERN_CONT "reserved");
break;
case E820_ACPI:
printk(KERN_CONT "ACPI data");
break;
case E820_NVS:
printk(KERN_CONT "ACPI NVS");
break;
case E820_UNUSABLE:
printk(KERN_CONT "unusable");
break;
case E820_PMEM:
case E820_PRAM:
printk(KERN_CONT "persistent (type %u)", type);
break;
default:
printk(KERN_CONT "type %u", type);
break;
}
}
void __init e820_print_map(char *who)
{
int i;
for (i = 0; i < e820->nr_map; i++) {
printk(KERN_INFO "%s: [mem %#018Lx-%#018Lx] ", who,
(unsigned long long) e820->map[i].addr,
(unsigned long long)
(e820->map[i].addr + e820->map[i].size - 1));
e820_print_type(e820->map[i].type);
printk(KERN_CONT "\n");
}
}
static int __init cpcompare(const void *a, const void *b)
{
struct change_member * const *app = a, * const *bpp = b;
const struct change_member *ap = *app, *bp = *bpp;
if (ap->addr != bp->addr)
return ap->addr > bp->addr ? 1 : -1;
return (ap->addr != ap->pbios->addr) - (bp->addr != bp->pbios->addr);
}
int __init sanitize_e820_map(struct e820entry *biosmap, int max_nr_map,
u32 *pnr_map)
{
static struct change_member change_point_list[2*E820_X_MAX] __initdata;
static struct change_member *change_point[2*E820_X_MAX] __initdata;
static struct e820entry *overlap_list[E820_X_MAX] __initdata;
static struct e820entry new_bios[E820_X_MAX] __initdata;
unsigned long current_type, last_type;
unsigned long long last_addr;
int chgidx;
int overlap_entries;
int new_bios_entry;
int old_nr, new_nr, chg_nr;
int i;
if (*pnr_map < 2)
return -1;
old_nr = *pnr_map;
BUG_ON(old_nr > max_nr_map);
for (i = 0; i < old_nr; i++)
if (biosmap[i].addr + biosmap[i].size < biosmap[i].addr)
return -1;
for (i = 0; i < 2 * old_nr; i++)
change_point[i] = &change_point_list[i];
chgidx = 0;
for (i = 0; i < old_nr; i++) {
if (biosmap[i].size != 0) {
change_point[chgidx]->addr = biosmap[i].addr;
change_point[chgidx++]->pbios = &biosmap[i];
change_point[chgidx]->addr = biosmap[i].addr +
biosmap[i].size;
change_point[chgidx++]->pbios = &biosmap[i];
}
}
chg_nr = chgidx;
sort(change_point, chg_nr, sizeof *change_point, cpcompare, NULL);
overlap_entries = 0;
new_bios_entry = 0;
last_type = 0;
last_addr = 0;
for (chgidx = 0; chgidx < chg_nr; chgidx++) {
if (change_point[chgidx]->addr ==
change_point[chgidx]->pbios->addr) {
overlap_list[overlap_entries++] =
change_point[chgidx]->pbios;
} else {
for (i = 0; i < overlap_entries; i++) {
if (overlap_list[i] ==
change_point[chgidx]->pbios)
overlap_list[i] =
overlap_list[overlap_entries-1];
}
overlap_entries--;
}
current_type = 0;
for (i = 0; i < overlap_entries; i++)
if (overlap_list[i]->type > current_type)
current_type = overlap_list[i]->type;
if (current_type != last_type || current_type == E820_PRAM) {
if (last_type != 0) {
new_bios[new_bios_entry].size =
change_point[chgidx]->addr - last_addr;
if (new_bios[new_bios_entry].size != 0)
if (++new_bios_entry >= max_nr_map)
break;
}
if (current_type != 0) {
new_bios[new_bios_entry].addr =
change_point[chgidx]->addr;
new_bios[new_bios_entry].type = current_type;
last_addr = change_point[chgidx]->addr;
}
last_type = current_type;
}
}
new_nr = new_bios_entry;
memcpy(biosmap, new_bios, new_nr * sizeof(struct e820entry));
*pnr_map = new_nr;
return 0;
}
static int __init __append_e820_map(struct e820entry *biosmap, int nr_map)
{
while (nr_map) {
u64 start = biosmap->addr;
u64 size = biosmap->size;
u64 end = start + size - 1;
u32 type = biosmap->type;
if (start > end && likely(size))
return -1;
e820_add_region(start, size, type);
biosmap++;
nr_map--;
}
return 0;
}
static int __init append_e820_map(struct e820entry *biosmap, int nr_map)
{
if (nr_map < 2)
return -1;
return __append_e820_map(biosmap, nr_map);
}
static u64 __init __e820_update_range(struct e820map *e820x, u64 start,
u64 size, unsigned old_type,
unsigned new_type)
{
u64 end;
unsigned int i;
u64 real_updated_size = 0;
BUG_ON(old_type == new_type);
if (size > (ULLONG_MAX - start))
size = ULLONG_MAX - start;
end = start + size;
printk(KERN_DEBUG "e820: update [mem %#010Lx-%#010Lx] ",
(unsigned long long) start, (unsigned long long) (end - 1));
e820_print_type(old_type);
printk(KERN_CONT " ==> ");
e820_print_type(new_type);
printk(KERN_CONT "\n");
for (i = 0; i < e820x->nr_map; i++) {
struct e820entry *ei = &e820x->map[i];
u64 final_start, final_end;
u64 ei_end;
if (ei->type != old_type)
continue;
ei_end = ei->addr + ei->size;
if (ei->addr >= start && ei_end <= end) {
ei->type = new_type;
real_updated_size += ei->size;
continue;
}
if (ei->addr < start && ei_end > end) {
__e820_add_region(e820x, start, size, new_type);
__e820_add_region(e820x, end, ei_end - end, ei->type);
ei->size = start - ei->addr;
real_updated_size += size;
continue;
}
final_start = max(start, ei->addr);
final_end = min(end, ei_end);
if (final_start >= final_end)
continue;
__e820_add_region(e820x, final_start, final_end - final_start,
new_type);
real_updated_size += final_end - final_start;
ei->size -= final_end - final_start;
if (ei->addr < final_start)
continue;
ei->addr = final_end;
}
return real_updated_size;
}
u64 __init e820_update_range(u64 start, u64 size, unsigned old_type,
unsigned new_type)
{
return __e820_update_range(e820, start, size, old_type, new_type);
}
static u64 __init e820_update_range_saved(u64 start, u64 size,
unsigned old_type, unsigned new_type)
{
return __e820_update_range(e820_saved, start, size, old_type,
new_type);
}
u64 __init e820_remove_range(u64 start, u64 size, unsigned old_type,
int checktype)
{
int i;
u64 end;
u64 real_removed_size = 0;
if (size > (ULLONG_MAX - start))
size = ULLONG_MAX - start;
end = start + size;
printk(KERN_DEBUG "e820: remove [mem %#010Lx-%#010Lx] ",
(unsigned long long) start, (unsigned long long) (end - 1));
if (checktype)
e820_print_type(old_type);
printk(KERN_CONT "\n");
for (i = 0; i < e820->nr_map; i++) {
struct e820entry *ei = &e820->map[i];
u64 final_start, final_end;
u64 ei_end;
if (checktype && ei->type != old_type)
continue;
ei_end = ei->addr + ei->size;
if (ei->addr >= start && ei_end <= end) {
real_removed_size += ei->size;
memset(ei, 0, sizeof(struct e820entry));
continue;
}
if (ei->addr < start && ei_end > end) {
e820_add_region(end, ei_end - end, ei->type);
ei->size = start - ei->addr;
real_removed_size += size;
continue;
}
final_start = max(start, ei->addr);
final_end = min(end, ei_end);
if (final_start >= final_end)
continue;
real_removed_size += final_end - final_start;
ei->size -= final_end - final_start;
if (ei->addr < final_start)
continue;
ei->addr = final_end;
}
return real_removed_size;
}
void __init update_e820(void)
{
if (sanitize_e820_map(e820->map, ARRAY_SIZE(e820->map), &e820->nr_map))
return;
printk(KERN_INFO "e820: modified physical RAM map:\n");
e820_print_map("modified");
}
static void __init update_e820_saved(void)
{
sanitize_e820_map(e820_saved->map, ARRAY_SIZE(e820_saved->map),
&e820_saved->nr_map);
}
static int __init e820_search_gap(unsigned long *gapstart,
unsigned long *gapsize)
{
unsigned long long last = MAX_GAP_END;
int i = e820->nr_map;
int found = 0;
while (--i >= 0) {
unsigned long long start = e820->map[i].addr;
unsigned long long end = start + e820->map[i].size;
if (last > end) {
unsigned long gap = last - end;
if (gap >= *gapsize) {
*gapsize = gap;
*gapstart = end;
found = 1;
}
}
if (start < last)
last = start;
}
return found;
}
__init void e820_setup_gap(void)
{
unsigned long gapstart, gapsize;
int found;
gapsize = 0x400000;
found = e820_search_gap(&gapstart, &gapsize);
if (!found) {
#ifdef CONFIG_X86_64
gapstart = (max_pfn << PAGE_SHIFT) + 1024*1024;
printk(KERN_ERR
"e820: cannot find a gap in the 32bit address range\n"
"e820: PCI devices with unassigned 32bit BARs may break!\n");
#else
gapstart = 0x10000000;
#endif
}
pci_mem_start = gapstart;
printk(KERN_INFO
"e820: [mem %#010lx-%#010lx] available for PCI devices\n",
gapstart, gapstart + gapsize - 1);
}
__init void e820_reallocate_tables(void)
{
struct e820map *n;
int size;
size = offsetof(struct e820map, map) + sizeof(struct e820entry) * e820->nr_map;
n = kmalloc(size, GFP_KERNEL);
BUG_ON(!n);
memcpy(n, e820, size);
e820 = n;
size = offsetof(struct e820map, map) + sizeof(struct e820entry) * e820_saved->nr_map;
n = kmalloc(size, GFP_KERNEL);
BUG_ON(!n);
memcpy(n, e820_saved, size);
e820_saved = n;
}
void __init parse_e820_ext(u64 phys_addr, u32 data_len)
{
int entries;
struct e820entry *extmap;
struct setup_data *sdata;
sdata = early_memremap(phys_addr, data_len);
entries = sdata->len / sizeof(struct e820entry);
extmap = (struct e820entry *)(sdata->data);
__append_e820_map(extmap, entries);
sanitize_e820_map(e820->map, ARRAY_SIZE(e820->map), &e820->nr_map);
early_memunmap(sdata, data_len);
printk(KERN_INFO "e820: extended physical RAM map:\n");
e820_print_map("extended");
}
void __init e820_mark_nosave_regions(unsigned long limit_pfn)
{
int i;
unsigned long pfn = 0;
for (i = 0; i < e820->nr_map; i++) {
struct e820entry *ei = &e820->map[i];
if (pfn < PFN_UP(ei->addr))
register_nosave_region(pfn, PFN_UP(ei->addr));
pfn = PFN_DOWN(ei->addr + ei->size);
if (ei->type != E820_RAM && ei->type != E820_RESERVED_KERN)
register_nosave_region(PFN_UP(ei->addr), pfn);
if (pfn >= limit_pfn)
break;
}
}
static int __init e820_mark_nvs_memory(void)
{
int i;
for (i = 0; i < e820->nr_map; i++) {
struct e820entry *ei = &e820->map[i];
if (ei->type == E820_NVS)
acpi_nvs_register(ei->addr, ei->size);
}
return 0;
}
u64 __init early_reserve_e820(u64 size, u64 align)
{
u64 addr;
addr = __memblock_alloc_base(size, align, MEMBLOCK_ALLOC_ACCESSIBLE);
if (addr) {
e820_update_range_saved(addr, size, E820_RAM, E820_RESERVED);
printk(KERN_INFO "e820: update e820_saved for early_reserve_e820\n");
update_e820_saved();
}
return addr;
}
static unsigned long __init e820_end_pfn(unsigned long limit_pfn, unsigned type)
{
int i;
unsigned long last_pfn = 0;
unsigned long max_arch_pfn = MAX_ARCH_PFN;
for (i = 0; i < e820->nr_map; i++) {
struct e820entry *ei = &e820->map[i];
unsigned long start_pfn;
unsigned long end_pfn;
if (ei->type != type)
continue;
start_pfn = ei->addr >> PAGE_SHIFT;
end_pfn = (ei->addr + ei->size) >> PAGE_SHIFT;
if (start_pfn >= limit_pfn)
continue;
if (end_pfn > limit_pfn) {
last_pfn = limit_pfn;
break;
}
if (end_pfn > last_pfn)
last_pfn = end_pfn;
}
if (last_pfn > max_arch_pfn)
last_pfn = max_arch_pfn;
printk(KERN_INFO "e820: last_pfn = %#lx max_arch_pfn = %#lx\n",
last_pfn, max_arch_pfn);
return last_pfn;
}
unsigned long __init e820_end_of_ram_pfn(void)
{
return e820_end_pfn(MAX_ARCH_PFN, E820_RAM);
}
unsigned long __init e820_end_of_low_ram_pfn(void)
{
return e820_end_pfn(1UL << (32 - PAGE_SHIFT), E820_RAM);
}
static void __init early_panic(char *msg)
{
early_printk(msg);
panic(msg);
}
static int __init parse_memopt(char *p)
{
u64 mem_size;
if (!p)
return -EINVAL;
if (!strcmp(p, "nopentium")) {
#ifdef CONFIG_X86_32
setup_clear_cpu_cap(X86_FEATURE_PSE);
return 0;
#else
printk(KERN_WARNING "mem=nopentium ignored! (only supported on x86_32)\n");
return -EINVAL;
#endif
}
userdef = 1;
mem_size = memparse(p, &p);
if (mem_size == 0)
return -EINVAL;
e820_remove_range(mem_size, ULLONG_MAX - mem_size, E820_RAM, 1);
return 0;
}
static int __init parse_memmap_one(char *p)
{
char *oldp;
u64 start_at, mem_size;
if (!p)
return -EINVAL;
if (!strncmp(p, "exactmap", 8)) {
#ifdef CONFIG_CRASH_DUMP
saved_max_pfn = e820_end_of_ram_pfn();
#endif
e820->nr_map = 0;
userdef = 1;
return 0;
}
oldp = p;
mem_size = memparse(p, &p);
if (p == oldp)
return -EINVAL;
userdef = 1;
if (*p == '@') {
start_at = memparse(p+1, &p);
e820_add_region(start_at, mem_size, E820_RAM);
} else if (*p == '#') {
start_at = memparse(p+1, &p);
e820_add_region(start_at, mem_size, E820_ACPI);
} else if (*p == '$') {
start_at = memparse(p+1, &p);
e820_add_region(start_at, mem_size, E820_RESERVED);
} else if (*p == '!') {
start_at = memparse(p+1, &p);
e820_add_region(start_at, mem_size, E820_PRAM);
} else
e820_remove_range(mem_size, ULLONG_MAX - mem_size, E820_RAM, 1);
return *p == '\0' ? 0 : -EINVAL;
}
static int __init parse_memmap_opt(char *str)
{
while (str) {
char *k = strchr(str, ',');
if (k)
*k++ = 0;
parse_memmap_one(str);
str = k;
}
return 0;
}
void __init finish_e820_parsing(void)
{
if (userdef) {
if (sanitize_e820_map(e820->map, ARRAY_SIZE(e820->map),
&e820->nr_map) < 0)
early_panic("Invalid user supplied memory map");
printk(KERN_INFO "e820: user-defined physical RAM map:\n");
e820_print_map("user");
}
}
static const char *__init e820_type_to_string(int e820_type)
{
switch (e820_type) {
case E820_RESERVED_KERN:
case E820_RAM: return "System RAM";
case E820_ACPI: return "ACPI Tables";
case E820_NVS: return "ACPI Non-volatile Storage";
case E820_UNUSABLE: return "Unusable memory";
case E820_PRAM: return "Persistent Memory (legacy)";
case E820_PMEM: return "Persistent Memory";
default: return "reserved";
}
}
static unsigned long __init e820_type_to_iomem_type(int e820_type)
{
switch (e820_type) {
case E820_RESERVED_KERN:
case E820_RAM:
return IORESOURCE_SYSTEM_RAM;
case E820_ACPI:
case E820_NVS:
case E820_UNUSABLE:
case E820_PRAM:
case E820_PMEM:
default:
return IORESOURCE_MEM;
}
}
static unsigned long __init e820_type_to_iores_desc(int e820_type)
{
switch (e820_type) {
case E820_ACPI:
return IORES_DESC_ACPI_TABLES;
case E820_NVS:
return IORES_DESC_ACPI_NV_STORAGE;
case E820_PMEM:
return IORES_DESC_PERSISTENT_MEMORY;
case E820_PRAM:
return IORES_DESC_PERSISTENT_MEMORY_LEGACY;
case E820_RESERVED_KERN:
case E820_RAM:
case E820_UNUSABLE:
default:
return IORES_DESC_NONE;
}
}
static bool __init do_mark_busy(u32 type, struct resource *res)
{
if (res->start < (1ULL<<20))
return true;
switch (type) {
case E820_RESERVED:
case E820_PRAM:
case E820_PMEM:
return false;
default:
return true;
}
}
void __init e820_reserve_resources(void)
{
int i;
struct resource *res;
u64 end;
res = alloc_bootmem(sizeof(struct resource) * e820->nr_map);
e820_res = res;
for (i = 0; i < e820->nr_map; i++) {
end = e820->map[i].addr + e820->map[i].size - 1;
if (end != (resource_size_t)end) {
res++;
continue;
}
res->name = e820_type_to_string(e820->map[i].type);
res->start = e820->map[i].addr;
res->end = end;
res->flags = e820_type_to_iomem_type(e820->map[i].type);
res->desc = e820_type_to_iores_desc(e820->map[i].type);
if (do_mark_busy(e820->map[i].type, res)) {
res->flags |= IORESOURCE_BUSY;
insert_resource(&iomem_resource, res);
}
res++;
}
for (i = 0; i < e820_saved->nr_map; i++) {
struct e820entry *entry = &e820_saved->map[i];
firmware_map_add_early(entry->addr,
entry->addr + entry->size,
e820_type_to_string(entry->type));
}
}
static unsigned long __init ram_alignment(resource_size_t pos)
{
unsigned long mb = pos >> 20;
if (!mb)
return 64*1024;
if (mb < 16)
return 1024*1024;
return 64*1024*1024;
}
void __init e820_reserve_resources_late(void)
{
int i;
struct resource *res;
res = e820_res;
for (i = 0; i < e820->nr_map; i++) {
if (!res->parent && res->end)
insert_resource_expand_to_fit(&iomem_resource, res);
res++;
}
for (i = 0; i < e820->nr_map; i++) {
struct e820entry *entry = &e820->map[i];
u64 start, end;
if (entry->type != E820_RAM)
continue;
start = entry->addr + entry->size;
end = round_up(start, ram_alignment(start)) - 1;
if (end > MAX_RESOURCE_SIZE)
end = MAX_RESOURCE_SIZE;
if (start >= end)
continue;
printk(KERN_DEBUG
"e820: reserve RAM buffer [mem %#010llx-%#010llx]\n",
start, end);
reserve_region_with_split(&iomem_resource, start, end,
"RAM buffer");
}
}
char *__init default_machine_specific_memory_setup(void)
{
char *who = "BIOS-e820";
u32 new_nr;
new_nr = boot_params.e820_entries;
sanitize_e820_map(boot_params.e820_map,
ARRAY_SIZE(boot_params.e820_map),
&new_nr);
boot_params.e820_entries = new_nr;
if (append_e820_map(boot_params.e820_map, boot_params.e820_entries)
< 0) {
u64 mem_size;
if (boot_params.alt_mem_k
< boot_params.screen_info.ext_mem_k) {
mem_size = boot_params.screen_info.ext_mem_k;
who = "BIOS-88";
} else {
mem_size = boot_params.alt_mem_k;
who = "BIOS-e801";
}
e820->nr_map = 0;
e820_add_region(0, LOWMEMSIZE(), E820_RAM);
e820_add_region(HIGH_MEMORY, mem_size << 10, E820_RAM);
}
return who;
}
void __init setup_memory_map(void)
{
char *who;
who = x86_init.resources.memory_setup();
memcpy(e820_saved, e820, sizeof(struct e820map));
printk(KERN_INFO "e820: BIOS-provided physical RAM map:\n");
e820_print_map(who);
}
void __init memblock_x86_fill(void)
{
int i;
u64 end;
memblock_allow_resize();
for (i = 0; i < e820->nr_map; i++) {
struct e820entry *ei = &e820->map[i];
end = ei->addr + ei->size;
if (end != (resource_size_t)end)
continue;
if (ei->type != E820_RAM && ei->type != E820_RESERVED_KERN)
continue;
memblock_add(ei->addr, ei->size);
}
memblock_trim_memory(PAGE_SIZE);
memblock_dump_all();
}
void __init memblock_find_dma_reserve(void)
{
#ifdef CONFIG_X86_64
u64 nr_pages = 0, nr_free_pages = 0;
unsigned long start_pfn, end_pfn;
phys_addr_t start, end;
int i;
u64 u;
for_each_mem_pfn_range(i, MAX_NUMNODES, &start_pfn, &end_pfn, NULL) {
start_pfn = min(start_pfn, MAX_DMA_PFN);
end_pfn = min(end_pfn, MAX_DMA_PFN);
nr_pages += end_pfn - start_pfn;
}
for_each_free_mem_range(u, NUMA_NO_NODE, MEMBLOCK_NONE, &start, &end,
NULL) {
start_pfn = min_t(unsigned long, PFN_UP(start), MAX_DMA_PFN);
end_pfn = min_t(unsigned long, PFN_DOWN(end), MAX_DMA_PFN);
if (start_pfn < end_pfn)
nr_free_pages += end_pfn - start_pfn;
}
set_dma_reserve(nr_pages - nr_free_pages);
#endif
}
