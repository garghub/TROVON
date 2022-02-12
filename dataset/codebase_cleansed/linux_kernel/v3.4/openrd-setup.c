static int __init sd_uart_selection(char *str)
{
uart1 = -EINVAL;
if (!str)
return 0;
if (!strncmp(str, "232", 3)) {
uart1 = 232;
} else if (!strncmp(str, "485", 3)) {
if (machine_is_openrd_base()) {
uart1 = -ENODEV;
return 1;
}
uart1 = 485;
}
return 1;
}
static int __init uart1_mpp_config(void)
{
kirkwood_mpp_conf(openrd_uart1_mpp_config);
if (gpio_request(34, "SD_UART1_SEL")) {
printk(KERN_ERR "GPIO request failed for SD/UART1 selection"
", gpio: 34\n");
return -EIO;
}
if (gpio_request(28, "RS232_RS485_SEL")) {
printk(KERN_ERR "GPIO request failed for RS232/RS485 selection"
", gpio# 28\n");
gpio_free(34);
return -EIO;
}
gpio_direction_output(34, 0);
if (uart1 == 232)
gpio_direction_output(28, 0);
else
gpio_direction_output(28, 1);
gpio_free(34);
gpio_free(28);
return 0;
}
static void __init openrd_init(void)
{
kirkwood_init();
kirkwood_mpp_conf(openrd_mpp_config);
kirkwood_uart0_init();
kirkwood_nand_init(ARRAY_AND_SIZE(openrd_nand_parts), 25);
kirkwood_ehci_init();
if (machine_is_openrd_ultimate()) {
openrd_ge00_data.phy_addr = MV643XX_ETH_PHY_ADDR(0);
openrd_ge01_data.phy_addr = MV643XX_ETH_PHY_ADDR(1);
}
kirkwood_ge00_init(&openrd_ge00_data);
if (!machine_is_openrd_base())
kirkwood_ge01_init(&openrd_ge01_data);
kirkwood_sata_init(&openrd_sata_data);
kirkwood_i2c_init();
if (machine_is_openrd_client() || machine_is_openrd_ultimate()) {
platform_device_register(&openrd_client_audio_device);
i2c_register_board_info(0, i2c_board_info,
ARRAY_SIZE(i2c_board_info));
kirkwood_audio_init();
}
if (uart1 <= 0) {
if (uart1 < 0)
printk(KERN_ERR "Invalid kernel parameter to select "
"UART1. Defaulting to SD. ERROR CODE: %d\n",
uart1);
if (gpio_request(34, "SD_UART1_SEL")) {
printk(KERN_ERR "GPIO request failed for SD/UART1 "
"selection, gpio: 34\n");
} else {
gpio_direction_output(34, 1);
gpio_free(34);
kirkwood_sdio_init(&openrd_mvsdio_data);
}
} else {
if (!uart1_mpp_config())
kirkwood_uart1_init();
}
}
static int __init openrd_pci_init(void)
{
if (machine_is_openrd_base() ||
machine_is_openrd_client() ||
machine_is_openrd_ultimate())
kirkwood_pcie_init(KW_PCIE0);
return 0;
}
