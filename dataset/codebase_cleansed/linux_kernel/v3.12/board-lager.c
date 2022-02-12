static void __init lager_add_standard_devices(void)
{
r8a7790_clock_init();
pinctrl_register_mappings(lager_pinctrl_map,
ARRAY_SIZE(lager_pinctrl_map));
r8a7790_pinmux_init();
r8a7790_add_standard_devices();
platform_device_register_data(&platform_bus, "leds-gpio", -1,
&lager_leds_pdata,
sizeof(lager_leds_pdata));
platform_device_register_data(&platform_bus, "gpio-keys", -1,
&lager_keys_pdata,
sizeof(lager_keys_pdata));
regulator_register_always_on(0, "fixed-3.3V", fixed3v3_power_consumers,
ARRAY_SIZE(fixed3v3_power_consumers), 3300000);
platform_device_register_resndata(&platform_bus, "sh_mmcif", 1,
mmcif1_resources, ARRAY_SIZE(mmcif1_resources),
&mmcif1_pdata, sizeof(mmcif1_pdata));
platform_device_register_resndata(&platform_bus, "r8a7790-ether", -1,
ether_resources,
ARRAY_SIZE(ether_resources),
&ether_pdata, sizeof(ether_pdata));
}
static int lager_ksz8041_fixup(struct phy_device *phydev)
{
u16 phyctrl1 = phy_read(phydev, 0x1e);
phyctrl1 &= ~0xc000;
phyctrl1 |= 0x4000;
return phy_write(phydev, 0x1e, phyctrl1);
}
static void __init lager_init(void)
{
lager_add_standard_devices();
phy_register_fixup_for_id("r8a7790-ether-ff:01", lager_ksz8041_fixup);
}
