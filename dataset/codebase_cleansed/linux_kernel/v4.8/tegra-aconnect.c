static int tegra_aconnect_add_clock(struct device *dev, char *name)
{
struct clk *clk;
int ret;
clk = clk_get(dev, name);
if (IS_ERR(clk)) {
dev_err(dev, "%s clock not found\n", name);
return PTR_ERR(clk);
}
ret = pm_clk_add_clk(dev, clk);
if (ret)
clk_put(clk);
return ret;
}
static int tegra_aconnect_probe(struct platform_device *pdev)
{
int ret;
if (!pdev->dev.of_node)
return -EINVAL;
ret = pm_clk_create(&pdev->dev);
if (ret)
return ret;
ret = tegra_aconnect_add_clock(&pdev->dev, "ape");
if (ret)
goto clk_destroy;
ret = tegra_aconnect_add_clock(&pdev->dev, "apb2ape");
if (ret)
goto clk_destroy;
pm_runtime_enable(&pdev->dev);
of_platform_populate(pdev->dev.of_node, NULL, NULL, &pdev->dev);
dev_info(&pdev->dev, "Tegra ACONNECT bus registered\n");
return 0;
clk_destroy:
pm_clk_destroy(&pdev->dev);
return ret;
}
static int tegra_aconnect_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
pm_clk_destroy(&pdev->dev);
return 0;
}
static int tegra_aconnect_runtime_resume(struct device *dev)
{
return pm_clk_resume(dev);
}
static int tegra_aconnect_runtime_suspend(struct device *dev)
{
return pm_clk_suspend(dev);
}
