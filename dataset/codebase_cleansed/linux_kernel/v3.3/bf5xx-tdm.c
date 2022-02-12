static int bf5xx_tdm_set_dai_fmt(struct snd_soc_dai *cpu_dai,
unsigned int fmt)
{
int ret = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
break;
default:
printk(KERN_ERR "%s: Unknown DAI format type\n", __func__);
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
printk(KERN_ERR "%s: Unknown DAI master type\n", __func__);
ret = -EINVAL;
break;
}
return ret;
}
static int bf5xx_tdm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct sport_device *sport_handle = snd_soc_dai_get_drvdata(dai);
struct bf5xx_tdm_port *bf5xx_tdm = sport_handle->private_data;
int ret = 0;
bf5xx_tdm->tcr2 &= ~0x1f;
bf5xx_tdm->rcr2 &= ~0x1f;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S32_LE:
bf5xx_tdm->tcr2 |= 31;
bf5xx_tdm->rcr2 |= 31;
sport_handle->wdsize = 4;
break;
default:
pr_err("not supported PCM format yet\n");
return -EINVAL;
break;
}
if (!bf5xx_tdm->configured) {
ret = sport_config_rx(sport_handle, bf5xx_tdm->rcr1,
bf5xx_tdm->rcr2, 0, 0);
if (ret) {
pr_err("SPORT is busy!\n");
return -EBUSY;
}
ret = sport_config_tx(sport_handle, bf5xx_tdm->tcr1,
bf5xx_tdm->tcr2, 0, 0);
if (ret) {
pr_err("SPORT is busy!\n");
return -EBUSY;
}
bf5xx_tdm->configured = 1;
}
return 0;
}
static void bf5xx_tdm_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct sport_device *sport_handle = snd_soc_dai_get_drvdata(dai);
struct bf5xx_tdm_port *bf5xx_tdm = sport_handle->private_data;
if (!dai->active)
bf5xx_tdm->configured = 0;
}
static int bf5xx_tdm_set_channel_map(struct snd_soc_dai *dai,
unsigned int tx_num, unsigned int *tx_slot,
unsigned int rx_num, unsigned int *rx_slot)
{
struct sport_device *sport_handle = snd_soc_dai_get_drvdata(dai);
struct bf5xx_tdm_port *bf5xx_tdm = sport_handle->private_data;
int i;
unsigned int slot;
unsigned int tx_mapped = 0, rx_mapped = 0;
if ((tx_num > BFIN_TDM_DAI_MAX_SLOTS) ||
(rx_num > BFIN_TDM_DAI_MAX_SLOTS))
return -EINVAL;
for (i = 0; i < tx_num; i++) {
slot = tx_slot[i];
if ((slot < BFIN_TDM_DAI_MAX_SLOTS) &&
(!(tx_mapped & (1 << slot)))) {
bf5xx_tdm->tx_map[i] = slot;
tx_mapped |= 1 << slot;
} else
return -EINVAL;
}
for (i = 0; i < rx_num; i++) {
slot = rx_slot[i];
if ((slot < BFIN_TDM_DAI_MAX_SLOTS) &&
(!(rx_mapped & (1 << slot)))) {
bf5xx_tdm->rx_map[i] = slot;
rx_mapped |= 1 << slot;
} else
return -EINVAL;
}
return 0;
}
static int bf5xx_tdm_suspend(struct snd_soc_dai *dai)
{
struct sport_device *sport = snd_soc_dai_get_drvdata(dai);
if (dai->playback_active)
sport_tx_stop(sport);
if (dai->capture_active)
sport_rx_stop(sport);
peripheral_free_list(sport->pin_req);
return 0;
}
static int bf5xx_tdm_resume(struct snd_soc_dai *dai)
{
int ret;
struct sport_device *sport = snd_soc_dai_get_drvdata(dai);
ret = sport_set_multichannel(sport, 8, 0xFF, 1);
if (ret) {
pr_err("SPORT is busy!\n");
ret = -EBUSY;
}
ret = sport_config_rx(sport, 0, 0x1F, 0, 0);
if (ret) {
pr_err("SPORT is busy!\n");
ret = -EBUSY;
}
ret = sport_config_tx(sport, 0, 0x1F, 0, 0);
if (ret) {
pr_err("SPORT is busy!\n");
ret = -EBUSY;
}
peripheral_request_list(sport->pin_req, "soc-audio");
return 0;
}
static int __devinit bfin_tdm_probe(struct platform_device *pdev)
{
struct sport_device *sport_handle;
int ret;
sport_handle = sport_init(pdev, 4, 8 * sizeof(u32),
sizeof(struct bf5xx_tdm_port));
if (!sport_handle)
return -ENODEV;
ret = sport_set_multichannel(sport_handle, 8, 0xFF, 1);
if (ret) {
pr_err("SPORT is busy!\n");
ret = -EBUSY;
goto sport_config_err;
}
ret = sport_config_rx(sport_handle, 0, 0x1F, 0, 0);
if (ret) {
pr_err("SPORT is busy!\n");
ret = -EBUSY;
goto sport_config_err;
}
ret = sport_config_tx(sport_handle, 0, 0x1F, 0, 0);
if (ret) {
pr_err("SPORT is busy!\n");
ret = -EBUSY;
goto sport_config_err;
}
ret = snd_soc_register_dai(&pdev->dev, &bf5xx_tdm_dai);
if (ret) {
pr_err("Failed to register DAI: %d\n", ret);
goto sport_config_err;
}
return 0;
sport_config_err:
sport_done(sport_handle);
return ret;
}
static int __devexit bfin_tdm_remove(struct platform_device *pdev)
{
struct sport_device *sport_handle = platform_get_drvdata(pdev);
snd_soc_unregister_dai(&pdev->dev);
sport_done(sport_handle);
return 0;
}
