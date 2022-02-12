static void __init ti8168_evm_init(void)
{
omap_serial_init();
omap_sdrc_init(NULL, NULL);
omap_board_config = ti8168_evm_config;
omap_board_config_size = ARRAY_SIZE(ti8168_evm_config);
}
static void __init ti8168_evm_map_io(void)
{
omapti816x_map_common_io();
}
