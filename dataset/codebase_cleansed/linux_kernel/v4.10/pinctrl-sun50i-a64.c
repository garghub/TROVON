static int a64_pinctrl_probe(struct platform_device *pdev)
{
return sunxi_pinctrl_init(pdev,
&a64_pinctrl_data);
}
