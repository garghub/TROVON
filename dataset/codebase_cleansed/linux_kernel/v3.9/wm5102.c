static int wm5102_sysclk_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct arizona *arizona = dev_get_drvdata(codec->dev->parent);
struct regmap *regmap = codec->control_data;
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
regmap_write(regmap, patch[i].reg,
patch[i].def);
break;
default:
break;
}
return 0;
}
static int wm5102_spk_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
struct snd_soc_codec *codec = w->codec;
struct arizona *arizona = dev_get_drvdata(codec->dev->parent);
struct wm5102_priv *wm5102 = snd_soc_codec_get_drvdata(codec);
if (arizona->rev < 1)
return 0;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
if (!wm5102->spk_ena) {
snd_soc_write(codec, 0x4f5, 0x25a);
wm5102->spk_ena_pending = true;
}
break;
case SND_SOC_DAPM_POST_PMU:
if (wm5102->spk_ena_pending) {
msleep(75);
snd_soc_write(codec, 0x4f5, 0xda);
wm5102->spk_ena_pending = false;
wm5102->spk_ena++;
}
break;
case SND_SOC_DAPM_PRE_PMD:
wm5102->spk_ena--;
if (!wm5102->spk_ena)
snd_soc_write(codec, 0x4f5, 0x25a);
break;
case SND_SOC_DAPM_POST_PMD:
if (!wm5102->spk_ena)
snd_soc_write(codec, 0x4f5, 0x0da);
break;
}
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
default:
return -EINVAL;
}
}
static int wm5102_codec_probe(struct snd_soc_codec *codec)
{
struct wm5102_priv *priv = snd_soc_codec_get_drvdata(codec);
int ret;
codec->control_data = priv->core.arizona->regmap;
ret = snd_soc_codec_set_cache_io(codec, 32, 16, SND_SOC_REGMAP);
if (ret != 0)
return ret;
ret = snd_soc_add_codec_controls(codec, wm_adsp_fw_controls, 1);
if (ret != 0)
return ret;
snd_soc_dapm_disable_pin(&codec->dapm, "HAPTICS");
priv->core.arizona->dapm = &codec->dapm;
return 0;
}
static int wm5102_codec_remove(struct snd_soc_codec *codec)
{
struct wm5102_priv *priv = snd_soc_codec_get_drvdata(codec);
priv->core.arizona->dapm = NULL;
return 0;
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
wm5102->core.arizona = arizona;
wm5102->core.adsp[0].part = "wm5102";
wm5102->core.adsp[0].num = 1;
wm5102->core.adsp[0].type = WMFW_ADSP2;
wm5102->core.adsp[0].base = ARIZONA_DSP1_CONTROL_1;
wm5102->core.adsp[0].dev = arizona->dev;
wm5102->core.adsp[0].regmap = arizona->regmap;
wm5102->core.adsp[0].mem = wm5102_dsp1_regions;
wm5102->core.adsp[0].num_mems = ARRAY_SIZE(wm5102_dsp1_regions);
ret = wm_adsp2_init(&wm5102->core.adsp[0], true);
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
for (i = 0; i < ARRAY_SIZE(wm5102_dai); i++)
arizona_init_dai(&wm5102->core, i);
for (i = 0; i < ARRAY_SIZE(wm5102_digital_vu); i++)
regmap_update_bits(arizona->regmap, wm5102_digital_vu[i],
WM5102_DIG_VU, WM5102_DIG_VU);
pm_runtime_enable(&pdev->dev);
pm_runtime_idle(&pdev->dev);
return snd_soc_register_codec(&pdev->dev, &soc_codec_dev_wm5102,
wm5102_dai, ARRAY_SIZE(wm5102_dai));
}
static int wm5102_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
