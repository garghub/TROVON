static bool alc5632_volatile_register(struct device *dev,
unsigned int reg)
{
switch (reg) {
case ALC5632_RESET:
case ALC5632_PWR_DOWN_CTRL_STATUS:
case ALC5632_GPIO_PIN_STATUS:
case ALC5632_OVER_CURR_STATUS:
case ALC5632_HID_CTRL_DATA:
case ALC5632_EQ_CTRL:
case ALC5632_VENDOR_ID1:
case ALC5632_VENDOR_ID2:
return true;
default:
break;
}
return false;
}
static inline int alc5632_reset(struct regmap *map)
{
return regmap_write(map, ALC5632_RESET, 0x59B4);
}
static int amp_mixer_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
snd_soc_write(w->codec, ALC5632_HID_CTRL_INDEX, 0x46);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_write(w->codec, ALC5632_HID_CTRL_DATA, 0xFFFF);
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_write(w->codec, ALC5632_HID_CTRL_DATA, 0);
break;
}
return 0;
}
static int alc5632_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
int source, unsigned int freq_in, unsigned int freq_out)
{
int i;
struct snd_soc_codec *codec = codec_dai->codec;
int gbl_clk = 0, pll_div = 0;
u16 reg;
if (pll_id < ALC5632_PLL_FR_MCLK || pll_id > ALC5632_PLL_FR_VBCLK)
return -EINVAL;
snd_soc_update_bits(codec, ALC5632_PWR_MANAG_ADD2,
ALC5632_PWR_ADD2_PLL1,
0);
snd_soc_update_bits(codec, ALC5632_PWR_MANAG_ADD2,
ALC5632_PWR_ADD2_PLL2,
0);
reg = snd_soc_read(codec, ALC5632_DAI_CONTROL);
if (reg & ALC5632_DAI_SDP_SLAVE_MODE)
return 0;
if (!freq_in || !freq_out)
return 0;
switch (pll_id) {
case ALC5632_PLL_FR_MCLK:
for (i = 0; i < ARRAY_SIZE(codec_master_pll_div); i++) {
if (codec_master_pll_div[i].pll_in == freq_in
&& codec_master_pll_div[i].pll_out == freq_out) {
pll_div = codec_master_pll_div[i].regvalue;
break;
}
}
break;
case ALC5632_PLL_FR_BCLK:
for (i = 0; i < ARRAY_SIZE(codec_slave_pll_div); i++) {
if (codec_slave_pll_div[i].pll_in == freq_in
&& codec_slave_pll_div[i].pll_out == freq_out) {
gbl_clk = ALC5632_PLL_FR_BCLK;
pll_div = codec_slave_pll_div[i].regvalue;
break;
}
}
break;
case ALC5632_PLL_FR_VBCLK:
for (i = 0; i < ARRAY_SIZE(codec_slave_pll_div); i++) {
if (codec_slave_pll_div[i].pll_in == freq_in
&& codec_slave_pll_div[i].pll_out == freq_out) {
gbl_clk = ALC5632_PLL_FR_VBCLK;
pll_div = codec_slave_pll_div[i].regvalue;
break;
}
}
break;
default:
return -EINVAL;
}
if (!pll_div)
return -EINVAL;
snd_soc_write(codec, ALC5632_GPCR2, gbl_clk);
snd_soc_write(codec, ALC5632_PLL1_CTRL, pll_div);
snd_soc_update_bits(codec, ALC5632_PWR_MANAG_ADD2,
ALC5632_PWR_ADD2_PLL1,
ALC5632_PWR_ADD2_PLL1);
snd_soc_update_bits(codec, ALC5632_PWR_MANAG_ADD2,
ALC5632_PWR_ADD2_PLL2,
ALC5632_PWR_ADD2_PLL2);
snd_soc_update_bits(codec, ALC5632_GPCR1,
ALC5632_GPCR1_CLK_SYS_SRC_SEL_PLL1,
ALC5632_GPCR1_CLK_SYS_SRC_SEL_PLL1);
return 0;
}
static int get_coeff(struct snd_soc_codec *codec, int rate)
{
struct alc5632_priv *alc5632 = snd_soc_codec_get_drvdata(codec);
int i;
for (i = 0; i < ARRAY_SIZE(coeff_div); i++) {
if (coeff_div[i].fs * rate == alc5632->sysclk)
return i;
}
return -EINVAL;
}
static int alc5632_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct alc5632_priv *alc5632 = snd_soc_codec_get_drvdata(codec);
switch (freq) {
case 4096000:
case 8192000:
case 11289600:
case 12288000:
case 16384000:
case 16934400:
case 18432000:
case 22579200:
case 24576000:
alc5632->sysclk = freq;
return 0;
}
return -EINVAL;
}
static int alc5632_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 iface = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
iface = ALC5632_DAI_SDP_MASTER_MODE;
break;
case SND_SOC_DAIFMT_CBS_CFS:
iface = ALC5632_DAI_SDP_SLAVE_MODE;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
iface |= ALC5632_DAI_I2S_DF_I2S;
break;
case SND_SOC_DAIFMT_LEFT_J:
iface |= ALC5632_DAI_I2S_DF_LEFT;
break;
case SND_SOC_DAIFMT_DSP_A:
iface |= ALC5632_DAI_I2S_DF_PCM_A;
break;
case SND_SOC_DAIFMT_DSP_B:
iface |= ALC5632_DAI_I2S_DF_PCM_B;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
iface |= ALC5632_DAI_MAIN_I2S_BCLK_POL_CTRL;
break;
case SND_SOC_DAIFMT_IB_NF:
iface |= ALC5632_DAI_MAIN_I2S_BCLK_POL_CTRL;
break;
case SND_SOC_DAIFMT_NB_IF:
break;
default:
return -EINVAL;
}
return snd_soc_write(codec, ALC5632_DAI_CONTROL, iface);
}
static int alc5632_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
int coeff, rate;
u16 iface;
iface = snd_soc_read(codec, ALC5632_DAI_CONTROL);
iface &= ~ALC5632_DAI_I2S_DL_MASK;
switch (params_width(params)) {
case 16:
iface |= ALC5632_DAI_I2S_DL_16;
break;
case 20:
iface |= ALC5632_DAI_I2S_DL_20;
break;
case 24:
iface |= ALC5632_DAI_I2S_DL_24;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, ALC5632_DAI_CONTROL, iface);
rate = params_rate(params);
coeff = get_coeff(codec, rate);
if (coeff < 0)
return -EINVAL;
coeff = coeff_div[coeff].regvalue;
snd_soc_write(codec, ALC5632_DAC_CLK_CTRL1, coeff);
return 0;
}
static int alc5632_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u16 hp_mute = ALC5632_MISC_HP_DEPOP_MUTE_L
|ALC5632_MISC_HP_DEPOP_MUTE_R;
u16 mute_reg = snd_soc_read(codec, ALC5632_MISC_CTRL) & ~hp_mute;
if (mute)
mute_reg |= hp_mute;
return snd_soc_write(codec, ALC5632_MISC_CTRL, mute_reg);
}
static void enable_power_depop(struct snd_soc_codec *codec)
{
snd_soc_update_bits(codec, ALC5632_PWR_MANAG_ADD1,
ALC5632_PWR_ADD1_SOFTGEN_EN,
ALC5632_PWR_ADD1_SOFTGEN_EN);
snd_soc_update_bits(codec, ALC5632_PWR_MANAG_ADD3,
ALC5632_ADD3_POWER_EN,
ALC5632_ADD3_POWER_EN);
snd_soc_update_bits(codec, ALC5632_MISC_CTRL,
ALC5632_MISC_HP_DEPOP_MODE2_EN,
ALC5632_MISC_HP_DEPOP_MODE2_EN);
snd_soc_update_bits(codec, ALC5632_PWR_DOWN_CTRL_STATUS,
ALC5632_PWR_DOWN_CTRL_STATUS_MASK,
0);
msleep(500);
snd_soc_update_bits(codec, ALC5632_PWR_MANAG_ADD2,
ALC5632_ADD2_POWER_EN,
ALC5632_ADD2_POWER_EN);
snd_soc_update_bits(codec, ALC5632_PWR_MANAG_ADD1,
ALC5632_ADD1_POWER_EN,
ALC5632_ADD1_POWER_EN);
snd_soc_update_bits(codec, ALC5632_MISC_CTRL,
ALC5632_MISC_HP_DEPOP_MODE2_EN,
0);
}
static int alc5632_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_ON:
enable_power_depop(codec);
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
snd_soc_update_bits(codec, ALC5632_PWR_MANAG_ADD1,
ALC5632_PWR_MANAG_ADD1_MASK,
ALC5632_PWR_ADD1_MAIN_BIAS);
snd_soc_update_bits(codec, ALC5632_PWR_MANAG_ADD2,
ALC5632_PWR_MANAG_ADD2_MASK,
ALC5632_PWR_ADD2_VREF);
snd_soc_update_bits(codec, ALC5632_PWR_DOWN_CTRL_STATUS,
ALC5632_PWR_DOWN_CTRL_STATUS_MASK,
0xffff ^ (ALC5632_PWR_VREF_PR3
| ALC5632_PWR_VREF_PR2));
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, ALC5632_PWR_MANAG_ADD2,
ALC5632_PWR_MANAG_ADD2_MASK, 0);
snd_soc_update_bits(codec, ALC5632_PWR_MANAG_ADD3,
ALC5632_PWR_MANAG_ADD3_MASK, 0);
snd_soc_update_bits(codec, ALC5632_PWR_MANAG_ADD1,
ALC5632_PWR_MANAG_ADD1_MASK, 0);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int alc5632_suspend(struct snd_soc_codec *codec)
{
alc5632_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int alc5632_resume(struct snd_soc_codec *codec)
{
struct alc5632_priv *alc5632 = snd_soc_codec_get_drvdata(codec);
regcache_sync(alc5632->regmap);
alc5632_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int alc5632_probe(struct snd_soc_codec *codec)
{
struct alc5632_priv *alc5632 = snd_soc_codec_get_drvdata(codec);
alc5632_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
switch (alc5632->id) {
case 0x5c:
snd_soc_add_codec_controls(codec, alc5632_vol_snd_controls,
ARRAY_SIZE(alc5632_vol_snd_controls));
break;
default:
return -EINVAL;
}
return 0;
}
static int alc5632_remove(struct snd_soc_codec *codec)
{
alc5632_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int alc5632_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct alc5632_priv *alc5632;
int ret, ret1, ret2;
unsigned int vid1, vid2;
alc5632 = devm_kzalloc(&client->dev,
sizeof(struct alc5632_priv), GFP_KERNEL);
if (alc5632 == NULL)
return -ENOMEM;
i2c_set_clientdata(client, alc5632);
alc5632->regmap = devm_regmap_init_i2c(client, &alc5632_regmap);
if (IS_ERR(alc5632->regmap)) {
ret = PTR_ERR(alc5632->regmap);
dev_err(&client->dev, "regmap_init() failed: %d\n", ret);
return ret;
}
ret1 = regmap_read(alc5632->regmap, ALC5632_VENDOR_ID1, &vid1);
ret2 = regmap_read(alc5632->regmap, ALC5632_VENDOR_ID2, &vid2);
if (ret1 != 0 || ret2 != 0) {
dev_err(&client->dev,
"Failed to read chip ID: ret1=%d, ret2=%d\n", ret1, ret2);
return -EIO;
}
vid2 >>= 8;
if ((vid1 != 0x10EC) || (vid2 != id->driver_data)) {
dev_err(&client->dev,
"Device is not a ALC5632: VID1=0x%x, VID2=0x%x\n", vid1, vid2);
return -EINVAL;
}
ret = alc5632_reset(alc5632->regmap);
if (ret < 0) {
dev_err(&client->dev, "Failed to issue reset\n");
return ret;
}
alc5632->id = vid2;
switch (alc5632->id) {
case 0x5c:
alc5632_dai.name = "alc5632-hifi";
break;
default:
return -EINVAL;
}
ret = snd_soc_register_codec(&client->dev,
&soc_codec_device_alc5632, &alc5632_dai, 1);
if (ret < 0) {
dev_err(&client->dev, "Failed to register codec: %d\n", ret);
return ret;
}
return ret;
}
static int alc5632_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
