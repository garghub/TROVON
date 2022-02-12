static int sun9i_a80_pinctrl_probe(struct platform_device *pdev)
{
return sunxi_pinctrl_init(pdev,
&sun9i_a80_pinctrl_data);
}
