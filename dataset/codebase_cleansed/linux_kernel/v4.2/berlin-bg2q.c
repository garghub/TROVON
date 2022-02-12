static int berlin2q_pinctrl_probe(struct platform_device *pdev)
{
const struct of_device_id *match =
of_match_device(berlin2q_pinctrl_match, &pdev->dev);
return berlin_pinctrl_probe(pdev, match->data);
}
