static irqreturn_t stm32_i2s_isr(int irq, void *devid)
{
struct stm32_i2s_data *i2s = (struct stm32_i2s_data *)devid;
struct platform_device *pdev = i2s->pdev;
u32 sr, ier;
unsigned long flags;
int err = 0;
regmap_read(i2s->regmap, STM32_I2S_SR_REG, &sr);
regmap_read(i2s->regmap, STM32_I2S_IER_REG, &ier);
flags = sr & ier;
if (!flags) {
dev_dbg(&pdev->dev, "Spurious IRQ sr=0x%08x, ier=0x%08x\n",
sr, ier);
return IRQ_NONE;
}
regmap_update_bits(i2s->regmap, STM32_I2S_IFCR_REG,
I2S_IFCR_MASK, flags);
if (flags & I2S_SR_OVR) {
dev_dbg(&pdev->dev, "Overrun\n");
err = 1;
}
if (flags & I2S_SR_UDR) {
dev_dbg(&pdev->dev, "Underrun\n");
err = 1;
}
if (flags & I2S_SR_TIFRE)
dev_dbg(&pdev->dev, "Frame error\n");
if (err)
snd_pcm_stop_xrun(i2s->substream);
return IRQ_HANDLED;
}
static bool stm32_i2s_readable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case STM32_I2S_CR1_REG:
case STM32_I2S_CFG1_REG:
case STM32_I2S_CFG2_REG:
case STM32_I2S_IER_REG:
case STM32_I2S_SR_REG:
case STM32_I2S_IFCR_REG:
case STM32_I2S_TXDR_REG:
case STM32_I2S_RXDR_REG:
case STM32_I2S_CGFR_REG:
return true;
default:
return false;
}
}
static bool stm32_i2s_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case STM32_I2S_TXDR_REG:
case STM32_I2S_RXDR_REG:
return true;
default:
return false;
}
}
static bool stm32_i2s_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case STM32_I2S_CR1_REG:
case STM32_I2S_CFG1_REG:
case STM32_I2S_CFG2_REG:
case STM32_I2S_IER_REG:
case STM32_I2S_IFCR_REG:
case STM32_I2S_TXDR_REG:
case STM32_I2S_CGFR_REG:
return true;
default:
return false;
}
}
static int stm32_i2s_set_dai_fmt(struct snd_soc_dai *cpu_dai, unsigned int fmt)
{
struct stm32_i2s_data *i2s = snd_soc_dai_get_drvdata(cpu_dai);
u32 cgfr;
u32 cgfr_mask = I2S_CGFR_I2SSTD_MASK | I2S_CGFR_CKPOL |
I2S_CGFR_WSINV | I2S_CGFR_I2SCFG_MASK;
dev_dbg(cpu_dai->dev, "fmt %x\n", fmt);
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
cgfr = I2S_CGFR_I2SSTD_SET(I2S_STD_I2S);
break;
case SND_SOC_DAIFMT_MSB:
cgfr = I2S_CGFR_I2SSTD_SET(I2S_STD_LEFT_J);
break;
case SND_SOC_DAIFMT_LSB:
cgfr = I2S_CGFR_I2SSTD_SET(I2S_STD_RIGHT_J);
break;
case SND_SOC_DAIFMT_DSP_A:
cgfr = I2S_CGFR_I2SSTD_SET(I2S_STD_DSP);
break;
default:
dev_err(cpu_dai->dev, "Unsupported protocol %#x\n",
fmt & SND_SOC_DAIFMT_FORMAT_MASK);
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
cgfr |= I2S_CGFR_CKPOL;
break;
case SND_SOC_DAIFMT_NB_IF:
cgfr |= I2S_CGFR_WSINV;
break;
case SND_SOC_DAIFMT_IB_IF:
cgfr |= I2S_CGFR_CKPOL;
cgfr |= I2S_CGFR_WSINV;
break;
default:
dev_err(cpu_dai->dev, "Unsupported strobing %#x\n",
fmt & SND_SOC_DAIFMT_INV_MASK);
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
i2s->ms_flg = I2S_MS_SLAVE;
break;
case SND_SOC_DAIFMT_CBS_CFS:
i2s->ms_flg = I2S_MS_MASTER;
break;
default:
dev_err(cpu_dai->dev, "Unsupported mode %#x\n",
fmt & SND_SOC_DAIFMT_MASTER_MASK);
return -EINVAL;
}
i2s->fmt = fmt;
return regmap_update_bits(i2s->regmap, STM32_I2S_CGFR_REG,
cgfr_mask, cgfr);
}
static int stm32_i2s_set_sysclk(struct snd_soc_dai *cpu_dai,
int clk_id, unsigned int freq, int dir)
{
struct stm32_i2s_data *i2s = snd_soc_dai_get_drvdata(cpu_dai);
dev_dbg(cpu_dai->dev, "I2S MCLK frequency is %uHz\n", freq);
if ((dir == SND_SOC_CLOCK_OUT) && STM32_I2S_IS_MASTER(i2s)) {
i2s->mclk_rate = freq;
return regmap_update_bits(i2s->regmap, STM32_I2S_CGFR_REG,
I2S_CGFR_MCKOE, I2S_CGFR_MCKOE);
}
return 0;
}
static int stm32_i2s_configure_clock(struct snd_soc_dai *cpu_dai,
struct snd_pcm_hw_params *params)
{
struct stm32_i2s_data *i2s = snd_soc_dai_get_drvdata(cpu_dai);
unsigned long i2s_clock_rate;
unsigned int tmp, div, real_div, nb_bits, frame_len;
unsigned int rate = params_rate(params);
int ret;
u32 cgfr, cgfr_mask;
bool odd;
if (!(rate % 11025))
clk_set_parent(i2s->i2sclk, i2s->x11kclk);
else
clk_set_parent(i2s->i2sclk, i2s->x8kclk);
i2s_clock_rate = clk_get_rate(i2s->i2sclk);
if (i2s->mclk_rate) {
tmp = DIV_ROUND_CLOSEST(i2s_clock_rate, i2s->mclk_rate);
} else {
frame_len = 32;
if ((i2s->fmt & SND_SOC_DAIFMT_FORMAT_MASK) ==
SND_SOC_DAIFMT_DSP_A)
frame_len = 16;
ret = regmap_read(i2s->regmap, STM32_I2S_CGFR_REG, &cgfr);
if (ret < 0)
return ret;
nb_bits = frame_len * ((cgfr & I2S_CGFR_CHLEN) + 1);
tmp = DIV_ROUND_CLOSEST(i2s_clock_rate, (nb_bits * rate));
}
odd = tmp & 0x1;
div = tmp >> 1;
cgfr = I2S_CGFR_I2SDIV_SET(div) | (odd << I2S_CGFR_ODD_SHIFT);
cgfr_mask = I2S_CGFR_I2SDIV_MASK | I2S_CGFR_ODD;
real_div = ((2 * div) + odd);
dev_dbg(cpu_dai->dev, "I2S clk: %ld, SCLK: %d\n",
i2s_clock_rate, rate);
dev_dbg(cpu_dai->dev, "Divider: 2*%d(div)+%d(odd) = %d\n",
div, odd, real_div);
if (((div == 1) && odd) || (div > I2S_CGFR_I2SDIV_MAX)) {
dev_err(cpu_dai->dev, "Wrong divider setting\n");
return -EINVAL;
}
if (!div && !odd)
dev_warn(cpu_dai->dev, "real divider forced to 1\n");
ret = regmap_update_bits(i2s->regmap, STM32_I2S_CGFR_REG,
cgfr_mask, cgfr);
if (ret < 0)
return ret;
return regmap_update_bits(i2s->regmap, STM32_I2S_CFG2_REG,
I2S_CFG2_AFCNTR, I2S_CFG2_AFCNTR);
}
static int stm32_i2s_configure(struct snd_soc_dai *cpu_dai,
struct snd_pcm_hw_params *params,
struct snd_pcm_substream *substream)
{
struct stm32_i2s_data *i2s = snd_soc_dai_get_drvdata(cpu_dai);
int format = params_width(params);
u32 cfgr, cfgr_mask, cfg1, cfg1_mask;
unsigned int fthlv;
int ret;
if ((params_channels(params) == 1) &&
((i2s->fmt & SND_SOC_DAIFMT_FORMAT_MASK) != SND_SOC_DAIFMT_DSP_A)) {
dev_err(cpu_dai->dev, "Mono mode supported only by DSP_A\n");
return -EINVAL;
}
switch (format) {
case 16:
cfgr = I2S_CGFR_DATLEN_SET(I2S_I2SMOD_DATLEN_16);
cfgr_mask = I2S_CGFR_DATLEN_MASK;
break;
case 32:
cfgr = I2S_CGFR_DATLEN_SET(I2S_I2SMOD_DATLEN_32) |
I2S_CGFR_CHLEN;
cfgr_mask = I2S_CGFR_DATLEN_MASK | I2S_CGFR_CHLEN;
break;
default:
dev_err(cpu_dai->dev, "Unexpected format %d", format);
return -EINVAL;
}
if (STM32_I2S_IS_SLAVE(i2s)) {
cfgr |= I2S_CGFR_I2SCFG_SET(I2S_I2SMOD_FD_SLAVE);
cfgr |= I2S_CGFR_FIXCH;
cfgr_mask |= I2S_CGFR_FIXCH;
} else {
cfgr |= I2S_CGFR_I2SCFG_SET(I2S_I2SMOD_FD_MASTER);
}
cfgr_mask |= I2S_CGFR_I2SCFG_MASK;
ret = regmap_update_bits(i2s->regmap, STM32_I2S_CGFR_REG,
cfgr_mask, cfgr);
if (ret < 0)
return ret;
cfg1 = I2S_CFG1_RXDMAEN | I2S_CFG1_TXDMAEN;
cfg1_mask = cfg1;
fthlv = STM32_I2S_FIFO_SIZE * I2S_FIFO_TH_ONE_QUARTER / 4;
cfg1 |= I2S_CFG1_FTHVL_SET(fthlv - 1);
cfg1_mask |= I2S_CFG1_FTHVL_MASK;
return regmap_update_bits(i2s->regmap, STM32_I2S_CFG1_REG,
cfg1_mask, cfg1);
}
static int stm32_i2s_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct stm32_i2s_data *i2s = snd_soc_dai_get_drvdata(cpu_dai);
i2s->substream = substream;
spin_lock(&i2s->lock_fd);
i2s->refcount++;
spin_unlock(&i2s->lock_fd);
return regmap_update_bits(i2s->regmap, STM32_I2S_IFCR_REG,
I2S_IFCR_MASK, I2S_IFCR_MASK);
}
static int stm32_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
struct stm32_i2s_data *i2s = snd_soc_dai_get_drvdata(cpu_dai);
int ret;
ret = stm32_i2s_configure(cpu_dai, params, substream);
if (ret < 0) {
dev_err(cpu_dai->dev, "Configuration returned error %d\n", ret);
return ret;
}
if (STM32_I2S_IS_MASTER(i2s))
ret = stm32_i2s_configure_clock(cpu_dai, params);
return ret;
}
static int stm32_i2s_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *cpu_dai)
{
struct stm32_i2s_data *i2s = snd_soc_dai_get_drvdata(cpu_dai);
bool playback_flg = (substream->stream == SNDRV_PCM_STREAM_PLAYBACK);
u32 cfg1_mask, ier;
int ret;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
dev_dbg(cpu_dai->dev, "start I2S\n");
ret = regmap_update_bits(i2s->regmap, STM32_I2S_CR1_REG,
I2S_CR1_SPE, I2S_CR1_SPE);
if (ret < 0) {
dev_err(cpu_dai->dev, "Error %d enabling I2S\n", ret);
return ret;
}
ret = regmap_update_bits(i2s->regmap, STM32_I2S_CR1_REG,
I2S_CR1_CSTART, I2S_CR1_CSTART);
if (ret < 0) {
dev_err(cpu_dai->dev, "Error %d starting I2S\n", ret);
return ret;
}
regmap_update_bits(i2s->regmap, STM32_I2S_IFCR_REG,
I2S_IFCR_MASK, I2S_IFCR_MASK);
if (playback_flg) {
ier = I2S_IER_UDRIE;
} else {
ier = I2S_IER_OVRIE;
spin_lock(&i2s->lock_fd);
if (i2s->refcount == 1)
regmap_write(i2s->regmap,
STM32_I2S_TXDR_REG, 0);
spin_unlock(&i2s->lock_fd);
}
if (STM32_I2S_IS_SLAVE(i2s))
ier |= I2S_IER_TIFREIE;
regmap_update_bits(i2s->regmap, STM32_I2S_IER_REG, ier, ier);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
if (playback_flg)
regmap_update_bits(i2s->regmap, STM32_I2S_IER_REG,
I2S_IER_UDRIE,
(unsigned int)~I2S_IER_UDRIE);
else
regmap_update_bits(i2s->regmap, STM32_I2S_IER_REG,
I2S_IER_OVRIE,
(unsigned int)~I2S_IER_OVRIE);
spin_lock(&i2s->lock_fd);
i2s->refcount--;
if (i2s->refcount) {
spin_unlock(&i2s->lock_fd);
break;
}
spin_unlock(&i2s->lock_fd);
dev_dbg(cpu_dai->dev, "stop I2S\n");
ret = regmap_update_bits(i2s->regmap, STM32_I2S_CR1_REG,
I2S_CR1_SPE, 0);
if (ret < 0) {
dev_err(cpu_dai->dev, "Error %d disabling I2S\n", ret);
return ret;
}
cfg1_mask = I2S_CFG1_RXDMAEN | I2S_CFG1_TXDMAEN;
regmap_update_bits(i2s->regmap, STM32_I2S_CFG1_REG,
cfg1_mask, 0);
break;
default:
return -EINVAL;
}
return 0;
}
static void stm32_i2s_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct stm32_i2s_data *i2s = snd_soc_dai_get_drvdata(cpu_dai);
i2s->substream = NULL;
regmap_update_bits(i2s->regmap, STM32_I2S_CGFR_REG,
I2S_CGFR_MCKOE, (unsigned int)~I2S_CGFR_MCKOE);
}
static int stm32_i2s_dai_probe(struct snd_soc_dai *cpu_dai)
{
struct stm32_i2s_data *i2s = dev_get_drvdata(cpu_dai->dev);
struct snd_dmaengine_dai_dma_data *dma_data_tx = &i2s->dma_data_tx;
struct snd_dmaengine_dai_dma_data *dma_data_rx = &i2s->dma_data_rx;
dma_data_tx->addr_width = DMA_SLAVE_BUSWIDTH_UNDEFINED;
dma_data_tx->addr = (dma_addr_t)(i2s->phys_addr) + STM32_I2S_TXDR_REG;
dma_data_tx->maxburst = 1;
dma_data_rx->addr_width = DMA_SLAVE_BUSWIDTH_UNDEFINED;
dma_data_rx->addr = (dma_addr_t)(i2s->phys_addr) + STM32_I2S_RXDR_REG;
dma_data_rx->maxburst = 1;
snd_soc_dai_init_dma_data(cpu_dai, dma_data_tx, dma_data_rx);
return 0;
}
static void stm32_i2s_dai_init(struct snd_soc_pcm_stream *stream,
char *stream_name)
{
stream->stream_name = stream_name;
stream->channels_min = 1;
stream->channels_max = 2;
stream->rates = SNDRV_PCM_RATE_8000_192000;
stream->formats = SNDRV_PCM_FMTBIT_S16_LE |
SNDRV_PCM_FMTBIT_S32_LE;
}
static int stm32_i2s_dais_init(struct platform_device *pdev,
struct stm32_i2s_data *i2s)
{
struct snd_soc_dai_driver *dai_ptr;
dai_ptr = devm_kzalloc(&pdev->dev, sizeof(struct snd_soc_dai_driver),
GFP_KERNEL);
if (!dai_ptr)
return -ENOMEM;
snprintf(i2s->dais_name, STM32_I2S_DAI_NAME_SIZE,
"%s", dev_name(&pdev->dev));
dai_ptr->probe = stm32_i2s_dai_probe;
dai_ptr->ops = &stm32_i2s_pcm_dai_ops;
dai_ptr->name = i2s->dais_name;
dai_ptr->id = 1;
stm32_i2s_dai_init(&dai_ptr->playback, "playback");
stm32_i2s_dai_init(&dai_ptr->capture, "capture");
i2s->dai_drv = dai_ptr;
return 0;
}
static int stm32_i2s_parse_dt(struct platform_device *pdev,
struct stm32_i2s_data *i2s)
{
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *of_id;
struct reset_control *rst;
struct resource *res;
int irq, ret;
if (!np)
return -ENODEV;
of_id = of_match_device(stm32_i2s_ids, &pdev->dev);
if (of_id)
i2s->regmap_conf = (const struct regmap_config *)of_id->data;
else
return -EINVAL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i2s->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(i2s->base))
return PTR_ERR(i2s->base);
i2s->phys_addr = res->start;
i2s->pclk = devm_clk_get(&pdev->dev, "pclk");
if (IS_ERR(i2s->pclk)) {
dev_err(&pdev->dev, "Could not get pclk\n");
return PTR_ERR(i2s->pclk);
}
i2s->i2sclk = devm_clk_get(&pdev->dev, "i2sclk");
if (IS_ERR(i2s->i2sclk)) {
dev_err(&pdev->dev, "Could not get i2sclk\n");
return PTR_ERR(i2s->i2sclk);
}
i2s->x8kclk = devm_clk_get(&pdev->dev, "x8k");
if (IS_ERR(i2s->x8kclk)) {
dev_err(&pdev->dev, "missing x8k parent clock\n");
return PTR_ERR(i2s->x8kclk);
}
i2s->x11kclk = devm_clk_get(&pdev->dev, "x11k");
if (IS_ERR(i2s->x11kclk)) {
dev_err(&pdev->dev, "missing x11k parent clock\n");
return PTR_ERR(i2s->x11kclk);
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no irq for node %s\n", pdev->name);
return -ENOENT;
}
ret = devm_request_irq(&pdev->dev, irq, stm32_i2s_isr, IRQF_ONESHOT,
dev_name(&pdev->dev), i2s);
if (ret) {
dev_err(&pdev->dev, "irq request returned %d\n", ret);
return ret;
}
rst = devm_reset_control_get_exclusive(&pdev->dev, NULL);
if (!IS_ERR(rst)) {
reset_control_assert(rst);
udelay(2);
reset_control_deassert(rst);
}
return 0;
}
static int stm32_i2s_probe(struct platform_device *pdev)
{
struct stm32_i2s_data *i2s;
int ret;
i2s = devm_kzalloc(&pdev->dev, sizeof(*i2s), GFP_KERNEL);
if (!i2s)
return -ENOMEM;
ret = stm32_i2s_parse_dt(pdev, i2s);
if (ret)
return ret;
i2s->pdev = pdev;
i2s->ms_flg = I2S_MS_NOT_SET;
spin_lock_init(&i2s->lock_fd);
platform_set_drvdata(pdev, i2s);
ret = stm32_i2s_dais_init(pdev, i2s);
if (ret)
return ret;
i2s->regmap = devm_regmap_init_mmio(&pdev->dev, i2s->base,
i2s->regmap_conf);
if (IS_ERR(i2s->regmap)) {
dev_err(&pdev->dev, "regmap init failed\n");
return PTR_ERR(i2s->regmap);
}
ret = clk_prepare_enable(i2s->pclk);
if (ret) {
dev_err(&pdev->dev, "Enable pclk failed: %d\n", ret);
return ret;
}
ret = clk_prepare_enable(i2s->i2sclk);
if (ret) {
dev_err(&pdev->dev, "Enable i2sclk failed: %d\n", ret);
goto err_pclk_disable;
}
ret = devm_snd_soc_register_component(&pdev->dev, &stm32_i2s_component,
i2s->dai_drv, 1);
if (ret)
goto err_clocks_disable;
ret = devm_snd_dmaengine_pcm_register(&pdev->dev,
&stm32_i2s_pcm_config, 0);
if (ret)
goto err_clocks_disable;
ret = regmap_update_bits(i2s->regmap, STM32_I2S_CGFR_REG,
I2S_CGFR_I2SMOD, I2S_CGFR_I2SMOD);
if (ret)
goto err_clocks_disable;
return ret;
err_clocks_disable:
clk_disable_unprepare(i2s->i2sclk);
err_pclk_disable:
clk_disable_unprepare(i2s->pclk);
return ret;
}
static int stm32_i2s_remove(struct platform_device *pdev)
{
struct stm32_i2s_data *i2s = platform_get_drvdata(pdev);
clk_disable_unprepare(i2s->i2sclk);
clk_disable_unprepare(i2s->pclk);
return 0;
}
