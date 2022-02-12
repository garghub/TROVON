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
static void __init koelsch_add_i2c(unsigned idx)
{
unsigned res_idx = idx * 2;
BUG_ON(res_idx >= ARRAY_SIZE(i2c_resources));
platform_device_register_simple("i2c-rcar_gen2", idx,
i2c_resources + res_idx, 2);
}
static void __init koelsch_add_standard_devices(void)
{
r8a7791_clock_init();
pinctrl_register_mappings(koelsch_pinctrl_map,
ARRAY_SIZE(koelsch_pinctrl_map));
r8a7791_pinmux_init();
r8a7791_add_standard_devices();
platform_device_register_full(&ether_info);
platform_device_register_data(&platform_bus, "leds-gpio", -1,
&koelsch_leds_pdata,
sizeof(koelsch_leds_pdata));
platform_device_register_data(&platform_bus, "gpio-keys", -1,
&koelsch_keys_pdata,
sizeof(koelsch_keys_pdata));
platform_device_register_resndata(&platform_bus, "qspi", 0,
qspi_resources,
ARRAY_SIZE(qspi_resources),
&qspi_pdata, sizeof(qspi_pdata));
spi_register_board_info(spi_info, ARRAY_SIZE(spi_info));
koelsch_add_du_device();
platform_device_register_full(&sata0_info);
koelsch_add_i2c(1);
koelsch_add_i2c(2);
koelsch_add_i2c(4);
koelsch_add_i2c(5);
platform_device_register_data(&platform_bus, "reg-fixed-voltage", 0,
&vcc_sdhi0_info, sizeof(struct fixed_voltage_config));
platform_device_register_data(&platform_bus, "reg-fixed-voltage", 1,
&vcc_sdhi1_info, sizeof(struct fixed_voltage_config));
platform_device_register_data(&platform_bus, "reg-fixed-voltage", 2,
&vcc_sdhi2_info, sizeof(struct fixed_voltage_config));
platform_device_register_data(&platform_bus, "gpio-regulator", 0,
&vccq_sdhi0_info, sizeof(struct gpio_regulator_config));
platform_device_register_data(&platform_bus, "gpio-regulator", 1,
&vccq_sdhi1_info, sizeof(struct gpio_regulator_config));
platform_device_register_data(&platform_bus, "gpio-regulator", 2,
&vccq_sdhi2_info, sizeof(struct gpio_regulator_config));
platform_device_register_resndata(&platform_bus, "sh_mobile_sdhi", 0,
sdhi0_resources, ARRAY_SIZE(sdhi0_resources),
&sdhi0_info, sizeof(struct sh_mobile_sdhi_info));
platform_device_register_resndata(&platform_bus, "sh_mobile_sdhi", 1,
sdhi1_resources, ARRAY_SIZE(sdhi1_resources),
&sdhi1_info, sizeof(struct sh_mobile_sdhi_info));
platform_device_register_resndata(&platform_bus, "sh_mobile_sdhi", 2,
sdhi2_resources, ARRAY_SIZE(sdhi2_resources),
&sdhi2_info, sizeof(struct sh_mobile_sdhi_info));
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
irq_set_irq_type(irq_pin(0), IRQ_TYPE_LEVEL_LOW);
if (IS_ENABLED(CONFIG_PHYLIB))
phy_register_fixup_for_id("r8a7791-ether-ff:01",
koelsch_ksz8041_fixup);
}
