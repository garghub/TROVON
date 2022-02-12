static void usb_host_port_power(int port, int power)
{
if (!power)
return;
__raw_writew(__raw_readw(0xe6890008) | 0x600, 0xe6890008);
}
static void __init g4evm_map_io(void)
{
iotable_init(g4evm_io_desc, ARRAY_SIZE(g4evm_io_desc));
sh7377_add_early_devices();
shmobile_setup_console();
}
static void __init gpio_pull_up(u32 addr)
{
u8 data = __raw_readb(addr);
data &= 0x0F;
data |= 0xC0;
__raw_writeb(data, addr);
}
static void __init g4evm_init(void)
{
sh7377_pinmux_init();
gpio_request(GPIO_PORT109, NULL);
gpio_direction_output(GPIO_PORT109, 1);
gpio_export(GPIO_PORT109, 1);
gpio_request(GPIO_PORT110, NULL);
gpio_direction_output(GPIO_PORT110, 1);
gpio_export(GPIO_PORT110, 1);
gpio_request(GPIO_PORT112, NULL);
gpio_direction_output(GPIO_PORT112, 1);
gpio_export(GPIO_PORT112, 1);
gpio_request(GPIO_PORT113, NULL);
gpio_direction_output(GPIO_PORT113, 1);
gpio_export(GPIO_PORT113, 1);
gpio_request(GPIO_FN_VBUS_0, NULL);
gpio_request(GPIO_FN_PWEN, NULL);
gpio_request(GPIO_FN_OVCN, NULL);
gpio_request(GPIO_FN_OVCN2, NULL);
gpio_request(GPIO_FN_EXTLP, NULL);
gpio_request(GPIO_FN_IDIN, NULL);
__raw_writew(0x0200, 0xe605810a);
__raw_writew(0x00e0, 0xe60581c0);
__raw_writew(0x6010, 0xe60581c6);
__raw_writew(0x8a0a, 0xe605810c);
gpio_request(GPIO_FN_PORT60_KEYOUT5, NULL);
gpio_request(GPIO_FN_PORT61_KEYOUT4, NULL);
gpio_request(GPIO_FN_PORT62_KEYOUT3, NULL);
gpio_request(GPIO_FN_PORT63_KEYOUT2, NULL);
gpio_request(GPIO_FN_PORT64_KEYOUT1, NULL);
gpio_request(GPIO_FN_PORT65_KEYOUT0, NULL);
gpio_request(GPIO_FN_PORT66_KEYIN0_PU, NULL);
gpio_request(GPIO_FN_PORT67_KEYIN1_PU, NULL);
gpio_request(GPIO_FN_PORT68_KEYIN2_PU, NULL);
gpio_request(GPIO_FN_PORT69_KEYIN3_PU, NULL);
gpio_request(GPIO_FN_PORT70_KEYIN4_PU, NULL);
gpio_request(GPIO_FN_PORT71_KEYIN5_PU, NULL);
gpio_request(GPIO_FN_PORT72_KEYIN6_PU, NULL);
gpio_request(GPIO_FN_SDHICLK0, NULL);
gpio_request(GPIO_FN_SDHICD0, NULL);
gpio_request(GPIO_FN_SDHID0_0, NULL);
gpio_request(GPIO_FN_SDHID0_1, NULL);
gpio_request(GPIO_FN_SDHID0_2, NULL);
gpio_request(GPIO_FN_SDHID0_3, NULL);
gpio_request(GPIO_FN_SDHICMD0, NULL);
gpio_request(GPIO_FN_SDHIWP0, NULL);
gpio_pull_up(GPIO_SDHID0_D0);
gpio_pull_up(GPIO_SDHID0_D1);
gpio_pull_up(GPIO_SDHID0_D2);
gpio_pull_up(GPIO_SDHID0_D3);
gpio_pull_up(GPIO_SDHICMD0);
gpio_request(GPIO_FN_SDHICLK1, NULL);
gpio_request(GPIO_FN_SDHID1_0, NULL);
gpio_request(GPIO_FN_SDHID1_1, NULL);
gpio_request(GPIO_FN_SDHID1_2, NULL);
gpio_request(GPIO_FN_SDHID1_3, NULL);
gpio_request(GPIO_FN_SDHICMD1, NULL);
gpio_pull_up(GPIO_SDHID1_D0);
gpio_pull_up(GPIO_SDHID1_D1);
gpio_pull_up(GPIO_SDHID1_D2);
gpio_pull_up(GPIO_SDHID1_D3);
gpio_pull_up(GPIO_SDHICMD1);
sh7377_add_standard_devices();
platform_add_devices(g4evm_devices, ARRAY_SIZE(g4evm_devices));
}
static void __init g4evm_timer_init(void)
{
sh7377_clock_init();
shmobile_timer.init();
}
