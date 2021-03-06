void show_mem(unsigned int filter)
{
int i, total_reserved = 0;
int total_shared = 0, total_cached = 0;
unsigned long total_present = 0;
pg_data_t *pgdat;
printk(KERN_INFO "Mem-info:\n");
show_free_areas(filter);
printk(KERN_INFO "Node memory in pages:\n");
for_each_online_pgdat(pgdat) {
unsigned long present;
unsigned long flags;
int shared = 0, cached = 0, reserved = 0;
int nid = pgdat->node_id;
if (skip_free_areas_node(filter, nid))
continue;
pgdat_resize_lock(pgdat, &flags);
present = pgdat->node_present_pages;
for(i = 0; i < pgdat->node_spanned_pages; i++) {
struct page *page;
if (unlikely(i % MAX_ORDER_NR_PAGES == 0))
touch_nmi_watchdog();
if (pfn_valid(pgdat->node_start_pfn + i))
page = pfn_to_page(pgdat->node_start_pfn + i);
else {
#ifdef CONFIG_VIRTUAL_MEM_MAP
if (max_gap < LARGE_GAP)
continue;
#endif
i = vmemmap_find_next_valid_pfn(nid, i) - 1;
continue;
}
if (PageReserved(page))
reserved++;
else if (PageSwapCache(page))
cached++;
else if (page_count(page))
shared += page_count(page)-1;
}
pgdat_resize_unlock(pgdat, &flags);
total_present += present;
total_reserved += reserved;
total_cached += cached;
total_shared += shared;
printk(KERN_INFO "Node %4d: RAM: %11ld, rsvd: %8d, "
"shrd: %10d, swpd: %10d\n", nid,
present, reserved, shared, cached);
}
printk(KERN_INFO "%ld pages of RAM\n", total_present);
printk(KERN_INFO "%d reserved pages\n", total_reserved);
printk(KERN_INFO "%d pages shared\n", total_shared);
printk(KERN_INFO "%d pages swap cached\n", total_cached);
printk(KERN_INFO "Total of %ld pages in page table cache\n",
quicklist_total_size());
printk(KERN_INFO "%ld free buffer pages\n", nr_free_buffer_pages());
}
static int __init
find_bootmap_location (u64 start, u64 end, void *arg)
{
u64 needed = *(unsigned long *)arg;
u64 range_start, range_end, free_start;
int i;
#if IGNORE_PFN0
if (start == PAGE_OFFSET) {
start += PAGE_SIZE;
if (start >= end)
return 0;
}
#endif
free_start = PAGE_OFFSET;
for (i = 0; i < num_rsvd_regions; i++) {
range_start = max(start, free_start);
range_end = min(end, rsvd_region[i].start & PAGE_MASK);
free_start = PAGE_ALIGN(rsvd_region[i].end);
if (range_end <= range_start)
continue;
if (range_end - range_start >= needed) {
bootmap_start = __pa(range_start);
return -1;
}
if (range_end == end)
return 0;
}
return 0;
}
void * __cpuinit
per_cpu_init (void)
{
static bool first_time = true;
void *cpu0_data = __cpu0_per_cpu;
unsigned int cpu;
if (!first_time)
goto skip;
first_time = false;
for_each_possible_cpu(cpu) {
void *src = cpu == 0 ? cpu0_data : __phys_per_cpu_start;
memcpy(cpu_data, src, __per_cpu_end - __per_cpu_start);
__per_cpu_offset[cpu] = (char *)cpu_data - __per_cpu_start;
per_cpu(local_per_cpu_offset, cpu) = __per_cpu_offset[cpu];
if (cpu == 0)
ia64_set_kr(IA64_KR_PER_CPU_DATA, __pa(cpu_data) -
(unsigned long)__per_cpu_start);
cpu_data += PERCPU_PAGE_SIZE;
}
skip:
return __per_cpu_start + __per_cpu_offset[smp_processor_id()];
}
static inline void
alloc_per_cpu_data(void)
{
cpu_data = __alloc_bootmem(PERCPU_PAGE_SIZE * num_possible_cpus(),
PERCPU_PAGE_SIZE, __pa(MAX_DMA_ADDRESS));
}
void __init
setup_per_cpu_areas(void)
{
struct pcpu_alloc_info *ai;
struct pcpu_group_info *gi;
unsigned int cpu;
ssize_t static_size, reserved_size, dyn_size;
int rc;
ai = pcpu_alloc_alloc_info(1, num_possible_cpus());
if (!ai)
panic("failed to allocate pcpu_alloc_info");
gi = &ai->groups[0];
for_each_possible_cpu(cpu)
gi->cpu_map[gi->nr_units++] = cpu;
static_size = __per_cpu_end - __per_cpu_start;
reserved_size = PERCPU_MODULE_RESERVE;
dyn_size = PERCPU_PAGE_SIZE - static_size - reserved_size;
if (dyn_size < 0)
panic("percpu area overflow static=%zd reserved=%zd\n",
static_size, reserved_size);
ai->static_size = static_size;
ai->reserved_size = reserved_size;
ai->dyn_size = dyn_size;
ai->unit_size = PERCPU_PAGE_SIZE;
ai->atom_size = PAGE_SIZE;
ai->alloc_size = PERCPU_PAGE_SIZE;
rc = pcpu_setup_first_chunk(ai, __per_cpu_start + __per_cpu_offset[0]);
if (rc)
panic("failed to setup percpu area (err=%d)", rc);
pcpu_free_alloc_info(ai);
}
void __init
find_memory (void)
{
unsigned long bootmap_size;
reserve_memory();
min_low_pfn = ~0UL;
max_low_pfn = 0;
efi_memmap_walk(find_max_min_low_pfn, NULL);
max_pfn = max_low_pfn;
bootmap_size = bootmem_bootmap_pages(max_pfn) << PAGE_SHIFT;
bootmap_start = ~0UL;
efi_memmap_walk(find_bootmap_location, &bootmap_size);
if (bootmap_start == ~0UL)
panic("Cannot find %ld bytes for bootmap\n", bootmap_size);
bootmap_size = init_bootmem_node(NODE_DATA(0),
(bootmap_start >> PAGE_SHIFT), 0, max_pfn);
efi_memmap_walk(filter_rsvd_memory, free_bootmem);
reserve_bootmem(bootmap_start, bootmap_size, BOOTMEM_DEFAULT);
find_initrd();
alloc_per_cpu_data();
}
static int count_pages(u64 start, u64 end, void *arg)
{
unsigned long *count = arg;
*count += (end - start) >> PAGE_SHIFT;
return 0;
}
void __init
paging_init (void)
{
unsigned long max_dma;
unsigned long max_zone_pfns[MAX_NR_ZONES];
num_physpages = 0;
efi_memmap_walk(count_pages, &num_physpages);
memset(max_zone_pfns, 0, sizeof(max_zone_pfns));
#ifdef CONFIG_ZONE_DMA
max_dma = virt_to_phys((void *) MAX_DMA_ADDRESS) >> PAGE_SHIFT;
max_zone_pfns[ZONE_DMA] = max_dma;
#endif
max_zone_pfns[ZONE_NORMAL] = max_low_pfn;
#ifdef CONFIG_VIRTUAL_MEM_MAP
efi_memmap_walk(filter_memory, register_active_ranges);
efi_memmap_walk(find_largest_hole, (u64 *)&max_gap);
if (max_gap < LARGE_GAP) {
vmem_map = (struct page *) 0;
free_area_init_nodes(max_zone_pfns);
} else {
unsigned long map_size;
map_size = PAGE_ALIGN(ALIGN(max_low_pfn, MAX_ORDER_NR_PAGES) *
sizeof(struct page));
VMALLOC_END -= map_size;
vmem_map = (struct page *) VMALLOC_END;
efi_memmap_walk(create_mem_map_page_table, NULL);
NODE_DATA(0)->node_mem_map = vmem_map +
find_min_pfn_with_active_regions();
free_area_init_nodes(max_zone_pfns);
printk("Virtual mem_map starts at 0x%p\n", mem_map);
}
#else
memblock_add_node(0, PFN_PHYS(max_low_pfn), 0);
free_area_init_nodes(max_zone_pfns);
#endif
zero_page_memmap_ptr = virt_to_page(ia64_imva(empty_zero_page));
}
