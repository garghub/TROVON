static int atmel_ramc_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
const struct at91_ramc_caps *caps;
struct clk *clk;
match = of_match_device(atmel_ramc_of_match, &pdev->dev);
caps = match->data;
if (caps->has_ddrck) {
clk = devm_clk_get(&pdev->dev, "ddrck");
if (IS_ERR(clk))
return PTR_ERR(clk);
clk_prepare_enable(clk);
}
if (caps->has_mpddr_clk) {
clk = devm_clk_get(&pdev->dev, "mpddr");
if (IS_ERR(clk)) {
pr_err("AT91 RAMC: couldn't get mpddr clock\n");
return PTR_ERR(clk);
}
clk_prepare_enable(clk);
}
return 0;
}
static int __init atmel_ramc_init(void)
{
return platform_driver_register(&atmel_ramc_driver);
}
