static int sun50i_h5_pinctrl_probe(struct platform_device *pdev)
{
return sunxi_pinctrl_init(pdev,
&sun50i_h5_pinctrl_data);
}
