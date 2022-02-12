static int lpt_clk_probe(struct platform_device *pdev)
{
struct lpss_clk_data *drvdata;
struct clk *clk;
drvdata = devm_kzalloc(&pdev->dev, sizeof(*drvdata), GFP_KERNEL);
if (!drvdata)
return -ENOMEM;
drvdata->name = "lpss_clk";
clk = clk_register_fixed_rate(&pdev->dev, drvdata->name, NULL,
CLK_IS_ROOT, 100000000);
if (IS_ERR(clk))
return PTR_ERR(clk);
drvdata->clk = clk;
platform_set_drvdata(pdev, drvdata);
return 0;
}
int __init lpt_clk_init(void)
{
return platform_driver_register(&lpt_clk_driver);
}
