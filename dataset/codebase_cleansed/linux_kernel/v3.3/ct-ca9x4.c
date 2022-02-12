static void __init ct_ca9x4_map_io(void)
{
#ifdef CONFIG_LOCAL_TIMERS
twd_base = MMIO_P2V(A9_MPCORE_TWD);
#endif
iotable_init(ct_ca9x4_io_desc, ARRAY_SIZE(ct_ca9x4_io_desc));
}
static void __init ct_ca9x4_init_irq(void)
{
gic_init(0, 29, MMIO_P2V(A9_MPCORE_GIC_DIST),
MMIO_P2V(A9_MPCORE_GIC_CPU));
}
static void ct_ca9x4_clcd_enable(struct clcd_fb *fb)
{
v2m_cfg_write(SYS_CFG_MUXFPGA | SYS_CFG_SITE_DB1, 0);
v2m_cfg_write(SYS_CFG_DVIMODE | SYS_CFG_SITE_DB1, 2);
}
static int ct_ca9x4_clcd_setup(struct clcd_fb *fb)
{
unsigned long framesize = 1024 * 768 * 2;
fb->panel = versatile_clcd_get_panel("XVGA");
if (!fb->panel)
return -EINVAL;
return versatile_clcd_setup_dma(fb, framesize);
}
static long ct_round(struct clk *clk, unsigned long rate)
{
return rate;
}
static int ct_set(struct clk *clk, unsigned long rate)
{
return v2m_cfg_write(SYS_CFG_OSC | SYS_CFG_SITE_DB1 | 1, rate);
}
static void __init ct_ca9x4_init_early(void)
{
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
}
static void __init ct_ca9x4_init(void)
{
int i;
#ifdef CONFIG_CACHE_L2X0
void __iomem *l2x0_base = MMIO_P2V(CT_CA9X4_L2CC);
writel(0, l2x0_base + L2X0_TAG_LATENCY_CTRL);
writel(0, l2x0_base + L2X0_DATA_LATENCY_CTRL);
l2x0_init(l2x0_base, 0x00400000, 0xfe0fffff);
#endif
for (i = 0; i < ARRAY_SIZE(ct_ca9x4_amba_devs); i++)
amba_device_register(ct_ca9x4_amba_devs[i], &iomem_resource);
platform_device_register(&pmu_device);
}
static void __init ct_ca9x4_init_cpu_map(void)
{
int i, ncores = scu_get_core_count(MMIO_P2V(A9_MPCORE_SCU));
if (ncores > nr_cpu_ids) {
pr_warn("SMP: %u cores greater than maximum (%u), clipping\n",
ncores, nr_cpu_ids);
ncores = nr_cpu_ids;
}
for (i = 0; i < ncores; ++i)
set_cpu_possible(i, true);
set_smp_cross_call(gic_raise_softirq);
}
static void __init ct_ca9x4_smp_enable(unsigned int max_cpus)
{
scu_enable(MMIO_P2V(A9_MPCORE_SCU));
}
