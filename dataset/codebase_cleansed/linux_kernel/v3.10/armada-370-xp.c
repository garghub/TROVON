void __init armada_370_xp_map_io(void)
{
iotable_init(armada_370_xp_io_desc, ARRAY_SIZE(armada_370_xp_io_desc));
}
void __init armada_370_xp_timer_and_clk_init(void)
{
mvebu_clocks_init();
armada_370_xp_timer_init();
}
void __init armada_370_xp_init_early(void)
{
char *mbus_soc_name;
if (of_machine_is_compatible("marvell,armada370"))
mbus_soc_name = "marvell,armada370-mbus";
else
mbus_soc_name = "marvell,armadaxp-mbus";
mvebu_mbus_init(mbus_soc_name,
ARMADA_370_XP_MBUS_WINS_BASE,
ARMADA_370_XP_MBUS_WINS_SIZE,
ARMADA_370_XP_SDRAM_WINS_BASE,
ARMADA_370_XP_SDRAM_WINS_SIZE);
#ifdef CONFIG_CACHE_L2X0
l2x0_of_init(0, ~0UL);
#endif
}
static void __init armada_370_xp_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
coherency_init();
}
