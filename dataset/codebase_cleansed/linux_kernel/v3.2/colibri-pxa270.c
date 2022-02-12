static void __init colibri_pxa270_nor_init(void)
{
platform_device_register(&colibri_pxa270_flash_device);
}
static inline void colibri_pxa270_nor_init(void) {}
static void __init colibri_pxa270_eth_init(void)
{
platform_device_register(&colibri_pxa270_dm9000_device);
}
static inline void colibri_pxa270_eth_init(void) {}
static void __init colibri_pxa270_tsc_init(void)
{
pxa_set_ac97_info(&colibri_pxa270_ac97_pdata);
platform_device_register(&colibri_pxa270_ucb1400_device);
}
static inline void colibri_pxa270_tsc_init(void) {}
static void __init colibri_pxa270_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(colibri_pxa270_pin_config));
colibri_pxa270_nor_init();
colibri_pxa270_eth_init();
colibri_pxa270_tsc_init();
switch (colibri_pxa270_baseboard) {
case COLIBRI_EVALBOARD:
pxa2xx_mfp_config(ARRAY_AND_SIZE(
colibri_pxa270_evalboard_pin_config));
colibri_evalboard_init();
break;
case COLIBRI_PXA270_INCOME:
pxa2xx_mfp_config(ARRAY_AND_SIZE(income_pin_config));
colibri_pxa270_income_boardinit();
break;
default:
printk(KERN_ERR "Illegal colibri_pxa270_baseboard type %d\n",
colibri_pxa270_baseboard);
}
}
static void __init colibri_pxa270_income_init(void)
{
colibri_pxa270_baseboard = COLIBRI_PXA270_INCOME;
colibri_pxa270_init();
}
