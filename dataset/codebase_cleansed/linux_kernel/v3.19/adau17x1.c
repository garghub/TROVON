static int adau17x1_pll_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct adau *adau = snd_soc_codec_get_drvdata(codec);
int ret;
if (SND_SOC_DAPM_EVENT_ON(event)) {
adau->pll_regs[5] = 1;
} else {
adau->pll_regs[5] = 0;
regmap_update_bits(adau->regmap, ADAU17X1_CLOCK_CONTROL,
ADAU17X1_CLOCK_CONTROL_CORECLK_SRC_PLL, 0);
}
ret = regmap_raw_write(adau->regmap, ADAU17X1_PLL_CONTROL,
adau->pll_regs, ARRAY_SIZE(adau->pll_regs));
if (SND_SOC_DAPM_EVENT_ON(event)) {
mdelay(5);
regmap_update_bits(adau->regmap, ADAU17X1_CLOCK_CONTROL,
ADAU17X1_CLOCK_CONTROL_CORECLK_SRC_PLL,
ADAU17X1_CLOCK_CONTROL_CORECLK_SRC_PLL);
}
return 0;
}
static int adau17x1_dsp_mux_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_dapm_kcontrol_codec(kcontrol);
struct adau *adau = snd_soc_codec_get_drvdata(codec);
struct soc_enum *e = (struct soc_enum *)kcontrol->private_value;
struct snd_soc_dapm_update update;
unsigned int stream = e->shift_l;
unsigned int val, change;
int reg;
if (ucontrol->value.enumerated.item[0] >= e->items)
return -EINVAL;
switch (ucontrol->value.enumerated.item[0]) {
case 0:
val = 0;
adau->dsp_bypass[stream] = false;
break;
default:
val = (adau->tdm_slot[stream] * 2) + 1;
adau->dsp_bypass[stream] = true;
break;
}
if (stream == SNDRV_PCM_STREAM_PLAYBACK)
reg = ADAU17X1_SERIAL_INPUT_ROUTE;
else
reg = ADAU17X1_SERIAL_OUTPUT_ROUTE;
change = snd_soc_test_bits(codec, reg, 0xff, val);
if (change) {
update.kcontrol = kcontrol;
update.mask = 0xff;
update.reg = reg;
update.val = val;
snd_soc_dapm_mux_update_power(&codec->dapm, kcontrol,
ucontrol->value.enumerated.item[0], e, &update);
}
return change;
}
static int adau17x1_dsp_mux_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_dapm_kcontrol_codec(kcontrol);
struct adau *adau = snd_soc_codec_get_drvdata(codec);
struct soc_enum *e = (struct soc_enum *)kcontrol->private_value;
unsigned int stream = e->shift_l;
unsigned int reg, val;
int ret;
if (stream == SNDRV_PCM_STREAM_PLAYBACK)
reg = ADAU17X1_SERIAL_INPUT_ROUTE;
else
reg = ADAU17X1_SERIAL_OUTPUT_ROUTE;
ret = regmap_read(adau->regmap, reg, &val);
if (ret)
return ret;
if (val != 0)
val = 1;
ucontrol->value.enumerated.item[0] = val;
return 0;
}
bool adau17x1_has_dsp(struct adau *adau)
{
switch (adau->type) {
case ADAU1761:
case ADAU1381:
case ADAU1781:
return true;
default:
return false;
}
}
static int adau17x1_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct adau *adau = snd_soc_codec_get_drvdata(codec);
unsigned int val, div, dsp_div;
unsigned int freq;
int ret;
if (adau->clk_src == ADAU17X1_CLK_SRC_PLL)
freq = adau->pll_freq;
else
freq = adau->sysclk;
if (freq % params_rate(params) != 0)
return -EINVAL;
switch (freq / params_rate(params)) {
case 1024:
div = 0;
dsp_div = 1;
break;
case 6144:
div = 1;
dsp_div = 6;
break;
case 4096:
div = 2;
dsp_div = 5;
break;
case 3072:
div = 3;
dsp_div = 4;
break;
case 2048:
div = 4;
dsp_div = 3;
break;
case 1536:
div = 5;
dsp_div = 2;
break;
case 512:
div = 6;
dsp_div = 0;
break;
default:
return -EINVAL;
}
regmap_update_bits(adau->regmap, ADAU17X1_CONVERTER0,
ADAU17X1_CONVERTER0_CONVSR_MASK, div);
if (adau17x1_has_dsp(adau)) {
regmap_write(adau->regmap, ADAU17X1_SERIAL_SAMPLING_RATE, div);
regmap_write(adau->regmap, ADAU17X1_DSP_SAMPLING_RATE, dsp_div);
}
if (adau->sigmadsp) {
ret = adau17x1_setup_firmware(adau, params_rate(params));
if (ret < 0)
return ret;
}
if (adau->dai_fmt != SND_SOC_DAIFMT_RIGHT_J)
return 0;
switch (params_width(params)) {
case 16:
val = ADAU17X1_SERIAL_PORT1_DELAY16;
break;
case 24:
val = ADAU17X1_SERIAL_PORT1_DELAY8;
break;
case 32:
val = ADAU17X1_SERIAL_PORT1_DELAY0;
break;
default:
return -EINVAL;
}
return regmap_update_bits(adau->regmap, ADAU17X1_SERIAL_PORT1,
ADAU17X1_SERIAL_PORT1_DELAY_MASK, val);
}
static int adau17x1_set_dai_pll(struct snd_soc_dai *dai, int pll_id,
int source, unsigned int freq_in, unsigned int freq_out)
{
struct snd_soc_codec *codec = dai->codec;
struct adau *adau = snd_soc_codec_get_drvdata(codec);
unsigned int r, n, m, i, j;
unsigned int div;
int ret;
if (freq_in < 8000000 || freq_in > 27000000)
return -EINVAL;
if (!freq_out) {
r = 0;
n = 0;
m = 0;
div = 0;
} else {
if (freq_out % freq_in != 0) {
div = DIV_ROUND_UP(freq_in, 13500000);
freq_in /= div;
r = freq_out / freq_in;
i = freq_out % freq_in;
j = gcd(i, freq_in);
n = i / j;
m = freq_in / j;
div--;
} else {
r = freq_out / freq_in;
n = 0;
m = 0;
div = 0;
}
if (n > 0xffff || m > 0xffff || div > 3 || r > 8 || r < 2)
return -EINVAL;
}
adau->pll_regs[0] = m >> 8;
adau->pll_regs[1] = m & 0xff;
adau->pll_regs[2] = n >> 8;
adau->pll_regs[3] = n & 0xff;
adau->pll_regs[4] = (r << 3) | (div << 1);
if (m != 0)
adau->pll_regs[4] |= 1;
ret = regmap_raw_write(adau->regmap, ADAU17X1_PLL_CONTROL,
adau->pll_regs, ARRAY_SIZE(adau->pll_regs));
if (ret)
return ret;
adau->pll_freq = freq_out;
return 0;
}
static int adau17x1_set_dai_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct adau *adau = snd_soc_codec_get_drvdata(dai->codec);
struct snd_soc_dapm_context *dapm = &dai->codec->dapm;
switch (clk_id) {
case ADAU17X1_CLK_SRC_MCLK:
case ADAU17X1_CLK_SRC_PLL:
break;
default:
return -EINVAL;
}
adau->sysclk = freq;
if (adau->clk_src != clk_id) {
if (clk_id == ADAU17X1_CLK_SRC_PLL) {
snd_soc_dapm_add_routes(dapm,
&adau17x1_dapm_pll_route, 1);
} else {
snd_soc_dapm_del_routes(dapm,
&adau17x1_dapm_pll_route, 1);
}
}
adau->clk_src = clk_id;
return 0;
}
static int adau17x1_set_dai_fmt(struct snd_soc_dai *dai,
unsigned int fmt)
{
struct adau *adau = snd_soc_codec_get_drvdata(dai->codec);
unsigned int ctrl0, ctrl1;
int lrclk_pol;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
ctrl0 = ADAU17X1_SERIAL_PORT0_MASTER;
adau->master = true;
break;
case SND_SOC_DAIFMT_CBS_CFS:
ctrl0 = 0;
adau->master = false;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
lrclk_pol = 0;
ctrl1 = ADAU17X1_SERIAL_PORT1_DELAY1;
break;
case SND_SOC_DAIFMT_LEFT_J:
case SND_SOC_DAIFMT_RIGHT_J:
lrclk_pol = 1;
ctrl1 = ADAU17X1_SERIAL_PORT1_DELAY0;
break;
case SND_SOC_DAIFMT_DSP_A:
lrclk_pol = 1;
ctrl0 |= ADAU17X1_SERIAL_PORT0_PULSE_MODE;
ctrl1 = ADAU17X1_SERIAL_PORT1_DELAY1;
break;
case SND_SOC_DAIFMT_DSP_B:
lrclk_pol = 1;
ctrl0 |= ADAU17X1_SERIAL_PORT0_PULSE_MODE;
ctrl1 = ADAU17X1_SERIAL_PORT1_DELAY0;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
ctrl0 |= ADAU17X1_SERIAL_PORT0_BCLK_POL;
break;
case SND_SOC_DAIFMT_NB_IF:
lrclk_pol = !lrclk_pol;
break;
case SND_SOC_DAIFMT_IB_IF:
ctrl0 |= ADAU17X1_SERIAL_PORT0_BCLK_POL;
lrclk_pol = !lrclk_pol;
break;
default:
return -EINVAL;
}
if (lrclk_pol)
ctrl0 |= ADAU17X1_SERIAL_PORT0_LRCLK_POL;
regmap_write(adau->regmap, ADAU17X1_SERIAL_PORT0, ctrl0);
regmap_write(adau->regmap, ADAU17X1_SERIAL_PORT1, ctrl1);
adau->dai_fmt = fmt & SND_SOC_DAIFMT_FORMAT_MASK;
return 0;
}
static int adau17x1_set_dai_tdm_slot(struct snd_soc_dai *dai,
unsigned int tx_mask, unsigned int rx_mask, int slots, int slot_width)
{
struct adau *adau = snd_soc_codec_get_drvdata(dai->codec);
unsigned int ser_ctrl0, ser_ctrl1;
unsigned int conv_ctrl0, conv_ctrl1;
if (slots == 0) {
slots = 2;
rx_mask = 3;
tx_mask = 3;
slot_width = 32;
}
switch (slots) {
case 2:
ser_ctrl0 = ADAU17X1_SERIAL_PORT0_STEREO;
break;
case 4:
ser_ctrl0 = ADAU17X1_SERIAL_PORT0_TDM4;
break;
case 8:
if (adau->type == ADAU1361)
return -EINVAL;
ser_ctrl0 = ADAU17X1_SERIAL_PORT0_TDM8;
break;
default:
return -EINVAL;
}
switch (slot_width * slots) {
case 32:
if (adau->type == ADAU1761)
return -EINVAL;
ser_ctrl1 = ADAU17X1_SERIAL_PORT1_BCLK32;
break;
case 64:
ser_ctrl1 = ADAU17X1_SERIAL_PORT1_BCLK64;
break;
case 48:
ser_ctrl1 = ADAU17X1_SERIAL_PORT1_BCLK48;
break;
case 128:
ser_ctrl1 = ADAU17X1_SERIAL_PORT1_BCLK128;
break;
case 256:
if (adau->type == ADAU1361)
return -EINVAL;
ser_ctrl1 = ADAU17X1_SERIAL_PORT1_BCLK256;
break;
default:
return -EINVAL;
}
switch (rx_mask) {
case 0x03:
conv_ctrl1 = ADAU17X1_CONVERTER1_ADC_PAIR(1);
adau->tdm_slot[SNDRV_PCM_STREAM_CAPTURE] = 0;
break;
case 0x0c:
conv_ctrl1 = ADAU17X1_CONVERTER1_ADC_PAIR(2);
adau->tdm_slot[SNDRV_PCM_STREAM_CAPTURE] = 1;
break;
case 0x30:
conv_ctrl1 = ADAU17X1_CONVERTER1_ADC_PAIR(3);
adau->tdm_slot[SNDRV_PCM_STREAM_CAPTURE] = 2;
break;
case 0xc0:
conv_ctrl1 = ADAU17X1_CONVERTER1_ADC_PAIR(4);
adau->tdm_slot[SNDRV_PCM_STREAM_CAPTURE] = 3;
break;
default:
return -EINVAL;
}
switch (tx_mask) {
case 0x03:
conv_ctrl0 = ADAU17X1_CONVERTER0_DAC_PAIR(1);
adau->tdm_slot[SNDRV_PCM_STREAM_PLAYBACK] = 0;
break;
case 0x0c:
conv_ctrl0 = ADAU17X1_CONVERTER0_DAC_PAIR(2);
adau->tdm_slot[SNDRV_PCM_STREAM_PLAYBACK] = 1;
break;
case 0x30:
conv_ctrl0 = ADAU17X1_CONVERTER0_DAC_PAIR(3);
adau->tdm_slot[SNDRV_PCM_STREAM_PLAYBACK] = 2;
break;
case 0xc0:
conv_ctrl0 = ADAU17X1_CONVERTER0_DAC_PAIR(4);
adau->tdm_slot[SNDRV_PCM_STREAM_PLAYBACK] = 3;
break;
default:
return -EINVAL;
}
regmap_update_bits(adau->regmap, ADAU17X1_CONVERTER0,
ADAU17X1_CONVERTER0_DAC_PAIR_MASK, conv_ctrl0);
regmap_update_bits(adau->regmap, ADAU17X1_CONVERTER1,
ADAU17X1_CONVERTER1_ADC_PAIR_MASK, conv_ctrl1);
regmap_update_bits(adau->regmap, ADAU17X1_SERIAL_PORT0,
ADAU17X1_SERIAL_PORT0_TDM_MASK, ser_ctrl0);
regmap_update_bits(adau->regmap, ADAU17X1_SERIAL_PORT1,
ADAU17X1_SERIAL_PORT1_BCLK_MASK, ser_ctrl1);
if (!adau17x1_has_dsp(adau))
return 0;
if (adau->dsp_bypass[SNDRV_PCM_STREAM_PLAYBACK]) {
regmap_write(adau->regmap, ADAU17X1_SERIAL_INPUT_ROUTE,
(adau->tdm_slot[SNDRV_PCM_STREAM_PLAYBACK] * 2) + 1);
}
if (adau->dsp_bypass[SNDRV_PCM_STREAM_CAPTURE]) {
regmap_write(adau->regmap, ADAU17X1_SERIAL_OUTPUT_ROUTE,
(adau->tdm_slot[SNDRV_PCM_STREAM_CAPTURE] * 2) + 1);
}
return 0;
}
static int adau17x1_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct adau *adau = snd_soc_codec_get_drvdata(dai->codec);
if (adau->sigmadsp)
return sigmadsp_restrict_params(adau->sigmadsp, substream);
return 0;
}
int adau17x1_set_micbias_voltage(struct snd_soc_codec *codec,
enum adau17x1_micbias_voltage micbias)
{
struct adau *adau = snd_soc_codec_get_drvdata(codec);
switch (micbias) {
case ADAU17X1_MICBIAS_0_90_AVDD:
case ADAU17X1_MICBIAS_0_65_AVDD:
break;
default:
return -EINVAL;
}
return regmap_write(adau->regmap, ADAU17X1_MICBIAS, micbias << 2);
}
bool adau17x1_precious_register(struct device *dev, unsigned int reg)
{
if (reg < 0x400)
return true;
return false;
}
bool adau17x1_readable_register(struct device *dev, unsigned int reg)
{
if (reg < 0x400)
return true;
switch (reg) {
case ADAU17X1_CLOCK_CONTROL:
case ADAU17X1_PLL_CONTROL:
case ADAU17X1_REC_POWER_MGMT:
case ADAU17X1_MICBIAS:
case ADAU17X1_SERIAL_PORT0:
case ADAU17X1_SERIAL_PORT1:
case ADAU17X1_CONVERTER0:
case ADAU17X1_CONVERTER1:
case ADAU17X1_LEFT_INPUT_DIGITAL_VOL:
case ADAU17X1_RIGHT_INPUT_DIGITAL_VOL:
case ADAU17X1_ADC_CONTROL:
case ADAU17X1_PLAY_POWER_MGMT:
case ADAU17X1_DAC_CONTROL0:
case ADAU17X1_DAC_CONTROL1:
case ADAU17X1_DAC_CONTROL2:
case ADAU17X1_SERIAL_PORT_PAD:
case ADAU17X1_CONTROL_PORT_PAD0:
case ADAU17X1_CONTROL_PORT_PAD1:
case ADAU17X1_DSP_SAMPLING_RATE:
case ADAU17X1_SERIAL_INPUT_ROUTE:
case ADAU17X1_SERIAL_OUTPUT_ROUTE:
case ADAU17X1_DSP_ENABLE:
case ADAU17X1_DSP_RUN:
case ADAU17X1_SERIAL_SAMPLING_RATE:
return true;
default:
break;
}
return false;
}
bool adau17x1_volatile_register(struct device *dev, unsigned int reg)
{
if (reg < 0x4000)
return true;
switch (reg) {
case ADAU17X1_PLL_CONTROL:
case ADAU17X1_PLL_CONTROL + 1:
case ADAU17X1_PLL_CONTROL + 2:
case ADAU17X1_PLL_CONTROL + 3:
case ADAU17X1_PLL_CONTROL + 4:
case ADAU17X1_PLL_CONTROL + 5:
return true;
default:
break;
}
return false;
}
int adau17x1_setup_firmware(struct adau *adau, unsigned int rate)
{
int ret;
int dspsr;
ret = regmap_read(adau->regmap, ADAU17X1_DSP_SAMPLING_RATE, &dspsr);
if (ret)
return ret;
regmap_write(adau->regmap, ADAU17X1_DSP_ENABLE, 1);
regmap_write(adau->regmap, ADAU17X1_DSP_SAMPLING_RATE, 0xf);
ret = sigmadsp_setup(adau->sigmadsp, rate);
if (ret) {
regmap_write(adau->regmap, ADAU17X1_DSP_ENABLE, 0);
return ret;
}
regmap_write(adau->regmap, ADAU17X1_DSP_SAMPLING_RATE, dspsr);
return 0;
}
int adau17x1_add_widgets(struct snd_soc_codec *codec)
{
struct adau *adau = snd_soc_codec_get_drvdata(codec);
int ret;
ret = snd_soc_add_codec_controls(codec, adau17x1_controls,
ARRAY_SIZE(adau17x1_controls));
if (ret)
return ret;
ret = snd_soc_dapm_new_controls(&codec->dapm, adau17x1_dapm_widgets,
ARRAY_SIZE(adau17x1_dapm_widgets));
if (ret)
return ret;
if (adau17x1_has_dsp(adau)) {
ret = snd_soc_dapm_new_controls(&codec->dapm,
adau17x1_dsp_dapm_widgets,
ARRAY_SIZE(adau17x1_dsp_dapm_widgets));
if (ret)
return ret;
if (!adau->sigmadsp)
return 0;
ret = sigmadsp_attach(adau->sigmadsp, &codec->component);
if (ret) {
dev_err(codec->dev, "Failed to attach firmware: %d\n",
ret);
return ret;
}
}
return 0;
}
int adau17x1_add_routes(struct snd_soc_codec *codec)
{
struct adau *adau = snd_soc_codec_get_drvdata(codec);
int ret;
ret = snd_soc_dapm_add_routes(&codec->dapm, adau17x1_dapm_routes,
ARRAY_SIZE(adau17x1_dapm_routes));
if (ret)
return ret;
if (adau17x1_has_dsp(adau)) {
ret = snd_soc_dapm_add_routes(&codec->dapm,
adau17x1_dsp_dapm_routes,
ARRAY_SIZE(adau17x1_dsp_dapm_routes));
} else {
ret = snd_soc_dapm_add_routes(&codec->dapm,
adau17x1_no_dsp_dapm_routes,
ARRAY_SIZE(adau17x1_no_dsp_dapm_routes));
}
return ret;
}
int adau17x1_resume(struct snd_soc_codec *codec)
{
struct adau *adau = snd_soc_codec_get_drvdata(codec);
if (adau->switch_mode)
adau->switch_mode(codec->dev);
regcache_sync(adau->regmap);
return 0;
}
int adau17x1_probe(struct device *dev, struct regmap *regmap,
enum adau17x1_type type, void (*switch_mode)(struct device *dev),
const char *firmware_name)
{
struct adau *adau;
if (IS_ERR(regmap))
return PTR_ERR(regmap);
adau = devm_kzalloc(dev, sizeof(*adau), GFP_KERNEL);
if (!adau)
return -ENOMEM;
adau->regmap = regmap;
adau->switch_mode = switch_mode;
adau->type = type;
dev_set_drvdata(dev, adau);
if (firmware_name) {
adau->sigmadsp = devm_sigmadsp_init_regmap(dev, regmap, NULL,
firmware_name);
if (IS_ERR(adau->sigmadsp)) {
dev_warn(dev, "Could not find firmware file: %ld\n",
PTR_ERR(adau->sigmadsp));
adau->sigmadsp = NULL;
}
}
if (switch_mode)
switch_mode(dev);
return 0;
}
