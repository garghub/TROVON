static void __init armada_370_xp_map_io(void)
{
debug_ll_io_init();
}
static void __init armada_370_xp_timer_and_clk_init(void)
{
of_clk_init(NULL);
clocksource_of_init();
coherency_init();
BUG_ON(mvebu_mbus_dt_init());
#ifdef CONFIG_CACHE_L2X0
l2x0_of_init(0, ~0UL);
#endif
}
static void __init i2c_quirk(void)
{
struct device_node *np;
u32 dev, rev;
if (mvebu_get_soc_id(&rev, &dev) == 0 && dev > MV78XX0_A0_REV)
return;
for_each_compatible_node(np, NULL, "marvell,mv78230-i2c") {
struct property *new_compat;
new_compat = kzalloc(sizeof(*new_compat), GFP_KERNEL);
new_compat->name = kstrdup("compatible", GFP_KERNEL);
new_compat->length = sizeof("marvell,mv78230-a0-i2c");
new_compat->value = kstrdup("marvell,mv78230-a0-i2c",
GFP_KERNEL);
of_update_property(np, new_compat);
}
return;
}
static void __init armada_370_xp_dt_init(void)
{
if (of_machine_is_compatible("plathome,openblocks-ax3-4"))
i2c_quirk();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
