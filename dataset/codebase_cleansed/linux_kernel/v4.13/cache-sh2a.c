static void sh2a_flush_oc_line(unsigned long v, int way)
{
unsigned long addr = (v & 0x000007f0) | (way << 11);
unsigned long data;
data = __raw_readl(CACHE_OC_ADDRESS_ARRAY | addr);
if ((data & CACHE_PHYSADDR_MASK) == (v & CACHE_PHYSADDR_MASK)) {
data &= ~SH_CACHE_UPDATED;
__raw_writel(data, CACHE_OC_ADDRESS_ARRAY | addr);
}
}
static void sh2a_invalidate_line(unsigned long cache_addr, unsigned long v)
{
unsigned long addr = (v & 0x000007f0) | SH_CACHE_ASSOC;
__raw_writel((addr & CACHE_PHYSADDR_MASK), cache_addr | addr);
}
static void sh2a__flush_wback_region(void *start, int size)
{
#ifdef CONFIG_CACHE_WRITEBACK
unsigned long v;
unsigned long begin, end;
unsigned long flags;
int nr_ways;
begin = (unsigned long)start & ~(L1_CACHE_BYTES-1);
end = ((unsigned long)start + size + L1_CACHE_BYTES-1)
& ~(L1_CACHE_BYTES-1);
nr_ways = current_cpu_data.dcache.ways;
local_irq_save(flags);
jump_to_uncached();
if (((end - begin) >> PAGE_SHIFT) >= MAX_OCACHE_PAGES) {
begin = CACHE_OC_ADDRESS_ARRAY;
end = begin + (nr_ways * current_cpu_data.dcache.way_size);
for (v = begin; v < end; v += L1_CACHE_BYTES) {
unsigned long data = __raw_readl(v);
if (data & SH_CACHE_UPDATED)
__raw_writel(data & ~SH_CACHE_UPDATED, v);
}
} else {
int way;
for (way = 0; way < nr_ways; way++) {
for (v = begin; v < end; v += L1_CACHE_BYTES)
sh2a_flush_oc_line(v, way);
}
}
back_to_cached();
local_irq_restore(flags);
#endif
}
static void sh2a__flush_purge_region(void *start, int size)
{
unsigned long v;
unsigned long begin, end;
unsigned long flags;
begin = (unsigned long)start & ~(L1_CACHE_BYTES-1);
end = ((unsigned long)start + size + L1_CACHE_BYTES-1)
& ~(L1_CACHE_BYTES-1);
local_irq_save(flags);
jump_to_uncached();
for (v = begin; v < end; v+=L1_CACHE_BYTES) {
#ifdef CONFIG_CACHE_WRITEBACK
int way;
int nr_ways = current_cpu_data.dcache.ways;
for (way = 0; way < nr_ways; way++)
sh2a_flush_oc_line(v, way);
#endif
sh2a_invalidate_line(CACHE_OC_ADDRESS_ARRAY, v);
}
back_to_cached();
local_irq_restore(flags);
}
static void sh2a__flush_invalidate_region(void *start, int size)
{
unsigned long v;
unsigned long begin, end;
unsigned long flags;
begin = (unsigned long)start & ~(L1_CACHE_BYTES-1);
end = ((unsigned long)start + size + L1_CACHE_BYTES-1)
& ~(L1_CACHE_BYTES-1);
local_irq_save(flags);
jump_to_uncached();
if (((end - begin) >> PAGE_SHIFT) >= MAX_OCACHE_PAGES) {
__raw_writel(__raw_readl(SH_CCR) | CCR_OCACHE_INVALIDATE,
SH_CCR);
} else {
for (v = begin; v < end; v += L1_CACHE_BYTES)
sh2a_invalidate_line(CACHE_OC_ADDRESS_ARRAY, v);
}
back_to_cached();
local_irq_restore(flags);
}
static void sh2a_flush_icache_range(void *args)
{
struct flusher_data *data = args;
unsigned long start, end;
unsigned long v;
unsigned long flags;
start = data->addr1 & ~(L1_CACHE_BYTES-1);
end = (data->addr2 + L1_CACHE_BYTES-1) & ~(L1_CACHE_BYTES-1);
#ifdef CONFIG_CACHE_WRITEBACK
sh2a__flush_wback_region((void *)start, end-start);
#endif
local_irq_save(flags);
jump_to_uncached();
if (((end - start) >> PAGE_SHIFT) >= MAX_ICACHE_PAGES) {
__raw_writel(__raw_readl(SH_CCR) | CCR_ICACHE_INVALIDATE,
SH_CCR);
} else {
for (v = start; v < end; v += L1_CACHE_BYTES)
sh2a_invalidate_line(CACHE_IC_ADDRESS_ARRAY, v);
}
back_to_cached();
local_irq_restore(flags);
}
void __init sh2a_cache_init(void)
{
local_flush_icache_range = sh2a_flush_icache_range;
__flush_wback_region = sh2a__flush_wback_region;
__flush_purge_region = sh2a__flush_purge_region;
__flush_invalidate_region = sh2a__flush_invalidate_region;
}
