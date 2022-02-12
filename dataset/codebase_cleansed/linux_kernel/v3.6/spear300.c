static void __init spear300_dt_init(void)
{
int ret;
pl080_plat_data.slave_channels = spear300_dma_info;
pl080_plat_data.num_slave_channels = ARRAY_SIZE(spear300_dma_info);
of_platform_populate(NULL, of_default_bus_match_table,
spear300_auxdata_lookup, NULL);
shirq_ras1.regs.base = ioremap(SPEAR300_TELECOM_BASE, SZ_4K);
if (shirq_ras1.regs.base) {
ret = spear_shirq_register(&shirq_ras1);
if (ret)
pr_err("Error registering Shared IRQ\n");
}
}
static void __init spear300_map_io(void)
{
spear3xx_map_io();
}
