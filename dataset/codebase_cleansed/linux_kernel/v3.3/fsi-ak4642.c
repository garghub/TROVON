static int fsi_ak4642_dai_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dai *codec = rtd->codec_dai;
struct snd_soc_dai *cpu = rtd->cpu_dai;
int ret;
ret = snd_soc_dai_set_fmt(codec, SND_SOC_DAIFMT_LEFT_J |
SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(codec, 0, 11289600, 0);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_fmt(cpu, SND_SOC_DAIFMT_LEFT_J |
SND_SOC_DAIFMT_CBS_CFS);
return ret;
}
static int fsi_ak4642_probe(struct platform_device *pdev)
{
int ret = -ENOMEM;
struct fsi_ak4642_info *pinfo = pdev->dev.platform_data;
if (!pinfo) {
dev_err(&pdev->dev, "no info for fsi ak4642\n");
goto out;
}
fsi_snd_device = platform_device_alloc("soc-audio", pinfo->id);
if (!fsi_snd_device)
goto out;
fsi_dai_link.name = pinfo->name;
fsi_dai_link.stream_name = pinfo->name;
fsi_dai_link.cpu_dai_name = pinfo->cpu_dai;
fsi_dai_link.platform_name = pinfo->platform;
fsi_dai_link.codec_name = pinfo->codec;
fsi_soc_card.name = pinfo->card;
platform_set_drvdata(fsi_snd_device, &fsi_soc_card);
ret = platform_device_add(fsi_snd_device);
if (ret)
platform_device_put(fsi_snd_device);
out:
return ret;
}
static int fsi_ak4642_remove(struct platform_device *pdev)
{
platform_device_unregister(fsi_snd_device);
return 0;
}
