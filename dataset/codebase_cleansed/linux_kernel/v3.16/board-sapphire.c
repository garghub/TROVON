static void __init sapphire_init_irq(void)
{
msm_init_irq();
}
static void __init sapphire_init(void)
{
platform_add_devices(devices, ARRAY_SIZE(devices));
}
static void __init sapphire_fixup(struct tag *tags, char **cmdline)
{
int smi_sz = parse_tag_smi((const struct tag *)tags);
if (smi_sz == 32) {
memblock_add(PHYS_OFFSET, 84*SZ_1M);
} else if (smi_sz == 64) {
memblock_add(PHYS_OFFSET, 101*SZ_1M);
} else {
memblock_add(PHYS_OFFSET, 101*SZ_1M);
smi_sz = 64;
}
}
static void __init sapphire_map_io(void)
{
msm_map_common_io();
iotable_init(sapphire_io_desc, ARRAY_SIZE(sapphire_io_desc));
msm_clock_init();
}
static void __init sapphire_init_late(void)
{
smd_debugfs_init();
}
