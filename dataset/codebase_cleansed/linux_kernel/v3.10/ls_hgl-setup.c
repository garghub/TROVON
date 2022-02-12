static void ls_hgl_power_off(void)
{
orion5x_restart('h', NULL);
}
static void __init ls_hgl_init(void)
{
orion5x_init();
orion5x_mpp_conf(ls_hgl_mpp_modes);
orion5x_ehci0_init();
orion5x_ehci1_init();
orion5x_eth_init(&ls_hgl_eth_data);
orion5x_i2c_init();
orion5x_sata_init(&ls_hgl_sata_data);
orion5x_uart0_init();
orion5x_xor_init();
mvebu_mbus_add_window("devbus-boot", LS_HGL_NOR_BOOT_BASE,
LS_HGL_NOR_BOOT_SIZE);
platform_device_register(&ls_hgl_nor_flash);
platform_device_register(&ls_hgl_button_device);
platform_device_register(&ls_hgl_leds);
i2c_register_board_info(0, &ls_hgl_i2c_rtc, 1);
gpio_set_value(LS_HGL_GPIO_USB_POWER, 1);
pm_power_off = ls_hgl_power_off;
pr_info("%s: finished\n", __func__);
}
