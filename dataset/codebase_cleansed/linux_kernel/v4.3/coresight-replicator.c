static int replicator_enable(struct coresight_device *csdev, int inport,
int outport)
{
struct replicator_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
pm_runtime_get_sync(drvdata->dev);
dev_info(drvdata->dev, "REPLICATOR enabled\n");
return 0;
}
static void replicator_disable(struct coresight_device *csdev, int inport,
int outport)
{
struct replicator_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
pm_runtime_put(drvdata->dev);
dev_info(drvdata->dev, "REPLICATOR disabled\n");
}
static int replicator_probe(struct platform_device *pdev)
{
int ret;
struct device *dev = &pdev->dev;
struct coresight_platform_data *pdata = NULL;
struct replicator_drvdata *drvdata;
struct coresight_desc *desc;
struct device_node *np = pdev->dev.of_node;
if (np) {
pdata = of_get_coresight_platform_data(dev, np);
if (IS_ERR(pdata))
return PTR_ERR(pdata);
pdev->dev.platform_data = pdata;
}
drvdata = devm_kzalloc(dev, sizeof(*drvdata), GFP_KERNEL);
if (!drvdata)
return -ENOMEM;
drvdata->dev = &pdev->dev;
drvdata->atclk = devm_clk_get(&pdev->dev, "atclk");
if (!IS_ERR(drvdata->atclk)) {
ret = clk_prepare_enable(drvdata->atclk);
if (ret)
return ret;
}
pm_runtime_get_noresume(&pdev->dev);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
platform_set_drvdata(pdev, drvdata);
desc = devm_kzalloc(dev, sizeof(*desc), GFP_KERNEL);
if (!desc) {
ret = -ENOMEM;
goto out_disable_pm;
}
desc->type = CORESIGHT_DEV_TYPE_LINK;
desc->subtype.link_subtype = CORESIGHT_DEV_SUBTYPE_LINK_SPLIT;
desc->ops = &replicator_cs_ops;
desc->pdata = pdev->dev.platform_data;
desc->dev = &pdev->dev;
drvdata->csdev = coresight_register(desc);
if (IS_ERR(drvdata->csdev)) {
ret = PTR_ERR(drvdata->csdev);
goto out_disable_pm;
}
pm_runtime_put(&pdev->dev);
dev_info(dev, "REPLICATOR initialized\n");
return 0;
out_disable_pm:
if (!IS_ERR(drvdata->atclk))
clk_disable_unprepare(drvdata->atclk);
pm_runtime_put_noidle(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return ret;
}
static int replicator_remove(struct platform_device *pdev)
{
struct replicator_drvdata *drvdata = platform_get_drvdata(pdev);
coresight_unregister(drvdata->csdev);
pm_runtime_get_sync(&pdev->dev);
if (!IS_ERR(drvdata->atclk))
clk_disable_unprepare(drvdata->atclk);
pm_runtime_put_noidle(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int replicator_runtime_suspend(struct device *dev)
{
struct replicator_drvdata *drvdata = dev_get_drvdata(dev);
if (drvdata && !IS_ERR(drvdata->atclk))
clk_disable_unprepare(drvdata->atclk);
return 0;
}
static int replicator_runtime_resume(struct device *dev)
{
struct replicator_drvdata *drvdata = dev_get_drvdata(dev);
if (drvdata && !IS_ERR(drvdata->atclk))
clk_prepare_enable(drvdata->atclk);
return 0;
}
