static inline struct clk_regmap_mux *to_clk_regmap_mux(struct clk_hw *hw)
{
return container_of(to_clk_regmap(hw), struct clk_regmap_mux, clkr);
}
static u8 mux_get_parent(struct clk_hw *hw)
{
struct clk_regmap_mux *mux = to_clk_regmap_mux(hw);
struct clk_regmap *clkr = to_clk_regmap(hw);
unsigned int mask = GENMASK(mux->width - 1, 0);
unsigned int val;
regmap_read(clkr->regmap, mux->reg, &val);
val >>= mux->shift;
val &= mask;
return val;
}
static int mux_set_parent(struct clk_hw *hw, u8 index)
{
struct clk_regmap_mux *mux = to_clk_regmap_mux(hw);
struct clk_regmap *clkr = to_clk_regmap(hw);
unsigned int mask = GENMASK(mux->width + mux->shift - 1, mux->shift);
unsigned int val;
val = index;
val <<= mux->shift;
return regmap_update_bits(clkr->regmap, mux->reg, mask, val);
}
