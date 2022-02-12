static void __init smartq5_machine_init(void)
{
s3c_fb_set_platdata(&smartq5_lcd_pdata);
smartq_machine_init();
platform_add_devices(smartq5_devices, ARRAY_SIZE(smartq5_devices));
}
