static int sun4i_a10_pinctrl_probe(struct platform_device *pdev)
{
return sunxi_pinctrl_init(pdev,
&sun4i_a10_pinctrl_data);
}
