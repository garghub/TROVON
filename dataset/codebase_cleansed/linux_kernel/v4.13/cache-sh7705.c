static inline void cache_wback_all(void)
{
unsigned long ways, waysize, addrstart;
ways = current_cpu_data.dcache.ways;
waysize = current_cpu_data.dcache.sets;
waysize <<= current_cpu_data.dcache.entry_shift;
addrstart = CACHE_OC_ADDRESS_ARRAY;
do {
unsigned long addr;
for (addr = addrstart;
addr < addrstart + waysize;
addr += current_cpu_data.dcache.linesz) {
unsigned long data;
int v = SH_CACHE_UPDATED | SH_CACHE_VALID;
data = __raw_readl(addr);
if ((data & v) == v)
__raw_writel(data & ~v, addr);
}
addrstart += current_cpu_data.dcache.way_incr;
} while (--ways);
}
static void sh7705_flush_icache_range(void *args)
{
struct flusher_data *data = args;
unsigned long start, end;
start = data->addr1;
end = data->addr2;
__flush_wback_region((void *)start, end - start);
}
static void __flush_dcache_page(unsigned long phys)
{
unsigned long ways, waysize, addrstart;
unsigned long flags;
phys |= SH_CACHE_VALID;
local_irq_save(flags);
jump_to_uncached();
ways = current_cpu_data.dcache.ways;
waysize = current_cpu_data.dcache.sets;
waysize <<= current_cpu_data.dcache.entry_shift;
addrstart = CACHE_OC_ADDRESS_ARRAY;
do {
unsigned long addr;
for (addr = addrstart;
addr < addrstart + waysize;
addr += current_cpu_data.dcache.linesz) {
unsigned long data;
data = __raw_readl(addr) & (0x1ffffC00 | SH_CACHE_VALID);
if (data == phys) {
data &= ~(SH_CACHE_VALID | SH_CACHE_UPDATED);
__raw_writel(data, addr);
}
}
addrstart += current_cpu_data.dcache.way_incr;
} while (--ways);
back_to_cached();
local_irq_restore(flags);
}
static void sh7705_flush_dcache_page(void *arg)
{
struct page *page = arg;
struct address_space *mapping = page_mapping(page);
if (mapping && !mapping_mapped(mapping))
clear_bit(PG_dcache_clean, &page->flags);
else
__flush_dcache_page(__pa(page_address(page)));
}
static void sh7705_flush_cache_all(void *args)
{
unsigned long flags;
local_irq_save(flags);
jump_to_uncached();
cache_wback_all();
back_to_cached();
local_irq_restore(flags);
}
static void sh7705_flush_cache_page(void *args)
{
struct flusher_data *data = args;
unsigned long pfn = data->addr2;
__flush_dcache_page(pfn << PAGE_SHIFT);
}
static void sh7705_flush_icache_page(void *page)
{
__flush_purge_region(page_address(page), PAGE_SIZE);
}
void __init sh7705_cache_init(void)
{
local_flush_icache_range = sh7705_flush_icache_range;
local_flush_dcache_page = sh7705_flush_dcache_page;
local_flush_cache_all = sh7705_flush_cache_all;
local_flush_cache_mm = sh7705_flush_cache_all;
local_flush_cache_dup_mm = sh7705_flush_cache_all;
local_flush_cache_range = sh7705_flush_cache_all;
local_flush_cache_page = sh7705_flush_cache_page;
local_flush_icache_page = sh7705_flush_icache_page;
}
