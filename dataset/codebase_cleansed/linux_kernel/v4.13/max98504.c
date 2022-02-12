static bool max98504_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX98504_INTERRUPT_STATUS:
case MAX98504_INTERRUPT_FLAGS:
case MAX98504_INTERRUPT_FLAG_CLEARS:
case MAX98504_WATCHDOG_CLEAR:
case MAX98504_GLOBAL_ENABLE:
case MAX98504_SOFTWARE_RESET:
return true;
default:
return false;
}
}
static bool max98504_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX98504_SOFTWARE_RESET:
case MAX98504_WATCHDOG_CLEAR:
case MAX98504_INTERRUPT_FLAG_CLEARS:
return false;
default:
return true;
}
}
static int max98504_pcm_rx_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_component *c = snd_soc_dapm_to_component(w->dapm);
struct max98504_priv *max98504 = snd_soc_component_get_drvdata(c);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
regmap_write(max98504->regmap, MAX98504_PCM_RX_ENABLE,
max98504->pcm_rx_channels);
break;
case SND_SOC_DAPM_POST_PMD:
regmap_write(max98504->regmap, MAX98504_PCM_RX_ENABLE, 0);
break;
}
return 0;
}
static int max98504_component_probe(struct snd_soc_component *c)
{
struct max98504_priv *max98504 = snd_soc_component_get_drvdata(c);
struct regmap *map = max98504->regmap;
int ret;
ret = regulator_bulk_enable(MAX98504_NUM_SUPPLIES, max98504->supplies);
if (ret < 0)
return ret;
regmap_write(map, MAX98504_SOFTWARE_RESET, 0x1);
msleep(20);
if (!max98504->brownout_enable)
return 0;
regmap_write(map, MAX98504_PVDD_BROWNOUT_ENABLE, 0x1);
regmap_write(map, MAX98504_PVDD_BROWNOUT_CONFIG_1,
(max98504->brownout_threshold & 0x1f) << 3 |
(max98504->brownout_attenuation & 0x3));
regmap_write(map, MAX98504_PVDD_BROWNOUT_CONFIG_2,
max98504->brownout_attack_hold & 0xff);
regmap_write(map, MAX98504_PVDD_BROWNOUT_CONFIG_3,
max98504->brownout_timed_hold & 0xff);
regmap_write(map, MAX98504_PVDD_BROWNOUT_CONFIG_4,
max98504->brownout_release_rate & 0xff);
return 0;
}
static void max98504_component_remove(struct snd_soc_component *c)
{
struct max98504_priv *max98504 = snd_soc_component_get_drvdata(c);
regulator_bulk_disable(MAX98504_NUM_SUPPLIES, max98504->supplies);
}
static int max98504_set_tdm_slot(struct snd_soc_dai *dai,
unsigned int tx_mask, unsigned int rx_mask,
int slots, int slot_width)
{
struct max98504_priv *max98504 = snd_soc_dai_get_drvdata(dai);
struct regmap *map = max98504->regmap;
switch (dai->id) {
case MAX98504_DAI_ID_PCM:
regmap_write(map, MAX98504_PCM_TX_ENABLE, tx_mask);
max98504->pcm_rx_channels = rx_mask;
break;
case MAX98504_DAI_ID_PDM:
regmap_write(map, MAX98504_PDM_TX_ENABLE, tx_mask);
break;
default:
WARN_ON(1);
}
return 0;
}
static int max98504_set_channel_map(struct snd_soc_dai *dai,
unsigned int tx_num, unsigned int *tx_slot,
unsigned int rx_num, unsigned int *rx_slot)
{
struct max98504_priv *max98504 = snd_soc_dai_get_drvdata(dai);
struct regmap *map = max98504->regmap;
unsigned int i, sources = 0;
for (i = 0; i < tx_num; i++)
if (tx_slot[i])
sources |= (1 << i);
switch (dai->id) {
case MAX98504_DAI_ID_PCM:
regmap_write(map, MAX98504_PCM_TX_CHANNEL_SOURCES,
sources);
break;
case MAX98504_DAI_ID_PDM:
regmap_write(map, MAX98504_PDM_TX_CONTROL, sources);
break;
default:
WARN_ON(1);
}
regmap_write(map, MAX98504_MEASUREMENT_ENABLE, sources ? 0x3 : 0x01);
return 0;
}
static int max98504_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct device_node *node = dev->of_node;
struct max98504_priv *max98504;
int i, ret;
max98504 = devm_kzalloc(dev, sizeof(*max98504), GFP_KERNEL);
if (!max98504)
return -ENOMEM;
if (node) {
if (!of_property_read_u32(node, "maxim,brownout-threshold",
&max98504->brownout_threshold))
max98504->brownout_enable = true;
of_property_read_u32(node, "maxim,brownout-attenuation",
&max98504->brownout_attenuation);
of_property_read_u32(node, "maxim,brownout-attack-hold-ms",
&max98504->brownout_attack_hold);
of_property_read_u32(node, "maxim,brownout-timed-hold-ms",
&max98504->brownout_timed_hold);
of_property_read_u32(node, "maxim,brownout-release-rate-ms",
&max98504->brownout_release_rate);
}
max98504->regmap = devm_regmap_init_i2c(client, &max98504_regmap);
if (IS_ERR(max98504->regmap)) {
ret = PTR_ERR(max98504->regmap);
dev_err(&client->dev, "regmap initialization failed: %d\n", ret);
return ret;
}
for (i = 0; i < MAX98504_NUM_SUPPLIES; i++)
max98504->supplies[i].supply = max98504_supply_names[i];
ret = devm_regulator_bulk_get(dev, MAX98504_NUM_SUPPLIES,
max98504->supplies);
if (ret < 0)
return ret;
i2c_set_clientdata(client, max98504);
return devm_snd_soc_register_component(dev, &max98504_component_driver,
max98504_dai, ARRAY_SIZE(max98504_dai));
}
