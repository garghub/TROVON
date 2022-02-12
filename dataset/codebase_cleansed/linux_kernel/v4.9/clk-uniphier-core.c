static struct clk_hw *uniphier_clk_register(struct device *dev,
struct regmap *regmap,
const struct uniphier_clk_data *data)
{
switch (data->type) {
case UNIPHIER_CLK_TYPE_FIXED_FACTOR:
return uniphier_clk_register_fixed_factor(dev, data->name,
&data->data.factor);
case UNIPHIER_CLK_TYPE_FIXED_RATE:
return uniphier_clk_register_fixed_rate(dev, data->name,
&data->data.rate);
case UNIPHIER_CLK_TYPE_GATE:
return uniphier_clk_register_gate(dev, regmap, data->name,
&data->data.gate);
case UNIPHIER_CLK_TYPE_MUX:
return uniphier_clk_register_mux(dev, regmap, data->name,
&data->data.mux);
default:
dev_err(dev, "unsupported clock type\n");
return ERR_PTR(-EINVAL);
}
}
static int uniphier_clk_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct clk_hw_onecell_data *hw_data;
const struct uniphier_clk_data *p, *data;
struct regmap *regmap;
struct device_node *parent;
int clk_num = 0;
data = of_device_get_match_data(dev);
if (WARN_ON(!data))
return -EINVAL;
parent = of_get_parent(dev->of_node);
regmap = syscon_node_to_regmap(parent);
of_node_put(parent);
if (IS_ERR(regmap)) {
dev_err(dev, "failed to get regmap (error %ld)\n",
PTR_ERR(regmap));
return PTR_ERR(regmap);
}
for (p = data; p->name; p++)
clk_num = max(clk_num, p->idx + 1);
hw_data = devm_kzalloc(dev,
sizeof(*hw_data) + clk_num * sizeof(struct clk_hw *),
GFP_KERNEL);
if (!hw_data)
return -ENOMEM;
hw_data->num = clk_num;
while (--clk_num >= 0)
hw_data->hws[clk_num] = ERR_PTR(-EINVAL);
for (p = data; p->name; p++) {
struct clk_hw *hw;
dev_dbg(dev, "register %s (index=%d)\n", p->name, p->idx);
hw = uniphier_clk_register(dev, regmap, p);
if (IS_ERR(hw)) {
dev_err(dev, "failed to register %s (error %ld)\n",
p->name, PTR_ERR(hw));
return PTR_ERR(hw);
}
if (p->idx >= 0)
hw_data->hws[p->idx] = hw;
}
return of_clk_add_hw_provider(dev->of_node, of_clk_hw_onecell_get,
hw_data);
}
static int uniphier_clk_remove(struct platform_device *pdev)
{
of_clk_del_provider(pdev->dev.of_node);
return 0;
}
