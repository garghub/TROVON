static int bf5xx_i2s_set_dai_fmt(struct snd_soc_dai *cpu_dai,
unsigned int fmt)
{
struct sport_device *sport_handle = snd_soc_dai_get_drvdata(cpu_dai);
struct bf5xx_i2s_port *bf5xx_i2s = sport_handle->private_data;
int ret = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
bf5xx_i2s->tcr1 |= TFSR | TCKFE;
bf5xx_i2s->rcr1 |= RFSR | RCKFE;
bf5xx_i2s->tcr2 |= TSFSE;
bf5xx_i2s->rcr2 |= RSFSE;
break;
case SND_SOC_DAIFMT_DSP_A:
bf5xx_i2s->tcr1 |= TFSR;
bf5xx_i2s->rcr1 |= RFSR;
break;
case SND_SOC_DAIFMT_LEFT_J:
ret = -EINVAL;
break;
default:
dev_err(cpu_dai->dev, "%s: Unknown DAI format type\n",
__func__);
ret = -EINVAL;
break;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
break;
case SND_SOC_DAIFMT_CBS_CFS:
case SND_SOC_DAIFMT_CBM_CFS:
case SND_SOC_DAIFMT_CBS_CFM:
ret = -EINVAL;
break;
default:
dev_err(cpu_dai->dev, "%s: Unknown DAI master type\n",
__func__);
ret = -EINVAL;
break;
}
return ret;
}
static int bf5xx_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct sport_device *sport_handle = snd_soc_dai_get_drvdata(dai);
struct bf5xx_i2s_port *bf5xx_i2s = sport_handle->private_data;
int ret = 0;
bf5xx_i2s->tcr2 &= ~0x1f;
bf5xx_i2s->rcr2 &= ~0x1f;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S8:
bf5xx_i2s->tcr2 |= 7;
bf5xx_i2s->rcr2 |= 7;
sport_handle->wdsize = 1;
case SNDRV_PCM_FORMAT_S16_LE:
bf5xx_i2s->tcr2 |= 15;
bf5xx_i2s->rcr2 |= 15;
sport_handle->wdsize = 2;
break;
case SNDRV_PCM_FORMAT_S24_LE:
bf5xx_i2s->tcr2 |= 23;
bf5xx_i2s->rcr2 |= 23;
sport_handle->wdsize = 3;
break;
case SNDRV_PCM_FORMAT_S32_LE:
bf5xx_i2s->tcr2 |= 31;
bf5xx_i2s->rcr2 |= 31;
sport_handle->wdsize = 4;
break;
}
if (!bf5xx_i2s->configured) {
bf5xx_i2s->configured = 1;
ret = sport_config_rx(sport_handle, bf5xx_i2s->rcr1,
bf5xx_i2s->rcr2, 0, 0);
if (ret) {
dev_err(dai->dev, "SPORT is busy!\n");
return -EBUSY;
}
ret = sport_config_tx(sport_handle, bf5xx_i2s->tcr1,
bf5xx_i2s->tcr2, 0, 0);
if (ret) {
dev_err(dai->dev, "SPORT is busy!\n");
return -EBUSY;
}
}
return 0;
}
static void bf5xx_i2s_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct sport_device *sport_handle = snd_soc_dai_get_drvdata(dai);
struct bf5xx_i2s_port *bf5xx_i2s = sport_handle->private_data;
dev_dbg(dai->dev, "%s enter\n", __func__);
if (!dai->active)
bf5xx_i2s->configured = 0;
}
static int bf5xx_i2s_set_channel_map(struct snd_soc_dai *dai,
unsigned int tx_num, unsigned int *tx_slot,
unsigned int rx_num, unsigned int *rx_slot)
{
struct sport_device *sport_handle = snd_soc_dai_get_drvdata(dai);
struct bf5xx_i2s_port *bf5xx_i2s = sport_handle->private_data;
unsigned int tx_mapped = 0, rx_mapped = 0;
unsigned int slot;
int i;
if ((tx_num > BFIN_TDM_DAI_MAX_SLOTS) ||
(rx_num > BFIN_TDM_DAI_MAX_SLOTS))
return -EINVAL;
for (i = 0; i < tx_num; i++) {
slot = tx_slot[i];
if ((slot < BFIN_TDM_DAI_MAX_SLOTS) &&
(!(tx_mapped & (1 << slot)))) {
bf5xx_i2s->tx_dma_data.map[i] = slot;
tx_mapped |= 1 << slot;
} else
return -EINVAL;
}
for (i = 0; i < rx_num; i++) {
slot = rx_slot[i];
if ((slot < BFIN_TDM_DAI_MAX_SLOTS) &&
(!(rx_mapped & (1 << slot)))) {
bf5xx_i2s->rx_dma_data.map[i] = slot;
rx_mapped |= 1 << slot;
} else
return -EINVAL;
}
return 0;
}
static int bf5xx_i2s_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
unsigned int rx_mask, int slots, int width)
{
struct sport_device *sport_handle = snd_soc_dai_get_drvdata(dai);
struct bf5xx_i2s_port *bf5xx_i2s = sport_handle->private_data;
if (slots % 8 != 0 || slots > 8)
return -EINVAL;
if (width != 32)
return -EINVAL;
bf5xx_i2s->slots = slots;
bf5xx_i2s->tx_mask = tx_mask;
bf5xx_i2s->rx_mask = rx_mask;
bf5xx_i2s->tx_dma_data.tdm_mode = slots != 0;
bf5xx_i2s->rx_dma_data.tdm_mode = slots != 0;
return sport_set_multichannel(sport_handle, slots, tx_mask, rx_mask, 0);
}
static int bf5xx_i2s_suspend(struct snd_soc_dai *dai)
{
struct sport_device *sport_handle = snd_soc_dai_get_drvdata(dai);
dev_dbg(dai->dev, "%s : sport %d\n", __func__, dai->id);
if (dai->capture_active)
sport_rx_stop(sport_handle);
if (dai->playback_active)
sport_tx_stop(sport_handle);
return 0;
}
static int bf5xx_i2s_resume(struct snd_soc_dai *dai)
{
struct sport_device *sport_handle = snd_soc_dai_get_drvdata(dai);
struct bf5xx_i2s_port *bf5xx_i2s = sport_handle->private_data;
int ret;
dev_dbg(dai->dev, "%s : sport %d\n", __func__, dai->id);
ret = sport_config_rx(sport_handle, bf5xx_i2s->rcr1,
bf5xx_i2s->rcr2, 0, 0);
if (ret) {
dev_err(dai->dev, "SPORT is busy!\n");
return -EBUSY;
}
ret = sport_config_tx(sport_handle, bf5xx_i2s->tcr1,
bf5xx_i2s->tcr2, 0, 0);
if (ret) {
dev_err(dai->dev, "SPORT is busy!\n");
return -EBUSY;
}
return sport_set_multichannel(sport_handle, bf5xx_i2s->slots,
bf5xx_i2s->tx_mask, bf5xx_i2s->rx_mask, 0);
}
static int bf5xx_i2s_dai_probe(struct snd_soc_dai *dai)
{
struct sport_device *sport_handle = snd_soc_dai_get_drvdata(dai);
struct bf5xx_i2s_port *bf5xx_i2s = sport_handle->private_data;
unsigned int i;
for (i = 0; i < BFIN_TDM_DAI_MAX_SLOTS; i++) {
bf5xx_i2s->tx_dma_data.map[i] = i;
bf5xx_i2s->rx_dma_data.map[i] = i;
}
dai->playback_dma_data = &bf5xx_i2s->tx_dma_data;
dai->capture_dma_data = &bf5xx_i2s->rx_dma_data;
return 0;
}
static int bf5xx_i2s_probe(struct platform_device *pdev)
{
struct sport_device *sport_handle;
int ret;
sport_handle = sport_init(pdev, 4, 8 * sizeof(u32),
sizeof(struct bf5xx_i2s_port));
if (!sport_handle)
return -ENODEV;
ret = snd_soc_register_component(&pdev->dev, &bf5xx_i2s_component,
&bf5xx_i2s_dai, 1);
if (ret) {
dev_err(&pdev->dev, "Failed to register DAI: %d\n", ret);
sport_done(sport_handle);
return ret;
}
return 0;
}
static int bf5xx_i2s_remove(struct platform_device *pdev)
{
struct sport_device *sport_handle = platform_get_drvdata(pdev);
dev_dbg(&pdev->dev, "%s enter\n", __func__);
snd_soc_unregister_component(&pdev->dev);
sport_done(sport_handle);
return 0;
}
