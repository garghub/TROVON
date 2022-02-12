static u32 ext_field(u32 val, u32 mask)
{
return (val & mask) >> (ffs(mask) - 1);
}
static void __init clk_boston_setup(struct device_node *np)
{
unsigned long in_freq, cpu_freq, sys_freq;
uint mmcmdiv, mul, cpu_div, sys_div;
struct clk_hw_onecell_data *onecell;
struct regmap *regmap;
struct clk_hw *hw;
int err;
regmap = syscon_node_to_regmap(np->parent);
if (IS_ERR(regmap)) {
pr_err("failed to find regmap\n");
return;
}
err = regmap_read(regmap, BOSTON_PLAT_MMCMDIV, &mmcmdiv);
if (err) {
pr_err("failed to read mmcm_div register: %d\n", err);
return;
}
in_freq = ext_field(mmcmdiv, BOSTON_PLAT_MMCMDIV_INPUT) * 1000000;
mul = ext_field(mmcmdiv, BOSTON_PLAT_MMCMDIV_MUL);
sys_div = ext_field(mmcmdiv, BOSTON_PLAT_MMCMDIV_CLK0DIV);
sys_freq = mult_frac(in_freq, mul, sys_div);
cpu_div = ext_field(mmcmdiv, BOSTON_PLAT_MMCMDIV_CLK1DIV);
cpu_freq = mult_frac(in_freq, mul, cpu_div);
onecell = kzalloc(sizeof(*onecell) +
(BOSTON_CLK_COUNT * sizeof(struct clk_hw *)),
GFP_KERNEL);
if (!onecell)
return;
onecell->num = BOSTON_CLK_COUNT;
hw = clk_hw_register_fixed_rate(NULL, "input", NULL, 0, in_freq);
if (IS_ERR(hw)) {
pr_err("failed to register input clock: %ld\n", PTR_ERR(hw));
return;
}
onecell->hws[BOSTON_CLK_INPUT] = hw;
hw = clk_hw_register_fixed_rate(NULL, "sys", "input", 0, sys_freq);
if (IS_ERR(hw)) {
pr_err("failed to register sys clock: %ld\n", PTR_ERR(hw));
return;
}
onecell->hws[BOSTON_CLK_SYS] = hw;
hw = clk_hw_register_fixed_rate(NULL, "cpu", "input", 0, cpu_freq);
if (IS_ERR(hw)) {
pr_err("failed to register cpu clock: %ld\n", PTR_ERR(hw));
return;
}
onecell->hws[BOSTON_CLK_CPU] = hw;
err = of_clk_add_hw_provider(np, of_clk_hw_onecell_get, onecell);
if (err)
pr_err("failed to add DT provider: %d\n", err);
}
