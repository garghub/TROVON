static void __init colibri_mmc_init(void)
{
if (machine_is_colibri())
colibri_mci_platform_data.gpio_card_detect =
GPIO0_COLIBRI_PXA270_SD_DETECT;
if (machine_is_colibri300())
colibri_mci_platform_data.gpio_card_detect =
GPIO13_COLIBRI_PXA300_SD_DETECT;
else
colibri_mci_platform_data.gpio_card_detect =
GPIO28_COLIBRI_PXA320_SD_DETECT;
pxa_set_mci_info(&colibri_mci_platform_data);
}
static inline void colibri_mmc_init(void) {}
static int colibri_ohci_init(struct device *dev)
{
UP2OCR = UP2OCR_HXS | UP2OCR_HXOE | UP2OCR_DPPDE | UP2OCR_DMPDE;
return 0;
}
static void __init colibri_uhc_init(void)
{
if (machine_is_colibri())
colibri_ohci_info.flags |= ENABLE_PORT2;
pxa_set_ohci_info(&colibri_ohci_info);
}
static inline void colibri_uhc_init(void) {}
static void __init colibri_rtc_init(void)
{
pxa_set_i2c_info(NULL);
i2c_register_board_info(0, ARRAY_AND_SIZE(colibri_i2c_devs));
}
static inline void colibri_rtc_init(void) {}
void __init colibri_evalboard_init(void)
{
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
colibri_mmc_init();
colibri_uhc_init();
colibri_rtc_init();
}
