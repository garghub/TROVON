static int ph1_ld4_pinctrl_probe(struct platform_device *pdev)
{
return uniphier_pinctrl_probe(pdev, &ph1_ld4_pinctrl_desc,
&ph1_ld4_pindata);
}
