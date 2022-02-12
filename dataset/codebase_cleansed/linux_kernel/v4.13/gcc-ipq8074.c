static int gcc_ipq8074_probe(struct platform_device *pdev)
{
int ret, i;
for (i = 0; i < ARRAY_SIZE(gcc_ipq8074_hws); i++) {
ret = devm_clk_hw_register(&pdev->dev, gcc_ipq8074_hws[i]);
if (ret)
return ret;
}
return qcom_cc_probe(pdev, &gcc_ipq8074_desc);
}
static int __init gcc_ipq8074_init(void)
{
return platform_driver_register(&gcc_ipq8074_driver);
}
static void __exit gcc_ipq8074_exit(void)
{
platform_driver_unregister(&gcc_ipq8074_driver);
}
