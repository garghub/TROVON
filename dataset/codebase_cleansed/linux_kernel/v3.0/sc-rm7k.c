static void rm7k_sc_wback_inv(unsigned long addr, unsigned long size)
{
unsigned long end, a;
pr_debug("rm7k_sc_wback_inv[%08lx,%08lx]", addr, size);
BUG_ON(size == 0);
blast_scache_range(addr, addr + size);
if (!rm7k_tcache_init)
return;
a = addr & ~(tc_pagesize - 1);
end = (addr + size - 1) & ~(tc_pagesize - 1);
while(1) {
invalidate_tcache_page(a);
if (a == end)
break;
a += tc_pagesize;
}
}
static void rm7k_sc_inv(unsigned long addr, unsigned long size)
{
unsigned long end, a;
pr_debug("rm7k_sc_inv[%08lx,%08lx]", addr, size);
BUG_ON(size == 0);
blast_inv_scache_range(addr, addr + size);
if (!rm7k_tcache_init)
return;
a = addr & ~(tc_pagesize - 1);
end = (addr + size - 1) & ~(tc_pagesize - 1);
while(1) {
invalidate_tcache_page(a);
if (a == end)
break;
a += tc_pagesize;
}
}
static void blast_rm7k_tcache(void)
{
unsigned long start = CKSEG0ADDR(0);
unsigned long end = start + tcache_size;
write_c0_taglo(0);
while (start < end) {
cache_op(Page_Invalidate_T, start);
start += tc_pagesize;
}
}
static __cpuinit void __rm7k_tc_enable(void)
{
int i;
set_c0_config(RM7K_CONF_TE);
write_c0_taglo(0);
write_c0_taghi(0);
for (i = 0; i < tcache_size; i += tc_lsize)
cache_op(Index_Store_Tag_T, CKSEG0ADDR(i));
}
static __cpuinit void rm7k_tc_enable(void)
{
if (read_c0_config() & RM7K_CONF_TE)
return;
BUG_ON(tcache_size == 0);
run_uncached(__rm7k_tc_enable);
}
static __cpuinit void __rm7k_sc_enable(void)
{
int i;
set_c0_config(RM7K_CONF_SE);
write_c0_taglo(0);
write_c0_taghi(0);
for (i = 0; i < scache_size; i += sc_lsize)
cache_op(Index_Store_Tag_SD, CKSEG0ADDR(i));
}
static __cpuinit void rm7k_sc_enable(void)
{
if (read_c0_config() & RM7K_CONF_SE)
return;
pr_info("Enabling secondary cache...\n");
run_uncached(__rm7k_sc_enable);
if (rm7k_tcache_init)
rm7k_tc_enable();
}
static void rm7k_tc_disable(void)
{
unsigned long flags;
local_irq_save(flags);
blast_rm7k_tcache();
clear_c0_config(RM7K_CONF_TE);
local_irq_save(flags);
}
static void rm7k_sc_disable(void)
{
clear_c0_config(RM7K_CONF_SE);
if (rm7k_tcache_init)
rm7k_tc_disable();
}
static __cpuinit void __probe_tcache(void)
{
unsigned long flags, addr, begin, end, pow2;
begin = (unsigned long) &_stext;
begin &= ~((8 * 1024 * 1024) - 1);
end = begin + (8 * 1024 * 1024);
local_irq_save(flags);
set_c0_config(RM7K_CONF_TE);
pow2 = (256 * 1024);
for (addr = begin; addr <= end; addr = (begin + pow2)) {
unsigned long *p = (unsigned long *) addr;
__asm__ __volatile__("nop" : : "r" (*p));
pow2 <<= 1;
}
write_c0_taglo(0);
write_c0_taghi(0);
cache_op(Index_Store_Tag_T, begin);
pow2 = (512 * 1024);
for (addr = begin + (512 * 1024); addr <= end; addr = begin + pow2) {
cache_op(Index_Load_Tag_T, addr);
if (!read_c0_taglo())
break;
pow2 <<= 1;
}
addr -= begin;
tcache_size = addr;
clear_c0_config(RM7K_CONF_TE);
local_irq_restore(flags);
}
void __cpuinit rm7k_sc_init(void)
{
struct cpuinfo_mips *c = &current_cpu_data;
unsigned int config = read_c0_config();
if ((config & RM7K_CONF_SC))
return;
c->scache.linesz = sc_lsize;
c->scache.ways = 4;
c->scache.waybit= __ffs(scache_size / c->scache.ways);
c->scache.waysize = scache_size / c->scache.ways;
c->scache.sets = scache_size / (c->scache.linesz * c->scache.ways);
printk(KERN_INFO "Secondary cache size %dK, linesize %d bytes.\n",
(scache_size >> 10), sc_lsize);
if (!(config & RM7K_CONF_SE))
rm7k_sc_enable();
bcops = &rm7k_sc_ops;
rm7k_tcache_init = 0;
tcache_size = 0;
if (config & RM7K_CONF_TC)
return;
run_uncached(__probe_tcache);
rm7k_tc_enable();
rm7k_tcache_init = 1;
c->tcache.linesz = tc_lsize;
c->tcache.ways = 1;
pr_info("Tertiary cache size %ldK.\n", (tcache_size >> 10));
}
