static int hw_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
return regmap_write(codec->control_data, reg, value);
}
static unsigned int hw_read(struct snd_soc_codec *codec, unsigned int reg)
{
int ret;
unsigned int val;
ret = regmap_read(codec->control_data, reg, &val);
if (ret == 0)
return val;
else
return -1;
}
int snd_soc_codec_set_cache_io(struct snd_soc_codec *codec,
struct regmap *regmap)
{
int ret;
if (!regmap)
codec->control_data = dev_get_regmap(codec->dev, NULL);
else
codec->control_data = regmap;
if (IS_ERR(codec->control_data))
return PTR_ERR(codec->control_data);
codec->write = hw_write;
codec->read = hw_read;
ret = regmap_get_val_bytes(codec->control_data);
if (ret > 0)
codec->val_bytes = ret;
codec->using_regmap = true;
return 0;
}
int snd_soc_codec_set_cache_io(struct snd_soc_codec *codec,
struct regmap *regmap)
{
return -ENOTSUPP;
}
