static int sun7i_a20_pinctrl_probe(struct platform_device *pdev)
{
return sunxi_pinctrl_init(pdev,
&sun7i_a20_pinctrl_data);
}
