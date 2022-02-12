static int replicator_enable(struct coresight_device *csdev, int inport,
int outport)
{
struct replicator_state *drvdata = dev_get_drvdata(csdev->dev.parent);
CS_UNLOCK(drvdata->base);
if (outport == 0) {
writel_relaxed(0x00, drvdata->base + REPLICATOR_IDFILTER0);
writel_relaxed(0xff, drvdata->base + REPLICATOR_IDFILTER1);
} else {
writel_relaxed(0x00, drvdata->base + REPLICATOR_IDFILTER1);
writel_relaxed(0xff, drvdata->base + REPLICATOR_IDFILTER0);
}
CS_LOCK(drvdata->base);
dev_info(drvdata->dev, "REPLICATOR enabled\n");
return 0;
}
static void replicator_disable(struct coresight_device *csdev, int inport,
int outport)
{
struct replicator_state *drvdata = dev_get_drvdata(csdev->dev.parent);
CS_UNLOCK(drvdata->base);
if (outport == 0)
writel_relaxed(0xff, drvdata->base + REPLICATOR_IDFILTER0);
else
writel_relaxed(0xff, drvdata->base + REPLICATOR_IDFILTER1);
CS_LOCK(drvdata->base);
dev_info(drvdata->dev, "REPLICATOR disabled\n");
}
static int replicator_probe(struct amba_device *adev, const struct amba_id *id)
{
int ret;
struct device *dev = &adev->dev;
struct resource *res = &adev->res;
struct coresight_platform_data *pdata = NULL;
struct replicator_state *drvdata;
struct coresight_desc *desc;
struct device_node *np = adev->dev.of_node;
void __iomem *base;
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
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
drvdata->base = base;
dev_set_drvdata(dev, drvdata);
pm_runtime_put(&adev->dev);
desc = devm_kzalloc(dev, sizeof(*desc), GFP_KERNEL);
if (!desc)
return -ENOMEM;
desc->type = CORESIGHT_DEV_TYPE_LINK;
desc->subtype.link_subtype = CORESIGHT_DEV_SUBTYPE_LINK_SPLIT;
desc->ops = &replicator_cs_ops;
desc->pdata = adev->dev.platform_data;
desc->dev = &adev->dev;
drvdata->csdev = coresight_register(desc);
if (IS_ERR(drvdata->csdev))
return PTR_ERR(drvdata->csdev);
dev_info(dev, "%s initialized\n", (char *)id->data);
return 0;
}
static int replicator_runtime_suspend(struct device *dev)
{
struct replicator_state *drvdata = dev_get_drvdata(dev);
if (drvdata && !IS_ERR(drvdata->atclk))
clk_disable_unprepare(drvdata->atclk);
return 0;
}
static int replicator_runtime_resume(struct device *dev)
{
struct replicator_state *drvdata = dev_get_drvdata(dev);
if (drvdata && !IS_ERR(drvdata->atclk))
clk_prepare_enable(drvdata->atclk);
return 0;
}
