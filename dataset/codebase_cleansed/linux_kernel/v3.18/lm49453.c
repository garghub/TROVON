static int lm49453_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct lm49453_priv *lm49453 = snd_soc_codec_get_drvdata(codec);
u16 clk_div = 0;
lm49453->fs_rate = params_rate(params);
switch (lm49453->fs_rate) {
case 8000:
case 16000:
case 32000:
case 24000:
case 48000:
clk_div = 256;
break;
case 11025:
case 22050:
case 44100:
clk_div = 216;
break;
case 96000:
clk_div = 127;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, LM49453_P0_ADC_CLK_DIV_REG, clk_div);
snd_soc_write(codec, LM49453_P0_DAC_HP_CLK_DIV_REG, clk_div);
return 0;
}
static int lm49453_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 aif_val;
int mode = 0;
int clk_phase = 0;
int clk_shift = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
aif_val = 0;
break;
case SND_SOC_DAIFMT_CBS_CFM:
aif_val = LM49453_AUDIO_PORT1_BASIC_SYNC_MS;
break;
case SND_SOC_DAIFMT_CBM_CFS:
aif_val = LM49453_AUDIO_PORT1_BASIC_CLK_MS;
break;
case SND_SOC_DAIFMT_CBM_CFM:
aif_val = LM49453_AUDIO_PORT1_BASIC_CLK_MS |
LM49453_AUDIO_PORT1_BASIC_SYNC_MS;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
break;
case SND_SOC_DAIFMT_DSP_A:
mode = 1;
clk_phase = (1 << 5);
clk_shift = 1;
break;
case SND_SOC_DAIFMT_DSP_B:
mode = 1;
clk_phase = (1 << 5);
clk_shift = 0;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, LM49453_P0_AUDIO_PORT1_BASIC_REG,
LM49453_AUDIO_PORT1_BASIC_FMT_MASK|BIT(0)|BIT(5),
(aif_val | mode | clk_phase));
snd_soc_write(codec, LM49453_P0_AUDIO_PORT1_RX_MSB_REG, clk_shift);
return 0;
}
static int lm49453_set_dai_sysclk(struct snd_soc_dai *dai, int clk_id,
unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
u16 pll_clk = 0;
switch (freq) {
case 12288000:
case 26000000:
case 19200000:
pll_clk = 0;
break;
case 48000:
case 32576:
pll_clk = BIT(4);
return 0;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, LM49453_P0_PMC_SETUP_REG, BIT(4), pll_clk);
return 0;
}
static int lm49453_hp_mute(struct snd_soc_dai *dai, int mute)
{
snd_soc_update_bits(dai->codec, LM49453_P0_DAC_DSP_REG, BIT(1)|BIT(0),
(mute ? (BIT(1)|BIT(0)) : 0));
return 0;
}
static int lm49453_lo_mute(struct snd_soc_dai *dai, int mute)
{
snd_soc_update_bits(dai->codec, LM49453_P0_DAC_DSP_REG, BIT(3)|BIT(2),
(mute ? (BIT(3)|BIT(2)) : 0));
return 0;
}
static int lm49453_ls_mute(struct snd_soc_dai *dai, int mute)
{
snd_soc_update_bits(dai->codec, LM49453_P0_DAC_DSP_REG, BIT(5)|BIT(4),
(mute ? (BIT(5)|BIT(4)) : 0));
return 0;
}
static int lm49453_ep_mute(struct snd_soc_dai *dai, int mute)
{
snd_soc_update_bits(dai->codec, LM49453_P0_DAC_DSP_REG, BIT(4),
(mute ? BIT(4) : 0));
return 0;
}
static int lm49453_ha_mute(struct snd_soc_dai *dai, int mute)
{
snd_soc_update_bits(dai->codec, LM49453_P0_DAC_DSP_REG, BIT(7)|BIT(6),
(mute ? (BIT(7)|BIT(6)) : 0));
return 0;
}
static int lm49453_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct lm49453_priv *lm49453 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF)
regcache_sync(lm49453->regmap);
snd_soc_update_bits(codec, LM49453_P0_PMC_SETUP_REG,
LM49453_PMC_SETUP_CHIP_EN, LM49453_CHIP_EN);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, LM49453_P0_PMC_SETUP_REG,
LM49453_PMC_SETUP_CHIP_EN, 0);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int lm49453_remove(struct snd_soc_codec *codec)
{
lm49453_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int lm49453_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct lm49453_priv *lm49453;
int ret = 0;
lm49453 = devm_kzalloc(&i2c->dev, sizeof(struct lm49453_priv),
GFP_KERNEL);
if (lm49453 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, lm49453);
lm49453->regmap = devm_regmap_init_i2c(i2c, &lm49453_regmap_config);
if (IS_ERR(lm49453->regmap)) {
ret = PTR_ERR(lm49453->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_lm49453,
lm49453_dai, ARRAY_SIZE(lm49453_dai));
if (ret < 0)
dev_err(&i2c->dev, "Failed to register codec: %d\n", ret);
return ret;
}
static int lm49453_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
