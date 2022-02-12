static void __init ti8168_init_early(void)
{
omap2_init_common_infrastructure();
omap2_init_common_devices(NULL, NULL);
}
static void __init ti8168_evm_init_irq(void)
{
omap_init_irq();
}
static void __init ti8168_evm_init(void)
{
omap_serial_init();
omap_board_config = ti8168_evm_config;
omap_board_config_size = ARRAY_SIZE(ti8168_evm_config);
}
static void __init ti8168_evm_map_io(void)
{
omap2_set_globals_ti816x();
omapti816x_map_common_io();
}
