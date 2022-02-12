static void __init omap_zoom_init(void)
{
if (machine_is_omap_zoom2()) {
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
} else if (machine_is_omap_zoom3()) {
omap3_mux_init(board_mux, OMAP_PACKAGE_CBP);
omap_mux_init_gpio(ZOOM3_EHCI_RESET_GPIO, OMAP_PIN_OUTPUT);
usbhs_init_phys(phy_data, ARRAY_SIZE(phy_data));
usbhs_init(&usbhs_bdata);
}
board_nand_init(zoom_nand_partitions,
ARRAY_SIZE(zoom_nand_partitions), ZOOM_NAND_CS,
NAND_BUSWIDTH_16, nand_default_timings);
zoom_debugboard_init();
zoom_peripherals_init();
if (machine_is_omap_zoom2())
omap_sdrc_init(mt46h32m32lf6_sdrc_params,
mt46h32m32lf6_sdrc_params);
else if (machine_is_omap_zoom3())
omap_sdrc_init(h8mbx00u0mer0em_sdrc_params,
h8mbx00u0mer0em_sdrc_params);
zoom_display_init();
}
