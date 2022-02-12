static int tas5720_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int rate = params_rate(params);
bool ssz_ds;
int ret;
switch (rate) {
case 44100:
case 48000:
ssz_ds = false;
break;
case 88200:
case 96000:
ssz_ds = true;
break;
default:
dev_err(codec->dev, "unsupported sample rate: %u\n", rate);
return -EINVAL;
}
ret = snd_soc_update_bits(codec, TAS5720_DIGITAL_CTRL1_REG,
TAS5720_SSZ_DS, ssz_ds);
if (ret < 0) {
dev_err(codec->dev, "error setting sample rate: %d\n", ret);
return ret;
}
return 0;
}
static int tas5720_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
u8 serial_format;
int ret;
if ((fmt & SND_SOC_DAIFMT_MASTER_MASK) != SND_SOC_DAIFMT_CBS_CFS) {
dev_vdbg(codec->dev, "DAI Format master is not found\n");
return -EINVAL;
}
switch (fmt & (SND_SOC_DAIFMT_FORMAT_MASK |
SND_SOC_DAIFMT_INV_MASK)) {
case (SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF):
serial_format = TAS5720_SAIF_I2S;
break;
case (SND_SOC_DAIFMT_DSP_A | SND_SOC_DAIFMT_NB_NF):
serial_format = TAS5720_SAIF_I2S;
break;
case (SND_SOC_DAIFMT_DSP_B | SND_SOC_DAIFMT_NB_NF):
serial_format = TAS5720_SAIF_LEFTJ;
break;
case (SND_SOC_DAIFMT_LEFT_J | SND_SOC_DAIFMT_NB_NF):
serial_format = TAS5720_SAIF_LEFTJ;
break;
default:
dev_vdbg(codec->dev, "DAI Format is not found\n");
return -EINVAL;
}
ret = snd_soc_update_bits(codec, TAS5720_DIGITAL_CTRL1_REG,
TAS5720_SAIF_FORMAT_MASK,
serial_format);
if (ret < 0) {
dev_err(codec->dev, "error setting SAIF format: %d\n", ret);
return ret;
}
return 0;
}
static int tas5720_set_dai_tdm_slot(struct snd_soc_dai *dai,
unsigned int tx_mask, unsigned int rx_mask,
int slots, int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int first_slot;
int ret;
if (!tx_mask) {
dev_err(codec->dev, "tx masks must not be 0\n");
return -EINVAL;
}
first_slot = __ffs(tx_mask);
if (first_slot > 7) {
dev_err(codec->dev, "slot selection out of bounds (%u)\n",
first_slot);
return -EINVAL;
}
ret = snd_soc_update_bits(codec, TAS5720_DIGITAL_CTRL1_REG,
TAS5720_TDM_CFG_SRC, TAS5720_TDM_CFG_SRC);
if (ret < 0)
goto error_snd_soc_update_bits;
ret = snd_soc_update_bits(codec, TAS5720_DIGITAL_CTRL2_REG,
TAS5720_TDM_SLOT_SEL_MASK, first_slot);
if (ret < 0)
goto error_snd_soc_update_bits;
return 0;
error_snd_soc_update_bits:
dev_err(codec->dev, "error configuring TDM mode: %d\n", ret);
return ret;
}
static int tas5720_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
int ret;
ret = snd_soc_update_bits(codec, TAS5720_DIGITAL_CTRL2_REG,
TAS5720_MUTE, mute ? TAS5720_MUTE : 0);
if (ret < 0) {
dev_err(codec->dev, "error (un-)muting device: %d\n", ret);
return ret;
}
return 0;
}
static void tas5720_fault_check_work(struct work_struct *work)
{
struct tas5720_data *tas5720 = container_of(work, struct tas5720_data,
fault_check_work.work);
struct device *dev = tas5720->codec->dev;
unsigned int curr_fault;
int ret;
ret = regmap_read(tas5720->regmap, TAS5720_FAULT_REG, &curr_fault);
if (ret < 0) {
dev_err(dev, "failed to read FAULT register: %d\n", ret);
goto out;
}
curr_fault &= TAS5720_OCE | TAS5720_DCE | TAS5720_OTE;
if ((curr_fault & TAS5720_OCE) && !(tas5720->last_fault & TAS5720_OCE))
dev_crit(dev, "experienced an over current hardware fault\n");
if ((curr_fault & TAS5720_DCE) && !(tas5720->last_fault & TAS5720_DCE))
dev_crit(dev, "experienced a DC detection fault\n");
if ((curr_fault & TAS5720_OTE) && !(tas5720->last_fault & TAS5720_OTE))
dev_crit(dev, "experienced an over temperature fault\n");
tas5720->last_fault = curr_fault;
if (!curr_fault)
goto out;
ret = regmap_write_bits(tas5720->regmap, TAS5720_POWER_CTRL_REG,
TAS5720_SDZ, 0);
if (ret < 0)
dev_err(dev, "failed to write POWER_CTRL register: %d\n", ret);
ret = regmap_write_bits(tas5720->regmap, TAS5720_POWER_CTRL_REG,
TAS5720_SDZ, TAS5720_SDZ);
if (ret < 0)
dev_err(dev, "failed to write POWER_CTRL register: %d\n", ret);
out:
schedule_delayed_work(&tas5720->fault_check_work,
msecs_to_jiffies(TAS5720_FAULT_CHECK_INTERVAL));
}
static int tas5720_codec_probe(struct snd_soc_codec *codec)
{
struct tas5720_data *tas5720 = snd_soc_codec_get_drvdata(codec);
unsigned int device_id;
int ret;
tas5720->codec = codec;
ret = regulator_bulk_enable(ARRAY_SIZE(tas5720->supplies),
tas5720->supplies);
if (ret != 0) {
dev_err(codec->dev, "failed to enable supplies: %d\n", ret);
return ret;
}
ret = regmap_read(tas5720->regmap, TAS5720_DEVICE_ID_REG, &device_id);
if (ret < 0) {
dev_err(codec->dev, "failed to read device ID register: %d\n",
ret);
goto probe_fail;
}
if (device_id != TAS5720_DEVICE_ID) {
dev_err(codec->dev, "wrong device ID. expected: %u read: %u\n",
TAS5720_DEVICE_ID, device_id);
ret = -ENODEV;
goto probe_fail;
}
ret = snd_soc_update_bits(codec, TAS5720_DIGITAL_CTRL2_REG,
TAS5720_MUTE, TAS5720_MUTE);
if (ret < 0)
goto error_snd_soc_update_bits;
ret = snd_soc_update_bits(codec, TAS5720_POWER_CTRL_REG,
TAS5720_SDZ, 0);
if (ret < 0)
goto error_snd_soc_update_bits;
INIT_DELAYED_WORK(&tas5720->fault_check_work, tas5720_fault_check_work);
return 0;
error_snd_soc_update_bits:
dev_err(codec->dev, "error configuring device registers: %d\n", ret);
probe_fail:
regulator_bulk_disable(ARRAY_SIZE(tas5720->supplies),
tas5720->supplies);
return ret;
}
static int tas5720_codec_remove(struct snd_soc_codec *codec)
{
struct tas5720_data *tas5720 = snd_soc_codec_get_drvdata(codec);
int ret;
cancel_delayed_work_sync(&tas5720->fault_check_work);
ret = regulator_bulk_disable(ARRAY_SIZE(tas5720->supplies),
tas5720->supplies);
if (ret < 0)
dev_err(codec->dev, "failed to disable supplies: %d\n", ret);
return ret;
}
static int tas5720_dac_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct tas5720_data *tas5720 = snd_soc_codec_get_drvdata(codec);
int ret;
if (event & SND_SOC_DAPM_POST_PMU) {
ret = snd_soc_update_bits(codec, TAS5720_POWER_CTRL_REG,
TAS5720_SDZ, TAS5720_SDZ);
if (ret < 0) {
dev_err(codec->dev, "error waking codec: %d\n", ret);
return ret;
}
msleep(25);
tas5720->last_fault = 0;
schedule_delayed_work(&tas5720->fault_check_work,
msecs_to_jiffies(TAS5720_FAULT_CHECK_INTERVAL));
} else if (event & SND_SOC_DAPM_PRE_PMD) {
cancel_delayed_work_sync(&tas5720->fault_check_work);
ret = snd_soc_update_bits(codec, TAS5720_POWER_CTRL_REG,
TAS5720_SDZ, 0);
if (ret < 0) {
dev_err(codec->dev, "error shutting down codec: %d\n",
ret);
return ret;
}
}
return 0;
}
static int tas5720_suspend(struct snd_soc_codec *codec)
{
struct tas5720_data *tas5720 = snd_soc_codec_get_drvdata(codec);
int ret;
regcache_cache_only(tas5720->regmap, true);
regcache_mark_dirty(tas5720->regmap);
ret = regulator_bulk_disable(ARRAY_SIZE(tas5720->supplies),
tas5720->supplies);
if (ret < 0)
dev_err(codec->dev, "failed to disable supplies: %d\n", ret);
return ret;
}
static int tas5720_resume(struct snd_soc_codec *codec)
{
struct tas5720_data *tas5720 = snd_soc_codec_get_drvdata(codec);
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(tas5720->supplies),
tas5720->supplies);
if (ret < 0) {
dev_err(codec->dev, "failed to enable supplies: %d\n", ret);
return ret;
}
regcache_cache_only(tas5720->regmap, false);
ret = regcache_sync(tas5720->regmap);
if (ret < 0) {
dev_err(codec->dev, "failed to sync regcache: %d\n", ret);
return ret;
}
return 0;
}
static bool tas5720_is_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case TAS5720_DEVICE_ID_REG:
case TAS5720_FAULT_REG:
return true;
default:
return false;
}
}
static int tas5720_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct tas5720_data *data;
int ret;
int i;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->tas5720_client = client;
data->regmap = devm_regmap_init_i2c(client, &tas5720_regmap_config);
if (IS_ERR(data->regmap)) {
ret = PTR_ERR(data->regmap);
dev_err(dev, "failed to allocate register map: %d\n", ret);
return ret;
}
for (i = 0; i < ARRAY_SIZE(data->supplies); i++)
data->supplies[i].supply = tas5720_supply_names[i];
ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(data->supplies),
data->supplies);
if (ret != 0) {
dev_err(dev, "failed to request supplies: %d\n", ret);
return ret;
}
dev_set_drvdata(dev, data);
ret = snd_soc_register_codec(&client->dev,
&soc_codec_dev_tas5720,
tas5720_dai, ARRAY_SIZE(tas5720_dai));
if (ret < 0) {
dev_err(dev, "failed to register codec: %d\n", ret);
return ret;
}
return 0;
}
static int tas5720_remove(struct i2c_client *client)
{
struct device *dev = &client->dev;
snd_soc_unregister_codec(dev);
return 0;
}
