static int st_rproc_start(struct rproc *rproc)
{
struct st_rproc *ddata = rproc->priv;
int err;
regmap_update_bits(ddata->boot_base, ddata->boot_offset,
ddata->config->bootaddr_mask, rproc->bootaddr);
err = clk_enable(ddata->clk);
if (err) {
dev_err(&rproc->dev, "Failed to enable clock\n");
return err;
}
if (ddata->config->sw_reset) {
err = reset_control_deassert(ddata->sw_reset);
if (err) {
dev_err(&rproc->dev, "Failed to deassert S/W Reset\n");
goto sw_reset_fail;
}
}
if (ddata->config->pwr_reset) {
err = reset_control_deassert(ddata->pwr_reset);
if (err) {
dev_err(&rproc->dev, "Failed to deassert Power Reset\n");
goto pwr_reset_fail;
}
}
dev_info(&rproc->dev, "Started from 0x%x\n", rproc->bootaddr);
return 0;
pwr_reset_fail:
if (ddata->config->pwr_reset)
reset_control_assert(ddata->sw_reset);
sw_reset_fail:
clk_disable(ddata->clk);
return err;
}
static int st_rproc_stop(struct rproc *rproc)
{
struct st_rproc *ddata = rproc->priv;
int sw_err = 0, pwr_err = 0;
if (ddata->config->sw_reset) {
sw_err = reset_control_assert(ddata->sw_reset);
if (sw_err)
dev_err(&rproc->dev, "Failed to assert S/W Reset\n");
}
if (ddata->config->pwr_reset) {
pwr_err = reset_control_assert(ddata->pwr_reset);
if (pwr_err)
dev_err(&rproc->dev, "Failed to assert Power Reset\n");
}
clk_disable(ddata->clk);
return sw_err ?: pwr_err;
}
static int st_rproc_state(struct platform_device *pdev)
{
struct rproc *rproc = platform_get_drvdata(pdev);
struct st_rproc *ddata = rproc->priv;
int reset_sw = 0, reset_pwr = 0;
if (ddata->config->sw_reset)
reset_sw = reset_control_status(ddata->sw_reset);
if (ddata->config->pwr_reset)
reset_pwr = reset_control_status(ddata->pwr_reset);
if (reset_sw < 0 || reset_pwr < 0)
return -EINVAL;
return !reset_sw && !reset_pwr;
}
static int st_rproc_parse_dt(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct rproc *rproc = platform_get_drvdata(pdev);
struct st_rproc *ddata = rproc->priv;
struct device_node *np = dev->of_node;
int err;
if (ddata->config->sw_reset) {
ddata->sw_reset = devm_reset_control_get(dev, "sw_reset");
if (IS_ERR(ddata->sw_reset)) {
dev_err(dev, "Failed to get S/W Reset\n");
return PTR_ERR(ddata->sw_reset);
}
}
if (ddata->config->pwr_reset) {
ddata->pwr_reset = devm_reset_control_get(dev, "pwr_reset");
if (IS_ERR(ddata->pwr_reset)) {
dev_err(dev, "Failed to get Power Reset\n");
return PTR_ERR(ddata->pwr_reset);
}
}
ddata->clk = devm_clk_get(dev, NULL);
if (IS_ERR(ddata->clk)) {
dev_err(dev, "Failed to get clock\n");
return PTR_ERR(ddata->clk);
}
err = of_property_read_u32(np, "clock-frequency", &ddata->clk_rate);
if (err) {
dev_err(dev, "failed to get clock frequency\n");
return err;
}
ddata->boot_base = syscon_regmap_lookup_by_phandle(np, "st,syscfg");
if (IS_ERR(ddata->boot_base)) {
dev_err(dev, "Boot base not found\n");
return PTR_ERR(ddata->boot_base);
}
err = of_property_read_u32_index(np, "st,syscfg", 1,
&ddata->boot_offset);
if (err) {
dev_err(dev, "Boot offset not found\n");
return -EINVAL;
}
err = of_reserved_mem_device_init(dev);
if (err) {
dev_err(dev, "Failed to obtain shared memory\n");
return err;
}
err = clk_prepare(ddata->clk);
if (err)
dev_err(dev, "failed to get clock\n");
return err;
}
static int st_rproc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct of_device_id *match;
struct st_rproc *ddata;
struct device_node *np = dev->of_node;
struct rproc *rproc;
int enabled;
int ret;
match = of_match_device(st_rproc_match, dev);
if (!match || !match->data) {
dev_err(dev, "No device match found\n");
return -ENODEV;
}
rproc = rproc_alloc(dev, np->name, &st_rproc_ops, NULL, sizeof(*ddata));
if (!rproc)
return -ENOMEM;
rproc->has_iommu = false;
ddata = rproc->priv;
ddata->config = (struct st_rproc_config *)match->data;
platform_set_drvdata(pdev, rproc);
ret = st_rproc_parse_dt(pdev);
if (ret)
goto free_rproc;
enabled = st_rproc_state(pdev);
if (enabled < 0)
goto free_rproc;
if (enabled) {
atomic_inc(&rproc->power);
rproc->state = RPROC_RUNNING;
} else {
clk_set_rate(ddata->clk, ddata->clk_rate);
}
ret = rproc_add(rproc);
if (ret)
goto free_rproc;
return 0;
free_rproc:
rproc_free(rproc);
return ret;
}
static int st_rproc_remove(struct platform_device *pdev)
{
struct rproc *rproc = platform_get_drvdata(pdev);
struct st_rproc *ddata = rproc->priv;
rproc_del(rproc);
clk_disable_unprepare(ddata->clk);
of_reserved_mem_device_release(&pdev->dev);
rproc_free(rproc);
return 0;
}
