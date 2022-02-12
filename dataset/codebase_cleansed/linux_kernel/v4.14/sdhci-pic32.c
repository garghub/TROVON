static unsigned int pic32_sdhci_get_max_clock(struct sdhci_host *host)
{
struct pic32_sdhci_priv *sdhci_pdata = sdhci_priv(host);
return clk_get_rate(sdhci_pdata->base_clk);
}
static void pic32_sdhci_set_bus_width(struct sdhci_host *host, int width)
{
u8 ctrl;
ctrl = sdhci_readb(host, SDHCI_HOST_CONTROL);
if (width == MMC_BUS_WIDTH_8) {
ctrl &= ~SDHCI_CTRL_4BITBUS;
if (host->version >= SDHCI_SPEC_300)
ctrl |= SDHCI_CTRL_8BITBUS;
} else {
if (host->version >= SDHCI_SPEC_300)
ctrl &= ~SDHCI_CTRL_8BITBUS;
if (width == MMC_BUS_WIDTH_4)
ctrl |= SDHCI_CTRL_4BITBUS;
else
ctrl &= ~SDHCI_CTRL_4BITBUS;
}
ctrl &= ~SDHCI_CTRL_CDTLVL;
ctrl |= SDHCI_CTRL_CDSSEL;
sdhci_writeb(host, ctrl, SDHCI_HOST_CONTROL);
}
static unsigned int pic32_sdhci_get_ro(struct sdhci_host *host)
{
return 0;
}
static void pic32_sdhci_shared_bus(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
u32 bus = readl(host->ioaddr + SDH_SHARED_BUS_CTRL);
u32 clk_pins = (bus & SDH_SHARED_BUS_NR_CLK_PINS_MASK) >> 0;
u32 irq_pins = (bus & SDH_SHARED_BUS_NR_IRQ_PINS_MASK) >> 4;
if (clk_pins & 1)
bus |= (1 << SDH_SHARED_BUS_CLK_PINS);
if (irq_pins & 1)
bus |= (1 << SDH_SHARED_BUS_IRQ_PINS);
writel(bus, host->ioaddr + SDH_SHARED_BUS_CTRL);
}
static int pic32_sdhci_probe_platform(struct platform_device *pdev,
struct pic32_sdhci_priv *pdata)
{
int ret = 0;
u32 caps_slot_type;
struct sdhci_host *host = platform_get_drvdata(pdev);
host->caps = readl(host->ioaddr + SDHCI_CAPABILITIES);
caps_slot_type = (host->caps & SDH_CAPS_SDH_SLOT_TYPE_MASK) >> 30;
if (caps_slot_type == SDH_SLOT_TYPE_SHARED_BUS)
pic32_sdhci_shared_bus(pdev);
return ret;
}
static int pic32_sdhci_probe(struct platform_device *pdev)
{
struct sdhci_host *host;
struct sdhci_pltfm_host *pltfm_host;
struct pic32_sdhci_priv *sdhci_pdata;
struct pic32_sdhci_platform_data *plat_data;
int ret;
host = sdhci_pltfm_init(pdev, &sdhci_pic32_pdata,
sizeof(struct pic32_sdhci_priv));
if (IS_ERR(host)) {
ret = PTR_ERR(host);
goto err;
}
pltfm_host = sdhci_priv(host);
sdhci_pdata = sdhci_pltfm_priv(pltfm_host);
plat_data = pdev->dev.platform_data;
if (plat_data && plat_data->setup_dma) {
ret = plat_data->setup_dma(ADMA_FIFO_RD_THSHLD,
ADMA_FIFO_WR_THSHLD);
if (ret)
goto err_host;
}
sdhci_pdata->sys_clk = devm_clk_get(&pdev->dev, "sys_clk");
if (IS_ERR(sdhci_pdata->sys_clk)) {
ret = PTR_ERR(sdhci_pdata->sys_clk);
dev_err(&pdev->dev, "Error getting clock\n");
goto err_host;
}
ret = clk_prepare_enable(sdhci_pdata->sys_clk);
if (ret) {
dev_err(&pdev->dev, "Error enabling clock\n");
goto err_host;
}
sdhci_pdata->base_clk = devm_clk_get(&pdev->dev, "base_clk");
if (IS_ERR(sdhci_pdata->base_clk)) {
ret = PTR_ERR(sdhci_pdata->base_clk);
dev_err(&pdev->dev, "Error getting clock\n");
goto err_sys_clk;
}
ret = clk_prepare_enable(sdhci_pdata->base_clk);
if (ret) {
dev_err(&pdev->dev, "Error enabling clock\n");
goto err_base_clk;
}
ret = mmc_of_parse(host->mmc);
if (ret)
goto err_base_clk;
ret = pic32_sdhci_probe_platform(pdev, sdhci_pdata);
if (ret) {
dev_err(&pdev->dev, "failed to probe platform!\n");
goto err_base_clk;
}
ret = sdhci_add_host(host);
if (ret) {
dev_err(&pdev->dev, "error adding host\n");
goto err_base_clk;
}
dev_info(&pdev->dev, "Successfully added sdhci host\n");
return 0;
err_base_clk:
clk_disable_unprepare(sdhci_pdata->base_clk);
err_sys_clk:
clk_disable_unprepare(sdhci_pdata->sys_clk);
err_host:
sdhci_pltfm_free(pdev);
err:
dev_err(&pdev->dev, "pic32-sdhci probe failed: %d\n", ret);
return ret;
}
static int pic32_sdhci_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct pic32_sdhci_priv *sdhci_pdata = sdhci_priv(host);
u32 scratch;
scratch = readl(host->ioaddr + SDHCI_INT_STATUS);
sdhci_remove_host(host, scratch == (u32)~0);
clk_disable_unprepare(sdhci_pdata->base_clk);
clk_disable_unprepare(sdhci_pdata->sys_clk);
sdhci_pltfm_free(pdev);
return 0;
}
