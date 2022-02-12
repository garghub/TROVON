static void pxav2_set_private_registers(struct sdhci_host *host, u8 mask)
{
struct platform_device *pdev = to_platform_device(mmc_dev(host->mmc));
struct sdhci_pxa_platdata *pdata = pdev->dev.platform_data;
if (mask == SDHCI_RESET_ALL) {
u16 tmp = 0;
if (pdata && pdata->clk_delay_sel == 1) {
tmp = readw(host->ioaddr + SD_CLOCK_BURST_SIZE_SETUP);
tmp &= ~(SDCLK_DELAY_MASK << SDCLK_DELAY_SHIFT);
tmp |= (pdata->clk_delay_cycles & SDCLK_DELAY_MASK)
<< SDCLK_DELAY_SHIFT;
tmp &= ~(SDCLK_SEL_MASK << SDCLK_SEL_SHIFT);
tmp |= (1 & SDCLK_SEL_MASK) << SDCLK_SEL_SHIFT;
writew(tmp, host->ioaddr + SD_CLOCK_BURST_SIZE_SETUP);
}
if (pdata && (pdata->flags & PXA_FLAG_ENABLE_CLOCK_GATING)) {
tmp = readw(host->ioaddr + SD_FIFO_PARAM);
tmp &= ~CLK_GATE_SETTING_BITS;
writew(tmp, host->ioaddr + SD_FIFO_PARAM);
} else {
tmp = readw(host->ioaddr + SD_FIFO_PARAM);
tmp &= ~CLK_GATE_SETTING_BITS;
tmp |= CLK_GATE_SETTING_BITS;
writew(tmp, host->ioaddr + SD_FIFO_PARAM);
}
}
}
static int pxav2_mmc_set_width(struct sdhci_host *host, int width)
{
u8 ctrl;
u16 tmp;
ctrl = readb(host->ioaddr + SDHCI_HOST_CONTROL);
tmp = readw(host->ioaddr + SD_CE_ATA_2);
if (width == MMC_BUS_WIDTH_8) {
ctrl &= ~SDHCI_CTRL_4BITBUS;
tmp |= MMC_CARD | MMC_WIDTH;
} else {
tmp &= ~(MMC_CARD | MMC_WIDTH);
if (width == MMC_BUS_WIDTH_4)
ctrl |= SDHCI_CTRL_4BITBUS;
else
ctrl &= ~SDHCI_CTRL_4BITBUS;
}
writew(tmp, host->ioaddr + SD_CE_ATA_2);
writeb(ctrl, host->ioaddr + SDHCI_HOST_CONTROL);
return 0;
}
static struct sdhci_pxa_platdata *pxav2_get_mmc_pdata(struct device *dev)
{
struct sdhci_pxa_platdata *pdata;
struct device_node *np = dev->of_node;
u32 bus_width;
u32 clk_delay_cycles;
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return NULL;
if (of_find_property(np, "non-removable", NULL))
pdata->flags |= PXA_FLAG_CARD_PERMANENT;
of_property_read_u32(np, "bus-width", &bus_width);
if (bus_width == 8)
pdata->flags |= PXA_FLAG_SD_8_BIT_CAPABLE_SLOT;
of_property_read_u32(np, "mrvl,clk-delay-cycles", &clk_delay_cycles);
if (clk_delay_cycles > 0) {
pdata->clk_delay_sel = 1;
pdata->clk_delay_cycles = clk_delay_cycles;
}
return pdata;
}
static inline struct sdhci_pxa_platdata *pxav2_get_mmc_pdata(struct device *dev)
{
return NULL;
}
static int sdhci_pxav2_probe(struct platform_device *pdev)
{
struct sdhci_pltfm_host *pltfm_host;
struct sdhci_pxa_platdata *pdata = pdev->dev.platform_data;
struct device *dev = &pdev->dev;
struct sdhci_host *host = NULL;
struct sdhci_pxa *pxa = NULL;
const struct of_device_id *match;
int ret;
struct clk *clk;
pxa = kzalloc(sizeof(struct sdhci_pxa), GFP_KERNEL);
if (!pxa)
return -ENOMEM;
host = sdhci_pltfm_init(pdev, NULL, 0);
if (IS_ERR(host)) {
kfree(pxa);
return PTR_ERR(host);
}
pltfm_host = sdhci_priv(host);
pltfm_host->priv = pxa;
clk = clk_get(dev, "PXA-SDHCLK");
if (IS_ERR(clk)) {
dev_err(dev, "failed to get io clock\n");
ret = PTR_ERR(clk);
goto err_clk_get;
}
pltfm_host->clk = clk;
clk_prepare_enable(clk);
host->quirks = SDHCI_QUIRK_BROKEN_ADMA
| SDHCI_QUIRK_BROKEN_TIMEOUT_VAL
| SDHCI_QUIRK_CAP_CLOCK_BASE_BROKEN;
match = of_match_device(of_match_ptr(sdhci_pxav2_of_match), &pdev->dev);
if (match) {
pdata = pxav2_get_mmc_pdata(dev);
}
if (pdata) {
if (pdata->flags & PXA_FLAG_CARD_PERMANENT) {
host->quirks |= SDHCI_QUIRK_BROKEN_CARD_DETECTION;
host->mmc->caps |= MMC_CAP_NONREMOVABLE;
}
if (pdata->flags & PXA_FLAG_SD_8_BIT_CAPABLE_SLOT)
host->mmc->caps |= MMC_CAP_8_BIT_DATA;
if (pdata->quirks)
host->quirks |= pdata->quirks;
if (pdata->host_caps)
host->mmc->caps |= pdata->host_caps;
if (pdata->pm_caps)
host->mmc->pm_caps |= pdata->pm_caps;
}
host->ops = &pxav2_sdhci_ops;
ret = sdhci_add_host(host);
if (ret) {
dev_err(&pdev->dev, "failed to add host\n");
goto err_add_host;
}
platform_set_drvdata(pdev, host);
return 0;
err_add_host:
clk_disable_unprepare(clk);
clk_put(clk);
err_clk_get:
sdhci_pltfm_free(pdev);
kfree(pxa);
return ret;
}
static int sdhci_pxav2_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_pxa *pxa = pltfm_host->priv;
sdhci_remove_host(host, 1);
clk_disable_unprepare(pltfm_host->clk);
clk_put(pltfm_host->clk);
sdhci_pltfm_free(pdev);
kfree(pxa);
return 0;
}
