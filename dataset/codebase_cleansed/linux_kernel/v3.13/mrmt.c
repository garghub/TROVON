static int ads7846_pendown_state(void)
{
return !gpio_get_value( PIN_TS_EXTINT );
}
static void mrmt_power_off(void)
{
gpio_set_value( PIN_PWR_ON, 0 );
}
static int __init mrmt1_init(void)
{
gpio_set_value( PIN_PWR_ON, 1 );
pm_power_off = mrmt_power_off;
at32_map_usart(2, 1, 0);
at32_map_usart(3, 2, ATMEL_USART_RTS | ATMEL_USART_CTS);
at32_add_device_usart(1);
at32_add_device_usart(2);
at32_select_gpio( PIN_PWR_SW_N, AT32_GPIOF_DEGLITCH);
at32_select_gpio( PIN_PB_LEFT, AT32_GPIOF_DEGLITCH);
at32_select_gpio( PIN_PB_RIGHT, AT32_GPIOF_DEGLITCH);
platform_device_register(&rmt_gpio_keys);
#ifdef CONFIG_BOARD_MRMT_RTC_I2C
i2c_register_board_info(0, &mrmt1_i2c_rtc, 1);
#endif
#ifndef CONFIG_BOARD_MRMT_LCD_DISABLE
at32_add_device_lcdc(0, &rmt_lcdc_data,
fbmem_start, fbmem_size,
(ATMEL_LCDC_ALT_24BIT | ATMEL_LCDC_PE_DVAL ) );
#endif
#ifdef CONFIG_BOARD_MRMT_AC97
at32_add_device_ac97c(0, &ac97c0_data, AC97C_BOTH);
#endif
#ifdef CONFIG_BOARD_MRMT_ADS7846_TS
at32_select_periph( GPIO_PIOB_BASE, 1 << (PB_EXTINT_BASE+TS_IRQ),
GPIO_PERIPH_A, AT32_GPIOF_DEGLITCH);
irq_set_irq_type(AT32_EXTINT(TS_IRQ), IRQ_TYPE_EDGE_FALLING);
at32_spi_setup_slaves(0,spi01_board_info,ARRAY_SIZE(spi01_board_info));
spi_register_board_info(spi01_board_info,ARRAY_SIZE(spi01_board_info));
#endif
#ifdef CONFIG_BOARD_MRMT_UCB1400_TS
at32_select_periph( GPIO_PIOB_BASE, 1 << (PB_EXTINT_BASE+TS_IRQ),
GPIO_PERIPH_A, AT32_GPIOF_DEGLITCH);
platform_device_register(&rmt_ts_device);
#endif
at32_select_gpio( PIN_LCD_DISP, AT32_GPIOF_OUTPUT );
gpio_request( PIN_LCD_DISP, "LCD_DISP" );
gpio_direction_output( PIN_LCD_DISP, 0 );
#ifdef CONFIG_BOARD_MRMT_LCD_DISABLE
at32_select_gpio( PIN_LCD_BL, AT32_GPIOF_OUTPUT );
gpio_request( PIN_LCD_BL, "LCD_BL" );
gpio_direction_output( PIN_LCD_BL, 0 );
#else
gpio_set_value( PIN_LCD_DISP, 1 );
#ifdef CONFIG_BOARD_MRMT_BL_PWM
at32_add_device_pwm(1 << PWM_CH_BL);
platform_device_register(&rmt_pwm_led_dev);
#else
udelay( 1 );
at32_select_gpio( PIN_LCD_BL, AT32_GPIOF_OUTPUT );
gpio_request( PIN_LCD_BL, "LCD_BL" );
gpio_direction_output( PIN_LCD_BL, 1 );
#endif
#endif
at32_select_gpio( PIN_BT_RST, AT32_GPIOF_OUTPUT );
gpio_request( PIN_BT_RST, "BT_RST" );
gpio_direction_output( PIN_BT_RST, 1 );
at32_select_gpio( PIN_ZB_RST_N, AT32_GPIOF_OUTPUT );
gpio_request( PIN_ZB_RST_N, "ZB_RST_N" );
gpio_direction_output( PIN_ZB_RST_N, 0 );
#ifdef CONFIG_BOARD_MRMT_WIRELESS_ZB
udelay( 1000 );
gpio_set_value( PIN_ZB_RST_N, 1 );
#endif
#ifdef CONFIG_BOARD_MRMT_WIRELESS_BT
udelay( 1000 );
gpio_set_value( PIN_BT_RST, 0 );
#endif
return 0;
}
static int __init mrmt1_early_init(void)
{
at32_select_gpio( PIN_PWR_ON, AT32_GPIOF_OUTPUT );
gpio_request( PIN_PWR_ON, "PIN_PWR_ON" );
gpio_direction_output( PIN_PWR_ON, 1 );
return 0;
}
