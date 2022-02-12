static void __init brownstone_init(void)
{
mfp_config(ARRAY_AND_SIZE(brownstone_pin_config));
mmp2_add_uart(1);
mmp2_add_uart(3);
mmp2_add_twsi(1, NULL, ARRAY_AND_SIZE(brownstone_twsi1_info));
mmp2_add_sdhost(0, &mmp2_sdh_platdata_mmc0);
mmp2_add_sdhost(2, &mmp2_sdh_platdata_mmc2);
mmp2_add_asram(&mmp2_asram_platdata);
mmp2_add_isram(&mmp2_isram_platdata);
platform_device_register(&brownstone_v_5vp_device);
}
