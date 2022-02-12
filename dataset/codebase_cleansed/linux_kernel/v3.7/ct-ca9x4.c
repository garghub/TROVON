static void __init ct_ca9x4_map_io(void)
{
iotable_init(ct_ca9x4_io_desc, ARRAY_SIZE(ct_ca9x4_io_desc));
}
static void __init ca9x4_twd_init(void)
{
int err = twd_local_timer_register(&twd_local_timer);
if (err)
pr_err("twd_local_timer_register failed %d\n", err);
}
static void __init ct_ca9x4_init_irq(void)
{
gic_init(0, 29, ioremap(A9_MPCORE_GIC_DIST, SZ_4K),
ioremap(A9_MPCORE_GIC_CPU, SZ_256));
ca9x4_twd_init();
}
static void ct_ca9x4_clcd_enable(struct clcd_fb *fb)
{
u32 site = v2m_get_master_site();
v2m_cfg_write(SYS_CFG_MUXFPGA | SYS_CFG_SITE(site), site);
v2m_cfg_write(SYS_CFG_DVIMODE | SYS_CFG_SITE(SYS_CFG_SITE_MB), 2);
}
static int ct_ca9x4_clcd_setup(struct clcd_fb *fb)
{
unsigned long framesize = 1024 * 768 * 2;
fb->panel = versatile_clcd_get_panel("XVGA");
if (!fb->panel)
return -EINVAL;
return versatile_clcd_setup_dma(fb, framesize);
}
static void __init ct_ca9x4_init(void)
{
int i;
struct clk *clk;
#ifdef CONFIG_CACHE_L2X0
void __iomem *l2x0_base = ioremap(CT_CA9X4_L2CC, SZ_4K);
writel(0, l2x0_base + L2X0_TAG_LATENCY_CTRL);
writel(0, l2x0_base + L2X0_DATA_LATENCY_CTRL);
l2x0_init(l2x0_base, 0x00400000, 0xfe0fffff);
#endif
ct_osc1.site = v2m_get_master_site();
clk = v2m_osc_register("ct:osc1", &ct_osc1);
clk_register_clkdev(clk, NULL, "ct:clcd");
for (i = 0; i < ARRAY_SIZE(ct_ca9x4_amba_devs); i++)
amba_device_register(ct_ca9x4_amba_devs[i], &iomem_resource);
platform_device_register(&pmu_device);
}
static void __init ct_ca9x4_init_cpu_map(void)
{
int i, ncores;
ct_ca9x4_scu_base = ioremap(A9_MPCORE_SCU, SZ_128);
if (WARN_ON(!ct_ca9x4_scu_base))
return;
ncores = scu_get_core_count(ct_ca9x4_scu_base);
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
scu_enable(ct_ca9x4_scu_base);
}
