static int proxstream2_pinctrl_probe(struct platform_device *pdev)
{
return uniphier_pinctrl_probe(pdev, &proxstream2_pinctrl_desc,
&proxstream2_pindata);
}
