static int uniphier_ld20_pinctrl_probe(struct platform_device *pdev)
{
return uniphier_pinctrl_probe(pdev, &uniphier_ld20_pindata);
}
