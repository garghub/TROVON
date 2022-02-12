static int ph1_sld8_pinctrl_probe(struct platform_device *pdev)
{
return uniphier_pinctrl_probe(pdev, &ph1_sld8_pinctrl_desc,
&ph1_sld8_pindata);
}
