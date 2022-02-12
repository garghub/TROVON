static inline int ssm2602_get_coeff(int mclk, int rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(ssm2602_coeff_table); i++) {
if (ssm2602_coeff_table[i].rate == rate &&
ssm2602_coeff_table[i].mclk == mclk)
return ssm2602_coeff_table[i].srate;
}
return -EINVAL;
}
static int ssm2602_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct ssm2602_priv *ssm2602 = snd_soc_codec_get_drvdata(codec);
int srate = ssm2602_get_coeff(ssm2602->sysclk, params_rate(params));
unsigned int iface;
if (srate < 0)
return srate;
regmap_write(ssm2602->regmap, SSM2602_SRATE, srate);
switch (params_width(params)) {
case 16:
iface = 0x0;
break;
case 20:
iface = 0x4;
break;
case 24:
iface = 0x8;
break;
case 32:
iface = 0xc;
break;
default:
return -EINVAL;
}
regmap_update_bits(ssm2602->regmap, SSM2602_IFACE,
IFACE_AUDIO_DATA_LEN, iface);
return 0;
}
static int ssm2602_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct ssm2602_priv *ssm2602 = snd_soc_codec_get_drvdata(codec);
if (ssm2602->sysclk_constraints) {
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
ssm2602->sysclk_constraints);
}
return 0;
}
static int ssm2602_mute(struct snd_soc_dai *dai, int mute)
{
struct ssm2602_priv *ssm2602 = snd_soc_codec_get_drvdata(dai->codec);
if (mute)
regmap_update_bits(ssm2602->regmap, SSM2602_APDIGI,
APDIGI_ENABLE_DAC_MUTE,
APDIGI_ENABLE_DAC_MUTE);
else
regmap_update_bits(ssm2602->regmap, SSM2602_APDIGI,
APDIGI_ENABLE_DAC_MUTE, 0);
return 0;
}
static int ssm2602_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct ssm2602_priv *ssm2602 = snd_soc_codec_get_drvdata(codec);
if (dir == SND_SOC_CLOCK_IN) {
if (clk_id != SSM2602_SYSCLK)
return -EINVAL;
switch (freq) {
case 12288000:
case 18432000:
ssm2602->sysclk_constraints = &ssm2602_constraints_12288000;
break;
case 11289600:
case 16934400:
ssm2602->sysclk_constraints = &ssm2602_constraints_11289600;
break;
case 12000000:
ssm2602->sysclk_constraints = NULL;
break;
default:
return -EINVAL;
}
ssm2602->sysclk = freq;
} else {
unsigned int mask;
switch (clk_id) {
case SSM2602_CLK_CLKOUT:
mask = PWR_CLK_OUT_PDN;
break;
case SSM2602_CLK_XTO:
mask = PWR_OSC_PDN;
break;
default:
return -EINVAL;
}
if (freq == 0)
ssm2602->clk_out_pwr |= mask;
else
ssm2602->clk_out_pwr &= ~mask;
regmap_update_bits(ssm2602->regmap, SSM2602_PWR,
PWR_CLK_OUT_PDN | PWR_OSC_PDN, ssm2602->clk_out_pwr);
}
return 0;
}
static int ssm2602_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct ssm2602_priv *ssm2602 = snd_soc_codec_get_drvdata(codec_dai->codec);
unsigned int iface = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
iface |= 0x0040;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
iface |= 0x0002;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
iface |= 0x0001;
break;
case SND_SOC_DAIFMT_DSP_A:
iface |= 0x0013;
break;
case SND_SOC_DAIFMT_DSP_B:
iface |= 0x0003;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
iface |= 0x0090;
break;
case SND_SOC_DAIFMT_IB_NF:
iface |= 0x0080;
break;
case SND_SOC_DAIFMT_NB_IF:
iface |= 0x0010;
break;
default:
return -EINVAL;
}
regmap_write(ssm2602->regmap, SSM2602_IFACE, iface);
return 0;
}
static int ssm2602_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct ssm2602_priv *ssm2602 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
regmap_update_bits(ssm2602->regmap, SSM2602_PWR,
PWR_POWER_OFF | PWR_CLK_OUT_PDN | PWR_OSC_PDN,
ssm2602->clk_out_pwr);
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
regmap_update_bits(ssm2602->regmap, SSM2602_PWR,
PWR_POWER_OFF | PWR_CLK_OUT_PDN | PWR_OSC_PDN,
PWR_CLK_OUT_PDN | PWR_OSC_PDN);
break;
case SND_SOC_BIAS_OFF:
regmap_update_bits(ssm2602->regmap, SSM2602_PWR,
PWR_POWER_OFF, PWR_POWER_OFF);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int ssm2602_suspend(struct snd_soc_codec *codec)
{
ssm2602_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int ssm2602_resume(struct snd_soc_codec *codec)
{
struct ssm2602_priv *ssm2602 = snd_soc_codec_get_drvdata(codec);
regcache_sync(ssm2602->regmap);
ssm2602_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int ssm2602_codec_probe(struct snd_soc_codec *codec)
{
struct ssm2602_priv *ssm2602 = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret;
regmap_update_bits(ssm2602->regmap, SSM2602_LOUT1V,
LOUT1V_LRHP_BOTH, LOUT1V_LRHP_BOTH);
regmap_update_bits(ssm2602->regmap, SSM2602_ROUT1V,
ROUT1V_RLHP_BOTH, ROUT1V_RLHP_BOTH);
ret = snd_soc_add_codec_controls(codec, ssm2602_snd_controls,
ARRAY_SIZE(ssm2602_snd_controls));
if (ret)
return ret;
ret = snd_soc_dapm_new_controls(dapm, ssm2602_dapm_widgets,
ARRAY_SIZE(ssm2602_dapm_widgets));
if (ret)
return ret;
return snd_soc_dapm_add_routes(dapm, ssm2602_routes,
ARRAY_SIZE(ssm2602_routes));
}
static int ssm2604_codec_probe(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret;
ret = snd_soc_dapm_new_controls(dapm, ssm2604_dapm_widgets,
ARRAY_SIZE(ssm2604_dapm_widgets));
if (ret)
return ret;
return snd_soc_dapm_add_routes(dapm, ssm2604_routes,
ARRAY_SIZE(ssm2604_routes));
}
static int ssm260x_codec_probe(struct snd_soc_codec *codec)
{
struct ssm2602_priv *ssm2602 = snd_soc_codec_get_drvdata(codec);
int ret;
ret = regmap_write(ssm2602->regmap, SSM2602_RESET, 0);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset: %d\n", ret);
return ret;
}
regmap_update_bits(ssm2602->regmap, SSM2602_LINVOL,
LINVOL_LRIN_BOTH, LINVOL_LRIN_BOTH);
regmap_update_bits(ssm2602->regmap, SSM2602_RINVOL,
RINVOL_RLIN_BOTH, RINVOL_RLIN_BOTH);
regmap_write(ssm2602->regmap, SSM2602_APANA, APANA_SELECT_DAC |
APANA_ENABLE_MIC_BOOST);
switch (ssm2602->type) {
case SSM2602:
ret = ssm2602_codec_probe(codec);
break;
case SSM2604:
ret = ssm2604_codec_probe(codec);
break;
}
if (ret)
return ret;
ssm2602_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int ssm2602_remove(struct snd_soc_codec *codec)
{
ssm2602_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static bool ssm2602_register_volatile(struct device *dev, unsigned int reg)
{
return reg == SSM2602_RESET;
}
int ssm2602_probe(struct device *dev, enum ssm2602_type type,
struct regmap *regmap)
{
struct ssm2602_priv *ssm2602;
if (IS_ERR(regmap))
return PTR_ERR(regmap);
ssm2602 = devm_kzalloc(dev, sizeof(*ssm2602), GFP_KERNEL);
if (ssm2602 == NULL)
return -ENOMEM;
dev_set_drvdata(dev, ssm2602);
ssm2602->type = type;
ssm2602->regmap = regmap;
return snd_soc_register_codec(dev, &soc_codec_dev_ssm2602,
&ssm2602_dai, 1);
}
