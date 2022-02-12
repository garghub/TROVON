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
int ret;
ret = clk_prepare_enable(drvdata->clk);
if (ret)
return ret;
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
clk_disable_unprepare(drvdata->clk);
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
int ret;
u32 val;
struct funnel_drvdata *drvdata = dev_get_drvdata(dev->parent);
ret = clk_prepare_enable(drvdata->clk);
if (ret)
return ret;
val = get_funnel_ctrl_hw(drvdata);
clk_disable_unprepare(drvdata->clk);
return sprintf(buf, "%#x\n", val);
}
static int funnel_probe(struct amba_device *adev, const struct amba_id *id)
{
void __iomem *base;
struct device *dev = &adev->dev;
struct coresight_platform_data *pdata = NULL;
struct funnel_drvdata *drvdata;
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
dev_set_drvdata(dev, drvdata);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
drvdata->base = base;
drvdata->clk = adev->pclk;
desc = devm_kzalloc(dev, sizeof(*desc), GFP_KERNEL);
if (!desc)
return -ENOMEM;
desc->type = CORESIGHT_DEV_TYPE_LINK;
desc->subtype.link_subtype = CORESIGHT_DEV_SUBTYPE_LINK_MERG;
desc->ops = &funnel_cs_ops;
desc->pdata = pdata;
desc->dev = dev;
desc->groups = coresight_funnel_groups;
drvdata->csdev = coresight_register(desc);
if (IS_ERR(drvdata->csdev))
return PTR_ERR(drvdata->csdev);
dev_info(dev, "FUNNEL initialized\n");
return 0;
}
static int funnel_remove(struct amba_device *adev)
{
struct funnel_drvdata *drvdata = amba_get_drvdata(adev);
coresight_unregister(drvdata->csdev);
return 0;
}
