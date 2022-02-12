static void hp_t5325_power_off(void)
{
gpio_set_value(HP_T5325_GPIO_POWER_OFF, 1);
}
static void __init hp_t5325_init(void)
{
kirkwood_init();
kirkwood_mpp_conf(hp_t5325_mpp_config);
kirkwood_uart0_init();
spi_register_board_info(hp_t5325_spi_slave_info,
ARRAY_SIZE(hp_t5325_spi_slave_info));
kirkwood_spi_init();
kirkwood_i2c_init();
kirkwood_ge00_init(&hp_t5325_ge00_data);
kirkwood_sata_init(&hp_t5325_sata_data);
kirkwood_ehci_init();
platform_device_register(&hp_t5325_button_device);
i2c_register_board_info(0, i2c_board_info, ARRAY_SIZE(i2c_board_info));
kirkwood_audio_init();
if (gpio_request(HP_T5325_GPIO_POWER_OFF, "power-off") == 0 &&
gpio_direction_output(HP_T5325_GPIO_POWER_OFF, 0) == 0)
pm_power_off = hp_t5325_power_off;
else
pr_err("t5325: failed to configure power-off GPIO\n");
}
static int __init hp_t5325_pci_init(void)
{
if (machine_is_t5325())
kirkwood_pcie_init(KW_PCIE0);
return 0;
}
