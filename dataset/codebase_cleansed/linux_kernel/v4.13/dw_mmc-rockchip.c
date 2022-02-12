static void dw_mci_rk3288_set_ios(struct dw_mci *host, struct mmc_ios *ios)
{
struct dw_mci_rockchip_priv_data *priv = host->priv;
int ret;
unsigned int cclkin;
u32 bus_hz;
if (ios->clock == 0)
return;
if (ios->bus_width == MMC_BUS_WIDTH_8 &&
ios->timing == MMC_TIMING_MMC_DDR52)
cclkin = 2 * ios->clock * RK3288_CLKGEN_DIV;
else
cclkin = ios->clock * RK3288_CLKGEN_DIV;
ret = clk_set_rate(host->ciu_clk, cclkin);
if (ret)
dev_warn(host->dev, "failed to set rate %uHz\n", ios->clock);
bus_hz = clk_get_rate(host->ciu_clk) / RK3288_CLKGEN_DIV;
if (bus_hz != host->bus_hz) {
host->bus_hz = bus_hz;
host->current_speed = 0;
}
if (!IS_ERR(priv->sample_clk))
clk_set_phase(priv->sample_clk, priv->default_sample_phase);
if (!IS_ERR(priv->drv_clk)) {
int phase;
phase = 90;
switch (ios->timing) {
case MMC_TIMING_MMC_DDR52:
if (ios->bus_width == MMC_BUS_WIDTH_8)
phase = 180;
break;
case MMC_TIMING_UHS_SDR104:
case MMC_TIMING_MMC_HS200:
phase = 180;
break;
}
clk_set_phase(priv->drv_clk, phase);
}
}
static int dw_mci_rk3288_execute_tuning(struct dw_mci_slot *slot, u32 opcode)
{
struct dw_mci *host = slot->host;
struct dw_mci_rockchip_priv_data *priv = host->priv;
struct mmc_host *mmc = slot->mmc;
int ret = 0;
int i;
bool v, prev_v = 0, first_v;
struct range_t {
int start;
int end;
};
struct range_t *ranges;
unsigned int range_count = 0;
int longest_range_len = -1;
int longest_range = -1;
int middle_phase;
if (IS_ERR(priv->sample_clk)) {
dev_err(host->dev, "Tuning clock (sample_clk) not defined.\n");
return -EIO;
}
ranges = kmalloc_array(priv->num_phases / 2 + 1,
sizeof(*ranges), GFP_KERNEL);
if (!ranges)
return -ENOMEM;
for (i = 0; i < priv->num_phases; ) {
clk_set_phase(priv->sample_clk,
TUNING_ITERATION_TO_PHASE(i, priv->num_phases));
v = !mmc_send_tuning(mmc, opcode, NULL);
if (i == 0)
first_v = v;
if ((!prev_v) && v) {
range_count++;
ranges[range_count-1].start = i;
}
if (v) {
ranges[range_count-1].end = i;
i++;
} else if (i == priv->num_phases - 1) {
i++;
} else {
i += DIV_ROUND_UP(20 * priv->num_phases, 360);
if (i >= priv->num_phases)
i = priv->num_phases - 1;
}
prev_v = v;
}
if (range_count == 0) {
dev_warn(host->dev, "All phases bad!");
ret = -EIO;
goto free;
}
if ((range_count > 1) && first_v && v) {
ranges[0].start = ranges[range_count-1].start;
range_count--;
}
if (ranges[0].start == 0 && ranges[0].end == priv->num_phases - 1) {
clk_set_phase(priv->sample_clk, priv->default_sample_phase);
dev_info(host->dev, "All phases work, using default phase %d.",
priv->default_sample_phase);
goto free;
}
for (i = 0; i < range_count; i++) {
int len = (ranges[i].end - ranges[i].start + 1);
if (len < 0)
len += priv->num_phases;
if (longest_range_len < len) {
longest_range_len = len;
longest_range = i;
}
dev_dbg(host->dev, "Good phase range %d-%d (%d len)\n",
TUNING_ITERATION_TO_PHASE(ranges[i].start,
priv->num_phases),
TUNING_ITERATION_TO_PHASE(ranges[i].end,
priv->num_phases),
len
);
}
dev_dbg(host->dev, "Best phase range %d-%d (%d len)\n",
TUNING_ITERATION_TO_PHASE(ranges[longest_range].start,
priv->num_phases),
TUNING_ITERATION_TO_PHASE(ranges[longest_range].end,
priv->num_phases),
longest_range_len
);
middle_phase = ranges[longest_range].start + longest_range_len / 2;
middle_phase %= priv->num_phases;
dev_info(host->dev, "Successfully tuned phase to %d\n",
TUNING_ITERATION_TO_PHASE(middle_phase, priv->num_phases));
clk_set_phase(priv->sample_clk,
TUNING_ITERATION_TO_PHASE(middle_phase,
priv->num_phases));
free:
kfree(ranges);
return ret;
}
static int dw_mci_rk3288_parse_dt(struct dw_mci *host)
{
struct device_node *np = host->dev->of_node;
struct dw_mci_rockchip_priv_data *priv;
priv = devm_kzalloc(host->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
if (of_property_read_u32(np, "rockchip,desired-num-phases",
&priv->num_phases))
priv->num_phases = 360;
if (of_property_read_u32(np, "rockchip,default-sample-phase",
&priv->default_sample_phase))
priv->default_sample_phase = 0;
priv->drv_clk = devm_clk_get(host->dev, "ciu-drive");
if (IS_ERR(priv->drv_clk))
dev_dbg(host->dev, "ciu_drv not available\n");
priv->sample_clk = devm_clk_get(host->dev, "ciu-sample");
if (IS_ERR(priv->sample_clk))
dev_dbg(host->dev, "ciu_sample not available\n");
host->priv = priv;
return 0;
}
static int dw_mci_rockchip_init(struct dw_mci *host)
{
host->sdio_id0 = 8;
if (of_device_is_compatible(host->dev->of_node,
"rockchip,rk3288-dw-mshc"))
host->bus_hz /= RK3288_CLKGEN_DIV;
return 0;
}
static int dw_mci_rockchip_probe(struct platform_device *pdev)
{
const struct dw_mci_drv_data *drv_data;
const struct of_device_id *match;
int ret;
if (!pdev->dev.of_node)
return -ENODEV;
match = of_match_node(dw_mci_rockchip_match, pdev->dev.of_node);
drv_data = match->data;
pm_runtime_get_noresume(&pdev->dev);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
pm_runtime_set_autosuspend_delay(&pdev->dev, 50);
pm_runtime_use_autosuspend(&pdev->dev);
ret = dw_mci_pltfm_register(pdev, drv_data);
if (ret) {
pm_runtime_disable(&pdev->dev);
pm_runtime_set_suspended(&pdev->dev);
pm_runtime_put_noidle(&pdev->dev);
return ret;
}
pm_runtime_put_autosuspend(&pdev->dev);
return 0;
}
static int dw_mci_rockchip_remove(struct platform_device *pdev)
{
pm_runtime_get_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
pm_runtime_put_noidle(&pdev->dev);
return dw_mci_pltfm_remove(pdev);
}
