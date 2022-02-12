static unsigned long rk808_clkout_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return 32768;
}
static int rk808_clkout2_enable(struct clk_hw *hw, bool enable)
{
struct rk808_clkout *rk808_clkout = container_of(hw,
struct rk808_clkout,
clkout2_hw);
struct rk808 *rk808 = rk808_clkout->rk808;
return regmap_update_bits(rk808->regmap, RK808_CLK32OUT_REG,
CLK32KOUT2_EN, enable ? CLK32KOUT2_EN : 0);
}
static int rk808_clkout2_prepare(struct clk_hw *hw)
{
return rk808_clkout2_enable(hw, true);
}
static void rk808_clkout2_unprepare(struct clk_hw *hw)
{
rk808_clkout2_enable(hw, false);
}
static int rk808_clkout2_is_prepared(struct clk_hw *hw)
{
struct rk808_clkout *rk808_clkout = container_of(hw,
struct rk808_clkout,
clkout2_hw);
struct rk808 *rk808 = rk808_clkout->rk808;
uint32_t val;
int ret = regmap_read(rk808->regmap, RK808_CLK32OUT_REG, &val);
if (ret < 0)
return ret;
return (val & CLK32KOUT2_EN) ? 1 : 0;
}
static struct clk_hw *
of_clk_rk808_get(struct of_phandle_args *clkspec, void *data)
{
struct rk808_clkout *rk808_clkout = data;
unsigned int idx = clkspec->args[0];
if (idx >= 2) {
pr_err("%s: invalid index %u\n", __func__, idx);
return ERR_PTR(-EINVAL);
}
return idx ? &rk808_clkout->clkout2_hw : &rk808_clkout->clkout1_hw;
}
static int rk808_clkout_probe(struct platform_device *pdev)
{
struct rk808 *rk808 = dev_get_drvdata(pdev->dev.parent);
struct i2c_client *client = rk808->i2c;
struct device_node *node = client->dev.of_node;
struct clk_init_data init = {};
struct rk808_clkout *rk808_clkout;
int ret;
rk808_clkout = devm_kzalloc(&client->dev,
sizeof(*rk808_clkout), GFP_KERNEL);
if (!rk808_clkout)
return -ENOMEM;
rk808_clkout->rk808 = rk808;
init.parent_names = NULL;
init.num_parents = 0;
init.name = "rk808-clkout1";
init.ops = &rk808_clkout1_ops;
rk808_clkout->clkout1_hw.init = &init;
of_property_read_string_index(node, "clock-output-names",
0, &init.name);
ret = devm_clk_hw_register(&client->dev, &rk808_clkout->clkout1_hw);
if (ret)
return ret;
init.name = "rk808-clkout2";
init.ops = &rk808_clkout2_ops;
rk808_clkout->clkout2_hw.init = &init;
of_property_read_string_index(node, "clock-output-names",
1, &init.name);
ret = devm_clk_hw_register(&client->dev, &rk808_clkout->clkout2_hw);
if (ret)
return ret;
return of_clk_add_hw_provider(node, of_clk_rk808_get, rk808_clkout);
}
static int rk808_clkout_remove(struct platform_device *pdev)
{
struct rk808 *rk808 = dev_get_drvdata(pdev->dev.parent);
struct i2c_client *client = rk808->i2c;
struct device_node *node = client->dev.of_node;
of_clk_del_provider(node);
return 0;
}
