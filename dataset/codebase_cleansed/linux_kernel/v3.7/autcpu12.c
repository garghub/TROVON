void __init autcpu12_map_io(void)
{
clps711x_map_io();
iotable_init(autcpu12_io_desc, ARRAY_SIZE(autcpu12_io_desc));
}
static void __init autcpu12_init(void)
{
platform_device_register(&autcpu12_nvram_pdev);
}
