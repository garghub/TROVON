static int fsl_asrc_request_pair(int channels, struct fsl_asrc_pair *pair)
{
enum asrc_pair_index index = ASRC_INVALID_PAIR;
struct fsl_asrc *asrc_priv = pair->asrc_priv;
struct device *dev = &asrc_priv->pdev->dev;
unsigned long lock_flags;
int i, ret = 0;
spin_lock_irqsave(&asrc_priv->lock, lock_flags);
for (i = ASRC_PAIR_A; i < ASRC_PAIR_MAX_NUM; i++) {
if (asrc_priv->pair[i] != NULL)
continue;
index = i;
if (i != ASRC_PAIR_B)
break;
}
if (index == ASRC_INVALID_PAIR) {
dev_err(dev, "all pairs are busy now\n");
ret = -EBUSY;
} else if (asrc_priv->channel_avail < channels) {
dev_err(dev, "can't afford required channels: %d\n", channels);
ret = -EINVAL;
} else {
asrc_priv->channel_avail -= channels;
asrc_priv->pair[index] = pair;
pair->channels = channels;
pair->index = index;
}
spin_unlock_irqrestore(&asrc_priv->lock, lock_flags);
return ret;
}
static void fsl_asrc_release_pair(struct fsl_asrc_pair *pair)
{
struct fsl_asrc *asrc_priv = pair->asrc_priv;
enum asrc_pair_index index = pair->index;
unsigned long lock_flags;
regmap_update_bits(asrc_priv->regmap, REG_ASRCTR,
ASRCTR_ASRCEi_MASK(index), 0);
spin_lock_irqsave(&asrc_priv->lock, lock_flags);
asrc_priv->channel_avail += pair->channels;
asrc_priv->pair[index] = NULL;
pair->error = 0;
spin_unlock_irqrestore(&asrc_priv->lock, lock_flags);
}
static void fsl_asrc_set_watermarks(struct fsl_asrc_pair *pair, u32 in, u32 out)
{
struct fsl_asrc *asrc_priv = pair->asrc_priv;
enum asrc_pair_index index = pair->index;
regmap_update_bits(asrc_priv->regmap, REG_ASRMCR(index),
ASRMCRi_EXTTHRSHi_MASK |
ASRMCRi_INFIFO_THRESHOLD_MASK |
ASRMCRi_OUTFIFO_THRESHOLD_MASK,
ASRMCRi_EXTTHRSHi |
ASRMCRi_INFIFO_THRESHOLD(in) |
ASRMCRi_OUTFIFO_THRESHOLD(out));
}
static u32 fsl_asrc_cal_asrck_divisor(struct fsl_asrc_pair *pair, u32 div)
{
u32 ps;
for (ps = 0; div > 8; ps++)
div >>= 1;
return ((div - 1) << ASRCDRi_AxCPi_WIDTH) | ps;
}
static int fsl_asrc_set_ideal_ratio(struct fsl_asrc_pair *pair,
int inrate, int outrate)
{
struct fsl_asrc *asrc_priv = pair->asrc_priv;
enum asrc_pair_index index = pair->index;
unsigned long ratio;
int i;
if (!outrate) {
pair_err("output rate should not be zero\n");
return -EINVAL;
}
ratio = (inrate / outrate) << IDEAL_RATIO_DECIMAL_DEPTH;
inrate %= outrate;
for (i = 1; i <= IDEAL_RATIO_DECIMAL_DEPTH; i++) {
inrate <<= 1;
if (inrate < outrate)
continue;
ratio |= 1 << (IDEAL_RATIO_DECIMAL_DEPTH - i);
inrate -= outrate;
if (!inrate)
break;
}
regmap_write(asrc_priv->regmap, REG_ASRIDRL(index), ratio);
regmap_write(asrc_priv->regmap, REG_ASRIDRH(index), ratio >> 24);
return 0;
}
static int fsl_asrc_config_pair(struct fsl_asrc_pair *pair)
{
struct asrc_config *config = pair->config;
struct fsl_asrc *asrc_priv = pair->asrc_priv;
enum asrc_pair_index index = pair->index;
u32 inrate, outrate, indiv, outdiv;
u32 clk_index[2], div[2];
int in, out, channels;
struct clk *clk;
bool ideal;
if (!config) {
pair_err("invalid pair config\n");
return -EINVAL;
}
if (config->channel_num < 1 || config->channel_num > 10) {
pair_err("does not support %d channels\n", config->channel_num);
return -EINVAL;
}
if (config->output_word_width == ASRC_WIDTH_8_BIT) {
pair_err("does not support 8bit width output\n");
return -EINVAL;
}
inrate = config->input_sample_rate;
outrate = config->output_sample_rate;
ideal = config->inclk == INCLK_NONE;
for (in = 0; in < ARRAY_SIZE(supported_input_rate); in++)
if (inrate == supported_input_rate[in])
break;
if (in == ARRAY_SIZE(supported_input_rate)) {
pair_err("unsupported input sample rate: %dHz\n", inrate);
return -EINVAL;
}
for (out = 0; out < ARRAY_SIZE(supported_asrc_rate); out++)
if (outrate == supported_asrc_rate[out])
break;
if (out == ARRAY_SIZE(supported_asrc_rate)) {
pair_err("unsupported output sample rate: %dHz\n", outrate);
return -EINVAL;
}
clk_index[IN] = clk_map[IN][config->inclk];
clk_index[OUT] = clk_map[OUT][config->outclk];
clk = asrc_priv->asrck_clk[clk_index[ideal ? OUT : IN]];
div[IN] = clk_get_rate(clk) / inrate;
if (div[IN] == 0) {
pair_err("failed to support input sample rate %dHz by asrck_%x\n",
inrate, clk_index[ideal ? OUT : IN]);
return -EINVAL;
}
clk = asrc_priv->asrck_clk[clk_index[OUT]];
if (ideal)
div[OUT] = clk_get_rate(clk) / IDEAL_RATIO_RATE;
else
div[OUT] = clk_get_rate(clk) / outrate;
if (div[OUT] == 0) {
pair_err("failed to support output sample rate %dHz by asrck_%x\n",
outrate, clk_index[OUT]);
return -EINVAL;
}
channels = config->channel_num;
if (asrc_priv->channel_bits < 4)
channels /= 2;
regmap_update_bits(asrc_priv->regmap, REG_ASRCNCR,
ASRCNCR_ANCi_MASK(index, asrc_priv->channel_bits),
ASRCNCR_ANCi(index, channels, asrc_priv->channel_bits));
regmap_update_bits(asrc_priv->regmap, REG_ASRCTR,
ASRCTR_ATSi_MASK(index), ASRCTR_ATS(index));
regmap_update_bits(asrc_priv->regmap, REG_ASRCTR,
ASRCTR_USRi_MASK(index), 0);
regmap_update_bits(asrc_priv->regmap, REG_ASRCSR,
ASRCSR_AICSi_MASK(index) | ASRCSR_AOCSi_MASK(index),
ASRCSR_AICS(index, clk_index[IN]) |
ASRCSR_AOCS(index, clk_index[OUT]));
indiv = fsl_asrc_cal_asrck_divisor(pair, div[IN]);
outdiv = fsl_asrc_cal_asrck_divisor(pair, div[OUT]);
regmap_update_bits(asrc_priv->regmap, REG_ASRCDR(index),
ASRCDRi_AOCPi_MASK(index) | ASRCDRi_AICPi_MASK(index) |
ASRCDRi_AOCDi_MASK(index) | ASRCDRi_AICDi_MASK(index),
ASRCDRi_AOCP(index, outdiv) | ASRCDRi_AICP(index, indiv));
regmap_update_bits(asrc_priv->regmap, REG_ASRMCR1(index),
ASRMCR1i_OW16_MASK | ASRMCR1i_IWD_MASK,
ASRMCR1i_OW16(config->output_word_width) |
ASRMCR1i_IWD(config->input_word_width));
regmap_update_bits(asrc_priv->regmap, REG_ASRMCR(index),
ASRMCRi_BUFSTALLi_MASK, ASRMCRi_BUFSTALLi);
fsl_asrc_set_watermarks(pair, ASRC_INPUTFIFO_THRESHOLD,
ASRC_INPUTFIFO_THRESHOLD);
if (!ideal)
return 0;
regmap_update_bits(asrc_priv->regmap, REG_ASRCTR,
ASRCTR_ATSi_MASK(index), 0);
regmap_update_bits(asrc_priv->regmap, REG_ASRCTR,
ASRCTR_IDRi_MASK(index) | ASRCTR_USRi_MASK(index),
ASRCTR_IDR(index) | ASRCTR_USR(index));
regmap_update_bits(asrc_priv->regmap, REG_ASRCFG,
ASRCFG_PREMODi_MASK(index) | ASRCFG_POSTMODi_MASK(index),
ASRCFG_PREMOD(index, process_option[in][out][0]) |
ASRCFG_POSTMOD(index, process_option[in][out][1]));
return fsl_asrc_set_ideal_ratio(pair, inrate, outrate);
}
static void fsl_asrc_start_pair(struct fsl_asrc_pair *pair)
{
struct fsl_asrc *asrc_priv = pair->asrc_priv;
enum asrc_pair_index index = pair->index;
int reg, retry = 10, i;
regmap_update_bits(asrc_priv->regmap, REG_ASRCTR,
ASRCTR_ASRCEi_MASK(index), ASRCTR_ASRCE(index));
do {
udelay(5);
regmap_read(asrc_priv->regmap, REG_ASRCFG, &reg);
reg &= ASRCFG_INIRQi_MASK(index);
} while (!reg && --retry);
regmap_read(asrc_priv->regmap, REG_ASRCNCR, &reg);
for (i = 0; i < pair->channels * 4; i++)
regmap_write(asrc_priv->regmap, REG_ASRDI(index), 0);
regmap_write(asrc_priv->regmap, REG_ASRIER, ASRIER_AOLIE);
}
static void fsl_asrc_stop_pair(struct fsl_asrc_pair *pair)
{
struct fsl_asrc *asrc_priv = pair->asrc_priv;
enum asrc_pair_index index = pair->index;
regmap_update_bits(asrc_priv->regmap, REG_ASRCTR,
ASRCTR_ASRCEi_MASK(index), 0);
}
struct dma_chan *fsl_asrc_get_dma_channel(struct fsl_asrc_pair *pair, bool dir)
{
struct fsl_asrc *asrc_priv = pair->asrc_priv;
enum asrc_pair_index index = pair->index;
char name[4];
sprintf(name, "%cx%c", dir == IN ? 'r' : 't', index + 'a');
return dma_request_slave_channel(&asrc_priv->pdev->dev, name);
}
static int fsl_asrc_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct fsl_asrc *asrc_priv = snd_soc_dai_get_drvdata(dai);
int width = snd_pcm_format_width(params_format(params));
struct snd_pcm_runtime *runtime = substream->runtime;
struct fsl_asrc_pair *pair = runtime->private_data;
unsigned int channels = params_channels(params);
unsigned int rate = params_rate(params);
struct asrc_config config;
int word_width, ret;
ret = fsl_asrc_request_pair(channels, pair);
if (ret) {
dev_err(dai->dev, "fail to request asrc pair\n");
return ret;
}
pair->config = &config;
if (width == 16)
width = ASRC_WIDTH_16_BIT;
else
width = ASRC_WIDTH_24_BIT;
if (asrc_priv->asrc_width == 16)
word_width = ASRC_WIDTH_16_BIT;
else
word_width = ASRC_WIDTH_24_BIT;
config.pair = pair->index;
config.channel_num = channels;
config.inclk = INCLK_NONE;
config.outclk = OUTCLK_ASRCK1_CLK;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
config.input_word_width = width;
config.output_word_width = word_width;
config.input_sample_rate = rate;
config.output_sample_rate = asrc_priv->asrc_rate;
} else {
config.input_word_width = word_width;
config.output_word_width = width;
config.input_sample_rate = asrc_priv->asrc_rate;
config.output_sample_rate = rate;
}
ret = fsl_asrc_config_pair(pair);
if (ret) {
dev_err(dai->dev, "fail to config asrc pair\n");
return ret;
}
return 0;
}
static int fsl_asrc_dai_hw_free(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct fsl_asrc_pair *pair = runtime->private_data;
if (pair)
fsl_asrc_release_pair(pair);
return 0;
}
static int fsl_asrc_dai_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct fsl_asrc_pair *pair = runtime->private_data;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
fsl_asrc_start_pair(pair);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
fsl_asrc_stop_pair(pair);
break;
default:
return -EINVAL;
}
return 0;
}
static int fsl_asrc_dai_probe(struct snd_soc_dai *dai)
{
struct fsl_asrc *asrc_priv = snd_soc_dai_get_drvdata(dai);
snd_soc_dai_init_dma_data(dai, &asrc_priv->dma_params_tx,
&asrc_priv->dma_params_rx);
return 0;
}
static bool fsl_asrc_readable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case REG_ASRCTR:
case REG_ASRIER:
case REG_ASRCNCR:
case REG_ASRCFG:
case REG_ASRCSR:
case REG_ASRCDR1:
case REG_ASRCDR2:
case REG_ASRSTR:
case REG_ASRPM1:
case REG_ASRPM2:
case REG_ASRPM3:
case REG_ASRPM4:
case REG_ASRPM5:
case REG_ASRTFR1:
case REG_ASRCCR:
case REG_ASRDOA:
case REG_ASRDOB:
case REG_ASRDOC:
case REG_ASRIDRHA:
case REG_ASRIDRLA:
case REG_ASRIDRHB:
case REG_ASRIDRLB:
case REG_ASRIDRHC:
case REG_ASRIDRLC:
case REG_ASR76K:
case REG_ASR56K:
case REG_ASRMCRA:
case REG_ASRFSTA:
case REG_ASRMCRB:
case REG_ASRFSTB:
case REG_ASRMCRC:
case REG_ASRFSTC:
case REG_ASRMCR1A:
case REG_ASRMCR1B:
case REG_ASRMCR1C:
return true;
default:
return false;
}
}
static bool fsl_asrc_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case REG_ASRSTR:
case REG_ASRDIA:
case REG_ASRDIB:
case REG_ASRDIC:
case REG_ASRDOA:
case REG_ASRDOB:
case REG_ASRDOC:
case REG_ASRFSTA:
case REG_ASRFSTB:
case REG_ASRFSTC:
case REG_ASRCFG:
return true;
default:
return false;
}
}
static bool fsl_asrc_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case REG_ASRCTR:
case REG_ASRIER:
case REG_ASRCNCR:
case REG_ASRCFG:
case REG_ASRCSR:
case REG_ASRCDR1:
case REG_ASRCDR2:
case REG_ASRSTR:
case REG_ASRPM1:
case REG_ASRPM2:
case REG_ASRPM3:
case REG_ASRPM4:
case REG_ASRPM5:
case REG_ASRTFR1:
case REG_ASRCCR:
case REG_ASRDIA:
case REG_ASRDIB:
case REG_ASRDIC:
case REG_ASRIDRHA:
case REG_ASRIDRLA:
case REG_ASRIDRHB:
case REG_ASRIDRLB:
case REG_ASRIDRHC:
case REG_ASRIDRLC:
case REG_ASR76K:
case REG_ASR56K:
case REG_ASRMCRA:
case REG_ASRMCRB:
case REG_ASRMCRC:
case REG_ASRMCR1A:
case REG_ASRMCR1B:
case REG_ASRMCR1C:
return true;
default:
return false;
}
}
static int fsl_asrc_init(struct fsl_asrc *asrc_priv)
{
regmap_write(asrc_priv->regmap, REG_ASRCTR, ASRCTR_ASRCEN);
regmap_write(asrc_priv->regmap, REG_ASRIER, 0x0);
regmap_write(asrc_priv->regmap, REG_ASRPM1, 0x7fffff);
regmap_write(asrc_priv->regmap, REG_ASRPM2, 0x255555);
regmap_write(asrc_priv->regmap, REG_ASRPM3, 0xff7280);
regmap_write(asrc_priv->regmap, REG_ASRPM4, 0xff7280);
regmap_write(asrc_priv->regmap, REG_ASRPM5, 0xff7280);
regmap_update_bits(asrc_priv->regmap, REG_ASRTFR1,
ASRTFR1_TF_BASE_MASK, ASRTFR1_TF_BASE(0xfc));
regmap_write(asrc_priv->regmap, REG_ASR76K, 0x06D6);
return regmap_write(asrc_priv->regmap, REG_ASR56K, 0x0947);
}
static irqreturn_t fsl_asrc_isr(int irq, void *dev_id)
{
struct fsl_asrc *asrc_priv = (struct fsl_asrc *)dev_id;
struct device *dev = &asrc_priv->pdev->dev;
enum asrc_pair_index index;
u32 status;
regmap_read(asrc_priv->regmap, REG_ASRSTR, &status);
regmap_write(asrc_priv->regmap, REG_ASRSTR, ASRSTR_AOLE);
for (index = ASRC_PAIR_A; index < ASRC_PAIR_MAX_NUM; index++) {
if (!asrc_priv->pair[index])
continue;
if (status & ASRSTR_ATQOL) {
asrc_priv->pair[index]->error |= ASRC_TASK_Q_OVERLOAD;
dev_dbg(dev, "ASRC Task Queue FIFO overload\n");
}
if (status & ASRSTR_AOOL(index)) {
asrc_priv->pair[index]->error |= ASRC_OUTPUT_TASK_OVERLOAD;
pair_dbg("Output Task Overload\n");
}
if (status & ASRSTR_AIOL(index)) {
asrc_priv->pair[index]->error |= ASRC_INPUT_TASK_OVERLOAD;
pair_dbg("Input Task Overload\n");
}
if (status & ASRSTR_AODO(index)) {
asrc_priv->pair[index]->error |= ASRC_OUTPUT_BUFFER_OVERFLOW;
pair_dbg("Output Data Buffer has overflowed\n");
}
if (status & ASRSTR_AIDU(index)) {
asrc_priv->pair[index]->error |= ASRC_INPUT_BUFFER_UNDERRUN;
pair_dbg("Input Data Buffer has underflowed\n");
}
}
return IRQ_HANDLED;
}
static int fsl_asrc_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct fsl_asrc *asrc_priv;
struct resource *res;
void __iomem *regs;
int irq, ret, i;
char tmp[16];
asrc_priv = devm_kzalloc(&pdev->dev, sizeof(*asrc_priv), GFP_KERNEL);
if (!asrc_priv)
return -ENOMEM;
asrc_priv->pdev = pdev;
strncpy(asrc_priv->name, np->name, sizeof(asrc_priv->name) - 1);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(regs))
return PTR_ERR(regs);
asrc_priv->paddr = res->start;
asrc_priv->regmap = devm_regmap_init_mmio_clk(&pdev->dev, "mem", regs,
&fsl_asrc_regmap_config);
if (IS_ERR(asrc_priv->regmap)) {
dev_err(&pdev->dev, "failed to init regmap\n");
return PTR_ERR(asrc_priv->regmap);
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no irq for node %s\n", np->full_name);
return irq;
}
ret = devm_request_irq(&pdev->dev, irq, fsl_asrc_isr, 0,
asrc_priv->name, asrc_priv);
if (ret) {
dev_err(&pdev->dev, "failed to claim irq %u: %d\n", irq, ret);
return ret;
}
asrc_priv->mem_clk = devm_clk_get(&pdev->dev, "mem");
if (IS_ERR(asrc_priv->mem_clk)) {
dev_err(&pdev->dev, "failed to get mem clock\n");
return PTR_ERR(asrc_priv->mem_clk);
}
asrc_priv->ipg_clk = devm_clk_get(&pdev->dev, "ipg");
if (IS_ERR(asrc_priv->ipg_clk)) {
dev_err(&pdev->dev, "failed to get ipg clock\n");
return PTR_ERR(asrc_priv->ipg_clk);
}
for (i = 0; i < ASRC_CLK_MAX_NUM; i++) {
sprintf(tmp, "asrck_%x", i);
asrc_priv->asrck_clk[i] = devm_clk_get(&pdev->dev, tmp);
if (IS_ERR(asrc_priv->asrck_clk[i])) {
dev_err(&pdev->dev, "failed to get %s clock\n", tmp);
return PTR_ERR(asrc_priv->asrck_clk[i]);
}
}
if (of_device_is_compatible(pdev->dev.of_node, "fsl,imx35-asrc")) {
asrc_priv->channel_bits = 3;
clk_map[IN] = input_clk_map_imx35;
clk_map[OUT] = output_clk_map_imx35;
} else {
asrc_priv->channel_bits = 4;
clk_map[IN] = input_clk_map_imx53;
clk_map[OUT] = output_clk_map_imx53;
}
ret = fsl_asrc_init(asrc_priv);
if (ret) {
dev_err(&pdev->dev, "failed to init asrc %d\n", ret);
return -EINVAL;
}
asrc_priv->channel_avail = 10;
ret = of_property_read_u32(np, "fsl,asrc-rate",
&asrc_priv->asrc_rate);
if (ret) {
dev_err(&pdev->dev, "failed to get output rate\n");
return -EINVAL;
}
ret = of_property_read_u32(np, "fsl,asrc-width",
&asrc_priv->asrc_width);
if (ret) {
dev_err(&pdev->dev, "failed to get output width\n");
return -EINVAL;
}
if (asrc_priv->asrc_width != 16 && asrc_priv->asrc_width != 24) {
dev_warn(&pdev->dev, "unsupported width, switching to 24bit\n");
asrc_priv->asrc_width = 24;
}
platform_set_drvdata(pdev, asrc_priv);
pm_runtime_enable(&pdev->dev);
spin_lock_init(&asrc_priv->lock);
ret = devm_snd_soc_register_component(&pdev->dev, &fsl_asrc_component,
&fsl_asrc_dai, 1);
if (ret) {
dev_err(&pdev->dev, "failed to register ASoC DAI\n");
return ret;
}
ret = devm_snd_soc_register_platform(&pdev->dev, &fsl_asrc_platform);
if (ret) {
dev_err(&pdev->dev, "failed to register ASoC platform\n");
return ret;
}
dev_info(&pdev->dev, "driver registered\n");
return 0;
}
static int fsl_asrc_runtime_resume(struct device *dev)
{
struct fsl_asrc *asrc_priv = dev_get_drvdata(dev);
int i;
clk_prepare_enable(asrc_priv->mem_clk);
clk_prepare_enable(asrc_priv->ipg_clk);
for (i = 0; i < ASRC_CLK_MAX_NUM; i++)
clk_prepare_enable(asrc_priv->asrck_clk[i]);
return 0;
}
static int fsl_asrc_runtime_suspend(struct device *dev)
{
struct fsl_asrc *asrc_priv = dev_get_drvdata(dev);
int i;
for (i = 0; i < ASRC_CLK_MAX_NUM; i++)
clk_disable_unprepare(asrc_priv->asrck_clk[i]);
clk_disable_unprepare(asrc_priv->ipg_clk);
clk_disable_unprepare(asrc_priv->mem_clk);
return 0;
}
static int fsl_asrc_suspend(struct device *dev)
{
struct fsl_asrc *asrc_priv = dev_get_drvdata(dev);
regcache_cache_only(asrc_priv->regmap, true);
regcache_mark_dirty(asrc_priv->regmap);
return 0;
}
static int fsl_asrc_resume(struct device *dev)
{
struct fsl_asrc *asrc_priv = dev_get_drvdata(dev);
u32 asrctr;
regmap_read(asrc_priv->regmap, REG_ASRCTR, &asrctr);
regmap_update_bits(asrc_priv->regmap, REG_ASRCTR,
ASRCTR_ASRCEi_ALL_MASK, 0);
regcache_cache_only(asrc_priv->regmap, false);
regcache_sync(asrc_priv->regmap);
regmap_update_bits(asrc_priv->regmap, REG_ASRCTR,
ASRCTR_ASRCEi_ALL_MASK, asrctr);
return 0;
}
