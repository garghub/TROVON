void __init lacie_v2_register_flash(void)
{
spi_register_board_info(lacie_v2_spi_slave_info,
ARRAY_SIZE(lacie_v2_spi_slave_info));
kirkwood_spi_init();
}
void __init lacie_v2_register_i2c_devices(void)
{
kirkwood_i2c_init();
i2c_register_board_info(0, lacie_v2_i2c_info,
ARRAY_SIZE(lacie_v2_i2c_info));
}
void __init lacie_v2_hdd_power_init(int hdd_num)
{
int i;
int err;
for (i = 0; i < hdd_num; i++) {
err = gpio_request(lacie_v2_gpio_hdd_power[i], NULL);
if (err == 0) {
err = gpio_direction_output(
lacie_v2_gpio_hdd_power[i], 1);
gpio_free(lacie_v2_gpio_hdd_power[i]);
}
if (err)
pr_err("Failed to power up HDD%d\n", i + 1);
}
}
