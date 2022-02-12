static int tegra20_pinctrl_probe(struct platform_device *pdev)
{
return tegra_pinctrl_probe(pdev, &tegra20_pinctrl);
}
