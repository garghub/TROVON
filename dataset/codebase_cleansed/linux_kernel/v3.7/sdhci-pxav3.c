static void pxav3_set_private_registers(struct sdhci_host *host, u8 mask)
{
struct platform_device *pdev = to_platform_device(mmc_dev(host->mmc));
struct sdhci_pxa_platdata *pdata = pdev->dev.platform_data;
if (mask == SDHCI_RESET_ALL) {
if (pdata && 0 != pdata->clk_delay_cycles) {
u16 tmp;
tmp = readw(host->ioaddr + SD_CLOCK_BURST_SIZE_SETUP);
tmp |= (pdata->clk_delay_cycles & SDCLK_DELAY_MASK)
<< SDCLK_DELAY_SHIFT;
tmp |= SDCLK_SEL;
writew(tmp, host->ioaddr + SD_CLOCK_BURST_SIZE_SETUP);
}
}
}
static void pxav3_gen_init_74_clocks(struct sdhci_host *host, u8 power_mode)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_pxa *pxa = pltfm_host->priv;
u16 tmp;
int count;
if (pxa->power_mode == MMC_POWER_UP
&& power_mode == MMC_POWER_ON) {
dev_dbg(mmc_dev(host->mmc),
"%s: slot->power_mode = %d,"
"ios->power_mode = %d\n",
__func__,
pxa->power_mode,
power_mode);
tmp = readw(host->ioaddr + SD_CE_ATA_2);
tmp |= SDCE_MISC_INT_EN;
writew(tmp, host->ioaddr + SD_CE_ATA_2);
tmp = readw(host->ioaddr + SD_CFG_FIFO_PARAM);
tmp |= SDCFG_GEN_PAD_CLK_ON;
writew(tmp, host->ioaddr + SD_CFG_FIFO_PARAM);
udelay(740);
count = 0;
while (count++ < MAX_WAIT_COUNT) {
if ((readw(host->ioaddr + SD_CE_ATA_2)
& SDCE_MISC_INT) == 0)
break;
udelay(10);
}
if (count == MAX_WAIT_COUNT)
dev_warn(mmc_dev(host->mmc), "74 clock interrupt not cleared\n");
tmp = readw(host->ioaddr + SD_CE_ATA_2);
tmp |= SDCE_MISC_INT;
writew(tmp, host->ioaddr + SD_CE_ATA_2);
}
pxa->power_mode = power_mode;
}
static int pxav3_set_uhs_signaling(struct sdhci_host *host, unsigned int uhs)
{
u16 ctrl_2;
ctrl_2 = sdhci_readw(host, SDHCI_HOST_CONTROL2);
ctrl_2 &= ~SDHCI_CTRL_UHS_MASK;
switch (uhs) {
case MMC_TIMING_UHS_SDR12:
ctrl_2 |= SDHCI_CTRL_UHS_SDR12;
break;
case MMC_TIMING_UHS_SDR25:
ctrl_2 |= SDHCI_CTRL_UHS_SDR25;
break;
case MMC_TIMING_UHS_SDR50:
ctrl_2 |= SDHCI_CTRL_UHS_SDR50 | SDHCI_CTRL_VDD_180;
break;
case MMC_TIMING_UHS_SDR104:
ctrl_2 |= SDHCI_CTRL_UHS_SDR104 | SDHCI_CTRL_VDD_180;
break;
case MMC_TIMING_UHS_DDR50:
ctrl_2 |= SDHCI_CTRL_UHS_DDR50 | SDHCI_CTRL_VDD_180;
break;
}
sdhci_writew(host, ctrl_2, SDHCI_HOST_CONTROL2);
dev_dbg(mmc_dev(host->mmc),
"%s uhs = %d, ctrl_2 = %04X\n",
__func__, uhs, ctrl_2);
return 0;
}
static struct sdhci_pxa_platdata *pxav3_get_mmc_pdata(struct device *dev)
{
struct sdhci_pxa_platdata *pdata;
struct device_node *np = dev->of_node;
u32 bus_width;
u32 clk_delay_cycles;
enum of_gpio_flags gpio_flags;
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return NULL;
if (of_find_property(np, "non-removable", NULL))
pdata->flags |= PXA_FLAG_CARD_PERMANENT;
of_property_read_u32(np, "bus-width", &bus_width);
if (bus_width == 8)
pdata->flags |= PXA_FLAG_SD_8_BIT_CAPABLE_SLOT;
of_property_read_u32(np, "mrvl,clk-delay-cycles", &clk_delay_cycles);
if (clk_delay_cycles > 0)
pdata->clk_delay_cycles = clk_delay_cycles;
pdata->ext_cd_gpio = of_get_named_gpio_flags(np, "cd-gpios", 0, &gpio_flags);
if (gpio_flags != OF_GPIO_ACTIVE_LOW)
pdata->host_caps2 |= MMC_CAP2_CD_ACTIVE_HIGH;
return pdata;
}
static inline struct sdhci_pxa_platdata *pxav3_get_mmc_pdata(struct device *dev)
{
return NULL;
}
static int __devinit sdhci_pxav3_probe(struct platform_device *pdev)
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
host = sdhci_pltfm_init(pdev, NULL);
if (IS_ERR(host)) {
kfree(pxa);
return PTR_ERR(host);
}
pltfm_host = sdhci_priv(host);
pltfm_host->priv = pxa;
clk = clk_get(dev, NULL);
if (IS_ERR(clk)) {
dev_err(dev, "failed to get io clock\n");
ret = PTR_ERR(clk);
goto err_clk_get;
}
pltfm_host->clk = clk;
clk_prepare_enable(clk);
host->quirks = SDHCI_QUIRK_BROKEN_TIMEOUT_VAL
| SDHCI_QUIRK_NO_ENDATTR_IN_NOPDESC
| SDHCI_QUIRK_32BIT_ADMA_SIZE;
host->mmc->caps |= MMC_CAP_1_8V_DDR;
match = of_match_device(of_match_ptr(sdhci_pxav3_of_match), &pdev->dev);
if (match)
pdata = pxav3_get_mmc_pdata(dev);
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
if (pdata->host_caps2)
host->mmc->caps2 |= pdata->host_caps2;
if (pdata->pm_caps)
host->mmc->pm_caps |= pdata->pm_caps;
if (gpio_is_valid(pdata->ext_cd_gpio)) {
ret = mmc_gpio_request_cd(host->mmc, pdata->ext_cd_gpio);
if (ret) {
dev_err(mmc_dev(host->mmc),
"failed to allocate card detect gpio\n");
goto err_cd_req;
}
}
}
host->ops = &pxav3_sdhci_ops;
sdhci_get_of_property(pdev);
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
mmc_gpio_free_cd(host->mmc);
err_cd_req:
err_clk_get:
sdhci_pltfm_free(pdev);
kfree(pxa);
return ret;
}
static int __devexit sdhci_pxav3_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_pxa *pxa = pltfm_host->priv;
struct sdhci_pxa_platdata *pdata = pdev->dev.platform_data;
sdhci_remove_host(host, 1);
clk_disable_unprepare(pltfm_host->clk);
clk_put(pltfm_host->clk);
if (gpio_is_valid(pdata->ext_cd_gpio))
mmc_gpio_free_cd(host->mmc);
sdhci_pltfm_free(pdev);
kfree(pxa);
platform_set_drvdata(pdev, NULL);
return 0;
}
