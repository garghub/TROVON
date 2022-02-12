static void __init ape6evm_add_standard_devices(void)
{
struct clk *parent;
struct clk *mp;
r8a73a4_clock_init();
parent = clk_get(NULL, "extal2");
mp = clk_get(NULL, "mp");
BUG_ON(IS_ERR(parent) || IS_ERR(mp));
clk_set_parent(mp, parent);
clk_put(parent);
clk_put(mp);
pinctrl_register_mappings(ape6evm_pinctrl_map,
ARRAY_SIZE(ape6evm_pinctrl_map));
r8a73a4_pinmux_init();
r8a73a4_add_standard_devices();
gpio_request_one(270, GPIOF_OUT_INIT_HIGH, NULL);
regulator_register_fixed(0, dummy_supplies, ARRAY_SIZE(dummy_supplies));
platform_device_register_resndata(&platform_bus, "smsc911x", -1,
lan9220_res, ARRAY_SIZE(lan9220_res),
&lan9220_data, sizeof(lan9220_data));
regulator_register_always_on(1, "MMC0 Vcc", vcc_mmc0_consumers,
ARRAY_SIZE(vcc_mmc0_consumers), 2800000);
platform_device_register_resndata(&platform_bus, "sh_mmcif", 0,
mmcif0_resources, ARRAY_SIZE(mmcif0_resources),
&mmcif0_pdata, sizeof(mmcif0_pdata));
platform_device_register_data(&platform_bus, "reg-fixed-voltage", 2,
&vcc_sdhi0_info, sizeof(vcc_sdhi0_info));
platform_device_register_resndata(&platform_bus, "sh_mobile_sdhi", 0,
sdhi0_resources, ARRAY_SIZE(sdhi0_resources),
&sdhi0_pdata, sizeof(sdhi0_pdata));
regulator_register_always_on(3, "SDHI1 Vcc", vcc_sdhi1_consumers,
ARRAY_SIZE(vcc_sdhi1_consumers), 3300000);
platform_device_register_resndata(&platform_bus, "sh_mobile_sdhi", 1,
sdhi1_resources, ARRAY_SIZE(sdhi1_resources),
&sdhi1_pdata, sizeof(sdhi1_pdata));
platform_device_register_data(&platform_bus, "gpio-keys", -1,
&ape6evm_keys_pdata,
sizeof(ape6evm_keys_pdata));
platform_device_register_data(&platform_bus, "leds-gpio", -1,
&ape6evm_leds_pdata,
sizeof(ape6evm_leds_pdata));
}
