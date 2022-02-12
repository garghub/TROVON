static int __devinit tegra30_pinctrl_probe(struct platform_device *pdev)
{
return tegra_pinctrl_probe(pdev, &tegra30_pinctrl);
}
static int __init tegra30_pinctrl_init(void)
{
return platform_driver_register(&tegra30_pinctrl_driver);
}
static void __exit tegra30_pinctrl_exit(void)
{
platform_driver_unregister(&tegra30_pinctrl_driver);
}
