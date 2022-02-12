static int clkgen_pll_is_locked(struct clk_hw *hw)
{
struct clkgen_pll *pll = to_clkgen_pll(hw);
u32 locked = CLKGEN_READ(pll, locked_status);
return !!locked;
}
static int clkgen_pll_is_enabled(struct clk_hw *hw)
{
struct clkgen_pll *pll = to_clkgen_pll(hw);
u32 poweroff = CLKGEN_READ(pll, pdn_status);
return !poweroff;
}
static unsigned long recalc_stm_pll800c65(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clkgen_pll *pll = to_clkgen_pll(hw);
unsigned long mdiv, ndiv, pdiv;
unsigned long rate;
uint64_t res;
if (!clkgen_pll_is_enabled(hw) || !clkgen_pll_is_locked(hw))
return 0;
pdiv = CLKGEN_READ(pll, pdiv);
mdiv = CLKGEN_READ(pll, mdiv);
ndiv = CLKGEN_READ(pll, ndiv);
if (!mdiv)
mdiv++;
res = (uint64_t)2 * (uint64_t)parent_rate * (uint64_t)ndiv;
rate = (unsigned long)div64_u64(res, mdiv * (1 << pdiv));
pr_debug("%s:%s rate %lu\n", __clk_get_name(hw->clk), __func__, rate);
return rate;
}
static unsigned long recalc_stm_pll1600c65(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clkgen_pll *pll = to_clkgen_pll(hw);
unsigned long mdiv, ndiv;
unsigned long rate;
if (!clkgen_pll_is_enabled(hw) || !clkgen_pll_is_locked(hw))
return 0;
mdiv = CLKGEN_READ(pll, mdiv);
ndiv = CLKGEN_READ(pll, ndiv);
if (!mdiv)
mdiv = 1;
rate = ((2 * (parent_rate / 1000) * ndiv) / mdiv) * 1000;
pr_debug("%s:%s rate %lu\n", __clk_get_name(hw->clk), __func__, rate);
return rate;
}
static unsigned long recalc_stm_pll3200c32(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clkgen_pll *pll = to_clkgen_pll(hw);
unsigned long ndiv, idf;
unsigned long rate = 0;
if (!clkgen_pll_is_enabled(hw) || !clkgen_pll_is_locked(hw))
return 0;
ndiv = CLKGEN_READ(pll, ndiv);
idf = CLKGEN_READ(pll, idf);
if (idf)
rate = ((2 * (parent_rate/1000) * ndiv) / idf) * 1000;
pr_debug("%s:%s rate %lu\n", __clk_get_name(hw->clk), __func__, rate);
return rate;
}
static unsigned long recalc_stm_pll1200c32(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clkgen_pll *pll = to_clkgen_pll(hw);
unsigned long odf, ldf, idf;
unsigned long rate;
if (!clkgen_pll_is_enabled(hw) || !clkgen_pll_is_locked(hw))
return 0;
odf = CLKGEN_READ(pll, odf[0]);
ldf = CLKGEN_READ(pll, ldf);
idf = CLKGEN_READ(pll, idf);
if (!idf)
idf = 1;
if (!odf)
odf = 1;
rate = (((parent_rate / 1000) * ldf) / (odf * idf)) * 1000;
pr_debug("%s:%s rate %lu\n", __clk_get_name(hw->clk), __func__, rate);
return rate;
}
static struct clk * __init clkgen_pll_register(const char *parent_name,
struct clkgen_pll_data *pll_data,
void __iomem *reg,
const char *clk_name)
{
struct clkgen_pll *pll;
struct clk *clk;
struct clk_init_data init;
pll = kzalloc(sizeof(*pll), GFP_KERNEL);
if (!pll)
return ERR_PTR(-ENOMEM);
init.name = clk_name;
init.ops = pll_data->ops;
init.flags = CLK_IS_BASIC | CLK_GET_RATE_NOCACHE;
init.parent_names = &parent_name;
init.num_parents = 1;
pll->data = pll_data;
pll->regs_base = reg;
pll->hw.init = &init;
clk = clk_register(NULL, &pll->hw);
if (IS_ERR(clk)) {
kfree(pll);
return clk;
}
pr_debug("%s: parent %s rate %lu\n",
__clk_get_name(clk),
__clk_get_name(clk_get_parent(clk)),
clk_get_rate(clk));
return clk;
}
static struct clk * __init clkgen_c65_lsdiv_register(const char *parent_name,
const char *clk_name)
{
struct clk *clk;
clk = clk_register_fixed_factor(NULL, clk_name, parent_name, 0, 1, 2);
if (IS_ERR(clk))
return clk;
pr_debug("%s: parent %s rate %lu\n",
__clk_get_name(clk),
__clk_get_name(clk_get_parent(clk)),
clk_get_rate(clk));
return clk;
}
static void __iomem * __init clkgen_get_register_base(
struct device_node *np)
{
struct device_node *pnode;
void __iomem *reg = NULL;
pnode = of_get_parent(np);
if (!pnode)
return NULL;
reg = of_iomap(pnode, 0);
of_node_put(pnode);
return reg;
}
static void __init clkgena_c65_pll_setup(struct device_node *np)
{
const int num_pll_outputs = 3;
struct clk_onecell_data *clk_data;
const char *parent_name;
void __iomem *reg;
const char *clk_name;
parent_name = of_clk_get_parent_name(np, 0);
if (!parent_name)
return;
reg = clkgen_get_register_base(np);
if (!reg)
return;
clk_data = kzalloc(sizeof(*clk_data), GFP_KERNEL);
if (!clk_data)
return;
clk_data->clk_num = num_pll_outputs;
clk_data->clks = kzalloc(clk_data->clk_num * sizeof(struct clk *),
GFP_KERNEL);
if (!clk_data->clks)
goto err;
if (of_property_read_string_index(np, "clock-output-names",
0, &clk_name))
goto err;
clk_data->clks[0] = clkgen_pll_register(parent_name,
(struct clkgen_pll_data *) &st_pll1600c65_ax,
reg + CLKGENAx_PLL0_OFFSET, clk_name);
if (IS_ERR(clk_data->clks[0]))
goto err;
if (of_property_read_string_index(np, "clock-output-names",
1, &clk_name))
goto err;
clk_data->clks[1] = clkgen_c65_lsdiv_register(__clk_get_name
(clk_data->clks[0]),
clk_name);
if (IS_ERR(clk_data->clks[1]))
goto err;
if (of_property_read_string_index(np, "clock-output-names",
2, &clk_name))
goto err;
clk_data->clks[2] = clkgen_pll_register(parent_name,
(struct clkgen_pll_data *) &st_pll800c65_ax,
reg + CLKGENAx_PLL1_OFFSET, clk_name);
if (IS_ERR(clk_data->clks[2]))
goto err;
of_clk_add_provider(np, of_clk_src_onecell_get, clk_data);
return;
err:
kfree(clk_data->clks);
kfree(clk_data);
}
static struct clk * __init clkgen_odf_register(const char *parent_name,
void __iomem *reg,
struct clkgen_pll_data *pll_data,
int odf,
spinlock_t *odf_lock,
const char *odf_name)
{
struct clk *clk;
unsigned long flags;
struct clk_gate *gate;
struct clk_divider *div;
flags = CLK_GET_RATE_NOCACHE | CLK_SET_RATE_GATE;
gate = kzalloc(sizeof(*gate), GFP_KERNEL);
if (!gate)
return ERR_PTR(-ENOMEM);
gate->flags = CLK_GATE_SET_TO_DISABLE;
gate->reg = reg + pll_data->odf_gate[odf].offset;
gate->bit_idx = pll_data->odf_gate[odf].shift;
gate->lock = odf_lock;
div = kzalloc(sizeof(*div), GFP_KERNEL);
if (!div) {
kfree(gate);
return ERR_PTR(-ENOMEM);
}
div->flags = CLK_DIVIDER_ONE_BASED | CLK_DIVIDER_ALLOW_ZERO;
div->reg = reg + pll_data->odf[odf].offset;
div->shift = pll_data->odf[odf].shift;
div->width = fls(pll_data->odf[odf].mask);
div->lock = odf_lock;
clk = clk_register_composite(NULL, odf_name, &parent_name, 1,
NULL, NULL,
&div->hw, &clk_divider_ops,
&gate->hw, &clk_gate_ops,
flags);
if (IS_ERR(clk))
return clk;
pr_debug("%s: parent %s rate %lu\n",
__clk_get_name(clk),
__clk_get_name(clk_get_parent(clk)),
clk_get_rate(clk));
return clk;
}
static void __init clkgen_c32_pll_setup(struct device_node *np)
{
const struct of_device_id *match;
struct clk *clk;
const char *parent_name, *pll_name;
void __iomem *pll_base;
int num_odfs, odf;
struct clk_onecell_data *clk_data;
struct clkgen_pll_data *data;
match = of_match_node(c32_pll_of_match, np);
if (!match) {
pr_err("%s: No matching data\n", __func__);
return;
}
data = (struct clkgen_pll_data *) match->data;
parent_name = of_clk_get_parent_name(np, 0);
if (!parent_name)
return;
pll_base = clkgen_get_register_base(np);
if (!pll_base)
return;
clk = clkgen_pll_register(parent_name, data, pll_base, np->name);
if (IS_ERR(clk))
return;
pll_name = __clk_get_name(clk);
num_odfs = data->num_odfs;
clk_data = kzalloc(sizeof(*clk_data), GFP_KERNEL);
if (!clk_data)
return;
clk_data->clk_num = num_odfs;
clk_data->clks = kzalloc(clk_data->clk_num * sizeof(struct clk *),
GFP_KERNEL);
if (!clk_data->clks)
goto err;
for (odf = 0; odf < num_odfs; odf++) {
struct clk *clk;
const char *clk_name;
if (of_property_read_string_index(np, "clock-output-names",
odf, &clk_name))
return;
clk = clkgen_odf_register(pll_name, pll_base, data,
odf, &clkgena_c32_odf_lock, clk_name);
if (IS_ERR(clk))
goto err;
clk_data->clks[odf] = clk;
}
of_clk_add_provider(np, of_clk_src_onecell_get, clk_data);
return;
err:
kfree(pll_name);
kfree(clk_data->clks);
kfree(clk_data);
}
static void __init clkgengpu_c32_pll_setup(struct device_node *np)
{
const struct of_device_id *match;
struct clk *clk;
const char *parent_name;
void __iomem *reg;
const char *clk_name;
struct clkgen_pll_data *data;
match = of_match_node(c32_gpu_pll_of_match, np);
if (!match) {
pr_err("%s: No matching data\n", __func__);
return;
}
data = (struct clkgen_pll_data *)match->data;
parent_name = of_clk_get_parent_name(np, 0);
if (!parent_name)
return;
reg = clkgen_get_register_base(np);
if (!reg)
return;
if (of_property_read_string_index(np, "clock-output-names",
0, &clk_name))
return;
clk = clkgen_pll_register(parent_name, data, reg, clk_name);
if (!IS_ERR(clk))
of_clk_add_provider(np, of_clk_src_simple_get, clk);
return;
}
