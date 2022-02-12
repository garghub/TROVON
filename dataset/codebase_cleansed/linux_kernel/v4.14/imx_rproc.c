static int imx_rproc_start(struct rproc *rproc)
{
struct imx_rproc *priv = rproc->priv;
const struct imx_rproc_dcfg *dcfg = priv->dcfg;
struct device *dev = priv->dev;
int ret;
ret = regmap_update_bits(priv->regmap, dcfg->src_reg,
dcfg->src_mask, dcfg->src_start);
if (ret)
dev_err(dev, "Filed to enable M4!\n");
return ret;
}
static int imx_rproc_stop(struct rproc *rproc)
{
struct imx_rproc *priv = rproc->priv;
const struct imx_rproc_dcfg *dcfg = priv->dcfg;
struct device *dev = priv->dev;
int ret;
ret = regmap_update_bits(priv->regmap, dcfg->src_reg,
dcfg->src_mask, dcfg->src_stop);
if (ret)
dev_err(dev, "Filed to stop M4!\n");
return ret;
}
static int imx_rproc_da_to_sys(struct imx_rproc *priv, u64 da,
int len, u64 *sys)
{
const struct imx_rproc_dcfg *dcfg = priv->dcfg;
int i;
for (i = 0; i < dcfg->att_size; i++) {
const struct imx_rproc_att *att = &dcfg->att[i];
if (da >= att->da && da + len < att->da + att->size) {
unsigned int offset = da - att->da;
*sys = att->sa + offset;
return 0;
}
}
dev_warn(priv->dev, "Translation filed: da = 0x%llx len = 0x%x\n",
da, len);
return -ENOENT;
}
static void *imx_rproc_da_to_va(struct rproc *rproc, u64 da, int len)
{
struct imx_rproc *priv = rproc->priv;
void *va = NULL;
u64 sys;
int i;
if (len <= 0)
return NULL;
if (imx_rproc_da_to_sys(priv, da, len, &sys))
return NULL;
for (i = 0; i < IMX7D_RPROC_MEM_MAX; i++) {
if (sys >= priv->mem[i].sys_addr && sys + len <
priv->mem[i].sys_addr + priv->mem[i].size) {
unsigned int offset = sys - priv->mem[i].sys_addr;
va = (__force void *)(priv->mem[i].cpu_addr + offset);
break;
}
}
dev_dbg(&rproc->dev, "da = 0x%llx len = 0x%x va = 0x%p\n", da, len, va);
return va;
}
static int imx_rproc_addr_init(struct imx_rproc *priv,
struct platform_device *pdev)
{
const struct imx_rproc_dcfg *dcfg = priv->dcfg;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
int a, b = 0, err, nph;
for (a = 0; a < dcfg->att_size; a++) {
const struct imx_rproc_att *att = &dcfg->att[a];
if (!(att->flags & ATT_OWN))
continue;
if (b >= IMX7D_RPROC_MEM_MAX)
break;
priv->mem[b].cpu_addr = devm_ioremap(&pdev->dev,
att->sa, att->size);
if (!priv->mem[b].cpu_addr) {
dev_err(dev, "devm_ioremap_resource failed\n");
return -ENOMEM;
}
priv->mem[b].sys_addr = att->sa;
priv->mem[b].size = att->size;
b++;
}
nph = of_count_phandle_with_args(np, "memory-region", NULL);
if (nph <= 0)
return 0;
for (a = 0; a < nph; a++) {
struct device_node *node;
struct resource res;
node = of_parse_phandle(np, "memory-region", a);
err = of_address_to_resource(node, 0, &res);
if (err) {
dev_err(dev, "unable to resolve memory region\n");
return err;
}
if (b >= IMX7D_RPROC_MEM_MAX)
break;
priv->mem[b].cpu_addr = devm_ioremap_resource(&pdev->dev, &res);
if (IS_ERR(priv->mem[b].cpu_addr)) {
dev_err(dev, "devm_ioremap_resource failed\n");
err = PTR_ERR(priv->mem[b].cpu_addr);
return err;
}
priv->mem[b].sys_addr = res.start;
priv->mem[b].size = resource_size(&res);
b++;
}
return 0;
}
static int imx_rproc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct imx_rproc *priv;
struct rproc *rproc;
struct regmap_config config = { .name = "imx-rproc" };
const struct imx_rproc_dcfg *dcfg;
struct regmap *regmap;
int ret;
regmap = syscon_regmap_lookup_by_phandle(np, "syscon");
if (IS_ERR(regmap)) {
dev_err(dev, "failed to find syscon\n");
return PTR_ERR(regmap);
}
regmap_attach_dev(dev, regmap, &config);
rproc = rproc_alloc(dev, "imx-rproc", &imx_rproc_ops,
NULL, sizeof(*priv));
if (!rproc) {
ret = -ENOMEM;
goto err;
}
dcfg = of_device_get_match_data(dev);
if (!dcfg)
return -EINVAL;
priv = rproc->priv;
priv->rproc = rproc;
priv->regmap = regmap;
priv->dcfg = dcfg;
priv->dev = dev;
dev_set_drvdata(dev, rproc);
ret = imx_rproc_addr_init(priv, pdev);
if (ret) {
dev_err(dev, "filed on imx_rproc_addr_init\n");
goto err_put_rproc;
}
priv->clk = devm_clk_get(dev, NULL);
if (IS_ERR(priv->clk)) {
dev_err(dev, "Failed to get clock\n");
rproc_free(rproc);
return PTR_ERR(priv->clk);
}
ret = clk_prepare_enable(priv->clk);
if (ret) {
dev_err(&rproc->dev, "Failed to enable clock\n");
rproc_free(rproc);
return ret;
}
ret = rproc_add(rproc);
if (ret) {
dev_err(dev, "rproc_add failed\n");
goto err_put_clk;
}
return ret;
err_put_clk:
clk_disable_unprepare(priv->clk);
err_put_rproc:
rproc_free(rproc);
err:
return ret;
}
static int imx_rproc_remove(struct platform_device *pdev)
{
struct rproc *rproc = platform_get_drvdata(pdev);
struct imx_rproc *priv = rproc->priv;
clk_disable_unprepare(priv->clk);
rproc_del(rproc);
rproc_free(rproc);
return 0;
}
