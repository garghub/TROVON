static void __init halibut_init_early(void)
{
arch_ioremap_caller = __msm_ioremap_caller;
}
static void __init halibut_init_irq(void)
{
msm_init_irq();
}
static void __init halibut_init(void)
{
platform_add_devices(devices, ARRAY_SIZE(devices));
}
static void __init halibut_fixup(struct tag *tags, char **cmdline,
struct meminfo *mi)
{
}
static void __init halibut_map_io(void)
{
msm_map_common_io();
msm_clock_init(msm_clocks_7x01a, msm_num_clocks_7x01a);
}
