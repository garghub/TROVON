static inline unsigned long clkc_readl(unsigned reg)
{
return readl(sirfsoc_clk_vbase + reg);
}
static inline void clkc_writel(u32 val, unsigned reg)
{
writel(val, sirfsoc_clk_vbase + reg);
}
static unsigned long pll_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned long fin = parent_rate;
struct clk_pll *clk = to_pllclk(hw);
u64 rate;
u32 regctrl0 = clkc_readl(clk->regofs + SIRFSOC_CLKC_MEMPLL_AB_CTRL0 -
SIRFSOC_CLKC_MEMPLL_AB_FREQ);
u32 regfreq = clkc_readl(clk->regofs);
u32 regssc = clkc_readl(clk->regofs + SIRFSOC_CLKC_MEMPLL_AB_SSC -
SIRFSOC_CLKC_MEMPLL_AB_FREQ);
u32 nr = (regfreq >> 16 & (BIT(3) - 1)) + 1;
u32 nf = (regfreq & (BIT(9) - 1)) + 1;
u32 ssdiv = regssc >> 8 & (BIT(12) - 1);
u32 ssdepth = regssc >> 20 & (BIT(2) - 1);
u32 ssmod = regssc & (BIT(8) - 1);
if (regctrl0 & SIRFSOC_ABPLL_CTRL0_BYPASS)
return fin;
if (regctrl0 & SIRFSOC_ABPLL_CTRL0_SSEN) {
rate = fin;
rate *= 1 << 24;
do_div(rate, nr);
do_div(rate, (256 * ((ssdiv >> ssdepth) << ssdepth)
+ (ssmod << ssdepth)));
} else {
rate = 2 * fin;
rate *= nf;
do_div(rate, nr);
}
return rate;
}
static int dto_clk_is_enabled(struct clk_hw *hw)
{
struct clk_dto *clk = to_dtoclk(hw);
int reg;
reg = clk->src_offset + SIRFSOC_CLKC_AUDIO_DTO_ENA - SIRFSOC_CLKC_AUDIO_DTO_SRC;
return !!(clkc_readl(reg) & BIT(0));
}
static int dto_clk_enable(struct clk_hw *hw)
{
u32 val, reg;
struct clk_dto *clk = to_dtoclk(hw);
reg = clk->src_offset + SIRFSOC_CLKC_AUDIO_DTO_ENA - SIRFSOC_CLKC_AUDIO_DTO_SRC;
val = clkc_readl(reg) | BIT(0);
clkc_writel(val, reg);
return 0;
}
static void dto_clk_disable(struct clk_hw *hw)
{
u32 val, reg;
struct clk_dto *clk = to_dtoclk(hw);
reg = clk->src_offset + SIRFSOC_CLKC_AUDIO_DTO_ENA - SIRFSOC_CLKC_AUDIO_DTO_SRC;
val = clkc_readl(reg) & ~BIT(0);
clkc_writel(val, reg);
}
static unsigned long dto_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
u64 rate = parent_rate;
struct clk_dto *clk = to_dtoclk(hw);
u32 finc = clkc_readl(clk->inc_offset);
u32 droff = clkc_readl(clk->src_offset + SIRFSOC_CLKC_AUDIO_DTO_DROFF - SIRFSOC_CLKC_AUDIO_DTO_SRC);
rate *= finc;
if (droff & BIT(0))
do_div(rate, DTO_RESL_NORMAL);
else
do_div(rate, DTO_RESL_DOUBLE);
return rate;
}
static long dto_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
u64 dividend = rate * DTO_RESL_DOUBLE;
do_div(dividend, *parent_rate);
dividend *= *parent_rate;
do_div(dividend, DTO_RESL_DOUBLE);
return dividend;
}
static int dto_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
u64 dividend = rate * DTO_RESL_DOUBLE;
struct clk_dto *clk = to_dtoclk(hw);
do_div(dividend, parent_rate);
clkc_writel(0, clk->src_offset + SIRFSOC_CLKC_AUDIO_DTO_DROFF - SIRFSOC_CLKC_AUDIO_DTO_SRC);
clkc_writel(dividend, clk->inc_offset);
return 0;
}
static u8 dto_clk_get_parent(struct clk_hw *hw)
{
struct clk_dto *clk = to_dtoclk(hw);
return clkc_readl(clk->src_offset);
}
static int dto_clk_set_parent(struct clk_hw *hw, u8 index)
{
struct clk_dto *clk = to_dtoclk(hw);
clkc_writel(index, clk->src_offset);
return 0;
}
static int unit_clk_is_enabled(struct clk_hw *hw)
{
struct clk_unit *clk = to_unitclk(hw);
u32 reg;
reg = clk->regofs + SIRFSOC_CLKC_ROOT_CLK_EN0_STAT - SIRFSOC_CLKC_ROOT_CLK_EN0_SET;
return !!(clkc_readl(reg) & BIT(clk->bit));
}
static int unit_clk_enable(struct clk_hw *hw)
{
u32 reg;
struct clk_unit *clk = to_unitclk(hw);
unsigned long flags;
reg = clk->regofs;
spin_lock_irqsave(clk->lock, flags);
clkc_writel(BIT(clk->bit), reg);
spin_unlock_irqrestore(clk->lock, flags);
return 0;
}
static void unit_clk_disable(struct clk_hw *hw)
{
u32 reg;
struct clk_unit *clk = to_unitclk(hw);
unsigned long flags;
reg = clk->regofs + SIRFSOC_CLKC_ROOT_CLK_EN0_CLR - SIRFSOC_CLKC_ROOT_CLK_EN0_SET;
spin_lock_irqsave(clk->lock, flags);
clkc_writel(BIT(clk->bit), reg);
spin_unlock_irqrestore(clk->lock, flags);
}
static struct clk * __init
atlas7_unit_clk_register(struct device *dev, const char *name,
const char * const parent_name, unsigned long flags,
u32 regofs, u8 bit, spinlock_t *lock)
{
struct clk *clk;
struct clk_unit *unit;
struct clk_init_data init;
unit = kzalloc(sizeof(*unit), GFP_KERNEL);
if (!unit)
return ERR_PTR(-ENOMEM);
init.name = name;
init.parent_names = &parent_name;
init.num_parents = 1;
init.ops = &unit_clk_ops;
init.flags = flags;
unit->hw.init = &init;
unit->regofs = regofs;
unit->bit = bit;
unit->lock = lock;
clk = clk_register(dev, &unit->hw);
if (IS_ERR(clk))
kfree(unit);
return clk;
}
static int atlas7_reset_module(struct reset_controller_dev *rcdev,
unsigned long reset_idx)
{
struct atlas7_reset_desc *reset = &atlas7_reset_unit[reset_idx];
unsigned long flags;
spin_lock_irqsave(reset->lock, flags);
if (clkc_readl(reset->clk_ofs + 8) & (1 << reset->clk_bit)) {
clkc_writel(1 << reset->rst_bit, reset->rst_ofs + 4);
udelay(2);
clkc_writel(1 << reset->clk_bit, reset->clk_ofs + 4);
clkc_writel(1 << reset->rst_bit, reset->rst_ofs);
clkc_writel(1 << reset->clk_bit, reset->clk_ofs);
} else {
clkc_writel(1 << reset->rst_bit, reset->rst_ofs + 4);
clkc_writel(1 << reset->clk_bit, reset->clk_ofs);
udelay(2);
clkc_writel(1 << reset->clk_bit, reset->clk_ofs + 4);
clkc_writel(1 << reset->rst_bit, reset->rst_ofs);
}
spin_unlock_irqrestore(reset->lock, flags);
return 0;
}
static void __init atlas7_clk_init(struct device_node *np)
{
struct clk *clk;
struct atlas7_div_init_data *div;
struct atlas7_mux_init_data *mux;
struct atlas7_unit_init_data *unit;
int i;
int ret;
sirfsoc_clk_vbase = of_iomap(np, 0);
if (!sirfsoc_clk_vbase)
panic("unable to map clkc registers\n");
of_node_put(np);
clk = clk_register(NULL, &clk_cpupll.hw);
BUG_ON(!clk);
clk = clk_register(NULL, &clk_mempll.hw);
BUG_ON(!clk);
clk = clk_register(NULL, &clk_sys0pll.hw);
BUG_ON(!clk);
clk = clk_register(NULL, &clk_sys1pll.hw);
BUG_ON(!clk);
clk = clk_register(NULL, &clk_sys2pll.hw);
BUG_ON(!clk);
clk = clk_register(NULL, &clk_sys3pll.hw);
BUG_ON(!clk);
clk = clk_register_divider_table(NULL, "cpupll_div1", "cpupll_vco", 0,
sirfsoc_clk_vbase + SIRFSOC_CLKC_CPUPLL_AB_CTRL1, 0, 3, 0,
pll_div_table, &cpupll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_divider_table(NULL, "cpupll_div2", "cpupll_vco", 0,
sirfsoc_clk_vbase + SIRFSOC_CLKC_CPUPLL_AB_CTRL1, 4, 3, 0,
pll_div_table, &cpupll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_divider_table(NULL, "cpupll_div3", "cpupll_vco", 0,
sirfsoc_clk_vbase + SIRFSOC_CLKC_CPUPLL_AB_CTRL1, 8, 3, 0,
pll_div_table, &cpupll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_divider_table(NULL, "mempll_div1", "mempll_vco", 0,
sirfsoc_clk_vbase + SIRFSOC_CLKC_MEMPLL_AB_CTRL1, 0, 3, 0,
pll_div_table, &mempll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_divider_table(NULL, "mempll_div2", "mempll_vco", 0,
sirfsoc_clk_vbase + SIRFSOC_CLKC_MEMPLL_AB_CTRL1, 4, 3, 0,
pll_div_table, &mempll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_divider_table(NULL, "mempll_div3", "mempll_vco", 0,
sirfsoc_clk_vbase + SIRFSOC_CLKC_MEMPLL_AB_CTRL1, 8, 3, 0,
pll_div_table, &mempll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_divider_table(NULL, "sys0pll_div1", "sys0pll_vco", 0,
sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS0PLL_AB_CTRL1, 0, 3, 0,
pll_div_table, &sys0pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_divider_table(NULL, "sys0pll_div2", "sys0pll_vco", 0,
sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS0PLL_AB_CTRL1, 4, 3, 0,
pll_div_table, &sys0pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_divider_table(NULL, "sys0pll_div3", "sys0pll_vco", 0,
sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS0PLL_AB_CTRL1, 8, 3, 0,
pll_div_table, &sys0pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_fixed_factor(NULL, "sys0pll_fixdiv", "sys0pll_vco",
CLK_SET_RATE_PARENT, 1, 2);
clk = clk_register_divider_table(NULL, "sys1pll_div1", "sys1pll_vco", 0,
sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS1PLL_AB_CTRL1, 0, 3, 0,
pll_div_table, &sys1pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_divider_table(NULL, "sys1pll_div2", "sys1pll_vco", 0,
sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS1PLL_AB_CTRL1, 4, 3, 0,
pll_div_table, &sys1pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_divider_table(NULL, "sys1pll_div3", "sys1pll_vco", 0,
sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS1PLL_AB_CTRL1, 8, 3, 0,
pll_div_table, &sys1pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_fixed_factor(NULL, "sys1pll_fixdiv", "sys1pll_vco",
CLK_SET_RATE_PARENT, 1, 2);
clk = clk_register_divider_table(NULL, "sys2pll_div1", "sys2pll_vco", 0,
sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS2PLL_AB_CTRL1, 0, 3, 0,
pll_div_table, &sys2pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_divider_table(NULL, "sys2pll_div2", "sys2pll_vco", 0,
sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS2PLL_AB_CTRL1, 4, 3, 0,
pll_div_table, &sys2pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_divider_table(NULL, "sys2pll_div3", "sys2pll_vco", 0,
sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS2PLL_AB_CTRL1, 8, 3, 0,
pll_div_table, &sys2pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_fixed_factor(NULL, "sys2pll_fixdiv", "sys2pll_vco",
CLK_SET_RATE_PARENT, 1, 2);
clk = clk_register_divider_table(NULL, "sys3pll_div1", "sys3pll_vco", 0,
sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS3PLL_AB_CTRL1, 0, 3, 0,
pll_div_table, &sys3pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_divider_table(NULL, "sys3pll_div2", "sys3pll_vco", 0,
sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS3PLL_AB_CTRL1, 4, 3, 0,
pll_div_table, &sys3pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_divider_table(NULL, "sys3pll_div3", "sys3pll_vco", 0,
sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS3PLL_AB_CTRL1, 8, 3, 0,
pll_div_table, &sys3pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_fixed_factor(NULL, "sys3pll_fixdiv", "sys3pll_vco",
CLK_SET_RATE_PARENT, 1, 2);
BUG_ON(!clk);
clk = clk_register_fixed_factor(NULL, "xinw_fixdiv_btslow", "xinw",
CLK_SET_RATE_PARENT, 1, 4);
BUG_ON(!clk);
clk = clk_register_gate(NULL, "cpupll_clk1", "cpupll_div1",
CLK_SET_RATE_PARENT, sirfsoc_clk_vbase + SIRFSOC_CLKC_CPUPLL_AB_CTRL1,
12, 0, &cpupll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_gate(NULL, "cpupll_clk2", "cpupll_div2",
CLK_SET_RATE_PARENT, sirfsoc_clk_vbase + SIRFSOC_CLKC_CPUPLL_AB_CTRL1,
13, 0, &cpupll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_gate(NULL, "cpupll_clk3", "cpupll_div3",
CLK_SET_RATE_PARENT, sirfsoc_clk_vbase + SIRFSOC_CLKC_CPUPLL_AB_CTRL1,
14, 0, &cpupll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_gate(NULL, "mempll_clk1", "mempll_div1",
CLK_SET_RATE_PARENT | CLK_IGNORE_UNUSED,
sirfsoc_clk_vbase + SIRFSOC_CLKC_MEMPLL_AB_CTRL1,
12, 0, &mempll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_gate(NULL, "mempll_clk2", "mempll_div2",
CLK_SET_RATE_PARENT, sirfsoc_clk_vbase + SIRFSOC_CLKC_MEMPLL_AB_CTRL1,
13, 0, &mempll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_gate(NULL, "mempll_clk3", "mempll_div3",
CLK_SET_RATE_PARENT, sirfsoc_clk_vbase + SIRFSOC_CLKC_MEMPLL_AB_CTRL1,
14, 0, &mempll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_gate(NULL, "sys0pll_clk1", "sys0pll_div1",
CLK_SET_RATE_PARENT, sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS0PLL_AB_CTRL1,
12, 0, &sys0pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_gate(NULL, "sys0pll_clk2", "sys0pll_div2",
CLK_SET_RATE_PARENT, sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS0PLL_AB_CTRL1,
13, 0, &sys0pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_gate(NULL, "sys0pll_clk3", "sys0pll_div3",
CLK_SET_RATE_PARENT, sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS0PLL_AB_CTRL1,
14, 0, &sys0pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_gate(NULL, "sys1pll_clk1", "sys1pll_div1",
CLK_SET_RATE_PARENT, sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS1PLL_AB_CTRL1,
12, 0, &sys1pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_gate(NULL, "sys1pll_clk2", "sys1pll_div2",
CLK_SET_RATE_PARENT, sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS1PLL_AB_CTRL1,
13, 0, &sys1pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_gate(NULL, "sys1pll_clk3", "sys1pll_div3",
CLK_SET_RATE_PARENT, sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS1PLL_AB_CTRL1,
14, 0, &sys1pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_gate(NULL, "sys2pll_clk1", "sys2pll_div1",
CLK_SET_RATE_PARENT, sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS2PLL_AB_CTRL1,
12, 0, &sys2pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_gate(NULL, "sys2pll_clk2", "sys2pll_div2",
CLK_SET_RATE_PARENT, sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS2PLL_AB_CTRL1,
13, 0, &sys2pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_gate(NULL, "sys2pll_clk3", "sys2pll_div3",
CLK_SET_RATE_PARENT, sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS2PLL_AB_CTRL1,
14, 0, &sys2pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_gate(NULL, "sys3pll_clk1", "sys3pll_div1",
CLK_SET_RATE_PARENT, sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS3PLL_AB_CTRL1,
12, 0, &sys3pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_gate(NULL, "sys3pll_clk2", "sys3pll_div2",
CLK_SET_RATE_PARENT, sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS3PLL_AB_CTRL1,
13, 0, &sys3pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register_gate(NULL, "sys3pll_clk3", "sys3pll_div3",
CLK_SET_RATE_PARENT, sirfsoc_clk_vbase + SIRFSOC_CLKC_SYS3PLL_AB_CTRL1,
14, 0, &sys3pll_ctrl1_lock);
BUG_ON(!clk);
clk = clk_register(NULL, &clk_audio_dto.hw);
BUG_ON(!clk);
clk = clk_register(NULL, &clk_disp0_dto.hw);
BUG_ON(!clk);
clk = clk_register(NULL, &clk_disp1_dto.hw);
BUG_ON(!clk);
for (i = 0; i < ARRAY_SIZE(divider_list); i++) {
div = &divider_list[i];
clk = clk_register_divider(NULL, div->div_name,
div->parent_name, div->divider_flags, sirfsoc_clk_vbase + div->div_offset,
div->shift, div->width, 0, div->lock);
BUG_ON(!clk);
clk = clk_register_gate(NULL, div->gate_name, div->div_name,
div->gate_flags, sirfsoc_clk_vbase + div->gate_offset,
div->gate_bit, 0, div->lock);
BUG_ON(!clk);
}
for (i = 0; i < ARRAY_SIZE(mux_list); i++) {
mux = &mux_list[i];
clk = clk_register_mux(NULL, mux->mux_name, mux->parent_names,
mux->parent_num, mux->flags,
sirfsoc_clk_vbase + mux->mux_offset,
mux->shift, mux->width,
mux->mux_flags, NULL);
atlas7_clks[ARRAY_SIZE(unit_list) + i] = clk;
BUG_ON(!clk);
}
for (i = 0; i < ARRAY_SIZE(unit_list); i++) {
unit = &unit_list[i];
atlas7_clks[i] = atlas7_unit_clk_register(NULL, unit->unit_name, unit->parent_name,
unit->flags, unit->regofs, unit->bit, unit->lock);
BUG_ON(!atlas7_clks[i]);
}
clk_data.clks = atlas7_clks;
clk_data.clk_num = ARRAY_SIZE(unit_list) + ARRAY_SIZE(mux_list);
ret = of_clk_add_provider(np, of_clk_src_onecell_get, &clk_data);
BUG_ON(ret);
atlas7_rst_ctlr.of_node = np;
atlas7_rst_ctlr.nr_resets = ARRAY_SIZE(atlas7_reset_unit);
reset_controller_register(&atlas7_rst_ctlr);
}
