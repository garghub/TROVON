static int bfin_i2s_set_dai_fmt(struct snd_soc_dai *cpu_dai,
unsigned int fmt)
{
struct sport_device *sport = snd_soc_dai_get_drvdata(cpu_dai);
struct device *dev = &sport->pdev->dev;
int ret = 0;
param.spctl &= ~(SPORT_CTL_OPMODE | SPORT_CTL_CKRE | SPORT_CTL_FSR
| SPORT_CTL_LFS | SPORT_CTL_LAFS);
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
param.spctl |= SPORT_CTL_OPMODE | SPORT_CTL_CKRE
| SPORT_CTL_LFS;
break;
case SND_SOC_DAIFMT_DSP_A:
param.spctl |= SPORT_CTL_FSR;
break;
case SND_SOC_DAIFMT_LEFT_J:
param.spctl |= SPORT_CTL_OPMODE | SPORT_CTL_LFS
| SPORT_CTL_LAFS;
break;
default:
dev_err(dev, "%s: Unknown DAI format type\n", __func__);
ret = -EINVAL;
break;
}
param.spctl &= ~(SPORT_CTL_ICLK | SPORT_CTL_IFS);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
break;
case SND_SOC_DAIFMT_CBS_CFS:
case SND_SOC_DAIFMT_CBM_CFS:
case SND_SOC_DAIFMT_CBS_CFM:
ret = -EINVAL;
break;
default:
dev_err(dev, "%s: Unknown DAI master type\n", __func__);
ret = -EINVAL;
break;
}
return ret;
}
static int bfin_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct sport_device *sport = snd_soc_dai_get_drvdata(dai);
struct device *dev = &sport->pdev->dev;
int ret = 0;
param.spctl &= ~SPORT_CTL_SLEN;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S8:
param.spctl |= 0x70;
sport->wdsize = 1;
break;
case SNDRV_PCM_FORMAT_S16_LE:
param.spctl |= 0xf0;
sport->wdsize = 2;
break;
case SNDRV_PCM_FORMAT_S24_LE:
param.spctl |= 0x170;
sport->wdsize = 3;
break;
case SNDRV_PCM_FORMAT_S32_LE:
param.spctl |= 0x1f0;
sport->wdsize = 4;
break;
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
ret = sport_set_tx_params(sport, &param);
if (ret) {
dev_err(dev, "SPORT tx is busy!\n");
return ret;
}
} else {
ret = sport_set_rx_params(sport, &param);
if (ret) {
dev_err(dev, "SPORT rx is busy!\n");
return ret;
}
}
return 0;
}
static int bfin_i2s_suspend(struct snd_soc_dai *dai)
{
struct sport_device *sport = snd_soc_dai_get_drvdata(dai);
if (dai->capture_active)
sport_rx_stop(sport);
if (dai->playback_active)
sport_tx_stop(sport);
return 0;
}
static int bfin_i2s_resume(struct snd_soc_dai *dai)
{
struct sport_device *sport = snd_soc_dai_get_drvdata(dai);
struct device *dev = &sport->pdev->dev;
int ret;
ret = sport_set_tx_params(sport, &param);
if (ret) {
dev_err(dev, "SPORT tx is busy!\n");
return ret;
}
ret = sport_set_rx_params(sport, &param);
if (ret) {
dev_err(dev, "SPORT rx is busy!\n");
return ret;
}
return 0;
}
static int bfin_i2s_probe(struct platform_device *pdev)
{
struct sport_device *sport;
struct device *dev = &pdev->dev;
int ret;
sport = sport_create(pdev);
if (!sport)
return -ENODEV;
ret = snd_soc_register_component(dev, &bfin_i2s_component,
&bfin_i2s_dai, 1);
if (ret) {
dev_err(dev, "Failed to register DAI: %d\n", ret);
sport_delete(sport);
return ret;
}
platform_set_drvdata(pdev, sport);
return 0;
}
static int bfin_i2s_remove(struct platform_device *pdev)
{
struct sport_device *sport = platform_get_drvdata(pdev);
snd_soc_unregister_component(&pdev->dev);
sport_delete(sport);
return 0;
}
