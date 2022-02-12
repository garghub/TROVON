static void __init mx51_3ds_init(void)
{
mxc_iomux_v3_setup_multiple_pads(mx51_3ds_pads,
ARRAY_SIZE(mx51_3ds_pads));
imx51_add_imx_uart(0, &uart_pdata);
imx51_add_imx_uart(1, &uart_pdata);
imx51_add_imx_uart(2, &uart_pdata);
imx51_add_ecspi(1, &mx51_3ds_ecspi2_pdata);
spi_register_board_info(mx51_3ds_spi_nor_device,
ARRAY_SIZE(mx51_3ds_spi_nor_device));
if (mxc_expio_init(MX51_CS5_BASE_ADDR, EXPIO_PARENT_INT))
printk(KERN_WARNING "Init of the debugboard failed, all "
"devices on the board are unusable.\n");
imx51_add_sdhci_esdhc_imx(0, NULL);
imx51_add_imx_keypad(&mx51_3ds_map_data);
imx51_add_imx2_wdt(0, NULL);
}
static void __init mx51_3ds_timer_init(void)
{
mx51_clocks_init(32768, 24000000, 22579200, 0);
}
