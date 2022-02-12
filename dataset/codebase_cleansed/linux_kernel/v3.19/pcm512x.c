static bool pcm512x_readable(struct device *dev, unsigned int reg)
{
switch (reg) {
case PCM512x_RESET:
case PCM512x_POWER:
case PCM512x_MUTE:
case PCM512x_PLL_EN:
case PCM512x_SPI_MISO_FUNCTION:
case PCM512x_DSP:
case PCM512x_GPIO_EN:
case PCM512x_BCLK_LRCLK_CFG:
case PCM512x_DSP_GPIO_INPUT:
case PCM512x_MASTER_MODE:
case PCM512x_PLL_REF:
case PCM512x_PLL_COEFF_0:
case PCM512x_PLL_COEFF_1:
case PCM512x_PLL_COEFF_2:
case PCM512x_PLL_COEFF_3:
case PCM512x_PLL_COEFF_4:
case PCM512x_DSP_CLKDIV:
case PCM512x_DAC_CLKDIV:
case PCM512x_NCP_CLKDIV:
case PCM512x_OSR_CLKDIV:
case PCM512x_MASTER_CLKDIV_1:
case PCM512x_MASTER_CLKDIV_2:
case PCM512x_FS_SPEED_MODE:
case PCM512x_IDAC_1:
case PCM512x_IDAC_2:
case PCM512x_ERROR_DETECT:
case PCM512x_I2S_1:
case PCM512x_I2S_2:
case PCM512x_DAC_ROUTING:
case PCM512x_DSP_PROGRAM:
case PCM512x_CLKDET:
case PCM512x_AUTO_MUTE:
case PCM512x_DIGITAL_VOLUME_1:
case PCM512x_DIGITAL_VOLUME_2:
case PCM512x_DIGITAL_VOLUME_3:
case PCM512x_DIGITAL_MUTE_1:
case PCM512x_DIGITAL_MUTE_2:
case PCM512x_DIGITAL_MUTE_3:
case PCM512x_GPIO_OUTPUT_1:
case PCM512x_GPIO_OUTPUT_2:
case PCM512x_GPIO_OUTPUT_3:
case PCM512x_GPIO_OUTPUT_4:
case PCM512x_GPIO_OUTPUT_5:
case PCM512x_GPIO_OUTPUT_6:
case PCM512x_GPIO_CONTROL_1:
case PCM512x_GPIO_CONTROL_2:
case PCM512x_OVERFLOW:
case PCM512x_RATE_DET_1:
case PCM512x_RATE_DET_2:
case PCM512x_RATE_DET_3:
case PCM512x_RATE_DET_4:
case PCM512x_ANALOG_MUTE_DET:
case PCM512x_GPIN:
case PCM512x_DIGITAL_MUTE_DET:
case PCM512x_OUTPUT_AMPLITUDE:
case PCM512x_ANALOG_GAIN_CTRL:
case PCM512x_UNDERVOLTAGE_PROT:
case PCM512x_ANALOG_MUTE_CTRL:
case PCM512x_ANALOG_GAIN_BOOST:
case PCM512x_VCOM_CTRL_1:
case PCM512x_VCOM_CTRL_2:
case PCM512x_CRAM_CTRL:
return true;
default:
return reg < 0xff;
}
}
static bool pcm512x_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case PCM512x_PLL_EN:
case PCM512x_OVERFLOW:
case PCM512x_RATE_DET_1:
case PCM512x_RATE_DET_2:
case PCM512x_RATE_DET_3:
case PCM512x_RATE_DET_4:
case PCM512x_ANALOG_MUTE_DET:
case PCM512x_GPIN:
case PCM512x_DIGITAL_MUTE_DET:
case PCM512x_CRAM_CTRL:
return true;
default:
return reg < 0xff;
}
}
static int pcm512x_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct pcm512x_priv *pcm512x = dev_get_drvdata(codec->dev);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
ret = regmap_update_bits(pcm512x->regmap, PCM512x_POWER,
PCM512x_RQST, 0);
if (ret != 0) {
dev_err(codec->dev, "Failed to remove standby: %d\n",
ret);
return ret;
}
break;
case SND_SOC_BIAS_OFF:
ret = regmap_update_bits(pcm512x->regmap, PCM512x_POWER,
PCM512x_RQST, PCM512x_RQST);
if (ret != 0) {
dev_err(codec->dev, "Failed to request standby: %d\n",
ret);
return ret;
}
break;
}
codec->dapm.bias_level = level;
return 0;
}
int pcm512x_probe(struct device *dev, struct regmap *regmap)
{
struct pcm512x_priv *pcm512x;
int i, ret;
pcm512x = devm_kzalloc(dev, sizeof(struct pcm512x_priv), GFP_KERNEL);
if (!pcm512x)
return -ENOMEM;
dev_set_drvdata(dev, pcm512x);
pcm512x->regmap = regmap;
for (i = 0; i < ARRAY_SIZE(pcm512x->supplies); i++)
pcm512x->supplies[i].supply = pcm512x_supply_names[i];
ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(pcm512x->supplies),
pcm512x->supplies);
if (ret != 0) {
dev_err(dev, "Failed to get supplies: %d\n", ret);
return ret;
}
pcm512x->supply_nb[0].notifier_call = pcm512x_regulator_event_0;
pcm512x->supply_nb[1].notifier_call = pcm512x_regulator_event_1;
pcm512x->supply_nb[2].notifier_call = pcm512x_regulator_event_2;
for (i = 0; i < ARRAY_SIZE(pcm512x->supplies); i++) {
ret = regulator_register_notifier(pcm512x->supplies[i].consumer,
&pcm512x->supply_nb[i]);
if (ret != 0) {
dev_err(dev,
"Failed to register regulator notifier: %d\n",
ret);
}
}
ret = regulator_bulk_enable(ARRAY_SIZE(pcm512x->supplies),
pcm512x->supplies);
if (ret != 0) {
dev_err(dev, "Failed to enable supplies: %d\n", ret);
return ret;
}
ret = regmap_write(regmap, PCM512x_RESET,
PCM512x_RSTM | PCM512x_RSTR);
if (ret != 0) {
dev_err(dev, "Failed to reset device: %d\n", ret);
goto err;
}
ret = regmap_write(regmap, PCM512x_RESET, 0);
if (ret != 0) {
dev_err(dev, "Failed to reset device: %d\n", ret);
goto err;
}
pcm512x->sclk = devm_clk_get(dev, NULL);
if (IS_ERR(pcm512x->sclk)) {
if (PTR_ERR(pcm512x->sclk) == -EPROBE_DEFER)
return -EPROBE_DEFER;
dev_info(dev, "No SCLK, using BCLK: %ld\n",
PTR_ERR(pcm512x->sclk));
regmap_update_bits(regmap, PCM512x_ERROR_DETECT,
PCM512x_IDCH, PCM512x_IDCH);
regmap_update_bits(regmap, PCM512x_PLL_REF,
PCM512x_SREF, PCM512x_SREF);
} else {
ret = clk_prepare_enable(pcm512x->sclk);
if (ret != 0) {
dev_err(dev, "Failed to enable SCLK: %d\n", ret);
return ret;
}
}
ret = regmap_update_bits(pcm512x->regmap, PCM512x_POWER,
PCM512x_RQST, PCM512x_RQST);
if (ret != 0) {
dev_err(dev, "Failed to request standby: %d\n",
ret);
goto err_clk;
}
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
pm_runtime_idle(dev);
ret = snd_soc_register_codec(dev, &pcm512x_codec_driver,
&pcm512x_dai, 1);
if (ret != 0) {
dev_err(dev, "Failed to register CODEC: %d\n", ret);
goto err_pm;
}
return 0;
err_pm:
pm_runtime_disable(dev);
err_clk:
if (!IS_ERR(pcm512x->sclk))
clk_disable_unprepare(pcm512x->sclk);
err:
regulator_bulk_disable(ARRAY_SIZE(pcm512x->supplies),
pcm512x->supplies);
return ret;
}
void pcm512x_remove(struct device *dev)
{
struct pcm512x_priv *pcm512x = dev_get_drvdata(dev);
snd_soc_unregister_codec(dev);
pm_runtime_disable(dev);
if (!IS_ERR(pcm512x->sclk))
clk_disable_unprepare(pcm512x->sclk);
regulator_bulk_disable(ARRAY_SIZE(pcm512x->supplies),
pcm512x->supplies);
}
static int pcm512x_suspend(struct device *dev)
{
struct pcm512x_priv *pcm512x = dev_get_drvdata(dev);
int ret;
ret = regmap_update_bits(pcm512x->regmap, PCM512x_POWER,
PCM512x_RQPD, PCM512x_RQPD);
if (ret != 0) {
dev_err(dev, "Failed to request power down: %d\n", ret);
return ret;
}
ret = regulator_bulk_disable(ARRAY_SIZE(pcm512x->supplies),
pcm512x->supplies);
if (ret != 0) {
dev_err(dev, "Failed to disable supplies: %d\n", ret);
return ret;
}
if (!IS_ERR(pcm512x->sclk))
clk_disable_unprepare(pcm512x->sclk);
return 0;
}
static int pcm512x_resume(struct device *dev)
{
struct pcm512x_priv *pcm512x = dev_get_drvdata(dev);
int ret;
if (!IS_ERR(pcm512x->sclk)) {
ret = clk_prepare_enable(pcm512x->sclk);
if (ret != 0) {
dev_err(dev, "Failed to enable SCLK: %d\n", ret);
return ret;
}
}
ret = regulator_bulk_enable(ARRAY_SIZE(pcm512x->supplies),
pcm512x->supplies);
if (ret != 0) {
dev_err(dev, "Failed to enable supplies: %d\n", ret);
return ret;
}
regcache_cache_only(pcm512x->regmap, false);
ret = regcache_sync(pcm512x->regmap);
if (ret != 0) {
dev_err(dev, "Failed to sync cache: %d\n", ret);
return ret;
}
ret = regmap_update_bits(pcm512x->regmap, PCM512x_POWER,
PCM512x_RQPD, 0);
if (ret != 0) {
dev_err(dev, "Failed to remove power down: %d\n", ret);
return ret;
}
return 0;
}
