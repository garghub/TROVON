static int eukrea_tlv320_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int ret;
ret = snd_soc_dai_set_fmt(cpu_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM);
if (ret) {
pr_err("%s: failed set cpu dai format\n", __func__);
return ret;
}
ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM);
if (ret) {
pr_err("%s: failed set codec dai format\n", __func__);
return ret;
}
ret = snd_soc_dai_set_sysclk(codec_dai, 0,
CODEC_CLOCK, SND_SOC_CLOCK_OUT);
if (ret) {
pr_err("%s: failed setting codec sysclk\n", __func__);
return ret;
}
snd_soc_dai_set_tdm_slot(cpu_dai, 0xffffffc, 0xffffffc, 2, 0);
ret = snd_soc_dai_set_sysclk(cpu_dai, IMX_SSP_SYS_CLK, 0,
SND_SOC_CLOCK_IN);
if (ret) {
pr_err("can't set CPU system clock IMX_SSP_SYS_CLK\n");
return ret;
}
return 0;
}
static int __init eukrea_tlv320_init(void)
{
int ret;
if (!machine_is_eukrea_cpuimx27() && !machine_is_eukrea_cpuimx25sd()
&& !machine_is_eukrea_cpuimx35sd()
&& !machine_is_eukrea_cpuimx51sd())
return 0;
eukrea_tlv320_snd_device = platform_device_alloc("soc-audio", -1);
if (!eukrea_tlv320_snd_device)
return -ENOMEM;
platform_set_drvdata(eukrea_tlv320_snd_device, &eukrea_tlv320);
ret = platform_device_add(eukrea_tlv320_snd_device);
if (ret) {
printk(KERN_ERR "ASoC: Platform device allocation failed\n");
platform_device_put(eukrea_tlv320_snd_device);
}
return ret;
}
static void __exit eukrea_tlv320_exit(void)
{
platform_device_unregister(eukrea_tlv320_snd_device);
}
