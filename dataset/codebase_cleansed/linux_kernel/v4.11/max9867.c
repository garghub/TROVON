static inline int get_ni_value(int mclk, int rate)
{
int i, ret = 0;
for (i = 0; i < ARRAY_SIZE(ni_div); i++) {
if (ni_div[i].mclk >= mclk)
break;
}
if (i == ARRAY_SIZE(ni_div))
return -EINVAL;
switch (rate) {
case 8000:
return ni_div[i].ni[pcm_rate_8];
case 16000:
return ni_div[i].ni[pcm_rate_16];
case 32000:
return ni_div[i].ni[pcm_rate_32];
case 44100:
return ni_div[i].ni[pcm_rate_44];
case 48000:
return ni_div[i].ni[pcm_rate_48];
default:
pr_err("%s wrong rate %d\n", __func__, rate);
ret = -EINVAL;
}
return ret;
}
static int max9867_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct max9867_priv *max9867 = snd_soc_codec_get_drvdata(codec);
unsigned int ni_h, ni_l;
int value;
value = get_ni_value(max9867->sysclk, params_rate(params));
if (value < 0)
return value;
ni_h = (0xFF00 & value) >> 8;
ni_l = 0x00FF & value;
regmap_update_bits(max9867->regmap, MAX9867_AUDIOCLKHIGH,
MAX9867_NI_HIGH_MASK, ni_h);
regmap_update_bits(max9867->regmap, MAX9867_AUDIOCLKLOW,
MAX9867_NI_LOW_MASK, ni_l);
if (!max9867->master) {
regmap_update_bits(max9867->regmap, MAX9867_AUDIOCLKLOW,
MAX9867_RAPID_LOCK, MAX9867_RAPID_LOCK);
regmap_update_bits(max9867->regmap, MAX9867_AUDIOCLKHIGH,
MAX9867_PLL, MAX9867_PLL);
} else {
unsigned long int bclk_rate, pclk_bclk_ratio;
int bclk_value;
bclk_rate = params_rate(params) * 2 * params_width(params);
pclk_bclk_ratio = max9867->pclk/bclk_rate;
switch (params_width(params)) {
case 8:
case 16:
switch (pclk_bclk_ratio) {
case 2:
bclk_value = MAX9867_IFC1B_PCLK_2;
break;
case 4:
bclk_value = MAX9867_IFC1B_PCLK_4;
break;
case 8:
bclk_value = MAX9867_IFC1B_PCLK_8;
break;
case 16:
bclk_value = MAX9867_IFC1B_PCLK_16;
break;
default:
dev_err(codec->dev,
"unsupported sampling rate\n");
return -EINVAL;
}
break;
case 24:
bclk_value = MAX9867_IFC1B_24BIT;
break;
case 32:
bclk_value = MAX9867_IFC1B_32BIT;
break;
default:
dev_err(codec->dev, "unsupported sampling rate\n");
return -EINVAL;
}
regmap_update_bits(max9867->regmap, MAX9867_IFC1B,
MAX9867_IFC1B_BCLK_MASK, bclk_value);
}
return 0;
}
static int max9867_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct max9867_priv *max9867 = snd_soc_codec_get_drvdata(codec);
regmap_update_bits(max9867->regmap, MAX9867_PWRMAN,
MAX9867_SHTDOWN_MASK, MAX9867_SHTDOWN_MASK);
return 0;
}
static int max9867_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
struct max9867_priv *max9867 = snd_soc_codec_get_drvdata(codec);
if (mute)
regmap_update_bits(max9867->regmap, MAX9867_DACLEVEL,
MAX9867_DAC_MUTE_MASK, MAX9867_DAC_MUTE_MASK);
else
regmap_update_bits(max9867->regmap, MAX9867_DACLEVEL,
MAX9867_DAC_MUTE_MASK, 0);
return 0;
}
static int max9867_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct max9867_priv *max9867 = snd_soc_codec_get_drvdata(codec);
int value = 0;
if (freq >= 10000000 && freq <= 20000000) {
value |= MAX9867_PSCLK_10_20;
max9867->pclk = freq;
} else if (freq >= 20000000 && freq <= 40000000) {
value |= MAX9867_PSCLK_20_40;
max9867->pclk = freq/2;
} else if (freq >= 40000000 && freq <= 60000000) {
value |= MAX9867_PSCLK_40_60;
max9867->pclk = freq/4;
} else {
pr_err("bad clock frequency %d", freq);
return -EINVAL;
}
value = value << MAX9867_PSCLK_SHIFT;
max9867->sysclk = freq;
value &= ~MAX9867_FREQ_MASK;
regmap_update_bits(max9867->regmap, MAX9867_SYSCLK,
MAX9867_PSCLK_MASK, value);
return 0;
}
static int max9867_dai_set_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct max9867_priv *max9867 = snd_soc_codec_get_drvdata(codec);
u8 iface1A = 0, iface1B = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
max9867->master = 1;
iface1A |= MAX9867_MASTER;
break;
case SND_SOC_DAIFMT_CBS_CFS:
max9867->master = 0;
iface1A &= ~MAX9867_MASTER;
break;
default:
return -EINVAL;
}
iface1A |= MAX9867_I2S_DLY;
iface1A |= MAX9867_SDOUT_HIZ;
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
iface1A |= MAX9867_WCI_MODE | MAX9867_BCI_MODE;
break;
case SND_SOC_DAIFMT_IB_NF:
iface1A |= MAX9867_BCI_MODE;
break;
case SND_SOC_DAIFMT_NB_IF:
iface1A |= MAX9867_WCI_MODE;
break;
default:
return -EINVAL;
}
regmap_write(max9867->regmap, MAX9867_IFC1A, iface1A);
regmap_write(max9867->regmap, MAX9867_IFC1B, iface1B);
return 0;
}
static int max9867_suspend(struct device *dev)
{
struct max9867_priv *max9867 = dev_get_drvdata(dev);
regmap_update_bits(max9867->regmap, MAX9867_PWRMAN,
MAX9867_SHTDOWN_MASK, ~MAX9867_SHTDOWN_MASK);
return 0;
}
static int max9867_resume(struct device *dev)
{
struct max9867_priv *max9867 = dev_get_drvdata(dev);
regmap_update_bits(max9867->regmap, MAX9867_PWRMAN,
MAX9867_SHTDOWN_MASK, MAX9867_SHTDOWN_MASK);
return 0;
}
static int max9867_probe(struct snd_soc_codec *codec)
{
struct max9867_priv *max9867 = snd_soc_codec_get_drvdata(codec);
dev_dbg(codec->dev, "max98090_probe\n");
max9867->codec = codec;
return 0;
}
static bool max9867_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX9867_STATUS:
case MAX9867_JACKSTATUS:
case MAX9867_AUXHIGH:
case MAX9867_AUXLOW:
return true;
default:
return false;
}
}
static int max9867_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct max9867_priv *max9867;
int ret = 0, reg;
max9867 = devm_kzalloc(&i2c->dev,
sizeof(*max9867), GFP_KERNEL);
if (!max9867)
return -ENOMEM;
i2c_set_clientdata(i2c, max9867);
max9867->regmap = devm_regmap_init_i2c(i2c, &max9867_regmap);
if (IS_ERR(max9867->regmap)) {
ret = PTR_ERR(max9867->regmap);
dev_err(&i2c->dev,
"Failed to allocate regmap: %d\n", ret);
return ret;
}
ret = regmap_read(max9867->regmap,
MAX9867_REVISION, &reg);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to read: %d\n", ret);
return ret;
}
dev_info(&i2c->dev, "device revision: %x\n", reg);
ret = snd_soc_register_codec(&i2c->dev, &max9867_codec,
max9867_dai, ARRAY_SIZE(max9867_dai));
if (ret < 0) {
dev_err(&i2c->dev, "Failed to register codec: %d\n", ret);
return ret;
}
return ret;
}
static int max9867_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
