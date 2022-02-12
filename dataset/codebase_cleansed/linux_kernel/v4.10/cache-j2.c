static void j2_flush_icache(void *args)
{
unsigned cpu;
for_each_possible_cpu(cpu)
__raw_writel(CACHE_ENABLE | ICACHE_FLUSH, j2_ccr_base + cpu);
}
static void j2_flush_dcache(void *args)
{
unsigned cpu;
for_each_possible_cpu(cpu)
__raw_writel(CACHE_ENABLE | DCACHE_FLUSH, j2_ccr_base + cpu);
}
static void j2_flush_both(void *args)
{
unsigned cpu;
for_each_possible_cpu(cpu)
__raw_writel(CACHE_ENABLE | CACHE_FLUSH, j2_ccr_base + cpu);
}
void __init j2_cache_init(void)
{
if (!j2_ccr_base)
return;
local_flush_cache_all = j2_flush_both;
local_flush_cache_mm = j2_flush_both;
local_flush_cache_dup_mm = j2_flush_both;
local_flush_cache_page = j2_flush_both;
local_flush_cache_range = j2_flush_both;
local_flush_dcache_page = j2_flush_dcache;
local_flush_icache_range = j2_flush_icache;
local_flush_icache_page = j2_flush_icache;
local_flush_cache_sigtramp = j2_flush_icache;
pr_info("Initial J2 CCR is %.8x\n", __raw_readl(j2_ccr_base));
}
