static int wm5102_sysclk_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct arizona *arizona = dev_get_drvdata(codec->dev->parent);
struct regmap *regmap = arizona->regmap;
const struct reg_default *patch = NULL;
int i, patch_size;
switch (arizona->rev) {
case 0:
patch = wm5102_sysclk_reva_patch;
patch_size = ARRAY_SIZE(wm5102_sysclk_reva_patch);
break;
default:
patch = wm5102_sysclk_revb_patch;
patch_size = ARRAY_SIZE(wm5102_sysclk_revb_patch);
break;
}
switch (event) {
case SND_SOC_DAPM_POST_PMU:
if (patch)
for (i = 0; i < patch_size; i++)
regmap_write_async(regmap, patch[i].reg,
patch[i].def);
break;
case SND_SOC_DAPM_PRE_PMD:
break;
default:
return 0;
}
return arizona_dvfs_sysclk_ev(w, kcontrol, event);
}
static int wm5102_adsp_power_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct arizona *arizona = dev_get_drvdata(codec->dev->parent);
unsigned int v = 0;
int ret;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
ret = regmap_read(arizona->regmap, ARIZONA_SYSTEM_CLOCK_1, &v);
if (ret != 0) {
dev_err(codec->dev,
"Failed to read SYSCLK state: %d\n", ret);
return -EIO;
}
v = (v & ARIZONA_SYSCLK_FREQ_MASK) >> ARIZONA_SYSCLK_FREQ_SHIFT;
if (v >= 3) {
ret = arizona_dvfs_up(codec, ARIZONA_DVFS_ADSP1_RQ);
if (ret) {
dev_err(codec->dev,
"Failed to raise DVFS: %d\n", ret);
return ret;
}
}
break;
case SND_SOC_DAPM_POST_PMD:
ret = arizona_dvfs_down(codec, ARIZONA_DVFS_ADSP1_RQ);
if (ret)
dev_warn(codec->dev,
"Failed to lower DVFS: %d\n", ret);
break;
default:
break;
}
return wm_adsp2_early_event(w, kcontrol, event, v);
}
static int wm5102_out_comp_coeff_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct arizona *arizona = dev_get_drvdata(codec->dev->parent);
mutex_lock(&arizona->dac_comp_lock);
put_unaligned_be16(arizona->dac_comp_coeff,
ucontrol->value.bytes.data);
mutex_unlock(&arizona->dac_comp_lock);
return 0;
}
static int wm5102_out_comp_coeff_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct arizona *arizona = dev_get_drvdata(codec->dev->parent);
mutex_lock(&arizona->dac_comp_lock);
memcpy(&arizona->dac_comp_coeff, ucontrol->value.bytes.data,
sizeof(arizona->dac_comp_coeff));
arizona->dac_comp_coeff = be16_to_cpu(arizona->dac_comp_coeff);
mutex_unlock(&arizona->dac_comp_lock);
return 0;
}
static int wm5102_out_comp_switch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct arizona *arizona = dev_get_drvdata(codec->dev->parent);
mutex_lock(&arizona->dac_comp_lock);
ucontrol->value.integer.value[0] = arizona->dac_comp_enabled;
mutex_unlock(&arizona->dac_comp_lock);
return 0;
}
static int wm5102_out_comp_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct arizona *arizona = dev_get_drvdata(codec->dev->parent);
mutex_lock(&arizona->dac_comp_lock);
arizona->dac_comp_enabled = ucontrol->value.integer.value[0];
mutex_unlock(&arizona->dac_comp_lock);
return 0;
}
static int wm5102_set_fll(struct snd_soc_codec *codec, int fll_id, int source,
unsigned int Fref, unsigned int Fout)
{
struct wm5102_priv *wm5102 = snd_soc_codec_get_drvdata(codec);
switch (fll_id) {
case WM5102_FLL1:
return arizona_set_fll(&wm5102->fll[0], source, Fref, Fout);
case WM5102_FLL2:
return arizona_set_fll(&wm5102->fll[1], source, Fref, Fout);
case WM5102_FLL1_REFCLK:
return arizona_set_fll_refclk(&wm5102->fll[0], source, Fref,
Fout);
case WM5102_FLL2_REFCLK:
return arizona_set_fll_refclk(&wm5102->fll[1], source, Fref,
Fout);
default:
return -EINVAL;
}
}
static int wm5102_open(struct snd_compr_stream *stream)
{
struct snd_soc_pcm_runtime *rtd = stream->private_data;
struct wm5102_priv *priv = snd_soc_codec_get_drvdata(rtd->codec);
return wm_adsp_compr_open(&priv->core.adsp[0], stream);
}
static irqreturn_t wm5102_adsp2_irq(int irq, void *data)
{
struct wm5102_priv *priv = data;
struct arizona *arizona = priv->core.arizona;
int ret;
ret = wm_adsp_compr_handle_irq(&priv->core.adsp[0]);
if (ret == -ENODEV) {
dev_err(arizona->dev, "Spurious compressed data IRQ\n");
return IRQ_NONE;
}
return IRQ_HANDLED;
}
static int wm5102_codec_probe(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct wm5102_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->core.arizona;
int ret;
ret = arizona_request_irq(arizona, ARIZONA_IRQ_DSP_IRQ1,
"ADSP2 Compressed IRQ", wm5102_adsp2_irq,
priv);
if (ret != 0) {
dev_err(codec->dev, "Failed to request DSP IRQ: %d\n", ret);
return ret;
}
ret = wm_adsp2_codec_probe(&priv->core.adsp[0], codec);
if (ret)
return ret;
ret = snd_soc_add_codec_controls(codec,
arizona_adsp2_rate_controls, 1);
if (ret)
goto err_adsp2_codec_probe;
arizona_init_spk(codec);
arizona_init_gpio(codec);
snd_soc_dapm_disable_pin(dapm, "HAPTICS");
priv->core.arizona->dapm = dapm;
return 0;
err_adsp2_codec_probe:
wm_adsp2_codec_remove(&priv->core.adsp[0], codec);
return ret;
}
static int wm5102_codec_remove(struct snd_soc_codec *codec)
{
struct wm5102_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->core.arizona;
wm_adsp2_codec_remove(&priv->core.adsp[0], codec);
priv->core.arizona->dapm = NULL;
arizona_free_irq(arizona, ARIZONA_IRQ_DSP_IRQ1, priv);
arizona_free_spk(codec);
return 0;
}
static struct regmap *wm5102_get_regmap(struct device *dev)
{
struct wm5102_priv *priv = dev_get_drvdata(dev);
return priv->core.arizona->regmap;
}
static int wm5102_probe(struct platform_device *pdev)
{
struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
struct wm5102_priv *wm5102;
int i, ret;
wm5102 = devm_kzalloc(&pdev->dev, sizeof(struct wm5102_priv),
GFP_KERNEL);
if (wm5102 == NULL)
return -ENOMEM;
platform_set_drvdata(pdev, wm5102);
mutex_init(&arizona->dac_comp_lock);
wm5102->core.arizona = arizona;
wm5102->core.num_inputs = 6;
arizona_init_dvfs(&wm5102->core);
wm5102->core.adsp[0].part = "wm5102";
wm5102->core.adsp[0].num = 1;
wm5102->core.adsp[0].type = WMFW_ADSP2;
wm5102->core.adsp[0].base = ARIZONA_DSP1_CONTROL_1;
wm5102->core.adsp[0].dev = arizona->dev;
wm5102->core.adsp[0].regmap = arizona->regmap;
wm5102->core.adsp[0].mem = wm5102_dsp1_regions;
wm5102->core.adsp[0].num_mems = ARRAY_SIZE(wm5102_dsp1_regions);
ret = wm_adsp2_init(&wm5102->core.adsp[0]);
if (ret != 0)
return ret;
for (i = 0; i < ARRAY_SIZE(wm5102->fll); i++)
wm5102->fll[i].vco_mult = 1;
arizona_init_fll(arizona, 1, ARIZONA_FLL1_CONTROL_1 - 1,
ARIZONA_IRQ_FLL1_LOCK, ARIZONA_IRQ_FLL1_CLOCK_OK,
&wm5102->fll[0]);
arizona_init_fll(arizona, 2, ARIZONA_FLL2_CONTROL_1 - 1,
ARIZONA_IRQ_FLL2_LOCK, ARIZONA_IRQ_FLL2_CLOCK_OK,
&wm5102->fll[1]);
regmap_update_bits(arizona->regmap, ARIZONA_SAMPLE_RATE_2,
ARIZONA_SAMPLE_RATE_2_MASK, 0x11);
regmap_update_bits(arizona->regmap, ARIZONA_SAMPLE_RATE_3,
ARIZONA_SAMPLE_RATE_3_MASK, 0x12);
for (i = 0; i < ARRAY_SIZE(wm5102_dai); i++)
arizona_init_dai(&wm5102->core, i);
for (i = 0; i < ARRAY_SIZE(wm5102_digital_vu); i++)
regmap_update_bits(arizona->regmap, wm5102_digital_vu[i],
WM5102_DIG_VU, WM5102_DIG_VU);
pm_runtime_enable(&pdev->dev);
pm_runtime_idle(&pdev->dev);
ret = snd_soc_register_platform(&pdev->dev, &wm5102_compr_platform);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to register platform: %d\n", ret);
return ret;
}
ret = snd_soc_register_codec(&pdev->dev, &soc_codec_dev_wm5102,
wm5102_dai, ARRAY_SIZE(wm5102_dai));
if (ret < 0) {
dev_err(&pdev->dev, "Failed to register codec: %d\n", ret);
snd_soc_unregister_platform(&pdev->dev);
}
return ret;
}
static int wm5102_remove(struct platform_device *pdev)
{
snd_soc_unregister_platform(&pdev->dev);
snd_soc_unregister_codec(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
