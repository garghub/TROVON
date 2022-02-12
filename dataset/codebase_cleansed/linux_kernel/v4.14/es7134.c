static int es7134_set_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
fmt &= (SND_SOC_DAIFMT_FORMAT_MASK | SND_SOC_DAIFMT_INV_MASK |
SND_SOC_DAIFMT_MASTER_MASK);
if (fmt != (SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBS_CFS)) {
dev_err(codec_dai->dev, "Invalid DAI format\n");
return -EINVAL;
}
return 0;
}
static int es7134_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&es7134_codec_driver,
&es7134_dai, 1);
}
static int es7134_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
