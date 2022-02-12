static int uniphier_clk_mux_set_parent(struct clk_hw *hw, u8 index)
{
struct uniphier_clk_mux *mux = to_uniphier_clk_mux(hw);
return regmap_write_bits(mux->regmap, mux->reg, mux->masks[index],
mux->vals[index]);
}
static u8 uniphier_clk_mux_get_parent(struct clk_hw *hw)
{
struct uniphier_clk_mux *mux = to_uniphier_clk_mux(hw);
int num_parents = clk_hw_get_num_parents(hw);
int ret;
unsigned int val;
u8 i;
ret = regmap_read(mux->regmap, mux->reg, &val);
if (ret)
return ret;
for (i = 0; i < num_parents; i++)
if ((mux->masks[i] & val) == mux->vals[i])
return i;
return -EINVAL;
}
struct clk_hw *uniphier_clk_register_mux(struct device *dev,
struct regmap *regmap,
const char *name,
const struct uniphier_clk_mux_data *data)
{
struct uniphier_clk_mux *mux;
struct clk_init_data init;
int ret;
mux = devm_kzalloc(dev, sizeof(*mux), GFP_KERNEL);
if (!mux)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &uniphier_clk_mux_ops;
init.flags = CLK_SET_RATE_PARENT;
init.parent_names = data->parent_names;
init.num_parents = data->num_parents,
mux->regmap = regmap;
mux->reg = data->reg;
mux->masks = data->masks;
mux->vals = data->vals;
mux->hw.init = &init;
ret = devm_clk_hw_register(dev, &mux->hw);
if (ret)
return ERR_PTR(ret);
return &mux->hw;
}
