static int wm5110_sysclk_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct arizona *arizona = dev_get_drvdata(codec->dev->parent);
struct regmap *regmap = codec->control_data;
const struct reg_default *patch = NULL;
int i, patch_size;
switch (arizona->rev) {
case 3:
patch = wm5110_sysclk_revd_patch;
patch_size = ARRAY_SIZE(wm5110_sysclk_revd_patch);
break;
default:
return 0;
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
struct wm5110_priv *priv = snd_soc_codec_get_drvdata(codec);
int ret;
codec->control_data = priv->core.arizona->regmap;
priv->core.arizona->dapm = &codec->dapm;
ret = snd_soc_codec_set_cache_io(codec, 32, 16, SND_SOC_REGMAP);
if (ret != 0)
return ret;
arizona_init_spk(codec);
arizona_init_gpio(codec);
ret = snd_soc_add_codec_controls(codec, wm_adsp2_fw_controls, 8);
if (ret != 0)
return ret;
snd_soc_dapm_disable_pin(&codec->dapm, "HAPTICS");
priv->core.arizona->dapm = &codec->dapm;
return 0;
}
static int wm5110_codec_remove(struct snd_soc_codec *codec)
{
struct wm5110_priv *priv = snd_soc_codec_get_drvdata(codec);
priv->core.arizona->dapm = NULL;
return 0;
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
ret = wm_adsp2_init(&wm5110->core.adsp[i], false);
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
