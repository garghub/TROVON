static int sta32x_coefficient_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int numcoef = kcontrol->private_value >> 16;
uinfo->type = SNDRV_CTL_ELEM_TYPE_BYTES;
uinfo->count = 3 * numcoef;
return 0;
}
static int sta32x_coefficient_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
int numcoef = kcontrol->private_value >> 16;
int index = kcontrol->private_value & 0xffff;
unsigned int cfud;
int i;
cfud = snd_soc_read(codec, STA32X_CFUD) & 0xf0;
snd_soc_write(codec, STA32X_CFUD, cfud);
snd_soc_write(codec, STA32X_CFADDR2, index);
if (numcoef == 1)
snd_soc_write(codec, STA32X_CFUD, cfud | 0x04);
else if (numcoef == 5)
snd_soc_write(codec, STA32X_CFUD, cfud | 0x08);
else
return -EINVAL;
for (i = 0; i < 3 * numcoef; i++)
ucontrol->value.bytes.data[i] =
snd_soc_read(codec, STA32X_B1CF1 + i);
return 0;
}
static int sta32x_coefficient_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
int numcoef = kcontrol->private_value >> 16;
int index = kcontrol->private_value & 0xffff;
unsigned int cfud;
int i;
cfud = snd_soc_read(codec, STA32X_CFUD) & 0xf0;
snd_soc_write(codec, STA32X_CFUD, cfud);
snd_soc_write(codec, STA32X_CFADDR2, index);
for (i = 0; i < 3 * numcoef; i++)
snd_soc_write(codec, STA32X_B1CF1 + i,
ucontrol->value.bytes.data[i]);
if (numcoef == 1)
snd_soc_write(codec, STA32X_CFUD, cfud | 0x01);
else if (numcoef == 5)
snd_soc_write(codec, STA32X_CFUD, cfud | 0x02);
else
return -EINVAL;
return 0;
}
static int sta32x_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct sta32x_priv *sta32x = snd_soc_codec_get_drvdata(codec);
int i, j, ir, fs;
unsigned int rates = 0;
unsigned int rate_min = -1;
unsigned int rate_max = 0;
pr_debug("mclk=%u\n", freq);
sta32x->mclk = freq;
if (sta32x->mclk) {
for (i = 0; i < ARRAY_SIZE(interpolation_ratios); i++) {
ir = interpolation_ratios[i].ir;
fs = interpolation_ratios[i].fs;
for (j = 0; mclk_ratios[ir][j].ratio; j++) {
if (mclk_ratios[ir][j].ratio * fs == freq) {
rates |= snd_pcm_rate_to_rate_bit(fs);
if (fs < rate_min)
rate_min = fs;
if (fs > rate_max)
rate_max = fs;
}
}
}
rates &= ~SNDRV_PCM_RATE_KNOT;
if (!rates) {
dev_err(codec->dev, "could not find a valid sample rate\n");
return -EINVAL;
}
} else {
rates = STA32X_RATES;
rate_min = 32000;
rate_max = 192000;
}
codec_dai->driver->playback.rates = rates;
codec_dai->driver->playback.rate_min = rate_min;
codec_dai->driver->playback.rate_max = rate_max;
return 0;
}
static int sta32x_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct sta32x_priv *sta32x = snd_soc_codec_get_drvdata(codec);
u8 confb = snd_soc_read(codec, STA32X_CONFB);
pr_debug("\n");
confb &= ~(STA32X_CONFB_C1IM | STA32X_CONFB_C2IM);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
case SND_SOC_DAIFMT_RIGHT_J:
case SND_SOC_DAIFMT_LEFT_J:
sta32x->format = fmt & SND_SOC_DAIFMT_FORMAT_MASK;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
confb |= STA32X_CONFB_C2IM;
break;
case SND_SOC_DAIFMT_NB_IF:
confb |= STA32X_CONFB_C1IM;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, STA32X_CONFB, confb);
return 0;
}
static int sta32x_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct sta32x_priv *sta32x = snd_soc_codec_get_drvdata(codec);
unsigned int rate;
int i, mcs = -1, ir = -1;
u8 confa, confb;
rate = params_rate(params);
pr_debug("rate: %u\n", rate);
for (i = 0; i < ARRAY_SIZE(interpolation_ratios); i++)
if (interpolation_ratios[i].fs == rate)
ir = interpolation_ratios[i].ir;
if (ir < 0)
return -EINVAL;
for (i = 0; mclk_ratios[ir][i].ratio; i++)
if (mclk_ratios[ir][i].ratio * rate == sta32x->mclk)
mcs = mclk_ratios[ir][i].mcs;
if (mcs < 0)
return -EINVAL;
confa = snd_soc_read(codec, STA32X_CONFA);
confa &= ~(STA32X_CONFA_MCS_MASK | STA32X_CONFA_IR_MASK);
confa |= (ir << STA32X_CONFA_IR_SHIFT) | (mcs << STA32X_CONFA_MCS_SHIFT);
confb = snd_soc_read(codec, STA32X_CONFB);
confb &= ~(STA32X_CONFB_SAI_MASK | STA32X_CONFB_SAIFB);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S24_LE:
case SNDRV_PCM_FORMAT_S24_BE:
case SNDRV_PCM_FORMAT_S24_3LE:
case SNDRV_PCM_FORMAT_S24_3BE:
pr_debug("24bit\n");
case SNDRV_PCM_FORMAT_S32_LE:
case SNDRV_PCM_FORMAT_S32_BE:
pr_debug("24bit or 32bit\n");
switch (sta32x->format) {
case SND_SOC_DAIFMT_I2S:
confb |= 0x0;
break;
case SND_SOC_DAIFMT_LEFT_J:
confb |= 0x1;
break;
case SND_SOC_DAIFMT_RIGHT_J:
confb |= 0x2;
break;
}
break;
case SNDRV_PCM_FORMAT_S20_3LE:
case SNDRV_PCM_FORMAT_S20_3BE:
pr_debug("20bit\n");
switch (sta32x->format) {
case SND_SOC_DAIFMT_I2S:
confb |= 0x4;
break;
case SND_SOC_DAIFMT_LEFT_J:
confb |= 0x5;
break;
case SND_SOC_DAIFMT_RIGHT_J:
confb |= 0x6;
break;
}
break;
case SNDRV_PCM_FORMAT_S18_3LE:
case SNDRV_PCM_FORMAT_S18_3BE:
pr_debug("18bit\n");
switch (sta32x->format) {
case SND_SOC_DAIFMT_I2S:
confb |= 0x8;
break;
case SND_SOC_DAIFMT_LEFT_J:
confb |= 0x9;
break;
case SND_SOC_DAIFMT_RIGHT_J:
confb |= 0xa;
break;
}
break;
case SNDRV_PCM_FORMAT_S16_LE:
case SNDRV_PCM_FORMAT_S16_BE:
pr_debug("16bit\n");
switch (sta32x->format) {
case SND_SOC_DAIFMT_I2S:
confb |= 0x0;
break;
case SND_SOC_DAIFMT_LEFT_J:
confb |= 0xd;
break;
case SND_SOC_DAIFMT_RIGHT_J:
confb |= 0xe;
break;
}
break;
default:
return -EINVAL;
}
snd_soc_write(codec, STA32X_CONFA, confa);
snd_soc_write(codec, STA32X_CONFB, confb);
return 0;
}
static int sta32x_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
int ret;
struct sta32x_priv *sta32x = snd_soc_codec_get_drvdata(codec);
pr_debug("level = %d\n", level);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, STA32X_CONFF,
STA32X_CONFF_PWDN | STA32X_CONFF_EAPD,
STA32X_CONFF_PWDN | STA32X_CONFF_EAPD);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
ret = regulator_bulk_enable(ARRAY_SIZE(sta32x->supplies),
sta32x->supplies);
if (ret != 0) {
dev_err(codec->dev,
"Failed to enable supplies: %d\n", ret);
return ret;
}
snd_soc_cache_sync(codec);
}
snd_soc_update_bits(codec, STA32X_CONFF,
STA32X_CONFF_PWDN | STA32X_CONFF_EAPD,
STA32X_CONFF_PWDN | STA32X_CONFF_EAPD);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, STA32X_CONFF,
STA32X_CONFF_PWDN | STA32X_CONFF_EAPD,
STA32X_CONFF_PWDN);
msleep(300);
regulator_bulk_disable(ARRAY_SIZE(sta32x->supplies),
sta32x->supplies);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int sta32x_suspend(struct snd_soc_codec *codec, pm_message_t state)
{
sta32x_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int sta32x_resume(struct snd_soc_codec *codec)
{
sta32x_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int sta32x_probe(struct snd_soc_codec *codec)
{
struct sta32x_priv *sta32x = snd_soc_codec_get_drvdata(codec);
int i, ret = 0;
sta32x->codec = codec;
for (i = 0; i < ARRAY_SIZE(sta32x->supplies); i++)
sta32x->supplies[i].supply = sta32x_supply_names[i];
ret = regulator_bulk_get(codec->dev, ARRAY_SIZE(sta32x->supplies),
sta32x->supplies);
if (ret != 0) {
dev_err(codec->dev, "Failed to request supplies: %d\n", ret);
goto err;
}
ret = regulator_bulk_enable(ARRAY_SIZE(sta32x->supplies),
sta32x->supplies);
if (ret != 0) {
dev_err(codec->dev, "Failed to enable supplies: %d\n", ret);
goto err_get;
}
ret = snd_soc_codec_set_cache_io(codec, 8, 8, SND_SOC_I2C);
if (ret < 0) {
dev_err(codec->dev, "failed to set cache I/O (ret=%i)\n", ret);
return ret;
}
for (i = 0; i < STA32X_REGISTER_COUNT; i++)
snd_soc_cache_write(codec, i, sta32x_regs[i]);
snd_soc_cache_write(codec, STA32X_CONFC,
codec->hw_read(codec, STA32X_CONFC));
snd_soc_cache_write(codec, STA32X_CONFE,
codec->hw_read(codec, STA32X_CONFE));
snd_soc_cache_write(codec, STA32X_CONFF,
codec->hw_read(codec, STA32X_CONFF));
snd_soc_cache_write(codec, STA32X_MMUTE,
codec->hw_read(codec, STA32X_MMUTE));
snd_soc_cache_write(codec, STA32X_AUTO1,
codec->hw_read(codec, STA32X_AUTO1));
snd_soc_cache_write(codec, STA32X_AUTO3,
codec->hw_read(codec, STA32X_AUTO3));
snd_soc_cache_write(codec, STA32X_C3CFG,
codec->hw_read(codec, STA32X_C3CFG));
snd_soc_update_bits(codec, STA32X_CONFA,
STA32X_CONFA_TWAB | STA32X_CONFA_TWRB, 0);
snd_soc_update_bits(codec, STA32X_CONFF,
STA32X_CONFF_OCFG_MASK,
1 << STA32X_CONFF_OCFG_SHIFT);
snd_soc_update_bits(codec, STA32X_C1CFG,
STA32X_CxCFG_OM_MASK,
0 << STA32X_CxCFG_OM_SHIFT);
snd_soc_update_bits(codec, STA32X_C2CFG,
STA32X_CxCFG_OM_MASK,
1 << STA32X_CxCFG_OM_SHIFT);
snd_soc_update_bits(codec, STA32X_C3CFG,
STA32X_CxCFG_OM_MASK,
2 << STA32X_CxCFG_OM_SHIFT);
sta32x_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
regulator_bulk_disable(ARRAY_SIZE(sta32x->supplies), sta32x->supplies);
return 0;
err_get:
regulator_bulk_free(ARRAY_SIZE(sta32x->supplies), sta32x->supplies);
err:
return ret;
}
static int sta32x_remove(struct snd_soc_codec *codec)
{
struct sta32x_priv *sta32x = snd_soc_codec_get_drvdata(codec);
regulator_bulk_disable(ARRAY_SIZE(sta32x->supplies), sta32x->supplies);
regulator_bulk_free(ARRAY_SIZE(sta32x->supplies), sta32x->supplies);
return 0;
}
static int sta32x_reg_is_volatile(struct snd_soc_codec *codec,
unsigned int reg)
{
switch (reg) {
case STA32X_CONFA ... STA32X_L2ATRT:
case STA32X_MPCC1 ... STA32X_FDRC2:
return 0;
}
return 1;
}
static __devinit int sta32x_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct sta32x_priv *sta32x;
int ret;
sta32x = kzalloc(sizeof(struct sta32x_priv), GFP_KERNEL);
if (!sta32x)
return -ENOMEM;
i2c_set_clientdata(i2c, sta32x);
ret = snd_soc_register_codec(&i2c->dev, &sta32x_codec, &sta32x_dai, 1);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to register codec (%d)\n", ret);
kfree(sta32x);
return ret;
}
return 0;
}
static __devexit int sta32x_i2c_remove(struct i2c_client *client)
{
struct sta32x_priv *sta32x = i2c_get_clientdata(client);
struct snd_soc_codec *codec = sta32x->codec;
if (codec)
sta32x_set_bias_level(codec, SND_SOC_BIAS_OFF);
regulator_bulk_free(ARRAY_SIZE(sta32x->supplies), sta32x->supplies);
if (codec) {
snd_soc_unregister_codec(&client->dev);
snd_soc_codec_set_drvdata(codec, NULL);
}
kfree(sta32x);
return 0;
}
static int __init sta32x_init(void)
{
return i2c_add_driver(&sta32x_i2c_driver);
}
static void __exit sta32x_exit(void)
{
i2c_del_driver(&sta32x_i2c_driver);
}
