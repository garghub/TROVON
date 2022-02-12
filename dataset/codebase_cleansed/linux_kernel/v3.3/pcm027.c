static void __init pcm027_init(void)
{
ARB_CNTRL = ARB_CORE_PARK | 0x234;
pxa2xx_mfp_config(pcm027_pin_config, ARRAY_SIZE(pcm027_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
platform_add_devices(devices, ARRAY_SIZE(devices));
#ifdef CONFIG_MACH_PCM990_BASEBOARD
pcm990_baseboard_init();
#endif
pxa2xx_set_spi_info(1, &pxa_ssp_master_info);
spi_register_board_info(spi_board_info, ARRAY_SIZE(spi_board_info));
}
static void __init pcm027_map_io(void)
{
pxa27x_map_io();
PGSR0 = 0x01308000;
PGSR1 = 0x00CF0002;
PGSR2 = 0x0E294000;
PGSR3 = 0x0000C000;
PWER = 0x40000000 | PWER_GPIO0 | PWER_GPIO1;
PRER = 0x00000000;
PFER = 0x00000003;
}
