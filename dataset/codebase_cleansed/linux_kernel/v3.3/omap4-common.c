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
void __iomem *gic_dist_base_addr;
gic_dist_base_addr = ioremap(OMAP44XX_GIC_DIST_BASE, SZ_4K);
BUG_ON(!gic_dist_base_addr);
omap_irq_base = ioremap(OMAP44XX_GIC_CPU_BASE, SZ_512);
BUG_ON(!omap_irq_base);
omap_wakeupgen_init();
gic_init(0, 29, gic_dist_base_addr, omap_irq_base);
}
void __iomem *omap4_get_l2cache_base(void)
{
return l2cache_base;
}
static void omap4_l2x0_disable(void)
{
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
if (!cpu_is_omap44xx())
return -ENOMEM;
sar_ram_base = ioremap(OMAP44XX_SAR_RAM_BASE, SZ_16K);
if (WARN_ON(!sar_ram_base))
return -ENOMEM;
return 0;
}
