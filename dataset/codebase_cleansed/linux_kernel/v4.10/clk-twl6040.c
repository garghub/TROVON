static int twl6040_pdmclk_is_prepared(struct clk_hw *hw)
{
struct twl6040_pdmclk *pdmclk = container_of(hw, struct twl6040_pdmclk,
pdmclk_hw);
return pdmclk->enabled;
}
static int twl6040_pdmclk_prepare(struct clk_hw *hw)
{
struct twl6040_pdmclk *pdmclk = container_of(hw, struct twl6040_pdmclk,
pdmclk_hw);
int ret;
ret = twl6040_power(pdmclk->twl6040, 1);
if (!ret)
pdmclk->enabled = 1;
return ret;
}
static void twl6040_pdmclk_unprepare(struct clk_hw *hw)
{
struct twl6040_pdmclk *pdmclk = container_of(hw, struct twl6040_pdmclk,
pdmclk_hw);
int ret;
ret = twl6040_power(pdmclk->twl6040, 0);
if (!ret)
pdmclk->enabled = 0;
}
static unsigned long twl6040_pdmclk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct twl6040_pdmclk *pdmclk = container_of(hw, struct twl6040_pdmclk,
pdmclk_hw);
return twl6040_get_sysclk(pdmclk->twl6040);
}
static int twl6040_pdmclk_probe(struct platform_device *pdev)
{
struct twl6040 *twl6040 = dev_get_drvdata(pdev->dev.parent);
struct twl6040_pdmclk *clkdata;
int ret;
clkdata = devm_kzalloc(&pdev->dev, sizeof(*clkdata), GFP_KERNEL);
if (!clkdata)
return -ENOMEM;
clkdata->dev = &pdev->dev;
clkdata->twl6040 = twl6040;
clkdata->pdmclk_hw.init = &twl6040_pdmclk_init;
ret = devm_clk_hw_register(&pdev->dev, &clkdata->pdmclk_hw);
if (ret)
return ret;
platform_set_drvdata(pdev, clkdata);
return of_clk_add_hw_provider(pdev->dev.parent->of_node,
of_clk_hw_simple_get,
&clkdata->pdmclk_hw);
}
