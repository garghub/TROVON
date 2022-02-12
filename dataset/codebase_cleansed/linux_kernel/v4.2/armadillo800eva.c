static void __init armadillo800eva_init(void)
{
board_staging_gic_setup_xlate("arm,cortex-a9-gic", 32);
board_staging_register_devices(armadillo800eva_devices,
ARRAY_SIZE(armadillo800eva_devices));
}
