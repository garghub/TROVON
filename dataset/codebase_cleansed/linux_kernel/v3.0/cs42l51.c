static int cs42l51_fill_cache(struct snd_soc_codec *codec)
{
u8 *cache = codec->reg_cache + 1;
struct i2c_client *i2c_client = codec->control_data;
s32 length;
length = i2c_smbus_read_i2c_block_data(i2c_client,
CS42L51_FIRSTREG | 0x80, CS42L51_NUMREGS, cache);
if (length != CS42L51_NUMREGS) {
dev_err(&i2c_client->dev,
"I2C read failure, addr=0x%x (ret=%d vs %d)\n",
i2c_client->addr, length, CS42L51_NUMREGS);
return -EIO;
}
return 0;
}
static int cs42l51_get_chan_mix(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
unsigned long value = snd_soc_read(codec, CS42L51_PCM_MIXER)&3;
switch (value) {
default:
case 0:
ucontrol->value.integer.value[0] = 0;
break;
case 1:
case 2:
ucontrol->value.integer.value[0] = 1;
break;
case 3:
ucontrol->value.integer.value[0] = 2;
break;
}
return 0;
}
static int cs42l51_set_chan_mix(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
unsigned char val;
switch (ucontrol->value.integer.value[0]) {
default:
case 0:
val = CHAN_MIX_NORMAL;
break;
case 1:
val = CHAN_MIX_BOTH;
break;
case 2:
val = CHAN_MIX_SWAP;
break;
}
snd_soc_write(codec, CS42L51_PCM_MIXER, val);
return 1;
}
static int cs42l51_pdn_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
unsigned long value;
value = snd_soc_read(w->codec, CS42L51_POWER_CTL1);
value &= ~CS42L51_POWER_CTL1_PDN;
switch (event) {
case SND_SOC_DAPM_PRE_PMD:
value |= CS42L51_POWER_CTL1_PDN;
break;
default:
case SND_SOC_DAPM_POST_PMD:
break;
}
snd_soc_update_bits(w->codec, CS42L51_POWER_CTL1,
CS42L51_POWER_CTL1_PDN, value);
return 0;
}
static int cs42l51_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int format)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct cs42l51_private *cs42l51 = snd_soc_codec_get_drvdata(codec);
int ret = 0;
switch (format & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
case SND_SOC_DAIFMT_LEFT_J:
case SND_SOC_DAIFMT_RIGHT_J:
cs42l51->audio_mode = format & SND_SOC_DAIFMT_FORMAT_MASK;
break;
default:
dev_err(codec->dev, "invalid DAI format\n");
ret = -EINVAL;
}
switch (format & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
cs42l51->func = MODE_MASTER;
break;
case SND_SOC_DAIFMT_CBS_CFS:
cs42l51->func = MODE_SLAVE_AUTO;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int cs42l51_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct cs42l51_private *cs42l51 = snd_soc_codec_get_drvdata(codec);
cs42l51->mclk = freq;
return 0;
}
static int cs42l51_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct cs42l51_private *cs42l51 = snd_soc_codec_get_drvdata(codec);
int ret;
unsigned int i;
unsigned int rate;
unsigned int ratio;
struct cs42l51_ratios *ratios = NULL;
int nr_ratios = 0;
int intf_ctl, power_ctl, fmt;
switch (cs42l51->func) {
case MODE_MASTER:
return -EINVAL;
case MODE_SLAVE:
ratios = slave_ratios;
nr_ratios = ARRAY_SIZE(slave_ratios);
break;
case MODE_SLAVE_AUTO:
ratios = slave_auto_ratios;
nr_ratios = ARRAY_SIZE(slave_auto_ratios);
break;
}
rate = params_rate(params);
ratio = cs42l51->mclk / rate;
for (i = 0; i < nr_ratios; i++) {
if (ratios[i].ratio == ratio)
break;
}
if (i == nr_ratios) {
dev_err(codec->dev, "could not find matching ratio\n");
return -EINVAL;
}
intf_ctl = snd_soc_read(codec, CS42L51_INTF_CTL);
power_ctl = snd_soc_read(codec, CS42L51_MIC_POWER_CTL);
intf_ctl &= ~(CS42L51_INTF_CTL_MASTER | CS42L51_INTF_CTL_ADC_I2S
| CS42L51_INTF_CTL_DAC_FORMAT(7));
power_ctl &= ~(CS42L51_MIC_POWER_CTL_SPEED(3)
| CS42L51_MIC_POWER_CTL_MCLK_DIV2);
switch (cs42l51->func) {
case MODE_MASTER:
intf_ctl |= CS42L51_INTF_CTL_MASTER;
power_ctl |= CS42L51_MIC_POWER_CTL_SPEED(ratios[i].speed_mode);
break;
case MODE_SLAVE:
power_ctl |= CS42L51_MIC_POWER_CTL_SPEED(ratios[i].speed_mode);
break;
case MODE_SLAVE_AUTO:
power_ctl |= CS42L51_MIC_POWER_CTL_AUTO;
break;
}
switch (cs42l51->audio_mode) {
case SND_SOC_DAIFMT_I2S:
intf_ctl |= CS42L51_INTF_CTL_ADC_I2S;
intf_ctl |= CS42L51_INTF_CTL_DAC_FORMAT(CS42L51_DAC_DIF_I2S);
break;
case SND_SOC_DAIFMT_LEFT_J:
intf_ctl |= CS42L51_INTF_CTL_DAC_FORMAT(CS42L51_DAC_DIF_LJ24);
break;
case SND_SOC_DAIFMT_RIGHT_J:
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
case SNDRV_PCM_FORMAT_S16_BE:
fmt = CS42L51_DAC_DIF_RJ16;
break;
case SNDRV_PCM_FORMAT_S18_3LE:
case SNDRV_PCM_FORMAT_S18_3BE:
fmt = CS42L51_DAC_DIF_RJ18;
break;
case SNDRV_PCM_FORMAT_S20_3LE:
case SNDRV_PCM_FORMAT_S20_3BE:
fmt = CS42L51_DAC_DIF_RJ20;
break;
case SNDRV_PCM_FORMAT_S24_LE:
case SNDRV_PCM_FORMAT_S24_BE:
fmt = CS42L51_DAC_DIF_RJ24;
break;
default:
dev_err(codec->dev, "unknown format\n");
return -EINVAL;
}
intf_ctl |= CS42L51_INTF_CTL_DAC_FORMAT(fmt);
break;
default:
dev_err(codec->dev, "unknown format\n");
return -EINVAL;
}
if (ratios[i].mclk)
power_ctl |= CS42L51_MIC_POWER_CTL_MCLK_DIV2;
ret = snd_soc_write(codec, CS42L51_INTF_CTL, intf_ctl);
if (ret < 0)
return ret;
ret = snd_soc_write(codec, CS42L51_MIC_POWER_CTL, power_ctl);
if (ret < 0)
return ret;
return 0;
}
static int cs42l51_dai_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
int reg;
int mask = CS42L51_DAC_OUT_CTL_DACA_MUTE|CS42L51_DAC_OUT_CTL_DACB_MUTE;
reg = snd_soc_read(codec, CS42L51_DAC_OUT_CTL);
if (mute)
reg |= mask;
else
reg &= ~mask;
return snd_soc_write(codec, CS42L51_DAC_OUT_CTL, reg);
}
static int cs42l51_probe(struct snd_soc_codec *codec)
{
struct cs42l51_private *cs42l51 = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret, reg;
codec->control_data = cs42l51->control_data;
ret = cs42l51_fill_cache(codec);
if (ret < 0) {
dev_err(codec->dev, "failed to fill register cache\n");
return ret;
}
ret = snd_soc_codec_set_cache_io(codec, 8, 8, cs42l51->control_type);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
reg = CS42L51_DAC_CTL_DATA_SEL(1)
| CS42L51_DAC_CTL_AMUTE | CS42L51_DAC_CTL_DACSZ(0);
ret = snd_soc_write(codec, CS42L51_DAC_CTL, reg);
if (ret < 0)
return ret;
snd_soc_add_controls(codec, cs42l51_snd_controls,
ARRAY_SIZE(cs42l51_snd_controls));
snd_soc_dapm_new_controls(dapm, cs42l51_dapm_widgets,
ARRAY_SIZE(cs42l51_dapm_widgets));
snd_soc_dapm_add_routes(dapm, cs42l51_routes,
ARRAY_SIZE(cs42l51_routes));
return 0;
}
static int cs42l51_i2c_probe(struct i2c_client *i2c_client,
const struct i2c_device_id *id)
{
struct cs42l51_private *cs42l51;
int ret;
ret = i2c_smbus_read_byte_data(i2c_client, CS42L51_CHIP_REV_ID);
if (ret < 0) {
dev_err(&i2c_client->dev, "failed to read I2C\n");
goto error;
}
if ((ret != CS42L51_MK_CHIP_REV(CS42L51_CHIP_ID, CS42L51_CHIP_REV_A)) &&
(ret != CS42L51_MK_CHIP_REV(CS42L51_CHIP_ID, CS42L51_CHIP_REV_B))) {
dev_err(&i2c_client->dev, "Invalid chip id\n");
ret = -ENODEV;
goto error;
}
dev_info(&i2c_client->dev, "found device cs42l51 rev %d\n",
ret & 7);
cs42l51 = kzalloc(sizeof(struct cs42l51_private), GFP_KERNEL);
if (!cs42l51) {
dev_err(&i2c_client->dev, "could not allocate codec\n");
return -ENOMEM;
}
i2c_set_clientdata(i2c_client, cs42l51);
cs42l51->control_data = i2c_client;
cs42l51->control_type = SND_SOC_I2C;
ret = snd_soc_register_codec(&i2c_client->dev,
&soc_codec_device_cs42l51, &cs42l51_dai, 1);
if (ret < 0)
kfree(cs42l51);
error:
return ret;
}
static int cs42l51_i2c_remove(struct i2c_client *client)
{
struct cs42l51_private *cs42l51 = i2c_get_clientdata(client);
snd_soc_unregister_codec(&client->dev);
kfree(cs42l51);
return 0;
}
static int __init cs42l51_init(void)
{
int ret;
ret = i2c_add_driver(&cs42l51_i2c_driver);
if (ret != 0) {
printk(KERN_ERR "%s: can't add i2c driver\n", __func__);
return ret;
}
return 0;
}
static void __exit cs42l51_exit(void)
{
i2c_del_driver(&cs42l51_i2c_driver);
}
