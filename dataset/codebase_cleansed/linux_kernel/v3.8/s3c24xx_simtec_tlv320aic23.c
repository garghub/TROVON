static int simtec_tlv320aic23_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_enable_pin(dapm, "Headphone Jack");
snd_soc_dapm_enable_pin(dapm, "Line In");
snd_soc_dapm_enable_pin(dapm, "Line Out");
snd_soc_dapm_enable_pin(dapm, "Mic Jack");
simtec_audio_init(rtd);
return 0;
}
static int simtec_audio_tlv320aic23_probe(struct platform_device *pd)
{
return simtec_audio_core_probe(pd, &snd_soc_machine_simtec_aic23);
}
