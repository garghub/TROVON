static struct ssc_clock_data playpaq_wm8510_calc_ssc_clock(
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
struct at32_ssc_info *ssc_p = snd_soc_dai_get_drvdata(cpu_dai);
struct ssc_device *ssc = ssc_p->ssc;
struct ssc_clock_data cd;
unsigned int rate, width_bits, channels;
unsigned int bitrate, ssc_div;
unsigned actual_rate;
rate = params_rate(params);
channels = params_channels(params);
width_bits = snd_pcm_format_physical_width(params_format(params));
bitrate = rate * width_bits * channels;
cd.ssc_rate = clk_get_rate(ssc->clk);
ssc_div = cd.ssc_rate / bitrate;
cd.cmr_div = ssc_div / 2;
if (ssc_div & 1) {
cd.cmr_div++;
}
cd.period = width_bits - 1;
actual_rate = (cd.ssc_rate / (cd.cmr_div * 2)) / (2 * (cd.period + 1));
pr_debug("playpaq_wm8510: Request rate = %u, actual rate = %u\n",
rate, actual_rate);
return cd;
}
static int playpaq_wm8510_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct at32_ssc_info *ssc_p = snd_soc_dai_get_drvdata(cpu_dai);
struct ssc_device *ssc = ssc_p->ssc;
unsigned int pll_out = 0, bclk = 0, mclk_div = 0;
int ret;
#if !defined CONFIG_SND_AT32_SOC_PLAYPAQ_SLAVE
const unsigned int fmt = (SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM);
#else
struct ssc_clock_data cd;
const unsigned int fmt = (SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBS_CFS);
#endif
if (ssc == NULL) {
pr_warning("playpaq_wm8510_hw_params: ssc is NULL!\n");
return -EINVAL;
}
switch (params_rate(params)) {
case 48000:
pll_out = 24576000;
mclk_div = WM8510_MCLKDIV_2;
bclk = WM8510_BCLKDIV_8;
break;
case 44100:
pll_out = 22579200;
mclk_div = WM8510_MCLKDIV_2;
bclk = WM8510_BCLKDIV_8;
break;
case 22050:
pll_out = 22579200;
mclk_div = WM8510_MCLKDIV_4;
bclk = WM8510_BCLKDIV_8;
break;
case 16000:
pll_out = 24576000;
mclk_div = WM8510_MCLKDIV_6;
bclk = WM8510_BCLKDIV_8;
break;
case 11025:
pll_out = 22579200;
mclk_div = WM8510_MCLKDIV_8;
bclk = WM8510_BCLKDIV_8;
break;
case 8000:
pll_out = 24576000;
mclk_div = WM8510_MCLKDIV_12;
bclk = WM8510_BCLKDIV_8;
break;
default:
pr_warning("playpaq_wm8510: Unsupported sample rate %d\n",
params_rate(params));
return -EINVAL;
}
ret = snd_soc_dai_set_fmt(codec_dai, fmt);
if (ret < 0) {
pr_warning("playpaq_wm8510: "
"Failed to set CODEC DAI format (%d)\n",
ret);
return ret;
}
ret = snd_soc_dai_set_fmt(cpu_dai, fmt);
if (ret < 0) {
pr_warning("playpaq_wm8510: "
"Failed to set CPU DAI format (%d)\n",
ret);
return ret;
}
#if defined CONFIG_SND_AT32_SOC_PLAYPAQ_SLAVE
cd = playpaq_wm8510_calc_ssc_clock(params, cpu_dai);
pr_debug("playpaq_wm8510: cmr_div = %d, period = %d\n",
cd.cmr_div, cd.period);
ret = snd_soc_dai_set_clkdiv(cpu_dai, AT32_SSC_CMR_DIV, cd.cmr_div);
if (ret < 0) {
pr_warning("playpaq_wm8510: Failed to set CPU CMR_DIV (%d)\n",
ret);
return ret;
}
ret = snd_soc_dai_set_clkdiv(cpu_dai, AT32_SSC_TCMR_PERIOD,
cd.period);
if (ret < 0) {
pr_warning("playpaq_wm8510: "
"Failed to set CPU transmit period (%d)\n",
ret);
return ret;
}
#endif
pr_debug("playpaq_wm8510: "
"pll_in = %ld, pll_out = %u, bclk = %x, mclk = %x\n",
clk_get_rate(CODEC_CLK), pll_out, bclk, mclk_div);
#if !defined CONFIG_SND_AT32_SOC_PLAYPAQ_SLAVE
ret = snd_soc_dai_set_clkdiv(codec_dai, WM8510_BCLKDIV, bclk);
if (ret < 0) {
pr_warning
("playpaq_wm8510: Failed to set CODEC DAI BCLKDIV (%d)\n",
ret);
return ret;
}
#endif
ret = snd_soc_dai_set_pll(codec_dai, 0, 0,
clk_get_rate(CODEC_CLK), pll_out);
if (ret < 0) {
pr_warning("playpaq_wm8510: Failed to set CODEC DAI PLL (%d)\n",
ret);
return ret;
}
ret = snd_soc_dai_set_clkdiv(codec_dai, WM8510_MCLKDIV, mclk_div);
if (ret < 0) {
pr_warning("playpaq_wm8510: Failed to set CODEC MCLKDIV (%d)\n",
ret);
return ret;
}
return 0;
}
static int playpaq_wm8510_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
int i;
for (i = 0; i < ARRAY_SIZE(playpaq_dapm_widgets); i++)
snd_soc_dapm_new_control(dapm, &playpaq_dapm_widgets[i]);
snd_soc_dapm_add_routes(dapm, intercon, ARRAY_SIZE(intercon));
snd_soc_dapm_enable_pin(dapm, "Int Mic");
snd_soc_dapm_enable_pin(dapm, "Ext Spk");
snd_soc_dapm_sync(dapm);
snd_soc_dai_set_clkdiv(rtd->codec_dai, WM8510_OPCLKDIV,
WM8510_OPCLKDIV_1 | 4);
return 0;
}
static int __init playpaq_asoc_init(void)
{
int ret = 0;
_gclk0 = clk_get(NULL, "gclk0");
if (IS_ERR(_gclk0)) {
_gclk0 = NULL;
goto err_gclk0;
}
_pll0 = clk_get(NULL, "pll0");
if (IS_ERR(_pll0)) {
_pll0 = NULL;
goto err_pll0;
}
if (clk_set_parent(_gclk0, _pll0)) {
pr_warning("snd-soc-playpaq: "
"Failed to set PLL0 as parent for DAC clock\n");
goto err_set_clk;
}
clk_set_rate(CODEC_CLK, 12000000);
clk_enable(CODEC_CLK);
#if defined CONFIG_AT32_ENHANCED_PORTMUX
at32_select_periph(MCLK_PIN, MCLK_PERIPH, 0);
#endif
playpaq_snd_device = platform_device_alloc("soc-audio", 0);
if (playpaq_snd_device == NULL) {
ret = -ENOMEM;
goto err_device_alloc;
}
platform_set_drvdata(playpaq_snd_device, &snd_soc_playpaq);
ret = platform_device_add(playpaq_snd_device);
if (ret) {
pr_warning("playpaq_wm8510: platform_device_add failed (%d)\n",
ret);
goto err_device_add;
}
return 0;
err_device_add:
if (playpaq_snd_device != NULL) {
platform_device_put(playpaq_snd_device);
playpaq_snd_device = NULL;
}
err_device_alloc:
err_set_clk:
if (_pll0 != NULL) {
clk_put(_pll0);
_pll0 = NULL;
}
err_pll0:
if (_gclk0 != NULL) {
clk_put(_gclk0);
_gclk0 = NULL;
}
return ret;
}
static void __exit playpaq_asoc_exit(void)
{
if (_gclk0 != NULL) {
clk_put(_gclk0);
_gclk0 = NULL;
}
if (_pll0 != NULL) {
clk_put(_pll0);
_pll0 = NULL;
}
#if defined CONFIG_AT32_ENHANCED_PORTMUX
at32_free_pin(MCLK_PIN);
#endif
platform_device_unregister(playpaq_snd_device);
playpaq_snd_device = NULL;
}
