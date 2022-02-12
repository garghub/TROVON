static int adau1781_dejitter_fixup(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct adau *adau = snd_soc_codec_get_drvdata(codec);
regmap_write(adau->regmap, ADAU1781_DEJITTER, 0);
if (!adau->master)
regmap_write(adau->regmap, ADAU1781_DEJITTER, 5);
return 0;
}
static int adau1781_set_bias_level(struct snd_soc_codec *codec,
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
regmap_update_bits(adau->regmap, ADAU1781_DIG_PWDN1, 0x8, 0x8);
break;
case SND_SOC_BIAS_OFF:
regmap_update_bits(adau->regmap, ADAU1781_DIG_PWDN1, 0xc, 0x0);
regmap_update_bits(adau->regmap, ADAU17X1_CLOCK_CONTROL,
ADAU17X1_CLOCK_CONTROL_SYSCLK_EN, 0);
break;
}
return 0;
}
static bool adau1781_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case ADAU1781_DMIC_BEEP_CTRL:
case ADAU1781_LEFT_PGA:
case ADAU1781_RIGHT_PGA:
case ADAU1781_LEFT_PLAYBACK_MIXER:
case ADAU1781_RIGHT_PLAYBACK_MIXER:
case ADAU1781_MONO_PLAYBACK_MIXER:
case ADAU1781_LEFT_LINEOUT:
case ADAU1781_RIGHT_LINEOUT:
case ADAU1781_SPEAKER:
case ADAU1781_BEEP_ZC:
case ADAU1781_DEJITTER:
case ADAU1781_DIG_PWDN0:
case ADAU1781_DIG_PWDN1:
return true;
default:
break;
}
return adau17x1_readable_register(dev, reg);
}
static int adau1781_set_input_mode(struct adau *adau, unsigned int reg,
bool differential)
{
unsigned int val;
if (differential)
val = ADAU1781_INPUT_DIFFERNTIAL;
else
val = 0;
return regmap_update_bits(adau->regmap, reg,
ADAU1781_INPUT_DIFFERNTIAL, val);
}
static int adau1781_codec_probe(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct adau1781_platform_data *pdata = dev_get_platdata(codec->dev);
struct adau *adau = snd_soc_codec_get_drvdata(codec);
int ret;
ret = adau17x1_add_widgets(codec);
if (ret)
return ret;
if (pdata) {
ret = adau1781_set_input_mode(adau, ADAU1781_LEFT_PGA,
pdata->left_input_differential);
if (ret)
return ret;
ret = adau1781_set_input_mode(adau, ADAU1781_RIGHT_PGA,
pdata->right_input_differential);
if (ret)
return ret;
}
if (pdata && pdata->use_dmic) {
ret = snd_soc_dapm_new_controls(dapm,
adau1781_dmic_dapm_widgets,
ARRAY_SIZE(adau1781_dmic_dapm_widgets));
if (ret)
return ret;
ret = snd_soc_dapm_add_routes(dapm, adau1781_dmic_dapm_routes,
ARRAY_SIZE(adau1781_dmic_dapm_routes));
if (ret)
return ret;
} else {
ret = snd_soc_dapm_add_routes(dapm, adau1781_adc_dapm_routes,
ARRAY_SIZE(adau1781_adc_dapm_routes));
if (ret)
return ret;
}
ret = adau17x1_add_routes(codec);
if (ret < 0)
return ret;
return 0;
}
int adau1781_probe(struct device *dev, struct regmap *regmap,
enum adau17x1_type type, void (*switch_mode)(struct device *dev))
{
const char *firmware_name;
int ret;
switch (type) {
case ADAU1381:
firmware_name = ADAU1381_FIRMWARE;
break;
case ADAU1781:
firmware_name = ADAU1781_FIRMWARE;
break;
default:
return -EINVAL;
}
ret = adau17x1_probe(dev, regmap, type, switch_mode, firmware_name);
if (ret)
return ret;
return snd_soc_register_codec(dev, &adau1781_codec_driver,
&adau1781_dai_driver, 1);
}
