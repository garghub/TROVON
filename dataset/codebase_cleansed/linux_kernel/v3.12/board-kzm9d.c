void __init kzm9d_add_standard_devices(void)
{
regulator_register_fixed(0, dummy_supplies, ARRAY_SIZE(dummy_supplies));
emev2_add_standard_devices();
platform_add_devices(kzm9d_devices, ARRAY_SIZE(kzm9d_devices));
}
