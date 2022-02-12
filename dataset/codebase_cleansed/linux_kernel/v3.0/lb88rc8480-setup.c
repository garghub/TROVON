static void __init lb88rc8480_init(void)
{
loki_init();
loki_ge0_init(&lb88rc8480_ge0_data);
loki_sas_init();
loki_uart0_init();
loki_uart1_init();
loki_setup_dev_boot_win(LB88RC8480_FLASH_BOOT_CS_BASE,
LB88RC8480_FLASH_BOOT_CS_SIZE);
platform_device_register(&lb88rc8480_boot_flash);
}
