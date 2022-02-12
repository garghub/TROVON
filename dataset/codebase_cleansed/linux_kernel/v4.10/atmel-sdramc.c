static int atmel_ramc_probe(struct platform_device *pdev)
{
const struct at91_ramc_caps *caps;
struct clk *clk;
caps = of_device_get_match_data(&pdev->dev);
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
