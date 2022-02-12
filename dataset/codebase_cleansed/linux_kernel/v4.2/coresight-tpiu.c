static void tpiu_enable_hw(struct tpiu_drvdata *drvdata)
{
CS_UNLOCK(drvdata->base);
CS_LOCK(drvdata->base);
}
static int tpiu_enable(struct coresight_device *csdev)
{
struct tpiu_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
pm_runtime_get_sync(csdev->dev.parent);
tpiu_enable_hw(drvdata);
dev_info(drvdata->dev, "TPIU enabled\n");
return 0;
}
static void tpiu_disable_hw(struct tpiu_drvdata *drvdata)
{
CS_UNLOCK(drvdata->base);
writel_relaxed(0x0, drvdata->base + TPIU_FFCR);
writel_relaxed(FFCR_FON_MAN, drvdata->base + TPIU_FFCR);
CS_LOCK(drvdata->base);
}
static void tpiu_disable(struct coresight_device *csdev)
{
struct tpiu_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
tpiu_disable_hw(drvdata);
pm_runtime_put(csdev->dev.parent);
dev_info(drvdata->dev, "TPIU disabled\n");
}
static int tpiu_probe(struct amba_device *adev, const struct amba_id *id)
{
int ret;
void __iomem *base;
struct device *dev = &adev->dev;
struct coresight_platform_data *pdata = NULL;
struct tpiu_drvdata *drvdata;
struct resource *res = &adev->res;
struct coresight_desc *desc;
struct device_node *np = adev->dev.of_node;
if (np) {
pdata = of_get_coresight_platform_data(dev, np);
if (IS_ERR(pdata))
return PTR_ERR(pdata);
adev->dev.platform_data = pdata;
}
drvdata = devm_kzalloc(dev, sizeof(*drvdata), GFP_KERNEL);
if (!drvdata)
return -ENOMEM;
drvdata->dev = &adev->dev;
drvdata->atclk = devm_clk_get(&adev->dev, "atclk");
if (!IS_ERR(drvdata->atclk)) {
ret = clk_prepare_enable(drvdata->atclk);
if (ret)
return ret;
}
dev_set_drvdata(dev, drvdata);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
drvdata->base = base;
tpiu_disable_hw(drvdata);
pm_runtime_put(&adev->dev);
desc = devm_kzalloc(dev, sizeof(*desc), GFP_KERNEL);
if (!desc)
return -ENOMEM;
desc->type = CORESIGHT_DEV_TYPE_SINK;
desc->subtype.sink_subtype = CORESIGHT_DEV_SUBTYPE_SINK_PORT;
desc->ops = &tpiu_cs_ops;
desc->pdata = pdata;
desc->dev = dev;
drvdata->csdev = coresight_register(desc);
if (IS_ERR(drvdata->csdev))
return PTR_ERR(drvdata->csdev);
dev_info(dev, "TPIU initialized\n");
return 0;
}
static int tpiu_remove(struct amba_device *adev)
{
struct tpiu_drvdata *drvdata = amba_get_drvdata(adev);
coresight_unregister(drvdata->csdev);
return 0;
}
static int tpiu_runtime_suspend(struct device *dev)
{
struct tpiu_drvdata *drvdata = dev_get_drvdata(dev);
if (drvdata && !IS_ERR(drvdata->atclk))
clk_disable_unprepare(drvdata->atclk);
return 0;
}
static int tpiu_runtime_resume(struct device *dev)
{
struct tpiu_drvdata *drvdata = dev_get_drvdata(dev);
if (drvdata && !IS_ERR(drvdata->atclk))
clk_prepare_enable(drvdata->atclk);
return 0;
}
