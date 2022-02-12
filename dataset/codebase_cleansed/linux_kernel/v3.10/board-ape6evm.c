static void __init ape6evm_add_standard_devices(void)
{
r8a73a4_clock_init();
pinctrl_register_mappings(ape6evm_pinctrl_map,
ARRAY_SIZE(ape6evm_pinctrl_map));
r8a73a4_pinmux_init();
r8a73a4_add_standard_devices();
gpio_request_one(270, GPIOF_OUT_INIT_HIGH, NULL);
regulator_register_fixed(0, dummy_supplies, ARRAY_SIZE(dummy_supplies));
platform_device_register_resndata(&platform_bus, "smsc911x", -1,
lan9220_res, ARRAY_SIZE(lan9220_res),
&lan9220_data, sizeof(lan9220_data));
}
