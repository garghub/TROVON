void __init emev2_map_io(void)
{
iotable_init(emev2_io_desc, ARRAY_SIZE(emev2_io_desc));
}
void __init emev2_add_standard_devices(void)
{
emev2_clock_init();
platform_add_devices(emev2_early_devices,
ARRAY_SIZE(emev2_early_devices));
platform_add_devices(emev2_late_devices,
ARRAY_SIZE(emev2_late_devices));
}
void __init emev2_init_delay(void)
{
shmobile_setup_delay(533, 1, 3);
}
void __init emev2_add_early_devices(void)
{
emev2_init_delay();
early_platform_add_devices(emev2_early_devices,
ARRAY_SIZE(emev2_early_devices));
shmobile_setup_console();
}
void __init emev2_init_irq(void)
{
void __iomem *gic_dist_base;
void __iomem *gic_cpu_base;
gic_dist_base = ioremap(0xe0028000, PAGE_SIZE);
gic_cpu_base = ioremap(0xe0020000, PAGE_SIZE);
BUG_ON(!gic_dist_base || !gic_cpu_base);
gic_init(0, 29, gic_dist_base, gic_cpu_base);
}
void __init emev2_add_standard_devices_dt(void)
{
of_platform_populate(NULL, of_default_bus_match_table,
emev2_auxdata_lookup, NULL);
}
