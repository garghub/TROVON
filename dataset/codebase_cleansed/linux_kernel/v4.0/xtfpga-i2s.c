static bool xtfpga_i2s_wr_reg(struct device *dev, unsigned int reg)
{
return reg >= XTFPGA_I2S_CONFIG;
}
static bool xtfpga_i2s_rd_reg(struct device *dev, unsigned int reg)
{
return reg < XTFPGA_I2S_CHAN0_DATA;
}
static bool xtfpga_i2s_volatile_reg(struct device *dev, unsigned int reg)
{
return reg == XTFPGA_I2S_INT_STATUS;
}
static bool xtfpga_pcm_push_tx(struct xtfpga_i2s *i2s)
{
struct snd_pcm_substream *tx_substream;
bool tx_active;
rcu_read_lock();
tx_substream = rcu_dereference(i2s->tx_substream);
tx_active = tx_substream && snd_pcm_running(tx_substream);
if (tx_active) {
unsigned tx_ptr = ACCESS_ONCE(i2s->tx_ptr);
unsigned new_tx_ptr = i2s->tx_fn(i2s, tx_substream->runtime,
tx_ptr);
cmpxchg(&i2s->tx_ptr, tx_ptr, new_tx_ptr);
}
rcu_read_unlock();
return tx_active;
}
static void xtfpga_pcm_refill_fifo(struct xtfpga_i2s *i2s)
{
unsigned int_status;
unsigned i;
regmap_read(i2s->regmap, XTFPGA_I2S_INT_STATUS,
&int_status);
for (i = 0; i < 2; ++i) {
bool tx_active = xtfpga_pcm_push_tx(i2s);
regmap_write(i2s->regmap, XTFPGA_I2S_INT_STATUS,
XTFPGA_I2S_INT_VALID);
if (tx_active)
regmap_read(i2s->regmap, XTFPGA_I2S_INT_STATUS,
&int_status);
if (!tx_active ||
!(int_status & XTFPGA_I2S_INT_LEVEL))
break;
i2s->tx_fifo_level = i2s->tx_fifo_low;
}
if (!(int_status & XTFPGA_I2S_INT_LEVEL))
regmap_write(i2s->regmap, XTFPGA_I2S_INT_MASK,
XTFPGA_I2S_INT_VALID);
else if (!(int_status & XTFPGA_I2S_INT_UNDERRUN))
regmap_write(i2s->regmap, XTFPGA_I2S_INT_MASK,
XTFPGA_I2S_INT_UNDERRUN);
if (!(int_status & XTFPGA_I2S_INT_UNDERRUN))
regmap_update_bits(i2s->regmap, XTFPGA_I2S_CONFIG,
XTFPGA_I2S_CONFIG_INT_ENABLE |
XTFPGA_I2S_CONFIG_TX_ENABLE,
XTFPGA_I2S_CONFIG_INT_ENABLE |
XTFPGA_I2S_CONFIG_TX_ENABLE);
else
regmap_update_bits(i2s->regmap, XTFPGA_I2S_CONFIG,
XTFPGA_I2S_CONFIG_INT_ENABLE |
XTFPGA_I2S_CONFIG_TX_ENABLE, 0);
}
static irqreturn_t xtfpga_i2s_threaded_irq_handler(int irq, void *dev_id)
{
struct xtfpga_i2s *i2s = dev_id;
struct snd_pcm_substream *tx_substream;
unsigned config, int_status, int_mask;
regmap_read(i2s->regmap, XTFPGA_I2S_CONFIG, &config);
regmap_read(i2s->regmap, XTFPGA_I2S_INT_MASK, &int_mask);
regmap_read(i2s->regmap, XTFPGA_I2S_INT_STATUS, &int_status);
if (!(config & XTFPGA_I2S_CONFIG_INT_ENABLE) ||
!(int_status & int_mask & XTFPGA_I2S_INT_VALID))
return IRQ_NONE;
if (int_status & XTFPGA_I2S_INT_UNDERRUN) {
i2s->tx_fifo_level = 0;
regmap_update_bits(i2s->regmap, XTFPGA_I2S_CONFIG,
XTFPGA_I2S_CONFIG_TX_ENABLE, 0);
} else {
i2s->tx_fifo_level = i2s->tx_fifo_low;
}
rcu_read_lock();
tx_substream = rcu_dereference(i2s->tx_substream);
if (tx_substream && snd_pcm_running(tx_substream)) {
snd_pcm_period_elapsed(tx_substream);
if (int_status & XTFPGA_I2S_INT_UNDERRUN)
dev_dbg_ratelimited(i2s->dev, "%s: underrun\n",
__func__);
}
rcu_read_unlock();
xtfpga_pcm_refill_fifo(i2s);
return IRQ_HANDLED;
}
static int xtfpga_i2s_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct xtfpga_i2s *i2s = snd_soc_dai_get_drvdata(dai);
snd_soc_dai_set_dma_data(dai, substream, i2s);
return 0;
}
static int xtfpga_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct xtfpga_i2s *i2s = snd_soc_dai_get_drvdata(dai);
unsigned srate = params_rate(params);
unsigned channels = params_channels(params);
unsigned period_size = params_period_size(params);
unsigned sample_size = snd_pcm_format_width(params_format(params));
unsigned freq, ratio, level;
int err;
regmap_update_bits(i2s->regmap, XTFPGA_I2S_CONFIG,
XTFPGA_I2S_CONFIG_RES_MASK,
sample_size << XTFPGA_I2S_CONFIG_RES_BASE);
freq = 256 * srate;
err = clk_set_rate(i2s->clk, freq);
if (err < 0)
return err;
ratio = (freq - (srate * sample_size * 8)) /
(srate * sample_size * 4);
regmap_update_bits(i2s->regmap, XTFPGA_I2S_CONFIG,
XTFPGA_I2S_CONFIG_RATIO_MASK,
ratio << XTFPGA_I2S_CONFIG_RATIO_BASE);
i2s->tx_fifo_low = XTFPGA_I2S_FIFO_SIZE / 2;
for (level = 1;
i2s->tx_fifo_low / 2 >= period_size * 2 &&
level < (XTFPGA_I2S_CONFIG_LEVEL_MASK >>
XTFPGA_I2S_CONFIG_LEVEL_BASE); ++level)
i2s->tx_fifo_low /= 2;
i2s->tx_fifo_high = 2 * i2s->tx_fifo_low;
regmap_update_bits(i2s->regmap, XTFPGA_I2S_CONFIG,
XTFPGA_I2S_CONFIG_LEVEL_MASK,
level << XTFPGA_I2S_CONFIG_LEVEL_BASE);
dev_dbg(i2s->dev,
"%s srate: %u, channels: %u, sample_size: %u, period_size: %u\n",
__func__, srate, channels, sample_size, period_size);
dev_dbg(i2s->dev, "%s freq: %u, ratio: %u, level: %u\n",
__func__, freq, ratio, level);
return 0;
}
static int xtfpga_i2s_set_fmt(struct snd_soc_dai *cpu_dai,
unsigned int fmt)
{
if ((fmt & SND_SOC_DAIFMT_INV_MASK) != SND_SOC_DAIFMT_NB_NF)
return -EINVAL;
if ((fmt & SND_SOC_DAIFMT_MASTER_MASK) != SND_SOC_DAIFMT_CBS_CFS)
return -EINVAL;
if ((fmt & SND_SOC_DAIFMT_FORMAT_MASK) != SND_SOC_DAIFMT_I2S)
return -EINVAL;
return 0;
}
static int xtfpga_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
void *p;
snd_soc_set_runtime_hwparams(substream, &xtfpga_pcm_hardware);
p = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
runtime->private_data = p;
return 0;
}
static int xtfpga_pcm_close(struct snd_pcm_substream *substream)
{
synchronize_rcu();
return 0;
}
static int xtfpga_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
int ret;
struct snd_pcm_runtime *runtime = substream->runtime;
struct xtfpga_i2s *i2s = runtime->private_data;
unsigned channels = params_channels(hw_params);
switch (channels) {
case 1:
case 2:
break;
default:
return -EINVAL;
}
switch (params_format(hw_params)) {
case SNDRV_PCM_FORMAT_S16_LE:
i2s->tx_fn = (channels == 1) ?
xtfpga_pcm_tx_1x16 :
xtfpga_pcm_tx_2x16;
break;
case SNDRV_PCM_FORMAT_S32_LE:
i2s->tx_fn = (channels == 1) ?
xtfpga_pcm_tx_1x32 :
xtfpga_pcm_tx_2x32;
break;
default:
return -EINVAL;
}
ret = snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
return ret;
}
static int xtfpga_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
int ret = 0;
struct snd_pcm_runtime *runtime = substream->runtime;
struct xtfpga_i2s *i2s = runtime->private_data;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
ACCESS_ONCE(i2s->tx_ptr) = 0;
rcu_assign_pointer(i2s->tx_substream, substream);
xtfpga_pcm_refill_fifo(i2s);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
rcu_assign_pointer(i2s->tx_substream, NULL);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static snd_pcm_uframes_t xtfpga_pcm_pointer(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct xtfpga_i2s *i2s = runtime->private_data;
snd_pcm_uframes_t pos = ACCESS_ONCE(i2s->tx_ptr);
return pos < runtime->buffer_size ? pos : 0;
}
static int xtfpga_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_card *card = rtd->card->snd_card;
size_t size = xtfpga_pcm_hardware.buffer_bytes_max;
return snd_pcm_lib_preallocate_pages_for_all(rtd->pcm,
SNDRV_DMA_TYPE_DEV,
card->dev, size, size);
}
static void xtfpga_pcm_free(struct snd_pcm *pcm)
{
snd_pcm_lib_preallocate_free_for_all(pcm);
}
static int xtfpga_i2s_runtime_suspend(struct device *dev)
{
struct xtfpga_i2s *i2s = dev_get_drvdata(dev);
clk_disable_unprepare(i2s->clk);
return 0;
}
static int xtfpga_i2s_runtime_resume(struct device *dev)
{
struct xtfpga_i2s *i2s = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(i2s->clk);
if (ret) {
dev_err(dev, "clk_prepare_enable failed: %d\n", ret);
return ret;
}
return 0;
}
static int xtfpga_i2s_probe(struct platform_device *pdev)
{
struct xtfpga_i2s *i2s;
struct resource *mem;
int err, irq;
i2s = devm_kzalloc(&pdev->dev, sizeof(*i2s), GFP_KERNEL);
if (!i2s) {
err = -ENOMEM;
goto err;
}
platform_set_drvdata(pdev, i2s);
i2s->dev = &pdev->dev;
dev_dbg(&pdev->dev, "dev: %p, i2s: %p\n", &pdev->dev, i2s);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i2s->regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(i2s->regs)) {
err = PTR_ERR(i2s->regs);
goto err;
}
i2s->regmap = devm_regmap_init_mmio(&pdev->dev, i2s->regs,
&xtfpga_i2s_regmap_config);
if (IS_ERR(i2s->regmap)) {
dev_err(&pdev->dev, "regmap init failed\n");
err = PTR_ERR(i2s->regmap);
goto err;
}
i2s->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(i2s->clk)) {
dev_err(&pdev->dev, "couldn't get clock\n");
err = PTR_ERR(i2s->clk);
goto err;
}
regmap_write(i2s->regmap, XTFPGA_I2S_CONFIG,
(0x1 << XTFPGA_I2S_CONFIG_CHANNEL_BASE));
regmap_write(i2s->regmap, XTFPGA_I2S_INT_STATUS, XTFPGA_I2S_INT_VALID);
regmap_write(i2s->regmap, XTFPGA_I2S_INT_MASK, XTFPGA_I2S_INT_UNDERRUN);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "No IRQ resource\n");
err = irq;
goto err;
}
err = devm_request_threaded_irq(&pdev->dev, irq, NULL,
xtfpga_i2s_threaded_irq_handler,
IRQF_SHARED | IRQF_ONESHOT,
pdev->name, i2s);
if (err < 0) {
dev_err(&pdev->dev, "request_irq failed\n");
goto err;
}
err = snd_soc_register_platform(&pdev->dev, &xtfpga_soc_platform);
if (err < 0) {
dev_err(&pdev->dev, "couldn't register platform\n");
goto err;
}
err = devm_snd_soc_register_component(&pdev->dev,
&xtfpga_i2s_component,
xtfpga_i2s_dai,
ARRAY_SIZE(xtfpga_i2s_dai));
if (err < 0) {
dev_err(&pdev->dev, "couldn't register component\n");
goto err_unregister_platform;
}
pm_runtime_enable(&pdev->dev);
if (!pm_runtime_enabled(&pdev->dev)) {
err = xtfpga_i2s_runtime_resume(&pdev->dev);
if (err)
goto err_pm_disable;
}
return 0;
err_pm_disable:
pm_runtime_disable(&pdev->dev);
err_unregister_platform:
snd_soc_unregister_platform(&pdev->dev);
err:
dev_err(&pdev->dev, "%s: err = %d\n", __func__, err);
return err;
}
static int xtfpga_i2s_remove(struct platform_device *pdev)
{
struct xtfpga_i2s *i2s = dev_get_drvdata(&pdev->dev);
snd_soc_unregister_platform(&pdev->dev);
if (i2s->regmap && !IS_ERR(i2s->regmap)) {
regmap_write(i2s->regmap, XTFPGA_I2S_CONFIG, 0);
regmap_write(i2s->regmap, XTFPGA_I2S_INT_MASK, 0);
regmap_write(i2s->regmap, XTFPGA_I2S_INT_STATUS,
XTFPGA_I2S_INT_VALID);
}
pm_runtime_disable(&pdev->dev);
if (!pm_runtime_status_suspended(&pdev->dev))
xtfpga_i2s_runtime_suspend(&pdev->dev);
return 0;
}
