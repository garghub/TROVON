static int arizona_spk_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
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
if (val & ARIZONA_SPK_OVERHEAT_STS) {
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
default:
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
} else if (val & ARIZONA_SPK_OVERHEAT_WARN_STS) {
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
} else if (val & ARIZONA_SPK_OVERHEAT_STS) {
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
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->arizona;
int ret;
ret = snd_soc_dapm_new_controls(dapm, &arizona_spkl, 1);
if (ret != 0)
return ret;
switch (arizona->type) {
case WM8997:
case CS47L24:
case WM1831:
break;
default:
ret = snd_soc_dapm_new_controls(dapm, &arizona_spkr, 1);
if (ret != 0)
return ret;
break;
}
ret = arizona_request_irq(arizona, ARIZONA_IRQ_SPK_OVERHEAT_WARN,
"Thermal warning", arizona_thermal_warn,
arizona);
if (ret != 0)
dev_err(arizona->dev,
"Failed to get thermal warning IRQ: %d\n",
ret);
ret = arizona_request_irq(arizona, ARIZONA_IRQ_SPK_OVERHEAT,
"Thermal shutdown", arizona_thermal_shutdown,
arizona);
if (ret != 0)
dev_err(arizona->dev,
"Failed to get thermal shutdown IRQ: %d\n",
ret);
return 0;
}
int arizona_free_spk(struct snd_soc_codec *codec)
{
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->arizona;
arizona_free_irq(arizona, ARIZONA_IRQ_SPK_OVERHEAT_WARN, arizona);
arizona_free_irq(arizona, ARIZONA_IRQ_SPK_OVERHEAT, arizona);
return 0;
}
int arizona_init_mono(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->arizona;
int i;
for (i = 0; i < ARIZONA_MAX_OUTPUT; ++i) {
if (arizona->pdata.out_mono[i])
snd_soc_dapm_add_routes(dapm,
&arizona_mono_routes[i], 1);
}
return 0;
}
int arizona_init_gpio(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->arizona;
int i;
switch (arizona->type) {
case WM5110:
case WM8280:
snd_soc_dapm_disable_pin(dapm, "DRC2 Signal Activity");
break;
default:
break;
}
snd_soc_dapm_disable_pin(dapm, "DRC1 Signal Activity");
for (i = 0; i < ARRAY_SIZE(arizona->pdata.gpio_defaults); i++) {
switch (arizona->pdata.gpio_defaults[i] & ARIZONA_GPN_FN_MASK) {
case ARIZONA_GP_FN_DRC1_SIGNAL_DETECT:
snd_soc_dapm_enable_pin(dapm, "DRC1 Signal Activity");
break;
case ARIZONA_GP_FN_DRC2_SIGNAL_DETECT:
snd_soc_dapm_enable_pin(dapm, "DRC2 Signal Activity");
break;
default:
break;
}
}
return 0;
}
const char *arizona_sample_rate_val_to_name(unsigned int rate_val)
{
int i;
for (i = 0; i < ARRAY_SIZE(arizona_sample_rate_val); ++i) {
if (arizona_sample_rate_val[i] == rate_val)
return arizona_sample_rate_text[i];
}
return "Illegal";
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
bool arizona_input_analog(struct snd_soc_codec *codec, int shift)
{
unsigned int reg = ARIZONA_IN1L_CONTROL + ((shift / 2) * 8);
unsigned int val = snd_soc_read(codec, reg);
return !(val & ARIZONA_IN1_MODE_MASK);
}
int arizona_in_ev(struct snd_soc_dapm_widget *w, struct snd_kcontrol *kcontrol,
int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
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
snd_soc_update_bits(codec, reg, ARIZONA_IN1L_MUTE, 0);
priv->in_pending--;
if (priv->in_pending == 0) {
msleep(1);
arizona_in_set_vu(codec, 1);
}
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, reg,
ARIZONA_IN1L_MUTE | ARIZONA_IN_VU,
ARIZONA_IN1L_MUTE | ARIZONA_IN_VU);
break;
case SND_SOC_DAPM_POST_PMD:
reg = snd_soc_read(codec, ARIZONA_INPUT_ENABLES);
if (reg == 0)
arizona_in_set_vu(codec, 0);
break;
default:
break;
}
return 0;
}
int arizona_out_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
switch (w->shift) {
case ARIZONA_OUT1L_ENA_SHIFT:
case ARIZONA_OUT1R_ENA_SHIFT:
case ARIZONA_OUT2L_ENA_SHIFT:
case ARIZONA_OUT2R_ENA_SHIFT:
case ARIZONA_OUT3L_ENA_SHIFT:
case ARIZONA_OUT3R_ENA_SHIFT:
priv->out_up_pending++;
priv->out_up_delay += 17;
break;
default:
break;
}
break;
case SND_SOC_DAPM_POST_PMU:
switch (w->shift) {
case ARIZONA_OUT1L_ENA_SHIFT:
case ARIZONA_OUT1R_ENA_SHIFT:
case ARIZONA_OUT2L_ENA_SHIFT:
case ARIZONA_OUT2R_ENA_SHIFT:
case ARIZONA_OUT3L_ENA_SHIFT:
case ARIZONA_OUT3R_ENA_SHIFT:
priv->out_up_pending--;
if (!priv->out_up_pending) {
msleep(priv->out_up_delay);
priv->out_up_delay = 0;
}
break;
default:
break;
}
break;
case SND_SOC_DAPM_PRE_PMD:
switch (w->shift) {
case ARIZONA_OUT1L_ENA_SHIFT:
case ARIZONA_OUT1R_ENA_SHIFT:
case ARIZONA_OUT2L_ENA_SHIFT:
case ARIZONA_OUT2R_ENA_SHIFT:
case ARIZONA_OUT3L_ENA_SHIFT:
case ARIZONA_OUT3R_ENA_SHIFT:
priv->out_down_pending++;
priv->out_down_delay++;
break;
default:
break;
}
break;
case SND_SOC_DAPM_POST_PMD:
switch (w->shift) {
case ARIZONA_OUT1L_ENA_SHIFT:
case ARIZONA_OUT1R_ENA_SHIFT:
case ARIZONA_OUT2L_ENA_SHIFT:
case ARIZONA_OUT2R_ENA_SHIFT:
case ARIZONA_OUT3L_ENA_SHIFT:
case ARIZONA_OUT3R_ENA_SHIFT:
priv->out_down_pending--;
if (!priv->out_down_pending) {
msleep(priv->out_down_delay);
priv->out_down_delay = 0;
}
break;
default:
break;
}
break;
default:
break;
}
return 0;
}
int arizona_hp_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
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
case SND_SOC_DAPM_PRE_PMU:
case SND_SOC_DAPM_POST_PMD:
return arizona_out_ev(w, kcontrol, event);
default:
return -EINVAL;
}
priv->arizona->hp_ena &= ~mask;
priv->arizona->hp_ena |= val;
if (priv->arizona->hpdet_clamp)
val = 0;
regmap_update_bits_async(arizona->regmap, ARIZONA_OUTPUT_ENABLES_1,
mask, val);
return arizona_out_ev(w, kcontrol, event);
}
static int arizona_dvfs_enable(struct snd_soc_codec *codec)
{
const struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->arizona;
int ret;
ret = regulator_set_voltage(arizona->dcvdd, 1800000, 1800000);
if (ret) {
dev_err(codec->dev, "Failed to boost DCVDD: %d\n", ret);
return ret;
}
ret = regmap_update_bits(arizona->regmap,
ARIZONA_DYNAMIC_FREQUENCY_SCALING_1,
ARIZONA_SUBSYS_MAX_FREQ,
ARIZONA_SUBSYS_MAX_FREQ);
if (ret) {
dev_err(codec->dev, "Failed to enable subsys max: %d\n", ret);
regulator_set_voltage(arizona->dcvdd, 1200000, 1800000);
return ret;
}
return 0;
}
static int arizona_dvfs_disable(struct snd_soc_codec *codec)
{
const struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->arizona;
int ret;
ret = regmap_update_bits(arizona->regmap,
ARIZONA_DYNAMIC_FREQUENCY_SCALING_1,
ARIZONA_SUBSYS_MAX_FREQ, 0);
if (ret) {
dev_err(codec->dev, "Failed to disable subsys max: %d\n", ret);
return ret;
}
ret = regulator_set_voltage(arizona->dcvdd, 1200000, 1800000);
if (ret) {
dev_err(codec->dev, "Failed to unboost DCVDD: %d\n", ret);
return ret;
}
return 0;
}
int arizona_dvfs_up(struct snd_soc_codec *codec, unsigned int flags)
{
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
int ret = 0;
mutex_lock(&priv->dvfs_lock);
if (!priv->dvfs_cached && !priv->dvfs_reqs) {
ret = arizona_dvfs_enable(codec);
if (ret)
goto err;
}
priv->dvfs_reqs |= flags;
err:
mutex_unlock(&priv->dvfs_lock);
return ret;
}
int arizona_dvfs_down(struct snd_soc_codec *codec, unsigned int flags)
{
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
unsigned int old_reqs;
int ret = 0;
mutex_lock(&priv->dvfs_lock);
old_reqs = priv->dvfs_reqs;
priv->dvfs_reqs &= ~flags;
if (!priv->dvfs_cached && old_reqs && !priv->dvfs_reqs)
ret = arizona_dvfs_disable(codec);
mutex_unlock(&priv->dvfs_lock);
return ret;
}
int arizona_dvfs_sysclk_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
int ret = 0;
mutex_lock(&priv->dvfs_lock);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
if (priv->dvfs_reqs)
ret = arizona_dvfs_enable(codec);
priv->dvfs_cached = false;
break;
case SND_SOC_DAPM_PRE_PMD:
priv->dvfs_cached = true;
if (priv->dvfs_reqs)
ret = arizona_dvfs_disable(codec);
break;
default:
break;
}
mutex_unlock(&priv->dvfs_lock);
return ret;
}
void arizona_init_dvfs(struct arizona_priv *priv)
{
mutex_init(&priv->dvfs_lock);
}
int arizona_anc_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
unsigned int val;
switch (event) {
case SND_SOC_DAPM_POST_PMU:
val = 1 << w->shift;
break;
case SND_SOC_DAPM_PRE_PMD:
val = 1 << (w->shift + 1);
break;
default:
return 0;
}
snd_soc_write(codec, ARIZONA_CLOCK_CONTROL, val);
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
rates = arizona_opclk_ref_44k1_rates;
else
rates = arizona_opclk_ref_48k_rates;
for (ref = 0; ref < ARRAY_SIZE(arizona_opclk_ref_48k_rates) &&
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
int *clk;
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
mode = ARIZONA_FMT_DSP_MODE_A;
break;
case SND_SOC_DAIFMT_DSP_B:
if ((fmt & SND_SOC_DAIFMT_MASTER_MASK)
!= SND_SOC_DAIFMT_CBM_CFM) {
arizona_aif_err(dai, "DSP_B not valid in slave mode\n");
return -EINVAL;
}
mode = ARIZONA_FMT_DSP_MODE_B;
break;
case SND_SOC_DAIFMT_I2S:
mode = ARIZONA_FMT_I2S_MODE;
break;
case SND_SOC_DAIFMT_LEFT_J:
if ((fmt & SND_SOC_DAIFMT_MASTER_MASK)
!= SND_SOC_DAIFMT_CBM_CFM) {
arizona_aif_err(dai, "LEFT_J not valid in slave mode\n");
return -EINVAL;
}
mode = ARIZONA_FMT_LEFT_JUSTIFIED_MODE;
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
unsigned int base_rate;
if (!substream->runtime)
return 0;
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
dai_priv->constraint.mask = ARIZONA_RATE_MASK;
else if (base_rate % 8000)
dai_priv->constraint.mask = ARIZONA_44K1_RATE_MASK;
else
dai_priv->constraint.mask = ARIZONA_48K_RATE_MASK;
return snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&dai_priv->constraint);
}
static void arizona_wm5102_set_dac_comp(struct snd_soc_codec *codec,
unsigned int rate)
{
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->arizona;
struct reg_sequence dac_comp[] = {
{ 0x80, 0x3 },
{ ARIZONA_DAC_COMP_1, 0 },
{ ARIZONA_DAC_COMP_2, 0 },
{ 0x80, 0x0 },
};
mutex_lock(&arizona->dac_comp_lock);
dac_comp[1].def = arizona->dac_comp_coeff;
if (rate >= 176400)
dac_comp[2].def = arizona->dac_comp_enabled;
mutex_unlock(&arizona->dac_comp_lock);
regmap_multi_reg_write(arizona->regmap,
dac_comp,
ARRAY_SIZE(dac_comp));
}
static int arizona_hw_params_rate(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona_dai_priv *dai_priv = &priv->dai[dai->id - 1];
int base = dai->driver->base;
int i, sr_val, ret;
for (i = 0; i < ARRAY_SIZE(arizona_sr_vals); i++)
if (arizona_sr_vals[i] == params_rate(params))
break;
if (i == ARRAY_SIZE(arizona_sr_vals)) {
arizona_aif_err(dai, "Unsupported sample rate %dHz\n",
params_rate(params));
return -EINVAL;
}
sr_val = i;
switch (priv->arizona->type) {
case WM5102:
case WM8997:
if (arizona_sr_vals[sr_val] >= 88200)
ret = arizona_dvfs_up(codec, ARIZONA_DVFS_SR1_RQ);
else
ret = arizona_dvfs_down(codec, ARIZONA_DVFS_SR1_RQ);
if (ret) {
arizona_aif_err(dai, "Failed to change DVFS %d\n", ret);
return ret;
}
break;
default:
break;
}
switch (dai_priv->clk) {
case ARIZONA_CLK_SYSCLK:
switch (priv->arizona->type) {
case WM5102:
arizona_wm5102_set_dac_comp(codec,
params_rate(params));
break;
default:
break;
}
snd_soc_update_bits(codec, ARIZONA_SAMPLE_RATE_1,
ARIZONA_SAMPLE_RATE_1_MASK, sr_val);
if (base)
snd_soc_update_bits(codec, base + ARIZONA_AIF_RATE_CTRL,
ARIZONA_AIF1_RATE_MASK, 0);
break;
case ARIZONA_CLK_ASYNCCLK:
snd_soc_update_bits(codec, ARIZONA_ASYNC_SAMPLE_RATE_1,
ARIZONA_ASYNC_SAMPLE_RATE_1_MASK, sr_val);
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
static bool arizona_aif_cfg_changed(struct snd_soc_codec *codec,
int base, int bclk, int lrclk, int frame)
{
int val;
val = snd_soc_read(codec, base + ARIZONA_AIF_BCLK_CTRL);
if (bclk != (val & ARIZONA_AIF1_BCLK_FREQ_MASK))
return true;
val = snd_soc_read(codec, base + ARIZONA_AIF_TX_BCLK_RATE);
if (lrclk != (val & ARIZONA_AIF1TX_BCPF_MASK))
return true;
val = snd_soc_read(codec, base + ARIZONA_AIF_FRAME_CTRL_1);
if (frame != (val & (ARIZONA_AIF1TX_WL_MASK |
ARIZONA_AIF1TX_SLOT_LEN_MASK)))
return true;
return false;
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
int channels = params_channels(params);
int chan_limit = arizona->pdata.max_channels_clocked[dai->id - 1];
int tdm_width = arizona->tdm_width[dai->id - 1];
int tdm_slots = arizona->tdm_slots[dai->id - 1];
int bclk, lrclk, wl, frame, bclk_target;
bool reconfig;
unsigned int aif_tx_state, aif_rx_state;
if (params_rate(params) % 4000)
rates = &arizona_44k1_bclk_rates[0];
else
rates = &arizona_48k_bclk_rates[0];
wl = params_width(params);
if (tdm_slots) {
arizona_aif_dbg(dai, "Configuring for %d %d bit TDM slots\n",
tdm_slots, tdm_width);
bclk_target = tdm_slots * tdm_width * params_rate(params);
channels = tdm_slots;
} else {
bclk_target = snd_soc_params_to_bclk(params);
tdm_width = wl;
}
if (chan_limit && chan_limit < channels) {
arizona_aif_dbg(dai, "Limiting to %d channels\n", chan_limit);
bclk_target /= channels;
bclk_target *= chan_limit;
}
val = snd_soc_read(codec, base + ARIZONA_AIF_FORMAT);
val &= ARIZONA_AIF1_FMT_MASK;
if ((channels & 1) && (val == ARIZONA_FMT_I2S_MODE)) {
arizona_aif_dbg(dai, "Forcing stereo mode\n");
bclk_target /= channels;
bclk_target *= channels + 1;
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
frame = wl << ARIZONA_AIF1TX_WL_SHIFT | tdm_width;
reconfig = arizona_aif_cfg_changed(codec, base, bclk, lrclk, frame);
if (reconfig) {
aif_tx_state = snd_soc_read(codec,
base + ARIZONA_AIF_TX_ENABLES);
aif_rx_state = snd_soc_read(codec,
base + ARIZONA_AIF_RX_ENABLES);
regmap_update_bits_async(arizona->regmap,
base + ARIZONA_AIF_TX_ENABLES, 0xff, 0x0);
regmap_update_bits(arizona->regmap,
base + ARIZONA_AIF_RX_ENABLES, 0xff, 0x0);
}
ret = arizona_hw_params_rate(substream, params, dai);
if (ret != 0)
goto restore_aif;
if (reconfig) {
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
regmap_update_bits(arizona->regmap,
base + ARIZONA_AIF_FRAME_CTRL_2,
ARIZONA_AIF1RX_WL_MASK |
ARIZONA_AIF1RX_SLOT_LEN_MASK, frame);
}
restore_aif:
if (reconfig) {
regmap_update_bits_async(arizona->regmap,
base + ARIZONA_AIF_TX_ENABLES,
0xff, aif_tx_state);
regmap_update_bits(arizona->regmap,
base + ARIZONA_AIF_RX_ENABLES,
0xff, aif_rx_state);
}
return ret;
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
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
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
snd_soc_dapm_del_routes(dapm, routes, ARRAY_SIZE(routes));
routes[0].source = arizona_dai_clk_str(clk_id);
routes[1].source = arizona_dai_clk_str(clk_id);
snd_soc_dapm_add_routes(dapm, routes, ARRAY_SIZE(routes));
dai_priv->clk = clk_id;
return snd_soc_dapm_sync(dapm);
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
static void arizona_set_channels_to_mask(struct snd_soc_dai *dai,
unsigned int base,
int channels, unsigned int mask)
{
struct snd_soc_codec *codec = dai->codec;
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->arizona;
int slot, i;
for (i = 0; i < channels; ++i) {
slot = ffs(mask) - 1;
if (slot < 0)
return;
regmap_write(arizona->regmap, base + i, slot);
mask &= ~(1 << slot);
}
if (mask)
arizona_aif_warn(dai, "Too many channels in TDM mask\n");
}
static int arizona_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
unsigned int rx_mask, int slots, int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
struct arizona_priv *priv = snd_soc_codec_get_drvdata(codec);
struct arizona *arizona = priv->arizona;
int base = dai->driver->base;
int rx_max_chan = dai->driver->playback.channels_max;
int tx_max_chan = dai->driver->capture.channels_max;
if (dai->id > ARIZONA_MAX_AIF)
return -ENOTSUPP;
if (slots == 0) {
tx_mask = (1 << tx_max_chan) - 1;
rx_mask = (1 << rx_max_chan) - 1;
}
arizona_set_channels_to_mask(dai, base + ARIZONA_AIF_FRAME_CTRL_3,
tx_max_chan, tx_mask);
arizona_set_channels_to_mask(dai, base + ARIZONA_AIF_FRAME_CTRL_11,
rx_max_chan, rx_mask);
arizona->tdm_width[dai->id - 1] = slot_width;
arizona->tdm_slots[dai->id - 1] = slots;
return 0;
}
int arizona_init_dai(struct arizona_priv *priv, int id)
{
struct arizona_dai_priv *dai_priv = &priv->dai[id];
dai_priv->clk = ARIZONA_CLK_SYSCLK;
dai_priv->constraint = arizona_constraint;
return 0;
}
static int arizona_validate_fll(struct arizona_fll *fll,
unsigned int Fref,
unsigned int Fout)
{
unsigned int Fvco_min;
if (fll->fout && Fout != fll->fout) {
arizona_fll_err(fll,
"Can't change output on active FLL\n");
return -EINVAL;
}
if (Fref / ARIZONA_FLL_MAX_REFDIV > ARIZONA_FLL_MAX_FREF) {
arizona_fll_err(fll,
"Can't scale %dMHz in to <=13.5MHz\n",
Fref);
return -EINVAL;
}
Fvco_min = ARIZONA_FLL_MIN_FVCO * fll->vco_mult;
if (Fout * ARIZONA_FLL_MAX_OUTDIV < Fvco_min) {
arizona_fll_err(fll, "No FLL_OUTDIV for Fout=%uHz\n",
Fout);
return -EINVAL;
}
return 0;
}
static int arizona_find_fratio(unsigned int Fref, int *fratio)
{
int i;
for (i = 0; i < ARRAY_SIZE(fll_fratios); i++) {
if (fll_fratios[i].min <= Fref && Fref <= fll_fratios[i].max) {
if (fratio)
*fratio = fll_fratios[i].fratio;
return fll_fratios[i].ratio;
}
}
return -EINVAL;
}
static int arizona_calc_fratio(struct arizona_fll *fll,
struct arizona_fll_cfg *cfg,
unsigned int target,
unsigned int Fref, bool sync)
{
int init_ratio, ratio;
int refdiv, div;
div = 1;
cfg->refdiv = 0;
while (Fref > ARIZONA_FLL_MAX_FREF) {
div *= 2;
Fref /= 2;
cfg->refdiv++;
if (div > ARIZONA_FLL_MAX_REFDIV)
return -EINVAL;
}
init_ratio = arizona_find_fratio(Fref, &cfg->fratio);
if (init_ratio < 0) {
arizona_fll_err(fll, "Unable to find FRATIO for Fref=%uHz\n",
Fref);
return init_ratio;
}
switch (fll->arizona->type) {
case WM5102:
case WM8997:
return init_ratio;
case WM5110:
case WM8280:
if (fll->arizona->rev < 3 || sync)
return init_ratio;
break;
default:
if (sync)
return init_ratio;
break;
}
cfg->fratio = init_ratio - 1;
refdiv = cfg->refdiv;
arizona_fll_dbg(fll, "pseudo: initial ratio=%u fref=%u refdiv=%u\n",
init_ratio, Fref, refdiv);
while (div <= ARIZONA_FLL_MAX_REFDIV) {
for (ratio = init_ratio; ratio > 0; ratio--) {
if (target % (ratio * Fref)) {
cfg->refdiv = refdiv;
cfg->fratio = ratio - 1;
arizona_fll_dbg(fll,
"pseudo: found fref=%u refdiv=%d(%d) ratio=%d\n",
Fref, refdiv, div, ratio);
return ratio;
}
}
for (ratio = init_ratio + 1; ratio <= ARIZONA_FLL_MAX_FRATIO;
ratio++) {
if ((ARIZONA_FLL_VCO_CORNER / 2) /
(fll->vco_mult * ratio) < Fref) {
arizona_fll_dbg(fll, "pseudo: hit VCO corner\n");
break;
}
if (Fref > pseudo_fref_max[ratio - 1]) {
arizona_fll_dbg(fll,
"pseudo: exceeded max fref(%u) for ratio=%u\n",
pseudo_fref_max[ratio - 1],
ratio);
break;
}
if (target % (ratio * Fref)) {
cfg->refdiv = refdiv;
cfg->fratio = ratio - 1;
arizona_fll_dbg(fll,
"pseudo: found fref=%u refdiv=%d(%d) ratio=%d\n",
Fref, refdiv, div, ratio);
return ratio;
}
}
div *= 2;
Fref /= 2;
refdiv++;
init_ratio = arizona_find_fratio(Fref, NULL);
arizona_fll_dbg(fll,
"pseudo: change fref=%u refdiv=%d(%d) ratio=%u\n",
Fref, refdiv, div, init_ratio);
}
arizona_fll_warn(fll, "Falling back to integer mode operation\n");
return cfg->fratio + 1;
}
static int arizona_calc_fll(struct arizona_fll *fll,
struct arizona_fll_cfg *cfg,
unsigned int Fref, bool sync)
{
unsigned int target, div, gcd_fll;
int i, ratio;
arizona_fll_dbg(fll, "Fref=%u Fout=%u\n", Fref, fll->fout);
div = ARIZONA_FLL_MIN_OUTDIV;
while (fll->fout * div < ARIZONA_FLL_MIN_FVCO * fll->vco_mult) {
div++;
if (div > ARIZONA_FLL_MAX_OUTDIV)
return -EINVAL;
}
target = fll->fout * div / fll->vco_mult;
cfg->outdiv = div;
arizona_fll_dbg(fll, "Fvco=%dHz\n", target);
ratio = arizona_calc_fratio(fll, cfg, target, Fref, sync);
if (ratio < 0)
return ratio;
Fref = Fref / (1 << cfg->refdiv);
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
arizona_fll_dbg(fll, "N=%d THETA=%d LAMBDA=%d\n",
cfg->n, cfg->theta, cfg->lambda);
arizona_fll_dbg(fll, "FRATIO=0x%x(%d) OUTDIV=%d REFCLK_DIV=0x%x(%d)\n",
cfg->fratio, ratio, cfg->outdiv,
cfg->refdiv, 1 << cfg->refdiv);
arizona_fll_dbg(fll, "GAIN=0x%x(%d)\n", cfg->gain, 1 << cfg->gain);
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
if (sync) {
regmap_update_bits(arizona->regmap, base + 0x7,
ARIZONA_FLL1_GAIN_MASK,
cfg->gain << ARIZONA_FLL1_GAIN_SHIFT);
} else {
regmap_update_bits(arizona->regmap, base + 0x5,
ARIZONA_FLL1_OUTDIV_MASK,
cfg->outdiv << ARIZONA_FLL1_OUTDIV_SHIFT);
regmap_update_bits(arizona->regmap, base + 0x9,
ARIZONA_FLL1_GAIN_MASK,
cfg->gain << ARIZONA_FLL1_GAIN_SHIFT);
}
regmap_update_bits_async(arizona->regmap, base + 2,
ARIZONA_FLL1_CTRL_UPD | ARIZONA_FLL1_N_MASK,
ARIZONA_FLL1_CTRL_UPD | cfg->n);
}
static int arizona_is_enabled_fll(struct arizona_fll *fll)
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
static int arizona_enable_fll(struct arizona_fll *fll)
{
struct arizona *arizona = fll->arizona;
bool use_sync = false;
int already_enabled = arizona_is_enabled_fll(fll);
struct arizona_fll_cfg cfg;
int i;
unsigned int val;
if (already_enabled < 0)
return already_enabled;
if (already_enabled) {
regmap_update_bits_async(fll->arizona->regmap, fll->base + 0x9,
ARIZONA_FLL1_GAIN_MASK, 0);
regmap_update_bits(fll->arizona->regmap, fll->base + 1,
ARIZONA_FLL1_FREERUN, ARIZONA_FLL1_FREERUN);
udelay(32);
}
if (fll->ref_src >= 0 && fll->ref_freq &&
fll->ref_src != fll->sync_src) {
arizona_calc_fll(fll, &cfg, fll->ref_freq, false);
arizona_apply_fll(arizona, fll->base, &cfg, fll->ref_src,
false);
if (fll->sync_src >= 0) {
arizona_calc_fll(fll, &cfg, fll->sync_freq, true);
arizona_apply_fll(arizona, fll->base + 0x10, &cfg,
fll->sync_src, true);
use_sync = true;
}
} else if (fll->sync_src >= 0) {
arizona_calc_fll(fll, &cfg, fll->sync_freq, false);
arizona_apply_fll(arizona, fll->base, &cfg,
fll->sync_src, false);
regmap_update_bits_async(arizona->regmap, fll->base + 0x11,
ARIZONA_FLL1_SYNC_ENA, 0);
} else {
arizona_fll_err(fll, "No clocks provided\n");
return -EINVAL;
}
if (use_sync && fll->sync_freq > 100000)
regmap_update_bits_async(arizona->regmap, fll->base + 0x17,
ARIZONA_FLL1_SYNC_BW, 0);
else
regmap_update_bits_async(arizona->regmap, fll->base + 0x17,
ARIZONA_FLL1_SYNC_BW,
ARIZONA_FLL1_SYNC_BW);
if (!already_enabled)
pm_runtime_get(arizona->dev);
regmap_update_bits_async(arizona->regmap, fll->base + 1,
ARIZONA_FLL1_ENA, ARIZONA_FLL1_ENA);
if (use_sync)
regmap_update_bits_async(arizona->regmap, fll->base + 0x11,
ARIZONA_FLL1_SYNC_ENA,
ARIZONA_FLL1_SYNC_ENA);
if (already_enabled)
regmap_update_bits_async(arizona->regmap, fll->base + 1,
ARIZONA_FLL1_FREERUN, 0);
arizona_fll_dbg(fll, "Waiting for FLL lock...\n");
val = 0;
for (i = 0; i < 15; i++) {
if (i < 5)
usleep_range(200, 400);
else
msleep(20);
regmap_read(arizona->regmap,
ARIZONA_INTERRUPT_RAW_STATUS_5,
&val);
if (val & (ARIZONA_FLL1_CLOCK_OK_STS << (fll->id - 1)))
break;
}
if (i == 15)
arizona_fll_warn(fll, "Timed out waiting for lock\n");
else
arizona_fll_dbg(fll, "FLL locked (%d polls)\n", i);
return 0;
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
regmap_update_bits_async(arizona->regmap, fll->base + 1,
ARIZONA_FLL1_FREERUN, 0);
if (change)
pm_runtime_put_autosuspend(arizona->dev);
}
int arizona_set_fll_refclk(struct arizona_fll *fll, int source,
unsigned int Fref, unsigned int Fout)
{
int ret = 0;
if (fll->ref_src == source && fll->ref_freq == Fref)
return 0;
if (fll->fout && Fref > 0) {
ret = arizona_validate_fll(fll, Fref, fll->fout);
if (ret != 0)
return ret;
}
fll->ref_src = source;
fll->ref_freq = Fref;
if (fll->fout && Fref > 0) {
ret = arizona_enable_fll(fll);
}
return ret;
}
int arizona_set_fll(struct arizona_fll *fll, int source,
unsigned int Fref, unsigned int Fout)
{
int ret = 0;
if (fll->sync_src == source &&
fll->sync_freq == Fref && fll->fout == Fout)
return 0;
if (Fout) {
if (fll->ref_src >= 0) {
ret = arizona_validate_fll(fll, fll->ref_freq, Fout);
if (ret != 0)
return ret;
}
ret = arizona_validate_fll(fll, Fref, Fout);
if (ret != 0)
return ret;
}
fll->sync_src = source;
fll->sync_freq = Fref;
fll->fout = Fout;
if (Fout)
ret = arizona_enable_fll(fll);
else
arizona_disable_fll(fll);
return ret;
}
int arizona_init_fll(struct arizona *arizona, int id, int base, int lock_irq,
int ok_irq, struct arizona_fll *fll)
{
unsigned int val;
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
static bool arizona_eq_filter_unstable(bool mode, __be16 _a, __be16 _b)
{
s16 a = be16_to_cpu(_a);
s16 b = be16_to_cpu(_b);
if (!mode) {
return abs(a) >= 4096;
} else {
if (abs(b) >= 4096)
return true;
return (abs((a << 16) / (4096 - b)) >= 4096 << 4);
}
}
int arizona_eq_coeff_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct arizona *arizona = dev_get_drvdata(codec->dev->parent);
struct soc_bytes *params = (void *)kcontrol->private_value;
unsigned int val;
__be16 *data;
int len;
int ret;
len = params->num_regs * regmap_get_val_bytes(arizona->regmap);
data = kmemdup(ucontrol->value.bytes.data, len, GFP_KERNEL | GFP_DMA);
if (!data)
return -ENOMEM;
data[0] &= cpu_to_be16(ARIZONA_EQ1_B1_MODE);
if (arizona_eq_filter_unstable(!!data[0], data[1], data[2]) ||
arizona_eq_filter_unstable(true, data[4], data[5]) ||
arizona_eq_filter_unstable(true, data[8], data[9]) ||
arizona_eq_filter_unstable(true, data[12], data[13]) ||
arizona_eq_filter_unstable(false, data[16], data[17])) {
dev_err(arizona->dev, "Rejecting unstable EQ coefficients\n");
ret = -EINVAL;
goto out;
}
ret = regmap_read(arizona->regmap, params->base, &val);
if (ret != 0)
goto out;
val &= ~ARIZONA_EQ1_B1_MODE;
data[0] |= cpu_to_be16(val);
ret = regmap_raw_write(arizona->regmap, params->base, data, len);
out:
kfree(data);
return ret;
}
int arizona_lhpf_coeff_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct arizona *arizona = dev_get_drvdata(codec->dev->parent);
__be16 *data = (__be16 *)ucontrol->value.bytes.data;
s16 val = be16_to_cpu(*data);
if (abs(val) >= 4096) {
dev_err(arizona->dev, "Rejecting unstable LHPF coefficients\n");
return -EINVAL;
}
return snd_soc_bytes_put(kcontrol, ucontrol);
}
