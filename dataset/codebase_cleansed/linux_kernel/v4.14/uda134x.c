static int uda134x_regmap_write(void *context, unsigned int reg,
unsigned int value)
{
struct uda134x_platform_data *pd = context;
int ret;
u8 addr;
u8 data = value;
switch (reg) {
case UDA134X_STATUS0:
case UDA134X_STATUS1:
addr = UDA134X_STATUS_ADDR;
data |= (reg - UDA134X_STATUS0) << 7;
break;
case UDA134X_DATA000:
case UDA134X_DATA001:
case UDA134X_DATA010:
case UDA134X_DATA011:
addr = UDA134X_DATA0_ADDR;
data |= (reg - UDA134X_DATA000) << 6;
break;
case UDA134X_DATA1:
addr = UDA134X_DATA1_ADDR;
break;
default:
addr = (reg | UDA134X_EXTADDR_PREFIX);
ret = l3_write(&pd->l3,
UDA134X_DATA0_ADDR, &addr, 1);
if (ret != 1)
return -EIO;
addr = UDA134X_DATA0_ADDR;
data = (value | UDA134X_EXTDATA_PREFIX);
break;
}
ret = l3_write(&pd->l3,
addr, &data, 1);
if (ret != 1)
return -EIO;
return 0;
}
static inline void uda134x_reset(struct snd_soc_codec *codec)
{
struct uda134x_priv *uda134x = snd_soc_codec_get_drvdata(codec);
unsigned int mask = 1<<6;
regmap_update_bits(uda134x->regmap, UDA134X_STATUS0, mask, mask);
msleep(1);
regmap_update_bits(uda134x->regmap, UDA134X_STATUS0, mask, 0);
}
static int uda134x_mute(struct snd_soc_dai *dai, int mute)
{
struct uda134x_priv *uda134x = snd_soc_codec_get_drvdata(dai->codec);
unsigned int mask = 1<<2;
unsigned int val;
pr_debug("%s mute: %d\n", __func__, mute);
if (mute)
val = mask;
else
val = 0;
return regmap_update_bits(uda134x->regmap, UDA134X_DATA010, mask, val);
}
static int uda134x_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct uda134x_priv *uda134x = snd_soc_codec_get_drvdata(codec);
struct snd_pcm_runtime *master_runtime;
if (uda134x->master_substream) {
master_runtime = uda134x->master_substream->runtime;
pr_debug("%s constraining to %d bits at %d\n", __func__,
master_runtime->sample_bits,
master_runtime->rate);
snd_pcm_hw_constraint_single(substream->runtime,
SNDRV_PCM_HW_PARAM_RATE,
master_runtime->rate);
snd_pcm_hw_constraint_single(substream->runtime,
SNDRV_PCM_HW_PARAM_SAMPLE_BITS,
master_runtime->sample_bits);
uda134x->slave_substream = substream;
} else
uda134x->master_substream = substream;
return 0;
}
static void uda134x_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct uda134x_priv *uda134x = snd_soc_codec_get_drvdata(codec);
if (uda134x->master_substream == substream)
uda134x->master_substream = uda134x->slave_substream;
uda134x->slave_substream = NULL;
}
static int uda134x_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct uda134x_priv *uda134x = snd_soc_codec_get_drvdata(codec);
unsigned int hw_params = 0;
if (substream == uda134x->slave_substream) {
pr_debug("%s ignoring hw_params for slave substream\n",
__func__);
return 0;
}
pr_debug("%s sysclk: %d, rate:%d\n", __func__,
uda134x->sysclk, params_rate(params));
switch (uda134x->sysclk / params_rate(params)) {
case 512:
break;
case 384:
hw_params |= (1<<4);
break;
case 256:
hw_params |= (1<<5);
break;
default:
printk(KERN_ERR "%s unsupported fs\n", __func__);
return -EINVAL;
}
pr_debug("%s dai_fmt: %d, params_format:%d\n", __func__,
uda134x->dai_fmt, params_format(params));
switch (uda134x->dai_fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
break;
case SND_SOC_DAIFMT_RIGHT_J:
switch (params_width(params)) {
case 16:
hw_params |= (1<<1);
break;
case 18:
hw_params |= (1<<2);
break;
case 20:
hw_params |= ((1<<2) | (1<<1));
break;
default:
printk(KERN_ERR "%s unsupported format (right)\n",
__func__);
return -EINVAL;
}
break;
case SND_SOC_DAIFMT_LEFT_J:
hw_params |= (1<<3);
break;
default:
printk(KERN_ERR "%s unsupported format\n", __func__);
return -EINVAL;
}
return regmap_update_bits(uda134x->regmap, UDA134X_STATUS0,
STATUS0_SYSCLK_MASK | STATUS0_DAIFMT_MASK, hw_params);
}
static int uda134x_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct uda134x_priv *uda134x = snd_soc_codec_get_drvdata(codec);
pr_debug("%s clk_id: %d, freq: %u, dir: %d\n", __func__,
clk_id, freq, dir);
if ((freq >= (256 * 8000)) && (freq <= (512 * 48000))) {
uda134x->sysclk = freq;
return 0;
}
printk(KERN_ERR "%s unsupported sysclk\n", __func__);
return -EINVAL;
}
static int uda134x_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct uda134x_priv *uda134x = snd_soc_codec_get_drvdata(codec);
pr_debug("%s fmt: %08X\n", __func__, fmt);
if ((fmt & SND_SOC_DAIFMT_MASTER_MASK) != SND_SOC_DAIFMT_CBS_CFS) {
printk(KERN_ERR "%s unsupported slave mode\n", __func__);
return -EINVAL;
}
if ((fmt & SND_SOC_DAIFMT_INV_MASK) != SND_SOC_DAIFMT_NB_NF) {
printk(KERN_ERR "%s unsupported clock inversion\n", __func__);
return -EINVAL;
}
uda134x->dai_fmt = fmt;
return 0;
}
static int uda134x_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct uda134x_priv *uda134x = snd_soc_codec_get_drvdata(codec);
struct uda134x_platform_data *pd = uda134x->pd;
pr_debug("%s bias level %d\n", __func__, level);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
if (pd->power) {
pd->power(1);
regcache_sync(uda134x->regmap);
}
break;
case SND_SOC_BIAS_STANDBY:
break;
case SND_SOC_BIAS_OFF:
if (pd->power) {
pd->power(0);
regcache_mark_dirty(uda134x->regmap);
}
break;
}
return 0;
}
static int uda134x_soc_probe(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct uda134x_priv *uda134x = snd_soc_codec_get_drvdata(codec);
struct uda134x_platform_data *pd = uda134x->pd;
const struct snd_soc_dapm_widget *widgets;
unsigned num_widgets;
int ret;
printk(KERN_INFO "UDA134X SoC Audio Codec\n");
switch (pd->model) {
case UDA134X_UDA1340:
case UDA134X_UDA1341:
case UDA134X_UDA1344:
case UDA134X_UDA1345:
break;
default:
printk(KERN_ERR "UDA134X SoC codec: "
"unsupported model %d\n",
pd->model);
return -EINVAL;
}
if (pd->power)
pd->power(1);
uda134x_reset(codec);
if (pd->model == UDA134X_UDA1341) {
widgets = uda1341_dapm_widgets;
num_widgets = ARRAY_SIZE(uda1341_dapm_widgets);
} else {
widgets = uda1340_dapm_widgets;
num_widgets = ARRAY_SIZE(uda1340_dapm_widgets);
}
ret = snd_soc_dapm_new_controls(dapm, widgets, num_widgets);
if (ret) {
printk(KERN_ERR "%s failed to register dapm controls: %d",
__func__, ret);
return ret;
}
switch (pd->model) {
case UDA134X_UDA1340:
case UDA134X_UDA1344:
ret = snd_soc_add_codec_controls(codec, uda1340_snd_controls,
ARRAY_SIZE(uda1340_snd_controls));
break;
case UDA134X_UDA1341:
ret = snd_soc_add_codec_controls(codec, uda1341_snd_controls,
ARRAY_SIZE(uda1341_snd_controls));
break;
case UDA134X_UDA1345:
ret = snd_soc_add_codec_controls(codec, uda1345_snd_controls,
ARRAY_SIZE(uda1345_snd_controls));
break;
default:
printk(KERN_ERR "%s unknown codec type: %d",
__func__, pd->model);
return -EINVAL;
}
if (ret < 0) {
printk(KERN_ERR "UDA134X: failed to register controls\n");
return ret;
}
return 0;
}
static int uda134x_codec_probe(struct platform_device *pdev)
{
struct uda134x_platform_data *pd = pdev->dev.platform_data;
struct uda134x_priv *uda134x;
int ret;
if (!pd) {
dev_err(&pdev->dev, "Missing L3 bitbang function\n");
return -ENODEV;
}
uda134x = devm_kzalloc(&pdev->dev, sizeof(*uda134x), GFP_KERNEL);
if (!uda134x)
return -ENOMEM;
uda134x->pd = pd;
platform_set_drvdata(pdev, uda134x);
if (pd->l3.use_gpios) {
ret = l3_set_gpio_ops(&pdev->dev, &uda134x->pd->l3);
if (ret < 0)
return ret;
}
uda134x->regmap = devm_regmap_init(&pdev->dev, NULL, pd,
&uda134x_regmap_config);
if (IS_ERR(uda134x->regmap))
return PTR_ERR(uda134x->regmap);
return snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_uda134x, &uda134x_dai, 1);
}
static int uda134x_codec_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
