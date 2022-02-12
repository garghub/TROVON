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
const struct platform_device_id *id_entry;
struct fsi_ak4642_data *pdata;
id_entry = pdev->id_entry;
if (!id_entry) {
dev_err(&pdev->dev, "unknown fsi ak4642\n");
return -ENODEV;
}
pdata = (struct fsi_ak4642_data *)id_entry->driver_data;
fsi_snd_device = platform_device_alloc("soc-audio", pdata->id);
if (!fsi_snd_device)
goto out;
fsi_dai_link.name = pdata->name;
fsi_dai_link.stream_name = pdata->name;
fsi_dai_link.cpu_dai_name = pdata->cpu_dai;
fsi_dai_link.platform_name = pdata->platform;
fsi_dai_link.codec_name = pdata->codec;
fsi_soc_card.name = pdata->card;
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
static int __init fsi_ak4642_init(void)
{
return platform_driver_register(&fsi_ak4642);
}
static void __exit fsi_ak4642_exit(void)
{
platform_driver_unregister(&fsi_ak4642);
}
