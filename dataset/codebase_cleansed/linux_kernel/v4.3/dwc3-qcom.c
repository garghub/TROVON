static int dwc3_qcom_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct dwc3_qcom *qdwc;
int ret;
qdwc = devm_kzalloc(&pdev->dev, sizeof(*qdwc), GFP_KERNEL);
if (!qdwc)
return -ENOMEM;
platform_set_drvdata(pdev, qdwc);
qdwc->dev = &pdev->dev;
qdwc->core_clk = devm_clk_get(qdwc->dev, "core");
if (IS_ERR(qdwc->core_clk)) {
dev_err(qdwc->dev, "failed to get core clock\n");
return PTR_ERR(qdwc->core_clk);
}
qdwc->iface_clk = devm_clk_get(qdwc->dev, "iface");
if (IS_ERR(qdwc->iface_clk)) {
dev_info(qdwc->dev, "failed to get optional iface clock\n");
qdwc->iface_clk = NULL;
}
qdwc->sleep_clk = devm_clk_get(qdwc->dev, "sleep");
if (IS_ERR(qdwc->sleep_clk)) {
dev_info(qdwc->dev, "failed to get optional sleep clock\n");
qdwc->sleep_clk = NULL;
}
ret = clk_prepare_enable(qdwc->core_clk);
if (ret) {
dev_err(qdwc->dev, "failed to enable core clock\n");
goto err_core;
}
ret = clk_prepare_enable(qdwc->iface_clk);
if (ret) {
dev_err(qdwc->dev, "failed to enable optional iface clock\n");
goto err_iface;
}
ret = clk_prepare_enable(qdwc->sleep_clk);
if (ret) {
dev_err(qdwc->dev, "failed to enable optional sleep clock\n");
goto err_sleep;
}
ret = of_platform_populate(node, NULL, NULL, qdwc->dev);
if (ret) {
dev_err(qdwc->dev, "failed to register core - %d\n", ret);
goto err_clks;
}
return 0;
err_clks:
clk_disable_unprepare(qdwc->sleep_clk);
err_sleep:
clk_disable_unprepare(qdwc->iface_clk);
err_iface:
clk_disable_unprepare(qdwc->core_clk);
err_core:
return ret;
}
static int dwc3_qcom_remove(struct platform_device *pdev)
{
struct dwc3_qcom *qdwc = platform_get_drvdata(pdev);
of_platform_depopulate(&pdev->dev);
clk_disable_unprepare(qdwc->sleep_clk);
clk_disable_unprepare(qdwc->iface_clk);
clk_disable_unprepare(qdwc->core_clk);
return 0;
}
