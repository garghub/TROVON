static int dw_mci_exynos_priv_init(struct dw_mci *host)
{
struct dw_mci_exynos_priv_data *priv;
int idx;
priv = devm_kzalloc(host->dev, sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(host->dev, "mem alloc failed for private data\n");
return -ENOMEM;
}
for (idx = 0; idx < ARRAY_SIZE(exynos_compat); idx++) {
if (of_device_is_compatible(host->dev->of_node,
exynos_compat[idx].compatible))
priv->ctrl_type = exynos_compat[idx].ctrl_type;
}
host->priv = priv;
return 0;
}
static int dw_mci_exynos_setup_clock(struct dw_mci *host)
{
struct dw_mci_exynos_priv_data *priv = host->priv;
if (priv->ctrl_type == DW_MCI_TYPE_EXYNOS5250)
host->bus_hz /= (priv->ciu_div + 1);
else if (priv->ctrl_type == DW_MCI_TYPE_EXYNOS4412)
host->bus_hz /= EXYNOS4412_FIXED_CIU_CLK_DIV;
else if (priv->ctrl_type == DW_MCI_TYPE_EXYNOS4210)
host->bus_hz /= EXYNOS4210_FIXED_CIU_CLK_DIV;
return 0;
}
static void dw_mci_exynos_prepare_command(struct dw_mci *host, u32 *cmdr)
{
if (SDMMC_CLKSEL_GET_DRV_WD3(mci_readl(host, CLKSEL)))
*cmdr |= SDMMC_CMD_USE_HOLD_REG;
}
static void dw_mci_exynos_set_ios(struct dw_mci *host, struct mmc_ios *ios)
{
struct dw_mci_exynos_priv_data *priv = host->priv;
if (ios->timing == MMC_TIMING_UHS_DDR50)
mci_writel(host, CLKSEL, priv->ddr_timing);
else
mci_writel(host, CLKSEL, priv->sdr_timing);
}
static int dw_mci_exynos_parse_dt(struct dw_mci *host)
{
struct dw_mci_exynos_priv_data *priv = host->priv;
struct device_node *np = host->dev->of_node;
u32 timing[2];
u32 div = 0;
int ret;
of_property_read_u32(np, "samsung,dw-mshc-ciu-div", &div);
priv->ciu_div = div;
ret = of_property_read_u32_array(np,
"samsung,dw-mshc-sdr-timing", timing, 2);
if (ret)
return ret;
priv->sdr_timing = SDMMC_CLKSEL_TIMING(timing[0], timing[1], div);
ret = of_property_read_u32_array(np,
"samsung,dw-mshc-ddr-timing", timing, 2);
if (ret)
return ret;
priv->ddr_timing = SDMMC_CLKSEL_TIMING(timing[0], timing[1], div);
return 0;
}
static int dw_mci_exynos_setup_bus(struct dw_mci *host,
struct device_node *slot_np, u8 bus_width)
{
int idx, gpio, ret;
if (!slot_np)
return -EINVAL;
for (idx = 0; idx < NUM_PINS(bus_width); idx++) {
gpio = of_get_gpio(slot_np, idx);
if (!gpio_is_valid(gpio)) {
dev_err(host->dev, "invalid gpio: %d\n", gpio);
return -EINVAL;
}
ret = devm_gpio_request(host->dev, gpio, "dw-mci-bus");
if (ret) {
dev_err(host->dev, "gpio [%d] request failed\n", gpio);
return -EBUSY;
}
}
if (host->pdata->quirks & DW_MCI_QUIRK_BROKEN_CARD_DETECTION)
return 0;
gpio = of_get_named_gpio(slot_np, "samsung,cd-pinmux-gpio", 0);
if (gpio_is_valid(gpio)) {
if (devm_gpio_request(host->dev, gpio, "dw-mci-cd"))
dev_err(host->dev, "gpio [%d] request failed\n", gpio);
} else {
dev_info(host->dev, "cd gpio not available");
}
return 0;
}
int dw_mci_exynos_probe(struct platform_device *pdev)
{
const struct dw_mci_drv_data *drv_data;
const struct of_device_id *match;
match = of_match_node(dw_mci_exynos_match, pdev->dev.of_node);
drv_data = match->data;
return dw_mci_pltfm_register(pdev, drv_data);
}
