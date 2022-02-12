static int arizona_spk_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
struct snd_soc_codec *codec = w->codec;
struct arizona *arizona = dev_get_drvdata(codec->dev->parent);
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
bool manual_ena = false;
int val;
switch (arizona->type) {
case WM5102:
switch (arizona->rev) {
case 0:
break;
default:
manual_ena = true;
break;
}
default:
break;
}
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
if (!priv->spk_ena && manual_ena) {
regmap_write_async(arizona->regmap, 0x4f5, 0x25a);
priv->spk_ena_pending = true;
}
break;
case SND_SOC_DAPM_POST_PMU:
val = snd_soc_read(codec, ARIZONA_INTERRUPT_RAW_STATUS_3);
if (val & ARIZONA_SPK_SHUTDOWN_STS) {
dev_crit(arizona->dev,
"Speaker not enabled due to temperature\n");
return -EBUSY;
}
regmap_update_bits_async(arizona->regmap,
ARIZONA_OUTPUT_ENABLES_1,
1 << w->shift, 1 << w->shift);
if (priv->spk_ena_pending) {
msleep(75);
regmap_write_async(arizona->regmap, 0x4f5, 0xda);
priv->spk_ena_pending = false;
priv->spk_ena++;
}
break;
case SND_SOC_DAPM_PRE_PMD:
if (manual_ena) {
priv->spk_ena--;
if (!priv->spk_ena)
regmap_write_async(arizona->regmap,
0x4f5, 0x25a);
}
regmap_update_bits_async(arizona->regmap,
ARIZONA_OUTPUT_ENABLES_1,
1 << w->shift, 0);
break;
case SND_SOC_DAPM_POST_PMD:
if (manual_ena) {
if (!priv->spk_ena)
regmap_write_async(arizona->regmap,
0x4f5, 0x0da);
}
break;
}
return 0;
}
static irqreturn_t arizona_thermal_warn(int irq, void *data)
{
struct arizona *arizona = data;
unsigned int val;
int ret;
ret = regmap_read(arizona->regmap, ARIZONA_INTERRUPT_RAW_STATUS_3,
&val);
if (ret != 0) {
dev_err(arizona->dev, "Failed to read thermal status: %d\n",
ret);
} else if (val & ARIZONA_SPK_SHUTDOWN_WARN_STS) {
dev_crit(arizona->dev, "Thermal warning\n");
}
return IRQ_HANDLED;
}
static irqreturn_t arizona_thermal_shutdown(int irq, void *data)
{
struct arizona *arizona = data;
unsigned int val;
int ret;
ret = regmap_read(arizona->regmap, ARIZONA_INTERRUPT_RAW_STATUS_3,
&val);
if (ret != 0) {
dev_err(arizona->dev, "Failed to read thermal status: %d\n",
ret);
} else if (val & ARIZONA_SPK_SHUTDOWN_STS) {
dev_crit(arizona->dev, "Thermal shutdown\n");
ret = regmap_update_bits(arizona->regmap,
ARIZONA_OUTPUT_ENABLES_1,
ARIZONA_OUT4L_ENA |
ARIZONA_OUT4R_ENA, 0);
if (ret != 0)
dev_crit(arizona->dev,
"Failed to disable speaker outputs: %d\n",
ret);
}
return IRQ_HANDLED;
}
int arizona_init_spk(struct snd_soc_codec *codec)
{
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->arizona;
int ret;
ret = snd_soc_dapm_new_controls(&codec->dapm, &arizona_spkl, 1);
if (ret != 0)
return ret;
switch (arizona->type) {
case WM8997:
break;
default:
ret = snd_soc_dapm_new_controls(&codec->dapm,
&arizona_spkr, 1);
if (ret != 0)
return ret;
break;
}
ret = arizona_request_irq(arizona, ARIZONA_IRQ_SPK_SHUTDOWN_WARN,
"Thermal warning", arizona_thermal_warn,
arizona);
if (ret != 0)
dev_err(arizona->dev,
"Failed to get thermal warning IRQ: %d\n",
ret);
ret = arizona_request_irq(arizona, ARIZONA_IRQ_SPK_SHUTDOWN,
"Thermal shutdown", arizona_thermal_shutdown,
arizona);
if (ret != 0)
dev_err(arizona->dev,
"Failed to get thermal shutdown IRQ: %d\n",
ret);
return 0;
}
int arizona_init_gpio(struct snd_soc_codec *codec)
{
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->arizona;
int i;
switch (arizona->type) {
case WM5110:
snd_soc_dapm_disable_pin(&codec->dapm, "DRC2 Signal Activity");
break;
default:
break;
}
snd_soc_dapm_disable_pin(&codec->dapm, "DRC1 Signal Activity");
for (i = 0; i < ARRAY_SIZE(arizona->pdata.gpio_defaults); i++) {
switch (arizona->pdata.gpio_defaults[i] & ARIZONA_GPN_FN_MASK) {
case ARIZONA_GP_FN_DRC1_SIGNAL_DETECT:
snd_soc_dapm_enable_pin(&codec->dapm,
"DRC1 Signal Activity");
break;
case ARIZONA_GP_FN_DRC2_SIGNAL_DETECT:
snd_soc_dapm_enable_pin(&codec->dapm,
"DRC2 Signal Activity");
break;
default:
break;
}
}
return 0;
}
static void arizona_in_set_vu(struct snd_soc_codec *codec, int ena)
{
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
unsigned int val;
int i;
if (ena)
val = ARIZONA_IN_VU;
else
val = 0;
for (i = 0; i < priv->num_inputs; i++)
snd_soc_update_bits(codec,
ARIZONA_ADC_DIGITAL_VOLUME_1L + (i * 4),
ARIZONA_IN_VU, val);
}
int arizona_in_ev(struct snd_soc_dapm_widget *w, struct snd_kcontrol *kcontrol,
int event)
{
struct arizona_priv *priv = snd_soc_codec_get_drvdata(w->codec);
unsigned int reg;
if (w->shift % 2)
reg = ARIZONA_ADC_DIGITAL_VOLUME_1L + ((w->shift / 2) * 8);
else
reg = ARIZONA_ADC_DIGITAL_VOLUME_1R + ((w->shift / 2) * 8);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
priv->in_pending++;
break;
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(w->codec, reg, ARIZONA_IN1L_MUTE, 0);
priv->in_pending--;
if (priv->in_pending == 0) {
msleep(1);
arizona_in_set_vu(w->codec, 1);
}
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(w->codec, reg,
ARIZONA_IN1L_MUTE | ARIZONA_IN_VU,
ARIZONA_IN1L_MUTE | ARIZONA_IN_VU);
break;
case SND_SOC_DAPM_POST_PMD:
reg = snd_soc_read(w->codec, ARIZONA_INPUT_ENABLES);
if (reg == 0)
arizona_in_set_vu(w->codec, 0);
}
return 0;
}
int arizona_out_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
switch (event) {
case SND_SOC_DAPM_POST_PMU:
switch (w->shift) {
case ARIZONA_OUT1L_ENA_SHIFT:
case ARIZONA_OUT1R_ENA_SHIFT:
case ARIZONA_OUT2L_ENA_SHIFT:
case ARIZONA_OUT2R_ENA_SHIFT:
case ARIZONA_OUT3L_ENA_SHIFT:
case ARIZONA_OUT3R_ENA_SHIFT:
msleep(17);
break;
default:
break;
}
break;
}
return 0;
}
int arizona_hp_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
struct arizona_priv *priv = snd_soc_codec_get_drvdata(w->codec);
struct arizona *arizona = priv->arizona;
unsigned int mask = 1 << w->shift;
unsigned int val;
switch (event) {
case SND_SOC_DAPM_POST_PMU:
val = mask;
break;
case SND_SOC_DAPM_PRE_PMD:
val = 0;
break;
default:
return -EINVAL;
}
priv->arizona->hp_ena &= ~mask;
priv->arizona->hp_ena |= val;
if (priv->arizona->hpdet_magic)
val = 0;
regmap_update_bits_async(arizona->regmap, ARIZONA_OUTPUT_ENABLES_1,
mask, val);
return arizona_out_ev(w, kcontrol, event);
}
static int arizona_set_opclk(struct snd_soc_codec *codec, unsigned int clk,
unsigned int freq)
{
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
unsigned int reg;
unsigned int *rates;
int ref, div, refclk;
switch (clk) {
case ARIZONA_CLK_OPCLK:
reg = ARIZONA_OUTPUT_SYSTEM_CLOCK;
refclk = priv->sysclk;
break;
case ARIZONA_CLK_ASYNC_OPCLK:
reg = ARIZONA_OUTPUT_ASYNC_CLOCK;
refclk = priv->asyncclk;
break;
default:
return -EINVAL;
}
if (refclk % 8000)
rates = arizona_sysclk_44k1_rates;
else
rates = arizona_sysclk_48k_rates;
for (ref = 0; ref < ARRAY_SIZE(arizona_sysclk_48k_rates) &&
rates[ref] <= refclk; ref++) {
div = 1;
while (rates[ref] / div >= freq && div < 32) {
if (rates[ref] / div == freq) {
dev_dbg(codec->dev, "Configured %dHz OPCLK\n",
freq);
snd_soc_update_bits(codec, reg,
ARIZONA_OPCLK_DIV_MASK |
ARIZONA_OPCLK_SEL_MASK,
(div <<
ARIZONA_OPCLK_DIV_SHIFT) |
ref);
return 0;
}
div++;
}
}
dev_err(codec->dev, "Unable to generate %dHz OPCLK\n", freq);
return -EINVAL;
}
int arizona_set_sysclk(struct snd_soc_codec *codec, int clk_id,
int source, unsigned int freq, int dir)
{
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->arizona;
char *name;
unsigned int reg;
unsigned int mask = ARIZONA_SYSCLK_FREQ_MASK | ARIZONA_SYSCLK_SRC_MASK;
unsigned int val = source << ARIZONA_SYSCLK_SRC_SHIFT;
unsigned int *clk;
switch (clk_id) {
case ARIZONA_CLK_SYSCLK:
name = "SYSCLK";
reg = ARIZONA_SYSTEM_CLOCK_1;
clk = &priv->sysclk;
mask |= ARIZONA_SYSCLK_FRAC;
break;
case ARIZONA_CLK_ASYNCCLK:
name = "ASYNCCLK";
reg = ARIZONA_ASYNC_CLOCK_1;
clk = &priv->asyncclk;
break;
case ARIZONA_CLK_OPCLK:
case ARIZONA_CLK_ASYNC_OPCLK:
return arizona_set_opclk(codec, clk_id, freq);
default:
return -EINVAL;
}
switch (freq) {
case 5644800:
case 6144000:
break;
case 11289600:
case 12288000:
val |= ARIZONA_CLK_12MHZ << ARIZONA_SYSCLK_FREQ_SHIFT;
break;
case 22579200:
case 24576000:
val |= ARIZONA_CLK_24MHZ << ARIZONA_SYSCLK_FREQ_SHIFT;
break;
case 45158400:
case 49152000:
val |= ARIZONA_CLK_49MHZ << ARIZONA_SYSCLK_FREQ_SHIFT;
break;
case 67737600:
case 73728000:
val |= ARIZONA_CLK_73MHZ << ARIZONA_SYSCLK_FREQ_SHIFT;
break;
case 90316800:
case 98304000:
val |= ARIZONA_CLK_98MHZ << ARIZONA_SYSCLK_FREQ_SHIFT;
break;
case 135475200:
case 147456000:
val |= ARIZONA_CLK_147MHZ << ARIZONA_SYSCLK_FREQ_SHIFT;
break;
case 0:
dev_dbg(arizona->dev, "%s cleared\n", name);
*clk = freq;
return 0;
default:
return -EINVAL;
}
*clk = freq;
if (freq % 6144000)
val |= ARIZONA_SYSCLK_FRAC;
dev_dbg(arizona->dev, "%s set to %uHz", name, freq);
return regmap_update_bits(arizona->regmap, reg, mask, val);
}
static int arizona_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->arizona;
int lrclk, bclk, mode, base;
base = dai->driver->base;
lrclk = 0;
bclk = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
mode = 0;
break;
case SND_SOC_DAIFMT_I2S:
mode = 2;
break;
default:
arizona_aif_err(dai, "Unsupported DAI format %d\n",
fmt & SND_SOC_DAIFMT_FORMAT_MASK);
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
case SND_SOC_DAIFMT_CBS_CFM:
lrclk |= ARIZONA_AIF1TX_LRCLK_MSTR;
break;
case SND_SOC_DAIFMT_CBM_CFS:
bclk |= ARIZONA_AIF1_BCLK_MSTR;
break;
case SND_SOC_DAIFMT_CBM_CFM:
bclk |= ARIZONA_AIF1_BCLK_MSTR;
lrclk |= ARIZONA_AIF1TX_LRCLK_MSTR;
break;
default:
arizona_aif_err(dai, "Unsupported master mode %d\n",
fmt & SND_SOC_DAIFMT_MASTER_MASK);
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
bclk |= ARIZONA_AIF1_BCLK_INV;
lrclk |= ARIZONA_AIF1TX_LRCLK_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
bclk |= ARIZONA_AIF1_BCLK_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
lrclk |= ARIZONA_AIF1TX_LRCLK_INV;
break;
default:
return -EINVAL;
}
regmap_update_bits_async(arizona->regmap, base + ARIZONA_AIF_BCLK_CTRL,
ARIZONA_AIF1_BCLK_INV |
ARIZONA_AIF1_BCLK_MSTR,
bclk);
regmap_update_bits_async(arizona->regmap, base + ARIZONA_AIF_TX_PIN_CTRL,
ARIZONA_AIF1TX_LRCLK_INV |
ARIZONA_AIF1TX_LRCLK_MSTR, lrclk);
regmap_update_bits_async(arizona->regmap,
base + ARIZONA_AIF_RX_PIN_CTRL,
ARIZONA_AIF1RX_LRCLK_INV |
ARIZONA_AIF1RX_LRCLK_MSTR, lrclk);
regmap_update_bits(arizona->regmap, base + ARIZONA_AIF_FORMAT,
ARIZONA_AIF1_FMT_MASK, mode);
return 0;
}
static int arizona_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona_dai_priv *dai_priv = &priv->dai[dai->id - 1];
const struct snd_pcm_hw_constraint_list *constraint;
unsigned int base_rate;
switch (dai_priv->clk) {
case ARIZONA_CLK_SYSCLK:
base_rate = priv->sysclk;
break;
case ARIZONA_CLK_ASYNCCLK:
base_rate = priv->asyncclk;
break;
default:
return 0;
}
if (base_rate == 0)
return 0;
if (base_rate % 8000)
constraint = &arizona_44k1_constraint;
else
constraint = &arizona_48k_constraint;
return snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
constraint);
}
static int arizona_hw_params_rate(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona_dai_priv *dai_priv = &priv->dai[dai->id - 1];
int base = dai->driver->base;
int i, sr_val;
for (i = 0; i < ARRAY_SIZE(arizona_sr_vals); i++)
if (arizona_sr_vals[i] == params_rate(params))
break;
if (i == ARRAY_SIZE(arizona_sr_vals)) {
arizona_aif_err(dai, "Unsupported sample rate %dHz\n",
params_rate(params));
return -EINVAL;
}
sr_val = i;
switch (dai_priv->clk) {
case ARIZONA_CLK_SYSCLK:
snd_soc_update_bits(codec, ARIZONA_SAMPLE_RATE_1,
ARIZONA_SAMPLE_RATE_1_MASK, sr_val);
if (base)
snd_soc_update_bits(codec, base + ARIZONA_AIF_RATE_CTRL,
ARIZONA_AIF1_RATE_MASK, 0);
break;
case ARIZONA_CLK_ASYNCCLK:
snd_soc_update_bits(codec, ARIZONA_ASYNC_SAMPLE_RATE_1,
ARIZONA_ASYNC_SAMPLE_RATE_MASK, sr_val);
if (base)
snd_soc_update_bits(codec, base + ARIZONA_AIF_RATE_CTRL,
ARIZONA_AIF1_RATE_MASK,
8 << ARIZONA_AIF1_RATE_SHIFT);
break;
default:
arizona_aif_err(dai, "Invalid clock %d\n", dai_priv->clk);
return -EINVAL;
}
return 0;
}
static int arizona_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->arizona;
int base = dai->driver->base;
const int *rates;
int i, ret, val;
int chan_limit = arizona->pdata.max_channels_clocked[dai->id - 1];
int bclk, lrclk, wl, frame, bclk_target;
if (params_rate(params) % 8000)
rates = &arizona_44k1_bclk_rates[0];
else
rates = &arizona_48k_bclk_rates[0];
bclk_target = snd_soc_params_to_bclk(params);
if (chan_limit && chan_limit < params_channels(params)) {
arizona_aif_dbg(dai, "Limiting to %d channels\n", chan_limit);
bclk_target /= params_channels(params);
bclk_target *= chan_limit;
}
val = snd_soc_read(codec, base + ARIZONA_AIF_FORMAT);
if (params_channels(params) == 1 && (val & ARIZONA_AIF1_FMT_MASK)) {
arizona_aif_dbg(dai, "Forcing stereo mode\n");
bclk_target *= 2;
}
for (i = 0; i < ARRAY_SIZE(arizona_44k1_bclk_rates); i++) {
if (rates[i] >= bclk_target &&
rates[i] % params_rate(params) == 0) {
bclk = i;
break;
}
}
if (i == ARRAY_SIZE(arizona_44k1_bclk_rates)) {
arizona_aif_err(dai, "Unsupported sample rate %dHz\n",
params_rate(params));
return -EINVAL;
}
lrclk = rates[bclk] / params_rate(params);
arizona_aif_dbg(dai, "BCLK %dHz LRCLK %dHz\n",
rates[bclk], rates[bclk] / lrclk);
wl = snd_pcm_format_width(params_format(params));
frame = wl << ARIZONA_AIF1TX_WL_SHIFT | wl;
ret = arizona_hw_params_rate(substream, params, dai);
if (ret != 0)
return ret;
regmap_update_bits_async(arizona->regmap,
base + ARIZONA_AIF_BCLK_CTRL,
ARIZONA_AIF1_BCLK_FREQ_MASK, bclk);
regmap_update_bits_async(arizona->regmap,
base + ARIZONA_AIF_TX_BCLK_RATE,
ARIZONA_AIF1TX_BCPF_MASK, lrclk);
regmap_update_bits_async(arizona->regmap,
base + ARIZONA_AIF_RX_BCLK_RATE,
ARIZONA_AIF1RX_BCPF_MASK, lrclk);
regmap_update_bits_async(arizona->regmap,
base + ARIZONA_AIF_FRAME_CTRL_1,
ARIZONA_AIF1TX_WL_MASK |
ARIZONA_AIF1TX_SLOT_LEN_MASK, frame);
regmap_update_bits(arizona->regmap, base + ARIZONA_AIF_FRAME_CTRL_2,
ARIZONA_AIF1RX_WL_MASK |
ARIZONA_AIF1RX_SLOT_LEN_MASK, frame);
return 0;
}
static const char *arizona_dai_clk_str(int clk_id)
{
switch (clk_id) {
case ARIZONA_CLK_SYSCLK:
return "SYSCLK";
case ARIZONA_CLK_ASYNCCLK:
return "ASYNCCLK";
default:
return "Unknown clock";
}
}
static int arizona_dai_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona_dai_priv *dai_priv = &priv->dai[dai->id - 1];
struct snd_soc_dapm_route routes[2];
switch (clk_id) {
case ARIZONA_CLK_SYSCLK:
case ARIZONA_CLK_ASYNCCLK:
break;
default:
return -EINVAL;
}
if (clk_id == dai_priv->clk)
return 0;
if (dai->active) {
dev_err(codec->dev, "Can't change clock on active DAI %d\n",
dai->id);
return -EBUSY;
}
dev_dbg(codec->dev, "Setting AIF%d to %s\n", dai->id + 1,
arizona_dai_clk_str(clk_id));
memset(&routes, 0, sizeof(routes));
routes[0].sink = dai->driver->capture.stream_name;
routes[1].sink = dai->driver->playback.stream_name;
routes[0].source = arizona_dai_clk_str(dai_priv->clk);
routes[1].source = arizona_dai_clk_str(dai_priv->clk);
snd_soc_dapm_del_routes(&codec->dapm, routes, ARRAY_SIZE(routes));
routes[0].source = arizona_dai_clk_str(clk_id);
routes[1].source = arizona_dai_clk_str(clk_id);
snd_soc_dapm_add_routes(&codec->dapm, routes, ARRAY_SIZE(routes));
dai_priv->clk = clk_id;
return snd_soc_dapm_sync(&codec->dapm);
}
static int arizona_set_tristate(struct snd_soc_dai *dai, int tristate)
{
struct snd_soc_codec *codec = dai->codec;
int base = dai->driver->base;
unsigned int reg;
if (tristate)
reg = ARIZONA_AIF1_TRI;
else
reg = 0;
return snd_soc_update_bits(codec, base + ARIZONA_AIF_RATE_CTRL,
ARIZONA_AIF1_TRI, reg);
}
int arizona_init_dai(struct arizona_priv *priv, int id)
{
struct arizona_dai_priv *dai_priv = &priv->dai[id];
dai_priv->clk = ARIZONA_CLK_SYSCLK;
return 0;
}
static irqreturn_t arizona_fll_clock_ok(int irq, void *data)
{
struct arizona_fll *fll = data;
arizona_fll_dbg(fll, "clock OK\n");
complete(&fll->ok);
return IRQ_HANDLED;
}
static int arizona_calc_fll(struct arizona_fll *fll,
struct arizona_fll_cfg *cfg,
unsigned int Fref,
unsigned int Fout)
{
unsigned int target, div, gcd_fll;
int i, ratio;
arizona_fll_dbg(fll, "Fref=%u Fout=%u\n", Fref, Fout);
div = 1;
cfg->refdiv = 0;
while ((Fref / div) > 13500000) {
div *= 2;
cfg->refdiv++;
if (div > 8) {
arizona_fll_err(fll,
"Can't scale %dMHz in to <=13.5MHz\n",
Fref);
return -EINVAL;
}
}
Fref /= div;
div = 1;
while (Fout * div < 90000000 * fll->vco_mult) {
div++;
if (div > 7) {
arizona_fll_err(fll, "No FLL_OUTDIV for Fout=%uHz\n",
Fout);
return -EINVAL;
}
}
target = Fout * div / fll->vco_mult;
cfg->outdiv = div;
arizona_fll_dbg(fll, "Fvco=%dHz\n", target);
for (i = 0; i < ARRAY_SIZE(fll_fratios); i++) {
if (fll_fratios[i].min <= Fref && Fref <= fll_fratios[i].max) {
cfg->fratio = fll_fratios[i].fratio;
ratio = fll_fratios[i].ratio;
break;
}
}
if (i == ARRAY_SIZE(fll_fratios)) {
arizona_fll_err(fll, "Unable to find FRATIO for Fref=%uHz\n",
Fref);
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(fll_gains); i++) {
if (fll_gains[i].min <= Fref && Fref <= fll_gains[i].max) {
cfg->gain = fll_gains[i].gain;
break;
}
}
if (i == ARRAY_SIZE(fll_gains)) {
arizona_fll_err(fll, "Unable to find gain for Fref=%uHz\n",
Fref);
return -EINVAL;
}
cfg->n = target / (ratio * Fref);
if (target % (ratio * Fref)) {
gcd_fll = gcd(target, ratio * Fref);
arizona_fll_dbg(fll, "GCD=%u\n", gcd_fll);
cfg->theta = (target - (cfg->n * ratio * Fref))
/ gcd_fll;
cfg->lambda = (ratio * Fref) / gcd_fll;
} else {
cfg->theta = 0;
cfg->lambda = 0;
}
while (cfg->lambda >= (1 << 16)) {
cfg->theta >>= 1;
cfg->lambda >>= 1;
}
arizona_fll_dbg(fll, "N=%x THETA=%x LAMBDA=%x\n",
cfg->n, cfg->theta, cfg->lambda);
arizona_fll_dbg(fll, "FRATIO=%x(%d) OUTDIV=%x REFCLK_DIV=%x\n",
cfg->fratio, cfg->fratio, cfg->outdiv, cfg->refdiv);
arizona_fll_dbg(fll, "GAIN=%d\n", cfg->gain);
return 0;
}
static void arizona_apply_fll(struct arizona *arizona, unsigned int base,
struct arizona_fll_cfg *cfg, int source,
bool sync)
{
regmap_update_bits_async(arizona->regmap, base + 3,
ARIZONA_FLL1_THETA_MASK, cfg->theta);
regmap_update_bits_async(arizona->regmap, base + 4,
ARIZONA_FLL1_LAMBDA_MASK, cfg->lambda);
regmap_update_bits_async(arizona->regmap, base + 5,
ARIZONA_FLL1_FRATIO_MASK,
cfg->fratio << ARIZONA_FLL1_FRATIO_SHIFT);
regmap_update_bits_async(arizona->regmap, base + 6,
ARIZONA_FLL1_CLK_REF_DIV_MASK |
ARIZONA_FLL1_CLK_REF_SRC_MASK,
cfg->refdiv << ARIZONA_FLL1_CLK_REF_DIV_SHIFT |
source << ARIZONA_FLL1_CLK_REF_SRC_SHIFT);
if (sync)
regmap_update_bits_async(arizona->regmap, base + 0x7,
ARIZONA_FLL1_GAIN_MASK,
cfg->gain << ARIZONA_FLL1_GAIN_SHIFT);
else
regmap_update_bits_async(arizona->regmap, base + 0x9,
ARIZONA_FLL1_GAIN_MASK,
cfg->gain << ARIZONA_FLL1_GAIN_SHIFT);
regmap_update_bits_async(arizona->regmap, base + 2,
ARIZONA_FLL1_CTRL_UPD | ARIZONA_FLL1_N_MASK,
ARIZONA_FLL1_CTRL_UPD | cfg->n);
}
static bool arizona_is_enabled_fll(struct arizona_fll *fll)
{
struct arizona *arizona = fll->arizona;
unsigned int reg;
int ret;
ret = regmap_read(arizona->regmap, fll->base + 1, &reg);
if (ret != 0) {
arizona_fll_err(fll, "Failed to read current state: %d\n",
ret);
return ret;
}
return reg & ARIZONA_FLL1_ENA;
}
static void arizona_enable_fll(struct arizona_fll *fll,
struct arizona_fll_cfg *ref,
struct arizona_fll_cfg *sync)
{
struct arizona *arizona = fll->arizona;
int ret;
bool use_sync = false;
if (fll->ref_src >= 0 && fll->ref_freq &&
fll->ref_src != fll->sync_src) {
regmap_update_bits_async(arizona->regmap, fll->base + 5,
ARIZONA_FLL1_OUTDIV_MASK,
ref->outdiv << ARIZONA_FLL1_OUTDIV_SHIFT);
arizona_apply_fll(arizona, fll->base, ref, fll->ref_src,
false);
if (fll->sync_src >= 0) {
arizona_apply_fll(arizona, fll->base + 0x10, sync,
fll->sync_src, true);
use_sync = true;
}
} else if (fll->sync_src >= 0) {
regmap_update_bits_async(arizona->regmap, fll->base + 5,
ARIZONA_FLL1_OUTDIV_MASK,
sync->outdiv << ARIZONA_FLL1_OUTDIV_SHIFT);
arizona_apply_fll(arizona, fll->base, sync,
fll->sync_src, false);
regmap_update_bits_async(arizona->regmap, fll->base + 0x11,
ARIZONA_FLL1_SYNC_ENA, 0);
} else {
arizona_fll_err(fll, "No clocks provided\n");
return;
}
if (use_sync && fll->sync_freq > 100000)
regmap_update_bits_async(arizona->regmap, fll->base + 0x17,
ARIZONA_FLL1_SYNC_BW, 0);
else
regmap_update_bits_async(arizona->regmap, fll->base + 0x17,
ARIZONA_FLL1_SYNC_BW,
ARIZONA_FLL1_SYNC_BW);
if (!arizona_is_enabled_fll(fll))
pm_runtime_get(arizona->dev);
try_wait_for_completion(&fll->ok);
regmap_update_bits_async(arizona->regmap, fll->base + 1,
ARIZONA_FLL1_FREERUN, 0);
regmap_update_bits_async(arizona->regmap, fll->base + 1,
ARIZONA_FLL1_ENA, ARIZONA_FLL1_ENA);
if (use_sync)
regmap_update_bits_async(arizona->regmap, fll->base + 0x11,
ARIZONA_FLL1_SYNC_ENA,
ARIZONA_FLL1_SYNC_ENA);
ret = wait_for_completion_timeout(&fll->ok,
msecs_to_jiffies(250));
if (ret == 0)
arizona_fll_warn(fll, "Timed out waiting for lock\n");
}
static void arizona_disable_fll(struct arizona_fll *fll)
{
struct arizona *arizona = fll->arizona;
bool change;
regmap_update_bits_async(arizona->regmap, fll->base + 1,
ARIZONA_FLL1_FREERUN, ARIZONA_FLL1_FREERUN);
regmap_update_bits_check(arizona->regmap, fll->base + 1,
ARIZONA_FLL1_ENA, 0, &change);
regmap_update_bits(arizona->regmap, fll->base + 0x11,
ARIZONA_FLL1_SYNC_ENA, 0);
if (change)
pm_runtime_put_autosuspend(arizona->dev);
}
int arizona_set_fll_refclk(struct arizona_fll *fll, int source,
unsigned int Fref, unsigned int Fout)
{
struct arizona_fll_cfg ref, sync;
int ret;
if (fll->ref_src == source && fll->ref_freq == Fref)
return 0;
if (fll->fout) {
if (Fref > 0) {
ret = arizona_calc_fll(fll, &ref, Fref, fll->fout);
if (ret != 0)
return ret;
}
if (fll->sync_src >= 0) {
ret = arizona_calc_fll(fll, &sync, fll->sync_freq,
fll->fout);
if (ret != 0)
return ret;
}
}
fll->ref_src = source;
fll->ref_freq = Fref;
if (fll->fout && Fref > 0) {
arizona_enable_fll(fll, &ref, &sync);
}
return 0;
}
int arizona_set_fll(struct arizona_fll *fll, int source,
unsigned int Fref, unsigned int Fout)
{
struct arizona_fll_cfg ref, sync;
int ret;
if (fll->sync_src == source &&
fll->sync_freq == Fref && fll->fout == Fout)
return 0;
if (Fout) {
if (fll->ref_src >= 0) {
ret = arizona_calc_fll(fll, &ref, fll->ref_freq,
Fout);
if (ret != 0)
return ret;
}
ret = arizona_calc_fll(fll, &sync, Fref, Fout);
if (ret != 0)
return ret;
}
fll->sync_src = source;
fll->sync_freq = Fref;
fll->fout = Fout;
if (Fout) {
arizona_enable_fll(fll, &ref, &sync);
} else {
arizona_disable_fll(fll);
}
return 0;
}
int arizona_init_fll(struct arizona *arizona, int id, int base, int lock_irq,
int ok_irq, struct arizona_fll *fll)
{
int ret;
unsigned int val;
init_completion(&fll->ok);
fll->id = id;
fll->base = base;
fll->arizona = arizona;
fll->sync_src = ARIZONA_FLL_SRC_NONE;
regmap_read(arizona->regmap, ARIZONA_CLOCK_32K_1, &val);
switch (val & ARIZONA_CLK_32K_SRC_MASK) {
case ARIZONA_CLK_SRC_MCLK1:
case ARIZONA_CLK_SRC_MCLK2:
fll->ref_src = val & ARIZONA_CLK_32K_SRC_MASK;
break;
default:
fll->ref_src = ARIZONA_FLL_SRC_NONE;
}
fll->ref_freq = 32768;
snprintf(fll->lock_name, sizeof(fll->lock_name), "FLL%d lock", id);
snprintf(fll->clock_ok_name, sizeof(fll->clock_ok_name),
"FLL%d clock OK", id);
ret = arizona_request_irq(arizona, ok_irq, fll->clock_ok_name,
arizona_fll_clock_ok, fll);
if (ret != 0) {
dev_err(arizona->dev, "Failed to get FLL%d clock OK IRQ: %d\n",
id, ret);
}
regmap_update_bits(arizona->regmap, fll->base + 1,
ARIZONA_FLL1_FREERUN, 0);
return 0;
}
int arizona_set_output_mode(struct snd_soc_codec *codec, int output, bool diff)
{
unsigned int reg, val;
if (output < 1 || output > 6)
return -EINVAL;
reg = ARIZONA_OUTPUT_PATH_CONFIG_1L + (output - 1) * 8;
if (diff)
val = ARIZONA_OUT1_MONO;
else
val = 0;
return snd_soc_update_bits(codec, reg, ARIZONA_OUT1_MONO, val);
}
