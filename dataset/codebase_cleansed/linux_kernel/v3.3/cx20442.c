static unsigned int cx20442_read_reg_cache(struct snd_soc_codec *codec,
unsigned int reg)
{
u8 *reg_cache = codec->reg_cache;
if (reg >= codec->driver->reg_cache_size)
return -EINVAL;
return reg_cache[reg];
}
static int cx20442_pm_to_v253_vls(u8 value)
{
switch (value & ~(1 << CX20442_AGC)) {
case 0:
return V253_VLS_T;
case (1 << CX20442_SPKOUT):
case (1 << CX20442_MIC):
case (1 << CX20442_SPKOUT) | (1 << CX20442_MIC):
return V253_VLS_M1S1;
case (1 << CX20442_TELOUT):
case (1 << CX20442_TELIN):
case (1 << CX20442_TELOUT) | (1 << CX20442_TELIN):
return V253_VLS_L;
case (1 << CX20442_TELOUT) | (1 << CX20442_MIC):
return V253_VLS_NONE;
}
return -EINVAL;
}
static int cx20442_pm_to_v253_vsp(u8 value)
{
switch (value & ~(1 << CX20442_AGC)) {
case (1 << CX20442_SPKOUT):
case (1 << CX20442_MIC):
case (1 << CX20442_SPKOUT) | (1 << CX20442_MIC):
return (bool)(value & (1 << CX20442_AGC));
}
return (value & (1 << CX20442_AGC)) ? -EINVAL : 0;
}
static int cx20442_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
struct cx20442_priv *cx20442 = snd_soc_codec_get_drvdata(codec);
u8 *reg_cache = codec->reg_cache;
int vls, vsp, old, len;
char buf[18];
if (reg >= codec->driver->reg_cache_size)
return -EINVAL;
if (!codec->hw_write || !cx20442->control_data)
return -EIO;
old = reg_cache[reg];
reg_cache[reg] = value;
vls = cx20442_pm_to_v253_vls(value);
if (vls < 0)
return vls;
vsp = cx20442_pm_to_v253_vsp(value);
if (vsp < 0)
return vsp;
if ((vls == V253_VLS_T) ||
(vls == cx20442_pm_to_v253_vls(old))) {
if (vsp == cx20442_pm_to_v253_vsp(old))
return 0;
len = snprintf(buf, ARRAY_SIZE(buf), "at+vsp=%d\r", vsp);
} else if (vsp == cx20442_pm_to_v253_vsp(old))
len = snprintf(buf, ARRAY_SIZE(buf), "at+vls=%d\r", vls);
else
len = snprintf(buf, ARRAY_SIZE(buf),
"at+vls=%d;+vsp=%d\r", vls, vsp);
if (unlikely(len > (ARRAY_SIZE(buf) - 1)))
return -ENOMEM;
dev_dbg(codec->dev, "%s: %s\n", __func__, buf);
if (codec->hw_write(cx20442->control_data, buf, len) != len)
return -EIO;
return 0;
}
static int v253_open(struct tty_struct *tty)
{
int ret, len = strlen(v253_init);
if (!tty->ops->write)
return -EINVAL;
if (!tty->disc_data)
return -ENODEV;
if (tty->ops->write(tty, v253_init, len) != len) {
ret = -EIO;
goto err;
}
return 0;
err:
tty->disc_data = NULL;
return ret;
}
static void v253_close(struct tty_struct *tty)
{
struct snd_soc_codec *codec = tty->disc_data;
struct cx20442_priv *cx20442;
tty->disc_data = NULL;
if (!codec)
return;
cx20442 = snd_soc_codec_get_drvdata(codec);
codec->hw_write = NULL;
cx20442->control_data = NULL;
codec->card->pop_time = 0;
}
static int v253_hangup(struct tty_struct *tty)
{
v253_close(tty);
return 0;
}
static void v253_receive(struct tty_struct *tty,
const unsigned char *cp, char *fp, int count)
{
struct snd_soc_codec *codec = tty->disc_data;
struct cx20442_priv *cx20442;
if (!codec)
return;
cx20442 = snd_soc_codec_get_drvdata(codec);
if (!cx20442->control_data) {
cx20442->control_data = tty;
codec->hw_write = (hw_write_t)tty->ops->write;
codec->card->pop_time = 1;
}
}
static void v253_wakeup(struct tty_struct *tty)
{
}
static int cx20442_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct cx20442_priv *cx20442 = snd_soc_codec_get_drvdata(codec);
int err = 0;
switch (level) {
case SND_SOC_BIAS_PREPARE:
if (codec->dapm.bias_level != SND_SOC_BIAS_STANDBY)
break;
if (IS_ERR(cx20442->por))
err = PTR_ERR(cx20442->por);
else
err = regulator_enable(cx20442->por);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level != SND_SOC_BIAS_PREPARE)
break;
if (IS_ERR(cx20442->por))
err = PTR_ERR(cx20442->por);
else
err = regulator_disable(cx20442->por);
break;
default:
break;
}
if (!err)
codec->dapm.bias_level = level;
return err;
}
static int cx20442_codec_probe(struct snd_soc_codec *codec)
{
struct cx20442_priv *cx20442;
cx20442 = kzalloc(sizeof(struct cx20442_priv), GFP_KERNEL);
if (cx20442 == NULL)
return -ENOMEM;
cx20442->por = regulator_get(codec->dev, "POR");
if (IS_ERR(cx20442->por))
dev_warn(codec->dev, "failed to get the regulator");
cx20442->control_data = NULL;
snd_soc_codec_set_drvdata(codec, cx20442);
codec->hw_write = NULL;
codec->card->pop_time = 0;
return 0;
}
static int cx20442_codec_remove(struct snd_soc_codec *codec)
{
struct cx20442_priv *cx20442 = snd_soc_codec_get_drvdata(codec);
if (cx20442->control_data) {
struct tty_struct *tty = cx20442->control_data;
tty_hangup(tty);
}
if (!IS_ERR(cx20442->por)) {
regulator_put(cx20442->por);
}
snd_soc_codec_set_drvdata(codec, NULL);
kfree(cx20442);
return 0;
}
static int cx20442_platform_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&cx20442_codec_dev, &cx20442_dai, 1);
}
static int __exit cx20442_platform_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
