static void littleton_init_lcd(void)
{
pxa_set_fb_info(NULL, &littleton_lcd_info);
}
static inline void littleton_init_lcd(void) {}
static void __init littleton_init_spi(void)
{
pxa2xx_set_spi_info(2, &littleton_spi_info);
spi_register_board_info(ARRAY_AND_SIZE(littleton_spi_devices));
}
static inline void littleton_init_spi(void) {}
static void __init littleton_init_keypad(void)
{
pxa_set_keypad_info(&littleton_keypad_info);
}
static inline void littleton_init_keypad(void) {}
static void __init littleton_init_mmc(void)
{
pxa_set_mci_info(&littleton_mci_platform_data);
}
static inline void littleton_init_mmc(void) {}
static void __init littleton_init_nand(void)
{
pxa3xx_set_nand_info(&littleton_nand_info);
}
static inline void littleton_init_nand(void) {}
static void __init littleton_init_i2c(void)
{
pxa_set_i2c_info(NULL);
i2c_register_board_info(0, ARRAY_AND_SIZE(littleton_i2c_info));
}
static inline void littleton_init_i2c(void) {}
static void __init littleton_init(void)
{
pxa3xx_mfp_config(ARRAY_AND_SIZE(littleton_mfp_cfg));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
platform_device_register(&smc91x_device);
littleton_init_spi();
littleton_init_i2c();
littleton_init_mmc();
littleton_init_lcd();
littleton_init_keypad();
littleton_init_nand();
}
