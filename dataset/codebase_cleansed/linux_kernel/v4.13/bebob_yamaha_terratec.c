static int
clk_src_get(struct snd_bebob *bebob, unsigned int *id)
{
int err;
err = avc_audio_get_selector(bebob->unit, 0, 4, id);
if (err < 0)
return err;
if (*id >= ARRAY_SIZE(clk_src_types))
return -EIO;
return 0;
}
