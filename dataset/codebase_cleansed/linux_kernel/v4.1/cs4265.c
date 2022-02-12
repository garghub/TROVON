static bool cs4265_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS4265_PWRCTL:
case CS4265_DAC_CTL:
case CS4265_ADC_CTL:
case CS4265_MCLK_FREQ:
case CS4265_SIG_SEL:
case CS4265_CHB_PGA_CTL:
case CS4265_CHA_PGA_CTL:
case CS4265_ADC_CTL2:
case CS4265_DAC_CHA_VOL:
case CS4265_DAC_CHB_VOL:
case CS4265_DAC_CTL2:
case CS4265_SPDIF_CTL1:
case CS4265_SPDIF_CTL2:
case CS4265_INT_MASK:
case CS4265_STATUS_MODE_MSB:
case CS4265_STATUS_MODE_LSB:
case CS4265_CHIP_ID:
return true;
default:
return false;
}
}
static bool cs4265_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS4265_INT_STATUS:
return true;
default:
return false;
}
}
static int cs4265_get_clk_index(int mclk, int rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(clk_map_table); i++) {
if (clk_map_table[i].rate == rate &&
clk_map_table[i].mclk == mclk)
return i;
}
return -EINVAL;
}
static int cs4265_set_sysclk(struct snd_soc_dai *codec_dai, int clk_id,
unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct cs4265_private *cs4265 = snd_soc_codec_get_drvdata(codec);
int i;
if (clk_id != 0) {
dev_err(codec->dev, "Invalid clk_id %d\n", clk_id);
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(clk_map_table); i++) {
if (clk_map_table[i].mclk == freq) {
cs4265->sysclk = freq;
return 0;
}
}
cs4265->sysclk = 0;
dev_err(codec->dev, "Invalid freq parameter %d\n", freq);
return -EINVAL;
}
static int cs4265_set_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct cs4265_private *cs4265 = snd_soc_codec_get_drvdata(codec);
u8 iface = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
snd_soc_update_bits(codec, CS4265_ADC_CTL,
CS4265_ADC_MASTER,
CS4265_ADC_MASTER);
break;
case SND_SOC_DAIFMT_CBS_CFS:
snd_soc_update_bits(codec, CS4265_ADC_CTL,
CS4265_ADC_MASTER,
0);
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
iface |= SND_SOC_DAIFMT_I2S;
break;
case SND_SOC_DAIFMT_RIGHT_J:
iface |= SND_SOC_DAIFMT_RIGHT_J;
break;
case SND_SOC_DAIFMT_LEFT_J:
iface |= SND_SOC_DAIFMT_LEFT_J;
break;
default:
return -EINVAL;
}
cs4265->format = iface;
return 0;
}
static int cs4265_digital_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
if (mute) {
snd_soc_update_bits(codec, CS4265_DAC_CTL,
CS4265_DAC_CTL_MUTE,
CS4265_DAC_CTL_MUTE);
snd_soc_update_bits(codec, CS4265_SPDIF_CTL2,
CS4265_SPDIF_CTL2_MUTE,
CS4265_SPDIF_CTL2_MUTE);
} else {
snd_soc_update_bits(codec, CS4265_DAC_CTL,
CS4265_DAC_CTL_MUTE,
0);
snd_soc_update_bits(codec, CS4265_SPDIF_CTL2,
CS4265_SPDIF_CTL2_MUTE,
0);
}
return 0;
}
static int cs4265_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct cs4265_private *cs4265 = snd_soc_codec_get_drvdata(codec);
int index;
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE &&
((cs4265->format & SND_SOC_DAIFMT_FORMAT_MASK)
== SND_SOC_DAIFMT_RIGHT_J))
return -EINVAL;
index = cs4265_get_clk_index(cs4265->sysclk, params_rate(params));
if (index >= 0) {
snd_soc_update_bits(codec, CS4265_ADC_CTL,
CS4265_ADC_FM, clk_map_table[index].fm_mode << 6);
snd_soc_update_bits(codec, CS4265_MCLK_FREQ,
CS4265_MCLK_FREQ_MASK,
clk_map_table[index].mclkdiv << 4);
} else {
dev_err(codec->dev, "can't get correct mclk\n");
return -EINVAL;
}
switch (cs4265->format & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
snd_soc_update_bits(codec, CS4265_DAC_CTL,
CS4265_DAC_CTL_DIF, (1 << 4));
snd_soc_update_bits(codec, CS4265_ADC_CTL,
CS4265_ADC_DIF, (1 << 4));
snd_soc_update_bits(codec, CS4265_SPDIF_CTL2,
CS4265_SPDIF_CTL2_DIF, (1 << 6));
break;
case SND_SOC_DAIFMT_RIGHT_J:
if (params_width(params) == 16) {
snd_soc_update_bits(codec, CS4265_DAC_CTL,
CS4265_DAC_CTL_DIF, (1 << 5));
snd_soc_update_bits(codec, CS4265_SPDIF_CTL2,
CS4265_SPDIF_CTL2_DIF, (1 << 7));
} else {
snd_soc_update_bits(codec, CS4265_DAC_CTL,
CS4265_DAC_CTL_DIF, (3 << 5));
snd_soc_update_bits(codec, CS4265_SPDIF_CTL2,
CS4265_SPDIF_CTL2_DIF, (1 << 7));
}
break;
case SND_SOC_DAIFMT_LEFT_J:
snd_soc_update_bits(codec, CS4265_DAC_CTL,
CS4265_DAC_CTL_DIF, 0);
snd_soc_update_bits(codec, CS4265_ADC_CTL,
CS4265_ADC_DIF, 0);
snd_soc_update_bits(codec, CS4265_SPDIF_CTL2,
CS4265_SPDIF_CTL2_DIF, (1 << 6));
break;
default:
return -EINVAL;
}
return 0;
}
static int cs4265_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, CS4265_PWRCTL,
CS4265_PWRCTL_PDN, 0);
break;
case SND_SOC_BIAS_STANDBY:
snd_soc_update_bits(codec, CS4265_PWRCTL,
CS4265_PWRCTL_PDN,
CS4265_PWRCTL_PDN);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, CS4265_PWRCTL,
CS4265_PWRCTL_PDN,
CS4265_PWRCTL_PDN);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int cs4265_i2c_probe(struct i2c_client *i2c_client,
const struct i2c_device_id *id)
{
struct cs4265_private *cs4265;
int ret = 0;
unsigned int devid = 0;
unsigned int reg;
cs4265 = devm_kzalloc(&i2c_client->dev, sizeof(struct cs4265_private),
GFP_KERNEL);
if (cs4265 == NULL)
return -ENOMEM;
cs4265->regmap = devm_regmap_init_i2c(i2c_client, &cs4265_regmap);
if (IS_ERR(cs4265->regmap)) {
ret = PTR_ERR(cs4265->regmap);
dev_err(&i2c_client->dev, "regmap_init() failed: %d\n", ret);
return ret;
}
cs4265->reset_gpio = devm_gpiod_get_optional(&i2c_client->dev,
"reset", GPIOD_OUT_LOW);
if (IS_ERR(cs4265->reset_gpio))
return PTR_ERR(cs4265->reset_gpio);
if (cs4265->reset_gpio) {
mdelay(1);
gpiod_set_value_cansleep(cs4265->reset_gpio, 1);
}
i2c_set_clientdata(i2c_client, cs4265);
ret = regmap_read(cs4265->regmap, CS4265_CHIP_ID, &reg);
devid = reg & CS4265_CHIP_ID_MASK;
if (devid != CS4265_CHIP_ID_VAL) {
ret = -ENODEV;
dev_err(&i2c_client->dev,
"CS4265 Device ID (%X). Expected %X\n",
devid, CS4265_CHIP_ID);
return ret;
}
dev_info(&i2c_client->dev,
"CS4265 Version %x\n",
reg & CS4265_REV_ID_MASK);
regmap_write(cs4265->regmap, CS4265_PWRCTL, 0x0F);
ret = snd_soc_register_codec(&i2c_client->dev,
&soc_codec_cs4265, cs4265_dai,
ARRAY_SIZE(cs4265_dai));
return ret;
}
static int cs4265_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
