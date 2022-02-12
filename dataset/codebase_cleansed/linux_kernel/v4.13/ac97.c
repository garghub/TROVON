static int ac97_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct snd_ac97 *ac97 = snd_soc_codec_get_drvdata(codec);
int reg = (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) ?
AC97_PCM_FRONT_DAC_RATE : AC97_PCM_LR_ADC_RATE;
return snd_ac97_set_rate(ac97, reg, substream->runtime->rate);
}
static int ac97_soc_probe(struct snd_soc_codec *codec)
{
struct snd_ac97 *ac97;
struct snd_ac97_bus *ac97_bus;
struct snd_ac97_template ac97_template;
int ret;
ret = snd_ac97_bus(codec->component.card->snd_card, 0, soc_ac97_ops,
NULL, &ac97_bus);
if (ret < 0)
return ret;
memset(&ac97_template, 0, sizeof(struct snd_ac97_template));
ret = snd_ac97_mixer(ac97_bus, &ac97_template, &ac97);
if (ret < 0)
return ret;
snd_soc_codec_set_drvdata(codec, ac97);
return 0;
}
static int ac97_soc_suspend(struct snd_soc_codec *codec)
{
struct snd_ac97 *ac97 = snd_soc_codec_get_drvdata(codec);
snd_ac97_suspend(ac97);
return 0;
}
static int ac97_soc_resume(struct snd_soc_codec *codec)
{
struct snd_ac97 *ac97 = snd_soc_codec_get_drvdata(codec);
snd_ac97_resume(ac97);
return 0;
}
static int ac97_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_ac97, &ac97_dai, 1);
}
static int ac97_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
