static void __init msm8960_map_io(void)
{
msm_map_msm8960_io();
}
static void __init msm8960_init_irq(void)
{
unsigned int i;
gic_init(0, GIC_PPI_START, MSM_QGIC_DIST_BASE,
(void *)MSM_QGIC_CPU_BASE);
writel(0xFFFFD7FF, MSM_QGIC_DIST_BASE + GIC_DIST_CONFIG + 4);
if (machine_is_msm8960_rumi3())
writel(0x0000FFFF, MSM_QGIC_DIST_BASE + GIC_DIST_ENABLE_SET);
for (i = GIC_PPI_START; i < GIC_SPI_START; i++) {
if (i != AVS_SVICINT && i != AVS_SVICINTSWDONE)
irq_set_handler(i, handle_percpu_irq);
}
}
static void __init msm8960_sim_init(void)
{
platform_add_devices(sim_devices, ARRAY_SIZE(sim_devices));
}
static void __init msm8960_rumi3_init(void)
{
platform_add_devices(rumi3_devices, ARRAY_SIZE(rumi3_devices));
}
