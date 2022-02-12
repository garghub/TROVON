static bool max98926_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX98926_VBAT_DATA:
case MAX98926_VBST_DATA:
case MAX98926_LIVE_STATUS0:
case MAX98926_LIVE_STATUS1:
case MAX98926_LIVE_STATUS2:
case MAX98926_STATE0:
case MAX98926_STATE1:
case MAX98926_STATE2:
case MAX98926_FLAG0:
case MAX98926_FLAG1:
case MAX98926_FLAG2:
case MAX98926_VERSION:
return true;
default:
return false;
}
}
static bool max98926_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX98926_IRQ_CLEAR0:
case MAX98926_IRQ_CLEAR1:
case MAX98926_IRQ_CLEAR2:
case MAX98926_ALC_HOLD_RLS:
return false;
default:
return true;
}
}
static void max98926_set_sense_data(struct max98926_priv *max98926)
{
regmap_update_bits(max98926->regmap,
MAX98926_DOUT_CFG_VMON,
MAX98926_DAI_VMON_EN_MASK,
MAX98926_DAI_VMON_EN_MASK);
regmap_update_bits(max98926->regmap,
MAX98926_DOUT_CFG_IMON,
MAX98926_DAI_IMON_EN_MASK,
MAX98926_DAI_IMON_EN_MASK);
if (!max98926->interleave_mode) {
regmap_update_bits(max98926->regmap,
MAX98926_DOUT_CFG_VMON,
MAX98926_DAI_VMON_SLOT_MASK,
max98926->v_slot);
regmap_update_bits(max98926->regmap,
MAX98926_DOUT_CFG_IMON,
MAX98926_DAI_IMON_SLOT_MASK,
max98926->i_slot);
} else {
regmap_update_bits(max98926->regmap,
MAX98926_FORMAT,
MAX98926_DAI_INTERLEAVE_MASK,
MAX98926_DAI_INTERLEAVE_MASK);
regmap_update_bits(max98926->regmap,
MAX98926_DOUT_CFG_VBAT,
MAX98926_DAI_INTERLEAVE_SLOT_MASK,
max98926->v_slot);
}
}
static int max98926_dai_set_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct max98926_priv *max98926 = snd_soc_codec_get_drvdata(codec);
unsigned int invert = 0;
dev_dbg(codec->dev, "%s: fmt 0x%08X\n", __func__, fmt);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
max98926_set_sense_data(max98926);
break;
default:
dev_err(codec->dev, "DAI clock mode unsupported");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_NB_IF:
invert = MAX98926_DAI_WCI_MASK;
break;
case SND_SOC_DAIFMT_IB_NF:
invert = MAX98926_DAI_BCI_MASK;
break;
case SND_SOC_DAIFMT_IB_IF:
invert = MAX98926_DAI_BCI_MASK | MAX98926_DAI_WCI_MASK;
break;
default:
dev_err(codec->dev, "DAI invert mode unsupported");
return -EINVAL;
}
regmap_write(max98926->regmap,
MAX98926_FORMAT, MAX98926_DAI_DLY_MASK);
regmap_update_bits(max98926->regmap, MAX98926_FORMAT,
MAX98926_DAI_BCI_MASK, invert);
return 0;
}
static int max98926_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
int dai_sr = -EINVAL;
int rate = params_rate(params), i;
struct snd_soc_codec *codec = dai->codec;
struct max98926_priv *max98926 = snd_soc_codec_get_drvdata(codec);
int blr_clk_ratio;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
regmap_update_bits(max98926->regmap,
MAX98926_FORMAT,
MAX98926_DAI_CHANSZ_MASK,
MAX98926_DAI_CHANSZ_16);
max98926->ch_size = 16;
break;
case SNDRV_PCM_FORMAT_S24_LE:
regmap_update_bits(max98926->regmap,
MAX98926_FORMAT,
MAX98926_DAI_CHANSZ_MASK,
MAX98926_DAI_CHANSZ_24);
max98926->ch_size = 24;
break;
case SNDRV_PCM_FORMAT_S32_LE:
regmap_update_bits(max98926->regmap,
MAX98926_FORMAT,
MAX98926_DAI_CHANSZ_MASK,
MAX98926_DAI_CHANSZ_32);
max98926->ch_size = 32;
break;
default:
dev_dbg(codec->dev, "format unsupported %d",
params_format(params));
return -EINVAL;
}
blr_clk_ratio = params_channels(params) * max98926->ch_size;
switch (blr_clk_ratio) {
case 32:
regmap_update_bits(max98926->regmap,
MAX98926_DAI_CLK_MODE2,
MAX98926_DAI_BSEL_MASK,
MAX98926_DAI_BSEL_32);
break;
case 48:
regmap_update_bits(max98926->regmap,
MAX98926_DAI_CLK_MODE2,
MAX98926_DAI_BSEL_MASK,
MAX98926_DAI_BSEL_48);
break;
case 64:
regmap_update_bits(max98926->regmap,
MAX98926_DAI_CLK_MODE2,
MAX98926_DAI_BSEL_MASK,
MAX98926_DAI_BSEL_64);
break;
default:
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(rate_table); i++) {
if (rate_table[i].rate >= rate) {
dai_sr = rate_table[i].sr;
break;
}
}
if (dai_sr < 0)
return -EINVAL;
regmap_update_bits(max98926->regmap,
MAX98926_DAI_CLK_MODE2,
MAX98926_DAI_SR_MASK, dai_sr << MAX98926_DAI_SR_SHIFT);
return 0;
}
static int max98926_probe(struct snd_soc_codec *codec)
{
struct max98926_priv *max98926 = snd_soc_codec_get_drvdata(codec);
max98926->codec = codec;
codec->control_data = max98926->regmap;
regmap_write(max98926->regmap, MAX98926_DOUT_HIZ_CFG4, 0xF0);
return 0;
}
static int max98926_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
int ret, reg;
u32 value;
struct max98926_priv *max98926;
max98926 = devm_kzalloc(&i2c->dev,
sizeof(*max98926), GFP_KERNEL);
if (!max98926)
return -ENOMEM;
i2c_set_clientdata(i2c, max98926);
max98926->regmap = devm_regmap_init_i2c(i2c, &max98926_regmap);
if (IS_ERR(max98926->regmap)) {
ret = PTR_ERR(max98926->regmap);
dev_err(&i2c->dev,
"Failed to allocate regmap: %d\n", ret);
goto err_out;
}
if (of_property_read_bool(i2c->dev.of_node, "interleave-mode"))
max98926->interleave_mode = true;
if (!of_property_read_u32(i2c->dev.of_node, "vmon-slot-no", &value)) {
if (value > MAX98926_DAI_VMON_SLOT_1E_1F) {
dev_err(&i2c->dev, "vmon slot number is wrong:\n");
return -EINVAL;
}
max98926->v_slot = value;
}
if (!of_property_read_u32(i2c->dev.of_node, "imon-slot-no", &value)) {
if (value > MAX98926_DAI_IMON_SLOT_1E_1F) {
dev_err(&i2c->dev, "imon slot number is wrong:\n");
return -EINVAL;
}
max98926->i_slot = value;
}
ret = regmap_read(max98926->regmap,
MAX98926_VERSION, &reg);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to read: %x\n", reg);
return ret;
}
ret = snd_soc_register_codec(&i2c->dev, &soc_codec_dev_max98926,
max98926_dai, ARRAY_SIZE(max98926_dai));
if (ret < 0)
dev_err(&i2c->dev,
"Failed to register codec: %d\n", ret);
dev_info(&i2c->dev, "device version: %x\n", reg);
err_out:
return ret;
}
static int max98926_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
