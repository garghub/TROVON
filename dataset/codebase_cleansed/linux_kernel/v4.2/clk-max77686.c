static int max77686_clk_probe(struct platform_device *pdev)
{
struct max77686_dev *iodev = dev_get_drvdata(pdev->dev.parent);
return max_gen_clk_probe(pdev, iodev->regmap, MAX77686_REG_32KHZ,
max77686_clks_init, MAX77686_CLKS_NUM);
}
static int max77686_clk_remove(struct platform_device *pdev)
{
return max_gen_clk_remove(pdev, MAX77686_CLKS_NUM);
}
