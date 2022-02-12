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
mmcc |= MS_MASTER;
break;
case SND_SOC_DAIFMT_CBS_CFS:
mmcc &= ~MS_MASTER;
break;
default:
return -EINVAL;
}
format = (fmt & SND_SOC_DAIFMT_FORMAT_MASK);
inv = (fmt & SND_SOC_DAIFMT_INV_MASK);
switch (format) {
case SND_SOC_DAIFMT_I2S:
spc &= ~SPDIF_PCM;
break;
case SND_SOC_DAIFMT_DSP_A:
case SND_SOC_DAIFMT_DSP_B:
if (mmcc & MS_MASTER) {
dev_err(codec->dev,
"PCM format in slave mode only\n");
return -EINVAL;
}
if (id == CS42L73_ASP) {
dev_err(codec->dev,
"PCM format is not supported on ASP port\n");
return -EINVAL;
}
spc |= SPDIF_PCM;
break;
default:
return -EINVAL;
}
if (spc & SPDIF_PCM) {
spc &= ~(PCM_MODE_MASK | PCM_BIT_ORDER);
switch (format) {
case SND_SOC_DAIFMT_DSP_B:
if (inv == SND_SOC_DAIFMT_IB_IF)
spc |= PCM_MODE0;
if (inv == SND_SOC_DAIFMT_IB_NF)
spc |= PCM_MODE1;
break;
case SND_SOC_DAIFMT_DSP_A:
if (inv == SND_SOC_DAIFMT_IB_IF)
spc |= PCM_MODE1;
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
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct cs42l73_private *priv = snd_soc_codec_get_drvdata(codec);
int id = dai->id;
int mclk_coeff;
int srate = params_rate(params);
if (priv->config[id].mmcc & MS_MASTER) {
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
priv->config[id].spc |= MCK_SCLK_MCLK;
} else {
priv->config[id].spc &= 0xFC;
priv->config[id].spc |= MCK_SCLK_64FS;
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
snd_soc_update_bits(codec, CS42L73_DMMCC, MCLKDIS, 0);
snd_soc_update_bits(codec, CS42L73_PWRCTL1, PDN, 0);
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
regcache_cache_only(cs42l73->regmap, false);
regcache_sync(cs42l73->regmap);
}
snd_soc_update_bits(codec, CS42L73_PWRCTL1, PDN, 1);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, CS42L73_PWRCTL1, PDN, 1);
snd_soc_update_bits(codec, CS42L73_DMMCC, MCLKDIS, 1);
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
int ret;
struct cs42l73_private *cs42l73 = snd_soc_codec_get_drvdata(codec);
codec->control_data = cs42l73->regmap;
ret = snd_soc_codec_set_cache_io(codec, 8, 8, SND_SOC_REGMAP);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
regcache_cache_only(cs42l73->regmap, true);
cs42l73_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
cs42l73->mclksel = CS42L73_CLKID_MCLK1;
cs42l73->mclk = 0;
return ret;
}
static int cs42l73_remove(struct snd_soc_codec *codec)
{
cs42l73_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static __devinit int cs42l73_i2c_probe(struct i2c_client *i2c_client,
const struct i2c_device_id *id)
{
struct cs42l73_private *cs42l73;
int ret;
unsigned int devid = 0;
unsigned int reg;
cs42l73 = devm_kzalloc(&i2c_client->dev, sizeof(struct cs42l73_private),
GFP_KERNEL);
if (!cs42l73) {
dev_err(&i2c_client->dev, "could not allocate codec\n");
return -ENOMEM;
}
i2c_set_clientdata(i2c_client, cs42l73);
cs42l73->regmap = regmap_init_i2c(i2c_client, &cs42l73_regmap);
if (IS_ERR(cs42l73->regmap)) {
ret = PTR_ERR(cs42l73->regmap);
dev_err(&i2c_client->dev, "regmap_init() failed: %d\n", ret);
goto err;
}
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
goto err_regmap;
}
ret = regmap_read(cs42l73->regmap, CS42L73_REVID, &reg);
if (ret < 0) {
dev_err(&i2c_client->dev, "Get Revision ID failed\n");
goto err_regmap;
}
dev_info(&i2c_client->dev,
"Cirrus Logic CS42L73, Revision: %02X\n", reg & 0xFF);
regcache_cache_only(cs42l73->regmap, true);
ret = snd_soc_register_codec(&i2c_client->dev,
&soc_codec_dev_cs42l73, cs42l73_dai,
ARRAY_SIZE(cs42l73_dai));
if (ret < 0)
goto err_regmap;
return 0;
err_regmap:
regmap_exit(cs42l73->regmap);
err:
return ret;
}
static __devexit int cs42l73_i2c_remove(struct i2c_client *client)
{
struct cs42l73_private *cs42l73 = i2c_get_clientdata(client);
snd_soc_unregister_codec(&client->dev);
regmap_exit(cs42l73->regmap);
return 0;
}
static int __init cs42l73_modinit(void)
{
int ret;
ret = i2c_add_driver(&cs42l73_i2c_driver);
if (ret != 0) {
pr_err("Failed to register CS42L73 I2C driver: %d\n", ret);
return ret;
}
return 0;
}
static void __exit cs42l73_exit(void)
{
i2c_del_driver(&cs42l73_i2c_driver);
}
