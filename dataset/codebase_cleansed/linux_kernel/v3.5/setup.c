void __init add_memory_region(phys_t start, phys_t size, long type)
{
int x = boot_mem_map.nr_map;
struct boot_mem_map_entry *prev = boot_mem_map.map + x - 1;
if (start + size < start) {
pr_warning("Trying to add an invalid memory region, skipped\n");
return;
}
if (x && prev->addr + prev->size == start && prev->type == type) {
prev->size += size;
return;
}
if (x == BOOT_MEM_MAP_MAX) {
pr_err("Ooops! Too many entries in the memory map!\n");
return;
}
boot_mem_map.map[x].addr = start;
boot_mem_map.map[x].size = size;
boot_mem_map.map[x].type = type;
boot_mem_map.nr_map++;
}
static void __init print_memory_map(void)
{
int i;
const int field = 2 * sizeof(unsigned long);
for (i = 0; i < boot_mem_map.nr_map; i++) {
printk(KERN_INFO " memory: %0*Lx @ %0*Lx ",
field, (unsigned long long) boot_mem_map.map[i].size,
field, (unsigned long long) boot_mem_map.map[i].addr);
switch (boot_mem_map.map[i].type) {
case BOOT_MEM_RAM:
printk(KERN_CONT "(usable)\n");
break;
case BOOT_MEM_INIT_RAM:
printk(KERN_CONT "(usable after init)\n");
break;
case BOOT_MEM_ROM_DATA:
printk(KERN_CONT "(ROM data)\n");
break;
case BOOT_MEM_RESERVED:
printk(KERN_CONT "(reserved)\n");
break;
default:
printk(KERN_CONT "type %lu\n", boot_mem_map.map[i].type);
break;
}
}
}
static int __init rd_start_early(char *p)
{
unsigned long start = memparse(p, &p);
#ifdef CONFIG_64BIT
if (start < XKPHYS)
start = (int)start;
#endif
initrd_start = start;
initrd_end += start;
return 0;
}
static int __init rd_size_early(char *p)
{
initrd_end += memparse(p, &p);
return 0;
}
static unsigned long __init init_initrd(void)
{
unsigned long end;
if (!initrd_start || initrd_end <= initrd_start)
goto disable;
if (initrd_start & ~PAGE_MASK) {
pr_err("initrd start must be page aligned\n");
goto disable;
}
if (initrd_start < PAGE_OFFSET) {
pr_err("initrd start < PAGE_OFFSET\n");
goto disable;
}
end = __pa(initrd_end);
initrd_end = (unsigned long)__va(end);
initrd_start = (unsigned long)__va(__pa(initrd_start));
ROOT_DEV = Root_RAM0;
return PFN_UP(end);
disable:
initrd_start = 0;
initrd_end = 0;
return 0;
}
static void __init finalize_initrd(void)
{
unsigned long size = initrd_end - initrd_start;
if (size == 0) {
printk(KERN_INFO "Initrd not found or empty");
goto disable;
}
if (__pa(initrd_end) > PFN_PHYS(max_low_pfn)) {
printk(KERN_ERR "Initrd extends beyond end of memory");
goto disable;
}
reserve_bootmem(__pa(initrd_start), size, BOOTMEM_DEFAULT);
initrd_below_start_ok = 1;
pr_info("Initial ramdisk at: 0x%lx (%lu bytes)\n",
initrd_start, size);
return;
disable:
printk(KERN_CONT " - disabling initrd\n");
initrd_start = 0;
initrd_end = 0;
}
static unsigned long __init init_initrd(void)
{
return 0;
}
static void __init bootmem_init(void)
{
init_initrd();
finalize_initrd();
}
static void __init bootmem_init(void)
{
unsigned long reserved_end;
unsigned long mapstart = ~0UL;
unsigned long bootmap_size;
int i;
reserved_end = max(init_initrd(),
(unsigned long) PFN_UP(__pa_symbol(&_end)));
min_low_pfn = ~0UL;
max_low_pfn = 0;
for (i = 0; i < boot_mem_map.nr_map; i++) {
unsigned long start, end;
if (boot_mem_map.map[i].type != BOOT_MEM_RAM)
continue;
start = PFN_UP(boot_mem_map.map[i].addr);
end = PFN_DOWN(boot_mem_map.map[i].addr
+ boot_mem_map.map[i].size);
if (end > max_low_pfn)
max_low_pfn = end;
if (start < min_low_pfn)
min_low_pfn = start;
if (end <= reserved_end)
continue;
if (start >= mapstart)
continue;
mapstart = max(reserved_end, start);
}
if (min_low_pfn >= max_low_pfn)
panic("Incorrect memory mapping !!!");
if (min_low_pfn > ARCH_PFN_OFFSET) {
pr_info("Wasting %lu bytes for tracking %lu unused pages\n",
(min_low_pfn - ARCH_PFN_OFFSET) * sizeof(struct page),
min_low_pfn - ARCH_PFN_OFFSET);
} else if (min_low_pfn < ARCH_PFN_OFFSET) {
pr_info("%lu free pages won't be used\n",
ARCH_PFN_OFFSET - min_low_pfn);
}
min_low_pfn = ARCH_PFN_OFFSET;
max_pfn = max_low_pfn;
if (max_low_pfn > PFN_DOWN(HIGHMEM_START)) {
#ifdef CONFIG_HIGHMEM
highstart_pfn = PFN_DOWN(HIGHMEM_START);
highend_pfn = max_low_pfn;
#endif
max_low_pfn = PFN_DOWN(HIGHMEM_START);
}
bootmap_size = init_bootmem_node(NODE_DATA(0), mapstart,
min_low_pfn, max_low_pfn);
for (i = 0; i < boot_mem_map.nr_map; i++) {
unsigned long start, end;
start = PFN_UP(boot_mem_map.map[i].addr);
end = PFN_DOWN(boot_mem_map.map[i].addr
+ boot_mem_map.map[i].size);
if (start <= min_low_pfn)
start = min_low_pfn;
if (start >= end)
continue;
#ifndef CONFIG_HIGHMEM
if (end > max_low_pfn)
end = max_low_pfn;
if (end <= start)
continue;
#endif
memblock_add_node(PFN_PHYS(start), PFN_PHYS(end - start), 0);
}
for (i = 0; i < boot_mem_map.nr_map; i++) {
unsigned long start, end, size;
start = PFN_UP(boot_mem_map.map[i].addr);
end = PFN_DOWN(boot_mem_map.map[i].addr
+ boot_mem_map.map[i].size);
switch (boot_mem_map.map[i].type) {
case BOOT_MEM_RAM:
break;
case BOOT_MEM_INIT_RAM:
memory_present(0, start, end);
continue;
default:
continue;
}
if (start >= max_low_pfn)
continue;
if (start < reserved_end)
start = reserved_end;
if (end > max_low_pfn)
end = max_low_pfn;
if (end <= start)
continue;
size = end - start;
free_bootmem(PFN_PHYS(start), size << PAGE_SHIFT);
memory_present(0, start, end);
}
reserve_bootmem(PFN_PHYS(mapstart), bootmap_size, BOOTMEM_DEFAULT);
finalize_initrd();
}
static int __init early_parse_mem(char *p)
{
unsigned long start, size;
if (usermem == 0) {
boot_mem_map.nr_map = 0;
usermem = 1;
}
start = 0;
size = memparse(p, &p);
if (*p == '@')
start = memparse(p + 1, &p);
add_memory_region(start, size, BOOT_MEM_RAM);
return 0;
}
static void __init arch_mem_init(char **cmdline_p)
{
phys_t init_mem, init_end, init_size;
extern void plat_mem_setup(void);
plat_mem_setup();
init_mem = PFN_UP(__pa_symbol(&__init_begin)) << PAGE_SHIFT;
init_end = PFN_DOWN(__pa_symbol(&__init_end)) << PAGE_SHIFT;
init_size = init_end - init_mem;
if (init_size) {
int i, found;
found = 0;
for (i = 0; i < boot_mem_map.nr_map; i++) {
if (init_mem >= boot_mem_map.map[i].addr &&
init_mem < (boot_mem_map.map[i].addr +
boot_mem_map.map[i].size)) {
found = 1;
break;
}
}
if (!found)
add_memory_region(init_mem, init_size,
BOOT_MEM_INIT_RAM);
}
pr_info("Determined physical RAM map:\n");
print_memory_map();
#ifdef CONFIG_CMDLINE_BOOL
#ifdef CONFIG_CMDLINE_OVERRIDE
strlcpy(boot_command_line, builtin_cmdline, COMMAND_LINE_SIZE);
#else
if (builtin_cmdline[0]) {
strlcat(arcs_cmdline, " ", COMMAND_LINE_SIZE);
strlcat(arcs_cmdline, builtin_cmdline, COMMAND_LINE_SIZE);
}
strlcpy(boot_command_line, arcs_cmdline, COMMAND_LINE_SIZE);
#endif
#else
strlcpy(boot_command_line, arcs_cmdline, COMMAND_LINE_SIZE);
#endif
strlcpy(command_line, boot_command_line, COMMAND_LINE_SIZE);
*cmdline_p = command_line;
parse_early_param();
if (usermem) {
pr_info("User-defined physical RAM map:\n");
print_memory_map();
}
bootmem_init();
device_tree_init();
sparse_init();
plat_swiotlb_setup();
paging_init();
}
static void __init resource_init(void)
{
int i;
if (UNCAC_BASE != IO_BASE)
return;
code_resource.start = __pa_symbol(&_text);
code_resource.end = __pa_symbol(&_etext) - 1;
data_resource.start = __pa_symbol(&_etext);
data_resource.end = __pa_symbol(&_edata) - 1;
for (i = 0; i < boot_mem_map.nr_map; i++) {
struct resource *res;
unsigned long start, end;
start = boot_mem_map.map[i].addr;
end = boot_mem_map.map[i].addr + boot_mem_map.map[i].size - 1;
if (start >= HIGHMEM_START)
continue;
if (end >= HIGHMEM_START)
end = HIGHMEM_START - 1;
res = alloc_bootmem(sizeof(struct resource));
switch (boot_mem_map.map[i].type) {
case BOOT_MEM_RAM:
case BOOT_MEM_INIT_RAM:
case BOOT_MEM_ROM_DATA:
res->name = "System RAM";
break;
case BOOT_MEM_RESERVED:
default:
res->name = "reserved";
}
res->start = start;
res->end = end;
res->flags = IORESOURCE_MEM | IORESOURCE_BUSY;
request_resource(&iomem_resource, res);
request_resource(res, &code_resource);
request_resource(res, &data_resource);
}
}
void __init setup_arch(char **cmdline_p)
{
cpu_probe();
prom_init();
#ifdef CONFIG_EARLY_PRINTK
setup_early_printk();
#endif
cpu_report();
check_bugs_early();
#if defined(CONFIG_VT)
#if defined(CONFIG_VGA_CONSOLE)
conswitchp = &vga_con;
#elif defined(CONFIG_DUMMY_CONSOLE)
conswitchp = &dummy_con;
#endif
#endif
arch_mem_init(cmdline_p);
resource_init();
plat_smp_setup();
cpu_cache_init();
}
static int __init debugfs_mips(void)
{
struct dentry *d;
d = debugfs_create_dir("mips", NULL);
if (!d)
return -ENOMEM;
mips_debugfs_dir = d;
return 0;
}
