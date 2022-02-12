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
static int twl6040_write(struct snd_soc_codec *codec,
unsigned int reg, unsigned int value)
{
struct twl6040 *twl6040 = codec->control_data;
if (reg >= TWL6040_CACHEREGNUM)
return -EIO;
twl6040_write_reg_cache(codec, reg, value);
if (likely(reg < TWL6040_REG_SW_SHADOW))
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
static inline int twl6040_hs_ramp_step(struct snd_soc_codec *codec,
unsigned int left_step, unsigned int right_step)
{
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
struct twl6040_output *headset = &priv->headset;
int left_complete = 0, right_complete = 0;
u8 reg, val;
left_step = (left_step > 0xF) ? 0xF : left_step;
reg = twl6040_read_reg_cache(codec, TWL6040_REG_HSGAIN);
val = (~reg & TWL6040_HSL_VOL_MASK);
if (headset->ramp == TWL6040_RAMP_UP) {
if (val < headset->left_vol) {
if (val + left_step > headset->left_vol)
val = headset->left_vol;
else
val += left_step;
reg &= ~TWL6040_HSL_VOL_MASK;
twl6040_write(codec, TWL6040_REG_HSGAIN,
(reg | (~val & TWL6040_HSL_VOL_MASK)));
} else {
left_complete = 1;
}
} else if (headset->ramp == TWL6040_RAMP_DOWN) {
if (val > 0x0) {
if ((int)val - (int)left_step < 0)
val = 0;
else
val -= left_step;
reg &= ~TWL6040_HSL_VOL_MASK;
twl6040_write(codec, TWL6040_REG_HSGAIN, reg |
(~val & TWL6040_HSL_VOL_MASK));
} else {
left_complete = 1;
}
}
right_step = (right_step > 0xF) ? 0xF : right_step;
reg = twl6040_read_reg_cache(codec, TWL6040_REG_HSGAIN);
val = (~reg & TWL6040_HSR_VOL_MASK) >> TWL6040_HSR_VOL_SHIFT;
if (headset->ramp == TWL6040_RAMP_UP) {
if (val < headset->right_vol) {
if (val + right_step > headset->right_vol)
val = headset->right_vol;
else
val += right_step;
reg &= ~TWL6040_HSR_VOL_MASK;
twl6040_write(codec, TWL6040_REG_HSGAIN,
(reg | (~val << TWL6040_HSR_VOL_SHIFT)));
} else {
right_complete = 1;
}
} else if (headset->ramp == TWL6040_RAMP_DOWN) {
if (val > 0x0) {
if ((int)val - (int)right_step < 0)
val = 0;
else
val -= right_step;
reg &= ~TWL6040_HSR_VOL_MASK;
twl6040_write(codec, TWL6040_REG_HSGAIN,
reg | (~val << TWL6040_HSR_VOL_SHIFT));
} else {
right_complete = 1;
}
}
return left_complete & right_complete;
}
static inline int twl6040_hf_ramp_step(struct snd_soc_codec *codec,
unsigned int left_step, unsigned int right_step)
{
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
struct twl6040_output *handsfree = &priv->handsfree;
int left_complete = 0, right_complete = 0;
u16 reg, val;
left_step = (left_step > 0x1D) ? 0x1D : left_step;
reg = twl6040_read_reg_cache(codec, TWL6040_REG_HFLGAIN);
reg = 0x1D - reg;
val = (reg & TWL6040_HF_VOL_MASK);
if (handsfree->ramp == TWL6040_RAMP_UP) {
if (val < handsfree->left_vol) {
if (val + left_step > handsfree->left_vol)
val = handsfree->left_vol;
else
val += left_step;
reg &= ~TWL6040_HF_VOL_MASK;
twl6040_write(codec, TWL6040_REG_HFLGAIN,
reg | (0x1D - val));
} else {
left_complete = 1;
}
} else if (handsfree->ramp == TWL6040_RAMP_DOWN) {
if (val > 0) {
if ((int)val - (int)left_step < 0)
val = 0;
else
val -= left_step;
reg &= ~TWL6040_HF_VOL_MASK;
twl6040_write(codec, TWL6040_REG_HFLGAIN,
reg | (0x1D - val));
} else {
left_complete = 1;
}
}
right_step = (right_step > 0x1D) ? 0x1D : right_step;
reg = twl6040_read_reg_cache(codec, TWL6040_REG_HFRGAIN);
reg = 0x1D - reg;
val = (reg & TWL6040_HF_VOL_MASK);
if (handsfree->ramp == TWL6040_RAMP_UP) {
if (val < handsfree->right_vol) {
if (val + right_step > handsfree->right_vol)
val = handsfree->right_vol;
else
val += right_step;
reg &= ~TWL6040_HF_VOL_MASK;
twl6040_write(codec, TWL6040_REG_HFRGAIN,
reg | (0x1D - val));
} else {
right_complete = 1;
}
} else if (handsfree->ramp == TWL6040_RAMP_DOWN) {
if (val > 0) {
if ((int)val - (int)right_step < 0)
val = 0;
else
val -= right_step;
reg &= ~TWL6040_HF_VOL_MASK;
twl6040_write(codec, TWL6040_REG_HFRGAIN,
reg | (0x1D - val));
}
}
return left_complete & right_complete;
}
static void twl6040_pga_hs_work(struct work_struct *work)
{
struct twl6040_data *priv =
container_of(work, struct twl6040_data, headset.work.work);
struct snd_soc_codec *codec = priv->codec;
struct twl6040_output *headset = &priv->headset;
int i, headset_complete;
if (headset->ramp == TWL6040_RAMP_NONE)
return;
for (i = 0; i < 16; i++) {
headset_complete = twl6040_hs_ramp_step(codec,
headset->left_step,
headset->right_step);
if (headset_complete)
break;
schedule_timeout_interruptible(
msecs_to_jiffies(headset->step_delay));
}
if (headset->ramp == TWL6040_RAMP_DOWN) {
headset->active = 0;
complete(&headset->ramp_done);
} else {
headset->active = 1;
}
headset->ramp = TWL6040_RAMP_NONE;
}
static void twl6040_pga_hf_work(struct work_struct *work)
{
struct twl6040_data *priv =
container_of(work, struct twl6040_data, handsfree.work.work);
struct snd_soc_codec *codec = priv->codec;
struct twl6040_output *handsfree = &priv->handsfree;
int i, handsfree_complete;
if (handsfree->ramp == TWL6040_RAMP_NONE)
return;
for (i = 0; i < 30; i++) {
handsfree_complete = twl6040_hf_ramp_step(codec,
handsfree->left_step,
handsfree->right_step);
if (handsfree_complete)
break;
schedule_timeout_interruptible(
msecs_to_jiffies(handsfree->step_delay));
}
if (handsfree->ramp == TWL6040_RAMP_DOWN) {
handsfree->active = 0;
complete(&handsfree->ramp_done);
} else
handsfree->active = 1;
handsfree->ramp = TWL6040_RAMP_NONE;
}
static int out_drv_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
struct twl6040_output *out;
struct delayed_work *work;
switch (w->shift) {
case 2:
out = &priv->headset;
work = &out->work;
cancel_delayed_work_sync(work);
out->left_step = priv->hs_left_step;
out->right_step = priv->hs_right_step;
out->step_delay = 5;
break;
case 4:
out = &priv->handsfree;
work = &out->work;
cancel_delayed_work_sync(work);
out->left_step = priv->hf_left_step;
out->right_step = priv->hf_right_step;
out->step_delay = 5;
break;
default:
return -1;
}
switch (event) {
case SND_SOC_DAPM_POST_PMU:
if (out->active)
break;
out->ramp = TWL6040_RAMP_UP;
out->left_step = out->left_vol;
out->right_step = out->right_vol;
queue_delayed_work(priv->workqueue, work, msecs_to_jiffies(1));
break;
case SND_SOC_DAPM_PRE_PMD:
if (!out->active)
break;
out->ramp = TWL6040_RAMP_DOWN;
INIT_COMPLETION(out->ramp_done);
queue_delayed_work(priv->workqueue, work, msecs_to_jiffies(1));
wait_for_completion_timeout(&out->ramp_done,
msecs_to_jiffies(2000));
break;
}
return 0;
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
queue_delayed_work(priv->workqueue, &priv->hs_jack.work,
msecs_to_jiffies(200));
return IRQ_HANDLED;
}
static int twl6040_put_volsw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct twl6040_data *twl6040_priv = snd_soc_codec_get_drvdata(codec);
struct twl6040_output *out = NULL;
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
int ret;
switch (mc->reg) {
case TWL6040_REG_HSGAIN:
out = &twl6040_priv->headset;
break;
case TWL6040_REG_HFLGAIN:
out = &twl6040_priv->handsfree;
break;
default:
dev_warn(codec->dev, "%s: Unexpected register: 0x%02x\n",
__func__, mc->reg);
return -EINVAL;
}
out->left_vol = ucontrol->value.integer.value[0];
out->right_vol = ucontrol->value.integer.value[1];
if (!out->active)
return 1;
ret = snd_soc_put_volsw(kcontrol, ucontrol);
if (ret < 0)
return ret;
return 1;
}
static int twl6040_get_volsw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct twl6040_data *twl6040_priv = snd_soc_codec_get_drvdata(codec);
struct twl6040_output *out = &twl6040_priv->headset;
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
switch (mc->reg) {
case TWL6040_REG_HSGAIN:
out = &twl6040_priv->headset;
break;
case TWL6040_REG_HFLGAIN:
out = &twl6040_priv->handsfree;
break;
default:
dev_warn(codec->dev, "%s: Unexpected register: 0x%02x\n",
__func__, mc->reg);
return -EINVAL;
}
ucontrol->value.integer.value[0] = out->left_vol;
ucontrol->value.integer.value[1] = out->right_vol;
return 0;
}
static int twl6040_soc_dapm_put_vibra_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_widget_list *wlist = snd_kcontrol_chip(kcontrol);
struct snd_soc_dapm_widget *widget = wlist->widgets[0];
struct snd_soc_codec *codec = widget->codec;
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
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
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
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
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
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
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
static int twl6040_suspend(struct snd_soc_codec *codec, pm_message_t state)
{
twl6040_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int twl6040_resume(struct snd_soc_codec *codec)
{
twl6040_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
twl6040_set_bias_level(codec, codec->dapm.suspend_bias_level);
return 0;
}
static int twl6040_probe(struct snd_soc_codec *codec)
{
struct twl6040_data *priv;
struct twl4030_codec_data *pdata = dev_get_platdata(codec->dev);
struct platform_device *pdev = container_of(codec->dev,
struct platform_device, dev);
int ret = 0;
priv = kzalloc(sizeof(struct twl6040_data), GFP_KERNEL);
if (priv == NULL)
return -ENOMEM;
snd_soc_codec_set_drvdata(codec, priv);
priv->codec = codec;
codec->control_data = dev_get_drvdata(codec->dev->parent);
codec->ignore_pmdown_time = 1;
if (pdata && pdata->hs_left_step && pdata->hs_right_step) {
priv->hs_left_step = pdata->hs_left_step;
priv->hs_right_step = pdata->hs_right_step;
} else {
priv->hs_left_step = 1;
priv->hs_right_step = 1;
}
if (pdata && pdata->hf_left_step && pdata->hf_right_step) {
priv->hf_left_step = pdata->hf_left_step;
priv->hf_right_step = pdata->hf_right_step;
} else {
priv->hf_left_step = 1;
priv->hf_right_step = 1;
}
priv->plug_irq = platform_get_irq(pdev, 0);
if (priv->plug_irq < 0) {
dev_err(codec->dev, "invalid irq\n");
ret = -EINVAL;
goto work_err;
}
priv->workqueue = alloc_workqueue("twl6040-codec", 0, 0);
if (!priv->workqueue) {
ret = -ENOMEM;
goto work_err;
}
INIT_DELAYED_WORK(&priv->hs_jack.work, twl6040_accessory_work);
INIT_DELAYED_WORK(&priv->headset.work, twl6040_pga_hs_work);
INIT_DELAYED_WORK(&priv->handsfree.work, twl6040_pga_hf_work);
mutex_init(&priv->mutex);
init_completion(&priv->headset.ramp_done);
init_completion(&priv->handsfree.ramp_done);
ret = request_threaded_irq(priv->plug_irq, NULL, twl6040_audio_handler,
0, "twl6040_irq_plug", codec);
if (ret) {
dev_err(codec->dev, "PLUG IRQ request failed: %d\n", ret);
goto plugirq_err;
}
twl6040_init_chip(codec);
ret = twl6040_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
if (!ret)
return 0;
free_irq(priv->plug_irq, codec);
plugirq_err:
destroy_workqueue(priv->workqueue);
work_err:
kfree(priv);
return ret;
}
static int twl6040_remove(struct snd_soc_codec *codec)
{
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
twl6040_set_bias_level(codec, SND_SOC_BIAS_OFF);
free_irq(priv->plug_irq, codec);
destroy_workqueue(priv->workqueue);
kfree(priv);
return 0;
}
static int __devinit twl6040_codec_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev, &soc_codec_dev_twl6040,
twl6040_dai, ARRAY_SIZE(twl6040_dai));
}
static int __devexit twl6040_codec_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
static int __init twl6040_codec_init(void)
{
return platform_driver_register(&twl6040_codec_driver);
}
static void __exit twl6040_codec_exit(void)
{
platform_driver_unregister(&twl6040_codec_driver);
}
