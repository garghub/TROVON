static inline void blast_r5000_scache(void)
{
unsigned long start = INDEX_BASE;
unsigned long end = start + scache_size;
while(start < end) {
cache_op(R5K_Page_Invalidate_S, start);
start += SC_PAGE;
}
}
static void r5k_dma_cache_inv_sc(unsigned long addr, unsigned long size)
{
unsigned long end, a;
BUG_ON(size == 0);
if (size >= scache_size) {
blast_r5000_scache();
return;
}
a = addr & ~(SC_PAGE - 1);
end = (addr + size - 1) & ~(SC_PAGE - 1);
while (a <= end) {
cache_op(R5K_Page_Invalidate_S, a);
a += SC_PAGE;
}
}
static void r5k_sc_enable(void)
{
unsigned long flags;
local_irq_save(flags);
set_c0_config(R5K_CONF_SE);
blast_r5000_scache();
local_irq_restore(flags);
}
static void r5k_sc_disable(void)
{
unsigned long flags;
local_irq_save(flags);
blast_r5000_scache();
clear_c0_config(R5K_CONF_SE);
local_irq_restore(flags);
}
static inline int __init r5k_sc_probe(void)
{
unsigned long config = read_c0_config();
if (config & CONF_SC)
return(0);
scache_size = (512 * 1024) << ((config & R5K_CONF_SS) >> 20);
printk("R5000 SCACHE size %ldkB, linesize 32 bytes.\n",
scache_size >> 10);
return 1;
}
void r5k_sc_init(void)
{
if (r5k_sc_probe()) {
r5k_sc_enable();
bcops = &r5k_sc_ops;
}
}
