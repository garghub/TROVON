static int dw_mci_socfpga_priv_init(struct dw_mci *host)
{
struct dw_mci_socfpga_priv_data *priv;
priv = devm_kzalloc(host->dev, sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(host->dev, "mem alloc failed for private data\n");
return -ENOMEM;
}
priv->sysreg = syscon_regmap_lookup_by_compatible("altr,sys-mgr");
if (IS_ERR(priv->sysreg)) {
dev_err(host->dev, "regmap for altr,sys-mgr lookup failed.\n");
return PTR_ERR(priv->sysreg);
}
host->priv = priv;
return 0;
}
static int dw_mci_socfpga_setup_clock(struct dw_mci *host)
{
struct dw_mci_socfpga_priv_data *priv = host->priv;
clk_disable_unprepare(host->ciu_clk);
regmap_write(priv->sysreg, SYSMGR_SDMMCGRP_CTRL_OFFSET,
priv->hs_timing);
clk_prepare_enable(host->ciu_clk);
host->bus_hz /= (priv->ciu_div + 1);
return 0;
}
static void dw_mci_socfpga_prepare_command(struct dw_mci *host, u32 *cmdr)
{
struct dw_mci_socfpga_priv_data *priv = host->priv;
if (priv->hs_timing & DRV_CLK_PHASE_SHIFT_SEL_MASK)
*cmdr |= SDMMC_CMD_USE_HOLD_REG;
}
static int dw_mci_socfpga_parse_dt(struct dw_mci *host)
{
struct dw_mci_socfpga_priv_data *priv = host->priv;
struct device_node *np = host->dev->of_node;
u32 timing[2];
u32 div = 0;
int ret;
ret = of_property_read_u32(np, "altr,dw-mshc-ciu-div", &div);
if (ret)
dev_info(host->dev, "No dw-mshc-ciu-div specified, assuming 1");
priv->ciu_div = div;
ret = of_property_read_u32_array(np,
"altr,dw-mshc-sdr-timing", timing, 2);
if (ret)
return ret;
priv->hs_timing = SYSMGR_SDMMC_CTRL_SET(timing[0], timing[1]);
return 0;
}
int dw_mci_socfpga_probe(struct platform_device *pdev)
{
const struct dw_mci_drv_data *drv_data;
const struct of_device_id *match;
match = of_match_node(dw_mci_socfpga_match, pdev->dev.of_node);
drv_data = match->data;
return dw_mci_pltfm_register(pdev, drv_data);
}
