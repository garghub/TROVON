static int t5325_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
unsigned int freq;
freq = params_rate(params) * 256;
return snd_soc_dai_set_sysclk(codec_dai, 0, freq, SND_SOC_CLOCK_IN);
}
static int t5325_dai_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_enable_pin(dapm, "Mic Jack");
snd_soc_dapm_enable_pin(dapm, "Headphone Jack");
snd_soc_dapm_enable_pin(dapm, "Speaker");
return 0;
}
static int t5325_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &t5325;
int ret;
card->dev = &pdev->dev;
ret = snd_soc_register_card(card);
if (ret)
dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
ret);
return ret;
}
static int t5325_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
return 0;
}
