static int __init imx_weim_gpr_setup(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct property *prop;
const __be32 *p;
struct regmap *gpr;
u32 gprvals[4] = {
05,
033,
0113,
01111,
};
u32 gprval = 0;
u32 val;
int cs = 0;
int i = 0;
gpr = syscon_regmap_lookup_by_phandle(np, "fsl,weim-cs-gpr");
if (IS_ERR(gpr)) {
dev_dbg(&pdev->dev, "failed to find weim-cs-gpr\n");
return 0;
}
of_property_for_each_u32(np, "ranges", prop, p, val) {
if (i % 4 == 0) {
cs = val;
} else if (i % 4 == 3 && val) {
val = (val / SZ_32M) | 1;
gprval |= val << cs * 3;
}
i++;
}
if (i == 0 || i % 4)
goto err;
for (i = 0; i < ARRAY_SIZE(gprvals); i++) {
if (gprval == gprvals[i]) {
regmap_update_bits(gpr, IOMUXC_GPR1, 0xfff, gprval);
return 0;
}
}
err:
dev_err(&pdev->dev, "Invalid 'ranges' configuration\n");
return -EINVAL;
}
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
int ret, have_child = 0;
if (devtype == &imx50_weim_devtype) {
ret = imx_weim_gpr_setup(pdev);
if (ret)
return ret;
}
for_each_child_of_node(pdev->dev.of_node, child) {
if (!child->name)
continue;
ret = weim_timing_setup(child, base, devtype);
if (ret)
dev_warn(&pdev->dev, "%s set timing failed.\n",
child->full_name);
else
have_child = 1;
}
if (have_child)
ret = of_platform_populate(pdev->dev.of_node,
of_default_bus_match_table,
NULL, &pdev->dev);
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
