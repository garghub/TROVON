static void __init evb3_init_i2c(void)
{
pxa_set_i2c_info(NULL);
i2c_register_board_info(0, ARRAY_AND_SIZE(evb3_i2c_info));
}
static inline void evb3_init_i2c(void) {}
static void __init evb3_init(void)
{
pxa3xx_mfp_config(ARRAY_AND_SIZE(evb3_mfp_cfg));
pxa_set_ffuart_info(NULL);
evb3_init_i2c();
}
