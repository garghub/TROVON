static int
clk_src_get(struct snd_bebob *bebob, unsigned int *id)
{
return avc_audio_get_selector(bebob->unit, 0, 4, id);
}
