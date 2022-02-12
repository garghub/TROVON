static int cs4270_reg_is_readable(struct snd_soc_codec *codec, unsigned int reg)
{
return (reg >= CS4270_FIRSTREG) && (reg <= CS4270_LASTREG);
}
static int cs4270_reg_is_volatile(struct snd_soc_codec *codec, unsigned int reg)
{
if ((reg < CS4270_FIRSTREG) || (reg > CS4270_LASTREG))
return 1;
return reg == CS4270_CHIPID;
}
static int cs4270_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct cs4270_private *cs4270 = snd_soc_codec_get_drvdata(codec);
cs4270->mclk = freq;
return 0;
}
static int cs4270_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int format)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct cs4270_private *cs4270 = snd_soc_codec_get_drvdata(codec);
switch (format & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
case SND_SOC_DAIFMT_LEFT_J:
cs4270->mode = format & SND_SOC_DAIFMT_FORMAT_MASK;
break;
default:
dev_err(codec->dev, "invalid dai format\n");
return -EINVAL;
}
switch (format & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
cs4270->slave_mode = 1;
break;
case SND_SOC_DAIFMT_CBM_CFM:
cs4270->slave_mode = 0;
break;
default:
dev_err(codec->dev, "Unknown master/slave configuration\n");
return -EINVAL;
}
return 0;
}
static int cs4270_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct cs4270_private *cs4270 = snd_soc_codec_get_drvdata(codec);
int ret;
unsigned int i;
unsigned int rate;
unsigned int ratio;
int reg;
rate = params_rate(params);
ratio = cs4270->mclk / rate;
for (i = 0; i < NUM_MCLK_RATIOS; i++) {
if (cs4270_mode_ratios[i].ratio == ratio)
break;
}
if (i == NUM_MCLK_RATIOS) {
dev_err(codec->dev, "could not find matching ratio\n");
return -EINVAL;
}
reg = snd_soc_read(codec, CS4270_MODE);
reg &= ~(CS4270_MODE_SPEED_MASK | CS4270_MODE_DIV_MASK);
reg |= cs4270_mode_ratios[i].mclk;
if (cs4270->slave_mode)
reg |= CS4270_MODE_SLAVE;
else
reg |= cs4270_mode_ratios[i].speed_mode;
ret = snd_soc_write(codec, CS4270_MODE, reg);
if (ret < 0) {
dev_err(codec->dev, "i2c write failed\n");
return ret;
}
reg = snd_soc_read(codec, CS4270_FORMAT);
reg &= ~(CS4270_FORMAT_DAC_MASK | CS4270_FORMAT_ADC_MASK);
switch (cs4270->mode) {
case SND_SOC_DAIFMT_I2S:
reg |= CS4270_FORMAT_DAC_I2S | CS4270_FORMAT_ADC_I2S;
break;
case SND_SOC_DAIFMT_LEFT_J:
reg |= CS4270_FORMAT_DAC_LJ | CS4270_FORMAT_ADC_LJ;
break;
default:
dev_err(codec->dev, "unknown dai format\n");
return -EINVAL;
}
ret = snd_soc_write(codec, CS4270_FORMAT, reg);
if (ret < 0) {
dev_err(codec->dev, "i2c write failed\n");
return ret;
}
return ret;
}
static int cs4270_dai_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
struct cs4270_private *cs4270 = snd_soc_codec_get_drvdata(codec);
int reg6;
reg6 = snd_soc_read(codec, CS4270_MUTE);
if (mute)
reg6 |= CS4270_MUTE_DAC_A | CS4270_MUTE_DAC_B;
else {
reg6 &= ~(CS4270_MUTE_DAC_A | CS4270_MUTE_DAC_B);
reg6 |= cs4270->manual_mute;
}
return snd_soc_write(codec, CS4270_MUTE, reg6);
}
static int cs4270_soc_put_mute(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct cs4270_private *cs4270 = snd_soc_codec_get_drvdata(codec);
int left = !ucontrol->value.integer.value[0];
int right = !ucontrol->value.integer.value[1];
cs4270->manual_mute = (left ? CS4270_MUTE_DAC_A : 0) |
(right ? CS4270_MUTE_DAC_B : 0);
return snd_soc_put_volsw(kcontrol, ucontrol);
}
static int cs4270_probe(struct snd_soc_codec *codec)
{
struct cs4270_private *cs4270 = snd_soc_codec_get_drvdata(codec);
int i, ret;
ret = snd_soc_codec_set_cache_io(codec, 8, 8, cs4270->control_type);
if (ret < 0) {
dev_err(codec->dev, "failed to set cache I/O (ret=%i)\n", ret);
return ret;
}
ret = snd_soc_update_bits(codec, CS4270_MUTE, CS4270_MUTE_AUTO, 0);
if (ret < 0) {
dev_err(codec->dev, "i2c write failed\n");
return ret;
}
ret = snd_soc_update_bits(codec, CS4270_TRANS,
CS4270_TRANS_SOFT | CS4270_TRANS_ZERO, 0);
if (ret < 0) {
dev_err(codec->dev, "i2c write failed\n");
return ret;
}
ret = snd_soc_add_codec_controls(codec, cs4270_snd_controls,
ARRAY_SIZE(cs4270_snd_controls));
if (ret < 0) {
dev_err(codec->dev, "failed to add controls\n");
return ret;
}
for (i = 0; i < ARRAY_SIZE(supply_names); i++)
cs4270->supplies[i].supply = supply_names[i];
ret = regulator_bulk_get(codec->dev, ARRAY_SIZE(cs4270->supplies),
cs4270->supplies);
if (ret < 0)
return ret;
ret = regulator_bulk_enable(ARRAY_SIZE(cs4270->supplies),
cs4270->supplies);
if (ret < 0)
goto error_free_regulators;
return 0;
error_free_regulators:
regulator_bulk_free(ARRAY_SIZE(cs4270->supplies),
cs4270->supplies);
return ret;
}
static int cs4270_remove(struct snd_soc_codec *codec)
{
struct cs4270_private *cs4270 = snd_soc_codec_get_drvdata(codec);
regulator_bulk_disable(ARRAY_SIZE(cs4270->supplies), cs4270->supplies);
regulator_bulk_free(ARRAY_SIZE(cs4270->supplies), cs4270->supplies);
return 0;
}
static int cs4270_soc_suspend(struct snd_soc_codec *codec)
{
struct cs4270_private *cs4270 = snd_soc_codec_get_drvdata(codec);
int reg, ret;
reg = snd_soc_read(codec, CS4270_PWRCTL) | CS4270_PWRCTL_PDN_ALL;
if (reg < 0)
return reg;
ret = snd_soc_write(codec, CS4270_PWRCTL, reg);
if (ret < 0)
return ret;
regulator_bulk_disable(ARRAY_SIZE(cs4270->supplies),
cs4270->supplies);
return 0;
}
static int cs4270_soc_resume(struct snd_soc_codec *codec)
{
struct cs4270_private *cs4270 = snd_soc_codec_get_drvdata(codec);
int reg;
regulator_bulk_enable(ARRAY_SIZE(cs4270->supplies),
cs4270->supplies);
ndelay(500);
snd_soc_cache_sync(codec);
reg = snd_soc_read(codec, CS4270_PWRCTL);
reg &= ~CS4270_PWRCTL_PDN_ALL;
return snd_soc_write(codec, CS4270_PWRCTL, reg);
}
static int cs4270_i2c_probe(struct i2c_client *i2c_client,
const struct i2c_device_id *id)
{
struct cs4270_private *cs4270;
int ret;
ret = i2c_smbus_read_byte_data(i2c_client, CS4270_CHIPID);
if (ret < 0) {
dev_err(&i2c_client->dev, "failed to read i2c at addr %X\n",
i2c_client->addr);
return ret;
}
if ((ret & 0xF0) != 0xC0) {
dev_err(&i2c_client->dev, "device at addr %X is not a CS4270\n",
i2c_client->addr);
return -ENODEV;
}
dev_info(&i2c_client->dev, "found device at i2c address %X\n",
i2c_client->addr);
dev_info(&i2c_client->dev, "hardware revision %X\n", ret & 0xF);
cs4270 = devm_kzalloc(&i2c_client->dev, sizeof(struct cs4270_private),
GFP_KERNEL);
if (!cs4270) {
dev_err(&i2c_client->dev, "could not allocate codec\n");
return -ENOMEM;
}
i2c_set_clientdata(i2c_client, cs4270);
cs4270->control_type = SND_SOC_I2C;
ret = snd_soc_register_codec(&i2c_client->dev,
&soc_codec_device_cs4270, &cs4270_dai, 1);
return ret;
}
static int cs4270_i2c_remove(struct i2c_client *i2c_client)
{
snd_soc_unregister_codec(&i2c_client->dev);
return 0;
}
static int __init cs4270_init(void)
{
return i2c_add_driver(&cs4270_i2c_driver);
}
static void __exit cs4270_exit(void)
{
i2c_del_driver(&cs4270_i2c_driver);
}
