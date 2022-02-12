static void audio_dma_irq(void *data)
{
struct snd_pcm_substream *substream = (struct snd_pcm_substream *)data;
struct snd_pcm_runtime *runtime = substream->runtime;
struct mxs_pcm_runtime_data *iprtd = runtime->private_data;
iprtd->offset += iprtd->period_bytes;
iprtd->offset %= iprtd->period_bytes * iprtd->periods;
snd_pcm_period_elapsed(substream);
}
static bool filter(struct dma_chan *chan, void *param)
{
struct mxs_pcm_runtime_data *iprtd = param;
struct mxs_pcm_dma_params *dma_params = iprtd->dma_params;
if (!mxs_dma_is_apbx(chan))
return false;
if (chan->chan_id != dma_params->chan_num)
return false;
chan->private = &iprtd->dma_data;
return true;
}
static int mxs_dma_alloc(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
struct mxs_pcm_runtime_data *iprtd = runtime->private_data;
dma_cap_mask_t mask;
iprtd->dma_params = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
iprtd->dma_data.chan_irq = iprtd->dma_params->chan_irq;
iprtd->dma_chan = dma_request_channel(mask, filter, iprtd);
if (!iprtd->dma_chan)
return -EINVAL;
return 0;
}
static int snd_mxs_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct mxs_pcm_runtime_data *iprtd = runtime->private_data;
unsigned long dma_addr;
struct dma_chan *chan;
int ret;
ret = mxs_dma_alloc(substream, params);
if (ret)
return ret;
chan = iprtd->dma_chan;
iprtd->size = params_buffer_bytes(params);
iprtd->periods = params_periods(params);
iprtd->period_bytes = params_period_bytes(params);
iprtd->offset = 0;
iprtd->period_time = HZ / (params_rate(params) /
params_period_size(params));
snd_pcm_set_runtime_buffer(substream, &substream->dma_buffer);
dma_addr = runtime->dma_addr;
iprtd->buf = substream->dma_buffer.area;
iprtd->desc = chan->device->device_prep_dma_cyclic(chan, dma_addr,
iprtd->period_bytes * iprtd->periods,
iprtd->period_bytes,
substream->stream == SNDRV_PCM_STREAM_PLAYBACK ?
DMA_TO_DEVICE : DMA_FROM_DEVICE);
if (!iprtd->desc) {
dev_err(&chan->dev->device, "cannot prepare slave dma\n");
return -EINVAL;
}
iprtd->desc->callback = audio_dma_irq;
iprtd->desc->callback_param = substream;
return 0;
}
static int snd_mxs_pcm_hw_free(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct mxs_pcm_runtime_data *iprtd = runtime->private_data;
if (iprtd->dma_chan) {
dma_release_channel(iprtd->dma_chan);
iprtd->dma_chan = NULL;
}
return 0;
}
static int snd_mxs_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct mxs_pcm_runtime_data *iprtd = runtime->private_data;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
dmaengine_submit(iprtd->desc);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
dmaengine_terminate_all(iprtd->dma_chan);
break;
default:
return -EINVAL;
}
return 0;
}
static snd_pcm_uframes_t snd_mxs_pcm_pointer(
struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct mxs_pcm_runtime_data *iprtd = runtime->private_data;
return bytes_to_frames(substream->runtime, iprtd->offset);
}
static int snd_mxs_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct mxs_pcm_runtime_data *iprtd;
int ret;
iprtd = kzalloc(sizeof(*iprtd), GFP_KERNEL);
if (iprtd == NULL)
return -ENOMEM;
runtime->private_data = iprtd;
ret = snd_pcm_hw_constraint_integer(substream->runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (ret < 0) {
kfree(iprtd);
return ret;
}
snd_soc_set_runtime_hwparams(substream, &snd_mxs_hardware);
return 0;
}
static int snd_mxs_close(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct mxs_pcm_runtime_data *iprtd = runtime->private_data;
kfree(iprtd);
return 0;
}
static int snd_mxs_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
struct snd_pcm_runtime *runtime = substream->runtime;
return dma_mmap_writecombine(substream->pcm->card->dev, vma,
runtime->dma_area,
runtime->dma_addr,
runtime->dma_bytes);
}
static int mxs_pcm_preallocate_dma_buffer(struct snd_pcm *pcm, int stream)
{
struct snd_pcm_substream *substream = pcm->streams[stream].substream;
struct snd_dma_buffer *buf = &substream->dma_buffer;
size_t size = snd_mxs_hardware.buffer_bytes_max;
buf->dev.type = SNDRV_DMA_TYPE_DEV;
buf->dev.dev = pcm->card->dev;
buf->private_data = NULL;
buf->area = dma_alloc_writecombine(pcm->card->dev, size,
&buf->addr, GFP_KERNEL);
if (!buf->area)
return -ENOMEM;
buf->bytes = size;
return 0;
}
static int mxs_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_card *card = rtd->card->snd_card;
struct snd_pcm *pcm = rtd->pcm;
int ret = 0;
if (!card->dev->dma_mask)
card->dev->dma_mask = &mxs_pcm_dmamask;
if (!card->dev->coherent_dma_mask)
card->dev->coherent_dma_mask = DMA_BIT_MASK(32);
if (pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream) {
ret = mxs_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_PLAYBACK);
if (ret)
goto out;
}
if (pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream) {
ret = mxs_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_CAPTURE);
if (ret)
goto out;
}
out:
return ret;
}
static void mxs_pcm_free(struct snd_pcm *pcm)
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
dma_free_writecombine(pcm->card->dev, buf->bytes,
buf->area, buf->addr);
buf->area = NULL;
}
}
static int __devinit mxs_soc_platform_probe(struct platform_device *pdev)
{
return snd_soc_register_platform(&pdev->dev, &mxs_soc_platform);
}
static int __devexit mxs_soc_platform_remove(struct platform_device *pdev)
{
snd_soc_unregister_platform(&pdev->dev);
return 0;
}
static int __init snd_mxs_pcm_init(void)
{
return platform_driver_register(&mxs_pcm_driver);
}
static void __exit snd_mxs_pcm_exit(void)
{
platform_driver_unregister(&mxs_pcm_driver);
}
