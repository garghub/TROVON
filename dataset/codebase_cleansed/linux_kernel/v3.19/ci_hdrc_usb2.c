static int ci_hdrc_usb2_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ci_hdrc_usb2_priv *priv;
struct ci_hdrc_platform_data *ci_pdata = dev_get_platdata(dev);
int ret;
if (!ci_pdata)
ci_pdata = &ci_default_pdata;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->clk = devm_clk_get(dev, NULL);
if (!IS_ERR(priv->clk)) {
ret = clk_prepare_enable(priv->clk);
if (ret) {
dev_err(dev, "failed to enable the clock: %d\n", ret);
return ret;
}
}
ret = dma_set_mask_and_coherent(dev, DMA_BIT_MASK(32));
if (ret)
goto clk_err;
ci_pdata->name = dev_name(dev);
priv->ci_pdev = ci_hdrc_add_device(dev, pdev->resource,
pdev->num_resources, ci_pdata);
if (IS_ERR(priv->ci_pdev)) {
ret = PTR_ERR(priv->ci_pdev);
if (ret != -EPROBE_DEFER)
dev_err(dev,
"failed to register ci_hdrc platform device: %d\n",
ret);
goto clk_err;
}
platform_set_drvdata(pdev, priv);
pm_runtime_no_callbacks(dev);
pm_runtime_enable(dev);
return 0;
clk_err:
if (!IS_ERR(priv->clk))
clk_disable_unprepare(priv->clk);
return ret;
}
static int ci_hdrc_usb2_remove(struct platform_device *pdev)
{
struct ci_hdrc_usb2_priv *priv = platform_get_drvdata(pdev);
pm_runtime_disable(&pdev->dev);
ci_hdrc_remove_device(priv->ci_pdev);
clk_disable_unprepare(priv->clk);
return 0;
}
