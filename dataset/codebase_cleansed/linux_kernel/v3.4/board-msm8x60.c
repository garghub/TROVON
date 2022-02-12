static void __init msm8x60_fixup(struct tag *tag, char **cmdline,
struct meminfo *mi)
{
for (; tag->hdr.size; tag = tag_next(tag))
if (tag->hdr.tag == ATAG_MEM &&
tag->u.mem.start == 0x40200000) {
tag->u.mem.start = 0x40000000;
tag->u.mem.size += SZ_2M;
}
}
static void __init msm8x60_reserve(void)
{
memblock_remove(0x40000000, SZ_2M);
}
static void __init msm8x60_map_io(void)
{
msm_map_msm8x60_io();
}
static void __init msm8x60_init_irq(void)
{
if (!of_have_populated_dt())
gic_init(0, GIC_PPI_START, MSM_QGIC_DIST_BASE,
(void *)MSM_QGIC_CPU_BASE);
#ifdef CONFIG_OF
else
of_irq_init(msm_dt_gic_match);
#endif
writel(0xFFFFD7FF, MSM_QGIC_DIST_BASE + GIC_DIST_CONFIG + 4);
if (!machine_is_msm8x60_sim())
writel(0x0000FFFF, MSM_QGIC_DIST_BASE + GIC_DIST_ENABLE_SET);
}
static void __init msm8x60_init(void)
{
}
static void __init msm8x60_dt_init(void)
{
if (of_machine_is_compatible("qcom,msm8660-surf")) {
printk(KERN_INFO "Init surf UART registers\n");
msm8x60_init_uart12dm();
}
of_platform_populate(NULL, of_default_bus_match_table,
msm_auxdata_lookup, NULL);
}
