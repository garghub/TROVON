static int ab8500_reg_clks(struct device *dev)
{
return 0;
}
static int ab8540_reg_clks(struct device *dev)
{
return 0;
}
static int ab9540_reg_clks(struct device *dev)
{
return 0;
}
static int abx500_clk_probe(struct platform_device *pdev)
{
struct ab8500 *parent = dev_get_drvdata(pdev->dev.parent);
int ret;
if (is_ab8500(parent) || is_ab8505(parent)) {
ret = ab8500_reg_clks(&pdev->dev);
} else if (is_ab8540(parent)) {
ret = ab8540_reg_clks(&pdev->dev);
} else if (is_ab9540(parent)) {
ret = ab9540_reg_clks(&pdev->dev);
} else {
dev_err(&pdev->dev, "non supported plf id\n");
return -ENODEV;
}
return ret;
}
static int __init abx500_clk_init(void)
{
return platform_driver_register(&abx500_clk_driver);
}
