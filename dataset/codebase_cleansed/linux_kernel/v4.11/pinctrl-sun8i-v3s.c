static int sun8i_v3s_pinctrl_probe(struct platform_device *pdev)
{
return sunxi_pinctrl_init(pdev,
&sun8i_v3s_pinctrl_data);
}
