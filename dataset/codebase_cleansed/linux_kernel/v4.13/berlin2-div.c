static int berlin2_div_is_enabled(struct clk_hw *hw)
{
struct berlin2_div *div = to_berlin2_div(hw);
struct berlin2_div_map *map = &div->map;
u32 reg;
if (div->lock)
spin_lock(div->lock);
reg = readl_relaxed(div->base + map->gate_offs);
reg >>= map->gate_shift;
if (div->lock)
spin_unlock(div->lock);
return (reg & 0x1);
}
static int berlin2_div_enable(struct clk_hw *hw)
{
struct berlin2_div *div = to_berlin2_div(hw);
struct berlin2_div_map *map = &div->map;
u32 reg;
if (div->lock)
spin_lock(div->lock);
reg = readl_relaxed(div->base + map->gate_offs);
reg |= BIT(map->gate_shift);
writel_relaxed(reg, div->base + map->gate_offs);
if (div->lock)
spin_unlock(div->lock);
return 0;
}
static void berlin2_div_disable(struct clk_hw *hw)
{
struct berlin2_div *div = to_berlin2_div(hw);
struct berlin2_div_map *map = &div->map;
u32 reg;
if (div->lock)
spin_lock(div->lock);
reg = readl_relaxed(div->base + map->gate_offs);
reg &= ~BIT(map->gate_shift);
writel_relaxed(reg, div->base + map->gate_offs);
if (div->lock)
spin_unlock(div->lock);
}
static int berlin2_div_set_parent(struct clk_hw *hw, u8 index)
{
struct berlin2_div *div = to_berlin2_div(hw);
struct berlin2_div_map *map = &div->map;
u32 reg;
if (div->lock)
spin_lock(div->lock);
reg = readl_relaxed(div->base + map->pll_switch_offs);
if (index == 0)
reg &= ~BIT(map->pll_switch_shift);
else
reg |= BIT(map->pll_switch_shift);
writel_relaxed(reg, div->base + map->pll_switch_offs);
if (index > 0) {
reg = readl_relaxed(div->base + map->pll_select_offs);
reg &= ~(PLL_SELECT_MASK << map->pll_select_shift);
reg |= (index - 1) << map->pll_select_shift;
writel_relaxed(reg, div->base + map->pll_select_offs);
}
if (div->lock)
spin_unlock(div->lock);
return 0;
}
static u8 berlin2_div_get_parent(struct clk_hw *hw)
{
struct berlin2_div *div = to_berlin2_div(hw);
struct berlin2_div_map *map = &div->map;
u32 reg;
u8 index = 0;
if (div->lock)
spin_lock(div->lock);
reg = readl_relaxed(div->base + map->pll_switch_offs);
reg &= BIT(map->pll_switch_shift);
if (reg) {
reg = readl_relaxed(div->base + map->pll_select_offs);
reg >>= map->pll_select_shift;
reg &= PLL_SELECT_MASK;
index = 1 + reg;
}
if (div->lock)
spin_unlock(div->lock);
return index;
}
static unsigned long berlin2_div_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct berlin2_div *div = to_berlin2_div(hw);
struct berlin2_div_map *map = &div->map;
u32 divsw, div3sw, divider = 1;
if (div->lock)
spin_lock(div->lock);
divsw = readl_relaxed(div->base + map->div_switch_offs) &
(1 << map->div_switch_shift);
div3sw = readl_relaxed(div->base + map->div3_switch_offs) &
(1 << map->div3_switch_shift);
if (div3sw != 0) {
divider = 3;
} else if (divsw == 0) {
divider = 1;
} else {
u32 reg;
reg = readl_relaxed(div->base + map->div_select_offs);
reg >>= map->div_select_shift;
reg &= DIV_SELECT_MASK;
divider = clk_div[reg];
}
if (div->lock)
spin_unlock(div->lock);
return parent_rate / divider;
}
struct clk_hw * __init
berlin2_div_register(const struct berlin2_div_map *map,
void __iomem *base, const char *name, u8 div_flags,
const char **parent_names, int num_parents,
unsigned long flags, spinlock_t *lock)
{
const struct clk_ops *mux_ops = &berlin2_div_mux_ops;
const struct clk_ops *rate_ops = &berlin2_div_rate_ops;
const struct clk_ops *gate_ops = &berlin2_div_gate_ops;
struct berlin2_div *div;
div = kzalloc(sizeof(*div), GFP_KERNEL);
if (!div)
return ERR_PTR(-ENOMEM);
memcpy(&div->map, map, sizeof(*map));
div->base = base;
div->lock = lock;
if ((div_flags & BERLIN2_DIV_HAS_GATE) == 0)
gate_ops = NULL;
if ((div_flags & BERLIN2_DIV_HAS_MUX) == 0)
mux_ops = NULL;
return clk_hw_register_composite(NULL, name, parent_names, num_parents,
&div->hw, mux_ops, &div->hw, rate_ops,
&div->hw, gate_ops, flags);
}
