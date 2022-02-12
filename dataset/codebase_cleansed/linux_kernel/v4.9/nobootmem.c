static void * __init __alloc_memory_core_early(int nid, u64 size, u64 align,
u64 goal, u64 limit)
{
void *ptr;
u64 addr;
ulong flags = choose_memblock_flags();
if (limit > memblock.current_limit)
limit = memblock.current_limit;
again:
addr = memblock_find_in_range_node(size, align, goal, limit, nid,
flags);
if (!addr && (flags & MEMBLOCK_MIRROR)) {
flags &= ~MEMBLOCK_MIRROR;
pr_warn("Could not allocate %pap bytes of mirrored memory\n",
&size);
goto again;
}
if (!addr)
return NULL;
if (memblock_reserve(addr, size))
return NULL;
ptr = phys_to_virt(addr);
memset(ptr, 0, size);
kmemleak_alloc(ptr, size, 0, 0);
return ptr;
}
void __init free_bootmem_late(unsigned long addr, unsigned long size)
{
unsigned long cursor, end;
kmemleak_free_part_phys(addr, size);
cursor = PFN_UP(addr);
end = PFN_DOWN(addr + size);
for (; cursor < end; cursor++) {
__free_pages_bootmem(pfn_to_page(cursor), cursor, 0);
totalram_pages++;
}
}
static void __init __free_pages_memory(unsigned long start, unsigned long end)
{
int order;
while (start < end) {
order = min(MAX_ORDER - 1UL, __ffs(start));
while (start + (1UL << order) > end)
order--;
__free_pages_bootmem(pfn_to_page(start), start, order);
start += (1UL << order);
}
}
static unsigned long __init __free_memory_core(phys_addr_t start,
phys_addr_t end)
{
unsigned long start_pfn = PFN_UP(start);
unsigned long end_pfn = min_t(unsigned long,
PFN_DOWN(end), max_low_pfn);
if (start_pfn > end_pfn)
return 0;
__free_pages_memory(start_pfn, end_pfn);
return end_pfn - start_pfn;
}
static unsigned long __init free_low_memory_core_early(void)
{
unsigned long count = 0;
phys_addr_t start, end;
u64 i;
memblock_clear_hotplug(0, -1);
for_each_reserved_mem_region(i, &start, &end)
reserve_bootmem_region(start, end);
for_each_free_mem_range(i, NUMA_NO_NODE, MEMBLOCK_NONE, &start, &end,
NULL)
count += __free_memory_core(start, end);
#ifdef CONFIG_ARCH_DISCARD_MEMBLOCK
{
phys_addr_t size;
size = get_allocated_memblock_reserved_regions_info(&start);
if (size)
count += __free_memory_core(start, start + size);
size = get_allocated_memblock_memory_regions_info(&start);
if (size)
count += __free_memory_core(start, start + size);
}
#endif
return count;
}
void reset_node_managed_pages(pg_data_t *pgdat)
{
struct zone *z;
for (z = pgdat->node_zones; z < pgdat->node_zones + MAX_NR_ZONES; z++)
z->managed_pages = 0;
}
void __init reset_all_zones_managed_pages(void)
{
struct pglist_data *pgdat;
if (reset_managed_pages_done)
return;
for_each_online_pgdat(pgdat)
reset_node_managed_pages(pgdat);
reset_managed_pages_done = 1;
}
unsigned long __init free_all_bootmem(void)
{
unsigned long pages;
reset_all_zones_managed_pages();
pages = free_low_memory_core_early();
totalram_pages += pages;
return pages;
}
void __init free_bootmem_node(pg_data_t *pgdat, unsigned long physaddr,
unsigned long size)
{
memblock_free(physaddr, size);
}
void __init free_bootmem(unsigned long addr, unsigned long size)
{
memblock_free(addr, size);
}
static void * __init ___alloc_bootmem_nopanic(unsigned long size,
unsigned long align,
unsigned long goal,
unsigned long limit)
{
void *ptr;
if (WARN_ON_ONCE(slab_is_available()))
return kzalloc(size, GFP_NOWAIT);
restart:
ptr = __alloc_memory_core_early(NUMA_NO_NODE, size, align, goal, limit);
if (ptr)
return ptr;
if (goal != 0) {
goal = 0;
goto restart;
}
return NULL;
}
void * __init __alloc_bootmem_nopanic(unsigned long size, unsigned long align,
unsigned long goal)
{
unsigned long limit = -1UL;
return ___alloc_bootmem_nopanic(size, align, goal, limit);
}
static void * __init ___alloc_bootmem(unsigned long size, unsigned long align,
unsigned long goal, unsigned long limit)
{
void *mem = ___alloc_bootmem_nopanic(size, align, goal, limit);
if (mem)
return mem;
pr_alert("bootmem alloc of %lu bytes failed!\n", size);
panic("Out of memory");
return NULL;
}
void * __init __alloc_bootmem(unsigned long size, unsigned long align,
unsigned long goal)
{
unsigned long limit = -1UL;
return ___alloc_bootmem(size, align, goal, limit);
}
void * __init ___alloc_bootmem_node_nopanic(pg_data_t *pgdat,
unsigned long size,
unsigned long align,
unsigned long goal,
unsigned long limit)
{
void *ptr;
again:
ptr = __alloc_memory_core_early(pgdat->node_id, size, align,
goal, limit);
if (ptr)
return ptr;
ptr = __alloc_memory_core_early(NUMA_NO_NODE, size, align,
goal, limit);
if (ptr)
return ptr;
if (goal) {
goal = 0;
goto again;
}
return NULL;
}
void * __init __alloc_bootmem_node_nopanic(pg_data_t *pgdat, unsigned long size,
unsigned long align, unsigned long goal)
{
if (WARN_ON_ONCE(slab_is_available()))
return kzalloc_node(size, GFP_NOWAIT, pgdat->node_id);
return ___alloc_bootmem_node_nopanic(pgdat, size, align, goal, 0);
}
static void * __init ___alloc_bootmem_node(pg_data_t *pgdat, unsigned long size,
unsigned long align, unsigned long goal,
unsigned long limit)
{
void *ptr;
ptr = ___alloc_bootmem_node_nopanic(pgdat, size, align, goal, limit);
if (ptr)
return ptr;
pr_alert("bootmem alloc of %lu bytes failed!\n", size);
panic("Out of memory");
return NULL;
}
void * __init __alloc_bootmem_node(pg_data_t *pgdat, unsigned long size,
unsigned long align, unsigned long goal)
{
if (WARN_ON_ONCE(slab_is_available()))
return kzalloc_node(size, GFP_NOWAIT, pgdat->node_id);
return ___alloc_bootmem_node(pgdat, size, align, goal, 0);
}
void * __init __alloc_bootmem_node_high(pg_data_t *pgdat, unsigned long size,
unsigned long align, unsigned long goal)
{
return __alloc_bootmem_node(pgdat, size, align, goal);
}
void * __init __alloc_bootmem_low(unsigned long size, unsigned long align,
unsigned long goal)
{
return ___alloc_bootmem(size, align, goal, ARCH_LOW_ADDRESS_LIMIT);
}
void * __init __alloc_bootmem_low_nopanic(unsigned long size,
unsigned long align,
unsigned long goal)
{
return ___alloc_bootmem_nopanic(size, align, goal,
ARCH_LOW_ADDRESS_LIMIT);
}
void * __init __alloc_bootmem_low_node(pg_data_t *pgdat, unsigned long size,
unsigned long align, unsigned long goal)
{
if (WARN_ON_ONCE(slab_is_available()))
return kzalloc_node(size, GFP_NOWAIT, pgdat->node_id);
return ___alloc_bootmem_node(pgdat, size, align, goal,
ARCH_LOW_ADDRESS_LIMIT);
}
