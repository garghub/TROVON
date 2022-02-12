static int es8316_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct es8316_priv *es8316 = snd_soc_codec_get_drvdata(codec);
int i;
int count = 0;
es8316->sysclk = freq;
if (freq == 0)
return 0;
for (i = 0; i < NR_SUPPORTED_MCLK_LRCK_RATIOS; i++) {
const unsigned int ratio = supported_mclk_lrck_ratios[i];
if (freq % ratio == 0)
es8316->allowed_rates[count++] = freq / ratio;
}
es8316->sysclk_constraints.list = es8316->allowed_rates;
es8316->sysclk_constraints.count = count;
return 0;
}
static int es8316_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u8 serdata1 = 0;
u8 serdata2 = 0;
u8 clksw;
u8 mask;
if ((fmt & SND_SOC_DAIFMT_MASTER_MASK) != SND_SOC_DAIFMT_CBS_CFS) {
dev_err(codec->dev, "Codec driver only supports slave mode\n");
return -EINVAL;
}
if ((fmt & SND_SOC_DAIFMT_FORMAT_MASK) != SND_SOC_DAIFMT_I2S) {
dev_err(codec->dev, "Codec driver only supports I2S format\n");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
serdata1 |= ES8316_SERDATA1_BCLK_INV;
serdata2 |= ES8316_SERDATA2_ADCLRP;
break;
case SND_SOC_DAIFMT_IB_NF:
serdata1 |= ES8316_SERDATA1_BCLK_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
serdata2 |= ES8316_SERDATA2_ADCLRP;
break;
default:
return -EINVAL;
}
mask = ES8316_SERDATA1_MASTER | ES8316_SERDATA1_BCLK_INV;
snd_soc_update_bits(codec, ES8316_SERDATA1, mask, serdata1);
mask = ES8316_SERDATA2_FMT_MASK | ES8316_SERDATA2_ADCLRP;
snd_soc_update_bits(codec, ES8316_SERDATA_ADC, mask, serdata2);
snd_soc_update_bits(codec, ES8316_SERDATA_DAC, mask, serdata2);
clksw = ES8316_CLKMGR_CLKSW_MCLK_ON | ES8316_CLKMGR_CLKSW_BCLK_ON;
snd_soc_update_bits(codec, ES8316_CLKMGR_CLKSW, clksw, clksw);
return 0;
}
static int es8316_pcm_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct es8316_priv *es8316 = snd_soc_codec_get_drvdata(codec);
if (es8316->sysclk == 0) {
dev_err(codec->dev, "No sysclk provided\n");
return -EINVAL;
}
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&es8316->sysclk_constraints);
return 0;
}
static int es8316_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct es8316_priv *es8316 = snd_soc_codec_get_drvdata(codec);
u8 wordlen = 0;
if (!es8316->sysclk) {
dev_err(codec->dev, "No MCLK configured\n");
return -EINVAL;
}
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
wordlen = ES8316_SERDATA2_LEN_16;
break;
case SNDRV_PCM_FORMAT_S20_3LE:
wordlen = ES8316_SERDATA2_LEN_20;
break;
case SNDRV_PCM_FORMAT_S24_LE:
wordlen = ES8316_SERDATA2_LEN_24;
break;
case SNDRV_PCM_FORMAT_S32_LE:
wordlen = ES8316_SERDATA2_LEN_32;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, ES8316_SERDATA_DAC,
ES8316_SERDATA2_LEN_MASK, wordlen);
snd_soc_update_bits(codec, ES8316_SERDATA_ADC,
ES8316_SERDATA2_LEN_MASK, wordlen);
return 0;
}
static int es8316_mute(struct snd_soc_dai *dai, int mute)
{
snd_soc_update_bits(dai->codec, ES8316_DAC_SET1, 0x20,
mute ? 0x20 : 0);
return 0;
}
static int es8316_probe(struct snd_soc_codec *codec)
{
snd_soc_write(codec, ES8316_RESET, 0x3f);
usleep_range(5000, 5500);
snd_soc_write(codec, ES8316_RESET, ES8316_RESET_CSM_ON);
msleep(30);
snd_soc_write(codec, ES8316_SYS_VMIDSEL, 0xff);
snd_soc_write(codec, ES8316_CLKMGR_ADCOSR, 0x32);
return 0;
}
static int es8316_i2c_probe(struct i2c_client *i2c_client,
const struct i2c_device_id *id)
{
struct es8316_priv *es8316;
struct regmap *regmap;
es8316 = devm_kzalloc(&i2c_client->dev, sizeof(struct es8316_priv),
GFP_KERNEL);
if (es8316 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c_client, es8316);
regmap = devm_regmap_init_i2c(i2c_client, &es8316_regmap);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
return snd_soc_register_codec(&i2c_client->dev, &soc_codec_dev_es8316,
&es8316_dai, 1);
}
static int es8316_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
