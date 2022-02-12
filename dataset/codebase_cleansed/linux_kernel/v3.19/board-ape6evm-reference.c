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
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
