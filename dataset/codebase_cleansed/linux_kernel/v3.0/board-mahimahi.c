static void __init mahimahi_init(void)
{
platform_add_devices(devices, ARRAY_SIZE(devices));
}
static void __init mahimahi_fixup(struct machine_desc *desc, struct tag *tags,
char **cmdline, struct meminfo *mi)
{
mi->nr_banks = 2;
mi->bank[0].start = PHYS_OFFSET;
mi->bank[0].node = PHYS_TO_NID(PHYS_OFFSET);
mi->bank[0].size = (219*1024*1024);
mi->bank[1].start = MSM_HIGHMEM_BASE;
mi->bank[1].node = PHYS_TO_NID(MSM_HIGHMEM_BASE);
mi->bank[1].size = MSM_HIGHMEM_SIZE;
}
static void __init mahimahi_map_io(void)
{
msm_map_common_io();
msm_clock_init();
}
