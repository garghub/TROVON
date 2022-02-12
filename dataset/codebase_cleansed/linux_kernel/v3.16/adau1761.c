static int adau1761_dejitter_fixup(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct adau *adau = snd_soc_codec_get_drvdata(w->codec);
regmap_write(adau->regmap, ADAU1761_DEJITTER, 0);
if (!adau->master)
regmap_write(adau->regmap, ADAU1761_DEJITTER, 3);
return 0;
}
static int adau1761_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct adau *adau = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
regmap_update_bits(adau->regmap, ADAU17X1_CLOCK_CONTROL,
ADAU17X1_CLOCK_CONTROL_SYSCLK_EN,
ADAU17X1_CLOCK_CONTROL_SYSCLK_EN);
break;
case SND_SOC_BIAS_OFF:
regmap_update_bits(adau->regmap, ADAU17X1_CLOCK_CONTROL,
ADAU17X1_CLOCK_CONTROL_SYSCLK_EN, 0);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static enum adau1761_output_mode adau1761_get_lineout_mode(
struct snd_soc_codec *codec)
{
struct adau1761_platform_data *pdata = codec->dev->platform_data;
if (pdata)
return pdata->lineout_mode;
return ADAU1761_OUTPUT_MODE_LINE;
}
static int adau1761_setup_digmic_jackdetect(struct snd_soc_codec *codec)
{
struct adau1761_platform_data *pdata = codec->dev->platform_data;
struct adau *adau = snd_soc_codec_get_drvdata(codec);
enum adau1761_digmic_jackdet_pin_mode mode;
unsigned int val = 0;
int ret;
if (pdata)
mode = pdata->digmic_jackdetect_pin_mode;
else
mode = ADAU1761_DIGMIC_JACKDET_PIN_MODE_NONE;
switch (mode) {
case ADAU1761_DIGMIC_JACKDET_PIN_MODE_JACKDETECT:
switch (pdata->jackdetect_debounce_time) {
case ADAU1761_JACKDETECT_DEBOUNCE_5MS:
case ADAU1761_JACKDETECT_DEBOUNCE_10MS:
case ADAU1761_JACKDETECT_DEBOUNCE_20MS:
case ADAU1761_JACKDETECT_DEBOUNCE_40MS:
val |= pdata->jackdetect_debounce_time << 6;
break;
default:
return -EINVAL;
}
if (pdata->jackdetect_active_low)
val |= ADAU1761_DIGMIC_JACKDETECT_ACTIVE_LOW;
ret = snd_soc_add_codec_controls(codec,
adau1761_jack_detect_controls,
ARRAY_SIZE(adau1761_jack_detect_controls));
if (ret)
return ret;
case ADAU1761_DIGMIC_JACKDET_PIN_MODE_NONE:
ret = snd_soc_dapm_add_routes(&codec->dapm,
adau1761_no_dmic_routes,
ARRAY_SIZE(adau1761_no_dmic_routes));
if (ret)
return ret;
break;
case ADAU1761_DIGMIC_JACKDET_PIN_MODE_DIGMIC:
ret = snd_soc_dapm_new_controls(&codec->dapm,
adau1761_dmic_widgets,
ARRAY_SIZE(adau1761_dmic_widgets));
if (ret)
return ret;
ret = snd_soc_dapm_add_routes(&codec->dapm,
adau1761_dmic_routes,
ARRAY_SIZE(adau1761_dmic_routes));
if (ret)
return ret;
val |= ADAU1761_DIGMIC_JACKDETECT_DIGMIC;
break;
default:
return -EINVAL;
}
regmap_write(adau->regmap, ADAU1761_DIGMIC_JACKDETECT, val);
return 0;
}
static int adau1761_setup_headphone_mode(struct snd_soc_codec *codec)
{
struct adau *adau = snd_soc_codec_get_drvdata(codec);
struct adau1761_platform_data *pdata = codec->dev->platform_data;
enum adau1761_output_mode mode;
int ret;
if (pdata)
mode = pdata->headphone_mode;
else
mode = ADAU1761_OUTPUT_MODE_HEADPHONE;
switch (mode) {
case ADAU1761_OUTPUT_MODE_LINE:
break;
case ADAU1761_OUTPUT_MODE_HEADPHONE_CAPLESS:
regmap_update_bits(adau->regmap, ADAU1761_PLAY_MONO_OUTPUT_VOL,
ADAU1761_PLAY_MONO_OUTPUT_VOL_MODE_HP |
ADAU1761_PLAY_MONO_OUTPUT_VOL_UNMUTE,
ADAU1761_PLAY_MONO_OUTPUT_VOL_MODE_HP |
ADAU1761_PLAY_MONO_OUTPUT_VOL_UNMUTE);
case ADAU1761_OUTPUT_MODE_HEADPHONE:
regmap_update_bits(adau->regmap, ADAU1761_PLAY_HP_RIGHT_VOL,
ADAU1761_PLAY_HP_RIGHT_VOL_MODE_HP,
ADAU1761_PLAY_HP_RIGHT_VOL_MODE_HP);
break;
default:
return -EINVAL;
}
if (mode == ADAU1761_OUTPUT_MODE_HEADPHONE_CAPLESS) {
ret = snd_soc_dapm_new_controls(&codec->dapm,
adau1761_capless_dapm_widgets,
ARRAY_SIZE(adau1761_capless_dapm_widgets));
if (ret)
return ret;
ret = snd_soc_dapm_add_routes(&codec->dapm,
adau1761_capless_dapm_routes,
ARRAY_SIZE(adau1761_capless_dapm_routes));
} else {
ret = snd_soc_add_codec_controls(codec, adau1761_mono_controls,
ARRAY_SIZE(adau1761_mono_controls));
if (ret)
return ret;
ret = snd_soc_dapm_new_controls(&codec->dapm,
adau1761_mono_dapm_widgets,
ARRAY_SIZE(adau1761_mono_dapm_widgets));
if (ret)
return ret;
ret = snd_soc_dapm_add_routes(&codec->dapm,
adau1761_mono_dapm_routes,
ARRAY_SIZE(adau1761_mono_dapm_routes));
}
return ret;
}
static bool adau1761_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case ADAU1761_DIGMIC_JACKDETECT:
case ADAU1761_REC_MIXER_LEFT0:
case ADAU1761_REC_MIXER_LEFT1:
case ADAU1761_REC_MIXER_RIGHT0:
case ADAU1761_REC_MIXER_RIGHT1:
case ADAU1761_LEFT_DIFF_INPUT_VOL:
case ADAU1761_RIGHT_DIFF_INPUT_VOL:
case ADAU1761_PLAY_LR_MIXER_LEFT:
case ADAU1761_PLAY_MIXER_LEFT0:
case ADAU1761_PLAY_MIXER_LEFT1:
case ADAU1761_PLAY_MIXER_RIGHT0:
case ADAU1761_PLAY_MIXER_RIGHT1:
case ADAU1761_PLAY_LR_MIXER_RIGHT:
case ADAU1761_PLAY_MIXER_MONO:
case ADAU1761_PLAY_HP_LEFT_VOL:
case ADAU1761_PLAY_HP_RIGHT_VOL:
case ADAU1761_PLAY_LINE_LEFT_VOL:
case ADAU1761_PLAY_LINE_RIGHT_VOL:
case ADAU1761_PLAY_MONO_OUTPUT_VOL:
case ADAU1761_POP_CLICK_SUPPRESS:
case ADAU1761_JACK_DETECT_PIN:
case ADAU1761_DEJITTER:
case ADAU1761_CLK_ENABLE0:
case ADAU1761_CLK_ENABLE1:
return true;
default:
break;
}
return adau17x1_readable_register(dev, reg);
}
static int adau1761_codec_probe(struct snd_soc_codec *codec)
{
struct adau1761_platform_data *pdata = codec->dev->platform_data;
struct adau *adau = snd_soc_codec_get_drvdata(codec);
int ret;
ret = adau17x1_add_widgets(codec);
if (ret < 0)
return ret;
if (pdata && pdata->input_differential) {
regmap_update_bits(adau->regmap, ADAU1761_LEFT_DIFF_INPUT_VOL,
ADAU1761_DIFF_INPUT_VOL_LDEN,
ADAU1761_DIFF_INPUT_VOL_LDEN);
regmap_update_bits(adau->regmap, ADAU1761_RIGHT_DIFF_INPUT_VOL,
ADAU1761_DIFF_INPUT_VOL_LDEN,
ADAU1761_DIFF_INPUT_VOL_LDEN);
ret = snd_soc_add_codec_controls(codec,
adau1761_differential_mode_controls,
ARRAY_SIZE(adau1761_differential_mode_controls));
if (ret)
return ret;
} else {
ret = snd_soc_add_codec_controls(codec,
adau1761_single_mode_controls,
ARRAY_SIZE(adau1761_single_mode_controls));
if (ret)
return ret;
}
switch (adau1761_get_lineout_mode(codec)) {
case ADAU1761_OUTPUT_MODE_LINE:
break;
case ADAU1761_OUTPUT_MODE_HEADPHONE:
regmap_update_bits(adau->regmap, ADAU1761_PLAY_LINE_LEFT_VOL,
ADAU1761_PLAY_LINE_LEFT_VOL_MODE_HP,
ADAU1761_PLAY_LINE_LEFT_VOL_MODE_HP);
regmap_update_bits(adau->regmap, ADAU1761_PLAY_LINE_RIGHT_VOL,
ADAU1761_PLAY_LINE_RIGHT_VOL_MODE_HP,
ADAU1761_PLAY_LINE_RIGHT_VOL_MODE_HP);
break;
default:
return -EINVAL;
}
ret = adau1761_setup_headphone_mode(codec);
if (ret)
return ret;
ret = adau1761_setup_digmic_jackdetect(codec);
if (ret)
return ret;
if (adau->type == ADAU1761) {
ret = snd_soc_dapm_new_controls(&codec->dapm,
adau1761_dapm_widgets,
ARRAY_SIZE(adau1761_dapm_widgets));
if (ret)
return ret;
ret = snd_soc_dapm_add_routes(&codec->dapm,
adau1761_dapm_routes,
ARRAY_SIZE(adau1761_dapm_routes));
if (ret)
return ret;
ret = adau17x1_load_firmware(adau, codec->dev,
ADAU1761_FIRMWARE);
if (ret)
dev_warn(codec->dev, "Failed to firmware\n");
}
ret = adau17x1_add_routes(codec);
if (ret < 0)
return ret;
return 0;
}
int adau1761_probe(struct device *dev, struct regmap *regmap,
enum adau17x1_type type, void (*switch_mode)(struct device *dev))
{
struct snd_soc_dai_driver *dai_drv;
int ret;
ret = adau17x1_probe(dev, regmap, type, switch_mode);
if (ret)
return ret;
if (type == ADAU1361)
dai_drv = &adau1361_dai_driver;
else
dai_drv = &adau1761_dai_driver;
return snd_soc_register_codec(dev, &adau1761_codec_driver, dai_drv, 1);
}
