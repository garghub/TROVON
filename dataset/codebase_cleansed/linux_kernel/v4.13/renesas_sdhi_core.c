static void renesas_sdhi_sdbuf_width(struct tmio_mmc_host *host, int width)
{
u32 val;
switch (sd_ctrl_read16(host, CTL_VERSION)) {
case SDHI_VER_GEN2_SDR50:
val = (width == 32) ? 0x0001 : 0x0000;
break;
case SDHI_VER_GEN2_SDR104:
val = (width == 32) ? 0x0000 : 0x0001;
break;
case SDHI_VER_GEN3_SD:
case SDHI_VER_GEN3_SDMMC:
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
static int renesas_sdhi_clk_enable(struct tmio_mmc_host *host)
{
struct mmc_host *mmc = host->mmc;
struct renesas_sdhi *priv = host_to_priv(host);
int ret = clk_prepare_enable(priv->clk);
if (ret < 0)
return ret;
ret = clk_prepare_enable(priv->clk_cd);
if (ret < 0) {
clk_disable_unprepare(priv->clk);
return ret;
}
if (!mmc->f_max)
mmc->f_max = clk_get_rate(priv->clk);
mmc->f_min = max(clk_round_rate(priv->clk, 1) / 512, 1L);
renesas_sdhi_sdbuf_width(host, 16);
return 0;
}
static unsigned int renesas_sdhi_clk_update(struct tmio_mmc_host *host,
unsigned int new_clock)
{
struct renesas_sdhi *priv = host_to_priv(host);
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
static void renesas_sdhi_clk_disable(struct tmio_mmc_host *host)
{
struct renesas_sdhi *priv = host_to_priv(host);
clk_disable_unprepare(priv->clk);
clk_disable_unprepare(priv->clk_cd);
}
static int renesas_sdhi_card_busy(struct mmc_host *mmc)
{
struct tmio_mmc_host *host = mmc_priv(mmc);
return !(sd_ctrl_read16_and_16_as_32(host, CTL_STATUS) &
TMIO_STAT_DAT0);
}
static int renesas_sdhi_start_signal_voltage_switch(struct mmc_host *mmc,
struct mmc_ios *ios)
{
struct tmio_mmc_host *host = mmc_priv(mmc);
struct renesas_sdhi *priv = host_to_priv(host);
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
static inline u32 sd_scc_read32(struct tmio_mmc_host *host,
struct renesas_sdhi *priv, int addr)
{
return readl(priv->scc_ctl + (addr << host->bus_shift));
}
static inline void sd_scc_write32(struct tmio_mmc_host *host,
struct renesas_sdhi *priv,
int addr, u32 val)
{
writel(val, priv->scc_ctl + (addr << host->bus_shift));
}
static unsigned int renesas_sdhi_init_tuning(struct tmio_mmc_host *host)
{
struct renesas_sdhi *priv;
priv = host_to_priv(host);
sd_scc_write32(host, priv, SH_MOBILE_SDHI_SCC_DTCNTL,
0x8 << SH_MOBILE_SDHI_SCC_DTCNTL_TAPNUM_SHIFT);
sd_ctrl_write32_as_16_and_16(host, CTL_STATUS, 0x0);
sd_scc_write32(host, priv, SH_MOBILE_SDHI_SCC_DTCNTL,
SH_MOBILE_SDHI_SCC_DTCNTL_TAPEN |
sd_scc_read32(host, priv, SH_MOBILE_SDHI_SCC_DTCNTL));
sd_ctrl_write16(host, CTL_SD_CARD_CLK_CTL, ~CLK_CTL_SCLKEN &
sd_ctrl_read16(host, CTL_SD_CARD_CLK_CTL));
sd_scc_write32(host, priv, SH_MOBILE_SDHI_SCC_CKSEL,
SH_MOBILE_SDHI_SCC_CKSEL_DTSEL |
sd_scc_read32(host, priv, SH_MOBILE_SDHI_SCC_CKSEL));
sd_ctrl_write16(host, CTL_SD_CARD_CLK_CTL, CLK_CTL_SCLKEN |
sd_ctrl_read16(host, CTL_SD_CARD_CLK_CTL));
sd_scc_write32(host, priv, SH_MOBILE_SDHI_SCC_RVSCNTL,
~SH_MOBILE_SDHI_SCC_RVSCNTL_RVSEN &
sd_scc_read32(host, priv, SH_MOBILE_SDHI_SCC_RVSCNTL));
sd_scc_write32(host, priv, SH_MOBILE_SDHI_SCC_DT2FF, host->scc_tappos);
return (sd_scc_read32(host, priv, SH_MOBILE_SDHI_SCC_DTCNTL) >>
SH_MOBILE_SDHI_SCC_DTCNTL_TAPNUM_SHIFT) &
SH_MOBILE_SDHI_SCC_DTCNTL_TAPNUM_MASK;
}
static void renesas_sdhi_prepare_tuning(struct tmio_mmc_host *host,
unsigned long tap)
{
struct renesas_sdhi *priv = host_to_priv(host);
sd_scc_write32(host, priv, SH_MOBILE_SDHI_SCC_TAPSET, tap);
}
static int renesas_sdhi_select_tuning(struct tmio_mmc_host *host)
{
struct renesas_sdhi *priv = host_to_priv(host);
unsigned long tap_cnt;
unsigned long tap_set;
unsigned long tap_start;
unsigned long tap_end;
unsigned long ntap;
unsigned long i;
sd_scc_write32(host, priv, SH_MOBILE_SDHI_SCC_RVSREQ, 0);
tap_cnt = 0;
ntap = 0;
tap_start = 0;
tap_end = 0;
for (i = 0; i < host->tap_num * 2; i++) {
if (test_bit(i, host->taps)) {
ntap++;
} else {
if (ntap > tap_cnt) {
tap_start = i - ntap;
tap_end = i - 1;
tap_cnt = ntap;
}
ntap = 0;
}
}
if (ntap > tap_cnt) {
tap_start = i - ntap;
tap_end = i - 1;
tap_cnt = ntap;
}
if (tap_cnt >= SH_MOBILE_SDHI_MAX_TAP)
tap_set = (tap_start + tap_end) / 2 % host->tap_num;
else
return -EIO;
sd_scc_write32(host, priv, SH_MOBILE_SDHI_SCC_TAPSET, tap_set);
sd_scc_write32(host, priv, SH_MOBILE_SDHI_SCC_RVSCNTL,
SH_MOBILE_SDHI_SCC_RVSCNTL_RVSEN |
sd_scc_read32(host, priv, SH_MOBILE_SDHI_SCC_RVSCNTL));
return 0;
}
static bool renesas_sdhi_check_scc_error(struct tmio_mmc_host *host)
{
struct renesas_sdhi *priv = host_to_priv(host);
if (sd_scc_read32(host, priv, SH_MOBILE_SDHI_SCC_RVSCNTL) &
SH_MOBILE_SDHI_SCC_RVSCNTL_RVSEN &&
sd_scc_read32(host, priv, SH_MOBILE_SDHI_SCC_RVSREQ) &
SH_MOBILE_SDHI_SCC_RVSREQ_RVSERR) {
sd_scc_write32(host, priv, SH_MOBILE_SDHI_SCC_RVSREQ, 0);
return true;
}
return false;
}
static void renesas_sdhi_hw_reset(struct tmio_mmc_host *host)
{
struct renesas_sdhi *priv;
priv = host_to_priv(host);
sd_ctrl_write16(host, CTL_SD_CARD_CLK_CTL, ~CLK_CTL_SCLKEN &
sd_ctrl_read16(host, CTL_SD_CARD_CLK_CTL));
sd_scc_write32(host, priv, SH_MOBILE_SDHI_SCC_CKSEL,
~SH_MOBILE_SDHI_SCC_CKSEL_DTSEL &
sd_scc_read32(host, priv, SH_MOBILE_SDHI_SCC_CKSEL));
sd_ctrl_write16(host, CTL_SD_CARD_CLK_CTL, CLK_CTL_SCLKEN |
sd_ctrl_read16(host, CTL_SD_CARD_CLK_CTL));
sd_scc_write32(host, priv, SH_MOBILE_SDHI_SCC_RVSCNTL,
~SH_MOBILE_SDHI_SCC_RVSCNTL_RVSEN &
sd_scc_read32(host, priv, SH_MOBILE_SDHI_SCC_RVSCNTL));
sd_scc_write32(host, priv, SH_MOBILE_SDHI_SCC_RVSCNTL,
~SH_MOBILE_SDHI_SCC_RVSCNTL_RVSEN &
sd_scc_read32(host, priv, SH_MOBILE_SDHI_SCC_RVSCNTL));
}
static int renesas_sdhi_wait_idle(struct tmio_mmc_host *host)
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
static int renesas_sdhi_write16_hook(struct tmio_mmc_host *host, int addr)
{
switch (addr) {
case CTL_SD_CMD:
case CTL_STOP_INTERNAL_ACTION:
case CTL_XFER_BLK_COUNT:
case CTL_SD_CARD_CLK_CTL:
case CTL_SD_XFER_LEN:
case CTL_SD_MEM_CARD_OPT:
case CTL_TRANSACTION_CTL:
case CTL_DMA_ENABLE:
case EXT_ACC:
return renesas_sdhi_wait_idle(host);
}
return 0;
}
static int renesas_sdhi_multi_io_quirk(struct mmc_card *card,
unsigned int direction, int blk_size)
{
if ((direction == MMC_DATA_READ) &&
blk_size == 2)
return 1;
return blk_size;
}
static void renesas_sdhi_enable_dma(struct tmio_mmc_host *host, bool enable)
{
sd_ctrl_write16(host, CTL_DMA_ENABLE, enable ? 2 : 0);
renesas_sdhi_sdbuf_width(host, enable ? 32 : 16);
}
int renesas_sdhi_probe(struct platform_device *pdev,
const struct tmio_mmc_dma_ops *dma_ops)
{
struct tmio_mmc_data *mmd = pdev->dev.platform_data;
const struct renesas_sdhi_of_data *of_data;
struct tmio_mmc_data *mmc_data;
struct tmio_mmc_dma *dma_priv;
struct tmio_mmc_host *host;
struct renesas_sdhi *priv;
struct resource *res;
int irq, ret, i;
of_data = of_device_get_match_data(&pdev->dev);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -EINVAL;
priv = devm_kzalloc(&pdev->dev, sizeof(struct renesas_sdhi),
GFP_KERNEL);
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
priv->clk_cd = devm_clk_get(&pdev->dev, "cd");
if (IS_ERR(priv->clk_cd))
priv->clk_cd = NULL;
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
if (of_data) {
mmc_data->flags |= of_data->tmio_flags;
mmc_data->ocr_mask = of_data->tmio_ocr_mask;
mmc_data->capabilities |= of_data->capabilities;
mmc_data->capabilities2 |= of_data->capabilities2;
mmc_data->dma_rx_offset = of_data->dma_rx_offset;
dma_priv->dma_buswidth = of_data->dma_buswidth;
host->bus_shift = of_data->bus_shift;
}
host->dma = dma_priv;
host->write16_hook = renesas_sdhi_write16_hook;
host->clk_enable = renesas_sdhi_clk_enable;
host->clk_update = renesas_sdhi_clk_update;
host->clk_disable = renesas_sdhi_clk_disable;
host->multi_io_quirk = renesas_sdhi_multi_io_quirk;
if (mmc_data->flags & TMIO_MMC_MIN_RCAR2) {
host->card_busy = renesas_sdhi_card_busy;
host->start_signal_voltage_switch =
renesas_sdhi_start_signal_voltage_switch;
}
if (!host->bus_shift && resource_size(res) > 0x100)
host->bus_shift = 1;
if (mmd)
*mmc_data = *mmd;
dma_priv->filter = shdma_chan_filter;
dma_priv->enable = renesas_sdhi_enable_dma;
mmc_data->alignment_shift = 1;
mmc_data->capabilities |= MMC_CAP_MMC_HIGHSPEED;
mmc_data->flags |= TMIO_MMC_BLKSZ_2BYTES;
mmc_data->flags |= TMIO_MMC_SDIO_IRQ;
mmc_data->flags |= TMIO_MMC_HAVE_CMD12_CTRL;
mmc_data->flags |= TMIO_MMC_SDIO_STATUS_SETBITS;
ret = tmio_mmc_host_probe(host, mmc_data, dma_ops);
if (ret < 0)
goto efree;
if (of_data && of_data->scc_offset &&
(host->mmc->caps & MMC_CAP_UHS_SDR104 ||
host->mmc->caps2 & MMC_CAP2_HS200_1_8V_SDR)) {
const struct renesas_sdhi_scc *taps = of_data->taps;
bool hit = false;
host->mmc->caps |= MMC_CAP_HW_RESET;
for (i = 0; i < of_data->taps_num; i++) {
if (taps[i].clk_rate == 0 ||
taps[i].clk_rate == host->mmc->f_max) {
host->scc_tappos = taps->tap;
hit = true;
break;
}
}
if (!hit)
dev_warn(&host->pdev->dev, "Unknown clock rate for SDR104\n");
priv->scc_ctl = host->ctl + of_data->scc_offset;
host->init_tuning = renesas_sdhi_init_tuning;
host->prepare_tuning = renesas_sdhi_prepare_tuning;
host->select_tuning = renesas_sdhi_select_tuning;
host->check_scc_error = renesas_sdhi_check_scc_error;
host->hw_reset = renesas_sdhi_hw_reset;
}
i = 0;
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
int renesas_sdhi_remove(struct platform_device *pdev)
{
struct mmc_host *mmc = platform_get_drvdata(pdev);
struct tmio_mmc_host *host = mmc_priv(mmc);
tmio_mmc_host_remove(host);
return 0;
}
