static void __init seaboard_i2c_init(void)
{
gpio_request(TEGRA_GPIO_ISL29018_IRQ, "isl29018");
gpio_direction_input(TEGRA_GPIO_ISL29018_IRQ);
i2c_register_board_info(0, &isl29018_device, 1);
i2c_register_board_info(3, &adt7461_device, 1);
platform_device_register(&tegra_i2c_device1);
platform_device_register(&tegra_i2c_device2);
platform_device_register(&tegra_i2c_device3);
platform_device_register(&tegra_i2c_device4);
}
static void __init seaboard_common_init(void)
{
seaboard_pinmux_init();
tegra_clk_init_from_table(seaboard_clk_init_table);
tegra_sdhci_device1.dev.platform_data = &sdhci_pdata1;
tegra_sdhci_device3.dev.platform_data = &sdhci_pdata3;
tegra_sdhci_device4.dev.platform_data = &sdhci_pdata4;
platform_add_devices(seaboard_devices, ARRAY_SIZE(seaboard_devices));
}
static void __init tegra_seaboard_init(void)
{
debug_uart_platform_data[0].membase = IO_ADDRESS(TEGRA_UARTD_BASE);
debug_uart_platform_data[0].mapbase = TEGRA_UARTD_BASE;
debug_uart_platform_data[0].irq = INT_UARTD;
seaboard_common_init();
seaboard_i2c_init();
}
static void __init tegra_kaen_init(void)
{
debug_uart_platform_data[0].membase = IO_ADDRESS(TEGRA_UARTB_BASE);
debug_uart_platform_data[0].mapbase = TEGRA_UARTB_BASE;
debug_uart_platform_data[0].irq = INT_UARTB;
seaboard_common_init();
seaboard_i2c_init();
}
static void __init tegra_wario_init(void)
{
debug_uart_platform_data[0].membase = IO_ADDRESS(TEGRA_UARTB_BASE);
debug_uart_platform_data[0].mapbase = TEGRA_UARTB_BASE;
debug_uart_platform_data[0].irq = INT_UARTB;
seaboard_common_init();
seaboard_i2c_init();
}
