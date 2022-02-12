static void __init ttc_dkb_init(void)
{
mfp_config(ARRAY_AND_SIZE(ttc_dkb_pin_config));
pxa910_add_uart(1);
platform_add_devices(ARRAY_AND_SIZE(ttc_dkb_devices));
}
