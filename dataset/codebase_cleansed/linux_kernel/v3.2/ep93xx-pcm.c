static void ep93xx_pcm_dma_callback(void *data)
{
struct snd_pcm_substream *substream = data;
struct ep93xx_runtime_data *rtd = substream->runtime->private_data;
rtd->pointer_bytes += rtd->period_bytes;
rtd->pointer_bytes %= rtd->period_bytes * rtd->periods;
snd_pcm_period_elapsed(substream);
}
static bool ep93xx_pcm_dma_filter(struct dma_chan *chan, void *filter_param)
{
struct ep93xx_dma_data *data = filter_param;
if (data->direction == ep93xx_dma_chan_direction(chan)) {
chan->private = data;
return true;
}
return false;
}
static int ep93xx_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *soc_rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = soc_rtd->cpu_dai;
struct ep93xx_pcm_dma_params *dma_params;
struct ep93xx_runtime_data *rtd;
dma_cap_mask_t mask;
int ret;
ret = snd_pcm_hw_constraint_integer(substream->runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (ret < 0)
return ret;
snd_soc_set_runtime_hwparams(substream, &ep93xx_pcm_hardware);
rtd = kmalloc(sizeof(*rtd), GFP_KERNEL);
if (!rtd)
return -ENOMEM;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
dma_cap_set(DMA_CYCLIC, mask);
dma_params = snd_soc_dai_get_dma_data(cpu_dai, substream);
rtd->dma_data.port = dma_params->dma_port;
rtd->dma_data.name = dma_params->name;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
rtd->dma_data.direction = DMA_TO_DEVICE;
else
rtd->dma_data.direction = DMA_FROM_DEVICE;
rtd->dma_chan = dma_request_channel(mask, ep93xx_pcm_dma_filter,
&rtd->dma_data);
if (!rtd->dma_chan) {
kfree(rtd);
return -EINVAL;
}
substream->runtime->private_data = rtd;
return 0;
}
static int ep93xx_pcm_close(struct snd_pcm_substream *substream)
{
struct ep93xx_runtime_data *rtd = substream->runtime->private_data;
dma_release_channel(rtd->dma_chan);
kfree(rtd);
return 0;
}
static int ep93xx_pcm_dma_submit(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct ep93xx_runtime_data *rtd = runtime->private_data;
struct dma_chan *chan = rtd->dma_chan;
struct dma_device *dma_dev = chan->device;
struct dma_async_tx_descriptor *desc;
rtd->pointer_bytes = 0;
desc = dma_dev->device_prep_dma_cyclic(chan, runtime->dma_addr,
rtd->period_bytes * rtd->periods,
rtd->period_bytes,
rtd->dma_data.direction);
if (!desc)
return -EINVAL;
desc->callback = ep93xx_pcm_dma_callback;
desc->callback_param = substream;
dmaengine_submit(desc);
return 0;
}
static void ep93xx_pcm_dma_flush(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct ep93xx_runtime_data *rtd = runtime->private_data;
dmaengine_terminate_all(rtd->dma_chan);
}
static int ep93xx_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct ep93xx_runtime_data *rtd = runtime->private_data;
snd_pcm_set_runtime_buffer(substream, &substream->dma_buffer);
rtd->periods = params_periods(params);
rtd->period_bytes = params_period_bytes(params);
return 0;
}
static int ep93xx_pcm_hw_free(struct snd_pcm_substream *substream)
{
snd_pcm_set_runtime_buffer(substream, NULL);
return 0;
}
static int ep93xx_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
int ret;
ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
ret = ep93xx_pcm_dma_submit(substream);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
ep93xx_pcm_dma_flush(substream);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static snd_pcm_uframes_t ep93xx_pcm_pointer(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct ep93xx_runtime_data *rtd = substream->runtime->private_data;
return bytes_to_frames(runtime, rtd->pointer_bytes);
}
static int ep93xx_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
struct snd_pcm_runtime *runtime = substream->runtime;
return dma_mmap_writecombine(substream->pcm->card->dev, vma,
runtime->dma_area,
runtime->dma_addr,
runtime->dma_bytes);
}
static int ep93xx_pcm_preallocate_dma_buffer(struct snd_pcm *pcm, int stream)
{
struct snd_pcm_substream *substream = pcm->streams[stream].substream;
struct snd_dma_buffer *buf = &substream->dma_buffer;
size_t size = ep93xx_pcm_hardware.buffer_bytes_max;
buf->dev.type = SNDRV_DMA_TYPE_DEV;
buf->dev.dev = pcm->card->dev;
buf->private_data = NULL;
buf->area = dma_alloc_writecombine(pcm->card->dev, size,
&buf->addr, GFP_KERNEL);
buf->bytes = size;
return (buf->area == NULL) ? -ENOMEM : 0;
}
static void ep93xx_pcm_free_dma_buffers(struct snd_pcm *pcm)
{
struct snd_pcm_substream *substream;
struct snd_dma_buffer *buf;
int stream;
for (stream = 0; stream < 2; stream++) {
substream = pcm->streams[stream].substream;
if (!substream)
continue;
buf = &substream->dma_buffer;
if (!buf->area)
continue;
dma_free_writecombine(pcm->card->dev, buf->bytes, buf->area,
buf->addr);
buf->area = NULL;
}
}
static int ep93xx_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_card *card = rtd->card->snd_card;
struct snd_soc_dai *dai = rtd->cpu_dai;
struct snd_pcm *pcm = rtd->pcm;
int ret = 0;
if (!card->dev->dma_mask)
card->dev->dma_mask = &ep93xx_pcm_dmamask;
if (!card->dev->coherent_dma_mask)
card->dev->coherent_dma_mask = 0xffffffff;
if (dai->driver->playback.channels_min) {
ret = ep93xx_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_PLAYBACK);
if (ret)
return ret;
}
if (dai->driver->capture.channels_min) {
ret = ep93xx_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_CAPTURE);
if (ret)
return ret;
}
return 0;
}
static int __devinit ep93xx_soc_platform_probe(struct platform_device *pdev)
{
return snd_soc_register_platform(&pdev->dev, &ep93xx_soc_platform);
}
static int __devexit ep93xx_soc_platform_remove(struct platform_device *pdev)
{
snd_soc_unregister_platform(&pdev->dev);
return 0;
}
static int __init ep93xx_soc_platform_init(void)
{
return platform_driver_register(&ep93xx_pcm_driver);
}
static void __exit ep93xx_soc_platform_exit(void)
{
platform_driver_unregister(&ep93xx_pcm_driver);
}
