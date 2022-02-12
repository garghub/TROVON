static void qcom_ebi2_setup_chipselect(struct device_node *np,
struct device *dev,
void __iomem *ebi2_base,
void __iomem *ebi2_xmem,
u32 csindex)
{
const struct cs_data *csd;
u32 slowcfg, fastcfg;
u32 val;
int ret;
int i;
csd = &cs_info[csindex];
val = readl(ebi2_base);
val |= csd->enable_mask;
writel(val, ebi2_base);
dev_dbg(dev, "enabled CS%u\n", csindex);
slowcfg = 0;
fastcfg = 0;
for (i = 0; i < ARRAY_SIZE(xmem_props); i++) {
const struct ebi2_xmem_prop *xp = &xmem_props[i];
ret = of_property_read_u32(np, xp->prop, &val);
if (ret) {
dev_dbg(dev, "could not read %s for CS%d\n",
xp->prop, csindex);
continue;
}
if (xp->max == 1 && val) {
if (xp->slowreg)
slowcfg |= BIT(xp->shift);
else
fastcfg |= BIT(xp->shift);
dev_dbg(dev, "set %s flag\n", xp->prop);
continue;
}
if (val > xp->max) {
dev_err(dev,
"too high value for %s: %u, capped at %u\n",
xp->prop, val, xp->max);
val = xp->max;
}
if (xp->slowreg)
slowcfg |= (val << xp->shift);
else
fastcfg |= (val << xp->shift);
dev_dbg(dev, "set %s to %u\n", xp->prop, val);
}
dev_info(dev, "CS%u: SLOW CFG 0x%08x, FAST CFG 0x%08x\n",
csindex, slowcfg, fastcfg);
if (slowcfg)
writel(slowcfg, ebi2_xmem + csd->slow_cfg);
if (fastcfg)
writel(fastcfg, ebi2_xmem + csd->fast_cfg);
}
static int qcom_ebi2_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device_node *child;
struct device *dev = &pdev->dev;
struct resource *res;
void __iomem *ebi2_base;
void __iomem *ebi2_xmem;
struct clk *ebi2xclk;
struct clk *ebi2clk;
bool have_children = false;
u32 val;
int ret;
ebi2xclk = devm_clk_get(dev, "ebi2x");
if (IS_ERR(ebi2xclk))
return PTR_ERR(ebi2xclk);
ret = clk_prepare_enable(ebi2xclk);
if (ret) {
dev_err(dev, "could not enable EBI2X clk (%d)\n", ret);
return ret;
}
ebi2clk = devm_clk_get(dev, "ebi2");
if (IS_ERR(ebi2clk)) {
ret = PTR_ERR(ebi2clk);
goto err_disable_2x_clk;
}
ret = clk_prepare_enable(ebi2clk);
if (ret) {
dev_err(dev, "could not enable EBI2 clk\n");
goto err_disable_2x_clk;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ebi2_base = devm_ioremap_resource(dev, res);
if (IS_ERR(ebi2_base)) {
ret = PTR_ERR(ebi2_base);
goto err_disable_clk;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
ebi2_xmem = devm_ioremap_resource(dev, res);
if (IS_ERR(ebi2_xmem)) {
ret = PTR_ERR(ebi2_xmem);
goto err_disable_clk;
}
writel(0UL, ebi2_xmem + EBI2_XMEM_CFG);
val = readl(ebi2_base);
val &= ~EBI2_CSN_MASK;
writel(val, ebi2_base);
for_each_available_child_of_node(np, child) {
u32 csindex;
ret = of_property_read_u32(child, "reg", &csindex);
if (ret)
return ret;
if (csindex > 5) {
dev_err(dev,
"invalid chipselect %u, we only support 0-5\n",
csindex);
continue;
}
qcom_ebi2_setup_chipselect(child,
dev,
ebi2_base,
ebi2_xmem,
csindex);
have_children = true;
}
if (have_children)
return of_platform_default_populate(np, NULL, dev);
return 0;
err_disable_clk:
clk_disable_unprepare(ebi2clk);
err_disable_2x_clk:
clk_disable_unprepare(ebi2xclk);
return ret;
}
