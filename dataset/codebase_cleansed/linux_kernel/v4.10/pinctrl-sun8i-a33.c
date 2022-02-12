static int sun8i_a33_pinctrl_probe(struct platform_device *pdev)
{
return sunxi_pinctrl_init(pdev,
&sun8i_a33_pinctrl_data);
}
