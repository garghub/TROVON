static int sun6i_a31s_pinctrl_probe(struct platform_device *pdev)
{
return sunxi_pinctrl_init(pdev,
&sun6i_a31s_pinctrl_data);
}
