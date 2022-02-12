static int db1200_i2s_startup(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int ret;
snd_soc_dai_set_sysclk(codec_dai, WM8731_SYSCLK_XTAL,
12000000, SND_SOC_CLOCK_IN);
ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_LEFT_J |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0)
goto out;
ret = snd_soc_dai_set_fmt(cpu_dai, SND_SOC_DAIFMT_LEFT_J |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0)
goto out;
ret = 0;
out:
return ret;
}
static int __devinit db1200_audio_probe(struct platform_device *pdev)
{
const struct platform_device_id *pid = platform_get_device_id(pdev);
struct snd_soc_card *card;
card = db1200_cards[pid->driver_data];
card->dev = &pdev->dev;
return snd_soc_register_card(card);
}
static int __devexit db1200_audio_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
return 0;
}
static int __init db1200_audio_load(void)
{
return platform_driver_register(&db1200_audio_driver);
}
static void __exit db1200_audio_unload(void)
{
platform_driver_unregister(&db1200_audio_driver);
}
