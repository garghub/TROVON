static void __init smartq7_machine_init(void)
{
s3c_fb_set_platdata(&smartq7_lcd_pdata);
smartq_machine_init();
platform_add_devices(smartq7_devices, ARRAY_SIZE(smartq7_devices));
}
