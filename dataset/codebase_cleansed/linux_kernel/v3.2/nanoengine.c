static void __init nanoengine_map_io(void)
{
sa1100_map_io();
iotable_init(nanoengine_io_desc, ARRAY_SIZE(nanoengine_io_desc));
sa1100_register_uart(0, 1);
sa1100_register_uart(1, 2);
sa1100_register_uart(2, 3);
Ser1SDCR0 |= SDCR0_UART;
Ser2UTCR4 = 0;
Ser2HSCR0 = 0;
}
static void __init nanoengine_init(void)
{
sa11x0_register_mtd(&nanoengine_flash_data, nanoengine_flash_resources,
ARRAY_SIZE(nanoengine_flash_resources));
}
