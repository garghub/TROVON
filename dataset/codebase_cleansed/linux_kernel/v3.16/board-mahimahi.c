static void __init mahimahi_init(void)
{
platform_add_devices(devices, ARRAY_SIZE(devices));
}
static void __init mahimahi_fixup(struct tag *tags, char **cmdline)
{
memblock_add(PHYS_OFFSET, 219*SZ_1M);
memblock_add(MSM_HIGHMEM_BASE, MSM_HIGHMEM_SIZE);
}
static void __init mahimahi_map_io(void)
{
msm_map_common_io();
msm_clock_init();
}
static void __init mahimahi_init_late(void)
{
smd_debugfs_init();
}
