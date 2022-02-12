static int mt6397_pinctrl_probe(struct platform_device *pdev)
{
struct mt6397_chip *mt6397;
mt6397 = dev_get_drvdata(pdev->dev.parent);
return mtk_pctrl_init(pdev, &mt6397_pinctrl_data, mt6397->regmap);
}
static int __init mtk_pinctrl_init(void)
{
return platform_driver_register(&mtk_pinctrl_driver);
}
