static void __init omap_zoom_init_early(void)
{
omap2_init_common_infrastructure();
if (machine_is_omap_zoom2())
omap2_init_common_devices(mt46h32m32lf6_sdrc_params,
mt46h32m32lf6_sdrc_params);
else if (machine_is_omap_zoom3())
omap2_init_common_devices(h8mbx00u0mer0em_sdrc_params,
h8mbx00u0mer0em_sdrc_params);
}
static void __init omap_zoom_init(void)
{
if (machine_is_omap_zoom2()) {
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
} else if (machine_is_omap_zoom3()) {
omap3_mux_init(board_mux, OMAP_PACKAGE_CBP);
omap_mux_init_gpio(ZOOM3_EHCI_RESET_GPIO, OMAP_PIN_OUTPUT);
usbhs_init(&usbhs_bdata);
}
board_nand_init(zoom_nand_partitions, ARRAY_SIZE(zoom_nand_partitions),
ZOOM_NAND_CS, NAND_BUSWIDTH_16);
zoom_debugboard_init();
zoom_peripherals_init();
zoom_display_init();
}
