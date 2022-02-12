static int __init dm814x_adpll_early_init(void)
{
struct device_node *np;
if (!timer_clocks_initialized)
return -ENODEV;
np = of_find_node_by_name(NULL, "pllss");
if (!np) {
pr_err("Could not find node for plls\n");
return -ENODEV;
}
of_platform_populate(np, NULL, NULL, NULL);
return 0;
}
static int __init dm814x_adpll_enable_init_clocks(void)
{
int i, err;
if (!timer_clocks_initialized)
return -ENODEV;
for (i = 0; i < ARRAY_SIZE(init_clocks); i++) {
struct clk *clock;
clock = clk_get(NULL, init_clocks[i]);
if (WARN(IS_ERR(clock), "could not find init clock %s\n",
init_clocks[i]))
continue;
err = clk_prepare_enable(clock);
if (WARN(err, "could not enable init clock %s\n",
init_clocks[i]))
continue;
}
return 0;
}
int __init dm814x_dt_clk_init(void)
{
ti_dt_clocks_register(dm814_clks);
omap2_clk_disable_autoidle_all();
omap2_clk_enable_init_clocks(NULL, 0);
timer_clocks_initialized = true;
return 0;
}
