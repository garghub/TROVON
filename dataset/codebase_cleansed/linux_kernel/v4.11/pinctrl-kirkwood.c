static int kirkwood_pinctrl_probe(struct platform_device *pdev)
{
const struct of_device_id *match =
of_match_device(kirkwood_pinctrl_of_match, &pdev->dev);
pdev->dev.platform_data = (void *)match->data;
return mvebu_pinctrl_simple_mmio_probe(pdev);
}
