static void sh_mobile_sdhi_sdbuf_width(struct tmio_mmc_host *host, int width)
{
u32 val;
switch (sd_ctrl_read16(host, CTL_VERSION)) {
case 0x490C:
val = (width == 32) ? 0x0001 : 0x0000;
break;
case 0xCB0D:
val = (width == 32) ? 0x0000 : 0x0001;
break;
case 0xCC10:
case 0xCD10:
if (width == 64)
val = 0x0000;
else if (width == 32)
val = 0x0101;
else
val = 0x0001;
break;
default:
return;
}
sd_ctrl_write16(host, EXT_ACC, val);
}
static int sh_mobile_sdhi_clk_enable(struct tmio_mmc_host *host)
{
struct mmc_host *mmc = host->mmc;
struct sh_mobile_sdhi *priv = host_to_priv(host);
int ret = clk_prepare_enable(priv->clk);
if (ret < 0)
return ret;
if (!mmc->f_max)
mmc->f_max = clk_get_rate(priv->clk);
mmc->f_min = max(clk_round_rate(priv->clk, 1) / 512, 1L);
sh_mobile_sdhi_sdbuf_width(host, 16);
return 0;
}
static unsigned int sh_mobile_sdhi_clk_update(struct tmio_mmc_host *host,
unsigned int new_clock)
{
struct sh_mobile_sdhi *priv = host_to_priv(host);
unsigned int freq, diff, best_freq = 0, diff_min = ~0;
int i, ret;
if (!(host->pdata->flags & TMIO_MMC_MIN_RCAR2))
return clk_get_rate(priv->clk);
for (i = min(9, ilog2(UINT_MAX / new_clock)); i >= 0; i--) {
freq = clk_round_rate(priv->clk, new_clock << i);
if (freq > (new_clock << i)) {
freq = clk_round_rate(priv->clk,
(new_clock << i) / 4 * 3);
if (freq > (new_clock << i))
continue;
}
diff = new_clock - (freq >> i);
if (diff <= diff_min) {
best_freq = freq;
diff_min = diff;
}
}
ret = clk_set_rate(priv->clk, best_freq);
return ret == 0 ? best_freq : clk_get_rate(priv->clk);
}
static void sh_mobile_sdhi_clk_disable(struct tmio_mmc_host *host)
{
struct sh_mobile_sdhi *priv = host_to_priv(host);
clk_disable_unprepare(priv->clk);
}
static int sh_mobile_sdhi_start_signal_voltage_switch(struct mmc_host *mmc,
struct mmc_ios *ios)
{
struct tmio_mmc_host *host = mmc_priv(mmc);
struct sh_mobile_sdhi *priv = host_to_priv(host);
struct pinctrl_state *pin_state;
int ret;
switch (ios->signal_voltage) {
case MMC_SIGNAL_VOLTAGE_330:
pin_state = priv->pins_default;
break;
case MMC_SIGNAL_VOLTAGE_180:
pin_state = priv->pins_uhs;
break;
default:
return -EINVAL;
}
if (IS_ERR(priv->pinctrl) || IS_ERR(pin_state))
return ios->signal_voltage ==
MMC_SIGNAL_VOLTAGE_330 ? 0 : -EINVAL;
ret = mmc_regulator_set_vqmmc(host->mmc, ios);
if (ret)
return ret;
return pinctrl_select_state(priv->pinctrl, pin_state);
}
static int sh_mobile_sdhi_wait_idle(struct tmio_mmc_host *host)
{
int timeout = 1000;
while (--timeout && !(sd_ctrl_read16_and_16_as_32(host, CTL_STATUS)
& TMIO_STAT_SCLKDIVEN))
udelay(1);
if (!timeout) {
dev_warn(&host->pdev->dev, "timeout waiting for SD bus idle\n");
return -EBUSY;
}
return 0;
}
static int sh_mobile_sdhi_write16_hook(struct tmio_mmc_host *host, int addr)
{
switch (addr)
{
case CTL_SD_CMD:
case CTL_STOP_INTERNAL_ACTION:
case CTL_XFER_BLK_COUNT:
case CTL_SD_CARD_CLK_CTL:
case CTL_SD_XFER_LEN:
case CTL_SD_MEM_CARD_OPT:
case CTL_TRANSACTION_CTL:
case CTL_DMA_ENABLE:
case EXT_ACC:
return sh_mobile_sdhi_wait_idle(host);
}
return 0;
}
static int sh_mobile_sdhi_multi_io_quirk(struct mmc_card *card,
unsigned int direction, int blk_size)
{
if ((direction == MMC_DATA_READ) &&
blk_size == 2)
return 1;
return blk_size;
}
static void sh_mobile_sdhi_enable_dma(struct tmio_mmc_host *host, bool enable)
{
sd_ctrl_write16(host, CTL_DMA_ENABLE, enable ? 2 : 0);
sh_mobile_sdhi_sdbuf_width(host, enable ? 32 : 16);
}
static int sh_mobile_sdhi_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(sh_mobile_sdhi_of_match, &pdev->dev);
struct sh_mobile_sdhi *priv;
struct tmio_mmc_data *mmc_data;
struct tmio_mmc_data *mmd = pdev->dev.platform_data;
struct tmio_mmc_host *host;
struct resource *res;
int irq, ret, i = 0;
struct tmio_mmc_dma *dma_priv;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -EINVAL;
priv = devm_kzalloc(&pdev->dev, sizeof(struct sh_mobile_sdhi), GFP_KERNEL);
if (!priv)
return -ENOMEM;
mmc_data = &priv->mmc_data;
dma_priv = &priv->dma_priv;
priv->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(priv->clk)) {
ret = PTR_ERR(priv->clk);
dev_err(&pdev->dev, "cannot get clock: %d\n", ret);
goto eprobe;
}
priv->pinctrl = devm_pinctrl_get(&pdev->dev);
if (!IS_ERR(priv->pinctrl)) {
priv->pins_default = pinctrl_lookup_state(priv->pinctrl,
PINCTRL_STATE_DEFAULT);
priv->pins_uhs = pinctrl_lookup_state(priv->pinctrl,
"state_uhs");
}
host = tmio_mmc_host_alloc(pdev);
if (!host) {
ret = -ENOMEM;
goto eprobe;
}
if (of_id && of_id->data) {
const struct sh_mobile_sdhi_of_data *of_data = of_id->data;
mmc_data->flags |= of_data->tmio_flags;
mmc_data->capabilities |= of_data->capabilities;
mmc_data->capabilities2 |= of_data->capabilities2;
mmc_data->dma_rx_offset = of_data->dma_rx_offset;
dma_priv->dma_buswidth = of_data->dma_buswidth;
host->bus_shift = of_data->bus_shift;
}
host->dma = dma_priv;
host->write16_hook = sh_mobile_sdhi_write16_hook;
host->clk_enable = sh_mobile_sdhi_clk_enable;
host->clk_update = sh_mobile_sdhi_clk_update;
host->clk_disable = sh_mobile_sdhi_clk_disable;
host->multi_io_quirk = sh_mobile_sdhi_multi_io_quirk;
host->start_signal_voltage_switch = sh_mobile_sdhi_start_signal_voltage_switch;
if (!host->bus_shift && resource_size(res) > 0x100)
host->bus_shift = 1;
if (mmd)
*mmc_data = *mmd;
dma_priv->filter = shdma_chan_filter;
dma_priv->enable = sh_mobile_sdhi_enable_dma;
mmc_data->alignment_shift = 1;
mmc_data->capabilities |= MMC_CAP_MMC_HIGHSPEED;
mmc_data->flags |= TMIO_MMC_BLKSZ_2BYTES;
mmc_data->flags |= TMIO_MMC_SDIO_IRQ;
mmc_data->flags |= TMIO_MMC_HAVE_CMD12_CTRL;
mmc_data->flags |= TMIO_MMC_SDIO_STATUS_QUIRK;
ret = tmio_mmc_host_probe(host, mmc_data);
if (ret < 0)
goto efree;
while (1) {
irq = platform_get_irq(pdev, i);
if (irq < 0)
break;
i++;
ret = devm_request_irq(&pdev->dev, irq, tmio_mmc_irq, 0,
dev_name(&pdev->dev), host);
if (ret)
goto eirq;
}
if (!i) {
ret = irq;
goto eirq;
}
dev_info(&pdev->dev, "%s base at 0x%08lx max clock rate %u MHz\n",
mmc_hostname(host->mmc), (unsigned long)
(platform_get_resource(pdev, IORESOURCE_MEM, 0)->start),
host->mmc->f_max / 1000000);
return ret;
eirq:
tmio_mmc_host_remove(host);
efree:
tmio_mmc_host_free(host);
eprobe:
return ret;
}
static int sh_mobile_sdhi_remove(struct platform_device *pdev)
{
struct mmc_host *mmc = platform_get_drvdata(pdev);
struct tmio_mmc_host *host = mmc_priv(mmc);
tmio_mmc_host_remove(host);
return 0;
}
