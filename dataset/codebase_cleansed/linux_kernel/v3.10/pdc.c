static int __init pdc_probe(struct platform_device *pdev)
{
struct clk *pclk, *hclk;
pclk = clk_get(&pdev->dev, "pclk");
if (IS_ERR(pclk)) {
dev_err(&pdev->dev, "no pclk defined\n");
return PTR_ERR(pclk);
}
hclk = clk_get(&pdev->dev, "hclk");
if (IS_ERR(hclk)) {
dev_err(&pdev->dev, "no hclk defined\n");
clk_put(pclk);
return PTR_ERR(hclk);
}
clk_enable(pclk);
clk_enable(hclk);
dev_info(&pdev->dev, "Atmel Peripheral DMA Controller enabled\n");
return 0;
}
static int __init pdc_init(void)
{
return platform_driver_probe(&pdc_driver, pdc_probe);
}
