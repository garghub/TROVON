static int uniphier_pro4_pinctrl_probe(struct platform_device *pdev)
{
return uniphier_pinctrl_probe(pdev, &uniphier_pro4_pindata);
}
