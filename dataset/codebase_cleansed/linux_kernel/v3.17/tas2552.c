static void tas2552_sw_shutdown(struct tas2552_data *tas_data, int sw_shutdown)
{
u8 cfg1_reg;
if (sw_shutdown)
cfg1_reg = 0;
else
cfg1_reg = TAS2552_SWS_MASK;
snd_soc_update_bits(tas_data->codec, TAS2552_CFG_1,
TAS2552_SWS_MASK, cfg1_reg);
}
static int tas2552_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct tas2552_data *tas2552 = dev_get_drvdata(codec->dev);
int sample_rate, pll_clk;
int d;
u8 p, j;
snd_soc_update_bits(codec, TAS2552_CFG_2, TAS2552_CLASSD_EN_MASK,
TAS2552_CLASSD_EN);
if (!tas2552->mclk)
return -EINVAL;
snd_soc_update_bits(codec, TAS2552_CFG_2, TAS2552_PLL_ENABLE, 0);
if (tas2552->mclk == TAS2552_245MHZ_CLK ||
tas2552->mclk == TAS2552_225MHZ_CLK) {
snd_soc_update_bits(codec, TAS2552_PLL_CTRL_2,
TAS2552_PLL_BYPASS_MASK,
TAS2552_PLL_BYPASS);
} else {
p = snd_soc_read(codec, TAS2552_PLL_CTRL_1);
p = (p >> 7);
sample_rate = params_rate(params);
if (sample_rate == 48000)
pll_clk = TAS2552_245MHZ_CLK;
else if (sample_rate == 44100)
pll_clk = TAS2552_225MHZ_CLK;
else {
dev_vdbg(codec->dev, "Substream sample rate is not found %i\n",
params_rate(params));
return -EINVAL;
}
j = (pll_clk * 2 * (1 << p)) / tas2552->mclk;
d = (pll_clk * 2 * (1 << p)) % tas2552->mclk;
snd_soc_update_bits(codec, TAS2552_PLL_CTRL_1,
TAS2552_PLL_J_MASK, j);
snd_soc_write(codec, TAS2552_PLL_CTRL_2,
(d >> 7) & TAS2552_PLL_D_UPPER_MASK);
snd_soc_write(codec, TAS2552_PLL_CTRL_3,
d & TAS2552_PLL_D_LOWER_MASK);
}
snd_soc_update_bits(codec, TAS2552_CFG_2, TAS2552_PLL_ENABLE,
TAS2552_PLL_ENABLE);
return 0;
}
static int tas2552_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
u8 serial_format;
u8 serial_control_mask;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
serial_format = 0x00;
break;
case SND_SOC_DAIFMT_CBS_CFM:
serial_format = TAS2552_WORD_CLK_MASK;
break;
case SND_SOC_DAIFMT_CBM_CFS:
serial_format = TAS2552_BIT_CLK_MASK;
break;
case SND_SOC_DAIFMT_CBM_CFM:
serial_format = (TAS2552_BIT_CLK_MASK | TAS2552_WORD_CLK_MASK);
break;
default:
dev_vdbg(codec->dev, "DAI Format master is not found\n");
return -EINVAL;
}
serial_control_mask = TAS2552_BIT_CLK_MASK | TAS2552_WORD_CLK_MASK;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
serial_format &= TAS2552_DAIFMT_I2S_MASK;
break;
case SND_SOC_DAIFMT_DSP_A:
serial_format |= TAS2552_DAIFMT_DSP;
break;
case SND_SOC_DAIFMT_RIGHT_J:
serial_format |= TAS2552_DAIFMT_RIGHT_J;
break;
case SND_SOC_DAIFMT_LEFT_J:
serial_format |= TAS2552_DAIFMT_LEFT_J;
break;
default:
dev_vdbg(codec->dev, "DAI Format is not found\n");
return -EINVAL;
}
if (fmt & SND_SOC_DAIFMT_FORMAT_MASK)
serial_control_mask |= TAS2552_DATA_FORMAT_MASK;
snd_soc_update_bits(codec, TAS2552_SER_CTRL_1, serial_control_mask,
serial_format);
return 0;
}
static int tas2552_set_dai_sysclk(struct snd_soc_dai *dai, int clk_id,
unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct tas2552_data *tas2552 = dev_get_drvdata(codec->dev);
tas2552->mclk = freq;
return 0;
}
static int tas2552_mute(struct snd_soc_dai *dai, int mute)
{
u8 cfg1_reg;
struct snd_soc_codec *codec = dai->codec;
if (mute)
cfg1_reg = TAS2552_MUTE_MASK;
else
cfg1_reg = ~TAS2552_MUTE_MASK;
snd_soc_update_bits(codec, TAS2552_CFG_1, TAS2552_MUTE_MASK, cfg1_reg);
return 0;
}
static int tas2552_runtime_suspend(struct device *dev)
{
struct tas2552_data *tas2552 = dev_get_drvdata(dev);
tas2552_sw_shutdown(tas2552, 0);
regcache_cache_only(tas2552->regmap, true);
regcache_mark_dirty(tas2552->regmap);
if (tas2552->enable_gpio)
gpiod_set_value(tas2552->enable_gpio, 0);
return 0;
}
static int tas2552_runtime_resume(struct device *dev)
{
struct tas2552_data *tas2552 = dev_get_drvdata(dev);
if (tas2552->enable_gpio)
gpiod_set_value(tas2552->enable_gpio, 1);
tas2552_sw_shutdown(tas2552, 1);
regcache_cache_only(tas2552->regmap, false);
regcache_sync(tas2552->regmap);
return 0;
}
static void tas2552_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
snd_soc_update_bits(codec, TAS2552_CFG_2, TAS2552_PLL_ENABLE, 0);
}
static int tas2552_codec_probe(struct snd_soc_codec *codec)
{
struct tas2552_data *tas2552 = snd_soc_codec_get_drvdata(codec);
int ret;
tas2552->codec = codec;
ret = regulator_bulk_enable(ARRAY_SIZE(tas2552->supplies),
tas2552->supplies);
if (ret != 0) {
dev_err(codec->dev, "Failed to enable supplies: %d\n",
ret);
return ret;
}
if (tas2552->enable_gpio)
gpiod_set_value(tas2552->enable_gpio, 1);
ret = pm_runtime_get_sync(codec->dev);
if (ret < 0) {
dev_err(codec->dev, "Enabling device failed: %d\n",
ret);
goto probe_fail;
}
snd_soc_write(codec, TAS2552_CFG_1, TAS2552_MUTE_MASK |
TAS2552_PLL_SRC_BCLK);
snd_soc_write(codec, TAS2552_CFG_3, TAS2552_I2S_OUT_SEL |
TAS2552_DIN_SRC_SEL_AVG_L_R | TAS2552_88_96KHZ);
snd_soc_write(codec, TAS2552_DOUT, TAS2552_PDM_DATA_I);
snd_soc_write(codec, TAS2552_OUTPUT_DATA, TAS2552_PDM_DATA_V_I | 0x8);
snd_soc_write(codec, TAS2552_PDM_CFG, TAS2552_PDM_BCLK_SEL);
snd_soc_write(codec, TAS2552_BOOST_PT_CTRL, TAS2552_APT_DELAY_200 |
TAS2552_APT_THRESH_2_1_7);
ret = regmap_register_patch(tas2552->regmap, tas2552_init_regs,
ARRAY_SIZE(tas2552_init_regs));
if (ret != 0) {
dev_err(codec->dev, "Failed to write init registers: %d\n",
ret);
goto patch_fail;
}
snd_soc_write(codec, TAS2552_CFG_2, TAS2552_CLASSD_EN |
TAS2552_BOOST_EN | TAS2552_APT_EN |
TAS2552_LIM_EN);
return 0;
patch_fail:
pm_runtime_put(codec->dev);
probe_fail:
if (tas2552->enable_gpio)
gpiod_set_value(tas2552->enable_gpio, 0);
regulator_bulk_disable(ARRAY_SIZE(tas2552->supplies),
tas2552->supplies);
return -EIO;
}
static int tas2552_codec_remove(struct snd_soc_codec *codec)
{
struct tas2552_data *tas2552 = snd_soc_codec_get_drvdata(codec);
pm_runtime_put(codec->dev);
if (tas2552->enable_gpio)
gpiod_set_value(tas2552->enable_gpio, 0);
return 0;
}
static int tas2552_suspend(struct snd_soc_codec *codec)
{
struct tas2552_data *tas2552 = snd_soc_codec_get_drvdata(codec);
int ret;
ret = regulator_bulk_disable(ARRAY_SIZE(tas2552->supplies),
tas2552->supplies);
if (ret != 0)
dev_err(codec->dev, "Failed to disable supplies: %d\n",
ret);
return 0;
}
static int tas2552_resume(struct snd_soc_codec *codec)
{
struct tas2552_data *tas2552 = snd_soc_codec_get_drvdata(codec);
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(tas2552->supplies),
tas2552->supplies);
if (ret != 0) {
dev_err(codec->dev, "Failed to enable supplies: %d\n",
ret);
}
return 0;
}
static int tas2552_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev;
struct tas2552_data *data;
int ret;
int i;
dev = &client->dev;
data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
data->enable_gpio = devm_gpiod_get(dev, "enable");
if (IS_ERR(data->enable_gpio)) {
ret = PTR_ERR(data->enable_gpio);
if (ret != -ENOENT && ret != -ENOSYS)
return ret;
data->enable_gpio = NULL;
} else {
gpiod_direction_output(data->enable_gpio, 0);
}
data->tas2552_client = client;
data->regmap = devm_regmap_init_i2c(client, &tas2552_regmap_config);
if (IS_ERR(data->regmap)) {
ret = PTR_ERR(data->regmap);
dev_err(&client->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
for (i = 0; i < ARRAY_SIZE(data->supplies); i++)
data->supplies[i].supply = tas2552_supply_names[i];
ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(data->supplies),
data->supplies);
if (ret != 0) {
dev_err(dev, "Failed to request supplies: %d\n", ret);
return ret;
}
pm_runtime_set_active(&client->dev);
pm_runtime_set_autosuspend_delay(&client->dev, 1000);
pm_runtime_use_autosuspend(&client->dev);
pm_runtime_enable(&client->dev);
pm_runtime_mark_last_busy(&client->dev);
pm_runtime_put_sync_autosuspend(&client->dev);
dev_set_drvdata(&client->dev, data);
ret = snd_soc_register_codec(&client->dev,
&soc_codec_dev_tas2552,
tas2552_dai, ARRAY_SIZE(tas2552_dai));
if (ret < 0)
dev_err(&client->dev, "Failed to register codec: %d\n", ret);
return ret;
}
static int tas2552_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
