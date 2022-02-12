static int
phase88_rack_clk_src_get(struct snd_bebob *bebob, unsigned int *id)
{
unsigned int enable_ext, enable_word;
int err;
err = avc_audio_get_selector(bebob->unit, 0, 0, &enable_ext);
if (err < 0)
goto end;
err = avc_audio_get_selector(bebob->unit, 0, 0, &enable_word);
if (err < 0)
goto end;
*id = (enable_ext & 0x01) | ((enable_word & 0x01) << 1);
end:
return err;
}
static int
phase24_series_clk_src_get(struct snd_bebob *bebob, unsigned int *id)
{
return avc_audio_get_selector(bebob->unit, 0, 4, id);
}
