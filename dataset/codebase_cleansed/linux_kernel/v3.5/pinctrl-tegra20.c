static int __devinit tegra20_pinctrl_probe(struct platform_device *pdev)
{
return tegra_pinctrl_probe(pdev, &tegra20_pinctrl);
}
static int __init tegra20_pinctrl_init(void)
{
return platform_driver_register(&tegra20_pinctrl_driver);
}
static void __exit tegra20_pinctrl_exit(void)
{
platform_driver_unregister(&tegra20_pinctrl_driver);
}
