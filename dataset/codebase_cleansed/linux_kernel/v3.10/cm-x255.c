static void __init cmx255_init_rtc(void)
{
pxa2xx_set_spi_info(1, &pxa_ssp_master_info);
spi_register_board_info(ARRAY_AND_SIZE(spi_board_info));
}
static inline void cmx255_init_rtc(void) {}
static void __init cmx255_init_nor(void)
{
platform_device_register(&cmx255_nor);
}
static inline void cmx255_init_nor(void) {}
static void __init cmx255_init_nand(void)
{
platform_device_register(&cmx255_nand);
}
static inline void cmx255_init_nand(void) {}
void __init cmx255_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(cmx255_pin_config));
cmx255_init_rtc();
cmx255_init_nor();
cmx255_init_nand();
}
