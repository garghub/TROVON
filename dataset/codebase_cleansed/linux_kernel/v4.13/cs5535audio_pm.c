static void snd_cs5535audio_stop_hardware(struct cs5535audio *cs5535au)
{
cs_writel(cs5535au, ACC_CODEC_CNTL, ACC_CODEC_CNTL_LNK_SHUTDOWN);
}
static int __maybe_unused snd_cs5535audio_suspend(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct cs5535audio *cs5535au = card->private_data;
int i;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(cs5535au->pcm);
snd_ac97_suspend(cs5535au->ac97);
for (i = 0; i < NUM_CS5535AUDIO_DMAS; i++) {
struct cs5535audio_dma *dma = &cs5535au->dmas[i];
if (dma && dma->substream)
dma->saved_prd = dma->ops->read_prd(cs5535au);
}
snd_cs5535audio_stop_hardware(cs5535au);
return 0;
}
static int __maybe_unused snd_cs5535audio_resume(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct cs5535audio *cs5535au = card->private_data;
u32 tmp;
int timeout;
int i;
cs_writel(cs5535au, ACC_CODEC_CNTL, ACC_CODEC_CNTL_LNK_WRM_RST);
timeout = 50;
do {
tmp = cs_readl(cs5535au, ACC_CODEC_STATUS);
if (tmp & PRM_RDY_STS)
break;
udelay(1);
} while (--timeout);
if (!timeout)
dev_err(cs5535au->card->dev, "Failure getting AC Link ready\n");
for (i = 0; i < NUM_CS5535AUDIO_DMAS; i++) {
struct cs5535audio_dma *dma = &cs5535au->dmas[i];
if (dma && dma->substream) {
dma->substream->ops->prepare(dma->substream);
dma->ops->setup_prd(cs5535au, dma->saved_prd);
}
}
snd_ac97_resume(cs5535au->ac97);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
