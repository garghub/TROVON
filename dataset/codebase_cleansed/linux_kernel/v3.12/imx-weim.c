static int __init weim_timing_setup(struct device_node *np, void __iomem *base,
const struct imx_weim_devtype *devtype)
{
u32 cs_idx, value[devtype->cs_regs_count];
int i, ret;
ret = of_property_read_u32(np, "reg", &cs_idx);
if (ret)
return ret;
if (cs_idx >= devtype->cs_count)
return -EINVAL;
ret = of_property_read_u32_array(np, "fsl,weim-cs-timing",
value, devtype->cs_regs_count);
if (ret)
return ret;
for (i = 0; i < devtype->cs_regs_count; i++)
writel(value[i], base + cs_idx * devtype->cs_stride + i * 4);
return 0;
}
static int __init weim_parse_dt(struct platform_device *pdev,
void __iomem *base)
{
const struct of_device_id *of_id = of_match_device(weim_id_table,
&pdev->dev);
const struct imx_weim_devtype *devtype = of_id->data;
struct device_node *child;
int ret;
for_each_child_of_node(pdev->dev.of_node, child) {
if (!child->name)
continue;
ret = weim_timing_setup(child, base, devtype);
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
static int __init weim_probe(struct platform_device *pdev)
{
struct resource *res;
struct clk *clk;
void __iomem *base;
int ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(clk))
return PTR_ERR(clk);
ret = clk_prepare_enable(clk);
if (ret)
return ret;
ret = weim_parse_dt(pdev, base);
if (ret)
clk_disable_unprepare(clk);
else
dev_info(&pdev->dev, "Driver registered.\n");
return ret;
}
