static int twl6040_bitclk_is_enabled(struct clk_hw *hw)
{
struct twl6040_clk *twl6040_clk = container_of(hw, struct twl6040_clk,
mcpdm_fclk);
return twl6040_clk->enabled;
}
static int twl6040_bitclk_prepare(struct clk_hw *hw)
{
struct twl6040_clk *twl6040_clk = container_of(hw, struct twl6040_clk,
mcpdm_fclk);
int ret;
ret = twl6040_power(twl6040_clk->twl6040, 1);
if (!ret)
twl6040_clk->enabled = 1;
return ret;
}
static void twl6040_bitclk_unprepare(struct clk_hw *hw)
{
struct twl6040_clk *twl6040_clk = container_of(hw, struct twl6040_clk,
mcpdm_fclk);
int ret;
ret = twl6040_power(twl6040_clk->twl6040, 0);
if (!ret)
twl6040_clk->enabled = 0;
}
static int twl6040_clk_probe(struct platform_device *pdev)
{
struct twl6040 *twl6040 = dev_get_drvdata(pdev->dev.parent);
struct twl6040_clk *clkdata;
clkdata = devm_kzalloc(&pdev->dev, sizeof(*clkdata), GFP_KERNEL);
if (!clkdata)
return -ENOMEM;
clkdata->dev = &pdev->dev;
clkdata->twl6040 = twl6040;
clkdata->mcpdm_fclk.init = &wm831x_clkout_init;
clkdata->clk = clk_register(&pdev->dev, &clkdata->mcpdm_fclk);
if (IS_ERR(clkdata->clk))
return PTR_ERR(clkdata->clk);
platform_set_drvdata(pdev, clkdata);
return 0;
}
static int twl6040_clk_remove(struct platform_device *pdev)
{
struct twl6040_clk *clkdata = platform_get_drvdata(pdev);
clk_unregister(clkdata->clk);
return 0;
}
