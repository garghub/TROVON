static void __init adssphere_init_machine(void)
{
ep93xx_init_devices();
ep93xx_register_flash(4, EP93XX_CS6_PHYS_BASE, SZ_32M);
ep93xx_register_eth(&adssphere_eth_data, 1);
}
