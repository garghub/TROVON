static unsigned long
berlin2_pll_recalc_rate(struct clk_hw *hw, unsigned long parent_rate)
{
struct berlin2_pll *pll = to_berlin2_pll(hw);
struct berlin2_pll_map *map = &pll->map;
u32 val, fbdiv, rfdiv, vcodivsel, vcodiv;
u64 rate = parent_rate;
val = readl_relaxed(pll->base + SPLL_CTRL0);
fbdiv = (val >> map->fbdiv_shift) & FBDIV_MASK;
rfdiv = (val >> map->rfdiv_shift) & RFDIV_MASK;
if (rfdiv == 0) {
pr_warn("%s has zero rfdiv\n", clk_hw_get_name(hw));
rfdiv = 1;
}
val = readl_relaxed(pll->base + SPLL_CTRL1);
vcodivsel = (val >> map->divsel_shift) & DIVSEL_MASK;
vcodiv = map->vcodiv[vcodivsel];
if (vcodiv == 0) {
pr_warn("%s has zero vcodiv (index %d)\n",
clk_hw_get_name(hw), vcodivsel);
vcodiv = 1;
}
rate *= fbdiv * map->mult;
do_div(rate, rfdiv * vcodiv);
return (unsigned long)rate;
}
int __init
berlin2_pll_register(const struct berlin2_pll_map *map,
void __iomem *base, const char *name,
const char *parent_name, unsigned long flags)
{
struct clk_init_data init;
struct berlin2_pll *pll;
pll = kzalloc(sizeof(*pll), GFP_KERNEL);
if (!pll)
return -ENOMEM;
memcpy(&pll->map, map, sizeof(*map));
pll->base = base;
pll->hw.init = &init;
init.name = name;
init.ops = &berlin2_pll_ops;
init.parent_names = &parent_name;
init.num_parents = 1;
init.flags = flags;
return clk_hw_register(NULL, &pll->hw);
}
