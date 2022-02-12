static int
weim_timing_setup(struct platform_device *pdev, struct device_node *np)
{
struct imx_weim *weim = platform_get_drvdata(pdev);
u32 value[CS_TIMING_LEN];
u32 cs_idx;
int ret;
int i;
ret = of_property_read_u32(np, "reg", &cs_idx);
if (ret)
return ret;
if (cs_idx > 3)
return -EINVAL;
ret = of_property_read_u32_array(np, "fsl,weim-cs-timing",
value, CS_TIMING_LEN);
if (ret)
return ret;
for (i = 0; i < CS_TIMING_LEN; i++)
writel(value[i], weim->base + cs_idx * CS_REG_RANGE + i * 4);
return 0;
}
static int weim_parse_dt(struct platform_device *pdev)
{
struct device_node *child;
int ret;
for_each_child_of_node(pdev->dev.of_node, child) {
if (!child->name)
continue;
ret = weim_timing_setup(pdev, child);
if (ret) {
dev_err(&pdev->dev, "%s set timing failed.\n",
child->full_name);
return ret;
}
}
ret = of_platform_populate(pdev->dev.of_node, NULL, NULL, &pdev->dev);
if (ret)
dev_err(&pdev->dev, "%s fail to create devices.\n",
pdev->dev.of_node->full_name);
return ret;
}
static int weim_probe(struct platform_device *pdev)
{
struct imx_weim *weim;
struct resource *res;
int ret = -EINVAL;
weim = devm_kzalloc(&pdev->dev, sizeof(*weim), GFP_KERNEL);
if (!weim) {
ret = -ENOMEM;
goto weim_err;
}
platform_set_drvdata(pdev, weim);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
weim->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(weim->base)) {
ret = PTR_ERR(weim->base);
goto weim_err;
}
weim->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(weim->clk))
goto weim_err;
ret = clk_prepare_enable(weim->clk);
if (ret)
goto weim_err;
ret = weim_parse_dt(pdev);
if (ret) {
clk_disable_unprepare(weim->clk);
goto weim_err;
}
dev_info(&pdev->dev, "WEIM driver registered.\n");
return 0;
weim_err:
return ret;
}
