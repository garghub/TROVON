static int fsi_hdmi_dai_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dai *cpu = rtd->cpu_dai;
int ret;
ret = snd_soc_dai_set_fmt(cpu, SND_SOC_DAIFMT_CBM_CFM);
return ret;
}
static int fsi_hdmi_probe(struct platform_device *pdev)
{
int ret = -ENOMEM;
const struct platform_device_id *id_entry;
struct fsi_hdmi_data *pdata;
id_entry = pdev->id_entry;
if (!id_entry) {
dev_err(&pdev->dev, "unknown fsi hdmi\n");
return -ENODEV;
}
pdata = (struct fsi_hdmi_data *)id_entry->driver_data;
fsi_snd_device = platform_device_alloc("soc-audio", pdata->id);
if (!fsi_snd_device)
goto out;
fsi_dai_link.cpu_dai_name = pdata->cpu_dai;
fsi_soc_card.name = pdata->card;
platform_set_drvdata(fsi_snd_device, &fsi_soc_card);
ret = platform_device_add(fsi_snd_device);
if (ret)
platform_device_put(fsi_snd_device);
out:
return ret;
}
static int fsi_hdmi_remove(struct platform_device *pdev)
{
platform_device_unregister(fsi_snd_device);
return 0;
}
static int __init fsi_hdmi_init(void)
{
return platform_driver_register(&fsi_hdmi);
}
static void __exit fsi_hdmi_exit(void)
{
platform_driver_unregister(&fsi_hdmi);
}
