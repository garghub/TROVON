static void __init spear310_dt_init(void)
{
void __iomem *base;
int ret;
pl080_plat_data.slave_channels = spear310_dma_info;
pl080_plat_data.num_slave_channels = ARRAY_SIZE(spear310_dma_info);
of_platform_populate(NULL, of_default_bus_match_table,
spear310_auxdata_lookup, NULL);
base = ioremap(SPEAR310_SOC_CONFIG_BASE, SZ_4K);
if (base) {
shirq_ras1.regs.base = base;
ret = spear_shirq_register(&shirq_ras1);
if (ret)
pr_err("Error registering Shared IRQ 1\n");
shirq_ras2.regs.base = base;
ret = spear_shirq_register(&shirq_ras2);
if (ret)
pr_err("Error registering Shared IRQ 2\n");
shirq_ras3.regs.base = base;
ret = spear_shirq_register(&shirq_ras3);
if (ret)
pr_err("Error registering Shared IRQ 3\n");
shirq_intrcomm_ras.regs.base = base;
ret = spear_shirq_register(&shirq_intrcomm_ras);
if (ret)
pr_err("Error registering Shared IRQ 4\n");
}
}
static void __init spear310_map_io(void)
{
spear3xx_map_io();
}
