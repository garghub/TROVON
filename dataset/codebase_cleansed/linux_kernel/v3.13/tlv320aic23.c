static int snd_soc_tlv320aic23_put_volsw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
u16 val, reg;
val = (ucontrol->value.integer.value[0] & 0x07);
val = (val >= 4) ? 4 : (3 - val);
reg = snd_soc_read(codec, TLV320AIC23_ANLG) & (~0x1C0);
snd_soc_write(codec, TLV320AIC23_ANLG, reg | (val << 6));
return 0;
}
static int snd_soc_tlv320aic23_get_volsw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
u16 val;
val = snd_soc_read(codec, TLV320AIC23_ANLG) & (0x1C0);
val = val >> 6;
val = (val >= 4) ? 4 : (3 - val);
ucontrol->value.integer.value[0] = val;
return 0;
}
static unsigned get_score(int adc, int adc_l, int adc_h, int need_adc,
int dac, int dac_l, int dac_h, int need_dac)
{
if ((adc >= adc_l) && (adc <= adc_h) &&
(dac >= dac_l) && (dac <= dac_h)) {
int diff_adc = need_adc - adc;
int diff_dac = need_dac - dac;
return abs(diff_adc) + abs(diff_dac);
}
return UINT_MAX;
}
static int find_rate(int mclk, u32 need_adc, u32 need_dac)
{
int i, j;
int best_i = -1;
int best_j = -1;
int best_div = 0;
unsigned best_score = UINT_MAX;
int adc_l, adc_h, dac_l, dac_h;
need_adc *= SR_MULT;
need_dac *= SR_MULT;
adc_l = need_adc - (need_adc >> 5);
adc_h = need_adc + (need_adc >> 5);
dac_l = need_dac - (need_dac >> 5);
dac_h = need_dac + (need_dac >> 5);
for (i = 0; i < ARRAY_SIZE(bosr_usb_divisor_table); i++) {
int base = mclk / bosr_usb_divisor_table[i];
int mask = sr_valid_mask[i];
for (j = 0; j < ARRAY_SIZE(sr_adc_mult_table);
j++, mask >>= 1) {
int adc;
int dac;
int score;
if ((mask & 1) == 0)
continue;
adc = base * sr_adc_mult_table[j];
dac = base * sr_dac_mult_table[j];
score = get_score(adc, adc_l, adc_h, need_adc,
dac, dac_l, dac_h, need_dac);
if (best_score > score) {
best_score = score;
best_i = i;
best_j = j;
best_div = 0;
}
score = get_score((adc >> 1), adc_l, adc_h, need_adc,
(dac >> 1), dac_l, dac_h, need_dac);
if ((score != UINT_MAX) && (best_score >= score)) {
best_score = score;
best_i = i;
best_j = j;
best_div = 1;
}
}
}
return (best_j << 2) | best_i | (best_div << TLV320AIC23_CLKIN_SHIFT);
}
static void get_current_sample_rates(struct snd_soc_codec *codec, int mclk,
u32 *sample_rate_adc, u32 *sample_rate_dac)
{
int src = snd_soc_read(codec, TLV320AIC23_SRATE);
int sr = (src >> 2) & 0x0f;
int val = (mclk / bosr_usb_divisor_table[src & 3]);
int adc = (val * sr_adc_mult_table[sr]) / SR_MULT;
int dac = (val * sr_dac_mult_table[sr]) / SR_MULT;
if (src & TLV320AIC23_CLKIN_HALF) {
adc >>= 1;
dac >>= 1;
}
*sample_rate_adc = adc;
*sample_rate_dac = dac;
}
static int set_sample_rate_control(struct snd_soc_codec *codec, int mclk,
u32 sample_rate_adc, u32 sample_rate_dac)
{
int data = find_rate(mclk, sample_rate_adc, sample_rate_dac);
if (data < 0) {
printk(KERN_ERR "%s:Invalid rate %u,%u requested\n",
__func__, sample_rate_adc, sample_rate_dac);
return -EINVAL;
}
snd_soc_write(codec, TLV320AIC23_SRATE, data);
#ifdef DEBUG
{
u32 adc, dac;
get_current_sample_rates(codec, mclk, &adc, &dac);
printk(KERN_DEBUG "actual samplerate = %u,%u reg=%x\n",
adc, dac, data);
}
#endif
return 0;
}
static int tlv320aic23_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
u16 iface_reg;
int ret;
struct aic23 *aic23 = snd_soc_codec_get_drvdata(codec);
u32 sample_rate_adc = aic23->requested_adc;
u32 sample_rate_dac = aic23->requested_dac;
u32 sample_rate = params_rate(params);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
aic23->requested_dac = sample_rate_dac = sample_rate;
if (!sample_rate_adc)
sample_rate_adc = sample_rate;
} else {
aic23->requested_adc = sample_rate_adc = sample_rate;
if (!sample_rate_dac)
sample_rate_dac = sample_rate;
}
ret = set_sample_rate_control(codec, aic23->mclk, sample_rate_adc,
sample_rate_dac);
if (ret < 0)
return ret;
iface_reg = snd_soc_read(codec, TLV320AIC23_DIGT_FMT) & ~(0x03 << 2);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
iface_reg |= (0x01 << 2);
break;
case SNDRV_PCM_FORMAT_S24_LE:
iface_reg |= (0x02 << 2);
break;
case SNDRV_PCM_FORMAT_S32_LE:
iface_reg |= (0x03 << 2);
break;
}
snd_soc_write(codec, TLV320AIC23_DIGT_FMT, iface_reg);
return 0;
}
static int tlv320aic23_pcm_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
snd_soc_write(codec, TLV320AIC23_ACTIVE, 0x0001);
return 0;
}
static void tlv320aic23_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct aic23 *aic23 = snd_soc_codec_get_drvdata(codec);
if (!codec->active) {
udelay(50);
snd_soc_write(codec, TLV320AIC23_ACTIVE, 0x0);
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
aic23->requested_dac = 0;
else
aic23->requested_adc = 0;
}
static int tlv320aic23_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u16 reg;
reg = snd_soc_read(codec, TLV320AIC23_DIGT);
if (mute)
reg |= TLV320AIC23_DACM_MUTE;
else
reg &= ~TLV320AIC23_DACM_MUTE;
snd_soc_write(codec, TLV320AIC23_DIGT, reg);
return 0;
}
static int tlv320aic23_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 iface_reg;
iface_reg = snd_soc_read(codec, TLV320AIC23_DIGT_FMT) & (~0x03);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
iface_reg |= TLV320AIC23_MS_MASTER;
break;
case SND_SOC_DAIFMT_CBS_CFS:
iface_reg &= ~TLV320AIC23_MS_MASTER;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
iface_reg |= TLV320AIC23_FOR_I2S;
break;
case SND_SOC_DAIFMT_DSP_A:
iface_reg |= TLV320AIC23_LRP_ON;
case SND_SOC_DAIFMT_DSP_B:
iface_reg |= TLV320AIC23_FOR_DSP;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
iface_reg |= TLV320AIC23_FOR_LJUST;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, TLV320AIC23_DIGT_FMT, iface_reg);
return 0;
}
static int tlv320aic23_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct aic23 *aic23 = snd_soc_dai_get_drvdata(codec_dai);
aic23->mclk = freq;
return 0;
}
static int tlv320aic23_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
u16 reg = snd_soc_read(codec, TLV320AIC23_PWR) & 0x17f;
switch (level) {
case SND_SOC_BIAS_ON:
reg &= ~(TLV320AIC23_DEVICE_PWR_OFF | TLV320AIC23_OSC_OFF | \
TLV320AIC23_DAC_OFF);
snd_soc_write(codec, TLV320AIC23_PWR, reg);
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
snd_soc_write(codec, TLV320AIC23_PWR,
reg | TLV320AIC23_CLK_OFF);
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, TLV320AIC23_ACTIVE, 0x0);
snd_soc_write(codec, TLV320AIC23_PWR, 0x1ff);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int tlv320aic23_suspend(struct snd_soc_codec *codec)
{
tlv320aic23_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int tlv320aic23_resume(struct snd_soc_codec *codec)
{
struct aic23 *aic23 = snd_soc_codec_get_drvdata(codec);
regcache_mark_dirty(aic23->regmap);
regcache_sync(aic23->regmap);
tlv320aic23_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int tlv320aic23_probe(struct snd_soc_codec *codec)
{
int ret;
ret = snd_soc_codec_set_cache_io(codec, 7, 9, SND_SOC_REGMAP);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
snd_soc_write(codec, TLV320AIC23_RESET, 0);
tlv320aic23_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
snd_soc_write(codec, TLV320AIC23_DIGT, TLV320AIC23_DEEMP_44K);
snd_soc_update_bits(codec, TLV320AIC23_LINVOL,
TLV320AIC23_LIM_MUTED, TLV320AIC23_LRS_ENABLED);
snd_soc_update_bits(codec, TLV320AIC23_RINVOL,
TLV320AIC23_LIM_MUTED, TLV320AIC23_LRS_ENABLED);
snd_soc_update_bits(codec, TLV320AIC23_ANLG,
TLV320AIC23_BYPASS_ON | TLV320AIC23_MICM_MUTED,
0);
snd_soc_write(codec, TLV320AIC23_LCHNVOL,
TLV320AIC23_DEFAULT_OUT_VOL & TLV320AIC23_OUT_VOL_MASK);
snd_soc_write(codec, TLV320AIC23_RCHNVOL,
TLV320AIC23_DEFAULT_OUT_VOL & TLV320AIC23_OUT_VOL_MASK);
snd_soc_write(codec, TLV320AIC23_ACTIVE, 0x1);
return 0;
}
static int tlv320aic23_remove(struct snd_soc_codec *codec)
{
tlv320aic23_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int tlv320aic23_codec_probe(struct i2c_client *i2c,
const struct i2c_device_id *i2c_id)
{
struct aic23 *aic23;
int ret;
if (!i2c_check_functionality(i2c->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EINVAL;
aic23 = devm_kzalloc(&i2c->dev, sizeof(struct aic23), GFP_KERNEL);
if (aic23 == NULL)
return -ENOMEM;
aic23->regmap = devm_regmap_init_i2c(i2c, &tlv320aic23_regmap);
if (IS_ERR(aic23->regmap))
return PTR_ERR(aic23->regmap);
i2c_set_clientdata(i2c, aic23);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_tlv320aic23, &tlv320aic23_dai, 1);
return ret;
}
static int __exit tlv320aic23_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
