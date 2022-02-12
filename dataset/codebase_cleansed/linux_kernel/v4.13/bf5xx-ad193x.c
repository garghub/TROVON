static int bf5xx_ad193x_link_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, 0, 24576000, SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_tdm_slot(codec_dai, 0xFF, 0xFF, 8, 32);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_tdm_slot(cpu_dai, 0xFF, 0xFF, 8, 32);
if (ret < 0)
return ret;
return 0;
}
static int __init bf5xx_ad193x_init(void)
{
int ret;
bfxx_ad193x_snd_device = platform_device_alloc("soc-audio", -1);
if (!bfxx_ad193x_snd_device)
return -ENOMEM;
platform_set_drvdata(bfxx_ad193x_snd_device, &bf5xx_ad193x);
ret = platform_device_add(bfxx_ad193x_snd_device);
if (ret)
platform_device_put(bfxx_ad193x_snd_device);
return ret;
}
static void __exit bf5xx_ad193x_exit(void)
{
platform_device_unregister(bfxx_ad193x_snd_device);
}
