static int gic_runtime_resume(struct device *dev)
{
struct gic_chip_data *gic = dev_get_drvdata(dev);
int ret;
ret = pm_clk_resume(dev);
if (ret)
return ret;
if (!gic)
return 0;
gic_dist_restore(gic);
gic_cpu_restore(gic);
return 0;
}
static int gic_runtime_suspend(struct device *dev)
{
struct gic_chip_data *gic = dev_get_drvdata(dev);
gic_dist_save(gic);
gic_cpu_save(gic);
return pm_clk_suspend(dev);
}
static int gic_get_clocks(struct device *dev, const struct gic_clk_data *data)
{
struct clk *clk;
unsigned int i;
int ret;
if (!dev || !data)
return -EINVAL;
ret = pm_clk_create(dev);
if (ret)
return ret;
for (i = 0; i < data->num_clocks; i++) {
clk = of_clk_get_by_name(dev->of_node, data->clocks[i]);
if (IS_ERR(clk)) {
dev_err(dev, "failed to get clock %s\n",
data->clocks[i]);
ret = PTR_ERR(clk);
goto error;
}
ret = pm_clk_add_clk(dev, clk);
if (ret) {
dev_err(dev, "failed to add clock at index %d\n", i);
clk_put(clk);
goto error;
}
}
return 0;
error:
pm_clk_destroy(dev);
return ret;
}
static int gic_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct gic_clk_data *data;
struct gic_chip_data *gic;
int ret, irq;
data = of_device_get_match_data(&pdev->dev);
if (!data) {
dev_err(&pdev->dev, "no device match found\n");
return -ENODEV;
}
irq = irq_of_parse_and_map(dev->of_node, 0);
if (!irq) {
dev_err(dev, "no parent interrupt found!\n");
return -EINVAL;
}
ret = gic_get_clocks(dev, data);
if (ret)
goto irq_dispose;
pm_runtime_enable(dev);
ret = pm_runtime_get_sync(dev);
if (ret < 0)
goto rpm_disable;
ret = gic_of_init_child(dev, &gic, irq);
if (ret)
goto rpm_put;
platform_set_drvdata(pdev, gic);
pm_runtime_put(dev);
dev_info(dev, "GIC IRQ controller registered\n");
return 0;
rpm_put:
pm_runtime_put_sync(dev);
rpm_disable:
pm_runtime_disable(dev);
pm_clk_destroy(dev);
irq_dispose:
irq_dispose_mapping(irq);
return ret;
}
