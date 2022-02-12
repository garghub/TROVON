static void tegra30_init_one_clock(struct clk *c)
{
struct clk_tegra *clk = to_clk_tegra(c->hw);
__clk_init(NULL, c);
INIT_LIST_HEAD(&clk->shared_bus_list);
if (!clk->lookup.dev_id && !clk->lookup.con_id)
clk->lookup.con_id = c->name;
clk->lookup.clk = c;
clkdev_add(&clk->lookup);
tegra_clk_add(c);
}
void __init tegra30_init_clocks(void)
{
int i;
struct clk *c;
for (i = 0; i < ARRAY_SIZE(tegra_ptr_clks); i++)
tegra30_init_one_clock(tegra_ptr_clks[i]);
for (i = 0; i < ARRAY_SIZE(tegra_list_clks); i++)
tegra30_init_one_clock(tegra_list_clks[i]);
for (i = 0; i < ARRAY_SIZE(tegra_clk_duplicates); i++) {
c = tegra_get_clock_by_name(tegra_clk_duplicates[i].name);
if (!c) {
pr_err("%s: Unknown duplicate clock %s\n", __func__,
tegra_clk_duplicates[i].name);
continue;
}
tegra_clk_duplicates[i].lookup.clk = c;
clkdev_add(&tegra_clk_duplicates[i].lookup);
}
for (i = 0; i < ARRAY_SIZE(tegra_sync_source_list); i++)
tegra30_init_one_clock(tegra_sync_source_list[i]);
for (i = 0; i < ARRAY_SIZE(tegra_clk_audio_list); i++)
tegra30_init_one_clock(tegra_clk_audio_list[i]);
for (i = 0; i < ARRAY_SIZE(tegra_clk_audio_2x_list); i++)
tegra30_init_one_clock(tegra_clk_audio_2x_list[i]);
for (i = 0; i < ARRAY_SIZE(tegra_clk_out_list); i++)
tegra30_init_one_clock(tegra_clk_out_list[i]);
tegra30_cpu_car_ops_init();
}
