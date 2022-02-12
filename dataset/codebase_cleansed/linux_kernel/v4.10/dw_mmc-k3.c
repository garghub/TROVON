static void dw_mci_k3_set_ios(struct dw_mci *host, struct mmc_ios *ios)
{
int ret;
ret = clk_set_rate(host->ciu_clk, ios->clock);
if (ret)
dev_warn(host->dev, "failed to set rate %uHz\n", ios->clock);
host->bus_hz = clk_get_rate(host->ciu_clk);
}
static int dw_mci_hi6220_parse_dt(struct dw_mci *host)
{
struct k3_priv *priv;
priv = devm_kzalloc(host->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->reg = syscon_regmap_lookup_by_phandle(host->dev->of_node,
"hisilicon,peripheral-syscon");
if (IS_ERR(priv->reg))
priv->reg = NULL;
host->priv = priv;
return 0;
}
static int dw_mci_hi6220_switch_voltage(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct dw_mci_slot *slot = mmc_priv(mmc);
struct k3_priv *priv;
struct dw_mci *host;
int min_uv, max_uv;
int ret;
host = slot->host;
priv = host->priv;
if (!priv || !priv->reg)
return 0;
if (ios->signal_voltage == MMC_SIGNAL_VOLTAGE_330) {
ret = regmap_update_bits(priv->reg, AO_SCTRL_CTRL3,
AO_SCTRL_SEL18, 0);
min_uv = 3000000;
max_uv = 3000000;
} else if (ios->signal_voltage == MMC_SIGNAL_VOLTAGE_180) {
ret = regmap_update_bits(priv->reg, AO_SCTRL_CTRL3,
AO_SCTRL_SEL18, AO_SCTRL_SEL18);
min_uv = 1800000;
max_uv = 1800000;
} else {
dev_dbg(host->dev, "voltage not supported\n");
return -EINVAL;
}
if (ret) {
dev_dbg(host->dev, "switch voltage failed\n");
return ret;
}
if (IS_ERR_OR_NULL(mmc->supply.vqmmc))
return 0;
ret = regulator_set_voltage(mmc->supply.vqmmc, min_uv, max_uv);
if (ret) {
dev_dbg(host->dev, "Regulator set error %d: %d - %d\n",
ret, min_uv, max_uv);
return ret;
}
return 0;
}
static void dw_mci_hi6220_set_ios(struct dw_mci *host, struct mmc_ios *ios)
{
int ret;
unsigned int clock;
clock = (ios->clock <= 25000000) ? 25000000 : ios->clock;
ret = clk_set_rate(host->biu_clk, clock);
if (ret)
dev_warn(host->dev, "failed to set rate %uHz\n", clock);
host->bus_hz = clk_get_rate(host->biu_clk);
}
static int dw_mci_hi6220_execute_tuning(struct dw_mci_slot *slot, u32 opcode)
{
return 0;
}
static int dw_mci_k3_probe(struct platform_device *pdev)
{
const struct dw_mci_drv_data *drv_data;
const struct of_device_id *match;
match = of_match_node(dw_mci_k3_match, pdev->dev.of_node);
drv_data = match->data;
return dw_mci_pltfm_register(pdev, drv_data);
}
