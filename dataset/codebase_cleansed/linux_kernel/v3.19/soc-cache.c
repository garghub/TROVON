int snd_soc_cache_init(struct snd_soc_codec *codec)
{
const struct snd_soc_codec_driver *codec_drv = codec->driver;
size_t reg_size;
reg_size = codec_drv->reg_cache_size * codec_drv->reg_word_size;
if (!reg_size)
return 0;
dev_dbg(codec->dev, "ASoC: Initializing cache for %s codec\n",
codec->component.name);
if (codec_drv->reg_cache_default)
codec->reg_cache = kmemdup(codec_drv->reg_cache_default,
reg_size, GFP_KERNEL);
else
codec->reg_cache = kzalloc(reg_size, GFP_KERNEL);
if (!codec->reg_cache)
return -ENOMEM;
return 0;
}
int snd_soc_cache_exit(struct snd_soc_codec *codec)
{
dev_dbg(codec->dev, "ASoC: Destroying cache for %s codec\n",
codec->component.name);
kfree(codec->reg_cache);
codec->reg_cache = NULL;
return 0;
}
