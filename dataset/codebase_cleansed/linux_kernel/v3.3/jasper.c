static void __init jasper_init(void)
{
mfp_config(ARRAY_AND_SIZE(jasper_pin_config));
mmp2_add_uart(1);
mmp2_add_uart(3);
mmp2_add_twsi(1, NULL, ARRAY_AND_SIZE(jasper_twsi1_info));
mmp2_add_sdhost(0, &mmp2_sdh_platdata_mmc0);
regulator_has_full_constraints();
}
