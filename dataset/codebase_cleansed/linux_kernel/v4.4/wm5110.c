static int wm5110_sysclk_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct arizona *arizona = dev_get_drvdata(codec->dev->parent);
struct regmap *regmap = arizona->regmap;
const struct reg_default *patch = NULL;
int i, patch_size;
switch (arizona->rev) {
case 3:
patch = wm5110_sysclk_revd_patch;
patch_size = ARRAY_SIZE(wm5110_sysclk_revd_patch);
break;
default:
patch = wm5110_sysclk_reve_patch;
patch_size = ARRAY_SIZE(wm5110_sysclk_reve_patch);
break;
}
switch (event) {
case SND_SOC_DAPM_POST_PMU:
if (patch)
for (i = 0; i < patch_size; i++)
regmap_write_async(regmap, patch[i].reg,
patch[i].def);
break;
default:
break;
}
return 0;
}
static int wm5110_hp_pre_enable(struct snd_soc_dapm_widget *w)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->arizona;
unsigned int val = snd_soc_read(codec, ARIZONA_DRE_ENABLE);
const struct reg_sequence *wseq;
int nregs;
switch (w->shift) {
case ARIZONA_OUT1L_ENA_SHIFT:
if (val & ARIZONA_DRE1L_ENA_MASK) {
wseq = wm5110_dre_left_enable;
nregs = ARRAY_SIZE(wm5110_dre_left_enable);
} else {
wseq = wm5110_no_dre_left_enable;
nregs = ARRAY_SIZE(wm5110_no_dre_left_enable);
priv->out_up_delay += 10;
}
break;
case ARIZONA_OUT1R_ENA_SHIFT:
if (val & ARIZONA_DRE1R_ENA_MASK) {
wseq = wm5110_dre_right_enable;
nregs = ARRAY_SIZE(wm5110_dre_right_enable);
} else {
wseq = wm5110_no_dre_right_enable;
nregs = ARRAY_SIZE(wm5110_no_dre_right_enable);
priv->out_up_delay += 10;
}
break;
default:
return 0;
}
return regmap_multi_reg_write(arizona->regmap, wseq, nregs);
}
static int wm5110_hp_pre_disable(struct snd_soc_dapm_widget *w)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
unsigned int val = snd_soc_read(codec, ARIZONA_DRE_ENABLE);
switch (w->shift) {
case ARIZONA_OUT1L_ENA_SHIFT:
if (!(val & ARIZONA_DRE1L_ENA_MASK)) {
snd_soc_update_bits(codec, ARIZONA_SPARE_TRIGGERS,
ARIZONA_WS_TRG1, ARIZONA_WS_TRG1);
snd_soc_update_bits(codec, ARIZONA_SPARE_TRIGGERS,
ARIZONA_WS_TRG1, 0);
priv->out_down_delay += 27;
}
break;
case ARIZONA_OUT1R_ENA_SHIFT:
if (!(val & ARIZONA_DRE1R_ENA_MASK)) {
snd_soc_update_bits(codec, ARIZONA_SPARE_TRIGGERS,
ARIZONA_WS_TRG2, ARIZONA_WS_TRG2);
snd_soc_update_bits(codec, ARIZONA_SPARE_TRIGGERS,
ARIZONA_WS_TRG2, 0);
priv->out_down_delay += 27;
}
break;
default:
break;
}
return 0;
}
static int wm5110_hp_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
switch (priv->arizona->rev) {
case 0 ... 3:
break;
default:
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
wm5110_hp_pre_enable(w);
break;
case SND_SOC_DAPM_PRE_PMD:
wm5110_hp_pre_disable(w);
break;
default:
break;
}
break;
}
return arizona_hp_ev(w, kcontrol, event);
}
static int wm5110_clear_pga_volume(struct arizona *arizona, int output)
{
struct reg_sequence clear_pga = {
ARIZONA_OUTPUT_PATH_CONFIG_1L + output * 4, 0x80
};
int ret;
ret = regmap_multi_reg_write_bypassed(arizona->regmap, &clear_pga, 1);
if (ret)
dev_err(arizona->dev, "Failed to clear PGA (0x%x): %d\n",
clear_pga.reg, ret);
return ret;
}
static int wm5110_put_dre(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct arizona *arizona = dev_get_drvdata(codec->dev->parent);
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int ena, dre;
unsigned int mask = (0x1 << mc->shift) | (0x1 << mc->rshift);
unsigned int lnew = (!!ucontrol->value.integer.value[0]) << mc->shift;
unsigned int rnew = (!!ucontrol->value.integer.value[1]) << mc->rshift;
unsigned int lold, rold;
unsigned int lena, rena;
int ret;
snd_soc_dapm_mutex_lock(dapm);
ret = regmap_read(arizona->regmap, ARIZONA_OUTPUT_ENABLES_1, &ena);
if (ret) {
dev_err(arizona->dev, "Failed to read output state: %d\n", ret);
goto err;
}
ret = regmap_read(arizona->regmap, ARIZONA_DRE_ENABLE, &dre);
if (ret) {
dev_err(arizona->dev, "Failed to read DRE state: %d\n", ret);
goto err;
}
lold = dre & (1 << mc->shift);
rold = dre & (1 << mc->rshift);
lena = ena & (1 << mc->rshift);
rena = ena & (1 << mc->shift);
if ((lena && lnew != lold) || (rena && rnew != rold)) {
dev_err(arizona->dev, "Can't change DRE on active outputs\n");
ret = -EBUSY;
goto err;
}
ret = regmap_update_bits(arizona->regmap, ARIZONA_DRE_ENABLE,
mask, lnew | rnew);
if (ret) {
dev_err(arizona->dev, "Failed to set DRE: %d\n", ret);
goto err;
}
if (!lnew && lold)
wm5110_clear_pga_volume(arizona, mc->shift);
if (!rnew && rold)
wm5110_clear_pga_volume(arizona, mc->rshift);
err:
snd_soc_dapm_mutex_unlock(dapm);
return ret;
}
static int wm5110_in_pga_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct snd_soc_card *card = dapm->card;
int ret;
mutex_lock_nested(&card->dapm_mutex, SND_SOC_DAPM_CLASS_RUNTIME);
ret = snd_soc_get_volsw_range(kcontrol, ucontrol);
mutex_unlock(&card->dapm_mutex);
return ret;
}
static int wm5110_in_pga_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct snd_soc_card *card = dapm->card;
int ret;
mutex_lock_nested(&card->dapm_mutex, SND_SOC_DAPM_CLASS_RUNTIME);
ret = snd_soc_put_volsw_range(kcontrol, ucontrol);
mutex_unlock(&card->dapm_mutex);
return ret;
}
static int wm5110_in_analog_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct wm5110_priv *wm5110 = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->arizona;
unsigned int reg, mask;
struct reg_sequence analog_seq[] = {
{ 0x80, 0x3 },
{ 0x35d, 0 },
{ 0x80, 0x0 },
};
reg = ARIZONA_IN1L_CONTROL + ((w->shift ^ 0x1) * 4);
mask = ARIZONA_IN1L_PGA_VOL_MASK;
switch (event) {
case SND_SOC_DAPM_WILL_PMU:
wm5110->in_value |= 0x3 << ((w->shift ^ 0x1) * 2);
wm5110->in_pre_pending++;
wm5110->in_post_pending++;
return 0;
case SND_SOC_DAPM_PRE_PMU:
wm5110->in_pga_cache[w->shift] = snd_soc_read(codec, reg);
snd_soc_update_bits(codec, reg, mask,
0x40 << ARIZONA_IN1L_PGA_VOL_SHIFT);
wm5110->in_pre_pending--;
if (wm5110->in_pre_pending == 0) {
analog_seq[1].def = wm5110->in_value;
regmap_multi_reg_write_bypassed(arizona->regmap,
analog_seq,
ARRAY_SIZE(analog_seq));
msleep(55);
wm5110->in_value = 0;
}
break;
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, reg, mask,
wm5110->in_pga_cache[w->shift]);
wm5110->in_post_pending--;
if (wm5110->in_post_pending == 0)
regmap_multi_reg_write_bypassed(arizona->regmap,
analog_seq,
ARRAY_SIZE(analog_seq));
break;
default:
break;
}
return 0;
}
static int wm5110_in_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->arizona;
switch (arizona->rev) {
case 0 ... 4:
if (arizona_input_analog(codec, w->shift))
wm5110_in_analog_ev(w, kcontrol, event);
break;
default:
break;
}
return arizona_in_ev(w, kcontrol, event);
}
static int wm5110_set_fll(struct snd_soc_codec *codec, int fll_id, int source,
unsigned int Fref, unsigned int Fout)
{
struct wm5110_priv *wm5110 = snd_soc_codec_get_drvdata(codec);
switch (fll_id) {
case WM5110_FLL1:
return arizona_set_fll(&wm5110->fll[0], source, Fref, Fout);
case WM5110_FLL2:
return arizona_set_fll(&wm5110->fll[1], source, Fref, Fout);
case WM5110_FLL1_REFCLK:
return arizona_set_fll_refclk(&wm5110->fll[0], source, Fref,
Fout);
case WM5110_FLL2_REFCLK:
return arizona_set_fll_refclk(&wm5110->fll[1], source, Fref,
Fout);
default:
return -EINVAL;
}
}
static int wm5110_codec_probe(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct wm5110_priv *priv = snd_soc_codec_get_drvdata(codec);
int i, ret;
priv->core.arizona->dapm = dapm;
arizona_init_spk(codec);
arizona_init_gpio(codec);
arizona_init_mono(codec);
for (i = 0; i < WM5110_NUM_ADSP; ++i) {
ret = wm_adsp2_codec_probe(&priv->core.adsp[i], codec);
if (ret)
goto err_adsp2_codec_probe;
}
ret = snd_soc_add_codec_controls(codec,
arizona_adsp2_rate_controls,
WM5110_NUM_ADSP);
if (ret)
goto err_adsp2_codec_probe;
snd_soc_dapm_disable_pin(dapm, "HAPTICS");
return 0;
err_adsp2_codec_probe:
for (--i; i >= 0; --i)
wm_adsp2_codec_remove(&priv->core.adsp[i], codec);
return ret;
}
static int wm5110_codec_remove(struct snd_soc_codec *codec)
{
struct wm5110_priv *priv = snd_soc_codec_get_drvdata(codec);
int i;
for (i = 0; i < WM5110_NUM_ADSP; ++i)
wm_adsp2_codec_remove(&priv->core.adsp[i], codec);
priv->core.arizona->dapm = NULL;
return 0;
}
static struct regmap *wm5110_get_regmap(struct device *dev)
{
struct wm5110_priv *priv = dev_get_drvdata(dev);
return priv->core.arizona->regmap;
}
static int wm5110_probe(struct platform_device *pdev)
{
struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
struct wm5110_priv *wm5110;
int i, ret;
wm5110 = devm_kzalloc(&pdev->dev, sizeof(struct wm5110_priv),
GFP_KERNEL);
if (wm5110 == NULL)
return -ENOMEM;
platform_set_drvdata(pdev, wm5110);
wm5110->core.arizona = arizona;
wm5110->core.num_inputs = 8;
for (i = 0; i < WM5110_NUM_ADSP; i++) {
wm5110->core.adsp[i].part = "wm5110";
wm5110->core.adsp[i].num = i + 1;
wm5110->core.adsp[i].type = WMFW_ADSP2;
wm5110->core.adsp[i].dev = arizona->dev;
wm5110->core.adsp[i].regmap = arizona->regmap;
wm5110->core.adsp[i].base = ARIZONA_DSP1_CONTROL_1
+ (0x100 * i);
wm5110->core.adsp[i].mem = wm5110_dsp_regions[i];
wm5110->core.adsp[i].num_mems
= ARRAY_SIZE(wm5110_dsp1_regions);
ret = wm_adsp2_init(&wm5110->core.adsp[i]);
if (ret != 0)
return ret;
}
for (i = 0; i < ARRAY_SIZE(wm5110->fll); i++)
wm5110->fll[i].vco_mult = 3;
arizona_init_fll(arizona, 1, ARIZONA_FLL1_CONTROL_1 - 1,
ARIZONA_IRQ_FLL1_LOCK, ARIZONA_IRQ_FLL1_CLOCK_OK,
&wm5110->fll[0]);
arizona_init_fll(arizona, 2, ARIZONA_FLL2_CONTROL_1 - 1,
ARIZONA_IRQ_FLL2_LOCK, ARIZONA_IRQ_FLL2_CLOCK_OK,
&wm5110->fll[1]);
regmap_update_bits(arizona->regmap, ARIZONA_SAMPLE_RATE_2,
ARIZONA_SAMPLE_RATE_2_MASK, 0x11);
regmap_update_bits(arizona->regmap, ARIZONA_SAMPLE_RATE_3,
ARIZONA_SAMPLE_RATE_3_MASK, 0x12);
for (i = 0; i < ARRAY_SIZE(wm5110_dai); i++)
arizona_init_dai(&wm5110->core, i);
for (i = 0; i < ARRAY_SIZE(wm5110_digital_vu); i++)
regmap_update_bits(arizona->regmap, wm5110_digital_vu[i],
WM5110_DIG_VU, WM5110_DIG_VU);
pm_runtime_enable(&pdev->dev);
pm_runtime_idle(&pdev->dev);
return snd_soc_register_codec(&pdev->dev, &soc_codec_dev_wm5110,
wm5110_dai, ARRAY_SIZE(wm5110_dai));
}
static int wm5110_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
