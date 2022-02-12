static bool ad1980_readable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case AC97_RESET ... AC97_MASTER_MONO:
case AC97_PHONE ... AC97_CD:
case AC97_AUX ... AC97_GENERAL_PURPOSE:
case AC97_POWERDOWN ... AC97_PCM_LR_ADC_RATE:
case AC97_SPDIF:
case AC97_CODEC_CLASS_REV:
case AC97_PCI_SVID:
case AC97_AD_CODEC_CFG:
case AC97_AD_JACK_SPDIF:
case AC97_AD_SERIAL_CFG:
case AC97_VENDOR_ID1:
case AC97_VENDOR_ID2:
return true;
default:
return false;
}
}
static bool ad1980_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case AC97_VENDOR_ID1:
case AC97_VENDOR_ID2:
return false;
default:
return ad1980_readable_reg(dev, reg);
}
}
static int ad1980_reset(struct snd_soc_codec *codec, int try_warm)
{
struct snd_ac97 *ac97 = snd_soc_codec_get_drvdata(codec);
unsigned int retry_cnt = 0;
int ret;
do {
ret = snd_ac97_reset(ac97, true, AD1980_VENDOR_ID,
AD1980_VENDOR_MASK);
if (ret >= 0)
return 0;
snd_soc_write(codec, AC97_AD_SERIAL_CFG, 0x9900);
} while (retry_cnt++ < 10);
dev_err(codec->dev, "Failed to reset: AC97 link error\n");
return -EIO;
}
static int ad1980_soc_probe(struct snd_soc_codec *codec)
{
struct snd_ac97 *ac97;
struct regmap *regmap;
int ret;
u16 vendor_id2;
u16 ext_status;
ac97 = snd_soc_new_ac97_codec(codec, 0, 0);
if (IS_ERR(ac97)) {
ret = PTR_ERR(ac97);
dev_err(codec->dev, "Failed to register AC97 codec: %d\n", ret);
return ret;
}
regmap = regmap_init_ac97(ac97, &ad1980_regmap_config);
if (IS_ERR(regmap)) {
ret = PTR_ERR(regmap);
goto err_free_ac97;
}
snd_soc_codec_init_regmap(codec, regmap);
snd_soc_codec_set_drvdata(codec, ac97);
ret = ad1980_reset(codec, 0);
if (ret < 0)
goto reset_err;
vendor_id2 = snd_soc_read(codec, AC97_VENDOR_ID2);
if (vendor_id2 == 0x5374) {
dev_warn(codec->dev,
"Found AD1981 - only 2/2 IN/OUT Channels supported\n");
}
snd_soc_write(codec, AC97_MASTER, 0x0000);
snd_soc_write(codec, AC97_PCM, 0x0000);
snd_soc_write(codec, AC97_REC_GAIN, 0x0000);
snd_soc_write(codec, AC97_CENTER_LFE_MASTER, 0x0000);
snd_soc_write(codec, AC97_SURROUND_MASTER, 0x0000);
ext_status = snd_soc_read(codec, AC97_EXTENDED_STATUS);
snd_soc_write(codec, AC97_EXTENDED_STATUS, ext_status&~0x3800);
return 0;
reset_err:
snd_soc_codec_exit_regmap(codec);
err_free_ac97:
snd_soc_free_ac97_codec(ac97);
return ret;
}
static int ad1980_soc_remove(struct snd_soc_codec *codec)
{
struct snd_ac97 *ac97 = snd_soc_codec_get_drvdata(codec);
snd_soc_codec_exit_regmap(codec);
snd_soc_free_ac97_codec(ac97);
return 0;
}
static int ad1980_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_ad1980, &ad1980_dai, 1);
}
static int ad1980_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
