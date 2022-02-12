static unsigned int ac97_read(struct snd_soc_codec *codec,
unsigned int reg)
{
u16 *cache = codec->reg_cache;
switch (reg) {
case AC97_RESET:
case AC97_INT_PAGING:
case AC97_POWERDOWN:
case AC97_EXTENDED_STATUS:
case AC97_VENDOR_ID1:
case AC97_VENDOR_ID2:
return soc_ac97_ops.read(codec->ac97, reg);
default:
reg = reg >> 1;
if (reg >= ARRAY_SIZE(ad1980_reg))
return -EINVAL;
return cache[reg];
}
}
static int ac97_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int val)
{
u16 *cache = codec->reg_cache;
soc_ac97_ops.write(codec->ac97, reg, val);
reg = reg >> 1;
if (reg < ARRAY_SIZE(ad1980_reg))
cache[reg] = val;
return 0;
}
static int ad1980_reset(struct snd_soc_codec *codec, int try_warm)
{
u16 retry_cnt = 0;
retry:
if (try_warm && soc_ac97_ops.warm_reset) {
soc_ac97_ops.warm_reset(codec->ac97);
if (ac97_read(codec, AC97_RESET) == 0x0090)
return 1;
}
soc_ac97_ops.reset(codec->ac97);
ac97_write(codec, AC97_AD_SERIAL_CFG, 0x9900);
if (ac97_read(codec, AC97_RESET) != 0x0090)
goto err;
return 0;
err:
while (retry_cnt++ < 10)
goto retry;
printk(KERN_ERR "AD1980 AC97 reset failed\n");
return -EIO;
}
static int ad1980_soc_probe(struct snd_soc_codec *codec)
{
int ret;
u16 vendor_id2;
u16 ext_status;
printk(KERN_INFO "AD1980 SoC Audio Codec\n");
ret = snd_soc_new_ac97_codec(codec, &soc_ac97_ops, 0);
if (ret < 0) {
printk(KERN_ERR "ad1980: failed to register AC97 codec\n");
return ret;
}
ret = ad1980_reset(codec, 0);
if (ret < 0) {
printk(KERN_ERR "Failed to reset AD1980: AC97 link error\n");
goto reset_err;
}
if (ac97_read(codec, AC97_VENDOR_ID1) != 0x4144) {
ret = -ENODEV;
goto reset_err;
}
vendor_id2 = ac97_read(codec, AC97_VENDOR_ID2);
if (vendor_id2 != 0x5370) {
if (vendor_id2 != 0x5374) {
ret = -ENODEV;
goto reset_err;
} else {
printk(KERN_WARNING "ad1980: "
"Found AD1981 - only 2/2 IN/OUT Channels "
"supported\n");
}
}
ac97_write(codec, AC97_MASTER, 0x0000);
ac97_write(codec, AC97_PCM, 0x0000);
ac97_write(codec, AC97_REC_GAIN, 0x0000);
ac97_write(codec, AC97_CENTER_LFE_MASTER, 0x0000);
ac97_write(codec, AC97_SURROUND_MASTER, 0x0000);
ext_status = ac97_read(codec, AC97_EXTENDED_STATUS);
ac97_write(codec, AC97_EXTENDED_STATUS, ext_status&~0x3800);
snd_soc_add_controls(codec, ad1980_snd_ac97_controls,
ARRAY_SIZE(ad1980_snd_ac97_controls));
return 0;
reset_err:
snd_soc_free_ac97_codec(codec);
return ret;
}
static int ad1980_soc_remove(struct snd_soc_codec *codec)
{
snd_soc_free_ac97_codec(codec);
return 0;
}
static __devinit int ad1980_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_ad1980, &ad1980_dai, 1);
}
static int __devexit ad1980_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
