static void __init gesbc9312_init_machine(void)
{
ep93xx_init_devices();
ep93xx_register_flash(4, EP93XX_CS6_PHYS_BASE, SZ_8M);
ep93xx_register_eth(&gesbc9312_eth_data, 0);
}
