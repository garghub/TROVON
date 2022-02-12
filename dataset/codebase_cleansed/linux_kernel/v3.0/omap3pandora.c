static int omap3pandora_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int fmt = SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBS_CFS;
int ret;
ret = snd_soc_dai_set_fmt(codec_dai, fmt);
if (ret < 0) {
pr_err(PREFIX "can't set codec DAI configuration\n");
return ret;
}
ret = snd_soc_dai_set_fmt(cpu_dai, fmt);
if (ret < 0) {
pr_err(PREFIX "can't set cpu DAI configuration\n");
return ret;
}
ret = snd_soc_dai_set_sysclk(codec_dai, 0, 26000000,
SND_SOC_CLOCK_IN);
if (ret < 0) {
pr_err(PREFIX "can't set codec system clock\n");
return ret;
}
ret = snd_soc_dai_set_sysclk(cpu_dai, OMAP_MCBSP_SYSCLK_CLKS_EXT,
256 * params_rate(params),
SND_SOC_CLOCK_IN);
if (ret < 0) {
pr_err(PREFIX "can't set cpu system clock\n");
return ret;
}
ret = snd_soc_dai_set_clkdiv(cpu_dai, OMAP_MCBSP_CLKGDV, 8);
if (ret < 0) {
pr_err(PREFIX "can't set SRG clock divider\n");
return ret;
}
return 0;
}
static int omap3pandora_dac_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
if (SND_SOC_DAPM_EVENT_ON(event)) {
regulator_enable(omap3pandora_dac_reg);
mdelay(1);
gpio_set_value(OMAP3_PANDORA_DAC_POWER_GPIO, 1);
} else {
gpio_set_value(OMAP3_PANDORA_DAC_POWER_GPIO, 0);
mdelay(1);
regulator_disable(omap3pandora_dac_reg);
}
return 0;
}
static int omap3pandora_hp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
if (SND_SOC_DAPM_EVENT_ON(event))
gpio_set_value(OMAP3_PANDORA_AMP_POWER_GPIO, 1);
else
gpio_set_value(OMAP3_PANDORA_AMP_POWER_GPIO, 0);
return 0;
}
static int omap3pandora_out_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret;
snd_soc_dapm_nc_pin(dapm, "EARPIECE");
snd_soc_dapm_nc_pin(dapm, "PREDRIVEL");
snd_soc_dapm_nc_pin(dapm, "PREDRIVER");
snd_soc_dapm_nc_pin(dapm, "HSOL");
snd_soc_dapm_nc_pin(dapm, "HSOR");
snd_soc_dapm_nc_pin(dapm, "CARKITL");
snd_soc_dapm_nc_pin(dapm, "CARKITR");
snd_soc_dapm_nc_pin(dapm, "HFL");
snd_soc_dapm_nc_pin(dapm, "HFR");
snd_soc_dapm_nc_pin(dapm, "VIBRA");
ret = snd_soc_dapm_new_controls(dapm, omap3pandora_out_dapm_widgets,
ARRAY_SIZE(omap3pandora_out_dapm_widgets));
if (ret < 0)
return ret;
snd_soc_dapm_add_routes(dapm, omap3pandora_out_map,
ARRAY_SIZE(omap3pandora_out_map));
return snd_soc_dapm_sync(dapm);
}
static int omap3pandora_in_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret;
snd_soc_dapm_nc_pin(dapm, "HSMIC");
snd_soc_dapm_nc_pin(dapm, "CARKITMIC");
snd_soc_dapm_nc_pin(dapm, "DIGIMIC0");
snd_soc_dapm_nc_pin(dapm, "DIGIMIC1");
ret = snd_soc_dapm_new_controls(dapm, omap3pandora_in_dapm_widgets,
ARRAY_SIZE(omap3pandora_in_dapm_widgets));
if (ret < 0)
return ret;
snd_soc_dapm_add_routes(dapm, omap3pandora_in_map,
ARRAY_SIZE(omap3pandora_in_map));
return snd_soc_dapm_sync(dapm);
}
static int __init omap3pandora_soc_init(void)
{
int ret;
if (!machine_is_omap3_pandora())
return -ENODEV;
pr_info("OMAP3 Pandora SoC init\n");
ret = gpio_request(OMAP3_PANDORA_DAC_POWER_GPIO, "dac_power");
if (ret) {
pr_err(PREFIX "Failed to get DAC power GPIO\n");
return ret;
}
ret = gpio_direction_output(OMAP3_PANDORA_DAC_POWER_GPIO, 0);
if (ret) {
pr_err(PREFIX "Failed to set DAC power GPIO direction\n");
goto fail0;
}
ret = gpio_request(OMAP3_PANDORA_AMP_POWER_GPIO, "amp_power");
if (ret) {
pr_err(PREFIX "Failed to get amp power GPIO\n");
goto fail0;
}
ret = gpio_direction_output(OMAP3_PANDORA_AMP_POWER_GPIO, 0);
if (ret) {
pr_err(PREFIX "Failed to set amp power GPIO direction\n");
goto fail1;
}
omap3pandora_snd_device = platform_device_alloc("soc-audio", -1);
if (omap3pandora_snd_device == NULL) {
pr_err(PREFIX "Platform device allocation failed\n");
ret = -ENOMEM;
goto fail1;
}
platform_set_drvdata(omap3pandora_snd_device, &snd_soc_card_omap3pandora);
ret = platform_device_add(omap3pandora_snd_device);
if (ret) {
pr_err(PREFIX "Unable to add platform device\n");
goto fail2;
}
omap3pandora_dac_reg = regulator_get(&omap3pandora_snd_device->dev, "vcc");
if (IS_ERR(omap3pandora_dac_reg)) {
pr_err(PREFIX "Failed to get DAC regulator from %s: %ld\n",
dev_name(&omap3pandora_snd_device->dev),
PTR_ERR(omap3pandora_dac_reg));
ret = PTR_ERR(omap3pandora_dac_reg);
goto fail3;
}
return 0;
fail3:
platform_device_del(omap3pandora_snd_device);
fail2:
platform_device_put(omap3pandora_snd_device);
fail1:
gpio_free(OMAP3_PANDORA_AMP_POWER_GPIO);
fail0:
gpio_free(OMAP3_PANDORA_DAC_POWER_GPIO);
return ret;
}
static void __exit omap3pandora_soc_exit(void)
{
regulator_put(omap3pandora_dac_reg);
platform_device_unregister(omap3pandora_snd_device);
gpio_free(OMAP3_PANDORA_AMP_POWER_GPIO);
gpio_free(OMAP3_PANDORA_DAC_POWER_GPIO);
}
