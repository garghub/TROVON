void __init netxbig_init(void)
{
if (of_machine_is_compatible("lacie,net5big_v2"))
netxbig_v2_leds.dev.platform_data = &net5big_v2_leds_data;
platform_device_register(&netxbig_v2_leds);
}
