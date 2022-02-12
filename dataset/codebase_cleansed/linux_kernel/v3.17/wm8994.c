static void wm8958_micd_set_rate(struct snd_soc_codec *codec)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
struct wm8994 *control = wm8994->wm8994;
int best, i, sysclk, val;
bool idle;
const struct wm8958_micd_rate *rates;
int num_rates;
idle = !wm8994->jack_mic;
sysclk = snd_soc_read(codec, WM8994_CLOCKING_1);
if (sysclk & WM8994_SYSCLK_SRC)
sysclk = wm8994->aifclk[1];
else
sysclk = wm8994->aifclk[0];
if (control->pdata.micd_rates) {
rates = control->pdata.micd_rates;
num_rates = control->pdata.num_micd_rates;
} else if (wm8994->jackdet) {
rates = jackdet_rates;
num_rates = ARRAY_SIZE(jackdet_rates);
} else {
rates = micdet_rates;
num_rates = ARRAY_SIZE(micdet_rates);
}
best = 0;
for (i = 0; i < num_rates; i++) {
if (rates[i].idle != idle)
continue;
if (abs(rates[i].sysclk - sysclk) <
abs(rates[best].sysclk - sysclk))
best = i;
else if (rates[best].idle != idle)
best = i;
}
val = rates[best].start << WM8958_MICD_BIAS_STARTTIME_SHIFT
| rates[best].rate << WM8958_MICD_RATE_SHIFT;
dev_dbg(codec->dev, "MICD rate %d,%d for %dHz %s\n",
rates[best].start, rates[best].rate, sysclk,
idle ? "idle" : "active");
snd_soc_update_bits(codec, WM8958_MIC_DETECT_1,
WM8958_MICD_BIAS_STARTTIME_MASK |
WM8958_MICD_RATE_MASK, val);
}
static int configure_aif_clock(struct snd_soc_codec *codec, int aif)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
int rate;
int reg1 = 0;
int offset;
if (aif)
offset = 4;
else
offset = 0;
switch (wm8994->sysclk[aif]) {
case WM8994_SYSCLK_MCLK1:
rate = wm8994->mclk[0];
break;
case WM8994_SYSCLK_MCLK2:
reg1 |= 0x8;
rate = wm8994->mclk[1];
break;
case WM8994_SYSCLK_FLL1:
reg1 |= 0x10;
rate = wm8994->fll[0].out;
break;
case WM8994_SYSCLK_FLL2:
reg1 |= 0x18;
rate = wm8994->fll[1].out;
break;
default:
return -EINVAL;
}
if (rate >= 13500000) {
rate /= 2;
reg1 |= WM8994_AIF1CLK_DIV;
dev_dbg(codec->dev, "Dividing AIF%d clock to %dHz\n",
aif + 1, rate);
}
wm8994->aifclk[aif] = rate;
snd_soc_update_bits(codec, WM8994_AIF1_CLOCKING_1 + offset,
WM8994_AIF1CLK_SRC_MASK | WM8994_AIF1CLK_DIV,
reg1);
return 0;
}
static int configure_clock(struct snd_soc_codec *codec)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
int change, new;
configure_aif_clock(codec, 0);
configure_aif_clock(codec, 1);
if (wm8994->aifclk[0] == wm8994->aifclk[1]) {
wm8958_micd_set_rate(codec);
return 0;
}
if (wm8994->aifclk[0] < wm8994->aifclk[1])
new = WM8994_SYSCLK_SRC;
else
new = 0;
change = snd_soc_update_bits(codec, WM8994_CLOCKING_1,
WM8994_SYSCLK_SRC, new);
if (change)
snd_soc_dapm_sync(&codec->dapm);
wm8958_micd_set_rate(codec);
return 0;
}
static int check_clk_sys(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
int reg = snd_soc_read(source->codec, WM8994_CLOCKING_1);
const char *clk;
if (reg & WM8994_SYSCLK_SRC)
clk = "AIF2CLK";
else
clk = "AIF1CLK";
return strcmp(source->name, clk) == 0;
}
static int wm8994_put_drc_sw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
int mask, ret;
if (mc->shift == WM8994_AIF1DAC1_DRC_ENA_SHIFT)
mask = WM8994_AIF1ADC1L_DRC_ENA_MASK |
WM8994_AIF1ADC1R_DRC_ENA_MASK;
else
mask = WM8994_AIF1DAC1_DRC_ENA_MASK;
ret = snd_soc_read(codec, mc->reg);
if (ret < 0)
return ret;
if (ret & mask)
return -EINVAL;
return snd_soc_put_volsw(kcontrol, ucontrol);
}
static void wm8994_set_drc(struct snd_soc_codec *codec, int drc)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
struct wm8994 *control = wm8994->wm8994;
struct wm8994_pdata *pdata = &control->pdata;
int base = wm8994_drc_base[drc];
int cfg = wm8994->drc_cfg[drc];
int save, i;
save = snd_soc_read(codec, base);
save &= WM8994_AIF1DAC1_DRC_ENA | WM8994_AIF1ADC1L_DRC_ENA |
WM8994_AIF1ADC1R_DRC_ENA;
for (i = 0; i < WM8994_DRC_REGS; i++)
snd_soc_update_bits(codec, base + i, 0xffff,
pdata->drc_cfgs[cfg].regs[i]);
snd_soc_update_bits(codec, base, WM8994_AIF1DAC1_DRC_ENA |
WM8994_AIF1ADC1L_DRC_ENA |
WM8994_AIF1ADC1R_DRC_ENA, save);
}
static int wm8994_get_drc(const char *name)
{
if (strcmp(name, "AIF1DRC1 Mode") == 0)
return 0;
if (strcmp(name, "AIF1DRC2 Mode") == 0)
return 1;
if (strcmp(name, "AIF2DRC Mode") == 0)
return 2;
return -EINVAL;
}
static int wm8994_put_drc_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
struct wm8994 *control = wm8994->wm8994;
struct wm8994_pdata *pdata = &control->pdata;
int drc = wm8994_get_drc(kcontrol->id.name);
int value = ucontrol->value.integer.value[0];
if (drc < 0)
return drc;
if (value >= pdata->num_drc_cfgs)
return -EINVAL;
wm8994->drc_cfg[drc] = value;
wm8994_set_drc(codec, drc);
return 0;
}
static int wm8994_get_drc_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
int drc = wm8994_get_drc(kcontrol->id.name);
if (drc < 0)
return drc;
ucontrol->value.enumerated.item[0] = wm8994->drc_cfg[drc];
return 0;
}
static void wm8994_set_retune_mobile(struct snd_soc_codec *codec, int block)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
struct wm8994 *control = wm8994->wm8994;
struct wm8994_pdata *pdata = &control->pdata;
int base = wm8994_retune_mobile_base[block];
int iface, best, best_val, save, i, cfg;
if (!pdata || !wm8994->num_retune_mobile_texts)
return;
switch (block) {
case 0:
case 1:
iface = 0;
break;
case 2:
iface = 1;
break;
default:
return;
}
cfg = wm8994->retune_mobile_cfg[block];
best = 0;
best_val = INT_MAX;
for (i = 0; i < pdata->num_retune_mobile_cfgs; i++) {
if (strcmp(pdata->retune_mobile_cfgs[i].name,
wm8994->retune_mobile_texts[cfg]) == 0 &&
abs(pdata->retune_mobile_cfgs[i].rate
- wm8994->dac_rates[iface]) < best_val) {
best = i;
best_val = abs(pdata->retune_mobile_cfgs[i].rate
- wm8994->dac_rates[iface]);
}
}
dev_dbg(codec->dev, "ReTune Mobile %d %s/%dHz for %dHz sample rate\n",
block,
pdata->retune_mobile_cfgs[best].name,
pdata->retune_mobile_cfgs[best].rate,
wm8994->dac_rates[iface]);
save = snd_soc_read(codec, base);
save &= WM8994_AIF1DAC1_EQ_ENA;
for (i = 0; i < WM8994_EQ_REGS; i++)
snd_soc_update_bits(codec, base + i, 0xffff,
pdata->retune_mobile_cfgs[best].regs[i]);
snd_soc_update_bits(codec, base, WM8994_AIF1DAC1_EQ_ENA, save);
}
static int wm8994_get_retune_mobile_block(const char *name)
{
if (strcmp(name, "AIF1.1 EQ Mode") == 0)
return 0;
if (strcmp(name, "AIF1.2 EQ Mode") == 0)
return 1;
if (strcmp(name, "AIF2 EQ Mode") == 0)
return 2;
return -EINVAL;
}
static int wm8994_put_retune_mobile_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
struct wm8994 *control = wm8994->wm8994;
struct wm8994_pdata *pdata = &control->pdata;
int block = wm8994_get_retune_mobile_block(kcontrol->id.name);
int value = ucontrol->value.integer.value[0];
if (block < 0)
return block;
if (value >= pdata->num_retune_mobile_cfgs)
return -EINVAL;
wm8994->retune_mobile_cfg[block] = value;
wm8994_set_retune_mobile(codec, block);
return 0;
}
static int wm8994_get_retune_mobile_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
int block = wm8994_get_retune_mobile_block(kcontrol->id.name);
if (block < 0)
return block;
ucontrol->value.enumerated.item[0] = wm8994->retune_mobile_cfg[block];
return 0;
}
static void wm1811_jackdet_set_mode(struct snd_soc_codec *codec, u16 mode)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
if (!wm8994->jackdet || !wm8994->micdet[0].jack)
return;
if (wm8994->active_refcount)
mode = WM1811_JACKDET_MODE_AUDIO;
if (mode == wm8994->jackdet_mode)
return;
wm8994->jackdet_mode = mode;
if (mode != WM1811_JACKDET_MODE_NONE)
mode = WM1811_JACKDET_MODE_AUDIO;
snd_soc_update_bits(codec, WM8994_ANTIPOP_2,
WM1811_JACKDET_MODE_MASK, mode);
}
static void active_reference(struct snd_soc_codec *codec)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
mutex_lock(&wm8994->accdet_lock);
wm8994->active_refcount++;
dev_dbg(codec->dev, "Active refcount incremented, now %d\n",
wm8994->active_refcount);
wm1811_jackdet_set_mode(codec, WM1811_JACKDET_MODE_AUDIO);
mutex_unlock(&wm8994->accdet_lock);
}
static void active_dereference(struct snd_soc_codec *codec)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
u16 mode;
mutex_lock(&wm8994->accdet_lock);
wm8994->active_refcount--;
dev_dbg(codec->dev, "Active refcount decremented, now %d\n",
wm8994->active_refcount);
if (wm8994->active_refcount == 0) {
if (wm8994->jack_mic || wm8994->mic_detecting)
mode = WM1811_JACKDET_MODE_MIC;
else
mode = WM1811_JACKDET_MODE_JACK;
wm1811_jackdet_set_mode(codec, mode);
}
mutex_unlock(&wm8994->accdet_lock);
}
static int clk_sys_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
return configure_clock(codec);
case SND_SOC_DAPM_POST_PMU:
if (wm8994->jackdet && !wm8994->clk_has_run) {
queue_delayed_work(system_power_efficient_wq,
&wm8994->jackdet_bootstrap,
msecs_to_jiffies(1000));
wm8994->clk_has_run = true;
}
break;
case SND_SOC_DAPM_POST_PMD:
configure_clock(codec);
break;
}
return 0;
}
static void vmid_reference(struct snd_soc_codec *codec)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
pm_runtime_get_sync(codec->dev);
wm8994->vmid_refcount++;
dev_dbg(codec->dev, "Referencing VMID, refcount is now %d\n",
wm8994->vmid_refcount);
if (wm8994->vmid_refcount == 1) {
snd_soc_update_bits(codec, WM8994_ANTIPOP_1,
WM8994_LINEOUT1_DISCH |
WM8994_LINEOUT2_DISCH, 0);
wm_hubs_vmid_ena(codec);
switch (wm8994->vmid_mode) {
default:
WARN_ON(NULL == "Invalid VMID mode");
case WM8994_VMID_NORMAL:
snd_soc_update_bits(codec, WM8994_ANTIPOP_2,
WM8994_BIAS_SRC |
WM8994_VMID_DISCH |
WM8994_STARTUP_BIAS_ENA |
WM8994_VMID_BUF_ENA |
WM8994_VMID_RAMP_MASK,
WM8994_BIAS_SRC |
WM8994_STARTUP_BIAS_ENA |
WM8994_VMID_BUF_ENA |
(0x2 << WM8994_VMID_RAMP_SHIFT));
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_1,
WM8994_BIAS_ENA |
WM8994_VMID_SEL_MASK,
WM8994_BIAS_ENA | 0x2);
msleep(300);
snd_soc_update_bits(codec, WM8994_ANTIPOP_2,
WM8994_VMID_RAMP_MASK |
WM8994_BIAS_SRC,
0);
break;
case WM8994_VMID_FORCE:
snd_soc_update_bits(codec, WM8994_ANTIPOP_2,
WM8994_BIAS_SRC |
WM8994_VMID_DISCH |
WM8994_STARTUP_BIAS_ENA |
WM8994_VMID_BUF_ENA |
WM8994_VMID_RAMP_MASK,
WM8994_BIAS_SRC |
WM8994_STARTUP_BIAS_ENA |
WM8994_VMID_BUF_ENA |
(0x2 << WM8994_VMID_RAMP_SHIFT));
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_1,
WM8994_BIAS_ENA |
WM8994_VMID_SEL_MASK,
WM8994_BIAS_ENA | 0x2);
msleep(400);
snd_soc_update_bits(codec, WM8994_ANTIPOP_2,
WM8994_VMID_RAMP_MASK |
WM8994_BIAS_SRC,
0);
break;
}
}
}
static void vmid_dereference(struct snd_soc_codec *codec)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
wm8994->vmid_refcount--;
dev_dbg(codec->dev, "Dereferencing VMID, refcount is now %d\n",
wm8994->vmid_refcount);
if (wm8994->vmid_refcount == 0) {
if (wm8994->hubs.lineout1_se)
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_3,
WM8994_LINEOUT1N_ENA |
WM8994_LINEOUT1P_ENA,
WM8994_LINEOUT1N_ENA |
WM8994_LINEOUT1P_ENA);
if (wm8994->hubs.lineout2_se)
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_3,
WM8994_LINEOUT2N_ENA |
WM8994_LINEOUT2P_ENA,
WM8994_LINEOUT2N_ENA |
WM8994_LINEOUT2P_ENA);
snd_soc_update_bits(codec, WM8994_ANTIPOP_2,
WM8994_BIAS_SRC |
WM8994_VMID_DISCH,
WM8994_BIAS_SRC |
WM8994_VMID_DISCH);
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_1,
WM8994_VMID_SEL_MASK, 0);
msleep(400);
snd_soc_update_bits(codec, WM8994_ANTIPOP_1,
WM8994_LINEOUT1_DISCH |
WM8994_LINEOUT2_DISCH,
WM8994_LINEOUT1_DISCH |
WM8994_LINEOUT2_DISCH);
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_3,
WM8994_LINEOUT1N_ENA |
WM8994_LINEOUT1P_ENA |
WM8994_LINEOUT2N_ENA |
WM8994_LINEOUT2P_ENA, 0);
snd_soc_update_bits(codec, WM8994_ANTIPOP_2,
WM8994_BIAS_SRC |
WM8994_STARTUP_BIAS_ENA |
WM8994_VMID_BUF_ENA |
WM8994_VMID_RAMP_MASK, 0);
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_1,
WM8994_VMID_SEL_MASK, 0);
}
pm_runtime_put(codec->dev);
}
static int vmid_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
vmid_reference(codec);
break;
case SND_SOC_DAPM_POST_PMD:
vmid_dereference(codec);
break;
}
return 0;
}
static bool wm8994_check_class_w_digital(struct snd_soc_codec *codec)
{
int source = 0;
int reg, reg_r;
reg = snd_soc_read(codec, WM8994_DAC1_LEFT_MIXER_ROUTING);
switch (reg) {
case WM8994_AIF2DACL_TO_DAC1L:
dev_vdbg(codec->dev, "Class W source AIF2DAC\n");
source = 2 << WM8994_CP_DYN_SRC_SEL_SHIFT;
break;
case WM8994_AIF1DAC2L_TO_DAC1L:
dev_vdbg(codec->dev, "Class W source AIF1DAC2\n");
source = 1 << WM8994_CP_DYN_SRC_SEL_SHIFT;
break;
case WM8994_AIF1DAC1L_TO_DAC1L:
dev_vdbg(codec->dev, "Class W source AIF1DAC1\n");
source = 0 << WM8994_CP_DYN_SRC_SEL_SHIFT;
break;
default:
dev_vdbg(codec->dev, "DAC mixer setting: %x\n", reg);
return false;
}
reg_r = snd_soc_read(codec, WM8994_DAC1_RIGHT_MIXER_ROUTING);
if (reg_r != reg) {
dev_vdbg(codec->dev, "Left and right DAC mixers different\n");
return false;
}
snd_soc_update_bits(codec, WM8994_CLASS_W_1,
WM8994_CP_DYN_SRC_SEL_MASK, source);
return true;
}
static int aif1clk_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
struct wm8994 *control = wm8994->wm8994;
int mask = WM8994_AIF1DAC1L_ENA | WM8994_AIF1DAC1R_ENA;
int i;
int dac;
int adc;
int val;
switch (control->type) {
case WM8994:
case WM8958:
mask |= WM8994_AIF1DAC2L_ENA | WM8994_AIF1DAC2R_ENA;
break;
default:
break;
}
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
if (wm8994->channels[0] <= 2)
mask &= ~(WM8994_AIF1DAC2L_ENA | WM8994_AIF1DAC2R_ENA);
val = snd_soc_read(codec, WM8994_AIF1_CONTROL_1);
if ((val & WM8994_AIF1ADCL_SRC) &&
(val & WM8994_AIF1ADCR_SRC))
adc = WM8994_AIF1ADC1R_ENA | WM8994_AIF1ADC2R_ENA;
else if (!(val & WM8994_AIF1ADCL_SRC) &&
!(val & WM8994_AIF1ADCR_SRC))
adc = WM8994_AIF1ADC1L_ENA | WM8994_AIF1ADC2L_ENA;
else
adc = WM8994_AIF1ADC1R_ENA | WM8994_AIF1ADC2R_ENA |
WM8994_AIF1ADC1L_ENA | WM8994_AIF1ADC2L_ENA;
val = snd_soc_read(codec, WM8994_AIF1_CONTROL_2);
if ((val & WM8994_AIF1DACL_SRC) &&
(val & WM8994_AIF1DACR_SRC))
dac = WM8994_AIF1DAC1R_ENA | WM8994_AIF1DAC2R_ENA;
else if (!(val & WM8994_AIF1DACL_SRC) &&
!(val & WM8994_AIF1DACR_SRC))
dac = WM8994_AIF1DAC1L_ENA | WM8994_AIF1DAC2L_ENA;
else
dac = WM8994_AIF1DAC1R_ENA | WM8994_AIF1DAC2R_ENA |
WM8994_AIF1DAC1L_ENA | WM8994_AIF1DAC2L_ENA;
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_4,
mask, adc);
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_5,
mask, dac);
snd_soc_update_bits(codec, WM8994_CLOCKING_1,
WM8994_AIF1DSPCLK_ENA |
WM8994_SYSDSPCLK_ENA,
WM8994_AIF1DSPCLK_ENA |
WM8994_SYSDSPCLK_ENA);
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_4, mask,
WM8994_AIF1ADC1R_ENA |
WM8994_AIF1ADC1L_ENA |
WM8994_AIF1ADC2R_ENA |
WM8994_AIF1ADC2L_ENA);
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_5, mask,
WM8994_AIF1DAC1R_ENA |
WM8994_AIF1DAC1L_ENA |
WM8994_AIF1DAC2R_ENA |
WM8994_AIF1DAC2L_ENA);
break;
case SND_SOC_DAPM_POST_PMU:
for (i = 0; i < ARRAY_SIZE(wm8994_vu_bits); i++)
snd_soc_write(codec, wm8994_vu_bits[i].reg,
snd_soc_read(codec,
wm8994_vu_bits[i].reg));
break;
case SND_SOC_DAPM_PRE_PMD:
case SND_SOC_DAPM_POST_PMD:
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_5,
mask, 0);
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_4,
mask, 0);
val = snd_soc_read(codec, WM8994_CLOCKING_1);
if (val & WM8994_AIF2DSPCLK_ENA)
val = WM8994_SYSDSPCLK_ENA;
else
val = 0;
snd_soc_update_bits(codec, WM8994_CLOCKING_1,
WM8994_SYSDSPCLK_ENA |
WM8994_AIF1DSPCLK_ENA, val);
break;
}
return 0;
}
static int aif2clk_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
int i;
int dac;
int adc;
int val;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
val = snd_soc_read(codec, WM8994_AIF2_CONTROL_1);
if ((val & WM8994_AIF2ADCL_SRC) &&
(val & WM8994_AIF2ADCR_SRC))
adc = WM8994_AIF2ADCR_ENA;
else if (!(val & WM8994_AIF2ADCL_SRC) &&
!(val & WM8994_AIF2ADCR_SRC))
adc = WM8994_AIF2ADCL_ENA;
else
adc = WM8994_AIF2ADCL_ENA | WM8994_AIF2ADCR_ENA;
val = snd_soc_read(codec, WM8994_AIF2_CONTROL_2);
if ((val & WM8994_AIF2DACL_SRC) &&
(val & WM8994_AIF2DACR_SRC))
dac = WM8994_AIF2DACR_ENA;
else if (!(val & WM8994_AIF2DACL_SRC) &&
!(val & WM8994_AIF2DACR_SRC))
dac = WM8994_AIF2DACL_ENA;
else
dac = WM8994_AIF2DACL_ENA | WM8994_AIF2DACR_ENA;
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_4,
WM8994_AIF2ADCL_ENA |
WM8994_AIF2ADCR_ENA, adc);
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_5,
WM8994_AIF2DACL_ENA |
WM8994_AIF2DACR_ENA, dac);
snd_soc_update_bits(codec, WM8994_CLOCKING_1,
WM8994_AIF2DSPCLK_ENA |
WM8994_SYSDSPCLK_ENA,
WM8994_AIF2DSPCLK_ENA |
WM8994_SYSDSPCLK_ENA);
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_4,
WM8994_AIF2ADCL_ENA |
WM8994_AIF2ADCR_ENA,
WM8994_AIF2ADCL_ENA |
WM8994_AIF2ADCR_ENA);
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_5,
WM8994_AIF2DACL_ENA |
WM8994_AIF2DACR_ENA,
WM8994_AIF2DACL_ENA |
WM8994_AIF2DACR_ENA);
break;
case SND_SOC_DAPM_POST_PMU:
for (i = 0; i < ARRAY_SIZE(wm8994_vu_bits); i++)
snd_soc_write(codec, wm8994_vu_bits[i].reg,
snd_soc_read(codec,
wm8994_vu_bits[i].reg));
break;
case SND_SOC_DAPM_PRE_PMD:
case SND_SOC_DAPM_POST_PMD:
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_5,
WM8994_AIF2DACL_ENA |
WM8994_AIF2DACR_ENA, 0);
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_4,
WM8994_AIF2ADCL_ENA |
WM8994_AIF2ADCR_ENA, 0);
val = snd_soc_read(codec, WM8994_CLOCKING_1);
if (val & WM8994_AIF1DSPCLK_ENA)
val = WM8994_SYSDSPCLK_ENA;
else
val = 0;
snd_soc_update_bits(codec, WM8994_CLOCKING_1,
WM8994_SYSDSPCLK_ENA |
WM8994_AIF2DSPCLK_ENA, val);
break;
}
return 0;
}
static int aif1clk_late_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
wm8994->aif1clk_enable = 1;
break;
case SND_SOC_DAPM_POST_PMD:
wm8994->aif1clk_disable = 1;
break;
}
return 0;
}
static int aif2clk_late_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
wm8994->aif2clk_enable = 1;
break;
case SND_SOC_DAPM_POST_PMD:
wm8994->aif2clk_disable = 1;
break;
}
return 0;
}
static int late_enable_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
if (wm8994->aif1clk_enable) {
aif1clk_ev(w, kcontrol, SND_SOC_DAPM_PRE_PMU);
snd_soc_update_bits(codec, WM8994_AIF1_CLOCKING_1,
WM8994_AIF1CLK_ENA_MASK,
WM8994_AIF1CLK_ENA);
aif1clk_ev(w, kcontrol, SND_SOC_DAPM_POST_PMU);
wm8994->aif1clk_enable = 0;
}
if (wm8994->aif2clk_enable) {
aif2clk_ev(w, kcontrol, SND_SOC_DAPM_PRE_PMU);
snd_soc_update_bits(codec, WM8994_AIF2_CLOCKING_1,
WM8994_AIF2CLK_ENA_MASK,
WM8994_AIF2CLK_ENA);
aif2clk_ev(w, kcontrol, SND_SOC_DAPM_POST_PMU);
wm8994->aif2clk_enable = 0;
}
break;
}
wm8958_aif_ev(w, kcontrol, event);
return 0;
}
static int late_disable_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMD:
if (wm8994->aif1clk_disable) {
aif1clk_ev(w, kcontrol, SND_SOC_DAPM_PRE_PMD);
snd_soc_update_bits(codec, WM8994_AIF1_CLOCKING_1,
WM8994_AIF1CLK_ENA_MASK, 0);
aif1clk_ev(w, kcontrol, SND_SOC_DAPM_POST_PMD);
wm8994->aif1clk_disable = 0;
}
if (wm8994->aif2clk_disable) {
aif2clk_ev(w, kcontrol, SND_SOC_DAPM_PRE_PMD);
snd_soc_update_bits(codec, WM8994_AIF2_CLOCKING_1,
WM8994_AIF2CLK_ENA_MASK, 0);
aif2clk_ev(w, kcontrol, SND_SOC_DAPM_POST_PMD);
wm8994->aif2clk_disable = 0;
}
break;
}
return 0;
}
static int adc_mux_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
late_enable_ev(w, kcontrol, event);
return 0;
}
static int micbias_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
late_enable_ev(w, kcontrol, event);
return 0;
}
static int dac_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
unsigned int mask = 1 << w->shift;
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_5,
mask, mask);
return 0;
}
static int post_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
dev_dbg(codec->dev, "SRC status: %x\n",
snd_soc_read(codec,
WM8994_RATE_STATUS));
return 0;
}
static int wm8994_put_class_w(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_dapm_kcontrol_codec(kcontrol);
int ret;
ret = snd_soc_dapm_put_volsw(kcontrol, ucontrol);
wm_hubs_update_class_w(codec);
return ret;
}
static int wm8994_get_fll_config(struct wm8994 *control, struct fll_div *fll,
int freq_in, int freq_out)
{
u64 Kpart;
unsigned int K, Ndiv, Nmod, gcd_fll;
pr_debug("FLL input=%dHz, output=%dHz\n", freq_in, freq_out);
fll->clk_ref_div = 0;
while (freq_in > 13500000) {
fll->clk_ref_div++;
freq_in /= 2;
if (fll->clk_ref_div > 3)
return -EINVAL;
}
pr_debug("CLK_REF_DIV=%d, Fref=%dHz\n", fll->clk_ref_div, freq_in);
fll->outdiv = 3;
while (freq_out * (fll->outdiv + 1) < 90000000) {
fll->outdiv++;
if (fll->outdiv > 63)
return -EINVAL;
}
freq_out *= fll->outdiv + 1;
pr_debug("OUTDIV=%d, Fvco=%dHz\n", fll->outdiv, freq_out);
if (freq_in > 1000000) {
fll->fll_fratio = 0;
} else if (freq_in > 256000) {
fll->fll_fratio = 1;
freq_in *= 2;
} else if (freq_in > 128000) {
fll->fll_fratio = 2;
freq_in *= 4;
} else if (freq_in > 64000) {
fll->fll_fratio = 3;
freq_in *= 8;
} else {
fll->fll_fratio = 4;
freq_in *= 16;
}
pr_debug("FLL_FRATIO=%d, Fref=%dHz\n", fll->fll_fratio, freq_in);
Ndiv = freq_out / freq_in;
fll->n = Ndiv;
Nmod = freq_out % freq_in;
pr_debug("Nmod=%d\n", Nmod);
switch (control->type) {
case WM8994:
Kpart = FIXED_FLL_SIZE * (long long)Nmod;
do_div(Kpart, freq_in);
K = Kpart & 0xFFFFFFFF;
if ((K % 10) >= 5)
K += 5;
fll->k = K / 10;
fll->lambda = 0;
pr_debug("N=%x K=%x\n", fll->n, fll->k);
break;
default:
gcd_fll = gcd(freq_out, freq_in);
fll->k = (freq_out - (freq_in * fll->n)) / gcd_fll;
fll->lambda = freq_in / gcd_fll;
}
return 0;
}
static int _wm8994_set_fll(struct snd_soc_codec *codec, int id, int src,
unsigned int freq_in, unsigned int freq_out)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
struct wm8994 *control = wm8994->wm8994;
int reg_offset, ret;
struct fll_div fll;
u16 reg, clk1, aif_reg, aif_src;
unsigned long timeout;
bool was_enabled;
switch (id) {
case WM8994_FLL1:
reg_offset = 0;
id = 0;
aif_src = 0x10;
break;
case WM8994_FLL2:
reg_offset = 0x20;
id = 1;
aif_src = 0x18;
break;
default:
return -EINVAL;
}
reg = snd_soc_read(codec, WM8994_FLL1_CONTROL_1 + reg_offset);
was_enabled = reg & WM8994_FLL1_ENA;
switch (src) {
case 0:
if (freq_out)
return -EINVAL;
src = wm8994->fll[id].src;
break;
case WM8994_FLL_SRC_MCLK1:
case WM8994_FLL_SRC_MCLK2:
case WM8994_FLL_SRC_LRCLK:
case WM8994_FLL_SRC_BCLK:
break;
case WM8994_FLL_SRC_INTERNAL:
freq_in = 12000000;
freq_out = 12000000;
break;
default:
return -EINVAL;
}
if (wm8994->fll[id].src == src &&
wm8994->fll[id].in == freq_in && wm8994->fll[id].out == freq_out)
return 0;
if (freq_out)
ret = wm8994_get_fll_config(control, &fll, freq_in, freq_out);
else
ret = wm8994_get_fll_config(control, &fll, wm8994->fll[id].in,
wm8994->fll[id].out);
if (ret < 0)
return ret;
clk1 = snd_soc_read(codec, WM8994_CLOCKING_1);
if (clk1 & WM8994_SYSCLK_SRC)
aif_reg = WM8994_AIF2_CLOCKING_1;
else
aif_reg = WM8994_AIF1_CLOCKING_1;
reg = snd_soc_read(codec, aif_reg);
if ((reg & WM8994_AIF1CLK_ENA) &&
(reg & WM8994_AIF1CLK_SRC_MASK) == aif_src) {
dev_err(codec->dev, "FLL%d is currently providing SYSCLK\n",
id + 1);
return -EBUSY;
}
snd_soc_update_bits(codec, WM8994_FLL1_CONTROL_1 + reg_offset,
WM8994_FLL1_ENA, 0);
if (wm8994->fll_byp && src == WM8994_FLL_SRC_BCLK &&
freq_in == freq_out && freq_out) {
dev_dbg(codec->dev, "Bypassing FLL%d\n", id + 1);
snd_soc_update_bits(codec, WM8994_FLL1_CONTROL_5 + reg_offset,
WM8958_FLL1_BYP, WM8958_FLL1_BYP);
goto out;
}
reg = (fll.outdiv << WM8994_FLL1_OUTDIV_SHIFT) |
(fll.fll_fratio << WM8994_FLL1_FRATIO_SHIFT);
snd_soc_update_bits(codec, WM8994_FLL1_CONTROL_2 + reg_offset,
WM8994_FLL1_OUTDIV_MASK |
WM8994_FLL1_FRATIO_MASK, reg);
snd_soc_update_bits(codec, WM8994_FLL1_CONTROL_3 + reg_offset,
WM8994_FLL1_K_MASK, fll.k);
snd_soc_update_bits(codec, WM8994_FLL1_CONTROL_4 + reg_offset,
WM8994_FLL1_N_MASK,
fll.n << WM8994_FLL1_N_SHIFT);
if (fll.lambda) {
snd_soc_update_bits(codec, WM8958_FLL1_EFS_1 + reg_offset,
WM8958_FLL1_LAMBDA_MASK,
fll.lambda);
snd_soc_update_bits(codec, WM8958_FLL1_EFS_2 + reg_offset,
WM8958_FLL1_EFS_ENA, WM8958_FLL1_EFS_ENA);
} else {
snd_soc_update_bits(codec, WM8958_FLL1_EFS_2 + reg_offset,
WM8958_FLL1_EFS_ENA, 0);
}
snd_soc_update_bits(codec, WM8994_FLL1_CONTROL_5 + reg_offset,
WM8994_FLL1_FRC_NCO | WM8958_FLL1_BYP |
WM8994_FLL1_REFCLK_DIV_MASK |
WM8994_FLL1_REFCLK_SRC_MASK,
((src == WM8994_FLL_SRC_INTERNAL)
<< WM8994_FLL1_FRC_NCO_SHIFT) |
(fll.clk_ref_div << WM8994_FLL1_REFCLK_DIV_SHIFT) |
(src - 1));
try_wait_for_completion(&wm8994->fll_locked[id]);
if (freq_out) {
if (!was_enabled) {
active_reference(codec);
switch (control->type) {
case WM8994:
vmid_reference(codec);
break;
case WM8958:
if (control->revision < 1)
vmid_reference(codec);
break;
default:
break;
}
}
reg = WM8994_FLL1_ENA;
if (fll.k)
reg |= WM8994_FLL1_FRAC;
if (src == WM8994_FLL_SRC_INTERNAL)
reg |= WM8994_FLL1_OSC_ENA;
snd_soc_update_bits(codec, WM8994_FLL1_CONTROL_1 + reg_offset,
WM8994_FLL1_ENA | WM8994_FLL1_OSC_ENA |
WM8994_FLL1_FRAC, reg);
if (wm8994->fll_locked_irq) {
timeout = wait_for_completion_timeout(&wm8994->fll_locked[id],
msecs_to_jiffies(10));
if (timeout == 0)
dev_warn(codec->dev,
"Timed out waiting for FLL lock\n");
} else {
msleep(5);
}
} else {
if (was_enabled) {
switch (control->type) {
case WM8994:
vmid_dereference(codec);
break;
case WM8958:
if (control->revision < 1)
vmid_dereference(codec);
break;
default:
break;
}
active_dereference(codec);
}
}
out:
wm8994->fll[id].in = freq_in;
wm8994->fll[id].out = freq_out;
wm8994->fll[id].src = src;
configure_clock(codec);
if (max(wm8994->aifclk[0], wm8994->aifclk[1]) < 50000) {
dev_dbg(codec->dev, "Configuring AIFs for 128fs\n");
wm8994->aifdiv[0] = snd_soc_read(codec, WM8994_AIF1_RATE)
& WM8994_AIF1CLK_RATE_MASK;
wm8994->aifdiv[1] = snd_soc_read(codec, WM8994_AIF2_RATE)
& WM8994_AIF1CLK_RATE_MASK;
snd_soc_update_bits(codec, WM8994_AIF1_RATE,
WM8994_AIF1CLK_RATE_MASK, 0x1);
snd_soc_update_bits(codec, WM8994_AIF2_RATE,
WM8994_AIF2CLK_RATE_MASK, 0x1);
} else if (wm8994->aifdiv[0]) {
snd_soc_update_bits(codec, WM8994_AIF1_RATE,
WM8994_AIF1CLK_RATE_MASK,
wm8994->aifdiv[0]);
snd_soc_update_bits(codec, WM8994_AIF2_RATE,
WM8994_AIF2CLK_RATE_MASK,
wm8994->aifdiv[1]);
wm8994->aifdiv[0] = 0;
wm8994->aifdiv[1] = 0;
}
return 0;
}
static irqreturn_t wm8994_fll_locked_irq(int irq, void *data)
{
struct completion *completion = data;
complete(completion);
return IRQ_HANDLED;
}
static int wm8994_set_fll(struct snd_soc_dai *dai, int id, int src,
unsigned int freq_in, unsigned int freq_out)
{
return _wm8994_set_fll(dai->codec, id, src, freq_in, freq_out);
}
static int wm8994_set_dai_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
int i;
switch (dai->id) {
case 1:
case 2:
break;
default:
return -EINVAL;
}
switch (clk_id) {
case WM8994_SYSCLK_MCLK1:
wm8994->sysclk[dai->id - 1] = WM8994_SYSCLK_MCLK1;
wm8994->mclk[0] = freq;
dev_dbg(dai->dev, "AIF%d using MCLK1 at %uHz\n",
dai->id, freq);
break;
case WM8994_SYSCLK_MCLK2:
wm8994->sysclk[dai->id - 1] = WM8994_SYSCLK_MCLK2;
wm8994->mclk[1] = freq;
dev_dbg(dai->dev, "AIF%d using MCLK2 at %uHz\n",
dai->id, freq);
break;
case WM8994_SYSCLK_FLL1:
wm8994->sysclk[dai->id - 1] = WM8994_SYSCLK_FLL1;
dev_dbg(dai->dev, "AIF%d using FLL1\n", dai->id);
break;
case WM8994_SYSCLK_FLL2:
wm8994->sysclk[dai->id - 1] = WM8994_SYSCLK_FLL2;
dev_dbg(dai->dev, "AIF%d using FLL2\n", dai->id);
break;
case WM8994_SYSCLK_OPCLK:
if (freq) {
for (i = 0; i < ARRAY_SIZE(opclk_divs); i++)
if (opclk_divs[i] == freq)
break;
if (i == ARRAY_SIZE(opclk_divs))
return -EINVAL;
snd_soc_update_bits(codec, WM8994_CLOCKING_2,
WM8994_OPCLK_DIV_MASK, i);
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_2,
WM8994_OPCLK_ENA, WM8994_OPCLK_ENA);
} else {
snd_soc_update_bits(codec, WM8994_POWER_MANAGEMENT_2,
WM8994_OPCLK_ENA, 0);
}
default:
return -EINVAL;
}
configure_clock(codec);
if (max(wm8994->aifclk[0], wm8994->aifclk[1]) < 50000) {
dev_dbg(codec->dev, "Configuring AIFs for 128fs\n");
wm8994->aifdiv[0] = snd_soc_read(codec, WM8994_AIF1_RATE)
& WM8994_AIF1CLK_RATE_MASK;
wm8994->aifdiv[1] = snd_soc_read(codec, WM8994_AIF2_RATE)
& WM8994_AIF1CLK_RATE_MASK;
snd_soc_update_bits(codec, WM8994_AIF1_RATE,
WM8994_AIF1CLK_RATE_MASK, 0x1);
snd_soc_update_bits(codec, WM8994_AIF2_RATE,
WM8994_AIF2CLK_RATE_MASK, 0x1);
} else if (wm8994->aifdiv[0]) {
snd_soc_update_bits(codec, WM8994_AIF1_RATE,
WM8994_AIF1CLK_RATE_MASK,
wm8994->aifdiv[0]);
snd_soc_update_bits(codec, WM8994_AIF2_RATE,
WM8994_AIF2CLK_RATE_MASK,
wm8994->aifdiv[1]);
wm8994->aifdiv[0] = 0;
wm8994->aifdiv[1] = 0;
}
return 0;
}
static int wm8994_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
struct wm8994 *control = wm8994->wm8994;
wm_hubs_set_bias_level(codec, level);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
switch (control->type) {
case WM8958:
case WM1811:
snd_soc_update_bits(codec, WM8958_MICBIAS1,
WM8958_MICB1_MODE, 0);
snd_soc_update_bits(codec, WM8958_MICBIAS2,
WM8958_MICB2_MODE, 0);
break;
default:
break;
}
if (codec->dapm.bias_level == SND_SOC_BIAS_STANDBY)
active_reference(codec);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
switch (control->type) {
case WM8958:
if (control->revision == 0) {
snd_soc_update_bits(codec,
WM8958_CHARGE_PUMP_2,
WM8958_CP_DISCH,
WM8958_CP_DISCH);
}
break;
default:
break;
}
snd_soc_update_bits(codec, WM8994_ANTIPOP_1,
WM8994_LINEOUT1_DISCH |
WM8994_LINEOUT2_DISCH,
WM8994_LINEOUT1_DISCH |
WM8994_LINEOUT2_DISCH);
}
if (codec->dapm.bias_level == SND_SOC_BIAS_PREPARE)
active_dereference(codec);
switch (control->type) {
case WM8958:
case WM1811:
snd_soc_update_bits(codec, WM8958_MICBIAS1,
WM8958_MICB1_MODE,
WM8958_MICB1_MODE);
snd_soc_update_bits(codec, WM8958_MICBIAS2,
WM8958_MICB2_MODE,
WM8958_MICB2_MODE);
break;
default:
break;
}
break;
case SND_SOC_BIAS_OFF:
if (codec->dapm.bias_level == SND_SOC_BIAS_STANDBY)
wm8994->cur_fw = NULL;
break;
}
codec->dapm.bias_level = level;
return 0;
}
int wm8994_vmid_mode(struct snd_soc_codec *codec, enum wm8994_vmid_mode mode)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = &codec->dapm;
switch (mode) {
case WM8994_VMID_NORMAL:
snd_soc_dapm_mutex_lock(dapm);
if (wm8994->hubs.lineout1_se) {
snd_soc_dapm_disable_pin_unlocked(dapm,
"LINEOUT1N Driver");
snd_soc_dapm_disable_pin_unlocked(dapm,
"LINEOUT1P Driver");
}
if (wm8994->hubs.lineout2_se) {
snd_soc_dapm_disable_pin_unlocked(dapm,
"LINEOUT2N Driver");
snd_soc_dapm_disable_pin_unlocked(dapm,
"LINEOUT2P Driver");
}
snd_soc_dapm_sync_unlocked(dapm);
wm8994->vmid_mode = mode;
snd_soc_dapm_mutex_unlock(dapm);
break;
case WM8994_VMID_FORCE:
snd_soc_dapm_mutex_lock(dapm);
if (wm8994->hubs.lineout1_se) {
snd_soc_dapm_force_enable_pin_unlocked(dapm,
"LINEOUT1N Driver");
snd_soc_dapm_force_enable_pin_unlocked(dapm,
"LINEOUT1P Driver");
}
if (wm8994->hubs.lineout2_se) {
snd_soc_dapm_force_enable_pin_unlocked(dapm,
"LINEOUT2N Driver");
snd_soc_dapm_force_enable_pin_unlocked(dapm,
"LINEOUT2P Driver");
}
wm8994->vmid_mode = mode;
snd_soc_dapm_sync_unlocked(dapm);
snd_soc_dapm_mutex_unlock(dapm);
break;
default:
return -EINVAL;
}
return 0;
}
static int wm8994_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
struct wm8994 *control = wm8994->wm8994;
int ms_reg;
int aif1_reg;
int dac_reg;
int adc_reg;
int ms = 0;
int aif1 = 0;
int lrclk = 0;
switch (dai->id) {
case 1:
ms_reg = WM8994_AIF1_MASTER_SLAVE;
aif1_reg = WM8994_AIF1_CONTROL_1;
dac_reg = WM8994_AIF1DAC_LRCLK;
adc_reg = WM8994_AIF1ADC_LRCLK;
break;
case 2:
ms_reg = WM8994_AIF2_MASTER_SLAVE;
aif1_reg = WM8994_AIF2_CONTROL_1;
dac_reg = WM8994_AIF1DAC_LRCLK;
adc_reg = WM8994_AIF1ADC_LRCLK;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
case SND_SOC_DAIFMT_CBM_CFM:
ms = WM8994_AIF1_MSTR;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_B:
aif1 |= WM8994_AIF1_LRCLK_INV;
lrclk |= WM8958_AIF1_LRCLK_INV;
case SND_SOC_DAIFMT_DSP_A:
aif1 |= 0x18;
break;
case SND_SOC_DAIFMT_I2S:
aif1 |= 0x10;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
aif1 |= 0x8;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
case SND_SOC_DAIFMT_DSP_B:
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
aif1 |= WM8994_AIF1_BCLK_INV;
break;
default:
return -EINVAL;
}
break;
case SND_SOC_DAIFMT_I2S:
case SND_SOC_DAIFMT_RIGHT_J:
case SND_SOC_DAIFMT_LEFT_J:
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
aif1 |= WM8994_AIF1_BCLK_INV | WM8994_AIF1_LRCLK_INV;
lrclk |= WM8958_AIF1_LRCLK_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
aif1 |= WM8994_AIF1_BCLK_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
aif1 |= WM8994_AIF1_LRCLK_INV;
lrclk |= WM8958_AIF1_LRCLK_INV;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
switch (control->type) {
case WM1811:
case WM8958:
if (dai->id == 2)
snd_soc_update_bits(codec, WM8958_AIF3_CONTROL_1,
WM8994_AIF1_LRCLK_INV |
WM8958_AIF3_FMT_MASK, aif1);
break;
default:
break;
}
snd_soc_update_bits(codec, aif1_reg,
WM8994_AIF1_BCLK_INV | WM8994_AIF1_LRCLK_INV |
WM8994_AIF1_FMT_MASK,
aif1);
snd_soc_update_bits(codec, ms_reg, WM8994_AIF1_MSTR,
ms);
snd_soc_update_bits(codec, dac_reg,
WM8958_AIF1_LRCLK_INV, lrclk);
snd_soc_update_bits(codec, adc_reg,
WM8958_AIF1_LRCLK_INV, lrclk);
return 0;
}
static int wm8994_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
struct wm8994 *control = wm8994->wm8994;
struct wm8994_pdata *pdata = &control->pdata;
int aif1_reg;
int aif2_reg;
int bclk_reg;
int lrclk_reg;
int rate_reg;
int aif1 = 0;
int aif2 = 0;
int bclk = 0;
int lrclk = 0;
int rate_val = 0;
int id = dai->id - 1;
int i, cur_val, best_val, bclk_rate, best;
switch (dai->id) {
case 1:
aif1_reg = WM8994_AIF1_CONTROL_1;
aif2_reg = WM8994_AIF1_CONTROL_2;
bclk_reg = WM8994_AIF1_BCLK;
rate_reg = WM8994_AIF1_RATE;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK ||
wm8994->lrclk_shared[0]) {
lrclk_reg = WM8994_AIF1DAC_LRCLK;
} else {
lrclk_reg = WM8994_AIF1ADC_LRCLK;
dev_dbg(codec->dev, "AIF1 using split LRCLK\n");
}
break;
case 2:
aif1_reg = WM8994_AIF2_CONTROL_1;
aif2_reg = WM8994_AIF2_CONTROL_2;
bclk_reg = WM8994_AIF2_BCLK;
rate_reg = WM8994_AIF2_RATE;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK ||
wm8994->lrclk_shared[1]) {
lrclk_reg = WM8994_AIF2DAC_LRCLK;
} else {
lrclk_reg = WM8994_AIF2ADC_LRCLK;
dev_dbg(codec->dev, "AIF2 using split LRCLK\n");
}
break;
default:
return -EINVAL;
}
bclk_rate = params_rate(params);
switch (params_width(params)) {
case 16:
bclk_rate *= 16;
break;
case 20:
bclk_rate *= 20;
aif1 |= 0x20;
break;
case 24:
bclk_rate *= 24;
aif1 |= 0x40;
break;
case 32:
bclk_rate *= 32;
aif1 |= 0x60;
break;
default:
return -EINVAL;
}
wm8994->channels[id] = params_channels(params);
if (pdata->max_channels_clocked[id] &&
wm8994->channels[id] > pdata->max_channels_clocked[id]) {
dev_dbg(dai->dev, "Constraining channels to %d from %d\n",
pdata->max_channels_clocked[id], wm8994->channels[id]);
wm8994->channels[id] = pdata->max_channels_clocked[id];
}
switch (wm8994->channels[id]) {
case 1:
case 2:
bclk_rate *= 2;
break;
default:
bclk_rate *= 4;
break;
}
for (i = 0; i < ARRAY_SIZE(srs); i++)
if (srs[i].rate == params_rate(params))
break;
if (i == ARRAY_SIZE(srs))
return -EINVAL;
rate_val |= srs[i].val << WM8994_AIF1_SR_SHIFT;
dev_dbg(dai->dev, "Sample rate is %dHz\n", srs[i].rate);
dev_dbg(dai->dev, "AIF%dCLK is %dHz, target BCLK %dHz\n",
dai->id, wm8994->aifclk[id], bclk_rate);
if (wm8994->channels[id] == 1 &&
(snd_soc_read(codec, aif1_reg) & 0x18) == 0x18)
aif2 |= WM8994_AIF1_MONO;
if (wm8994->aifclk[id] == 0) {
dev_err(dai->dev, "AIF%dCLK not configured\n", dai->id);
return -EINVAL;
}
best = 0;
best_val = abs((fs_ratios[0] * params_rate(params))
- wm8994->aifclk[id]);
for (i = 1; i < ARRAY_SIZE(fs_ratios); i++) {
cur_val = abs((fs_ratios[i] * params_rate(params))
- wm8994->aifclk[id]);
if (cur_val >= best_val)
continue;
best = i;
best_val = cur_val;
}
dev_dbg(dai->dev, "Selected AIF%dCLK/fs = %d\n",
dai->id, fs_ratios[best]);
rate_val |= best;
best = 0;
for (i = 0; i < ARRAY_SIZE(bclk_divs); i++) {
cur_val = (wm8994->aifclk[id] * 10 / bclk_divs[i]) - bclk_rate;
if (cur_val < 0)
break;
best = i;
}
bclk_rate = wm8994->aifclk[id] * 10 / bclk_divs[best];
dev_dbg(dai->dev, "Using BCLK_DIV %d for actual BCLK %dHz\n",
bclk_divs[best], bclk_rate);
bclk |= best << WM8994_AIF1_BCLK_DIV_SHIFT;
lrclk = bclk_rate / params_rate(params);
if (!lrclk) {
dev_err(dai->dev, "Unable to generate LRCLK from %dHz BCLK\n",
bclk_rate);
return -EINVAL;
}
dev_dbg(dai->dev, "Using LRCLK rate %d for actual LRCLK %dHz\n",
lrclk, bclk_rate / lrclk);
snd_soc_update_bits(codec, aif1_reg, WM8994_AIF1_WL_MASK, aif1);
snd_soc_update_bits(codec, aif2_reg, WM8994_AIF1_MONO, aif2);
snd_soc_update_bits(codec, bclk_reg, WM8994_AIF1_BCLK_DIV_MASK, bclk);
snd_soc_update_bits(codec, lrclk_reg, WM8994_AIF1DAC_RATE_MASK,
lrclk);
snd_soc_update_bits(codec, rate_reg, WM8994_AIF1_SR_MASK |
WM8994_AIF1CLK_RATE_MASK, rate_val);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
switch (dai->id) {
case 1:
wm8994->dac_rates[0] = params_rate(params);
wm8994_set_retune_mobile(codec, 0);
wm8994_set_retune_mobile(codec, 1);
break;
case 2:
wm8994->dac_rates[1] = params_rate(params);
wm8994_set_retune_mobile(codec, 2);
break;
}
}
return 0;
}
static int wm8994_aif3_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
struct wm8994 *control = wm8994->wm8994;
int aif1_reg;
int aif1 = 0;
switch (dai->id) {
case 3:
switch (control->type) {
case WM1811:
case WM8958:
aif1_reg = WM8958_AIF3_CONTROL_1;
break;
default:
return 0;
}
break;
default:
return 0;
}
switch (params_width(params)) {
case 16:
break;
case 20:
aif1 |= 0x20;
break;
case 24:
aif1 |= 0x40;
break;
case 32:
aif1 |= 0x60;
break;
default:
return -EINVAL;
}
return snd_soc_update_bits(codec, aif1_reg, WM8994_AIF1_WL_MASK, aif1);
}
static int wm8994_aif_mute(struct snd_soc_dai *codec_dai, int mute)
{
struct snd_soc_codec *codec = codec_dai->codec;
int mute_reg;
int reg;
switch (codec_dai->id) {
case 1:
mute_reg = WM8994_AIF1_DAC1_FILTERS_1;
break;
case 2:
mute_reg = WM8994_AIF2_DAC_FILTERS_1;
break;
default:
return -EINVAL;
}
if (mute)
reg = WM8994_AIF1DAC1_MUTE;
else
reg = 0;
snd_soc_update_bits(codec, mute_reg, WM8994_AIF1DAC1_MUTE, reg);
return 0;
}
static int wm8994_set_tristate(struct snd_soc_dai *codec_dai, int tristate)
{
struct snd_soc_codec *codec = codec_dai->codec;
int reg, val, mask;
switch (codec_dai->id) {
case 1:
reg = WM8994_AIF1_MASTER_SLAVE;
mask = WM8994_AIF1_TRI;
break;
case 2:
reg = WM8994_AIF2_MASTER_SLAVE;
mask = WM8994_AIF2_TRI;
break;
default:
return -EINVAL;
}
if (tristate)
val = mask;
else
val = 0;
return snd_soc_update_bits(codec, reg, mask, val);
}
static int wm8994_aif2_probe(struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
snd_soc_update_bits(codec, WM8994_GPIO_3,
WM8994_GPN_PU | WM8994_GPN_PD, 0);
snd_soc_update_bits(codec, WM8994_GPIO_4,
WM8994_GPN_PU | WM8994_GPN_PD, 0);
snd_soc_update_bits(codec, WM8994_GPIO_5,
WM8994_GPN_PU | WM8994_GPN_PD, 0);
return 0;
}
static int wm8994_codec_suspend(struct snd_soc_codec *codec)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
int i, ret;
for (i = 0; i < ARRAY_SIZE(wm8994->fll); i++) {
memcpy(&wm8994->fll_suspend[i], &wm8994->fll[i],
sizeof(struct wm8994_fll_config));
ret = _wm8994_set_fll(codec, i + 1, 0, 0, 0);
if (ret < 0)
dev_warn(codec->dev, "Failed to stop FLL%d: %d\n",
i + 1, ret);
}
wm8994_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8994_codec_resume(struct snd_soc_codec *codec)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
int i, ret;
for (i = 0; i < ARRAY_SIZE(wm8994->fll); i++) {
if (!wm8994->fll_suspend[i].out)
continue;
ret = _wm8994_set_fll(codec, i + 1,
wm8994->fll_suspend[i].src,
wm8994->fll_suspend[i].in,
wm8994->fll_suspend[i].out);
if (ret < 0)
dev_warn(codec->dev, "Failed to restore FLL%d: %d\n",
i + 1, ret);
}
return 0;
}
static void wm8994_handle_retune_mobile_pdata(struct wm8994_priv *wm8994)
{
struct snd_soc_codec *codec = wm8994->hubs.codec;
struct wm8994 *control = wm8994->wm8994;
struct wm8994_pdata *pdata = &control->pdata;
struct snd_kcontrol_new controls[] = {
SOC_ENUM_EXT("AIF1.1 EQ Mode",
wm8994->retune_mobile_enum,
wm8994_get_retune_mobile_enum,
wm8994_put_retune_mobile_enum),
SOC_ENUM_EXT("AIF1.2 EQ Mode",
wm8994->retune_mobile_enum,
wm8994_get_retune_mobile_enum,
wm8994_put_retune_mobile_enum),
SOC_ENUM_EXT("AIF2 EQ Mode",
wm8994->retune_mobile_enum,
wm8994_get_retune_mobile_enum,
wm8994_put_retune_mobile_enum),
};
int ret, i, j;
const char **t;
wm8994->num_retune_mobile_texts = 0;
wm8994->retune_mobile_texts = NULL;
for (i = 0; i < pdata->num_retune_mobile_cfgs; i++) {
for (j = 0; j < wm8994->num_retune_mobile_texts; j++) {
if (strcmp(pdata->retune_mobile_cfgs[i].name,
wm8994->retune_mobile_texts[j]) == 0)
break;
}
if (j != wm8994->num_retune_mobile_texts)
continue;
t = krealloc(wm8994->retune_mobile_texts,
sizeof(char *) *
(wm8994->num_retune_mobile_texts + 1),
GFP_KERNEL);
if (t == NULL)
continue;
t[wm8994->num_retune_mobile_texts] =
pdata->retune_mobile_cfgs[i].name;
wm8994->num_retune_mobile_texts++;
wm8994->retune_mobile_texts = t;
}
dev_dbg(codec->dev, "Allocated %d unique ReTune Mobile names\n",
wm8994->num_retune_mobile_texts);
wm8994->retune_mobile_enum.items = wm8994->num_retune_mobile_texts;
wm8994->retune_mobile_enum.texts = wm8994->retune_mobile_texts;
ret = snd_soc_add_codec_controls(wm8994->hubs.codec, controls,
ARRAY_SIZE(controls));
if (ret != 0)
dev_err(wm8994->hubs.codec->dev,
"Failed to add ReTune Mobile controls: %d\n", ret);
}
static void wm8994_handle_pdata(struct wm8994_priv *wm8994)
{
struct snd_soc_codec *codec = wm8994->hubs.codec;
struct wm8994 *control = wm8994->wm8994;
struct wm8994_pdata *pdata = &control->pdata;
int ret, i;
if (!pdata)
return;
wm_hubs_handle_analogue_pdata(codec, pdata->lineout1_diff,
pdata->lineout2_diff,
pdata->lineout1fb,
pdata->lineout2fb,
pdata->jd_scthr,
pdata->jd_thr,
pdata->micb1_delay,
pdata->micb2_delay,
pdata->micbias1_lvl,
pdata->micbias2_lvl);
dev_dbg(codec->dev, "%d DRC configurations\n", pdata->num_drc_cfgs);
if (pdata->num_drc_cfgs) {
struct snd_kcontrol_new controls[] = {
SOC_ENUM_EXT("AIF1DRC1 Mode", wm8994->drc_enum,
wm8994_get_drc_enum, wm8994_put_drc_enum),
SOC_ENUM_EXT("AIF1DRC2 Mode", wm8994->drc_enum,
wm8994_get_drc_enum, wm8994_put_drc_enum),
SOC_ENUM_EXT("AIF2DRC Mode", wm8994->drc_enum,
wm8994_get_drc_enum, wm8994_put_drc_enum),
};
wm8994->drc_texts = devm_kzalloc(wm8994->hubs.codec->dev,
sizeof(char *) * pdata->num_drc_cfgs, GFP_KERNEL);
if (!wm8994->drc_texts)
return;
for (i = 0; i < pdata->num_drc_cfgs; i++)
wm8994->drc_texts[i] = pdata->drc_cfgs[i].name;
wm8994->drc_enum.items = pdata->num_drc_cfgs;
wm8994->drc_enum.texts = wm8994->drc_texts;
ret = snd_soc_add_codec_controls(wm8994->hubs.codec, controls,
ARRAY_SIZE(controls));
for (i = 0; i < WM8994_NUM_DRC; i++)
wm8994_set_drc(codec, i);
} else {
ret = snd_soc_add_codec_controls(wm8994->hubs.codec,
wm8994_drc_controls,
ARRAY_SIZE(wm8994_drc_controls));
}
if (ret != 0)
dev_err(wm8994->hubs.codec->dev,
"Failed to add DRC mode controls: %d\n", ret);
dev_dbg(codec->dev, "%d ReTune Mobile configurations\n",
pdata->num_retune_mobile_cfgs);
if (pdata->num_retune_mobile_cfgs)
wm8994_handle_retune_mobile_pdata(wm8994);
else
snd_soc_add_codec_controls(wm8994->hubs.codec, wm8994_eq_controls,
ARRAY_SIZE(wm8994_eq_controls));
for (i = 0; i < ARRAY_SIZE(pdata->micbias); i++) {
if (pdata->micbias[i]) {
snd_soc_write(codec, WM8958_MICBIAS1 + i,
pdata->micbias[i] & 0xffff);
}
}
}
int wm8994_mic_detect(struct snd_soc_codec *codec, struct snd_soc_jack *jack,
int micbias)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
struct wm8994_micdet *micdet;
struct wm8994 *control = wm8994->wm8994;
int reg, ret;
if (control->type != WM8994) {
dev_warn(codec->dev, "Not a WM8994\n");
return -EINVAL;
}
switch (micbias) {
case 1:
micdet = &wm8994->micdet[0];
if (jack)
ret = snd_soc_dapm_force_enable_pin(&codec->dapm,
"MICBIAS1");
else
ret = snd_soc_dapm_disable_pin(&codec->dapm,
"MICBIAS1");
break;
case 2:
micdet = &wm8994->micdet[1];
if (jack)
ret = snd_soc_dapm_force_enable_pin(&codec->dapm,
"MICBIAS1");
else
ret = snd_soc_dapm_disable_pin(&codec->dapm,
"MICBIAS1");
break;
default:
dev_warn(codec->dev, "Invalid MICBIAS %d\n", micbias);
return -EINVAL;
}
if (ret != 0)
dev_warn(codec->dev, "Failed to configure MICBIAS%d: %d\n",
micbias, ret);
dev_dbg(codec->dev, "Configuring microphone detection on %d %p\n",
micbias, jack);
micdet->jack = jack;
micdet->detecting = true;
if (wm8994->micdet[0].jack || wm8994->micdet[1].jack)
reg = WM8994_MICD_ENA;
else
reg = 0;
snd_soc_update_bits(codec, WM8994_MICBIAS, WM8994_MICD_ENA, reg);
snd_soc_update_bits(codec, WM8994_IRQ_DEBOUNCE,
WM8994_MIC1_DET_DB_MASK | WM8994_MIC1_SHRT_DB_MASK |
WM8994_MIC2_DET_DB_MASK | WM8994_MIC2_SHRT_DB_MASK,
WM8994_MIC1_DET_DB | WM8994_MIC1_SHRT_DB);
snd_soc_dapm_sync(&codec->dapm);
return 0;
}
static void wm8994_mic_work(struct work_struct *work)
{
struct wm8994_priv *priv = container_of(work,
struct wm8994_priv,
mic_work.work);
struct regmap *regmap = priv->wm8994->regmap;
struct device *dev = priv->wm8994->dev;
unsigned int reg;
int ret;
int report;
pm_runtime_get_sync(dev);
ret = regmap_read(regmap, WM8994_INTERRUPT_RAW_STATUS_2, &reg);
if (ret < 0) {
dev_err(dev, "Failed to read microphone status: %d\n",
ret);
pm_runtime_put(dev);
return;
}
dev_dbg(dev, "Microphone status: %x\n", reg);
report = 0;
if (reg & WM8994_MIC1_DET_STS) {
if (priv->micdet[0].detecting)
report = SND_JACK_HEADSET;
}
if (reg & WM8994_MIC1_SHRT_STS) {
if (priv->micdet[0].detecting)
report = SND_JACK_HEADPHONE;
else
report |= SND_JACK_BTN_0;
}
if (report)
priv->micdet[0].detecting = false;
else
priv->micdet[0].detecting = true;
snd_soc_jack_report(priv->micdet[0].jack, report,
SND_JACK_HEADSET | SND_JACK_BTN_0);
report = 0;
if (reg & WM8994_MIC2_DET_STS) {
if (priv->micdet[1].detecting)
report = SND_JACK_HEADSET;
}
if (reg & WM8994_MIC2_SHRT_STS) {
if (priv->micdet[1].detecting)
report = SND_JACK_HEADPHONE;
else
report |= SND_JACK_BTN_0;
}
if (report)
priv->micdet[1].detecting = false;
else
priv->micdet[1].detecting = true;
snd_soc_jack_report(priv->micdet[1].jack, report,
SND_JACK_HEADSET | SND_JACK_BTN_0);
pm_runtime_put(dev);
}
static irqreturn_t wm8994_mic_irq(int irq, void *data)
{
struct wm8994_priv *priv = data;
struct snd_soc_codec *codec = priv->hubs.codec;
#ifndef CONFIG_SND_SOC_WM8994_MODULE
trace_snd_soc_jack_irq(dev_name(codec->dev));
#endif
pm_wakeup_event(codec->dev, 300);
queue_delayed_work(system_power_efficient_wq,
&priv->mic_work, msecs_to_jiffies(250));
return IRQ_HANDLED;
}
static void wm1811_micd_stop(struct snd_soc_codec *codec)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
if (!wm8994->jackdet)
return;
snd_soc_update_bits(codec, WM8958_MIC_DETECT_1, WM8958_MICD_ENA, 0);
wm1811_jackdet_set_mode(codec, WM1811_JACKDET_MODE_JACK);
if (wm8994->wm8994->pdata.jd_ext_cap)
snd_soc_dapm_disable_pin(&codec->dapm,
"MICBIAS2");
}
static void wm8958_button_det(struct snd_soc_codec *codec, u16 status)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
int report;
report = 0;
if (status & 0x4)
report |= SND_JACK_BTN_0;
if (status & 0x8)
report |= SND_JACK_BTN_1;
if (status & 0x10)
report |= SND_JACK_BTN_2;
if (status & 0x20)
report |= SND_JACK_BTN_3;
if (status & 0x40)
report |= SND_JACK_BTN_4;
if (status & 0x80)
report |= SND_JACK_BTN_5;
snd_soc_jack_report(wm8994->micdet[0].jack, report,
wm8994->btn_mask);
}
static void wm8958_open_circuit_work(struct work_struct *work)
{
struct wm8994_priv *wm8994 = container_of(work,
struct wm8994_priv,
open_circuit_work.work);
struct device *dev = wm8994->wm8994->dev;
mutex_lock(&wm8994->accdet_lock);
wm1811_micd_stop(wm8994->hubs.codec);
dev_dbg(dev, "Reporting open circuit\n");
wm8994->jack_mic = false;
wm8994->mic_detecting = true;
wm8958_micd_set_rate(wm8994->hubs.codec);
snd_soc_jack_report(wm8994->micdet[0].jack, 0,
wm8994->btn_mask |
SND_JACK_HEADSET);
mutex_unlock(&wm8994->accdet_lock);
}
static void wm8958_mic_id(void *data, u16 status)
{
struct snd_soc_codec *codec = data;
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
if (!(status & WM8958_MICD_STS)) {
dev_dbg(codec->dev, "Detected open circuit\n");
queue_delayed_work(system_power_efficient_wq,
&wm8994->open_circuit_work,
msecs_to_jiffies(2500));
return;
}
if (status & 0x600) {
dev_dbg(codec->dev, "Detected microphone\n");
wm8994->mic_detecting = false;
wm8994->jack_mic = true;
wm8958_micd_set_rate(codec);
snd_soc_jack_report(wm8994->micdet[0].jack, SND_JACK_HEADSET,
SND_JACK_HEADSET);
}
if (status & 0xfc) {
dev_dbg(codec->dev, "Detected headphone\n");
wm8994->mic_detecting = false;
wm8958_micd_set_rate(codec);
wm1811_micd_stop(codec);
snd_soc_jack_report(wm8994->micdet[0].jack, SND_JACK_HEADPHONE,
SND_JACK_HEADSET);
}
}
static void wm1811_mic_work(struct work_struct *work)
{
struct wm8994_priv *wm8994 = container_of(work, struct wm8994_priv,
mic_work.work);
struct wm8994 *control = wm8994->wm8994;
struct snd_soc_codec *codec = wm8994->hubs.codec;
pm_runtime_get_sync(codec->dev);
if (control->pdata.jd_ext_cap) {
snd_soc_dapm_force_enable_pin(&codec->dapm,
"MICBIAS2");
snd_soc_dapm_sync(&codec->dapm);
}
mutex_lock(&wm8994->accdet_lock);
dev_dbg(codec->dev, "Starting mic detection\n");
if (wm8994->micd_cb) {
wm8994->micd_cb(wm8994->micd_cb_data);
} else {
wm8994->mic_detecting = true;
wm1811_jackdet_set_mode(codec, WM1811_JACKDET_MODE_MIC);
snd_soc_update_bits(codec, WM8958_MIC_DETECT_1,
WM8958_MICD_ENA, WM8958_MICD_ENA);
}
mutex_unlock(&wm8994->accdet_lock);
pm_runtime_put(codec->dev);
}
static irqreturn_t wm1811_jackdet_irq(int irq, void *data)
{
struct wm8994_priv *wm8994 = data;
struct wm8994 *control = wm8994->wm8994;
struct snd_soc_codec *codec = wm8994->hubs.codec;
int reg, delay;
bool present;
pm_runtime_get_sync(codec->dev);
cancel_delayed_work_sync(&wm8994->mic_complete_work);
mutex_lock(&wm8994->accdet_lock);
reg = snd_soc_read(codec, WM1811_JACKDET_CTRL);
if (reg < 0) {
dev_err(codec->dev, "Failed to read jack status: %d\n", reg);
mutex_unlock(&wm8994->accdet_lock);
pm_runtime_put(codec->dev);
return IRQ_NONE;
}
dev_dbg(codec->dev, "JACKDET %x\n", reg);
present = reg & WM1811_JACKDET_LVL;
if (present) {
dev_dbg(codec->dev, "Jack detected\n");
wm8958_micd_set_rate(codec);
snd_soc_update_bits(codec, WM8958_MICBIAS2,
WM8958_MICB2_DISCH, 0);
snd_soc_update_bits(codec, WM1811_JACKDET_CTRL,
WM1811_JACKDET_DB, 0);
delay = control->pdata.micdet_delay;
queue_delayed_work(system_power_efficient_wq,
&wm8994->mic_work,
msecs_to_jiffies(delay));
} else {
dev_dbg(codec->dev, "Jack not detected\n");
cancel_delayed_work_sync(&wm8994->mic_work);
snd_soc_update_bits(codec, WM8958_MICBIAS2,
WM8958_MICB2_DISCH, WM8958_MICB2_DISCH);
snd_soc_update_bits(codec, WM1811_JACKDET_CTRL,
WM1811_JACKDET_DB, WM1811_JACKDET_DB);
wm8994->mic_detecting = false;
wm8994->jack_mic = false;
snd_soc_update_bits(codec, WM8958_MIC_DETECT_1,
WM8958_MICD_ENA, 0);
wm1811_jackdet_set_mode(codec, WM1811_JACKDET_MODE_JACK);
}
mutex_unlock(&wm8994->accdet_lock);
if (control->pdata.jd_ext_cap && !present)
snd_soc_dapm_disable_pin(&codec->dapm, "MICBIAS2");
if (present)
snd_soc_jack_report(wm8994->micdet[0].jack,
SND_JACK_MECHANICAL, SND_JACK_MECHANICAL);
else
snd_soc_jack_report(wm8994->micdet[0].jack, 0,
SND_JACK_MECHANICAL | SND_JACK_HEADSET |
wm8994->btn_mask);
snd_soc_jack_report(wm8994->micdet[0].jack, 0, 0);
pm_runtime_put(codec->dev);
return IRQ_HANDLED;
}
static void wm1811_jackdet_bootstrap(struct work_struct *work)
{
struct wm8994_priv *wm8994 = container_of(work,
struct wm8994_priv,
jackdet_bootstrap.work);
wm1811_jackdet_irq(0, wm8994);
}
int wm8958_mic_detect(struct snd_soc_codec *codec, struct snd_soc_jack *jack,
wm1811_micdet_cb det_cb, void *det_cb_data,
wm1811_mic_id_cb id_cb, void *id_cb_data)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
struct wm8994 *control = wm8994->wm8994;
u16 micd_lvl_sel;
switch (control->type) {
case WM1811:
case WM8958:
break;
default:
return -EINVAL;
}
if (jack) {
snd_soc_dapm_force_enable_pin(&codec->dapm, "CLK_SYS");
snd_soc_dapm_sync(&codec->dapm);
wm8994->micdet[0].jack = jack;
if (det_cb) {
wm8994->micd_cb = det_cb;
wm8994->micd_cb_data = det_cb_data;
} else {
wm8994->mic_detecting = true;
wm8994->jack_mic = false;
}
if (id_cb) {
wm8994->mic_id_cb = id_cb;
wm8994->mic_id_cb_data = id_cb_data;
} else {
wm8994->mic_id_cb = wm8958_mic_id;
wm8994->mic_id_cb_data = codec;
}
wm8958_micd_set_rate(codec);
if (control->pdata.micd_lvl_sel)
micd_lvl_sel = control->pdata.micd_lvl_sel;
else
micd_lvl_sel = 0x41;
wm8994->btn_mask = SND_JACK_BTN_0 | SND_JACK_BTN_1 |
SND_JACK_BTN_2 | SND_JACK_BTN_3 |
SND_JACK_BTN_4 | SND_JACK_BTN_5;
snd_soc_update_bits(codec, WM8958_MIC_DETECT_2,
WM8958_MICD_LVL_SEL_MASK, micd_lvl_sel);
WARN_ON(codec->dapm.bias_level > SND_SOC_BIAS_STANDBY);
if (wm8994->jackdet) {
snd_soc_update_bits(codec, WM1811_JACKDET_CTRL,
WM1811_JACKDET_DB, 0);
snd_soc_update_bits(codec, WM8958_MICBIAS2,
WM8958_MICB2_DISCH,
WM8958_MICB2_DISCH);
snd_soc_update_bits(codec, WM8994_LDO_1,
WM8994_LDO1_DISCH, 0);
wm1811_jackdet_set_mode(codec,
WM1811_JACKDET_MODE_JACK);
} else {
snd_soc_update_bits(codec, WM8958_MIC_DETECT_1,
WM8958_MICD_ENA, WM8958_MICD_ENA);
}
} else {
snd_soc_update_bits(codec, WM8958_MIC_DETECT_1,
WM8958_MICD_ENA, 0);
wm1811_jackdet_set_mode(codec, WM1811_JACKDET_MODE_NONE);
snd_soc_dapm_disable_pin(&codec->dapm, "CLK_SYS");
snd_soc_dapm_sync(&codec->dapm);
}
return 0;
}
static void wm8958_mic_work(struct work_struct *work)
{
struct wm8994_priv *wm8994 = container_of(work,
struct wm8994_priv,
mic_complete_work.work);
struct snd_soc_codec *codec = wm8994->hubs.codec;
pm_runtime_get_sync(codec->dev);
mutex_lock(&wm8994->accdet_lock);
wm8994->mic_id_cb(wm8994->mic_id_cb_data, wm8994->mic_status);
mutex_unlock(&wm8994->accdet_lock);
pm_runtime_put(codec->dev);
}
static irqreturn_t wm8958_mic_irq(int irq, void *data)
{
struct wm8994_priv *wm8994 = data;
struct snd_soc_codec *codec = wm8994->hubs.codec;
int reg, count, ret, id_delay;
if (!(snd_soc_read(codec, WM8958_MIC_DETECT_1) & WM8958_MICD_ENA))
return IRQ_HANDLED;
cancel_delayed_work_sync(&wm8994->mic_complete_work);
cancel_delayed_work_sync(&wm8994->open_circuit_work);
pm_runtime_get_sync(codec->dev);
count = 10;
do {
reg = snd_soc_read(codec, WM8958_MIC_DETECT_3);
if (reg < 0) {
dev_err(codec->dev,
"Failed to read mic detect status: %d\n",
reg);
pm_runtime_put(codec->dev);
return IRQ_NONE;
}
if (!(reg & WM8958_MICD_VALID)) {
dev_dbg(codec->dev, "Mic detect data not valid\n");
goto out;
}
if (!(reg & WM8958_MICD_STS) || (reg & WM8958_MICD_LVL_MASK))
break;
msleep(1);
} while (count--);
if (count == 0)
dev_warn(codec->dev, "No impedance range reported for jack\n");
#ifndef CONFIG_SND_SOC_WM8994_MODULE
trace_snd_soc_jack_irq(dev_name(codec->dev));
#endif
if (wm8994->jackdet) {
ret = snd_soc_read(codec, WM1811_JACKDET_CTRL);
if (ret < 0) {
dev_err(codec->dev, "Failed to read jack status: %d\n",
ret);
} else if (!(ret & WM1811_JACKDET_LVL)) {
dev_dbg(codec->dev, "Ignoring removed jack\n");
goto out;
}
} else if (!(reg & WM8958_MICD_STS)) {
snd_soc_jack_report(wm8994->micdet[0].jack, 0,
SND_JACK_MECHANICAL | SND_JACK_HEADSET |
wm8994->btn_mask);
wm8994->mic_detecting = true;
goto out;
}
wm8994->mic_status = reg;
id_delay = wm8994->wm8994->pdata.mic_id_delay;
if (wm8994->mic_detecting)
queue_delayed_work(system_power_efficient_wq,
&wm8994->mic_complete_work,
msecs_to_jiffies(id_delay));
else
wm8958_button_det(codec, reg);
out:
pm_runtime_put(codec->dev);
return IRQ_HANDLED;
}
static irqreturn_t wm8994_fifo_error(int irq, void *data)
{
struct snd_soc_codec *codec = data;
dev_err(codec->dev, "FIFO error\n");
return IRQ_HANDLED;
}
static irqreturn_t wm8994_temp_warn(int irq, void *data)
{
struct snd_soc_codec *codec = data;
dev_err(codec->dev, "Thermal warning\n");
return IRQ_HANDLED;
}
static irqreturn_t wm8994_temp_shut(int irq, void *data)
{
struct snd_soc_codec *codec = data;
dev_crit(codec->dev, "Thermal shutdown\n");
return IRQ_HANDLED;
}
static int wm8994_codec_probe(struct snd_soc_codec *codec)
{
struct wm8994 *control = dev_get_drvdata(codec->dev->parent);
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = &codec->dapm;
unsigned int reg;
int ret, i;
wm8994->hubs.codec = codec;
mutex_init(&wm8994->accdet_lock);
INIT_DELAYED_WORK(&wm8994->jackdet_bootstrap,
wm1811_jackdet_bootstrap);
INIT_DELAYED_WORK(&wm8994->open_circuit_work,
wm8958_open_circuit_work);
switch (control->type) {
case WM8994:
INIT_DELAYED_WORK(&wm8994->mic_work, wm8994_mic_work);
break;
case WM1811:
INIT_DELAYED_WORK(&wm8994->mic_work, wm1811_mic_work);
break;
default:
break;
}
INIT_DELAYED_WORK(&wm8994->mic_complete_work, wm8958_mic_work);
for (i = 0; i < ARRAY_SIZE(wm8994->fll_locked); i++)
init_completion(&wm8994->fll_locked[i]);
wm8994->micdet_irq = control->pdata.micdet_irq;
codec->dapm.idle_bias_off = 1;
switch (control->type) {
case WM8994:
if (!control->pdata.lineout1_diff ||
!control->pdata.lineout2_diff)
codec->dapm.idle_bias_off = 0;
switch (control->revision) {
case 2:
case 3:
wm8994->hubs.dcs_codes_l = -5;
wm8994->hubs.dcs_codes_r = -5;
wm8994->hubs.hp_startup_mode = 1;
wm8994->hubs.dcs_readback_mode = 1;
wm8994->hubs.series_startup = 1;
break;
default:
wm8994->hubs.dcs_readback_mode = 2;
break;
}
break;
case WM8958:
wm8994->hubs.dcs_readback_mode = 1;
wm8994->hubs.hp_startup_mode = 1;
switch (control->revision) {
case 0:
break;
default:
wm8994->fll_byp = true;
break;
}
break;
case WM1811:
wm8994->hubs.dcs_readback_mode = 2;
wm8994->hubs.no_series_update = 1;
wm8994->hubs.hp_startup_mode = 1;
wm8994->hubs.no_cache_dac_hp_direct = true;
wm8994->fll_byp = true;
wm8994->hubs.dcs_codes_l = -9;
wm8994->hubs.dcs_codes_r = -7;
snd_soc_update_bits(codec, WM8994_ANALOGUE_HP_1,
WM1811_HPOUT1_ATTN, WM1811_HPOUT1_ATTN);
break;
default:
break;
}
wm8994_request_irq(wm8994->wm8994, WM8994_IRQ_FIFOS_ERR,
wm8994_fifo_error, "FIFO error", codec);
wm8994_request_irq(wm8994->wm8994, WM8994_IRQ_TEMP_WARN,
wm8994_temp_warn, "Thermal warning", codec);
wm8994_request_irq(wm8994->wm8994, WM8994_IRQ_TEMP_SHUT,
wm8994_temp_shut, "Thermal shutdown", codec);
switch (control->type) {
case WM8994:
if (wm8994->micdet_irq) {
ret = request_threaded_irq(wm8994->micdet_irq, NULL,
wm8994_mic_irq,
IRQF_TRIGGER_RISING,
"Mic1 detect",
wm8994);
if (ret != 0)
dev_warn(codec->dev,
"Failed to request Mic1 detect IRQ: %d\n",
ret);
}
ret = wm8994_request_irq(wm8994->wm8994,
WM8994_IRQ_MIC1_SHRT,
wm8994_mic_irq, "Mic 1 short",
wm8994);
if (ret != 0)
dev_warn(codec->dev,
"Failed to request Mic1 short IRQ: %d\n",
ret);
ret = wm8994_request_irq(wm8994->wm8994,
WM8994_IRQ_MIC2_DET,
wm8994_mic_irq, "Mic 2 detect",
wm8994);
if (ret != 0)
dev_warn(codec->dev,
"Failed to request Mic2 detect IRQ: %d\n",
ret);
ret = wm8994_request_irq(wm8994->wm8994,
WM8994_IRQ_MIC2_SHRT,
wm8994_mic_irq, "Mic 2 short",
wm8994);
if (ret != 0)
dev_warn(codec->dev,
"Failed to request Mic2 short IRQ: %d\n",
ret);
break;
case WM8958:
case WM1811:
if (wm8994->micdet_irq) {
ret = request_threaded_irq(wm8994->micdet_irq, NULL,
wm8958_mic_irq,
IRQF_TRIGGER_RISING,
"Mic detect",
wm8994);
if (ret != 0)
dev_warn(codec->dev,
"Failed to request Mic detect IRQ: %d\n",
ret);
} else {
wm8994_request_irq(wm8994->wm8994, WM8994_IRQ_MIC1_DET,
wm8958_mic_irq, "Mic detect",
wm8994);
}
}
switch (control->type) {
case WM1811:
if (control->cust_id > 1 || control->revision > 1) {
ret = wm8994_request_irq(wm8994->wm8994,
WM8994_IRQ_GPIO(6),
wm1811_jackdet_irq, "JACKDET",
wm8994);
if (ret == 0)
wm8994->jackdet = true;
}
break;
default:
break;
}
wm8994->fll_locked_irq = true;
for (i = 0; i < ARRAY_SIZE(wm8994->fll_locked); i++) {
ret = wm8994_request_irq(wm8994->wm8994,
WM8994_IRQ_FLL1_LOCK + i,
wm8994_fll_locked_irq, "FLL lock",
&wm8994->fll_locked[i]);
if (ret != 0)
wm8994->fll_locked_irq = false;
}
pm_runtime_get_sync(codec->dev);
ret = regmap_read(control->regmap, WM8994_GPIO_1, &reg);
if (ret < 0) {
dev_err(codec->dev, "Failed to read GPIO1 state: %d\n", ret);
goto err_irq;
}
if ((reg & WM8994_GPN_FN_MASK) != WM8994_GP_FN_PIN_SPECIFIC) {
wm8994->lrclk_shared[0] = 1;
wm8994_dai[0].symmetric_rates = 1;
} else {
wm8994->lrclk_shared[0] = 0;
}
ret = regmap_read(control->regmap, WM8994_GPIO_6, &reg);
if (ret < 0) {
dev_err(codec->dev, "Failed to read GPIO6 state: %d\n", ret);
goto err_irq;
}
if ((reg & WM8994_GPN_FN_MASK) != WM8994_GP_FN_PIN_SPECIFIC) {
wm8994->lrclk_shared[1] = 1;
wm8994_dai[1].symmetric_rates = 1;
} else {
wm8994->lrclk_shared[1] = 0;
}
pm_runtime_put(codec->dev);
for (i = 0; i < ARRAY_SIZE(wm8994_vu_bits); i++)
snd_soc_update_bits(codec, wm8994_vu_bits[i].reg,
wm8994_vu_bits[i].mask,
wm8994_vu_bits[i].mask);
snd_soc_update_bits(codec, WM8994_AIF1_DAC1_FILTERS_2,
1 << WM8994_AIF1DAC1_3D_GAIN_SHIFT,
1 << WM8994_AIF1DAC1_3D_GAIN_SHIFT);
snd_soc_update_bits(codec, WM8994_AIF1_DAC2_FILTERS_2,
1 << WM8994_AIF1DAC2_3D_GAIN_SHIFT,
1 << WM8994_AIF1DAC2_3D_GAIN_SHIFT);
snd_soc_update_bits(codec, WM8994_AIF2_DAC_FILTERS_2,
1 << WM8994_AIF2DAC_3D_GAIN_SHIFT,
1 << WM8994_AIF2DAC_3D_GAIN_SHIFT);
switch (control->type) {
case WM8994:
case WM8958:
snd_soc_update_bits(codec, WM8994_AIF1_CONTROL_1,
WM8994_AIF1ADC_TDM, WM8994_AIF1ADC_TDM);
break;
default:
break;
}
switch (control->type) {
case WM8958:
case WM1811:
snd_soc_update_bits(codec, WM8958_MICBIAS1,
WM8958_MICB1_MODE, WM8958_MICB1_MODE);
snd_soc_update_bits(codec, WM8958_MICBIAS2,
WM8958_MICB2_MODE, WM8958_MICB2_MODE);
break;
default:
break;
}
wm8994->hubs.check_class_w_digital = wm8994_check_class_w_digital;
wm_hubs_update_class_w(codec);
wm8994_handle_pdata(wm8994);
wm_hubs_add_analogue_controls(codec);
snd_soc_add_codec_controls(codec, wm8994_snd_controls,
ARRAY_SIZE(wm8994_snd_controls));
snd_soc_dapm_new_controls(dapm, wm8994_dapm_widgets,
ARRAY_SIZE(wm8994_dapm_widgets));
switch (control->type) {
case WM8994:
snd_soc_dapm_new_controls(dapm, wm8994_specific_dapm_widgets,
ARRAY_SIZE(wm8994_specific_dapm_widgets));
if (control->revision < 4) {
snd_soc_dapm_new_controls(dapm, wm8994_lateclk_revd_widgets,
ARRAY_SIZE(wm8994_lateclk_revd_widgets));
snd_soc_dapm_new_controls(dapm, wm8994_adc_revd_widgets,
ARRAY_SIZE(wm8994_adc_revd_widgets));
snd_soc_dapm_new_controls(dapm, wm8994_dac_revd_widgets,
ARRAY_SIZE(wm8994_dac_revd_widgets));
} else {
snd_soc_dapm_new_controls(dapm, wm8994_lateclk_widgets,
ARRAY_SIZE(wm8994_lateclk_widgets));
snd_soc_dapm_new_controls(dapm, wm8994_adc_widgets,
ARRAY_SIZE(wm8994_adc_widgets));
snd_soc_dapm_new_controls(dapm, wm8994_dac_widgets,
ARRAY_SIZE(wm8994_dac_widgets));
}
break;
case WM8958:
snd_soc_add_codec_controls(codec, wm8958_snd_controls,
ARRAY_SIZE(wm8958_snd_controls));
snd_soc_dapm_new_controls(dapm, wm8958_dapm_widgets,
ARRAY_SIZE(wm8958_dapm_widgets));
if (control->revision < 1) {
snd_soc_dapm_new_controls(dapm, wm8994_lateclk_revd_widgets,
ARRAY_SIZE(wm8994_lateclk_revd_widgets));
snd_soc_dapm_new_controls(dapm, wm8994_adc_revd_widgets,
ARRAY_SIZE(wm8994_adc_revd_widgets));
snd_soc_dapm_new_controls(dapm, wm8994_dac_revd_widgets,
ARRAY_SIZE(wm8994_dac_revd_widgets));
} else {
snd_soc_dapm_new_controls(dapm, wm8994_lateclk_widgets,
ARRAY_SIZE(wm8994_lateclk_widgets));
snd_soc_dapm_new_controls(dapm, wm8994_adc_widgets,
ARRAY_SIZE(wm8994_adc_widgets));
snd_soc_dapm_new_controls(dapm, wm8994_dac_widgets,
ARRAY_SIZE(wm8994_dac_widgets));
}
break;
case WM1811:
snd_soc_add_codec_controls(codec, wm8958_snd_controls,
ARRAY_SIZE(wm8958_snd_controls));
snd_soc_dapm_new_controls(dapm, wm8958_dapm_widgets,
ARRAY_SIZE(wm8958_dapm_widgets));
snd_soc_dapm_new_controls(dapm, wm8994_lateclk_widgets,
ARRAY_SIZE(wm8994_lateclk_widgets));
snd_soc_dapm_new_controls(dapm, wm8994_adc_widgets,
ARRAY_SIZE(wm8994_adc_widgets));
snd_soc_dapm_new_controls(dapm, wm8994_dac_widgets,
ARRAY_SIZE(wm8994_dac_widgets));
break;
}
wm_hubs_add_analogue_routes(codec, 0, 0);
ret = wm8994_request_irq(wm8994->wm8994, WM8994_IRQ_DCS_DONE,
wm_hubs_dcs_done, "DC servo done",
&wm8994->hubs);
if (ret == 0)
wm8994->hubs.dcs_done_irq = true;
snd_soc_dapm_add_routes(dapm, intercon, ARRAY_SIZE(intercon));
switch (control->type) {
case WM8994:
snd_soc_dapm_add_routes(dapm, wm8994_intercon,
ARRAY_SIZE(wm8994_intercon));
if (control->revision < 4) {
snd_soc_dapm_add_routes(dapm, wm8994_revd_intercon,
ARRAY_SIZE(wm8994_revd_intercon));
snd_soc_dapm_add_routes(dapm, wm8994_lateclk_revd_intercon,
ARRAY_SIZE(wm8994_lateclk_revd_intercon));
} else {
snd_soc_dapm_add_routes(dapm, wm8994_lateclk_intercon,
ARRAY_SIZE(wm8994_lateclk_intercon));
}
break;
case WM8958:
if (control->revision < 1) {
snd_soc_dapm_add_routes(dapm, wm8994_intercon,
ARRAY_SIZE(wm8994_intercon));
snd_soc_dapm_add_routes(dapm, wm8994_revd_intercon,
ARRAY_SIZE(wm8994_revd_intercon));
snd_soc_dapm_add_routes(dapm, wm8994_lateclk_revd_intercon,
ARRAY_SIZE(wm8994_lateclk_revd_intercon));
} else {
snd_soc_dapm_add_routes(dapm, wm8994_lateclk_intercon,
ARRAY_SIZE(wm8994_lateclk_intercon));
snd_soc_dapm_add_routes(dapm, wm8958_intercon,
ARRAY_SIZE(wm8958_intercon));
}
wm8958_dsp2_init(codec);
break;
case WM1811:
snd_soc_dapm_add_routes(dapm, wm8994_lateclk_intercon,
ARRAY_SIZE(wm8994_lateclk_intercon));
snd_soc_dapm_add_routes(dapm, wm8958_intercon,
ARRAY_SIZE(wm8958_intercon));
break;
}
return 0;
err_irq:
if (wm8994->jackdet)
wm8994_free_irq(wm8994->wm8994, WM8994_IRQ_GPIO(6), wm8994);
wm8994_free_irq(wm8994->wm8994, WM8994_IRQ_MIC2_SHRT, wm8994);
wm8994_free_irq(wm8994->wm8994, WM8994_IRQ_MIC2_DET, wm8994);
wm8994_free_irq(wm8994->wm8994, WM8994_IRQ_MIC1_SHRT, wm8994);
if (wm8994->micdet_irq)
free_irq(wm8994->micdet_irq, wm8994);
for (i = 0; i < ARRAY_SIZE(wm8994->fll_locked); i++)
wm8994_free_irq(wm8994->wm8994, WM8994_IRQ_FLL1_LOCK + i,
&wm8994->fll_locked[i]);
wm8994_free_irq(wm8994->wm8994, WM8994_IRQ_DCS_DONE,
&wm8994->hubs);
wm8994_free_irq(wm8994->wm8994, WM8994_IRQ_FIFOS_ERR, codec);
wm8994_free_irq(wm8994->wm8994, WM8994_IRQ_TEMP_SHUT, codec);
wm8994_free_irq(wm8994->wm8994, WM8994_IRQ_TEMP_WARN, codec);
return ret;
}
static int wm8994_codec_remove(struct snd_soc_codec *codec)
{
struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
struct wm8994 *control = wm8994->wm8994;
int i;
wm8994_set_bias_level(codec, SND_SOC_BIAS_OFF);
for (i = 0; i < ARRAY_SIZE(wm8994->fll_locked); i++)
wm8994_free_irq(wm8994->wm8994, WM8994_IRQ_FLL1_LOCK + i,
&wm8994->fll_locked[i]);
wm8994_free_irq(wm8994->wm8994, WM8994_IRQ_DCS_DONE,
&wm8994->hubs);
wm8994_free_irq(wm8994->wm8994, WM8994_IRQ_FIFOS_ERR, codec);
wm8994_free_irq(wm8994->wm8994, WM8994_IRQ_TEMP_SHUT, codec);
wm8994_free_irq(wm8994->wm8994, WM8994_IRQ_TEMP_WARN, codec);
if (wm8994->jackdet)
wm8994_free_irq(wm8994->wm8994, WM8994_IRQ_GPIO(6), wm8994);
switch (control->type) {
case WM8994:
if (wm8994->micdet_irq)
free_irq(wm8994->micdet_irq, wm8994);
wm8994_free_irq(wm8994->wm8994, WM8994_IRQ_MIC2_DET,
wm8994);
wm8994_free_irq(wm8994->wm8994, WM8994_IRQ_MIC1_SHRT,
wm8994);
wm8994_free_irq(wm8994->wm8994, WM8994_IRQ_MIC1_DET,
wm8994);
break;
case WM1811:
case WM8958:
if (wm8994->micdet_irq)
free_irq(wm8994->micdet_irq, wm8994);
break;
}
release_firmware(wm8994->mbc);
release_firmware(wm8994->mbc_vss);
release_firmware(wm8994->enh_eq);
kfree(wm8994->retune_mobile_texts);
return 0;
}
static struct regmap *wm8994_get_regmap(struct device *dev)
{
struct wm8994 *control = dev_get_drvdata(dev->parent);
return control->regmap;
}
static int wm8994_probe(struct platform_device *pdev)
{
struct wm8994_priv *wm8994;
wm8994 = devm_kzalloc(&pdev->dev, sizeof(struct wm8994_priv),
GFP_KERNEL);
if (wm8994 == NULL)
return -ENOMEM;
platform_set_drvdata(pdev, wm8994);
wm8994->wm8994 = dev_get_drvdata(pdev->dev.parent);
pm_runtime_enable(&pdev->dev);
pm_runtime_idle(&pdev->dev);
return snd_soc_register_codec(&pdev->dev, &soc_codec_dev_wm8994,
wm8994_dai, ARRAY_SIZE(wm8994_dai));
}
static int wm8994_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int wm8994_suspend(struct device *dev)
{
struct wm8994_priv *wm8994 = dev_get_drvdata(dev);
if (wm8994->jackdet && !wm8994->active_refcount)
regmap_update_bits(wm8994->wm8994->regmap, WM8994_ANTIPOP_2,
WM1811_JACKDET_MODE_MASK,
wm8994->jackdet_mode);
return 0;
}
static int wm8994_resume(struct device *dev)
{
struct wm8994_priv *wm8994 = dev_get_drvdata(dev);
if (wm8994->jackdet && wm8994->jackdet_mode)
regmap_update_bits(wm8994->wm8994->regmap, WM8994_ANTIPOP_2,
WM1811_JACKDET_MODE_MASK,
WM1811_JACKDET_MODE_AUDIO);
return 0;
}
