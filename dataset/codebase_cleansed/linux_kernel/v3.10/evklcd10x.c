static void atevklcd10x_lcdc_power_control(int on)
{
gpio_set_value(GPIO_PIN_PB(15), on);
}
static int __init atevklcd10x_init(void)
{
at32_select_gpio(GPIO_PIN_PB(15), AT32_GPIOF_OUTPUT);
gpio_request(GPIO_PIN_PB(15), "backlight");
gpio_direction_output(GPIO_PIN_PB(15), 0);
atevklcd10x_lcdc_data.atmel_lcdfb_power_control =
atevklcd10x_lcdc_power_control;
at32_add_device_lcdc(0, &atevklcd10x_lcdc_data,
fbmem_start, fbmem_size,
#ifdef CONFIG_BOARD_ATNGW100_MKII
ATMEL_LCDC_PRI_18BIT | ATMEL_LCDC_PC_DVAL
#else
ATMEL_LCDC_ALT_18BIT | ATMEL_LCDC_PE_DVAL
#endif
);
at32_add_device_ac97c(0, &ac97c0_data, AC97C_BOTH);
return 0;
}
