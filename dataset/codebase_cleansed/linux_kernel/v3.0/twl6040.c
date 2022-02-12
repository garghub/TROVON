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
u8 value;
if (reg >= TWL6040_CACHEREGNUM)
return -EIO;
twl_i2c_read_u8(TWL_MODULE_AUDIO_VOICE, &value, reg);
twl6040_write_reg_cache(codec, reg, value);
return value;
}
static int twl6040_write(struct snd_soc_codec *codec,
unsigned int reg, unsigned int value)
{
if (reg >= TWL6040_CACHEREGNUM)
return -EIO;
twl6040_write_reg_cache(codec, reg, value);
return twl_i2c_write_u8(TWL_MODULE_AUDIO_VOICE, value, reg);
}
static void twl6040_init_vio_regs(struct snd_soc_codec *codec)
{
u8 *cache = codec->reg_cache;
int reg, i;
twl6040_write(codec, TWL6040_REG_ACCCTL, cache[TWL6040_REG_ACCCTL]);
for (i = 0; i < TWL6040_VIOREGNUM; i++) {
reg = twl6040_vio_reg[i];
switch (reg) {
case TWL6040_REG_ASICID:
case TWL6040_REG_ASICREV:
case TWL6040_REG_STATUS:
continue;
default:
break;
}
twl6040_write(codec, reg, cache[reg]);
}
}
static void twl6040_init_vdd_regs(struct snd_soc_codec *codec)
{
u8 *cache = codec->reg_cache;
int reg, i;
for (i = 0; i < TWL6040_VDDREGNUM; i++) {
reg = twl6040_vdd_reg[i];
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
val += left_step;
reg &= ~TWL6040_HSL_VOL_MASK;
twl6040_write(codec, TWL6040_REG_HSGAIN,
(reg | (~val & TWL6040_HSL_VOL_MASK)));
} else {
left_complete = 1;
}
} else if (headset->ramp == TWL6040_RAMP_DOWN) {
if (val > 0x0) {
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
val += right_step;
reg &= ~TWL6040_HSR_VOL_MASK;
twl6040_write(codec, TWL6040_REG_HSGAIN,
(reg | (~val << TWL6040_HSR_VOL_SHIFT)));
} else {
right_complete = 1;
}
} else if (headset->ramp == TWL6040_RAMP_DOWN) {
if (val > 0x0) {
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
val += left_step;
reg &= ~TWL6040_HF_VOL_MASK;
twl6040_write(codec, TWL6040_REG_HFLGAIN,
reg | (0x1D - val));
} else {
left_complete = 1;
}
} else if (handsfree->ramp == TWL6040_RAMP_DOWN) {
if (val > 0) {
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
val += right_step;
reg &= ~TWL6040_HF_VOL_MASK;
twl6040_write(codec, TWL6040_REG_HFRGAIN,
reg | (0x1D - val));
} else {
right_complete = 1;
}
} else if (handsfree->ramp == TWL6040_RAMP_DOWN) {
if (val > 0) {
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
container_of(work, struct twl6040_data, hs_delayed_work.work);
struct snd_soc_codec *codec = priv->codec;
struct twl6040_output *headset = &priv->headset;
unsigned int delay = headset->step_delay;
int i, headset_complete;
if (headset->ramp == TWL6040_RAMP_NONE)
return;
for (i = 0; i <= 16; i++) {
headset_complete = 1;
if (headset->ramp != TWL6040_RAMP_NONE)
headset_complete = twl6040_hs_ramp_step(codec,
headset->left_step,
headset->right_step);
if (headset_complete)
break;
if (i >= 8)
schedule_timeout_interruptible(msecs_to_jiffies(delay +
(delay >> 1)));
else
schedule_timeout_interruptible(msecs_to_jiffies(delay));
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
container_of(work, struct twl6040_data, hf_delayed_work.work);
struct snd_soc_codec *codec = priv->codec;
struct twl6040_output *handsfree = &priv->handsfree;
unsigned int delay = handsfree->step_delay;
int i, handsfree_complete;
if (handsfree->ramp == TWL6040_RAMP_NONE)
return;
for (i = 0; i <= 32; i++) {
handsfree_complete = 1;
if (handsfree->ramp != TWL6040_RAMP_NONE)
handsfree_complete = twl6040_hf_ramp_step(codec,
handsfree->left_step,
handsfree->right_step);
if (handsfree_complete)
break;
if (i >= 16)
schedule_timeout_interruptible(msecs_to_jiffies(delay +
(delay >> 1)));
else
schedule_timeout_interruptible(msecs_to_jiffies(delay));
}
if (handsfree->ramp == TWL6040_RAMP_DOWN) {
handsfree->active = 0;
complete(&handsfree->ramp_done);
} else
handsfree->active = 1;
handsfree->ramp = TWL6040_RAMP_NONE;
}
static int pga_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
struct twl6040_output *out;
struct delayed_work *work;
struct workqueue_struct *queue;
switch (w->shift) {
case 2:
case 3:
out = &priv->headset;
work = &priv->hs_delayed_work;
queue = priv->hs_workqueue;
out->step_delay = 5;
break;
case 4:
out = &priv->handsfree;
work = &priv->hf_delayed_work;
queue = priv->hf_workqueue;
out->step_delay = 5;
if (SND_SOC_DAPM_EVENT_ON(event))
priv->non_lp++;
else
priv->non_lp--;
break;
default:
return -1;
}
switch (event) {
case SND_SOC_DAPM_POST_PMU:
if (out->active)
break;
out->left_step = out->left_vol;
out->right_step = out->right_vol;
if (!delayed_work_pending(work)) {
out->ramp = TWL6040_RAMP_UP;
queue_delayed_work(queue, work,
msecs_to_jiffies(1));
}
break;
case SND_SOC_DAPM_PRE_PMD:
if (!out->active)
break;
if (!delayed_work_pending(work)) {
out->left_step = 1;
out->right_step = 1;
out->ramp = TWL6040_RAMP_DOWN;
INIT_COMPLETION(out->ramp_done);
queue_delayed_work(queue, work,
msecs_to_jiffies(1));
wait_for_completion_timeout(&out->ramp_done,
msecs_to_jiffies(2000));
}
break;
}
return 0;
}
static void twl6040_power_up(struct snd_soc_codec *codec)
{
u8 ncpctl, ldoctl, lppllctl, accctl;
ncpctl = twl6040_read_reg_cache(codec, TWL6040_REG_NCPCTL);
ldoctl = twl6040_read_reg_cache(codec, TWL6040_REG_LDOCTL);
lppllctl = twl6040_read_reg_cache(codec, TWL6040_REG_LPPLLCTL);
accctl = twl6040_read_reg_cache(codec, TWL6040_REG_ACCCTL);
ldoctl |= TWL6040_REFENA;
twl6040_write(codec, TWL6040_REG_LDOCTL, ldoctl);
msleep(10);
ldoctl |= TWL6040_OSCENA;
twl6040_write(codec, TWL6040_REG_LDOCTL, ldoctl);
udelay(10);
ldoctl |= TWL6040_HSLDOENA;
twl6040_write(codec, TWL6040_REG_LDOCTL, ldoctl);
udelay(244);
ncpctl |= TWL6040_NCPENA | TWL6040_NCPOPEN;
twl6040_write(codec, TWL6040_REG_NCPCTL, ncpctl);
udelay(488);
ldoctl |= TWL6040_LSLDOENA;
twl6040_write(codec, TWL6040_REG_LDOCTL, ldoctl);
udelay(244);
lppllctl |= TWL6040_LPLLENA;
twl6040_write(codec, TWL6040_REG_LPPLLCTL, lppllctl);
accctl |= TWL6040_RESETSPLIT;
twl6040_write(codec, TWL6040_REG_ACCCTL, accctl);
mdelay(5);
accctl &= ~TWL6040_RESETSPLIT;
twl6040_write(codec, TWL6040_REG_ACCCTL, accctl);
ldoctl &= ~TWL6040_OSCENA;
twl6040_write(codec, TWL6040_REG_LDOCTL, ldoctl);
}
static void twl6040_power_down(struct snd_soc_codec *codec)
{
u8 ncpctl, ldoctl, lppllctl, accctl;
ncpctl = twl6040_read_reg_cache(codec, TWL6040_REG_NCPCTL);
ldoctl = twl6040_read_reg_cache(codec, TWL6040_REG_LDOCTL);
lppllctl = twl6040_read_reg_cache(codec, TWL6040_REG_LPPLLCTL);
accctl = twl6040_read_reg_cache(codec, TWL6040_REG_ACCCTL);
ldoctl |= TWL6040_OSCENA;
twl6040_write(codec, TWL6040_REG_LDOCTL, ldoctl);
udelay(10);
lppllctl &= ~TWL6040_LPLLENA;
twl6040_write(codec, TWL6040_REG_LPPLLCTL, lppllctl);
ldoctl &= ~TWL6040_LSLDOENA;
twl6040_write(codec, TWL6040_REG_LDOCTL, ldoctl);
udelay(244);
ncpctl &= ~(TWL6040_NCPENA | TWL6040_NCPOPEN);
twl6040_write(codec, TWL6040_REG_NCPCTL, ncpctl);
udelay(488);
ldoctl &= ~TWL6040_HSLDOENA;
twl6040_write(codec, TWL6040_REG_LDOCTL, ldoctl);
udelay(244);
ldoctl &= ~TWL6040_OSCENA;
twl6040_write(codec, TWL6040_REG_LDOCTL, ldoctl);
ldoctl &= ~TWL6040_REFENA;
twl6040_write(codec, TWL6040_REG_LDOCTL, ldoctl);
msleep(10);
}
static int headset_power_mode(struct snd_soc_codec *codec, int high_perf)
{
int hslctl, hsrctl;
int mask = TWL6040_HSDRVMODEL | TWL6040_HSDACMODEL;
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
msleep(1);
return 0;
}
static int twl6040_power_mode_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
if (SND_SOC_DAPM_EVENT_ON(event))
priv->non_lp++;
else
priv->non_lp--;
msleep(1);
return 0;
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
struct twl6040_data, delayed_work.work);
struct snd_soc_codec *codec = priv->codec;
struct twl6040_jack_data *hs_jack = &priv->hs_jack;
twl6040_hs_jack_report(codec, hs_jack->jack, hs_jack->report);
}
static irqreturn_t twl6040_naudint_handler(int irq, void *data)
{
struct snd_soc_codec *codec = data;
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
u8 intid;
twl_i2c_read_u8(TWL_MODULE_AUDIO_VOICE, &intid, TWL6040_REG_INTID);
if (intid & TWL6040_THINT)
dev_alert(codec->dev, "die temp over-limit detection\n");
if ((intid & TWL6040_PLUGINT) || (intid & TWL6040_UNPLUGINT))
queue_delayed_work(priv->workqueue, &priv->delayed_work,
msecs_to_jiffies(200));
if (intid & TWL6040_HOOKINT)
dev_info(codec->dev, "hook detection\n");
if (intid & TWL6040_HFINT)
dev_alert(codec->dev, "hf drivers over current detection\n");
if (intid & TWL6040_VIBINT)
dev_alert(codec->dev, "vib drivers over current detection\n");
if (intid & TWL6040_READYINT)
complete(&priv->ready);
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
unsigned int reg = mc->reg;
switch (reg) {
case TWL6040_REG_HSGAIN:
out = &twl6040_priv->headset;
break;
default:
break;
}
if (out) {
out->left_vol = ucontrol->value.integer.value[0];
out->right_vol = ucontrol->value.integer.value[1];
if (!out->active)
return 1;
}
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
unsigned int reg = mc->reg;
switch (reg) {
case TWL6040_REG_HSGAIN:
out = &twl6040_priv->headset;
ucontrol->value.integer.value[0] = out->left_vol;
ucontrol->value.integer.value[1] = out->right_vol;
return 0;
default:
break;
}
return snd_soc_get_volsw(kcontrol, ucontrol);
}
static int twl6040_put_volsw_2r_vu(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct twl6040_data *twl6040_priv = snd_soc_codec_get_drvdata(codec);
struct twl6040_output *out = NULL;
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
int ret;
unsigned int reg = mc->reg;
switch (reg) {
case TWL6040_REG_HFLGAIN:
case TWL6040_REG_HFRGAIN:
out = &twl6040_priv->handsfree;
break;
default:
break;
}
if (out) {
out->left_vol = ucontrol->value.integer.value[0];
out->right_vol = ucontrol->value.integer.value[1];
if (!out->active)
return 1;
}
ret = snd_soc_put_volsw_2r(kcontrol, ucontrol);
if (ret < 0)
return ret;
return 1;
}
static int twl6040_get_volsw_2r(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct twl6040_data *twl6040_priv = snd_soc_codec_get_drvdata(codec);
struct twl6040_output *out = &twl6040_priv->handsfree;
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int reg = mc->reg;
switch (reg) {
case TWL6040_REG_HFLGAIN:
case TWL6040_REG_HFRGAIN:
out = &twl6040_priv->handsfree;
ucontrol->value.integer.value[0] = out->left_vol;
ucontrol->value.integer.value[1] = out->right_vol;
return 0;
default:
break;
}
return snd_soc_get_volsw_2r(kcontrol, ucontrol);
}
static int twl6040_add_widgets(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_new_controls(dapm, twl6040_dapm_widgets,
ARRAY_SIZE(twl6040_dapm_widgets));
snd_soc_dapm_add_routes(dapm, intercon, ARRAY_SIZE(intercon));
snd_soc_dapm_new_widgets(dapm);
return 0;
}
static int twl6040_power_up_completion(struct snd_soc_codec *codec,
int naudint)
{
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
int time_left;
u8 intid;
time_left = wait_for_completion_timeout(&priv->ready,
msecs_to_jiffies(144));
if (!time_left) {
twl_i2c_read_u8(TWL_MODULE_AUDIO_VOICE, &intid,
TWL6040_REG_INTID);
if (!(intid & TWL6040_READYINT)) {
dev_err(codec->dev, "timeout waiting for READYINT\n");
return -ETIMEDOUT;
}
}
priv->codec_powered = 1;
return 0;
}
static int twl6040_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
int audpwron = priv->audpwron;
int naudint = priv->naudint;
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (priv->codec_powered)
break;
if (gpio_is_valid(audpwron)) {
gpio_set_value(audpwron, 1);
ret = twl6040_power_up_completion(codec, naudint);
if (ret)
return ret;
twl6040_read_reg_volatile(codec, TWL6040_REG_NCPCTL);
twl6040_read_reg_volatile(codec, TWL6040_REG_LDOCTL);
twl6040_read_reg_volatile(codec, TWL6040_REG_LPPLLCTL);
} else {
twl6040_power_up(codec);
priv->codec_powered = 1;
}
twl6040_init_vdd_regs(codec);
twl6040_write(codec, TWL6040_REG_GPOCTL, 0x02);
twl6040_write(codec, TWL6040_REG_HSGAIN, 0xFF);
twl6040_write(codec, TWL6040_REG_EARCTL, 0x1E);
twl6040_write(codec, TWL6040_REG_HFLGAIN, 0x1D);
twl6040_write(codec, TWL6040_REG_HFRGAIN, 0x1D);
break;
case SND_SOC_BIAS_OFF:
if (!priv->codec_powered)
break;
if (gpio_is_valid(audpwron)) {
gpio_set_value(audpwron, 0);
udelay(500);
twl6040_read_reg_volatile(codec, TWL6040_REG_NCPCTL);
twl6040_read_reg_volatile(codec, TWL6040_REG_LDOCTL);
twl6040_write_reg_cache(codec, TWL6040_REG_LPPLLCTL,
0x00);
} else {
twl6040_power_down(codec);
}
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
priv->sysclk_constraints);
return 0;
}
static int twl6040_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
u8 lppllctl;
int rate;
if (priv->pll == TWL6040_HPPLL_ID)
return 0;
lppllctl = twl6040_read_reg_cache(codec, TWL6040_REG_LPPLLCTL);
rate = params_rate(params);
switch (rate) {
case 11250:
case 22500:
case 44100:
case 88200:
lppllctl |= TWL6040_LPLLFIN;
priv->sysclk = 17640000;
break;
case 8000:
case 16000:
case 32000:
case 48000:
case 96000:
lppllctl &= ~TWL6040_LPLLFIN;
priv->sysclk = 19200000;
break;
default:
dev_err(codec->dev, "unsupported rate %d\n", rate);
return -EINVAL;
}
twl6040_write(codec, TWL6040_REG_LPPLLCTL, lppllctl);
return 0;
}
static int twl6040_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
if (!priv->sysclk) {
dev_err(codec->dev,
"no mclk configured, call set_sysclk() on init\n");
return -EINVAL;
}
if ((priv->sysclk == 17640000) &&
substream->stream == SNDRV_PCM_STREAM_CAPTURE) {
dev_err(codec->dev,
"capture mode is not supported at %dHz\n",
priv->sysclk);
return -EINVAL;
}
if ((priv->sysclk == 17640000) && priv->non_lp) {
dev_err(codec->dev,
"some enabled paths aren't supported at %dHz\n",
priv->sysclk);
return -EPERM;
}
return 0;
}
static int twl6040_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
u8 hppllctl, lppllctl;
hppllctl = twl6040_read_reg_cache(codec, TWL6040_REG_HPPLLCTL);
lppllctl = twl6040_read_reg_cache(codec, TWL6040_REG_LPPLLCTL);
switch (clk_id) {
case TWL6040_SYSCLK_SEL_LPPLL:
switch (freq) {
case 32768:
headset_power_mode(codec, 0);
lppllctl |= TWL6040_LPLLENA;
twl6040_write(codec, TWL6040_REG_LPPLLCTL, lppllctl);
mdelay(5);
lppllctl &= ~TWL6040_HPLLSEL;
twl6040_write(codec, TWL6040_REG_LPPLLCTL, lppllctl);
hppllctl &= ~TWL6040_HPLLENA;
twl6040_write(codec, TWL6040_REG_HPPLLCTL, hppllctl);
break;
default:
dev_err(codec->dev, "unknown mclk freq %d\n", freq);
return -EINVAL;
}
switch (priv->sysclk) {
case 17640000:
lppllctl |= TWL6040_LPLLFIN;
break;
case 19200000:
lppllctl &= ~TWL6040_LPLLFIN;
break;
default:
lppllctl &= ~TWL6040_LPLLFIN;
priv->sysclk = 19200000;
break;
}
twl6040_write(codec, TWL6040_REG_LPPLLCTL, lppllctl);
priv->pll = TWL6040_LPPLL_ID;
priv->sysclk_constraints = &lp_constraints;
break;
case TWL6040_SYSCLK_SEL_HPPLL:
hppllctl &= ~TWL6040_MCLK_MSK;
switch (freq) {
case 12000000:
hppllctl |= TWL6040_MCLK_12000KHZ |
TWL6040_HPLLSQRBP |
TWL6040_HPLLENA;
break;
case 19200000:
hppllctl |= TWL6040_MCLK_19200KHZ |
TWL6040_HPLLSQRENA |
TWL6040_HPLLBP;
break;
case 26000000:
hppllctl |= TWL6040_MCLK_26000KHZ |
TWL6040_HPLLSQRBP |
TWL6040_HPLLENA;
break;
case 38400000:
hppllctl |= TWL6040_MCLK_38400KHZ |
TWL6040_HPLLSQRENA |
TWL6040_HPLLBP;
break;
default:
dev_err(codec->dev, "unknown mclk freq %d\n", freq);
return -EINVAL;
}
headset_power_mode(codec, 1);
twl6040_write(codec, TWL6040_REG_HPPLLCTL, hppllctl);
udelay(500);
lppllctl |= TWL6040_HPLLSEL;
twl6040_write(codec, TWL6040_REG_LPPLLCTL, lppllctl);
lppllctl &= ~TWL6040_LPLLENA;
twl6040_write(codec, TWL6040_REG_LPPLLCTL, lppllctl);
priv->pll = TWL6040_HPPLL_ID;
priv->sysclk = 19200000;
priv->sysclk_constraints = &hp_constraints;
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
struct twl4030_codec_data *twl_codec = codec->dev->platform_data;
struct twl6040_data *priv;
int audpwron, naudint;
int ret = 0;
u8 icrev, intmr = TWL6040_ALLINT_MSK;
priv = kzalloc(sizeof(struct twl6040_data), GFP_KERNEL);
if (priv == NULL)
return -ENOMEM;
snd_soc_codec_set_drvdata(codec, priv);
priv->codec = codec;
twl_i2c_read_u8(TWL_MODULE_AUDIO_VOICE, &icrev, TWL6040_REG_ASICREV);
if (twl_codec && (icrev > 0))
audpwron = twl_codec->audpwron_gpio;
else
audpwron = -EINVAL;
if (twl_codec)
naudint = twl_codec->naudint_irq;
else
naudint = 0;
priv->audpwron = audpwron;
priv->naudint = naudint;
priv->workqueue = create_singlethread_workqueue("twl6040-codec");
if (!priv->workqueue) {
ret = -ENOMEM;
goto work_err;
}
INIT_DELAYED_WORK(&priv->delayed_work, twl6040_accessory_work);
mutex_init(&priv->mutex);
init_completion(&priv->ready);
init_completion(&priv->headset.ramp_done);
init_completion(&priv->handsfree.ramp_done);
if (gpio_is_valid(audpwron)) {
ret = gpio_request(audpwron, "audpwron");
if (ret)
goto gpio1_err;
ret = gpio_direction_output(audpwron, 0);
if (ret)
goto gpio2_err;
priv->codec_powered = 0;
intmr &= ~(TWL6040_READYMSK | TWL6040_PLUGMSK);
twl6040_read_reg_volatile(codec, TWL6040_REG_INTID);
}
twl6040_write(codec, TWL6040_REG_INTMR, intmr);
if (naudint) {
ret = request_threaded_irq(naudint, NULL,
twl6040_naudint_handler,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"twl6040_codec", codec);
if (ret)
goto gpio2_err;
}
twl6040_init_vio_regs(codec);
priv->hf_workqueue = create_singlethread_workqueue("twl6040-hf");
if (priv->hf_workqueue == NULL) {
ret = -ENOMEM;
goto irq_err;
}
priv->hs_workqueue = create_singlethread_workqueue("twl6040-hs");
if (priv->hs_workqueue == NULL) {
ret = -ENOMEM;
goto wq_err;
}
INIT_DELAYED_WORK(&priv->hs_delayed_work, twl6040_pga_hs_work);
INIT_DELAYED_WORK(&priv->hf_delayed_work, twl6040_pga_hf_work);
ret = twl6040_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
if (ret)
goto bias_err;
snd_soc_add_controls(codec, twl6040_snd_controls,
ARRAY_SIZE(twl6040_snd_controls));
twl6040_add_widgets(codec);
return 0;
bias_err:
destroy_workqueue(priv->hs_workqueue);
wq_err:
destroy_workqueue(priv->hf_workqueue);
irq_err:
if (naudint)
free_irq(naudint, codec);
gpio2_err:
if (gpio_is_valid(audpwron))
gpio_free(audpwron);
gpio1_err:
destroy_workqueue(priv->workqueue);
work_err:
kfree(priv);
return ret;
}
static int twl6040_remove(struct snd_soc_codec *codec)
{
struct twl6040_data *priv = snd_soc_codec_get_drvdata(codec);
int audpwron = priv->audpwron;
int naudint = priv->naudint;
twl6040_set_bias_level(codec, SND_SOC_BIAS_OFF);
if (gpio_is_valid(audpwron))
gpio_free(audpwron);
if (naudint)
free_irq(naudint, codec);
destroy_workqueue(priv->workqueue);
destroy_workqueue(priv->hf_workqueue);
destroy_workqueue(priv->hs_workqueue);
kfree(priv);
return 0;
}
static int __devinit twl6040_codec_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_twl6040, &twl6040_dai, 1);
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
