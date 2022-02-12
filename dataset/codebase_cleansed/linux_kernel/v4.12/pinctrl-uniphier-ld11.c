static int uniphier_ld11_pinctrl_probe(struct platform_device *pdev)
{
return uniphier_pinctrl_probe(pdev, &uniphier_ld11_pindata);
}
