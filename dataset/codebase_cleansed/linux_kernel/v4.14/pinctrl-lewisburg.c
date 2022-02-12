static int lbg_pinctrl_probe(struct platform_device *pdev)
{
return intel_pinctrl_probe(pdev, &lbg_soc_data);
}
