static int sun4i_a10_pinctrl_probe(struct platform_device *pdev)
{
unsigned long variant = (unsigned long)of_device_get_match_data(&pdev->dev);
return sunxi_pinctrl_init_with_variant(pdev, &sun4i_a10_pinctrl_data,
variant);
}
