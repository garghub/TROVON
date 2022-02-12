static inline unsigned int uda134x_read_reg_cache(struct snd_soc_codec *codec,
unsigned int reg)
{
u8 *cache = codec->reg_cache;
if (reg >= UDA134X_REGS_NUM)
return -1;
return cache[reg];
}
static inline void uda134x_write_reg_cache(struct snd_soc_codec *codec,
u8 reg, unsigned int value)
{
u8 *cache = codec->reg_cache;
if (reg >= UDA134X_REGS_NUM)
return;
cache[reg] = value;
}
static int uda134x_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
int ret;
u8 addr;
u8 data = value;
struct uda134x_platform_data *pd = codec->control_data;
pr_debug("%s reg: %02X, value:%02X\n", __func__, reg, value);
if (reg >= UDA134X_REGS_NUM) {
printk(KERN_ERR "%s unknown register: reg: %u",
__func__, reg);
return -EINVAL;
}
uda134x_write_reg_cache(codec, reg, value);
switch (reg) {
case UDA134X_STATUS0:
case UDA134X_STATUS1:
addr = UDA134X_STATUS_ADDR;
break;
case UDA134X_DATA000:
case UDA134X_DATA001:
case UDA134X_DATA010:
case UDA134X_DATA011:
addr = UDA134X_DATA0_ADDR;
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
u8 reset_reg = uda134x_read_reg_cache(codec, UDA134X_STATUS0);
uda134x_write(codec, UDA134X_STATUS0, reset_reg | (1<<6));
msleep(1);
uda134x_write(codec, UDA134X_STATUS0, reset_reg & ~(1<<6));
}
static int uda134x_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u8 mute_reg = uda134x_read_reg_cache(codec, UDA134X_DATA010);
pr_debug("%s mute: %d\n", __func__, mute);
if (mute)
mute_reg |= (1<<2);
else
mute_reg &= ~(1<<2);
uda134x_write(codec, UDA134X_DATA010, mute_reg);
return 0;
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
snd_pcm_hw_constraint_minmax(substream->runtime,
SNDRV_PCM_HW_PARAM_RATE,
master_runtime->rate,
master_runtime->rate);
snd_pcm_hw_constraint_minmax(substream->runtime,
SNDRV_PCM_HW_PARAM_SAMPLE_BITS,
master_runtime->sample_bits,
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
u8 hw_params;
if (substream == uda134x->slave_substream) {
pr_debug("%s ignoring hw_params for slave substream\n",
__func__);
return 0;
}
hw_params = uda134x_read_reg_cache(codec, UDA134X_STATUS0);
hw_params &= STATUS0_SYSCLK_MASK;
hw_params &= STATUS0_DAIFMT_MASK;
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
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
hw_params |= (1<<1);
break;
case SNDRV_PCM_FORMAT_S18_3LE:
hw_params |= (1<<2);
break;
case SNDRV_PCM_FORMAT_S20_3LE:
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
uda134x_write(codec, UDA134X_STATUS0, hw_params);
return 0;
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
struct uda134x_platform_data *pd = codec->control_data;
int i;
u8 *cache = codec->reg_cache;
pr_debug("%s bias level %d\n", __func__, level);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
if (pd->power) {
pd->power(1);
for (i = 0; i < ARRAY_SIZE(uda134x_reg); i++)
codec->driver->write(codec, i, *cache++);
}
break;
case SND_SOC_BIAS_STANDBY:
break;
case SND_SOC_BIAS_OFF:
if (pd->power)
pd->power(0);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int uda134x_soc_probe(struct snd_soc_codec *codec)
{
struct uda134x_priv *uda134x;
struct uda134x_platform_data *pd = codec->card->dev->platform_data;
const struct snd_soc_dapm_widget *widgets;
unsigned num_widgets;
int ret;
printk(KERN_INFO "UDA134X SoC Audio Codec\n");
if (!pd) {
printk(KERN_ERR "UDA134X SoC codec: "
"missing L3 bitbang function\n");
return -ENODEV;
}
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
uda134x = kzalloc(sizeof(struct uda134x_priv), GFP_KERNEL);
if (uda134x == NULL)
return -ENOMEM;
snd_soc_codec_set_drvdata(codec, uda134x);
codec->control_data = pd;
if (pd->power)
pd->power(1);
uda134x_reset(codec);
if (pd->is_powered_on_standby)
uda134x_set_bias_level(codec, SND_SOC_BIAS_ON);
else
uda134x_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
if (pd->model == UDA134X_UDA1341) {
widgets = uda1341_dapm_widgets;
num_widgets = ARRAY_SIZE(uda1341_dapm_widgets);
} else {
widgets = uda1340_dapm_widgets;
num_widgets = ARRAY_SIZE(uda1340_dapm_widgets);
}
ret = snd_soc_dapm_new_controls(&codec->dapm, widgets, num_widgets);
if (ret) {
printk(KERN_ERR "%s failed to register dapm controls: %d",
__func__, ret);
kfree(uda134x);
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
kfree(uda134x);
return -EINVAL;
}
if (ret < 0) {
printk(KERN_ERR "UDA134X: failed to register controls\n");
kfree(uda134x);
return ret;
}
return 0;
}
static int uda134x_soc_remove(struct snd_soc_codec *codec)
{
struct uda134x_priv *uda134x = snd_soc_codec_get_drvdata(codec);
uda134x_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
uda134x_set_bias_level(codec, SND_SOC_BIAS_OFF);
kfree(uda134x);
return 0;
}
static int uda134x_soc_suspend(struct snd_soc_codec *codec)
{
uda134x_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
uda134x_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int uda134x_soc_resume(struct snd_soc_codec *codec)
{
uda134x_set_bias_level(codec, SND_SOC_BIAS_PREPARE);
uda134x_set_bias_level(codec, SND_SOC_BIAS_ON);
return 0;
}
static int uda134x_codec_probe(struct platform_device *pdev)
{
return snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_uda134x, &uda134x_dai, 1);
}
static int uda134x_codec_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
