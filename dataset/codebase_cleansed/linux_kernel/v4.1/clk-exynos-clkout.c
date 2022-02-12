static int exynos_clkout_suspend(void)
{
clkout->pmu_debug_save = readl(clkout->reg + EXYNOS_PMU_DEBUG_REG);
return 0;
}
static void exynos_clkout_resume(void)
{
writel(clkout->pmu_debug_save, clkout->reg + EXYNOS_PMU_DEBUG_REG);
}
static void __init exynos_clkout_init(struct device_node *node, u32 mux_mask)
{
const char *parent_names[EXYNOS_CLKOUT_PARENTS];
struct clk *parents[EXYNOS_CLKOUT_PARENTS];
int parent_count;
int ret;
int i;
clkout = kzalloc(sizeof(*clkout), GFP_KERNEL);
if (!clkout)
return;
spin_lock_init(&clkout->slock);
parent_count = 0;
for (i = 0; i < EXYNOS_CLKOUT_PARENTS; ++i) {
char name[] = "clkoutXX";
snprintf(name, sizeof(name), "clkout%d", i);
parents[i] = of_clk_get_by_name(node, name);
if (IS_ERR(parents[i])) {
parent_names[i] = "none";
continue;
}
parent_names[i] = __clk_get_name(parents[i]);
parent_count = i + 1;
}
if (!parent_count)
goto free_clkout;
clkout->reg = of_iomap(node, 0);
if (!clkout->reg)
goto clks_put;
clkout->gate.reg = clkout->reg + EXYNOS_PMU_DEBUG_REG;
clkout->gate.bit_idx = EXYNOS_CLKOUT_DISABLE_SHIFT;
clkout->gate.flags = CLK_GATE_SET_TO_DISABLE;
clkout->gate.lock = &clkout->slock;
clkout->mux.reg = clkout->reg + EXYNOS_PMU_DEBUG_REG;
clkout->mux.mask = mux_mask;
clkout->mux.shift = EXYNOS_CLKOUT_MUX_SHIFT;
clkout->mux.lock = &clkout->slock;
clkout->clk_table[0] = clk_register_composite(NULL, "clkout",
parent_names, parent_count, &clkout->mux.hw,
&clk_mux_ops, NULL, NULL, &clkout->gate.hw,
&clk_gate_ops, CLK_SET_RATE_PARENT
| CLK_SET_RATE_NO_REPARENT);
if (IS_ERR(clkout->clk_table[0]))
goto err_unmap;
clkout->data.clks = clkout->clk_table;
clkout->data.clk_num = EXYNOS_CLKOUT_NR_CLKS;
ret = of_clk_add_provider(node, of_clk_src_onecell_get, &clkout->data);
if (ret)
goto err_clk_unreg;
register_syscore_ops(&exynos_clkout_syscore_ops);
return;
err_clk_unreg:
clk_unregister(clkout->clk_table[0]);
err_unmap:
iounmap(clkout->reg);
clks_put:
for (i = 0; i < EXYNOS_CLKOUT_PARENTS; ++i)
if (!IS_ERR(parents[i]))
clk_put(parents[i]);
free_clkout:
kfree(clkout);
pr_err("%s: failed to register clkout clock\n", __func__);
}
static void __init exynos4_clkout_init(struct device_node *node)
{
exynos_clkout_init(node, EXYNOS4_CLKOUT_MUX_MASK);
}
static void __init exynos5_clkout_init(struct device_node *node)
{
exynos_clkout_init(node, EXYNOS5_CLKOUT_MUX_MASK);
}
