static bool cs42l56_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS42L56_CHIP_ID_1 ... CS42L56_LIM_ATTACK_RATE:
return true;
default:
return false;
}
}
static bool cs42l56_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS42L56_INT_STATUS:
return true;
default:
return false;
}
}
static int cs42l56_get_mclk_ratio(int mclk, int rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(clk_ratio_table); i++) {
if (clk_ratio_table[i].mclk == mclk &&
clk_ratio_table[i].srate == rate)
return clk_ratio_table[i].ratio;
}
return -EINVAL;
}
static int cs42l56_set_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct cs42l56_private *cs42l56 = snd_soc_codec_get_drvdata(codec);
switch (freq) {
case CS42L56_MCLK_5P6448MHZ:
case CS42L56_MCLK_6MHZ:
case CS42L56_MCLK_6P144MHZ:
cs42l56->mclk_div2 = 0;
cs42l56->mclk_prediv = 0;
break;
case CS42L56_MCLK_11P2896MHZ:
case CS42L56_MCLK_12MHZ:
case CS42L56_MCLK_12P288MHZ:
cs42l56->mclk_div2 = CS42L56_MCLK_DIV2;
cs42l56->mclk_prediv = 0;
break;
case CS42L56_MCLK_22P5792MHZ:
case CS42L56_MCLK_24MHZ:
case CS42L56_MCLK_24P576MHZ:
cs42l56->mclk_div2 = CS42L56_MCLK_DIV2;
cs42l56->mclk_prediv = CS42L56_MCLK_PREDIV;
break;
default:
return -EINVAL;
}
cs42l56->mclk = freq;
snd_soc_update_bits(codec, CS42L56_CLKCTL_1,
CS42L56_MCLK_PREDIV_MASK,
cs42l56->mclk_prediv);
snd_soc_update_bits(codec, CS42L56_CLKCTL_1,
CS42L56_MCLK_DIV2_MASK,
cs42l56->mclk_div2);
return 0;
}
static int cs42l56_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct cs42l56_private *cs42l56 = snd_soc_codec_get_drvdata(codec);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
cs42l56->iface = CS42L56_MASTER_MODE;
break;
case SND_SOC_DAIFMT_CBS_CFS:
cs42l56->iface = CS42L56_SLAVE_MODE;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
cs42l56->iface_fmt = CS42L56_DIG_FMT_I2S;
break;
case SND_SOC_DAIFMT_LEFT_J:
cs42l56->iface_fmt = CS42L56_DIG_FMT_LEFT_J;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
cs42l56->iface_inv = 0;
break;
case SND_SOC_DAIFMT_IB_NF:
cs42l56->iface_inv = CS42L56_SCLK_INV;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, CS42L56_CLKCTL_1,
CS42L56_MS_MODE_MASK, cs42l56->iface);
snd_soc_update_bits(codec, CS42L56_SERIAL_FMT,
CS42L56_DIG_FMT_MASK, cs42l56->iface_fmt);
snd_soc_update_bits(codec, CS42L56_CLKCTL_1,
CS42L56_SCLK_INV_MASK, cs42l56->iface_inv);
return 0;
}
static int cs42l56_digital_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
if (mute) {
snd_soc_update_bits(codec, CS42L56_DSP_MUTE_CTL,
CS42L56_ADCAMIX_MUTE_MASK |
CS42L56_ADCBMIX_MUTE_MASK |
CS42L56_PCMAMIX_MUTE_MASK |
CS42L56_PCMBMIX_MUTE_MASK |
CS42L56_MSTB_MUTE_MASK |
CS42L56_MSTA_MUTE_MASK,
CS42L56_MUTE_ALL);
snd_soc_update_bits(codec, CS42L56_MISC_ADC_CTL,
CS42L56_ADCA_MUTE_MASK |
CS42L56_ADCB_MUTE_MASK,
CS42L56_MUTE_ALL);
snd_soc_update_bits(codec, CS42L56_HPA_VOLUME,
CS42L56_HP_MUTE_MASK, CS42L56_MUTE_ALL);
snd_soc_update_bits(codec, CS42L56_HPB_VOLUME,
CS42L56_HP_MUTE_MASK, CS42L56_MUTE_ALL);
snd_soc_update_bits(codec, CS42L56_LOA_VOLUME,
CS42L56_LO_MUTE_MASK, CS42L56_MUTE_ALL);
snd_soc_update_bits(codec, CS42L56_LOB_VOLUME,
CS42L56_LO_MUTE_MASK, CS42L56_MUTE_ALL);
} else {
snd_soc_update_bits(codec, CS42L56_DSP_MUTE_CTL,
CS42L56_ADCAMIX_MUTE_MASK |
CS42L56_ADCBMIX_MUTE_MASK |
CS42L56_PCMAMIX_MUTE_MASK |
CS42L56_PCMBMIX_MUTE_MASK |
CS42L56_MSTB_MUTE_MASK |
CS42L56_MSTA_MUTE_MASK,
CS42L56_UNMUTE);
snd_soc_update_bits(codec, CS42L56_MISC_ADC_CTL,
CS42L56_ADCA_MUTE_MASK |
CS42L56_ADCB_MUTE_MASK,
CS42L56_UNMUTE);
snd_soc_update_bits(codec, CS42L56_HPA_VOLUME,
CS42L56_HP_MUTE_MASK, CS42L56_UNMUTE);
snd_soc_update_bits(codec, CS42L56_HPB_VOLUME,
CS42L56_HP_MUTE_MASK, CS42L56_UNMUTE);
snd_soc_update_bits(codec, CS42L56_LOA_VOLUME,
CS42L56_LO_MUTE_MASK, CS42L56_UNMUTE);
snd_soc_update_bits(codec, CS42L56_LOB_VOLUME,
CS42L56_LO_MUTE_MASK, CS42L56_UNMUTE);
}
return 0;
}
static int cs42l56_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct cs42l56_private *cs42l56 = snd_soc_codec_get_drvdata(codec);
int ratio;
ratio = cs42l56_get_mclk_ratio(cs42l56->mclk, params_rate(params));
if (ratio >= 0) {
snd_soc_update_bits(codec, CS42L56_CLKCTL_2,
CS42L56_CLK_RATIO_MASK, ratio);
} else {
dev_err(codec->dev, "unsupported mclk/sclk/lrclk ratio\n");
return -EINVAL;
}
return 0;
}
static int cs42l56_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct cs42l56_private *cs42l56 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, CS42L56_CLKCTL_1,
CS42L56_MCLK_DIS_MASK, 0);
snd_soc_update_bits(codec, CS42L56_PWRCTL_1,
CS42L56_PDN_ALL_MASK, 0);
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
regcache_cache_only(cs42l56->regmap, false);
regcache_sync(cs42l56->regmap);
ret = regulator_bulk_enable(ARRAY_SIZE(cs42l56->supplies),
cs42l56->supplies);
if (ret != 0) {
dev_err(cs42l56->dev,
"Failed to enable regulators: %d\n",
ret);
return ret;
}
}
snd_soc_update_bits(codec, CS42L56_PWRCTL_1,
CS42L56_PDN_ALL_MASK, 1);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, CS42L56_PWRCTL_1,
CS42L56_PDN_ALL_MASK, 1);
snd_soc_update_bits(codec, CS42L56_CLKCTL_1,
CS42L56_MCLK_DIS_MASK, 1);
regcache_cache_only(cs42l56->regmap, true);
regulator_bulk_disable(ARRAY_SIZE(cs42l56->supplies),
cs42l56->supplies);
break;
}
return 0;
}
static void cs42l56_beep_work(struct work_struct *work)
{
struct cs42l56_private *cs42l56 =
container_of(work, struct cs42l56_private, beep_work);
struct snd_soc_codec *codec = cs42l56->codec;
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
int i;
int val = 0;
int best = 0;
if (cs42l56->beep_rate) {
for (i = 0; i < ARRAY_SIZE(beep_freq); i++) {
if (abs(cs42l56->beep_rate - beep_freq[i]) <
abs(cs42l56->beep_rate - beep_freq[best]))
best = i;
}
dev_dbg(codec->dev, "Set beep rate %dHz for requested %dHz\n",
beep_freq[best], cs42l56->beep_rate);
val = (best << CS42L56_BEEP_RATE_SHIFT);
snd_soc_dapm_enable_pin(dapm, "Beep");
} else {
dev_dbg(codec->dev, "Disabling beep\n");
snd_soc_dapm_disable_pin(dapm, "Beep");
}
snd_soc_update_bits(codec, CS42L56_BEEP_FREQ_ONTIME,
CS42L56_BEEP_FREQ_MASK, val);
snd_soc_dapm_sync(dapm);
}
static int cs42l56_beep_event(struct input_dev *dev, unsigned int type,
unsigned int code, int hz)
{
struct snd_soc_codec *codec = input_get_drvdata(dev);
struct cs42l56_private *cs42l56 = snd_soc_codec_get_drvdata(codec);
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
cs42l56->beep_rate = hz;
schedule_work(&cs42l56->beep_work);
return 0;
}
static ssize_t cs42l56_beep_set(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct cs42l56_private *cs42l56 = dev_get_drvdata(dev);
long int time;
int ret;
ret = kstrtol(buf, 10, &time);
if (ret != 0)
return ret;
input_event(cs42l56->beep, EV_SND, SND_TONE, time);
return count;
}
static void cs42l56_init_beep(struct snd_soc_codec *codec)
{
struct cs42l56_private *cs42l56 = snd_soc_codec_get_drvdata(codec);
int ret;
cs42l56->beep = devm_input_allocate_device(codec->dev);
if (!cs42l56->beep) {
dev_err(codec->dev, "Failed to allocate beep device\n");
return;
}
INIT_WORK(&cs42l56->beep_work, cs42l56_beep_work);
cs42l56->beep_rate = 0;
cs42l56->beep->name = "CS42L56 Beep Generator";
cs42l56->beep->phys = dev_name(codec->dev);
cs42l56->beep->id.bustype = BUS_I2C;
cs42l56->beep->evbit[0] = BIT_MASK(EV_SND);
cs42l56->beep->sndbit[0] = BIT_MASK(SND_BELL) | BIT_MASK(SND_TONE);
cs42l56->beep->event = cs42l56_beep_event;
cs42l56->beep->dev.parent = codec->dev;
input_set_drvdata(cs42l56->beep, codec);
ret = input_register_device(cs42l56->beep);
if (ret != 0) {
cs42l56->beep = NULL;
dev_err(codec->dev, "Failed to register beep device\n");
}
ret = device_create_file(codec->dev, &dev_attr_beep);
if (ret != 0) {
dev_err(codec->dev, "Failed to create keyclick file: %d\n",
ret);
}
}
static void cs42l56_free_beep(struct snd_soc_codec *codec)
{
struct cs42l56_private *cs42l56 = snd_soc_codec_get_drvdata(codec);
device_remove_file(codec->dev, &dev_attr_beep);
cancel_work_sync(&cs42l56->beep_work);
cs42l56->beep = NULL;
snd_soc_update_bits(codec, CS42L56_BEEP_TONE_CFG,
CS42L56_BEEP_EN_MASK, 0);
}
static int cs42l56_probe(struct snd_soc_codec *codec)
{
cs42l56_init_beep(codec);
return 0;
}
static int cs42l56_remove(struct snd_soc_codec *codec)
{
cs42l56_free_beep(codec);
return 0;
}
static int cs42l56_handle_of_data(struct i2c_client *i2c_client,
struct cs42l56_platform_data *pdata)
{
struct device_node *np = i2c_client->dev.of_node;
u32 val32;
if (of_property_read_bool(np, "cirrus,ain1a-reference-cfg"))
pdata->ain1a_ref_cfg = true;
if (of_property_read_bool(np, "cirrus,ain2a-reference-cfg"))
pdata->ain2a_ref_cfg = true;
if (of_property_read_bool(np, "cirrus,ain1b-reference-cfg"))
pdata->ain1b_ref_cfg = true;
if (of_property_read_bool(np, "cirrus,ain2b-reference-cfg"))
pdata->ain2b_ref_cfg = true;
if (of_property_read_u32(np, "cirrus,micbias-lvl", &val32) >= 0)
pdata->micbias_lvl = val32;
if (of_property_read_u32(np, "cirrus,chgfreq-divisor", &val32) >= 0)
pdata->chgfreq = val32;
if (of_property_read_u32(np, "cirrus,adaptive-pwr-cfg", &val32) >= 0)
pdata->adaptive_pwr = val32;
if (of_property_read_u32(np, "cirrus,hpf-left-freq", &val32) >= 0)
pdata->hpfa_freq = val32;
if (of_property_read_u32(np, "cirrus,hpf-left-freq", &val32) >= 0)
pdata->hpfb_freq = val32;
pdata->gpio_nreset = of_get_named_gpio(np, "cirrus,gpio-nreset", 0);
return 0;
}
static int cs42l56_i2c_probe(struct i2c_client *i2c_client,
const struct i2c_device_id *id)
{
struct cs42l56_private *cs42l56;
struct cs42l56_platform_data *pdata =
dev_get_platdata(&i2c_client->dev);
int ret, i;
unsigned int devid = 0;
unsigned int alpha_rev, metal_rev;
unsigned int reg;
cs42l56 = devm_kzalloc(&i2c_client->dev,
sizeof(struct cs42l56_private),
GFP_KERNEL);
if (cs42l56 == NULL)
return -ENOMEM;
cs42l56->dev = &i2c_client->dev;
cs42l56->regmap = devm_regmap_init_i2c(i2c_client, &cs42l56_regmap);
if (IS_ERR(cs42l56->regmap)) {
ret = PTR_ERR(cs42l56->regmap);
dev_err(&i2c_client->dev, "regmap_init() failed: %d\n", ret);
return ret;
}
if (pdata) {
cs42l56->pdata = *pdata;
} else {
pdata = devm_kzalloc(&i2c_client->dev,
sizeof(struct cs42l56_platform_data),
GFP_KERNEL);
if (!pdata) {
dev_err(&i2c_client->dev,
"could not allocate pdata\n");
return -ENOMEM;
}
if (i2c_client->dev.of_node) {
ret = cs42l56_handle_of_data(i2c_client,
&cs42l56->pdata);
if (ret != 0)
return ret;
}
cs42l56->pdata = *pdata;
}
if (cs42l56->pdata.gpio_nreset) {
ret = gpio_request_one(cs42l56->pdata.gpio_nreset,
GPIOF_OUT_INIT_HIGH, "CS42L56 /RST");
if (ret < 0) {
dev_err(&i2c_client->dev,
"Failed to request /RST %d: %d\n",
cs42l56->pdata.gpio_nreset, ret);
return ret;
}
gpio_set_value_cansleep(cs42l56->pdata.gpio_nreset, 0);
gpio_set_value_cansleep(cs42l56->pdata.gpio_nreset, 1);
}
i2c_set_clientdata(i2c_client, cs42l56);
for (i = 0; i < ARRAY_SIZE(cs42l56->supplies); i++)
cs42l56->supplies[i].supply = cs42l56_supply_names[i];
ret = devm_regulator_bulk_get(&i2c_client->dev,
ARRAY_SIZE(cs42l56->supplies),
cs42l56->supplies);
if (ret != 0) {
dev_err(&i2c_client->dev,
"Failed to request supplies: %d\n", ret);
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(cs42l56->supplies),
cs42l56->supplies);
if (ret != 0) {
dev_err(&i2c_client->dev,
"Failed to enable supplies: %d\n", ret);
return ret;
}
ret = regmap_read(cs42l56->regmap, CS42L56_CHIP_ID_1, &reg);
devid = reg & CS42L56_CHIP_ID_MASK;
if (devid != CS42L56_DEVID) {
dev_err(&i2c_client->dev,
"CS42L56 Device ID (%X). Expected %X\n",
devid, CS42L56_DEVID);
goto err_enable;
}
alpha_rev = reg & CS42L56_AREV_MASK;
metal_rev = reg & CS42L56_MTLREV_MASK;
dev_info(&i2c_client->dev, "Cirrus Logic CS42L56 ");
dev_info(&i2c_client->dev, "Alpha Rev %X Metal Rev %X\n",
alpha_rev, metal_rev);
if (cs42l56->pdata.ain1a_ref_cfg)
regmap_update_bits(cs42l56->regmap, CS42L56_AIN_REFCFG_ADC_MUX,
CS42L56_AIN1A_REF_MASK,
CS42L56_AIN1A_REF_MASK);
if (cs42l56->pdata.ain1b_ref_cfg)
regmap_update_bits(cs42l56->regmap, CS42L56_AIN_REFCFG_ADC_MUX,
CS42L56_AIN1B_REF_MASK,
CS42L56_AIN1B_REF_MASK);
if (cs42l56->pdata.ain2a_ref_cfg)
regmap_update_bits(cs42l56->regmap, CS42L56_AIN_REFCFG_ADC_MUX,
CS42L56_AIN2A_REF_MASK,
CS42L56_AIN2A_REF_MASK);
if (cs42l56->pdata.ain2b_ref_cfg)
regmap_update_bits(cs42l56->regmap, CS42L56_AIN_REFCFG_ADC_MUX,
CS42L56_AIN2B_REF_MASK,
CS42L56_AIN2B_REF_MASK);
if (cs42l56->pdata.micbias_lvl)
regmap_update_bits(cs42l56->regmap, CS42L56_GAIN_BIAS_CTL,
CS42L56_MIC_BIAS_MASK,
cs42l56->pdata.micbias_lvl);
if (cs42l56->pdata.chgfreq)
regmap_update_bits(cs42l56->regmap, CS42L56_CLASSH_CTL,
CS42L56_CHRG_FREQ_MASK,
cs42l56->pdata.chgfreq);
if (cs42l56->pdata.hpfb_freq)
regmap_update_bits(cs42l56->regmap, CS42L56_HPF_CTL,
CS42L56_HPFB_FREQ_MASK,
cs42l56->pdata.hpfb_freq);
if (cs42l56->pdata.hpfa_freq)
regmap_update_bits(cs42l56->regmap, CS42L56_HPF_CTL,
CS42L56_HPFA_FREQ_MASK,
cs42l56->pdata.hpfa_freq);
if (cs42l56->pdata.adaptive_pwr)
regmap_update_bits(cs42l56->regmap, CS42L56_CLASSH_CTL,
CS42L56_ADAPT_PWR_MASK,
cs42l56->pdata.adaptive_pwr);
ret = snd_soc_register_codec(&i2c_client->dev,
&soc_codec_dev_cs42l56, &cs42l56_dai, 1);
if (ret < 0)
return ret;
return 0;
err_enable:
regulator_bulk_disable(ARRAY_SIZE(cs42l56->supplies),
cs42l56->supplies);
return ret;
}
static int cs42l56_i2c_remove(struct i2c_client *client)
{
struct cs42l56_private *cs42l56 = i2c_get_clientdata(client);
snd_soc_unregister_codec(&client->dev);
regulator_bulk_disable(ARRAY_SIZE(cs42l56->supplies),
cs42l56->supplies);
return 0;
}
