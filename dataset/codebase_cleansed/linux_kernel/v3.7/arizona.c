int arizona_in_ev(struct snd_soc_dapm_widget *w, struct snd_kcontrol *kcontrol,
int event)
{
return 0;
}
int arizona_out_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
return 0;
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
val |= 1 << ARIZONA_SYSCLK_FREQ_SHIFT;
break;
case 22579200:
case 24576000:
val |= 2 << ARIZONA_SYSCLK_FREQ_SHIFT;
break;
case 45158400:
case 49152000:
val |= 3 << ARIZONA_SYSCLK_FREQ_SHIFT;
break;
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
int lrclk, bclk, mode, base;
base = dai->driver->base;
lrclk = 0;
bclk = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
mode = 0;
break;
case SND_SOC_DAIFMT_DSP_B:
mode = 1;
break;
case SND_SOC_DAIFMT_I2S:
mode = 2;
break;
case SND_SOC_DAIFMT_LEFT_J:
mode = 3;
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
snd_soc_update_bits(codec, base + ARIZONA_AIF_BCLK_CTRL,
ARIZONA_AIF1_BCLK_INV | ARIZONA_AIF1_BCLK_MSTR,
bclk);
snd_soc_update_bits(codec, base + ARIZONA_AIF_TX_PIN_CTRL,
ARIZONA_AIF1TX_LRCLK_INV |
ARIZONA_AIF1TX_LRCLK_MSTR, lrclk);
snd_soc_update_bits(codec, base + ARIZONA_AIF_RX_PIN_CTRL,
ARIZONA_AIF1RX_LRCLK_INV |
ARIZONA_AIF1RX_LRCLK_MSTR, lrclk);
snd_soc_update_bits(codec, base + ARIZONA_AIF_FORMAT,
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
if (base_rate % 8000)
constraint = &arizona_44k1_constraint;
else
constraint = &arizona_48k_constraint;
return snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
constraint);
}
static int arizona_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona_dai_priv *dai_priv = &priv->dai[dai->id - 1];
int base = dai->driver->base;
const int *rates;
int i;
int bclk, lrclk, wl, frame, sr_val;
if (params_rate(params) % 8000)
rates = &arizona_44k1_bclk_rates[0];
else
rates = &arizona_48k_bclk_rates[0];
for (i = 0; i < ARRAY_SIZE(arizona_44k1_bclk_rates); i++) {
if (rates[i] >= snd_soc_params_to_bclk(params) &&
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
for (i = 0; i < ARRAY_SIZE(arizona_sr_vals); i++)
if (arizona_sr_vals[i] == params_rate(params))
break;
if (i == ARRAY_SIZE(arizona_sr_vals)) {
arizona_aif_err(dai, "Unsupported sample rate %dHz\n",
params_rate(params));
return -EINVAL;
}
sr_val = i;
lrclk = snd_soc_params_to_bclk(params) / params_rate(params);
arizona_aif_dbg(dai, "BCLK %dHz LRCLK %dHz\n",
rates[bclk], rates[bclk] / lrclk);
wl = snd_pcm_format_width(params_format(params));
frame = wl << ARIZONA_AIF1TX_WL_SHIFT | wl;
switch (dai_priv->clk) {
case ARIZONA_CLK_SYSCLK:
snd_soc_update_bits(codec, ARIZONA_SAMPLE_RATE_1,
ARIZONA_SAMPLE_RATE_1_MASK, sr_val);
snd_soc_update_bits(codec, base + ARIZONA_AIF_RATE_CTRL,
ARIZONA_AIF1_RATE_MASK, 0);
break;
case ARIZONA_CLK_ASYNCCLK:
snd_soc_update_bits(codec, ARIZONA_ASYNC_SAMPLE_RATE_1,
ARIZONA_ASYNC_SAMPLE_RATE_MASK, sr_val);
snd_soc_update_bits(codec, base + ARIZONA_AIF_RATE_CTRL,
ARIZONA_AIF1_RATE_MASK, 8);
break;
default:
arizona_aif_err(dai, "Invalid clock %d\n", dai_priv->clk);
return -EINVAL;
}
snd_soc_update_bits(codec, base + ARIZONA_AIF_BCLK_CTRL,
ARIZONA_AIF1_BCLK_FREQ_MASK, bclk);
snd_soc_update_bits(codec, base + ARIZONA_AIF_TX_BCLK_RATE,
ARIZONA_AIF1TX_BCPF_MASK, lrclk);
snd_soc_update_bits(codec, base + ARIZONA_AIF_RX_BCLK_RATE,
ARIZONA_AIF1RX_BCPF_MASK, lrclk);
snd_soc_update_bits(codec, base + ARIZONA_AIF_FRAME_CTRL_1,
ARIZONA_AIF1TX_WL_MASK |
ARIZONA_AIF1TX_SLOT_LEN_MASK, frame);
snd_soc_update_bits(codec, base + ARIZONA_AIF_FRAME_CTRL_2,
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
memset(&routes, 0, sizeof(routes));
routes[0].sink = dai->driver->capture.stream_name;
routes[1].sink = dai->driver->playback.stream_name;
routes[0].source = arizona_dai_clk_str(dai_priv->clk);
routes[1].source = arizona_dai_clk_str(dai_priv->clk);
snd_soc_dapm_del_routes(&codec->dapm, routes, ARRAY_SIZE(routes));
routes[0].source = arizona_dai_clk_str(clk_id);
routes[1].source = arizona_dai_clk_str(clk_id);
snd_soc_dapm_add_routes(&codec->dapm, routes, ARRAY_SIZE(routes));
return snd_soc_dapm_sync(&codec->dapm);
}
int arizona_init_dai(struct arizona_priv *priv, int id)
{
struct arizona_dai_priv *dai_priv = &priv->dai[id];
dai_priv->clk = ARIZONA_CLK_SYSCLK;
return 0;
}
static irqreturn_t arizona_fll_lock(int irq, void *data)
{
struct arizona_fll *fll = data;
arizona_fll_dbg(fll, "Lock status changed\n");
complete(&fll->lock);
return IRQ_HANDLED;
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
cfg->n = target / (ratio * Fref);
if (target % Fref) {
gcd_fll = gcd(target, ratio * Fref);
arizona_fll_dbg(fll, "GCD=%u\n", gcd_fll);
cfg->theta = (target - (cfg->n * ratio * Fref))
/ gcd_fll;
cfg->lambda = (ratio * Fref) / gcd_fll;
} else {
cfg->theta = 0;
cfg->lambda = 0;
}
arizona_fll_dbg(fll, "N=%x THETA=%x LAMBDA=%x\n",
cfg->n, cfg->theta, cfg->lambda);
arizona_fll_dbg(fll, "FRATIO=%x(%d) OUTDIV=%x REFCLK_DIV=%x\n",
cfg->fratio, cfg->fratio, cfg->outdiv, cfg->refdiv);
return 0;
}
static void arizona_apply_fll(struct arizona *arizona, unsigned int base,
struct arizona_fll_cfg *cfg, int source)
{
regmap_update_bits(arizona->regmap, base + 3,
ARIZONA_FLL1_THETA_MASK, cfg->theta);
regmap_update_bits(arizona->regmap, base + 4,
ARIZONA_FLL1_LAMBDA_MASK, cfg->lambda);
regmap_update_bits(arizona->regmap, base + 5,
ARIZONA_FLL1_FRATIO_MASK,
cfg->fratio << ARIZONA_FLL1_FRATIO_SHIFT);
regmap_update_bits(arizona->regmap, base + 6,
ARIZONA_FLL1_CLK_REF_DIV_MASK |
ARIZONA_FLL1_CLK_REF_SRC_MASK,
cfg->refdiv << ARIZONA_FLL1_CLK_REF_DIV_SHIFT |
source << ARIZONA_FLL1_CLK_REF_SRC_SHIFT);
regmap_update_bits(arizona->regmap, base + 2,
ARIZONA_FLL1_CTRL_UPD | ARIZONA_FLL1_N_MASK,
ARIZONA_FLL1_CTRL_UPD | cfg->n);
}
int arizona_set_fll(struct arizona_fll *fll, int source,
unsigned int Fref, unsigned int Fout)
{
struct arizona *arizona = fll->arizona;
struct arizona_fll_cfg cfg, sync;
unsigned int reg, val;
int syncsrc;
bool ena;
int ret;
ret = regmap_read(arizona->regmap, fll->base + 1, &reg);
if (ret != 0) {
arizona_fll_err(fll, "Failed to read current state: %d\n",
ret);
return ret;
}
ena = reg & ARIZONA_FLL1_ENA;
if (Fout) {
regmap_read(arizona->regmap, ARIZONA_CLOCK_32K_1, &val);
switch (val & ARIZONA_CLK_32K_SRC_MASK) {
case ARIZONA_CLK_SRC_MCLK1:
case ARIZONA_CLK_SRC_MCLK2:
syncsrc = val & ARIZONA_CLK_32K_SRC_MASK;
break;
default:
syncsrc = -1;
}
if (source == syncsrc)
syncsrc = -1;
if (syncsrc >= 0) {
ret = arizona_calc_fll(fll, &sync, Fref, Fout);
if (ret != 0)
return ret;
ret = arizona_calc_fll(fll, &cfg, 32768, Fout);
if (ret != 0)
return ret;
} else {
ret = arizona_calc_fll(fll, &cfg, Fref, Fout);
if (ret != 0)
return ret;
}
} else {
regmap_update_bits(arizona->regmap, fll->base + 1,
ARIZONA_FLL1_ENA, 0);
regmap_update_bits(arizona->regmap, fll->base + 0x11,
ARIZONA_FLL1_SYNC_ENA, 0);
if (ena)
pm_runtime_put_autosuspend(arizona->dev);
return 0;
}
regmap_update_bits(arizona->regmap, fll->base + 5,
ARIZONA_FLL1_OUTDIV_MASK,
cfg.outdiv << ARIZONA_FLL1_OUTDIV_SHIFT);
if (syncsrc >= 0) {
arizona_apply_fll(arizona, fll->base, &cfg, syncsrc);
arizona_apply_fll(arizona, fll->base + 0x10, &sync, source);
} else {
arizona_apply_fll(arizona, fll->base, &cfg, source);
}
if (!ena)
pm_runtime_get(arizona->dev);
try_wait_for_completion(&fll->ok);
regmap_update_bits(arizona->regmap, fll->base + 1,
ARIZONA_FLL1_ENA, ARIZONA_FLL1_ENA);
if (syncsrc >= 0)
regmap_update_bits(arizona->regmap, fll->base + 0x11,
ARIZONA_FLL1_SYNC_ENA,
ARIZONA_FLL1_SYNC_ENA);
ret = wait_for_completion_timeout(&fll->ok,
msecs_to_jiffies(25));
if (ret == 0)
arizona_fll_warn(fll, "Timed out waiting for lock\n");
return 0;
}
int arizona_init_fll(struct arizona *arizona, int id, int base, int lock_irq,
int ok_irq, struct arizona_fll *fll)
{
int ret;
init_completion(&fll->lock);
init_completion(&fll->ok);
fll->id = id;
fll->base = base;
fll->arizona = arizona;
snprintf(fll->lock_name, sizeof(fll->lock_name), "FLL%d lock", id);
snprintf(fll->clock_ok_name, sizeof(fll->clock_ok_name),
"FLL%d clock OK", id);
ret = arizona_request_irq(arizona, lock_irq, fll->lock_name,
arizona_fll_lock, fll);
if (ret != 0) {
dev_err(arizona->dev, "Failed to get FLL%d lock IRQ: %d\n",
id, ret);
}
ret = arizona_request_irq(arizona, ok_irq, fll->clock_ok_name,
arizona_fll_clock_ok, fll);
if (ret != 0) {
dev_err(arizona->dev, "Failed to get FLL%d clock OK IRQ: %d\n",
id, ret);
}
return 0;
}
