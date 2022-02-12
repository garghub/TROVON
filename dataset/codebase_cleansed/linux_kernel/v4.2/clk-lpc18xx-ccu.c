static struct clk *lpc18xx_ccu_branch_clk_get(struct of_phandle_args *clkspec,
void *data)
{
struct lpc18xx_branch_clk_data *clk_data = data;
unsigned int offset = clkspec->args[0];
int i, j;
for (i = 0; i < ARRAY_SIZE(clk_branches); i++) {
if (clk_branches[i].offset != offset)
continue;
for (j = 0; j < clk_data->num; j++) {
if (!strcmp(clk_branches[i].base_name, clk_data->name[j]))
return clk_branches[i].clk;
}
}
pr_err("%s: invalid clock offset %d\n", __func__, offset);
return ERR_PTR(-EINVAL);
}
static int lpc18xx_ccu_gate_endisable(struct clk_hw *hw, bool enable)
{
struct clk_gate *gate = to_clk_gate(hw);
u32 val;
val = clk_readl(gate->reg);
if (val & LPC18XX_CCU_DIVSTAT)
val |= LPC18XX_CCU_DIV;
if (enable) {
val |= LPC18XX_CCU_RUN;
} else {
val |= LPC18XX_CCU_AUTO;
clk_writel(val, gate->reg);
val &= ~LPC18XX_CCU_RUN;
}
clk_writel(val, gate->reg);
return 0;
}
static int lpc18xx_ccu_gate_enable(struct clk_hw *hw)
{
return lpc18xx_ccu_gate_endisable(hw, true);
}
static void lpc18xx_ccu_gate_disable(struct clk_hw *hw)
{
lpc18xx_ccu_gate_endisable(hw, false);
}
static int lpc18xx_ccu_gate_is_enabled(struct clk_hw *hw)
{
struct clk_gate *gate = to_clk_gate(hw);
return clk_readl(gate->reg) & LPC18XX_CCU_RUN;
}
static void lpc18xx_ccu_register_branch_gate_div(struct lpc18xx_clk_branch *branch,
void __iomem *reg_base,
const char *parent)
{
const struct clk_ops *div_ops = NULL;
struct clk_divider *div = NULL;
struct clk_hw *div_hw = NULL;
if (branch->flags & CCU_BRANCH_HAVE_DIV2) {
div = kzalloc(sizeof(*div), GFP_KERNEL);
if (!div)
return;
div->reg = branch->offset + reg_base;
div->flags = CLK_DIVIDER_READ_ONLY;
div->shift = 27;
div->width = 1;
div_hw = &div->hw;
div_ops = &clk_divider_ops;
}
branch->gate.reg = branch->offset + reg_base;
branch->gate.bit_idx = 0;
branch->clk = clk_register_composite(NULL, branch->name, &parent, 1,
NULL, NULL,
div_hw, div_ops,
&branch->gate.hw, &lpc18xx_ccu_gate_ops, 0);
if (IS_ERR(branch->clk)) {
kfree(div);
pr_warn("%s: failed to register %s\n", __func__, branch->name);
return;
}
switch (branch->offset) {
case CLK_CPU_EMC:
case CLK_CPU_CORE:
case CLK_CPU_CREG:
case CLK_CPU_EMCDIV:
clk_prepare_enable(branch->clk);
}
}
static void lpc18xx_ccu_register_branch_clks(void __iomem *reg_base,
const char *base_name)
{
const char *parent = base_name;
int i;
for (i = 0; i < ARRAY_SIZE(clk_branches); i++) {
if (strcmp(clk_branches[i].base_name, base_name))
continue;
lpc18xx_ccu_register_branch_gate_div(&clk_branches[i], reg_base,
parent);
if (clk_branches[i].flags & CCU_BRANCH_IS_BUS)
parent = clk_branches[i].name;
}
}
static void __init lpc18xx_ccu_init(struct device_node *np)
{
struct lpc18xx_branch_clk_data *clk_data;
void __iomem *reg_base;
int i, ret;
reg_base = of_iomap(np, 0);
if (!reg_base) {
pr_warn("%s: failed to map address range\n", __func__);
return;
}
clk_data = kzalloc(sizeof(*clk_data), GFP_KERNEL);
if (!clk_data)
return;
clk_data->num = of_property_count_strings(np, "clock-names");
clk_data->name = kcalloc(clk_data->num, sizeof(char *), GFP_KERNEL);
if (!clk_data->name) {
kfree(clk_data);
return;
}
for (i = 0; i < clk_data->num; i++) {
ret = of_property_read_string_index(np, "clock-names", i,
&clk_data->name[i]);
if (ret) {
pr_warn("%s: failed to get clock name at idx %d\n",
__func__, i);
continue;
}
lpc18xx_ccu_register_branch_clks(reg_base, clk_data->name[i]);
}
of_clk_add_provider(np, lpc18xx_ccu_branch_clk_get, clk_data);
}
