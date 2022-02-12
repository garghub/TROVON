static void __init koelsch_add_du_device(void)
{
struct platform_device_info info = {
.name = "rcar-du-r8a7791",
.id = -1,
.res = du_resources,
.num_res = ARRAY_SIZE(du_resources),
.data = &koelsch_du_pdata,
.size_data = sizeof(koelsch_du_pdata),
.dma_mask = DMA_BIT_MASK(32),
};
platform_device_register_full(&info);
}
static void __init koelsch_add_standard_devices(void)
{
r8a7791_clock_init();
pinctrl_register_mappings(koelsch_pinctrl_map,
ARRAY_SIZE(koelsch_pinctrl_map));
r8a7791_pinmux_init();
r8a7791_add_standard_devices();
platform_device_register_resndata(&platform_bus, "r8a7791-ether", -1,
ether_resources,
ARRAY_SIZE(ether_resources),
&ether_pdata, sizeof(ether_pdata));
platform_device_register_data(&platform_bus, "leds-gpio", -1,
&koelsch_leds_pdata,
sizeof(koelsch_leds_pdata));
platform_device_register_data(&platform_bus, "gpio-keys", -1,
&koelsch_keys_pdata,
sizeof(koelsch_keys_pdata));
koelsch_add_du_device();
}
static int koelsch_ksz8041_fixup(struct phy_device *phydev)
{
u16 phyctrl1 = phy_read(phydev, 0x1e);
phyctrl1 &= ~0xc000;
phyctrl1 |= 0x4000;
return phy_write(phydev, 0x1e, phyctrl1);
}
static void __init koelsch_init(void)
{
koelsch_add_standard_devices();
if (IS_ENABLED(CONFIG_PHYLIB))
phy_register_fixup_for_id("r8a7791-ether-ff:01",
koelsch_ksz8041_fixup);
}
