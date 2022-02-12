static void __init ttc_dkb_init(void)
{
mfp_config(ARRAY_AND_SIZE(ttc_dkb_pin_config));
pxa910_add_uart(1);
pxa910_add_twsi(0, NULL, ARRAY_AND_SIZE(ttc_dkb_i2c_info));
platform_add_devices(ARRAY_AND_SIZE(ttc_dkb_devices));
}
