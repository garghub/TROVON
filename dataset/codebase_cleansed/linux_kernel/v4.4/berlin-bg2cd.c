static int berlin2cd_pinctrl_probe(struct platform_device *pdev)
{
const struct of_device_id *match =
of_match_device(berlin2cd_pinctrl_match, &pdev->dev);
return berlin_pinctrl_probe(pdev, match->data);
}
