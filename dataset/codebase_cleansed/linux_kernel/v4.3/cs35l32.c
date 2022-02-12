static bool cs35l32_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS35L32_DEVID_AB ... CS35L32_AUDIO_LED_MNGR:
case CS35L32_ADSP_CTL ... CS35L32_FLASH_INHIBIT:
return true;
default:
return false;
}
}
static bool cs35l32_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS35L32_DEVID_AB ... CS35L32_REV_ID:
case CS35L32_INT_STATUS_1 ... CS35L32_LED_STATUS:
return true;
default:
return false;
}
}
static bool cs35l32_precious_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS35L32_INT_STATUS_1 ... CS35L32_LED_STATUS:
return true;
default:
return false;
}
}
static int cs35l32_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
snd_soc_update_bits(codec, CS35L32_ADSP_CTL,
CS35L32_ADSP_MASTER_MASK,
CS35L32_ADSP_MASTER_MASK);
break;
case SND_SOC_DAIFMT_CBS_CFS:
snd_soc_update_bits(codec, CS35L32_ADSP_CTL,
CS35L32_ADSP_MASTER_MASK, 0);
break;
default:
return -EINVAL;
}
return 0;
}
static int cs35l32_set_tristate(struct snd_soc_dai *dai, int tristate)
{
struct snd_soc_codec *codec = dai->codec;
return snd_soc_update_bits(codec, CS35L32_PWRCTL2,
CS35L32_SDOUT_3ST, tristate << 3);
}
static int cs35l32_codec_set_sysclk(struct snd_soc_codec *codec,
int clk_id, int source, unsigned int freq, int dir)
{
unsigned int val;
switch (freq) {
case 6000000:
val = CS35L32_MCLK_RATIO;
break;
case 12000000:
val = CS35L32_MCLK_DIV2_MASK | CS35L32_MCLK_RATIO;
break;
case 6144000:
val = 0;
break;
case 12288000:
val = CS35L32_MCLK_DIV2_MASK;
break;
default:
return -EINVAL;
}
return snd_soc_update_bits(codec, CS35L32_CLK_CTL,
CS35L32_MCLK_DIV2_MASK | CS35L32_MCLK_RATIO_MASK, val);
}
static int cs35l32_handle_of_data(struct i2c_client *i2c_client,
struct cs35l32_platform_data *pdata)
{
struct device_node *np = i2c_client->dev.of_node;
unsigned int val;
if (of_property_read_u32(np, "cirrus,sdout-share", &val) >= 0)
pdata->sdout_share = val;
of_property_read_u32(np, "cirrus,boost-manager", &val);
switch (val) {
case CS35L32_BOOST_MGR_AUTO:
case CS35L32_BOOST_MGR_AUTO_AUDIO:
case CS35L32_BOOST_MGR_BYPASS:
case CS35L32_BOOST_MGR_FIXED:
pdata->boost_mng = val;
break;
default:
dev_err(&i2c_client->dev,
"Wrong cirrus,boost-manager DT value %d\n", val);
pdata->boost_mng = CS35L32_BOOST_MGR_BYPASS;
}
of_property_read_u32(np, "cirrus,sdout-datacfg", &val);
switch (val) {
case CS35L32_DATA_CFG_LR_VP:
case CS35L32_DATA_CFG_LR_STAT:
case CS35L32_DATA_CFG_LR:
case CS35L32_DATA_CFG_LR_VPSTAT:
pdata->sdout_datacfg = val;
break;
default:
dev_err(&i2c_client->dev,
"Wrong cirrus,sdout-datacfg DT value %d\n", val);
pdata->sdout_datacfg = CS35L32_DATA_CFG_LR;
}
of_property_read_u32(np, "cirrus,battery-threshold", &val);
switch (val) {
case CS35L32_BATT_THRESH_3_1V:
case CS35L32_BATT_THRESH_3_2V:
case CS35L32_BATT_THRESH_3_3V:
case CS35L32_BATT_THRESH_3_4V:
pdata->batt_thresh = val;
break;
default:
dev_err(&i2c_client->dev,
"Wrong cirrus,battery-threshold DT value %d\n", val);
pdata->batt_thresh = CS35L32_BATT_THRESH_3_3V;
}
of_property_read_u32(np, "cirrus,battery-recovery", &val);
switch (val) {
case CS35L32_BATT_RECOV_3_1V:
case CS35L32_BATT_RECOV_3_2V:
case CS35L32_BATT_RECOV_3_3V:
case CS35L32_BATT_RECOV_3_4V:
case CS35L32_BATT_RECOV_3_5V:
case CS35L32_BATT_RECOV_3_6V:
pdata->batt_recov = val;
break;
default:
dev_err(&i2c_client->dev,
"Wrong cirrus,battery-recovery DT value %d\n", val);
pdata->batt_recov = CS35L32_BATT_RECOV_3_4V;
}
return 0;
}
static int cs35l32_i2c_probe(struct i2c_client *i2c_client,
const struct i2c_device_id *id)
{
struct cs35l32_private *cs35l32;
struct cs35l32_platform_data *pdata =
dev_get_platdata(&i2c_client->dev);
int ret, i;
unsigned int devid = 0;
unsigned int reg;
cs35l32 = devm_kzalloc(&i2c_client->dev, sizeof(struct cs35l32_private),
GFP_KERNEL);
if (!cs35l32) {
dev_err(&i2c_client->dev, "could not allocate codec\n");
return -ENOMEM;
}
i2c_set_clientdata(i2c_client, cs35l32);
cs35l32->regmap = devm_regmap_init_i2c(i2c_client, &cs35l32_regmap);
if (IS_ERR(cs35l32->regmap)) {
ret = PTR_ERR(cs35l32->regmap);
dev_err(&i2c_client->dev, "regmap_init() failed: %d\n", ret);
return ret;
}
if (pdata) {
cs35l32->pdata = *pdata;
} else {
pdata = devm_kzalloc(&i2c_client->dev,
sizeof(struct cs35l32_platform_data),
GFP_KERNEL);
if (!pdata) {
dev_err(&i2c_client->dev, "could not allocate pdata\n");
return -ENOMEM;
}
if (i2c_client->dev.of_node) {
ret = cs35l32_handle_of_data(i2c_client,
&cs35l32->pdata);
if (ret != 0)
return ret;
}
}
for (i = 0; i < ARRAY_SIZE(cs35l32->supplies); i++)
cs35l32->supplies[i].supply = cs35l32_supply_names[i];
ret = devm_regulator_bulk_get(&i2c_client->dev,
ARRAY_SIZE(cs35l32->supplies),
cs35l32->supplies);
if (ret != 0) {
dev_err(&i2c_client->dev,
"Failed to request supplies: %d\n", ret);
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(cs35l32->supplies),
cs35l32->supplies);
if (ret != 0) {
dev_err(&i2c_client->dev,
"Failed to enable supplies: %d\n", ret);
return ret;
}
cs35l32->reset_gpio = devm_gpiod_get_optional(&i2c_client->dev,
"reset", GPIOD_OUT_LOW);
if (IS_ERR(cs35l32->reset_gpio))
return PTR_ERR(cs35l32->reset_gpio);
gpiod_set_value_cansleep(cs35l32->reset_gpio, 1);
ret = regmap_read(cs35l32->regmap, CS35L32_DEVID_AB, &reg);
devid = (reg & 0xFF) << 12;
ret = regmap_read(cs35l32->regmap, CS35L32_DEVID_CD, &reg);
devid |= (reg & 0xFF) << 4;
ret = regmap_read(cs35l32->regmap, CS35L32_DEVID_E, &reg);
devid |= (reg & 0xF0) >> 4;
if (devid != CS35L32_CHIP_ID) {
ret = -ENODEV;
dev_err(&i2c_client->dev,
"CS35L32 Device ID (%X). Expected %X\n",
devid, CS35L32_CHIP_ID);
return ret;
}
ret = regmap_read(cs35l32->regmap, CS35L32_REV_ID, &reg);
if (ret < 0) {
dev_err(&i2c_client->dev, "Get Revision ID failed\n");
return ret;
}
ret = regmap_register_patch(cs35l32->regmap, cs35l32_monitor_patch,
ARRAY_SIZE(cs35l32_monitor_patch));
if (ret < 0) {
dev_err(&i2c_client->dev, "Failed to apply errata patch\n");
return ret;
}
dev_info(&i2c_client->dev,
"Cirrus Logic CS35L32, Revision: %02X\n", reg & 0xFF);
if (cs35l32->pdata.boost_mng)
regmap_update_bits(cs35l32->regmap, CS35L32_AUDIO_LED_MNGR,
CS35L32_BOOST_MASK,
cs35l32->pdata.boost_mng);
if (cs35l32->pdata.sdout_share)
regmap_update_bits(cs35l32->regmap, CS35L32_ADSP_CTL,
CS35L32_ADSP_SHARE_MASK,
cs35l32->pdata.sdout_share << 3);
if (cs35l32->pdata.sdout_datacfg)
regmap_update_bits(cs35l32->regmap, CS35L32_ADSP_CTL,
CS35L32_ADSP_DATACFG_MASK,
cs35l32->pdata.sdout_datacfg << 4);
if (cs35l32->pdata.batt_recov)
regmap_update_bits(cs35l32->regmap, CS35L32_BATT_THRESHOLD,
CS35L32_BATT_REC_MASK,
cs35l32->pdata.batt_recov << 1);
if (cs35l32->pdata.batt_thresh)
regmap_update_bits(cs35l32->regmap, CS35L32_BATT_THRESHOLD,
CS35L32_BATT_THRESH_MASK,
cs35l32->pdata.batt_thresh << 4);
regmap_update_bits(cs35l32->regmap, CS35L32_PWRCTL1, CS35L32_PDN_AMP,
CS35L32_PDN_AMP);
ret = regmap_read(cs35l32->regmap, CS35L32_INT_STATUS_1, &reg);
ret = snd_soc_register_codec(&i2c_client->dev,
&soc_codec_dev_cs35l32, cs35l32_dai,
ARRAY_SIZE(cs35l32_dai));
if (ret < 0)
goto err_disable;
return 0;
err_disable:
regulator_bulk_disable(ARRAY_SIZE(cs35l32->supplies),
cs35l32->supplies);
return ret;
}
static int cs35l32_i2c_remove(struct i2c_client *i2c_client)
{
struct cs35l32_private *cs35l32 = i2c_get_clientdata(i2c_client);
snd_soc_unregister_codec(&i2c_client->dev);
gpiod_set_value_cansleep(cs35l32->reset_gpio, 0);
return 0;
}
static int cs35l32_runtime_suspend(struct device *dev)
{
struct cs35l32_private *cs35l32 = dev_get_drvdata(dev);
regcache_cache_only(cs35l32->regmap, true);
regcache_mark_dirty(cs35l32->regmap);
gpiod_set_value_cansleep(cs35l32->reset_gpio, 0);
regulator_bulk_disable(ARRAY_SIZE(cs35l32->supplies),
cs35l32->supplies);
return 0;
}
static int cs35l32_runtime_resume(struct device *dev)
{
struct cs35l32_private *cs35l32 = dev_get_drvdata(dev);
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(cs35l32->supplies),
cs35l32->supplies);
if (ret != 0) {
dev_err(dev, "Failed to enable supplies: %d\n",
ret);
return ret;
}
gpiod_set_value_cansleep(cs35l32->reset_gpio, 1);
regcache_cache_only(cs35l32->regmap, false);
regcache_sync(cs35l32->regmap);
return 0;
}
