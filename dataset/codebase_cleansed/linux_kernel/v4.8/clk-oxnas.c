static inline struct clk_oxnas *to_clk_oxnas(struct clk_hw *hw)
{
return container_of(hw, struct clk_oxnas, hw);
}
static int oxnas_clk_is_enabled(struct clk_hw *hw)
{
struct clk_oxnas *std = to_clk_oxnas(hw);
int ret;
unsigned int val;
ret = regmap_read(std->regmap, CLK_STAT_REGOFFSET, &val);
if (ret < 0)
return ret;
return val & BIT(std->bit);
}
static int oxnas_clk_enable(struct clk_hw *hw)
{
struct clk_oxnas *std = to_clk_oxnas(hw);
regmap_write(std->regmap, CLK_SET_REGOFFSET, BIT(std->bit));
return 0;
}
static void oxnas_clk_disable(struct clk_hw *hw)
{
struct clk_oxnas *std = to_clk_oxnas(hw);
regmap_write(std->regmap, CLK_CLR_REGOFFSET, BIT(std->bit));
}
static int oxnas_stdclk_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct clk_oxnas_data *clk_oxnas;
struct regmap *regmap;
int i;
clk_oxnas = devm_kzalloc(&pdev->dev, sizeof(*clk_oxnas), GFP_KERNEL);
if (!clk_oxnas)
return -ENOMEM;
regmap = syscon_node_to_regmap(of_get_parent(np));
if (IS_ERR(regmap)) {
dev_err(&pdev->dev, "failed to have parent regmap\n");
return PTR_ERR(regmap);
}
for (i = 0; i < ARRAY_SIZE(clk_oxnas_init); i++) {
struct clk_oxnas *_clk;
_clk = &clk_oxnas->clk_oxnas[i];
_clk->bit = clk_oxnas_init[i].bit;
_clk->hw.init = clk_oxnas_init[i].clk_init;
_clk->regmap = regmap;
clk_oxnas->clks[i] =
devm_clk_register(&pdev->dev, &_clk->hw);
if (WARN_ON(IS_ERR(clk_oxnas->clks[i])))
return PTR_ERR(clk_oxnas->clks[i]);
}
clk_oxnas->onecell_data->clks = clk_oxnas->clks;
clk_oxnas->onecell_data->clk_num = ARRAY_SIZE(clk_oxnas_init);
return of_clk_add_provider(np, of_clk_src_onecell_get,
clk_oxnas->onecell_data);
}
