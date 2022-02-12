static void funnel_enable_hw(struct funnel_drvdata *drvdata, int port)
{
u32 functl;
CS_UNLOCK(drvdata->base);
functl = readl_relaxed(drvdata->base + FUNNEL_FUNCTL);
functl &= ~FUNNEL_HOLDTIME_MASK;
functl |= FUNNEL_HOLDTIME;
functl |= (1 << port);
writel_relaxed(functl, drvdata->base + FUNNEL_FUNCTL);
writel_relaxed(drvdata->priority, drvdata->base + FUNNEL_PRICTL);
CS_LOCK(drvdata->base);
}
static int funnel_enable(struct coresight_device *csdev, int inport,
int outport)
{
struct funnel_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
funnel_enable_hw(drvdata, inport);
dev_info(drvdata->dev, "FUNNEL inport %d enabled\n", inport);
return 0;
}
static void funnel_disable_hw(struct funnel_drvdata *drvdata, int inport)
{
u32 functl;
CS_UNLOCK(drvdata->base);
functl = readl_relaxed(drvdata->base + FUNNEL_FUNCTL);
functl &= ~(1 << inport);
writel_relaxed(functl, drvdata->base + FUNNEL_FUNCTL);
CS_LOCK(drvdata->base);
}
static void funnel_disable(struct coresight_device *csdev, int inport,
int outport)
{
struct funnel_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
funnel_disable_hw(drvdata, inport);
dev_info(drvdata->dev, "FUNNEL inport %d disabled\n", inport);
}
static ssize_t priority_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct funnel_drvdata *drvdata = dev_get_drvdata(dev->parent);
unsigned long val = drvdata->priority;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t priority_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct funnel_drvdata *drvdata = dev_get_drvdata(dev->parent);
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
drvdata->priority = val;
return size;
}
static u32 get_funnel_ctrl_hw(struct funnel_drvdata *drvdata)
{
u32 functl;
CS_UNLOCK(drvdata->base);
functl = readl_relaxed(drvdata->base + FUNNEL_FUNCTL);
CS_LOCK(drvdata->base);
return functl;
}
static ssize_t funnel_ctrl_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
u32 val;
struct funnel_drvdata *drvdata = dev_get_drvdata(dev->parent);
pm_runtime_get_sync(drvdata->dev);
val = get_funnel_ctrl_hw(drvdata);
pm_runtime_put(drvdata->dev);
return sprintf(buf, "%#x\n", val);
}
static int funnel_probe(struct amba_device *adev, const struct amba_id *id)
{
int ret;
void __iomem *base;
struct device *dev = &adev->dev;
struct coresight_platform_data *pdata = NULL;
struct funnel_drvdata *drvdata;
struct resource *res = &adev->res;
struct coresight_desc desc = { 0 };
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
pm_runtime_put(&adev->dev);
desc.type = CORESIGHT_DEV_TYPE_LINK;
desc.subtype.link_subtype = CORESIGHT_DEV_SUBTYPE_LINK_MERG;
desc.ops = &funnel_cs_ops;
desc.pdata = pdata;
desc.dev = dev;
desc.groups = coresight_funnel_groups;
drvdata->csdev = coresight_register(&desc);
if (IS_ERR(drvdata->csdev))
return PTR_ERR(drvdata->csdev);
return 0;
}
static int funnel_runtime_suspend(struct device *dev)
{
struct funnel_drvdata *drvdata = dev_get_drvdata(dev);
if (drvdata && !IS_ERR(drvdata->atclk))
clk_disable_unprepare(drvdata->atclk);
return 0;
}
static int funnel_runtime_resume(struct device *dev)
{
struct funnel_drvdata *drvdata = dev_get_drvdata(dev);
if (drvdata && !IS_ERR(drvdata->atclk))
clk_prepare_enable(drvdata->atclk);
return 0;
}
