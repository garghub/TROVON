static int snd_soc_get_volsw_2r_st(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
unsigned int reg = mc->reg;
unsigned int reg2 = mc->rreg;
int val[2], val2[2], i;
val[0] = snd_soc_read(codec, reg) & 0x3f;
val[1] = (snd_soc_read(codec, PM860X_SIDETONE_SHIFT) >> 4) & 0xf;
val2[0] = snd_soc_read(codec, reg2) & 0x3f;
val2[1] = (snd_soc_read(codec, PM860X_SIDETONE_SHIFT)) & 0xf;
for (i = 0; i < ARRAY_SIZE(st_table); i++) {
if ((st_table[i].m == val[0]) && (st_table[i].n == val[1]))
ucontrol->value.integer.value[0] = i;
if ((st_table[i].m == val2[0]) && (st_table[i].n == val2[1]))
ucontrol->value.integer.value[1] = i;
}
return 0;
}
static int snd_soc_put_volsw_2r_st(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
unsigned int reg = mc->reg;
unsigned int reg2 = mc->rreg;
int err;
unsigned int val, val2;
val = ucontrol->value.integer.value[0];
val2 = ucontrol->value.integer.value[1];
if (val >= ARRAY_SIZE(st_table) || val2 >= ARRAY_SIZE(st_table))
return -EINVAL;
err = snd_soc_update_bits(codec, reg, 0x3f, st_table[val].m);
if (err < 0)
return err;
err = snd_soc_update_bits(codec, PM860X_SIDETONE_SHIFT, 0xf0,
st_table[val].n << 4);
if (err < 0)
return err;
err = snd_soc_update_bits(codec, reg2, 0x3f, st_table[val2].m);
if (err < 0)
return err;
err = snd_soc_update_bits(codec, PM860X_SIDETONE_SHIFT, 0x0f,
st_table[val2].n);
return err;
}
static int snd_soc_get_volsw_2r_out(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
unsigned int reg = mc->reg;
unsigned int reg2 = mc->rreg;
unsigned int shift = mc->shift;
int max = mc->max, val, val2;
unsigned int mask = (1 << fls(max)) - 1;
val = snd_soc_read(codec, reg) >> shift;
val2 = snd_soc_read(codec, reg2) >> shift;
ucontrol->value.integer.value[0] = (max - val) & mask;
ucontrol->value.integer.value[1] = (max - val2) & mask;
return 0;
}
static int snd_soc_put_volsw_2r_out(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
unsigned int reg = mc->reg;
unsigned int reg2 = mc->rreg;
unsigned int shift = mc->shift;
int max = mc->max;
unsigned int mask = (1 << fls(max)) - 1;
int err;
unsigned int val, val2, val_mask;
val_mask = mask << shift;
val = ((max - ucontrol->value.integer.value[0]) & mask);
val2 = ((max - ucontrol->value.integer.value[1]) & mask);
val = val << shift;
val2 = val2 << shift;
err = snd_soc_update_bits(codec, reg, val_mask, val);
if (err < 0)
return err;
err = snd_soc_update_bits(codec, reg2, val_mask, val2);
return err;
}
static int pm860x_rsync_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
snd_soc_update_bits(codec, PM860X_DAC_OFFSET, DAC_MUTE, 0);
snd_soc_update_bits(codec, PM860X_EAR_CTRL_2,
RSYNC_CHANGE, RSYNC_CHANGE);
return 0;
}
static int pm860x_dac_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
unsigned int dac = 0;
int data;
if (!strcmp(w->name, "Left DAC"))
dac = DAC_LEFT;
if (!strcmp(w->name, "Right DAC"))
dac = DAC_RIGHT;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
if (dac) {
dac |= MODULATOR;
snd_soc_update_bits(codec, PM860X_DAC_OFFSET,
DAC_MUTE, DAC_MUTE);
snd_soc_update_bits(codec, PM860X_EAR_CTRL_2,
RSYNC_CHANGE, RSYNC_CHANGE);
snd_soc_update_bits(codec, PM860X_DAC_EN_2,
dac, dac);
}
break;
case SND_SOC_DAPM_PRE_PMD:
if (dac) {
snd_soc_update_bits(codec, PM860X_DAC_OFFSET,
DAC_MUTE, DAC_MUTE);
snd_soc_update_bits(codec, PM860X_EAR_CTRL_2,
RSYNC_CHANGE, RSYNC_CHANGE);
data = snd_soc_read(codec, PM860X_DAC_EN_2);
data &= ~dac;
if (!(data & (DAC_LEFT | DAC_RIGHT)))
data &= ~MODULATOR;
snd_soc_write(codec, PM860X_DAC_EN_2, data);
}
break;
}
return 0;
}
static int pm860x_digital_mute(struct snd_soc_dai *codec_dai, int mute)
{
struct snd_soc_codec *codec = codec_dai->codec;
int data = 0, mask = MUTE_LEFT | MUTE_RIGHT;
if (mute)
data = mask;
snd_soc_update_bits(codec, PM860X_DAC_OFFSET, mask, data);
snd_soc_update_bits(codec, PM860X_EAR_CTRL_2,
RSYNC_CHANGE, RSYNC_CHANGE);
return 0;
}
static int pm860x_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
unsigned char inf = 0, mask = 0;
switch (params_width(params)) {
case 16:
inf &= ~PCM_INF2_18WL;
break;
case 18:
inf |= PCM_INF2_18WL;
break;
default:
return -EINVAL;
}
mask |= PCM_INF2_18WL;
snd_soc_update_bits(codec, PM860X_PCM_IFACE_2, mask, inf);
switch (params_rate(params)) {
case 8000:
inf = 0;
break;
case 16000:
inf = 3;
break;
case 32000:
inf = 6;
break;
case 48000:
inf = 8;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, PM860X_PCM_RATE, 0x0f, inf);
return 0;
}
static int pm860x_pcm_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct pm860x_priv *pm860x = snd_soc_codec_get_drvdata(codec);
unsigned char inf = 0, mask = 0;
int ret = -EINVAL;
mask |= PCM_INF2_BCLK | PCM_INF2_FS | PCM_INF2_MASTER;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
case SND_SOC_DAIFMT_CBM_CFS:
if (pm860x->dir == PM860X_CLK_DIR_OUT) {
inf |= PCM_INF2_MASTER;
ret = 0;
}
break;
case SND_SOC_DAIFMT_CBS_CFS:
if (pm860x->dir == PM860X_CLK_DIR_IN) {
inf &= ~PCM_INF2_MASTER;
ret = 0;
}
break;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
inf |= PCM_EXACT_I2S;
ret = 0;
break;
}
mask |= PCM_MODE_MASK;
if (ret)
return ret;
snd_soc_update_bits(codec, PM860X_PCM_IFACE_2, mask, inf);
return 0;
}
static int pm860x_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct pm860x_priv *pm860x = snd_soc_codec_get_drvdata(codec);
if (dir == PM860X_CLK_DIR_OUT)
pm860x->dir = PM860X_CLK_DIR_OUT;
else
return -EINVAL;
return 0;
}
static int pm860x_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
unsigned char inf;
switch (params_width(params)) {
case 16:
inf = 0;
break;
case 18:
inf = PCM_INF2_18WL;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, PM860X_I2S_IFACE_2, PCM_INF2_18WL, inf);
switch (params_rate(params)) {
case 8000:
inf = 0;
break;
case 11025:
inf = 1;
break;
case 16000:
inf = 3;
break;
case 22050:
inf = 4;
break;
case 32000:
inf = 6;
break;
case 44100:
inf = 7;
break;
case 48000:
inf = 8;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, PM860X_I2S_IFACE_4, 0xf, inf);
return 0;
}
static int pm860x_i2s_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct pm860x_priv *pm860x = snd_soc_codec_get_drvdata(codec);
unsigned char inf = 0, mask = 0;
mask |= PCM_INF2_BCLK | PCM_INF2_FS | PCM_INF2_MASTER;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
if (pm860x->dir == PM860X_CLK_DIR_OUT)
inf |= PCM_INF2_MASTER;
else
return -EINVAL;
break;
case SND_SOC_DAIFMT_CBS_CFS:
if (pm860x->dir == PM860X_CLK_DIR_IN)
inf &= ~PCM_INF2_MASTER;
else
return -EINVAL;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
inf |= PCM_EXACT_I2S;
break;
default:
return -EINVAL;
}
mask |= PCM_MODE_MASK;
snd_soc_update_bits(codec, PM860X_I2S_IFACE_2, mask, inf);
return 0;
}
static int pm860x_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct pm860x_priv *pm860x = snd_soc_codec_get_drvdata(codec);
int data;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
data = AUDIO_PLL | AUDIO_SECTION_ON;
pm860x_reg_write(pm860x->i2c, REG_MISC2, data);
udelay(300);
data = AUDIO_PLL | AUDIO_SECTION_RESET
| AUDIO_SECTION_ON;
pm860x_reg_write(pm860x->i2c, REG_MISC2, data);
}
break;
case SND_SOC_BIAS_OFF:
data = AUDIO_PLL | AUDIO_SECTION_RESET | AUDIO_SECTION_ON;
pm860x_set_bits(pm860x->i2c, REG_MISC2, data, 0);
break;
}
return 0;
}
static irqreturn_t pm860x_codec_handler(int irq, void *data)
{
struct pm860x_priv *pm860x = data;
int status, shrt, report = 0, mic_report = 0;
int mask;
status = pm860x_reg_read(pm860x->i2c, REG_STATUS_1);
shrt = pm860x_reg_read(pm860x->i2c, REG_SHORTS);
mask = pm860x->det.hs_shrt | pm860x->det.hook_det | pm860x->det.lo_shrt
| pm860x->det.hp_det;
#ifndef CONFIG_SND_SOC_88PM860X_MODULE
if (status & (HEADSET_STATUS | MIC_STATUS | SHORT_HS1 | SHORT_HS2 |
SHORT_LO1 | SHORT_LO2))
trace_snd_soc_jack_irq(dev_name(pm860x->codec->dev));
#endif
if ((pm860x->det.hp_det & SND_JACK_HEADPHONE)
&& (status & HEADSET_STATUS))
report |= SND_JACK_HEADPHONE;
if ((pm860x->det.mic_det & SND_JACK_MICROPHONE)
&& (status & MIC_STATUS))
mic_report |= SND_JACK_MICROPHONE;
if (pm860x->det.hs_shrt && (shrt & (SHORT_HS1 | SHORT_HS2)))
report |= pm860x->det.hs_shrt;
if (pm860x->det.hook_det && (status & HOOK_STATUS))
report |= pm860x->det.hook_det;
if (pm860x->det.lo_shrt && (shrt & (SHORT_LO1 | SHORT_LO2)))
report |= pm860x->det.lo_shrt;
if (report)
snd_soc_jack_report(pm860x->det.hp_jack, report, mask);
if (mic_report)
snd_soc_jack_report(pm860x->det.mic_jack, SND_JACK_MICROPHONE,
SND_JACK_MICROPHONE);
dev_dbg(pm860x->codec->dev, "headphone report:0x%x, mask:%x\n",
report, mask);
dev_dbg(pm860x->codec->dev, "microphone report:0x%x\n", mic_report);
return IRQ_HANDLED;
}
int pm860x_hs_jack_detect(struct snd_soc_codec *codec,
struct snd_soc_jack *jack,
int det, int hook, int hs_shrt, int lo_shrt)
{
struct pm860x_priv *pm860x = snd_soc_codec_get_drvdata(codec);
int data;
pm860x->det.hp_jack = jack;
pm860x->det.hp_det = det;
pm860x->det.hook_det = hook;
pm860x->det.hs_shrt = hs_shrt;
pm860x->det.lo_shrt = lo_shrt;
if (det & SND_JACK_HEADPHONE)
pm860x_set_bits(pm860x->i2c, REG_HS_DET,
EN_HS_DET, EN_HS_DET);
if (hs_shrt) {
data = CLR_SHORT_HS2 | CLR_SHORT_HS1;
pm860x_set_bits(pm860x->i2c, REG_SHORTS, data, data);
}
if (lo_shrt) {
data = CLR_SHORT_LO2 | CLR_SHORT_LO1;
pm860x_set_bits(pm860x->i2c, REG_SHORTS, data, data);
}
pm860x_codec_handler(0, pm860x);
return 0;
}
int pm860x_mic_jack_detect(struct snd_soc_codec *codec,
struct snd_soc_jack *jack, int det)
{
struct pm860x_priv *pm860x = snd_soc_codec_get_drvdata(codec);
pm860x->det.mic_jack = jack;
pm860x->det.mic_det = det;
if (det & SND_JACK_MICROPHONE)
pm860x_set_bits(pm860x->i2c, REG_MIC_DET,
MICDET_MASK, MICDET_MASK);
pm860x_codec_handler(0, pm860x);
return 0;
}
static int pm860x_probe(struct snd_soc_codec *codec)
{
struct pm860x_priv *pm860x = snd_soc_codec_get_drvdata(codec);
int i, ret;
pm860x->codec = codec;
for (i = 0; i < 4; i++) {
ret = request_threaded_irq(pm860x->irq[i], NULL,
pm860x_codec_handler, IRQF_ONESHOT,
pm860x->name[i], pm860x);
if (ret < 0) {
dev_err(codec->dev, "Failed to request IRQ!\n");
goto out;
}
}
return 0;
out:
while (--i >= 0)
free_irq(pm860x->irq[i], pm860x);
return ret;
}
static int pm860x_remove(struct snd_soc_codec *codec)
{
struct pm860x_priv *pm860x = snd_soc_codec_get_drvdata(codec);
int i;
for (i = 3; i >= 0; i--)
free_irq(pm860x->irq[i], pm860x);
return 0;
}
static struct regmap *pm860x_get_regmap(struct device *dev)
{
struct pm860x_priv *pm860x = dev_get_drvdata(dev);
return pm860x->regmap;
}
static int pm860x_codec_probe(struct platform_device *pdev)
{
struct pm860x_chip *chip = dev_get_drvdata(pdev->dev.parent);
struct pm860x_priv *pm860x;
struct resource *res;
int i, ret;
pm860x = devm_kzalloc(&pdev->dev, sizeof(struct pm860x_priv),
GFP_KERNEL);
if (pm860x == NULL)
return -ENOMEM;
pm860x->chip = chip;
pm860x->i2c = (chip->id == CHIP_PM8607) ? chip->client
: chip->companion;
pm860x->regmap = (chip->id == CHIP_PM8607) ? chip->regmap
: chip->regmap_companion;
platform_set_drvdata(pdev, pm860x);
for (i = 0; i < 4; i++) {
res = platform_get_resource(pdev, IORESOURCE_IRQ, i);
if (!res) {
dev_err(&pdev->dev, "Failed to get IRQ resources\n");
return -EINVAL;
}
pm860x->irq[i] = res->start + chip->irq_base;
strncpy(pm860x->name[i], res->name, MAX_NAME_LEN);
}
ret = snd_soc_register_codec(&pdev->dev, &soc_codec_dev_pm860x,
pm860x_dai, ARRAY_SIZE(pm860x_dai));
if (ret) {
dev_err(&pdev->dev, "Failed to register codec\n");
return -EINVAL;
}
return ret;
}
static int pm860x_codec_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
