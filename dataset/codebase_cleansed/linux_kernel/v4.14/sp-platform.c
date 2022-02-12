static struct sp_dev_vdata *sp_get_of_version(struct platform_device *pdev)
{
#ifdef CONFIG_OF
const struct of_device_id *match;
match = of_match_node(sp_of_match, pdev->dev.of_node);
if (match && match->data)
return (struct sp_dev_vdata *)match->data;
#endif
return NULL;
}
static struct sp_dev_vdata *sp_get_acpi_version(struct platform_device *pdev)
{
#ifdef CONFIG_ACPI
const struct acpi_device_id *match;
match = acpi_match_device(sp_acpi_match, &pdev->dev);
if (match && match->driver_data)
return (struct sp_dev_vdata *)match->driver_data;
#endif
return NULL;
}
static int sp_get_irqs(struct sp_device *sp)
{
struct sp_platform *sp_platform = sp->dev_specific;
struct device *dev = sp->dev;
struct platform_device *pdev = to_platform_device(dev);
unsigned int i, count;
int ret;
for (i = 0, count = 0; i < pdev->num_resources; i++) {
struct resource *res = &pdev->resource[i];
if (resource_type(res) == IORESOURCE_IRQ)
count++;
}
sp_platform->irq_count = count;
ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_notice(dev, "unable to get IRQ (%d)\n", ret);
return ret;
}
sp->psp_irq = ret;
if (count == 1) {
sp->ccp_irq = ret;
} else {
ret = platform_get_irq(pdev, 1);
if (ret < 0) {
dev_notice(dev, "unable to get IRQ (%d)\n", ret);
return ret;
}
sp->ccp_irq = ret;
}
return 0;
}
static int sp_platform_probe(struct platform_device *pdev)
{
struct sp_device *sp;
struct sp_platform *sp_platform;
struct device *dev = &pdev->dev;
enum dev_dma_attr attr;
struct resource *ior;
int ret;
ret = -ENOMEM;
sp = sp_alloc_struct(dev);
if (!sp)
goto e_err;
sp_platform = devm_kzalloc(dev, sizeof(*sp_platform), GFP_KERNEL);
if (!sp_platform)
goto e_err;
sp->dev_specific = sp_platform;
sp->dev_vdata = pdev->dev.of_node ? sp_get_of_version(pdev)
: sp_get_acpi_version(pdev);
if (!sp->dev_vdata) {
ret = -ENODEV;
dev_err(dev, "missing driver data\n");
goto e_err;
}
ior = platform_get_resource(pdev, IORESOURCE_MEM, 0);
sp->io_map = devm_ioremap_resource(dev, ior);
if (IS_ERR(sp->io_map)) {
ret = PTR_ERR(sp->io_map);
goto e_err;
}
attr = device_get_dma_attr(dev);
if (attr == DEV_DMA_NOT_SUPPORTED) {
dev_err(dev, "DMA is not supported");
goto e_err;
}
sp_platform->coherent = (attr == DEV_DMA_COHERENT);
if (sp_platform->coherent)
sp->axcache = CACHE_WB_NO_ALLOC;
else
sp->axcache = CACHE_NONE;
ret = dma_set_mask_and_coherent(dev, DMA_BIT_MASK(48));
if (ret) {
dev_err(dev, "dma_set_mask_and_coherent failed (%d)\n", ret);
goto e_err;
}
ret = sp_get_irqs(sp);
if (ret)
goto e_err;
dev_set_drvdata(dev, sp);
ret = sp_init(sp);
if (ret)
goto e_err;
dev_notice(dev, "enabled\n");
return 0;
e_err:
dev_notice(dev, "initialization failed\n");
return ret;
}
static int sp_platform_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct sp_device *sp = dev_get_drvdata(dev);
sp_destroy(sp);
dev_notice(dev, "disabled\n");
return 0;
}
static int sp_platform_suspend(struct platform_device *pdev,
pm_message_t state)
{
struct device *dev = &pdev->dev;
struct sp_device *sp = dev_get_drvdata(dev);
return sp_suspend(sp, state);
}
static int sp_platform_resume(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct sp_device *sp = dev_get_drvdata(dev);
return sp_resume(sp);
}
int sp_platform_init(void)
{
return platform_driver_register(&sp_platform_driver);
}
void sp_platform_exit(void)
{
platform_driver_unregister(&sp_platform_driver);
}
