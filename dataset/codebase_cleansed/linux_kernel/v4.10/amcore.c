static void __init dm9000_pre_init(void)
{
mcf_autovector(DM9000_IRQ);
}
static int __init init_amcore(void)
{
#if IS_ENABLED(CONFIG_DM9000)
dm9000_pre_init();
#endif
i2c_register_board_info(0, amcore_i2c_info,
ARRAY_SIZE(amcore_i2c_info));
platform_add_devices(amcore_devices, ARRAY_SIZE(amcore_devices));
return 0;
}
