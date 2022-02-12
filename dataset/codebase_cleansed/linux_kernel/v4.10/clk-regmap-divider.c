static inline struct clk_regmap_div *to_clk_regmap_div(struct clk_hw *hw)
{
return container_of(to_clk_regmap(hw), struct clk_regmap_div, clkr);
}
static long div_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct clk_regmap_div *divider = to_clk_regmap_div(hw);
return divider_round_rate(hw, rate, prate, NULL, divider->width,
CLK_DIVIDER_ROUND_CLOSEST);
}
static int div_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_regmap_div *divider = to_clk_regmap_div(hw);
struct clk_regmap *clkr = &divider->clkr;
u32 div;
div = divider_get_val(rate, parent_rate, NULL, divider->width,
CLK_DIVIDER_ROUND_CLOSEST);
return regmap_update_bits(clkr->regmap, divider->reg,
(BIT(divider->width) - 1) << divider->shift,
div << divider->shift);
}
static unsigned long div_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_regmap_div *divider = to_clk_regmap_div(hw);
struct clk_regmap *clkr = &divider->clkr;
u32 div;
regmap_read(clkr->regmap, divider->reg, &div);
div >>= divider->shift;
div &= BIT(divider->width) - 1;
return divider_recalc_rate(hw, parent_rate, div, NULL,
CLK_DIVIDER_ROUND_CLOSEST);
}
