static int gcc_msm8960_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct of_device_id *match;
struct platform_device *tsens;
int ret;
match = of_match_device(gcc_msm8960_match_table, &pdev->dev);
if (!match)
return -EINVAL;
ret = qcom_cc_register_board_clk(dev, "cxo_board", "cxo", 19200000);
if (ret)
return ret;
ret = qcom_cc_register_board_clk(dev, "pxo_board", "pxo", 27000000);
if (ret)
return ret;
ret = qcom_cc_probe(pdev, match->data);
if (ret)
return ret;
tsens = platform_device_register_data(&pdev->dev, "qcom-tsens", -1,
NULL, 0);
if (IS_ERR(tsens))
return PTR_ERR(tsens);
platform_set_drvdata(pdev, tsens);
return 0;
}
static int gcc_msm8960_remove(struct platform_device *pdev)
{
struct platform_device *tsens = platform_get_drvdata(pdev);
platform_device_unregister(tsens);
return 0;
}
static int __init gcc_msm8960_init(void)
{
return platform_driver_register(&gcc_msm8960_driver);
}
static void __exit gcc_msm8960_exit(void)
{
platform_driver_unregister(&gcc_msm8960_driver);
}
