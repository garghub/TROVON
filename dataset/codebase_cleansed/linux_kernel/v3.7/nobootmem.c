static void * __init __alloc_memory_core_early(int nid, u64 size, u64 align,
u64 goal, u64 limit)
{
void *ptr;
u64 addr;
if (limit > memblock.current_limit)
limit = memblock.current_limit;
addr = memblock_find_in_range_node(goal, limit, size, align, nid);
if (!addr)
return NULL;
ptr = phys_to_virt(addr);
memset(ptr, 0, size);
memblock_reserve(addr, size);
kmemleak_alloc(ptr, size, 0, 0);
return ptr;
}
void __init free_bootmem_late(unsigned long addr, unsigned long size)
{
unsigned long cursor, end;
kmemleak_free_part(__va(addr), size);
cursor = PFN_UP(addr);
end = PFN_DOWN(addr + size);
for (; cursor < end; cursor++) {
__free_pages_bootmem(pfn_to_page(cursor), 0);
totalram_pages++;
}
}
static void __init __free_pages_memory(unsigned long start, unsigned long end)
{
unsigned long i, start_aligned, end_aligned;
int order = ilog2(BITS_PER_LONG);
start_aligned = (start + (BITS_PER_LONG - 1)) & ~(BITS_PER_LONG - 1);
end_aligned = end & ~(BITS_PER_LONG - 1);
if (end_aligned <= start_aligned) {
for (i = start; i < end; i++)
__free_pages_bootmem(pfn_to_page(i), 0);
return;
}
for (i = start; i < start_aligned; i++)
__free_pages_bootmem(pfn_to_page(i), 0);
for (i = start_aligned; i < end_aligned; i += BITS_PER_LONG)
__free_pages_bootmem(pfn_to_page(i), order);
for (i = end_aligned; i < end; i++)
__free_pages_bootmem(pfn_to_page(i), 0);
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
unsigned long __init free_low_memory_core_early(int nodeid)
{
unsigned long count = 0;
phys_addr_t start, end, size;
u64 i;
for_each_free_mem_range(i, MAX_NUMNODES, &start, &end, NULL)
count += __free_memory_core(start, end);
size = get_allocated_memblock_reserved_regions_info(&start);
if (size)
count += __free_memory_core(start, start + size);
return count;
}
unsigned long __init free_all_bootmem_node(pg_data_t *pgdat)
{
register_page_bootmem_info_node(pgdat);
return 0;
}
unsigned long __init free_all_bootmem(void)
{
return free_low_memory_core_early(MAX_NUMNODES);
}
void __init free_bootmem_node(pg_data_t *pgdat, unsigned long physaddr,
unsigned long size)
{
kmemleak_free_part(__va(physaddr), size);
memblock_free(physaddr, size);
}
void __init free_bootmem(unsigned long addr, unsigned long size)
{
kmemleak_free_part(__va(addr), size);
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
ptr = __alloc_memory_core_early(MAX_NUMNODES, size, align, goal, limit);
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
printk(KERN_ALERT "bootmem alloc of %lu bytes failed!\n", size);
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
ptr = __alloc_memory_core_early(MAX_NUMNODES, size, align,
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
void * __init ___alloc_bootmem_node(pg_data_t *pgdat, unsigned long size,
unsigned long align, unsigned long goal,
unsigned long limit)
{
void *ptr;
ptr = ___alloc_bootmem_node_nopanic(pgdat, size, align, goal, limit);
if (ptr)
return ptr;
printk(KERN_ALERT "bootmem alloc of %lu bytes failed!\n", size);
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
void * __init __alloc_bootmem_low_node(pg_data_t *pgdat, unsigned long size,
unsigned long align, unsigned long goal)
{
if (WARN_ON_ONCE(slab_is_available()))
return kzalloc_node(size, GFP_NOWAIT, pgdat->node_id);
return ___alloc_bootmem_node(pgdat, size, align, goal,
ARCH_LOW_ADDRESS_LIMIT);
}
