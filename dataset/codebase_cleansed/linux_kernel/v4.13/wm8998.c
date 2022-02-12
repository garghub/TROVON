static int wm8998_asrc_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
unsigned int val;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
val = snd_soc_read(codec, ARIZONA_ASRC_RATE1);
val &= ARIZONA_ASRC_RATE1_MASK;
val >>= ARIZONA_ASRC_RATE1_SHIFT;
switch (val) {
case 0:
case 1:
case 2:
val = snd_soc_read(codec,
ARIZONA_SAMPLE_RATE_1 + val);
if (val >= 0x11) {
dev_warn(codec->dev,
"Unsupported ASRC rate1 (%s)\n",
arizona_sample_rate_val_to_name(val));
return -EINVAL;
}
break;
default:
dev_err(codec->dev,
"Illegal ASRC rate1 selector (0x%x)\n",
val);
return -EINVAL;
}
val = snd_soc_read(codec, ARIZONA_ASRC_RATE2);
val &= ARIZONA_ASRC_RATE2_MASK;
val >>= ARIZONA_ASRC_RATE2_SHIFT;
switch (val) {
case 8:
case 9:
val -= 0x8;
val = snd_soc_read(codec,
ARIZONA_ASYNC_SAMPLE_RATE_1 + val);
if (val >= 0x11) {
dev_warn(codec->dev,
"Unsupported ASRC rate2 (%s)\n",
arizona_sample_rate_val_to_name(val));
return -EINVAL;
}
break;
default:
dev_err(codec->dev,
"Illegal ASRC rate2 selector (0x%x)\n",
val);
return -EINVAL;
}
break;
default:
return -EINVAL;
}
return 0;
}
static int wm8998_in1mux_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_dapm_kcontrol_codec(kcontrol);
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct wm8998_priv *wm8998 = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = wm8998->core.arizona;
struct soc_enum *e = (struct soc_enum *)kcontrol->private_value;
unsigned int mux, inmode;
unsigned int mode_val, src_val;
mux = ucontrol->value.enumerated.item[0];
if (mux > 1)
return -EINVAL;
inmode = arizona->pdata.inmode[2 * mux];
src_val = mux << ARIZONA_IN1L_SRC_SHIFT;
if (inmode & ARIZONA_INMODE_SE)
src_val |= 1 << ARIZONA_IN1L_SRC_SE_SHIFT;
switch (arizona->pdata.inmode[0]) {
case ARIZONA_INMODE_DMIC:
if (mux)
mode_val = 0;
else
mode_val = 1 << ARIZONA_IN1_MODE_SHIFT;
snd_soc_update_bits(codec, ARIZONA_IN1L_CONTROL,
ARIZONA_IN1_MODE_MASK, mode_val);
snd_soc_update_bits(codec,
ARIZONA_ADC_DIGITAL_VOLUME_1L,
ARIZONA_IN1L_SRC_MASK |
ARIZONA_IN1L_SRC_SE_MASK, src_val);
snd_soc_update_bits(codec,
ARIZONA_ADC_DIGITAL_VOLUME_1R,
ARIZONA_IN1R_SRC_MASK |
ARIZONA_IN1R_SRC_SE_MASK, src_val);
break;
default:
snd_soc_update_bits(codec,
e->reg,
ARIZONA_IN1L_SRC_MASK |
ARIZONA_IN1L_SRC_SE_MASK,
src_val);
break;
}
return snd_soc_dapm_mux_update_power(dapm, kcontrol,
ucontrol->value.enumerated.item[0],
e, NULL);
}
static int wm8998_in2mux_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_dapm_kcontrol_codec(kcontrol);
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct wm8998_priv *wm8998 = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = wm8998->core.arizona;
struct soc_enum *e = (struct soc_enum *)kcontrol->private_value;
unsigned int mux, inmode, src_val, mode_val;
mux = ucontrol->value.enumerated.item[0];
if (mux > 1)
return -EINVAL;
inmode = arizona->pdata.inmode[1 + (2 * mux)];
if (inmode & ARIZONA_INMODE_DMIC)
mode_val = 1 << ARIZONA_IN2_MODE_SHIFT;
else
mode_val = 0;
src_val = mux << ARIZONA_IN2L_SRC_SHIFT;
if (inmode & ARIZONA_INMODE_SE)
src_val |= 1 << ARIZONA_IN2L_SRC_SE_SHIFT;
snd_soc_update_bits(codec, ARIZONA_IN2L_CONTROL,
ARIZONA_IN2_MODE_MASK, mode_val);
snd_soc_update_bits(codec, ARIZONA_ADC_DIGITAL_VOLUME_2L,
ARIZONA_IN2L_SRC_MASK | ARIZONA_IN2L_SRC_SE_MASK,
src_val);
return snd_soc_dapm_mux_update_power(dapm, kcontrol,
ucontrol->value.enumerated.item[0],
e, NULL);
}
static int wm8998_set_fll(struct snd_soc_codec *codec, int fll_id, int source,
unsigned int Fref, unsigned int Fout)
{
struct wm8998_priv *wm8998 = snd_soc_codec_get_drvdata(codec);
switch (fll_id) {
case WM8998_FLL1:
return arizona_set_fll(&wm8998->fll[0], source, Fref, Fout);
case WM8998_FLL2:
return arizona_set_fll(&wm8998->fll[1], source, Fref, Fout);
case WM8998_FLL1_REFCLK:
return arizona_set_fll_refclk(&wm8998->fll[0], source, Fref,
Fout);
case WM8998_FLL2_REFCLK:
return arizona_set_fll_refclk(&wm8998->fll[1], source, Fref,
Fout);
default:
return -EINVAL;
}
}
static int wm8998_codec_probe(struct snd_soc_codec *codec)
{
struct wm8998_priv *priv = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct snd_soc_component *component = snd_soc_dapm_to_component(dapm);
int ret;
priv->core.arizona->dapm = dapm;
ret = arizona_init_spk(codec);
if (ret < 0)
return ret;
arizona_init_gpio(codec);
arizona_init_notifiers(codec);
snd_soc_component_disable_pin(component, "HAPTICS");
return 0;
}
static int wm8998_codec_remove(struct snd_soc_codec *codec)
{
struct wm8998_priv *priv = snd_soc_codec_get_drvdata(codec);
priv->core.arizona->dapm = NULL;
return 0;
}
static struct regmap *wm8998_get_regmap(struct device *dev)
{
struct wm8998_priv *priv = dev_get_drvdata(dev);
return priv->core.arizona->regmap;
}
static int wm8998_probe(struct platform_device *pdev)
{
struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
struct wm8998_priv *wm8998;
int i, ret;
wm8998 = devm_kzalloc(&pdev->dev, sizeof(struct wm8998_priv),
GFP_KERNEL);
if (!wm8998)
return -ENOMEM;
platform_set_drvdata(pdev, wm8998);
wm8998->core.arizona = arizona;
wm8998->core.num_inputs = 3;
for (i = 0; i < ARRAY_SIZE(wm8998->fll); i++)
wm8998->fll[i].vco_mult = 1;
arizona_init_fll(arizona, 1, ARIZONA_FLL1_CONTROL_1 - 1,
ARIZONA_IRQ_FLL1_LOCK, ARIZONA_IRQ_FLL1_CLOCK_OK,
&wm8998->fll[0]);
arizona_init_fll(arizona, 2, ARIZONA_FLL2_CONTROL_1 - 1,
ARIZONA_IRQ_FLL2_LOCK, ARIZONA_IRQ_FLL2_CLOCK_OK,
&wm8998->fll[1]);
for (i = 0; i < ARRAY_SIZE(wm8998_dai); i++)
arizona_init_dai(&wm8998->core, i);
for (i = 0; i < ARRAY_SIZE(wm8998_digital_vu); i++)
regmap_update_bits(arizona->regmap, wm8998_digital_vu[i],
WM8998_DIG_VU, WM8998_DIG_VU);
pm_runtime_enable(&pdev->dev);
pm_runtime_idle(&pdev->dev);
ret = arizona_init_spk_irqs(arizona);
if (ret < 0)
return ret;
ret = snd_soc_register_codec(&pdev->dev, &soc_codec_dev_wm8998,
wm8998_dai, ARRAY_SIZE(wm8998_dai));
if (ret < 0) {
dev_err(&pdev->dev, "Failed to register codec: %d\n", ret);
goto err_spk_irqs;
}
return ret;
err_spk_irqs:
arizona_free_spk_irqs(arizona);
return ret;
}
static int wm8998_remove(struct platform_device *pdev)
{
struct wm8998_priv *wm8998 = platform_get_drvdata(pdev);
struct arizona *arizona = wm8998->core.arizona;
snd_soc_unregister_codec(&pdev->dev);
pm_runtime_disable(&pdev->dev);
arizona_free_spk_irqs(arizona);
return 0;
}
