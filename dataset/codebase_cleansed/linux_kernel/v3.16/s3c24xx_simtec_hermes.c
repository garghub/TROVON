static int simtec_hermes_init(struct snd_soc_pcm_runtime *rtd)
{
simtec_audio_init(rtd);
return 0;
}
static int simtec_audio_hermes_probe(struct platform_device *pd)
{
dev_info(&pd->dev, "probing....\n");
return simtec_audio_core_probe(pd, &snd_soc_machine_simtec_aic33);
}
