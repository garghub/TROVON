static inline struct clk_oxnas_gate *to_clk_oxnas_gate(struct clk_hw *hw)
{
return container_of(hw, struct clk_oxnas_gate, hw);
}
static int oxnas_clk_gate_is_enabled(struct clk_hw *hw)
{
struct clk_oxnas_gate *std = to_clk_oxnas_gate(hw);
int ret;
unsigned int val;
ret = regmap_read(std->regmap, CLK_STAT_REGOFFSET, &val);
if (ret < 0)
return ret;
return val & BIT(std->bit);
}
static int oxnas_clk_gate_enable(struct clk_hw *hw)
{
struct clk_oxnas_gate *std = to_clk_oxnas_gate(hw);
regmap_write(std->regmap, CLK_SET_REGOFFSET, BIT(std->bit));
return 0;
}
static void oxnas_clk_gate_disable(struct clk_hw *hw)
{
struct clk_oxnas_gate *std = to_clk_oxnas_gate(hw);
regmap_write(std->regmap, CLK_CLR_REGOFFSET, BIT(std->bit));
}
static int oxnas_stdclk_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
const struct oxnas_stdclk_data *data;
const struct of_device_id *id;
struct regmap *regmap;
int ret;
int i;
id = of_match_device(oxnas_stdclk_dt_ids, &pdev->dev);
if (!id)
return -ENODEV;
data = id->data;
regmap = syscon_node_to_regmap(of_get_parent(np));
if (IS_ERR(regmap)) {
dev_err(&pdev->dev, "failed to have parent regmap\n");
return PTR_ERR(regmap);
}
for (i = 0 ; i < data->ngates ; ++i)
data->gates[i]->regmap = regmap;
for (i = 0; i < data->onecell_data->num; i++) {
if (!data->onecell_data->hws[i])
continue;
ret = devm_clk_hw_register(&pdev->dev,
data->onecell_data->hws[i]);
if (ret)
return ret;
}
return of_clk_add_hw_provider(np, of_clk_hw_onecell_get,
data->onecell_data);
}
