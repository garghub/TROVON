void __init add_memory_region(phys_addr_t start, phys_addr_t size, long type)
{
int x = boot_mem_map.nr_map;
int i;
if (start + size - 1 == (phys_addr_t)ULLONG_MAX)
--size;
if (start + size < start) {
pr_warn("Trying to add an invalid memory region, skipped\n");
return;
}
for (i = 0; i < boot_mem_map.nr_map; i++) {
struct boot_mem_map_entry *entry = boot_mem_map.map + i;
unsigned long top;
if (entry->type != type)
continue;
if (start + size < entry->addr)
continue;
if (entry->addr + entry->size < start)
continue;
top = max(entry->addr + entry->size, start + size);
entry->addr = min(entry->addr, start);
entry->size = top - entry->addr;
return;
}
if (boot_mem_map.nr_map == BOOT_MEM_MAP_MAX) {
pr_err("Ooops! Too many entries in the memory map!\n");
return;
}
boot_mem_map.map[x].addr = start;
boot_mem_map.map[x].size = size;
boot_mem_map.map[x].type = type;
boot_mem_map.nr_map++;
}
void __init detect_memory_region(phys_addr_t start, phys_addr_t sz_min, phys_addr_t sz_max)
{
void *dm = &detect_magic;
phys_addr_t size;
for (size = sz_min; size < sz_max; size <<= 1) {
if (!memcmp(dm, dm + size, sizeof(detect_magic)))
break;
}
pr_debug("Memory: %lluMB of RAM detected at 0x%llx (min: %lluMB, max: %lluMB)\n",
((unsigned long long) size) / SZ_1M,
(unsigned long long) start,
((unsigned long long) sz_min) / SZ_1M,
((unsigned long long) sz_max) / SZ_1M);
add_memory_region(start, size, BOOT_MEM_RAM);
}
bool __init memory_region_available(phys_addr_t start, phys_addr_t size)
{
int i;
bool in_ram = false, free = true;
for (i = 0; i < boot_mem_map.nr_map; i++) {
phys_addr_t start_, end_;
start_ = boot_mem_map.map[i].addr;
end_ = boot_mem_map.map[i].addr + boot_mem_map.map[i].size;
switch (boot_mem_map.map[i].type) {
case BOOT_MEM_RAM:
if (start >= start_ && start + size <= end_)
in_ram = true;
break;
case BOOT_MEM_RESERVED:
if ((start >= start_ && start < end_) ||
(start < start_ && start + size >= start_))
free = false;
break;
default:
continue;
}
}
return in_ram && free;
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
static void __init maybe_bswap_initrd(void)
{
#if defined(CONFIG_CPU_CAVIUM_OCTEON)
u64 buf;
if (!memcmp((void *)initrd_start, "070701", 6))
return;
if (decompress_method((unsigned char *)initrd_start, 8, NULL))
return;
buf = swab64p((u64 *)initrd_start);
if (!memcmp(&buf, "070701", 6) ||
decompress_method((unsigned char *)(&buf), 8, NULL)) {
unsigned long i;
pr_info("Byteswapped initrd detected\n");
for (i = initrd_start; i < ALIGN(initrd_end, 8); i += 8)
swab64s((u64 *)i);
}
#endif
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
maybe_bswap_initrd();
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
static unsigned long __init bootmap_bytes(unsigned long pages)
{
unsigned long bytes = DIV_ROUND_UP(pages, 8);
return ALIGN(bytes, sizeof(long));
}
static void __init bootmem_init(void)
{
unsigned long reserved_end;
unsigned long mapstart = ~0UL;
unsigned long bootmap_size;
bool bootmap_valid = false;
int i;
init_initrd();
reserved_end = (unsigned long) PFN_UP(__pa_symbol(&_end));
min_low_pfn = ~0UL;
max_low_pfn = 0;
for (i = 0; i < boot_mem_map.nr_map; i++) {
unsigned long start, end;
if (boot_mem_map.map[i].type != BOOT_MEM_RAM)
continue;
start = PFN_UP(boot_mem_map.map[i].addr);
end = PFN_DOWN(boot_mem_map.map[i].addr
+ boot_mem_map.map[i].size);
#ifndef CONFIG_HIGHMEM
if (start >= PFN_DOWN(HIGHMEM_START))
continue;
if (end > PFN_DOWN(HIGHMEM_START))
end = PFN_DOWN(HIGHMEM_START);
#endif
if (end > max_low_pfn)
max_low_pfn = end;
if (start < min_low_pfn)
min_low_pfn = start;
if (end <= reserved_end)
continue;
#ifdef CONFIG_BLK_DEV_INITRD
if (initrd_end && end <= (unsigned long)PFN_UP(__pa(initrd_end)))
continue;
#endif
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
#ifdef CONFIG_BLK_DEV_INITRD
if (initrd_end)
mapstart = max(mapstart, (unsigned long)PFN_UP(__pa(initrd_end)));
#endif
bootmap_size = bootmap_bytes(max_low_pfn - min_low_pfn);
bootmap_valid = memory_region_available(PFN_PHYS(mapstart),
bootmap_size);
for (i = 0; i < boot_mem_map.nr_map && !bootmap_valid; i++) {
unsigned long mapstart_addr;
switch (boot_mem_map.map[i].type) {
case BOOT_MEM_RESERVED:
mapstart_addr = PFN_ALIGN(boot_mem_map.map[i].addr +
boot_mem_map.map[i].size);
if (PHYS_PFN(mapstart_addr) < mapstart)
break;
bootmap_valid = memory_region_available(mapstart_addr,
bootmap_size);
if (bootmap_valid)
mapstart = PHYS_PFN(mapstart_addr);
break;
default:
break;
}
}
if (!bootmap_valid)
panic("No memory area to place a bootmap bitmap");
if (bootmap_size != init_bootmem_node(NODE_DATA(0), mapstart,
min_low_pfn, max_low_pfn))
panic("Unexpected memory size required for bootmap");
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
if (start > min_low_pfn && end < max_low_pfn)
reserve_bootmem(boot_mem_map.map[i].addr,
boot_mem_map.map[i].size,
BOOTMEM_DEFAULT);
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
#ifdef CONFIG_RELOCATABLE
if (__pa_symbol(_text) > __pa_symbol(VMLINUX_LOAD_ADDRESS)) {
unsigned long offset;
extern void show_kernel_relocation(const char *level);
offset = __pa_symbol(_text) - __pa_symbol(VMLINUX_LOAD_ADDRESS);
free_bootmem(__pa_symbol(VMLINUX_LOAD_ADDRESS), offset);
#if defined(CONFIG_DEBUG_KERNEL) && defined(CONFIG_DEBUG_INFO)
show_kernel_relocation(KERN_INFO);
#endif
}
#endif
finalize_initrd();
}
static int __init early_parse_mem(char *p)
{
phys_addr_t start, size;
if (usermem == 0) {
boot_mem_map.nr_map = 0;
usermem = 1;
}
start = 0;
size = memparse(p, &p);
if (*p == '@')
start = memparse(p + 1, &p);
add_memory_region(start, size, BOOT_MEM_RAM);
if (start && start > PHYS_OFFSET)
add_memory_region(PHYS_OFFSET, start - PHYS_OFFSET,
BOOT_MEM_RESERVED);
return 0;
}
static int __init early_parse_elfcorehdr(char *p)
{
int i;
setup_elfcorehdr = memparse(p, &p);
for (i = 0; i < boot_mem_map.nr_map; i++) {
unsigned long start = boot_mem_map.map[i].addr;
unsigned long end = (boot_mem_map.map[i].addr +
boot_mem_map.map[i].size);
if (setup_elfcorehdr >= start && setup_elfcorehdr < end) {
setup_elfcorehdr_size = end - setup_elfcorehdr;
break;
}
}
return 0;
}
static void __init arch_mem_addpart(phys_addr_t mem, phys_addr_t end, int type)
{
phys_addr_t size;
int i;
size = end - mem;
if (!size)
return;
for (i = 0; i < boot_mem_map.nr_map; i++) {
if (mem >= boot_mem_map.map[i].addr &&
mem < (boot_mem_map.map[i].addr +
boot_mem_map.map[i].size))
return;
}
add_memory_region(mem, size, type);
}
static inline unsigned long long get_total_mem(void)
{
unsigned long long total;
total = max_pfn - min_low_pfn;
return total << PAGE_SHIFT;
}
static void __init mips_parse_crashkernel(void)
{
unsigned long long total_mem;
unsigned long long crash_size, crash_base;
int ret;
total_mem = get_total_mem();
ret = parse_crashkernel(boot_command_line, total_mem,
&crash_size, &crash_base);
if (ret != 0 || crash_size <= 0)
return;
if (!memory_region_available(crash_base, crash_size)) {
pr_warn("Invalid memory region reserved for crash kernel\n");
return;
}
crashk_res.start = crash_base;
crashk_res.end = crash_base + crash_size - 1;
}
static void __init request_crashkernel(struct resource *res)
{
int ret;
if (crashk_res.start == crashk_res.end)
return;
ret = request_resource(res, &crashk_res);
if (!ret)
pr_info("Reserving %ldMB of memory at %ldMB for crashkernel\n",
(unsigned long)((crashk_res.end -
crashk_res.start + 1) >> 20),
(unsigned long)(crashk_res.start >> 20));
}
static void __init mips_parse_crashkernel(void)
{
}
static void __init request_crashkernel(struct resource *res)
{
}
static void __init arch_mem_init(char **cmdline_p)
{
struct memblock_region *reg;
extern void plat_mem_setup(void);
plat_mem_setup();
arch_mem_addpart(PFN_DOWN(__pa_symbol(&_text)) << PAGE_SHIFT,
PFN_UP(__pa_symbol(&_edata)) << PAGE_SHIFT,
BOOT_MEM_RAM);
arch_mem_addpart(PFN_UP(__pa_symbol(&__init_begin)) << PAGE_SHIFT,
PFN_DOWN(__pa_symbol(&__init_end)) << PAGE_SHIFT,
BOOT_MEM_INIT_RAM);
pr_info("Determined physical RAM map:\n");
print_memory_map();
#if defined(CONFIG_CMDLINE_BOOL) && defined(CONFIG_CMDLINE_OVERRIDE)
strlcpy(boot_command_line, builtin_cmdline, COMMAND_LINE_SIZE);
#else
if ((USE_PROM_CMDLINE && arcs_cmdline[0]) ||
(USE_DTB_CMDLINE && !boot_command_line[0]))
strlcpy(boot_command_line, arcs_cmdline, COMMAND_LINE_SIZE);
if (EXTEND_WITH_PROM && arcs_cmdline[0]) {
if (boot_command_line[0])
strlcat(boot_command_line, " ", COMMAND_LINE_SIZE);
strlcat(boot_command_line, arcs_cmdline, COMMAND_LINE_SIZE);
}
#if defined(CONFIG_CMDLINE_BOOL)
if (builtin_cmdline[0]) {
if (boot_command_line[0])
strlcat(boot_command_line, " ", COMMAND_LINE_SIZE);
strlcat(boot_command_line, builtin_cmdline, COMMAND_LINE_SIZE);
}
if (BUILTIN_EXTEND_WITH_PROM && arcs_cmdline[0]) {
if (boot_command_line[0])
strlcat(boot_command_line, " ", COMMAND_LINE_SIZE);
strlcat(boot_command_line, arcs_cmdline, COMMAND_LINE_SIZE);
}
#endif
#endif
strlcpy(command_line, boot_command_line, COMMAND_LINE_SIZE);
*cmdline_p = command_line;
parse_early_param();
if (usermem) {
pr_info("User-defined physical RAM map:\n");
print_memory_map();
}
early_init_fdt_reserve_self();
early_init_fdt_scan_reserved_mem();
bootmem_init();
#ifdef CONFIG_PROC_VMCORE
if (setup_elfcorehdr && setup_elfcorehdr_size) {
printk(KERN_INFO "kdump reserved memory at %lx-%lx\n",
setup_elfcorehdr, setup_elfcorehdr_size);
reserve_bootmem(setup_elfcorehdr, setup_elfcorehdr_size,
BOOTMEM_DEFAULT);
}
#endif
mips_parse_crashkernel();
#ifdef CONFIG_KEXEC
if (crashk_res.start != crashk_res.end)
reserve_bootmem(crashk_res.start,
crashk_res.end - crashk_res.start + 1,
BOOTMEM_DEFAULT);
#endif
device_tree_init();
sparse_init();
plat_swiotlb_setup();
dma_contiguous_reserve(PFN_PHYS(max_low_pfn));
for_each_memblock(reserved, reg)
if (reg->size != 0)
reserve_bootmem(reg->base, reg->size, BOOTMEM_DEFAULT);
reserve_bootmem_region(__pa_symbol(&__nosave_begin),
__pa_symbol(&__nosave_end));
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
res->start = start;
res->end = end;
res->flags = IORESOURCE_MEM | IORESOURCE_BUSY;
switch (boot_mem_map.map[i].type) {
case BOOT_MEM_RAM:
case BOOT_MEM_INIT_RAM:
case BOOT_MEM_ROM_DATA:
res->name = "System RAM";
res->flags |= IORESOURCE_SYSRAM;
break;
case BOOT_MEM_RESERVED:
default:
res->name = "reserved";
}
request_resource(&iomem_resource, res);
request_resource(res, &code_resource);
request_resource(res, &data_resource);
request_crashkernel(res);
}
}
static void __init prefill_possible_map(void)
{
int i, possible = num_possible_cpus();
if (possible > nr_cpu_ids)
possible = nr_cpu_ids;
for (i = 0; i < possible; i++)
set_cpu_possible(i, true);
for (; i < NR_CPUS; i++)
set_cpu_possible(i, false);
nr_cpu_ids = possible;
}
static inline void prefill_possible_map(void) {}
void __init setup_arch(char **cmdline_p)
{
cpu_probe();
mips_cm_probe();
prom_init();
setup_early_fdc_console();
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
prefill_possible_map();
cpu_cache_init();
paging_init();
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
