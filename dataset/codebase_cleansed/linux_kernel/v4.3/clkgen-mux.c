static const char ** __init clkgen_mux_get_parents(struct device_node *np,
int *num_parents)
{
const char **parents;
int nparents;
nparents = of_clk_get_parent_count(np);
if (WARN_ON(nparents <= 0))
return ERR_PTR(-EINVAL);
parents = kcalloc(nparents, sizeof(const char *), GFP_KERNEL);
if (!parents)
return ERR_PTR(-ENOMEM);
*num_parents = of_clk_parent_fill(np, parents, nparents);
return parents;
}
static int clkgena_divmux_is_running(struct clkgena_divmux *mux)
{
u32 regval = readl(mux->feedback_reg[mux->muxsel]);
u32 running = regval & BIT(mux->feedback_bit_idx);
return !!running;
}
static int clkgena_divmux_enable(struct clk_hw *hw)
{
struct clkgena_divmux *genamux = to_clkgena_divmux(hw);
struct clk_hw *mux_hw = &genamux->mux.hw;
unsigned long timeout;
int ret = 0;
__clk_hw_set_clk(mux_hw, hw);
ret = clk_mux_ops.set_parent(mux_hw, genamux->muxsel);
if (ret)
return ret;
timeout = jiffies + msecs_to_jiffies(10);
while (!clkgena_divmux_is_running(genamux)) {
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
cpu_relax();
}
return 0;
}
static void clkgena_divmux_disable(struct clk_hw *hw)
{
struct clkgena_divmux *genamux = to_clkgena_divmux(hw);
struct clk_hw *mux_hw = &genamux->mux.hw;
__clk_hw_set_clk(mux_hw, hw);
clk_mux_ops.set_parent(mux_hw, CKGAX_CLKOPSRC_SWITCH_OFF);
}
static int clkgena_divmux_is_enabled(struct clk_hw *hw)
{
struct clkgena_divmux *genamux = to_clkgena_divmux(hw);
struct clk_hw *mux_hw = &genamux->mux.hw;
__clk_hw_set_clk(mux_hw, hw);
return (s8)clk_mux_ops.get_parent(mux_hw) > 0;
}
static u8 clkgena_divmux_get_parent(struct clk_hw *hw)
{
struct clkgena_divmux *genamux = to_clkgena_divmux(hw);
struct clk_hw *mux_hw = &genamux->mux.hw;
__clk_hw_set_clk(mux_hw, hw);
genamux->muxsel = clk_mux_ops.get_parent(mux_hw);
if ((s8)genamux->muxsel < 0) {
pr_debug("%s: %s: Invalid parent, setting to default.\n",
__func__, clk_hw_get_name(hw));
genamux->muxsel = 0;
}
return genamux->muxsel;
}
static int clkgena_divmux_set_parent(struct clk_hw *hw, u8 index)
{
struct clkgena_divmux *genamux = to_clkgena_divmux(hw);
if (index >= CKGAX_CLKOPSRC_SWITCH_OFF)
return -EINVAL;
genamux->muxsel = index;
if (clkgena_divmux_is_enabled(hw))
clkgena_divmux_enable(hw);
return 0;
}
static unsigned long clkgena_divmux_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clkgena_divmux *genamux = to_clkgena_divmux(hw);
struct clk_hw *div_hw = &genamux->div[genamux->muxsel].hw;
__clk_hw_set_clk(div_hw, hw);
return clk_divider_ops.recalc_rate(div_hw, parent_rate);
}
static int clkgena_divmux_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clkgena_divmux *genamux = to_clkgena_divmux(hw);
struct clk_hw *div_hw = &genamux->div[genamux->muxsel].hw;
__clk_hw_set_clk(div_hw, hw);
return clk_divider_ops.set_rate(div_hw, rate, parent_rate);
}
static long clkgena_divmux_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct clkgena_divmux *genamux = to_clkgena_divmux(hw);
struct clk_hw *div_hw = &genamux->div[genamux->muxsel].hw;
__clk_hw_set_clk(div_hw, hw);
return clk_divider_ops.round_rate(div_hw, rate, prate);
}
static struct clk * __init clk_register_genamux(const char *name,
const char **parent_names, u8 num_parents,
void __iomem *reg,
const struct clkgena_divmux_data *muxdata,
u32 idx)
{
const int mux_width = 2;
const int divider_width = 5;
struct clkgena_divmux *genamux;
struct clk *clk;
struct clk_init_data init;
int i;
genamux = kzalloc(sizeof(*genamux), GFP_KERNEL);
if (!genamux)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &clkgena_divmux_ops;
init.flags = CLK_IS_BASIC | CLK_GET_RATE_NOCACHE;
init.parent_names = parent_names;
init.num_parents = num_parents;
genamux->mux.lock = &clkgena_divmux_lock;
genamux->mux.mask = BIT(mux_width) - 1;
genamux->mux.shift = muxdata->mux_start_bit + (idx * mux_width);
if (genamux->mux.shift > 31) {
genamux->mux.reg = reg + muxdata->mux_offset2;
genamux->mux.shift -= 32;
} else {
genamux->mux.reg = reg + muxdata->mux_offset;
}
for (i = 0; i < NUM_INPUTS; i++) {
void __iomem *divbase = reg + muxdata->div_offsets[i];
genamux->div[i].width = divider_width;
genamux->div[i].reg = divbase + (idx * sizeof(u32));
genamux->feedback_reg[i] = reg + muxdata->fb_offsets[i];
}
genamux->feedback_bit_idx = muxdata->fb_start_bit_idx + idx;
genamux->hw.init = &init;
clk = clk_register(NULL, &genamux->hw);
if (IS_ERR(clk)) {
kfree(genamux);
goto err;
}
pr_debug("%s: parent %s rate %lu\n",
__clk_get_name(clk),
__clk_get_name(clk_get_parent(clk)),
clk_get_rate(clk));
err:
return clk;
}
static void __iomem * __init clkgen_get_register_base(struct device_node *np)
{
struct device_node *pnode;
void __iomem *reg;
pnode = of_get_parent(np);
if (!pnode)
return NULL;
reg = of_iomap(pnode, 0);
of_node_put(pnode);
return reg;
}
static void __init st_of_clkgena_divmux_setup(struct device_node *np)
{
const struct of_device_id *match;
const struct clkgena_divmux_data *data;
struct clk_onecell_data *clk_data;
void __iomem *reg;
const char **parents;
int num_parents = 0, i;
match = of_match_node(clkgena_divmux_of_match, np);
if (WARN_ON(!match))
return;
data = match->data;
reg = clkgen_get_register_base(np);
if (!reg)
return;
parents = clkgen_mux_get_parents(np, &num_parents);
if (IS_ERR(parents))
goto err_parents;
clk_data = kzalloc(sizeof(*clk_data), GFP_KERNEL);
if (!clk_data)
goto err_alloc;
clk_data->clk_num = data->num_outputs;
clk_data->clks = kcalloc(clk_data->clk_num, sizeof(struct clk *),
GFP_KERNEL);
if (!clk_data->clks)
goto err_alloc_clks;
for (i = 0; i < clk_data->clk_num; i++) {
struct clk *clk;
const char *clk_name;
if (of_property_read_string_index(np, "clock-output-names",
i, &clk_name))
break;
if (*clk_name == '\0')
continue;
clk = clk_register_genamux(clk_name, parents, num_parents,
reg, data, i);
if (IS_ERR(clk))
goto err;
clk_data->clks[i] = clk;
}
kfree(parents);
of_clk_add_provider(np, of_clk_src_onecell_get, clk_data);
return;
err:
kfree(clk_data->clks);
err_alloc_clks:
kfree(clk_data);
err_alloc:
kfree(parents);
err_parents:
iounmap(reg);
}
static void __init st_of_clkgena_prediv_setup(struct device_node *np)
{
const struct of_device_id *match;
void __iomem *reg;
const char *parent_name, *clk_name;
struct clk *clk;
const struct clkgena_prediv_data *data;
match = of_match_node(clkgena_prediv_of_match, np);
if (!match) {
pr_err("%s: No matching data\n", __func__);
return;
}
data = match->data;
reg = clkgen_get_register_base(np);
if (!reg)
return;
parent_name = of_clk_get_parent_name(np, 0);
if (!parent_name)
goto err;
if (of_property_read_string_index(np, "clock-output-names",
0, &clk_name))
goto err;
clk = clk_register_divider_table(NULL, clk_name, parent_name,
CLK_GET_RATE_NOCACHE,
reg + data->offset, data->shift, 1,
0, data->table, NULL);
if (IS_ERR(clk))
goto err;
of_clk_add_provider(np, of_clk_src_simple_get, clk);
pr_debug("%s: parent %s rate %u\n",
__clk_get_name(clk),
__clk_get_name(clk_get_parent(clk)),
(unsigned int)clk_get_rate(clk));
return;
err:
iounmap(reg);
}
static void __init st_of_clkgen_mux_setup(struct device_node *np)
{
const struct of_device_id *match;
struct clk *clk;
void __iomem *reg;
const char **parents;
int num_parents;
const struct clkgen_mux_data *data;
match = of_match_node(mux_of_match, np);
if (!match) {
pr_err("%s: No matching data\n", __func__);
return;
}
data = match->data;
reg = of_iomap(np, 0);
if (!reg) {
pr_err("%s: Failed to get base address\n", __func__);
return;
}
parents = clkgen_mux_get_parents(np, &num_parents);
if (IS_ERR(parents)) {
pr_err("%s: Failed to get parents (%ld)\n",
__func__, PTR_ERR(parents));
goto err_parents;
}
clk = clk_register_mux(NULL, np->name, parents, num_parents,
data->clk_flags | CLK_SET_RATE_PARENT,
reg + data->offset,
data->shift, data->width, data->mux_flags,
data->lock);
if (IS_ERR(clk))
goto err;
pr_debug("%s: parent %s rate %u\n",
__clk_get_name(clk),
__clk_get_name(clk_get_parent(clk)),
(unsigned int)clk_get_rate(clk));
kfree(parents);
of_clk_add_provider(np, of_clk_src_simple_get, clk);
return;
err:
kfree(parents);
err_parents:
iounmap(reg);
}
static void __init st_of_clkgen_vcc_setup(struct device_node *np)
{
const struct of_device_id *match;
void __iomem *reg;
const char **parents;
int num_parents, i;
struct clk_onecell_data *clk_data;
const struct clkgen_vcc_data *data;
match = of_match_node(vcc_of_match, np);
if (WARN_ON(!match))
return;
data = match->data;
reg = of_iomap(np, 0);
if (!reg)
return;
parents = clkgen_mux_get_parents(np, &num_parents);
if (IS_ERR(parents))
goto err_parents;
clk_data = kzalloc(sizeof(*clk_data), GFP_KERNEL);
if (!clk_data)
goto err_alloc;
clk_data->clk_num = VCC_MAX_CHANNELS;
clk_data->clks = kcalloc(clk_data->clk_num, sizeof(struct clk *),
GFP_KERNEL);
if (!clk_data->clks)
goto err_alloc_clks;
for (i = 0; i < clk_data->clk_num; i++) {
struct clk *clk;
const char *clk_name;
struct clk_gate *gate;
struct clk_divider *div;
struct clk_mux *mux;
if (of_property_read_string_index(np, "clock-output-names",
i, &clk_name))
break;
if (*clk_name == '\0')
continue;
gate = kzalloc(sizeof(*gate), GFP_KERNEL);
if (!gate)
goto err;
div = kzalloc(sizeof(*div), GFP_KERNEL);
if (!div) {
kfree(gate);
goto err;
}
mux = kzalloc(sizeof(*mux), GFP_KERNEL);
if (!mux) {
kfree(gate);
kfree(div);
goto err;
}
gate->reg = reg + VCC_GATE_OFFSET;
gate->bit_idx = i;
gate->flags = CLK_GATE_SET_TO_DISABLE;
gate->lock = data->lock;
div->reg = reg + VCC_DIV_OFFSET;
div->shift = 2 * i;
div->width = 2;
div->flags = CLK_DIVIDER_POWER_OF_TWO |
CLK_DIVIDER_ROUND_CLOSEST;
mux->reg = reg + VCC_MUX_OFFSET;
mux->shift = 2 * i;
mux->mask = 0x3;
clk = clk_register_composite(NULL, clk_name, parents,
num_parents,
&mux->hw, &clk_mux_ops,
&div->hw, &clk_divider_ops,
&gate->hw, &clk_gate_ops,
data->clk_flags |
CLK_GET_RATE_NOCACHE);
if (IS_ERR(clk)) {
kfree(gate);
kfree(div);
kfree(mux);
goto err;
}
pr_debug("%s: parent %s rate %u\n",
__clk_get_name(clk),
__clk_get_name(clk_get_parent(clk)),
(unsigned int)clk_get_rate(clk));
clk_data->clks[i] = clk;
}
kfree(parents);
of_clk_add_provider(np, of_clk_src_onecell_get, clk_data);
return;
err:
for (i = 0; i < clk_data->clk_num; i++) {
struct clk_composite *composite;
if (!clk_data->clks[i])
continue;
composite = container_of(__clk_get_hw(clk_data->clks[i]),
struct clk_composite, hw);
kfree(container_of(composite->gate_hw, struct clk_gate, hw));
kfree(container_of(composite->rate_hw, struct clk_divider, hw));
kfree(container_of(composite->mux_hw, struct clk_mux, hw));
}
kfree(clk_data->clks);
err_alloc_clks:
kfree(clk_data);
err_alloc:
kfree(parents);
err_parents:
iounmap(reg);
}
