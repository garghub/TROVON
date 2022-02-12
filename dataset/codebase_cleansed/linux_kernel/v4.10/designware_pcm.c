void dw_pcm_push_tx(struct dw_i2s_dev *dev)
{
struct snd_pcm_substream *tx_substream;
bool tx_active, period_elapsed;
rcu_read_lock();
tx_substream = rcu_dereference(dev->tx_substream);
tx_active = tx_substream && snd_pcm_running(tx_substream);
if (tx_active) {
unsigned int tx_ptr = READ_ONCE(dev->tx_ptr);
unsigned int new_tx_ptr = dev->tx_fn(dev, tx_substream->runtime,
tx_ptr, &period_elapsed);
cmpxchg(&dev->tx_ptr, tx_ptr, new_tx_ptr);
if (period_elapsed)
snd_pcm_period_elapsed(tx_substream);
}
rcu_read_unlock();
}
static int dw_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct dw_i2s_dev *dev = snd_soc_dai_get_drvdata(rtd->cpu_dai);
snd_soc_set_runtime_hwparams(substream, &dw_pcm_hardware);
snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS);
runtime->private_data = dev;
return 0;
}
static int dw_pcm_close(struct snd_pcm_substream *substream)
{
synchronize_rcu();
return 0;
}
static int dw_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct dw_i2s_dev *dev = runtime->private_data;
int ret;
switch (params_channels(hw_params)) {
case 2:
break;
default:
dev_err(dev->dev, "invalid channels number\n");
return -EINVAL;
}
switch (params_format(hw_params)) {
case SNDRV_PCM_FORMAT_S16_LE:
dev->tx_fn = dw_pcm_tx_16;
break;
case SNDRV_PCM_FORMAT_S32_LE:
dev->tx_fn = dw_pcm_tx_32;
break;
default:
dev_err(dev->dev, "invalid format\n");
return -EINVAL;
}
if (substream->stream != SNDRV_PCM_STREAM_PLAYBACK) {
dev_err(dev->dev, "only playback is available\n");
return -EINVAL;
}
ret = snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
if (ret < 0)
return ret;
else
return 0;
}
static int dw_pcm_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int dw_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct dw_i2s_dev *dev = runtime->private_data;
int ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
WRITE_ONCE(dev->tx_ptr, 0);
rcu_assign_pointer(dev->tx_substream, substream);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
rcu_assign_pointer(dev->tx_substream, NULL);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static snd_pcm_uframes_t dw_pcm_pointer(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct dw_i2s_dev *dev = runtime->private_data;
snd_pcm_uframes_t pos = READ_ONCE(dev->tx_ptr);
return pos < runtime->buffer_size ? pos : 0;
}
static int dw_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
size_t size = dw_pcm_hardware.buffer_bytes_max;
return snd_pcm_lib_preallocate_pages_for_all(rtd->pcm,
SNDRV_DMA_TYPE_CONTINUOUS,
snd_dma_continuous_data(GFP_KERNEL), size, size);
}
static void dw_pcm_free(struct snd_pcm *pcm)
{
snd_pcm_lib_preallocate_free_for_all(pcm);
}
int dw_pcm_register(struct platform_device *pdev)
{
return devm_snd_soc_register_platform(&pdev->dev, &dw_pcm_platform);
}
