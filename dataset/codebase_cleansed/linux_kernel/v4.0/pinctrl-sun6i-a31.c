static int sun6i_a31_pinctrl_probe(struct platform_device *pdev)
{
return sunxi_pinctrl_init(pdev,
&sun6i_a31_pinctrl_data);
}
