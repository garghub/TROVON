static void init_audio_sync_clock_mux(void)
{
int i;
struct clk_mux_sel *sel = mux_audio_sync_clk;
const struct audio_sources *src = mux_audio_sync_clk_sources;
struct clk_lookup *lookup;
for (i = 0; src->name; i++, sel++, src++) {
sel->input = tegra_get_clock_by_name(src->name);
if (!sel->input)
pr_err("%s: could not find clk %s\n", __func__,
src->name);
audio_parents[src->value] = sel->input;
sel->value = src->value;
}
lookup = tegra_audio_clk_lookups;
for (i = 0; i < ARRAY_SIZE(tegra_audio_clk_lookups); i++, lookup++) {
struct clk *c = lookup->clk;
struct clk_tegra *clk = to_clk_tegra(c->hw);
__clk_init(NULL, c);
INIT_LIST_HEAD(&clk->shared_bus_list);
clk->lookup.con_id = lookup->con_id;
clk->lookup.clk = c;
clkdev_add(&clk->lookup);
tegra_clk_add(c);
}
}
static void tegra2_init_one_clock(struct clk *c)
{
struct clk_tegra *clk = to_clk_tegra(c->hw);
int ret;
ret = __clk_init(NULL, c);
if (ret)
pr_err("clk init failed %s\n", __clk_get_name(c));
INIT_LIST_HEAD(&clk->shared_bus_list);
if (!clk->lookup.dev_id && !clk->lookup.con_id)
clk->lookup.con_id = c->name;
clk->lookup.clk = c;
clkdev_add(&clk->lookup);
tegra_clk_add(c);
}
void __init tegra2_init_clocks(void)
{
int i;
struct clk *c;
for (i = 0; i < ARRAY_SIZE(tegra_ptr_clks); i++)
tegra2_init_one_clock(tegra_ptr_clks[i]);
for (i = 0; i < ARRAY_SIZE(tegra_list_clks); i++)
tegra2_init_one_clock(tegra_list_clks[i]);
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
init_audio_sync_clock_mux();
tegra20_cpu_car_ops_init();
}
