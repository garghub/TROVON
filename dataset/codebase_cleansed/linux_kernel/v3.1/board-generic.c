static void __init omap_generic_init_irq(void)
{
omap1_init_common_hw();
omap1_init_irq();
}
static void __init omap_generic_init(void)
{
#ifdef CONFIG_ARCH_OMAP15XX
if (cpu_is_omap15xx()) {
omap_cfg_reg(UART1_TX);
omap_cfg_reg(UART1_RTS);
omap_cfg_reg(UART2_TX);
omap_cfg_reg(UART2_RTS);
omap_cfg_reg(UART3_TX);
omap_cfg_reg(UART3_RX);
omap1_usb_init(&generic1510_usb_config);
}
#endif
#if defined(CONFIG_ARCH_OMAP16XX)
if (!cpu_is_omap1510()) {
omap1_usb_init(&generic1610_usb_config);
}
#endif
omap_board_config = generic_config;
omap_board_config_size = ARRAY_SIZE(generic_config);
omap_serial_init();
omap_register_i2c_bus(1, 100, NULL, 0);
}
static void __init omap_generic_map_io(void)
{
omap1_map_common_io();
}
