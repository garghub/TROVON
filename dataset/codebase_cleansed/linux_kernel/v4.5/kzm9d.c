static void __init kzm9d_init(void)
{
board_staging_gic_setup_xlate("arm,pl390", 32);
if (!board_staging_dt_node_available(usbs1_res,
ARRAY_SIZE(usbs1_res))) {
board_staging_gic_fixup_resources(usbs1_res,
ARRAY_SIZE(usbs1_res));
platform_device_register_simple("emxx_udc", -1, usbs1_res,
ARRAY_SIZE(usbs1_res));
}
}
