static int fsi_da7210_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dai *codec = rtd->codec_dai;
struct snd_soc_dai *cpu = rtd->cpu_dai;
int ret;
ret = snd_soc_dai_set_fmt(codec,
SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_fmt(cpu, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_CBS_CFS);
return ret;
}
static int __init fsi_da7210_sound_init(void)
{
int ret;
fsi_da7210_snd_device = platform_device_alloc("soc-audio", FSI_PORT_B);
if (!fsi_da7210_snd_device)
return -ENOMEM;
platform_set_drvdata(fsi_da7210_snd_device, &fsi_soc_card);
ret = platform_device_add(fsi_da7210_snd_device);
if (ret)
platform_device_put(fsi_da7210_snd_device);
return ret;
}
static void __exit fsi_da7210_sound_exit(void)
{
platform_device_unregister(fsi_da7210_snd_device);
}
