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
static int __init t5325_init(void)
{
int ret;
if (!machine_is_t5325())
return 0;
t5325_snd_device = platform_device_alloc("soc-audio", -1);
if (!t5325_snd_device)
return -ENOMEM;
platform_set_drvdata(t5325_snd_device,
&t5325);
ret = platform_device_add(t5325_snd_device);
if (ret) {
printk(KERN_ERR "%s: platform_device_add failed\n", __func__);
platform_device_put(t5325_snd_device);
}
return ret;
}
static void __exit t5325_exit(void)
{
platform_device_unregister(t5325_snd_device);
}
