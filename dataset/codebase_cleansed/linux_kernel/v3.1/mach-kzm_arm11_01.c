static int __init kzm_init_ext_uart(void)
{
u8 tmp;
mxc_iomux_mode(IOMUX_MODE(MX31_PIN_GPIO1_1, IOMUX_CONFIG_GPIO));
gpio_request(IOMUX_TO_GPIO(MX31_PIN_GPIO1_1), "ext-uart-int");
gpio_direction_input(IOMUX_TO_GPIO(MX31_PIN_GPIO1_1));
tmp = __raw_readb(KZM_ARM11_IO_ADDRESS(KZM_ARM11_CTL1));
tmp |= 0x2;
__raw_writeb(tmp, KZM_ARM11_IO_ADDRESS(KZM_ARM11_CTL1));
return platform_device_register(&serial_device);
}
static inline int kzm_init_ext_uart(void)
{
return 0;
}
static int __init kzm_init_smsc9118(void)
{
mxc_iomux_mode(IOMUX_MODE(MX31_PIN_GPIO1_2, IOMUX_CONFIG_GPIO));
gpio_request(IOMUX_TO_GPIO(MX31_PIN_GPIO1_2), "smsc9118-int");
gpio_direction_input(IOMUX_TO_GPIO(MX31_PIN_GPIO1_2));
return platform_device_register(&kzm_smsc9118_device);
}
static inline int kzm_init_smsc9118(void)
{
return 0;
}
static void __init kzm_init_imx_uart(void)
{
imx31_add_imx_uart0(&uart_pdata);
imx31_add_imx_uart1(&uart_pdata);
}
static inline void kzm_init_imx_uart(void)
{
}
static void __init kzm_board_init(void)
{
imx31_soc_init();
mxc_iomux_setup_multiple_pins(kzm_pins,
ARRAY_SIZE(kzm_pins), "kzm");
kzm_init_ext_uart();
kzm_init_smsc9118();
kzm_init_imx_uart();
pr_info("Clock input source is 26MHz\n");
}
static void __init kzm_map_io(void)
{
mx31_map_io();
iotable_init(kzm_io_desc, ARRAY_SIZE(kzm_io_desc));
}
static void __init kzm_timer_init(void)
{
mx31_clocks_init(26000000);
}
