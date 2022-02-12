static void __init pcm038_init_sram(void)
{
__raw_writel(0x0000d843, MX27_IO_ADDRESS(MX27_WEIM_CSCRxU(1)));
__raw_writel(0x22252521, MX27_IO_ADDRESS(MX27_WEIM_CSCRxL(1)));
__raw_writel(0x22220a00, MX27_IO_ADDRESS(MX27_WEIM_CSCRxA(1)));
}
static int pcm038_usbh2_init(struct platform_device *pdev)
{
return mx27_initialize_usb_hw(pdev->id, MXC_EHCI_POWER_PINS_ENABLED |
MXC_EHCI_INTERFACE_DIFF_UNI);
}
static void __init pcm038_init(void)
{
imx27_soc_init();
mxc_gpio_setup_multiple_pins(pcm038_pins, ARRAY_SIZE(pcm038_pins),
"PCM038");
pcm038_init_sram();
imx27_add_imx_uart0(&uart_pdata);
imx27_add_imx_uart1(&uart_pdata);
imx27_add_imx_uart2(&uart_pdata);
mxc_gpio_mode(PE16_AF_OWIRE);
imx27_add_mxc_nand(&pcm038_nand_board_info);
i2c_register_board_info(1, pcm038_i2c_devices,
ARRAY_SIZE(pcm038_i2c_devices));
imx27_add_imx_i2c(1, &pcm038_i2c1_data);
mxc_gpio_mode(GPIO_PORTE | 18 | GPIO_GPIO | GPIO_OUT);
mxc_gpio_mode(GPIO_PORTD | 28 | GPIO_GPIO | GPIO_OUT);
mxc_gpio_mode(GPIO_PORTB | 23 | GPIO_GPIO | GPIO_IN);
imx27_add_spi_imx0(&pcm038_spi0_data);
spi_register_board_info(pcm038_spi_board_info,
ARRAY_SIZE(pcm038_spi_board_info));
imx27_add_mxc_ehci_hs(2, &usbh2_pdata);
imx27_add_fec(NULL);
platform_add_devices(platform_devices, ARRAY_SIZE(platform_devices));
imx27_add_imx2_wdt(NULL);
imx27_add_mxc_w1(NULL);
#ifdef CONFIG_MACH_PCM970_BASEBOARD
pcm970_baseboard_init();
#endif
}
static void __init pcm038_timer_init(void)
{
mx27_clocks_init(26000000);
}
