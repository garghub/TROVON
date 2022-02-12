static int simtec_tlv320aic23_init(struct snd_soc_pcm_runtime *rtd)
{
simtec_audio_init(rtd);
return 0;
}
static int simtec_audio_tlv320aic23_probe(struct platform_device *pd)
{
return simtec_audio_core_probe(pd, &snd_soc_machine_simtec_aic23);
}
