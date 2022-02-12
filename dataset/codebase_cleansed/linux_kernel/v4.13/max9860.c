static int max9860_dvddio_event(struct notifier_block *nb,
unsigned long event, void *data)
{
struct max9860_priv *max9860 = container_of(nb, struct max9860_priv,
dvddio_nb);
if (event & REGULATOR_EVENT_DISABLE) {
regcache_mark_dirty(max9860->regmap);
regcache_cache_only(max9860->regmap, true);
}
return 0;
}
static bool max9860_readable(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX9860_INTRSTATUS ... MAX9860_MICGAIN:
case MAX9860_MICADC ... MAX9860_PWRMAN:
case MAX9860_REVISION:
return true;
}
return false;
}
static bool max9860_writeable(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX9860_INTEN ... MAX9860_MICGAIN:
case MAX9860_MICADC ... MAX9860_PWRMAN:
return true;
}
return false;
}
static bool max9860_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX9860_INTRSTATUS:
case MAX9860_MICREADBACK:
return true;
}
return false;
}
static bool max9860_precious(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX9860_INTRSTATUS:
return true;
}
return false;
}
static int max9860_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct max9860_priv *max9860 = snd_soc_codec_get_drvdata(codec);
u8 master;
u8 ifc1a = 0;
u8 ifc1b = 0;
u8 sysclk = 0;
unsigned long n;
int ret;
dev_dbg(codec->dev, "hw_params %u Hz, %u channels\n",
params_rate(params),
params_channels(params));
if (params_channels(params) == 2)
ifc1b |= MAX9860_ST;
switch (max9860->fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
master = 0;
break;
case SND_SOC_DAIFMT_CBM_CFM:
master = MAX9860_MASTER;
break;
default:
return -EINVAL;
}
ifc1a |= master;
if (master) {
if (params_width(params) * params_channels(params) > 48)
ifc1b |= MAX9860_BSEL_64X;
else
ifc1b |= MAX9860_BSEL_48X;
}
switch (max9860->fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
ifc1a |= MAX9860_DDLY;
ifc1b |= MAX9860_ADLY;
break;
case SND_SOC_DAIFMT_LEFT_J:
ifc1a |= MAX9860_WCI;
break;
case SND_SOC_DAIFMT_DSP_A:
if (params_width(params) != 16) {
dev_err(codec->dev,
"DSP_A works for 16 bits per sample only.\n");
return -EINVAL;
}
ifc1a |= MAX9860_DDLY | MAX9860_WCI | MAX9860_HIZ | MAX9860_TDM;
ifc1b |= MAX9860_ADLY;
break;
case SND_SOC_DAIFMT_DSP_B:
if (params_width(params) != 16) {
dev_err(codec->dev,
"DSP_B works for 16 bits per sample only.\n");
return -EINVAL;
}
ifc1a |= MAX9860_WCI | MAX9860_HIZ | MAX9860_TDM;
break;
default:
return -EINVAL;
}
switch (max9860->fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_NB_IF:
switch (max9860->fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
case SND_SOC_DAIFMT_DSP_B:
return -EINVAL;
}
ifc1a ^= MAX9860_WCI;
break;
case SND_SOC_DAIFMT_IB_IF:
switch (max9860->fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
case SND_SOC_DAIFMT_DSP_B:
return -EINVAL;
}
ifc1a ^= MAX9860_WCI;
case SND_SOC_DAIFMT_IB_NF:
ifc1a ^= MAX9860_DBCI;
ifc1b ^= MAX9860_ABCI;
break;
default:
return -EINVAL;
}
dev_dbg(codec->dev, "IFC1A %02x\n", ifc1a);
ret = regmap_write(max9860->regmap, MAX9860_IFC1A, ifc1a);
if (ret) {
dev_err(codec->dev, "Failed to set IFC1A: %d\n", ret);
return ret;
}
dev_dbg(codec->dev, "IFC1B %02x\n", ifc1b);
ret = regmap_write(max9860->regmap, MAX9860_IFC1B, ifc1b);
if (ret) {
dev_err(codec->dev, "Failed to set IFC1B: %d\n", ret);
return ret;
}
if (params_rate(params) == 8000 || params_rate(params) == 16000) {
if (master) {
switch (max9860->pclk_rate) {
case 12000000:
sysclk = MAX9860_FREQ_12MHZ;
break;
case 13000000:
sysclk = MAX9860_FREQ_13MHZ;
break;
case 19200000:
sysclk = MAX9860_FREQ_19_2MHZ;
break;
default:
break;
}
if (sysclk && params_rate(params) == 16000)
sysclk |= MAX9860_16KHZ;
}
}
n = DIV_ROUND_CLOSEST_ULL(65536ULL * 96 * params_rate(params),
max9860->pclk_rate);
if (!sysclk) {
if (params_rate(params) > 24000)
sysclk |= MAX9860_16KHZ;
if (!master)
n |= 1;
}
sysclk |= max9860->psclk;
dev_dbg(codec->dev, "SYSCLK %02x\n", sysclk);
ret = regmap_write(max9860->regmap,
MAX9860_SYSCLK, sysclk);
if (ret) {
dev_err(codec->dev, "Failed to set SYSCLK: %d\n", ret);
return ret;
}
dev_dbg(codec->dev, "N %lu\n", n);
ret = regmap_write(max9860->regmap,
MAX9860_AUDIOCLKHIGH, n >> 8);
if (ret) {
dev_err(codec->dev, "Failed to set NHI: %d\n", ret);
return ret;
}
ret = regmap_write(max9860->regmap,
MAX9860_AUDIOCLKLOW, n & 0xff);
if (ret) {
dev_err(codec->dev, "Failed to set NLO: %d\n", ret);
return ret;
}
if (!master) {
dev_dbg(codec->dev, "Enable PLL\n");
ret = regmap_update_bits(max9860->regmap, MAX9860_AUDIOCLKHIGH,
MAX9860_PLL, MAX9860_PLL);
if (ret) {
dev_err(codec->dev, "Failed to enable PLL: %d\n", ret);
return ret;
}
}
return 0;
}
static int max9860_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct max9860_priv *max9860 = snd_soc_codec_get_drvdata(codec);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
case SND_SOC_DAIFMT_CBS_CFS:
max9860->fmt = fmt;
return 0;
default:
return -EINVAL;
}
}
static int max9860_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct max9860_priv *max9860 = dev_get_drvdata(codec->dev);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
ret = regmap_update_bits(max9860->regmap, MAX9860_PWRMAN,
MAX9860_SHDN, MAX9860_SHDN);
if (ret) {
dev_err(codec->dev, "Failed to remove SHDN: %d\n", ret);
return ret;
}
break;
case SND_SOC_BIAS_OFF:
ret = regmap_update_bits(max9860->regmap, MAX9860_PWRMAN,
MAX9860_SHDN, 0);
if (ret) {
dev_err(codec->dev, "Failed to request SHDN: %d\n",
ret);
return ret;
}
break;
}
return 0;
}
static int max9860_suspend(struct device *dev)
{
struct max9860_priv *max9860 = dev_get_drvdata(dev);
int ret;
ret = regmap_update_bits(max9860->regmap, MAX9860_SYSCLK,
MAX9860_PSCLK, MAX9860_PSCLK_OFF);
if (ret) {
dev_err(dev, "Failed to disable clock: %d\n", ret);
return ret;
}
regulator_disable(max9860->dvddio);
return 0;
}
static int max9860_resume(struct device *dev)
{
struct max9860_priv *max9860 = dev_get_drvdata(dev);
int ret;
ret = regulator_enable(max9860->dvddio);
if (ret) {
dev_err(dev, "Failed to enable DVDDIO: %d\n", ret);
return ret;
}
regcache_cache_only(max9860->regmap, false);
ret = regcache_sync(max9860->regmap);
if (ret) {
dev_err(dev, "Failed to sync cache: %d\n", ret);
return ret;
}
ret = regmap_update_bits(max9860->regmap, MAX9860_SYSCLK,
MAX9860_PSCLK, max9860->psclk);
if (ret) {
dev_err(dev, "Failed to enable clock: %d\n", ret);
return ret;
}
return 0;
}
static int max9860_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct device *dev = &i2c->dev;
struct max9860_priv *max9860;
int ret;
struct clk *mclk;
unsigned long mclk_rate;
int i;
int intr;
max9860 = devm_kzalloc(dev, sizeof(struct max9860_priv), GFP_KERNEL);
if (!max9860)
return -ENOMEM;
max9860->dvddio = devm_regulator_get(dev, "DVDDIO");
if (IS_ERR(max9860->dvddio)) {
ret = PTR_ERR(max9860->dvddio);
if (ret != -EPROBE_DEFER)
dev_err(dev, "Failed to get DVDDIO supply: %d\n", ret);
return ret;
}
max9860->dvddio_nb.notifier_call = max9860_dvddio_event;
ret = regulator_register_notifier(max9860->dvddio, &max9860->dvddio_nb);
if (ret)
dev_err(dev, "Failed to register DVDDIO notifier: %d\n", ret);
ret = regulator_enable(max9860->dvddio);
if (ret != 0) {
dev_err(dev, "Failed to enable DVDDIO: %d\n", ret);
return ret;
}
max9860->regmap = devm_regmap_init_i2c(i2c, &max9860_regmap);
if (IS_ERR(max9860->regmap)) {
ret = PTR_ERR(max9860->regmap);
goto err_regulator;
}
dev_set_drvdata(dev, max9860);
mclk = clk_get(dev, "mclk");
if (IS_ERR(mclk)) {
ret = PTR_ERR(mclk);
if (ret != -EPROBE_DEFER)
dev_err(dev, "Failed to get MCLK: %d\n", ret);
goto err_regulator;
}
mclk_rate = clk_get_rate(mclk);
clk_put(mclk);
if (mclk_rate > 60000000 || mclk_rate < 10000000) {
dev_err(dev, "Bad mclk %luHz (needs 10MHz - 60MHz)\n",
mclk_rate);
ret = -EINVAL;
goto err_regulator;
}
if (mclk_rate >= 40000000)
max9860->psclk = 3;
else if (mclk_rate >= 20000000)
max9860->psclk = 2;
else
max9860->psclk = 1;
max9860->pclk_rate = mclk_rate >> (max9860->psclk - 1);
max9860->psclk <<= MAX9860_PSCLK_SHIFT;
dev_dbg(dev, "mclk %lu pclk %lu\n", mclk_rate, max9860->pclk_rate);
regcache_cache_bypass(max9860->regmap, true);
for (i = 0; i < max9860_regmap.num_reg_defaults; ++i) {
ret = regmap_write(max9860->regmap,
max9860_regmap.reg_defaults[i].reg,
max9860_regmap.reg_defaults[i].def);
if (ret) {
dev_err(dev, "Failed to initialize register %u: %d\n",
max9860_regmap.reg_defaults[i].reg, ret);
goto err_regulator;
}
}
regcache_cache_bypass(max9860->regmap, false);
ret = regmap_read(max9860->regmap, MAX9860_INTRSTATUS, &intr);
if (ret) {
dev_err(dev, "Failed to clear INTRSTATUS: %d\n", ret);
goto err_regulator;
}
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
pm_runtime_idle(dev);
ret = snd_soc_register_codec(dev, &max9860_codec_driver,
&max9860_dai, 1);
if (ret) {
dev_err(dev, "Failed to register CODEC: %d\n", ret);
goto err_pm;
}
return 0;
err_pm:
pm_runtime_disable(dev);
err_regulator:
regulator_disable(max9860->dvddio);
return ret;
}
static int max9860_remove(struct i2c_client *i2c)
{
struct device *dev = &i2c->dev;
struct max9860_priv *max9860 = dev_get_drvdata(dev);
snd_soc_unregister_codec(dev);
pm_runtime_disable(dev);
regulator_disable(max9860->dvddio);
return 0;
}
