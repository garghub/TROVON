static bool cs42l73_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS42L73_IS1:
case CS42L73_IS2:
return true;
default:
return false;
}
}
static bool cs42l73_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS42L73_DEVID_AB:
case CS42L73_DEVID_CD:
case CS42L73_DEVID_E:
case CS42L73_REVID:
case CS42L73_PWRCTL1:
case CS42L73_PWRCTL2:
case CS42L73_PWRCTL3:
case CS42L73_CPFCHC:
case CS42L73_OLMBMSDC:
case CS42L73_DMMCC:
case CS42L73_XSPC:
case CS42L73_XSPMMCC:
case CS42L73_ASPC:
case CS42L73_ASPMMCC:
case CS42L73_VSPC:
case CS42L73_VSPMMCC:
case CS42L73_VXSPFS:
case CS42L73_MIOPC:
case CS42L73_ADCIPC:
case CS42L73_MICAPREPGAAVOL:
case CS42L73_MICBPREPGABVOL:
case CS42L73_IPADVOL:
case CS42L73_IPBDVOL:
case CS42L73_PBDC:
case CS42L73_HLADVOL:
case CS42L73_HLBDVOL:
case CS42L73_SPKDVOL:
case CS42L73_ESLDVOL:
case CS42L73_HPAAVOL:
case CS42L73_HPBAVOL:
case CS42L73_LOAAVOL:
case CS42L73_LOBAVOL:
case CS42L73_STRINV:
case CS42L73_XSPINV:
case CS42L73_ASPINV:
case CS42L73_VSPINV:
case CS42L73_LIMARATEHL:
case CS42L73_LIMRRATEHL:
case CS42L73_LMAXHL:
case CS42L73_LIMARATESPK:
case CS42L73_LIMRRATESPK:
case CS42L73_LMAXSPK:
case CS42L73_LIMARATEESL:
case CS42L73_LIMRRATEESL:
case CS42L73_LMAXESL:
case CS42L73_ALCARATE:
case CS42L73_ALCRRATE:
case CS42L73_ALCMINMAX:
case CS42L73_NGCAB:
case CS42L73_ALCNGMC:
case CS42L73_MIXERCTL:
case CS42L73_HLAIPAA:
case CS42L73_HLBIPBA:
case CS42L73_HLAXSPAA:
case CS42L73_HLBXSPBA:
case CS42L73_HLAASPAA:
case CS42L73_HLBASPBA:
case CS42L73_HLAVSPMA:
case CS42L73_HLBVSPMA:
case CS42L73_XSPAIPAA:
case CS42L73_XSPBIPBA:
case CS42L73_XSPAXSPAA:
case CS42L73_XSPBXSPBA:
case CS42L73_XSPAASPAA:
case CS42L73_XSPAASPBA:
case CS42L73_XSPAVSPMA:
case CS42L73_XSPBVSPMA:
case CS42L73_ASPAIPAA:
case CS42L73_ASPBIPBA:
case CS42L73_ASPAXSPAA:
case CS42L73_ASPBXSPBA:
case CS42L73_ASPAASPAA:
case CS42L73_ASPBASPBA:
case CS42L73_ASPAVSPMA:
case CS42L73_ASPBVSPMA:
case CS42L73_VSPAIPAA:
case CS42L73_VSPBIPBA:
case CS42L73_VSPAXSPAA:
case CS42L73_VSPBXSPBA:
case CS42L73_VSPAASPAA:
case CS42L73_VSPBASPBA:
case CS42L73_VSPAVSPMA:
case CS42L73_VSPBVSPMA:
case CS42L73_MMIXCTL:
case CS42L73_SPKMIPMA:
case CS42L73_SPKMXSPA:
case CS42L73_SPKMASPA:
case CS42L73_SPKMVSPMA:
case CS42L73_ESLMIPMA:
case CS42L73_ESLMXSPA:
case CS42L73_ESLMASPA:
case CS42L73_ESLMVSPMA:
case CS42L73_IM1:
case CS42L73_IM2:
return true;
default:
return false;
}
}
static int cs42l73_spklo_spk_amp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct cs42l73_private *priv = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMD:
priv->shutdwn_delay = 150;
break;
default:
pr_err("Invalid event = 0x%x\n", event);
}
return 0;
}
static int cs42l73_ear_amp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct cs42l73_private *priv = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMD:
if (priv->shutdwn_delay < 50)
priv->shutdwn_delay = 50;
break;
default:
pr_err("Invalid event = 0x%x\n", event);
}
return 0;
}
static int cs42l73_hp_amp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct cs42l73_private *priv = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMD:
if (priv->shutdwn_delay < 30)
priv->shutdwn_delay = 30;
break;
default:
pr_err("Invalid event = 0x%x\n", event);
}
return 0;
}
static int cs42l73_get_mclkx_coeff(int mclkx)
{
int i;
for (i = 0; i < ARRAY_SIZE(cs42l73_mclkx_coeffs); i++) {
if (cs42l73_mclkx_coeffs[i].mclkx == mclkx)
return i;
}
return -EINVAL;
}
static int cs42l73_get_mclk_coeff(int mclk, int srate)
{
int i;
for (i = 0; i < ARRAY_SIZE(cs42l73_mclk_coeffs); i++) {
if (cs42l73_mclk_coeffs[i].mclk == mclk &&
cs42l73_mclk_coeffs[i].srate == srate)
return i;
}
return -EINVAL;
}
static int cs42l73_set_mclk(struct snd_soc_dai *dai, unsigned int freq)
{
struct snd_soc_codec *codec = dai->codec;
struct cs42l73_private *priv = snd_soc_codec_get_drvdata(codec);
int mclkx_coeff;
u32 mclk = 0;
u8 dmmcc = 0;
mclkx_coeff = cs42l73_get_mclkx_coeff(freq);
if (mclkx_coeff < 0)
return mclkx_coeff;
mclk = cs42l73_mclkx_coeffs[mclkx_coeff].mclkx /
cs42l73_mclkx_coeffs[mclkx_coeff].ratio;
dev_dbg(codec->dev, "MCLK%u %u <-> internal MCLK %u\n",
priv->mclksel + 1, cs42l73_mclkx_coeffs[mclkx_coeff].mclkx,
mclk);
dmmcc = (priv->mclksel << 4) |
(cs42l73_mclkx_coeffs[mclkx_coeff].mclkdiv << 1);
snd_soc_write(codec, CS42L73_DMMCC, dmmcc);
priv->sysclk = mclkx_coeff;
priv->mclk = mclk;
return 0;
}
static int cs42l73_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct cs42l73_private *priv = snd_soc_codec_get_drvdata(codec);
switch (clk_id) {
case CS42L73_CLKID_MCLK1:
break;
case CS42L73_CLKID_MCLK2:
break;
default:
return -EINVAL;
}
if ((cs42l73_set_mclk(dai, freq)) < 0) {
dev_err(codec->dev, "Unable to set MCLK for dai %s\n",
dai->name);
return -EINVAL;
}
priv->mclksel = clk_id;
return 0;
}
static int cs42l73_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct cs42l73_private *priv = snd_soc_codec_get_drvdata(codec);
u8 id = codec_dai->id;
unsigned int inv, format;
u8 spc, mmcc;
spc = snd_soc_read(codec, CS42L73_SPC(id));
mmcc = snd_soc_read(codec, CS42L73_MMCC(id));
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
mmcc |= CS42L73_MS_MASTER;
break;
case SND_SOC_DAIFMT_CBS_CFS:
mmcc &= ~CS42L73_MS_MASTER;
break;
default:
return -EINVAL;
}
format = (fmt & SND_SOC_DAIFMT_FORMAT_MASK);
inv = (fmt & SND_SOC_DAIFMT_INV_MASK);
switch (format) {
case SND_SOC_DAIFMT_I2S:
spc &= ~CS42L73_SPDIF_PCM;
break;
case SND_SOC_DAIFMT_DSP_A:
case SND_SOC_DAIFMT_DSP_B:
if (mmcc & CS42L73_MS_MASTER) {
dev_err(codec->dev,
"PCM format in slave mode only\n");
return -EINVAL;
}
if (id == CS42L73_ASP) {
dev_err(codec->dev,
"PCM format is not supported on ASP port\n");
return -EINVAL;
}
spc |= CS42L73_SPDIF_PCM;
break;
default:
return -EINVAL;
}
if (spc & CS42L73_SPDIF_PCM) {
spc &= ~(CS42L73_PCM_MODE_MASK | CS42L73_PCM_BIT_ORDER);
switch (format) {
case SND_SOC_DAIFMT_DSP_B:
if (inv == SND_SOC_DAIFMT_IB_IF)
spc |= CS42L73_PCM_MODE0;
if (inv == SND_SOC_DAIFMT_IB_NF)
spc |= CS42L73_PCM_MODE1;
break;
case SND_SOC_DAIFMT_DSP_A:
if (inv == SND_SOC_DAIFMT_IB_IF)
spc |= CS42L73_PCM_MODE1;
break;
default:
return -EINVAL;
}
}
priv->config[id].spc = spc;
priv->config[id].mmcc = mmcc;
return 0;
}
static unsigned int cs42l73_get_xspfs_coeff(u32 rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(cs42l73_asrc_rates); i++) {
if (cs42l73_asrc_rates[i] == rate)
return i + 1;
}
return 0;
}
static void cs42l73_update_asrc(struct snd_soc_codec *codec, int id, int srate)
{
u8 spfs = 0;
if (srate > 0)
spfs = cs42l73_get_xspfs_coeff(srate);
switch (id) {
case CS42L73_XSP:
snd_soc_update_bits(codec, CS42L73_VXSPFS, 0x0f, spfs);
break;
case CS42L73_ASP:
snd_soc_update_bits(codec, CS42L73_ASPC, 0x3c, spfs << 2);
break;
case CS42L73_VSP:
snd_soc_update_bits(codec, CS42L73_VXSPFS, 0xf0, spfs << 4);
break;
default:
break;
}
}
static int cs42l73_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct cs42l73_private *priv = snd_soc_codec_get_drvdata(codec);
int id = dai->id;
int mclk_coeff;
int srate = params_rate(params);
if (priv->config[id].mmcc & CS42L73_MS_MASTER) {
mclk_coeff =
cs42l73_get_mclk_coeff(priv->mclk, srate);
if (mclk_coeff < 0)
return -EINVAL;
dev_dbg(codec->dev,
"DAI[%d]: MCLK %u, srate %u, MMCC[5:0] = %x\n",
id, priv->mclk, srate,
cs42l73_mclk_coeffs[mclk_coeff].mmcc);
priv->config[id].mmcc &= 0xC0;
priv->config[id].mmcc |= cs42l73_mclk_coeffs[mclk_coeff].mmcc;
priv->config[id].spc &= 0xFC;
if (priv->mclk >= 6400000)
priv->config[id].spc |= CS42L73_MCK_SCLK_64FS;
else
priv->config[id].spc |= CS42L73_MCK_SCLK_MCLK;
} else {
priv->config[id].spc &= 0xFC;
priv->config[id].spc |= CS42L73_MCK_SCLK_64FS;
}
priv->config[id].srate = srate;
snd_soc_write(codec, CS42L73_SPC(id), priv->config[id].spc);
snd_soc_write(codec, CS42L73_MMCC(id), priv->config[id].mmcc);
cs42l73_update_asrc(codec, id, srate);
return 0;
}
static int cs42l73_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct cs42l73_private *cs42l73 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
snd_soc_update_bits(codec, CS42L73_DMMCC, CS42L73_MCLKDIS, 0);
snd_soc_update_bits(codec, CS42L73_PWRCTL1, CS42L73_PDN, 0);
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
regcache_cache_only(cs42l73->regmap, false);
regcache_sync(cs42l73->regmap);
}
snd_soc_update_bits(codec, CS42L73_PWRCTL1, CS42L73_PDN, 1);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, CS42L73_PWRCTL1, CS42L73_PDN, 1);
if (cs42l73->shutdwn_delay > 0) {
mdelay(cs42l73->shutdwn_delay);
cs42l73->shutdwn_delay = 0;
} else {
mdelay(15);
}
snd_soc_update_bits(codec, CS42L73_DMMCC, CS42L73_MCLKDIS, 1);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int cs42l73_set_tristate(struct snd_soc_dai *dai, int tristate)
{
struct snd_soc_codec *codec = dai->codec;
int id = dai->id;
return snd_soc_update_bits(codec, CS42L73_SPC(id),
0x7F, tristate << 7);
}
static int cs42l73_pcm_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&constraints_12_24);
return 0;
}
static int cs42l73_suspend(struct snd_soc_codec *codec)
{
cs42l73_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int cs42l73_resume(struct snd_soc_codec *codec)
{
cs42l73_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int cs42l73_probe(struct snd_soc_codec *codec)
{
struct cs42l73_private *cs42l73 = snd_soc_codec_get_drvdata(codec);
cs42l73_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
if (cs42l73->pdata.chgfreq)
snd_soc_update_bits(codec, CS42L73_CPFCHC,
CS42L73_CHARGEPUMP_MASK,
cs42l73->pdata.chgfreq << 4);
cs42l73->mclksel = CS42L73_CLKID_MCLK1;
cs42l73->mclk = 0;
return 0;
}
static int cs42l73_remove(struct snd_soc_codec *codec)
{
cs42l73_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int cs42l73_i2c_probe(struct i2c_client *i2c_client,
const struct i2c_device_id *id)
{
struct cs42l73_private *cs42l73;
struct cs42l73_platform_data *pdata = dev_get_platdata(&i2c_client->dev);
int ret;
unsigned int devid = 0;
unsigned int reg;
u32 val32;
cs42l73 = devm_kzalloc(&i2c_client->dev, sizeof(struct cs42l73_private),
GFP_KERNEL);
if (!cs42l73)
return -ENOMEM;
cs42l73->regmap = devm_regmap_init_i2c(i2c_client, &cs42l73_regmap);
if (IS_ERR(cs42l73->regmap)) {
ret = PTR_ERR(cs42l73->regmap);
dev_err(&i2c_client->dev, "regmap_init() failed: %d\n", ret);
return ret;
}
if (pdata) {
cs42l73->pdata = *pdata;
} else {
pdata = devm_kzalloc(&i2c_client->dev,
sizeof(struct cs42l73_platform_data),
GFP_KERNEL);
if (!pdata) {
dev_err(&i2c_client->dev, "could not allocate pdata\n");
return -ENOMEM;
}
if (i2c_client->dev.of_node) {
if (of_property_read_u32(i2c_client->dev.of_node,
"chgfreq", &val32) >= 0)
pdata->chgfreq = val32;
}
pdata->reset_gpio = of_get_named_gpio(i2c_client->dev.of_node,
"reset-gpio", 0);
cs42l73->pdata = *pdata;
}
i2c_set_clientdata(i2c_client, cs42l73);
if (cs42l73->pdata.reset_gpio) {
ret = devm_gpio_request_one(&i2c_client->dev,
cs42l73->pdata.reset_gpio,
GPIOF_OUT_INIT_HIGH,
"CS42L73 /RST");
if (ret < 0) {
dev_err(&i2c_client->dev, "Failed to request /RST %d: %d\n",
cs42l73->pdata.reset_gpio, ret);
return ret;
}
gpio_set_value_cansleep(cs42l73->pdata.reset_gpio, 0);
gpio_set_value_cansleep(cs42l73->pdata.reset_gpio, 1);
}
regcache_cache_bypass(cs42l73->regmap, true);
ret = regmap_read(cs42l73->regmap, CS42L73_DEVID_AB, &reg);
devid = (reg & 0xFF) << 12;
ret = regmap_read(cs42l73->regmap, CS42L73_DEVID_CD, &reg);
devid |= (reg & 0xFF) << 4;
ret = regmap_read(cs42l73->regmap, CS42L73_DEVID_E, &reg);
devid |= (reg & 0xF0) >> 4;
if (devid != CS42L73_DEVID) {
ret = -ENODEV;
dev_err(&i2c_client->dev,
"CS42L73 Device ID (%X). Expected %X\n",
devid, CS42L73_DEVID);
return ret;
}
ret = regmap_read(cs42l73->regmap, CS42L73_REVID, &reg);
if (ret < 0) {
dev_err(&i2c_client->dev, "Get Revision ID failed\n");
return ret;;
}
dev_info(&i2c_client->dev,
"Cirrus Logic CS42L73, Revision: %02X\n", reg & 0xFF);
regcache_cache_bypass(cs42l73->regmap, false);
ret = snd_soc_register_codec(&i2c_client->dev,
&soc_codec_dev_cs42l73, cs42l73_dai,
ARRAY_SIZE(cs42l73_dai));
if (ret < 0)
return ret;
return 0;
}
static int cs42l73_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
