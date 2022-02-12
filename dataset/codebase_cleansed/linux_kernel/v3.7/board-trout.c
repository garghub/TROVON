static void __init trout_init_early(void)
{
arch_ioremap_caller = __msm_ioremap_caller;
}
static void __init trout_init_irq(void)
{
msm_init_irq();
}
static void __init trout_fixup(struct tag *tags, char **cmdline,
struct meminfo *mi)
{
mi->nr_banks = 1;
mi->bank[0].start = PHYS_OFFSET;
mi->bank[0].size = (101*1024*1024);
}
static void __init trout_init(void)
{
int rc;
platform_add_devices(devices, ARRAY_SIZE(devices));
#ifdef CONFIG_MMC
rc = trout_init_mmc(system_rev);
if (rc)
printk(KERN_CRIT "%s: MMC init failure (%d)\n", __func__, rc);
#endif
}
static void __init trout_map_io(void)
{
msm_map_common_io();
iotable_init(trout_io_desc, ARRAY_SIZE(trout_io_desc));
#ifdef CONFIG_MSM_DEBUG_UART3
writeb(0x80, TROUT_CPLD_BASE + 0x00);
#endif
msm_clock_init(msm_clocks_7x01a, msm_num_clocks_7x01a);
}
static void __init trout_init_late(void)
{
smd_debugfs_init();
}
