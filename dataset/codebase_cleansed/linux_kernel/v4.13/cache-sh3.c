static void sh3__flush_wback_region(void *start, int size)
{
unsigned long v, j;
unsigned long begin, end;
unsigned long flags;
begin = (unsigned long)start & ~(L1_CACHE_BYTES-1);
end = ((unsigned long)start + size + L1_CACHE_BYTES-1)
& ~(L1_CACHE_BYTES-1);
for (v = begin; v < end; v+=L1_CACHE_BYTES) {
unsigned long addrstart = CACHE_OC_ADDRESS_ARRAY;
for (j = 0; j < current_cpu_data.dcache.ways; j++) {
unsigned long data, addr, p;
p = __pa(v);
addr = addrstart | (v & current_cpu_data.dcache.entry_mask);
local_irq_save(flags);
data = __raw_readl(addr);
if ((data & CACHE_PHYSADDR_MASK) ==
(p & CACHE_PHYSADDR_MASK)) {
data &= ~SH_CACHE_UPDATED;
__raw_writel(data, addr);
local_irq_restore(flags);
break;
}
local_irq_restore(flags);
addrstart += current_cpu_data.dcache.way_incr;
}
}
}
static void sh3__flush_purge_region(void *start, int size)
{
unsigned long v;
unsigned long begin, end;
begin = (unsigned long)start & ~(L1_CACHE_BYTES-1);
end = ((unsigned long)start + size + L1_CACHE_BYTES-1)
& ~(L1_CACHE_BYTES-1);
for (v = begin; v < end; v+=L1_CACHE_BYTES) {
unsigned long data, addr;
data = (v & 0xfffffc00);
addr = CACHE_OC_ADDRESS_ARRAY |
(v & current_cpu_data.dcache.entry_mask) | SH_CACHE_ASSOC;
__raw_writel(data, addr);
}
}
void __init sh3_cache_init(void)
{
__flush_wback_region = sh3__flush_wback_region;
__flush_purge_region = sh3__flush_purge_region;
__flush_invalidate_region = sh3__flush_purge_region;
}
