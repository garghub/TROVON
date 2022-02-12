static void __init marzen_add_du_device(void)
{
struct platform_device_info info = {
.name = "rcar-du-r8a7779",
.id = -1,
.res = du_resources,
.num_res = ARRAY_SIZE(du_resources),
.data = &du_pdata,
.size_data = sizeof(du_pdata),
.dma_mask = DMA_BIT_MASK(32),
};
platform_device_register_full(&info);
}
static void __init marzen_init(void)
{
regulator_register_always_on(0, "fixed-3.3V", fixed3v3_power_consumers,
ARRAY_SIZE(fixed3v3_power_consumers), 3300000);
regulator_register_fixed(1, dummy_supplies,
ARRAY_SIZE(dummy_supplies));
pinctrl_register_mappings(marzen_pinctrl_map,
ARRAY_SIZE(marzen_pinctrl_map));
r8a7779_pinmux_init();
r8a7779_init_irq_extpin(1);
r8a7779_add_standard_devices();
r8a7779_add_vin_device(1, &vin_platform_data);
r8a7779_add_vin_device(3, &vin_platform_data);
platform_add_devices(marzen_devices, ARRAY_SIZE(marzen_devices));
marzen_add_du_device();
}
