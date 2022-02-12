static int max77802_clk_probe(struct platform_device *pdev)
{
struct max77686_dev *iodev = dev_get_drvdata(pdev->dev.parent);
int ret;
ret = max_gen_clk_probe(pdev, iodev->regmap, MAX77802_REG_32KHZ,
max77802_clks_init, MAX77802_CLKS_NUM);
if (ret) {
dev_err(&pdev->dev, "generic probe failed %d\n", ret);
return ret;
}
ret = regmap_update_bits(iodev->regmap, MAX77802_REG_32KHZ,
1 << MAX77802_CLOCK_LOW_JITTER_SHIFT,
1 << MAX77802_CLOCK_LOW_JITTER_SHIFT);
if (ret < 0)
dev_err(&pdev->dev, "failed to enable low-jitter mode\n");
return ret;
}
static int max77802_clk_remove(struct platform_device *pdev)
{
return max_gen_clk_remove(pdev, MAX77802_CLKS_NUM);
}
