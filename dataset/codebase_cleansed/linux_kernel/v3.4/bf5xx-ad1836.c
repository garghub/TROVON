static int bf5xx_ad1836_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
unsigned int channel_map[] = {0, 4, 1, 5, 2, 6, 3, 7};
int ret = 0;
ret = snd_soc_dai_set_channel_map(cpu_dai, ARRAY_SIZE(channel_map),
channel_map, ARRAY_SIZE(channel_map), channel_map);
if (ret < 0)
return ret;
return 0;
}
static int __init bf5xx_ad1836_init(void)
{
int ret;
bfxx_ad1836_snd_device = platform_device_alloc("soc-audio", -1);
if (!bfxx_ad1836_snd_device)
return -ENOMEM;
platform_set_drvdata(bfxx_ad1836_snd_device, &bf5xx_ad1836);
ret = platform_device_add(bfxx_ad1836_snd_device);
if (ret)
platform_device_put(bfxx_ad1836_snd_device);
return ret;
}
static void __exit bf5xx_ad1836_exit(void)
{
platform_device_unregister(bfxx_ad1836_snd_device);
}
