static int bf5xx_ad193x_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
unsigned int clk = 0;
unsigned int channel_map[] = {0, 1, 2, 3, 4, 5, 6, 7};
int ret = 0;
switch (params_rate(params)) {
case 48000:
clk = 24576000;
break;
}
ret = snd_soc_dai_set_sysclk(codec_dai, 0, clk,
SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_tdm_slot(codec_dai, 0xFF, 0xFF, 8, 32);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_channel_map(cpu_dai, ARRAY_SIZE(channel_map),
channel_map, ARRAY_SIZE(channel_map), channel_map);
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
