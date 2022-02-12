static int openrd_client_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
unsigned int freq;
switch (params_rate(params)) {
default:
case 44100:
freq = 11289600;
break;
case 48000:
freq = 12288000;
break;
case 96000:
freq = 24576000;
break;
}
return snd_soc_dai_set_sysclk(codec_dai, 0, freq, SND_SOC_CLOCK_IN);
}
static int __init openrd_client_init(void)
{
int ret;
if (!machine_is_openrd_client() && !machine_is_openrd_ultimate())
return 0;
openrd_client_snd_device = platform_device_alloc("soc-audio", -1);
if (!openrd_client_snd_device)
return -ENOMEM;
platform_set_drvdata(openrd_client_snd_device,
&openrd_client);
ret = platform_device_add(openrd_client_snd_device);
if (ret) {
printk(KERN_ERR "%s: platform_device_add failed\n", __func__);
platform_device_put(openrd_client_snd_device);
}
return ret;
}
static void __exit openrd_client_exit(void)
{
platform_device_unregister(openrd_client_snd_device);
}
