static u8 clk_periph_get_parent(struct clk_hw *hw)
{
struct tegra_clk_periph *periph = to_clk_periph(hw);
const struct clk_ops *mux_ops = periph->mux_ops;
struct clk_hw *mux_hw = &periph->mux.hw;
mux_hw->clk = hw->clk;
return mux_ops->get_parent(mux_hw);
}
static int clk_periph_set_parent(struct clk_hw *hw, u8 index)
{
struct tegra_clk_periph *periph = to_clk_periph(hw);
const struct clk_ops *mux_ops = periph->mux_ops;
struct clk_hw *mux_hw = &periph->mux.hw;
mux_hw->clk = hw->clk;
return mux_ops->set_parent(mux_hw, index);
}
static unsigned long clk_periph_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct tegra_clk_periph *periph = to_clk_periph(hw);
const struct clk_ops *div_ops = periph->div_ops;
struct clk_hw *div_hw = &periph->divider.hw;
div_hw->clk = hw->clk;
return div_ops->recalc_rate(div_hw, parent_rate);
}
static long clk_periph_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct tegra_clk_periph *periph = to_clk_periph(hw);
const struct clk_ops *div_ops = periph->div_ops;
struct clk_hw *div_hw = &periph->divider.hw;
div_hw->clk = hw->clk;
return div_ops->round_rate(div_hw, rate, prate);
}
static int clk_periph_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct tegra_clk_periph *periph = to_clk_periph(hw);
const struct clk_ops *div_ops = periph->div_ops;
struct clk_hw *div_hw = &periph->divider.hw;
div_hw->clk = hw->clk;
return div_ops->set_rate(div_hw, rate, parent_rate);
}
static int clk_periph_is_enabled(struct clk_hw *hw)
{
struct tegra_clk_periph *periph = to_clk_periph(hw);
const struct clk_ops *gate_ops = periph->gate_ops;
struct clk_hw *gate_hw = &periph->gate.hw;
gate_hw->clk = hw->clk;
return gate_ops->is_enabled(gate_hw);
}
static int clk_periph_enable(struct clk_hw *hw)
{
struct tegra_clk_periph *periph = to_clk_periph(hw);
const struct clk_ops *gate_ops = periph->gate_ops;
struct clk_hw *gate_hw = &periph->gate.hw;
gate_hw->clk = hw->clk;
return gate_ops->enable(gate_hw);
}
static void clk_periph_disable(struct clk_hw *hw)
{
struct tegra_clk_periph *periph = to_clk_periph(hw);
const struct clk_ops *gate_ops = periph->gate_ops;
struct clk_hw *gate_hw = &periph->gate.hw;
gate_ops->disable(gate_hw);
}
void tegra_periph_reset_deassert(struct clk *c)
{
struct clk_hw *hw = __clk_get_hw(c);
struct tegra_clk_periph *periph = to_clk_periph(hw);
struct tegra_clk_periph_gate *gate;
if (periph->magic != TEGRA_CLK_PERIPH_MAGIC) {
gate = to_clk_periph_gate(hw);
if (gate->magic != TEGRA_CLK_PERIPH_GATE_MAGIC) {
WARN_ON(1);
return;
}
} else {
gate = &periph->gate;
}
tegra_periph_reset(gate, 0);
}
void tegra_periph_reset_assert(struct clk *c)
{
struct clk_hw *hw = __clk_get_hw(c);
struct tegra_clk_periph *periph = to_clk_periph(hw);
struct tegra_clk_periph_gate *gate;
if (periph->magic != TEGRA_CLK_PERIPH_MAGIC) {
gate = to_clk_periph_gate(hw);
if (gate->magic != TEGRA_CLK_PERIPH_GATE_MAGIC) {
WARN_ON(1);
return;
}
} else {
gate = &periph->gate;
}
tegra_periph_reset(gate, 1);
}
static struct clk *_tegra_clk_register_periph(const char *name,
const char **parent_names, int num_parents,
struct tegra_clk_periph *periph,
void __iomem *clk_base, u32 offset, bool div,
unsigned long flags)
{
struct clk *clk;
struct clk_init_data init;
init.name = name;
init.ops = div ? &tegra_clk_periph_ops : &tegra_clk_periph_nodiv_ops;
init.flags = flags;
init.parent_names = parent_names;
init.num_parents = num_parents;
periph->hw.init = &init;
periph->magic = TEGRA_CLK_PERIPH_MAGIC;
periph->mux.reg = clk_base + offset;
periph->divider.reg = div ? (clk_base + offset) : NULL;
periph->gate.clk_base = clk_base;
clk = clk_register(NULL, &periph->hw);
if (IS_ERR(clk))
return clk;
periph->mux.hw.clk = clk;
periph->divider.hw.clk = div ? clk : NULL;
periph->gate.hw.clk = clk;
return clk;
}
struct clk *tegra_clk_register_periph(const char *name,
const char **parent_names, int num_parents,
struct tegra_clk_periph *periph, void __iomem *clk_base,
u32 offset, unsigned long flags)
{
return _tegra_clk_register_periph(name, parent_names, num_parents,
periph, clk_base, offset, true, flags);
}
struct clk *tegra_clk_register_periph_nodiv(const char *name,
const char **parent_names, int num_parents,
struct tegra_clk_periph *periph, void __iomem *clk_base,
u32 offset)
{
return _tegra_clk_register_periph(name, parent_names, num_parents,
periph, clk_base, offset, false, CLK_SET_RATE_PARENT);
}
