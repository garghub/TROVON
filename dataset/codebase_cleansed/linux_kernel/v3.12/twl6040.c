static inline unsigned int twl6040_read_reg_cache(struct snd_soc_codec *codec,
unsigned int reg)
{
u8 *cache = codec->reg_cache;
if (reg >= TWL6040_CACHEREGNUM)
return -EIO;
return cache[reg];
}
static inline void twl6040_write_reg_cache(struct snd_soc_codec *codec,
u8 reg, u8 value)
{
u8 *cache = codec->reg_cache;
if (reg >= TWL6040_CACHEREGNUM)
return;
cache[reg] = value;
}
static int twl6040_read_reg_volatile(struct snd_soc_codec *codec,
unsigned int reg)
{
struct twl6040 *twl6040 = codec->control_data;
u8 value;
if (reg >= TWL6040_CACHEREGNUM)
return -EIO;
if (likely(reg < TWL6040_REG_SW_SHADOW)) {
value = twl6040_reg_read(twl6040, reg);
twl6040_write_reg_cache(codec, reg, value);
} else {
value = twl6040_read_reg_cache(codec, reg);
}
return value;
}
static bool twl6040_is_path_unmuted(struct snd_soc_codec *codec,
unsigned int reg)
{
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
switch (reg) {
case TWL6040_REG_HSLCTL:
case TWL6040_REG_HSRCTL:
case TWL6040_REG_EARCTL:
return priv->dl1_unmuted;
case TWL6040_REG_HFLCTL:
case TWL6040_REG_HFRCTL:
return priv->dl2_unmuted;
default:
return 1;
};
}
static int twl6040_write(struct snd_soc_codec *codec,
unsigned int reg, unsigned int value)
{
struct twl6040 *twl6040 = codec->control_data;
if (reg >= TWL6040_CACHEREGNUM)
return -EIO;
twl6040_write_reg_cache(codec, reg, value);
if (likely(reg < TWL6040_REG_SW_SHADOW) &&
twl6040_is_path_unmuted(codec, reg))
return twl6040_reg_write(twl6040, reg, value);
else
return 0;
}
static void twl6040_init_chip(struct snd_soc_codec *codec)
{
struct twl6040 *twl6040 = codec->control_data;
u8 val;
val = twl6040_get_revid(twl6040);
twl6040_write_reg_cache(codec, TWL6040_REG_ASICREV, val);
twl6040_read_reg_volatile(codec, TWL6040_REG_TRIM1);
twl6040_read_reg_volatile(codec, TWL6040_REG_TRIM2);
twl6040_read_reg_volatile(codec, TWL6040_REG_TRIM3);
twl6040_read_reg_volatile(codec, TWL6040_REG_HSOTRIM);
twl6040_read_reg_volatile(codec, TWL6040_REG_HFOTRIM);
twl6040_write_reg_cache(codec, TWL6040_REG_MICLCTL, 0x18);
twl6040_write_reg_cache(codec, TWL6040_REG_MICRCTL, 0x18);
twl6040_write_reg_cache(codec, TWL6040_REG_HSGAIN, 0xff);
twl6040_write_reg_cache(codec, TWL6040_REG_EARCTL, 0x1e);
twl6040_write_reg_cache(codec, TWL6040_REG_HFLGAIN, 0x1d);
twl6040_write_reg_cache(codec, TWL6040_REG_HFRGAIN, 0x1d);
twl6040_write_reg_cache(codec, TWL6040_REG_LINEGAIN, 0);
}
static void twl6040_restore_regs(struct snd_soc_codec *codec)
{
u8 *cache = codec->reg_cache;
int reg, i;
for (i = 0; i < ARRAY_SIZE(twl6040_restore_list); i++) {
reg = twl6040_restore_list[i];
twl6040_write(codec, reg, cache[reg]);
}
}
static int headset_power_mode(struct snd_soc_codec *codec, int high_perf)
{
int hslctl, hsrctl;
int mask = TWL6040_HSDRVMODE | TWL6040_HSDACMODE;
hslctl = twl6040_read_reg_cache(codec, TWL6040_REG_HSLCTL);
hsrctl = twl6040_read_reg_cache(codec, TWL6040_REG_HSRCTL);
if (high_perf) {
hslctl &= ~mask;
hsrctl &= ~mask;
} else {
hslctl |= mask;
hsrctl |= mask;
}
twl6040_write(codec, TWL6040_REG_HSLCTL, hslctl);
twl6040_write(codec, TWL6040_REG_HSRCTL, hsrctl);
return 0;
}
static int twl6040_hs_dac_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
u8 hslctl, hsrctl;
hslctl = twl6040_read_reg_cache(codec, TWL6040_REG_HSLCTL);
hsrctl = twl6040_read_reg_cache(codec, TWL6040_REG_HSRCTL);
if (SND_SOC_DAPM_EVENT_ON(event)) {
hslctl |= TWL6040_HSDACENA;
hsrctl |= TWL6040_HSDACENA;
} else {
hslctl &= ~TWL6040_HSDACENA;
hsrctl &= ~TWL6040_HSDACENA;
}
twl6040_write(codec, TWL6040_REG_HSLCTL, hslctl);
twl6040_write(codec, TWL6040_REG_HSRCTL, hsrctl);
msleep(1);
return 0;
}
static int twl6040_ep_drv_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
int ret = 0;
if (SND_SOC_DAPM_EVENT_ON(event)) {
priv->hs_power_mode_locked = 1;
ret = headset_power_mode(codec, 1);
} else {
priv->hs_power_mode_locked = 0;
ret = headset_power_mode(codec, priv->hs_power_mode);
}
msleep(1);
return ret;
}
static void twl6040_hs_jack_report(struct snd_soc_codec *codec,
struct snd_soc_jack *jack, int report)
{
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
int status;
mutex_lock(&priv->mutex);
status = twl6040_read_reg_volatile(codec, TWL6040_REG_STATUS);
if (status & TWL6040_PLUGCOMP)
snd_soc_jack_report(jack, report, report);
else
snd_soc_jack_report(jack, 0, report);
mutex_unlock(&priv->mutex);
}
void twl6040_hs_jack_detect(struct snd_soc_codec *codec,
struct snd_soc_jack *jack, int report)
{
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
struct twl6040_jack_data *hs_jack = &priv->hs_jack;
hs_jack->jack = jack;
hs_jack->report = report;
twl6040_hs_jack_report(codec, hs_jack->jack, hs_jack->report);
}
static void twl6040_accessory_work(struct work_struct *work)
{
struct twl6040_data *priv = container_of(work,
struct twl6040_data, hs_jack.work.work);
struct snd_soc_codec *codec = priv->codec;
struct twl6040_jack_data *hs_jack = &priv->hs_jack;
twl6040_hs_jack_report(codec, hs_jack->jack, hs_jack->report);
}
static irqreturn_t twl6040_audio_handler(int irq, void *data)
{
struct snd_soc_codec *codec = data;
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
queue_delayed_work(system_power_efficient_wq,
&priv->hs_jack.work, msecs_to_jiffies(200));
return IRQ_HANDLED;
}
static int twl6040_soc_dapm_put_vibra_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_dapm_kcontrol_codec(kcontrol);
struct soc_enum *e = (struct soc_enum *)kcontrol->private_value;
unsigned int val;
val = twl6040_read_reg_volatile(codec, e->reg);
if (val & TWL6040_VIBENA && !(val & TWL6040_VIBSEL))
return -EBUSY;
return snd_soc_dapm_put_enum_double(kcontrol, ucontrol);
}
static int twl6040_headset_power_get_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
ucontrol->value.enumerated.item[0] = priv->hs_power_mode;
return 0;
}
static int twl6040_headset_power_put_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
int high_perf = ucontrol->value.enumerated.item[0];
int ret = 0;
if (!priv->hs_power_mode_locked)
ret = headset_power_mode(codec, high_perf);
if (!ret)
priv->hs_power_mode = high_perf;
return ret;
}
static int twl6040_pll_get_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
ucontrol->value.enumerated.item[0] = priv->pll_power_mode;
return 0;
}
static int twl6040_pll_put_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
priv->pll_power_mode = ucontrol->value.enumerated.item[0];
return 0;
}
int twl6040_get_dl1_gain(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = &codec->dapm;
if (snd_soc_dapm_get_pin_status(dapm, "EP"))
return -1;
if (snd_soc_dapm_get_pin_status(dapm, "HSOR") ||
snd_soc_dapm_get_pin_status(dapm, "HSOL")) {
u8 val = snd_soc_read(codec, TWL6040_REG_HSLCTL);
if (val & TWL6040_HSDACMODE)
return -8;
else
return -1;
}
return 0;
}
int twl6040_get_clk_id(struct snd_soc_codec *codec)
{
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
return priv->pll_power_mode;
}
int twl6040_get_trim_value(struct snd_soc_codec *codec, enum twl6040_trim trim)
{
if (unlikely(trim >= TWL6040_TRIM_INVAL))
return -EINVAL;
return twl6040_read_reg_cache(codec, TWL6040_REG_TRIM1 + trim);
}
int twl6040_get_hs_step_size(struct snd_soc_codec *codec)
{
struct twl6040 *twl6040 = codec->control_data;
if (twl6040_get_revid(twl6040) < TWL6040_REV_ES1_3)
return 2;
else
return 1;
}
static int twl6040_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct twl6040 *twl6040 = codec->control_data;
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (priv->codec_powered)
break;
ret = twl6040_power(twl6040, 1);
if (ret)
return ret;
priv->codec_powered = 1;
twl6040_restore_regs(codec);
twl6040_write(codec, TWL6040_REG_GPOCTL, 0x02);
break;
case SND_SOC_BIAS_OFF:
if (!priv->codec_powered)
break;
twl6040_power(twl6040, 0);
priv->codec_powered = 0;
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int twl6040_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&sysclk_constraints[priv->pll_power_mode]);
return 0;
}
static int twl6040_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
int rate;
rate = params_rate(params);
switch (rate) {
case 11250:
case 22500:
case 44100:
case 88200:
if (unlikely(priv->pll == TWL6040_SYSCLK_SEL_HPPLL)) {
dev_err(codec->dev, "HPPLL does not support rate %d\n",
rate);
return -EINVAL;
}
priv->sysclk = 17640000;
break;
case 8000:
case 16000:
case 32000:
case 48000:
case 96000:
priv->sysclk = 19200000;
break;
default:
dev_err(codec->dev, "unsupported rate %d\n", rate);
return -EINVAL;
}
return 0;
}
static int twl6040_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct twl6040 *twl6040 = codec->control_data;
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
int ret;
if (!priv->sysclk) {
dev_err(codec->dev,
"no mclk configured, call set_sysclk() on init\n");
return -EINVAL;
}
ret = twl6040_set_pll(twl6040, priv->pll, priv->clk_in, priv->sysclk);
if (ret) {
dev_err(codec->dev, "Can not set PLL (%d)\n", ret);
return -EPERM;
}
return 0;
}
static int twl6040_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
switch (clk_id) {
case TWL6040_SYSCLK_SEL_LPPLL:
case TWL6040_SYSCLK_SEL_HPPLL:
priv->pll = clk_id;
priv->clk_in = freq;
break;
default:
dev_err(codec->dev, "unknown clk_id %d\n", clk_id);
return -EINVAL;
}
return 0;
}
static void twl6040_mute_path(struct snd_soc_codec *codec, enum twl6040_dai_id id,
int mute)
{
struct twl6040 *twl6040 = codec->control_data;
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
int hslctl, hsrctl, earctl;
int hflctl, hfrctl;
switch (id) {
case TWL6040_DAI_DL1:
hslctl = twl6040_read_reg_cache(codec, TWL6040_REG_HSLCTL);
hsrctl = twl6040_read_reg_cache(codec, TWL6040_REG_HSRCTL);
earctl = twl6040_read_reg_cache(codec, TWL6040_REG_EARCTL);
if (mute) {
earctl &= ~0x01;
hslctl &= ~(TWL6040_HSDRVENA | TWL6040_HSDACENA);
hsrctl &= ~(TWL6040_HSDRVENA | TWL6040_HSDACENA);
}
twl6040_reg_write(twl6040, TWL6040_REG_EARCTL, earctl);
twl6040_reg_write(twl6040, TWL6040_REG_HSLCTL, hslctl);
twl6040_reg_write(twl6040, TWL6040_REG_HSRCTL, hsrctl);
priv->dl1_unmuted = !mute;
break;
case TWL6040_DAI_DL2:
hflctl = twl6040_read_reg_cache(codec, TWL6040_REG_HFLCTL);
hfrctl = twl6040_read_reg_cache(codec, TWL6040_REG_HFRCTL);
if (mute) {
hflctl &= ~(TWL6040_HFDACENA | TWL6040_HFPGAENA |
TWL6040_HFDRVENA);
hfrctl &= ~(TWL6040_HFDACENA | TWL6040_HFPGAENA |
TWL6040_HFDRVENA);
}
twl6040_reg_write(twl6040, TWL6040_REG_HFLCTL, hflctl);
twl6040_reg_write(twl6040, TWL6040_REG_HFRCTL, hfrctl);
priv->dl2_unmuted = !mute;
break;
default:
break;
};
}
static int twl6040_digital_mute(struct snd_soc_dai *dai, int mute)
{
switch (dai->id) {
case TWL6040_DAI_LEGACY:
twl6040_mute_path(dai->codec, TWL6040_DAI_DL1, mute);
twl6040_mute_path(dai->codec, TWL6040_DAI_DL2, mute);
break;
case TWL6040_DAI_DL1:
case TWL6040_DAI_DL2:
twl6040_mute_path(dai->codec, dai->id, mute);
break;
default:
break;
}
return 0;
}
static int twl6040_suspend(struct snd_soc_codec *codec)
{
twl6040_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int twl6040_resume(struct snd_soc_codec *codec)
{
twl6040_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int twl6040_probe(struct snd_soc_codec *codec)
{
struct twl6040_data *priv;
struct platform_device *pdev = container_of(codec->dev,
struct platform_device, dev);
int ret = 0;
priv = devm_kzalloc(codec->dev, sizeof(*priv), GFP_KERNEL);
if (priv == NULL)
return -ENOMEM;
snd_soc_codec_set_drvdata(codec, priv);
priv->codec = codec;
codec->control_data = dev_get_drvdata(codec->dev->parent);
priv->plug_irq = platform_get_irq(pdev, 0);
if (priv->plug_irq < 0) {
dev_err(codec->dev, "invalid irq\n");
return -EINVAL;
}
INIT_DELAYED_WORK(&priv->hs_jack.work, twl6040_accessory_work);
mutex_init(&priv->mutex);
ret = request_threaded_irq(priv->plug_irq, NULL,
twl6040_audio_handler, IRQF_NO_SUSPEND,
"twl6040_irq_plug", codec);
if (ret) {
dev_err(codec->dev, "PLUG IRQ request failed: %d\n", ret);
return ret;
}
twl6040_init_chip(codec);
return twl6040_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
}
static int twl6040_remove(struct snd_soc_codec *codec)
{
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
free_irq(priv->plug_irq, codec);
twl6040_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int twl6040_codec_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev, &soc_codec_dev_twl6040,
twl6040_dai, ARRAY_SIZE(twl6040_dai));
}
static int twl6040_codec_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
