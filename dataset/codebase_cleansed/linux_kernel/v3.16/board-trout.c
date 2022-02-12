static void __init trout_init_early(void)
{
arch_ioremap_caller = __msm_ioremap_caller;
}
static void __init trout_init_irq(void)
{
msm_init_irq();
}
static void __init trout_fixup(struct tag *tags, char **cmdline)
{
memblock_add(PHYS_OFFSET, 101*SZ_1M);
}
static void __init trout_init(void)
{
int rc;
platform_add_devices(devices, ARRAY_SIZE(devices));
if (IS_ENABLED(CONFIG_MMC)) {
rc = trout_init_mmc(system_rev);
if (rc)
pr_crit("MMC init failure (%d)\n", rc);
}
}
static void __init trout_map_io(void)
{
msm_map_common_io();
iotable_init(trout_io_desc, ARRAY_SIZE(trout_io_desc));
#ifdef CONFIG_MSM_DEBUG_UART3
writeb(0x80, TROUT_CPLD_BASE + 0x00);
#endif
}
static void __init trout_init_late(void)
{
smd_debugfs_init();
}
