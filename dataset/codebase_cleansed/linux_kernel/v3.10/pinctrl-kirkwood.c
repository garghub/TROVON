static int kirkwood_pinctrl_probe(struct platform_device *pdev)
{
const struct of_device_id *match =
of_match_device(kirkwood_pinctrl_of_match, &pdev->dev);
pdev->dev.platform_data = (void *)match->data;
return mvebu_pinctrl_probe(pdev);
}
static int kirkwood_pinctrl_remove(struct platform_device *pdev)
{
return mvebu_pinctrl_remove(pdev);
}
