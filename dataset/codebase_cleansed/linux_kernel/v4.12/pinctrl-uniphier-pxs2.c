static int uniphier_pxs2_pinctrl_probe(struct platform_device *pdev)
{
return uniphier_pinctrl_probe(pdev, &uniphier_pxs2_pindata);
}
