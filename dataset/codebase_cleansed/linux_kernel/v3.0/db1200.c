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
static int __init db1200_audio_load(void)
{
int ret;
ret = -ENOMEM;
db1200_asoc_dev = platform_device_alloc("soc-audio", 1);
if (!db1200_asoc_dev)
goto out;
if (bcsr_read(BCSR_RESETS) & BCSR_RESETS_PSC1MUX)
platform_set_drvdata(db1200_asoc_dev, &db1200_i2s_machine);
else
platform_set_drvdata(db1200_asoc_dev, &db1200_ac97_machine);
ret = platform_device_add(db1200_asoc_dev);
if (ret) {
platform_device_put(db1200_asoc_dev);
db1200_asoc_dev = NULL;
}
out:
return ret;
}
static void __exit db1200_audio_unload(void)
{
platform_device_unregister(db1200_asoc_dev);
}
