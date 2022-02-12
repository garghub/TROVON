static int sffsdr_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int fs;
int ret = 0;
fs = params_rate(params);
#ifndef CONFIG_SFFSDR_FPGA
if (fs != 44100) {
pr_debug("warning: only 44.1 kHz is supported without SFFSDR FPGA module\n");
return -EINVAL;
}
#endif
ret = snd_soc_dai_set_fmt(cpu_dai, AUDIO_FORMAT);
if (ret < 0)
return ret;
pr_debug("sffsdr_hw_params: rate = %d Hz\n", fs);
#ifndef CONFIG_SFFSDR_FPGA
return 0;
#else
return sffsdr_fpga_set_codec_fs(fs);
#endif
}
static int __init sffsdr_init(void)
{
int ret;
if (!machine_is_sffsdr())
return -EINVAL;
platform_device_register(&pcm3008_codec);
sffsdr_snd_device = platform_device_alloc("soc-audio", 0);
if (!sffsdr_snd_device) {
printk(KERN_ERR "platform device allocation failed\n");
return -ENOMEM;
}
platform_set_drvdata(sffsdr_snd_device, &snd_soc_sffsdr);
platform_device_add_data(sffsdr_snd_device, &sffsdr_snd_data,
sizeof(sffsdr_snd_data));
ret = platform_device_add_resources(sffsdr_snd_device,
sffsdr_snd_resources,
ARRAY_SIZE(sffsdr_snd_resources));
if (ret) {
printk(KERN_ERR "platform device add resources failed\n");
goto error;
}
ret = platform_device_add(sffsdr_snd_device);
if (ret)
goto error;
return ret;
error:
platform_device_put(sffsdr_snd_device);
return ret;
}
static void __exit sffsdr_exit(void)
{
platform_device_unregister(sffsdr_snd_device);
platform_device_unregister(&pcm3008_codec);
}
