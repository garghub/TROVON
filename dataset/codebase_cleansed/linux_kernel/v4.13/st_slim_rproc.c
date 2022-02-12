static int slim_clk_get(struct st_slim_rproc *slim_rproc, struct device *dev)
{
int clk, err;
for (clk = 0; clk < ST_SLIM_MAX_CLK; clk++) {
slim_rproc->clks[clk] = of_clk_get(dev->of_node, clk);
if (IS_ERR(slim_rproc->clks[clk])) {
err = PTR_ERR(slim_rproc->clks[clk]);
if (err == -EPROBE_DEFER)
goto err_put_clks;
slim_rproc->clks[clk] = NULL;
break;
}
}
return 0;
err_put_clks:
while (--clk >= 0)
clk_put(slim_rproc->clks[clk]);
return err;
}
static void slim_clk_disable(struct st_slim_rproc *slim_rproc)
{
int clk;
for (clk = 0; clk < ST_SLIM_MAX_CLK && slim_rproc->clks[clk]; clk++)
clk_disable_unprepare(slim_rproc->clks[clk]);
}
static int slim_clk_enable(struct st_slim_rproc *slim_rproc)
{
int clk, ret;
for (clk = 0; clk < ST_SLIM_MAX_CLK && slim_rproc->clks[clk]; clk++) {
ret = clk_prepare_enable(slim_rproc->clks[clk]);
if (ret)
goto err_disable_clks;
}
return 0;
err_disable_clks:
while (--clk >= 0)
clk_disable_unprepare(slim_rproc->clks[clk]);
return ret;
}
static int slim_rproc_start(struct rproc *rproc)
{
struct device *dev = &rproc->dev;
struct st_slim_rproc *slim_rproc = rproc->priv;
unsigned long hw_id, hw_ver, fw_rev;
u32 val;
val = SLIM_CLK_GATE_DIS | SLIM_CLK_GATE_RESET;
writel(val, slim_rproc->slimcore + SLIM_CLK_GATE_OFST);
writel(SLIM_STBUS_SYNC_DIS, slim_rproc->peri + SLIM_STBUS_SYNC_OFST);
writel(!SLIM_CLK_GATE_DIS,
slim_rproc->slimcore + SLIM_CLK_GATE_OFST);
writel(~0U, slim_rproc->peri + SLIM_INT_CLR_OFST);
writel(~0U, slim_rproc->peri + SLIM_CMD_CLR_OFST);
writel(~0U, slim_rproc->peri + SLIM_INT_MASK_OFST);
writel(~0U, slim_rproc->peri + SLIM_CMD_MASK_OFST);
writel(SLIM_EN_RUN, slim_rproc->slimcore + SLIM_EN_OFST);
hw_id = readl_relaxed(slim_rproc->slimcore + SLIM_ID_OFST);
hw_ver = readl_relaxed(slim_rproc->slimcore + SLIM_VER_OFST);
fw_rev = readl(slim_rproc->mem[ST_SLIM_DMEM].cpu_addr +
SLIM_REV_ID_OFST);
dev_info(dev, "fw rev:%ld.%ld on SLIM %ld.%ld\n",
SLIM_REV_ID_MAJ(fw_rev), SLIM_REV_ID_MIN(fw_rev),
hw_id, hw_ver);
return 0;
}
static int slim_rproc_stop(struct rproc *rproc)
{
struct st_slim_rproc *slim_rproc = rproc->priv;
u32 val;
writel(0UL, slim_rproc->peri + SLIM_INT_MASK_OFST);
writel(0UL, slim_rproc->peri + SLIM_CMD_MASK_OFST);
writel(SLIM_CLK_GATE_DIS, slim_rproc->slimcore + SLIM_CLK_GATE_OFST);
writel(!SLIM_EN_RUN, slim_rproc->slimcore + SLIM_EN_OFST);
val = readl(slim_rproc->slimcore + SLIM_EN_OFST);
if (val & SLIM_EN_RUN)
dev_warn(&rproc->dev, "Failed to disable SLIM");
dev_dbg(&rproc->dev, "slim stopped\n");
return 0;
}
static void *slim_rproc_da_to_va(struct rproc *rproc, u64 da, int len)
{
struct st_slim_rproc *slim_rproc = rproc->priv;
void *va = NULL;
int i;
for (i = 0; i < ST_SLIM_MEM_MAX; i++) {
if (da != slim_rproc->mem[i].bus_addr)
continue;
if (len <= slim_rproc->mem[i].size) {
va = (__force void *)slim_rproc->mem[i].cpu_addr;
break;
}
}
dev_dbg(&rproc->dev, "da = 0x%llx len = 0x%x va = 0x%p\n", da, len, va);
return va;
}
static struct resource_table *slim_rproc_find_rsc_table(struct rproc *rproc,
const struct firmware *fw,
int *tablesz)
{
*tablesz = sizeof(empty_rsc_tbl);
return &empty_rsc_tbl;
}
struct st_slim_rproc *st_slim_rproc_alloc(struct platform_device *pdev,
char *fw_name)
{
struct device *dev = &pdev->dev;
struct st_slim_rproc *slim_rproc;
struct device_node *np = dev->of_node;
struct rproc *rproc;
struct resource *res;
int err, i;
const struct rproc_fw_ops *elf_ops;
if (!fw_name)
return ERR_PTR(-EINVAL);
if (!of_device_is_compatible(np, "st,slim-rproc"))
return ERR_PTR(-EINVAL);
rproc = rproc_alloc(dev, np->name, &slim_rproc_ops,
fw_name, sizeof(*slim_rproc));
if (!rproc)
return ERR_PTR(-ENOMEM);
rproc->has_iommu = false;
slim_rproc = rproc->priv;
slim_rproc->rproc = rproc;
elf_ops = rproc->fw_ops;
slim_rproc_fw_ops.load = elf_ops->load;
slim_rproc_fw_ops.sanity_check = elf_ops->sanity_check;
rproc->fw_ops = &slim_rproc_fw_ops;
for (i = 0; i < ARRAY_SIZE(mem_names); i++) {
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
mem_names[i]);
slim_rproc->mem[i].cpu_addr = devm_ioremap_resource(dev, res);
if (IS_ERR(slim_rproc->mem[i].cpu_addr)) {
dev_err(&pdev->dev, "devm_ioremap_resource failed\n");
err = PTR_ERR(slim_rproc->mem[i].cpu_addr);
goto err;
}
slim_rproc->mem[i].bus_addr = res->start;
slim_rproc->mem[i].size = resource_size(res);
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "slimcore");
slim_rproc->slimcore = devm_ioremap_resource(dev, res);
if (IS_ERR(slim_rproc->slimcore)) {
dev_err(&pdev->dev, "failed to ioremap slimcore IO\n");
err = PTR_ERR(slim_rproc->slimcore);
goto err;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "peripherals");
slim_rproc->peri = devm_ioremap_resource(dev, res);
if (IS_ERR(slim_rproc->peri)) {
dev_err(&pdev->dev, "failed to ioremap peripherals IO\n");
err = PTR_ERR(slim_rproc->peri);
goto err;
}
err = slim_clk_get(slim_rproc, dev);
if (err)
goto err;
err = slim_clk_enable(slim_rproc);
if (err) {
dev_err(dev, "Failed to enable clocks\n");
goto err_clk_put;
}
err = rproc_add(rproc);
if (err) {
dev_err(dev, "registration of slim remoteproc failed\n");
goto err_clk_dis;
}
return slim_rproc;
err_clk_dis:
slim_clk_disable(slim_rproc);
err_clk_put:
for (i = 0; i < ST_SLIM_MAX_CLK && slim_rproc->clks[i]; i++)
clk_put(slim_rproc->clks[i]);
err:
rproc_free(rproc);
return ERR_PTR(err);
}
void st_slim_rproc_put(struct st_slim_rproc *slim_rproc)
{
int clk;
if (!slim_rproc)
return;
slim_clk_disable(slim_rproc);
for (clk = 0; clk < ST_SLIM_MAX_CLK && slim_rproc->clks[clk]; clk++)
clk_put(slim_rproc->clks[clk]);
rproc_del(slim_rproc->rproc);
rproc_free(slim_rproc->rproc);
}
