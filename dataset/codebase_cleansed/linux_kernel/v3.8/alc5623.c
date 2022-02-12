static void alc5623_fill_cache(struct snd_soc_codec *codec)
{
int i, step = codec->driver->reg_cache_step;
u16 *cache = codec->reg_cache;
codec->cache_bypass = 1;
for (i = 0 ; i < codec->driver->reg_cache_size ; i += step)
cache[i] = snd_soc_read(codec, i);
codec->cache_bypass = 0;
}
static inline int alc5623_reset(struct snd_soc_codec *codec)
{
return snd_soc_write(codec, ALC5623_RESET, 0);
}
static int amp_mixer_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
snd_soc_write(w->codec, ALC5623_HID_CTRL_INDEX, 0x46);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_write(w->codec, ALC5623_HID_CTRL_DATA, 0xFFFF);
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_write(w->codec, ALC5623_HID_CTRL_DATA, 0);
break;
}
return 0;
}
static int alc5623_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
int source, unsigned int freq_in, unsigned int freq_out)
{
int i;
struct snd_soc_codec *codec = codec_dai->codec;
int gbl_clk = 0, pll_div = 0;
u16 reg;
if (pll_id < ALC5623_PLL_FR_MCLK || pll_id > ALC5623_PLL_FR_BCK)
return -ENODEV;
snd_soc_update_bits(codec, ALC5623_PWR_MANAG_ADD2,
ALC5623_PWR_ADD2_PLL,
0);
reg = snd_soc_read(codec, ALC5623_DAI_CONTROL);
if (reg & ALC5623_DAI_SDP_SLAVE_MODE)
return 0;
if (!freq_in || !freq_out)
return 0;
switch (pll_id) {
case ALC5623_PLL_FR_MCLK:
for (i = 0; i < ARRAY_SIZE(codec_master_pll_div); i++) {
if (codec_master_pll_div[i].pll_in == freq_in
&& codec_master_pll_div[i].pll_out == freq_out) {
pll_div = codec_master_pll_div[i].regvalue;
break;
}
}
break;
case ALC5623_PLL_FR_BCK:
for (i = 0; i < ARRAY_SIZE(codec_slave_pll_div); i++) {
if (codec_slave_pll_div[i].pll_in == freq_in
&& codec_slave_pll_div[i].pll_out == freq_out) {
gbl_clk = ALC5623_GBL_CLK_PLL_SOUR_SEL_BITCLK;
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
snd_soc_write(codec, ALC5623_GLOBAL_CLK_CTRL_REG, gbl_clk);
snd_soc_write(codec, ALC5623_PLL_CTRL, pll_div);
snd_soc_update_bits(codec, ALC5623_PWR_MANAG_ADD2,
ALC5623_PWR_ADD2_PLL,
ALC5623_PWR_ADD2_PLL);
gbl_clk |= ALC5623_GBL_CLK_SYS_SOUR_SEL_PLL;
snd_soc_write(codec, ALC5623_GLOBAL_CLK_CTRL_REG, gbl_clk);
return 0;
}
static int get_coeff(struct snd_soc_codec *codec, int rate)
{
struct alc5623_priv *alc5623 = snd_soc_codec_get_drvdata(codec);
int i;
for (i = 0; i < ARRAY_SIZE(coeff_div); i++) {
if (coeff_div[i].fs * rate == alc5623->sysclk)
return i;
}
return -EINVAL;
}
static int alc5623_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct alc5623_priv *alc5623 = snd_soc_codec_get_drvdata(codec);
switch (freq) {
case 8192000:
case 11289600:
case 12288000:
case 16384000:
case 16934400:
case 18432000:
case 22579200:
case 24576000:
alc5623->sysclk = freq;
return 0;
}
return -EINVAL;
}
static int alc5623_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 iface = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
iface = ALC5623_DAI_SDP_MASTER_MODE;
break;
case SND_SOC_DAIFMT_CBS_CFS:
iface = ALC5623_DAI_SDP_SLAVE_MODE;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
iface |= ALC5623_DAI_I2S_DF_I2S;
break;
case SND_SOC_DAIFMT_RIGHT_J:
iface |= ALC5623_DAI_I2S_DF_RIGHT;
break;
case SND_SOC_DAIFMT_LEFT_J:
iface |= ALC5623_DAI_I2S_DF_LEFT;
break;
case SND_SOC_DAIFMT_DSP_A:
iface |= ALC5623_DAI_I2S_DF_PCM;
break;
case SND_SOC_DAIFMT_DSP_B:
iface |= ALC5623_DAI_I2S_DF_PCM | ALC5623_DAI_I2S_PCM_MODE;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
iface |= ALC5623_DAI_MAIN_I2S_BCLK_POL_CTRL;
break;
case SND_SOC_DAIFMT_IB_NF:
iface |= ALC5623_DAI_MAIN_I2S_BCLK_POL_CTRL;
break;
case SND_SOC_DAIFMT_NB_IF:
break;
default:
return -EINVAL;
}
return snd_soc_write(codec, ALC5623_DAI_CONTROL, iface);
}
static int alc5623_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct alc5623_priv *alc5623 = snd_soc_codec_get_drvdata(codec);
int coeff, rate;
u16 iface;
iface = snd_soc_read(codec, ALC5623_DAI_CONTROL);
iface &= ~ALC5623_DAI_I2S_DL_MASK;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
iface |= ALC5623_DAI_I2S_DL_16;
break;
case SNDRV_PCM_FORMAT_S20_3LE:
iface |= ALC5623_DAI_I2S_DL_20;
break;
case SNDRV_PCM_FORMAT_S24_LE:
iface |= ALC5623_DAI_I2S_DL_24;
break;
case SNDRV_PCM_FORMAT_S32_LE:
iface |= ALC5623_DAI_I2S_DL_32;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, ALC5623_DAI_CONTROL, iface);
rate = params_rate(params);
coeff = get_coeff(codec, rate);
if (coeff < 0)
return -EINVAL;
coeff = coeff_div[coeff].regvalue;
dev_dbg(codec->dev, "%s: sysclk=%d,rate=%d,coeff=0x%04x\n",
__func__, alc5623->sysclk, rate, coeff);
snd_soc_write(codec, ALC5623_STEREO_AD_DA_CLK_CTRL, coeff);
return 0;
}
static int alc5623_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u16 hp_mute = ALC5623_MISC_M_DAC_L_INPUT | ALC5623_MISC_M_DAC_R_INPUT;
u16 mute_reg = snd_soc_read(codec, ALC5623_MISC_CTRL) & ~hp_mute;
if (mute)
mute_reg |= hp_mute;
return snd_soc_write(codec, ALC5623_MISC_CTRL, mute_reg);
}
static void enable_power_depop(struct snd_soc_codec *codec)
{
struct alc5623_priv *alc5623 = snd_soc_codec_get_drvdata(codec);
snd_soc_update_bits(codec, ALC5623_PWR_MANAG_ADD1,
ALC5623_PWR_ADD1_SOFTGEN_EN,
ALC5623_PWR_ADD1_SOFTGEN_EN);
snd_soc_write(codec, ALC5623_PWR_MANAG_ADD3, ALC5623_ADD3_POWER_EN);
snd_soc_update_bits(codec, ALC5623_MISC_CTRL,
ALC5623_MISC_HP_DEPOP_MODE2_EN,
ALC5623_MISC_HP_DEPOP_MODE2_EN);
msleep(500);
snd_soc_write(codec, ALC5623_PWR_MANAG_ADD2, ALC5623_ADD2_POWER_EN);
if (alc5623->id == 0x22)
snd_soc_write(codec, ALC5623_PWR_MANAG_ADD1,
ALC5623_ADD1_POWER_EN_5622);
else
snd_soc_write(codec, ALC5623_PWR_MANAG_ADD1,
ALC5623_ADD1_POWER_EN);
snd_soc_update_bits(codec, ALC5623_MISC_CTRL,
ALC5623_MISC_HP_DEPOP_MODE2_EN,
0);
}
static int alc5623_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_ON:
enable_power_depop(codec);
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
snd_soc_write(codec, ALC5623_PWR_MANAG_ADD2,
ALC5623_PWR_ADD2_VREF);
snd_soc_write(codec, ALC5623_PWR_MANAG_ADD3,
ALC5623_PWR_ADD3_MAIN_BIAS);
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, ALC5623_PWR_MANAG_ADD2, 0);
snd_soc_write(codec, ALC5623_PWR_MANAG_ADD3, 0);
snd_soc_write(codec, ALC5623_PWR_MANAG_ADD1, 0);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int alc5623_suspend(struct snd_soc_codec *codec)
{
alc5623_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int alc5623_resume(struct snd_soc_codec *codec)
{
int i, step = codec->driver->reg_cache_step;
u16 *cache = codec->reg_cache;
for (i = 2 ; i < codec->driver->reg_cache_size ; i += step)
snd_soc_write(codec, i, cache[i]);
alc5623_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
if (codec->dapm.suspend_bias_level == SND_SOC_BIAS_ON) {
alc5623_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
codec->dapm.bias_level = SND_SOC_BIAS_ON;
alc5623_set_bias_level(codec, codec->dapm.bias_level);
}
return 0;
}
static int alc5623_probe(struct snd_soc_codec *codec)
{
struct alc5623_priv *alc5623 = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret;
ret = snd_soc_codec_set_cache_io(codec, 8, 16, alc5623->control_type);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
alc5623_reset(codec);
alc5623_fill_cache(codec);
alc5623_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
if (alc5623->add_ctrl) {
snd_soc_write(codec, ALC5623_ADD_CTRL_REG,
alc5623->add_ctrl);
}
if (alc5623->jack_det_ctrl) {
snd_soc_write(codec, ALC5623_JACK_DET_CTRL,
alc5623->jack_det_ctrl);
}
switch (alc5623->id) {
case 0x21:
snd_soc_add_codec_controls(codec, alc5621_vol_snd_controls,
ARRAY_SIZE(alc5621_vol_snd_controls));
break;
case 0x22:
snd_soc_add_codec_controls(codec, alc5622_vol_snd_controls,
ARRAY_SIZE(alc5622_vol_snd_controls));
break;
case 0x23:
snd_soc_add_codec_controls(codec, alc5623_vol_snd_controls,
ARRAY_SIZE(alc5623_vol_snd_controls));
break;
default:
return -EINVAL;
}
snd_soc_add_codec_controls(codec, alc5623_snd_controls,
ARRAY_SIZE(alc5623_snd_controls));
snd_soc_dapm_new_controls(dapm, alc5623_dapm_widgets,
ARRAY_SIZE(alc5623_dapm_widgets));
snd_soc_dapm_add_routes(dapm, intercon, ARRAY_SIZE(intercon));
switch (alc5623->id) {
case 0x21:
case 0x22:
snd_soc_dapm_new_controls(dapm, alc5623_dapm_amp_widgets,
ARRAY_SIZE(alc5623_dapm_amp_widgets));
snd_soc_dapm_add_routes(dapm, intercon_amp_spk,
ARRAY_SIZE(intercon_amp_spk));
break;
case 0x23:
snd_soc_dapm_add_routes(dapm, intercon_spk,
ARRAY_SIZE(intercon_spk));
break;
default:
return -EINVAL;
}
return ret;
}
static int alc5623_remove(struct snd_soc_codec *codec)
{
alc5623_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int alc5623_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct alc5623_platform_data *pdata;
struct alc5623_priv *alc5623;
int ret, vid1, vid2;
vid1 = i2c_smbus_read_word_data(client, ALC5623_VENDOR_ID1);
if (vid1 < 0) {
dev_err(&client->dev, "failed to read I2C\n");
return -EIO;
}
vid1 = ((vid1 & 0xff) << 8) | (vid1 >> 8);
vid2 = i2c_smbus_read_byte_data(client, ALC5623_VENDOR_ID2);
if (vid2 < 0) {
dev_err(&client->dev, "failed to read I2C\n");
return -EIO;
}
if ((vid1 != 0x10ec) || (vid2 != id->driver_data)) {
dev_err(&client->dev, "unknown or wrong codec\n");
dev_err(&client->dev, "Expected %x:%lx, got %x:%x\n",
0x10ec, id->driver_data,
vid1, vid2);
return -ENODEV;
}
dev_dbg(&client->dev, "Found codec id : alc56%02x\n", vid2);
alc5623 = devm_kzalloc(&client->dev, sizeof(struct alc5623_priv),
GFP_KERNEL);
if (alc5623 == NULL)
return -ENOMEM;
pdata = client->dev.platform_data;
if (pdata) {
alc5623->add_ctrl = pdata->add_ctrl;
alc5623->jack_det_ctrl = pdata->jack_det_ctrl;
}
alc5623->id = vid2;
switch (alc5623->id) {
case 0x21:
alc5623_dai.name = "alc5621-hifi";
break;
case 0x22:
alc5623_dai.name = "alc5622-hifi";
break;
case 0x23:
alc5623_dai.name = "alc5623-hifi";
break;
default:
return -EINVAL;
}
i2c_set_clientdata(client, alc5623);
alc5623->control_type = SND_SOC_I2C;
ret = snd_soc_register_codec(&client->dev,
&soc_codec_device_alc5623, &alc5623_dai, 1);
if (ret != 0)
dev_err(&client->dev, "Failed to register codec: %d\n", ret);
return ret;
}
static int alc5623_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
