static int dwc3_of_simple_clk_init(struct dwc3_of_simple *simple, int count)
{
struct device *dev = simple->dev;
struct device_node *np = dev->of_node;
int i;
simple->num_clocks = count;
if (!count)
return 0;
simple->clks = devm_kcalloc(dev, simple->num_clocks,
sizeof(struct clk *), GFP_KERNEL);
if (!simple->clks)
return -ENOMEM;
for (i = 0; i < simple->num_clocks; i++) {
struct clk *clk;
int ret;
clk = of_clk_get(np, i);
if (IS_ERR(clk)) {
while (--i >= 0)
clk_put(simple->clks[i]);
return PTR_ERR(clk);
}
ret = clk_prepare_enable(clk);
if (ret < 0) {
while (--i >= 0) {
clk_disable_unprepare(simple->clks[i]);
clk_put(simple->clks[i]);
}
clk_put(clk);
return ret;
}
simple->clks[i] = clk;
}
return 0;
}
static int dwc3_of_simple_probe(struct platform_device *pdev)
{
struct dwc3_of_simple *simple;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
int ret;
int i;
simple = devm_kzalloc(dev, sizeof(*simple), GFP_KERNEL);
if (!simple)
return -ENOMEM;
platform_set_drvdata(pdev, simple);
simple->dev = dev;
ret = dwc3_of_simple_clk_init(simple, of_clk_get_parent_count(np));
if (ret)
return ret;
ret = of_platform_populate(np, NULL, NULL, dev);
if (ret) {
for (i = 0; i < simple->num_clocks; i++) {
clk_disable_unprepare(simple->clks[i]);
clk_put(simple->clks[i]);
}
return ret;
}
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
return 0;
}
static int dwc3_of_simple_remove(struct platform_device *pdev)
{
struct dwc3_of_simple *simple = platform_get_drvdata(pdev);
struct device *dev = &pdev->dev;
int i;
for (i = 0; i < simple->num_clocks; i++) {
clk_disable_unprepare(simple->clks[i]);
clk_put(simple->clks[i]);
}
of_platform_depopulate(dev);
pm_runtime_put_sync(dev);
pm_runtime_disable(dev);
return 0;
}
static int dwc3_of_simple_runtime_suspend(struct device *dev)
{
struct dwc3_of_simple *simple = dev_get_drvdata(dev);
int i;
for (i = 0; i < simple->num_clocks; i++)
clk_disable(simple->clks[i]);
return 0;
}
static int dwc3_of_simple_runtime_resume(struct device *dev)
{
struct dwc3_of_simple *simple = dev_get_drvdata(dev);
int ret;
int i;
for (i = 0; i < simple->num_clocks; i++) {
ret = clk_enable(simple->clks[i]);
if (ret < 0) {
while (--i >= 0)
clk_disable(simple->clks[i]);
return ret;
}
}
return 0;
}
