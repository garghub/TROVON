static int replicator_enable(struct coresight_device *csdev, int inport,
int outport)
{
struct replicator_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
dev_info(drvdata->dev, "REPLICATOR enabled\n");
return 0;
}
static void replicator_disable(struct coresight_device *csdev, int inport,
int outport)
{
struct replicator_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
dev_info(drvdata->dev, "REPLICATOR disabled\n");
}
static int replicator_probe(struct platform_device *pdev)
{
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
platform_set_drvdata(pdev, drvdata);
desc = devm_kzalloc(dev, sizeof(*desc), GFP_KERNEL);
if (!desc)
return -ENOMEM;
desc->type = CORESIGHT_DEV_TYPE_LINK;
desc->subtype.link_subtype = CORESIGHT_DEV_SUBTYPE_LINK_SPLIT;
desc->ops = &replicator_cs_ops;
desc->pdata = pdev->dev.platform_data;
desc->dev = &pdev->dev;
drvdata->csdev = coresight_register(desc);
if (IS_ERR(drvdata->csdev))
return PTR_ERR(drvdata->csdev);
dev_info(dev, "REPLICATOR initialized\n");
return 0;
}
static int replicator_remove(struct platform_device *pdev)
{
struct replicator_drvdata *drvdata = platform_get_drvdata(pdev);
coresight_unregister(drvdata->csdev);
return 0;
}
static int __init replicator_init(void)
{
return platform_driver_register(&replicator_driver);
}
static void __exit replicator_exit(void)
{
platform_driver_unregister(&replicator_driver);
}
