static void __init board_smc91x_init(void)
{
board_smc91x_data.gpio_irq = 158;
gpmc_smc91x_init(&board_smc91x_data);
}
static inline void board_smc91x_init(void)
{
}
static void enable_board_wakeup_source(void)
{
omap_mux_init_signal("sys_nirq",
OMAP_WAKEUP_EN | OMAP_PIN_INPUT_PULLUP);
}
static void __init omap_sdp_init(void)
{
omap3_mux_init(board_mux, OMAP_PACKAGE_CBP);
zoom_peripherals_init();
omap_sdrc_init(h8mbx00u0mer0em_sdrc_params,
h8mbx00u0mer0em_sdrc_params);
zoom_display_init();
board_smc91x_init();
board_flash_init(sdp_flash_partitions, chip_sel_sdp, NAND_BUSWIDTH_16);
enable_board_wakeup_source();
usbhs_init(&usbhs_bdata);
}
