static void __init simone_init_machine(void)
{
ep93xx_init_devices();
ep93xx_register_flash(2, EP93XX_CS6_PHYS_BASE, SZ_8M);
ep93xx_register_eth(&simone_eth_data, 1);
ep93xx_register_fb(&simone_fb_info);
ep93xx_register_i2c(&simone_i2c_gpio_data, simone_i2c_board_info,
ARRAY_SIZE(simone_i2c_board_info));
ep93xx_register_ac97();
}
