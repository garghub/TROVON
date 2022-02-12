void __init gic_init_irq(void)
{
void __iomem *gic_cpu_base;
gic_dist_base_addr = ioremap(OMAP44XX_GIC_DIST_BASE, SZ_4K);
BUG_ON(!gic_dist_base_addr);
gic_cpu_base = ioremap(OMAP44XX_GIC_CPU_BASE, SZ_512);
BUG_ON(!gic_cpu_base);
gic_init(0, 29, gic_dist_base_addr, gic_cpu_base);
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
BUG_ON(!l2cache_base);
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
