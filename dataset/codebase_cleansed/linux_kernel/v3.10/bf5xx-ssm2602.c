static int bf5xx_ssm2602_dai_init(struct snd_soc_pcm_runtime *rtd)
{
return snd_soc_dai_set_sysclk(rtd->codec_dai, SSM2602_SYSCLK, 12000000,
SND_SOC_CLOCK_IN);
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
