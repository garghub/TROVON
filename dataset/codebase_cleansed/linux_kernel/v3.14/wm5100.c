static int wm5100_alloc_sr(struct snd_soc_codec *codec, int rate)
{
struct wm5100_priv *wm5100 = snd_soc_codec_get_drvdata(codec);
int sr_code, sr_free, i;
for (i = 0; i < ARRAY_SIZE(wm5100_sr_code); i++)
if (wm5100_sr_code[i] == rate)
break;
if (i == ARRAY_SIZE(wm5100_sr_code)) {
dev_err(codec->dev, "Unsupported sample rate: %dHz\n", rate);
return -EINVAL;
}
sr_code = i;
if ((wm5100->sysclk % rate) == 0) {
sr_free = -1;
for (i = 0; i < ARRAY_SIZE(wm5100_sr_regs); i++) {
if (!wm5100->sr_ref[i] && sr_free == -1) {
sr_free = i;
continue;
}
if ((snd_soc_read(codec, wm5100_sr_regs[i]) &
WM5100_SAMPLE_RATE_1_MASK) == sr_code)
break;
}
if (i < ARRAY_SIZE(wm5100_sr_regs)) {
wm5100->sr_ref[i]++;
dev_dbg(codec->dev, "SR %dHz, slot %d, ref %d\n",
rate, i, wm5100->sr_ref[i]);
return i;
}
if (sr_free == -1) {
dev_err(codec->dev, "All SR slots already in use\n");
return -EBUSY;
}
dev_dbg(codec->dev, "Allocating SR slot %d for %dHz\n",
sr_free, rate);
wm5100->sr_ref[sr_free]++;
snd_soc_update_bits(codec, wm5100_sr_regs[sr_free],
WM5100_SAMPLE_RATE_1_MASK,
sr_code);
return sr_free;
} else {
dev_err(codec->dev,
"SR %dHz incompatible with %dHz SYSCLK and %dHz ASYNCCLK\n",
rate, wm5100->sysclk, wm5100->asyncclk);
return -EINVAL;
}
}
static void wm5100_free_sr(struct snd_soc_codec *codec, int rate)
{
struct wm5100_priv *wm5100 = snd_soc_codec_get_drvdata(codec);
int i, sr_code;
for (i = 0; i < ARRAY_SIZE(wm5100_sr_code); i++)
if (wm5100_sr_code[i] == rate)
break;
if (i == ARRAY_SIZE(wm5100_sr_code)) {
dev_err(codec->dev, "Unsupported sample rate: %dHz\n", rate);
return;
}
sr_code = wm5100_sr_code[i];
for (i = 0; i < ARRAY_SIZE(wm5100_sr_regs); i++) {
if (!wm5100->sr_ref[i])
continue;
if ((snd_soc_read(codec, wm5100_sr_regs[i]) &
WM5100_SAMPLE_RATE_1_MASK) == sr_code)
break;
}
if (i < ARRAY_SIZE(wm5100_sr_regs)) {
wm5100->sr_ref[i]--;
dev_dbg(codec->dev, "Dereference SR %dHz, count now %d\n",
rate, wm5100->sr_ref[i]);
} else {
dev_warn(codec->dev, "Freeing unreferenced sample rate %dHz\n",
rate);
}
}
static int wm5100_reset(struct wm5100_priv *wm5100)
{
if (wm5100->pdata.reset) {
gpio_set_value_cansleep(wm5100->pdata.reset, 0);
gpio_set_value_cansleep(wm5100->pdata.reset, 1);
return 0;
} else {
return regmap_write(wm5100->regmap, WM5100_SOFTWARE_RESET, 0);
}
}
static void wm5100_seq_notifier(struct snd_soc_dapm_context *dapm,
enum snd_soc_dapm_type event, int subseq)
{
struct snd_soc_codec *codec = container_of(dapm,
struct snd_soc_codec, dapm);
struct wm5100_priv *wm5100 = snd_soc_codec_get_drvdata(codec);
u16 val, expect, i;
if (wm5100->out_ena[0]) {
expect = snd_soc_read(codec, WM5100_CHANNEL_ENABLES_1);
for (i = 0; i < 200; i++) {
val = snd_soc_read(codec, WM5100_OUTPUT_STATUS_1);
if (val == expect) {
wm5100->out_ena[0] = false;
break;
}
}
if (i == 200) {
dev_err(codec->dev, "Timeout waiting for OUTPUT1 %x\n",
expect);
}
}
if (wm5100->out_ena[1]) {
expect = snd_soc_read(codec, WM5100_OUTPUT_ENABLES_2);
for (i = 0; i < 200; i++) {
val = snd_soc_read(codec, WM5100_OUTPUT_STATUS_2);
if (val == expect) {
wm5100->out_ena[1] = false;
break;
}
}
if (i == 200) {
dev_err(codec->dev, "Timeout waiting for OUTPUT2 %x\n",
expect);
}
}
}
static int wm5100_out_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
struct wm5100_priv *wm5100 = snd_soc_codec_get_drvdata(w->codec);
switch (w->reg) {
case WM5100_CHANNEL_ENABLES_1:
wm5100->out_ena[0] = true;
break;
case WM5100_OUTPUT_ENABLES_2:
wm5100->out_ena[0] = true;
break;
default:
break;
}
return 0;
}
static void wm5100_log_status3(struct wm5100_priv *wm5100, int val)
{
if (val & WM5100_SPK_SHUTDOWN_WARN_EINT)
dev_crit(wm5100->dev, "Speaker shutdown warning\n");
if (val & WM5100_SPK_SHUTDOWN_EINT)
dev_crit(wm5100->dev, "Speaker shutdown\n");
if (val & WM5100_CLKGEN_ERR_EINT)
dev_crit(wm5100->dev, "SYSCLK underclocked\n");
if (val & WM5100_CLKGEN_ERR_ASYNC_EINT)
dev_crit(wm5100->dev, "ASYNCCLK underclocked\n");
}
static void wm5100_log_status4(struct wm5100_priv *wm5100, int val)
{
if (val & WM5100_AIF3_ERR_EINT)
dev_err(wm5100->dev, "AIF3 configuration error\n");
if (val & WM5100_AIF2_ERR_EINT)
dev_err(wm5100->dev, "AIF2 configuration error\n");
if (val & WM5100_AIF1_ERR_EINT)
dev_err(wm5100->dev, "AIF1 configuration error\n");
if (val & WM5100_CTRLIF_ERR_EINT)
dev_err(wm5100->dev, "Control interface error\n");
if (val & WM5100_ISRC2_UNDERCLOCKED_EINT)
dev_err(wm5100->dev, "ISRC2 underclocked\n");
if (val & WM5100_ISRC1_UNDERCLOCKED_EINT)
dev_err(wm5100->dev, "ISRC1 underclocked\n");
if (val & WM5100_FX_UNDERCLOCKED_EINT)
dev_err(wm5100->dev, "FX underclocked\n");
if (val & WM5100_AIF3_UNDERCLOCKED_EINT)
dev_err(wm5100->dev, "AIF3 underclocked\n");
if (val & WM5100_AIF2_UNDERCLOCKED_EINT)
dev_err(wm5100->dev, "AIF2 underclocked\n");
if (val & WM5100_AIF1_UNDERCLOCKED_EINT)
dev_err(wm5100->dev, "AIF1 underclocked\n");
if (val & WM5100_ASRC_UNDERCLOCKED_EINT)
dev_err(wm5100->dev, "ASRC underclocked\n");
if (val & WM5100_DAC_UNDERCLOCKED_EINT)
dev_err(wm5100->dev, "DAC underclocked\n");
if (val & WM5100_ADC_UNDERCLOCKED_EINT)
dev_err(wm5100->dev, "ADC underclocked\n");
if (val & WM5100_MIXER_UNDERCLOCKED_EINT)
dev_err(wm5100->dev, "Mixer underclocked\n");
}
static int wm5100_post_ev(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
struct snd_soc_codec *codec = w->codec;
struct wm5100_priv *wm5100 = snd_soc_codec_get_drvdata(codec);
int ret;
ret = snd_soc_read(codec, WM5100_INTERRUPT_RAW_STATUS_3);
ret &= WM5100_SPK_SHUTDOWN_WARN_STS |
WM5100_SPK_SHUTDOWN_STS | WM5100_CLKGEN_ERR_STS |
WM5100_CLKGEN_ERR_ASYNC_STS;
wm5100_log_status3(wm5100, ret);
ret = snd_soc_read(codec, WM5100_INTERRUPT_RAW_STATUS_4);
wm5100_log_status4(wm5100, ret);
return 0;
}
static int wm5100_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
int lrclk, bclk, mask, base;
base = dai->driver->base;
lrclk = 0;
bclk = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
mask = 0;
break;
case SND_SOC_DAIFMT_I2S:
mask = 2;
break;
default:
dev_err(codec->dev, "Unsupported DAI format %d\n",
fmt & SND_SOC_DAIFMT_FORMAT_MASK);
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
case SND_SOC_DAIFMT_CBS_CFM:
lrclk |= WM5100_AIF1TX_LRCLK_MSTR;
break;
case SND_SOC_DAIFMT_CBM_CFS:
bclk |= WM5100_AIF1_BCLK_MSTR;
break;
case SND_SOC_DAIFMT_CBM_CFM:
lrclk |= WM5100_AIF1TX_LRCLK_MSTR;
bclk |= WM5100_AIF1_BCLK_MSTR;
break;
default:
dev_err(codec->dev, "Unsupported master mode %d\n",
fmt & SND_SOC_DAIFMT_MASTER_MASK);
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
bclk |= WM5100_AIF1_BCLK_INV;
lrclk |= WM5100_AIF1TX_LRCLK_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
bclk |= WM5100_AIF1_BCLK_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
lrclk |= WM5100_AIF1TX_LRCLK_INV;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, base + 1, WM5100_AIF1_BCLK_MSTR |
WM5100_AIF1_BCLK_INV, bclk);
snd_soc_update_bits(codec, base + 2, WM5100_AIF1TX_LRCLK_MSTR |
WM5100_AIF1TX_LRCLK_INV, lrclk);
snd_soc_update_bits(codec, base + 3, WM5100_AIF1TX_LRCLK_MSTR |
WM5100_AIF1TX_LRCLK_INV, lrclk);
snd_soc_update_bits(codec, base + 5, WM5100_AIF1_FMT_MASK, mask);
return 0;
}
static int wm5100_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm5100_priv *wm5100 = snd_soc_codec_get_drvdata(codec);
bool async = wm5100->aif_async[dai->id];
int i, base, bclk, aif_rate, lrclk, wl, fl, sr;
int *bclk_rates;
base = dai->driver->base;
wl = snd_pcm_format_width(params_format(params));
if (wl < 0)
return wl;
fl = snd_soc_params_to_frame_size(params);
if (fl < 0)
return fl;
dev_dbg(codec->dev, "Word length %d bits, frame length %d bits\n",
wl, fl);
bclk = snd_soc_params_to_bclk(params);
if (bclk < 0)
return bclk;
if (!async) {
aif_rate = wm5100->sysclk;
sr = wm5100_alloc_sr(codec, params_rate(params));
if (sr < 0)
return sr;
} else {
aif_rate = wm5100->asyncclk;
sr = 3;
for (i = 0; i < ARRAY_SIZE(wm5100_sr_code); i++)
if (params_rate(params) == wm5100_sr_code[i])
break;
if (i == ARRAY_SIZE(wm5100_sr_code)) {
dev_err(codec->dev, "Invalid rate %dHzn",
params_rate(params));
return -EINVAL;
}
snd_soc_update_bits(codec, WM5100_CLOCKING_8,
WM5100_ASYNC_SAMPLE_RATE_MASK, i);
}
if (!aif_rate) {
dev_err(codec->dev, "%s has no rate set\n",
async ? "ASYNCCLK" : "SYSCLK");
return -EINVAL;
}
dev_dbg(codec->dev, "Target BCLK is %dHz, using %dHz %s\n",
bclk, aif_rate, async ? "ASYNCCLK" : "SYSCLK");
if (aif_rate % 4000)
bclk_rates = wm5100_bclk_rates_cd;
else
bclk_rates = wm5100_bclk_rates_dat;
for (i = 0; i < WM5100_NUM_BCLK_RATES; i++)
if (bclk_rates[i] >= bclk && (bclk_rates[i] % bclk == 0))
break;
if (i == WM5100_NUM_BCLK_RATES) {
dev_err(codec->dev,
"No valid BCLK for %dHz found from %dHz %s\n",
bclk, aif_rate, async ? "ASYNCCLK" : "SYSCLK");
return -EINVAL;
}
bclk = i;
dev_dbg(codec->dev, "Setting %dHz BCLK\n", bclk_rates[bclk]);
snd_soc_update_bits(codec, base + 1, WM5100_AIF1_BCLK_FREQ_MASK, bclk);
lrclk = bclk_rates[bclk] / params_rate(params);
dev_dbg(codec->dev, "Setting %dHz LRCLK\n", bclk_rates[bclk] / lrclk);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK ||
wm5100->aif_symmetric[dai->id])
snd_soc_update_bits(codec, base + 7,
WM5100_AIF1RX_BCPF_MASK, lrclk);
else
snd_soc_update_bits(codec, base + 6,
WM5100_AIF1TX_BCPF_MASK, lrclk);
i = (wl << WM5100_AIF1TX_WL_SHIFT) | fl;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
snd_soc_update_bits(codec, base + 9,
WM5100_AIF1RX_WL_MASK |
WM5100_AIF1RX_SLOT_LEN_MASK, i);
else
snd_soc_update_bits(codec, base + 8,
WM5100_AIF1TX_WL_MASK |
WM5100_AIF1TX_SLOT_LEN_MASK, i);
snd_soc_update_bits(codec, base + 4, WM5100_AIF1_RATE_MASK, sr);
return 0;
}
static int wm5100_set_sysclk(struct snd_soc_codec *codec, int clk_id,
int source, unsigned int freq, int dir)
{
struct wm5100_priv *wm5100 = snd_soc_codec_get_drvdata(codec);
int *rate_store;
int fval, audio_rate, ret, reg;
switch (clk_id) {
case WM5100_CLK_SYSCLK:
reg = WM5100_CLOCKING_3;
rate_store = &wm5100->sysclk;
break;
case WM5100_CLK_ASYNCCLK:
reg = WM5100_CLOCKING_7;
rate_store = &wm5100->asyncclk;
break;
case WM5100_CLK_32KHZ:
switch (source) {
case WM5100_CLKSRC_MCLK1:
case WM5100_CLKSRC_MCLK2:
case WM5100_CLKSRC_SYSCLK:
snd_soc_update_bits(codec, WM5100_CLOCKING_1,
WM5100_CLK_32K_SRC_MASK,
source);
break;
default:
return -EINVAL;
}
return 0;
case WM5100_CLK_AIF1:
case WM5100_CLK_AIF2:
case WM5100_CLK_AIF3:
switch (source) {
case WM5100_CLKSRC_SYSCLK:
wm5100->aif_async[clk_id - 1] = false;
break;
case WM5100_CLKSRC_ASYNCCLK:
wm5100->aif_async[clk_id - 1] = true;
break;
default:
dev_err(codec->dev, "Invalid source %d\n", source);
return -EINVAL;
}
return 0;
case WM5100_CLK_OPCLK:
switch (freq) {
case 5644800:
case 6144000:
snd_soc_update_bits(codec, WM5100_MISC_GPIO_1,
WM5100_OPCLK_SEL_MASK, 0);
break;
case 11289600:
case 12288000:
snd_soc_update_bits(codec, WM5100_MISC_GPIO_1,
WM5100_OPCLK_SEL_MASK, 0);
break;
case 22579200:
case 24576000:
snd_soc_update_bits(codec, WM5100_MISC_GPIO_1,
WM5100_OPCLK_SEL_MASK, 0);
break;
default:
dev_err(codec->dev, "Unsupported OPCLK %dHz\n",
freq);
return -EINVAL;
}
return 0;
default:
dev_err(codec->dev, "Unknown clock %d\n", clk_id);
return -EINVAL;
}
switch (source) {
case WM5100_CLKSRC_SYSCLK:
case WM5100_CLKSRC_ASYNCCLK:
dev_err(codec->dev, "Invalid source %d\n", source);
return -EINVAL;
}
switch (freq) {
case 5644800:
case 6144000:
fval = 0;
break;
case 11289600:
case 12288000:
fval = 1;
break;
case 22579200:
case 24576000:
fval = 2;
break;
default:
dev_err(codec->dev, "Invalid clock rate: %d\n", freq);
return -EINVAL;
}
switch (freq) {
case 5644800:
case 11289600:
case 22579200:
audio_rate = 44100;
break;
case 6144000:
case 12288000:
case 24576000:
audio_rate = 48000;
break;
default:
BUG();
audio_rate = 0;
break;
}
snd_soc_update_bits(codec, reg, WM5100_SYSCLK_FREQ_MASK |
WM5100_SYSCLK_SRC_MASK,
fval << WM5100_SYSCLK_FREQ_SHIFT | source);
if (clk_id == WM5100_CLK_SYSCLK) {
dev_dbg(codec->dev, "Setting primary audio rate to %dHz",
audio_rate);
if (0 && *rate_store)
wm5100_free_sr(codec, audio_rate);
ret = wm5100_alloc_sr(codec, audio_rate);
if (ret != 0)
dev_warn(codec->dev, "Primary audio slot is %d\n",
ret);
}
*rate_store = freq;
return 0;
}
static int fll_factors(struct _fll_div *fll_div, unsigned int Fref,
unsigned int Fout)
{
unsigned int target;
unsigned int div;
unsigned int fratio, gcd_fll;
int i;
div = 1;
fll_div->fll_refclk_div = 0;
while ((Fref / div) > 13500000) {
div *= 2;
fll_div->fll_refclk_div++;
if (div > 8) {
pr_err("Can't scale %dMHz input down to <=13.5MHz\n",
Fref);
return -EINVAL;
}
}
pr_debug("FLL Fref=%u Fout=%u\n", Fref, Fout);
Fref /= div;
div = 2;
while (Fout * div < 90000000) {
div++;
if (div > 64) {
pr_err("Unable to find FLL_OUTDIV for Fout=%uHz\n",
Fout);
return -EINVAL;
}
}
target = Fout * div;
fll_div->fll_outdiv = div - 1;
pr_debug("FLL Fvco=%dHz\n", target);
for (i = 0; i < ARRAY_SIZE(fll_fratios); i++) {
if (fll_fratios[i].min <= Fref && Fref <= fll_fratios[i].max) {
fll_div->fll_fratio = fll_fratios[i].fll_fratio;
fratio = fll_fratios[i].ratio;
break;
}
}
if (i == ARRAY_SIZE(fll_fratios)) {
pr_err("Unable to find FLL_FRATIO for Fref=%uHz\n", Fref);
return -EINVAL;
}
fll_div->n = target / (fratio * Fref);
if (target % Fref == 0) {
fll_div->theta = 0;
fll_div->lambda = 0;
} else {
gcd_fll = gcd(target, fratio * Fref);
fll_div->theta = (target - (fll_div->n * fratio * Fref))
/ gcd_fll;
fll_div->lambda = (fratio * Fref) / gcd_fll;
}
pr_debug("FLL N=%x THETA=%x LAMBDA=%x\n",
fll_div->n, fll_div->theta, fll_div->lambda);
pr_debug("FLL_FRATIO=%x(%d) FLL_OUTDIV=%x FLL_REFCLK_DIV=%x\n",
fll_div->fll_fratio, fratio, fll_div->fll_outdiv,
fll_div->fll_refclk_div);
return 0;
}
static int wm5100_set_fll(struct snd_soc_codec *codec, int fll_id, int source,
unsigned int Fref, unsigned int Fout)
{
struct i2c_client *i2c = to_i2c_client(codec->dev);
struct wm5100_priv *wm5100 = snd_soc_codec_get_drvdata(codec);
struct _fll_div factors;
struct wm5100_fll *fll;
int ret, base, lock, i, timeout;
switch (fll_id) {
case WM5100_FLL1:
fll = &wm5100->fll[0];
base = WM5100_FLL1_CONTROL_1 - 1;
lock = WM5100_FLL1_LOCK_STS;
break;
case WM5100_FLL2:
fll = &wm5100->fll[1];
base = WM5100_FLL2_CONTROL_2 - 1;
lock = WM5100_FLL2_LOCK_STS;
break;
default:
dev_err(codec->dev, "Unknown FLL %d\n",fll_id);
return -EINVAL;
}
if (!Fout) {
dev_dbg(codec->dev, "FLL%d disabled", fll_id);
if (fll->fout)
pm_runtime_put(codec->dev);
fll->fout = 0;
snd_soc_update_bits(codec, base + 1, WM5100_FLL1_ENA, 0);
return 0;
}
switch (source) {
case WM5100_FLL_SRC_MCLK1:
case WM5100_FLL_SRC_MCLK2:
case WM5100_FLL_SRC_FLL1:
case WM5100_FLL_SRC_FLL2:
case WM5100_FLL_SRC_AIF1BCLK:
case WM5100_FLL_SRC_AIF2BCLK:
case WM5100_FLL_SRC_AIF3BCLK:
break;
default:
dev_err(codec->dev, "Invalid FLL source %d\n", source);
return -EINVAL;
}
ret = fll_factors(&factors, Fref, Fout);
if (ret < 0)
return ret;
snd_soc_update_bits(codec, base + 1, WM5100_FLL1_ENA, 0);
snd_soc_update_bits(codec, base + 2,
WM5100_FLL1_OUTDIV_MASK | WM5100_FLL1_FRATIO_MASK,
(factors.fll_outdiv << WM5100_FLL1_OUTDIV_SHIFT) |
factors.fll_fratio);
snd_soc_update_bits(codec, base + 3, WM5100_FLL1_THETA_MASK,
factors.theta);
snd_soc_update_bits(codec, base + 5, WM5100_FLL1_N_MASK, factors.n);
snd_soc_update_bits(codec, base + 6,
WM5100_FLL1_REFCLK_DIV_MASK |
WM5100_FLL1_REFCLK_SRC_MASK,
(factors.fll_refclk_div
<< WM5100_FLL1_REFCLK_DIV_SHIFT) | source);
snd_soc_update_bits(codec, base + 7, WM5100_FLL1_LAMBDA_MASK,
factors.lambda);
try_wait_for_completion(&fll->lock);
pm_runtime_get_sync(codec->dev);
snd_soc_update_bits(codec, base + 1, WM5100_FLL1_ENA, WM5100_FLL1_ENA);
if (i2c->irq)
timeout = 2;
else
timeout = 50;
snd_soc_update_bits(codec, WM5100_CLOCKING_3, WM5100_SYSCLK_ENA,
WM5100_SYSCLK_ENA);
for (i = 0; i < timeout; i++) {
if (i2c->irq) {
ret = wait_for_completion_timeout(&fll->lock,
msecs_to_jiffies(25));
if (ret > 0)
break;
} else {
msleep(1);
}
ret = snd_soc_read(codec,
WM5100_INTERRUPT_RAW_STATUS_3);
if (ret < 0) {
dev_err(codec->dev,
"Failed to read FLL status: %d\n",
ret);
continue;
}
if (ret & lock)
break;
}
if (i == timeout) {
dev_err(codec->dev, "FLL%d lock timed out\n", fll_id);
pm_runtime_put(codec->dev);
return -ETIMEDOUT;
}
fll->src = source;
fll->fref = Fref;
fll->fout = Fout;
dev_dbg(codec->dev, "FLL%d running %dHz->%dHz\n", fll_id,
Fref, Fout);
return 0;
}
static void wm5100_set_detect_mode(struct wm5100_priv *wm5100, int the_mode)
{
struct wm5100_jack_mode *mode = &wm5100->pdata.jack_modes[the_mode];
if (WARN_ON(the_mode >= ARRAY_SIZE(wm5100->pdata.jack_modes)))
return;
gpio_set_value_cansleep(wm5100->pdata.hp_pol, mode->hp_pol);
regmap_update_bits(wm5100->regmap, WM5100_ACCESSORY_DETECT_MODE_1,
WM5100_ACCDET_BIAS_SRC_MASK |
WM5100_ACCDET_SRC,
(mode->bias << WM5100_ACCDET_BIAS_SRC_SHIFT) |
mode->micd_src << WM5100_ACCDET_SRC_SHIFT);
regmap_update_bits(wm5100->regmap, WM5100_MISC_CONTROL,
WM5100_HPCOM_SRC,
mode->micd_src << WM5100_HPCOM_SRC_SHIFT);
wm5100->jack_mode = the_mode;
dev_dbg(wm5100->dev, "Set microphone polarity to %d\n",
wm5100->jack_mode);
}
static void wm5100_report_headphone(struct wm5100_priv *wm5100)
{
dev_dbg(wm5100->dev, "Headphone detected\n");
wm5100->jack_detecting = false;
snd_soc_jack_report(wm5100->jack, SND_JACK_HEADPHONE,
SND_JACK_HEADPHONE);
regmap_update_bits(wm5100->regmap, WM5100_MIC_DETECT_1,
WM5100_ACCDET_RATE_MASK,
7 << WM5100_ACCDET_RATE_SHIFT);
}
static void wm5100_micd_irq(struct wm5100_priv *wm5100)
{
unsigned int val;
int ret;
ret = regmap_read(wm5100->regmap, WM5100_MIC_DETECT_3, &val);
if (ret != 0) {
dev_err(wm5100->dev, "Failed to read micropone status: %d\n",
ret);
return;
}
dev_dbg(wm5100->dev, "Microphone event: %x\n", val);
if (!(val & WM5100_ACCDET_VALID)) {
dev_warn(wm5100->dev, "Microphone detection state invalid\n");
return;
}
if (!(val & WM5100_ACCDET_STS)) {
dev_dbg(wm5100->dev, "Jack removal detected\n");
wm5100->jack_mic = false;
wm5100->jack_detecting = true;
wm5100->jack_flips = 0;
snd_soc_jack_report(wm5100->jack, 0,
SND_JACK_LINEOUT | SND_JACK_HEADSET |
SND_JACK_BTN_0);
regmap_update_bits(wm5100->regmap, WM5100_MIC_DETECT_1,
WM5100_ACCDET_RATE_MASK,
WM5100_ACCDET_RATE_MASK);
return;
}
if (val & 0x400) {
if (wm5100->jack_detecting) {
dev_dbg(wm5100->dev, "Microphone detected\n");
wm5100->jack_mic = true;
wm5100->jack_detecting = false;
snd_soc_jack_report(wm5100->jack,
SND_JACK_HEADSET,
SND_JACK_HEADSET | SND_JACK_BTN_0);
regmap_update_bits(wm5100->regmap, WM5100_MIC_DETECT_1,
WM5100_ACCDET_RATE_MASK,
5 << WM5100_ACCDET_RATE_SHIFT);
} else {
dev_dbg(wm5100->dev, "Mic button up\n");
snd_soc_jack_report(wm5100->jack, 0, SND_JACK_BTN_0);
}
return;
}
if (wm5100->jack_detecting && (val & 0x3f8)) {
wm5100->jack_flips++;
if (wm5100->jack_flips > 1)
wm5100_report_headphone(wm5100);
else
wm5100_set_detect_mode(wm5100, !wm5100->jack_mode);
return;
}
if (val & 0x3fc) {
if (wm5100->jack_mic) {
dev_dbg(wm5100->dev, "Mic button detected\n");
snd_soc_jack_report(wm5100->jack, SND_JACK_BTN_0,
SND_JACK_BTN_0);
} else if (wm5100->jack_detecting) {
wm5100_report_headphone(wm5100);
}
}
}
int wm5100_detect(struct snd_soc_codec *codec, struct snd_soc_jack *jack)
{
struct wm5100_priv *wm5100 = snd_soc_codec_get_drvdata(codec);
if (jack) {
wm5100->jack = jack;
wm5100->jack_detecting = true;
wm5100->jack_flips = 0;
wm5100_set_detect_mode(wm5100, 0);
snd_soc_update_bits(codec, WM5100_MIC_DETECT_1,
WM5100_ACCDET_BIAS_STARTTIME_MASK |
WM5100_ACCDET_RATE_MASK,
(7 << WM5100_ACCDET_BIAS_STARTTIME_SHIFT) |
WM5100_ACCDET_RATE_MASK);
snd_soc_dapm_force_enable_pin(&codec->dapm, "CP2");
snd_soc_dapm_force_enable_pin(&codec->dapm, "SYSCLK");
snd_soc_dapm_sync(&codec->dapm);
snd_soc_update_bits(codec, WM5100_MIC_DETECT_1,
WM5100_ACCDET_ENA, WM5100_ACCDET_ENA);
snd_soc_update_bits(codec, WM5100_INTERRUPT_STATUS_3_MASK,
WM5100_IM_ACCDET_EINT, 0);
} else {
snd_soc_update_bits(codec, WM5100_INTERRUPT_STATUS_3_MASK,
WM5100_IM_HPDET_EINT |
WM5100_IM_ACCDET_EINT,
WM5100_IM_HPDET_EINT |
WM5100_IM_ACCDET_EINT);
snd_soc_update_bits(codec, WM5100_MIC_DETECT_1,
WM5100_ACCDET_ENA, 0);
wm5100->jack = NULL;
}
return 0;
}
static irqreturn_t wm5100_irq(int irq, void *data)
{
struct wm5100_priv *wm5100 = data;
irqreturn_t status = IRQ_NONE;
unsigned int irq_val, mask_val;
int ret;
ret = regmap_read(wm5100->regmap, WM5100_INTERRUPT_STATUS_3, &irq_val);
if (ret < 0) {
dev_err(wm5100->dev, "Failed to read IRQ status 3: %d\n",
ret);
irq_val = 0;
}
ret = regmap_read(wm5100->regmap, WM5100_INTERRUPT_STATUS_3_MASK,
&mask_val);
if (ret < 0) {
dev_err(wm5100->dev, "Failed to read IRQ mask 3: %d\n",
ret);
mask_val = 0xffff;
}
irq_val &= ~mask_val;
regmap_write(wm5100->regmap, WM5100_INTERRUPT_STATUS_3, irq_val);
if (irq_val)
status = IRQ_HANDLED;
wm5100_log_status3(wm5100, irq_val);
if (irq_val & WM5100_FLL1_LOCK_EINT) {
dev_dbg(wm5100->dev, "FLL1 locked\n");
complete(&wm5100->fll[0].lock);
}
if (irq_val & WM5100_FLL2_LOCK_EINT) {
dev_dbg(wm5100->dev, "FLL2 locked\n");
complete(&wm5100->fll[1].lock);
}
if (irq_val & WM5100_ACCDET_EINT)
wm5100_micd_irq(wm5100);
ret = regmap_read(wm5100->regmap, WM5100_INTERRUPT_STATUS_4, &irq_val);
if (ret < 0) {
dev_err(wm5100->dev, "Failed to read IRQ status 4: %d\n",
ret);
irq_val = 0;
}
ret = regmap_read(wm5100->regmap, WM5100_INTERRUPT_STATUS_4_MASK,
&mask_val);
if (ret < 0) {
dev_err(wm5100->dev, "Failed to read IRQ mask 4: %d\n",
ret);
mask_val = 0xffff;
}
irq_val &= ~mask_val;
if (irq_val)
status = IRQ_HANDLED;
regmap_write(wm5100->regmap, WM5100_INTERRUPT_STATUS_4, irq_val);
wm5100_log_status4(wm5100, irq_val);
return status;
}
static irqreturn_t wm5100_edge_irq(int irq, void *data)
{
irqreturn_t ret = IRQ_NONE;
irqreturn_t val;
do {
val = wm5100_irq(irq, data);
if (val != IRQ_NONE)
ret = val;
} while (val != IRQ_NONE);
return ret;
}
static inline struct wm5100_priv *gpio_to_wm5100(struct gpio_chip *chip)
{
return container_of(chip, struct wm5100_priv, gpio_chip);
}
static void wm5100_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct wm5100_priv *wm5100 = gpio_to_wm5100(chip);
regmap_update_bits(wm5100->regmap, WM5100_GPIO_CTRL_1 + offset,
WM5100_GP1_LVL, !!value << WM5100_GP1_LVL_SHIFT);
}
static int wm5100_gpio_direction_out(struct gpio_chip *chip,
unsigned offset, int value)
{
struct wm5100_priv *wm5100 = gpio_to_wm5100(chip);
int val, ret;
val = (1 << WM5100_GP1_FN_SHIFT) | (!!value << WM5100_GP1_LVL_SHIFT);
ret = regmap_update_bits(wm5100->regmap, WM5100_GPIO_CTRL_1 + offset,
WM5100_GP1_FN_MASK | WM5100_GP1_DIR |
WM5100_GP1_LVL, val);
if (ret < 0)
return ret;
else
return 0;
}
static int wm5100_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct wm5100_priv *wm5100 = gpio_to_wm5100(chip);
unsigned int reg;
int ret;
ret = regmap_read(wm5100->regmap, WM5100_GPIO_CTRL_1 + offset, &reg);
if (ret < 0)
return ret;
return (reg & WM5100_GP1_LVL) != 0;
}
static int wm5100_gpio_direction_in(struct gpio_chip *chip, unsigned offset)
{
struct wm5100_priv *wm5100 = gpio_to_wm5100(chip);
return regmap_update_bits(wm5100->regmap, WM5100_GPIO_CTRL_1 + offset,
WM5100_GP1_FN_MASK | WM5100_GP1_DIR,
(1 << WM5100_GP1_FN_SHIFT) |
(1 << WM5100_GP1_DIR_SHIFT));
}
static void wm5100_init_gpio(struct i2c_client *i2c)
{
struct wm5100_priv *wm5100 = i2c_get_clientdata(i2c);
int ret;
wm5100->gpio_chip = wm5100_template_chip;
wm5100->gpio_chip.ngpio = 6;
wm5100->gpio_chip.dev = &i2c->dev;
if (wm5100->pdata.gpio_base)
wm5100->gpio_chip.base = wm5100->pdata.gpio_base;
else
wm5100->gpio_chip.base = -1;
ret = gpiochip_add(&wm5100->gpio_chip);
if (ret != 0)
dev_err(&i2c->dev, "Failed to add GPIOs: %d\n", ret);
}
static void wm5100_free_gpio(struct i2c_client *i2c)
{
struct wm5100_priv *wm5100 = i2c_get_clientdata(i2c);
int ret;
ret = gpiochip_remove(&wm5100->gpio_chip);
if (ret != 0)
dev_err(&i2c->dev, "Failed to remove GPIOs: %d\n", ret);
}
static void wm5100_init_gpio(struct i2c_client *i2c)
{
}
static void wm5100_free_gpio(struct i2c_client *i2c)
{
}
static int wm5100_probe(struct snd_soc_codec *codec)
{
struct i2c_client *i2c = to_i2c_client(codec->dev);
struct wm5100_priv *wm5100 = snd_soc_codec_get_drvdata(codec);
int ret, i;
wm5100->codec = codec;
codec->control_data = wm5100->regmap;
ret = snd_soc_codec_set_cache_io(codec, 16, 16, SND_SOC_REGMAP);
if (ret != 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
for (i = 0; i < ARRAY_SIZE(wm5100_dig_vu); i++)
snd_soc_update_bits(codec, wm5100_dig_vu[i], WM5100_OUT_VU,
WM5100_OUT_VU);
snd_soc_write(codec, WM5100_IRQ_DEBOUNCE_1, 0);
snd_soc_write(codec, WM5100_IRQ_DEBOUNCE_2, 0);
if (i2c->irq)
snd_soc_dapm_new_controls(&codec->dapm,
wm5100_dapm_widgets_noirq,
ARRAY_SIZE(wm5100_dapm_widgets_noirq));
if (wm5100->pdata.hp_pol) {
ret = gpio_request_one(wm5100->pdata.hp_pol,
GPIOF_OUT_INIT_HIGH, "WM5100 HP_POL");
if (ret < 0) {
dev_err(&i2c->dev, "Failed to request HP_POL %d: %d\n",
wm5100->pdata.hp_pol, ret);
goto err_gpio;
}
}
return 0;
err_gpio:
return ret;
}
static int wm5100_remove(struct snd_soc_codec *codec)
{
struct wm5100_priv *wm5100 = snd_soc_codec_get_drvdata(codec);
if (wm5100->pdata.hp_pol) {
gpio_free(wm5100->pdata.hp_pol);
}
return 0;
}
static int wm5100_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm5100_pdata *pdata = dev_get_platdata(&i2c->dev);
struct wm5100_priv *wm5100;
unsigned int reg;
int ret, i, irq_flags;
wm5100 = devm_kzalloc(&i2c->dev, sizeof(struct wm5100_priv),
GFP_KERNEL);
if (wm5100 == NULL)
return -ENOMEM;
wm5100->dev = &i2c->dev;
wm5100->regmap = devm_regmap_init_i2c(i2c, &wm5100_regmap);
if (IS_ERR(wm5100->regmap)) {
ret = PTR_ERR(wm5100->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
goto err;
}
for (i = 0; i < ARRAY_SIZE(wm5100->fll); i++)
init_completion(&wm5100->fll[i].lock);
if (pdata)
wm5100->pdata = *pdata;
i2c_set_clientdata(i2c, wm5100);
for (i = 0; i < ARRAY_SIZE(wm5100->core_supplies); i++)
wm5100->core_supplies[i].supply = wm5100_core_supply_names[i];
ret = devm_regulator_bulk_get(&i2c->dev,
ARRAY_SIZE(wm5100->core_supplies),
wm5100->core_supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to request core supplies: %d\n",
ret);
goto err;
}
ret = regulator_bulk_enable(ARRAY_SIZE(wm5100->core_supplies),
wm5100->core_supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to enable core supplies: %d\n",
ret);
goto err;
}
if (wm5100->pdata.ldo_ena) {
ret = gpio_request_one(wm5100->pdata.ldo_ena,
GPIOF_OUT_INIT_HIGH, "WM5100 LDOENA");
if (ret < 0) {
dev_err(&i2c->dev, "Failed to request LDOENA %d: %d\n",
wm5100->pdata.ldo_ena, ret);
goto err_enable;
}
msleep(2);
}
if (wm5100->pdata.reset) {
ret = gpio_request_one(wm5100->pdata.reset,
GPIOF_OUT_INIT_HIGH, "WM5100 /RESET");
if (ret < 0) {
dev_err(&i2c->dev, "Failed to request /RESET %d: %d\n",
wm5100->pdata.reset, ret);
goto err_ldo;
}
}
ret = regmap_read(wm5100->regmap, WM5100_SOFTWARE_RESET, &reg);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to read ID register: %d\n", ret);
goto err_reset;
}
switch (reg) {
case 0x8997:
case 0x5100:
break;
default:
dev_err(&i2c->dev, "Device is not a WM5100, ID is %x\n", reg);
ret = -EINVAL;
goto err_reset;
}
ret = regmap_read(wm5100->regmap, WM5100_DEVICE_REVISION, &reg);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to read revision register\n");
goto err_reset;
}
wm5100->rev = reg & WM5100_DEVICE_REVISION_MASK;
dev_info(&i2c->dev, "revision %c\n", wm5100->rev + 'A');
ret = wm5100_reset(wm5100);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to issue reset\n");
goto err_reset;
}
switch (wm5100->rev) {
case 0:
ret = regmap_register_patch(wm5100->regmap,
wm5100_reva_patches,
ARRAY_SIZE(wm5100_reva_patches));
if (ret != 0) {
dev_err(&i2c->dev, "Failed to register patches: %d\n",
ret);
goto err_reset;
}
break;
default:
break;
}
wm5100_init_gpio(i2c);
for (i = 0; i < ARRAY_SIZE(wm5100->pdata.gpio_defaults); i++) {
if (!wm5100->pdata.gpio_defaults[i])
continue;
regmap_write(wm5100->regmap, WM5100_GPIO_CTRL_1 + i,
wm5100->pdata.gpio_defaults[i]);
}
for (i = 0; i < ARRAY_SIZE(wm5100->pdata.in_mode); i++) {
regmap_update_bits(wm5100->regmap, wm5100_mic_ctrl_reg[i],
WM5100_IN1_MODE_MASK |
WM5100_IN1_DMIC_SUP_MASK,
(wm5100->pdata.in_mode[i] <<
WM5100_IN1_MODE_SHIFT) |
(wm5100->pdata.dmic_sup[i] <<
WM5100_IN1_DMIC_SUP_SHIFT));
}
if (i2c->irq) {
if (wm5100->pdata.irq_flags)
irq_flags = wm5100->pdata.irq_flags;
else
irq_flags = IRQF_TRIGGER_LOW;
irq_flags |= IRQF_ONESHOT;
if (irq_flags & (IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING))
ret = request_threaded_irq(i2c->irq, NULL,
wm5100_edge_irq, irq_flags,
"wm5100", wm5100);
else
ret = request_threaded_irq(i2c->irq, NULL, wm5100_irq,
irq_flags, "wm5100",
wm5100);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to request IRQ %d: %d\n",
i2c->irq, ret);
} else {
regmap_update_bits(wm5100->regmap,
WM5100_INTERRUPT_STATUS_3_MASK,
WM5100_IM_SPK_SHUTDOWN_WARN_EINT |
WM5100_IM_SPK_SHUTDOWN_EINT |
WM5100_IM_ASRC2_LOCK_EINT |
WM5100_IM_ASRC1_LOCK_EINT |
WM5100_IM_FLL2_LOCK_EINT |
WM5100_IM_FLL1_LOCK_EINT |
WM5100_CLKGEN_ERR_EINT |
WM5100_CLKGEN_ERR_ASYNC_EINT, 0);
regmap_update_bits(wm5100->regmap,
WM5100_INTERRUPT_STATUS_4_MASK,
WM5100_AIF3_ERR_EINT |
WM5100_AIF2_ERR_EINT |
WM5100_AIF1_ERR_EINT |
WM5100_CTRLIF_ERR_EINT |
WM5100_ISRC2_UNDERCLOCKED_EINT |
WM5100_ISRC1_UNDERCLOCKED_EINT |
WM5100_FX_UNDERCLOCKED_EINT |
WM5100_AIF3_UNDERCLOCKED_EINT |
WM5100_AIF2_UNDERCLOCKED_EINT |
WM5100_AIF1_UNDERCLOCKED_EINT |
WM5100_ASRC_UNDERCLOCKED_EINT |
WM5100_DAC_UNDERCLOCKED_EINT |
WM5100_ADC_UNDERCLOCKED_EINT |
WM5100_MIXER_UNDERCLOCKED_EINT, 0);
}
}
pm_runtime_set_active(&i2c->dev);
pm_runtime_enable(&i2c->dev);
pm_request_idle(&i2c->dev);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm5100, wm5100_dai,
ARRAY_SIZE(wm5100_dai));
if (ret < 0) {
dev_err(&i2c->dev, "Failed to register WM5100: %d\n", ret);
goto err_reset;
}
return ret;
err_reset:
if (i2c->irq)
free_irq(i2c->irq, wm5100);
wm5100_free_gpio(i2c);
if (wm5100->pdata.reset) {
gpio_set_value_cansleep(wm5100->pdata.reset, 0);
gpio_free(wm5100->pdata.reset);
}
err_ldo:
if (wm5100->pdata.ldo_ena) {
gpio_set_value_cansleep(wm5100->pdata.ldo_ena, 0);
gpio_free(wm5100->pdata.ldo_ena);
}
err_enable:
regulator_bulk_disable(ARRAY_SIZE(wm5100->core_supplies),
wm5100->core_supplies);
err:
return ret;
}
static int wm5100_i2c_remove(struct i2c_client *i2c)
{
struct wm5100_priv *wm5100 = i2c_get_clientdata(i2c);
snd_soc_unregister_codec(&i2c->dev);
if (i2c->irq)
free_irq(i2c->irq, wm5100);
wm5100_free_gpio(i2c);
if (wm5100->pdata.reset) {
gpio_set_value_cansleep(wm5100->pdata.reset, 0);
gpio_free(wm5100->pdata.reset);
}
if (wm5100->pdata.ldo_ena) {
gpio_set_value_cansleep(wm5100->pdata.ldo_ena, 0);
gpio_free(wm5100->pdata.ldo_ena);
}
return 0;
}
static int wm5100_runtime_suspend(struct device *dev)
{
struct wm5100_priv *wm5100 = dev_get_drvdata(dev);
regcache_cache_only(wm5100->regmap, true);
regcache_mark_dirty(wm5100->regmap);
if (wm5100->pdata.ldo_ena)
gpio_set_value_cansleep(wm5100->pdata.ldo_ena, 0);
regulator_bulk_disable(ARRAY_SIZE(wm5100->core_supplies),
wm5100->core_supplies);
return 0;
}
static int wm5100_runtime_resume(struct device *dev)
{
struct wm5100_priv *wm5100 = dev_get_drvdata(dev);
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(wm5100->core_supplies),
wm5100->core_supplies);
if (ret != 0) {
dev_err(dev, "Failed to enable supplies: %d\n",
ret);
return ret;
}
if (wm5100->pdata.ldo_ena) {
gpio_set_value_cansleep(wm5100->pdata.ldo_ena, 1);
msleep(2);
}
regcache_cache_only(wm5100->regmap, false);
regcache_sync(wm5100->regmap);
return 0;
}
