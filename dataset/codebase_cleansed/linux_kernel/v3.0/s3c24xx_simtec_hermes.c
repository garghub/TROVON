static int simtec_hermes_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_new_controls(dapm, dapm_widgets,
ARRAY_SIZE(dapm_widgets));
snd_soc_dapm_add_routes(dapm, base_map, ARRAY_SIZE(base_map));
snd_soc_dapm_enable_pin(dapm, "Headphone Jack");
snd_soc_dapm_enable_pin(dapm, "Line In");
snd_soc_dapm_enable_pin(dapm, "Line Out");
snd_soc_dapm_enable_pin(dapm, "Mic Jack");
simtec_audio_init(rtd);
snd_soc_dapm_sync(dapm);
return 0;
}
static int __devinit simtec_audio_hermes_probe(struct platform_device *pd)
{
dev_info(&pd->dev, "probing....\n");
return simtec_audio_core_probe(pd, &snd_soc_machine_simtec_aic33);
}
static int __init simtec_hermes_modinit(void)
{
return platform_driver_register(&simtec_audio_hermes_platdrv);
}
static void __exit simtec_hermes_modexit(void)
{
platform_driver_unregister(&simtec_audio_hermes_platdrv);
}
