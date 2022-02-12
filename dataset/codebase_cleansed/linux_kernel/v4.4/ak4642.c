static int ak4642_lout_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_PRE_PMD:
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec, SG_SL2, LOPS, LOPS);
break;
case SND_SOC_DAPM_POST_PMU:
case SND_SOC_DAPM_POST_PMD:
mdelay(300);
snd_soc_update_bits(codec, SG_SL2, LOPS, 0);
break;
}
return 0;
}
static int ak4642_dai_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
int is_play = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
struct snd_soc_codec *codec = dai->codec;
if (is_play) {
snd_soc_write(codec, L_IVC, 0x91);
snd_soc_write(codec, R_IVC, 0x91);
} else {
snd_soc_update_bits(codec, SG_SL1, PMMP | MGAIN0, PMMP | MGAIN0);
snd_soc_write(codec, TIMER, ZTM(0x3) | WTM(0x3));
snd_soc_write(codec, ALC_CTL1, ALC | LMTH0);
snd_soc_update_bits(codec, PW_MGMT1, PMADL, PMADL);
snd_soc_update_bits(codec, PW_MGMT3, PMADR, PMADR);
}
return 0;
}
static void ak4642_dai_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
int is_play = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
struct snd_soc_codec *codec = dai->codec;
if (is_play) {
} else {
snd_soc_update_bits(codec, PW_MGMT1, PMADL, 0);
snd_soc_update_bits(codec, PW_MGMT3, PMADR, 0);
snd_soc_update_bits(codec, ALC_CTL1, ALC, 0);
}
}
static int ak4642_dai_set_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct ak4642_priv *priv = snd_soc_codec_get_drvdata(codec);
u8 pll;
int extended_freq = 0;
switch (freq) {
case 11289600:
pll = PLL2;
break;
case 12288000:
pll = PLL2 | PLL0;
break;
case 12000000:
pll = PLL2 | PLL1;
break;
case 24000000:
pll = PLL2 | PLL1 | PLL0;
break;
case 13500000:
pll = PLL3 | PLL2;
break;
case 27000000:
pll = PLL3 | PLL2 | PLL0;
break;
case 19200000:
pll = PLL3;
extended_freq = 1;
break;
case 13000000:
pll = PLL3 | PLL2 | PLL1;
extended_freq = 1;
break;
case 26000000:
pll = PLL3 | PLL2 | PLL1 | PLL0;
extended_freq = 1;
break;
default:
return -EINVAL;
}
if (extended_freq && !priv->drvdata->extended_frequencies)
return -EINVAL;
snd_soc_update_bits(codec, MD_CTL1, PLL_MASK, pll);
return 0;
}
static int ak4642_dai_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
u8 data;
u8 bcko;
data = MCKO | PMPLL;
bcko = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
data |= MS;
bcko = BCKO_64;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, PW_MGMT2, MS | MCKO | PMPLL, data);
snd_soc_update_bits(codec, MD_CTL1, BCKO_MASK, bcko);
data = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_LEFT_J:
data = LEFT_J;
break;
case SND_SOC_DAIFMT_I2S:
data = I2S;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, MD_CTL1, DIF_MASK, data);
return 0;
}
static int ak4642_set_mcko(struct snd_soc_codec *codec,
u32 frequency)
{
u32 fs_list[] = {
[0] = 8000,
[1] = 12000,
[2] = 16000,
[3] = 24000,
[4] = 7350,
[5] = 11025,
[6] = 14700,
[7] = 22050,
[10] = 32000,
[11] = 48000,
[14] = 29400,
[15] = 44100,
};
u32 ps_list[] = {
[0] = 256,
[1] = 128,
[2] = 64,
[3] = 32
};
int ps, fs;
for (ps = 0; ps < ARRAY_SIZE(ps_list); ps++) {
for (fs = 0; fs < ARRAY_SIZE(fs_list); fs++) {
if (frequency == ps_list[ps] * fs_list[fs]) {
snd_soc_write(codec, MD_CTL2,
PSs(ps) | FSs(fs));
return 0;
}
}
}
return 0;
}
static int ak4642_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct ak4642_priv *priv = snd_soc_codec_get_drvdata(codec);
u32 rate = clk_get_rate(priv->mcko);
if (!rate)
rate = params_rate(params) * 256;
return ak4642_set_mcko(codec, rate);
}
static int ak4642_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, PW_MGMT1, 0x00);
break;
default:
snd_soc_update_bits(codec, PW_MGMT1, PMVCM, PMVCM);
break;
}
return 0;
}
static int ak4642_resume(struct snd_soc_codec *codec)
{
struct regmap *regmap = dev_get_regmap(codec->dev, NULL);
regcache_mark_dirty(regmap);
regcache_sync(regmap);
return 0;
}
static int ak4642_probe(struct snd_soc_codec *codec)
{
struct ak4642_priv *priv = snd_soc_codec_get_drvdata(codec);
if (priv->mcko)
ak4642_set_mcko(codec, clk_get_rate(priv->mcko));
return 0;
}
static struct clk *ak4642_of_parse_mcko(struct device *dev)
{
struct device_node *np = dev->of_node;
struct clk *clk;
const char *clk_name = np->name;
const char *parent_clk_name = NULL;
u32 rate;
if (of_property_read_u32(np, "clock-frequency", &rate))
return NULL;
if (of_property_read_bool(np, "clocks"))
parent_clk_name = of_clk_get_parent_name(np, 0);
of_property_read_string(np, "clock-output-names", &clk_name);
clk = clk_register_fixed_rate(dev, clk_name, parent_clk_name,
(parent_clk_name) ? 0 : CLK_IS_ROOT,
rate);
if (!IS_ERR(clk))
of_clk_add_provider(np, of_clk_src_simple_get, clk);
return clk;
}
static int ak4642_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct device *dev = &i2c->dev;
struct device_node *np = dev->of_node;
const struct ak4642_drvdata *drvdata = NULL;
struct regmap *regmap;
struct ak4642_priv *priv;
struct clk *mcko = NULL;
if (np) {
const struct of_device_id *of_id;
mcko = ak4642_of_parse_mcko(dev);
if (IS_ERR(mcko))
mcko = NULL;
of_id = of_match_device(ak4642_of_match, dev);
if (of_id)
drvdata = of_id->data;
} else {
drvdata = (const struct ak4642_drvdata *)id->driver_data;
}
if (!drvdata) {
dev_err(dev, "Unknown device type\n");
return -EINVAL;
}
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->drvdata = drvdata;
priv->mcko = mcko;
i2c_set_clientdata(i2c, priv);
regmap = devm_regmap_init_i2c(i2c, drvdata->regmap_config);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
return snd_soc_register_codec(dev,
&soc_codec_dev_ak4642, &ak4642_dai, 1);
}
static int ak4642_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
