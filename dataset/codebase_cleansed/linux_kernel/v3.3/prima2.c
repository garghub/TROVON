void __init sirfsoc_mach_init(void)
{
of_platform_bus_probe(NULL, sirfsoc_of_bus_ids, NULL);
}
