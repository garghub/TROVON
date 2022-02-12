static bool cs42l52_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS42L52_CHIP:
case CS42L52_PWRCTL1:
case CS42L52_PWRCTL2:
case CS42L52_PWRCTL3:
case CS42L52_CLK_CTL:
case CS42L52_IFACE_CTL1:
case CS42L52_IFACE_CTL2:
case CS42L52_ADC_PGA_A:
case CS42L52_ADC_PGA_B:
case CS42L52_ANALOG_HPF_CTL:
case CS42L52_ADC_HPF_FREQ:
case CS42L52_ADC_MISC_CTL:
case CS42L52_PB_CTL1:
case CS42L52_MISC_CTL:
case CS42L52_PB_CTL2:
case CS42L52_MICA_CTL:
case CS42L52_MICB_CTL:
case CS42L52_PGAA_CTL:
case CS42L52_PGAB_CTL:
case CS42L52_PASSTHRUA_VOL:
case CS42L52_PASSTHRUB_VOL:
case CS42L52_ADCA_VOL:
case CS42L52_ADCB_VOL:
case CS42L52_ADCA_MIXER_VOL:
case CS42L52_ADCB_MIXER_VOL:
case CS42L52_PCMA_MIXER_VOL:
case CS42L52_PCMB_MIXER_VOL:
case CS42L52_BEEP_FREQ:
case CS42L52_BEEP_VOL:
case CS42L52_BEEP_TONE_CTL:
case CS42L52_TONE_CTL:
case CS42L52_MASTERA_VOL:
case CS42L52_MASTERB_VOL:
case CS42L52_HPA_VOL:
case CS42L52_HPB_VOL:
case CS42L52_SPKA_VOL:
case CS42L52_SPKB_VOL:
case CS42L52_ADC_PCM_MIXER:
case CS42L52_LIMITER_CTL1:
case CS42L52_LIMITER_CTL2:
case CS42L52_LIMITER_AT_RATE:
case CS42L52_ALC_CTL:
case CS42L52_ALC_RATE:
case CS42L52_ALC_THRESHOLD:
case CS42L52_NOISE_GATE_CTL:
case CS42L52_CLK_STATUS:
case CS42L52_BATT_COMPEN:
case CS42L52_BATT_LEVEL:
case CS42L52_SPK_STATUS:
case CS42L52_TEM_CTL:
case CS42L52_THE_FOLDBACK:
case CS42L52_CHARGE_PUMP:
return true;
default:
return false;
}
}
static bool cs42l52_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS42L52_IFACE_CTL2:
case CS42L52_CLK_STATUS:
case CS42L52_BATT_LEVEL:
case CS42L52_SPK_STATUS:
case CS42L52_CHARGE_PUMP:
return 1;
default:
return 0;
}
}
static int cs42l52_get_clk(int mclk, int rate)
{
int i, ret = 0;
u_int mclk1, mclk2 = 0;
for (i = 0; i < ARRAY_SIZE(clk_map_table); i++) {
if (clk_map_table[i].rate == rate) {
mclk1 = clk_map_table[i].mclk;
if (abs(mclk - mclk1) < abs(mclk - mclk2)) {
mclk2 = mclk1;
ret = i;
}
}
}
if (ret > ARRAY_SIZE(clk_map_table))
return -EINVAL;
return ret;
}
static int cs42l52_set_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct cs42l52_private *cs42l52 = snd_soc_codec_get_drvdata(codec);
if ((freq >= CS42L52_MIN_CLK) && (freq <= CS42L52_MAX_CLK)) {
cs42l52->sysclk = freq;
} else {
dev_err(codec->dev, "Invalid freq parameter\n");
return -EINVAL;
}
return 0;
}
static int cs42l52_set_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct cs42l52_private *cs42l52 = snd_soc_codec_get_drvdata(codec);
u8 iface = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
iface = CS42L52_IFACE_CTL1_MASTER;
break;
case SND_SOC_DAIFMT_CBS_CFS:
iface = CS42L52_IFACE_CTL1_SLAVE;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
iface |= CS42L52_IFACE_CTL1_ADC_FMT_I2S |
CS42L52_IFACE_CTL1_DAC_FMT_I2S;
break;
case SND_SOC_DAIFMT_RIGHT_J:
iface |= CS42L52_IFACE_CTL1_DAC_FMT_RIGHT_J;
break;
case SND_SOC_DAIFMT_LEFT_J:
iface |= CS42L52_IFACE_CTL1_ADC_FMT_LEFT_J |
CS42L52_IFACE_CTL1_DAC_FMT_LEFT_J;
break;
case SND_SOC_DAIFMT_DSP_A:
iface |= CS42L52_IFACE_CTL1_DSP_MODE_EN;
break;
case SND_SOC_DAIFMT_DSP_B:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
iface |= CS42L52_IFACE_CTL1_INV_SCLK;
break;
case SND_SOC_DAIFMT_IB_NF:
iface |= CS42L52_IFACE_CTL1_INV_SCLK;
break;
case SND_SOC_DAIFMT_NB_IF:
break;
default:
return -EINVAL;
}
cs42l52->config.format = iface;
snd_soc_write(codec, CS42L52_IFACE_CTL1, cs42l52->config.format);
return 0;
}
static int cs42l52_digital_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
if (mute)
snd_soc_update_bits(codec, CS42L52_PB_CTL1,
CS42L52_PB_CTL1_MUTE_MASK,
CS42L52_PB_CTL1_MUTE);
else
snd_soc_update_bits(codec, CS42L52_PB_CTL1,
CS42L52_PB_CTL1_MUTE_MASK,
CS42L52_PB_CTL1_UNMUTE);
return 0;
}
static int cs42l52_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct cs42l52_private *cs42l52 = snd_soc_codec_get_drvdata(codec);
u32 clk = 0;
int index;
index = cs42l52_get_clk(cs42l52->sysclk, params_rate(params));
if (index >= 0) {
cs42l52->sysclk = clk_map_table[index].mclk;
clk |= (clk_map_table[index].speed << CLK_SPEED_SHIFT) |
(clk_map_table[index].group << CLK_32K_SR_SHIFT) |
(clk_map_table[index].videoclk << CLK_27M_MCLK_SHIFT) |
(clk_map_table[index].ratio << CLK_RATIO_SHIFT) |
clk_map_table[index].mclkdiv2;
snd_soc_write(codec, CS42L52_CLK_CTL, clk);
} else {
dev_err(codec->dev, "can't get correct mclk\n");
return -EINVAL;
}
return 0;
}
static int cs42l52_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct cs42l52_private *cs42l52 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, CS42L52_PWRCTL1,
CS42L52_PWRCTL1_PDN_CODEC, 0);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
regcache_cache_only(cs42l52->regmap, false);
regcache_sync(cs42l52->regmap);
}
snd_soc_write(codec, CS42L52_PWRCTL1, CS42L52_PWRCTL1_PDN_ALL);
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, CS42L52_PWRCTL1, CS42L52_PWRCTL1_PDN_ALL);
regcache_cache_only(cs42l52->regmap, true);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int cs42l52_suspend(struct snd_soc_codec *codec)
{
cs42l52_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int cs42l52_resume(struct snd_soc_codec *codec)
{
cs42l52_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static void cs42l52_beep_work(struct work_struct *work)
{
struct cs42l52_private *cs42l52 =
container_of(work, struct cs42l52_private, beep_work);
struct snd_soc_codec *codec = cs42l52->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
int i;
int val = 0;
int best = 0;
if (cs42l52->beep_rate) {
for (i = 0; i < ARRAY_SIZE(beep_rates); i++) {
if (abs(cs42l52->beep_rate - beep_rates[i]) <
abs(cs42l52->beep_rate - beep_rates[best]))
best = i;
}
dev_dbg(codec->dev, "Set beep rate %dHz for requested %dHz\n",
beep_rates[best], cs42l52->beep_rate);
val = (best << CS42L52_BEEP_RATE_SHIFT);
snd_soc_dapm_enable_pin(dapm, "Beep");
} else {
dev_dbg(codec->dev, "Disabling beep\n");
snd_soc_dapm_disable_pin(dapm, "Beep");
}
snd_soc_update_bits(codec, CS42L52_BEEP_FREQ,
CS42L52_BEEP_RATE_MASK, val);
snd_soc_dapm_sync(dapm);
}
static int cs42l52_beep_event(struct input_dev *dev, unsigned int type,
unsigned int code, int hz)
{
struct snd_soc_codec *codec = input_get_drvdata(dev);
struct cs42l52_private *cs42l52 = snd_soc_codec_get_drvdata(codec);
dev_dbg(codec->dev, "Beep event %x %x\n", code, hz);
switch (code) {
case SND_BELL:
if (hz)
hz = 261;
case SND_TONE:
break;
default:
return -1;
}
cs42l52->beep_rate = hz;
schedule_work(&cs42l52->beep_work);
return 0;
}
static ssize_t cs42l52_beep_set(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct cs42l52_private *cs42l52 = dev_get_drvdata(dev);
long int time;
int ret;
ret = kstrtol(buf, 10, &time);
if (ret != 0)
return ret;
input_event(cs42l52->beep, EV_SND, SND_TONE, time);
return count;
}
static void cs42l52_init_beep(struct snd_soc_codec *codec)
{
struct cs42l52_private *cs42l52 = snd_soc_codec_get_drvdata(codec);
int ret;
cs42l52->beep = input_allocate_device();
if (!cs42l52->beep) {
dev_err(codec->dev, "Failed to allocate beep device\n");
return;
}
INIT_WORK(&cs42l52->beep_work, cs42l52_beep_work);
cs42l52->beep_rate = 0;
cs42l52->beep->name = "CS42L52 Beep Generator";
cs42l52->beep->phys = dev_name(codec->dev);
cs42l52->beep->id.bustype = BUS_I2C;
cs42l52->beep->evbit[0] = BIT_MASK(EV_SND);
cs42l52->beep->sndbit[0] = BIT_MASK(SND_BELL) | BIT_MASK(SND_TONE);
cs42l52->beep->event = cs42l52_beep_event;
cs42l52->beep->dev.parent = codec->dev;
input_set_drvdata(cs42l52->beep, codec);
ret = input_register_device(cs42l52->beep);
if (ret != 0) {
input_free_device(cs42l52->beep);
cs42l52->beep = NULL;
dev_err(codec->dev, "Failed to register beep device\n");
}
ret = device_create_file(codec->dev, &dev_attr_beep);
if (ret != 0) {
dev_err(codec->dev, "Failed to create keyclick file: %d\n",
ret);
}
}
static void cs42l52_free_beep(struct snd_soc_codec *codec)
{
struct cs42l52_private *cs42l52 = snd_soc_codec_get_drvdata(codec);
device_remove_file(codec->dev, &dev_attr_beep);
input_unregister_device(cs42l52->beep);
cancel_work_sync(&cs42l52->beep_work);
cs42l52->beep = NULL;
snd_soc_update_bits(codec, CS42L52_BEEP_TONE_CTL,
CS42L52_BEEP_EN_MASK, 0);
}
static void cs42l52_init_beep(struct snd_soc_codec *codec)
{
}
static void cs42l52_free_beep(struct snd_soc_codec *codec)
{
}
static int cs42l52_probe(struct snd_soc_codec *codec)
{
struct cs42l52_private *cs42l52 = snd_soc_codec_get_drvdata(codec);
int ret;
codec->control_data = cs42l52->regmap;
ret = snd_soc_codec_set_cache_io(codec, 8, 8, SND_SOC_REGMAP);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
regcache_cache_only(cs42l52->regmap, true);
cs42l52_init_beep(codec);
cs42l52_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
cs42l52->sysclk = CS42L52_DEFAULT_CLK;
cs42l52->config.format = CS42L52_DEFAULT_FORMAT;
snd_soc_update_bits(codec, CS42L52_MICA_CTL,
CS42L52_MIC_CTL_TYPE_MASK,
cs42l52->pdata.mica_cfg <<
CS42L52_MIC_CTL_TYPE_SHIFT);
snd_soc_update_bits(codec, CS42L52_MICB_CTL,
CS42L52_MIC_CTL_TYPE_MASK,
cs42l52->pdata.micb_cfg <<
CS42L52_MIC_CTL_TYPE_SHIFT);
if (cs42l52->pdata.mica_cfg)
snd_soc_update_bits(codec, CS42L52_MICA_CTL,
CS42L52_MIC_CTL_MIC_SEL_MASK,
cs42l52->pdata.mica_sel <<
CS42L52_MIC_CTL_MIC_SEL_SHIFT);
if (cs42l52->pdata.micb_cfg)
snd_soc_update_bits(codec, CS42L52_MICB_CTL,
CS42L52_MIC_CTL_MIC_SEL_MASK,
cs42l52->pdata.micb_sel <<
CS42L52_MIC_CTL_MIC_SEL_SHIFT);
snd_soc_update_bits(codec, CS42L52_CHARGE_PUMP,
CS42L52_CHARGE_PUMP_MASK,
cs42l52->pdata.chgfreq <<
CS42L52_CHARGE_PUMP_SHIFT);
snd_soc_update_bits(codec, CS42L52_IFACE_CTL2,
CS42L52_IFACE_CTL2_BIAS_LVL,
cs42l52->pdata.micbias_lvl);
return ret;
}
static int cs42l52_remove(struct snd_soc_codec *codec)
{
cs42l52_free_beep(codec);
cs42l52_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int cs42l52_i2c_probe(struct i2c_client *i2c_client,
const struct i2c_device_id *id)
{
struct cs42l52_private *cs42l52;
int ret;
unsigned int devid = 0;
unsigned int reg;
cs42l52 = devm_kzalloc(&i2c_client->dev, sizeof(struct cs42l52_private),
GFP_KERNEL);
if (cs42l52 == NULL)
return -ENOMEM;
cs42l52->dev = &i2c_client->dev;
cs42l52->regmap = devm_regmap_init_i2c(i2c_client, &cs42l52_regmap);
if (IS_ERR(cs42l52->regmap)) {
ret = PTR_ERR(cs42l52->regmap);
dev_err(&i2c_client->dev, "regmap_init() failed: %d\n", ret);
return ret;
}
i2c_set_clientdata(i2c_client, cs42l52);
if (dev_get_platdata(&i2c_client->dev))
memcpy(&cs42l52->pdata, dev_get_platdata(&i2c_client->dev),
sizeof(cs42l52->pdata));
ret = regmap_register_patch(cs42l52->regmap, cs42l52_threshold_patch,
ARRAY_SIZE(cs42l52_threshold_patch));
if (ret != 0)
dev_warn(cs42l52->dev, "Failed to apply regmap patch: %d\n",
ret);
ret = regmap_read(cs42l52->regmap, CS42L52_CHIP, &reg);
devid = reg & CS42L52_CHIP_ID_MASK;
if (devid != CS42L52_CHIP_ID) {
ret = -ENODEV;
dev_err(&i2c_client->dev,
"CS42L52 Device ID (%X). Expected %X\n",
devid, CS42L52_CHIP_ID);
return ret;
}
regcache_cache_only(cs42l52->regmap, true);
ret = snd_soc_register_codec(&i2c_client->dev,
&soc_codec_dev_cs42l52, &cs42l52_dai, 1);
if (ret < 0)
return ret;
return 0;
}
static int cs42l52_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
