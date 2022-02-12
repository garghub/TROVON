static void __init msm7x30_init_irq(void)
{
msm_init_irq();
}
static void __init msm7x30_init(void)
{
msm_device_otg.dev.platform_data = &msm_otg_pdata;
msm_device_hsusb.dev.parent = &msm_device_otg.dev;
msm_device_hsusb_host.dev.parent = &msm_device_otg.dev;
platform_add_devices(devices, ARRAY_SIZE(devices));
}
static void __init msm7x30_map_io(void)
{
msm_map_msm7x30_io();
msm_clock_init(msm_clocks_7x30, msm_num_clocks_7x30);
}
