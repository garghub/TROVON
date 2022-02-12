static int adau1373_pll_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct adau1373 *adau1373 = snd_soc_codec_get_drvdata(codec);
unsigned int pll_id = w->name[3] - '1';
unsigned int val;
if (SND_SOC_DAPM_EVENT_ON(event))
val = ADAU1373_PLL_CTRL6_PLL_EN;
else
val = 0;
regmap_update_bits(adau1373->regmap, ADAU1373_PLL_CTRL6(pll_id),
ADAU1373_PLL_CTRL6_PLL_EN, val);
if (SND_SOC_DAPM_EVENT_ON(event))
mdelay(5);
return 0;
}
static int adau1373_check_aif_clk(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = source->codec;
struct adau1373 *adau1373 = snd_soc_codec_get_drvdata(codec);
unsigned int dai;
const char *clk;
dai = sink->name[3] - '1';
if (!adau1373->dais[dai].master)
return 0;
if (adau1373->dais[dai].clk_src == ADAU1373_CLK_SRC_PLL1)
clk = "SYSCLK1";
else
clk = "SYSCLK2";
return strcmp(source->name, clk) == 0;
}
static int adau1373_check_src(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = source->codec;
struct adau1373 *adau1373 = snd_soc_codec_get_drvdata(codec);
unsigned int dai;
dai = sink->name[3] - '1';
return adau1373->dais[dai].enable_src;
}
static int adau1373_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct adau1373 *adau1373 = snd_soc_codec_get_drvdata(codec);
struct adau1373_dai *adau1373_dai = &adau1373->dais[dai->id];
unsigned int div;
unsigned int freq;
unsigned int ctrl;
freq = adau1373_dai->sysclk;
if (freq % params_rate(params) != 0)
return -EINVAL;
switch (freq / params_rate(params)) {
case 1024:
div = 0;
break;
case 1536:
div = 1;
break;
case 2048:
div = 2;
break;
case 3072:
div = 3;
break;
case 4096:
div = 4;
break;
case 6144:
div = 5;
break;
case 5632:
div = 6;
break;
default:
return -EINVAL;
}
adau1373_dai->enable_src = (div != 0);
regmap_update_bits(adau1373->regmap, ADAU1373_BCLKDIV(dai->id),
ADAU1373_BCLKDIV_SR_MASK | ADAU1373_BCLKDIV_BCLK_MASK,
(div << 2) | ADAU1373_BCLKDIV_64);
switch (params_width(params)) {
case 16:
ctrl = ADAU1373_DAI_WLEN_16;
break;
case 20:
ctrl = ADAU1373_DAI_WLEN_20;
break;
case 24:
ctrl = ADAU1373_DAI_WLEN_24;
break;
case 32:
ctrl = ADAU1373_DAI_WLEN_32;
break;
default:
return -EINVAL;
}
return regmap_update_bits(adau1373->regmap, ADAU1373_DAI(dai->id),
ADAU1373_DAI_WLEN_MASK, ctrl);
}
static int adau1373_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct adau1373 *adau1373 = snd_soc_codec_get_drvdata(codec);
struct adau1373_dai *adau1373_dai = &adau1373->dais[dai->id];
unsigned int ctrl;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
ctrl = ADAU1373_DAI_MASTER;
adau1373_dai->master = true;
break;
case SND_SOC_DAIFMT_CBS_CFS:
ctrl = 0;
adau1373_dai->master = false;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
ctrl |= ADAU1373_DAI_FORMAT_I2S;
break;
case SND_SOC_DAIFMT_LEFT_J:
ctrl |= ADAU1373_DAI_FORMAT_LEFT_J;
break;
case SND_SOC_DAIFMT_RIGHT_J:
ctrl |= ADAU1373_DAI_FORMAT_RIGHT_J;
break;
case SND_SOC_DAIFMT_DSP_B:
ctrl |= ADAU1373_DAI_FORMAT_DSP;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
ctrl |= ADAU1373_DAI_INVERT_BCLK;
break;
case SND_SOC_DAIFMT_NB_IF:
ctrl |= ADAU1373_DAI_INVERT_LRCLK;
break;
case SND_SOC_DAIFMT_IB_IF:
ctrl |= ADAU1373_DAI_INVERT_LRCLK | ADAU1373_DAI_INVERT_BCLK;
break;
default:
return -EINVAL;
}
regmap_update_bits(adau1373->regmap, ADAU1373_DAI(dai->id),
~ADAU1373_DAI_WLEN_MASK, ctrl);
return 0;
}
static int adau1373_set_dai_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct adau1373 *adau1373 = snd_soc_codec_get_drvdata(dai->codec);
struct adau1373_dai *adau1373_dai = &adau1373->dais[dai->id];
switch (clk_id) {
case ADAU1373_CLK_SRC_PLL1:
case ADAU1373_CLK_SRC_PLL2:
break;
default:
return -EINVAL;
}
adau1373_dai->sysclk = freq;
adau1373_dai->clk_src = clk_id;
regmap_update_bits(adau1373->regmap, ADAU1373_BCLKDIV(dai->id),
ADAU1373_BCLKDIV_SOURCE, clk_id << 5);
return 0;
}
static int adau1373_set_pll(struct snd_soc_codec *codec, int pll_id,
int source, unsigned int freq_in, unsigned int freq_out)
{
struct adau1373 *adau1373 = snd_soc_codec_get_drvdata(codec);
unsigned int dpll_div = 0;
unsigned int x, r, n, m, i, j, mode;
switch (pll_id) {
case ADAU1373_PLL1:
case ADAU1373_PLL2:
break;
default:
return -EINVAL;
}
switch (source) {
case ADAU1373_PLL_SRC_BCLK1:
case ADAU1373_PLL_SRC_BCLK2:
case ADAU1373_PLL_SRC_BCLK3:
case ADAU1373_PLL_SRC_LRCLK1:
case ADAU1373_PLL_SRC_LRCLK2:
case ADAU1373_PLL_SRC_LRCLK3:
case ADAU1373_PLL_SRC_MCLK1:
case ADAU1373_PLL_SRC_MCLK2:
case ADAU1373_PLL_SRC_GPIO1:
case ADAU1373_PLL_SRC_GPIO2:
case ADAU1373_PLL_SRC_GPIO3:
case ADAU1373_PLL_SRC_GPIO4:
break;
default:
return -EINVAL;
}
if (freq_in < 7813 || freq_in > 27000000)
return -EINVAL;
if (freq_out < 45158000 || freq_out > 49152000)
return -EINVAL;
while (freq_in < 8000000) {
freq_in *= 2;
dpll_div++;
}
if (freq_out % freq_in != 0) {
x = DIV_ROUND_UP(freq_in, 13500000);
freq_in /= x;
r = freq_out / freq_in;
i = freq_out % freq_in;
j = gcd(i, freq_in);
n = i / j;
m = freq_in / j;
x--;
mode = 1;
} else {
r = freq_out / freq_in;
n = 0;
m = 0;
x = 0;
mode = 0;
}
if (r < 2 || r > 8 || x > 3 || m > 0xffff || n > 0xffff)
return -EINVAL;
if (dpll_div) {
dpll_div = 11 - dpll_div;
regmap_update_bits(adau1373->regmap, ADAU1373_PLL_CTRL6(pll_id),
ADAU1373_PLL_CTRL6_DPLL_BYPASS, 0);
} else {
regmap_update_bits(adau1373->regmap, ADAU1373_PLL_CTRL6(pll_id),
ADAU1373_PLL_CTRL6_DPLL_BYPASS,
ADAU1373_PLL_CTRL6_DPLL_BYPASS);
}
regmap_write(adau1373->regmap, ADAU1373_DPLL_CTRL(pll_id),
(source << 4) | dpll_div);
regmap_write(adau1373->regmap, ADAU1373_PLL_CTRL1(pll_id), (m >> 8) & 0xff);
regmap_write(adau1373->regmap, ADAU1373_PLL_CTRL2(pll_id), m & 0xff);
regmap_write(adau1373->regmap, ADAU1373_PLL_CTRL3(pll_id), (n >> 8) & 0xff);
regmap_write(adau1373->regmap, ADAU1373_PLL_CTRL4(pll_id), n & 0xff);
regmap_write(adau1373->regmap, ADAU1373_PLL_CTRL5(pll_id),
(r << 3) | (x << 1) | mode);
regmap_update_bits(adau1373->regmap, ADAU1373_CLK_SRC_DIV(pll_id), 0x3f, 0x09);
return 0;
}
static void adau1373_load_drc_settings(struct adau1373 *adau1373,
unsigned int nr, uint8_t *drc)
{
unsigned int i;
for (i = 0; i < ADAU1373_DRC_SIZE; ++i)
regmap_write(adau1373->regmap, ADAU1373_DRC(nr) + i, drc[i]);
}
static bool adau1373_valid_micbias(enum adau1373_micbias_voltage micbias)
{
switch (micbias) {
case ADAU1373_MICBIAS_2_9V:
case ADAU1373_MICBIAS_2_2V:
case ADAU1373_MICBIAS_2_6V:
case ADAU1373_MICBIAS_1_8V:
return true;
default:
break;
}
return false;
}
static int adau1373_probe(struct snd_soc_codec *codec)
{
struct adau1373 *adau1373 = snd_soc_codec_get_drvdata(codec);
struct adau1373_platform_data *pdata = codec->dev->platform_data;
bool lineout_differential = false;
unsigned int val;
int i;
if (pdata) {
if (pdata->num_drc > ARRAY_SIZE(pdata->drc_setting))
return -EINVAL;
if (!adau1373_valid_micbias(pdata->micbias1) ||
!adau1373_valid_micbias(pdata->micbias2))
return -EINVAL;
for (i = 0; i < pdata->num_drc; ++i) {
adau1373_load_drc_settings(adau1373, i,
pdata->drc_setting[i]);
}
snd_soc_add_codec_controls(codec, adau1373_drc_controls,
pdata->num_drc);
val = 0;
for (i = 0; i < 4; ++i) {
if (pdata->input_differential[i])
val |= BIT(i);
}
regmap_write(adau1373->regmap, ADAU1373_INPUT_MODE, val);
val = 0;
if (pdata->lineout_differential)
val |= ADAU1373_OUTPUT_CTRL_LDIFF;
if (pdata->lineout_ground_sense)
val |= ADAU1373_OUTPUT_CTRL_LNFBEN;
regmap_write(adau1373->regmap, ADAU1373_OUTPUT_CTRL, val);
lineout_differential = pdata->lineout_differential;
regmap_write(adau1373->regmap, ADAU1373_EP_CTRL,
(pdata->micbias1 << ADAU1373_EP_CTRL_MICBIAS1_OFFSET) |
(pdata->micbias2 << ADAU1373_EP_CTRL_MICBIAS2_OFFSET));
}
if (!lineout_differential) {
snd_soc_add_codec_controls(codec, adau1373_lineout2_controls,
ARRAY_SIZE(adau1373_lineout2_controls));
}
regmap_write(adau1373->regmap, ADAU1373_ADC_CTRL,
ADAU1373_ADC_CTRL_RESET_FORCE | ADAU1373_ADC_CTRL_PEAK_DETECT);
return 0;
}
static int adau1373_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct adau1373 *adau1373 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
regmap_update_bits(adau1373->regmap, ADAU1373_PWDN_CTRL3,
ADAU1373_PWDN_CTRL3_PWR_EN, ADAU1373_PWDN_CTRL3_PWR_EN);
break;
case SND_SOC_BIAS_OFF:
regmap_update_bits(adau1373->regmap, ADAU1373_PWDN_CTRL3,
ADAU1373_PWDN_CTRL3_PWR_EN, 0);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int adau1373_resume(struct snd_soc_codec *codec)
{
struct adau1373 *adau1373 = snd_soc_codec_get_drvdata(codec);
regcache_sync(adau1373->regmap);
return 0;
}
static bool adau1373_register_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case ADAU1373_SOFT_RESET:
case ADAU1373_ADC_DAC_STATUS:
return true;
default:
return false;
}
}
static int adau1373_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct adau1373 *adau1373;
int ret;
adau1373 = devm_kzalloc(&client->dev, sizeof(*adau1373), GFP_KERNEL);
if (!adau1373)
return -ENOMEM;
adau1373->regmap = devm_regmap_init_i2c(client,
&adau1373_regmap_config);
if (IS_ERR(adau1373->regmap))
return PTR_ERR(adau1373->regmap);
regmap_write(adau1373->regmap, ADAU1373_SOFT_RESET, 0x00);
dev_set_drvdata(&client->dev, adau1373);
ret = snd_soc_register_codec(&client->dev, &adau1373_codec_driver,
adau1373_dai_driver, ARRAY_SIZE(adau1373_dai_driver));
return ret;
}
static int adau1373_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
