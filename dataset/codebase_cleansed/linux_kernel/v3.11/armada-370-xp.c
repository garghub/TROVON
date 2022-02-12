static void __init armada_370_xp_map_io(void)
{
debug_ll_io_init();
}
static void __init armada_370_xp_mbus_init(void)
{
char *mbus_soc_name;
struct device_node *dn;
const __be32 mbus_wins_offs = cpu_to_be32(ARMADA_370_XP_MBUS_WINS_OFFS);
const __be32 sdram_wins_offs = cpu_to_be32(ARMADA_370_XP_SDRAM_WINS_OFFS);
if (of_machine_is_compatible("marvell,armada370"))
mbus_soc_name = "marvell,armada370-mbus";
else
mbus_soc_name = "marvell,armadaxp-mbus";
dn = of_find_node_by_name(NULL, "internal-regs");
BUG_ON(!dn);
mvebu_mbus_init(mbus_soc_name,
of_translate_address(dn, &mbus_wins_offs),
ARMADA_370_XP_MBUS_WINS_SIZE,
of_translate_address(dn, &sdram_wins_offs),
ARMADA_370_XP_SDRAM_WINS_SIZE);
}
static void __init armada_370_xp_timer_and_clk_init(void)
{
of_clk_init(NULL);
armada_370_xp_timer_init();
coherency_init();
armada_370_xp_mbus_init();
#ifdef CONFIG_CACHE_L2X0
l2x0_of_init(0, ~0UL);
#endif
}
static void __init armada_370_xp_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
