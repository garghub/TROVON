static void __init sapphire_init_irq(void)
{
msm_init_irq();
}
static void __init sapphire_init(void)
{
platform_add_devices(devices, ARRAY_SIZE(devices));
}
static void __init sapphire_fixup(struct tag *tags, char **cmdline,
struct meminfo *mi)
{
int smi_sz = parse_tag_smi((const struct tag *)tags);
mi->nr_banks = 1;
mi->bank[0].start = PHYS_OFFSET;
mi->bank[0].node = PHYS_TO_NID(PHYS_OFFSET);
if (smi_sz == 32) {
mi->bank[0].size = (84*1024*1024);
} else if (smi_sz == 64) {
mi->bank[0].size = (101*1024*1024);
} else {
smi_sz = 64;
mi->bank[0].size = (101*1024*1024);
}
}
static void __init sapphire_map_io(void)
{
msm_map_common_io();
iotable_init(sapphire_io_desc, ARRAY_SIZE(sapphire_io_desc));
msm_clock_init();
}
