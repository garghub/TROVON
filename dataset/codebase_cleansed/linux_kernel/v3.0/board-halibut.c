static void __init halibut_init_irq(void)
{
msm_init_irq();
}
static void __init halibut_init(void)
{
platform_add_devices(devices, ARRAY_SIZE(devices));
}
static void __init halibut_fixup(struct machine_desc *desc, struct tag *tags,
char **cmdline, struct meminfo *mi)
{
mi->nr_banks=1;
mi->bank[0].start = PHYS_OFFSET;
mi->bank[0].size = (101*1024*1024);
}
static void __init halibut_map_io(void)
{
msm_map_common_io();
msm_clock_init(msm_clocks_7x01a, msm_num_clocks_7x01a);
}
