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
shmobile_clk_workaround(clk_names, ARRAY_SIZE(clk_names), false);
r8a7791_add_dt_devices();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
koelsch_add_du_device();
}
