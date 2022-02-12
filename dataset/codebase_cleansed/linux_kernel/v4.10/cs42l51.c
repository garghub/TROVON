static int cs42l51_get_chan_mix(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
unsigned long value = snd_soc_read(codec, CS42L51_PCM_MIXER)&3;
switch (value) {
default:
case 0:
ucontrol->value.enumerated.item[0] = 0;
break;
case 1:
case 2:
ucontrol->value.enumerated.item[0] = 1;
break;
case 3:
ucontrol->value.enumerated.item[0] = 2;
break;
}
return 0;
}
static int cs42l51_set_chan_mix(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
unsigned char val;
switch (ucontrol->value.enumerated.item[0]) {
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
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, CS42L51_POWER_CTL1,
CS42L51_POWER_CTL1_PDN,
CS42L51_POWER_CTL1_PDN);
break;
default:
case SND_SOC_DAPM_POST_PMD:
snd_soc_update_bits(codec, CS42L51_POWER_CTL1,
CS42L51_POWER_CTL1_PDN, 0);
break;
}
return 0;
}
static int cs42l51_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int format)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct cs42l51_private *cs42l51 = snd_soc_codec_get_drvdata(codec);
switch (format & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
case SND_SOC_DAIFMT_LEFT_J:
case SND_SOC_DAIFMT_RIGHT_J:
cs42l51->audio_mode = format & SND_SOC_DAIFMT_FORMAT_MASK;
break;
default:
dev_err(codec->dev, "invalid DAI format\n");
return -EINVAL;
}
switch (format & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
cs42l51->func = MODE_MASTER;
break;
case SND_SOC_DAIFMT_CBS_CFS:
cs42l51->func = MODE_SLAVE_AUTO;
break;
default:
dev_err(codec->dev, "Unknown master/slave configuration\n");
return -EINVAL;
}
return 0;
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
struct snd_soc_codec *codec = dai->codec;
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
switch (params_width(params)) {
case 16:
fmt = CS42L51_DAC_DIF_RJ16;
break;
case 18:
fmt = CS42L51_DAC_DIF_RJ18;
break;
case 20:
fmt = CS42L51_DAC_DIF_RJ20;
break;
case 24:
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
static int cs42l51_codec_probe(struct snd_soc_codec *codec)
{
int ret, reg;
reg = CS42L51_DAC_CTL_DATA_SEL(1)
| CS42L51_DAC_CTL_AMUTE | CS42L51_DAC_CTL_DACSZ(0);
ret = snd_soc_write(codec, CS42L51_DAC_CTL, reg);
if (ret < 0)
return ret;
return 0;
}
int cs42l51_probe(struct device *dev, struct regmap *regmap)
{
struct cs42l51_private *cs42l51;
unsigned int val;
int ret;
if (IS_ERR(regmap))
return PTR_ERR(regmap);
cs42l51 = devm_kzalloc(dev, sizeof(struct cs42l51_private),
GFP_KERNEL);
if (!cs42l51)
return -ENOMEM;
dev_set_drvdata(dev, cs42l51);
ret = regmap_read(regmap, CS42L51_CHIP_REV_ID, &val);
if (ret < 0) {
dev_err(dev, "failed to read I2C\n");
goto error;
}
if ((val != CS42L51_MK_CHIP_REV(CS42L51_CHIP_ID, CS42L51_CHIP_REV_A)) &&
(val != CS42L51_MK_CHIP_REV(CS42L51_CHIP_ID, CS42L51_CHIP_REV_B))) {
dev_err(dev, "Invalid chip id: %x\n", val);
ret = -ENODEV;
goto error;
}
dev_info(dev, "Cirrus Logic CS42L51, Revision: %02X\n",
val & CS42L51_CHIP_REV_MASK);
ret = snd_soc_register_codec(dev,
&soc_codec_device_cs42l51, &cs42l51_dai, 1);
error:
return ret;
}
