static int sun5i_a13_pinctrl_probe(struct platform_device *pdev)
{
return sunxi_pinctrl_init(pdev,
&sun5i_a13_pinctrl_data);
}
