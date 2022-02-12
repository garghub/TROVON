static int bf5xx_ssm2602_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
unsigned int clk = 0;
int ret = 0;
pr_debug("%s rate %d format %x\n", __func__, params_rate(params),
params_format(params));
switch (params_rate(params)) {
case 8000:
case 16000:
case 48000:
case 96000:
case 11025:
case 22050:
case 44100:
clk = 12000000;
break;
}
ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_fmt(cpu_dai, SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, SSM2602_SYSCLK, clk,
SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
return 0;
}
static int __init bf5xx_ssm2602_init(void)
{
int ret;
pr_debug("%s enter\n", __func__);
bf5xx_ssm2602_snd_device = platform_device_alloc("soc-audio", -1);
if (!bf5xx_ssm2602_snd_device)
return -ENOMEM;
platform_set_drvdata(bf5xx_ssm2602_snd_device, &bf5xx_ssm2602);
ret = platform_device_add(bf5xx_ssm2602_snd_device);
if (ret)
platform_device_put(bf5xx_ssm2602_snd_device);
return ret;
}
static void __exit bf5xx_ssm2602_exit(void)
{
pr_debug("%s enter\n", __func__);
platform_device_unregister(bf5xx_ssm2602_snd_device);
}
