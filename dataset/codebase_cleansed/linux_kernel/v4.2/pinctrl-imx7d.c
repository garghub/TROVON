static int imx7d_pinctrl_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct imx_pinctrl_soc_info *pinctrl_info;
match = of_match_device(imx7d_pinctrl_of_match, &pdev->dev);
if (!match)
return -ENODEV;
pinctrl_info = (struct imx_pinctrl_soc_info *) match->data;
return imx_pinctrl_probe(pdev, pinctrl_info);
}
static int __init imx7d_pinctrl_init(void)
{
return platform_driver_register(&imx7d_pinctrl_driver);
}
static void __exit imx7d_pinctrl_exit(void)
{
platform_driver_unregister(&imx7d_pinctrl_driver);
}
