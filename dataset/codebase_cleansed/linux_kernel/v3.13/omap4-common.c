void omap_bus_sync(void)
{
if (dram_sync && sram_sync) {
writel_relaxed(readl_relaxed(dram_sync), dram_sync);
writel_relaxed(readl_relaxed(sram_sync), sram_sync);
isb();
}
}
int __init omap_barrier_reserve_memblock(void)
{
size = ALIGN(PAGE_SIZE, SZ_1M);
paddr = arm_memblock_steal(size, SZ_1M);
return 0;
}
void __init omap_barriers_init(void)
{
struct map_desc dram_io_desc[1];
dram_io_desc[0].virtual = OMAP4_DRAM_BARRIER_VA;
dram_io_desc[0].pfn = __phys_to_pfn(paddr);
dram_io_desc[0].length = size;
dram_io_desc[0].type = MT_MEMORY_SO;
iotable_init(dram_io_desc, ARRAY_SIZE(dram_io_desc));
dram_sync = (void __iomem *) dram_io_desc[0].virtual;
sram_sync = (void __iomem *) OMAP4_SRAM_VA;
pr_info("OMAP4: Map 0x%08llx to 0x%08lx for dram barrier\n",
(long long) paddr, dram_io_desc[0].virtual);
}
void __init omap_barriers_init(void)
{}
void __init gic_init_irq(void)
{
void __iomem *omap_irq_base;
gic_dist_base_addr = ioremap(OMAP44XX_GIC_DIST_BASE, SZ_4K);
BUG_ON(!gic_dist_base_addr);
twd_base = ioremap(OMAP44XX_LOCAL_TWD_BASE, SZ_4K);
BUG_ON(!twd_base);
omap_irq_base = ioremap(OMAP44XX_GIC_CPU_BASE, SZ_512);
BUG_ON(!omap_irq_base);
omap_wakeupgen_init();
gic_init(0, 29, gic_dist_base_addr, omap_irq_base);
}
void gic_dist_disable(void)
{
if (gic_dist_base_addr)
__raw_writel(0x0, gic_dist_base_addr + GIC_DIST_CTRL);
}
bool gic_dist_disabled(void)
{
return !(__raw_readl(gic_dist_base_addr + GIC_DIST_CTRL) & 0x1);
}
void gic_timer_retrigger(void)
{
u32 twd_int = __raw_readl(twd_base + TWD_TIMER_INTSTAT);
u32 gic_int = __raw_readl(gic_dist_base_addr + GIC_DIST_PENDING_SET);
u32 twd_ctrl = __raw_readl(twd_base + TWD_TIMER_CONTROL);
if (twd_int && !(gic_int & BIT(IRQ_LOCALTIMER))) {
pr_warn("%s: lost localtimer interrupt\n", __func__);
__raw_writel(1, twd_base + TWD_TIMER_INTSTAT);
if (!(twd_ctrl & TWD_TIMER_CONTROL_PERIODIC)) {
__raw_writel(1, twd_base + TWD_TIMER_COUNTER);
twd_ctrl |= TWD_TIMER_CONTROL_ENABLE;
__raw_writel(twd_ctrl, twd_base + TWD_TIMER_CONTROL);
}
}
}
void __iomem *omap4_get_l2cache_base(void)
{
return l2cache_base;
}
static void omap4_l2x0_disable(void)
{
outer_flush_all();
omap_smc1(0x102, 0x0);
}
static void omap4_l2x0_set_debug(unsigned long val)
{
omap_smc1(0x100, val);
}
static int __init omap_l2_cache_init(void)
{
u32 aux_ctrl = 0;
if (!cpu_is_omap44xx())
return -ENODEV;
l2cache_base = ioremap(OMAP44XX_L2CACHE_BASE, SZ_4K);
if (WARN_ON(!l2cache_base))
return -ENOMEM;
aux_ctrl = ((1 << L2X0_AUX_CTRL_ASSOCIATIVITY_SHIFT) |
(0x1 << 25) |
(0x1 << L2X0_AUX_CTRL_NS_LOCKDOWN_SHIFT) |
(0x1 << L2X0_AUX_CTRL_NS_INT_CTRL_SHIFT));
if (omap_rev() == OMAP4430_REV_ES1_0) {
aux_ctrl |= 0x2 << L2X0_AUX_CTRL_WAY_SIZE_SHIFT;
} else {
aux_ctrl |= ((0x3 << L2X0_AUX_CTRL_WAY_SIZE_SHIFT) |
(1 << L2X0_AUX_CTRL_SHARE_OVERRIDE_SHIFT) |
(1 << L2X0_AUX_CTRL_DATA_PREFETCH_SHIFT) |
(1 << L2X0_AUX_CTRL_INSTR_PREFETCH_SHIFT) |
(1 << L2X0_AUX_CTRL_EARLY_BRESP_SHIFT));
}
if (omap_rev() != OMAP4430_REV_ES1_0)
omap_smc1(0x109, aux_ctrl);
omap_smc1(0x102, 0x1);
if (of_have_populated_dt())
l2x0_of_init(aux_ctrl, L2X0_AUX_CTRL_MASK);
else
l2x0_init(l2cache_base, aux_ctrl, L2X0_AUX_CTRL_MASK);
outer_cache.disable = omap4_l2x0_disable;
outer_cache.set_debug = omap4_l2x0_set_debug;
return 0;
}
void __iomem *omap4_get_sar_ram_base(void)
{
return sar_ram_base;
}
static int __init omap4_sar_ram_init(void)
{
unsigned long sar_base;
if (cpu_is_omap44xx())
sar_base = OMAP44XX_SAR_RAM_BASE;
else if (soc_is_omap54xx())
sar_base = OMAP54XX_SAR_RAM_BASE;
else
return -ENOMEM;
sar_ram_base = ioremap(sar_base, SZ_16K);
if (WARN_ON(!sar_ram_base))
return -ENOMEM;
return 0;
}
void __init omap_gic_of_init(void)
{
struct device_node *np;
if (!cpu_is_omap446x())
goto skip_errata_init;
np = of_find_compatible_node(NULL, NULL, "arm,cortex-a9-gic");
gic_dist_base_addr = of_iomap(np, 0);
WARN_ON(!gic_dist_base_addr);
np = of_find_compatible_node(NULL, NULL, "arm,cortex-a9-twd-timer");
twd_base = of_iomap(np, 0);
WARN_ON(!twd_base);
skip_errata_init:
omap_wakeupgen_init();
irqchip_init();
}
